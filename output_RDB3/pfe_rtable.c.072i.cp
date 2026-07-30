
IPA constant propagation start:
Determining dynamic type for call: iftmp.22_7 = pfe_rtable_get_by_phys_entry_va (rtable_6(D), _5);
  Starting walk at: iftmp.22_7 = pfe_rtable_get_by_phys_entry_va (rtable_6(D), _5);
  instance pointer: rtable_6(D)  Outer instance pointer: rtable_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: iftmp.22_7 = pfe_rtable_get_by_phys_entry_va (rtable_6(D), _5);
  Starting walk at: iftmp.22_7 = pfe_rtable_get_by_phys_entry_va (rtable_6(D), _5);
  instance pointer: _5  Outer instance pointer: ISRA.52_37(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: temp_60 = pfe_get_crc32_be (4294967295, &sport, 4);
  Starting walk at: temp_60 = pfe_get_crc32_be (4294967295, &sport, 4);
  instance pointer: &sport  Outer instance pointer: sport offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: temp_9 = pfe_get_crc32_be (4294967295, &sport, 4);
  Starting walk at: temp_9 = pfe_get_crc32_be (4294967295, &sport, 4);
  instance pointer: &sport  Outer instance pointer: sport offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_rtable_phys_entry_is_pool (rtable_1(D), phys_entry_va_2(D));
  Starting walk at: _3 = pfe_rtable_phys_entry_is_pool (rtable_1(D), phys_entry_va_2(D));
  instance pointer: rtable_1(D)  Outer instance pointer: rtable_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_rtable_phys_entry_is_pool (rtable_1(D), phys_entry_va_2(D));
  Starting walk at: _3 = pfe_rtable_phys_entry_is_pool (rtable_1(D), phys_entry_va_2(D));
  instance pointer: phys_entry_va_2(D)  Outer instance pointer: phys_entry_va_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = pfe_rtable_match_criterion (_7, _8, entry_20);
  Starting walk at: _9 = pfe_rtable_match_criterion (_7, _8, entry_20);
  instance pointer: _8  Outer instance pointer: rtable_18(D) offset: 544 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_rtable_match_criterion (_7, _8, entry_20);
Determining dynamic type for call: _9 = pfe_rtable_match_criterion (_7, _8, entry_20);
  Starting walk at: _9 = pfe_rtable_match_criterion (_7, _8, entry_20);
  instance pointer: entry_20  Outer instance pointer: entry_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_rtable_match_criterion (_7, _8, entry_20);
Determining dynamic type for call: entry_18 = pfe_rtable_prepare_first_entry (rtable_7(D));
  Starting walk at: entry_18 = pfe_rtable_prepare_first_entry (rtable_7(D));
  instance pointer: rtable_7(D)  Outer instance pointer: rtable_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_3, arg_10(D), 50);
  Function call may change dynamic type:autolibc_memcpy (_2, arg_10(D), 4);
  Function call may change dynamic type:autolibc_memcpy (_1, arg_10(D), 4);
Determining dynamic type for call: _7 = pfe_rtable_match_criterion (_5, _6, entry_19);
  Starting walk at: _7 = pfe_rtable_match_criterion (_5, _6, entry_19);
  instance pointer: _6  Outer instance pointer: rtable_18(D) offset: 544 (bits) vtbl reference: 
  Function call may change dynamic type:_7 = pfe_rtable_match_criterion (_5, _6, entry_19);
Determining dynamic type for call: _7 = pfe_rtable_match_criterion (_5, _6, entry_19);
  Starting walk at: _7 = pfe_rtable_match_criterion (_5, _6, entry_19);
  instance pointer: entry_19  Outer instance pointer: entry_19 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_7 = pfe_rtable_match_criterion (_5, _6, entry_19);
Determining dynamic type for call: _19 = pfe_rtable_entry_to_5t (entry_29(D), &five_tuple);
  Starting walk at: _19 = pfe_rtable_entry_to_5t (entry_29(D), &five_tuple);
  instance pointer: entry_29(D)  Outer instance pointer: entry_29(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _19 = pfe_rtable_entry_to_5t (entry_29(D), &five_tuple);
  Starting walk at: _19 = pfe_rtable_entry_to_5t (entry_29(D), &five_tuple);
  instance pointer: &five_tuple  Outer instance pointer: five_tuple offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_rtable_destroy_stats_table (_4, _5);
  Starting walk at: pfe_rtable_destroy_stats_table (_4, _5);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:fifo_destroy (_3);
Determining dynamic type for call: _18 = pfe_rtable_create_stats_table (class_39(D), 21);
  Starting walk at: _18 = pfe_rtable_create_stats_table (class_39(D), 21);
  instance pointer: class_39(D)  Outer instance pointer: class_39(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (&stats_tbl_index, 0, 21);
  Function call may change dynamic type:_2 = oal_mm_virt_to_phys_contig (_1);
  Function call may change dynamic type:autolibc_memset (&pfe_rtable, 0, 140);
Determining dynamic type for call: rtable_47 = pfe_rtable_configure_table (class_39(D), &pfe_rtable, table_params$pool_size_52);
  Starting walk at: rtable_47 = pfe_rtable_configure_table (class_39(D), &pfe_rtable, table_params$pool_size_52);
  instance pointer: class_39(D)  Outer instance pointer: class_39(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_18 = pfe_rtable_create_stats_table (class_39(D), 21);
  Function call may change dynamic type:autolibc_memset (&stats_tbl_index, 0, 21);
  Function call may change dynamic type:_2 = oal_mm_virt_to_phys_contig (_1);
  Function call may change dynamic type:autolibc_memset (&pfe_rtable, 0, 140);
Determining dynamic type for call: rtable_47 = pfe_rtable_configure_table (class_39(D), &pfe_rtable, table_params$pool_size_52);
  Starting walk at: rtable_47 = pfe_rtable_configure_table (class_39(D), &pfe_rtable, table_params$pool_size_52);
  instance pointer: &pfe_rtable  Outer instance pointer: pfe_rtable offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_18 = pfe_rtable_create_stats_table (class_39(D), 21);
  Function call may change dynamic type:autolibc_memset (&stats_tbl_index, 0, 21);
  Function call may change dynamic type:_2 = oal_mm_virt_to_phys_contig (_1);
  Function call may change dynamic type:autolibc_memset (&pfe_rtable, 0, 140);
Determining dynamic type for call: pfe_rtable_destroy (&pfe_rtable);
  Starting walk at: pfe_rtable_destroy (&pfe_rtable);
  instance pointer: &pfe_rtable  Outer instance pointer: pfe_rtable offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t map the table memory\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2805, "");
  Function call may change dynamic type:_18 = pfe_rtable_create_stats_table (class_39(D), 21);
  Function call may change dynamic type:autolibc_memset (&stats_tbl_index, 0, 21);
  Function call may change dynamic type:_2 = oal_mm_virt_to_phys_contig (_1);
  Function call may change dynamic type:autolibc_memset (&pfe_rtable, 0, 140);
Determining dynamic type for call: pfe_rtable_invalidate (rtable_21(D));
  Starting walk at: pfe_rtable_invalidate (rtable_21(D));
  instance pointer: rtable_21(D)  Outer instance pointer: rtable_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = pfe_class_set_rtable (class_24(D), _2, _7, 128);
Determining dynamic type for call: ret_32 = fifo_put (_12, _14);
  Starting walk at: ret_32 = fifo_put (_12, _14);
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = fifo_create (_9, &pfe_rtable_fifo.instance, &pfe_rtable_fifo.data);
  Function call may change dynamic type:pfe_rtable_invalidate (rtable_21(D));
  Function call may change dynamic type:_8 = pfe_class_set_rtable (class_24(D), _2, _7, 128);
  Function call may change dynamic type:ret_32 = fifo_put (_12, _14);
Determining dynamic type for call: ret_32 = fifo_put (_12, _14);
  Starting walk at: ret_32 = fifo_put (_12, _14);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = fifo_create (_9, &pfe_rtable_fifo.instance, &pfe_rtable_fifo.data);
  Function call may change dynamic type:pfe_rtable_invalidate (rtable_21(D));
  Function call may change dynamic type:_8 = pfe_class_set_rtable (class_24(D), _2, _7, 128);
  Function call may change dynamic type:ret_32 = fifo_put (_12, _14);
Determining dynamic type for call: pfe_rtable_destroy (rtable_21(D));
  Starting walk at: pfe_rtable_destroy (rtable_21(D));
  instance pointer: rtable_21(D)  Outer instance pointer: rtable_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Pool filling failed (VA pool)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2733, "");
  Function call may change dynamic type:ret_32 = fifo_put (_12, _14);
  Function call may change dynamic type:_10 = fifo_create (_9, &pfe_rtable_fifo.instance, &pfe_rtable_fifo.data);
  Function call may change dynamic type:pfe_rtable_invalidate (rtable_21(D));
  Function call may change dynamic type:_8 = pfe_class_set_rtable (class_24(D), _2, _7, 128);
  Function call may change dynamic type:ret_32 = fifo_put (_12, _14);
Determining dynamic type for call: pfe_rtable_destroy (rtable_21(D));
  Starting walk at: pfe_rtable_destroy (rtable_21(D));
  instance pointer: rtable_21(D)  Outer instance pointer: rtable_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t create pool\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2720, "");
  Function call may change dynamic type:_10 = fifo_create (_9, &pfe_rtable_fifo.instance, &pfe_rtable_fifo.data);
  Function call may change dynamic type:pfe_rtable_invalidate (rtable_21(D));
  Function call may change dynamic type:_8 = pfe_class_set_rtable (class_24(D), _2, _7, 128);
Determining dynamic type for call: pfe_rtable_destroy (rtable_21(D));
  Starting walk at: pfe_rtable_destroy (rtable_21(D));
  instance pointer: rtable_21(D)  Outer instance pointer: rtable_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Unable to set routing table address\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2707, "");
  Function call may change dynamic type:_8 = pfe_class_set_rtable (class_24(D), _2, _7, 128);
Determining dynamic type for call: err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  Starting walk at: err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  instance pointer: rtable_28(D)  Outer instance pointer: rtable_28(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (80);
  Function call may change dynamic type:_10 (_11, 0);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t delete timed-out entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2576, err_35, "");
  Function call may change dynamic type:err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  Function call may change dynamic type:pfe_rtable_entry_free_nolock (entry_33, 0);
Determining dynamic type for call: err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  Starting walk at: err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  instance pointer: entry_33  Outer instance pointer: entry_33 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (80);
  Function call may change dynamic type:_10 (_11, 0);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t delete timed-out entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2576, err_35, "");
  Function call may change dynamic type:err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  Function call may change dynamic type:pfe_rtable_entry_free_nolock (entry_33, 0);
Determining dynamic type for call: pfe_rtable_entry_free_nolock (entry_33, 0);
  Starting walk at: pfe_rtable_entry_free_nolock (entry_33, 0);
  instance pointer: entry_33  Outer instance pointer: entry_33 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  Function call may change dynamic type:oal_mutex_lock.part.0 (80);
  Function call may change dynamic type:_10 (_11, 0);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t delete timed-out entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2576, err_35, "");
  Function call may change dynamic type:err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  Function call may change dynamic type:pfe_rtable_entry_free_nolock (entry_33, 0);
Determining dynamic type for call: _10 (_11, 0);
  Starting walk at: _10 (_11, 0);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (80);
  Function call may change dynamic type:_10 (_11, 0);
Determining dynamic type for call: _2 = pfe_rtable_phys_entry_is_htable (rtable_14(D), _1);
  Starting walk at: _2 = pfe_rtable_phys_entry_is_htable (rtable_14(D), _1);
  instance pointer: rtable_14(D)  Outer instance pointer: rtable_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_rtable_phys_entry_is_htable (rtable_14(D), _1);
  Starting walk at: _2 = pfe_rtable_phys_entry_is_htable (rtable_14(D), _1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_rtable_phys_entry_is_pool (rtable_14(D), _1);
  Starting walk at: _3 = pfe_rtable_phys_entry_is_pool (rtable_14(D), _1);
  instance pointer: rtable_14(D)  Outer instance pointer: rtable_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_rtable_phys_entry_is_pool (rtable_14(D), _1);
  Starting walk at: _3 = pfe_rtable_phys_entry_is_pool (rtable_14(D), _1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_rtable_del_entry_nolock_pool (rtable_14(D), entry_13(D));
  Starting walk at: pfe_rtable_del_entry_nolock_pool (rtable_14(D), entry_13(D));
  instance pointer: rtable_14(D)  Outer instance pointer: rtable_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_rtable_del_entry_nolock_pool (rtable_14(D), entry_13(D));
  Starting walk at: pfe_rtable_del_entry_nolock_pool (rtable_14(D), entry_13(D));
  instance pointer: entry_13(D)  Outer instance pointer: entry_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_rtable_del_entry_nolock_htable (rtable_14(D), entry_13(D));
  Starting walk at: pfe_rtable_del_entry_nolock_htable (rtable_14(D), entry_13(D));
  instance pointer: rtable_14(D)  Outer instance pointer: rtable_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_rtable_del_entry_nolock_htable (rtable_14(D), entry_13(D));
  Starting walk at: pfe_rtable_del_entry_nolock_htable (rtable_14(D), entry_13(D));
  instance pointer: entry_13(D)  Outer instance pointer: entry_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_38 = fifo_put (_11, _12);
  Starting walk at: ret_38 = fifo_put (_11, _12);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_10, 0, 128);
  Function call may change dynamic type:oal_time_usleep (10);
Determining dynamic type for call: ret_38 = fifo_put (_11, _12);
  Starting walk at: ret_38 = fifo_put (_11, _12);
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_10, 0, 128);
  Function call may change dynamic type:oal_time_usleep (10);
Determining dynamic type for call: pfe_rtable_clear_stats (rtable_57(D), _4);
  Starting walk at: pfe_rtable_clear_stats (rtable_57(D), _4);
  instance pointer: rtable_57(D)  Outer instance pointer: rtable_57(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _17 = pfe_rtable_phys_entry_is_pool (rtable_57(D), _16);
  Starting walk at: _17 = pfe_rtable_phys_entry_is_pool (rtable_57(D), _16);
  instance pointer: rtable_57(D)  Outer instance pointer: rtable_57(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_14, 0, 128);
  Function call may change dynamic type:autolibc_memcpy (_10, _12, 128);
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:pfe_rtable_free_stats_index (_7);
  Function call may change dynamic type:pfe_rtable_clear_stats (rtable_57(D), _4);
Determining dynamic type for call: _17 = pfe_rtable_phys_entry_is_pool (rtable_57(D), _16);
  Starting walk at: _17 = pfe_rtable_phys_entry_is_pool (rtable_57(D), _16);
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_14, 0, 128);
  Function call may change dynamic type:autolibc_memcpy (_10, _12, 128);
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:pfe_rtable_free_stats_index (_7);
  Function call may change dynamic type:pfe_rtable_clear_stats (rtable_57(D), _4);
Determining dynamic type for call: ret_78 = fifo_put (_18, _16);
  Starting walk at: ret_78 = fifo_put (_18, _16);
  instance pointer: _18  Outer instance pointer: _18 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_14, 0, 128);
  Function call may change dynamic type:autolibc_memcpy (_10, _12, 128);
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:pfe_rtable_free_stats_index (_7);
  Function call may change dynamic type:pfe_rtable_clear_stats (rtable_57(D), _4);
Determining dynamic type for call: ret_78 = fifo_put (_18, _16);
  Starting walk at: ret_78 = fifo_put (_18, _16);
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_14, 0, 128);
  Function call may change dynamic type:autolibc_memcpy (_10, _12, 128);
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:pfe_rtable_free_stats_index (_7);
  Function call may change dynamic type:pfe_rtable_clear_stats (rtable_57(D), _4);
Determining dynamic type for call: next_phys_entry_pa_82 = pfe_rtable_phys_entry_get_pa (rtable_57(D), _20);
  Starting walk at: next_phys_entry_pa_82 = pfe_rtable_phys_entry_get_pa (rtable_57(D), _20);
  instance pointer: rtable_57(D)  Outer instance pointer: rtable_57(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_14, 0, 128);
  Function call may change dynamic type:autolibc_memcpy (_10, _12, 128);
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:pfe_rtable_free_stats_index (_7);
  Function call may change dynamic type:pfe_rtable_clear_stats (rtable_57(D), _4);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t return routing table entry to the pool\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2306, "");
  Function call may change dynamic type:ret_78 = fifo_put (_18, _16);
Determining dynamic type for call: next_phys_entry_pa_82 = pfe_rtable_phys_entry_get_pa (rtable_57(D), _20);
  Starting walk at: next_phys_entry_pa_82 = pfe_rtable_phys_entry_get_pa (rtable_57(D), _20);
  instance pointer: _20  Outer instance pointer: _20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (_14, 0, 128);
  Function call may change dynamic type:autolibc_memcpy (_10, _12, 128);
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:pfe_rtable_free_stats_index (_7);
  Function call may change dynamic type:pfe_rtable_clear_stats (rtable_57(D), _4);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t return routing table entry to the pool\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2306, "");
  Function call may change dynamic type:ret_78 = fifo_put (_18, _16);
Determining dynamic type for call: ret_8 = pfe_rtable_del_entry_nolock (rtable_5(D), entry_6(D));
  Starting walk at: ret_8 = pfe_rtable_del_entry_nolock (rtable_5(D), entry_6(D));
  instance pointer: rtable_5(D)  Outer instance pointer: rtable_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (79);
Determining dynamic type for call: ret_8 = pfe_rtable_del_entry_nolock (rtable_5(D), entry_6(D));
  Starting walk at: ret_8 = pfe_rtable_del_entry_nolock (rtable_5(D), entry_6(D));
  instance pointer: entry_6(D)  Outer instance pointer: entry_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (79);
Determining dynamic type for call: _1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Starting walk at: _1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  instance pointer: rtable_20(D)  Outer instance pointer: rtable_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: _1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Starting walk at: _1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  instance pointer: entry_21(D)  Outer instance pointer: entry_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  Starting walk at: ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  instance pointer: rtable_20(D)  Outer instance pointer: rtable_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  Starting walk at: ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  instance pointer: entry_21(D)  Outer instance pointer: entry_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  Starting walk at: ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  instance pointer: &phys_entry_temp  Outer instance pointer: phys_entry_temp offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: pfe_rtable_add_entry_validate.isra.0 (rtable_20(D), entry_21(D), _32);
  Starting walk at: pfe_rtable_add_entry_validate.isra.0 (rtable_20(D), entry_21(D), _32);
  instance pointer: rtable_20(D)  Outer instance pointer: rtable_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_2, _3, 128);
  Function call may change dynamic type:ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  Function call may change dynamic type:_1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: pfe_rtable_add_entry_validate.isra.0 (rtable_20(D), entry_21(D), _32);
  Starting walk at: pfe_rtable_add_entry_validate.isra.0 (rtable_20(D), entry_21(D), _32);
  instance pointer: entry_21(D)  Outer instance pointer: entry_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_2, _3, 128);
  Function call may change dynamic type:ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  Function call may change dynamic type:_1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: pfe_rtable_add_entry_validate.isra.0 (rtable_20(D), entry_21(D), _32);
  Starting walk at: pfe_rtable_add_entry_validate.isra.0 (rtable_20(D), entry_21(D), _32);
  instance pointer: _32  Outer instance pointer: _32 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_2, _3, 128);
  Function call may change dynamic type:ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  Function call may change dynamic type:_1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (78);
Determining dynamic type for call: _7 = pfe_rtable_entry_get_hash.isra.0 (_78, ipv_type_54, _6);
  Starting walk at: _7 = pfe_rtable_entry_get_hash.isra.0 (_78, ipv_type_54, _6);
  instance pointer: _78  Outer instance pointer: entry_53(D) offset: 32 (bits) vtbl reference: 
Determining dynamic type for call: _45 = fifo_get (_44);
  Starting walk at: _45 = fifo_get (_44);
  instance pointer: _44  Outer instance pointer: _44 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = pfe_rtable_get_free_stats_index.isra.0 (_77);
  Function call may change dynamic type:_7 = pfe_rtable_entry_get_hash.isra.0 (_78, ipv_type_54, _6);
  Function call may change dynamic type:_28 = pfe_l2br_get_vlan_stats_index (domain_66);
  Function call may change dynamic type:domain_66 = pfe_l2br_get_first_domain (_23, 1, _27);
Determining dynamic type for call: ret_76 = pfe_rtable_add_entry_link (rtable_55(D), phys_entry_temp_58(D));
  Starting walk at: ret_76 = pfe_rtable_add_entry_link (rtable_55(D), phys_entry_temp_58(D));
  instance pointer: rtable_55(D)  Outer instance pointer: rtable_55(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_45 = fifo_get (_44);
  Function call may change dynamic type:_10 = pfe_rtable_get_free_stats_index.isra.0 (_77);
  Function call may change dynamic type:_7 = pfe_rtable_entry_get_hash.isra.0 (_78, ipv_type_54, _6);
  Function call may change dynamic type:_28 = pfe_l2br_get_vlan_stats_index (domain_66);
  Function call may change dynamic type:domain_66 = pfe_l2br_get_first_domain (_23, 1, _27);
Determining dynamic type for call: ret_76 = pfe_rtable_add_entry_link (rtable_55(D), phys_entry_temp_58(D));
  Starting walk at: ret_76 = pfe_rtable_add_entry_link (rtable_55(D), phys_entry_temp_58(D));
  instance pointer: phys_entry_temp_58(D)  Outer instance pointer: phys_entry_temp_58(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_45 = fifo_get (_44);
  Function call may change dynamic type:_10 = pfe_rtable_get_free_stats_index.isra.0 (_77);
  Function call may change dynamic type:_7 = pfe_rtable_entry_get_hash.isra.0 (_78, ipv_type_54, _6);
  Function call may change dynamic type:_28 = pfe_l2br_get_vlan_stats_index (domain_66);
  Function call may change dynamic type:domain_66 = pfe_l2br_get_first_domain (_23, 1, _27);
Determining dynamic type for call: ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
  Starting walk at: ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
  instance pointer: rtable_39(D)  Outer instance pointer: rtable_39(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
  Starting walk at: ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
  instance pointer: phys_entry_temp_37(D)  Outer instance pointer: phys_entry_temp_37(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_rtable_phys_entry_is_htable (rtable_39(D), _2);
  Starting walk at: _3 = pfe_rtable_phys_entry_is_htable (rtable_39(D), _2);
  instance pointer: rtable_39(D)  Outer instance pointer: rtable_39(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
Determining dynamic type for call: _3 = pfe_rtable_phys_entry_is_htable (rtable_39(D), _2);
  Starting walk at: _3 = pfe_rtable_phys_entry_is_htable (rtable_39(D), _2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
Determining dynamic type for call: _14 = pfe_rtable_phys_entry_get_va (rtable_39(D), _13);
  Starting walk at: _14 = pfe_rtable_phys_entry_get_va (rtable_39(D), _13);
  instance pointer: rtable_39(D)  Outer instance pointer: rtable_39(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
Determining dynamic type for call: _14 = pfe_rtable_phys_entry_get_va (rtable_39(D), _13);
  Starting walk at: _14 = pfe_rtable_phys_entry_get_va (rtable_39(D), _13);
  instance pointer: _13  Outer instance pointer: _13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_41 = pfe_rtable_add_entry_get_phys_pa (rtable_39(D), phys_entry_temp_37(D));
Determining dynamic type for call: _2 = pfe_rtable_phys_entry_get_pa (rtable_10(D), _1);
  Starting walk at: _2 = pfe_rtable_phys_entry_get_pa (rtable_10(D), _1);
  instance pointer: rtable_10(D)  Outer instance pointer: rtable_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_rtable_phys_entry_get_pa (rtable_10(D), _1);
  Starting walk at: _2 = pfe_rtable_phys_entry_get_pa (rtable_10(D), _1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = pfe_rtable_phys_entry_is_pool (rtable_10(D), _3);
  Starting walk at: _4 = pfe_rtable_phys_entry_is_pool (rtable_10(D), _3);
  instance pointer: rtable_10(D)  Outer instance pointer: rtable_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get PA (entry @ v0x%p)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1961, _1, "");
Determining dynamic type for call: _4 = pfe_rtable_phys_entry_is_pool (rtable_10(D), _3);
  Starting walk at: _4 = pfe_rtable_phys_entry_is_pool (rtable_10(D), _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get PA (entry @ v0x%p)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1961, _1, "");
Determining dynamic type for call: ret_15 = fifo_put (_5, _3);
  Starting walk at: ret_15 = fifo_put (_5, _3);
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get PA (entry @ v0x%p)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1961, _1, "");
Determining dynamic type for call: ret_15 = fifo_put (_5, _3);
  Starting walk at: ret_15 = fifo_put (_5, _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t get PA (entry @ v0x%p)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1961, _1, "");
Determining dynamic type for call: _1 = pfe_rtable_entry_to_5t (entry_11(D), &arg.five_tuple);
  Starting walk at: _1 = pfe_rtable_entry_to_5t (entry_11(D), &arg.five_tuple);
  instance pointer: entry_11(D)  Outer instance pointer: entry_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_entry_to_5t (entry_11(D), &arg.five_tuple);
  Starting walk at: _1 = pfe_rtable_entry_to_5t (entry_11(D), &arg.five_tuple);
  instance pointer: &arg.five_tuple  Outer instance pointer: arg offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pfe_rtable_match_criterion (5, &arg, entry2_14);
  Starting walk at: _5 = pfe_rtable_match_criterion (5, &arg, entry2_14);
  instance pointer: &arg  Outer instance pointer: arg offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_rtable_match_criterion (5, &arg, entry2_14);
  Function call may change dynamic type:_1 = pfe_rtable_entry_to_5t (entry_11(D), &arg.five_tuple);
Determining dynamic type for call: _5 = pfe_rtable_match_criterion (5, &arg, entry2_14);
  Starting walk at: _5 = pfe_rtable_match_criterion (5, &arg, entry2_14);
  instance pointer: entry2_14  Outer instance pointer: entry2_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = pfe_rtable_match_criterion (5, &arg, entry2_14);
  Function call may change dynamic type:_1 = pfe_rtable_entry_to_5t (entry_11(D), &arg.five_tuple);
Determining dynamic type for call: ptr_7 = pfe_rtable_entry_get_child_nolock (entry_5(D));
  Starting walk at: ptr_7 = pfe_rtable_entry_get_child_nolock (entry_5(D));
  instance pointer: entry_5(D)  Outer instance pointer: entry_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (81);
Determining dynamic type for call: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  Starting walk at: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  instance pointer: entry_4(D)  Outer instance pointer: entry_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  Starting walk at: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  Starting walk at: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  instance pointer: entry_4(D)  Outer instance pointer: entry_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  Starting walk at: _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  instance pointer: &tuple  Outer instance pointer: tuple offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_12 = pfe_rtable_entry_set_sip (entry_10(D), _1);
  Starting walk at: ret_12 = pfe_rtable_entry_set_sip (entry_10(D), _1);
  instance pointer: entry_10(D)  Outer instance pointer: entry_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_12 = pfe_rtable_entry_set_sip (entry_10(D), _1);
  Starting walk at: ret_12 = pfe_rtable_entry_set_sip (entry_10(D), _1);
  instance pointer: _1  Outer instance pointer: tuple_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_14 = pfe_rtable_entry_set_dip (entry_10(D), _2);
  Starting walk at: ret_14 = pfe_rtable_entry_set_dip (entry_10(D), _2);
  instance pointer: entry_10(D)  Outer instance pointer: entry_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_12 = pfe_rtable_entry_set_sip (entry_10(D), _1);
Determining dynamic type for call: ret_14 = pfe_rtable_entry_set_dip (entry_10(D), _2);
  Starting walk at: ret_14 = pfe_rtable_entry_set_dip (entry_10(D), _2);
  instance pointer: _2  Outer instance pointer: tuple_8(D) offset: 176 (bits) vtbl reference: 
  Function call may change dynamic type:ret_12 = pfe_rtable_entry_set_sip (entry_10(D), _1);
Determining dynamic type for call: pfe_rtable_entry_free_nolock (entry_3(D), 1);
  Starting walk at: pfe_rtable_entry_free_nolock (entry_3(D), 1);
  instance pointer: entry_3(D)  Outer instance pointer: entry_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (82);
Determining dynamic type for call: pfe_rtable_entry_free_nolock.part.0 (entry_10(D));
  Starting walk at: pfe_rtable_entry_free_nolock.part.0 (entry_10(D));
  instance pointer: entry_10(D)  Outer instance pointer: entry_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_phys_entry_is_htable (rtable_11(D), phys_entry_pa_12(D));
  Starting walk at: _1 = pfe_rtable_phys_entry_is_htable (rtable_11(D), phys_entry_pa_12(D));
  instance pointer: rtable_11(D)  Outer instance pointer: rtable_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_phys_entry_is_htable (rtable_11(D), phys_entry_pa_12(D));
  Starting walk at: _1 = pfe_rtable_phys_entry_is_htable (rtable_11(D), phys_entry_pa_12(D));
  instance pointer: phys_entry_pa_12(D)  Outer instance pointer: phys_entry_pa_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pfe_rtable_phys_entry_is_pool (rtable_11(D), phys_entry_pa_12(D));
  Starting walk at: _5 = pfe_rtable_phys_entry_is_pool (rtable_11(D), phys_entry_pa_12(D));
  instance pointer: rtable_11(D)  Outer instance pointer: rtable_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pfe_rtable_phys_entry_is_pool (rtable_11(D), phys_entry_pa_12(D));
  Starting walk at: _5 = pfe_rtable_phys_entry_is_pool (rtable_11(D), phys_entry_pa_12(D));
  instance pointer: phys_entry_pa_12(D)  Outer instance pointer: phys_entry_pa_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_phys_entry_is_htable (rtable_8(D), phys_entry_va_9(D));
  Starting walk at: _1 = pfe_rtable_phys_entry_is_htable (rtable_8(D), phys_entry_va_9(D));
  instance pointer: rtable_8(D)  Outer instance pointer: rtable_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_rtable_phys_entry_is_htable (rtable_8(D), phys_entry_va_9(D));
  Starting walk at: _1 = pfe_rtable_phys_entry_is_htable (rtable_8(D), phys_entry_va_9(D));
  instance pointer: phys_entry_va_9(D)  Outer instance pointer: phys_entry_va_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pa_6 = pfe_rtable_phys_entry_get_pa.part.0 (rtable_8(D), phys_entry_va_9(D));
  Starting walk at: pa_6 = pfe_rtable_phys_entry_get_pa.part.0 (rtable_8(D), phys_entry_va_9(D));
  instance pointer: rtable_8(D)  Outer instance pointer: rtable_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pa_6 = pfe_rtable_phys_entry_get_pa.part.0 (rtable_8(D), phys_entry_va_9(D));
  Starting walk at: pa_6 = pfe_rtable_phys_entry_get_pa.part.0 (rtable_8(D), phys_entry_va_9(D));
  instance pointer: phys_entry_va_9(D)  Outer instance pointer: phys_entry_va_9(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_rtable_clear_stats.part.0/375:
  Jump functions of caller  pfe_rtable_entry_set_dip.part.0/344:
  Jump functions of caller  pfe_rtable_entry_set_sip.part.0/343:
  Jump functions of caller  pfe_rtable_add_entry_validate.isra.0/340:
    callsite  pfe_rtable_add_entry_validate.isra.0/340 -> pfe_rtable_get_by_phys_entry_va/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_free_nolock.part.0/339:
  Jump functions of caller  pfe_rtable_entry_get_hash.isra.0/338:
    callsite  pfe_rtable_entry_get_hash.isra.0/338 -> pfe_get_crc32_be/24 : 
       param 0: CONST: 4294967295
         value: 0xffffffff, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_get_hash.isra.0/338 -> pfe_get_crc32_be/24 : 
       param 0: CONST: 4294967295
         value: 0xffffffff, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_phys_entry_get_pa.part.0/336:
    callsite  pfe_rtable_phys_entry_get_pa.part.0/336 -> pfe_rtable_phys_entry_is_pool/28 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_get_free_stats_index.isra.0/335:
  Jump functions of caller  oal_mutex_unlock.part.0/334:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/333:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  pfe_class_get_num_of_pes/332:
  Jump functions of caller  pfe_class_read_dmem/331:
  Jump functions of caller  fifo_destroy/330:
  Jump functions of caller  isa_init/329:
  Jump functions of caller  fifo_create/328:
  Jump functions of caller  pfe_class_set_rtable/327:
  Jump functions of caller  pfe_class_dmem_heap_free/326:
  Jump functions of caller  pfe_class_write_dmem/325:
  Jump functions of caller  pfe_class_get_mmap/324:
  Jump functions of caller  pfe_class_dmem_heap_alloc/323:
  Jump functions of caller  oal_mm_virt_to_phys_contig/322:
  Jump functions of caller  pfe_class_rtable_lookup_disable/321:
  Jump functions of caller  pfe_class_rtable_lookup_enable/320:
  Jump functions of caller  oal_time_usleep/319:
  Jump functions of caller  __builtin_expect/318:
  Jump functions of caller  pfe_l2br_get_vlan_stats_index/317:
  Jump functions of caller  pfe_l2br_get_first_domain/316:
  Jump functions of caller  autolibc_memcmp/315:
  Jump functions of caller  pfe_phy_if_get_id/314:
  Jump functions of caller  autolibc_memcpy/313:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/312:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/311:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/310:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/309:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/308:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/307:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/306:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/305:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/304:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/303:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/302:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/301:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/300:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/299:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/298:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/297:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/296:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/295:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/294:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/293:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/292:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/291:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/290:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/289:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/288:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/287:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/286:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/285:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/284:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/283:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/282:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/281:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/280:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/279:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/278:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/277:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/276:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/275:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/274:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/273:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/272:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/271:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/270:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/269:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/268:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/267:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/266:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/265:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/264:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/263:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/262:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/261:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/260:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/259:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/258:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/257:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/256:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/255:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/254:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/253:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/252:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/251:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/250:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/249:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/248:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/247:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/246:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/245:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/244:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/243:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/242:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/241:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/240:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/239:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/238:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/237:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/236:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/235:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/234:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/233:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/232:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/231:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/230:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/229:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/228:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/227:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/226:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/225:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/224:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/223:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/222:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/221:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/220:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/219:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/218:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/217:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/216:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/215:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/214:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/213:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/212:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/211:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/210:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/209:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/208:
  Jump functions of caller  isa_release/207:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/206:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/205:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/204:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/203:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/202:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/201:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/200:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/199:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/198:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/197:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/196:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/195:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/194:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/193:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/192:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/191:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/190:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/189:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/188:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/187:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/186:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/185:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/184:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/183:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/182:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/181:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/180:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/179:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/178:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/177:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/176:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/175:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/174:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/173:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/172:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/171:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/170:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/169:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/168:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/167:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/166:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/165:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/164:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/163:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/162:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/161:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/160:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/159:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/158:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/157:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/156:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/155:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/154:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/153:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/152:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/151:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/150:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/149:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/148:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/147:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/146:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/145:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/144:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/143:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/142:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/141:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/140:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/139:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/138:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/137:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/136:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/135:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/134:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/133:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/132:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/131:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/130:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/129:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/128:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/127:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/126:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/125:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/124:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/123:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/122:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/121:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/120:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/119:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/118:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/117:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/116:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/115:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/114:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/113:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/112:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/111:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/110:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/109:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/108:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/107:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/106:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/105:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/104:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/103:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/102:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/101:
  Jump functions of caller  pfe_hm_report/100:
  Jump functions of caller  autolibc_memset/99:
  Jump functions of caller  isa_reserve/98:
  Jump functions of caller  pfe_rtable_clear_stats/97:
    callsite  pfe_rtable_clear_stats/97 -> pfe_rtable_clear_stats.part.0/375 : 
  Jump functions of caller  pfe_rtable_get_stats/96:
  Jump functions of caller  pfe_rtable_get_next/95:
    callsite  pfe_rtable_get_next/95 -> pfe_rtable_match_criterion/92 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_get_first/94:
    callsite  pfe_rtable_get_first/94 -> pfe_rtable_prepare_first_entry/93 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_prepare_first_entry/93:
    callsite  pfe_rtable_prepare_first_entry/93 -> pfe_rtable_match_criterion/92 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_match_criterion/92:
    callsite  pfe_rtable_match_criterion/92 -> pfe_rtable_entry_to_5t/90 : 
       param 0: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_rtable_entry_to_5t_out/91:
  Jump functions of caller  pfe_rtable_entry_to_5t/90:
  Jump functions of caller  pfe_rtable_get_entry_size/89:
  Jump functions of caller  pfe_rtable_destroy/88:
    callsite  pfe_rtable_destroy/88 -> pfe_rtable_destroy_stats_table/84 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_get_size/87:
  Jump functions of caller  pfe_rtable_create/86:
    callsite  pfe_rtable_create/86 -> pfe_rtable_configure_table/85 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &pfe_rtable
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_create/86 -> pfe_rtable_destroy/88 : 
       param 0: CONST: &pfe_rtable
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_rtable_create/86 -> pfe_rtable_create_stats_table/83 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 21
         value: 0x15, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_configure_table/85:
    callsite  pfe_rtable_configure_table/85 -> pfe_rtable_destroy/88 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_configure_table/85 -> fifo_put/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_configure_table/85 -> pfe_rtable_destroy/88 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_configure_table/85 -> pfe_rtable_invalidate/25 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_configure_table/85 -> pfe_rtable_destroy/88 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_destroy_stats_table/84:
  Jump functions of caller  pfe_rtable_create_stats_table/83:
  Jump functions of caller  pfe_rtable_do_timeouts/82:
    callsite  pfe_rtable_do_timeouts/82 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 80
         value: 0x50, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_do_timeouts/82 -> pfe_rtable_entry_free_nolock/32 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_do_timeouts/82 -> pfe_rtable_del_entry_nolock/81 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_do_timeouts/82 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 80
         value: 0x50, mask: 0x0
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _10 (_11, 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_del_entry_nolock/81:
    callsite  pfe_rtable_del_entry_nolock/81 -> pfe_rtable_del_entry_nolock_pool/80 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_del_entry_nolock/81 -> pfe_rtable_phys_entry_is_pool/28 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_del_entry_nolock/81 -> pfe_rtable_del_entry_nolock_htable/79 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_del_entry_nolock/81 -> pfe_rtable_phys_entry_is_htable/27 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_del_entry_nolock_pool/80:
    callsite  pfe_rtable_del_entry_nolock_pool/80 -> fifo_put/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_del_entry_nolock_htable/79:
    callsite  pfe_rtable_del_entry_nolock_htable/79 -> pfe_rtable_phys_entry_get_pa/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_del_entry_nolock_htable/79 -> fifo_put/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_del_entry_nolock_htable/79 -> pfe_rtable_phys_entry_is_pool/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_del_entry_nolock_htable/79 -> pfe_rtable_free_stats_index/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_rtable_del_entry_nolock_htable/79 -> pfe_rtable_clear_stats/97 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_rtable_del_entry/78:
    callsite  pfe_rtable_del_entry/78 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 79
         value: 0x4f, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_del_entry/78 -> pfe_rtable_del_entry_nolock/81 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_del_entry/78 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 79
         value: 0x4f, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_add_entry/77:
    callsite  pfe_rtable_add_entry/77 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 78
         value: 0x4e, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_add_entry/77 -> pfe_rtable_add_entry_validate.isra.0/340 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry/77 -> pfe_rtable_add_entry_id/75 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_rtable_add_entry/77 -> pfe_rtable_entry_is_duplicate/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry/77 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 78
         value: 0x4e, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_add_entry_id/75:
    callsite  pfe_rtable_add_entry_id/75 -> pfe_rtable_add_entry_link/74 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry_id/75 -> fifo_get/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry_id/75 -> pfe_rtable_get_free_stats_index.isra.0/335 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pfe_rtable_add_entry_id/75 -> pfe_rtable_entry_get_hash.isra.0/338 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_add_entry_link/74:
    callsite  pfe_rtable_add_entry_link/74 -> pfe_rtable_phys_entry_get_va/30 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry_link/74 -> pfe_rtable_phys_entry_is_htable/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry_link/74 -> pfe_rtable_add_entry_get_phys_pa/73 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_add_entry_get_phys_pa/73:
    callsite  pfe_rtable_add_entry_get_phys_pa/73 -> fifo_put/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry_get_phys_pa/73 -> pfe_rtable_phys_entry_is_pool/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_add_entry_get_phys_pa/73 -> pfe_rtable_phys_entry_get_pa/29 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_is_duplicate/72:
    callsite  pfe_rtable_entry_is_duplicate/72 -> pfe_rtable_match_criterion/92 : 
       param 0: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_entry_is_duplicate/72 -> pfe_rtable_entry_to_5t/90 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_rtable_entry_get_stats_index/70:
  Jump functions of caller  pfe_rtable_entry_get_child/69:
    callsite  pfe_rtable_entry_get_child/69 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 81
         value: 0x51, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_get_child/69 -> pfe_rtable_entry_get_child_nolock/68 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_entry_get_child/69 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 81
         value: 0x51, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_get_child_nolock/68:
  Jump functions of caller  pfe_rtable_entry_set_child/67:
  Jump functions of caller  pfe_rtable_entry_get_refptr/66:
  Jump functions of caller  pfe_rtable_entry_set_refptr/65:
  Jump functions of caller  pfe_rtable_entry_set_callback/64:
  Jump functions of caller  pfe_rtable_entry_get_route_id/63:
  Jump functions of caller  pfe_rtable_entry_set_route_id/62:
  Jump functions of caller  pfe_rtable_entry_set_timeout/61:
    callsite  pfe_rtable_entry_set_timeout/61 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 77
         value: 0x4d, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_timeout/61 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 77
         value: 0x4d, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_get_action_flags/60:
  Jump functions of caller  pfe_rtable_entry_get_id5t/59:
  Jump functions of caller  pfe_rtable_entry_set_id5t/58:
  Jump functions of caller  pfe_rtable_entry_set_out_pppoe_sid/57:
    callsite  pfe_rtable_entry_set_out_pppoe_sid/57 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 76
         value: 0x4c, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_pppoe_sid/57 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 76
         value: 0x4c, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_out_inner_vlan/56:
    callsite  pfe_rtable_entry_set_out_inner_vlan/56 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 75
         value: 0x4b, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_inner_vlan/56 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 75
         value: 0x4b, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_get_out_vlan/55:
  Jump functions of caller  pfe_rtable_entry_set_out_vlan/54:
    callsite  pfe_rtable_entry_set_out_vlan/54 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 74
         value: 0x4a, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_vlan/54 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 74
         value: 0x4a, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_out_mac_addrs/53:
    callsite  pfe_rtable_entry_set_out_mac_addrs/53 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 73
         value: 0x49, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_mac_addrs/53 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 73
         value: 0x49, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_remove_ttl_decrement/52:
    callsite  pfe_rtable_entry_remove_ttl_decrement/52 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 72
         value: 0x48, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_remove_ttl_decrement/52 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 72
         value: 0x48, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_ttl_decrement/51:
    callsite  pfe_rtable_entry_set_ttl_decrement/51 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 71
         value: 0x47, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_ttl_decrement/51 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 71
         value: 0x47, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_out_dport/50:
    callsite  pfe_rtable_entry_set_out_dport/50 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 70
         value: 0x46, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_dport/50 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 70
         value: 0x46, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_out_sport/49:
    callsite  pfe_rtable_entry_set_out_sport/49 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 69
         value: 0x45, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_sport/49 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 69
         value: 0x45, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_out_dip/48:
    callsite  pfe_rtable_entry_set_out_dip/48 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 68
         value: 0x44, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_dip/48 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 68
         value: 0x44, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_out_sip/47:
    callsite  pfe_rtable_entry_set_out_sip/47 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 67
         value: 0x43, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_set_out_sip/47 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 67
         value: 0x43, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_set_dstif/46:
  Jump functions of caller  pfe_rtable_entry_set_dstif_id/45:
  Jump functions of caller  pfe_rtable_entry_get_proto/44:
  Jump functions of caller  pfe_rtable_entry_set_proto/43:
  Jump functions of caller  pfe_rtable_entry_get_dport/42:
  Jump functions of caller  pfe_rtable_entry_set_dport/41:
  Jump functions of caller  pfe_rtable_entry_get_sport/40:
  Jump functions of caller  pfe_rtable_entry_set_sport/39:
  Jump functions of caller  pfe_rtable_entry_get_dip/38:
    callsite  pfe_rtable_entry_get_dip/38 -> pfe_rtable_entry_to_5t/90 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_rtable_entry_set_dip/37:
    callsite  pfe_rtable_entry_set_dip/37 -> pfe_rtable_entry_set_dip.part.0/344 : 
  Jump functions of caller  pfe_rtable_entry_get_sip/36:
    callsite  pfe_rtable_entry_get_sip/36 -> pfe_rtable_entry_to_5t/90 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_rtable_entry_set_sip/35:
    callsite  pfe_rtable_entry_set_sip/35 -> pfe_rtable_entry_set_sip.part.0/343 : 
  Jump functions of caller  pfe_rtable_entry_set_5t/34:
    callsite  pfe_rtable_entry_set_5t/34 -> pfe_rtable_entry_set_dip/37 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 1, offset 176
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_rtable_entry_set_5t/34 -> pfe_rtable_entry_set_sip/35 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 1, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_free/33:
    callsite  pfe_rtable_entry_free/33 -> oal_mutex_unlock.part.0/334 : 
       param 0: CONST: 82
         value: 0x52, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_free/33 -> pfe_rtable_entry_free_nolock/32 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_rtable_entry_free/33 -> oal_mutex_lock.part.0/333 : 
       param 0: CONST: 82
         value: 0x52, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_free_nolock/32:
    callsite  pfe_rtable_entry_free_nolock/32 -> pfe_rtable_entry_free_nolock.part.0/339 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_entry_create/31:
  Jump functions of caller  pfe_rtable_phys_entry_get_va/30:
    callsite  pfe_rtable_phys_entry_get_va/30 -> pfe_rtable_phys_entry_is_pool/28 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_phys_entry_get_va/30 -> pfe_rtable_phys_entry_is_htable/27 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_phys_entry_get_pa/29:
    callsite  pfe_rtable_phys_entry_get_pa/29 -> pfe_rtable_phys_entry_get_pa.part.0/336 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_rtable_phys_entry_get_pa/29 -> pfe_rtable_phys_entry_is_htable/27 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_rtable_phys_entry_is_pool/28:
  Jump functions of caller  pfe_rtable_phys_entry_is_htable/27:
  Jump functions of caller  pfe_rtable_invalidate/25:
  Jump functions of caller  pfe_get_crc32_be/24:
  Jump functions of caller  pfe_rtable_get_by_phys_entry_va/23:
  Jump functions of caller  pfe_rtable_free_stats_index/22:
  Jump functions of caller  fifo_get/9:
  Jump functions of caller  fifo_put/8:

 Propagating constants:

Not considering pfe_rtable_clear_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_get_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_get_next for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_get_first for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_to_5t_out for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_to_5t for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_get_entry_size for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_get_size for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_do_timeouts for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_del_entry for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_add_entry for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_stats_index for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_child for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_child_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_child for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_refptr for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_refptr for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_callback for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_route_id for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_route_id for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_timeout for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_action_flags for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_id5t for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_id5t for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_pppoe_sid for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_inner_vlan for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_out_vlan for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_vlan for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_mac_addrs for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_remove_ttl_decrement for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_ttl_decrement for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_dport for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_sport for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_dip for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_out_sip for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_dstif for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_dstif_id for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_proto for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_proto for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_dport for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_dport for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_sport for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_sport for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_dip for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_dip for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_get_sip for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_sip for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_set_5t for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_free for cloning; -fipa-cp-clone disabled.
Not considering pfe_rtable_entry_create for cloning; -fipa-cp-clone disabled.

overall_size: 2400, max_new_size: 11001
 - context independent values, size: 81, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 81, time_benefit: 2.250000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 20, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 13, time_benefit: 66.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_rtable_clear_stats.part.0/375:
  Node: pfe_rtable_entry_set_dip.part.0/344:
  Node: pfe_rtable_entry_set_sip.part.0/343:
  Node: pfe_rtable_add_entry_validate.isra.0/340:
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
  Node: pfe_rtable_entry_free_nolock.part.0/339:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_rtable_entry_get_hash.isra.0/338:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_ct_rtable_entry_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         pfe_ipv_type_t [0, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_rtable_phys_entry_get_pa.part.0/336:
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
  Node: pfe_rtable_get_free_stats_index.isra.0/335:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: oal_mutex_unlock.part.0/334:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x50, mask = 0x1f
         const oal_mutex_t [67, 82]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/333:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x50, mask = 0x1f
         const oal_mutex_t [67, 82]
        AGGS VARIABLE
  Node: pfe_rtable_clear_stats/97:
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
  Node: pfe_rtable_get_stats/96:
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
  Node: pfe_rtable_get_next/95:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_get_first/94:
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
  Node: pfe_rtable_prepare_first_entry/93:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_rtable_match_criterion/92:
    param [0]: VARIABLE
               5 [loc_time: 7, loc_size: 33, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const union pfe_rtable_criterion_arg_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_rtable_entry_to_5t_out/91:
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
  Node: pfe_rtable_entry_to_5t/90:
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
  Node: pfe_rtable_get_entry_size/89:
  Node: pfe_rtable_destroy/88:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_get_size/87:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_create/86:
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
  Node: pfe_rtable_configure_table/85:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &pfe_rtable [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_rtable_destroy_stats_table/84:
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
  Node: pfe_rtable_create_stats_table/83:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 21 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x15, mask = 0x0
         uint16_t [21, 21]
        AGGS VARIABLE
  Node: pfe_rtable_do_timeouts/82:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_del_entry_nolock/81:
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
  Node: pfe_rtable_del_entry_nolock_pool/80:
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
  Node: pfe_rtable_del_entry_nolock_htable/79:
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
  Node: pfe_rtable_del_entry/78:
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
  Node: pfe_rtable_add_entry/77:
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
  Node: pfe_rtable_add_entry_id/75:
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
         struct pfe_rtable_phys_entry_infor_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_rtable_add_entry_link/74:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_phys_entry_infor_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_rtable_add_entry_get_phys_pa/73:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_phys_entry_infor_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_rtable_entry_is_duplicate/72:
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
  Node: pfe_rtable_entry_get_stats_index/70:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_get_child/69:
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
  Node: pfe_rtable_entry_get_child_nolock/68:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_child/67:
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
  Node: pfe_rtable_entry_get_refptr/66:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_refptr/65:
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
  Node: pfe_rtable_entry_set_callback/64:
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
  Node: pfe_rtable_entry_get_route_id/63:
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
  Node: pfe_rtable_entry_set_route_id/62:
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
  Node: pfe_rtable_entry_set_timeout/61:
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
  Node: pfe_rtable_entry_get_action_flags/60:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_get_id5t/59:
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
  Node: pfe_rtable_entry_set_id5t/58:
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
  Node: pfe_rtable_entry_set_out_pppoe_sid/57:
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
  Node: pfe_rtable_entry_set_out_inner_vlan/56:
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
  Node: pfe_rtable_entry_get_out_vlan/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_out_vlan/54:
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
  Node: pfe_rtable_entry_set_out_mac_addrs/53:
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
  Node: pfe_rtable_entry_remove_ttl_decrement/52:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_ttl_decrement/51:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_out_dport/50:
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
  Node: pfe_rtable_entry_set_out_sport/49:
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
  Node: pfe_rtable_entry_set_out_dip/48:
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
  Node: pfe_rtable_entry_set_out_sip/47:
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
  Node: pfe_rtable_entry_set_dstif/46:
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
  Node: pfe_rtable_entry_set_dstif_id/45:
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
  Node: pfe_rtable_entry_get_proto/44:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_proto/43:
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
  Node: pfe_rtable_entry_get_dport/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_dport/41:
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
  Node: pfe_rtable_entry_get_sport/40:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_rtable_entry_set_sport/39:
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
  Node: pfe_rtable_entry_get_dip/38:
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
  Node: pfe_rtable_entry_set_dip/37:
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
  Node: pfe_rtable_entry_get_sip/36:
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
  Node: pfe_rtable_entry_set_sip/35:
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
  Node: pfe_rtable_entry_set_5t/34:
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
  Node: pfe_rtable_entry_free/33:
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
  Node: pfe_rtable_entry_free_nolock/32:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 2, loc_size: 16, prop_time: 0, prop_size: 0]
               0 [loc_time: 2, loc_size: 13, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
  Node: pfe_rtable_entry_create/31:
  Node: pfe_rtable_phys_entry_get_va/30:
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
  Node: pfe_rtable_phys_entry_get_pa/29:
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
  Node: pfe_rtable_phys_entry_is_pool/28:
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
  Node: pfe_rtable_phys_entry_is_htable/27:
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
  Node: pfe_rtable_invalidate/25:
    param [0]: &pfe_rtable [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_rtable_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_get_crc32_be/24:
    param [0]: 4294967295 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0xffffffff, mask = 0x0
         uint32_t [4294967295, +INF]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint8_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: 4 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4, mask = 0x0
         uint16_t [4, 4]
        AGGS VARIABLE
  Node: pfe_rtable_get_by_phys_entry_va/23:
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
  Node: pfe_rtable_free_stats_index/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fifo_get/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: fifo_put/8:
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

 - Creating a specialized node of pfe_rtable_configure_table/85 for all known contexts.
    replacing param #1 rtable with const &pfe_rtable
 - Creating a specialized node of pfe_rtable_create_stats_table/83 for all known contexts.
    replacing param #1 conntrack_count with const 21
 - Creating a specialized node of pfe_rtable_invalidate/25 for all known contexts.
    replacing param #0 rtable with const &pfe_rtable
 - Creating a specialized node of pfe_get_crc32_be/24 for all known contexts.
    replacing param #0 crc with const 4294967295
    replacing param #2 len with const 4
Propagated bits info for function pfe_get_crc32_be.constprop/381:
 param 0: value = 0xffffffff, mask = 0x0
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x4, mask = 0x0
Propagated bits info for function pfe_rtable_invalidate.constprop/380:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_rtable_create_stats_table.constprop/379:
 param 1: value = 0x15, mask = 0x0
Propagated bits info for function pfe_rtable_configure_table.constprop/378:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_rtable_entry_get_hash.isra.0/338:
 param 1: value = 0x0, mask = 0x1
Propagated bits info for function oal_mutex_unlock.part.0/334:
 param 0: value = 0x50, mask = 0x1f
Propagated bits info for function oal_mutex_lock.part.0/333:
 param 0: value = 0x50, mask = 0x1f
Propagated bits info for function pfe_rtable_configure_table/85:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_rtable_create_stats_table/83:
 param 1: value = 0x15, mask = 0x0
Propagated bits info for function pfe_rtable_add_entry_id/75:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_rtable_add_entry_link/74:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_rtable_add_entry_get_phys_pa/73:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_rtable_entry_free_nolock/32:
 param 1: value = 0x0, mask = 0x1
Propagated bits info for function pfe_rtable_invalidate/25:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_get_crc32_be/24:
 param 0: value = 0xffffffff, mask = 0x0
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x4, mask = 0x0

IPA constant propagation end

Reclaiming functions: pfe_rtable_configure_table/85 pfe_rtable_create_stats_table/83 pfe_rtable_invalidate/25 pfe_get_crc32_be/24
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_get_crc32_be.constprop.0/381 (pfe_get_crc32_be.constprop) @076f3620
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of pfe_get_crc32_be/24
  Availability: local
  Function flags: count:14744043 (estimated locally) local optimize_size
  Called by: pfe_rtable_entry_get_hash.isra.0/338 (420086786 (estimated locally),0.50 per call) pfe_rtable_entry_get_hash.isra.0/338 (214748365 (estimated locally),0.26 per call) 
  Calls: 
pfe_rtable_invalidate.constprop.0/380 (pfe_rtable_invalidate.constprop) @076f3000
  Type: function definition analyzed
  Visibility:
  References: pfe_rtable/18 (addr)
  Referring: 
  Clone of pfe_rtable_invalidate/25
  Availability: local
  Function flags: count:118111600 (estimated locally) local optimize_size
  Called by: pfe_rtable_configure_table.constprop/378 (429497 (estimated locally),0.00 per call) 
  Calls: 
pfe_rtable_create_stats_table.constprop.0/379 (pfe_rtable_create_stats_table.constprop) @0768a460
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of pfe_rtable_create_stats_table/83
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: pfe_rtable_create/86 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_class_dmem_heap_alloc/323 (1073741823 (estimated locally),1.00 per call) pfe_hm_report/100 (536870911 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/101 (536870911 (estimated locally),0.50 per call) pfe_class_get_mmap/324 (536870911 (estimated locally),0.50 per call) pfe_hm_report/100 (268435456 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/101 (268435456 (estimated locally),0.25 per call) pfe_class_write_dmem/325 (268435456 (estimated locally),0.25 per call) pfe_hm_report/100 (88583700 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/101 (88583700 (estimated locally),0.08 per call) pfe_class_dmem_heap_free/326 (88583700 (estimated locally),0.08 per call) 
pfe_rtable_configure_table.constprop.0/378 (pfe_rtable_configure_table.constprop) @075dc380
  Type: function definition analyzed
  Visibility:
  References: pfe_rtable_fifo/17 (addr)pfe_rtable_fifo/17 (addr)pfe_rtable_entries/14 (addr)pfe_rtable_entries_isa_def/20 (addr)pfe_rtable/18 (addr)
  Referring: 
  Clone of pfe_rtable_configure_table/85
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_rtable_create/86 (488689700 (estimated locally),0.46 per call) 
  Calls: pfe_class_set_rtable/327 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/100 (1073312328 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (1073312328 (estimated locally),1.00 per call) pfe_rtable_destroy/88 (1073312328 (estimated locally),1.00 per call) pfe_rtable_invalidate.constprop/380 (429497 (estimated locally),0.00 per call) fifo_create/328 (429497 (estimated locally),0.00 per call) pfe_hm_report/100 (34102 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (34102 (estimated locally),0.00 per call) pfe_rtable_destroy/88 (34102 (estimated locally),0.00 per call) fifo_put/8 (3492853 (estimated locally),0.00 per call) pfe_hm_report/100 (192107 (estimated locally),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (192107 (estimated locally),0.00 per call) pfe_rtable_destroy/88 (192107 (estimated locally),0.00 per call) isa_init/329 (203288 (estimated locally),0.00 per call) 
pfe_rtable_clear_stats.part.0/375 (pfe_rtable_clear_stats.part.0) @0a80c7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_rtable_clear_stats/97 (375809640 (estimated locally),0.35 per call) 
  Calls: pfe_hm_report/100 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_set_dip.part.0/344 (pfe_rtable_entry_set_dip.part.0) @0a7f98c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_rtable_entry_set_dip/37 (145547982 (estimated locally),0.14 per call) 
  Calls: pfe_hm_report/100 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_set_sip.part.0/343 (pfe_rtable_entry_set_sip.part.0) @0a7f9700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_rtable_entry_set_sip/35 (145547982 (estimated locally),0.14 per call) 
  Calls: pfe_hm_report/100 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_add_entry_validate.isra.0/340 (pfe_rtable_add_entry_validate.isra.0) @079c6ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry/77 (226667973 (estimated locally),0.21 per call) 
  Calls: pfe_class_rtable_lookup_enable/320 (354334802 (estimated locally),0.33 per call) pfe_rtable_get_by_phys_entry_va/23 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_free_nolock.part.0/339 (pfe_rtable_entry_free_nolock.part.0) @073dfb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: pfe_rtable_entries/14 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_rtable_entry_free_nolock/32 (92449170 (estimated locally),0.09 per call) 
  Calls: isa_release/207 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_get_hash.isra.0/338 (pfe_rtable_entry_get_hash.isra.0) @073df8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:840173572 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry_id/75 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/101 (205338421 (estimated locally),0.24 per call) pfe_hm_report/100 (205338421 (estimated locally),0.24 per call) pfe_get_crc32_be.constprop/381 (214748365 (estimated locally),0.26 per call) pfe_get_crc32_be.constprop/381 (420086786 (estimated locally),0.50 per call) 
pfe_rtable_phys_entry_get_pa.part.0/336 (pfe_rtable_phys_entry_get_pa.part.0) @0700d9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_rtable_phys_entry_get_pa/29 (708669600 (estimated locally),0.66 per call) 
  Calls: pfe_rtable_phys_entry_is_pool/28 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_get_free_stats_index.isra.0/335 (pfe_rtable_get_free_stats_index.isra.0) @0700d700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: stats_tbl_index/13 (read)stats_tbl_index/13 (write)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry_id/75 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_mutex_unlock.part.0/334 (oal_mutex_unlock.part.0) @06fba540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_rtable_do_timeouts/82 (118111601 (estimated locally),1.00 per call) pfe_rtable_del_entry/78 (1073741824 (estimated locally),1.00 per call) pfe_rtable_add_entry/77 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_child/69 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_timeout/61 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_pppoe_sid/57 (257726846 (estimated locally),0.24 per call) pfe_rtable_entry_set_out_inner_vlan/56 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_vlan/54 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_mac_addrs/53 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_remove_ttl_decrement/52 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_ttl_decrement/51 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_dport/50 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_sport/49 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_dip/48 (313786814 (estimated locally),0.29 per call) pfe_rtable_entry_set_out_sip/47 (313786814 (estimated locally),0.29 per call) pfe_rtable_entry_free/33 (401890827 (estimated locally),0.37 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/333 (oal_mutex_lock.part.0) @06d60d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_rtable_do_timeouts/82 (118111600 (estimated locally),1.00 per call) pfe_rtable_del_entry/78 (1073741824 (estimated locally),1.00 per call) pfe_rtable_add_entry/77 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_child/69 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_timeout/61 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_pppoe_sid/57 (257726846 (estimated locally),0.24 per call) pfe_rtable_entry_set_out_inner_vlan/56 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_vlan/54 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_mac_addrs/53 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_remove_ttl_decrement/52 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_ttl_decrement/51 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_dport/50 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_sport/49 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_set_out_dip/48 (313786814 (estimated locally),0.29 per call) pfe_rtable_entry_set_out_sip/47 (313786814 (estimated locally),0.29 per call) pfe_rtable_entry_free/33 (401890827 (estimated locally),0.37 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
pfe_class_get_num_of_pes/332 (pfe_class_get_num_of_pes) @077ff460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_get_stats/96 (1073741824 (estimated locally),9.35 per call) 
  Calls: 
pfe_class_read_dmem/331 (pfe_class_read_dmem) @077ff380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_get_stats/96 (1014686025 (estimated locally),8.83 per call) 
  Calls: 
fifo_destroy/330 (fifo_destroy) @077e8b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_destroy/88 (0 (precise),0.00 per call) 
  Calls: 
isa_init/329 (isa_init) @077e87e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_configure_table.constprop/378 (203288 (estimated locally),0.00 per call) 
  Calls: 
fifo_create/328 (fifo_create) @077e8700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_configure_table.constprop/378 (429497 (estimated locally),0.00 per call) 
  Calls: 
pfe_class_set_rtable/327 (pfe_class_set_rtable) @077e8620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_configure_table.constprop/378 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_dmem_heap_free/326 (pfe_class_dmem_heap_free) @077e8460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_create_stats_table.constprop/379 (88583700 (estimated locally),0.08 per call) pfe_rtable_destroy_stats_table/84 (88583700 (estimated locally),0.08 per call) 
  Calls: 
pfe_class_write_dmem/325 (pfe_class_write_dmem) @077e8380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_create_stats_table.constprop/379 (268435456 (estimated locally),0.25 per call) pfe_rtable_clear_stats/97 (697932186 (estimated locally),0.65 per call) pfe_rtable_destroy_stats_table/84 (177167401 (estimated locally),0.17 per call) 
  Calls: 
pfe_class_get_mmap/324 (pfe_class_get_mmap) @077e82a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_create_stats_table.constprop/379 (536870911 (estimated locally),0.50 per call) pfe_rtable_destroy_stats_table/84 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_class_dmem_heap_alloc/323 (pfe_class_dmem_heap_alloc) @077e81c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_create_stats_table.constprop/379 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
oal_mm_virt_to_phys_contig/322 (oal_mm_virt_to_phys_contig) @077e8000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_create/86 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_rtable_lookup_disable/321 (pfe_class_rtable_lookup_disable) @077be8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_del_entry/78 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_class_rtable_lookup_enable/320 (pfe_class_rtable_lookup_enable) @077be620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_add_entry_validate.isra.0/340 (354334802 (estimated locally),0.33 per call) 
  Calls: 
oal_time_usleep/319 (oal_time_usleep) @07792b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_del_entry_nolock_htable/79 (201326592 (estimated locally),0.19 per call) pfe_rtable_del_entry_nolock_htable/79 (872415233 (estimated locally),0.81 per call) pfe_rtable_del_entry_nolock_pool/80 (1073741824 (estimated locally),1.00 per call) pfe_rtable_add_entry_link/74 (37904965 (estimated locally),0.11 per call) 
  Calls: 
__builtin_expect/318 (__builtin_expect) @07792ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: fifo_put/8 (1073741824 (estimated locally),1.00 per call) fifo_get/9 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_l2br_get_vlan_stats_index/317 (pfe_l2br_get_vlan_stats_index) @07792a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_add_entry_id/75 (153493589 (estimated locally),0.14 per call) 
  Calls: 
pfe_l2br_get_first_domain/316 (pfe_l2br_get_first_domain) @077929a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_add_entry_id/75 (287064877 (estimated locally),0.27 per call) 
  Calls: 
autolibc_memcmp/315 (autolibc_memcmp) @077927e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_match_criterion/92 (67108864 (estimated locally),0.06 per call) 
  Calls: 
pfe_phy_if_get_id/314 (pfe_phy_if_get_id) @07764ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_match_criterion/92 (134217728 (estimated locally),0.12 per call) pfe_rtable_entry_set_dstif/46 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memcpy/313 (autolibc_memcpy) @07764460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_del_entry_nolock_htable/79 (872415233 (estimated locally),0.81 per call) pfe_rtable_get_first/94 (178956971 (estimated locally),0.17 per call) pfe_rtable_get_first/94 (178956971 (estimated locally),0.17 per call) pfe_rtable_get_first/94 (178956971 (estimated locally),0.17 per call) pfe_rtable_entry_to_5t_out/91 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_to_5t_out/91 (708669605 (estimated locally),0.66 per call) pfe_rtable_entry_to_5t_out/91 (365072220 (estimated locally),0.34 per call) pfe_rtable_entry_to_5t_out/91 (365072220 (estimated locally),0.34 per call) pfe_rtable_add_entry/77 (226667973 (estimated locally),0.21 per call) pfe_rtable_entry_get_dip/38 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_sip/36 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_to_5t/90 (351718093 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (351718093 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_set_out_mac_addrs/53 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_set_out_mac_addrs/53 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_set_out_dip/48 (352985512 (estimated locally),0.33 per call) pfe_rtable_entry_set_out_dip/48 (233860969 (estimated locally),0.22 per call) pfe_rtable_entry_set_out_sip/47 (352985512 (estimated locally),0.33 per call) pfe_rtable_entry_set_out_sip/47 (233860969 (estimated locally),0.22 per call) pfe_rtable_entry_set_dip/37 (391322932 (estimated locally),0.36 per call) pfe_rtable_entry_set_dip/37 (348966093 (estimated locally),0.33 per call) pfe_rtable_entry_set_sip/35 (391322932 (estimated locally),0.36 per call) pfe_rtable_entry_set_sip/35 (348966093 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/312 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @077641c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/311 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @077640e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/310 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @07764000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/309 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @07762ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/308 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @07762e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/307 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @07762d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/306 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @07762c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/305 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07762b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/304 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07762a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/303 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @077629a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/302 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @077628c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/301 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @077627e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/300 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @07762700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/299 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @07762620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/298 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @07762540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/297 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07762460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/296 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07762380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/295 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @077622a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/294 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @077621c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/293 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @077620e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/292 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @07762000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/291 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @07761ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/290 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @07761e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/289 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @07761d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/288 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @07761c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/287 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07761b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/286 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07761a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/285 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @077619a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/284 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @077618c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/283 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @077617e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/282 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @07761700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/281 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07761620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/280 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @07761540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/279 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07761460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/278 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07761380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/277 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @077612a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/276 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @077611c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/275 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @077610e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/274 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @07761000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/273 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @07760ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/272 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @07760e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/271 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07760d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/270 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07760c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/269 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07760b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/268 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07760a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/267 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @077609a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/266 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @077608c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/265 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @077607e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/264 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @07760700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/263 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @07760620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/262 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @07760540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/261 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07760460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/260 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07760380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/259 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @077602a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/258 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @077601c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/257 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @077600e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/256 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @07760000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/255 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @0775fee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/254 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @0775fe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/253 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @0775fd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/252 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @0775fc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/251 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @0775fb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/250 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @0775fa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/249 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @0775f9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/248 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @0775f8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/247 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @0775f7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/246 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @0775f700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/245 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @0775f620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/244 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @0775f540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/243 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @0775f460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/242 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @0775f380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/241 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @0775f2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/240 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @0775f1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/239 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @0775f0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/238 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @0775f000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/237 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @0775eee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/236 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @0775ee00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/235 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0775ed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/234 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @0775ec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/233 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @0775eb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/232 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @0775ea80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/231 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @0775e9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/230 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @0775e8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/229 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @0775e7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/228 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @0775e700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/227 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @0775e620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/226 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @0775e540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/225 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @0775e460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/224 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0775e380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/223 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0775e2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/222 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0775e1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/221 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0775e0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/220 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0775e000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/219 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0775aa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/218 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0775aee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/217 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0775ae00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/216 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0775ad20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/215 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0775ac40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/214 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0775ab60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/213 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0775a9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/212 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0775a8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/211 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0775a7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/210 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0775a700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/209 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0775a620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/208 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0775a540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
isa_release/207 (isa_release) @0775a380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_entry_free_nolock.part.0/339 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/206 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0775a1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/205 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0775a0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/204 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0775a000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/203 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @07758ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/202 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @07758e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/201 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @07758d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/200 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @07758c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/199 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07758b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/198 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07758a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/197 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @077589a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/196 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @077588c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/195 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @077587e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/194 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @07758700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/193 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @07758620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/192 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @07758540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/191 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07758460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/190 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07758380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/189 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @077582a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/188 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @077581c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/187 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @077580e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/186 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @07758000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/185 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @07757ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/184 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @07757e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/183 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @07757d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/182 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @07757c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/181 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07757b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/180 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07757a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/179 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @077579a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/178 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @077578c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/177 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @077577e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/176 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @07757700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/175 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07757620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/174 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @07757540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/173 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07757460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/172 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07757380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/171 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @077572a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/170 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @077571c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/169 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @077570e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/168 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @07757000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/167 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @07756ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/166 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @07756e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/165 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07756d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/164 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07756c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/163 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07756b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/162 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07756a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/161 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @077569a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/160 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @077568c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/159 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @077567e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/158 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @07756700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/157 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @07756620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/156 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @07756540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/155 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07756460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/154 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07756380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/153 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @077562a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/152 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @077561c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/151 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @077560e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/150 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @07756000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/149 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @07753ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/148 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @07753e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/147 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @07753d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/146 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @07753c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/145 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07753b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/144 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07753a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/143 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @077539a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/142 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @077538c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/141 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @077537e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/140 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @07753700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/139 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @07753620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/138 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @07753540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/137 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @07753460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/136 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07753380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/135 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @077532a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/134 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @077531c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/133 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @077530e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/132 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @07753000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/131 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @07752ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/130 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @07752e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/129 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @07752d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/128 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @07752c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/127 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07752b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/126 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07752a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/125 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @077529a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/124 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @077528c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/123 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @077527e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/122 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @07752700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/121 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @07752620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/120 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @07752540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/119 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @07752460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/118 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @07752380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/117 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @077522a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/116 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @077521c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/115 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @077520e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/114 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @07752000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/113 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @07750a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/112 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @07750ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/111 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @07750e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/110 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @07750d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/109 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @07750c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/108 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @07750b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/107 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @077509a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/106 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @077508c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/105 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @077507e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/104 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @07750700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/103 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @07750620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/102 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @07750540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/101 (oal_util_raise_dem_for_drv_runtime_err) @077502a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_create_stats_table.constprop/379 (536870911 (estimated locally),0.50 per call) pfe_rtable_create_stats_table.constprop/379 (268435456 (estimated locally),0.25 per call) pfe_rtable_create_stats_table.constprop/379 (88583700 (estimated locally),0.08 per call) pfe_rtable_configure_table.constprop/378 (1073312328 (estimated locally),1.00 per call) pfe_rtable_configure_table.constprop/378 (34102 (estimated locally),0.00 per call) pfe_rtable_configure_table.constprop/378 (192107 (estimated locally),0.00 per call) pfe_rtable_do_timeouts/82 (477815112 (estimated locally),4.05 per call) pfe_rtable_del_entry_nolock/81 (395664414 (estimated locally),0.37 per call) pfe_rtable_del_entry_nolock_htable/79 (58270358 (estimated locally),0.05 per call) pfe_rtable_clear_stats.part.0/375 (1073741824 (estimated locally),1.00 per call) pfe_rtable_get_stats/96 (37904966 (estimated locally),0.33 per call) pfe_rtable_get_first/94 (178956971 (estimated locally),0.17 per call) pfe_rtable_entry_is_duplicate/72 (80820822 (estimated locally),0.33 per call) pfe_rtable_match_criterion/92 (134217728 (estimated locally),0.12 per call) pfe_rtable_match_criterion/92 (67108864 (estimated locally),0.06 per call) pfe_rtable_entry_get_dip/38 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_get_sip/36 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (367688929 (estimated locally),0.34 per call) pfe_rtable_create/86 (585052125 (estimated locally),0.54 per call) pfe_rtable_entry_set_out_pppoe_sid/57 (237404317 (estimated locally),0.22 per call) pfe_rtable_entry_set_out_pppoe_sid/57 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_set_out_dip/48 (486895342 (estimated locally),0.45 per call) pfe_rtable_entry_set_out_sip/47 (486895342 (estimated locally),0.45 per call) pfe_rtable_entry_set_dip/37 (187904819 (estimated locally),0.17 per call) pfe_rtable_entry_set_dip.part.0/344 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_set_sip/35 (187904819 (estimated locally),0.17 per call) pfe_rtable_entry_set_sip.part.0/343 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_create/31 (322122547 (estimated locally),0.30 per call) pfe_rtable_destroy_stats_table/84 (88583700 (estimated locally),0.08 per call) pfe_rtable_destroy_stats_table/84 (177167401 (estimated locally),0.17 per call) pfe_rtable_del_entry_nolock_pool/80 (354334802 (estimated locally),0.33 per call) pfe_rtable_add_entry_get_phys_pa/73 (29503018 (estimated locally),0.03 per call) pfe_rtable_add_entry_get_phys_pa/73 (187153200 (estimated locally),0.17 per call) pfe_rtable_entry_get_hash.isra.0/338 (205338421 (estimated locally),0.24 per call) 
  Calls: 
pfe_hm_report/100 (pfe_hm_report) @077501c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_create_stats_table.constprop/379 (536870911 (estimated locally),0.50 per call) pfe_rtable_create_stats_table.constprop/379 (268435456 (estimated locally),0.25 per call) pfe_rtable_create_stats_table.constprop/379 (88583700 (estimated locally),0.08 per call) pfe_rtable_configure_table.constprop/378 (1073312328 (estimated locally),1.00 per call) pfe_rtable_configure_table.constprop/378 (34102 (estimated locally),0.00 per call) pfe_rtable_configure_table.constprop/378 (192107 (estimated locally),0.00 per call) pfe_rtable_do_timeouts/82 (477815112 (estimated locally),4.05 per call) pfe_rtable_del_entry_nolock/81 (395664414 (estimated locally),0.37 per call) pfe_rtable_del_entry_nolock_htable/79 (58270358 (estimated locally),0.05 per call) pfe_rtable_clear_stats.part.0/375 (1073741824 (estimated locally),1.00 per call) pfe_rtable_get_stats/96 (37904966 (estimated locally),0.33 per call) pfe_rtable_get_first/94 (178956971 (estimated locally),0.17 per call) pfe_rtable_entry_is_duplicate/72 (80820822 (estimated locally),0.33 per call) pfe_rtable_match_criterion/92 (134217728 (estimated locally),0.12 per call) pfe_rtable_match_criterion/92 (67108864 (estimated locally),0.06 per call) pfe_rtable_entry_get_dip/38 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_get_sip/36 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (367688929 (estimated locally),0.34 per call) pfe_rtable_create/86 (585052125 (estimated locally),0.54 per call) pfe_rtable_entry_set_out_pppoe_sid/57 (237404317 (estimated locally),0.22 per call) pfe_rtable_entry_set_out_pppoe_sid/57 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_set_out_dip/48 (486895342 (estimated locally),0.45 per call) pfe_rtable_entry_set_out_sip/47 (486895342 (estimated locally),0.45 per call) pfe_rtable_entry_set_dip/37 (187904819 (estimated locally),0.17 per call) pfe_rtable_entry_set_dip.part.0/344 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_set_sip/35 (187904819 (estimated locally),0.17 per call) pfe_rtable_entry_set_sip.part.0/343 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_create/31 (322122547 (estimated locally),0.30 per call) pfe_rtable_destroy_stats_table/84 (88583700 (estimated locally),0.08 per call) pfe_rtable_destroy_stats_table/84 (177167401 (estimated locally),0.17 per call) pfe_rtable_del_entry_nolock_pool/80 (354334802 (estimated locally),0.33 per call) pfe_rtable_add_entry_get_phys_pa/73 (29503018 (estimated locally),0.03 per call) pfe_rtable_add_entry_get_phys_pa/73 (187153200 (estimated locally),0.17 per call) pfe_rtable_entry_get_hash.isra.0/338 (205338421 (estimated locally),0.24 per call) 
  Calls: 
autolibc_memset/99 (autolibc_memset) @077500e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_del_entry_nolock_htable/79 (201326592 (estimated locally),0.19 per call) pfe_rtable_del_entry_nolock_htable/79 (872415233 (estimated locally),0.81 per call) pfe_rtable_get_stats/96 (114863532 (estimated locally),1.00 per call) pfe_rtable_entry_to_5t_out/91 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_to_5t/90 (1073741824 (estimated locally),1.00 per call) pfe_rtable_create/86 (1073741824 (estimated locally),1.00 per call) pfe_rtable_create/86 (1073741824 (estimated locally),1.00 per call) pfe_rtable_destroy/88 (751619278 (estimated locally),0.70 per call) pfe_rtable_entry_create/31 (751619278 (estimated locally),0.70 per call) pfe_rtable_del_entry_nolock_pool/80 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
isa_reserve/98 (isa_reserve) @07750000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_rtable_entry_create/31 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_clear_stats/97 (pfe_rtable_clear_stats) @07744e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_rtable_clear_stats_stat/19 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_rtable_del_entry_nolock_htable/79 (354334802 (estimated locally),0.33 per call) 
  Calls: pfe_class_write_dmem/325 (697932186 (estimated locally),0.65 per call) pfe_rtable_clear_stats.part.0/375 (375809640 (estimated locally),0.35 per call) 
pfe_rtable_get_stats/96 (pfe_rtable_get_stats) @077449a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_get_num_of_pes/332 (1073741824 (estimated locally),9.35 per call) pfe_class_read_dmem/331 (1014686025 (estimated locally),8.83 per call) autolibc_memset/99 (114863532 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (37904966 (estimated locally),0.33 per call) pfe_hm_report/100 (37904966 (estimated locally),0.33 per call) 
pfe_rtable_get_next/95 (pfe_rtable_get_next) @07744540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:122750723 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_rtable_match_criterion/92 (542552617 (estimated locally),4.42 per call) 
pfe_rtable_get_first/94 (pfe_rtable_get_first) @077440e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073527120 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_rtable_prepare_first_entry/93 (894784854 (estimated locally),0.83 per call) oal_util_raise_dem_for_drv_runtime_err/101 (178956971 (estimated locally),0.17 per call) pfe_hm_report/100 (178956971 (estimated locally),0.17 per call) autolibc_memcpy/313 (178956971 (estimated locally),0.17 per call) autolibc_memcpy/313 (178956971 (estimated locally),0.17 per call) autolibc_memcpy/313 (178956971 (estimated locally),0.17 per call) 
pfe_rtable_prepare_first_entry/93 (pfe_rtable_prepare_first_entry) @077328c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:104460865 (estimated locally) body local optimize_size
  Called by: pfe_rtable_get_first/94 (894784854 (estimated locally),0.83 per call) 
  Calls: pfe_rtable_match_criterion/92 (542552618 (estimated locally),5.19 per call) 
pfe_rtable_match_criterion/92 (pfe_rtable_match_criterion) @07732ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_get_next/95 (542552617 (estimated locally),4.42 per call) pfe_rtable_entry_is_duplicate/72 (1014686025 (estimated locally),4.14 per call) pfe_rtable_prepare_first_entry/93 (542552618 (estimated locally),5.19 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/101 (134217728 (estimated locally),0.12 per call) pfe_hm_report/100 (134217728 (estimated locally),0.12 per call) autolibc_memcmp/315 (67108864 (estimated locally),0.06 per call) oal_util_raise_dem_for_drv_runtime_err/101 (67108864 (estimated locally),0.06 per call) pfe_hm_report/100 (67108864 (estimated locally),0.06 per call) pfe_rtable_entry_to_5t/90 (134217728 (estimated locally),0.12 per call) pfe_phy_if_get_id/314 (134217728 (estimated locally),0.12 per call) 
pfe_rtable_entry_to_5t_out/91 (pfe_rtable_entry_to_5t_out) @07732a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/313 (708669605 (estimated locally),0.66 per call) autolibc_memcpy/313 (708669605 (estimated locally),0.66 per call) autolibc_memcpy/313 (365072220 (estimated locally),0.34 per call) autolibc_memcpy/313 (365072220 (estimated locally),0.34 per call) autolibc_memset/99 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_to_5t/90 (pfe_rtable_entry_to_5t) @077327e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_rtable_entry_is_duplicate/72 (244911582 (estimated locally),1.00 per call) pfe_rtable_match_criterion/92 (134217728 (estimated locally),0.12 per call) pfe_rtable_entry_get_dip/38 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_sip/36 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/101 (367688929 (estimated locally),0.34 per call) pfe_hm_report/100 (367688929 (estimated locally),0.34 per call) autolibc_memcpy/313 (351718093 (estimated locally),0.33 per call) autolibc_memcpy/313 (351718093 (estimated locally),0.33 per call) autolibc_memcpy/313 (354334802 (estimated locally),0.33 per call) autolibc_memcpy/313 (354334802 (estimated locally),0.33 per call) autolibc_memset/99 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_get_entry_size/89 (pfe_rtable_get_entry_size) @07732460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_destroy/88 (pfe_rtable_destroy) @077321c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_rtable_entries/14 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_rtable_configure_table.constprop/378 (1073312328 (estimated locally),1.00 per call) pfe_rtable_configure_table.constprop/378 (34102 (estimated locally),0.00 per call) pfe_rtable_configure_table.constprop/378 (192107 (estimated locally),0.00 per call) pfe_rtable_create/86 (585052125 (estimated locally),0.54 per call) 
  Calls: autolibc_memset/99 (751619278 (estimated locally),0.70 per call) pfe_rtable_destroy_stats_table/84 (751619278 (estimated locally),0.70 per call) fifo_destroy/330 (0 (precise),0.00 per call) 
pfe_rtable_get_size/87 (pfe_rtable_get_size) @07723c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_create/86 (pfe_rtable_create) @07723ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_rtable/18 (addr)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (read)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)pfe_rtable/18 (write)stats_tbl_index/13 (addr)pfe_rtable/18 (write)pfe_rtable/18 (read)pfe_rtable/18 (read)pfe_rtable/18 (addr)pfe_rtable/18 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_rtable_configure_table.constprop/378 (488689700 (estimated locally),0.46 per call) pfe_rtable_destroy/88 (585052125 (estimated locally),0.54 per call) oal_util_raise_dem_for_drv_runtime_err/101 (585052125 (estimated locally),0.54 per call) pfe_hm_report/100 (585052125 (estimated locally),0.54 per call) pfe_rtable_create_stats_table.constprop/379 (1073741824 (estimated locally),1.00 per call) autolibc_memset/99 (1073741824 (estimated locally),1.00 per call) oal_mm_virt_to_phys_contig/322 (1073741824 (estimated locally),1.00 per call) autolibc_memset/99 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_configure_table/85 (pfe_rtable_configure_table) @07723b60
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_destroy_stats_table/84 (pfe_rtable_destroy_stats_table) @07723620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_rtable_destroy/88 (751619278 (estimated locally),0.70 per call) 
  Calls: pfe_class_dmem_heap_free/326 (88583700 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/101 (88583700 (estimated locally),0.08 per call) pfe_hm_report/100 (88583700 (estimated locally),0.08 per call) pfe_class_write_dmem/325 (177167401 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/101 (177167401 (estimated locally),0.17 per call) pfe_hm_report/100 (177167401 (estimated locally),0.17 per call) pfe_class_get_mmap/324 (354334802 (estimated locally),0.33 per call) 
pfe_rtable_create_stats_table/83 (pfe_rtable_create_stats_table) @077231c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_do_timeouts/82 (pfe_rtable_do_timeouts) @0770b620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (118111601 (estimated locally),1.00 per call) pfe_rtable_entry_free_nolock/32 (477815112 (estimated locally),4.05 per call) oal_util_raise_dem_for_drv_runtime_err/101 (477815112 (estimated locally),4.05 per call) pfe_hm_report/100 (477815112 (estimated locally),4.05 per call) pfe_rtable_del_entry_nolock/81 (955630224 (estimated locally),8.09 per call) oal_mutex_lock.part.0/333 (118111600 (estimated locally),1.00 per call) 
   Indirect call(133386866 (estimated locally),1.13 per call) 
pfe_rtable_del_entry_nolock/81 (pfe_rtable_del_entry_nolock) @0770bc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_rtable_do_timeouts/82 (955630224 (estimated locally),8.09 per call) pfe_rtable_del_entry/78 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/101 (395664414 (estimated locally),0.37 per call) pfe_hm_report/100 (395664414 (estimated locally),0.37 per call) pfe_rtable_del_entry_nolock_pool/80 (203827122 (estimated locally),0.19 per call) pfe_rtable_phys_entry_is_pool/28 (599491536 (estimated locally),0.56 per call) pfe_rtable_del_entry_nolock_htable/79 (152127742 (estimated locally),0.14 per call) pfe_rtable_phys_entry_is_htable/27 (751619277 (estimated locally),0.70 per call) 
pfe_rtable_del_entry_nolock_pool/80 (pfe_rtable_del_entry_nolock_pool) @0770b8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_del_entry_nolock/81 (203827122 (estimated locally),0.19 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/101 (354334802 (estimated locally),0.33 per call) pfe_hm_report/100 (354334802 (estimated locally),0.33 per call) fifo_put/8 (1073741824 (estimated locally),1.00 per call) autolibc_memset/99 (1073741824 (estimated locally),1.00 per call) oal_time_usleep/319 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_del_entry_nolock_htable/79 (pfe_rtable_del_entry_nolock_htable) @0770b540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_del_entry_nolock/81 (152127742 (estimated locally),0.14 per call) 
  Calls: autolibc_memset/99 (201326592 (estimated locally),0.19 per call) oal_time_usleep/319 (201326592 (estimated locally),0.19 per call) pfe_rtable_phys_entry_get_pa/29 (872415233 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/101 (58270358 (estimated locally),0.05 per call) pfe_hm_report/100 (58270358 (estimated locally),0.05 per call) fifo_put/8 (176576843 (estimated locally),0.16 per call) pfe_rtable_phys_entry_is_pool/28 (872415233 (estimated locally),0.81 per call) autolibc_memset/99 (872415233 (estimated locally),0.81 per call) autolibc_memcpy/313 (872415233 (estimated locally),0.81 per call) oal_time_usleep/319 (872415233 (estimated locally),0.81 per call) pfe_rtable_free_stats_index/22 (354334802 (estimated locally),0.33 per call) pfe_rtable_clear_stats/97 (354334802 (estimated locally),0.33 per call) 
pfe_rtable_del_entry/78 (pfe_rtable_del_entry) @0770b1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (1073741824 (estimated locally),1.00 per call) pfe_class_rtable_lookup_disable/321 (354334802 (estimated locally),0.33 per call) pfe_rtable_del_entry_nolock/81 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/333 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_add_entry/77 (pfe_rtable_add_entry) @076f3d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (1073741824 (estimated locally),1.00 per call) pfe_rtable_add_entry_validate.isra.0/340 (226667973 (estimated locally),0.21 per call) autolibc_memcpy/313 (226667973 (estimated locally),0.21 per call) pfe_rtable_add_entry_id/75 (686872646 (estimated locally),0.64 per call) pfe_rtable_entry_is_duplicate/72 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/333 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_add_entry_id/75 (pfe_rtable_add_entry_id) @076f3ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry/77 (686872646 (estimated locally),0.64 per call) 
  Calls: pfe_rtable_add_entry_link/74 (1007304048 (estimated locally),0.94 per call) fifo_get/9 (354334802 (estimated locally),0.33 per call) pfe_l2br_get_vlan_stats_index/317 (153493589 (estimated locally),0.14 per call) pfe_l2br_get_first_domain/316 (287064877 (estimated locally),0.27 per call) pfe_rtable_get_free_stats_index.isra.0/335 (1073741824 (estimated locally),1.00 per call) pfe_rtable_entry_get_hash.isra.0/338 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_add_entry_link/74 (pfe_rtable_add_entry_link) @076f3c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:348071309 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry_id/75 (1007304048 (estimated locally),0.94 per call) 
  Calls: oal_time_usleep/319 (37904965 (estimated locally),0.11 per call) pfe_rtable_phys_entry_get_va/30 (1014686025 (estimated locally),2.92 per call) pfe_rtable_phys_entry_is_htable/27 (174035655 (estimated locally),0.50 per call) pfe_rtable_add_entry_get_phys_pa/73 (348071309 (estimated locally),1.00 per call) 
pfe_rtable_add_entry_get_phys_pa/73 (pfe_rtable_add_entry_get_phys_pa) @076f39a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry_link/74 (348071309 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/101 (29503018 (estimated locally),0.03 per call) pfe_hm_report/100 (29503018 (estimated locally),0.03 per call) fifo_put/8 (89403084 (estimated locally),0.08 per call) pfe_rtable_phys_entry_is_pool/28 (187153200 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/101 (187153200 (estimated locally),0.17 per call) pfe_hm_report/100 (187153200 (estimated locally),0.17 per call) pfe_rtable_phys_entry_get_pa/29 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_is_duplicate/72 (pfe_rtable_entry_is_duplicate) @076f3540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:244911582 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry/77 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_rtable_match_criterion/92 (1014686025 (estimated locally),4.14 per call) oal_util_raise_dem_for_drv_runtime_err/101 (80820822 (estimated locally),0.33 per call) pfe_hm_report/100 (80820822 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (244911582 (estimated locally),1.00 per call) 
pfe_rtable_entry_get_stats_index/70 (pfe_rtable_entry_get_stats_index) @076edb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_child/69 (pfe_rtable_entry_get_child) @076ed620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) pfe_rtable_entry_get_child_nolock/68 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_get_child_nolock/68 (pfe_rtable_entry_get_child_nolock) @076ed0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_rtable_entry_get_child/69 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_entry_set_child/67 (pfe_rtable_entry_set_child) @076edd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_refptr/66 (pfe_rtable_entry_get_refptr) @076eda80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_refptr/65 (pfe_rtable_entry_set_refptr) @076ed7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_callback/64 (pfe_rtable_entry_set_callback) @076ed540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_route_id/63 (pfe_rtable_entry_get_route_id) @076ed2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_route_id/62 (pfe_rtable_entry_set_route_id) @076ed000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_timeout/61 (pfe_rtable_entry_set_timeout) @076bda80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_get_action_flags/60 (pfe_rtable_entry_get_action_flags) @076bd380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_id5t/59 (pfe_rtable_entry_get_id5t) @076bdee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_id5t/58 (pfe_rtable_entry_set_id5t) @076bdc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_out_pppoe_sid/57 (pfe_rtable_entry_set_out_pppoe_sid) @076bd9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (257726846 (estimated locally),0.24 per call) oal_mutex_lock.part.0/333 (257726846 (estimated locally),0.24 per call) oal_util_raise_dem_for_drv_runtime_err/101 (237404317 (estimated locally),0.22 per call) pfe_hm_report/100 (237404317 (estimated locally),0.22 per call) oal_util_raise_dem_for_drv_runtime_err/101 (354334802 (estimated locally),0.33 per call) pfe_hm_report/100 (354334802 (estimated locally),0.33 per call) 
pfe_rtable_entry_set_out_inner_vlan/56 (pfe_rtable_entry_set_out_inner_vlan) @076bd540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_get_out_vlan/55 (pfe_rtable_entry_get_out_vlan) @076bd2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_out_vlan/54 (pfe_rtable_entry_set_out_vlan) @076bd000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_set_out_mac_addrs/53 (pfe_rtable_entry_set_out_mac_addrs) @076ada80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) autolibc_memcpy/313 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/313 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_remove_ttl_decrement/52 (pfe_rtable_entry_remove_ttl_decrement) @076ad460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_set_ttl_decrement/51 (pfe_rtable_entry_set_ttl_decrement) @076adee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_set_out_dport/50 (pfe_rtable_entry_set_out_dport) @076adc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_set_out_sport/49 (pfe_rtable_entry_set_out_sport) @076ad9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (574129754 (estimated locally),0.53 per call) oal_mutex_lock.part.0/333 (574129754 (estimated locally),0.53 per call) 
pfe_rtable_entry_set_out_dip/48 (pfe_rtable_entry_set_out_dip) @076ad700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (313786814 (estimated locally),0.29 per call) oal_mutex_lock.part.0/333 (313786814 (estimated locally),0.29 per call) oal_util_raise_dem_for_drv_runtime_err/101 (486895342 (estimated locally),0.45 per call) pfe_hm_report/100 (486895342 (estimated locally),0.45 per call) autolibc_memcpy/313 (352985512 (estimated locally),0.33 per call) autolibc_memcpy/313 (233860969 (estimated locally),0.22 per call) 
pfe_rtable_entry_set_out_sip/47 (pfe_rtable_entry_set_out_sip) @076ad380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (313786814 (estimated locally),0.29 per call) oal_mutex_lock.part.0/333 (313786814 (estimated locally),0.29 per call) oal_util_raise_dem_for_drv_runtime_err/101 (486895342 (estimated locally),0.45 per call) pfe_hm_report/100 (486895342 (estimated locally),0.45 per call) autolibc_memcpy/313 (352985512 (estimated locally),0.33 per call) autolibc_memcpy/313 (233860969 (estimated locally),0.22 per call) 
pfe_rtable_entry_set_dstif/46 (pfe_rtable_entry_set_dstif) @076ad000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_phy_if_get_id/314 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_set_dstif_id/45 (pfe_rtable_entry_set_dstif_id) @076a6b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_proto/44 (pfe_rtable_entry_get_proto) @076a6620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_proto/43 (pfe_rtable_entry_set_proto) @076a6000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_dport/42 (pfe_rtable_entry_get_dport) @076a6d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_dport/41 (pfe_rtable_entry_set_dport) @076a6a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_sport/40 (pfe_rtable_entry_get_sport) @076a67e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_set_sport/39 (pfe_rtable_entry_set_sport) @076a6540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_entry_get_dip/38 (pfe_rtable_entry_get_dip) @076a62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/313 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (354334802 (estimated locally),0.33 per call) pfe_hm_report/100 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_set_dip/37 (pfe_rtable_entry_set_dip) @0769bd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_rtable_entry_set_5t/34 (354334802 (estimated locally),0.33 per call) 
  Calls: autolibc_memcpy/313 (391322932 (estimated locally),0.36 per call) pfe_rtable_entry_set_dip.part.0/344 (145547982 (estimated locally),0.14 per call) autolibc_memcpy/313 (348966093 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/101 (187904819 (estimated locally),0.17 per call) pfe_hm_report/100 (187904819 (estimated locally),0.17 per call) 
pfe_rtable_entry_get_sip/36 (pfe_rtable_entry_get_sip) @0769b0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/313 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/101 (354334802 (estimated locally),0.33 per call) pfe_hm_report/100 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_to_5t/90 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_set_sip/35 (pfe_rtable_entry_set_sip) @0769bc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_rtable_entry_set_5t/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: autolibc_memcpy/313 (391322932 (estimated locally),0.36 per call) pfe_rtable_entry_set_sip.part.0/343 (145547982 (estimated locally),0.14 per call) autolibc_memcpy/313 (348966093 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/101 (187904819 (estimated locally),0.17 per call) pfe_hm_report/100 (187904819 (estimated locally),0.17 per call) 
pfe_rtable_entry_set_5t/34 (pfe_rtable_entry_set_5t) @0769b7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_rtable_entry_set_dip/37 (354334802 (estimated locally),0.33 per call) pfe_rtable_entry_set_sip/35 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_entry_free/33 (pfe_rtable_entry_free) @0769b540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/334 (401890827 (estimated locally),0.37 per call) pfe_rtable_entry_free_nolock/32 (751619277 (estimated locally),0.70 per call) oal_mutex_lock.part.0/333 (401890827 (estimated locally),0.37 per call) 
pfe_rtable_entry_free_nolock/32 (pfe_rtable_entry_free_nolock) @0769b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_do_timeouts/82 (477815112 (estimated locally),4.05 per call) pfe_rtable_entry_free/33 (751619277 (estimated locally),0.70 per call) 
  Calls: pfe_rtable_entry_free_nolock.part.0/339 (92449170 (estimated locally),0.09 per call) 
pfe_rtable_entry_create/31 (pfe_rtable_entry_create) @0769b000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_rtable_entries/14 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/101 (322122547 (estimated locally),0.30 per call) pfe_hm_report/100 (322122547 (estimated locally),0.30 per call) autolibc_memset/99 (751619278 (estimated locally),0.70 per call) isa_reserve/98 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_phys_entry_get_va/30 (pfe_rtable_phys_entry_get_va) @0768a7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry_link/74 (1014686025 (estimated locally),2.92 per call) 
  Calls: pfe_rtable_phys_entry_is_pool/28 (708669605 (estimated locally),0.66 per call) pfe_rtable_phys_entry_is_htable/27 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_phys_entry_get_pa/29 (pfe_rtable_phys_entry_get_pa) @0768ac40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_del_entry_nolock_htable/79 (872415233 (estimated locally),0.81 per call) pfe_rtable_add_entry_get_phys_pa/73 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_rtable_phys_entry_get_pa.part.0/336 (708669600 (estimated locally),0.66 per call) pfe_rtable_phys_entry_is_htable/27 (1073741824 (estimated locally),1.00 per call) 
pfe_rtable_phys_entry_is_pool/28 (pfe_rtable_phys_entry_is_pool) @0768a9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_del_entry_nolock/81 (599491536 (estimated locally),0.56 per call) pfe_rtable_del_entry_nolock_htable/79 (872415233 (estimated locally),0.81 per call) pfe_rtable_add_entry_get_phys_pa/73 (187153200 (estimated locally),0.17 per call) pfe_rtable_phys_entry_get_va/30 (708669605 (estimated locally),0.66 per call) pfe_rtable_phys_entry_get_pa.part.0/336 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_phys_entry_is_htable/27 (pfe_rtable_phys_entry_is_htable) @0768a700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_del_entry_nolock/81 (751619277 (estimated locally),0.70 per call) pfe_rtable_add_entry_link/74 (174035655 (estimated locally),0.50 per call) pfe_rtable_phys_entry_get_va/30 (1073741824 (estimated locally),1.00 per call) pfe_rtable_phys_entry_get_pa/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_rtable_invalidate/25 (pfe_rtable_invalidate) @075dc1c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_get_crc32_be/24 (pfe_get_crc32_be) @075dcd20
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:14744043 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_rtable_get_by_phys_entry_va/23 (pfe_rtable_get_by_phys_entry_va) @075dca80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:115301074 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry_validate.isra.0/340 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_free_stats_index/22 (pfe_rtable_free_stats_index) @075dc620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: stats_tbl_index/13 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_del_entry_nolock_htable/79 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_rtable_entries_isa_def/20 (pfe_rtable_entries_isa_def) @075ccf78
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_rtable_entries_index/15 (addr)pfe_rtable_entries_pool/16 (addr)
  Referring: pfe_rtable_configure_table.constprop.0/378 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_rtable_clear_stats_stat/19 (pfe_rtable_clear_stats_stat) @075ccea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_rtable_clear_stats/97 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_rtable/18 (pfe_rtable) @075cce10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_rtable_create/86 (addr)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (read)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (write)pfe_rtable_create/86 (read)pfe_rtable_create/86 (read)pfe_rtable_create/86 (addr)pfe_rtable_create/86 (addr)pfe_rtable_configure_table.constprop.0/378 (addr)pfe_rtable_invalidate.constprop.0/380 (addr)
  Availability: available
  Varpool flags:
pfe_rtable_fifo/17 (pfe_rtable_fifo) @075ccd80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_rtable_configure_table.constprop.0/378 (addr)pfe_rtable_configure_table.constprop.0/378 (addr)
  Availability: available
  Varpool flags:
pfe_rtable_entries_pool/16 (pfe_rtable_entries_pool) @075cccf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_rtable_entries_isa_def/20 (addr)
  Availability: available
  Varpool flags:
pfe_rtable_entries_index/15 (pfe_rtable_entries_index) @075ccc60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_rtable_entries_isa_def/20 (addr)
  Availability: available
  Varpool flags:
pfe_rtable_entries/14 (pfe_rtable_entries) @075ccbd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_rtable_destroy/88 (addr)pfe_rtable_entry_free_nolock.part.0/339 (addr)pfe_rtable_entry_create/31 (addr)pfe_rtable_configure_table.constprop.0/378 (addr)
  Availability: available
  Varpool flags:
stats_tbl_index/13 (stats_tbl_index) @075ccb40
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_rtable_free_stats_index/22 (write)pfe_rtable_get_free_stats_index.isra.0/335 (write)pfe_rtable_get_free_stats_index.isra.0/335 (read)pfe_rtable_create/86 (addr)
  Availability: available
  Varpool flags:
fifo_get/9 (fifo_get) @07014620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_add_entry_id/75 (354334802 (estimated locally),0.33 per call) 
  Calls: __builtin_expect/318 (1073741824 (estimated locally),1.00 per call) 
fifo_put/8 (fifo_put) @07014380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_rtable_configure_table.constprop/378 (3492853 (estimated locally),0.00 per call) pfe_rtable_del_entry_nolock_htable/79 (176576843 (estimated locally),0.16 per call) pfe_rtable_del_entry_nolock_pool/80 (1073741824 (estimated locally),1.00 per call) pfe_rtable_add_entry_get_phys_pa/73 (89403084 (estimated locally),0.08 per call) 
  Calls: __builtin_expect/318 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f03ca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/208 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/209 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/210 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/211 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/212 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/213 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/214 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/215 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/216 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/217 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/218 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/219 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/220 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/221 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/222 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/223 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/224 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/225 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/226 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/227 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/228 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/229 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/230 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/231 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/232 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/233 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/234 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/235 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/236 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/237 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/238 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/239 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/240 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/241 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/242 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/243 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/244 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/245 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/246 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/247 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/248 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/249 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/250 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/251 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/252 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/253 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/254 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/255 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/256 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/257 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/258 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/259 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/260 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/261 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/262 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/263 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/264 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/265 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/266 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/267 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/268 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/269 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/270 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/271 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/272 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/273 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/274 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/275 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/276 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/277 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/278 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/279 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/280 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/281 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/282 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/283 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/284 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/285 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/286 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/287 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/288 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/289 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/290 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/291 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/292 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/293 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/294 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/295 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/296 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/297 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/298 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/299 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/300 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/301 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/302 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/303 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/304 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/305 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/306 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/307 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/308 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/309 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/310 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/311 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/312 (addr)
  Referring: oal_mutex_unlock.part.0/334 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f03bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/102 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/103 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/104 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/105 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/106 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/107 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/108 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/109 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/110 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/111 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/112 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/113 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/114 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/115 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/116 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/117 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/118 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/119 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/120 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/121 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/122 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/123 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/124 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/125 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/126 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/127 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/128 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/129 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/130 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/131 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/132 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/133 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/134 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/135 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/136 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/137 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/138 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/139 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/140 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/141 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/142 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/143 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/144 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/145 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/146 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/147 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/148 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/149 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/150 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/151 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/152 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/153 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/154 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/155 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/156 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/157 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/158 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/159 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/160 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/161 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/162 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/163 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/164 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/165 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/166 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/167 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/168 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/169 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/170 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/171 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/172 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/173 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/174 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/175 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/176 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/177 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/178 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/179 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/180 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/181 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/182 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/183 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/184 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/185 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/186 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/187 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/188 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/189 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/190 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/191 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/192 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/193 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/194 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/195 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/196 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/197 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/198 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/199 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/200 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/201 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/202 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/203 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/204 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/205 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/206 (addr)
  Referring: oal_mutex_lock.part.0/333 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function pfe_rtable_phys_entry_is_htable (pfe_rtable_phys_entry_is_htable, funcdef_no=17, decl_uid=10639, cgraph_uid=18, symbol_order=27)

Modification phase of node pfe_rtable_phys_entry_is_htable/27
pfe_rtable_phys_entry_is_htable (const struct pfe_rtable_t * rtable, const struct pfe_ct_rtable_entry_t * phys_entry)
{
  bool_t ret;
  unsigned int _1;
  unsigned int phys_entry.16_2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = rtable_8(D)->htable_base_va;
  phys_entry.16_2 = (unsigned int) phys_entry_9(D);
  if (_1 <= phys_entry.16_2)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  _3 = rtable_8(D)->htable_end_va;
  if (phys_entry.16_2 < _3)
    goto <bb 7>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  _4 = rtable_8(D)->htable_base_pa;
  if (phys_entry.16_2 >= _4)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 402653184]:
  _5 = rtable_8(D)->htable_end_pa;
  if (phys_entry.16_2 < _5)
    goto <bb 7>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 603979777]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_6 = PHI <1(3), 1(5), 0(6)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_rtable_phys_entry_is_pool (pfe_rtable_phys_entry_is_pool, funcdef_no=18, decl_uid=10642, cgraph_uid=19, symbol_order=28)

Modification phase of node pfe_rtable_phys_entry_is_pool/28
pfe_rtable_phys_entry_is_pool (const struct pfe_rtable_t * rtable, const struct pfe_ct_rtable_entry_t * phys_entry)
{
  bool_t ret;
  unsigned int _1;
  unsigned int phys_entry.12_2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = rtable_8(D)->pool_base_va;
  phys_entry.12_2 = (unsigned int) phys_entry_9(D);
  if (_1 <= phys_entry.12_2)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  _3 = rtable_8(D)->pool_end_va;
  if (phys_entry.12_2 < _3)
    goto <bb 7>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  _4 = rtable_8(D)->pool_base_pa;
  if (phys_entry.12_2 >= _4)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 402653184]:
  _5 = rtable_8(D)->pool_end_pa;
  if (phys_entry.12_2 < _5)
    goto <bb 7>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 603979777]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_6 = PHI <1(3), 1(5), 0(6)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function fifo_put (fifo_put, funcdef_no=6, decl_uid=7255, cgraph_uid=7, symbol_order=8)

Modification phase of node fifo_put/8
fifo_put (volatile struct fifo_t * const fifo, void * const ptr)
{
  errno_t err;
  uint32_t fill_level;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  _Bool _4;
  long int _5;
  long int _6;
  void * * _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  void * * _12;
  long unsigned int _13;
  long unsigned int _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} fifo_18(D)->write;
  _2 ={v} fifo_18(D)->read;
  fill_level_19 = _1 - _2;
  # DEBUG fill_level => fill_level_19
  # DEBUG BEGIN_STMT
  _3 ={v} fifo_18(D)->depth;
  _4 = _3 > fill_level_19;
  _5 = (long int) _4;
  _6 = __builtin_expect (_5, 1);
  if (_6 != 0)
    goto <bb 3>; [90.00%]
  else
    goto <bb 4>; [10.00%]

  <bb 3> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _7 ={v} fifo_18(D)->data;
  _8 ={v} fifo_18(D)->write;
  _9 ={v} fifo_18(D)->depth_mask;
  _10 = _8 & _9;
  _11 = _10 * 4;
  _12 = _7 + _11;
  *_12 = ptr_20(D);
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" dmb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  _13 ={v} fifo_18(D)->write;
  _14 = _13 + 1;
  fifo_18(D)->write ={v} _14;
  # DEBUG BEGIN_STMT
  # DEBUG err => 0

  <bb 4> [local count: 1073741824]:
  # err_15 = PHI <0(3), 75(2)>
  # DEBUG err => err_15
  # DEBUG BEGIN_STMT
  return err_15;

}



;; Function oal_mutex_lock.part.0 (oal_mutex_lock.part.0, funcdef_no=88, decl_uid=11772, cgraph_uid=324, symbol_order=333)

Modification phase of node oal_mutex_lock.part.0/333
Adjusting mask for param 0 to 0x1f
Setting value range of param 0 [67, 82]
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



;; Function oal_mutex_unlock.part.0 (oal_mutex_unlock.part.0, funcdef_no=89, decl_uid=11777, cgraph_uid=325, symbol_order=334)

Modification phase of node oal_mutex_unlock.part.0/334
Adjusting mask for param 0 to 0x1f
Setting value range of param 0 [67, 82]
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



;; Function pfe_rtable_phys_entry_get_pa (pfe_rtable_phys_entry_get_pa, funcdef_no=19, decl_uid=10645, cgraph_uid=20, symbol_order=29)

Modification phase of node pfe_rtable_phys_entry_get_pa/29
pfe_rtable_phys_entry_get_pa (struct pfe_rtable_t * rtable, struct pfe_ct_rtable_entry_t * phys_entry_va)
{
  struct pfe_ct_rtable_entry_t * pa;
  unsigned char _1;
  long unsigned int phys_entry_va.10_2;
  unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_rtable_phys_entry_is_htable (rtable_8(D), phys_entry_va_9(D));
  if (_1 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  phys_entry_va.10_2 = (long unsigned int) phys_entry_va_9(D);
  _3 = rtable_8(D)->htable_va_pa_offset;
  _4 = phys_entry_va.10_2 - _3;
  pa_10 = (struct pfe_ct_rtable_entry_t *) _4;
  # DEBUG pa => pa_10
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 708669600]:
  pa_6 = pfe_rtable_phys_entry_get_pa.part.0 (rtable_8(D), phys_entry_va_9(D));

  <bb 5> [local count: 1073741824]:
  # pa_5 = PHI <pa_10(3), pa_6(4)>
  # DEBUG pa => pa_5
  # DEBUG BEGIN_STMT
  return pa_5;

}



;; Function pfe_get_crc32_be.constprop (pfe_get_crc32_be.constprop.0, funcdef_no=99, decl_uid=11981, cgraph_uid=372, symbol_order=381)

Modification phase of node pfe_get_crc32_be.constprop/381
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
pfe_get_crc32_be.constprop (uint8_t * data)
{
  uint32_t tempcrc;
  uint16 idx;
  uint8_t i;
  uint32_t crc;
  uint16_t len;
  sizetype _2;
  uint8_t * _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _11;
  signed int tempcrc.6_12;
  long unsigned int iftmp.5_13;

  <bb 11> [local count: 14744043]:
  # DEBUG len => 4
  # DEBUG crc => 4294967295

  <bb 2> [local count: 14744043]:
  # DEBUG BEGIN_STMT
  # DEBUG tempcrc => 4294967295
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG idx => 0
  goto <bb 9>; [100.00%]

  <bb 3> [local count: 119292716]:
  # DEBUG BEGIN_STMT
  _2 = (sizetype) idx_1;
  _4 = data_3(D) + _2;
  _5 = *_4;
  _6 = (long unsigned int) _5;
  _7 = _6 << 24;
  tempcrc_9 = _7 ^ tempcrc_8;
  # DEBUG tempcrc => tempcrc_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 954449108]:
  # DEBUG BEGIN_STMT
  _11 = tempcrc_10 << 1;
  tempcrc.6_12 = (signed int) tempcrc_10;
  if (tempcrc.6_12 < 0)
    goto <bb 6>; [41.00%]
  else
    goto <bb 5>; [59.00%]

  <bb 5> [local count: 563124975]:

  <bb 6> [local count: 954449110]:
  # iftmp.5_13 = PHI <79764919(4), 0(5)>
  tempcrc_14 = _11 ^ iftmp.5_13;
  # DEBUG tempcrc => tempcrc_14
  # DEBUG BEGIN_STMT
  i_16 = i_15 + 1;
  # DEBUG i => i_16

  <bb 7> [local count: 1073741824]:
  # tempcrc_10 = PHI <tempcrc_9(3), tempcrc_14(6)>
  # i_15 = PHI <0(3), i_16(6)>
  # DEBUG i => i_15
  # DEBUG tempcrc => tempcrc_10
  # DEBUG BEGIN_STMT
  if (i_15 != 8)
    goto <bb 4>; [88.89%]
  else
    goto <bb 8>; [11.11%]

  <bb 8> [local count: 119292717]:
  # tempcrc_19 = PHI <tempcrc_10(7)>
  # DEBUG BEGIN_STMT
  idx_17 = idx_1 + 1;
  # DEBUG idx => idx_17

  <bb 9> [local count: 134036760]:
  # tempcrc_8 = PHI <4294967295(2), tempcrc_19(8)>
  # idx_1 = PHI <0(2), idx_17(8)>
  # DEBUG idx => idx_1
  # DEBUG tempcrc => tempcrc_8
  # DEBUG BEGIN_STMT
  if (idx_1 <= 3)
    goto <bb 3>; [89.00%]
  else
    goto <bb 10>; [11.00%]

  <bb 10> [local count: 14744044]:
  # tempcrc_18 = PHI <tempcrc_8(9)>
  # DEBUG BEGIN_STMT
  return tempcrc_18;

}



;; Function pfe_rtable_entry_create (pfe_rtable_entry_create, funcdef_no=21, decl_uid=10450, cgraph_uid=22, symbol_order=31)

Modification phase of node pfe_rtable_entry_create/31
pfe_rtable_entry_create ()
{
  struct pfe_rtable_entry_t * entry;
  struct pfe_ct_rtable_entry_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_5 = isa_reserve (&pfe_rtable_entries);
  # DEBUG entry => entry_5
  # DEBUG BEGIN_STMT
  if (entry_5 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  autolibc_memset (entry_5, 0, 192);
  # DEBUG BEGIN_STMT
  _1 = &entry_5->temp_phys_entry;
  entry_5->phys_entry = _1;
  # DEBUG BEGIN_STMT
  entry_5->rtable = 0B;
  # DEBUG BEGIN_STMT
  entry_5->timeout = 4294967295;
  # DEBUG BEGIN_STMT
  entry_5->curr_timeout = 4294967295;
  # DEBUG BEGIN_STMT
  entry_5->route_id = 0;
  # DEBUG BEGIN_STMT
  entry_5->route_id_valid = 0;
  # DEBUG BEGIN_STMT
  entry_5->ref_counter = 0;
  # DEBUG BEGIN_STMT
  entry_5->callback = 0B;
  # DEBUG BEGIN_STMT
  entry_5->callback_arg = 0B;
  # DEBUG BEGIN_STMT
  entry_5->refptr = 0B;
  # DEBUG BEGIN_STMT
  entry_5->child = 0B;
  # DEBUG BEGIN_STMT
  entry_5->temp_phys_entry.flag_ipv6 = 255;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] PFE RT ISA exhausted, no more entries left\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 632, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return entry_5;

}



;; Function pfe_rtable_entry_free (pfe_rtable_entry_free, funcdef_no=23, decl_uid=10453, cgraph_uid=24, symbol_order=33)

Modification phase of node pfe_rtable_entry_free/33
pfe_rtable_entry_free (struct pfe_rtable_t * rtable, struct pfe_rtable_entry_t * entry)
{
  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  if (entry_3(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 3> [local count: 751619277]:
  # DEBUG BEGIN_STMT
  if (rtable_5(D) != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 401890827]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 82
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (82);
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 751619277]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  pfe_rtable_entry_free_nolock (entry_3(D), 1);
  # DEBUG BEGIN_STMT
  if (rtable_5(D) != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 401890827]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 82
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (82);
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_sip (pfe_rtable_entry_set_sip, funcdef_no=25, decl_uid=10459, cgraph_uid=26, symbol_order=35)

Modification phase of node pfe_rtable_entry_set_sip/35
pfe_rtable_entry_set_sip (struct pfe_rtable_entry_t * entry, const struct pfe_ip_addr_t * ip_addr)
{
  errno_t ret;
  unsigned char _1;
  struct pfe_ct_rtable_entry_t * _2;
  unsigned char _3;
  unsigned char _4;
  uint32_t * _5;
  const union 
{
  uint8_t v4[4];
} * _6;
  struct pfe_ct_rtable_entry_t * _7;
  struct pfe_ct_rtable_entry_t * _8;
  unsigned char _9;
  uint32_t * _13;
  const union 
{
  uint16_t v6[8];
} * _14;
  struct pfe_ct_rtable_entry_t * _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = ip_addr_18(D)->is_ipv4;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = entry_19(D)->phys_entry;
  _3 = _2->flag_ipv6;
  _4 = _3 + 255;
  if (_4 <= 253)
    goto <bb 4>; [35.00%]
  else
    goto <bb 5>; [65.00%]

  <bb 4> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] IP version mismatch\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 771, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 348966093]:
  # DEBUG BEGIN_STMT
  _5 = &_2->ipv.v4.sip;
  _6 = &ip_addr_18(D)->v4;
  autolibc_memcpy (_5, _6, 4);
  # DEBUG BEGIN_STMT
  _7 = entry_19(D)->phys_entry;
  _7->flag_ipv6 = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  goto <bb 10>; [100.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 = entry_19(D)->phys_entry;
  _9 = _8->flag_ipv6;
  if (_9 != 255)
    goto <bb 7>; [79.76%]
  else
    goto <bb 9>; [20.24%]

  <bb 7> [local count: 428208240]:
  if (_9 != 1)
    goto <bb 8>; [33.99%]
  else
    goto <bb 9>; [66.01%]

  <bb 8> [local count: 145547982]:
  # DEBUG D#7 => entry_19(D)
  # DEBUG D#8 => ip_addr_18(D)
  ret_10 = pfe_rtable_entry_set_sip.part.0 ();
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 391322932]:
  # DEBUG BEGIN_STMT
  _13 = &_8->ipv.v6.sip[0];
  _14 = &ip_addr_18(D)->v6;
  autolibc_memcpy (_13, _14, 16);
  # DEBUG BEGIN_STMT
  _15 = entry_19(D)->phys_entry;
  _15->flag_ipv6 = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 10> [local count: 1073741824]:
  # ret_16 = PHI <0(5), ret_10(8), 0(9), 22(4)>
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  return ret_16;

}



;; Function pfe_rtable_entry_set_dip (pfe_rtable_entry_set_dip, funcdef_no=27, decl_uid=10468, cgraph_uid=28, symbol_order=37)

Modification phase of node pfe_rtable_entry_set_dip/37
pfe_rtable_entry_set_dip (struct pfe_rtable_entry_t * entry, const struct pfe_ip_addr_t * ip_addr)
{
  errno_t ret;
  unsigned char _1;
  struct pfe_ct_rtable_entry_t * _2;
  unsigned char _3;
  unsigned char _4;
  uint32_t * _5;
  const union 
{
  uint8_t v4[4];
} * _6;
  struct pfe_ct_rtable_entry_t * _7;
  struct pfe_ct_rtable_entry_t * _8;
  unsigned char _9;
  uint32_t * _13;
  const union 
{
  uint16_t v6[8];
} * _14;
  struct pfe_ct_rtable_entry_t * _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = ip_addr_18(D)->is_ipv4;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = entry_19(D)->phys_entry;
  _3 = _2->flag_ipv6;
  _4 = _3 + 255;
  if (_4 <= 253)
    goto <bb 4>; [35.00%]
  else
    goto <bb 5>; [65.00%]

  <bb 4> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] IP version mismatch\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 848, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 348966093]:
  # DEBUG BEGIN_STMT
  _5 = &_2->ipv.v4.dip;
  _6 = &ip_addr_18(D)->v4;
  autolibc_memcpy (_5, _6, 4);
  # DEBUG BEGIN_STMT
  _7 = entry_19(D)->phys_entry;
  _7->flag_ipv6 = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  goto <bb 10>; [100.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 = entry_19(D)->phys_entry;
  _9 = _8->flag_ipv6;
  if (_9 != 255)
    goto <bb 7>; [79.76%]
  else
    goto <bb 9>; [20.24%]

  <bb 7> [local count: 428208240]:
  if (_9 != 1)
    goto <bb 8>; [33.99%]
  else
    goto <bb 9>; [66.01%]

  <bb 8> [local count: 145547982]:
  # DEBUG D#11 => entry_19(D)
  # DEBUG D#12 => ip_addr_18(D)
  ret_10 = pfe_rtable_entry_set_dip.part.0 ();
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 391322932]:
  # DEBUG BEGIN_STMT
  _13 = &_8->ipv.v6.dip[0];
  _14 = &ip_addr_18(D)->v6;
  autolibc_memcpy (_13, _14, 16);
  # DEBUG BEGIN_STMT
  _15 = entry_19(D)->phys_entry;
  _15->flag_ipv6 = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 10> [local count: 1073741824]:
  # ret_16 = PHI <0(5), ret_10(8), 0(9), 22(4)>
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  return ret_16;

}



;; Function pfe_rtable_entry_set_5t (pfe_rtable_entry_set_5t, funcdef_no=24, decl_uid=10456, cgraph_uid=25, symbol_order=34)

Modification phase of node pfe_rtable_entry_set_5t/34
pfe_rtable_entry_set_5t (struct pfe_rtable_entry_t * entry, const struct pfe_5_tuple_t * tuple)
{
  errno_t ret;
  const struct pfe_ip_addr_t * _1;
  const struct pfe_ip_addr_t * _2;
  short unsigned int _3;
  short unsigned int _4;
  unsigned char _5;
  short unsigned int _15;
  struct pfe_ct_rtable_entry_t * _16;
  short unsigned int _17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &tuple_8(D)->src_ip;
  ret_12 = pfe_rtable_entry_set_sip (entry_10(D), _1);
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  if (ret_12 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = &tuple_8(D)->dst_ip;
  ret_14 = pfe_rtable_entry_set_dip (entry_10(D), _2);
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  if (ret_14 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _3 = tuple_8(D)->sport;
  # DEBUG entry => entry_10(D)
  # DEBUG sport => _3
  # DEBUG INLINE_ENTRY pfe_rtable_entry_set_sport
  # DEBUG BEGIN_STMT
  _16 = entry_10(D)->phys_entry;
  _17 = _3 r>> 8;
  _16->sport = _17;
  # DEBUG entry => NULL
  # DEBUG sport => NULL
  # DEBUG BEGIN_STMT
  _4 = tuple_8(D)->dport;
  # DEBUG entry => entry_10(D)
  # DEBUG dport => _4
  # DEBUG INLINE_ENTRY pfe_rtable_entry_set_dport
  # DEBUG BEGIN_STMT
  _15 = _4 r>> 8;
  _16->dport = _15;
  # DEBUG entry => NULL
  # DEBUG dport => NULL
  # DEBUG BEGIN_STMT
  _5 = tuple_8(D)->proto;
  # DEBUG entry => entry_10(D)
  # DEBUG proto => _5
  # DEBUG INLINE_ENTRY pfe_rtable_entry_set_proto
  # DEBUG BEGIN_STMT
  _16->proto = _5;

  <bb 5> [local count: 1073741824]:
  # ret_6 = PHI <ret_12(2), ret_14(3), 0(4)>
  # DEBUG entry => NULL
  # DEBUG proto => NULL
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_rtable_entry_set_sport (pfe_rtable_entry_set_sport, funcdef_no=29, decl_uid=10477, cgraph_uid=30, symbol_order=39)

Modification phase of node pfe_rtable_entry_set_sport/39
pfe_rtable_entry_set_sport (struct pfe_rtable_entry_t * entry, uint16_t sport)
{
  struct pfe_ct_rtable_entry_t * _1;
  short unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_4(D)->phys_entry;
  _2 = sport_5(D) r>> 8;
  _1->sport = _2;
  return;

}



;; Function pfe_rtable_entry_get_sport (pfe_rtable_entry_get_sport, funcdef_no=30, decl_uid=10479, cgraph_uid=31, symbol_order=40)

Modification phase of node pfe_rtable_entry_get_sport/40
pfe_rtable_entry_get_sport (const struct pfe_rtable_entry_t * entry)
{
  uint16_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  short unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_4(D)->phys_entry;
  _2 = _1->sport;
  ret_5 = _2 r>> 8;
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_rtable_entry_set_dport (pfe_rtable_entry_set_dport, funcdef_no=31, decl_uid=10485, cgraph_uid=32, symbol_order=41)

Modification phase of node pfe_rtable_entry_set_dport/41
pfe_rtable_entry_set_dport (struct pfe_rtable_entry_t * entry, uint16_t dport)
{
  struct pfe_ct_rtable_entry_t * _1;
  short unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_4(D)->phys_entry;
  _2 = dport_5(D) r>> 8;
  _1->dport = _2;
  return;

}



;; Function pfe_rtable_entry_get_dport (pfe_rtable_entry_get_dport, funcdef_no=32, decl_uid=10487, cgraph_uid=33, symbol_order=42)

Modification phase of node pfe_rtable_entry_get_dport/42
pfe_rtable_entry_get_dport (const struct pfe_rtable_entry_t * entry)
{
  uint16_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  short unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_4(D)->phys_entry;
  _2 = _1->dport;
  ret_5 = _2 r>> 8;
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_rtable_entry_set_proto (pfe_rtable_entry_set_proto, funcdef_no=33, decl_uid=10493, cgraph_uid=34, symbol_order=43)

Modification phase of node pfe_rtable_entry_set_proto/43
pfe_rtable_entry_set_proto (struct pfe_rtable_entry_t * entry, uint8_t proto)
{
  struct pfe_ct_rtable_entry_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_3(D)->phys_entry;
  _1->proto = proto_4(D);
  return;

}



;; Function pfe_rtable_entry_get_proto (pfe_rtable_entry_get_proto, funcdef_no=34, decl_uid=10495, cgraph_uid=35, symbol_order=44)

Modification phase of node pfe_rtable_entry_get_proto/44
pfe_rtable_entry_get_proto (const struct pfe_rtable_entry_t * entry)
{
  uint8_t ret;
  struct pfe_ct_rtable_entry_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_3(D)->phys_entry;
  ret_4 = _1->proto;
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_rtable_entry_set_dstif_id (pfe_rtable_entry_set_dstif_id, funcdef_no=35, decl_uid=10553, cgraph_uid=36, symbol_order=45)

Modification phase of node pfe_rtable_entry_set_dstif_id/45
pfe_rtable_entry_set_dstif_id (struct pfe_rtable_entry_t * entry, pfe_ct_phy_if_id_t if_id)
{
  errno_t ret;
  struct pfe_ct_rtable_entry_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (if_id_4(D) > 9)
    goto <bb 4>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _1 = entry_6(D)->phys_entry;
  _1->e_phy_if = if_id_4(D);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_2 = PHI <22(2), 0(3)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_rtable_entry_set_dstif (pfe_rtable_entry_set_dstif, funcdef_no=36, decl_uid=10498, cgraph_uid=37, symbol_order=46)

Modification phase of node pfe_rtable_entry_set_dstif/46
pfe_rtable_entry_set_dstif (struct pfe_rtable_entry_t * entry, const struct pfe_phy_if_t * iface)
{
  errno_t ret;
  pfe_ct_phy_if_id_t if_id;
  struct pfe_ct_rtable_entry_t * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if_id_3 = pfe_phy_if_get_id (iface_2(D));
  # DEBUG if_id => if_id_3
  # DEBUG BEGIN_STMT
  # DEBUG entry => entry_4(D)
  # DEBUG if_id => if_id_3
  # DEBUG INLINE_ENTRY pfe_rtable_entry_set_dstif_id
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (if_id_3 > 9)
    goto <bb 4>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _5 = entry_4(D)->phys_entry;
  _5->e_phy_if = if_id_3;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_6 = PHI <22(2), 0(3)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  # DEBUG entry => NULL
  # DEBUG if_id => NULL
  # DEBUG ret => NULL
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_rtable_entry_set_out_sip (pfe_rtable_entry_set_out_sip, funcdef_no=37, decl_uid=10465, cgraph_uid=38, symbol_order=47)

Modification phase of node pfe_rtable_entry_set_out_sip/47
pfe_rtable_entry_set_out_sip (struct pfe_rtable_entry_t * entry, const struct pfe_ip_addr_t * output_sip)
{
  errno_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  unsigned char _2;
  unsigned char _3;
  uint32_t * _4;
  const union 
{
  uint8_t v4[4];
} * _5;
  struct pfe_ct_rtable_entry_t * _6;
  unsigned char _7;
  uint32_t * _8;
  const union 
{
  uint16_t v6[8];
} * _9;
  struct pfe_ct_rtable_entry_t * _10;
  struct pfe_rtable_t * _11;
  struct pfe_ct_rtable_entry_t * _12;
  long unsigned int _13;
  long unsigned int _14;
  struct pfe_rtable_t * _15;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_19(D)->phys_entry;
  _2 = _1->flag_ipv6;
  if (_2 != 255)
    goto <bb 3>; [66.00%]
  else
    goto <bb 5>; [34.00%]

  <bb 3> [local count: 708669604]:
  _3 = output_sip_20(D)->is_ipv4;
  if (_3 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 233860969]:
  # DEBUG BEGIN_STMT
  _4 = &_1->args.ipv.v4.sip;
  _5 = &output_sip_20(D)->v4;
  autolibc_memcpy (_4, _5, 4);
  # DEBUG BEGIN_STMT
  _6 = entry_19(D)->phys_entry;
  _6->flag_ipv6 = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 839880854]:
  # DEBUG BEGIN_STMT
  if (_2 != 255)
    goto <bb 6>; [87.98%]
  else
    goto <bb 8>; [12.02%]

  <bb 6> [local count: 738927176]:
  _7 = output_sip_20(D)->is_ipv4;
  if (_7 == 0)
    goto <bb 7>; [47.77%]
  else
    goto <bb 8>; [52.23%]

  <bb 7> [local count: 352985512]:
  # DEBUG BEGIN_STMT
  _8 = &_1->args.ipv.v6.sip[0];
  _9 = &output_sip_20(D)->v6;
  autolibc_memcpy (_8, _9, 16);
  # DEBUG BEGIN_STMT
  _10 = entry_19(D)->phys_entry;
  _10->flag_ipv6 = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 486895342]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] IP version mismatch\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1127, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 586846482]:
  # DEBUG BEGIN_STMT
  _11 = entry_19(D)->rtable;
  if (_11 != 0B)
    goto <bb 10>; [53.47%]
  else
    goto <bb 11>; [46.53%]

  <bb 10> [local count: 313786814]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 67
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (67);
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 586846482]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _12 = entry_19(D)->phys_entry;
  _13 = _12->actions;
  _14 = _13 | 512;
  _12->actions = _14;
  # DEBUG BEGIN_STMT
  _15 = entry_19(D)->rtable;
  if (_15 != 0B)
    goto <bb 12>; [53.47%]
  else
    goto <bb 13>; [46.53%]

  <bb 12> [local count: 313786814]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 67
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (67);
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  # ret_30 = PHI <22(8), 0(11), 0(12)>
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_30;

}



;; Function pfe_rtable_entry_set_out_dip (pfe_rtable_entry_set_out_dip, funcdef_no=38, decl_uid=10474, cgraph_uid=39, symbol_order=48)

Modification phase of node pfe_rtable_entry_set_out_dip/48
pfe_rtable_entry_set_out_dip (struct pfe_rtable_entry_t * entry, const struct pfe_ip_addr_t * output_dip)
{
  errno_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  unsigned char _2;
  unsigned char _3;
  uint32_t * _4;
  const union 
{
  uint8_t v4[4];
} * _5;
  struct pfe_ct_rtable_entry_t * _6;
  unsigned char _7;
  uint32_t * _8;
  const union 
{
  uint16_t v6[8];
} * _9;
  struct pfe_ct_rtable_entry_t * _10;
  struct pfe_rtable_t * _11;
  struct pfe_ct_rtable_entry_t * _12;
  long unsigned int _13;
  long unsigned int _14;
  struct pfe_rtable_t * _15;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_19(D)->phys_entry;
  _2 = _1->flag_ipv6;
  if (_2 != 255)
    goto <bb 3>; [66.00%]
  else
    goto <bb 5>; [34.00%]

  <bb 3> [local count: 708669604]:
  _3 = output_dip_20(D)->is_ipv4;
  if (_3 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 233860969]:
  # DEBUG BEGIN_STMT
  _4 = &_1->args.ipv.v4.dip;
  _5 = &output_dip_20(D)->v4;
  autolibc_memcpy (_4, _5, 4);
  # DEBUG BEGIN_STMT
  _6 = entry_19(D)->phys_entry;
  _6->flag_ipv6 = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 839880854]:
  # DEBUG BEGIN_STMT
  if (_2 != 255)
    goto <bb 6>; [87.98%]
  else
    goto <bb 8>; [12.02%]

  <bb 6> [local count: 738927176]:
  _7 = output_dip_20(D)->is_ipv4;
  if (_7 == 0)
    goto <bb 7>; [47.77%]
  else
    goto <bb 8>; [52.23%]

  <bb 7> [local count: 352985512]:
  # DEBUG BEGIN_STMT
  _8 = &_1->args.ipv.v6.dip[0];
  _9 = &output_dip_20(D)->v6;
  autolibc_memcpy (_8, _9, 16);
  # DEBUG BEGIN_STMT
  _10 = entry_19(D)->phys_entry;
  _10->flag_ipv6 = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 486895342]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] IP version mismatch\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1184, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 586846482]:
  # DEBUG BEGIN_STMT
  _11 = entry_19(D)->rtable;
  if (_11 != 0B)
    goto <bb 10>; [53.47%]
  else
    goto <bb 11>; [46.53%]

  <bb 10> [local count: 313786814]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 68
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (68);
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 586846482]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _12 = entry_19(D)->phys_entry;
  _13 = _12->actions;
  _14 = _13 | 2048;
  _12->actions = _14;
  # DEBUG BEGIN_STMT
  _15 = entry_19(D)->rtable;
  if (_15 != 0B)
    goto <bb 12>; [53.47%]
  else
    goto <bb 13>; [46.53%]

  <bb 12> [local count: 313786814]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 68
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (68);
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  # ret_30 = PHI <22(8), 0(11), 0(12)>
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_30;

}



;; Function pfe_rtable_entry_set_out_sport (pfe_rtable_entry_set_out_sport, funcdef_no=39, decl_uid=10482, cgraph_uid=40, symbol_order=49)

Modification phase of node pfe_rtable_entry_set_out_sport/49
pfe_rtable_entry_set_out_sport (const struct pfe_rtable_entry_t * entry, uint16_t output_sport)
{
  struct pfe_rtable_t * _1;
  struct pfe_ct_rtable_entry_t * _2;
  short unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  struct pfe_rtable_t * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_10(D)->rtable;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 69
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (69);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = entry_10(D)->phys_entry;
  _3 = output_sport_11(D) r>> 8;
  _2->args.sport = _3;
  # DEBUG BEGIN_STMT
  _4 = _2->actions;
  _5 = _4 | 1024;
  _2->actions = _5;
  # DEBUG BEGIN_STMT
  _6 = entry_10(D)->rtable;
  if (_6 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 69
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (69);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_out_dport (pfe_rtable_entry_set_out_dport, funcdef_no=40, decl_uid=10490, cgraph_uid=41, symbol_order=50)

Modification phase of node pfe_rtable_entry_set_out_dport/50
pfe_rtable_entry_set_out_dport (struct pfe_rtable_entry_t * entry, uint16_t output_dport)
{
  struct pfe_rtable_t * _1;
  struct pfe_ct_rtable_entry_t * _2;
  short unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  struct pfe_rtable_t * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_10(D)->rtable;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 70
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (70);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = entry_10(D)->phys_entry;
  _3 = output_dport_11(D) r>> 8;
  _2->args.dport = _3;
  # DEBUG BEGIN_STMT
  _4 = _2->actions;
  _5 = _4 | 4096;
  _2->actions = _5;
  # DEBUG BEGIN_STMT
  _6 = entry_10(D)->rtable;
  if (_6 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 70
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (70);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_ttl_decrement (pfe_rtable_entry_set_ttl_decrement, funcdef_no=41, decl_uid=10446, cgraph_uid=42, symbol_order=51)

Modification phase of node pfe_rtable_entry_set_ttl_decrement/51
pfe_rtable_entry_set_ttl_decrement (struct pfe_rtable_entry_t * entry)
{
  struct pfe_rtable_t * _1;
  struct pfe_ct_rtable_entry_t * _2;
  long unsigned int _3;
  long unsigned int _4;
  struct pfe_rtable_t * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_9(D)->rtable;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 71
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (71);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = entry_9(D)->phys_entry;
  _3 = _2->actions;
  _4 = _3 | 2147483648;
  _2->actions = _4;
  # DEBUG BEGIN_STMT
  _5 = entry_9(D)->rtable;
  if (_5 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 71
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (71);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_remove_ttl_decrement (pfe_rtable_entry_remove_ttl_decrement, funcdef_no=42, decl_uid=10448, cgraph_uid=43, symbol_order=52)

Modification phase of node pfe_rtable_entry_remove_ttl_decrement/52
pfe_rtable_entry_remove_ttl_decrement (struct pfe_rtable_entry_t * entry)
{
  struct pfe_rtable_t * _1;
  struct pfe_ct_rtable_entry_t * _2;
  long unsigned int _3;
  long unsigned int _4;
  struct pfe_rtable_t * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_9(D)->rtable;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 72
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (72);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = entry_9(D)->phys_entry;
  _3 = _2->actions;
  _4 = _3 & 2147483647;
  _2->actions = _4;
  # DEBUG BEGIN_STMT
  _5 = entry_9(D)->rtable;
  if (_5 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 72
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (72);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_out_mac_addrs (pfe_rtable_entry_set_out_mac_addrs, funcdef_no=43, decl_uid=10502, cgraph_uid=44, symbol_order=53)

Modification phase of node pfe_rtable_entry_set_out_mac_addrs/53
pfe_rtable_entry_set_out_mac_addrs (struct pfe_rtable_entry_t * entry, const uint8_t * smac, const uint8_t * dmac)
{
  struct pfe_ct_rtable_entry_t * _1;
  uint8_t[6] * _2;
  struct pfe_ct_rtable_entry_t * _3;
  uint8_t[6] * _4;
  struct pfe_rtable_t * _5;
  struct pfe_ct_rtable_entry_t * _6;
  long unsigned int _7;
  long unsigned int _8;
  struct pfe_rtable_t * _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_13(D)->phys_entry;
  _2 = &_1->args.smac;
  autolibc_memcpy (_2, smac_14(D), 6);
  # DEBUG BEGIN_STMT
  _3 = entry_13(D)->phys_entry;
  _4 = &_3->args.dmac;
  autolibc_memcpy (_4, dmac_16(D), 6);
  # DEBUG BEGIN_STMT
  _5 = entry_13(D)->rtable;
  if (_5 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 73
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (73);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _6 = entry_13(D)->phys_entry;
  _7 = _6->actions;
  _8 = _7 | 16777216;
  _6->actions = _8;
  # DEBUG BEGIN_STMT
  _9 = entry_13(D)->rtable;
  if (_9 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 73
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (73);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_out_vlan (pfe_rtable_entry_set_out_vlan, funcdef_no=44, decl_uid=10506, cgraph_uid=45, symbol_order=54)

Modification phase of node pfe_rtable_entry_set_out_vlan/54
pfe_rtable_entry_set_out_vlan (struct pfe_rtable_entry_t * entry, uint16_t vlan, bool_t replace)
{
  struct pfe_ct_rtable_entry_t * _1;
  short unsigned int _2;
  struct pfe_rtable_t * _3;
  struct pfe_ct_rtable_entry_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  struct pfe_rtable_t * _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_14(D)->phys_entry;
  _2 = vlan_15(D) r>> 8;
  _1->args.vlan = _2;
  # DEBUG BEGIN_STMT
  _3 = entry_14(D)->rtable;
  if (_3 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 74
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (74);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _4 = entry_14(D)->phys_entry;
  _5 = _4->actions;
  _6 = _5 & 4261396479;
  # DEBUG BEGIN_STMT
  if (replace_17(D) != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _7 = _6 | 16384;
  _4->actions = _7;
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 = _6 | 33554432;
  _4->actions = _8;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _9 = entry_14(D)->rtable;
  if (_9 != 0B)
    goto <bb 8>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 8> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 74
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (74);
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_get_out_vlan (pfe_rtable_entry_get_out_vlan, funcdef_no=45, decl_uid=10508, cgraph_uid=46, symbol_order=55)

Modification phase of node pfe_rtable_entry_get_out_vlan/55
pfe_rtable_entry_get_out_vlan (const struct pfe_rtable_entry_t * entry)
{
  uint16_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  short unsigned int _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = entry_16(D)->phys_entry;
  _2 = _1->actions;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  _11 = _9 | _10;
  _12 = _11 & 4194306;
  if (_12 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _13 = _1->args.vlan;
  ret_17 = _13 r>> 8;
  # DEBUG ret => ret_17

  <bb 4> [local count: 1073741824]:
  # ret_14 = PHI <0(2), ret_17(3)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  return ret_14;

}



;; Function pfe_rtable_entry_set_out_inner_vlan (pfe_rtable_entry_set_out_inner_vlan, funcdef_no=46, decl_uid=10511, cgraph_uid=47, symbol_order=56)

Modification phase of node pfe_rtable_entry_set_out_inner_vlan/56
pfe_rtable_entry_set_out_inner_vlan (struct pfe_rtable_entry_t * entry, uint16_t vlan)
{
  struct pfe_ct_rtable_entry_t * _1;
  short unsigned int _2;
  struct pfe_rtable_t * _3;
  struct pfe_ct_rtable_entry_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  struct pfe_rtable_t * _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = entry_11(D)->phys_entry;
  _2 = vlan_12(D) r>> 8;
  _1->args.vlan1 = _2;
  # DEBUG BEGIN_STMT
  _3 = entry_11(D)->rtable;
  if (_3 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 75
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (75);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _4 = entry_11(D)->phys_entry;
  _5 = _4->actions;
  _6 = _5 | 524288;
  _4->actions = _6;
  # DEBUG BEGIN_STMT
  _7 = entry_11(D)->rtable;
  if (_7 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 75
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (75);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_out_pppoe_sid (pfe_rtable_entry_set_out_pppoe_sid, funcdef_no=47, decl_uid=10514, cgraph_uid=48, symbol_order=57)

Modification phase of node pfe_rtable_entry_set_out_pppoe_sid/57
pfe_rtable_entry_set_out_pppoe_sid (struct pfe_rtable_entry_t * entry, uint16_t sid)
{
  uint32_t flags;
  struct pfe_ct_rtable_entry_t * _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  short unsigned int _13;
  struct pfe_rtable_t * _14;
  struct pfe_ct_rtable_entry_t * _15;
  long unsigned int _16;
  long unsigned int _17;
  struct pfe_rtable_t * _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_22(D)->phys_entry;
  _2 = _1->actions;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  flags_23 = _9 | _10;
  # DEBUG flags => flags_23
  # DEBUG BEGIN_STMT
  _11 = flags_23 & 2048;
  if (_11 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Action (PFE_RTABLE_ADD_PPPOE_HDR) must no be combined with PFE_RTABLE_ADD_VLAN1_HDR\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1489, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 4> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  _12 = flags_23 & 1;
  if (_12 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Action (PFE_RTABLE_ADD_PPPOE_HDR) requires also the PFE_RTABLE_ADD_ETH_HDR flag set\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 1495, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 6> [local count: 482002705]:
  # DEBUG BEGIN_STMT
  _13 = sid_24(D) r>> 8;
  _1->args.pppoe_sid = _13;
  # DEBUG BEGIN_STMT
  _14 = entry_22(D)->rtable;
  if (_14 != 0B)
    goto <bb 7>; [53.47%]
  else
    goto <bb 8>; [46.53%]

  <bb 7> [local count: 257726846]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 76
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (76);
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 482002705]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _15 = entry_22(D)->phys_entry;
  _16 = _15->actions;
  _17 = _16 | 67108864;
  _15->actions = _17;
  # DEBUG BEGIN_STMT
  _18 = entry_22(D)->rtable;
  if (_18 != 0B)
    goto <bb 9>; [53.47%]
  else
    goto <bb 10>; [46.53%]

  <bb 9> [local count: 257726846]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 76
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (76);
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_id5t (pfe_rtable_entry_set_id5t, funcdef_no=48, decl_uid=10547, cgraph_uid=49, symbol_order=58)

Modification phase of node pfe_rtable_entry_set_id5t/58
pfe_rtable_entry_set_id5t (struct pfe_rtable_entry_t * entry, uint32_t id5t)
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  struct pfe_ct_rtable_entry_t * _9;
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = id5t_11(D) >> 24;
  _2 = id5t_11(D) >> 8;
  _3 = _2 & 65280;
  _4 = _1 | _3;
  _5 = id5t_11(D) << 8;
  _6 = _5 & 16711680;
  _7 = _4 | _6;
  _8 = id5t_11(D) << 24;
  _9 = entry_13(D)->phys_entry;
  _10 = _7 | _8;
  _9->id5t = _10;
  return;

}



;; Function pfe_rtable_entry_get_id5t (pfe_rtable_entry_get_id5t, funcdef_no=49, decl_uid=10550, cgraph_uid=50, symbol_order=59)

Modification phase of node pfe_rtable_entry_get_id5t/59
pfe_rtable_entry_get_id5t (const struct pfe_rtable_entry_t * entry, uint32_t * id5t)
{
  struct pfe_ct_rtable_entry_t * _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_13(D)->phys_entry;
  _2 = _1->id5t;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  _11 = _9 | _10;
  *id5t_14(D) = _11;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_rtable_entry_get_action_flags (pfe_rtable_entry_get_action_flags, funcdef_no=50, decl_uid=10516, cgraph_uid=51, symbol_order=60)

Modification phase of node pfe_rtable_entry_get_action_flags/60
pfe_rtable_entry_get_action_flags (struct pfe_rtable_entry_t * entry)
{
  pfe_ct_route_actions_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_12(D)->phys_entry;
  _2 = _1->actions;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  ret_13 = _9 | _10;
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  return ret_13;

}



;; Function pfe_rtable_entry_set_timeout (pfe_rtable_entry_set_timeout, funcdef_no=51, decl_uid=10519, cgraph_uid=52, symbol_order=61)

Modification phase of node pfe_rtable_entry_set_timeout/61
pfe_rtable_entry_set_timeout (struct pfe_rtable_entry_t * entry, uint32_t timeout)
{
  uint32_t elapsed;
  struct pfe_rtable_t * _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  struct pfe_rtable_t * _5;
  long unsigned int _17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_10(D)->rtable;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 77
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (77);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = entry_10(D)->timeout;
  if (_2 == 4294967295)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  entry_10(D)->curr_timeout = timeout_12(D);
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _3 = entry_10(D)->curr_timeout;
  elapsed_11 = _2 - _3;
  # DEBUG elapsed => elapsed_11
  # DEBUG BEGIN_STMT
  if (elapsed_11 >= timeout_12(D))
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  entry_10(D)->curr_timeout = 0;
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _17 = _3 - _2;
  _4 = timeout_12(D) + _17;
  entry_10(D)->curr_timeout = _4;

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  entry_10(D)->timeout = timeout_12(D);
  # DEBUG BEGIN_STMT
  _5 = entry_10(D)->rtable;
  if (_5 != 0B)
    goto <bb 10>; [53.47%]
  else
    goto <bb 11>; [46.53%]

  <bb 10> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 77
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (77);
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_rtable_entry_set_route_id (pfe_rtable_entry_set_route_id, funcdef_no=52, decl_uid=10522, cgraph_uid=53, symbol_order=62)

Modification phase of node pfe_rtable_entry_set_route_id/62
pfe_rtable_entry_set_route_id (struct pfe_rtable_entry_t * entry, uint32_t route_id)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  entry_2(D)->route_id = route_id_3(D);
  # DEBUG BEGIN_STMT
  entry_2(D)->route_id_valid = 1;
  return;

}



;; Function pfe_rtable_entry_get_route_id (pfe_rtable_entry_get_route_id, funcdef_no=53, decl_uid=10525, cgraph_uid=54, symbol_order=63)

Modification phase of node pfe_rtable_entry_get_route_id/63
pfe_rtable_entry_get_route_id (const struct pfe_rtable_entry_t * entry, uint32_t * route_id)
{
  errno_t ret;
  unsigned char _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_6(D)->route_id_valid;
  if (_1 == 1)
    goto <bb 3>; [48.89%]
  else
    goto <bb 4>; [51.11%]

  <bb 3> [local count: 524952378]:
  # DEBUG BEGIN_STMT
  _2 = entry_6(D)->route_id;
  *route_id_7(D) = _2;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_3 = PHI <0(3), 2(2)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_rtable_entry_set_callback (pfe_rtable_entry_set_callback, funcdef_no=54, decl_uid=10529, cgraph_uid=55, symbol_order=64)

Modification phase of node pfe_rtable_entry_set_callback/64
pfe_rtable_entry_set_callback (struct pfe_rtable_entry_t * entry, void (*pfe_rtable_callback_t) (void *, pfe_rtable_cbk_event_t) cbk, void * arg)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  entry_2(D)->callback = cbk_3(D);
  # DEBUG BEGIN_STMT
  entry_2(D)->callback_arg = arg_5(D);
  return;

}



;; Function pfe_rtable_entry_set_refptr (pfe_rtable_entry_set_refptr, funcdef_no=55, decl_uid=10532, cgraph_uid=56, symbol_order=65)

Modification phase of node pfe_rtable_entry_set_refptr/65
pfe_rtable_entry_set_refptr (struct pfe_rtable_entry_t * entry, void * refptr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  entry_2(D)->refptr = refptr_3(D);
  return;

}



;; Function pfe_rtable_entry_get_refptr (pfe_rtable_entry_get_refptr, funcdef_no=56, decl_uid=10534, cgraph_uid=57, symbol_order=66)

Modification phase of node pfe_rtable_entry_get_refptr/66
pfe_rtable_entry_get_refptr (struct pfe_rtable_entry_t * entry)
{
  void * ptr;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ptr_3 = entry_2(D)->refptr;
  # DEBUG ptr => ptr_3
  # DEBUG BEGIN_STMT
  return ptr_3;

}



;; Function pfe_rtable_entry_set_child (pfe_rtable_entry_set_child, funcdef_no=57, decl_uid=10537, cgraph_uid=58, symbol_order=67)

Modification phase of node pfe_rtable_entry_set_child/67
pfe_rtable_entry_set_child (struct pfe_rtable_entry_t * entry, struct pfe_rtable_entry_t * child)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  entry_3(D)->child = child_4(D);
  # DEBUG BEGIN_STMT
  if (child_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  child_4(D)->child = entry_3(D);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function pfe_rtable_entry_get_child_nolock (pfe_rtable_entry_get_child_nolock, funcdef_no=58, decl_uid=10539, cgraph_uid=59, symbol_order=68)

Modification phase of node pfe_rtable_entry_get_child_nolock/68
pfe_rtable_entry_get_child_nolock (const struct pfe_rtable_entry_t * entry)
{
  struct pfe_rtable_entry_t * ptr;
  signed char _1;
  unsigned char _2;
  unsigned char _3;
  signed char _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ptr_8 = entry_7(D)->child;
  # DEBUG ptr => ptr_8
  # DEBUG BEGIN_STMT
  if (ptr_8 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = ptr_8->ref_counter;
  _2 = (unsigned char) _1;
  _3 = _2 + 1;
  _4 = (signed char) _3;
  ptr_8->ref_counter = _4;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return ptr_8;

}



;; Function pfe_rtable_entry_get_child (pfe_rtable_entry_get_child, funcdef_no=59, decl_uid=10542, cgraph_uid=60, symbol_order=69)

Modification phase of node pfe_rtable_entry_get_child/69
pfe_rtable_entry_get_child (struct pfe_rtable_t * rtable, const struct pfe_rtable_entry_t * entry)
{
  struct pfe_rtable_entry_t * ptr;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (rtable_3(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 81
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (81);
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  ptr_7 = pfe_rtable_entry_get_child_nolock (entry_5(D));
  # DEBUG ptr => ptr_7
  # DEBUG BEGIN_STMT
  if (rtable_3(D) != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 81
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (81);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ptr_7;

}



;; Function pfe_rtable_entry_get_stats_index (pfe_rtable_entry_get_stats_index, funcdef_no=60, decl_uid=10544, cgraph_uid=61, symbol_order=70)

Modification phase of node pfe_rtable_entry_get_stats_index/70
pfe_rtable_entry_get_stats_index (const struct pfe_rtable_entry_t * entry)
{
  uint8_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  short unsigned int _2;
  short unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = entry_5(D)->phys_entry;
  _2 = _1->conntrack_stats_index;
  _3 = _2 >> 8;
  ret_6 = (uint8_t) _3;
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_rtable_get_size (pfe_rtable_get_size, funcdef_no=77, decl_uid=10444, cgraph_uid=78, symbol_order=87)

Modification phase of node pfe_rtable_get_size/87
pfe_rtable_get_size (const struct pfe_rtable_t * rtable)
{
  uint32_t ret;
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = rtable_4(D)->pool_size;
  _2 = rtable_4(D)->htable_size;
  # DEBUG BEGIN_STMT
  ret_5 = _1 + _2;
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_rtable_destroy (pfe_rtable_destroy, funcdef_no=78, decl_uid=10428, cgraph_uid=79, symbol_order=88)

Modification phase of node pfe_rtable_destroy/88
pfe_rtable_destroy (struct pfe_rtable_t * rtable)
{
  unsigned int _1;
  unsigned int _2;
  volatile struct fifo_t * _3;
  struct pfe_class_t * _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (rtable_10(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = rtable_10(D)->htable_base_va;
  if (_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  rtable_10(D)->htable_base_va = 0;

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _2 = rtable_10(D)->pool_base_va;
  if (_2 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  rtable_10(D)->pool_base_va = 0;

  <bb 7> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _3 = rtable_10(D)->pool_va;
  if (_3 != 0B)
    goto <bb 8>; [0.00%]
  else
    goto <bb 9>; [100.00%]

  <bb 8> [count: 0]:
  # DEBUG BEGIN_STMT
  fifo_destroy (_3);
  # DEBUG BEGIN_STMT
  rtable_10(D)->pool_va = 0B;

  <bb 9> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _4 = rtable_10(D)->class;
  _5 = rtable_10(D)->conntrack_stats_table_addr;
  pfe_rtable_destroy_stats_table (_4, _5);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_rtable_entries, 0, 8);

  <bb 10> [local count: 1073741824]:
  return;

}



;; Function pfe_rtable_create (pfe_rtable_create, funcdef_no=76, decl_uid=10420, cgraph_uid=77, symbol_order=86)

Modification phase of node pfe_rtable_create/86
pfe_rtable_create (struct pfe_class_t * class, struct pfe_l2br_t * bridge, struct pfe_class_table_sizes_t table_params)
{
  long unsigned int table_params$pool_size;
  unsigned int table_params$pool_base_va;
  unsigned int table_params$htable_base_va;
  struct pfe_rtable_t * rtable;
  void * _1;
  void * _2;
  unsigned int _3;
  long unsigned int _4;
  unsigned int _5;
  unsigned int _6;
  unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  unsigned int _10;
  long unsigned int _11;
  unsigned int _12;
  unsigned int _13;
  unsigned int _14;
  unsigned int _15;
  unsigned int _16;
  unsigned int _17;
  long unsigned int _18;
  unsigned int _19;
  unsigned int _20;

  <bb 2> [local count: 1073741824]:
  table_params$htable_base_va_23 = MEM[(struct  *)&table_params];
  # DEBUG table_params$htable_base_va => table_params$htable_base_va_23
  table_params$pool_base_va_51 = MEM[(struct  *)&table_params + 4B];
  # DEBUG table_params$pool_base_va => table_params$pool_base_va_51
  table_params$pool_size_52 = MEM[(struct  *)&table_params + 12B];
  # DEBUG table_params$pool_size => table_params$pool_size_52
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG rtable => &pfe_rtable
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_rtable, 0, 140);
  # DEBUG BEGIN_STMT
  pfe_rtable.htable_base_va = table_params$htable_base_va_23;
  # DEBUG BEGIN_STMT
  _1 = (void *) table_params$htable_base_va_23;
  _2 = oal_mm_virt_to_phys_contig (_1);
  _3 = (unsigned int) _2;
  pfe_rtable.htable_base_pa = _3;
  # DEBUG BEGIN_STMT
  _4 = table_params.htable_size;
  pfe_rtable.htable_size = _4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = pfe_rtable.htable_base_va;
  _6 = _4 * 128;
  _7 = _5 + _6;
  _8 = _7 + 4294967295;
  pfe_rtable.htable_end_va = _8;
  # DEBUG BEGIN_STMT
  _9 = _3 + _6;
  _10 = _9 + 4294967295;
  pfe_rtable.htable_end_pa = _10;
  # DEBUG BEGIN_STMT
  pfe_rtable.pool_base_va = table_params$pool_base_va_51;
  # DEBUG BEGIN_STMT
  _11 = table_params$pool_base_va_51 - table_params$htable_base_va_23;
  _12 = _3 + _11;
  pfe_rtable.pool_base_pa = _12;
  # DEBUG BEGIN_STMT
  pfe_rtable.pool_size = table_params$pool_size_52;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = table_params$pool_size_52 * 128;
  _14 = _13 + table_params$pool_base_va_51;
  _15 = _14 + 4294967295;
  pfe_rtable.pool_end_va = _15;
  # DEBUG BEGIN_STMT
  _16 = _12 + _13;
  _17 = _16 + 4294967295;
  pfe_rtable.pool_end_pa = _17;
  # DEBUG BEGIN_STMT
  pfe_rtable.bridge = bridge_37(D);
  # DEBUG BEGIN_STMT
  pfe_rtable.class = class_39(D);
  # DEBUG BEGIN_STMT
  pfe_rtable.active_entries_count = 0;
  # DEBUG BEGIN_STMT
  pfe_rtable.conntrack_stats_table_size = 20;
  # DEBUG BEGIN_STMT
  autolibc_memset (&stats_tbl_index, 0, 21);
  # DEBUG BEGIN_STMT
  _18 = pfe_rtable_create_stats_table (class_39(D), 21);
  pfe_rtable.conntrack_stats_table_addr = _18;
  # DEBUG BEGIN_STMT
  _19 = pfe_rtable.htable_base_va;
  if (_19 == 0)
    goto <bb 4>; [16.75%]
  else
    goto <bb 3>; [83.25%]

  <bb 3> [local count: 893890069]:
  _20 = pfe_rtable.pool_base_va;
  if (_20 == 0)
    goto <bb 4>; [45.33%]
  else
    goto <bb 5>; [54.67%]

  <bb 4> [local count: 585052125]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t map the table memory\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2805, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_rtable_destroy (&pfe_rtable);
  # DEBUG BEGIN_STMT
  # DEBUG rtable => 0B
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 488689700]:
  # DEBUG BEGIN_STMT
  rtable_47 = pfe_rtable_configure_table (class_39(D), &pfe_rtable, table_params$pool_size_52);
  # DEBUG rtable => rtable_47

  <bb 6> [local count: 1073741824]:
  # rtable_21 = PHI <0B(4), rtable_47(5)>
  # DEBUG rtable => rtable_21
  # DEBUG BEGIN_STMT
  return rtable_21;

}



;; Function pfe_rtable_get_entry_size (pfe_rtable_get_entry_size, funcdef_no=79, decl_uid=10430, cgraph_uid=80, symbol_order=89)

Modification phase of node pfe_rtable_get_entry_size/89
pfe_rtable_get_entry_size ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 128;

}



;; Function pfe_rtable_entry_to_5t (pfe_rtable_entry_to_5t, funcdef_no=80, decl_uid=10433, cgraph_uid=81, symbol_order=90)

Modification phase of node pfe_rtable_entry_to_5t/90
pfe_rtable_entry_to_5t (const struct pfe_rtable_entry_t * entry, struct pfe_5_tuple_t * tuple)
{
  errno_t ret;
  struct pfe_ct_rtable_entry_t * _1;
  unsigned char _2;
  union 
{
  uint8_t v4[4];
} * _3;
  uint32_t * _4;
  union 
{
  uint8_t v4[4];
} * _5;
  struct pfe_ct_rtable_entry_t * _6;
  uint32_t * _7;
  union 
{
  uint16_t v6[8];
} * _8;
  uint32_t * _9;
  union 
{
  uint16_t v6[8];
} * _10;
  struct pfe_ct_rtable_entry_t * _11;
  uint32_t * _12;
  struct pfe_ct_rtable_entry_t * _13;
  short unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  unsigned char _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (tuple_21(D), 0, 50);
  # DEBUG BEGIN_STMT
  _1 = entry_23(D)->phys_entry;
  _2 = _1->flag_ipv6;
  if (_2 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _3 = &tuple_21(D)->src_ip.v4;
  _4 = &_1->ipv.v4.sip;
  autolibc_memcpy (_3, _4, 4);
  # DEBUG BEGIN_STMT
  _5 = &tuple_21(D)->dst_ip.v4;
  _6 = entry_23(D)->phys_entry;
  _7 = &_6->ipv.v4.dip;
  autolibc_memcpy (_5, _7, 4);
  # DEBUG BEGIN_STMT
  tuple_21(D)->src_ip.is_ipv4 = 1;
  # DEBUG BEGIN_STMT
  tuple_21(D)->dst_ip.is_ipv4 = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  if (_2 == 1)
    goto <bb 5>; [48.89%]
  else
    goto <bb 6>; [51.11%]

  <bb 5> [local count: 351718093]:
  # DEBUG BEGIN_STMT
  _8 = &tuple_21(D)->src_ip.v6;
  _9 = &_1->ipv.v6.sip[0];
  autolibc_memcpy (_8, _9, 16);
  # DEBUG BEGIN_STMT
  _10 = &tuple_21(D)->dst_ip.v6;
  _11 = entry_23(D)->phys_entry;
  _12 = &_11->ipv.v6.dip[0];
  autolibc_memcpy (_10, _12, 16);
  # DEBUG BEGIN_STMT
  tuple_21(D)->src_ip.is_ipv4 = 0;
  # DEBUG BEGIN_STMT
  tuple_21(D)->dst_ip.is_ipv4 = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 367688929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unknown IP version\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2930, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 706052896]:
  # DEBUG BEGIN_STMT
  _13 = entry_23(D)->phys_entry;
  _14 = _13->sport;
  _15 = _14 r>> 8;
  tuple_21(D)->sport = _15;
  # DEBUG BEGIN_STMT
  _16 = _13->dport;
  _17 = _16 r>> 8;
  tuple_21(D)->dport = _17;
  # DEBUG BEGIN_STMT
  _18 = _13->proto;
  tuple_21(D)->proto = _18;

  <bb 8> [local count: 1073741824]:
  # ret_37 = PHI <22(6), 0(7)>
  # DEBUG BEGIN_STMT
  return ret_37;

}



;; Function pfe_rtable_entry_get_sip (pfe_rtable_entry_get_sip, funcdef_no=26, decl_uid=10462, cgraph_uid=27, symbol_order=36)

Modification phase of node pfe_rtable_entry_get_sip/36
pfe_rtable_entry_get_sip (struct pfe_rtable_entry_t * entry, struct pfe_ip_addr_t * ip_addr)
{
  struct pfe_5_tuple_t tuple;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  if (_1 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Entry conversion failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 818, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memcpy (ip_addr_8(D), &tuple.src_ip, 22);
  tuple ={v} {CLOBBER};
  return;

}



;; Function pfe_rtable_entry_get_dip (pfe_rtable_entry_get_dip, funcdef_no=28, decl_uid=10471, cgraph_uid=29, symbol_order=38)

Modification phase of node pfe_rtable_entry_get_dip/38
pfe_rtable_entry_get_dip (struct pfe_rtable_entry_t * entry, struct pfe_ip_addr_t * ip_addr)
{
  struct pfe_5_tuple_t tuple;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_rtable_entry_to_5t (entry_4(D), &tuple);
  if (_1 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Entry conversion failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 895, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memcpy (ip_addr_8(D), &tuple.dst_ip, 22);
  tuple ={v} {CLOBBER};
  return;

}



;; Function pfe_rtable_match_criterion (pfe_rtable_match_criterion, funcdef_no=82, decl_uid=10661, cgraph_uid=83, symbol_order=92)

Modification phase of node pfe_rtable_match_criterion/92
Setting nonnull for 1
pfe_rtable_match_criterion (pfe_rtable_get_criterion_t crit, const union pfe_rtable_criterion_arg_t * arg, struct pfe_rtable_entry_t * entry)
{
  struct pfe_5_tuple_t five_tuple;
  bool_t match;
  struct pfe_ct_rtable_entry_t * _1;
  unsigned char _2;
  _Bool _3;
  struct pfe_ct_rtable_entry_t * _4;
  unsigned char _5;
  _Bool _6;
  struct pfe_phy_if_t * _7;
  <unnamed type> _8;
  struct pfe_ct_rtable_entry_t * _9;
  <unnamed type> _10;
  _Bool _11;
  unsigned char _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  struct pfe_ct_rtable_entry_t * _16;
  long unsigned int _17;
  _Bool _18;
  int _19;
  const struct pfe_5_tuple_t * _20;
  long int _21;
  _Bool _22;
  int iftmp.0_24;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (crit_26(D)) <default: <L14> [12.50%], case 0: <L18> [12.50%], case 1: <L1> [12.50%], case 2: <L2> [12.50%], case 3: <L3> [12.50%], case 4: <L4> [12.50%], case 5: <L10> [12.50%], case 6: <L9> [12.50%]>

  <bb 3> [local count: 134217728]:
<L1>:
  # DEBUG BEGIN_STMT
  _1 = entry_29(D)->phys_entry;
  _2 = _1->flag_ipv6;
  _3 = _2 == 0;
  match_39 = (bool_t) _3;
  # DEBUG match => match_39
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 4> [local count: 134217728]:
<L2>:
  # DEBUG BEGIN_STMT
  _4 = entry_29(D)->phys_entry;
  _5 = _4->flag_ipv6;
  _6 = _5 == 1;
  match_38 = (bool_t) _6;
  # DEBUG match => match_38
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 5> [local count: 134217728]:
<L3>:
  # DEBUG BEGIN_STMT
  _7 = arg_28(D)->iface;
  _8 = pfe_phy_if_get_id (_7);
  _9 = entry_29(D)->phys_entry;
  _10 = _9->e_phy_if;
  _11 = _8 == _10;
  match_37 = (bool_t) _11;
  # DEBUG match => match_37
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 6> [local count: 134217728]:
<L4>:
  # DEBUG BEGIN_STMT
  _12 = entry_29(D)->route_id_valid;
  if (_12 == 1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 45634028]:
  _13 = arg_28(D)->route_id;
  _14 = entry_29(D)->route_id;
  if (_13 == _14)
    goto <bb 9>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 118702159]:

  <bb 9> [local count: 134217728]:
  # iftmp.0_24 = PHI <1(7), 0(8)>
  match_36 = (bool_t) iftmp.0_24;
  # DEBUG match => match_36
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 10> [local count: 134217728]:
<L9>:
  # DEBUG BEGIN_STMT
  _15 = arg_28(D)->id5t;
  _16 = entry_29(D)->phys_entry;
  _17 = _16->id5t;
  _18 = _15 == _17;
  match_30 = (bool_t) _18;
  # DEBUG match => match_30
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 11> [local count: 134217728]:
<L10>:
  # DEBUG BEGIN_STMT
  _19 = pfe_rtable_entry_to_5t (entry_29(D), &five_tuple);
  if (_19 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Entry conversion failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 3046, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  goto <bb 15>; [100.00%]

  <bb 13> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  _20 = &arg_28(D)->five_tuple;
  _21 = autolibc_memcmp (&five_tuple, _20, 50);
  _22 = _21 == 0;
  match_33 = (bool_t) _22;
  # DEBUG match => match_33
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 134217728]:
<L14>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unknown criterion\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 3056, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  # match_23 = PHI <1(2), match_39(3), match_38(4), match_37(5), match_36(9), match_30(10), match_33(13), 0(14), 0(12)>
<L18>:
  # DEBUG match => match_23
  # DEBUG BEGIN_STMT
  five_tuple ={v} {CLOBBER};
  return match_23;

}



;; Function pfe_rtable_add_entry (pfe_rtable_add_entry, funcdef_no=67, decl_uid=10423, cgraph_uid=68, symbol_order=77)

Modification phase of node pfe_rtable_add_entry/77
pfe_rtable_add_entry (struct pfe_rtable_t * rtable, struct pfe_rtable_entry_t * entry)
{
  errno_t ret;
  struct pfe_rtable_phys_entry_infor_t phys_entry_temp;
  unsigned char _1;
  struct pfe_ct_rtable_entry_t * _2;
  struct pfe_ct_rtable_entry_t * _3;
  struct pfe_ct_rtable_entry_t * _4;
  struct pfe_ct_rtable_entry_t * _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  struct pfe_ct_rtable_entry_t * _32;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  phys_entry_temp = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 78
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (78);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = pfe_rtable_entry_is_duplicate (rtable_20(D), entry_21(D));
  if (_1 == 1)
    goto <bb 5>; [36.03%]
  else
    goto <bb 3>; [63.97%]

  <bb 3> [local count: 686872646]:
  # DEBUG BEGIN_STMT
  ret_24 = pfe_rtable_add_entry_id (rtable_20(D), entry_21(D), &phys_entry_temp);
  # DEBUG ret => ret_24
  # DEBUG BEGIN_STMT
  if (ret_24 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 226667973]:
  # DEBUG BEGIN_STMT
  _2 = phys_entry_temp.new_phys_entry_va;
  _3 = &entry_21(D)->temp_phys_entry;
  autolibc_memcpy (_2, _3, 128);
  # DEBUG BEGIN_STMT
  _4 = phys_entry_temp.new_phys_entry_va;
  entry_21(D)->phys_entry = _4;
  # DEBUG BEGIN_STMT
  _5 = phys_entry_temp.new_phys_entry_pa;
  _6 = (long unsigned int) _5;
  _7 = _6 >> 24;
  _8 = _6 >> 8;
  _9 = _8 & 65280;
  _10 = _7 | _9;
  _11 = _6 << 8;
  _12 = _11 & 16711680;
  _13 = _10 | _12;
  _14 = _6 << 24;
  _15 = _13 | _14;
  _4->rt_orig = _15;
  # DEBUG BEGIN_STMT
  _4->i_phy_if = 10;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" dmb" :  :  : "memory");
  # DEBUG BEGIN_STMT
  _32 = MEM[(struct pfe_ct_rtable_entry_t * *)&phys_entry_temp + 8B];
  # DEBUG D#6 => &phys_entry_temp
  pfe_rtable_add_entry_validate.isra.0 (rtable_20(D), entry_21(D), _32);

  <bb 5> [local count: 1073741824]:
  # ret_16 = PHI <116(2), ret_24(3), 0(4)>
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 78
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (78);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  phys_entry_temp ={v} {CLOBBER};
  return ret_16;

}



;; Function pfe_rtable_entry_to_5t_out (pfe_rtable_entry_to_5t_out, funcdef_no=81, decl_uid=10436, cgraph_uid=82, symbol_order=91)

Modification phase of node pfe_rtable_entry_to_5t_out/91
pfe_rtable_entry_to_5t_out (const struct pfe_rtable_entry_t * entry, struct pfe_5_tuple_t * tuple)
{
  struct pfe_ct_rtable_entry_t * _1;
  unsigned char _2;
  union 
{
  uint16_t v6[8];
} * _3;
  uint32_t * _4;
  union 
{
  uint16_t v6[8];
} * _5;
  struct pfe_ct_rtable_entry_t * _6;
  uint32_t * _7;
  union 
{
  uint8_t v4[4];
} * _8;
  uint32_t * _9;
  union 
{
  uint8_t v4[4];
} * _10;
  struct pfe_ct_rtable_entry_t * _11;
  uint32_t * _12;
  struct pfe_ct_rtable_entry_t * _13;
  short unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  unsigned char _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (tuple_21(D), 0, 50);
  # DEBUG BEGIN_STMT
  _1 = entry_23(D)->phys_entry;
  _2 = _1->flag_ipv6;
  if (_2 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  _3 = &tuple_21(D)->src_ip.v6;
  _4 = &_1->args.ipv.v6.sip[0];
  autolibc_memcpy (_3, _4, 16);
  # DEBUG BEGIN_STMT
  _5 = &tuple_21(D)->dst_ip.v6;
  _6 = entry_23(D)->phys_entry;
  _7 = &_6->args.ipv.v6.dip[0];
  autolibc_memcpy (_5, _7, 16);
  # DEBUG BEGIN_STMT
  tuple_21(D)->src_ip.is_ipv4 = 0;
  # DEBUG BEGIN_STMT
  tuple_21(D)->dst_ip.is_ipv4 = 0;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _8 = &tuple_21(D)->src_ip.v4;
  _9 = &_1->args.ipv.v4.sip;
  autolibc_memcpy (_8, _9, 4);
  # DEBUG BEGIN_STMT
  _10 = &tuple_21(D)->dst_ip.v4;
  _11 = entry_23(D)->phys_entry;
  _12 = &_11->args.ipv.v4.dip;
  autolibc_memcpy (_10, _12, 4);
  # DEBUG BEGIN_STMT
  tuple_21(D)->src_ip.is_ipv4 = 1;
  # DEBUG BEGIN_STMT
  tuple_21(D)->dst_ip.is_ipv4 = 1;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _13 = entry_23(D)->phys_entry;
  _14 = _13->args.sport;
  _15 = _14 r>> 8;
  tuple_21(D)->sport = _15;
  # DEBUG BEGIN_STMT
  _16 = _13->args.dport;
  _17 = _16 r>> 8;
  tuple_21(D)->dport = _17;
  # DEBUG BEGIN_STMT
  _18 = _13->proto;
  tuple_21(D)->proto = _18;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_rtable_get_first (pfe_rtable_get_first, funcdef_no=84, decl_uid=10440, cgraph_uid=85, symbol_order=94)

Modification phase of node pfe_rtable_get_first/94
pfe_rtable_get_first (struct pfe_rtable_t * rtable, pfe_rtable_get_criterion_t crit, void * arg)
{
  struct pfe_rtable_entry_t * entry;
  uint32_t * _1;
  uint32_t * _2;
  struct pfe_5_tuple_t * _3;

  <bb 2> [local count: 1073527120]:
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  rtable_7(D)->cur_crit = crit_8(D);
  # DEBUG BEGIN_STMT
  switch (crit_8(D)) <default: <L7> [16.67%], case 0 ... 2: <L14> [16.67%], case 3: <L3> [16.67%], case 4: <L4> [16.67%], case 5: <L6> [16.67%], case 6: <L5> [16.67%]>

  <bb 4> [local count: 178956971]:
<L3>:
  # DEBUG BEGIN_STMT
  rtable_7(D)->cur_crit_arg.iface = arg_10(D);
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 178956971]:
<L4>:
  # DEBUG BEGIN_STMT
  _1 = &rtable_7(D)->cur_crit_arg.route_id;
  autolibc_memcpy (_1, arg_10(D), 4);
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 178956971]:
<L5>:
  # DEBUG BEGIN_STMT
  _2 = &rtable_7(D)->cur_crit_arg.id5t;
  autolibc_memcpy (_2, arg_10(D), 4);
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 178956971]:
<L6>:
  # DEBUG BEGIN_STMT
  _3 = &rtable_7(D)->cur_crit_arg.five_tuple;
  autolibc_memcpy (_3, arg_10(D), 50);
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 1
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 178956971]:
<L7>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unknown criterion\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 3169, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 0
  # DEBUG BEGIN_STMT
  # DEBUG known_crit => 0
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 894784854]:
<L14>:
  # DEBUG known_crit => NULL
  # DEBUG BEGIN_STMT
  entry_18 = pfe_rtable_prepare_first_entry (rtable_7(D));
  # DEBUG entry => entry_18

  <bb 10> [local count: 1073741824]:
  # entry_4 = PHI <0B(8), entry_18(9)>
  # DEBUG entry => entry_4
  # DEBUG BEGIN_STMT
  return entry_4;

}



;; Function pfe_rtable_get_next (pfe_rtable_get_next, funcdef_no=85, decl_uid=10442, cgraph_uid=86, symbol_order=95)

Modification phase of node pfe_rtable_get_next/95
pfe_rtable_get_next (struct pfe_rtable_t * rtable)
{
  struct pfe_rtable_entry_t * entry;
  struct LLIST_Struct * _1;
  struct LLIST_t * _2;
  struct LLIST_t * _3;
  int _5;
  struct LLIST_Struct * _6;
  <unnamed type> _7;
  union pfe_rtable_criterion_arg_t * _8;
  unsigned char _9;
  signed char _10;
  unsigned char _11;
  unsigned char _12;
  signed char _13;
  struct LLIST_t * _14;

  <bb 2> [local count: 122750723]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  # DEBUG BEGIN_STMT
  _1 = rtable_18(D)->active_entries.prNext;
  _2 = &rtable_18(D)->active_entries;
  if (_1 != _2)
    goto <bb 3>; [85.10%]
  else
    goto <bb 9>; [14.90%]

  <bb 3> [local count: 104460865]:
  # DEBUG BEGIN_STMT
  _3 = rtable_18(D)->cur_item;
  if (_2 == _3)
    goto <bb 9>; [14.90%]
  else
    goto <bb 10>; [85.10%]

  <bb 10> [local count: 88896196]:
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _5 = _14 - 176B;
  entry_20 = (struct pfe_rtable_entry_t *) _5;
  # DEBUG entry => entry_20
  # DEBUG BEGIN_STMT
  _6 = _14->prNext;
  rtable_18(D)->cur_item = _6;
  # DEBUG BEGIN_STMT
  if (_14 != 176B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 5> [local count: 542552617]:
  # DEBUG BEGIN_STMT
  _7 = rtable_18(D)->cur_crit;
  _8 = &rtable_18(D)->cur_crit_arg;
  _9 = pfe_rtable_match_criterion (_7, _8, entry_20);
  if (_9 == 1)
    goto <bb 6>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 6> [local count: 29840394]:
  # entry_4 = PHI <entry_20(5)>
  # DEBUG BEGIN_STMT
  # DEBUG match => 1
  # DEBUG BEGIN_STMT
  _10 = entry_4->ref_counter;
  _11 = (unsigned char) _10;
  _12 = _11 + 1;
  _13 = (signed char) _12;
  entry_4->ref_counter = _13;
  # DEBUG BEGIN_STMT
  # DEBUG match => 1
  # DEBUG entry => entry_4
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 984845632]:

  <bb 8> [local count: 1073741824]:
  # DEBUG entry => NULL
  # DEBUG BEGIN_STMT
  _14 = rtable_18(D)->cur_item;
  if (_2 != _14)
    goto <bb 4>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 122750721]:
  # entry_15 = PHI <entry_4(6), 0B(2), 0B(8), 0B(3)>
  # DEBUG match => NULL
  # DEBUG entry => entry_15
  # DEBUG BEGIN_STMT
  return entry_15;

}



;; Function pfe_rtable_get_stats (pfe_rtable_get_stats, funcdef_no=86, decl_uid=10559, cgraph_uid=87, symbol_order=96)

Modification phase of node pfe_rtable_get_stats/96
pfe_rtable_get_stats (const struct pfe_rtable_t * rtable, struct pfe_ct_conntrack_stats_t * stat, uint8_t conntrack_index)
{
  struct pfe_ct_conntrack_stats_t stats;
  uint16_t offset;
  errno_t ret;
  uint32_t i;
  short unsigned int _1;
  short unsigned int _2;
  struct pfe_class_t * _4;
  long int i.27_5;
  long unsigned int _6;
  unsigned int _7;
  unsigned int _8;
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
  struct pfe_class_t * _33;
  long unsigned int _34;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG offset => 0
  # DEBUG BEGIN_STMT
  _1 = (short unsigned int) conntrack_index_41(D);
  _2 = rtable_43(D)->conntrack_stats_table_size;
  if (_1 > _2)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 37904966]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid conntrack index\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 3273, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (stat_46(D), 0, 8);
  # DEBUG BEGIN_STMT
  offset_48 = _1 * 8;
  # DEBUG offset => offset_48
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  stats = {};
  # DEBUG BEGIN_STMT
  _4 = rtable_43(D)->class;
  i.27_5 = (long int) i_35;
  _6 = rtable_43(D)->conntrack_stats_table_addr;
  _7 = (unsigned int) offset_48;
  _8 = _6 + _7;
  ret_52 = pfe_class_read_dmem (_4, i.27_5, &stats, _8, 8);
  # DEBUG ret => ret_52
  # DEBUG BEGIN_STMT
  if (ret_52 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  _9 = stat_46(D)->hit;
  _10 = stats.hit;
  _11 = _10 >> 24;
  _12 = _10 >> 8;
  _13 = _12 & 65280;
  _14 = _11 | _13;
  _15 = _10 << 8;
  _16 = _15 & 16711680;
  _17 = _14 | _16;
  _18 = _10 << 24;
  _19 = _17 | _18;
  _20 = _9 + _19;
  stat_46(D)->hit = _20;
  # DEBUG BEGIN_STMT
  _21 = stat_46(D)->hit_bytes;
  _22 = stats.hit_bytes;
  _23 = _22 >> 24;
  _24 = _22 >> 8;
  _25 = _24 & 65280;
  _26 = _23 | _25;
  _27 = _22 << 8;
  _28 = _27 & 16711680;
  _29 = _26 | _28;
  _30 = _22 << 24;
  _31 = _29 | _30;
  _32 = _21 + _31;
  stat_46(D)->hit_bytes = _32;
  # DEBUG BEGIN_STMT
  i_55 = i_35 + 1;
  # DEBUG i => i_55
  stats ={v} {CLOBBER};
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 55807731]:
  # ret_3 = PHI <ret_52(5)>
  stats ={v} {CLOBBER};
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 1073741824]:
  # i_35 = PHI <0(4), i_55(6)>
  # ret_36 = PHI <0(4), 0(6)>
  # DEBUG ret => ret_36
  # DEBUG i => i_35
  # DEBUG BEGIN_STMT
  _33 = rtable_43(D)->class;
  _34 = pfe_class_get_num_of_pes (_33);
  if (_34 > i_35)
    goto <bb 5>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 114863532]:
  # ret_37 = PHI <ret_3(7), ret_36(8)>
  # DEBUG ret => ret_37
  # DEBUG BEGIN_STMT
  return ret_37;

}



;; Function pfe_rtable_clear_stats (pfe_rtable_clear_stats, funcdef_no=87, decl_uid=10705, cgraph_uid=88, symbol_order=97)

Modification phase of node pfe_rtable_clear_stats/97
pfe_rtable_clear_stats (const struct pfe_rtable_t * rtable, uint8_t conntrack_index)
{
  uint16_t offset;
  errno_t ret;
  short unsigned int _1;
  short unsigned int _2;
  struct pfe_class_t * _4;
  long unsigned int _5;
  unsigned int _6;
  unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG offset => 0
  # DEBUG BEGIN_STMT
  _1 = (short unsigned int) conntrack_index_11(D);
  _2 = rtable_13(D)->conntrack_stats_table_size;
  if (_1 > _2)
    goto <bb 3>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 3> [local count: 375809640]:
  # DEBUG D#15 => rtable_13(D)
  # DEBUG D#16 => conntrack_index_11(D)
  ret_3 = pfe_rtable_clear_stats.part.0 ();
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  offset_14 = _1 * 8;
  # DEBUG offset => offset_14
  # DEBUG BEGIN_STMT
  _4 = rtable_13(D)->class;
  _5 = rtable_13(D)->conntrack_stats_table_addr;
  _6 = (unsigned int) offset_14;
  _7 = _5 + _6;
  ret_16 = pfe_class_write_dmem (_4, -1, _7, &pfe_rtable_clear_stats_stat, 8);
  # DEBUG ret => ret_16

  <bb 5> [local count: 1073741824]:
  # ret_8 = PHI <ret_3(3), ret_16(4)>
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_rtable_del_entry_nolock (pfe_rtable_del_entry_nolock, funcdef_no=71, decl_uid=10657, cgraph_uid=72, symbol_order=81)

Modification phase of node pfe_rtable_del_entry_nolock/81
pfe_rtable_del_entry_nolock (struct pfe_rtable_t * rtable, struct pfe_rtable_entry_t * entry)
{
  struct pfe_ct_rtable_entry_t * _1;
  unsigned char _2;
  unsigned char _3;
  signed char _4;
  unsigned char _5;
  unsigned char _6;
  signed char _7;
  long unsigned int _8;
  long unsigned int _9;
  struct pfe_rtable_t * _22;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = MEM[(struct pfe_rtable_t * *)entry_13(D)];
  # DEBUG D#2 => entry_13(D)
  # DEBUG INLINE_ENTRY pfe_rtable_entry_is_in_table
  # DEBUG entry => D#2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_22 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 11>; [30.00%]

  <bb 3> [local count: 751619277]:
  # DEBUG ret => 1
  # DEBUG BEGIN_STMT
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  _1 = entry_13(D)->phys_entry;
  _2 = pfe_rtable_phys_entry_is_htable (rtable_14(D), _1);
  if (_2 == 1)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 152127742]:
  # DEBUG BEGIN_STMT
  pfe_rtable_del_entry_nolock_htable (rtable_14(D), entry_13(D));
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 599491536]:
  # DEBUG BEGIN_STMT
  _3 = pfe_rtable_phys_entry_is_pool (rtable_14(D), _1);
  if (_3 == 1)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 203827122]:
  # DEBUG BEGIN_STMT
  pfe_rtable_del_entry_nolock_pool (rtable_14(D), entry_13(D));
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 395664414]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Wrong address (found rtable entry @ v0x%p)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2478, _1, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 8> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  entry_13(D)->rtable = 0B;
  # DEBUG BEGIN_STMT
  _4 = entry_13(D)->ref_counter;
  _5 = (unsigned char) _4;
  _6 = _5 + 255;
  _7 = (signed char) _6;
  entry_13(D)->ref_counter = _7;
  # DEBUG BEGIN_STMT
  _8 = rtable_14(D)->active_entries_count;
  if (_8 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 9> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _9 = _8 + 4294967295;
  rtable_14(D)->active_entries_count = _9;
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  # DEBUG ret => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_rtable_del_entry (pfe_rtable_del_entry, funcdef_no=68, decl_uid=10426, cgraph_uid=69, symbol_order=78)

Modification phase of node pfe_rtable_del_entry/78
pfe_rtable_del_entry (struct pfe_rtable_t * rtable, struct pfe_rtable_entry_t * entry)
{
  errno_t ret;
  long unsigned int _1;
  struct pfe_class_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 79
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (79);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  ret_8 = pfe_rtable_del_entry_nolock (rtable_5(D), entry_6(D));
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  _1 = rtable_5(D)->active_entries_count;
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = rtable_5(D)->class;
  pfe_class_rtable_lookup_disable (_2);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 79
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (79);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_rtable_do_timeouts (pfe_rtable_do_timeouts, funcdef_no=72, decl_uid=10555, cgraph_uid=73, symbol_order=82)

Modification phase of node pfe_rtable_do_timeouts/82
pfe_rtable_do_timeouts (struct pfe_rtable_t * rtable)
{
  errno_t err;
  pfe_rtable_entry_status_t flags;
  struct pfe_rtable_entry_t * entry;
  struct LLIST_t to_be_removed_list;
  struct LLIST_t * aux;
  struct LLIST_t * item;
  int _1;
  struct pfe_ct_rtable_entry_t * _2;
  long unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  void (*<Tba5>) (void *, pfe_rtable_cbk_event_t) _10;
  void * _11;
  struct LLIST_Struct * _12;
  struct LLIST_t * _13;
  struct LLIST_t * _14;
  int _15;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 80
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (80);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  to_be_removed_list.prNext = &to_be_removed_list;
  # DEBUG BEGIN_STMT
  to_be_removed_list.prPrev = &to_be_removed_list;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  item_29 = rtable_28(D)->active_entries.prNext;
  # DEBUG item => item_29
  goto <bb 15>; [100.00%]

  <bb 3> [local count: 955630220]:
  # DEBUG BEGIN_STMT
  _1 = item_16 - 176B;
  entry_40 = (struct pfe_rtable_entry_t *) _1;
  # DEBUG entry => entry_40
  # DEBUG BEGIN_STMT
  _2 = entry_40->phys_entry;
  flags_41 = _2->status;
  # DEBUG flags => flags_41
  # DEBUG BEGIN_STMT
  _3 = entry_40->timeout;
  if (_3 == 4294967295)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 193419556]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 14>; [100.00%]

  <bb 5> [local count: 762210664]:
  # DEBUG BEGIN_STMT
  _4 = flags_41 & 1;
  if (_4 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 381105332]:
  # DEBUG BEGIN_STMT
  entry_40->curr_timeout = _3;
  # DEBUG BEGIN_STMT
  _5 = _2->status;
  _6 = _5 & 254;
  _2->status = _6;
  goto <bb 14>; [100.00%]

  <bb 7> [local count: 381105332]:
  # DEBUG BEGIN_STMT
  _7 = entry_40->curr_timeout;
  if (_7 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 190552666]:
  # DEBUG BEGIN_STMT
  _8 = _7 + 4294967295;
  entry_40->curr_timeout = _8;
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 190552666]:
  # DEBUG BEGIN_STMT
  entry_40->curr_timeout = 0;

  <bb 10> [local count: 381105332]:
  # DEBUG BEGIN_STMT
  _9 = entry_40->curr_timeout;
  if (_9 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 11> [local count: 190552666]:
  # DEBUG BEGIN_STMT
  _10 = entry_40->callback;
  if (_10 != 0B)
    goto <bb 12>; [70.00%]
  else
    goto <bb 13>; [30.00%]

  <bb 12> [local count: 133386866]:
  # DEBUG BEGIN_STMT
  _11 = entry_40->callback_arg;
  _10 (_11, 0);

  <bb 13> [local count: 190552666]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = to_be_removed_list.prPrev;
  entry_40->list_to_remove_entry.prPrev = _12;
  # DEBUG BEGIN_STMT
  entry_40->list_to_remove_entry.prNext = &to_be_removed_list;
  # DEBUG BEGIN_STMT
  _13 = &entry_40->list_to_remove_entry;
  _12->prNext = _13;
  # DEBUG BEGIN_STMT
  to_be_removed_list.prPrev = _13;

  <bb 14> [local count: 955630222]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  item_51 = item_16->prNext;
  # DEBUG item => item_51

  <bb 15> [local count: 1073741821]:
  # item_16 = PHI <item_29(2), item_51(14)>
  # DEBUG item => item_16
  # DEBUG BEGIN_STMT
  _14 = &rtable_28(D)->active_entries;
  if (_14 != item_16)
    goto <bb 3>; [89.00%]
  else
    goto <bb 16>; [11.00%]

  <bb 16> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  item_30 = to_be_removed_list.prNext;
  # DEBUG item => item_30
  aux_31 = item_30->prNext;
  # DEBUG aux => aux_31
  goto <bb 21>; [100.00%]

  <bb 17> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  _15 = item_17 - 184B;
  entry_33 = (struct pfe_rtable_entry_t *) _15;
  # DEBUG entry => entry_33
  # DEBUG BEGIN_STMT
  err_35 = pfe_rtable_del_entry_nolock (rtable_28(D), entry_33);
  # DEBUG err => err_35
  # DEBUG BEGIN_STMT
  if (err_35 != 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 18> [local count: 477815112]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t delete timed-out entry: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_rtable.c", 2576, err_35, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 20>; [100.00%]

  <bb 19> [local count: 477815112]:
  # DEBUG BEGIN_STMT
  pfe_rtable_entry_free_nolock (entry_33, 0);

  <bb 20> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  # DEBUG item => aux_18
  aux_39 = aux_18->prNext;
  # DEBUG aux => aux_39

  <bb 21> [local count: 1073741824]:
  # item_17 = PHI <item_30(16), aux_18(20)>
  # aux_18 = PHI <aux_31(16), aux_39(20)>
  # DEBUG aux => aux_18
  # DEBUG item => item_17
  # DEBUG BEGIN_STMT
  if (&to_be_removed_list != item_17)
    goto <bb 17>; [89.00%]
  else
    goto <bb 22>; [11.00%]

  <bb 22> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 80
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (80);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  to_be_removed_list ={v} {CLOBBER};
  return;

}


