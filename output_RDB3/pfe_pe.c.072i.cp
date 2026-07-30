
IPA constant propagation start:
Determining dynamic type for call: _1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
  Starting walk at: _1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
  instance pointer: pe_31(D)  Outer instance pointer: pe_31(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
  Starting walk at: _1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
  instance pointer: &mmap_data  Outer instance pointer: mmap_data offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_31(D), &flags, _12, 1);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_31(D), &flags, _12, 1);
  instance pointer: pe_31(D)  Outer instance pointer: pe_31(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_31(D), &flags, _12, 1);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_31(D), &flags, _12, 1);
  instance pointer: &flags  Outer instance pointer: flags offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_31(D), _25, buf_34(D), 66);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_31(D), _25, buf_34(D), 66);
  instance pointer: pe_31(D)  Outer instance pointer: pe_31(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_31(D), &flags, _12, 1);
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_31(D), _25, buf_34(D), 66);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_31(D), _25, buf_34(D), 66);
  instance pointer: buf_34(D)  Outer instance pointer: buf_34(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_31(D), &flags, _12, 1);
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
Determining dynamic type for call: _1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
  Starting walk at: _1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
  instance pointer: pe_40(D)  Outer instance pointer: pe_40(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
  Starting walk at: _1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
  instance pointer: &mmap_data  Outer instance pointer: mmap_data offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  instance pointer: pe_40(D)  Outer instance pointer: pe_40(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  instance pointer: &flags  Outer instance pointer: flags offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), buf_43(D), _23, 66);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), buf_43(D), _23, 66);
  instance pointer: pe_40(D)  Outer instance pointer: pe_40(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), buf_43(D), _23, 66);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), buf_43(D), _23, 66);
  instance pointer: buf_43(D)  Outer instance pointer: buf_43(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_40(D), _34, &flags, 1);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_40(D), _34, &flags, 1);
  instance pointer: pe_40(D)  Outer instance pointer: pe_40(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), buf_43(D), _23, 66);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_40(D), _34, &flags, 1);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_40(D), _34, &flags, 1);
  instance pointer: &flags  Outer instance pointer: flags offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), buf_43(D), _23, 66);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  Function call may change dynamic type:_1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
Determining dynamic type for call: pfe_pe_lock_family (pe_5(D));
  Starting walk at: pfe_pe_lock_family (pe_5(D));
  instance pointer: pe_5(D)  Outer instance pointer: pe_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (29);
Determining dynamic type for call: _1 = pfe_pe_get_state_monitor_nolock (pe_5(D), &state_monitor);
  Starting walk at: _1 = pfe_pe_get_state_monitor_nolock (pe_5(D), &state_monitor);
  instance pointer: pe_5(D)  Outer instance pointer: pe_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_lock_family (pe_5(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (29);
Determining dynamic type for call: _1 = pfe_pe_get_state_monitor_nolock (pe_5(D), &state_monitor);
  Starting walk at: _1 = pfe_pe_get_state_monitor_nolock (pe_5(D), &state_monitor);
  instance pointer: &state_monitor  Outer instance pointer: state_monitor offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_lock_family (pe_5(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (29);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 16);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 16);
  instance pointer: pe_2(D)  Outer instance pointer: pe_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 16);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 16);
  instance pointer: stats_3(D)  Outer instance pointer: stats_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 184);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 184);
  instance pointer: pe_2(D)  Outer instance pointer: pe_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 184);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 184);
  instance pointer: stats_3(D)  Outer instance pointer: stats_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_pe_get_state_monitor_nolock (pe_30(D), &state_monitor);
  Starting walk at: _1 = pfe_pe_get_state_monitor_nolock (pe_30(D), &state_monitor);
  instance pointer: pe_30(D)  Outer instance pointer: pe_30(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_pe_get_state_monitor_nolock (pe_30(D), &state_monitor);
  Starting walk at: _1 = pfe_pe_get_state_monitor_nolock (pe_30(D), &state_monitor);
  instance pointer: &state_monitor  Outer instance pointer: state_monitor offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 52);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 52);
  instance pointer: pe_2(D)  Outer instance pointer: pe_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 52);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 52);
  instance pointer: stats_3(D)  Outer instance pointer: stats_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_pe_get_mmap (pe_5(D), &pfe_pe_mmap);
  Starting walk at: _1 = pfe_pe_get_mmap (pe_5(D), &pfe_pe_mmap);
  instance pointer: pe_5(D)  Outer instance pointer: pe_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_pe_get_mmap (pe_5(D), &pfe_pe_mmap);
  Starting walk at: _1 = pfe_pe_get_mmap (pe_5(D), &pfe_pe_mmap);
  instance pointer: &pfe_pe_mmap  Outer instance pointer: pfe_pe_mmap offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_pe_get_mmap (pe_47(D), &pfe_pe_mmap);
  Starting walk at: _3 = pfe_pe_get_mmap (pe_47(D), &pfe_pe_mmap);
  instance pointer: pe_47(D)  Outer instance pointer: pe_47(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_pe_get_mmap (pe_47(D), &pfe_pe_mmap);
  Starting walk at: _3 = pfe_pe_get_mmap (pe_47(D), &pfe_pe_mmap);
  instance pointer: &pfe_pe_mmap  Outer instance pointer: pfe_pe_mmap offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_lock_family (pe_25(D));
  Starting walk at: pfe_pe_lock_family (pe_25(D));
  instance pointer: pe_25(D)  Outer instance pointer: pe_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (24);
  Function call may change dynamic type:oal_mutex_lock.part.0 (32);
Determining dynamic type for call: ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  Starting walk at: ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  instance pointer: pe_25(D)  Outer instance pointer: pe_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_lock_family (pe_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (24);
  Function call may change dynamic type:oal_mutex_lock.part.0 (32);
Determining dynamic type for call: _12 = pfe_pe_fw_load_cycles.isra.0 (_39, _2);
  Starting walk at: _12 = pfe_pe_fw_load_cycles.isra.0 (_39, _2);
  instance pointer: _39  Outer instance pointer: _39 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1980, ret_29, "");
  Function call may change dynamic type:ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  Function call may change dynamic type:pfe_pe_lock_family (pe_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (24);
  Function call may change dynamic type:oal_mutex_lock.part.0 (32);
  Function call may change dynamic type:_9 (_4, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_4, 0, 0, 0, _7);
Determining dynamic type for call: _6 (_4, 0, 0, 0, _7);
  Starting walk at: _6 (_4, 0, 0, 0, _7);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1980, ret_29, "");
  Function call may change dynamic type:ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  Function call may change dynamic type:pfe_pe_lock_family (pe_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (24);
  Function call may change dynamic type:oal_mutex_lock.part.0 (32);
  Function call may change dynamic type:_9 (_4, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_4, 0, 0, 0, _7);
Determining dynamic type for call: _9 (_4, 1, 0, 0, _10);
  Starting walk at: _9 (_4, 1, 0, 0, _10);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 (_4, 0, 0, 0, _7);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1980, ret_29, "");
  Function call may change dynamic type:ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  Function call may change dynamic type:pfe_pe_lock_family (pe_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (24);
  Function call may change dynamic type:oal_mutex_lock.part.0 (32);
  Function call may change dynamic type:_9 (_4, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_4, 0, 0, 0, _7);
Determining dynamic type for call: ret_38 = pfe_pe_load_firmware_aux (pe_25(D), pe_num_27(D), elf_36(D));
  Starting walk at: ret_38 = pfe_pe_load_firmware_aux (pe_25(D), pe_num_27(D), elf_36(D));
  instance pointer: pe_25(D)  Outer instance pointer: pe_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1980, ret_29, "");
  Function call may change dynamic type:ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  Function call may change dynamic type:pfe_pe_lock_family (pe_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (24);
  Function call may change dynamic type:oal_mutex_lock.part.0 (32);
  Function call may change dynamic type:_9 (_4, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_4, 0, 0, 0, _7);
Determining dynamic type for call: ret_38 = pfe_pe_load_firmware_aux (pe_25(D), pe_num_27(D), elf_36(D));
  Starting walk at: ret_38 = pfe_pe_load_firmware_aux (pe_25(D), pe_num_27(D), elf_36(D));
  instance pointer: elf_36(D)  Outer instance pointer: elf_36(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1980, ret_29, "");
  Function call may change dynamic type:ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  Function call may change dynamic type:pfe_pe_lock_family (pe_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (24);
  Function call may change dynamic type:oal_mutex_lock.part.0 (32);
  Function call may change dynamic type:_9 (_4, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_4, 0, 0, 0, _7);
Determining dynamic type for call: pfe_pe_free_mem (pe_67(D), pe_num_68(D));
  Starting walk at: pfe_pe_free_mem (pe_67(D), pe_num_68(D));
  instance pointer: pe_67(D)  Outer instance pointer: pe_67(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_43 = autolibc_strcmp (&mmap_version_str, &tmp_mmap.common.version.cthdr);
  Function call may change dynamic type:autolibc_memcpy (&tmp_mmap, _42, _28);
  Function call may change dynamic type:autolibc_memcpy (&mmap_size, _18, 4);
  Function call may change dynamic type:_1 = ELF_SectFindName (elf_58(D), ".pfe_pe_mmap", &section_idx, 0B, 0B);
Determining dynamic type for call: ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  Starting walk at: ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  instance pointer: elf_58(D)  Outer instance pointer: elf_58(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_43 = autolibc_strcmp (&mmap_version_str, &tmp_mmap.common.version.cthdr);
  Function call may change dynamic type:autolibc_memcpy (&tmp_mmap, _42, _28);
  Function call may change dynamic type:autolibc_memcpy (&mmap_size, _18, 4);
  Function call may change dynamic type:_1 = ELF_SectFindName (elf_58(D), ".pfe_pe_mmap", &section_idx, 0B, 0B);
Determining dynamic type for call: ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  Starting walk at: ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  instance pointer: &features_size  Outer instance pointer: features_size offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_43 = autolibc_strcmp (&mmap_version_str, &tmp_mmap.common.version.cthdr);
  Function call may change dynamic type:autolibc_memcpy (&tmp_mmap, _42, _28);
  Function call may change dynamic type:autolibc_memcpy (&mmap_size, _18, 4);
  Function call may change dynamic type:_1 = ELF_SectFindName (elf_58(D), ".pfe_pe_mmap", &section_idx, 0B, 0B);
Determining dynamic type for call: ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  Starting walk at: ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  instance pointer: &messages_size  Outer instance pointer: messages_size offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_43 = autolibc_strcmp (&mmap_version_str, &tmp_mmap.common.version.cthdr);
  Function call may change dynamic type:autolibc_memcpy (&tmp_mmap, _42, _28);
  Function call may change dynamic type:autolibc_memcpy (&mmap_size, _18, 4);
  Function call may change dynamic type:_1 = ELF_SectFindName (elf_58(D), ".pfe_pe_mmap", &section_idx, 0B, 0B);
Determining dynamic type for call: ret_74 = pfe_pe_upload_sections (pe_67(D), pe_num_68(D), elf_58(D));
  Starting walk at: ret_74 = pfe_pe_upload_sections (pe_67(D), pe_num_68(D), elf_58(D));
  instance pointer: pe_67(D)  Outer instance pointer: pe_67(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  Function call may change dynamic type:_43 = autolibc_strcmp (&mmap_version_str, &tmp_mmap.common.version.cthdr);
  Function call may change dynamic type:autolibc_memcpy (&tmp_mmap, _42, _28);
  Function call may change dynamic type:autolibc_memcpy (&mmap_size, _18, 4);
  Function call may change dynamic type:_1 = ELF_SectFindName (elf_58(D), ".pfe_pe_mmap", &section_idx, 0B, 0B);
Determining dynamic type for call: ret_74 = pfe_pe_upload_sections (pe_67(D), pe_num_68(D), elf_58(D));
  Starting walk at: ret_74 = pfe_pe_upload_sections (pe_67(D), pe_num_68(D), elf_58(D));
  instance pointer: elf_58(D)  Outer instance pointer: elf_58(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  Function call may change dynamic type:_43 = autolibc_strcmp (&mmap_version_str, &tmp_mmap.common.version.cthdr);
  Function call may change dynamic type:autolibc_memcpy (&tmp_mmap, _42, _28);
  Function call may change dynamic type:autolibc_memcpy (&mmap_size, _18, 4);
  Function call may change dynamic type:_1 = ELF_SectFindName (elf_58(D), ".pfe_pe_mmap", &section_idx, 0B, 0B);
Determining dynamic type for call: pfe_pe_free_mem (pe_67(D), pe_num_68(D));
  Starting walk at: pfe_pe_free_mem (pe_67(D), pe_num_68(D));
  instance pointer: pe_67(D)  Outer instance pointer: pe_67(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_71 = pfe_pe_copy_firmware_sections (elf_58(D), &features_size, &messages_size);
  Function call may change dynamic type:_43 = autolibc_strcmp (&mmap_version_str, &tmp_mmap.common.version.cthdr);
  Function call may change dynamic type:autolibc_memcpy (&tmp_mmap, _42, _28);
  Function call may change dynamic type:autolibc_memcpy (&mmap_size, _18, 4);
  Function call may change dynamic type:_1 = ELF_SectFindName (elf_58(D), ".pfe_pe_mmap", &section_idx, 0B, 0B);
Determining dynamic type for call: pfe_pe_lock_family (pe_20(D));
  Starting walk at: pfe_pe_lock_family (pe_20(D));
  instance pointer: pe_20(D)  Outer instance pointer: pe_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (33);
Determining dynamic type for call: ret_24 = pfe_pe_fw_install_ops (pe_20(D), _1);
  Starting walk at: ret_24 = pfe_pe_fw_install_ops (pe_20(D), _1);
  instance pointer: pe_20(D)  Outer instance pointer: pe_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_lock_family (pe_20(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (33);
Determining dynamic type for call: _12 = pfe_pe_fw_load_cycles.isra.0 (_32, _1);
  Starting walk at: _12 = pfe_pe_fw_load_cycles.isra.0 (_32, _1);
  instance pointer: _32  Outer instance pointer: _32 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1731, ret_24, "");
  Function call may change dynamic type:ret_24 = pfe_pe_fw_install_ops (pe_20(D), _1);
  Function call may change dynamic type:pfe_pe_lock_family (pe_20(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (33);
  Function call may change dynamic type:_9 (_3, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_3, 0, 0, 0, _7);
Determining dynamic type for call: _6 (_3, 0, 0, 0, _7);
  Starting walk at: _6 (_3, 0, 0, 0, _7);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1731, ret_24, "");
  Function call may change dynamic type:ret_24 = pfe_pe_fw_install_ops (pe_20(D), _1);
  Function call may change dynamic type:pfe_pe_lock_family (pe_20(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (33);
  Function call may change dynamic type:_9 (_3, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_3, 0, 0, 0, _7);
Determining dynamic type for call: _9 (_3, 1, 0, 0, _10);
  Starting walk at: _9 (_3, 1, 0, 0, _10);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 (_3, 0, 0, 0, _7);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1731, ret_24, "");
  Function call may change dynamic type:ret_24 = pfe_pe_fw_install_ops (pe_20(D), _1);
  Function call may change dynamic type:pfe_pe_lock_family (pe_20(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (33);
  Function call may change dynamic type:_9 (_3, 1, 0, 0, _10);
  Function call may change dynamic type:_6 (_3, 0, 0, 0, _7);
Determining dynamic type for call: _1 = pfe_pe_is_dmem (pe_7(D), load_addr_8(D), size_9(D));
  Starting walk at: _1 = pfe_pe_is_dmem (pe_7(D), load_addr_8(D), size_9(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_pe_is_imem (pe_7(D), load_addr_8(D), size_9(D));
  Starting walk at: _2 = pfe_pe_is_imem (pe_7(D), load_addr_8(D), size_9(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_val_15 = pfe_pe_load_imem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  Starting walk at: ret_val_15 = pfe_pe_load_imem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_val_15 = pfe_pe_load_imem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  Starting walk at: ret_val_15 = pfe_pe_load_imem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  instance pointer: sdata_12(D)  Outer instance pointer: sdata_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_val_17 = pfe_pe_load_dmem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  Starting walk at: ret_val_17 = pfe_pe_load_dmem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_val_17 = pfe_pe_load_dmem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  Starting walk at: ret_val_17 = pfe_pe_load_dmem_section_nolock (pe_7(D), sdata_12(D), load_addr_8(D), size_9(D), type_13(D));
  instance pointer: sdata_12(D)  Outer instance pointer: sdata_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 (pe_19(D), 1, _11, data_14(D), size_16(D));
  Starting walk at: _9 (pe_19(D), 1, _11, data_14(D), size_16(D));
  instance pointer: pe_19(D)  Outer instance pointer: pe_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 (pe_19(D), 1, _11, data_14(D), size_16(D));
  Starting walk at: _9 (pe_19(D), 1, _11, data_14(D), size_16(D));
  instance pointer: data_14(D)  Outer instance pointer: data_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _12 (pe_19(D), 0, 0, addr_16(D), size_20(D));
  Starting walk at: _12 (pe_19(D), 0, 0, addr_16(D), size_20(D));
  instance pointer: pe_19(D)  Outer instance pointer: pe_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 (pe_19(D), 0, _10, sdata_15(D), size_20(D));
  Starting walk at: _8 (pe_19(D), 0, _10, sdata_15(D), size_20(D));
  instance pointer: pe_19(D)  Outer instance pointer: pe_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 (pe_19(D), 0, _10, sdata_15(D), size_20(D));
  Starting walk at: _8 (pe_19(D), 0, _10, sdata_15(D), size_20(D));
  instance pointer: sdata_15(D)  Outer instance pointer: sdata_15(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_lock_family (pe_33(D));
  Starting walk at: pfe_pe_lock_family (pe_33(D));
  instance pointer: pe_33(D)  Outer instance pointer: pe_33(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (28);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_33(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (28);
  Function call may change dynamic type:ret_50 = pfe_pe_memlock_acquire_nolock (_3);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Memory lock failed for PE instance %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1214, ii_16, "");
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_33(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (28);
  Function call may change dynamic type:ret_50 = pfe_pe_memlock_acquire_nolock (_3);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Memory lock failed for PE instance %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1214, ii_16, "");
Determining dynamic type for call: ret_45 = pfe_pe_memlock_release_nolock (_15);
  Starting walk at: ret_45 = pfe_pe_memlock_release_nolock (_15);
  instance pointer: _15  Outer instance pointer: _15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_33(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (28);
  Function call may change dynamic type:ret_50 = pfe_pe_memlock_acquire_nolock (_3);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Memory lock failed for PE instance %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1214, ii_16, "");
  Function call may change dynamic type:ret_45 = pfe_pe_memlock_release_nolock (_15);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Memory unlock failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1248, "");
Determining dynamic type for call: ret_50 = pfe_pe_memlock_acquire_nolock (_3);
  Starting walk at: ret_50 = pfe_pe_memlock_acquire_nolock (_3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_lock_family (pe_33(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (28);
  Function call may change dynamic type:ret_50 = pfe_pe_memlock_acquire_nolock (_3);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Memory lock failed for PE instance %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1214, ii_16, "");
Determining dynamic type for call: pfe_pe_lock_family (pe_7(D));
  Starting walk at: pfe_pe_lock_family (pe_7(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (23);
  Function call may change dynamic type:oal_mutex_lock.part.0 (31);
Determining dynamic type for call: ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Starting walk at: ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (23);
  Function call may change dynamic type:oal_mutex_lock.part.0 (31);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_7(D), dst_ptr_11(D), src_addr_12(D), len_13(D));
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_7(D), dst_ptr_11(D), src_addr_12(D), len_13(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (23);
  Function call may change dynamic type:oal_mutex_lock.part.0 (31);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_7(D), dst_ptr_11(D), src_addr_12(D), len_13(D));
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_7(D), dst_ptr_11(D), src_addr_12(D), len_13(D));
  instance pointer: dst_ptr_11(D)  Outer instance pointer: dst_ptr_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (23);
  Function call may change dynamic type:oal_mutex_lock.part.0 (31);
Determining dynamic type for call: pfe_pe_memlock_release_nolock (pe_7(D));
  Starting walk at: pfe_pe_memlock_release_nolock (pe_7(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_7(D), dst_ptr_11(D), src_addr_12(D), len_13(D));
  Function call may change dynamic type:ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (23);
  Function call may change dynamic type:oal_mutex_lock.part.0 (31);
Determining dynamic type for call: _1 = pfe_pe_mem_read (pe_22(D), 0, src_temp_9, 1);
  Starting walk at: _1 = pfe_pe_mem_read (pe_22(D), 0, src_temp_9, 1);
  instance pointer: pe_22(D)  Outer instance pointer: pe_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (dst_byteptr_7, &val, 1);
  Function call may change dynamic type:_1 = pfe_pe_mem_read (pe_22(D), 0, src_temp_9, 1);
Determining dynamic type for call: _6 = pfe_pe_mem_read (pe_22(D), 0, src_temp_4, _5);
  Starting walk at: _6 = pfe_pe_mem_read (pe_22(D), 0, src_temp_4, _5);
  instance pointer: pe_22(D)  Outer instance pointer: pe_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (dst_byteptr_7, &val, 1);
  Function call may change dynamic type:_1 = pfe_pe_mem_read (pe_22(D), 0, src_temp_9, 1);
  Function call may change dynamic type:_3 = pfe_pe_mem_read (pe_22(D), 0, src_temp_10, 4);
Determining dynamic type for call: _3 = pfe_pe_mem_read (pe_22(D), 0, src_temp_10, 4);
  Starting walk at: _3 = pfe_pe_mem_read (pe_22(D), 0, src_temp_10, 4);
  instance pointer: pe_22(D)  Outer instance pointer: pe_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (dst_byteptr_7, &val, 1);
  Function call may change dynamic type:_1 = pfe_pe_mem_read (pe_22(D), 0, src_temp_9, 1);
  Function call may change dynamic type:_3 = pfe_pe_mem_read (pe_22(D), 0, src_temp_10, 4);
Determining dynamic type for call: pfe_pe_lock_family (pe_7(D));
  Starting walk at: pfe_pe_lock_family (pe_7(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (22);
  Function call may change dynamic type:oal_mutex_lock.part.0 (30);
Determining dynamic type for call: ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Starting walk at: ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (22);
  Function call may change dynamic type:oal_mutex_lock.part.0 (30);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_7(D), dst_addr_11(D), src_ptr_12(D), len_13(D));
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_7(D), dst_addr_11(D), src_ptr_12(D), len_13(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (22);
  Function call may change dynamic type:oal_mutex_lock.part.0 (30);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_7(D), dst_addr_11(D), src_ptr_12(D), len_13(D));
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_7(D), dst_addr_11(D), src_ptr_12(D), len_13(D));
  instance pointer: src_ptr_12(D)  Outer instance pointer: src_ptr_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (22);
  Function call may change dynamic type:oal_mutex_lock.part.0 (30);
Determining dynamic type for call: pfe_pe_memlock_release_nolock (pe_7(D));
  Starting walk at: pfe_pe_memlock_release_nolock (pe_7(D));
  instance pointer: pe_7(D)  Outer instance pointer: pe_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_7(D), dst_addr_11(D), src_ptr_12(D), len_13(D));
  Function call may change dynamic type:ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  Function call may change dynamic type:pfe_pe_lock_family (pe_7(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (22);
  Function call may change dynamic type:oal_mutex_lock.part.0 (30);
Determining dynamic type for call: pfe_pe_mem_write.isra.0 (pe_26(D), 0, _5, mem_data$addr_21, 1, _3);
  Starting walk at: pfe_pe_mem_write.isra.0 (pe_26(D), 0, _5, mem_data$addr_21, 1, _3);
  instance pointer: pe_26(D)  Outer instance pointer: pe_26(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_mem_write.isra.0 (pe_26(D), 0, _5, mem_data$addr_21, 1, _3);
Determining dynamic type for call: _11 = pfe_pe_get_u32_from_byteptr (src_byteptr_35, len_temp_37);
  Starting walk at: _11 = pfe_pe_get_u32_from_byteptr (src_byteptr_35, len_temp_37);
  instance pointer: src_byteptr_35  Outer instance pointer: src_byteptr_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_mem_write.isra.0 (pe_26(D), 0, _5, mem_data$addr_21, 1, _3);
  Function call may change dynamic type:pfe_pe_mem_write.isra.0 (pe_26(D), 0, _9, mem_data$addr_23, 4, 0);
Determining dynamic type for call: pfe_pe_mem_write.isra.0 (pe_26(D), 0, _11, mem_data$addr_7, _12, 0);
  Starting walk at: pfe_pe_mem_write.isra.0 (pe_26(D), 0, _11, mem_data$addr_7, _12, 0);
  instance pointer: pe_26(D)  Outer instance pointer: pe_26(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_mem_write.isra.0 (pe_26(D), 0, _5, mem_data$addr_21, 1, _3);
  Function call may change dynamic type:pfe_pe_mem_write.isra.0 (pe_26(D), 0, _9, mem_data$addr_23, 4, 0);
Determining dynamic type for call: pfe_pe_mem_write.isra.0 (pe_26(D), 0, _9, mem_data$addr_23, 4, 0);
  Starting walk at: pfe_pe_mem_write.isra.0 (pe_26(D), 0, _9, mem_data$addr_23, 4, 0);
  instance pointer: pe_26(D)  Outer instance pointer: pe_26(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_mem_write.isra.0 (pe_26(D), 0, _5, mem_data$addr_21, 1, _3);
  Function call may change dynamic type:pfe_pe_mem_write.isra.0 (pe_26(D), 0, _9, mem_data$addr_23, 4, 0);
Determining dynamic type for call: _1 = pfe_pe_check_pe_times.isra.0 (pe_27(D), idx_12, best_pe_loader_cnt_16, pe_num_25(D));
  Starting walk at: _1 = pfe_pe_check_pe_times.isra.0 (pe_27(D), idx_12, best_pe_loader_cnt_16, pe_num_25(D));
  instance pointer: pe_27(D)  Outer instance pointer: pe_27(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] PEs are not identical\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 546, "");
Determining dynamic type for call: ret_32 = pfe_pe_fw_ops_valid (pe_27(D), _4);
  Starting walk at: ret_32 = pfe_pe_fw_ops_valid (pe_27(D), _4);
  instance pointer: pe_27(D)  Outer instance pointer: pe_27(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] PEs are not identical\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 546, "");
Determining dynamic type for call: ret_32 = pfe_pe_fw_ops_valid (pe_27(D), _4);
  Starting walk at: ret_32 = pfe_pe_fw_ops_valid (pe_27(D), _4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] PEs are not identical\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 546, "");
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_15(D), misc_dmem_16, &misc_ctrl, 4);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_15(D), misc_dmem_16, &misc_ctrl, 4);
  instance pointer: pe_15(D)  Outer instance pointer: pe_15(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_15(D), misc_dmem_16, &misc_ctrl, 4);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_15(D), misc_dmem_16, &misc_ctrl, 4);
  instance pointer: &misc_ctrl  Outer instance pointer: misc_ctrl offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_17 = pfe_pe_mem_process_lock (pe_14(D), misc_dmem_15);
  Starting walk at: ret_17 = pfe_pe_mem_process_lock (pe_14(D), misc_dmem_15);
  instance pointer: pe_14(D)  Outer instance pointer: pe_14(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  instance pointer: pe_11(D)  Outer instance pointer: pe_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  instance pointer: &misc_ctrl  Outer instance pointer: misc_ctrl offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  instance pointer: pe_11(D)  Outer instance pointer: pe_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  instance pointer: &misc_ctrl  Outer instance pointer: misc_ctrl offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
Determining dynamic type for call: _3 = pfe_pe_is_active_nolock (pe_11(D));
  Starting walk at: _3 = pfe_pe_is_active_nolock (pe_11(D));
  instance pointer: pe_11(D)  Outer instance pointer: pe_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  instance pointer: pe_11(D)  Outer instance pointer: pe_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:_3 = pfe_pe_is_active_nolock (pe_11(D));
  Function call may change dynamic type:pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:oal_time_usleep (10);
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  instance pointer: &misc_ctrl  Outer instance pointer: misc_ctrl offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_time_usleep (10);
  Function call may change dynamic type:_3 = pfe_pe_is_active_nolock (pe_11(D));
  Function call may change dynamic type:pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:oal_time_usleep (10);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  instance pointer: pe_11(D)  Outer instance pointer: pe_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Timed-out\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 360, "");
  Function call may change dynamic type:_3 = pfe_pe_is_active_nolock (pe_11(D));
  Function call may change dynamic type:pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:oal_time_usleep (10);
Determining dynamic type for call: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Starting walk at: pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  instance pointer: &misc_ctrl  Outer instance pointer: misc_ctrl offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Timed-out\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 360, "");
  Function call may change dynamic type:_3 = pfe_pe_is_active_nolock (pe_11(D));
  Function call may change dynamic type:pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_11(D), misc_dmem_12(D), &misc_ctrl, 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_11(D), &misc_ctrl, misc_dmem_12(D), 4);
  Function call may change dynamic type:oal_time_usleep (10);
Determining dynamic type for call: _1 = pfe_pe_get_state_monitor_nolock (pe_6(D), &state_monitor);
  Starting walk at: _1 = pfe_pe_get_state_monitor_nolock (pe_6(D), &state_monitor);
  instance pointer: pe_6(D)  Outer instance pointer: pe_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_pe_get_state_monitor_nolock (pe_6(D), &state_monitor);
  Starting walk at: _1 = pfe_pe_get_state_monitor_nolock (pe_6(D), &state_monitor);
  instance pointer: &state_monitor  Outer instance pointer: state_monitor offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_15(D), state_monitor_16(D), _11, 8);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_15(D), state_monitor_16(D), _11, 8);
  instance pointer: pe_15(D)  Outer instance pointer: pe_15(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_15(D), state_monitor_16(D), _11, 8);
  Starting walk at: pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_15(D), state_monitor_16(D), _11, 8);
  instance pointer: state_monitor_16(D)  Outer instance pointer: state_monitor_16(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  Starting walk at: load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  instance pointer: elf_file_92(D)  Outer instance pointer: elf_file_92(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
Determining dynamic type for call: load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  Starting walk at: load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
Determining dynamic type for call: _75 = pfe_pe_fw_load_cycles.isra.0 (_110, _74);
  Starting walk at: _75 = pfe_pe_fw_load_cycles.isra.0 (_110, _74);
  instance pointer: _110  Outer instance pointer: _110 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  Function call may change dynamic type:pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
Determining dynamic type for call: ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Starting walk at: ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  instance pointer: _51  Outer instance pointer: _51 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  Function call may change dynamic type:pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
Determining dynamic type for call: ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Starting walk at: ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  instance pointer: buf_93  Outer instance pointer: buf_93 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  Function call may change dynamic type:pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
Determining dynamic type for call: pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Starting walk at: pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  instance pointer: pe_97(D)  Outer instance pointer: pe_97(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  Function call may change dynamic type:pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
Determining dynamic type for call: pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Starting walk at: pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  instance pointer: pe_97(D)  Outer instance pointer: pe_97(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);
  Function call may change dynamic type:pfe_pe_free_mem (pe_97(D), pe_num_96(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t upload firmware section %s, %u bytes @ 0x%08x. Reason: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 194, _73, sh_size_6, sh_addr_103, ret_7, "");
  Function call may change dynamic type:ret_101 = pfe_pe_load_elf_section (_51, buf_93, load_addr_95, sh_size_99, sh_type_98);
  Function call may change dynamic type:load_addr_95 = pfe_pe_get_elf_sect_load_addr (elf_file_92(D), _3);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_pe_mem_write.isra.0/308:
  Jump functions of caller  pfe_pe_check_pe_times.isra.0/306:
  Jump functions of caller  pfe_pe_fw_load_cycles.isra.0/305:
  Jump functions of caller  oal_mutex_unlock.part.0/304:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/303:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  Dem_SetEventStatus/302:
  Jump functions of caller  autolibc_strcmp/299:
  Jump functions of caller  ELF_SectFindName/298:
  Jump functions of caller  autolibc_memset/297:
  Jump functions of caller  autolibc_memcpy/296:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/295:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/294:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/293:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/292:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/291:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/290:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/289:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/288:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/287:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/286:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/285:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/284:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/283:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/282:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/281:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/280:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/279:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/278:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/277:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/276:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/275:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/274:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/273:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/272:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/271:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/270:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/269:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/268:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/267:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/266:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/265:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/264:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/263:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/262:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/261:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/260:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/259:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/258:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/257:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/256:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/255:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/254:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/253:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/252:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/251:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/250:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/249:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/248:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/247:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/246:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/245:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/244:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/243:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/242:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/241:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/240:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/239:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/238:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/237:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/236:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/235:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/234:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/233:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/232:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/231:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/230:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/229:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/228:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/227:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/226:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/225:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/224:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/223:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/222:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/221:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/220:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/219:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/218:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/217:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/216:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/215:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/214:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/213:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/212:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/211:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/210:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/209:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/208:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/207:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/206:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/205:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/204:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/203:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/202:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/201:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/200:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/199:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/198:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/197:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/196:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/195:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/194:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/193:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/192:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/191:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/190:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/189:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/188:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/187:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/186:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/185:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/184:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/183:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/182:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/181:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/180:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/179:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/178:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/177:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/176:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/175:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/174:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/173:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/172:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/171:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/170:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/169:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/168:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/167:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/166:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/165:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/164:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/163:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/162:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/161:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/160:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/159:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/158:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/157:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/156:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/155:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/154:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/153:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/152:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/151:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/150:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/149:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/148:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/147:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/146:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/145:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/144:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/143:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/142:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/141:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/140:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/139:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/138:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/137:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/136:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/135:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/134:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/133:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/132:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/131:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/130:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/129:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/128:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/127:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/126:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/125:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/124:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/123:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/122:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/121:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/120:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/119:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/118:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/117:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/116:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/115:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/114:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/113:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/112:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/111:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/110:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/109:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/108:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/107:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/106:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/105:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/104:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/103:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/102:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/101:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/100:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/99:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/98:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/97:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/96:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/95:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/94:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/93:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/92:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/91:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/90:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/89:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/88:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/87:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/86:
  Jump functions of caller  oal_time_usleep/85:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/84:
  Jump functions of caller  pfe_hm_report/83:
  Jump functions of caller  __builtin_expect/82:
  Jump functions of caller  pfe_pe_put_data_nolock/81:
    callsite  pfe_pe_put_data_nolock/81 -> pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 66
         value: 0x42, mask: 0x0
         Unknown VR
    callsite  pfe_pe_put_data_nolock/81 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_pe_put_data_nolock/81 -> pfe_pe_get_mmap/69 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_pe_get_data_nolock/80:
    callsite  pfe_pe_get_data_nolock/80 -> pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_pe_get_data_nolock/80 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 66
         value: 0x42, mask: 0x0
         Unknown VR
    callsite  pfe_pe_get_data_nolock/80 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_pe_get_data_nolock/80 -> pfe_pe_get_mmap/69 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_pe_get_fw_state/79:
    callsite  pfe_pe_get_fw_state/79 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 29
         value: 0x1d, mask: 0x0
         Unknown VR
    callsite  pfe_pe_get_fw_state/79 -> pfe_pe_get_state_monitor_nolock/30 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_pe_get_fw_state/79 -> pfe_pe_lock_family/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_get_fw_state/79 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 29
         value: 0x1d, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_get_class_algo_stats_nolock/78:
    callsite  pfe_pe_get_class_algo_stats_nolock/78 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 16
         value: 0x10, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_get_classify_stats_nolock/77:
    callsite  pfe_pe_get_classify_stats_nolock/77 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 184
         value: 0xb8, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_check_stalled_nolock/76:
    callsite  pfe_pe_check_stalled_nolock/76 -> pfe_pe_get_state_monitor_nolock/30 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_pe_get_pe_stats_nolock/75:
    callsite  pfe_pe_get_pe_stats_nolock/75 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 52
         value: 0x34, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_check_mmap/74:
    callsite  pfe_pe_check_mmap/74 -> pfe_pe_get_mmap/69 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_pe_get_fw_messages_nolock/73:
  Jump functions of caller  pfe_pe_get_fw_feature_entry/72:
    callsite  pfe_pe_get_fw_feature_entry/72 -> pfe_pe_get_mmap/69 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_pe_get_fw_feature_str_base/71:
  Jump functions of caller  pfe_pe_destroy/70:
  Jump functions of caller  pfe_pe_get_mmap/69:
  Jump functions of caller  pfe_pe_load_firmware/68:
    callsite  pfe_pe_load_firmware/68 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 32
         value: 0x20, mask: 0x0
         Unknown VR
    callsite  pfe_pe_load_firmware/68 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 24
         value: 0x18, mask: 0x0
         Unknown VR
    callsite  pfe_pe_load_firmware/68 -> pfe_pe_load_firmware_aux/66 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_load_firmware/68 -> pfe_pe_fw_load_cycles.isra.0/305 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_pe_load_firmware/68 -> pfe_pe_fw_install_ops/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_pe_load_firmware/68 -> pfe_pe_lock_family/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_load_firmware/68 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 32
         value: 0x20, mask: 0x0
         Unknown VR
    callsite  pfe_pe_load_firmware/68 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 24
         value: 0x18, mask: 0x0
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _9 (_4, 1, 0, 0, _10);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _6 (_4, 0, 0, 0, _7);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_pe_copy_firmware_sections/67:
  Jump functions of caller  pfe_pe_load_firmware_aux/66:
    callsite  pfe_pe_load_firmware_aux/66 -> pfe_pe_upload_sections/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_load_firmware_aux/66 -> pfe_pe_free_mem/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_load_firmware_aux/66 -> pfe_pe_copy_firmware_sections/67 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_pe_load_firmware_aux/66 -> pfe_pe_free_mem/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_pe_mem_default_init/65:
    callsite  pfe_pe_mem_default_init/65 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 33
         value: 0x21, mask: 0x0
         Unknown VR
    callsite  pfe_pe_mem_default_init/65 -> pfe_pe_fw_load_cycles.isra.0/305 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_pe_mem_default_init/65 -> pfe_pe_fw_install_ops/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_pe_mem_default_init/65 -> pfe_pe_lock_family/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_mem_default_init/65 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 33
         value: 0x21, mask: 0x0
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _9 (_3, 1, 0, 0, _10);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _6 (_3, 0, 0, 0, _7);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_pe_set_iaccess/63:
  Jump functions of caller  pfe_pe_set_lmem/62:
  Jump functions of caller  pfe_pe_set_imem/61:
  Jump functions of caller  pfe_pe_set_dmem/60:
  Jump functions of caller  pfe_pe_create/59:
  Jump functions of caller  pfe_pe_get_elf_sect_load_addr/58:
  Jump functions of caller  pfe_pe_load_elf_section/57:
    callsite  pfe_pe_load_elf_section/57 -> pfe_pe_load_imem_section_nolock/54 : 
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
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_load_elf_section/57 -> pfe_pe_is_imem/56 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_load_elf_section/57 -> pfe_pe_load_dmem_section_nolock/53 : 
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
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_load_elf_section/57 -> pfe_pe_is_dmem/55 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_pe_is_imem/56:
  Jump functions of caller  pfe_pe_is_dmem/55:
  Jump functions of caller  pfe_pe_load_imem_section_nolock/54:
    indirect simple callsite, calling param -1, offset 0, for stmt _9 (pe_19(D), 1, _11, data_14(D), size_16(D));
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_pe_load_dmem_section_nolock/53:
    indirect simple callsite, calling param -1, offset 0, for stmt _12 (pe_19(D), 0, 0, addr_16(D), size_20(D));
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _8 (pe_19(D), 0, _10, sdata_15(D), size_20(D));
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_pe_gather_memcpy_from_dmem_to_host_32/52:
    callsite  pfe_pe_gather_memcpy_from_dmem_to_host_32/52 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 28
         value: 0x1c, mask: 0x0
         Unknown VR
    callsite  pfe_pe_gather_memcpy_from_dmem_to_host_32/52 -> pfe_pe_memlock_release_nolock/36 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_gather_memcpy_from_dmem_to_host_32/52 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_gather_memcpy_from_dmem_to_host_32/52 -> pfe_pe_memlock_acquire_nolock/35 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_gather_memcpy_from_dmem_to_host_32/52 -> pfe_pe_lock_family/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_gather_memcpy_from_dmem_to_host_32/52 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 28
         value: 0x1c, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_memcpy_from_dmem_to_host_32/51:
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 31
         value: 0x1f, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 23
         value: 0x17, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> pfe_pe_memlock_release_nolock/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
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
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> pfe_pe_memlock_acquire_nolock/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> pfe_pe_lock_family/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 31
         value: 0x1f, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_dmem_to_host_32/51 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 23
         value: 0x17, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_memcpy_from_dmem_to_host_32_nolock/50:
    callsite  pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 -> pfe_pe_mem_read/45 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [1, 3]
    callsite  pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 -> pfe_pe_mem_read/45 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 -> pfe_pe_mem_read/45 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_memcpy_from_host_to_dmem_32/49:
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 30
         value: 0x1e, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> oal_mutex_unlock.part.0/304 : 
       param 0: CONST: 22
         value: 0x16, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> pfe_pe_memlock_release_nolock/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 : 
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
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> pfe_pe_memlock_acquire_nolock/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> pfe_pe_lock_family/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 30
         value: 0x1e, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32/49 -> oal_mutex_lock.part.0/303 : 
       param 0: CONST: 22
         value: 0x16, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_memcpy_from_host_to_dmem_32_nolock/48:
    callsite  pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 -> pfe_pe_mem_write.isra.0/308 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [1, 3]
       param 5: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 -> pfe_pe_get_u32_from_byteptr/47 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
    callsite  pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 -> pfe_pe_mem_write.isra.0/308 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 5: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 -> pfe_pe_mem_write.isra.0/308 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [1, 4]
  Jump functions of caller  pfe_pe_get_u32_from_byteptr/47:
  Jump functions of caller  pfe_pe_mem_read/45:
  Jump functions of caller  pfe_pe_fw_memset_single/44:
  Jump functions of caller  pfe_pe_fw_memcpy_single/43:
  Jump functions of caller  pfe_pe_fw_memset_bulk/42:
  Jump functions of caller  pfe_pe_fw_memcpy_bulk/41:
  Jump functions of caller  pfe_pe_fw_install_ops/40:
    callsite  pfe_pe_fw_install_ops/40 -> pfe_pe_fw_ops_valid/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_pe_fw_install_ops/40 -> pfe_pe_check_pe_times.isra.0/306 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 2]
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_pe_fw_ops_valid/38:
  Jump functions of caller  pfe_pe_memlock_release_nolock/36:
    callsite  pfe_pe_memlock_release_nolock/36 -> pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_memlock_acquire_nolock/35:
    callsite  pfe_pe_memlock_acquire_nolock/35 -> pfe_pe_mem_process_lock/34 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_pe_mem_process_lock/34:
    callsite  pfe_pe_mem_process_lock/34 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  pfe_pe_mem_process_lock/34 -> pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  pfe_pe_mem_process_lock/34 -> pfe_pe_is_active_nolock/31 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_mem_process_lock/34 -> pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 255
           offset: 8, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  pfe_pe_mem_process_lock/34 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_unlock_family/33:
  Jump functions of caller  pfe_pe_lock_family/32:
  Jump functions of caller  pfe_pe_is_active_nolock/31:
    callsite  pfe_pe_is_active_nolock/31 -> pfe_pe_get_state_monitor_nolock/30 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_pe_get_state_monitor_nolock/30:
    callsite  pfe_pe_get_state_monitor_nolock/30 -> pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 8
         value: 0x8, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_pe_free_mem/29:
  Jump functions of caller  pfe_pe_upload_sections/28:
    callsite  pfe_pe_upload_sections/28 -> pfe_pe_fw_load_cycles.isra.0/305 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_pe_upload_sections/28 -> pfe_pe_free_mem/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_upload_sections/28 -> pfe_pe_load_elf_section/57 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
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
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_upload_sections/28 -> pfe_pe_free_mem/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_pe_upload_sections/28 -> pfe_pe_get_elf_sect_load_addr/58 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering pfe_pe_put_data_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_data_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_fw_state for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_class_algo_stats_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_classify_stats_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_check_stalled_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_pe_stats_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_check_mmap for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_fw_messages_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_fw_feature_entry for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_fw_feature_str_base for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_get_mmap for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_load_firmware for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_mem_default_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_set_iaccess for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_set_lmem for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_set_imem for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_set_dmem for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_gather_memcpy_from_dmem_to_host_32 for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_memcpy_from_dmem_to_host_32 for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_memcpy_from_dmem_to_host_32_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_memcpy_from_host_to_dmem_32 for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_fw_memset_single for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_fw_memcpy_single for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_fw_memset_bulk for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_fw_memcpy_bulk for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_memlock_release_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_memlock_acquire_nolock for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_unlock_family for cloning; -fipa-cp-clone disabled.
Not considering pfe_pe_lock_family for cloning; -fipa-cp-clone disabled.

overall_size: 2042, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 47, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 46, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_pe_mem_write.isra.0/308:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         pfe_pe_mem_t [0, 0]
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
               1 [loc_time: 7, loc_size: 46, prop_time: 0, prop_size: 0]
               4 [loc_time: 7, loc_size: 46, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8_t [1, 4]
        AGGS VARIABLE
    param [5]: VARIABLE
               0 [loc_time: 6, loc_size: 48, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8_t [0, 4]
        AGGS VARIABLE
  Node: pfe_pe_check_pe_times.isra.0/306:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         uint32_t [0, 2]
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
  Node: pfe_pe_fw_load_cycles.isra.0/305:
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
  Node: oal_mutex_unlock.part.0/304:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x1d, mask = 0x3f
         const oal_mutex_t [22, 33]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/303:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x1d, mask = 0x3f
         const oal_mutex_t [22, 33]
        AGGS VARIABLE
  Node: pfe_pe_put_data_nolock/81:
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
  Node: pfe_pe_get_data_nolock/80:
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
  Node: pfe_pe_get_fw_state/79:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_get_class_algo_stats_nolock/78:
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
  Node: pfe_pe_get_classify_stats_nolock/77:
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
  Node: pfe_pe_check_stalled_nolock/76:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_get_pe_stats_nolock/75:
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
  Node: pfe_pe_check_mmap/74:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_get_fw_messages_nolock/73:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_get_fw_feature_entry/72:
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
  Node: pfe_pe_get_fw_feature_str_base/71:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_destroy/70:
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
  Node: pfe_pe_get_mmap/69:
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
  Node: pfe_pe_load_firmware/68:
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
  Node: pfe_pe_copy_firmware_sections/67:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         uint32_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_pe_load_firmware_aux/66:
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
  Node: pfe_pe_mem_default_init/65:
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
  Node: pfe_pe_set_iaccess/63:
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
  Node: pfe_pe_set_lmem/62:
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
  Node: pfe_pe_set_imem/61:
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
  Node: pfe_pe_set_dmem/60:
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
  Node: pfe_pe_create/59:
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
  Node: pfe_pe_get_elf_sect_load_addr/58:
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
  Node: pfe_pe_load_elf_section/57:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_pe_t * ~[0B, 0B]
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
  Node: pfe_pe_is_imem/56:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct pfe_pe_t * ~[0B, 0B]
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
  Node: pfe_pe_is_dmem/55:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct pfe_pe_t * ~[0B, 0B]
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
  Node: pfe_pe_load_imem_section_nolock/54:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_pe_t * ~[0B, 0B]
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
  Node: pfe_pe_load_dmem_section_nolock/53:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_pe_t * ~[0B, 0B]
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
  Node: pfe_pe_gather_memcpy_from_dmem_to_host_32/52:
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
  Node: pfe_pe_memcpy_from_dmem_to_host_32/51:
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
  Node: pfe_pe_memcpy_from_dmem_to_host_32_nolock/50:
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
  Node: pfe_pe_memcpy_from_host_to_dmem_32/49:
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
  Node: pfe_pe_memcpy_from_host_to_dmem_32_nolock/48:
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
        ref offset 0: 255 [loc_time: 0, loc_size: 47, prop_time: 0, prop_size: 0]
               0 [loc_time: 0, loc_size: 47, prop_time: 0, prop_size: 0]
        ref offset 8: VARIABLE
               0 [loc_time: 0, loc_size: 47, prop_time: 0, prop_size: 0]
    param [3]: VARIABLE
               4 [loc_time: 65, loc_size: 47, prop_time: 0, prop_size: 0]
               1 [loc_time: 65, loc_size: 47, prop_time: 0, prop_size: 0]
               66 [loc_time: 65, loc_size: 47, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_pe_get_u32_from_byteptr/47:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         uint32_t [0, 3]
        AGGS VARIABLE
  Node: pfe_pe_mem_read/45:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         pfe_pe_mem_t [0, 0]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               1 [loc_time: 7, loc_size: 44, prop_time: 0, prop_size: 0]
               4 [loc_time: 6, loc_size: 44, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint8_t [1, 4]
        AGGS VARIABLE
  Node: pfe_pe_fw_memset_single/44:
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
  Node: pfe_pe_fw_memcpy_single/43:
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
  Node: pfe_pe_fw_memset_bulk/42:
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
  Node: pfe_pe_fw_memcpy_bulk/41:
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
  Node: pfe_pe_fw_install_ops/40:
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
  Node: pfe_pe_fw_ops_valid/38:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const struct pfe_pe_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_pe_memlock_release_nolock/36:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_memlock_acquire_nolock/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_mem_process_lock/34:
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
  Node: pfe_pe_unlock_family/33:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_lock_family/32:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_pe_is_active_nolock/31:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_pe_get_state_monitor_nolock/30:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_ct_pe_sw_state_monitor_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_pe_free_mem/29:
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
  Node: pfe_pe_upload_sections/28:
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

IPA decision stage:

 - Creating a specialized node of pfe_pe_mem_write.isra.0/308 for all known contexts.
    replacing param #1 ISRA.41 with const 0
 - Creating a specialized node of pfe_pe_mem_read/45 for all known contexts.
    replacing param #1 mem with const 0
Propagated bits info for function pfe_pe_mem_read.constprop/332:
 param 1: value = 0x0, mask = 0x0
 param 3: value = 0x0, mask = 0x7
Propagated bits info for function pfe_pe_mem_write.isra.0.constprop/331:
 param 1: value = 0x0, mask = 0x0
 param 4: value = 0x0, mask = 0x7
 param 5: value = 0x0, mask = 0x7
Propagated bits info for function pfe_pe_mem_write.isra.0/308:
 param 1: value = 0x0, mask = 0x0
 param 4: value = 0x0, mask = 0x7
 param 5: value = 0x0, mask = 0x7
Propagated bits info for function pfe_pe_check_pe_times.isra.0/306:
 param 1: value = 0x0, mask = 0x3
Propagated bits info for function oal_mutex_unlock.part.0/304:
 param 0: value = 0x1d, mask = 0x3f
Propagated bits info for function oal_mutex_lock.part.0/303:
 param 0: value = 0x1d, mask = 0x3f
Propagated bits info for function pfe_pe_copy_firmware_sections/67:
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_pe_get_u32_from_byteptr/47:
 param 1: value = 0x0, mask = 0x3
Propagated bits info for function pfe_pe_mem_read/45:
 param 1: value = 0x0, mask = 0x0
 param 3: value = 0x0, mask = 0x7
Propagated bits info for function pfe_pe_get_state_monitor_nolock/30:
 param 1: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: pfe_pe_mem_write.isra.0/308 pfe_pe_mem_read/45
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_pe_mem_read.constprop.0/332 (pfe_pe_mem_read.constprop) @078e8a80
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of pfe_pe_mem_read/45
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (958878293 (estimated locally),8.35 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (929350398 (estimated locally),8.09 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (37904966 (estimated locally),0.33 per call) 
  Calls: __builtin_expect/82 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/83 (107374182 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/84 (107374182 (estimated locally),0.10 per call) __builtin_expect/82 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_mem_write.isra.0.constprop.0/331 (pfe_pe_mem_write.isra.0.constprop) @078e8ee0
  Type: function definition analyzed
  Visibility: artificial
  References: 
  Referring: 
  Clone of pfe_pe_mem_write.isra.0/308
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (958878293 (estimated locally),8.35 per call) pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (929350398 (estimated locally),8.09 per call) pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (37904966 (estimated locally),0.33 per call) 
  Calls: __builtin_expect/82 (1073741824 (estimated locally),1.00 per call) __builtin_expect/82 (1073741823 (estimated locally),1.00 per call) pfe_hm_report/83 (107374182 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/84 (107374182 (estimated locally),0.10 per call) 
pfe_pe_mem_write.isra.0/308 (pfe_pe_mem_write.isra.0) @072b2700
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_check_pe_times.isra.0/306 (pfe_pe_check_pe_times.isra.0) @070939a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: fw_load_ops/26 (read)fw_load_ops/26 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_pe_fw_install_ops/40 (236258637 (estimated locally),2.00 per call) 
  Calls: 
pfe_pe_fw_load_cycles.isra.0/305 (pfe_pe_fw_load_cycles.isra.0) @07093700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_firmware/68 (1073741824 (estimated locally),9.35 per call) pfe_pe_mem_default_init/65 (1073741824 (estimated locally),9.09 per call) pfe_pe_upload_sections/28 (1073741824 (estimated locally),42.37 per call) 
  Calls: 
oal_mutex_unlock.part.0/304 (oal_mutex_unlock.part.0) @07040540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_pe_get_fw_state/79 (1073741824 (estimated locally),1.00 per call) pfe_pe_load_firmware/68 (75809931 (estimated locally),0.66 per call) pfe_pe_load_firmware/68 (39053601 (estimated locally),0.34 per call) pfe_pe_mem_default_init/65 (118111601 (estimated locally),1.00 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (118111599 (estimated locally),1.00 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (708669605 (estimated locally),0.66 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (365072220 (estimated locally),0.34 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (708669605 (estimated locally),0.66 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (365072220 (estimated locally),0.34 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/303 (oal_mutex_lock.part.0) @06df7d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_pe_get_fw_state/79 (1073741824 (estimated locally),1.00 per call) pfe_pe_load_firmware/68 (75809931 (estimated locally),0.66 per call) pfe_pe_load_firmware/68 (39053601 (estimated locally),0.34 per call) pfe_pe_mem_default_init/65 (118111600 (estimated locally),1.00 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (118111602 (estimated locally),1.00 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (708669605 (estimated locally),0.66 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (365072220 (estimated locally),0.34 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (708669605 (estimated locally),0.66 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (365072220 (estimated locally),0.34 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Dem_SetEventStatus/302 (Dem_SetEventStatus) @079bb0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_check_stalled_nolock/76 (27165668 (estimated locally),0.03 per call) pfe_pe_check_stalled_nolock/76 (89223651 (estimated locally),0.08 per call) 
  Calls: 
states.11879/301 (states) @0c83ee58
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_pe_check_stalled_nolock/76 (read)pfe_pe_check_stalled_nolock/76 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
mmap_version_str.11809/300 (mmap_version_str) @079ba3a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_pe_load_firmware_aux/66 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
autolibc_strcmp/299 (autolibc_strcmp) @07991ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_load_firmware_aux/66 (220947130 (estimated locally),0.34 per call) 
  Calls: 
ELF_SectFindName/298 (ELF_SectFindName) @07991e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_load_firmware_aux/66 (649844501 (estimated locally),1.00 per call) pfe_pe_copy_firmware_sections/67 (1073741824 (estimated locally),1.00 per call) pfe_pe_copy_firmware_sections/67 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memset/297 (autolibc_memset) @07983e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_create/59 (354334802 (estimated locally),0.33 per call) 
  Calls: 
autolibc_memcpy/296 (autolibc_memcpy) @079839a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_get_mmap/69 (731110809 (estimated locally),0.68 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (37904966 (estimated locally),0.33 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (958878293 (estimated locally),8.35 per call) pfe_pe_load_firmware_aux/66 (220947130 (estimated locally),0.34 per call) pfe_pe_load_firmware_aux/66 (220947130 (estimated locally),0.34 per call) pfe_pe_copy_firmware_sections/67 (341219046 (estimated locally),0.32 per call) pfe_pe_copy_firmware_sections/67 (182536110 (estimated locally),0.17 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/295 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @079837e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/294 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @07983700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/293 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @07983620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/292 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @07983540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/291 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @07983460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/290 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @07983380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/289 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @079832a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/288 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @079831c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/287 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @079830e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/286 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07983000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/285 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @07981ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/284 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @07981e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/283 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @07981d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/282 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @07981c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/281 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @07981b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/280 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07981a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/279 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @079819a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/278 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @079818c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/277 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @079817e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/276 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07981700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/275 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @07981620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/274 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @07981540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/273 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @07981460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/272 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @07981380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/271 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @079812a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/270 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @079811c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/269 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @079810e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/268 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07981000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/267 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @07980ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/266 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @07980e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/265 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @07980d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/264 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07980c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/263 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @07980b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/262 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07980a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/261 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @079809a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/260 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @079808c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/259 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @079807e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/258 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @07980700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/257 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @07980620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/256 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @07980540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/255 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @07980460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/254 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07980380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/253 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @079802a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/252 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @079801c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/251 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @079800e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/250 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07980000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/249 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @0797fee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/248 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @0797fe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/247 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @0797fd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/246 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @0797fc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/245 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @0797fb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/244 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @0797fa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/243 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @0797f9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/242 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @0797f8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/241 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @0797f7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/240 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @0797f700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/239 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @0797f620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/238 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @0797f540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/237 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @0797f460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/236 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @0797f380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/235 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @0797f2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/234 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @0797f1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/233 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @0797f0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/232 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @0797f000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/231 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @0797eee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/230 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @0797ee00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/229 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @0797ed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/228 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @0797ec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/227 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @0797eb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/226 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @0797ea80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/225 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @0797e9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/224 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @0797e8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/223 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @0797e7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/222 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @0797e700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/221 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @0797e620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/220 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @0797e540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/219 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @0797e460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/218 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0797e380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/217 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @0797e2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/216 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @0797e1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/215 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @0797e0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/214 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @0797e000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/213 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @0797d0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/212 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @0797dee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/211 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @0797de00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/210 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @0797dd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/209 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @0797dc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/208 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @0797db60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/207 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0797da80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/206 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0797d9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/205 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0797d8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/204 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0797d7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/203 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0797d700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/202 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0797d620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/201 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0797d540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/200 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0797d460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/199 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0797d380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/198 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0797d2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/197 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0797d1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/196 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0797d000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/195 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0797cee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/194 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0797ce00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/193 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0797cd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/192 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0797cc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/191 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0797cb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/190 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0797c9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/189 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0797c8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/188 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0797c7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/187 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @0797c700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/186 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @0797c620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/185 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @0797c540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/184 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @0797c460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/183 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @0797c380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/182 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @0797c2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/181 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @0797c1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/180 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @0797c0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/179 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @0797c000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/178 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @0797aee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/177 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @0797ae00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/176 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @0797ad20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/175 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @0797ac40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/174 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @0797ab60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/173 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @0797aa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/172 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @0797a9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/171 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @0797a8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/170 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @0797a7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/169 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @0797a700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/168 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @0797a620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/167 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @0797a540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/166 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @0797a460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/165 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @0797a380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/164 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @0797a2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/163 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @0797a1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/162 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @0797a0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/161 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @0797a000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/160 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @07978ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/159 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07978e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/158 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @07978d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/157 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07978c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/156 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07978b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/155 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07978a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/154 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @079789a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/153 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @079788c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/152 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @079787e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/151 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @07978700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/150 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @07978620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/149 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07978540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/148 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07978460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/147 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07978380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/146 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @079782a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/145 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @079781c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/144 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @079780e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/143 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @07978000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/142 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @07976ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/141 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @07976e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/140 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @07976d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/139 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07976c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/138 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07976b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/137 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07976a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/136 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @079769a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/135 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @079768c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/134 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @079767e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/133 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @07976700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/132 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @07976620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/131 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @07976540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/130 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @07976460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/129 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07976380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/128 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @079762a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/127 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @079761c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/126 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @079760e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/125 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @07976000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/124 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @07975ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/123 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @07975e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/122 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @07975d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/121 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @07975c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/120 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07975b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/119 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07975a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/118 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @079759a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/117 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @079758c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/116 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @079757e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/115 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @07975700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/114 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @07975620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/113 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @07975540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/112 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @07975460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/111 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07975380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/110 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @079752a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/109 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @079751c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/108 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @079750e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/107 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @07975000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/106 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @079742a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/105 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @07974ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/104 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @07974e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/103 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @07974d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/102 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @07974c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/101 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @07974b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/100 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @07974a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/99 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @079749a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/98 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @079748c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/97 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @079747e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/96 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @07974700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/95 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @07974620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/94 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @07974540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/93 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @07974460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/92 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @07974380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/91 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @079741c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/90 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @079740e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/89 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @07974000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/88 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0795bee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/87 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0795be00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/86 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0795bd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
oal_time_usleep/85 (oal_time_usleep) @0795b540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_mem_process_lock/34 (976138694 (estimated locally),1.06 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/84 (oal_util_raise_dem_for_drv_runtime_err) @0795b1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_mem_read.constprop/332 (107374182 (estimated locally),0.10 per call) pfe_pe_mem_write.isra.0.constprop/331 (107374182 (estimated locally),0.10 per call) pfe_pe_put_data_nolock/81 (225056286 (estimated locally),0.21 per call) pfe_pe_get_data_nolock/80 (225056286 (estimated locally),0.21 per call) pfe_pe_check_mmap/74 (225056286 (estimated locally),0.21 per call) pfe_pe_get_fw_feature_entry/72 (29253104 (estimated locally),0.03 per call) pfe_pe_get_fw_feature_entry/72 (37010506 (estimated locally),0.03 per call) pfe_pe_load_firmware/68 (37904966 (estimated locally),0.33 per call) pfe_pe_mem_default_init/65 (38976828 (estimated locally),0.33 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (315357970 (estimated locally),2.67 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (315357973 (estimated locally),2.67 per call) pfe_pe_mem_process_lock/34 (97603132 (estimated locally),0.11 per call) pfe_pe_mem_process_lock/34 (307166089 (estimated locally),0.33 per call) pfe_pe_mem_process_lock/34 (307166089 (estimated locally),0.33 per call) pfe_pe_lock_family/32 (107374182 (estimated locally),0.10 per call) pfe_pe_copy_firmware_sections/67 (183733332 (estimated locally),0.17 per call) pfe_pe_copy_firmware_sections/67 (182536110 (estimated locally),0.17 per call) pfe_pe_upload_sections/28 (55807731 (estimated locally),2.20 per call) pfe_pe_load_elf_section/57 (251792458 (estimated locally),0.23 per call) pfe_pe_load_imem_section_nolock/54 (147583831 (estimated locally),0.14 per call) pfe_pe_load_imem_section_nolock/54 (117421551 (estimated locally),0.11 per call) pfe_pe_load_imem_section_nolock/54 (148559655 (estimated locally),0.14 per call) pfe_pe_load_imem_section_nolock/54 (364964846 (estimated locally),0.34 per call) pfe_pe_load_dmem_section_nolock/53 (167700262 (estimated locally),0.16 per call) pfe_pe_load_dmem_section_nolock/53 (177884489 (estimated locally),0.17 per call) pfe_pe_load_dmem_section_nolock/53 (225056286 (estimated locally),0.21 per call) pfe_pe_get_elf_sect_load_addr/58 (59055800 (estimated locally),0.68 per call) pfe_pe_fw_memset_bulk/42 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_memcpy_bulk/41 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_memset_single/44 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_memcpy_single/43 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_install_ops/40 (19938832 (estimated locally),0.17 per call) 
  Calls: 
pfe_hm_report/83 (pfe_hm_report) @0795b0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_mem_read.constprop/332 (107374182 (estimated locally),0.10 per call) pfe_pe_mem_write.isra.0.constprop/331 (107374182 (estimated locally),0.10 per call) pfe_pe_put_data_nolock/81 (225056286 (estimated locally),0.21 per call) pfe_pe_get_data_nolock/80 (225056286 (estimated locally),0.21 per call) pfe_pe_check_stalled_nolock/76 (27165668 (estimated locally),0.03 per call) pfe_pe_check_stalled_nolock/76 (89223651 (estimated locally),0.08 per call) pfe_pe_check_mmap/74 (225056286 (estimated locally),0.21 per call) pfe_pe_get_fw_feature_entry/72 (29253104 (estimated locally),0.03 per call) pfe_pe_get_fw_feature_entry/72 (37010506 (estimated locally),0.03 per call) pfe_pe_load_firmware/68 (37904966 (estimated locally),0.33 per call) pfe_pe_mem_default_init/65 (38976828 (estimated locally),0.33 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (315357970 (estimated locally),2.67 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (315357973 (estimated locally),2.67 per call) pfe_pe_mem_process_lock/34 (97603132 (estimated locally),0.11 per call) pfe_pe_mem_process_lock/34 (307166089 (estimated locally),0.33 per call) pfe_pe_mem_process_lock/34 (307166089 (estimated locally),0.33 per call) pfe_pe_lock_family/32 (107374182 (estimated locally),0.10 per call) pfe_pe_copy_firmware_sections/67 (183733332 (estimated locally),0.17 per call) pfe_pe_copy_firmware_sections/67 (182536110 (estimated locally),0.17 per call) pfe_pe_upload_sections/28 (55807731 (estimated locally),2.20 per call) pfe_pe_load_elf_section/57 (251792458 (estimated locally),0.23 per call) pfe_pe_load_imem_section_nolock/54 (147583831 (estimated locally),0.14 per call) pfe_pe_load_imem_section_nolock/54 (117421551 (estimated locally),0.11 per call) pfe_pe_load_imem_section_nolock/54 (148559655 (estimated locally),0.14 per call) pfe_pe_load_imem_section_nolock/54 (364964846 (estimated locally),0.34 per call) pfe_pe_load_dmem_section_nolock/53 (167700262 (estimated locally),0.16 per call) pfe_pe_load_dmem_section_nolock/53 (177884489 (estimated locally),0.17 per call) pfe_pe_load_dmem_section_nolock/53 (225056286 (estimated locally),0.21 per call) pfe_pe_get_elf_sect_load_addr/58 (59055800 (estimated locally),0.68 per call) pfe_pe_fw_memset_bulk/42 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_memcpy_bulk/41 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_memset_single/44 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_memcpy_single/43 (11811160 (estimated locally),0.10 per call) pfe_pe_fw_install_ops/40 (19938832 (estimated locally),0.17 per call) 
  Calls: 
__builtin_expect/82 (__builtin_expect) @0795b000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_pe_mem_read.constprop/332 (1073741824 (estimated locally),1.00 per call) pfe_pe_mem_read.constprop/332 (1073741824 (estimated locally),1.00 per call) pfe_pe_mem_write.isra.0.constprop/331 (1073741824 (estimated locally),1.00 per call) pfe_pe_mem_write.isra.0.constprop/331 (1073741823 (estimated locally),1.00 per call) pfe_pe_lock_family/32 (1073741824 (estimated locally),1.00 per call) pfe_pe_fw_memset_bulk/42 (118111600 (estimated locally),1.00 per call) pfe_pe_fw_memcpy_bulk/41 (118111600 (estimated locally),1.00 per call) pfe_pe_fw_memset_single/44 (118111600 (estimated locally),1.00 per call) pfe_pe_fw_memcpy_single/43 (118111600 (estimated locally),1.00 per call) 
  Calls: 
pfe_pe_put_data_nolock/81 (pfe_pe_put_data_nolock) @07950ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (193667740 (estimated locally),0.18 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (405417081 (estimated locally),0.38 per call) oal_util_raise_dem_for_drv_runtime_err/84 (225056286 (estimated locally),0.21 per call) pfe_hm_report/83 (225056286 (estimated locally),0.21 per call) pfe_pe_get_mmap/69 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_get_data_nolock/80 (pfe_pe_get_data_nolock) @07950a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (193667740 (estimated locally),0.18 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (193667740 (estimated locally),0.18 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (405417081 (estimated locally),0.38 per call) oal_util_raise_dem_for_drv_runtime_err/84 (225056286 (estimated locally),0.21 per call) pfe_hm_report/83 (225056286 (estimated locally),0.21 per call) pfe_pe_get_mmap/69 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_get_fw_state/79 (pfe_pe_get_fw_state) @07950540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/304 (1073741824 (estimated locally),1.00 per call) pfe_pe_get_state_monitor_nolock/30 (1073741824 (estimated locally),1.00 per call) pfe_pe_lock_family/32 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/303 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_get_class_algo_stats_nolock/78 (pfe_pe_get_class_algo_stats_nolock) @079502a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_get_classify_stats_nolock/77 (pfe_pe_get_classify_stats_nolock) @07950000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_check_stalled_nolock/76 (pfe_pe_check_stalled_nolock) @07943b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: hm_types/27 (read)states.11879/301 (read)hm_types/27 (read)states.11879/301 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Dem_SetEventStatus/302 (27165668 (estimated locally),0.03 per call) pfe_hm_report/83 (27165668 (estimated locally),0.03 per call) Dem_SetEventStatus/302 (89223651 (estimated locally),0.08 per call) pfe_hm_report/83 (89223651 (estimated locally),0.08 per call) pfe_pe_get_state_monitor_nolock/30 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_get_pe_stats_nolock/75 (pfe_pe_get_pe_stats_nolock) @07943d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_check_mmap/74 (pfe_pe_check_mmap) @07943a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (225056286 (estimated locally),0.21 per call) pfe_hm_report/83 (225056286 (estimated locally),0.21 per call) pfe_pe_get_mmap/69 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_get_fw_messages_nolock/73 (pfe_pe_get_fw_messages_nolock) @07943700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_get_fw_feature_entry/72 (pfe_pe_get_fw_feature_entry) @07943460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (29253104 (estimated locally),0.03 per call) pfe_hm_report/83 (29253104 (estimated locally),0.03 per call) oal_util_raise_dem_for_drv_runtime_err/84 (37010506 (estimated locally),0.03 per call) pfe_hm_report/83 (37010506 (estimated locally),0.03 per call) pfe_pe_get_mmap/69 (176576843 (estimated locally),0.16 per call) 
pfe_pe_get_fw_feature_str_base/71 (pfe_pe_get_fw_feature_str_base) @07943000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_destroy/70 (pfe_pe_destroy) @07910a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:337461715 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_get_mmap/69 (pfe_pe_get_mmap) @07910000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_pe_put_data_nolock/81 (1073741824 (estimated locally),1.00 per call) pfe_pe_get_data_nolock/80 (1073741824 (estimated locally),1.00 per call) pfe_pe_check_mmap/74 (1073741824 (estimated locally),1.00 per call) pfe_pe_get_fw_feature_entry/72 (176576843 (estimated locally),0.16 per call) 
  Calls: autolibc_memcpy/296 (731110809 (estimated locally),0.68 per call) 
pfe_pe_load_firmware/68 (pfe_pe_load_firmware) @07910d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/304 (75809931 (estimated locally),0.66 per call) oal_mutex_unlock.part.0/304 (39053601 (estimated locally),0.34 per call) pfe_pe_load_firmware_aux/66 (23248379 (estimated locally),0.20 per call) pfe_pe_fw_load_cycles.isra.0/305 (1073741824 (estimated locally),9.35 per call) oal_util_raise_dem_for_drv_runtime_err/84 (37904966 (estimated locally),0.33 per call) pfe_hm_report/83 (37904966 (estimated locally),0.33 per call) pfe_pe_fw_install_ops/40 (114863532 (estimated locally),1.00 per call) pfe_pe_lock_family/32 (114863532 (estimated locally),1.00 per call) oal_mutex_lock.part.0/303 (75809931 (estimated locally),0.66 per call) oal_mutex_lock.part.0/303 (39053601 (estimated locally),0.34 per call) 
   Indirect call(958878293 (estimated locally),8.35 per call) 
   Indirect call(958878293 (estimated locally),8.35 per call) 
pfe_pe_copy_firmware_sections/67 (pfe_pe_copy_firmware_sections) @079109a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tmp_messages/25 (addr)tmp_features/24 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_firmware_aux/66 (603533983 (estimated locally),0.93 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (183733332 (estimated locally),0.17 per call) pfe_hm_report/83 (183733332 (estimated locally),0.17 per call) autolibc_memcpy/296 (341219046 (estimated locally),0.32 per call) ELF_SectFindName/298 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/84 (182536110 (estimated locally),0.17 per call) pfe_hm_report/83 (182536110 (estimated locally),0.17 per call) autolibc_memcpy/296 (182536110 (estimated locally),0.17 per call) ELF_SectFindName/298 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_load_firmware_aux/66 (pfe_pe_load_firmware_aux) @079101c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tmp_mmap/23 (addr)mmap_version_str.11809/300 (addr)tmp_mmap/23 (addr)tmp_mmap/23 (addr)tmp_messages/25 (addr)tmp_features/24 (addr)
  Referring: 
  Availability: local
  Function flags: count:649844501 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_firmware/68 (23248379 (estimated locally),0.20 per call) 
  Calls: pfe_pe_upload_sections/28 (236223200 (estimated locally),0.36 per call) pfe_pe_free_mem/29 (65543790 (estimated locally),0.10 per call) pfe_pe_copy_firmware_sections/67 (603533983 (estimated locally),0.93 per call) pfe_pe_free_mem/29 (46310518 (estimated locally),0.07 per call) autolibc_strcmp/299 (220947130 (estimated locally),0.34 per call) autolibc_memcpy/296 (220947130 (estimated locally),0.34 per call) autolibc_memcpy/296 (220947130 (estimated locally),0.34 per call) ELF_SectFindName/298 (649844501 (estimated locally),1.00 per call) 
pfe_pe_mem_default_init/65 (pfe_pe_mem_default_init) @07907a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/304 (118111601 (estimated locally),1.00 per call) pfe_pe_fw_load_cycles.isra.0/305 (1073741824 (estimated locally),9.09 per call) oal_util_raise_dem_for_drv_runtime_err/84 (38976828 (estimated locally),0.33 per call) pfe_hm_report/83 (38976828 (estimated locally),0.33 per call) pfe_pe_fw_install_ops/40 (118111600 (estimated locally),1.00 per call) pfe_pe_lock_family/32 (118111600 (estimated locally),1.00 per call) oal_mutex_lock.part.0/303 (118111600 (estimated locally),1.00 per call) 
   Indirect call(955630223 (estimated locally),8.09 per call) 
   Indirect call(955630223 (estimated locally),8.09 per call) 
pfe_pe_set_iaccess/63 (pfe_pe_set_iaccess) @07907ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_set_lmem/62 (pfe_pe_set_lmem) @079079a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_set_imem/61 (pfe_pe_set_imem) @07907700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_set_dmem/60 (pfe_pe_set_dmem) @07907460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_create/59 (pfe_pe_create) @079071c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memset/297 (354334802 (estimated locally),0.33 per call) 
pfe_pe_get_elf_sect_load_addr/58 (pfe_pe_get_elf_sect_load_addr) @078fae00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:86959666 (estimated locally) body local optimize_size
  Called by: pfe_pe_upload_sections/28 (119227249 (estimated locally),4.70 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (59055800 (estimated locally),0.68 per call) pfe_hm_report/83 (59055800 (estimated locally),0.68 per call) 
pfe_pe_load_elf_section/57 (pfe_pe_load_elf_section) @078fad20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_upload_sections/28 (1014686024 (estimated locally),40.04 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (251792458 (estimated locally),0.23 per call) pfe_hm_report/83 (251792458 (estimated locally),0.23 per call) pfe_pe_load_imem_section_nolock/54 (467614564 (estimated locally),0.44 per call) pfe_pe_is_imem/56 (719407023 (estimated locally),0.67 per call) pfe_pe_load_dmem_section_nolock/53 (354334802 (estimated locally),0.33 per call) pfe_pe_is_dmem/55 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_is_imem/56 (pfe_pe_is_imem) @078fa8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_elf_section/57 (719407023 (estimated locally),0.67 per call) 
  Calls: 
pfe_pe_is_dmem/55 (pfe_pe_is_dmem) @078fa460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_elf_section/57 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_pe_load_imem_section_nolock/54 (pfe_pe_load_imem_section_nolock) @078fa000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_elf_section/57 (467614564 (estimated locally),0.44 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (147583831 (estimated locally),0.14 per call) pfe_hm_report/83 (147583831 (estimated locally),0.14 per call) oal_util_raise_dem_for_drv_runtime_err/84 (117421551 (estimated locally),0.11 per call) pfe_hm_report/83 (117421551 (estimated locally),0.11 per call) oal_util_raise_dem_for_drv_runtime_err/84 (148559655 (estimated locally),0.14 per call) pfe_hm_report/83 (148559655 (estimated locally),0.14 per call) oal_util_raise_dem_for_drv_runtime_err/84 (364964846 (estimated locally),0.34 per call) pfe_hm_report/83 (364964846 (estimated locally),0.34 per call) 
   Indirect call(147583831 (estimated locally),0.14 per call) 
pfe_pe_load_dmem_section_nolock/53 (pfe_pe_load_dmem_section_nolock) @078ee8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_elf_section/57 (354334802 (estimated locally),0.33 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (167700262 (estimated locally),0.16 per call) pfe_hm_report/83 (167700262 (estimated locally),0.16 per call) oal_util_raise_dem_for_drv_runtime_err/84 (177884489 (estimated locally),0.17 per call) pfe_hm_report/83 (177884489 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/84 (225056286 (estimated locally),0.21 per call) pfe_hm_report/83 (225056286 (estimated locally),0.21 per call) 
   Indirect call(167700262 (estimated locally),0.16 per call) 
   Indirect call(167700262 (estimated locally),0.16 per call) 
pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (pfe_pe_gather_memcpy_from_dmem_to_host_32) @078ee1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111602 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/304 (118111599 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/84 (315357970 (estimated locally),2.67 per call) pfe_hm_report/83 (315357970 (estimated locally),2.67 per call) pfe_pe_memlock_release_nolock/36 (955630213 (estimated locally),8.09 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (492996551 (estimated locally),4.17 per call) oal_util_raise_dem_for_drv_runtime_err/84 (315357973 (estimated locally),2.67 per call) pfe_hm_report/83 (315357973 (estimated locally),2.67 per call) pfe_pe_memlock_acquire_nolock/35 (955630223 (estimated locally),8.09 per call) pfe_pe_lock_family/32 (118111602 (estimated locally),1.00 per call) oal_mutex_lock.part.0/303 (118111602 (estimated locally),1.00 per call) 
pfe_pe_memcpy_from_dmem_to_host_32/51 (pfe_pe_memcpy_from_dmem_to_host_32) @078c47e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/304 (708669605 (estimated locally),0.66 per call) oal_mutex_unlock.part.0/304 (365072220 (estimated locally),0.34 per call) pfe_pe_memlock_release_nolock/36 (354334802 (estimated locally),0.33 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (354334802 (estimated locally),0.33 per call) pfe_pe_memlock_acquire_nolock/35 (1073741824 (estimated locally),1.00 per call) pfe_pe_lock_family/32 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/303 (708669605 (estimated locally),0.66 per call) oal_mutex_lock.part.0/303 (365072220 (estimated locally),0.34 per call) 
pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (pfe_pe_memcpy_from_dmem_to_host_32_nolock) @078c4ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: pfe_pe_put_data_nolock/81 (405417081 (estimated locally),0.38 per call) pfe_pe_get_data_nolock/80 (193667740 (estimated locally),0.18 per call) pfe_pe_get_data_nolock/80 (405417081 (estimated locally),0.38 per call) pfe_pe_get_class_algo_stats_nolock/78 (1073741824 (estimated locally),1.00 per call) pfe_pe_get_classify_stats_nolock/77 (1073741824 (estimated locally),1.00 per call) pfe_pe_get_pe_stats_nolock/75 (1073741824 (estimated locally),1.00 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (492996551 (estimated locally),4.17 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (354334802 (estimated locally),0.33 per call) pfe_pe_mem_process_lock/34 (976138694 (estimated locally),1.06 per call) pfe_pe_mem_process_lock/34 (916913698 (estimated locally),1.00 per call) pfe_pe_get_state_monitor_nolock/30 (731110809 (estimated locally),0.68 per call) 
  Calls: autolibc_memcpy/296 (37904966 (estimated locally),0.33 per call) pfe_pe_mem_read.constprop/332 (37904966 (estimated locally),0.33 per call) pfe_pe_mem_read.constprop/332 (929350398 (estimated locally),8.09 per call) autolibc_memcpy/296 (958878293 (estimated locally),8.35 per call) pfe_pe_mem_read.constprop/332 (958878293 (estimated locally),8.35 per call) 
pfe_pe_memcpy_from_host_to_dmem_32/49 (pfe_pe_memcpy_from_host_to_dmem_32) @078c4c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/304 (708669605 (estimated locally),0.66 per call) oal_mutex_unlock.part.0/304 (365072220 (estimated locally),0.34 per call) pfe_pe_memlock_release_nolock/36 (354334802 (estimated locally),0.33 per call) pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (354334802 (estimated locally),0.33 per call) pfe_pe_memlock_acquire_nolock/35 (1073741824 (estimated locally),1.00 per call) pfe_pe_lock_family/32 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/303 (708669605 (estimated locally),0.66 per call) oal_mutex_lock.part.0/303 (365072220 (estimated locally),0.34 per call) 
pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (pfe_pe_memcpy_from_host_to_dmem_32_nolock) @078c49a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: pfe_pe_put_data_nolock/81 (193667740 (estimated locally),0.18 per call) pfe_pe_get_data_nolock/80 (193667740 (estimated locally),0.18 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (354334802 (estimated locally),0.33 per call) pfe_pe_mem_process_lock/34 (97603132 (estimated locally),0.11 per call) pfe_pe_mem_process_lock/34 (302581520 (estimated locally),0.33 per call) pfe_pe_memlock_release_nolock/36 (416752756 (estimated locally),0.39 per call) 
  Calls: pfe_pe_mem_write.isra.0.constprop/331 (37904966 (estimated locally),0.33 per call) pfe_pe_get_u32_from_byteptr/47 (37904966 (estimated locally),0.33 per call) pfe_pe_mem_write.isra.0.constprop/331 (929350398 (estimated locally),8.09 per call) pfe_pe_mem_write.isra.0.constprop/331 (958878293 (estimated locally),8.35 per call) 
pfe_pe_get_u32_from_byteptr/47 (pfe_pe_get_u32_from_byteptr) @078c4700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (37904966 (estimated locally),0.33 per call) 
  Calls: 
pfe_pe_mem_read/45 (pfe_pe_mem_read) @078b92a0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_fw_memset_single/44 (pfe_pe_fw_memset_single) @078b98c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: fw_load_ops/26 (addr)
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (11811160 (estimated locally),0.10 per call) pfe_hm_report/83 (11811160 (estimated locally),0.10 per call) __builtin_expect/82 (118111600 (estimated locally),1.00 per call) 
pfe_pe_fw_memcpy_single/43 (pfe_pe_fw_memcpy_single) @078b91c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: fw_load_ops/26 (addr)
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (11811160 (estimated locally),0.10 per call) pfe_hm_report/83 (11811160 (estimated locally),0.10 per call) __builtin_expect/82 (118111600 (estimated locally),1.00 per call) 
pfe_pe_fw_memset_bulk/42 (pfe_pe_fw_memset_bulk) @078aad20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: fw_load_ops/26 (addr)
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (11811160 (estimated locally),0.10 per call) pfe_hm_report/83 (11811160 (estimated locally),0.10 per call) __builtin_expect/82 (118111600 (estimated locally),1.00 per call) 
pfe_pe_fw_memcpy_bulk/41 (pfe_pe_fw_memcpy_bulk) @078aa700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: fw_load_ops/26 (addr)
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (11811160 (estimated locally),0.10 per call) pfe_hm_report/83 (11811160 (estimated locally),0.10 per call) __builtin_expect/82 (118111600 (estimated locally),1.00 per call) 
pfe_pe_fw_install_ops/40 (pfe_pe_fw_install_ops) @078aa0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: fw_load_ops/26 (read)fw_load_ops/26 (addr)fw_load_ops/26 (addr)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_firmware/68 (114863532 (estimated locally),1.00 per call) pfe_pe_mem_default_init/65 (118111600 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (19938832 (estimated locally),0.17 per call) pfe_hm_report/83 (19938832 (estimated locally),0.17 per call) pfe_pe_fw_ops_valid/38 (362524218 (estimated locally),3.07 per call) pfe_pe_check_pe_times.isra.0/306 (236258637 (estimated locally),2.00 per call) 
pfe_pe_fw_ops_valid/38 (pfe_pe_fw_ops_valid) @078e82a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_fw_install_ops/40 (362524218 (estimated locally),3.07 per call) 
  Calls: 
pfe_pe_memlock_release_nolock/36 (pfe_pe_memlock_release_nolock) @078e8c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (955630213 (estimated locally),8.09 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (354334802 (estimated locally),0.33 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (354334802 (estimated locally),0.33 per call) 
  Calls: pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (416752756 (estimated locally),0.39 per call) 
pfe_pe_memlock_acquire_nolock/35 (pfe_pe_memlock_acquire_nolock) @078e89a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (955630223 (estimated locally),8.09 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (1073741824 (estimated locally),1.00 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_pe_mem_process_lock/34 (416752756 (estimated locally),0.39 per call) 
pfe_pe_mem_process_lock/34 (pfe_pe_mem_process_lock) @078e8700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:916913698 (estimated locally) body local optimize_size
  Called by: pfe_pe_memlock_acquire_nolock/35 (416752756 (estimated locally),0.39 per call) 
  Calls: pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (976138694 (estimated locally),1.06 per call) oal_time_usleep/85 (976138694 (estimated locally),1.06 per call) pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (97603132 (estimated locally),0.11 per call) oal_util_raise_dem_for_drv_runtime_err/84 (97603132 (estimated locally),0.11 per call) pfe_hm_report/83 (97603132 (estimated locally),0.11 per call) pfe_pe_is_active_nolock/31 (302581520 (estimated locally),0.33 per call) pfe_pe_memcpy_from_host_to_dmem_32_nolock/48 (302581520 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/84 (307166089 (estimated locally),0.33 per call) pfe_hm_report/83 (307166089 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/84 (307166089 (estimated locally),0.33 per call) pfe_hm_report/83 (307166089 (estimated locally),0.33 per call) pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (916913698 (estimated locally),1.00 per call) 
pfe_pe_unlock_family/33 (pfe_pe_unlock_family) @078e81c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_pe_lock_family/32 (pfe_pe_lock_family) @077bdd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_pe_get_fw_state/79 (1073741824 (estimated locally),1.00 per call) pfe_pe_load_firmware/68 (114863532 (estimated locally),1.00 per call) pfe_pe_mem_default_init/65 (118111600 (estimated locally),1.00 per call) pfe_pe_gather_memcpy_from_dmem_to_host_32/52 (118111602 (estimated locally),1.00 per call) pfe_pe_memcpy_from_dmem_to_host_32/51 (1073741824 (estimated locally),1.00 per call) pfe_pe_memcpy_from_host_to_dmem_32/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/84 (107374182 (estimated locally),0.10 per call) pfe_hm_report/83 (107374182 (estimated locally),0.10 per call) __builtin_expect/82 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_is_active_nolock/31 (pfe_pe_is_active_nolock) @077bdee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_mem_process_lock/34 (302581520 (estimated locally),0.33 per call) 
  Calls: pfe_pe_get_state_monitor_nolock/30 (1073741824 (estimated locally),1.00 per call) 
pfe_pe_get_state_monitor_nolock/30 (pfe_pe_get_state_monitor_nolock) @077bdc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_pe_get_fw_state/79 (1073741824 (estimated locally),1.00 per call) pfe_pe_check_stalled_nolock/76 (1073741824 (estimated locally),1.00 per call) pfe_pe_is_active_nolock/31 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_pe_memcpy_from_dmem_to_host_32_nolock/50 (731110809 (estimated locally),0.68 per call) 
pfe_pe_free_mem/29 (pfe_pe_free_mem) @077bd9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_firmware_aux/66 (65543790 (estimated locally),0.10 per call) pfe_pe_load_firmware_aux/66 (46310518 (estimated locally),0.07 per call) pfe_pe_upload_sections/28 (55807731 (estimated locally),2.20 per call) pfe_pe_upload_sections/28 (4363717 (estimated locally),0.17 per call) 
  Calls: 
pfe_pe_upload_sections/28 (pfe_pe_upload_sections) @077bd700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:25343637 (estimated locally) body local optimize_size
  Called by: pfe_pe_load_firmware_aux/66 (236223200 (estimated locally),0.36 per call) 
  Calls: pfe_pe_fw_load_cycles.isra.0/305 (1073741824 (estimated locally),42.37 per call) pfe_pe_free_mem/29 (55807731 (estimated locally),2.20 per call) oal_util_raise_dem_for_drv_runtime_err/84 (55807731 (estimated locally),2.20 per call) pfe_hm_report/83 (55807731 (estimated locally),2.20 per call) pfe_pe_load_elf_section/57 (1014686024 (estimated locally),40.04 per call) pfe_pe_free_mem/29 (4363717 (estimated locally),0.17 per call) pfe_pe_get_elf_sect_load_addr/58 (119227249 (estimated locally),4.70 per call) 
hm_types/27 (hm_types) @077b3ea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_pe_check_stalled_nolock/76 (read)pfe_pe_check_stalled_nolock/76 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
fw_load_ops/26 (fw_load_ops) @077b3e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_pe_fw_memset_bulk/42 (addr)pfe_pe_fw_memcpy_bulk/41 (addr)pfe_pe_fw_memset_single/44 (addr)pfe_pe_fw_memcpy_single/43 (addr)
  Referring: pfe_pe_check_pe_times.isra.0/306 (read)pfe_pe_fw_install_ops/40 (addr)pfe_pe_fw_install_ops/40 (addr)pfe_pe_check_pe_times.isra.0/306 (read)pfe_pe_fw_install_ops/40 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
tmp_messages/25 (tmp_messages) @077b31f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_pe_copy_firmware_sections/67 (addr)pfe_pe_load_firmware_aux/66 (addr)
  Availability: available
  Varpool flags:
tmp_features/24 (tmp_features) @077b3168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_pe_copy_firmware_sections/67 (addr)pfe_pe_load_firmware_aux/66 (addr)
  Availability: available
  Varpool flags:
tmp_mmap/23 (tmp_mmap) @077b30d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_pe_load_firmware_aux/66 (addr)pfe_pe_load_firmware_aux/66 (addr)pfe_pe_load_firmware_aux/66 (addr)
  Availability: available
  Varpool flags:
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/2 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f94ca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/191 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/192 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/193 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/194 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/195 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/196 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/197 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/198 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/199 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/200 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/201 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/202 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/203 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/204 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/205 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/206 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/207 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/208 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/209 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/210 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/211 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/212 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/213 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/214 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/215 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/216 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/217 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/218 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/219 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/220 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/221 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/222 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/223 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/224 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/225 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/226 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/227 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/228 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/229 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/230 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/231 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/232 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/233 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/234 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/235 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/236 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/237 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/238 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/239 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/240 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/241 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/242 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/243 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/244 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/245 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/246 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/247 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/248 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/249 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/250 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/251 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/252 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/253 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/254 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/255 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/256 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/257 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/258 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/259 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/260 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/261 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/262 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/263 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/264 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/265 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/266 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/267 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/268 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/269 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/270 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/271 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/272 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/273 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/274 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/275 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/276 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/277 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/278 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/279 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/280 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/281 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/282 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/283 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/284 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/285 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/286 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/287 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/288 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/289 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/290 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/291 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/292 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/293 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/294 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/295 (addr)
  Referring: oal_mutex_unlock.part.0/304 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/1 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @06f94bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/86 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/87 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/88 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/89 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/90 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/91 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/92 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/93 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/94 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/95 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/96 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/97 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/98 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/99 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/100 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/101 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/102 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/103 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/104 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/105 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/106 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/107 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/108 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/109 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/110 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/111 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/112 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/113 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/114 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/115 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/116 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/117 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/118 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/119 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/120 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/121 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/122 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/123 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/124 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/125 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/126 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/127 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/128 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/129 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/130 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/131 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/132 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/133 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/134 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/135 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/136 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/137 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/138 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/139 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/140 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/141 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/142 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/143 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/144 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/145 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/146 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/147 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/148 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/149 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/150 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/151 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/152 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/153 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/154 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/155 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/156 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/157 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/158 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/159 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/160 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/161 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/162 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/163 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/164 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/165 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/166 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/167 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/168 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/169 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/170 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/171 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/172 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/173 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/174 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/175 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/176 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/177 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/178 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/179 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/180 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/181 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/182 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/183 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/184 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/185 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/186 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/187 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/188 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/189 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/190 (addr)
  Referring: oal_mutex_lock.part.0/303 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function pfe_pe_free_mem (pfe_pe_free_mem, funcdef_no=21, decl_uid=11361, cgraph_uid=22, symbol_order=29)

Modification phase of node pfe_pe_free_mem/29
pfe_pe_free_mem (struct pfe_pe_t * pe, uint32_t pe_num)
{
  uint32_t ii;
  long unsigned int _1;
  struct pfe_pe_t * _2;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = ii_3 * 112;
  _2 = pe_7(D) + _1;
  _2->mmap_data = 0B;
  # DEBUG BEGIN_STMT
  _2->fw_msg_section = 0B;
  # DEBUG BEGIN_STMT
  _2->fw_msg_section_size = 0;
  # DEBUG BEGIN_STMT
  _2->fw_feature_section = 0B;
  # DEBUG BEGIN_STMT
  _2->fw_feature_section_size = 0;
  # DEBUG BEGIN_STMT
  ii_13 = ii_3 + 1;
  # DEBUG ii => ii_13

  <bb 4> [local count: 1073741824]:
  # ii_3 = PHI <0(2), ii_13(3)>
  # DEBUG ii => ii_3
  # DEBUG BEGIN_STMT
  if (ii_3 < pe_num_6(D))
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  return;

}



;; Function pfe_pe_fw_memcpy_single (pfe_pe_fw_memcpy_single, funcdef_no=35, decl_uid=11352, cgraph_uid=36, symbol_order=43)

Modification phase of node pfe_pe_fw_memcpy_single/43
pfe_pe_fw_memcpy_single (struct pfe_pe_t * pe, pfe_pe_mem_t mem, addr_t dst_addr, const void * src_ptr, uint32_t len)
{
  const addr_t mem_addr;
  uint32_t mem_offs;
  uint32_t memsel;
  uint32_t addr_temp;
  bool_t * _1;
  unsigned char _2;
  _Bool _3;
  long int _4;
  long int _5;
  unsigned char _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  uint32_t * _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  unsigned int _21;
  volatile uint32_t * _22;
  long unsigned int _23;
  unsigned int _24;
  volatile uint32_t * _25;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG data => src_ptr_31(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_32(D) == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG memsel => 131072

  <bb 4> [local count: 118111600]:
  # memsel_27 = PHI <262144(2), 131072(3)>
  # DEBUG memsel => memsel_27
  # DEBUG BEGIN_STMT
  _1 = pe_34(D)->miflock;
  _2 = *_1;
  _3 = _2 == 0;
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 0);
  if (_5 != 0)
    goto <bb 5>; [10.00%]
  else
    goto <bb 6>; [90.00%]

  <bb 5> [local count: 11811160]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Accessing unlocked PE memory interface (write).\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 739, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 6> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = pe_34(D)->id;
  _7 = (long unsigned int) _6;
  _8 = _7 << 20;
  _9 = _8 & 15728640;
  _10 = _9 | memsel_27;
  addr_temp_37 = _10 | 2399141888;
  # DEBUG addr_temp => addr_temp_37
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mem_offs => 0
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  mem_addr_40 = mem_offs_28 + dst_addr_39(D);
  # DEBUG mem_addr => mem_addr_40
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = src_ptr_31(D) + mem_offs_28;
  _12 = *_11;
  _13 = _12 >> 24;
  _14 = _12 >> 8;
  _15 = _14 & 65280;
  _16 = _13 | _15;
  _17 = _12 << 8;
  _18 = _17 & 16711680;
  _19 = _16 | _18;
  _20 = _12 << 24;
  _21 = pe_34(D)->mem_access_wdata;
  _22 = (volatile uint32_t *) _21;
  _23 = _19 | _20;
  *_22 ={v} _23;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_42 = addr_temp_26 & 4294311936;
  # DEBUG addr_temp => addr_temp_42
  # DEBUG BEGIN_STMT
  addr_temp_43 = mem_addr_40 | addr_temp_42;
  # DEBUG addr_temp => addr_temp_43
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _24 = pe_34(D)->mem_access_addr;
  _25 = (volatile uint32_t *) _24;
  *_25 ={v} addr_temp_43;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem_offs_45 = mem_offs_28 + 4;
  # DEBUG mem_offs => mem_offs_45

  <bb 8> [local count: 1073741824]:
  # addr_temp_26 = PHI <addr_temp_37(6), addr_temp_43(7)>
  # mem_offs_28 = PHI <0(6), mem_offs_45(7)>
  # DEBUG mem_offs => mem_offs_28
  # DEBUG addr_temp => addr_temp_26
  # DEBUG BEGIN_STMT
  if (mem_offs_28 < len_38(D))
    goto <bb 7>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  return;

}



;; Function pfe_pe_fw_memset_single (pfe_pe_fw_memset_single, funcdef_no=36, decl_uid=11358, cgraph_uid=37, symbol_order=44)

Modification phase of node pfe_pe_fw_memset_single/44
pfe_pe_fw_memset_single (struct pfe_pe_t * pe, pfe_pe_mem_t mem, uint32_t val, addr_t addr, uint32_t size)
{
  const addr_t mem_addr;
  uint32_t mem_offs;
  uint32_t memsel;
  uint32_t addr_temp;
  bool_t * _1;
  unsigned char _2;
  _Bool _3;
  long int _4;
  long int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  unsigned int _14;
  volatile uint32_t * _15;
  long unsigned int _16;
  unsigned char _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  unsigned int _22;
  volatile uint32_t * _23;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_29(D) == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG memsel => 131072

  <bb 4> [local count: 118111600]:
  # memsel_25 = PHI <262144(2), 131072(3)>
  # DEBUG memsel => memsel_25
  # DEBUG BEGIN_STMT
  _1 = pe_31(D)->miflock;
  _2 = *_1;
  _3 = _2 == 0;
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 0);
  if (_5 != 0)
    goto <bb 5>; [10.00%]
  else
    goto <bb 6>; [90.00%]

  <bb 5> [local count: 11811160]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Accessing unlocked PE memory interface (write).\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 782, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 6> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = val_34(D) >> 24;
  _7 = val_34(D) >> 8;
  _8 = _7 & 65280;
  _9 = _6 | _8;
  _10 = val_34(D) << 8;
  _11 = _10 & 16711680;
  _12 = _9 | _11;
  _13 = val_34(D) << 24;
  _14 = pe_31(D)->mem_access_wdata;
  _15 = (volatile uint32_t *) _14;
  _16 = _12 | _13;
  *_15 ={v} _16;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = pe_31(D)->id;
  _18 = (long unsigned int) _17;
  _19 = _18 << 20;
  _20 = _19 & 15728640;
  _21 = _20 | memsel_25;
  addr_temp_36 = _21 | 2399141888;
  # DEBUG addr_temp => addr_temp_36
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mem_offs => 0
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  mem_addr_39 = mem_offs_26 + addr_38(D);
  # DEBUG mem_addr => mem_addr_39
  # DEBUG BEGIN_STMT
  addr_temp_40 = addr_temp_24 & 4294311936;
  # DEBUG addr_temp => addr_temp_40
  # DEBUG BEGIN_STMT
  addr_temp_41 = mem_addr_39 | addr_temp_40;
  # DEBUG addr_temp => addr_temp_41
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = pe_31(D)->mem_access_addr;
  _23 = (volatile uint32_t *) _22;
  *_23 ={v} addr_temp_41;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem_offs_43 = mem_offs_26 + 4;
  # DEBUG mem_offs => mem_offs_43

  <bb 8> [local count: 1073741824]:
  # addr_temp_24 = PHI <addr_temp_36(6), addr_temp_41(7)>
  # mem_offs_26 = PHI <0(6), mem_offs_43(7)>
  # DEBUG mem_offs => mem_offs_26
  # DEBUG addr_temp => addr_temp_24
  # DEBUG BEGIN_STMT
  if (mem_offs_26 < size_37(D))
    goto <bb 7>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  return;

}



;; Function pfe_pe_fw_memcpy_bulk (pfe_pe_fw_memcpy_bulk, funcdef_no=33, decl_uid=11340, cgraph_uid=34, symbol_order=41)

Modification phase of node pfe_pe_fw_memcpy_bulk/41
pfe_pe_fw_memcpy_bulk (struct pfe_pe_t * pe, pfe_pe_mem_t mem, addr_t dst_addr, const void * src_ptr, uint32_t len)
{
  const addr_t mem_addr;
  uint32_t mem_offs;
  uint32_t memsel;
  uint32_t addr_temp;
  bool_t * _1;
  unsigned char _2;
  _Bool _3;
  long int _4;
  long int _5;
  uint32_t * _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  unsigned int _16;
  volatile uint32_t * _17;
  long unsigned int _18;
  unsigned int _19;
  volatile uint32_t * _20;
  long unsigned int _27;
  long unsigned int _29;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG data => src_ptr_26(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_28(D) == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG memsel => 131072

  <bb 4> [local count: 118111600]:
  # memsel_22 = PHI <262144(2), 131072(3)>
  # DEBUG memsel => memsel_22
  # DEBUG BEGIN_STMT
  _1 = pe_31(D)->miflock;
  _2 = *_1;
  _3 = _2 == 0;
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 0);
  if (_5 != 0)
    goto <bb 5>; [10.00%]
  else
    goto <bb 6>; [90.00%]

  <bb 5> [local count: 11811160]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Accessing unlocked PE memory interface (write).\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 609, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 6> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_34 = memsel_22 | 2399141888;
  # DEBUG addr_temp => addr_temp_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mem_offs => 0
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  mem_addr_37 = mem_offs_23 + dst_addr_36(D);
  # DEBUG mem_addr => mem_addr_37
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = src_ptr_26(D) + mem_offs_23;
  _7 = *_6;
  _8 = _7 >> 24;
  _9 = _7 >> 8;
  _10 = _9 & 65280;
  _11 = _8 | _10;
  _12 = _7 << 8;
  _13 = _12 & 16711680;
  _14 = _11 | _13;
  _15 = _7 << 24;
  _16 = pe_31(D)->mem_access_wdata;
  _17 = (volatile uint32_t *) _16;
  _18 = _14 | _15;
  *_17 ={v} _18;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_39 = addr_temp_21 & 4278583296;
  # DEBUG addr_temp => addr_temp_39
  # DEBUG BEGIN_STMT
  addr_temp_40 = mem_addr_37 | addr_temp_39;
  # DEBUG addr_temp => addr_temp_40
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = pe_31(D)->mem_access_addr;
  _20 = (volatile uint32_t *) _19;
  *_20 ={v} addr_temp_40;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_42 = addr_temp_40 | 1048576;
  # DEBUG addr_temp => addr_temp_42
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} addr_temp_42;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_44 = addr_temp_40 | 3145728;
  # DEBUG addr_temp => addr_temp_44
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} addr_temp_44;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _27 = addr_temp_40 & 4293918719;
  addr_temp_46 = _27 | 2097152;
  # DEBUG addr_temp => addr_temp_46
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} addr_temp_46;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_48 = _27 | 6291456;
  # DEBUG addr_temp => addr_temp_48
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} addr_temp_48;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_50 = _27 | 7340032;
  # DEBUG addr_temp => addr_temp_50
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} addr_temp_50;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _29 = addr_temp_40 & 4291821567;
  addr_temp_52 = _29 | 5242880;
  # DEBUG addr_temp => addr_temp_52
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} addr_temp_52;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_54 = _29 | 4194304;
  # DEBUG addr_temp => addr_temp_54
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} addr_temp_54;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem_offs_56 = mem_offs_23 + 4;
  # DEBUG mem_offs => mem_offs_56

  <bb 8> [local count: 1073741824]:
  # addr_temp_21 = PHI <addr_temp_34(6), addr_temp_54(7)>
  # mem_offs_23 = PHI <0(6), mem_offs_56(7)>
  # DEBUG mem_offs => mem_offs_23
  # DEBUG addr_temp => addr_temp_21
  # DEBUG BEGIN_STMT
  if (mem_offs_23 < len_35(D))
    goto <bb 7>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  return;

}



;; Function pfe_pe_fw_memset_bulk (pfe_pe_fw_memset_bulk, funcdef_no=34, decl_uid=11346, cgraph_uid=35, symbol_order=42)

Modification phase of node pfe_pe_fw_memset_bulk/42
pfe_pe_fw_memset_bulk (struct pfe_pe_t * pe, pfe_pe_mem_t mem, uint32_t val, addr_t addr, uint32_t size)
{
  const addr_t mem_addr;
  uint32_t mem_offs;
  uint32_t memsel;
  uint32_t addr_temp;
  bool_t * _1;
  unsigned char _2;
  _Bool _3;
  long int _4;
  long int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  unsigned int _14;
  volatile uint32_t * _15;
  long unsigned int _16;
  unsigned int _17;
  volatile uint32_t * _18;
  long unsigned int _25;
  long unsigned int _26;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_24(D) == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG memsel => 131072

  <bb 4> [local count: 118111600]:
  # memsel_20 = PHI <262144(2), 131072(3)>
  # DEBUG memsel => memsel_20
  # DEBUG BEGIN_STMT
  _1 = pe_28(D)->miflock;
  _2 = *_1;
  _3 = _2 == 0;
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 0);
  if (_5 != 0)
    goto <bb 5>; [10.00%]
  else
    goto <bb 6>; [90.00%]

  <bb 5> [local count: 11811160]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Accessing unlocked PE memory interface (write).\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 673, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 6> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = val_31(D) >> 24;
  _7 = val_31(D) >> 8;
  _8 = _7 & 65280;
  _9 = _6 | _8;
  _10 = val_31(D) << 8;
  _11 = _10 & 16711680;
  _12 = _9 | _11;
  _13 = val_31(D) << 24;
  _14 = pe_28(D)->mem_access_wdata;
  _15 = (volatile uint32_t *) _14;
  _16 = _12 | _13;
  *_15 ={v} _16;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_33 = memsel_20 | 2399141888;
  # DEBUG addr_temp => addr_temp_33
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mem_offs => 0
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  mem_addr_36 = mem_offs_21 + addr_35(D);
  # DEBUG mem_addr => mem_addr_36
  # DEBUG BEGIN_STMT
  addr_temp_37 = addr_temp_19 & 4278583296;
  # DEBUG addr_temp => addr_temp_37
  # DEBUG BEGIN_STMT
  addr_temp_38 = mem_addr_36 | addr_temp_37;
  # DEBUG addr_temp => addr_temp_38
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = pe_28(D)->mem_access_addr;
  _18 = (volatile uint32_t *) _17;
  *_18 ={v} addr_temp_38;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_40 = addr_temp_38 | 1048576;
  # DEBUG addr_temp => addr_temp_40
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_18 ={v} addr_temp_40;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_42 = addr_temp_38 | 3145728;
  # DEBUG addr_temp => addr_temp_42
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_18 ={v} addr_temp_42;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = addr_temp_38 & 4293918719;
  addr_temp_44 = _25 | 2097152;
  # DEBUG addr_temp => addr_temp_44
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_18 ={v} addr_temp_44;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_46 = _25 | 6291456;
  # DEBUG addr_temp => addr_temp_46
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_18 ={v} addr_temp_46;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_48 = _25 | 7340032;
  # DEBUG addr_temp => addr_temp_48
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_18 ={v} addr_temp_48;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _26 = addr_temp_38 & 4291821567;
  addr_temp_50 = _26 | 5242880;
  # DEBUG addr_temp => addr_temp_50
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_18 ={v} addr_temp_50;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  addr_temp_52 = _26 | 4194304;
  # DEBUG addr_temp => addr_temp_52
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_18 ={v} addr_temp_52;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem_offs_54 = mem_offs_21 + 4;
  # DEBUG mem_offs => mem_offs_54

  <bb 8> [local count: 1073741824]:
  # addr_temp_19 = PHI <addr_temp_33(6), addr_temp_52(7)>
  # mem_offs_21 = PHI <0(6), mem_offs_54(7)>
  # DEBUG mem_offs => mem_offs_21
  # DEBUG addr_temp => addr_temp_19
  # DEBUG BEGIN_STMT
  if (mem_offs_21 < size_34(D))
    goto <bb 7>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  return;

}



;; Function oal_mutex_lock.part.0 (oal_mutex_lock.part.0, funcdef_no=74, decl_uid=12351, cgraph_uid=294, symbol_order=303)

Modification phase of node oal_mutex_lock.part.0/303
Adjusting mask for param 0 to 0x3f
Setting value range of param 0 [22, 33]
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



;; Function oal_mutex_unlock.part.0 (oal_mutex_unlock.part.0, funcdef_no=75, decl_uid=12356, cgraph_uid=295, symbol_order=304)

Modification phase of node oal_mutex_unlock.part.0/304
Adjusting mask for param 0 to 0x3f
Setting value range of param 0 [22, 33]
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



;; Function pfe_pe_fw_install_ops (pfe_pe_fw_install_ops, funcdef_no=32, decl_uid=11385, cgraph_uid=33, symbol_order=40)

Modification phase of node pfe_pe_fw_install_ops/40
pfe_pe_fw_install_ops (struct pfe_pe_t * pe, uint8_t pe_num)
{
  const struct fw_load_ops_t * pe_loader;
  uint8_t best_pe_loader_cnt;
  uint32_t pe_idx;
  uint32_t idx;
  errno_t ret;
  unsigned char _1;
  unsigned char _2;
  long unsigned int _3;
  struct pfe_pe_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  struct pfe_pe_t * _7;
  long unsigned int _8;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG idx => 0
  # DEBUG pe_idx => 0
  # DEBUG BEGIN_STMT
  # DEBUG best_pe_loader_cnt => 0
  # DEBUG BEGIN_STMT
  # DEBUG pe_loader => 0B
  # DEBUG BEGIN_STMT
  # DEBUG idx => 0
  goto <bb 13>; [100.00%]

  <bb 3> [local count: 236258637]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => pe_27(D)
  _1 = pfe_pe_check_pe_times.isra.0 (pe_27(D), idx_12, best_pe_loader_cnt_16, pe_num_25(D));
  if (_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 4> [local count: 118129319]:
  # DEBUG BEGIN_STMT
  _2 = fw_load_ops[idx_12].pe_loaded_cnt;
  if (_2 > 1)
    goto <bb 20>; [34.74%]
  else
    goto <bb 11>; [65.26%]

  <bb 20> [local count: 41038125]:
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 362524218]:
  # DEBUG BEGIN_STMT
  _3 = pe_idx_13 * 112;
  _4 = pe_27(D) + _3;
  ret_32 = pfe_pe_fw_ops_valid (pe_27(D), _4);
  # DEBUG ret => ret_32
  # DEBUG BEGIN_STMT
  if (ret_32 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 6> [local count: 19938832]:
  # ret_30 = PHI <ret_32(5)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] PEs are not identical\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 546, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 342585386]:
  # DEBUG BEGIN_STMT
  pe_idx_33 = pe_idx_13 + 1;
  # DEBUG pe_idx => pe_idx_33

  <bb 8> [local count: 383623511]:
  # ret_9 = PHI <0(7), 22(20)>
  # pe_idx_13 = PHI <pe_idx_33(7), 1(20)>
  # DEBUG pe_idx => pe_idx_13
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  _5 = (long unsigned int) pe_num_25(D);
  if (_5 > pe_idx_13)
    goto <bb 5>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 41038125]:
  # ret_10 = PHI <ret_30(6), ret_9(8)>
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  if (ret_10 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 10> [local count: 20519063]:
  # DEBUG BEGIN_STMT
  # DEBUG best_pe_loader_cnt => _2
  # DEBUG BEGIN_STMT
  pe_loader_36 = &fw_load_ops[idx_12];
  # DEBUG pe_loader => pe_loader_36
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 77091193]:
  # DEBUG BEGIN_STMT
  # DEBUG best_pe_loader_cnt => _2
  # DEBUG BEGIN_STMT
  pe_loader_31 = &fw_load_ops[idx_12];
  # DEBUG pe_loader => pe_loader_31

  <bb 12> [local count: 236258637]:
  # best_pe_loader_cnt_15 = PHI <best_pe_loader_cnt_16(3), _2(10), _2(11), best_pe_loader_cnt_16(9)>
  # pe_loader_17 = PHI <pe_loader_18(3), pe_loader_36(10), pe_loader_31(11), pe_loader_18(9)>
  # DEBUG pe_loader => pe_loader_17
  # DEBUG best_pe_loader_cnt => best_pe_loader_cnt_15
  # DEBUG BEGIN_STMT
  idx_37 = idx_12 + 1;
  # DEBUG idx => idx_37

  <bb 13> [local count: 354370237]:
  # idx_12 = PHI <0(2), idx_37(12)>
  # best_pe_loader_cnt_16 = PHI <0(2), best_pe_loader_cnt_15(12)>
  # pe_loader_18 = PHI <0B(2), pe_loader_17(12)>
  # DEBUG pe_loader => pe_loader_18
  # DEBUG best_pe_loader_cnt => best_pe_loader_cnt_16
  # DEBUG idx => idx_12
  # DEBUG BEGIN_STMT
  if (idx_12 != 2)
    goto <bb 3>; [66.67%]
  else
    goto <bb 14>; [33.33%]

  <bb 14> [local count: 118111600]:
  # pe_loader_26 = PHI <pe_loader_18(13)>
  goto <bb 16>; [100.00%]

  <bb 15> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _6 = pe_idx_14 * 112;
  _7 = pe_27(D) + _6;
  _7->fw_load_ops = pe_loader_26;
  # DEBUG BEGIN_STMT
  pe_idx_29 = pe_idx_14 + 1;
  # DEBUG pe_idx => pe_idx_29

  <bb 16> [local count: 1073741824]:
  # pe_idx_14 = PHI <pe_idx_29(15), 0(14)>
  # DEBUG ret => NULL
  # DEBUG pe_idx => pe_idx_14
  # DEBUG BEGIN_STMT
  _8 = (long unsigned int) pe_num_25(D);
  if (_8 > pe_idx_14)
    goto <bb 15>; [89.00%]
  else
    goto <bb 17>; [11.00%]

  <bb 17> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  if (pe_loader_26 != 0B)
    goto <bb 18>; [81.25%]
  else
    goto <bb 19>; [18.75%]

  <bb 18> [local count: 95965675]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 19> [local count: 118111601]:
  # ret_11 = PHI <19(17), 0(18)>
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_11;

}



;; Function pfe_pe_mem_write.isra.0.constprop (pfe_pe_mem_write.isra.0.constprop.0, funcdef_no=81, decl_uid=12485, cgraph_uid=322, symbol_order=331)

Modification phase of node pfe_pe_mem_write.isra.0.constprop/331
Adjusting mask for param 4 to 0x7
Adjusting mask for param 5 to 0x7
Setting value range of param 4 [1, 4]
Setting value range of param 5 [0, 4]
pfe_pe_mem_write.isra.0.constprop (struct pfe_pe_t * pe, uint32_t ISRA.42, addr_t ISRA.43, uint8_t ISRA.44, uint8_t ISRA.45)
{
  long unsigned int memdata$val;
  addr_t addr_temp;
  uint8_t size_temp;
  uint32_t val_temp;
  uint8_t offset_temp;
  uint32_t memsel;
  uint8_t bytesel;
  pfe_pe_mem_t ISRA.41;
  _Bool _9;
  long int _10;
  long int _11;
  unsigned int _12;
  unsigned int _13;
  int _15;
  int _16;
  int _17;
  unsigned int _18;
  int _20;
  long unsigned int _21;
  long unsigned int _22;
  unsigned int _23;
  unsigned int _24;
  long unsigned int _25;
  <unnamed type> _27;
  long unsigned int _28;
  long unsigned int _30;
  unsigned char _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int _36;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  bool_t * _43;
  unsigned char _44;
  _Bool _45;
  long int _46;
  long int _47;
  long unsigned int _49;
  long unsigned int _50;
  long unsigned int _51;
  long unsigned int _52;
  long unsigned int _53;
  long unsigned int _54;
  long unsigned int _55;
  long unsigned int _56;
  unsigned int _57;
  volatile uint32_t * _58;
  long unsigned int _59;
  unsigned int _60;
  volatile uint32_t * _61;

  <bb 11> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:

  <bb 3> [local count: 1073741824]:
  memdata$val_2 = ISRA.42_1(D);
  # DEBUG memdata$val => memdata$val_2
  # DEBUG BEGIN_STMT
  # DEBUG bytesel => 0
  # DEBUG BEGIN_STMT
  # DEBUG memsel => 0
  # DEBUG BEGIN_STMT
  offset_temp_4 = ISRA.45_3(D);
  # DEBUG offset_temp => offset_temp_4
  # DEBUG BEGIN_STMT
  # DEBUG val_temp => memdata$val_2
  # DEBUG BEGIN_STMT
  size_temp_6 = ISRA.44_5(D);
  # DEBUG size_temp => size_temp_6
  # DEBUG BEGIN_STMT
  addr_temp_8 = ISRA.43_7(D);
  # DEBUG addr_temp => addr_temp_8
  # DEBUG BEGIN_STMT
  _9 = offset_temp_4 != 0;
  _10 = (long int) _9;
  _11 = __builtin_expect (_10, 0);
  if (_11 != 0)
    goto <bb 4>; [10.00%]
  else
    goto <bb 5>; [90.00%]

  <bb 4> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = addr_temp_8 & 3;
  _13 = _12 * 8;
  val_temp_14 = memdata$val_2 << _13;
  # DEBUG val_temp => val_temp_14
  # DEBUG BEGIN_STMT
  _15 = (int) offset_temp_4;
  _16 = (int) size_temp_6;
  _17 = _15 - _16;
  _18 = 1 << _17;
  bytesel_19 = (uint8_t) _18;
  # DEBUG bytesel => bytesel_19
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = (int) size_temp_6;
  _21 = 1 << _20;
  _22 = _21 + 4294967295;
  _23 = (unsigned int) size_temp_6;
  _24 = 4 - _23;
  _25 = _22 << _24;
  bytesel_26 = (uint8_t) _25;
  # DEBUG bytesel => bytesel_26

  <bb 6> [local count: 1073741824]:
  # bytesel_37 = PHI <bytesel_19(4), bytesel_26(5)>
  # val_temp_48 = PHI <val_temp_14(4), memdata$val_2(5)>
  # DEBUG val_temp => val_temp_48
  # DEBUG bytesel => bytesel_37
  # DEBUG BEGIN_STMT
  _27 = 0;
  if (_27 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG memsel => 131072

  <bb 8> [local count: 1073741823]:
  # memsel_29 = PHI <262144(6), 131072(7)>
  # DEBUG memsel => memsel_29
  # DEBUG BEGIN_STMT
  _28 = addr_temp_8 & 1048575;
  _30 = _28 | memsel_29;
  _32 = pe_31(D)->id;
  _33 = (long unsigned int) _32;
  _34 = _33 << 20;
  _35 = _34 & 15728640;
  _36 = _30 | _35;
  _38 = (long unsigned int) bytesel_37;
  _39 = _38 << 24;
  _40 = _39 & 251658240;
  _41 = _36 | _40;
  addr_temp_42 = _41 | 2147483648;
  # DEBUG addr_temp => addr_temp_42
  # DEBUG BEGIN_STMT
  _43 = pe_31(D)->miflock;
  _44 = *_43;
  _45 = _44 == 0;
  _46 = (long int) _45;
  _47 = __builtin_expect (_46, 0);
  if (_47 != 0)
    goto <bb 9>; [10.00%]
  else
    goto <bb 10>; [90.00%]

  <bb 9> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Accessing unlocked PE memory interface (write).\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 924, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 10> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _49 = val_temp_48 >> 24;
  _50 = val_temp_48 >> 8;
  _51 = _50 & 65280;
  _52 = _49 | _51;
  _53 = val_temp_48 << 8;
  _54 = _53 & 16711680;
  _55 = _52 | _54;
  _56 = val_temp_48 << 24;
  _57 = pe_31(D)->mem_access_wdata;
  _58 = (volatile uint32_t *) _57;
  _59 = _55 | _56;
  *_58 ={v} _59;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _60 = pe_31(D)->mem_access_addr;
  _61 = (volatile uint32_t *) _60;
  *_61 ={v} addr_temp_42;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_pe_memcpy_from_host_to_dmem_32_nolock (pfe_pe_memcpy_from_host_to_dmem_32_nolock, funcdef_no=40, decl_uid=11334, cgraph_uid=41, symbol_order=48)

Modification phase of node pfe_pe_memcpy_from_host_to_dmem_32_nolock/48
pfe_pe_memcpy_from_host_to_dmem_32_nolock (struct pfe_pe_t * pe, addr_t dst_addr, const void * src_ptr, uint32_t len)
{
  unsigned int mem_data$addr;
  uint32_t len_temp;
  const uint8_t * src_byteptr;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  long unsigned int _5;
  unsigned int _6;
  unsigned int _8;
  long unsigned int _9;
  unsigned int _10;
  long unsigned int _11;
  unsigned char _12;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG src_byteptr => src_ptr_20(D)
  # DEBUG BEGIN_STMT
  # DEBUG len_temp => len_22(D)
  # DEBUG BEGIN_STMT
  # DEBUG mem_data => 0
  # DEBUG mem_data$val => 0
  # DEBUG mem_data$addr => dst_addr_25(D)
  # DEBUG mem_data$size => 0
  # DEBUG mem_data$offset => 0
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) mem_data$addr_21;
  _2 = _1 & 3;
  _3 = 4 - _2;
  # DEBUG mem_data$offset => _3
  # DEBUG BEGIN_STMT
  _4 = *src_byteptr_13;
  _5 = (long unsigned int) _4;
  # DEBUG mem_data$val => _5
  # DEBUG BEGIN_STMT
  # DEBUG mem_data$size => 1
  # DEBUG BEGIN_STMT
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  pfe_pe_mem_write.isra.0 (pe_26(D), 0, _5, mem_data$addr_21, 1, _3);
  # DEBUG BEGIN_STMT
  _6 = mem_data$addr_21 + 1;
  # DEBUG mem_data$addr => _6
  # DEBUG BEGIN_STMT
  src_byteptr_28 = src_byteptr_13 + 1;
  # DEBUG src_byteptr => src_byteptr_28
  # DEBUG BEGIN_STMT
  len_temp_29 = len_temp_15 + 4294967295;
  # DEBUG len_temp => len_temp_29

  <bb 4> [local count: 1073741824]:
  # src_byteptr_13 = PHI <src_ptr_20(D)(2), src_byteptr_28(3)>
  # len_temp_15 = PHI <len_22(D)(2), len_temp_29(3)>
  # mem_data$addr_21 = PHI <dst_addr_25(D)(2), _6(3)>
  # DEBUG mem_data$addr => mem_data$addr_21
  # DEBUG len_temp => len_temp_15
  # DEBUG src_byteptr => src_byteptr_13
  # DEBUG BEGIN_STMT
  _8 = mem_data$addr_21 & 3;
  if (_8 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 5> [local count: 114863532]:
  # src_byteptr_38 = PHI <src_byteptr_13(4), src_byteptr_13(6)>
  # len_temp_36 = PHI <len_temp_15(4), len_temp_15(6)>
  # mem_data$addr_34 = PHI <mem_data$addr_21(4), mem_data$addr_21(6)>
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 1014686025]:
  if (len_temp_15 != 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 7> [local count: 929350398]:
  # DEBUG BEGIN_STMT
  # DEBUG mem_data$offset => 0
  # DEBUG BEGIN_STMT
  _9 = MEM[(uint32_t *)src_byteptr_14];
  # DEBUG mem_data$val => _9
  # DEBUG BEGIN_STMT
  # DEBUG mem_data$size => 4
  # DEBUG BEGIN_STMT
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  pfe_pe_mem_write.isra.0 (pe_26(D), 0, _9, mem_data$addr_23, 4, 0);
  # DEBUG BEGIN_STMT
  len_temp_32 = len_temp_16 + 4294967292;
  # DEBUG len_temp => len_temp_32
  # DEBUG BEGIN_STMT
  src_byteptr_33 = src_byteptr_14 + 4;
  # DEBUG src_byteptr => src_byteptr_33
  # DEBUG BEGIN_STMT
  _10 = mem_data$addr_23 + 4;
  # DEBUG mem_data$addr => _10

  <bb 8> [local count: 1044213930]:
  # src_byteptr_14 = PHI <src_byteptr_38(5), src_byteptr_33(7)>
  # len_temp_16 = PHI <len_temp_36(5), len_temp_32(7)>
  # mem_data$addr_23 = PHI <mem_data$addr_34(5), _10(7)>
  # DEBUG mem_data$addr => mem_data$addr_23
  # DEBUG len_temp => len_temp_16
  # DEBUG src_byteptr => src_byteptr_14
  # DEBUG BEGIN_STMT
  if (len_temp_16 > 3)
    goto <bb 7>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 114863532]:
  # src_byteptr_35 = PHI <src_byteptr_14(8)>
  # len_temp_37 = PHI <len_temp_16(8)>
  # mem_data$addr_7 = PHI <mem_data$addr_23(8)>
  # DEBUG BEGIN_STMT
  if (len_temp_37 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 37904966]:
  # DEBUG BEGIN_STMT
  # DEBUG mem_data$offset => 0
  # DEBUG BEGIN_STMT
  _11 = pfe_pe_get_u32_from_byteptr (src_byteptr_35, len_temp_37);
  # DEBUG mem_data$val => _11
  # DEBUG BEGIN_STMT
  _12 = (unsigned char) len_temp_37;
  # DEBUG mem_data$size => _12
  # DEBUG BEGIN_STMT
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  # DEBUG D#4 => mem_data
  pfe_pe_mem_write.isra.0 (pe_26(D), 0, _11, mem_data$addr_7, _12, 0);

  <bb 11> [local count: 114863532]:
  return;

}



;; Function pfe_pe_mem_read.constprop (pfe_pe_mem_read.constprop.0, funcdef_no=80, decl_uid=12486, cgraph_uid=323, symbol_order=332)

Modification phase of node pfe_pe_mem_read.constprop/332
Adjusting mask for param 3 to 0x7
Setting value range of param 3 [1, 4]
pfe_pe_mem_read.constprop (struct pfe_pe_t * pe, addr_t addr, uint8_t size)
{
  uint32_t val;
  uint32_t mask;
  uint32_t memsel;
  addr_t adrr_temp;
  pfe_pe_mem_t mem;
  unsigned int _2;
  unsigned int _3;
  long unsigned int _4;
  long unsigned int _7;
  long unsigned int _9;
  unsigned char _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  bool_t * _16;
  unsigned char _17;
  _Bool _18;
  long int _19;
  long int _20;
  unsigned int _21;
  volatile uint32_t * _22;
  unsigned int _23;
  volatile uint32_t * _24;
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
  unsigned int _38;
  _Bool _39;
  long int _40;
  long int _41;
  unsigned int _42;

  <bb 11> [local count: 1073741824]:
  # DEBUG mem => 0

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG size_temp => size_1(D)
  # DEBUG BEGIN_STMT
  # DEBUG adrr_temp => addr_6(D)
  # DEBUG BEGIN_STMT
  if (size_1(D) != 4)
    goto <bb 3>; [66.00%]
  else
    goto <bb 4>; [34.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _2 = (unsigned int) size_1(D);
  _3 = _2 * 8;
  _4 = 1 << _3;
  mask_5 = _4 + 4294967295;
  # DEBUG mask => mask_5

  <bb 4> [local count: 1073741824]:
  # mask_45 = PHI <4294967295(2), mask_5(3)>
  # DEBUG mask => mask_45
  # DEBUG BEGIN_STMT
  if (1 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG memsel => 131072

  <bb 6> [local count: 1073741824]:
  # memsel_8 = PHI <262144(4), 131072(5)>
  # DEBUG memsel => memsel_8
  # DEBUG BEGIN_STMT
  _7 = addr_6(D) & 1048575;
  _9 = _7 | memsel_8;
  _11 = pe_10(D)->id;
  _12 = (long unsigned int) _11;
  _13 = _12 << 20;
  _14 = _13 & 15728640;
  adrr_temp_15 = _9 | _14;
  # DEBUG adrr_temp => adrr_temp_15
  # DEBUG BEGIN_STMT
  _16 = pe_10(D)->miflock;
  _17 = *_16;
  _18 = _17 == 0;
  _19 = (long int) _18;
  _20 = __builtin_expect (_19, 0);
  if (_20 != 0)
    goto <bb 7>; [10.00%]
  else
    goto <bb 8>; [90.00%]

  <bb 7> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Accessing unlocked PE memory interface (read).\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 851, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _21 = pe_10(D)->mem_access_addr;
  _22 = (volatile uint32_t *) _21;
  *_22 ={v} adrr_temp_15;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = pe_10(D)->mem_access_rdata;
  _24 = (volatile uint32_t *) _23;
  _25 ={v} *_24;
  _26 = _25 >> 24;
  _27 ={v} *_24;
  _28 = _27 >> 8;
  _29 = _28 & 65280;
  _30 = _26 | _29;
  _31 ={v} *_24;
  _32 = _31 << 8;
  _33 = _32 & 16711680;
  _34 = _30 | _33;
  _35 ={v} *_24;
  _36 = _35 << 24;
  val_37 = _34 | _36;
  # DEBUG val => val_37
  # DEBUG BEGIN_STMT
  _38 = adrr_temp_15 & 3;
  _39 = _38 != 0;
  _40 = (long int) _39;
  _41 = __builtin_expect (_40, 0);
  if (_41 != 0)
    goto <bb 9>; [10.00%]
  else
    goto <bb 10>; [90.00%]

  <bb 9> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  _42 = _38 * 8;
  val_43 = val_37 >> _42;
  # DEBUG val => val_43

  <bb 10> [local count: 1073741823]:
  # val_44 = PHI <val_37(8), val_43(9)>
  # DEBUG val => val_44
  # DEBUG BEGIN_STMT
  val_46 = val_44 & mask_45;
  # DEBUG val => val_46
  # DEBUG BEGIN_STMT
  return val_46;

}



;; Function pfe_pe_lock_family (pfe_pe_lock_family, funcdef_no=24, decl_uid=11285, cgraph_uid=25, symbol_order=32)

Modification phase of node pfe_pe_lock_family/32
pfe_pe_lock_family (struct pfe_pe_t * pe)
{
  bool_t * _1;
  unsigned char _2;
  _Bool _3;
  long int _4;
  long int _5;
  bool_t * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pe_9(D)->miflock;
  _2 = *_1;
  _3 = _2 != 0;
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 0);
  if (_5 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Lock already indicated.\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 291, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = pe_9(D)->miflock;
  *_6 = 1;
  return;

}



;; Function pfe_pe_unlock_family (pfe_pe_unlock_family, funcdef_no=25, decl_uid=11287, cgraph_uid=26, symbol_order=33)

Modification phase of node pfe_pe_unlock_family/33
pfe_pe_unlock_family (struct pfe_pe_t * pe)
{
  bool_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pe_3(D)->miflock;
  *_1 = 0;
  return;

}



;; Function pfe_pe_memlock_release_nolock (pfe_pe_memlock_release_nolock, funcdef_no=28, decl_uid=11283, cgraph_uid=29, symbol_order=36)

Modification phase of node pfe_pe_memlock_release_nolock/36
pfe_pe_memlock_release_nolock (struct pfe_pe_t * pe)
{
  struct pfe_ct_pe_misc_control_t misc_ctrl;
  uint32_t misc_dmem;
  errno_t ret;
  union pfe_ct_pe_mmap_t * _1;
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
  # DEBUG BEGIN_STMT
  misc_ctrl = {};
  # DEBUG BEGIN_STMT
  _1 = pe_15(D)->mmap_data;
  if (_1 == 0B)
    goto <bb 5>; [18.75%]
  else
    goto <bb 3>; [81.25%]

  <bb 3> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _2 = _1->common.pe_misc_control;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  misc_dmem_16 = _9 | _10;
  # DEBUG misc_dmem => misc_dmem_16
  # DEBUG BEGIN_STMT
  if (misc_dmem_16 == 0)
    goto <bb 5>; [52.23%]
  else
    goto <bb 4>; [47.77%]

  <bb 4> [local count: 416752756]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_15(D), misc_dmem_16, &misc_ctrl, 4);

  <bb 5> [local count: 1073741824]:
  # ret_11 = PHI <114(2), 22(3), 0(4)>
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  misc_ctrl ={v} {CLOBBER};
  return ret_11;

}



;; Function pfe_pe_memcpy_from_dmem_to_host_32_nolock (pfe_pe_memcpy_from_dmem_to_host_32_nolock, funcdef_no=42, decl_uid=11229, cgraph_uid=43, symbol_order=50)

Modification phase of node pfe_pe_memcpy_from_dmem_to_host_32_nolock/50
pfe_pe_memcpy_from_dmem_to_host_32_nolock (struct pfe_pe_t * pe, void * dst_ptr, addr_t src_addr, uint32_t len)
{
  uint32_t len_temp;
  addr_t src_temp;
  uint8_t * dst_byteptr;
  uint32_t val;
  long unsigned int _1;
  unsigned int _2;
  long unsigned int _3;
  unsigned char _5;
  long unsigned int _6;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG dst_byteptr => dst_ptr_16(D)
  # DEBUG BEGIN_STMT
  # DEBUG src_temp => src_addr_18(D)
  # DEBUG BEGIN_STMT
  # DEBUG len_temp => len_20(D)
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  _1 = pfe_pe_mem_read (pe_22(D), 0, src_temp_9, 1);
  val = _1;
  # DEBUG BEGIN_STMT
  autolibc_memcpy (dst_byteptr_7, &val, 1);
  # DEBUG BEGIN_STMT
  dst_byteptr_26 = dst_byteptr_7 + 1;
  # DEBUG dst_byteptr => dst_byteptr_26
  # DEBUG BEGIN_STMT
  src_temp_27 = src_temp_9 + 1;
  # DEBUG src_temp => src_temp_27
  # DEBUG BEGIN_STMT
  len_temp_28 = len_temp_11 + 4294967295;
  # DEBUG len_temp => len_temp_28

  <bb 4> [local count: 1073741824]:
  # dst_byteptr_7 = PHI <dst_ptr_16(D)(2), dst_byteptr_26(3)>
  # src_temp_9 = PHI <src_addr_18(D)(2), src_temp_27(3)>
  # len_temp_11 = PHI <len_20(D)(2), len_temp_28(3)>
  # DEBUG len_temp => len_temp_11
  # DEBUG src_temp => src_temp_9
  # DEBUG dst_byteptr => dst_byteptr_7
  # DEBUG BEGIN_STMT
  _2 = src_temp_9 & 3;
  if (_2 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 5> [local count: 114863532]:
  # dst_byteptr_17 = PHI <dst_byteptr_7(4), dst_byteptr_7(6)>
  # src_temp_41 = PHI <src_temp_9(4), src_temp_9(6)>
  # len_temp_39 = PHI <len_temp_11(4), len_temp_11(6)>
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 1014686025]:
  if (len_temp_11 != 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 7> [local count: 929350398]:
  # DEBUG BEGIN_STMT
  _3 = pfe_pe_mem_read (pe_22(D), 0, src_temp_10, 4);
  val = _3;
  # DEBUG BEGIN_STMT
  MEM[(uint32_t *)dst_byteptr_8] = _3;
  # DEBUG BEGIN_STMT
  len_temp_36 = len_temp_12 + 4294967292;
  # DEBUG len_temp => len_temp_36
  # DEBUG BEGIN_STMT
  src_temp_37 = src_temp_10 + 4;
  # DEBUG src_temp => src_temp_37
  # DEBUG BEGIN_STMT
  dst_byteptr_38 = dst_byteptr_8 + 4;
  # DEBUG dst_byteptr => dst_byteptr_38

  <bb 8> [local count: 1044213930]:
  # dst_byteptr_8 = PHI <dst_byteptr_17(5), dst_byteptr_38(7)>
  # src_temp_10 = PHI <src_temp_41(5), src_temp_37(7)>
  # len_temp_12 = PHI <len_temp_39(5), len_temp_36(7)>
  # DEBUG len_temp => len_temp_12
  # DEBUG src_temp => src_temp_10
  # DEBUG dst_byteptr => dst_byteptr_8
  # DEBUG BEGIN_STMT
  if (len_temp_12 > 3)
    goto <bb 7>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 114863532]:
  # dst_byteptr_40 = PHI <dst_byteptr_8(8)>
  # src_temp_4 = PHI <src_temp_10(8)>
  # len_temp_19 = PHI <len_temp_12(8)>
  # DEBUG BEGIN_STMT
  if (len_temp_19 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 37904966]:
  # DEBUG BEGIN_STMT
  _5 = (unsigned char) len_temp_19;
  _6 = pfe_pe_mem_read (pe_22(D), 0, src_temp_4, _5);
  val = _6;
  # DEBUG BEGIN_STMT
  autolibc_memcpy (dst_byteptr_40, &val, len_temp_19);

  <bb 11> [local count: 114863532]:
  val ={v} {CLOBBER};
  return;

}



;; Function pfe_pe_get_state_monitor_nolock (pfe_pe_get_state_monitor_nolock, funcdef_no=22, decl_uid=11327, cgraph_uid=23, symbol_order=30)

Modification phase of node pfe_pe_get_state_monitor_nolock/30
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
pfe_pe_get_state_monitor_nolock (struct pfe_pe_t * pe, struct pfe_ct_pe_sw_state_monitor_t * state_monitor)
{
  errno_t ret;
  union pfe_ct_pe_mmap_t * _1;
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
  _1 = pe_15(D)->mmap_data;
  if (_1 == 0B)
    goto <bb 4>; [31.91%]
  else
    goto <bb 3>; [68.09%]

  <bb 3> [local count: 731110809]:
  # DEBUG BEGIN_STMT
  _2 = _1->common.state_monitor;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  _11 = _9 | _10;
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_15(D), state_monitor_16(D), _11, 8);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_12 = PHI <5(2), 0(3)>
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  return ret_12;

}



;; Function pfe_pe_memlock_acquire_nolock (pfe_pe_memlock_acquire_nolock, funcdef_no=27, decl_uid=11281, cgraph_uid=28, symbol_order=35)

Modification phase of node pfe_pe_memlock_acquire_nolock/35
pfe_pe_memlock_acquire_nolock (struct pfe_pe_t * pe)
{
  uint32_t misc_dmem;
  errno_t ret;
  union pfe_ct_pe_mmap_t * _1;
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
  # DEBUG BEGIN_STMT
  _1 = pe_14(D)->mmap_data;
  if (_1 == 0B)
    goto <bb 5>; [18.75%]
  else
    goto <bb 3>; [81.25%]

  <bb 3> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  _2 = _1->common.pe_misc_control;
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  misc_dmem_15 = _9 | _10;
  # DEBUG misc_dmem => misc_dmem_15
  # DEBUG BEGIN_STMT
  if (misc_dmem_15 == 0)
    goto <bb 5>; [52.23%]
  else
    goto <bb 4>; [47.77%]

  <bb 4> [local count: 416752756]:
  # DEBUG BEGIN_STMT
  ret_17 = pfe_pe_mem_process_lock (pe_14(D), misc_dmem_15);
  # DEBUG ret => ret_17

  <bb 5> [local count: 1073741824]:
  # ret_11 = PHI <114(2), 22(3), ret_17(4)>
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  return ret_11;

}



;; Function pfe_pe_memcpy_from_host_to_dmem_32 (pfe_pe_memcpy_from_host_to_dmem_32, funcdef_no=41, decl_uid=11234, cgraph_uid=42, symbol_order=49)

Modification phase of node pfe_pe_memcpy_from_host_to_dmem_32/49
pfe_pe_memcpy_from_host_to_dmem_32 (struct pfe_pe_t * pe, addr_t dst_addr, const void * src_ptr, uint32_t len)
{
  errno_t ret;
  <unnamed type> _1;
  <unnamed type> _2;
  bool_t * _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pe_7(D)->type;
  if (_1 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 22
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (22);
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 30
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (30);
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  pfe_pe_lock_family (pe_7(D));
  # DEBUG BEGIN_STMT
  ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  if (ret_10 != 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 6>; [33.00%]

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_7(D), dst_addr_11(D), src_ptr_12(D), len_13(D));
  # DEBUG BEGIN_STMT
  pfe_pe_memlock_release_nolock (pe_7(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pe => pe_7(D)
  # DEBUG INLINE_ENTRY pfe_pe_unlock_family
  # DEBUG BEGIN_STMT
  _16 = pe_7(D)->miflock;
  *_16 = 0;
  # DEBUG pe => NULL
  # DEBUG BEGIN_STMT
  _2 = pe_7(D)->type;
  if (_2 == 1)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 22
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (22);
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 30
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (30);
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_pe_memcpy_from_dmem_to_host_32 (pfe_pe_memcpy_from_dmem_to_host_32, funcdef_no=43, decl_uid=11239, cgraph_uid=44, symbol_order=51)

Modification phase of node pfe_pe_memcpy_from_dmem_to_host_32/51
pfe_pe_memcpy_from_dmem_to_host_32 (struct pfe_pe_t * pe, void * dst_ptr, addr_t src_addr, uint32_t len)
{
  errno_t ret;
  <unnamed type> _1;
  <unnamed type> _2;
  bool_t * _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pe_7(D)->type;
  if (_1 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 23
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (23);
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 31
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (31);
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  pfe_pe_lock_family (pe_7(D));
  # DEBUG BEGIN_STMT
  ret_10 = pfe_pe_memlock_acquire_nolock (pe_7(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  if (ret_10 != 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 6>; [33.00%]

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_7(D), dst_ptr_11(D), src_addr_12(D), len_13(D));
  # DEBUG BEGIN_STMT
  pfe_pe_memlock_release_nolock (pe_7(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pe => pe_7(D)
  # DEBUG INLINE_ENTRY pfe_pe_unlock_family
  # DEBUG BEGIN_STMT
  _16 = pe_7(D)->miflock;
  *_16 = 0;
  # DEBUG pe => NULL
  # DEBUG BEGIN_STMT
  _2 = pe_7(D)->type;
  if (_2 == 1)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 23
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (23);
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 31
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (31);
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  # DEBUG mutex => NULL
  # DEBUG mutex => NULL
  return;

}



;; Function pfe_pe_gather_memcpy_from_dmem_to_host_32 (pfe_pe_gather_memcpy_from_dmem_to_host_32, funcdef_no=44, decl_uid=11246, cgraph_uid=45, symbol_order=52)

Modification phase of node pfe_pe_gather_memcpy_from_dmem_to_host_32/52
pfe_pe_gather_memcpy_from_dmem_to_host_32 (struct pfe_pe_t * pe, int32_t pe_count, void * dst_ptr, addr_t src_addr, uint32_t buffer_len, uint32_t read_len)
{
  errno_t ret_store;
  errno_t ret;
  boolean is_mem_lock_error;
  int32_t ii;
  unsigned int ii.1_1;
  unsigned int _2;
  struct pfe_pe_t * _3;
  long unsigned int ii.2_4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _8;
  struct pfe_pe_t * _9;
  long unsigned int _11;
  void * _12;
  unsigned int ii.5_13;
  unsigned int _14;
  struct pfe_pe_t * _15;
  bool_t * _54;

  <bb 2> [local count: 118111602]:
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  # DEBUG BEGIN_STMT
  # DEBUG is_mem_lock_error => 0
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG ret_store => 0
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 28
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (28);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  pfe_pe_lock_family (pe_33(D));
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  ii.1_1 = (unsigned int) ii_16;
  _2 = ii.1_1 * 112;
  _3 = pe_33(D) + _2;
  ret_50 = pfe_pe_memlock_acquire_nolock (_3);
  # DEBUG ret => ret_50
  # DEBUG BEGIN_STMT
  if (ret_50 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  # DEBUG is_mem_lock_error => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Memory lock failed for PE instance %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1214, ii_16, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret_store => ret_50

  <bb 5> [local count: 955630223]:
  # is_mem_lock_error_19 = PHI <is_mem_lock_error_20(3), 1(4)>
  # ret_store_21 = PHI <ret_store_22(3), ret_50(4)>
  # DEBUG ret_store => ret_store_21
  # DEBUG is_mem_lock_error => is_mem_lock_error_19
  # DEBUG BEGIN_STMT
  ii_53 = ii_16 + 1;
  # DEBUG ii => ii_53

  <bb 6> [local count: 1073741824]:
  # ii_16 = PHI <0(2), ii_53(5)>
  # is_mem_lock_error_20 = PHI <0(2), is_mem_lock_error_19(5)>
  # ret_store_22 = PHI <0(2), ret_store_21(5)>
  # DEBUG ret_store => ret_store_22
  # DEBUG is_mem_lock_error => is_mem_lock_error_20
  # DEBUG ii => ii_16
  # DEBUG BEGIN_STMT
  if (ii_16 < pe_count_35(D))
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  # is_mem_lock_error_7 = PHI <is_mem_lock_error_20(6)>
  # ret_store_10 = PHI <ret_store_22(6)>
  # DEBUG BEGIN_STMT
  if (is_mem_lock_error_7 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 17> [local count: 59055800]:
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 521689472]:
  # DEBUG BEGIN_STMT
  ii.2_4 = (long unsigned int) ii_17;
  _5 = ii.2_4 + 1;
  _6 = _5 * read_len_36(D);
  if (_6 <= buffer_len_37(D))
    goto <bb 10>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 118111601]:
  # ii_29 = PHI <0(8), 0(11), 0(7)>
  # ret_store_23 = PHI <11(8), ret_store_10(11), ret_store_10(7)>
  goto <bb 15>; [100.00%]

  <bb 10> [local count: 492996551]:
  # DEBUG BEGIN_STMT
  _8 = ii.2_4 * 112;
  _9 = pe_33(D) + _8;
  _11 = ii.2_4 * read_len_36(D);
  _12 = dst_ptr_38(D) + _11;
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (_9, _12, src_addr_39(D), read_len_36(D));
  # DEBUG BEGIN_STMT
  ii_41 = ii_17 + 1;
  # DEBUG ii => ii_41

  <bb 11> [local count: 552052351]:
  # ii_17 = PHI <ii_41(10), 0(17)>
  # DEBUG ii => ii_17
  # DEBUG BEGIN_STMT
  if (ii_17 < pe_count_35(D))
    goto <bb 8>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 12> [local count: 955630213]:
  # DEBUG BEGIN_STMT
  ii.5_13 = (unsigned int) ii_18;
  _14 = ii.5_13 * 112;
  _15 = pe_33(D) + _14;
  ret_45 = pfe_pe_memlock_release_nolock (_15);
  # DEBUG ret => ret_45
  # DEBUG BEGIN_STMT
  if (ret_45 != 0)
    goto <bb 13>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 13> [local count: 315357970]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Memory unlock failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1248, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret_store => ret_45

  <bb 14> [local count: 955630213]:
  # ret_store_24 = PHI <ret_store_25(12), ret_45(13)>
  # DEBUG ret_store => ret_store_24
  # DEBUG BEGIN_STMT
  ii_48 = ii_18 + 1;
  # DEBUG ii => ii_48

  <bb 15> [local count: 1073741811]:
  # ii_18 = PHI <ii_29(9), ii_48(14)>
  # ret_store_25 = PHI <ret_store_23(9), ret_store_24(14)>
  # DEBUG ret_store => ret_store_25
  # DEBUG ii => ii_18
  # DEBUG BEGIN_STMT
  if (ii_18 < pe_count_35(D))
    goto <bb 12>; [89.00%]
  else
    goto <bb 16>; [11.00%]

  <bb 16> [local count: 118111599]:
  # ret_store_42 = PHI <ret_store_25(15)>
  # DEBUG BEGIN_STMT
  # DEBUG ret => ret_store_42
  # DEBUG BEGIN_STMT
  # DEBUG pe => pe_33(D)
  # DEBUG INLINE_ENTRY pfe_pe_unlock_family
  # DEBUG BEGIN_STMT
  _54 = pe_33(D)->miflock;
  *_54 = 0;
  # DEBUG pe => NULL
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 28
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (28);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_store_42;

}



;; Function pfe_pe_create (pfe_pe_create, funcdef_no=51, decl_uid=11197, cgraph_uid=52, symbol_order=59)

Modification phase of node pfe_pe_create/59
pfe_pe_create (addr_t cbus_base_va, pfe_ct_pe_type_t type, uint8_t id, struct pfe_pe_t * pe, bool_t * miflock)
{
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG tmp_pe => pe_3(D)
  # DEBUG BEGIN_STMT
  _1 = type_4(D) + 255;
  if (_1 <= 2)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  autolibc_memset (pe_3(D), 0, 112);
  # DEBUG BEGIN_STMT
  pe_3(D)->type = type_4(D);
  # DEBUG BEGIN_STMT
  pe_3(D)->cbus_base_va = cbus_base_va_8(D);
  # DEBUG BEGIN_STMT
  pe_3(D)->id = id_10(D);
  # DEBUG BEGIN_STMT
  pe_3(D)->fw_msg_section = 0B;
  # DEBUG BEGIN_STMT
  pe_3(D)->mmap_data = 0B;
  # DEBUG BEGIN_STMT
  pe_3(D)->miflock = miflock_14(D);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return pe_3(D);

}



;; Function pfe_pe_set_dmem (pfe_pe_set_dmem, funcdef_no=52, decl_uid=11201, cgraph_uid=53, symbol_order=60)

Modification phase of node pfe_pe_set_dmem/60
pfe_pe_set_dmem (struct pfe_pe_t * pe, addr_t elf_base, addr_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pe_2(D)->dmem_elf_base_va = elf_base_3(D);
  # DEBUG BEGIN_STMT
  pe_2(D)->dmem_size = len_5(D);
  return;

}



;; Function pfe_pe_set_imem (pfe_pe_set_imem, funcdef_no=53, decl_uid=11205, cgraph_uid=54, symbol_order=61)

Modification phase of node pfe_pe_set_imem/61
pfe_pe_set_imem (struct pfe_pe_t * pe, addr_t elf_base, addr_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pe_2(D)->imem_elf_base_va = elf_base_3(D);
  # DEBUG BEGIN_STMT
  pe_2(D)->imem_size = len_5(D);
  return;

}



;; Function pfe_pe_set_lmem (pfe_pe_set_lmem, funcdef_no=54, decl_uid=11209, cgraph_uid=55, symbol_order=62)

Modification phase of node pfe_pe_set_lmem/62
pfe_pe_set_lmem (struct pfe_pe_t * pe, addr_t elf_base, addr_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pe_2(D)->lmem_base_addr_pa = elf_base_3(D);
  # DEBUG BEGIN_STMT
  pe_2(D)->lmem_size = len_5(D);
  return;

}



;; Function pfe_pe_set_iaccess (pfe_pe_set_iaccess, funcdef_no=55, decl_uid=11214, cgraph_uid=56, symbol_order=63)

Modification phase of node pfe_pe_set_iaccess/63
pfe_pe_set_iaccess (struct pfe_pe_t * pe, uint32_t wdata_reg, uint32_t rdata_reg, uint32_t addr_reg)
{
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pe_6(D)->cbus_base_va;
  _2 = _1 + addr_reg_7(D);
  pe_6(D)->mem_access_addr = _2;
  # DEBUG BEGIN_STMT
  _3 = _1 + rdata_reg_9(D);
  pe_6(D)->mem_access_rdata = _3;
  # DEBUG BEGIN_STMT
  _4 = _1 + wdata_reg_11(D);
  pe_6(D)->mem_access_wdata = _4;
  return;

}



;; Function pfe_pe_mem_default_init (pfe_pe_mem_default_init, funcdef_no=57, decl_uid=11217, cgraph_uid=58, symbol_order=65)

Modification phase of node pfe_pe_mem_default_init/65
pfe_pe_mem_default_init (struct pfe_pe_t * pe, uint32_t pe_num)
{
  errno_t ret;
  uint32_t pe_idx;
  unsigned char _1;
  long unsigned int _2;
  struct pfe_pe_t * _3;
  const struct fw_load_ops_t * _4;
  void (*<Td71>) (struct pfe_pe_tag *, pfe_pe_mem_t, uint32_t, addr_t, uint32_t) _6;
  unsigned int _7;
  const struct fw_load_ops_t * _8;
  void (*<Td71>) (struct pfe_pe_tag *, pfe_pe_mem_t, uint32_t, addr_t, uint32_t) _9;
  unsigned int _10;
  unsigned char _12;
  long unsigned int _13;
  bool_t * _27;
  const struct fw_load_ops_t * _32;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 33
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (33);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  pfe_pe_lock_family (pe_20(D));
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) pe_num_22(D);
  ret_24 = pfe_pe_fw_install_ops (pe_20(D), _1);
  # DEBUG ret => ret_24
  # DEBUG BEGIN_STMT
  if (ret_24 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 3> [local count: 38976828]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1731, ret_24, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 8> [local count: 118111600]:
  # pe_idx_17 = PHI <0(3), 0(2)>
  # ret_28 = PHI <ret_24(3), ret_24(2)>
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _2 = pe_idx_14 * 112;
  _3 = pe_20(D) + _2;
  _4 = _3->fw_load_ops;
  if (_4 == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 286689066]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 19

  <bb 7> [local count: 955630223]:
  # ret_15 = PHI <ret_16(5), 19(6)>
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  _6 = _4->pe_memset;
  _7 = _3->dmem_size;
  _6 (_3, 0, 0, 0, _7);
  # DEBUG BEGIN_STMT
  _8 = _3->fw_load_ops;
  _9 = _8->pe_memset;
  _10 = _3->imem_size;
  _9 (_3, 1, 0, 0, _10);
  # DEBUG BEGIN_STMT
  pe_idx_31 = pe_idx_14 + 1;
  # DEBUG pe_idx => pe_idx_31

  <bb 10> [local count: 1073741824]:
  # pe_idx_14 = PHI <pe_idx_17(8), pe_idx_31(7)>
  # ret_16 = PHI <ret_28(8), ret_15(7)>
  # DEBUG ret => ret_16
  # DEBUG pe_idx => pe_idx_14
  # DEBUG BEGIN_STMT
  _32 = MEM[(const struct fw_load_ops_t * *)pe_20(D) + 60B];
  # DEBUG D#1 => pe_20(D)
  _12 = pfe_pe_fw_load_cycles.isra.0 (_32, _1);
  _13 = (long unsigned int) _12;
  if (_13 > pe_idx_14)
    goto <bb 5>; [89.00%]
  else
    goto <bb 9>; [11.00%]

  <bb 9> [local count: 118111601]:
  # ret_11 = PHI <ret_16(10)>
  # DEBUG BEGIN_STMT
  # DEBUG pe => pe_20(D)
  # DEBUG INLINE_ENTRY pfe_pe_unlock_family
  # DEBUG BEGIN_STMT
  _27 = pe_20(D)->miflock;
  *_27 = 0;
  # DEBUG pe => NULL
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 33
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (33);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_11;

}



;; Function pfe_pe_load_firmware (pfe_pe_load_firmware, funcdef_no=60, decl_uid=11221, cgraph_uid=61, symbol_order=68)

Modification phase of node pfe_pe_load_firmware/68
pfe_pe_load_firmware (struct pfe_pe_t * pe, uint32_t pe_num, const void * elf)
{
  bool_t bOpsExist;
  errno_t ret;
  uint32_t pe_idx;
  <unnamed type> _1;
  unsigned char _2;
  long unsigned int _3;
  struct pfe_pe_t * _4;
  const struct fw_load_ops_t * _5;
  void (*<Td71>) (struct pfe_pe_tag *, pfe_pe_mem_t, uint32_t, addr_t, uint32_t) _6;
  unsigned int _7;
  const struct fw_load_ops_t * _8;
  void (*<Td71>) (struct pfe_pe_tag *, pfe_pe_mem_t, uint32_t, addr_t, uint32_t) _9;
  unsigned int _10;
  unsigned char _12;
  long unsigned int _13;
  <unnamed type> _14;
  bool_t * _32;
  const struct fw_load_ops_t * _39;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG bOpsExist => 1
  # DEBUG BEGIN_STMT
  _1 = pe_25(D)->type;
  if (_1 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 39053601]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 24
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (24);
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 75809931]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 32
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (32);
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 114863532]:
  # DEBUG mutex => NULL
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  pfe_pe_lock_family (pe_25(D));
  # DEBUG BEGIN_STMT
  _2 = (unsigned char) pe_num_27(D);
  ret_29 = pfe_pe_fw_install_ops (pe_25(D), _2);
  # DEBUG ret => ret_29
  # DEBUG BEGIN_STMT
  if (ret_29 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 6> [local count: 37904966]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t find PE load operations: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 1980, ret_29, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 10> [local count: 114863532]:
  # pe_idx_20 = PHI <0(6), 0(5)>
  goto <bb 17>; [100.00%]

  <bb 8> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _3 = pe_idx_15 * 112;
  _4 = pe_25(D) + _3;
  _5 = _4->fw_load_ops;
  if (_5 == 0B)
    goto <bb 11>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 9> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  _6 = _5->pe_memset;
  _7 = _4->dmem_size;
  _6 (_4, 0, 0, 0, _7);
  # DEBUG BEGIN_STMT
  _8 = _4->fw_load_ops;
  _9 = _8->pe_memset;
  _10 = _4->imem_size;
  _9 (_4, 1, 0, 0, _10);
  # DEBUG BEGIN_STMT
  pe_idx_35 = pe_idx_15 + 1;
  # DEBUG pe_idx => pe_idx_35

  <bb 17> [local count: 1073741824]:
  # pe_idx_15 = PHI <pe_idx_20(10), pe_idx_35(9)>
  # DEBUG pe_idx => pe_idx_15
  # DEBUG BEGIN_STMT
  _39 = MEM[(const struct fw_load_ops_t * *)pe_25(D) + 60B];
  # DEBUG D#1 => pe_25(D)
  _12 = pfe_pe_fw_load_cycles.isra.0 (_39, _2);
  _13 = (long unsigned int) _12;
  if (_13 > pe_idx_15)
    goto <bb 8>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 11> [local count: 114863532]:
  # ret_16 = PHI <19(8), ret_29(17)>
  # bOpsExist_18 = PHI <0(8), 1(17)>
  # DEBUG bOpsExist => bOpsExist_18
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  if (bOpsExist_18 == 1)
    goto <bb 12>; [20.24%]
  else
    goto <bb 13>; [79.76%]

  <bb 12> [local count: 23248379]:
  # DEBUG BEGIN_STMT
  ret_38 = pfe_pe_load_firmware_aux (pe_25(D), pe_num_27(D), elf_36(D));
  # DEBUG ret => ret_38

  <bb 13> [local count: 114863532]:
  # ret_17 = PHI <ret_16(11), ret_38(12)>
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  # DEBUG pe => pe_25(D)
  # DEBUG INLINE_ENTRY pfe_pe_unlock_family
  # DEBUG BEGIN_STMT
  _32 = pe_25(D)->miflock;
  *_32 = 0;
  # DEBUG pe => NULL
  # DEBUG BEGIN_STMT
  _14 = pe_25(D)->type;
  if (_14 == 1)
    goto <bb 14>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 14> [local count: 39053601]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 24
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (24);
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 15> [local count: 75809931]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 32
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (32);
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 114863532]:
  # DEBUG mutex => NULL
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_17;

}



;; Function pfe_pe_get_mmap (pfe_pe_get_mmap, funcdef_no=61, decl_uid=11224, cgraph_uid=62, symbol_order=69)

Modification phase of node pfe_pe_get_mmap/69
pfe_pe_get_mmap (const struct pfe_pe_t * pe, union pfe_ct_pe_mmap_t * mmap)
{
  errno_t ret;
  union pfe_ct_pe_mmap_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pe_5(D)->mmap_data;
  if (_1 != 0B)
    goto <bb 3>; [68.09%]
  else
    goto <bb 4>; [31.91%]

  <bb 3> [local count: 731110809]:
  # DEBUG BEGIN_STMT
  autolibc_memcpy (mmap_6(D), _1, 188);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_2 = PHI <0(3), 2(2)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_pe_destroy (pfe_pe_destroy, funcdef_no=62, decl_uid=11269, cgraph_uid=63, symbol_order=70)

Modification phase of node pfe_pe_destroy/70
pfe_pe_destroy (struct pfe_pe_t * pe, uint32_t pe_num)
{
  uint32_t pe_idx;
  long unsigned int _1;
  struct pfe_pe_t * _2;

  <bb 2> [local count: 337461715]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pe_6(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 236223200]:
  if (pe_num_8(D) != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 7> [local count: 118111600]:
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  _1 = pe_idx_3 * 112;
  _2 = pe_6(D) + _1;
  _2->mmap_data = 0B;
  # DEBUG BEGIN_STMT
  _2->fw_msg_section = 0B;
  # DEBUG BEGIN_STMT
  _2->fw_msg_section_size = 0;
  # DEBUG BEGIN_STMT
  _2->fw_feature_section = 0B;
  # DEBUG BEGIN_STMT
  _2->fw_feature_section_size = 0;
  # DEBUG BEGIN_STMT
  _2->miflock = 0B;
  # DEBUG BEGIN_STMT
  pe_idx_15 = pe_idx_3 + 1;
  # DEBUG pe_idx => pe_idx_15

  <bb 5> [local count: 1073741824]:
  # pe_idx_3 = PHI <pe_idx_15(4), 0(7)>
  # DEBUG pe_idx => pe_idx_3
  # DEBUG BEGIN_STMT
  if (pe_idx_3 < pe_num_8(D))
    goto <bb 4>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 6> [local count: 337461716]:
  return;

}



;; Function pfe_pe_get_fw_feature_str_base (pfe_pe_get_fw_feature_str_base, funcdef_no=63, decl_uid=11289, cgraph_uid=64, symbol_order=71)

Modification phase of node pfe_pe_get_fw_feature_str_base/71
pfe_pe_get_fw_feature_str_base (const struct pfe_pe_t * pe)
{
  char * str;
  long unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG str => 0B
  # DEBUG BEGIN_STMT
  _1 = pe_4(D)->fw_features_base;
  if (_1 != 4294967295)
    goto <bb 3>; [82.62%]
  else
    goto <bb 4>; [17.38%]

  <bb 3> [local count: 887125496]:
  # DEBUG BEGIN_STMT
  str_5 = pe_4(D)->fw_feature_section;
  # DEBUG str => str_5

  <bb 4> [local count: 1073741824]:
  # str_2 = PHI <0B(2), str_5(3)>
  # DEBUG str => str_2
  # DEBUG BEGIN_STMT
  return str_2;

}



;; Function pfe_pe_get_fw_feature_entry (pfe_pe_get_fw_feature_entry, funcdef_no=64, decl_uid=11250, cgraph_uid=65, symbol_order=72)

Modification phase of node pfe_pe_get_fw_feature_entry/72
pfe_pe_get_fw_feature_entry (struct pfe_pe_t * pe, uint32_t id, struct pfe_ct_feature_desc_t * * entry)
{
  union pfe_ct_pe_mmap_t pfe_pe_mmap;
  errno_t ret;
  uint32_t entry_ptr;
  void * _1;
  long unsigned int _2;
  int _3;
  long unsigned int _4;
  long unsigned int _5;
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
  void * _26;
  unsigned int _27;
  unsigned int _28;
  long unsigned int _29;
  unsigned int _30;
  unsigned int _31;
  uint32_t * _32;
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
  struct pfe_ct_feature_desc_t * _43;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = pe_47(D)->fw_feature_section;
  if (_1 == 0B)
    goto <bb 12>; [18.75%]
  else
    goto <bb 3>; [81.25%]

  <bb 3> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  _2 = pe_47(D)->fw_features_base;
  if (_2 == 4294967295)
    goto <bb 5>; [20.24%]
  else
    goto <bb 10>; [79.76%]

  <bb 5> [local count: 176576843]:
  # DEBUG BEGIN_STMT
  pfe_pe_mmap = {};
  # DEBUG BEGIN_STMT
  _3 = pfe_pe_get_mmap (pe_47(D), &pfe_pe_mmap);
  if (_3 != 0)
    goto <bb 6>; [20.96%]
  else
    goto <bb 7>; [79.04%]

  <bb 6> [local count: 37010506]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get memory map\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 2139, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  pfe_pe_mmap ={v} {CLOBBER};
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 7> [local count: 139566337]:
  # DEBUG BEGIN_STMT
  _4 = pfe_pe_mmap.common.version.features;
  _5 = _4 >> 24;
  _6 = _4 >> 8;
  _7 = _6 & 65280;
  _8 = _5 | _7;
  _9 = _4 << 8;
  _10 = _9 & 16711680;
  _11 = _8 | _10;
  _12 = _4 << 24;
  _13 = _11 | _12;
  pe_47(D)->fw_features_base = _13;
  # DEBUG BEGIN_STMT
  _14 = pe_47(D)->fw_feature_section_size;
  if (_13 > _14)
    goto <bb 8>; [20.96%]
  else
    goto <bb 9>; [79.04%]

  <bb 8> [local count: 29253104]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid address of features record 0x%x\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 2148, _13, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pe_47(D)->fw_features_base = 4294967295;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 5
  pfe_pe_mmap ={v} {CLOBBER};
  # DEBUG ret => 5
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 9> [local count: 110313232]:
  # DEBUG BEGIN_STMT
  _15 = pfe_pe_mmap.common.version.features_count;
  _16 = _15 >> 24;
  _17 = _15 >> 8;
  _18 = _17 & 65280;
  _19 = _16 | _18;
  _20 = _15 << 8;
  _21 = _20 & 16711680;
  _22 = _19 | _21;
  _23 = _15 << 24;
  _24 = _22 | _23;
  pe_47(D)->fw_features_size = _24;
  # DEBUG ret => 0
  pfe_pe_mmap ={v} {CLOBBER};
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 806151622]:
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  _25 = pe_47(D)->fw_features_size;
  if (_25 > id_57(D))
    goto <bb 11>; [65.00%]
  else
    goto <bb 12>; [35.00%]

  <bb 11> [local count: 523998554]:
  # DEBUG BEGIN_STMT
  _26 = pe_47(D)->fw_feature_section;
  _27 = (unsigned int) _26;
  _28 = id_57(D) * 4;
  _29 = pe_47(D)->fw_features_base;
  _30 = _28 + _29;
  _31 = _27 + _30;
  _32 = (uint32_t *) _31;
  _33 = *_32;
  _34 = _33 >> 24;
  _35 = _33 >> 8;
  _36 = _35 & 65280;
  _37 = _34 | _36;
  _38 = _33 << 8;
  _39 = _38 & 16711680;
  _40 = _37 | _39;
  _41 = _33 << 24;
  entry_ptr_58 = _40 | _41;
  # DEBUG entry_ptr => entry_ptr_58
  # DEBUG BEGIN_STMT
  _42 = _27 + entry_ptr_58;
  _43 = (struct pfe_ct_feature_desc_t *) _42;
  *entry_59(D) = _43;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 12> [local count: 1073741824]:
  # ret_44 = PHI <2(2), 2(6), 0(11), 2(10), 5(8)>
  # DEBUG ret => ret_44
  # DEBUG BEGIN_STMT
  return ret_44;

}



;; Function pfe_pe_get_fw_messages_nolock (pfe_pe_get_fw_messages_nolock, funcdef_no=65, decl_uid=11273, cgraph_uid=66, symbol_order=73)

Modification phase of node pfe_pe_get_fw_messages_nolock/73
pfe_pe_get_fw_messages_nolock (struct pfe_pe_t * pe)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_pe_check_mmap (pfe_pe_check_mmap, funcdef_no=66, decl_uid=11271, cgraph_uid=67, symbol_order=74)

Modification phase of node pfe_pe_check_mmap/74
pfe_pe_check_mmap (const struct pfe_pe_t * pe)
{
  errno_t ret;
  union pfe_ct_pe_mmap_t pfe_pe_mmap;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_pe_get_mmap (pe_5(D), &pfe_pe_mmap);
  if (_1 != 0)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get memory map\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 2329, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2

  <bb 4> [local count: 1073741824]:
  # ret_2 = PHI <2(3), 0(2)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_pe_mmap ={v} {CLOBBER};
  return ret_2;

}



;; Function pfe_pe_get_pe_stats_nolock (pfe_pe_get_pe_stats_nolock, funcdef_no=67, decl_uid=11254, cgraph_uid=68, symbol_order=75)

Modification phase of node pfe_pe_get_pe_stats_nolock/75
pfe_pe_get_pe_stats_nolock (struct pfe_pe_t * pe, uint32_t addr, struct pfe_ct_pe_stats_t * stats)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 52);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_pe_check_stalled_nolock (pfe_pe_check_stalled_nolock, funcdef_no=68, decl_uid=11256, cgraph_uid=69, symbol_order=76)

Modification phase of node pfe_pe_check_stalled_nolock/76
pfe_pe_check_stalled_nolock (struct pfe_pe_t * pe)
{
  static const char * states[11] = {"UNINIT", "INIT", "FRAMEWAIT", "FRAMEPARSE", "FRAMECLASSIFY", "FRAMEDISCARD", "FRAMEMODIFY", "FRAMESEND", "STOPPED", "EXCEPTION", "FAIL_STOP"};
  bool_t ret;
  struct pfe_ct_pe_sw_state_monitor_t state_monitor;
  int _1;
  <unnamed type> _2;
  <unnamed type> _3;
  <unnamed type> _4;
  int _5;
  <unnamed type> _6;
  unsigned char _7;
  int _8;
  const char * _9;
  unsigned char _10;
  <unnamed type> _11;
  long unsigned int _12;
  long unsigned int _13;
  <unnamed type> _14;
  int _15;
  <unnamed type> _16;
  unsigned char _17;
  int _18;
  int _19;
  const char * _20;
  long unsigned int _21;
  <unnamed type> _22;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_pe_get_state_monitor_nolock (pe_30(D), &state_monitor);
  if (_1 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = state_monitor.state;
  if (_2 == 9)
    goto <bb 4>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 4> [local count: 182536110]:
  _3 = pe_30(D)->prev_state;
  if (_3 != 9)
    goto <bb 5>; [48.88%]
  else
    goto <bb 6>; [51.12%]

  <bb 5> [local count: 89223651]:
  # DEBUG BEGIN_STMT
  _4 = pe_30(D)->type;
  _5 = (int) _4;
  _6 = hm_types[_5];
  _7 = pe_30(D)->id;
  _8 = (int) _7;
  _9 = states[9];
  pfe_hm_report (_6, 2, 181, "[%s:%d] Core %d raised exception in state %s", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 2415, _8, _9, "");
  # DEBUG BEGIN_STMT
  Dem_SetEventStatus (55, 3);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1

  <bb 6> [local count: 536870913]:
  # ret_23 = PHI <0(3), 0(4), 1(5)>
  # DEBUG ret => ret_23
  # DEBUG BEGIN_STMT
  _10 = pe_30(D)->stalled;
  if (_10 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 7> [local count: 268435456]:
  _11 = state_monitor.state;
  if (_11 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 8> [local count: 134217728]:
  _12 = state_monitor.counter;
  _13 = pe_30(D)->counter;
  if (_12 == _13)
    goto <bb 9>; [20.24%]
  else
    goto <bb 10>; [79.76%]

  <bb 9> [local count: 27165668]:
  # DEBUG BEGIN_STMT
  _14 = pe_30(D)->type;
  _15 = (int) _14;
  _16 = hm_types[_15];
  _17 = pe_30(D)->id;
  _18 = (int) _17;
  _19 = (int) _11;
  _20 = states[_19];
  pfe_hm_report (_16, 2, 180, "[%s:%d] Core %d stalled in state %s", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 2424, _18, _20, "");
  # DEBUG BEGIN_STMT
  Dem_SetEventStatus (54, 3);
  # DEBUG BEGIN_STMT
  pe_30(D)->stalled = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1

  <bb 10> [local count: 536870913]:
  # ret_24 = PHI <ret_23(6), ret_23(7), ret_23(8), 1(9)>
  # DEBUG ret => ret_24
  # DEBUG BEGIN_STMT
  _21 = state_monitor.counter;
  pe_30(D)->counter = _21;
  # DEBUG BEGIN_STMT
  _22 = state_monitor.state;
  pe_30(D)->prev_state = _22;

  <bb 11> [local count: 1073741824]:
  # ret_25 = PHI <0(2), ret_24(10)>
  # DEBUG ret => ret_25
  # DEBUG BEGIN_STMT
  state_monitor ={v} {CLOBBER};
  return ret_25;

}



;; Function pfe_pe_get_classify_stats_nolock (pfe_pe_get_classify_stats_nolock, funcdef_no=69, decl_uid=11260, cgraph_uid=70, symbol_order=77)

Modification phase of node pfe_pe_get_classify_stats_nolock/77
pfe_pe_get_classify_stats_nolock (struct pfe_pe_t * pe, uint32_t addr, struct pfe_ct_classify_stats_t * stats)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 184);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_pe_get_class_algo_stats_nolock (pfe_pe_get_class_algo_stats_nolock, funcdef_no=70, decl_uid=11264, cgraph_uid=71, symbol_order=78)

Modification phase of node pfe_pe_get_class_algo_stats_nolock/78
pfe_pe_get_class_algo_stats_nolock (struct pfe_pe_t * pe, uint32_t addr, struct pfe_ct_class_algo_stats_t * stats)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_2(D), stats_3(D), addr_4(D), 16);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_pe_get_fw_state (pfe_pe_get_fw_state, funcdef_no=71, decl_uid=11266, cgraph_uid=72, symbol_order=79)

Modification phase of node pfe_pe_get_fw_state/79
pfe_pe_get_fw_state (struct pfe_pe_t * pe)
{
  struct pfe_ct_pe_sw_state_monitor_t state_monitor;
  int _1;
  pfe_ct_pe_sw_state_t _9;
  bool_t * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  state_monitor = {};
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 29
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (29);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  pfe_pe_lock_family (pe_5(D));
  # DEBUG BEGIN_STMT
  _1 = pfe_pe_get_state_monitor_nolock (pe_5(D), &state_monitor);
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  state_monitor.state = 0;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG pe => pe_5(D)
  # DEBUG INLINE_ENTRY pfe_pe_unlock_family
  # DEBUG BEGIN_STMT
  _11 = pe_5(D)->miflock;
  *_11 = 0;
  # DEBUG pe => NULL
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 29
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (29);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _9 = state_monitor.state;
  state_monitor ={v} {CLOBBER};
  return _9;

}



;; Function pfe_pe_get_data_nolock (pfe_pe_get_data_nolock, funcdef_no=72, decl_uid=11276, cgraph_uid=73, symbol_order=80)

Modification phase of node pfe_pe_get_data_nolock/80
pfe_pe_get_data_nolock (struct pfe_pe_t * pe, struct pfe_ct_buffer_t * buf)
{
  union pfe_ct_pe_mmap_t mmap_data;
  errno_t ret;
  uint8_t flags;
  int _1;
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
  unsigned char flags.25_13;
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

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  flags = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  mmap_data = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_pe_get_mmap (pe_40(D), &mmap_data);
  if (_1 != 0)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get memory map\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 2640, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  # DEBUG class_mmap_data => &mmap_data.class_pe
  # DEBUG BEGIN_STMT
  _2 = MEM[(const struct pfe_ct_class_mmap_t *)&mmap_data].put_buffer;
  if (_2 != 0)
    goto <bb 5>; [47.77%]
  else
    goto <bb 7>; [52.23%]

  <bb 5> [local count: 405417081]:
  # DEBUG BEGIN_STMT
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  _11 = _9 | _10;
  _12 = _11 + 65;
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), &flags, _12, 1);
  # DEBUG BEGIN_STMT
  flags.25_13 = flags;
  if (flags.25_13 != 0)
    goto <bb 6>; [47.77%]
  else
    goto <bb 7>; [52.23%]

  <bb 6> [local count: 193667740]:
  # DEBUG BEGIN_STMT
  _14 = MEM[(const struct pfe_ct_class_mmap_t *)&mmap_data].put_buffer;
  _15 = _14 >> 24;
  _16 = _14 >> 8;
  _17 = _16 & 65280;
  _18 = _15 | _17;
  _19 = _14 << 8;
  _20 = _19 & 16711680;
  _21 = _18 | _20;
  _22 = _14 << 24;
  _23 = _21 | _22;
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_40(D), buf_43(D), _23, 66);
  # DEBUG BEGIN_STMT
  flags = 0;
  # DEBUG BEGIN_STMT
  _24 = MEM[(const struct pfe_ct_class_mmap_t *)&mmap_data].put_buffer;
  _25 = _24 >> 24;
  _26 = _24 >> 8;
  _27 = _26 & 65280;
  _28 = _25 | _27;
  _29 = _24 << 8;
  _30 = _29 & 16711680;
  _31 = _28 | _30;
  _32 = _24 << 24;
  _33 = _31 | _32;
  _34 = _33 + 65;
  pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_40(D), _34, &flags, 1);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_35 = PHI <2(3), 2(4), 0(6), 118(5)>
  # DEBUG ret => ret_35
  # DEBUG BEGIN_STMT
  flags ={v} {CLOBBER};
  mmap_data ={v} {CLOBBER};
  return ret_35;

}



;; Function pfe_pe_put_data_nolock (pfe_pe_put_data_nolock, funcdef_no=73, decl_uid=11279, cgraph_uid=74, symbol_order=81)

Modification phase of node pfe_pe_put_data_nolock/81
pfe_pe_put_data_nolock (struct pfe_pe_t * pe, struct pfe_ct_buffer_t * buf)
{
  union pfe_ct_pe_mmap_t mmap_data;
  errno_t ret;
  uint8_t flags;
  int _1;
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
  unsigned char flags.26_13;
  unsigned char _14;
  unsigned char _15;
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

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  flags = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  mmap_data = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_pe_get_mmap (pe_31(D), &mmap_data);
  if (_1 != 0)
    goto <bb 3>; [20.96%]
  else
    goto <bb 4>; [79.04%]

  <bb 3> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get memory map\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_pe.c", 2695, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  # DEBUG class_mmap_data => &mmap_data.class_pe
  # DEBUG BEGIN_STMT
  _2 = MEM[(const struct pfe_ct_class_mmap_t *)&mmap_data].get_buffer;
  if (_2 != 0)
    goto <bb 5>; [47.77%]
  else
    goto <bb 7>; [52.23%]

  <bb 5> [local count: 405417081]:
  # DEBUG BEGIN_STMT
  _3 = _2 >> 24;
  _4 = _2 >> 8;
  _5 = _4 & 65280;
  _6 = _3 | _5;
  _7 = _2 << 8;
  _8 = _7 & 16711680;
  _9 = _6 | _8;
  _10 = _2 << 24;
  _11 = _9 | _10;
  _12 = _11 + 65;
  pfe_pe_memcpy_from_dmem_to_host_32_nolock (pe_31(D), &flags, _12, 1);
  # DEBUG BEGIN_STMT
  flags.26_13 = flags;
  if (flags.26_13 == 0)
    goto <bb 6>; [47.77%]
  else
    goto <bb 7>; [52.23%]

  <bb 6> [local count: 193667740]:
  # DEBUG BEGIN_STMT
  _14 = buf_34(D)->flags;
  _15 = _14 | 1;
  buf_34(D)->flags = _15;
  # DEBUG BEGIN_STMT
  _16 = MEM[(const struct pfe_ct_class_mmap_t *)&mmap_data].get_buffer;
  _17 = _16 >> 24;
  _18 = _16 >> 8;
  _19 = _18 & 65280;
  _20 = _17 | _19;
  _21 = _16 << 8;
  _22 = _21 & 16711680;
  _23 = _20 | _22;
  _24 = _16 << 24;
  _25 = _23 | _24;
  pfe_pe_memcpy_from_host_to_dmem_32_nolock (pe_31(D), _25, buf_34(D), 66);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_26 = PHI <2(3), 2(4), 0(6), 118(5)>
  # DEBUG ret => ret_26
  # DEBUG BEGIN_STMT
  flags ={v} {CLOBBER};
  mmap_data ={v} {CLOBBER};
  return ret_26;

}


