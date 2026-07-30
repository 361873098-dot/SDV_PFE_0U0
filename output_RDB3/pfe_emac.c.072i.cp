
IPA constant propagation start:
Determining dynamic type for call: _3 = pfe_emac_mac_hash_col (emac_1(D), addr_2(D));
  Starting walk at: _3 = pfe_emac_mac_hash_col (emac_1(D), addr_2(D));
  instance pointer: emac_1(D)  Outer instance pointer: emac_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_emac_mac_hash_col (emac_1(D), addr_2(D));
  Starting walk at: _3 = pfe_emac_mac_hash_col (emac_1(D), addr_2(D));
  instance pointer: addr_2(D)  Outer instance pointer: addr_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_emac_get_index (emac_9(D));
  Starting walk at: _1 = pfe_emac_get_index (emac_9(D));
  instance pointer: emac_9(D)  Outer instance pointer: emac_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_14 = pfe_emac_check_timer_ownership (emac_12(D), &has_owner, &drv_id_owner);
  Starting walk at: ret_14 = pfe_emac_check_timer_ownership (emac_12(D), &has_owner, &drv_id_owner);
  instance pointer: emac_12(D)  Outer instance pointer: emac_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (65);
  Function call may change dynamic type:platform_11 = pfe_platform_get_instance ();
Determining dynamic type for call: ret_14 = pfe_emac_check_timer_ownership (emac_12(D), &has_owner, &drv_id_owner);
  Starting walk at: ret_14 = pfe_emac_check_timer_ownership (emac_12(D), &has_owner, &drv_id_owner);
  instance pointer: &has_owner  Outer instance pointer: has_owner offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (65);
  Function call may change dynamic type:platform_11 = pfe_platform_get_instance ();
Determining dynamic type for call: ret_14 = pfe_emac_check_timer_ownership (emac_12(D), &has_owner, &drv_id_owner);
  Starting walk at: ret_14 = pfe_emac_check_timer_ownership (emac_12(D), &has_owner, &drv_id_owner);
  instance pointer: &drv_id_owner  Outer instance pointer: drv_id_owner offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (65);
  Function call may change dynamic type:platform_11 = pfe_platform_get_instance ();
Determining dynamic type for call: pfe_emac_disable (emac_14(D));
  Starting walk at: pfe_emac_disable (emac_14(D));
  instance pointer: emac_14(D)  Outer instance pointer: emac_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_emac_cfg_clear_hash_table (_9);
  Function call may change dynamic type:autolibc_memset (_1, 0, 116);
  Function call may change dynamic type:autolibc_memset (&zero_address, 0, 6);
  Function call may change dynamic type:pfe_emac_cfg_write_addr_slot (_2, &zero_address, slot_11);
Determining dynamic type for call: _1 = pfe_emac_is_broad (addr_22(D));
  Starting walk at: _1 = pfe_emac_is_broad (addr_22(D));
  instance pointer: addr_22(D)  Outer instance pointer: addr_22(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_emac_mac_slot_idx (emac_24(D), addr_22(D));
  Starting walk at: _3 = pfe_emac_mac_slot_idx (emac_24(D), addr_22(D));
  instance pointer: emac_24(D)  Outer instance pointer: emac_24(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_27 = pfe_mac_db_add_addr (_2, addr_22(D), owner_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (59);
Determining dynamic type for call: _3 = pfe_emac_mac_slot_idx (emac_24(D), addr_22(D));
  Starting walk at: _3 = pfe_emac_mac_slot_idx (emac_24(D), addr_22(D));
  instance pointer: addr_22(D)  Outer instance pointer: addr_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_27 = pfe_mac_db_add_addr (_2, addr_22(D), owner_25(D));
  Function call may change dynamic type:oal_mutex_lock.part.0 (59);
Determining dynamic type for call: _2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  Starting walk at: _2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  instance pointer: emac_10(D)  Outer instance pointer: emac_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_15 = pfe_mac_db_del_addr (_1, addr_12(D), owner_13(D));
Determining dynamic type for call: _2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  Starting walk at: _2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  instance pointer: addr_12(D)  Outer instance pointer: addr_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_15 = pfe_mac_db_del_addr (_1, addr_12(D), owner_13(D));
Determining dynamic type for call: slot_18 = pfe_emac_mac_slot_idx (emac_10(D), addr_12(D));
  Starting walk at: slot_18 = pfe_emac_mac_slot_idx (emac_10(D), addr_12(D));
  instance pointer: emac_10(D)  Outer instance pointer: emac_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  Function call may change dynamic type:ret_15 = pfe_mac_db_del_addr (_1, addr_12(D), owner_13(D));
Determining dynamic type for call: slot_18 = pfe_emac_mac_slot_idx (emac_10(D), addr_12(D));
  Starting walk at: slot_18 = pfe_emac_mac_slot_idx (emac_10(D), addr_12(D));
  instance pointer: addr_12(D)  Outer instance pointer: addr_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  Function call may change dynamic type:ret_15 = pfe_mac_db_del_addr (_1, addr_12(D), owner_13(D));
Determining dynamic type for call: pfe_emac_del_addr_nolock.part.0 (emac_10(D), addr_12(D));
  Starting walk at: pfe_emac_del_addr_nolock.part.0 (emac_10(D), addr_12(D));
  instance pointer: emac_10(D)  Outer instance pointer: emac_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:slot_18 = pfe_emac_mac_slot_idx (emac_10(D), addr_12(D));
  Function call may change dynamic type:_2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  Function call may change dynamic type:ret_15 = pfe_mac_db_del_addr (_1, addr_12(D), owner_13(D));
Determining dynamic type for call: pfe_emac_del_addr_nolock.part.0 (emac_10(D), addr_12(D));
  Starting walk at: pfe_emac_del_addr_nolock.part.0 (emac_10(D), addr_12(D));
  instance pointer: addr_12(D)  Outer instance pointer: addr_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:slot_18 = pfe_emac_mac_slot_idx (emac_10(D), addr_12(D));
  Function call may change dynamic type:_2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  Function call may change dynamic type:ret_15 = pfe_mac_db_del_addr (_1, addr_12(D), owner_13(D));
Determining dynamic type for call: ret_6 = pfe_emac_del_addr_nolock (emac_2(D), addr_3(D), owner_4(D));
  Starting walk at: ret_6 = pfe_emac_del_addr_nolock (emac_2(D), addr_3(D), owner_4(D));
  instance pointer: emac_2(D)  Outer instance pointer: emac_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (58);
Determining dynamic type for call: ret_6 = pfe_emac_del_addr_nolock (emac_2(D), addr_3(D), owner_4(D));
  Starting walk at: ret_6 = pfe_emac_del_addr_nolock (emac_2(D), addr_3(D), owner_4(D));
  instance pointer: addr_3(D)  Outer instance pointer: addr_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (58);
Determining dynamic type for call: ret_18 = pfe_emac_del_addr_nolock (emac_9(D), &entry.addr, _2);
  Starting walk at: ret_18 = pfe_emac_del_addr_nolock (emac_9(D), &entry.addr, _2);
  instance pointer: emac_9(D)  Outer instance pointer: emac_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_14 = pfe_mac_db_find_by_crit (_1, crit_10(D), type_11(D), owner_12(D), &entry);
  Function call may change dynamic type:oal_mutex_lock.part.0 (57);
  Function call may change dynamic type:ret_20 = pfe_mac_db_find_by_crit (_1, crit_10(D), type_11(D), owner_12(D), &entry);
  Function call may change dynamic type:ret_18 = pfe_emac_del_addr_nolock (emac_9(D), &entry.addr, _2);
Determining dynamic type for call: ret_18 = pfe_emac_del_addr_nolock (emac_9(D), &entry.addr, _2);
  Starting walk at: ret_18 = pfe_emac_del_addr_nolock (emac_9(D), &entry.addr, _2);
  instance pointer: &entry.addr  Outer instance pointer: entry offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_14 = pfe_mac_db_find_by_crit (_1, crit_10(D), type_11(D), owner_12(D), &entry);
  Function call may change dynamic type:oal_mutex_lock.part.0 (57);
  Function call may change dynamic type:ret_20 = pfe_mac_db_find_by_crit (_1, crit_10(D), type_11(D), owner_12(D), &entry);
  Function call may change dynamic type:ret_18 = pfe_emac_del_addr_nolock (emac_9(D), &entry.addr, _2);
Determining dynamic type for call: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  Starting walk at: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  instance pointer: emac_7(D)  Outer instance pointer: emac_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  Starting walk at: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  instance pointer: &is_owner  Outer instance pointer: is_owner offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  Starting walk at: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  instance pointer: emac_7(D)  Outer instance pointer: emac_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  Starting walk at: ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  instance pointer: &is_owner  Outer instance pointer: is_owner offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = pfe_emac_local_is_timer_owner (emac_9(D), &is_owner);
  Starting walk at: ret_11 = pfe_emac_local_is_timer_owner (emac_9(D), &is_owner);
  instance pointer: emac_9(D)  Outer instance pointer: emac_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_11 = pfe_emac_local_is_timer_owner (emac_9(D), &is_owner);
  Starting walk at: ret_11 = pfe_emac_local_is_timer_owner (emac_9(D), &is_owner);
  instance pointer: &is_owner  Outer instance pointer: is_owner offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_15 = pfe_emac_local_is_timer_owner (emac_13(D), &is_owner);
  Starting walk at: ret_15 = pfe_emac_local_is_timer_owner (emac_13(D), &is_owner);
  instance pointer: emac_13(D)  Outer instance pointer: emac_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_15 = pfe_emac_local_is_timer_owner (emac_13(D), &is_owner);
  Starting walk at: ret_15 = pfe_emac_local_is_timer_owner (emac_13(D), &is_owner);
  instance pointer: &is_owner  Outer instance pointer: is_owner offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_emac_disable (emac_17);
  Starting walk at: pfe_emac_disable (emac_17);
  instance pointer: emac_17  Outer instance pointer: &emac_instance[_5] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_emac_cfg_pre_init (_7);
  Function call may change dynamic type:pfe_mac_db_create (_6);
  Function call may change dynamic type:autolibc_memset (emac_17, 0, 176);
  Function call may change dynamic type:emac_index_16 = pfe_emac_cfg_get_index (_1, cbus_base_va_13(D));
Determining dynamic type for call: pfe_emac_create_configure (emac_17);
  Starting walk at: pfe_emac_create_configure (emac_17);
  instance pointer: emac_17  Outer instance pointer: &emac_instance[_5] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pfe_emac_cfg_init (_8, mode_30(D), speed_31(D), duplex_32(D));
  Function call may change dynamic type:pfe_emac_disable (emac_17);
  Function call may change dynamic type:pfe_emac_cfg_pre_init (_7);
  Function call may change dynamic type:pfe_mac_db_create (_6);
  Function call may change dynamic type:autolibc_memset (emac_17, 0, 176);
  Function call may change dynamic type:emac_index_16 = pfe_emac_cfg_get_index (_1, cbus_base_va_13(D));
Determining dynamic type for call: pfe_emac_disable_loopback (emac_2(D));
  Starting walk at: pfe_emac_disable_loopback (emac_2(D));
  instance pointer: emac_2(D)  Outer instance pointer: emac_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_emac_disable_promisc_mode (emac_2(D));
  Starting walk at: pfe_emac_disable_promisc_mode (emac_2(D));
  instance pointer: emac_2(D)  Outer instance pointer: emac_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_emac_disable_loopback (emac_2(D));
Determining dynamic type for call: pfe_emac_disable_broadcast (emac_2(D));
  Starting walk at: pfe_emac_disable_broadcast (emac_2(D));
  instance pointer: emac_2(D)  Outer instance pointer: emac_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_emac_disable_promisc_mode (emac_2(D));
  Function call may change dynamic type:pfe_emac_disable_loopback (emac_2(D));
Determining dynamic type for call: _4 = pfe_emac_mac_slot_idx (emac_13(D), &addr_temp);
  Starting walk at: _4 = pfe_emac_mac_slot_idx (emac_13(D), &addr_temp);
  instance pointer: emac_13(D)  Outer instance pointer: emac_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_18 = pfe_mac_db_get_first_addr (_3, 3, 3, 9, &addr_temp);
  Function call may change dynamic type:_2 = pfe_emac_cfg_get_hash (_1, addr_14(D));
  Function call may change dynamic type:ret_23 = pfe_mac_db_get_next_addr (_3, &addr_temp);
  Function call may change dynamic type:_4 = pfe_emac_mac_slot_idx (emac_13(D), &addr_temp);
  Function call may change dynamic type:hash_temp_21 = pfe_emac_cfg_get_hash (_5, &addr_temp);
Determining dynamic type for call: _4 = pfe_emac_mac_slot_idx (emac_13(D), &addr_temp);
  Starting walk at: _4 = pfe_emac_mac_slot_idx (emac_13(D), &addr_temp);
  instance pointer: &addr_temp  Outer instance pointer: addr_temp offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_18 = pfe_mac_db_get_first_addr (_3, 3, 3, 9, &addr_temp);
  Function call may change dynamic type:_2 = pfe_emac_cfg_get_hash (_1, addr_14(D));
  Function call may change dynamic type:ret_23 = pfe_mac_db_get_next_addr (_3, &addr_temp);
  Function call may change dynamic type:_4 = pfe_emac_mac_slot_idx (emac_13(D), &addr_temp);
  Function call may change dynamic type:hash_temp_21 = pfe_emac_cfg_get_hash (_5, &addr_temp);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_emac_local_is_timer_owner.part.0/359:
  Jump functions of caller  pfe_emac_check_timer_ownership.part.0/351:
  Jump functions of caller  pfe_emac_del_addr_nolock.part.0/341:
    callsite  pfe_emac_del_addr_nolock.part.0/341 -> pfe_emac_mac_hash_col/19 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  oal_mutex_unlock.part.0/340:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/339:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  pfe_emac_cfg_pps0_configure/338:
  Jump functions of caller  pfe_emac_cfg_pps0_set_pulse_width/337:
  Jump functions of caller  pfe_emac_cfg_pps0_set_period/336:
  Jump functions of caller  pfe_hif_chnl_get_emac_timer_ownership/335:
  Jump functions of caller  pfe_hif_chnl_set_emac_timer_ownership/334:
  Jump functions of caller  pfe_platform_get_instance/333:
  Jump functions of caller  pfe_emac_cfg_isr/332:
  Jump functions of caller  pfe_emac_cfg_get_stat_value/331:
  Jump functions of caller  pfe_emac_cfg_get_tx_cnt/330:
  Jump functions of caller  pfe_emac_cfg_get_rx_cnt/329:
  Jump functions of caller  pfe_emac_cfg_mdio_write45/328:
  Jump functions of caller  pfe_emac_cfg_mdio_read45/327:
  Jump functions of caller  pfe_emac_cfg_mdio_write22/326:
  Jump functions of caller  pfe_emac_cfg_mdio_read22/325:
  Jump functions of caller  pfe_emac_cfg_disable_ts/324:
  Jump functions of caller  pfe_emac_cfg_clear_hash_table/323:
  Jump functions of caller  pfe_mac_db_add_addr/322:
  Jump functions of caller  pfe_emac_cfg_read_addr_slot/321:
  Jump functions of caller  pfe_mac_db_get_next_addr/320:
  Jump functions of caller  autolibc_memcmp/319:
  Jump functions of caller  pfe_mac_db_get_first_addr/318:
  Jump functions of caller  pfe_emac_cfg_set_hash_group/317:
  Jump functions of caller  pfe_emac_cfg_get_hash/316:
  Jump functions of caller  pfe_emac_cfg_write_addr_slot/315:
  Jump functions of caller  pfe_mac_db_del_addr/314:
  Jump functions of caller  pfe_mac_db_find_by_crit/313:
  Jump functions of caller  pfe_emac_cfg_set_duplex/312:
  Jump functions of caller  pfe_emac_cfg_set_speed/311:
  Jump functions of caller  pfe_emac_cfg_get_link_status/310:
  Jump functions of caller  pfe_emac_cfg_get_link_config/309:
  Jump functions of caller  pfe_emac_cfg_set_max_frame_length/308:
  Jump functions of caller  pfe_emac_cfg_set_rx_flow_control/307:
  Jump functions of caller  pfe_emac_cfg_set_tx_flow_control/306:
  Jump functions of caller  pfe_emac_cfg_get_rx_flow_control/305:
  Jump functions of caller  pfe_emac_cfg_get_tx_flow_control/304:
  Jump functions of caller  pfe_emac_cfg_set_broadcast/303:
  Jump functions of caller  pfe_emac_cfg_set_allmulti_mode/302:
  Jump functions of caller  pfe_emac_cfg_set_promisc_mode/301:
  Jump functions of caller  pfe_emac_cfg_set_loopback/300:
  Jump functions of caller  pfe_emac_cfg_set_ts_time/299:
  Jump functions of caller  pfe_emac_cfg_adjust_ts_time/298:
  Jump functions of caller  pfe_emac_cfg_get_ts_time/297:
  Jump functions of caller  pfe_emac_cfg_adjust_ts_freq/296:
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
  Jump functions of caller  pfe_emac_cfg_enable_ts/85:
  Jump functions of caller  pfe_emac_cfg_set_enable/84:
  Jump functions of caller  pfe_emac_cfg_init/83:
  Jump functions of caller  pfe_emac_cfg_pre_init/82:
  Jump functions of caller  pfe_mac_db_create/81:
  Jump functions of caller  autolibc_memset/80:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/79:
  Jump functions of caller  pfe_hm_report/78:
  Jump functions of caller  __builtin_expect/77:
  Jump functions of caller  pfe_emac_cfg_get_index/76:
  Jump functions of caller  pfe_emac_pps0_configure/75:
    callsite  pfe_emac_pps0_configure/75 -> pfe_emac_get_index/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_local_is_timer_owner/74:
    callsite  pfe_emac_local_is_timer_owner/74 -> pfe_emac_local_is_timer_owner.part.0/359 : 
  Jump functions of caller  pfe_emac_clear_timer_ownership/73:
    callsite  pfe_emac_clear_timer_ownership/73 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 66
         value: 0x42, mask: 0x0
         Unknown VR
    callsite  pfe_emac_clear_timer_ownership/73 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 66
         value: 0x42, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_emac_check_timer_ownership/72:
    callsite  pfe_emac_check_timer_ownership/72 -> pfe_emac_check_timer_ownership.part.0/351 : 
  Jump functions of caller  pfe_emac_set_timer_ownership/71:
    callsite  pfe_emac_set_timer_ownership/71 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 65
         value: 0x41, mask: 0x0
         Unknown VR
    callsite  pfe_emac_set_timer_ownership/71 -> pfe_emac_check_timer_ownership/72 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_emac_set_timer_ownership/71 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 65
         value: 0x41, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_emac_irq_unmask/70:
  Jump functions of caller  pfe_emac_irq_mask/69:
  Jump functions of caller  pfe_emac_isr/68:
  Jump functions of caller  pfe_emac_get_stat_value/67:
  Jump functions of caller  pfe_emac_get_tx_cnt/66:
  Jump functions of caller  pfe_emac_get_rx_cnt/65:
  Jump functions of caller  pfe_emac_mdio_write45/64:
  Jump functions of caller  pfe_emac_mdio_read45/63:
  Jump functions of caller  pfe_emac_mdio_write22/62:
  Jump functions of caller  pfe_emac_mdio_read22/61:
  Jump functions of caller  pfe_emac_mdio_unlock/60:
  Jump functions of caller  pfe_emac_mdio_lock/59:
    callsite  pfe_emac_mdio_lock/59 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 60
         value: 0x3c, mask: 0x0
         Unknown VR
    callsite  pfe_emac_mdio_lock/59 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 60
         value: 0x3c, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_emac_destroy/58:
    callsite  pfe_emac_destroy/58 -> pfe_emac_disable/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_add_addr/57:
    callsite  pfe_emac_add_addr/57 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 59
         value: 0x3b, mask: 0x0
         Unknown VR
    callsite  pfe_emac_add_addr/57 -> pfe_emac_mac_slot_idx/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_add_addr/57 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 59
         value: 0x3b, mask: 0x0
         Unknown VR
    callsite  pfe_emac_add_addr/57 -> pfe_emac_is_broad/6 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_del_addr_nolock/56:
    callsite  pfe_emac_del_addr_nolock/56 -> pfe_emac_del_addr_nolock.part.0/341 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_del_addr_nolock/56 -> pfe_emac_mac_slot_idx/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_del_addr_nolock/56 -> pfe_emac_mac_in_db/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_del_addr/55:
    callsite  pfe_emac_del_addr/55 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 58
         value: 0x3a, mask: 0x0
         Unknown VR
    callsite  pfe_emac_del_addr/55 -> pfe_emac_del_addr_nolock/56 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_emac_del_addr/55 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 58
         value: 0x3a, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_emac_flush_mac_addrs/54:
    callsite  pfe_emac_flush_mac_addrs/54 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 57
         value: 0x39, mask: 0x0
         Unknown VR
    callsite  pfe_emac_flush_mac_addrs/54 -> pfe_emac_del_addr_nolock/56 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pfe_emac_flush_mac_addrs/54 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 57
         value: 0x39, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_emac_set_link_duplex/53:
  Jump functions of caller  pfe_emac_set_link_speed/52:
  Jump functions of caller  pfe_emac_get_link_status/51:
  Jump functions of caller  pfe_emac_get_link_config/50:
  Jump functions of caller  pfe_emac_get_mii_mode/49:
  Jump functions of caller  pfe_emac_set_max_frame_length/48:
  Jump functions of caller  pfe_emac_disable_rx_flow_control/47:
  Jump functions of caller  pfe_emac_enable_rx_flow_control/46:
  Jump functions of caller  pfe_emac_disable_tx_flow_control/45:
  Jump functions of caller  pfe_emac_enable_tx_flow_control/44:
  Jump functions of caller  pfe_emac_get_flow_control/43:
  Jump functions of caller  pfe_emac_disable_broadcast/42:
  Jump functions of caller  pfe_emac_enable_broadcast/41:
  Jump functions of caller  pfe_emac_disable_allmulti_mode/40:
  Jump functions of caller  pfe_emac_enable_allmulti_mode/39:
  Jump functions of caller  pfe_emac_disable_promisc_mode/38:
  Jump functions of caller  pfe_emac_enable_promisc_mode/37:
  Jump functions of caller  pfe_emac_disable_loopback/36:
  Jump functions of caller  pfe_emac_enable_loopback/35:
  Jump functions of caller  pfe_emac_set_ts_time/34:
    callsite  pfe_emac_set_ts_time/34 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 64
         value: 0x40, mask: 0x0
         Unknown VR
    callsite  pfe_emac_set_ts_time/34 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 64
         value: 0x40, mask: 0x0
         Unknown VR
    callsite  pfe_emac_set_ts_time/34 -> pfe_emac_local_is_timer_owner/74 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_emac_adjust_ts_time/33:
    callsite  pfe_emac_adjust_ts_time/33 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 63
         value: 0x3f, mask: 0x0
         Unknown VR
    callsite  pfe_emac_adjust_ts_time/33 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 63
         value: 0x3f, mask: 0x0
         Unknown VR
    callsite  pfe_emac_adjust_ts_time/33 -> pfe_emac_local_is_timer_owner/74 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_emac_get_ts_time/32:
  Jump functions of caller  pfe_emac_get_ts_freq_adjustment/31:
  Jump functions of caller  pfe_emac_set_ts_freq_adjustment/30:
    callsite  pfe_emac_set_ts_freq_adjustment/30 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 62
         value: 0x3e, mask: 0x0
         Unknown VR
    callsite  pfe_emac_set_ts_freq_adjustment/30 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 62
         value: 0x3e, mask: 0x0
         Unknown VR
    callsite  pfe_emac_set_ts_freq_adjustment/30 -> pfe_emac_local_is_timer_owner/74 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_emac_enable_ts/29:
    callsite  pfe_emac_enable_ts/29 -> oal_mutex_unlock.part.0/340 : 
       param 0: CONST: 61
         value: 0x3d, mask: 0x0
         Unknown VR
    callsite  pfe_emac_enable_ts/29 -> oal_mutex_lock.part.0/339 : 
       param 0: CONST: 61
         value: 0x3d, mask: 0x0
         Unknown VR
    callsite  pfe_emac_enable_ts/29 -> pfe_emac_local_is_timer_owner/74 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  pfe_emac_disable/28:
  Jump functions of caller  pfe_emac_enable/27:
  Jump functions of caller  pfe_emac_get_gpi/26:
  Jump functions of caller  pfe_emac_bind_gpi/25:
  Jump functions of caller  pfe_emac_get_index/24:
  Jump functions of caller  pfe_emac_create/23:
    callsite  pfe_emac_create/23 -> pfe_emac_create_configure/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  pfe_emac_create/23 -> pfe_emac_disable/28 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_emac_create_configure/22:
    callsite  pfe_emac_create_configure/22 -> pfe_emac_disable_broadcast/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_create_configure/22 -> pfe_emac_disable_promisc_mode/38 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_emac_create_configure/22 -> pfe_emac_disable_loopback/36 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_mac_in_db/21:
  Jump functions of caller  pfe_emac_mac_slot_idx/20:
  Jump functions of caller  pfe_emac_mac_hash_col/19:
    callsite  pfe_emac_mac_hash_col/19 -> pfe_emac_mac_slot_idx/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_emac_is_broad/6:

 Propagating constants:

Not considering pfe_emac_pps0_configure for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_local_is_timer_owner for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_clear_timer_ownership for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_check_timer_ownership for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_set_timer_ownership for cloning; -fipa-cp-clone disabled.
Function pfe_emac_irq_unmask/70 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_emac_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_isr for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_stat_value for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_tx_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_rx_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_mdio_write45 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_mdio_read45 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_mdio_write22 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_mdio_read22 for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_mdio_unlock for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_mdio_lock for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_add_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_del_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_flush_mac_addrs for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_set_link_duplex for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_set_link_speed for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_link_status for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_link_config for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_mii_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_set_max_frame_length for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_disable_rx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable_rx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_disable_tx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable_tx_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_flow_control for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_disable_broadcast for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable_broadcast for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_disable_allmulti_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable_allmulti_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_disable_promisc_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable_promisc_mode for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_disable_loopback for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable_loopback for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_set_ts_time for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_adjust_ts_time for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_ts_time for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_ts_freq_adjustment for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_set_ts_freq_adjustment for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable_ts for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_gpi for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_bind_gpi for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_get_index for cloning; -fipa-cp-clone disabled.
Not considering pfe_emac_create for cloning; -fipa-cp-clone disabled.

overall_size: 1061, max_new_size: 11001
 - context independent values, size: 2, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: pfe_emac_local_is_timer_owner.part.0/359:
  Node: pfe_emac_check_timer_ownership.part.0/351:
  Node: pfe_emac_del_addr_nolock.part.0/341:
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
  Node: oal_mutex_unlock.part.0/340:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x42, mask = 0x7f
         const oal_mutex_t [57, 66]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/339:
    param [0]: BOTTOM
         ctxs: VARIABLE
         Bits: value = 0x42, mask = 0x7f
         const oal_mutex_t [57, 66]
        AGGS VARIABLE
  Node: pfe_emac_pps0_configure/75:
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
  Node: pfe_emac_local_is_timer_owner/74:
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
  Node: pfe_emac_clear_timer_ownership/73:
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
  Node: pfe_emac_check_timer_ownership/72:
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
  Node: pfe_emac_set_timer_ownership/71:
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
  Node: pfe_emac_irq_unmask/70:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_irq_mask/69:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_isr/68:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_get_stat_value/67:
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
  Node: pfe_emac_get_tx_cnt/66:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_get_rx_cnt/65:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_mdio_write45/64:
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
  Node: pfe_emac_mdio_read45/63:
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
  Node: pfe_emac_mdio_write22/62:
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
  Node: pfe_emac_mdio_read22/61:
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
  Node: pfe_emac_mdio_unlock/60:
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
  Node: pfe_emac_mdio_lock/59:
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
  Node: pfe_emac_destroy/58:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_add_addr/57:
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
  Node: pfe_emac_del_addr_nolock/56:
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
  Node: pfe_emac_del_addr/55:
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
  Node: pfe_emac_flush_mac_addrs/54:
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
  Node: pfe_emac_set_link_duplex/53:
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
  Node: pfe_emac_set_link_speed/52:
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
  Node: pfe_emac_get_link_status/51:
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
  Node: pfe_emac_get_link_config/50:
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
  Node: pfe_emac_get_mii_mode/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_set_max_frame_length/48:
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
  Node: pfe_emac_disable_rx_flow_control/47:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_enable_rx_flow_control/46:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_disable_tx_flow_control/45:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_enable_tx_flow_control/44:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_get_flow_control/43:
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
  Node: pfe_emac_disable_broadcast/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_enable_broadcast/41:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_disable_allmulti_mode/40:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_enable_allmulti_mode/39:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_disable_promisc_mode/38:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_enable_promisc_mode/37:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_disable_loopback/36:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_enable_loopback/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_set_ts_time/34:
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
  Node: pfe_emac_adjust_ts_time/33:
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
  Node: pfe_emac_get_ts_time/32:
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
  Node: pfe_emac_get_ts_freq_adjustment/31:
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
  Node: pfe_emac_set_ts_freq_adjustment/30:
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
  Node: pfe_emac_enable_ts/29:
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
  Node: pfe_emac_disable/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_enable/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_get_gpi/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_bind_gpi/25:
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
  Node: pfe_emac_get_index/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_emac_create/23:
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
  Node: pfe_emac_create_configure/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_emac_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_emac_mac_in_db/21:
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
  Node: pfe_emac_mac_slot_idx/20:
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
  Node: pfe_emac_mac_hash_col/19:
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
  Node: pfe_emac_is_broad/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function oal_mutex_unlock.part.0/340:
 param 0: value = 0x42, mask = 0x7f
Propagated bits info for function oal_mutex_lock.part.0/339:
 param 0: value = 0x42, mask = 0x7f
Propagated bits info for function pfe_emac_create_configure/22:
 param 0: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_emac_local_is_timer_owner.part.0/359 (pfe_emac_local_is_timer_owner.part.0) @07674d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_emac_local_is_timer_owner/74 (201326592 (estimated locally),0.19 per call) 
  Calls: pfe_hm_report/78 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/79 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_check_timer_ownership.part.0/351 (pfe_emac_check_timer_ownership.part.0) @07244380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_emac_check_timer_ownership/72 (21246073 (estimated locally),0.10 per call) 
  Calls: pfe_hm_report/78 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/79 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_del_addr_nolock.part.0/341 (pfe_emac_del_addr_nolock.part.0) @06e971c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_emac_del_addr_nolock/56 (58465243 (estimated locally),0.05 per call) 
  Calls: pfe_emac_mac_hash_col/19 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_get_hash/316 (354334802 (estimated locally),0.33 per call) pfe_emac_cfg_set_hash_group/317 (354334802 (estimated locally),0.33 per call) 
oal_mutex_unlock.part.0/340 (oal_mutex_unlock.part.0) @06e93ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_emac_set_ts_time/34 (223547679 (estimated locally),0.21 per call) pfe_emac_adjust_ts_time/33 (223547679 (estimated locally),0.21 per call) pfe_emac_set_ts_freq_adjustment/30 (223547679 (estimated locally),0.21 per call) pfe_emac_enable_ts/29 (192154432 (estimated locally),0.18 per call) pfe_emac_clear_timer_ownership/73 (872415233 (estimated locally),0.81 per call) pfe_emac_set_timer_ownership/71 (872415233 (estimated locally),0.81 per call) pfe_emac_mdio_lock/59 (1073741824 (estimated locally),1.00 per call) pfe_emac_add_addr/57 (697932186 (estimated locally),0.65 per call) pfe_emac_del_addr/55 (1073741824 (estimated locally),1.00 per call) pfe_emac_flush_mac_addrs/54 (59055800 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/339 (oal_mutex_lock.part.0) @06e2fd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_emac_set_ts_time/34 (223547679 (estimated locally),0.21 per call) pfe_emac_adjust_ts_time/33 (223547679 (estimated locally),0.21 per call) pfe_emac_set_ts_freq_adjustment/30 (223547679 (estimated locally),0.21 per call) pfe_emac_enable_ts/29 (192154432 (estimated locally),0.18 per call) pfe_emac_clear_timer_ownership/73 (872415233 (estimated locally),0.81 per call) pfe_emac_set_timer_ownership/71 (872415233 (estimated locally),0.81 per call) pfe_emac_mdio_lock/59 (1073741824 (estimated locally),1.00 per call) pfe_emac_add_addr/57 (697932186 (estimated locally),0.65 per call) pfe_emac_del_addr/55 (1073741824 (estimated locally),1.00 per call) pfe_emac_flush_mac_addrs/54 (59055801 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
pfe_emac_cfg_pps0_configure/338 (pfe_emac_cfg_pps0_configure) @078adee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_pps0_configure/75 (424342769 (estimated locally),0.40 per call) pfe_emac_pps0_configure/75 (424342769 (estimated locally),0.40 per call) 
  Calls: 
pfe_emac_cfg_pps0_set_pulse_width/337 (pfe_emac_cfg_pps0_set_pulse_width) @078ade00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_pps0_configure/75 (424342769 (estimated locally),0.40 per call) 
  Calls: 
pfe_emac_cfg_pps0_set_period/336 (pfe_emac_cfg_pps0_set_period) @078add20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_pps0_configure/75 (424342769 (estimated locally),0.40 per call) 
  Calls: 
pfe_hif_chnl_get_emac_timer_ownership/335 (pfe_hif_chnl_get_emac_timer_ownership) @078ad9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_local_is_timer_owner/74 (872415233 (estimated locally),0.81 per call) pfe_emac_clear_timer_ownership/73 (872415233 (estimated locally),0.81 per call) pfe_emac_check_timer_ownership/72 (607400719 (estimated locally),2.92 per call) 
  Calls: 
pfe_hif_chnl_set_emac_timer_ownership/334 (pfe_hif_chnl_set_emac_timer_ownership) @078ad700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_clear_timer_ownership/73 (176576843 (estimated locally),0.16 per call) pfe_emac_set_timer_ownership/71 (143948513 (estimated locally),0.13 per call) 
  Calls: 
pfe_platform_get_instance/333 (pfe_platform_get_instance) @078ad620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_local_is_timer_owner/74 (1073741824 (estimated locally),1.00 per call) pfe_emac_clear_timer_ownership/73 (1073741824 (estimated locally),1.00 per call) pfe_emac_set_timer_ownership/71 (1073741824 (estimated locally),1.00 per call) pfe_emac_check_timer_ownership/72 (208090819 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_isr/332 (pfe_emac_cfg_isr) @078ad2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_isr/68 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_stat_value/331 (pfe_emac_cfg_get_stat_value) @078ad0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_stat_value/67 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_tx_cnt/330 (pfe_emac_cfg_get_tx_cnt) @0789eee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_tx_cnt/66 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_rx_cnt/329 (pfe_emac_cfg_get_rx_cnt) @0789ed20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_rx_cnt/65 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_mdio_write45/328 (pfe_emac_cfg_mdio_write45) @0789eb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mdio_write45/64 (524845004 (estimated locally),0.49 per call) pfe_emac_mdio_write45/64 (175811651 (estimated locally),0.16 per call) 
  Calls: 
pfe_emac_cfg_mdio_read45/327 (pfe_emac_cfg_mdio_read45) @0789e9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mdio_read45/63 (524845004 (estimated locally),0.49 per call) pfe_emac_mdio_read45/63 (175811651 (estimated locally),0.16 per call) 
  Calls: 
pfe_emac_cfg_mdio_write22/326 (pfe_emac_cfg_mdio_write22) @0789e7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mdio_write22/62 (524845004 (estimated locally),0.49 per call) pfe_emac_mdio_write22/62 (175811651 (estimated locally),0.16 per call) 
  Calls: 
pfe_emac_cfg_mdio_read22/325 (pfe_emac_cfg_mdio_read22) @0789e620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mdio_read22/61 (524845004 (estimated locally),0.49 per call) pfe_emac_mdio_read22/61 (175811651 (estimated locally),0.16 per call) 
  Calls: 
pfe_emac_cfg_disable_ts/324 (pfe_emac_cfg_disable_ts) @0789e2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_destroy/58 (119292717 (estimated locally),0.53 per call) 
  Calls: 
pfe_emac_cfg_clear_hash_table/323 (pfe_emac_cfg_clear_hash_table) @0789e1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_destroy/58 (119292717 (estimated locally),0.53 per call) 
  Calls: 
pfe_mac_db_add_addr/322 (pfe_mac_db_add_addr) @0788eee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_add_addr/57 (697932186 (estimated locally),0.65 per call) 
  Calls: 
pfe_emac_cfg_read_addr_slot/321 (pfe_emac_cfg_read_addr_slot) @0788eb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mac_slot_idx/20 (314968206 (estimated locally),2.31 per call) 
  Calls: 
pfe_mac_db_get_next_addr/320 (pfe_mac_db_get_next_addr) @0788e9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mac_hash_col/19 (995711397 (estimated locally),12.76 per call) pfe_emac_mac_in_db/21 (958878293 (estimated locally),8.35 per call) 
  Calls: 
autolibc_memcmp/319 (autolibc_memcmp) @0788e8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mac_slot_idx/20 (314968206 (estimated locally),2.31 per call) pfe_emac_mac_in_db/21 (1014686025 (estimated locally),8.83 per call) 
  Calls: 
pfe_mac_db_get_first_addr/318 (pfe_mac_db_get_first_addr) @0788e7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_mac_hash_col/19 (78030430 (estimated locally),1.00 per call) pfe_emac_mac_in_db/21 (114863532 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_hash_group/317 (pfe_emac_cfg_set_hash_group) @0788e620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_add_addr/57 (26624717 (estimated locally),0.02 per call) pfe_emac_del_addr_nolock.part.0/341 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_emac_cfg_get_hash/316 (pfe_emac_cfg_get_hash) @0788e540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_add_addr/57 (26624717 (estimated locally),0.02 per call) pfe_emac_del_addr_nolock.part.0/341 (354334802 (estimated locally),0.33 per call) pfe_emac_mac_hash_col/19 (344993248 (estimated locally),4.42 per call) pfe_emac_mac_hash_col/19 (78030430 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_write_addr_slot/315 (pfe_emac_cfg_write_addr_slot) @0788e460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_destroy/58 (954449108 (estimated locally),4.28 per call) pfe_emac_add_addr/57 (51683274 (estimated locally),0.05 per call) pfe_emac_del_addr_nolock/56 (58465242 (estimated locally),0.05 per call) 
  Calls: 
pfe_mac_db_del_addr/314 (pfe_mac_db_del_addr) @0788e380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_del_addr_nolock/56 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_mac_db_find_by_crit/313 (pfe_mac_db_find_by_crit) @0788e1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_flush_mac_addrs/54 (55807731 (estimated locally),0.94 per call) pfe_emac_flush_mac_addrs/54 (59055801 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_duplex/312 (pfe_emac_cfg_set_duplex) @0788e000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_set_link_duplex/53 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_speed/311 (pfe_emac_cfg_set_speed) @07887e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_set_link_speed/52 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_link_status/310 (pfe_emac_cfg_get_link_status) @07887c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_link_status/51 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_link_config/309 (pfe_emac_cfg_get_link_config) @07887a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_link_config/50 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_max_frame_length/308 (pfe_emac_cfg_set_max_frame_length) @078877e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_set_max_frame_length/48 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_rx_flow_control/307 (pfe_emac_cfg_set_rx_flow_control) @07887540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_disable_rx_flow_control/47 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_rx_flow_control/46 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_tx_flow_control/306 (pfe_emac_cfg_set_tx_flow_control) @078872a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_disable_tx_flow_control/45 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_tx_flow_control/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_rx_flow_control/305 (pfe_emac_cfg_get_rx_flow_control) @078870e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_flow_control/43 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_tx_flow_control/304 (pfe_emac_cfg_get_tx_flow_control) @07887000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_flow_control/43 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_broadcast/303 (pfe_emac_cfg_set_broadcast) @0787dd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_disable_broadcast/42 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_broadcast/41 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_allmulti_mode/302 (pfe_emac_cfg_set_allmulti_mode) @0787da80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_disable_allmulti_mode/40 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_allmulti_mode/39 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_promisc_mode/301 (pfe_emac_cfg_set_promisc_mode) @0787d7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_disable_promisc_mode/38 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_promisc_mode/37 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_loopback/300 (pfe_emac_cfg_set_loopback) @0787d540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_disable_loopback/36 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_loopback/35 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_set_ts_time/299 (pfe_emac_cfg_set_ts_time) @0787d380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_set_ts_time/34 (223547679 (estimated locally),0.21 per call) 
  Calls: 
pfe_emac_cfg_adjust_ts_time/298 (pfe_emac_cfg_adjust_ts_time) @0787d1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_adjust_ts_time/33 (223547679 (estimated locally),0.21 per call) 
  Calls: 
pfe_emac_cfg_get_ts_time/297 (pfe_emac_cfg_get_ts_time) @0787d000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_get_ts_time/32 (482647369 (estimated locally),0.45 per call) 
  Calls: 
pfe_emac_cfg_adjust_ts_freq/296 (pfe_emac_cfg_adjust_ts_freq) @0787ad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_set_ts_freq_adjustment/30 (223547679 (estimated locally),0.21 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/295 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0787ab60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/294 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0787aa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/293 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0787a9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/292 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @0787a8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/291 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @0787a7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/290 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @0787a700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/289 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @0787a620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/288 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @0787a540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/287 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @0787a460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/286 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @0787a380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/285 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @0787a2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/284 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @0787a1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/283 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @0787a0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/282 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @0787a000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/281 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @07877ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/280 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07877e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/279 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07877d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/278 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07877c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/277 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07877b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/276 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07877a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/275 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @078779a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/274 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @078778c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/273 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @078777e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/272 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @07877700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/271 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @07877620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/270 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07877540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/269 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07877460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/268 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07877380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/267 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @078772a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/266 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @078771c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/265 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @078770e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/264 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @07877000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/263 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @07876ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/262 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07876e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/261 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @07876d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/260 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @07876c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/259 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @07876b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/258 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @07876a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/257 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @078769a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/256 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @078768c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/255 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @078767e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/254 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @07876700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/253 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @07876620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/252 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @07876540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/251 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @07876460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/250 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @07876380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/249 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @078762a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/248 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @078761c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/247 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @078760e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/246 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @07876000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/245 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @07875ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/244 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @07875e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/243 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @07875d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/242 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @07875c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/241 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @07875b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/240 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @07875a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/239 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @078759a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/238 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @078758c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/237 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @078757e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/236 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @07875700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/235 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @07875620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/234 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @07875540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/233 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @07875460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/232 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @07875380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/231 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @078752a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/230 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @078751c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/229 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @078750e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/228 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @07875000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/227 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @07874ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/226 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @07874e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/225 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @07874d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/224 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @07874c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/223 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @07874b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/222 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @07874a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/221 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @078749a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/220 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @078748c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/219 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @078747e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/218 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @07874700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/217 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @07874620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/216 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @07874540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/215 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @07874460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/214 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @07874380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/213 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @078742a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/212 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @078741c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/211 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @078740e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/210 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @07874000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/209 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @07873460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/208 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @07873ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/207 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @07873e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/206 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @07873d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/205 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @07873c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/204 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @07873b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/203 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @07873a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/202 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @078739a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/201 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @078738c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/200 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @078737e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/199 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @07873700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/198 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @07873620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/197 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @07873540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/196 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @07873380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/195 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @078732a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/194 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @078731c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/193 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @078730e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/192 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @07873000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/191 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @07871ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/190 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @07871d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/189 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @07871c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/188 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @07871b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/187 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @07871a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/186 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @078719a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/185 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @078718c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/184 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @078717e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/183 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @07871700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/182 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @07871620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/181 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @07871540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/180 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @07871460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/179 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @07871380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/178 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @078712a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/177 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @078711c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/176 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @078710e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/175 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @07871000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/174 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @07870ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/173 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @07870e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/172 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @07870d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/171 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @07870c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/170 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @07870b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/169 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @07870a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/168 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @078709a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/167 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @078708c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/166 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @078707e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/165 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @07870700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/164 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @07870620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/163 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @07870540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/162 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @07870460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/161 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @07870380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/160 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @078702a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/159 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @078701c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/158 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @078700e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/157 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @07870000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/156 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @0786fee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/155 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @0786fe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/154 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @0786fd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/153 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @0786fc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/152 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @0786fb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/151 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @0786fa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/150 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @0786f9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/149 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @0786f8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/148 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @0786f7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/147 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @0786f700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/146 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @0786f620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/145 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @0786f540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/144 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @0786f460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/143 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @0786f380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/142 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @0786f2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/141 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @0786f1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/140 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @0786f0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/139 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @0786f000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/138 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @0786eee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/137 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @0786ee00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/136 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @0786ed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/135 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @0786ec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/134 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @0786eb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/133 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @0786ea80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/132 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @0786e9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/131 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @0786e8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/130 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @0786e7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/129 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @0786e700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/128 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @0786e620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/127 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @0786e540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/126 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @0786e460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/125 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @0786e380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/124 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @0786e2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/123 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @0786e1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/122 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @0786e0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/121 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @0786e000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/120 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @0786dee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/119 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @0786de00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/118 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @0786dd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/117 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @0786dc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/116 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @0786db60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/115 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @0786da80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/114 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @0786d9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/113 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0786d8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/112 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @0786d7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/111 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @0786d700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/110 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @0786d620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/109 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @0786d540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/108 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @0786d460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/107 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @0786d380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/106 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @0786d2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/105 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @0786d1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/104 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @0786d0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/103 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @0786d000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/102 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0786b620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/101 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0786bee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/100 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0786be00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/99 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0786bd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/98 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0786bc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/97 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0786bb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/96 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0786ba80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/95 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0786b9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/94 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0786b8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/93 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0786b7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/92 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0786b700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/91 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0786b540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/90 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0786b460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/89 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0786b380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/88 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0786b2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/87 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0786b1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/86 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0786b0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
pfe_emac_cfg_enable_ts/85 (pfe_emac_cfg_enable_ts) @07850ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_enable_ts/29 (192154432 (estimated locally),0.18 per call) 
  Calls: 
pfe_emac_cfg_set_enable/84 (pfe_emac_cfg_set_enable) @07850c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_disable/28 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_init/83 (pfe_emac_cfg_init) @07850700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_create/23 (966367642 (estimated locally),0.90 per call) 
  Calls: 
pfe_emac_cfg_pre_init/82 (pfe_emac_cfg_pre_init) @07850620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_create/23 (966367642 (estimated locally),0.90 per call) 
  Calls: 
pfe_mac_db_create/81 (pfe_mac_db_create) @07850540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_create/23 (966367642 (estimated locally),0.90 per call) 
  Calls: 
autolibc_memset/80 (autolibc_memset) @07850460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_destroy/58 (119292716 (estimated locally),0.53 per call) pfe_emac_destroy/58 (119292716 (estimated locally),0.53 per call) pfe_emac_create/23 (966367642 (estimated locally),0.90 per call) pfe_emac_del_addr_nolock/56 (58465242 (estimated locally),0.05 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/79 (oal_util_raise_dem_for_drv_runtime_err) @07850380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_pps0_configure/75 (225056286 (estimated locally),0.21 per call) pfe_emac_enable_ts/29 (150787712 (estimated locally),0.14 per call) pfe_emac_local_is_timer_owner.part.0/359 (1073741824 (estimated locally),1.00 per call) pfe_emac_clear_timer_ownership/73 (201326592 (estimated locally),0.19 per call) pfe_emac_set_timer_ownership/71 (201326592 (estimated locally),0.19 per call) pfe_emac_check_timer_ownership.part.0/351 (1073741824 (estimated locally),1.00 per call) pfe_emac_add_addr/57 (375809639 (estimated locally),0.35 per call) pfe_emac_set_max_frame_length/48 (354334802 (estimated locally),0.33 per call) pfe_emac_create/23 (280246616 (estimated locally),0.26 per call) pfe_emac_create/23 (107374182 (estimated locally),0.10 per call) 
  Calls: 
pfe_hm_report/78 (pfe_hm_report) @078502a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_pps0_configure/75 (225056286 (estimated locally),0.21 per call) pfe_emac_enable_ts/29 (150787712 (estimated locally),0.14 per call) pfe_emac_local_is_timer_owner.part.0/359 (1073741824 (estimated locally),1.00 per call) pfe_emac_clear_timer_ownership/73 (201326592 (estimated locally),0.19 per call) pfe_emac_set_timer_ownership/71 (201326592 (estimated locally),0.19 per call) pfe_emac_check_timer_ownership.part.0/351 (1073741824 (estimated locally),1.00 per call) pfe_emac_add_addr/57 (375809639 (estimated locally),0.35 per call) pfe_emac_set_max_frame_length/48 (354334802 (estimated locally),0.33 per call) pfe_emac_create/23 (280246616 (estimated locally),0.26 per call) pfe_emac_create/23 (107374182 (estimated locally),0.10 per call) 
  Calls: 
__builtin_expect/77 (__builtin_expect) @078501c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_create/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_cfg_get_index/76 (pfe_emac_cfg_get_index) @078500e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_emac_create/23 (1073741824 (estimated locally),1.00 per call) pfe_emac_get_index/24 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_pps0_configure/75 (pfe_emac_pps0_configure) @07847380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/79 (225056286 (estimated locally),0.21 per call) pfe_hm_report/78 (225056286 (estimated locally),0.21 per call) pfe_emac_cfg_pps0_configure/338 (424342769 (estimated locally),0.40 per call) pfe_emac_cfg_pps0_configure/338 (424342769 (estimated locally),0.40 per call) pfe_emac_cfg_pps0_set_pulse_width/337 (424342769 (estimated locally),0.40 per call) pfe_emac_cfg_pps0_set_period/336 (424342769 (estimated locally),0.40 per call) pfe_emac_get_index/24 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_local_is_timer_owner/74 (pfe_emac_local_is_timer_owner) @07847d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_set_ts_time/34 (1073741824 (estimated locally),1.00 per call) pfe_emac_adjust_ts_time/33 (1073741824 (estimated locally),1.00 per call) pfe_emac_set_ts_freq_adjustment/30 (1073741824 (estimated locally),1.00 per call) pfe_emac_enable_ts/29 (922954113 (estimated locally),0.86 per call) 
  Calls: pfe_hif_chnl_get_emac_timer_ownership/335 (872415233 (estimated locally),0.81 per call) pfe_emac_local_is_timer_owner.part.0/359 (201326592 (estimated locally),0.19 per call) pfe_platform_get_instance/333 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_clear_timer_ownership/73 (pfe_emac_clear_timer_ownership) @078479a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_set_emac_timer_ownership/334 (176576843 (estimated locally),0.16 per call) pfe_hif_chnl_get_emac_timer_ownership/335 (872415233 (estimated locally),0.81 per call) oal_mutex_lock.part.0/339 (872415233 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/79 (201326592 (estimated locally),0.19 per call) pfe_hm_report/78 (201326592 (estimated locally),0.19 per call) pfe_platform_get_instance/333 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_check_timer_ownership/72 (pfe_emac_check_timer_ownership) @07847620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:208090819 (estimated locally) body optimize_size
  Called by: pfe_emac_set_timer_ownership/71 (872415233 (estimated locally),0.81 per call) 
  Calls: pfe_hif_chnl_get_emac_timer_ownership/335 (607400719 (estimated locally),2.92 per call) pfe_emac_check_timer_ownership.part.0/351 (21246073 (estimated locally),0.10 per call) pfe_platform_get_instance/333 (208090819 (estimated locally),1.00 per call) 
pfe_emac_set_timer_ownership/71 (pfe_emac_set_timer_ownership) @078472a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (872415233 (estimated locally),0.81 per call) pfe_hif_chnl_set_emac_timer_ownership/334 (143948513 (estimated locally),0.13 per call) pfe_emac_check_timer_ownership/72 (872415233 (estimated locally),0.81 per call) oal_mutex_lock.part.0/339 (872415233 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/79 (201326592 (estimated locally),0.19 per call) pfe_hm_report/78 (201326592 (estimated locally),0.19 per call) pfe_platform_get_instance/333 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_irq_unmask/70 (pfe_emac_irq_unmask) @07840d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_emac_irq_mask/69 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_irq_mask/69 (pfe_emac_irq_mask) @078407e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_emac_irq_unmask/70 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_isr/68 (pfe_emac_isr) @078402a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_isr/332 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_stat_value/67 (pfe_emac_get_stat_value) @07840ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_get_stat_value/331 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_tx_cnt/66 (pfe_emac_get_tx_cnt) @07840c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_get_tx_cnt/330 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_rx_cnt/65 (pfe_emac_get_rx_cnt) @078409a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_get_rx_cnt/329 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_mdio_write45/64 (pfe_emac_mdio_write45) @07840700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_mdio_write45/328 (524845004 (estimated locally),0.49 per call) pfe_emac_cfg_mdio_write45/328 (175811651 (estimated locally),0.16 per call) 
pfe_emac_mdio_read45/63 (pfe_emac_mdio_read45) @07840460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_mdio_read45/327 (524845004 (estimated locally),0.49 per call) pfe_emac_cfg_mdio_read45/327 (175811651 (estimated locally),0.16 per call) 
pfe_emac_mdio_write22/62 (pfe_emac_mdio_write22) @078401c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_mdio_write22/326 (524845004 (estimated locally),0.49 per call) pfe_emac_cfg_mdio_write22/326 (175811651 (estimated locally),0.16 per call) 
pfe_emac_mdio_read22/61 (pfe_emac_mdio_read22) @07835ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_mdio_read22/325 (524845004 (estimated locally),0.49 per call) pfe_emac_cfg_mdio_read22/325 (175811651 (estimated locally),0.16 per call) 
pfe_emac_mdio_unlock/60 (pfe_emac_mdio_unlock) @078358c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_mdio_lock/59 (pfe_emac_mdio_lock) @07835380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: key_seed/17 (read)key_seed/17 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/339 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_destroy/58 (pfe_emac_destroy) @07835e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:223102143 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_disable_ts/324 (119292717 (estimated locally),0.53 per call) pfe_emac_disable/28 (119292717 (estimated locally),0.53 per call) pfe_emac_cfg_clear_hash_table/323 (119292717 (estimated locally),0.53 per call) pfe_emac_cfg_write_addr_slot/315 (954449108 (estimated locally),4.28 per call) autolibc_memset/80 (119292716 (estimated locally),0.53 per call) autolibc_memset/80 (119292716 (estimated locally),0.53 per call) 
pfe_emac_add_addr/57 (pfe_emac_add_addr) @07835b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (697932186 (estimated locally),0.65 per call) pfe_emac_cfg_write_addr_slot/315 (51683274 (estimated locally),0.05 per call) pfe_emac_cfg_set_hash_group/317 (26624717 (estimated locally),0.02 per call) pfe_emac_cfg_get_hash/316 (26624717 (estimated locally),0.02 per call) pfe_emac_mac_slot_idx/20 (230317621 (estimated locally),0.21 per call) pfe_mac_db_add_addr/322 (697932186 (estimated locally),0.65 per call) oal_mutex_lock.part.0/339 (697932186 (estimated locally),0.65 per call) oal_util_raise_dem_for_drv_runtime_err/79 (375809639 (estimated locally),0.35 per call) pfe_hm_report/78 (375809639 (estimated locally),0.35 per call) pfe_emac_is_broad/6 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_del_addr_nolock/56 (pfe_emac_del_addr_nolock) @078357e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_emac_del_addr/55 (1073741824 (estimated locally),1.00 per call) pfe_emac_flush_mac_addrs/54 (1014686025 (estimated locally),17.18 per call) 
  Calls: pfe_emac_del_addr_nolock.part.0/341 (58465243 (estimated locally),0.05 per call) pfe_emac_cfg_write_addr_slot/315 (58465242 (estimated locally),0.05 per call) autolibc_memset/80 (58465242 (estimated locally),0.05 per call) pfe_emac_mac_slot_idx/20 (116930485 (estimated locally),0.11 per call) pfe_emac_mac_in_db/21 (354334802 (estimated locally),0.33 per call) pfe_mac_db_del_addr/314 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_del_addr/55 (pfe_emac_del_addr) @07835540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (1073741824 (estimated locally),1.00 per call) pfe_emac_del_addr_nolock/56 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/339 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_flush_mac_addrs/54 (pfe_emac_flush_mac_addrs) @078352a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:59055801 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (59055800 (estimated locally),1.00 per call) pfe_mac_db_find_by_crit/313 (55807731 (estimated locally),0.94 per call) pfe_emac_del_addr_nolock/56 (1014686025 (estimated locally),17.18 per call) pfe_mac_db_find_by_crit/313 (59055801 (estimated locally),1.00 per call) oal_mutex_lock.part.0/339 (59055801 (estimated locally),1.00 per call) 
pfe_emac_set_link_duplex/53 (pfe_emac_set_link_duplex) @07835000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_duplex/312 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_set_link_speed/52 (pfe_emac_set_link_speed) @07830b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_speed/311 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_link_status/51 (pfe_emac_get_link_status) @07830540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_get_link_status/310 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_link_config/50 (pfe_emac_get_link_config) @07830000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_get_link_config/309 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_mii_mode/49 (pfe_emac_get_mii_mode) @07830d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_set_max_frame_length/48 (pfe_emac_set_max_frame_length) @07830a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/79 (354334802 (estimated locally),0.33 per call) pfe_hm_report/78 (354334802 (estimated locally),0.33 per call) pfe_emac_cfg_set_max_frame_length/308 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_disable_rx_flow_control/47 (pfe_emac_disable_rx_flow_control) @07830700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_rx_flow_control/307 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable_rx_flow_control/46 (pfe_emac_enable_rx_flow_control) @07830460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_rx_flow_control/307 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_disable_tx_flow_control/45 (pfe_emac_disable_tx_flow_control) @078301c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_tx_flow_control/306 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable_tx_flow_control/44 (pfe_emac_enable_tx_flow_control) @0782bd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_tx_flow_control/306 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_flow_control/43 (pfe_emac_get_flow_control) @0782b7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_get_rx_flow_control/305 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_get_tx_flow_control/304 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_disable_broadcast/42 (pfe_emac_disable_broadcast) @0782b2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_create_configure/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_emac_cfg_set_broadcast/303 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable_broadcast/41 (pfe_emac_enable_broadcast) @0782bee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_broadcast/303 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_disable_allmulti_mode/40 (pfe_emac_disable_allmulti_mode) @0782bc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_allmulti_mode/302 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable_allmulti_mode/39 (pfe_emac_enable_allmulti_mode) @0782b9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_allmulti_mode/302 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_disable_promisc_mode/38 (pfe_emac_disable_promisc_mode) @0782b700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_create_configure/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_emac_cfg_set_promisc_mode/301 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable_promisc_mode/37 (pfe_emac_enable_promisc_mode) @0782b460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_promisc_mode/301 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_disable_loopback/36 (pfe_emac_disable_loopback) @0782b1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_create_configure/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_emac_cfg_set_loopback/300 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable_loopback/35 (pfe_emac_enable_loopback) @07813ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_loopback/300 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_set_ts_time/34 (pfe_emac_set_ts_time) @078139a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (223547679 (estimated locally),0.21 per call) pfe_emac_cfg_set_ts_time/299 (223547679 (estimated locally),0.21 per call) oal_mutex_lock.part.0/339 (223547679 (estimated locally),0.21 per call) pfe_emac_local_is_timer_owner/74 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_adjust_ts_time/33 (pfe_emac_adjust_ts_time) @07813380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (223547679 (estimated locally),0.21 per call) pfe_emac_cfg_adjust_ts_time/298 (223547679 (estimated locally),0.21 per call) oal_mutex_lock.part.0/339 (223547679 (estimated locally),0.21 per call) pfe_emac_local_is_timer_owner/74 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_ts_time/32 (pfe_emac_get_ts_time) @07813e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_get_ts_time/297 (482647369 (estimated locally),0.45 per call) 
pfe_emac_get_ts_freq_adjustment/31 (pfe_emac_get_ts_freq_adjustment) @07813b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_set_ts_freq_adjustment/30 (pfe_emac_set_ts_freq_adjustment) @078138c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (223547679 (estimated locally),0.21 per call) pfe_emac_cfg_adjust_ts_freq/296 (223547679 (estimated locally),0.21 per call) oal_mutex_lock.part.0/339 (223547679 (estimated locally),0.21 per call) pfe_emac_local_is_timer_owner/74 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable_ts/29 (pfe_emac_enable_ts) @07813620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_mutex_unlock.part.0/340 (192154432 (estimated locally),0.18 per call) pfe_emac_cfg_enable_ts/85 (192154432 (estimated locally),0.18 per call) oal_mutex_lock.part.0/339 (192154432 (estimated locally),0.18 per call) pfe_emac_local_is_timer_owner/74 (922954113 (estimated locally),0.86 per call) oal_util_raise_dem_for_drv_runtime_err/79 (150787712 (estimated locally),0.14 per call) pfe_hm_report/78 (150787712 (estimated locally),0.14 per call) 
pfe_emac_disable/28 (pfe_emac_disable) @078132a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_destroy/58 (119292717 (estimated locally),0.53 per call) pfe_emac_create/23 (966367642 (estimated locally),0.90 per call) 
  Calls: pfe_emac_cfg_set_enable/84 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_enable/27 (pfe_emac_enable) @07813000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_cfg_set_enable/84 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_get_gpi/26 (pfe_emac_get_gpi) @0780ab60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_bind_gpi/25 (pfe_emac_bind_gpi) @0780a0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_emac_get_index/24 (pfe_emac_get_index) @0780ad20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_emac_pps0_configure/75 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_emac_cfg_get_index/76 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_create/23 (pfe_emac_create) @0780aa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: emac_instance/16 (addr)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (addr)emac_instance/16 (read)emac_instance/16 (read)emac_instance/16 (write)emac_instance/16 (write)emac_instance/16 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_create_configure/22 (686121026 (estimated locally),0.64 per call) oal_util_raise_dem_for_drv_runtime_err/79 (280246616 (estimated locally),0.26 per call) pfe_hm_report/78 (280246616 (estimated locally),0.26 per call) pfe_emac_cfg_init/83 (966367642 (estimated locally),0.90 per call) pfe_emac_disable/28 (966367642 (estimated locally),0.90 per call) pfe_emac_cfg_pre_init/82 (966367642 (estimated locally),0.90 per call) pfe_mac_db_create/81 (966367642 (estimated locally),0.90 per call) autolibc_memset/80 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/79 (107374182 (estimated locally),0.10 per call) pfe_hm_report/78 (107374182 (estimated locally),0.10 per call) __builtin_expect/77 (1073741824 (estimated locally),1.00 per call) pfe_emac_cfg_get_index/76 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_create_configure/22 (pfe_emac_create_configure) @0780a540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_emac_create/23 (686121026 (estimated locally),0.64 per call) 
  Calls: pfe_emac_disable_broadcast/42 (1073741824 (estimated locally),1.00 per call) pfe_emac_disable_promisc_mode/38 (1073741824 (estimated locally),1.00 per call) pfe_emac_disable_loopback/36 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_mac_in_db/21 (pfe_emac_mac_in_db) @0780a2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: pfe_emac_del_addr_nolock/56 (354334802 (estimated locally),0.33 per call) 
  Calls: pfe_mac_db_get_next_addr/320 (958878293 (estimated locally),8.35 per call) autolibc_memcmp/319 (1014686025 (estimated locally),8.83 per call) pfe_mac_db_get_first_addr/318 (114863532 (estimated locally),1.00 per call) 
pfe_emac_mac_slot_idx/20 (pfe_emac_mac_slot_idx) @0780a000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:136615968 (estimated locally) body local optimize_size
  Called by: pfe_emac_add_addr/57 (230317621 (estimated locally),0.21 per call) pfe_emac_del_addr_nolock/56 (116930485 (estimated locally),0.11 per call) pfe_emac_mac_hash_col/19 (1014686025 (estimated locally),13.00 per call) 
  Calls: autolibc_memcmp/319 (314968206 (estimated locally),2.31 per call) pfe_emac_cfg_read_addr_slot/321 (314968206 (estimated locally),2.31 per call) 
pfe_emac_mac_hash_col/19 (pfe_emac_mac_hash_col) @07674a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:78030430 (estimated locally) body local optimize_size
  Called by: pfe_emac_del_addr_nolock.part.0/341 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_mac_db_get_next_addr/320 (995711397 (estimated locally),12.76 per call) pfe_emac_cfg_get_hash/316 (344993248 (estimated locally),4.42 per call) pfe_emac_mac_slot_idx/20 (1014686025 (estimated locally),13.00 per call) pfe_mac_db_get_first_addr/318 (78030430 (estimated locally),1.00 per call) pfe_emac_cfg_get_hash/316 (78030430 (estimated locally),1.00 per call) 
key_seed/17 (key_seed) @076239d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_emac_mdio_lock/59 (read)pfe_emac_mdio_lock/59 (write)
  Availability: available
  Varpool flags: initialized
emac_instance/16 (emac_instance) @07623948
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_emac_create/23 (addr)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (addr)pfe_emac_create/23 (read)pfe_emac_create/23 (read)pfe_emac_create/23 (write)pfe_emac_create/23 (write)pfe_emac_create/23 (write)
  Availability: available
  Varpool flags:
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @0731fa20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/191 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/192 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/193 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/194 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/195 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/196 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/197 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/198 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/199 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/200 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/201 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/202 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/203 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/204 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/205 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/206 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/207 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/208 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/209 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/210 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/211 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/212 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/213 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/214 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/215 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/216 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/217 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/218 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/219 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/220 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/221 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/222 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/223 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/224 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/225 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/226 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/227 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/228 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/229 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/230 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/231 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/232 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/233 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/234 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/235 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/236 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/237 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/238 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/239 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/240 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/241 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/242 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/243 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/244 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/245 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/246 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/247 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/248 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/249 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/250 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/251 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/252 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/253 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/254 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/255 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/256 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/257 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/258 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/259 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/260 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/261 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/262 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/263 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/264 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/265 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/266 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/267 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/268 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/269 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/270 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/271 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/272 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/273 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/274 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/275 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/276 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/277 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/278 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/279 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/280 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/281 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/282 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/283 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/284 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/285 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/286 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/287 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/288 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/289 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/290 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/291 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/292 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/293 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/294 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/295 (addr)
  Referring: oal_mutex_unlock.part.0/340 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @0731f948
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/86 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/87 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/88 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/89 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/90 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/91 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/92 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/93 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/94 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/95 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/96 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/97 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/98 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/99 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/100 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/101 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/102 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/103 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/104 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/105 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/106 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/107 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/108 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/109 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/110 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/111 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/112 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/113 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/114 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/115 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/116 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/117 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/118 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/119 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/120 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/121 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/122 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/123 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/124 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/125 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/126 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/127 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/128 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/129 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/130 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/131 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/132 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/133 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/134 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/135 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/136 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/137 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/138 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/139 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/140 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/141 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/142 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/143 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/144 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/145 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/146 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/147 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/148 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/149 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/150 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/151 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/152 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/153 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/154 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/155 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/156 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/157 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/158 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/159 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/160 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/161 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/162 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/163 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/164 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/165 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/166 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/167 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/168 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/169 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/170 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/171 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/172 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/173 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/174 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/175 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/176 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/177 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/178 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/179 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/180 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/181 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/182 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/183 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/184 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/185 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/186 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/187 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/188 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/189 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/190 (addr)
  Referring: oal_mutex_lock.part.0/339 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_emac_is_broad/6 (pfe_emac_is_broad) @072729a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_emac_add_addr/57 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function pfe_emac_mac_slot_idx (pfe_emac_mac_slot_idx, funcdef_no=15, decl_uid=11109, cgraph_uid=16, symbol_order=20)

Modification phase of node pfe_emac_mac_slot_idx/20
pfe_emac_mac_slot_idx (struct pfe_emac_t * emac, const uint8_t * addr)
{
  uint8_t slot;
  uint8_t addr_in_slot[6];
  uint8_t found_idx;
  unsigned char _1;
  unsigned int _2;
  int _3;
  unsigned int _4;
  unsigned int _5;
  unsigned int _6;
  long int _7;

  <bb 2> [local count: 136615968]:
  # DEBUG BEGIN_STMT
  # DEBUG found_idx => 8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG slot => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 954449109]:
  # DEBUG BEGIN_STMT
  _1 = emac_14(D)->mac_addr_slots;
  _2 = (unsigned int) _1;
  _3 = (int) slot_9;
  _4 = _2 >> _3;
  _5 = _4 & 1;
  if (_5 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 314968206]:
  # DEBUG BEGIN_STMT
  _6 = emac_14(D)->emac_base_va;
  pfe_emac_cfg_read_addr_slot (_6, &addr_in_slot, slot_9);
  # DEBUG BEGIN_STMT
  _7 = autolibc_memcmp (addr_16(D), &addr_in_slot, 6);
  if (_7 == 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 5> [local count: 937125857]:
  # DEBUG BEGIN_STMT
  slot_18 = slot_9 + 1;
  # DEBUG slot => slot_18

  <bb 6> [local count: 1073741824]:
  # slot_9 = PHI <0(2), slot_18(5)>
  # DEBUG slot => slot_9
  # DEBUG BEGIN_STMT
  if (slot_9 != 8)
    goto <bb 3>; [88.89%]
  else
    goto <bb 7>; [11.11%]

  <bb 7> [local count: 136615968]:
  # found_idx_8 = PHI <slot_9(4), 8(6)>
  # DEBUG found_idx => found_idx_8
  # DEBUG BEGIN_STMT
  addr_in_slot ={v} {CLOBBER};
  return found_idx_8;

}



;; Function oal_mutex_lock.part.0 (oal_mutex_lock.part.0, funcdef_no=71, decl_uid=11757, cgraph_uid=335, symbol_order=339)

Modification phase of node oal_mutex_lock.part.0/339
Adjusting mask for param 0 to 0x7f
Setting value range of param 0 [57, 66]
oal_mutex_lock.part.0 (const oal_mutex_t mutex)
{
  void (*<T7ee>) (void) _2;

  <bb 4> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex_1(D)];
  _2 ();

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function oal_mutex_unlock.part.0 (oal_mutex_unlock.part.0, funcdef_no=72, decl_uid=11762, cgraph_uid=336, symbol_order=340)

Modification phase of node oal_mutex_unlock.part.0/340
Adjusting mask for param 0 to 0x7f
Setting value range of param 0 [57, 66]
oal_mutex_unlock.part.0 (const oal_mutex_t mutex)
{
  void (*<T7ee>) (void) _2;

  <bb 4> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID[mutex_1(D)];
  _2 ();

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_del_addr_nolock (pfe_emac_del_addr_nolock, funcdef_no=51, decl_uid=11106, cgraph_uid=52, symbol_order=56)

Modification phase of node pfe_emac_del_addr_nolock/56
pfe_emac_del_addr_nolock (struct pfe_emac_t * emac, const uint8_t * addr, pfe_drv_id_t owner)
{
  uint8_t zero_address[6];
  uint8_t slot;
  errno_t ret;
  struct pfe_mac_db_t * _1;
  unsigned char _2;
  unsigned int _3;
  unsigned char _4;
  int _5;
  unsigned int _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &emac_10(D)->mac_db;
  ret_15 = pfe_mac_db_del_addr (_1, addr_12(D), owner_13(D));
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  if (ret_15 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = pfe_emac_mac_in_db (emac_10(D), addr_12(D));
  if (_2 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 4> [local count: 116930485]:
  # DEBUG BEGIN_STMT
  slot_18 = pfe_emac_mac_slot_idx (emac_10(D), addr_12(D));
  # DEBUG slot => slot_18
  # DEBUG BEGIN_STMT
  if (slot_18 <= 7)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 58465242]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&zero_address, 0, 6);
  # DEBUG BEGIN_STMT
  _3 = emac_10(D)->emac_base_va;
  pfe_emac_cfg_write_addr_slot (_3, &zero_address, slot_18);
  # DEBUG BEGIN_STMT
  _4 = emac_10(D)->mac_addr_slots;
  _5 = (int) slot_18;
  _6 = 1 << _5;
  _7 = (unsigned char) _6;
  _8 = ~_7;
  _9 = _4 & _8;
  emac_10(D)->mac_addr_slots = _9;
  zero_address ={v} {CLOBBER};
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 58465243]:
  # DEBUG D#1 => owner_13(D)
  pfe_emac_del_addr_nolock.part.0 (emac_10(D), addr_12(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return ret_15;

}



;; Function pfe_emac_get_index (pfe_emac_get_index, funcdef_no=19, decl_uid=8921, cgraph_uid=20, symbol_order=24)

Modification phase of node pfe_emac_get_index/24
pfe_emac_get_index (const struct pfe_emac_t * emac)
{
  uint8_t emac_idx;
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_4(D)->emac_base_va;
  _2 = emac_4(D)->cbus_base_va;
  emac_idx_6 = pfe_emac_cfg_get_index (_1, _2);
  # DEBUG emac_idx => emac_idx_6
  # DEBUG BEGIN_STMT
  return emac_idx_6;

}



;; Function pfe_emac_bind_gpi (pfe_emac_bind_gpi, funcdef_no=20, decl_uid=8924, cgraph_uid=21, symbol_order=25)

Modification phase of node pfe_emac_bind_gpi/25
pfe_emac_bind_gpi (struct pfe_emac_t * emac, struct pfe_gpi_t * gpi)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  emac_2(D)->gpi = gpi_3(D);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_emac_get_gpi (pfe_emac_get_gpi, funcdef_no=21, decl_uid=8926, cgraph_uid=22, symbol_order=26)

Modification phase of node pfe_emac_get_gpi/26
pfe_emac_get_gpi (const struct pfe_emac_t * emac)
{
  struct pfe_gpi_t * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _3 = emac_2(D)->gpi;
  return _3;

}



;; Function pfe_emac_enable (pfe_emac_enable, funcdef_no=22, decl_uid=8928, cgraph_uid=23, symbol_order=27)

Modification phase of node pfe_emac_enable/27
pfe_emac_enable (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_enable (_1, 1);
  return;

}



;; Function pfe_emac_disable (pfe_emac_disable, funcdef_no=23, decl_uid=8930, cgraph_uid=24, symbol_order=28)

Modification phase of node pfe_emac_disable/28
pfe_emac_disable (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_enable (_1, 0);
  return;

}



;; Function pfe_emac_get_ts_freq_adjustment (pfe_emac_get_ts_freq_adjustment, funcdef_no=26, decl_uid=8942, cgraph_uid=27, symbol_order=31)

Modification phase of node pfe_emac_get_ts_freq_adjustment/31
pfe_emac_get_ts_freq_adjustment (struct pfe_emac_t * emac, uint32_t * ppb, bool_t * sgn)
{
  errno_t ret;
  long unsigned int _1;
  unsigned char _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (ppb_5(D) == 0B)
    goto <bb 5>; [18.75%]
  else
    goto <bb 3>; [81.25%]

  <bb 3> [local count: 872415233]:
  if (sgn_6(D) == 0B)
    goto <bb 5>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 4> [local count: 708837377]:
  # DEBUG BEGIN_STMT
  _1 = emac_8(D)->adj_ppb;
  *ppb_5(D) = _1;
  # DEBUG BEGIN_STMT
  _2 = emac_8(D)->adj_sign;
  *sgn_6(D) = _2;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <22(3), 0(4), 22(2)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_emac_get_ts_time (pfe_emac_get_ts_time, funcdef_no=27, decl_uid=8957, cgraph_uid=28, symbol_order=32)

Modification phase of node pfe_emac_get_ts_time/32
pfe_emac_get_ts_time (struct pfe_emac_t * emac, uint32_t * sec, uint32_t * nsec, uint16_t * sec_hi)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (sec_4(D) == 0B)
    goto <bb 6>; [18.75%]
  else
    goto <bb 3>; [81.25%]

  <bb 3> [local count: 872415233]:
  if (nsec_5(D) == 0B)
    goto <bb 6>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 4> [local count: 708837377]:
  if (sec_hi_6(D) == 0B)
    goto <bb 6>; [31.91%]
  else
    goto <bb 5>; [68.09%]

  <bb 5> [local count: 482647369]:
  # DEBUG BEGIN_STMT
  _1 = emac_8(D)->emac_base_va;
  pfe_emac_cfg_get_ts_time (_1, sec_4(D), nsec_5(D), sec_hi_6(D));
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 6> [local count: 1073741824]:
  # ret_2 = PHI <22(3), 0(5), 22(2), 22(4)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_emac_enable_loopback (pfe_emac_enable_loopback, funcdef_no=30, decl_uid=8959, cgraph_uid=31, symbol_order=35)

Modification phase of node pfe_emac_enable_loopback/35
pfe_emac_enable_loopback (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_loopback (_1, 1);
  return;

}



;; Function pfe_emac_disable_loopback (pfe_emac_disable_loopback, funcdef_no=31, decl_uid=8961, cgraph_uid=32, symbol_order=36)

Modification phase of node pfe_emac_disable_loopback/36
pfe_emac_disable_loopback (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_loopback (_1, 0);
  return;

}



;; Function pfe_emac_enable_promisc_mode (pfe_emac_enable_promisc_mode, funcdef_no=32, decl_uid=8963, cgraph_uid=33, symbol_order=37)

Modification phase of node pfe_emac_enable_promisc_mode/37
pfe_emac_enable_promisc_mode (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_promisc_mode (_1, 1);
  return;

}



;; Function pfe_emac_disable_promisc_mode (pfe_emac_disable_promisc_mode, funcdef_no=33, decl_uid=8965, cgraph_uid=34, symbol_order=38)

Modification phase of node pfe_emac_disable_promisc_mode/38
pfe_emac_disable_promisc_mode (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_promisc_mode (_1, 0);
  return;

}



;; Function pfe_emac_enable_allmulti_mode (pfe_emac_enable_allmulti_mode, funcdef_no=34, decl_uid=8967, cgraph_uid=35, symbol_order=39)

Modification phase of node pfe_emac_enable_allmulti_mode/39
pfe_emac_enable_allmulti_mode (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_allmulti_mode (_1, 1);
  return;

}



;; Function pfe_emac_disable_allmulti_mode (pfe_emac_disable_allmulti_mode, funcdef_no=35, decl_uid=8969, cgraph_uid=36, symbol_order=40)

Modification phase of node pfe_emac_disable_allmulti_mode/40
pfe_emac_disable_allmulti_mode (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_allmulti_mode (_1, 0);
  return;

}



;; Function pfe_emac_enable_broadcast (pfe_emac_enable_broadcast, funcdef_no=36, decl_uid=8971, cgraph_uid=37, symbol_order=41)

Modification phase of node pfe_emac_enable_broadcast/41
pfe_emac_enable_broadcast (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_broadcast (_1, 1);
  return;

}



;; Function pfe_emac_disable_broadcast (pfe_emac_disable_broadcast, funcdef_no=37, decl_uid=8973, cgraph_uid=38, symbol_order=42)

Modification phase of node pfe_emac_disable_broadcast/42
pfe_emac_disable_broadcast (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_broadcast (_1, 0);
  return;

}



;; Function pfe_emac_create (pfe_emac_create, funcdef_no=18, decl_uid=8919, cgraph_uid=19, symbol_order=23)

Modification phase of node pfe_emac_create/23
pfe_emac_create (addr_t cbus_base_va, addr_t emac_base, pfe_emac_mii_mode_t mode, pfe_emac_speed_t speed, pfe_emac_duplex_t duplex)
{
  uint8_t emac_index;
  struct pfe_emac_t * emac;
  unsigned int _1;
  _Bool _2;
  long int _3;
  long int _4;
  int _5;
  struct pfe_mac_db_t * _6;
  unsigned int _7;
  unsigned int _8;
  int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG emac_index => 255
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_base_12(D) + cbus_base_va_13(D);
  emac_index_16 = pfe_emac_cfg_get_index (_1, cbus_base_va_13(D));
  # DEBUG emac_index => emac_index_16
  # DEBUG BEGIN_STMT
  _2 = emac_index_16 > 2;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 0);
  if (_4 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] EMAC index out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 217, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG emac => 0B
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _5 = (int) emac_index_16;
  emac_17 = &emac_instance[_5];
  # DEBUG emac => emac_17
  # DEBUG BEGIN_STMT
  autolibc_memset (emac_17, 0, 176);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].cbus_base_va = cbus_base_va_13(D);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].emac_base_offset = emac_base_12(D);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].emac_base_va = _1;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].mode = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].speed = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].duplex = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].emac_id = emac_index_16;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].mac_addr_slots = 0;
  # DEBUG BEGIN_STMT
  _6 = &MEM[(struct pfe_emac_t *)&emac_instance][_5].mac_db;
  pfe_mac_db_create (_6);
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct pfe_emac_t *)&emac_instance][_5].emac_base_va;
  pfe_emac_cfg_pre_init (_7);
  # DEBUG BEGIN_STMT
  pfe_emac_disable (emac_17);
  # DEBUG BEGIN_STMT
  _8 = MEM[(struct pfe_emac_t *)&emac_instance][_5].emac_base_va;
  _9 = pfe_emac_cfg_init (_8, mode_30(D), speed_31(D), duplex_32(D));
  if (_9 != 0)
    goto <bb 5>; [29.00%]
  else
    goto <bb 6>; [71.00%]

  <bb 5> [local count: 280246616]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid configuration requested\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 249, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG emac => 0B
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 686121026]:
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].mode = mode_30(D);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].speed = speed_31(D);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_emac_t *)&emac_instance][_5].duplex = duplex_32(D);
  # DEBUG BEGIN_STMT
  pfe_emac_create_configure (emac_17);

  <bb 7> [local count: 1073741824]:
  # emac_10 = PHI <0B(3), 0B(5), emac_17(6)>
  # DEBUG emac => emac_10
  # DEBUG BEGIN_STMT
  return emac_10;

}



;; Function pfe_emac_get_flow_control (pfe_emac_get_flow_control, funcdef_no=38, decl_uid=8985, cgraph_uid=39, symbol_order=43)

Modification phase of node pfe_emac_get_flow_control/43
pfe_emac_get_flow_control (const struct pfe_emac_t * emac, bool_t * tx_enable, bool_t * rx_enable)
{
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_4(D)->emac_base_va;
  pfe_emac_cfg_get_tx_flow_control (_1, tx_enable_5(D));
  # DEBUG BEGIN_STMT
  _2 = emac_4(D)->emac_base_va;
  pfe_emac_cfg_get_rx_flow_control (_2, rx_enable_7(D));
  return;

}



;; Function pfe_emac_enable_tx_flow_control (pfe_emac_enable_tx_flow_control, funcdef_no=39, decl_uid=8975, cgraph_uid=40, symbol_order=44)

Modification phase of node pfe_emac_enable_tx_flow_control/44
pfe_emac_enable_tx_flow_control (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_tx_flow_control (_1, 1);
  return;

}



;; Function pfe_emac_disable_tx_flow_control (pfe_emac_disable_tx_flow_control, funcdef_no=40, decl_uid=8977, cgraph_uid=41, symbol_order=45)

Modification phase of node pfe_emac_disable_tx_flow_control/45
pfe_emac_disable_tx_flow_control (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_tx_flow_control (_1, 0);
  return;

}



;; Function pfe_emac_enable_rx_flow_control (pfe_emac_enable_rx_flow_control, funcdef_no=41, decl_uid=8979, cgraph_uid=42, symbol_order=46)

Modification phase of node pfe_emac_enable_rx_flow_control/46
pfe_emac_enable_rx_flow_control (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_rx_flow_control (_1, 1);
  return;

}



;; Function pfe_emac_disable_rx_flow_control (pfe_emac_disable_rx_flow_control, funcdef_no=42, decl_uid=8981, cgraph_uid=43, symbol_order=47)

Modification phase of node pfe_emac_disable_rx_flow_control/47
pfe_emac_disable_rx_flow_control (const struct pfe_emac_t * emac)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  pfe_emac_cfg_set_rx_flow_control (_1, 0);
  return;

}



;; Function pfe_emac_set_max_frame_length (pfe_emac_set_max_frame_length, funcdef_no=43, decl_uid=8988, cgraph_uid=44, symbol_order=48)

Modification phase of node pfe_emac_set_max_frame_length/48
pfe_emac_set_max_frame_length (const struct pfe_emac_t * emac, uint32_t len)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_4(D)->emac_base_va;
  ret_7 = pfe_emac_cfg_set_max_frame_length (_1, len_5(D));
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  if (ret_7 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Attempt to set unsupported frame length value\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 827, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_emac_get_mii_mode (pfe_emac_get_mii_mode, funcdef_no=44, decl_uid=8990, cgraph_uid=45, symbol_order=49)

Modification phase of node pfe_emac_get_mii_mode/49
pfe_emac_get_mii_mode (const struct pfe_emac_t * emac)
{
  pfe_emac_mii_mode_t mii_mode;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mii_mode_3 = emac_2(D)->mode;
  # DEBUG mii_mode => mii_mode_3
  # DEBUG BEGIN_STMT
  return mii_mode_3;

}



;; Function pfe_emac_get_link_config (pfe_emac_get_link_config, funcdef_no=45, decl_uid=8994, cgraph_uid=46, symbol_order=50)

Modification phase of node pfe_emac_get_link_config/50
pfe_emac_get_link_config (const struct pfe_emac_t * emac, pfe_emac_speed_t * speed, pfe_emac_duplex_t * duplex)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  ret_7 = pfe_emac_cfg_get_link_config (_1, speed_4(D), duplex_5(D));
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  return ret_7;

}



;; Function pfe_emac_get_link_status (pfe_emac_get_link_status, funcdef_no=46, decl_uid=8999, cgraph_uid=47, symbol_order=51)

Modification phase of node pfe_emac_get_link_status/51
pfe_emac_get_link_status (const struct pfe_emac_t * emac, pfe_emac_link_speed_t * link_speed, pfe_emac_duplex_t * duplex, bool_t * link)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  ret_8 = pfe_emac_cfg_get_link_status (_1, link_speed_4(D), duplex_5(D), link_6(D));
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_emac_set_link_speed (pfe_emac_set_link_speed, funcdef_no=47, decl_uid=9002, cgraph_uid=48, symbol_order=52)

Modification phase of node pfe_emac_set_link_speed/52
pfe_emac_set_link_speed (const struct pfe_emac_t * emac, pfe_emac_speed_t link_speed)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  ret_6 = pfe_emac_cfg_set_speed (_1, link_speed_4(D));
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_emac_set_link_duplex (pfe_emac_set_link_duplex, funcdef_no=48, decl_uid=9005, cgraph_uid=49, symbol_order=53)

Modification phase of node pfe_emac_set_link_duplex/53
pfe_emac_set_link_duplex (const struct pfe_emac_t * emac, pfe_emac_duplex_t duplex)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  ret_6 = pfe_emac_cfg_set_duplex (_1, duplex_4(D));
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_emac_flush_mac_addrs (pfe_emac_flush_mac_addrs, funcdef_no=49, decl_uid=9046, cgraph_uid=50, symbol_order=54)

Modification phase of node pfe_emac_flush_mac_addrs/54
pfe_emac_flush_mac_addrs (struct pfe_emac_t * emac, pfe_mac_db_crit_t crit, pfe_mac_type_t type, pfe_drv_id_t owner)
{
  errno_t ret;
  struct pfe_mac_db_list_entry_t entry;
  struct pfe_mac_db_t * _1;
  <unnamed type> _2;

  <bb 2> [local count: 59055801]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 57
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (57);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = &emac_9(D)->mac_db;
  ret_14 = pfe_mac_db_find_by_crit (_1, crit_10(D), type_11(D), owner_12(D), &entry);
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _2 = entry.owner;
  ret_18 = pfe_emac_del_addr_nolock (emac_9(D), &entry.addr, _2);
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  if (ret_18 == 0)
    goto <bb 4>; [5.50%]
  else
    goto <bb 10>; [94.50%]

  <bb 10> [local count: 958878293]:
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 55807731]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_20 = pfe_mac_db_find_by_crit (_1, crit_10(D), type_11(D), owner_12(D), &entry);
  # DEBUG ret => ret_20

  <bb 5> [local count: 114863532]:
  # ret_3 = PHI <ret_14(2), ret_20(4)>

  <bb 6> [local count: 1073741824]:
  # ret_4 = PHI <ret_3(5), ret_18(10)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ret_4 == 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 59055800]:
  # ret_15 = PHI <ret_4(6)>
  # DEBUG BEGIN_STMT
  if (ret_15 == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 20078972]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 9> [local count: 59055800]:
  # ret_5 = PHI <ret_15(7), 0(8)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 57
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (57);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  entry ={v} {CLOBBER};
  return ret_5;

}



;; Function pfe_emac_del_addr (pfe_emac_del_addr, funcdef_no=50, decl_uid=9050, cgraph_uid=51, symbol_order=55)

Modification phase of node pfe_emac_del_addr/55
pfe_emac_del_addr (struct pfe_emac_t * emac, const uint8_t * addr, pfe_drv_id_t owner)
{
  errno_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 58
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (58);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  ret_6 = pfe_emac_del_addr_nolock (emac_2(D), addr_3(D), owner_4(D));
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 58
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (58);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_emac_add_addr (pfe_emac_add_addr, funcdef_no=52, decl_uid=9041, cgraph_uid=53, symbol_order=57)

Modification phase of node pfe_emac_add_addr/57
pfe_emac_add_addr (struct pfe_emac_t * emac, const uint8_t * addr, pfe_drv_id_t owner)
{
  uint32_t hash;
  uint32_t slot;
  errno_t ret;
  unsigned char _1;
  struct pfe_mac_db_t * _2;
  unsigned char _3;
  unsigned char _4;
  unsigned int _5;
  unsigned int _6;
  unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  unsigned char _10;
  unsigned int _11;
  unsigned char _12;
  unsigned char _13;
  unsigned int _14;
  unsigned char _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = pfe_emac_is_broad (addr_22(D));
  if (_1 != 0)
    goto <bb 3>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 3> [local count: 375809639]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] broadcast MAC received\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 1139, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 13>; [100.00%]

  <bb 4> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 59
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (59);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = &emac_24(D)->mac_db;
  ret_27 = pfe_mac_db_add_addr (_2, addr_22(D), owner_25(D));
  # DEBUG ret => ret_27
  # DEBUG BEGIN_STMT
  if (ret_27 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 5> [local count: 230317621]:
  # DEBUG BEGIN_STMT
  _3 = pfe_emac_mac_slot_idx (emac_24(D), addr_22(D));
  # DEBUG slot => (uint32_t) _3
  # DEBUG BEGIN_STMT
  if (_3 == 8)
    goto <bb 14>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 14> [local count: 78307991]:
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 435078385]:
  # DEBUG BEGIN_STMT
  _4 = emac_24(D)->mac_addr_slots;
  _5 = (unsigned int) _4;
  _6 = _5 >> slot_17;
  _7 = _6 & 1;
  if (_7 == 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 7> [local count: 411149073]:
  # DEBUG BEGIN_STMT
  slot_29 = slot_17 + 1;
  # DEBUG slot => slot_29

  <bb 8> [local count: 489457065]:
  # slot_17 = PHI <slot_29(7), 0(14)>
  # DEBUG slot => slot_17
  # DEBUG BEGIN_STMT
  if (slot_17 != 8)
    goto <bb 6>; [88.89%]
  else
    goto <bb 9>; [11.11%]

  <bb 9> [local count: 78307991]:
  # slot_20 = PHI <slot_17(6), slot_17(8)>
  # DEBUG BEGIN_STMT
  if (slot_20 == 8)
    goto <bb 10>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 10> [local count: 26624717]:
  # DEBUG BEGIN_STMT
  _8 = emac_24(D)->emac_base_va;
  hash_33 = pfe_emac_cfg_get_hash (_8, addr_22(D));
  # DEBUG hash => hash_33
  # DEBUG BEGIN_STMT
  _9 = emac_24(D)->emac_base_va;
  pfe_emac_cfg_set_hash_group (_9, hash_33, 1);
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 51683274]:
  # DEBUG BEGIN_STMT
  _10 = emac_24(D)->mac_addr_slots;
  _11 = 1 << slot_20;
  _12 = (unsigned char) _11;
  _13 = _10 | _12;
  emac_24(D)->mac_addr_slots = _13;
  # DEBUG BEGIN_STMT
  _14 = emac_24(D)->emac_base_va;
  _15 = (unsigned char) slot_20;
  pfe_emac_cfg_write_addr_slot (_14, addr_22(D), _15);

  <bb 12> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 59
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (59);

  <bb 13> [local count: 1073741824]:
  # ret_16 = PHI <22(3), ret_27(12)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  return ret_16;

}



;; Function pfe_emac_destroy (pfe_emac_destroy, funcdef_no=53, decl_uid=9052, cgraph_uid=54, symbol_order=58)

Modification phase of node pfe_emac_destroy/58
pfe_emac_destroy (struct pfe_emac_t * emac)
{
  uint8_t slot;
  uint8_t zero_address[6];
  struct pfe_mac_db_t * _1;
  unsigned int _2;
  unsigned char _3;
  int _4;
  unsigned int _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  unsigned int _9;
  unsigned int _10;

  <bb 2> [local count: 223102143]:
  # DEBUG BEGIN_STMT
  if (emac_14(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 3> [local count: 119292716]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&zero_address, 0, 6);
  # DEBUG BEGIN_STMT
  _1 = &emac_14(D)->mac_db;
  autolibc_memset (_1, 0, 116);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG slot => 0
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 954449108]:
  # DEBUG BEGIN_STMT
  _2 = emac_14(D)->emac_base_va;
  pfe_emac_cfg_write_addr_slot (_2, &zero_address, slot_11);
  # DEBUG BEGIN_STMT
  _3 = emac_14(D)->mac_addr_slots;
  _4 = (int) slot_11;
  _5 = 1 << _4;
  _6 = (unsigned char) _5;
  _7 = ~_6;
  _8 = _3 & _7;
  emac_14(D)->mac_addr_slots = _8;
  # DEBUG BEGIN_STMT
  slot_24 = slot_11 + 1;
  # DEBUG slot => slot_24

  <bb 5> [local count: 1073741824]:
  # slot_11 = PHI <0(3), slot_24(4)>
  # DEBUG slot => slot_11
  # DEBUG BEGIN_STMT
  if (slot_11 != 8)
    goto <bb 4>; [88.89%]
  else
    goto <bb 6>; [11.11%]

  <bb 6> [local count: 119292717]:
  # DEBUG BEGIN_STMT
  _9 = emac_14(D)->emac_base_va;
  pfe_emac_cfg_clear_hash_table (_9);
  # DEBUG BEGIN_STMT
  pfe_emac_disable (emac_14(D));
  # DEBUG BEGIN_STMT
  _10 = emac_14(D)->emac_base_va;
  pfe_emac_cfg_disable_ts (_10);
  zero_address ={v} {CLOBBER};

  <bb 7> [local count: 223102144]:
  return;

}



;; Function pfe_emac_mdio_lock (pfe_emac_mdio_lock, funcdef_no=54, decl_uid=9008, cgraph_uid=55, symbol_order=59)

Modification phase of node pfe_emac_mdio_lock/59
pfe_emac_mdio_lock (struct pfe_emac_t * emac, uint32_t * key)
{
  errno_t ret;
  unsigned char _1;
  long unsigned int key_seed.7_2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 60
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (60);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = emac_7(D)->mdio_locked;
  if (_1 == 1)
    goto <bb 4>; [21.72%]
  else
    goto <bb 3>; [78.28%]

  <bb 3> [local count: 840525101]:
  # DEBUG BEGIN_STMT
  emac_7(D)->mdio_locked = 1;
  # DEBUG BEGIN_STMT
  key_seed.7_2 = key_seed;
  emac_7(D)->mdio_key = key_seed.7_2;
  # DEBUG BEGIN_STMT
  _3 = key_seed.7_2 + 1;
  key_seed = _3;
  # DEBUG BEGIN_STMT
  *key_11(D) = key_seed.7_2;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_4 = PHI <115(2), 0(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 60
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (60);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_emac_mdio_unlock (pfe_emac_mdio_unlock, funcdef_no=55, decl_uid=9011, cgraph_uid=56, symbol_order=60)

Modification phase of node pfe_emac_mdio_unlock/60
pfe_emac_mdio_unlock (struct pfe_emac_t * emac, uint32_t key)
{
  errno_t ret;
  unsigned char _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_6(D)->mdio_locked;
  if (_1 == 1)
    goto <bb 3>; [48.89%]
  else
    goto <bb 5>; [51.11%]

  <bb 3> [local count: 524952378]:
  # DEBUG BEGIN_STMT
  _2 = emac_6(D)->mdio_key;
  if (_2 == key_7(D))
    goto <bb 4>; [48.89%]
  else
    goto <bb 5>; [51.11%]

  <bb 4> [local count: 256649217]:
  # DEBUG BEGIN_STMT
  emac_6(D)->mdio_locked = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <115(3), 120(2), 0(4)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_emac_mdio_read22 (pfe_emac_mdio_read22, funcdef_no=56, decl_uid=9017, cgraph_uid=57, symbol_order=61)

Modification phase of node pfe_emac_mdio_read22/61
pfe_emac_mdio_read22 (struct pfe_emac_t * emac, uint8_t pa, uint8_t ra, uint16_t * val, uint32_t key)
{
  errno_t ret;
  unsigned char _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_8(D)->mdio_locked;
  if (_1 == 1)
    goto <bb 3>; [51.12%]
  else
    goto <bb 5>; [48.88%]

  <bb 3> [local count: 548896821]:
  # DEBUG BEGIN_STMT
  _2 = emac_8(D)->mdio_key;
  if (_2 == key_14(D))
    goto <bb 4>; [32.03%]
  else
    goto <bb 6>; [67.97%]

  <bb 4> [local count: 175811651]:
  # DEBUG BEGIN_STMT
  _3 = emac_8(D)->emac_base_va;
  ret_16 = pfe_emac_cfg_mdio_read22 (_3, pa_9(D), ra_10(D), val_11(D));
  # DEBUG ret => ret_16
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _4 = emac_8(D)->emac_base_va;
  ret_13 = pfe_emac_cfg_mdio_read22 (_4, pa_9(D), ra_10(D), val_11(D));
  # DEBUG ret => ret_13

  <bb 6> [local count: 1073741824]:
  # ret_5 = PHI <115(3), ret_13(5), ret_16(4)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_emac_mdio_write22 (pfe_emac_mdio_write22, funcdef_no=57, decl_uid=9023, cgraph_uid=58, symbol_order=62)

Modification phase of node pfe_emac_mdio_write22/62
pfe_emac_mdio_write22 (struct pfe_emac_t * emac, uint8_t pa, uint8_t ra, uint16_t val, uint32_t key)
{
  errno_t ret;
  unsigned char _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_8(D)->mdio_locked;
  if (_1 == 1)
    goto <bb 3>; [51.12%]
  else
    goto <bb 5>; [48.88%]

  <bb 3> [local count: 548896821]:
  # DEBUG BEGIN_STMT
  _2 = emac_8(D)->mdio_key;
  if (_2 == key_14(D))
    goto <bb 4>; [32.03%]
  else
    goto <bb 6>; [67.97%]

  <bb 4> [local count: 175811651]:
  # DEBUG BEGIN_STMT
  _3 = emac_8(D)->emac_base_va;
  ret_16 = pfe_emac_cfg_mdio_write22 (_3, pa_9(D), ra_10(D), val_11(D));
  # DEBUG ret => ret_16
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _4 = emac_8(D)->emac_base_va;
  ret_13 = pfe_emac_cfg_mdio_write22 (_4, pa_9(D), ra_10(D), val_11(D));
  # DEBUG ret => ret_13

  <bb 6> [local count: 1073741824]:
  # ret_5 = PHI <115(3), ret_13(5), ret_16(4)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_emac_mdio_read45 (pfe_emac_mdio_read45, funcdef_no=58, decl_uid=9030, cgraph_uid=59, symbol_order=63)

Modification phase of node pfe_emac_mdio_read45/63
pfe_emac_mdio_read45 (struct pfe_emac_t * emac, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t * val, uint32_t key)
{
  errno_t ret;
  unsigned char _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_8(D)->mdio_locked;
  if (_1 == 1)
    goto <bb 3>; [51.12%]
  else
    goto <bb 5>; [48.88%]

  <bb 3> [local count: 548896821]:
  # DEBUG BEGIN_STMT
  _2 = emac_8(D)->mdio_key;
  if (_2 == key_15(D))
    goto <bb 4>; [32.03%]
  else
    goto <bb 6>; [67.97%]

  <bb 4> [local count: 175811651]:
  # DEBUG BEGIN_STMT
  _3 = emac_8(D)->emac_base_va;
  ret_17 = pfe_emac_cfg_mdio_read45 (_3, pa_9(D), dev_10(D), ra_11(D), val_12(D));
  # DEBUG ret => ret_17
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _4 = emac_8(D)->emac_base_va;
  ret_14 = pfe_emac_cfg_mdio_read45 (_4, pa_9(D), dev_10(D), ra_11(D), val_12(D));
  # DEBUG ret => ret_14

  <bb 6> [local count: 1073741824]:
  # ret_5 = PHI <115(3), ret_14(5), ret_17(4)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_emac_mdio_write45 (pfe_emac_mdio_write45, funcdef_no=59, decl_uid=9037, cgraph_uid=60, symbol_order=64)

Modification phase of node pfe_emac_mdio_write45/64
pfe_emac_mdio_write45 (struct pfe_emac_t * emac, uint8_t pa, uint8_t dev, uint16_t ra, uint16_t val, uint32_t key)
{
  errno_t ret;
  unsigned char _1;
  long unsigned int _2;
  unsigned int _3;
  unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_8(D)->mdio_locked;
  if (_1 == 1)
    goto <bb 3>; [51.12%]
  else
    goto <bb 5>; [48.88%]

  <bb 3> [local count: 548896821]:
  # DEBUG BEGIN_STMT
  _2 = emac_8(D)->mdio_key;
  if (_2 == key_15(D))
    goto <bb 4>; [32.03%]
  else
    goto <bb 6>; [67.97%]

  <bb 4> [local count: 175811651]:
  # DEBUG BEGIN_STMT
  _3 = emac_8(D)->emac_base_va;
  ret_17 = pfe_emac_cfg_mdio_write45 (_3, pa_9(D), dev_10(D), ra_11(D), val_12(D));
  # DEBUG ret => ret_17
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _4 = emac_8(D)->emac_base_va;
  ret_14 = pfe_emac_cfg_mdio_write45 (_4, pa_9(D), dev_10(D), ra_11(D), val_12(D));
  # DEBUG ret => ret_14

  <bb 6> [local count: 1073741824]:
  # ret_5 = PHI <115(3), ret_14(5), ret_17(4)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_emac_get_rx_cnt (pfe_emac_get_rx_cnt, funcdef_no=60, decl_uid=9054, cgraph_uid=61, symbol_order=65)

Modification phase of node pfe_emac_get_rx_cnt/65
pfe_emac_get_rx_cnt (const struct pfe_emac_t * emac)
{
  uint32_t rx_cnt;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  rx_cnt_5 = pfe_emac_cfg_get_rx_cnt (_1);
  # DEBUG rx_cnt => rx_cnt_5
  # DEBUG BEGIN_STMT
  return rx_cnt_5;

}



;; Function pfe_emac_get_tx_cnt (pfe_emac_get_tx_cnt, funcdef_no=61, decl_uid=9056, cgraph_uid=62, symbol_order=66)

Modification phase of node pfe_emac_get_tx_cnt/66
pfe_emac_get_tx_cnt (const struct pfe_emac_t * emac)
{
  uint32_t tx_cnt;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  tx_cnt_5 = pfe_emac_cfg_get_tx_cnt (_1);
  # DEBUG tx_cnt => tx_cnt_5
  # DEBUG BEGIN_STMT
  return tx_cnt_5;

}



;; Function pfe_emac_get_stat_value (pfe_emac_get_stat_value, funcdef_no=62, decl_uid=9059, cgraph_uid=63, symbol_order=67)

Modification phase of node pfe_emac_get_stat_value/67
pfe_emac_get_stat_value (const struct pfe_emac_t * emac, uint32_t stat_id)
{
  uint32_t stat_value;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = emac_3(D)->emac_base_va;
  stat_value_6 = pfe_emac_cfg_get_stat_value (_1, stat_id_4(D));
  # DEBUG stat_value => stat_value_6
  # DEBUG BEGIN_STMT
  return stat_value_6;

}



;; Function pfe_emac_isr (pfe_emac_isr, funcdef_no=63, decl_uid=9061, cgraph_uid=64, symbol_order=68)

Modification phase of node pfe_emac_isr/68
pfe_emac_isr (struct pfe_emac_t * emac)
{
  errno_t ret;
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = emac_4(D)->emac_base_va;
  _2 = emac_4(D)->cbus_base_va;
  ret_6 = pfe_emac_cfg_isr (_1, _2);
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_emac_irq_mask (pfe_emac_irq_mask, funcdef_no=64, decl_uid=9063, cgraph_uid=65, symbol_order=69)

Modification phase of node pfe_emac_irq_mask/69
pfe_emac_irq_mask (struct pfe_emac_t * emac)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_emac_irq_unmask (pfe_emac_irq_unmask, funcdef_no=77, decl_uid=9065, cgraph_uid=66, symbol_order=70)

Modification phase of node pfe_emac_irq_unmask/70
pfe_emac_irq_unmask (struct pfe_emac_t * emac)
{
  <bb 2> [local count: 1073741824]:
  pfe_emac_irq_mask (emac_1(D)); [tail call]
  return;

}



;; Function pfe_emac_check_timer_ownership (pfe_emac_check_timer_ownership, funcdef_no=67, decl_uid=9072, cgraph_uid=68, symbol_order=72)

Modification phase of node pfe_emac_check_timer_ownership/72
pfe_emac_check_timer_ownership (struct pfe_emac_t * emac, bool_t * has_owner, pfe_drv_id_t * drv_id)
{
  pfe_ct_phy_if_id_t chnl_id;
  struct pfe_platform_t * platform;
  errno_t ret;
  <unnamed type> _1;
  unsigned char _2;
  unsigned int _15;
  unsigned int _23;

  <bb 2> [local count: 208090819]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG platform => 0B
  # DEBUG BEGIN_STMT
  # DEBUG chnl_id => 10
  # DEBUG BEGIN_STMT
  *has_owner_11(D) = 0;
  # DEBUG BEGIN_STMT
  platform_14 = pfe_platform_get_instance ();
  # DEBUG platform => platform_14
  # DEBUG BEGIN_STMT
  if (platform_14 == 0B)
    goto <bb 3>; [10.21%]
  else
    goto <bb 11>; [89.79%]

  <bb 11> [local count: 186844746]:
  goto <bb 9>; [100.00%]

  <bb 3> [local count: 21246073]:
  # DEBUG D#3 => emac_16(D)
  # DEBUG D#4 => has_owner_11(D)
  # DEBUG D#5 => drv_id_19(D)
  ret_4 = pfe_emac_check_timer_ownership.part.0 ();
  goto <bb 10>; [100.00%]

  <bb 4> [local count: 920304119]:
  # DEBUG BEGIN_STMT
  if (chnl_id_6 == 5)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 312903400]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 607400719]:
  # DEBUG BEGIN_STMT
  # DEBUG platform => platform_14
  # DEBUG INLINE_ENTRY pfe_get_hif_base_addr
  # DEBUG BEGIN_STMT
  _15 = platform_14->cbus_baseaddr;
  # DEBUG BEGIN_STMT
  _23 = _15 + 622592;
  # DEBUG platform => NULL
  _1 = emac_16(D)->emac_id;
  _2 = pfe_hif_chnl_get_emac_timer_ownership (_23, chnl_id_6, _1);
  *has_owner_11(D) = _2;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (_2 == 1)
    goto <bb 7>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 7> [local count: 33407039]:
  # chnl_id_3 = PHI <chnl_id_6(6)>
  # DEBUG BEGIN_STMT
  *drv_id_19(D) = chnl_id_3;
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 886897079]:
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  chnl_id_21 = chnl_id_6 + 1;
  # DEBUG chnl_id => chnl_id_21

  <bb 9> [local count: 1073741824]:
  # chnl_id_6 = PHI <chnl_id_21(8), 4(11)>
  # DEBUG chnl_id => chnl_id_6
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (chnl_id_6 <= 9)
    goto <bb 4>; [85.71%]
  else
    goto <bb 10>; [14.29%]

  <bb 10> [local count: 208090819]:
  # ret_5 = PHI <ret_4(3), 0(7), 0(9)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_emac_set_timer_ownership (pfe_emac_set_timer_ownership, funcdef_no=66, decl_uid=9068, cgraph_uid=67, symbol_order=71)

Modification phase of node pfe_emac_set_timer_ownership/71
pfe_emac_set_timer_ownership (struct pfe_emac_t * emac, pfe_drv_id_t drv_id)
{
  struct pfe_platform_t * platform;
  pfe_drv_id_t drv_id_owner;
  bool_t has_owner;
  errno_t ret;
  unsigned char has_owner.9_1;
  <unnamed type> _2;
  unsigned int _15;
  unsigned int _23;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  has_owner = 0;
  # DEBUG BEGIN_STMT
  drv_id_owner = 10;
  # DEBUG BEGIN_STMT
  # DEBUG platform => 0B
  # DEBUG BEGIN_STMT
  platform_11 = pfe_platform_get_instance ();
  # DEBUG platform => platform_11
  # DEBUG BEGIN_STMT
  if (platform_11 == 0B)
    goto <bb 3>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 3> [local count: 201326592]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get PFE platform instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 1657, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 65
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (65);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  ret_14 = pfe_emac_check_timer_ownership (emac_12(D), &has_owner, &drv_id_owner);
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  if (ret_14 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 436207616]:
  has_owner.9_1 = has_owner;
  if (has_owner.9_1 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 143948513]:
  # DEBUG BEGIN_STMT
  # DEBUG platform => platform_11
  # DEBUG INLINE_ENTRY pfe_get_hif_base_addr
  # DEBUG BEGIN_STMT
  _15 = platform_11->cbus_baseaddr;
  # DEBUG BEGIN_STMT
  _23 = _15 + 622592;
  # DEBUG platform => NULL
  _2 = emac_12(D)->emac_id;
  ret_18 = pfe_hif_chnl_set_emac_timer_ownership (_23, drv_id_16(D), _2, 1);
  # DEBUG ret => ret_18

  <bb 7> [local count: 872415233]:
  # ret_3 = PHI <ret_18(6), 115(5), 115(4)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 65
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (65);

  <bb 8> [local count: 1073741824]:
  # ret_4 = PHI <22(3), ret_3(7)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  has_owner ={v} {CLOBBER};
  drv_id_owner ={v} {CLOBBER};
  return ret_4;

}



;; Function pfe_emac_clear_timer_ownership (pfe_emac_clear_timer_ownership, funcdef_no=68, decl_uid=9075, cgraph_uid=69, symbol_order=73)

Modification phase of node pfe_emac_clear_timer_ownership/73
pfe_emac_clear_timer_ownership (struct pfe_emac_t * emac, pfe_drv_id_t drv_id)
{
  struct pfe_platform_t * platform;
  errno_t ret;
  <unnamed type> _1;
  unsigned char _2;
  <unnamed type> _3;
  unsigned int _11;
  unsigned int _15;
  unsigned int _20;
  unsigned int _21;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG platform => 0B
  # DEBUG BEGIN_STMT
  platform_10 = pfe_platform_get_instance ();
  # DEBUG platform => platform_10
  # DEBUG BEGIN_STMT
  if (platform_10 == 0B)
    goto <bb 3>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 3> [local count: 201326592]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get PFE platform instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 1757, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 66
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (66);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  # DEBUG platform => platform_10
  # DEBUG INLINE_ENTRY pfe_get_hif_base_addr
  # DEBUG BEGIN_STMT
  _15 = platform_10->cbus_baseaddr;
  # DEBUG BEGIN_STMT
  _11 = _15 + 622592;
  # DEBUG platform => NULL
  _1 = emac_12(D)->emac_id;
  _2 = pfe_hif_chnl_get_emac_timer_ownership (_11, drv_id_13(D), _1);
  if (_2 == 1)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 176576843]:
  # DEBUG BEGIN_STMT
  # DEBUG platform => platform_10
  # DEBUG INLINE_ENTRY pfe_get_hif_base_addr
  # DEBUG BEGIN_STMT
  _20 = platform_10->cbus_baseaddr;
  # DEBUG BEGIN_STMT
  _21 = _20 + 622592;
  # DEBUG platform => NULL
  _3 = emac_12(D)->emac_id;
  ret_17 = pfe_hif_chnl_set_emac_timer_ownership (_21, drv_id_13(D), _3, 0);
  # DEBUG ret => ret_17

  <bb 6> [local count: 872415233]:
  # ret_4 = PHI <ret_17(5), 115(4)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 66
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (66);

  <bb 7> [local count: 1073741824]:
  # ret_5 = PHI <22(3), ret_4(6)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_emac_local_is_timer_owner (pfe_emac_local_is_timer_owner, funcdef_no=69, decl_uid=9078, cgraph_uid=70, symbol_order=74)

Modification phase of node pfe_emac_local_is_timer_owner/74
pfe_emac_local_is_timer_owner (struct pfe_emac_t * emac, bool_t * is_owner)
{
  struct pfe_platform_t * platform;
  errno_t ret;
  <unnamed type> _1;
  unsigned char _2;
  unsigned int _9;
  unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG platform => 0B
  # DEBUG BEGIN_STMT
  platform_8 = pfe_platform_get_instance ();
  # DEBUG platform => platform_8
  # DEBUG BEGIN_STMT
  if (platform_8 == 0B)
    goto <bb 3>; [18.75%]
  else
    goto <bb 4>; [81.25%]

  <bb 3> [local count: 201326592]:
  # DEBUG D#9 => emac_10(D)
  # DEBUG D#10 => is_owner_12(D)
  ret_14 = pfe_emac_local_is_timer_owner.part.0 ();
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  # DEBUG platform => platform_8
  # DEBUG INLINE_ENTRY pfe_get_hif_base_addr
  # DEBUG BEGIN_STMT
  _9 = platform_8->cbus_baseaddr;
  # DEBUG BEGIN_STMT
  _15 = _9 + 622592;
  # DEBUG platform => NULL
  _1 = emac_10(D)->emac_id;
  _2 = pfe_hif_chnl_get_emac_timer_ownership (_15, 6, _1);
  *is_owner_12(D) = _2;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <ret_14(3), 0(4)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_emac_enable_ts (pfe_emac_enable_ts, funcdef_no=24, decl_uid=8934, cgraph_uid=25, symbol_order=29)

Modification phase of node pfe_emac_enable_ts/29
pfe_emac_enable_ts (struct pfe_emac_t * emac, uint32_t i_clk_hz, uint32_t o_clk_hz)
{
  bool_t eclk;
  bool_t is_owner;
  errno_t ret;
  unsigned char is_owner.1_1;
  unsigned int _2;
  int iftmp.0_4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  is_owner = 0;
  # DEBUG BEGIN_STMT
  if (i_clk_hz_8(D) == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  if (o_clk_hz_9(D) == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 268435456]:

  <bb 5> [local count: 1073741824]:
  # iftmp.0_4 = PHI <1(3), 0(4), 1(2)>
  eclk_10 = (bool_t) iftmp.0_4;
  # DEBUG eclk => eclk_10
  # DEBUG BEGIN_STMT
  if (eclk_10 == 0)
    goto <bb 6>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 6> [local count: 719407023]:
  if (i_clk_hz_8(D) <= o_clk_hz_9(D))
    goto <bb 7>; [20.96%]
  else
    goto <bb 8>; [79.04%]

  <bb 7> [local count: 150787712]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Invalid clock configuration\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 370, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 922954113]:
  # DEBUG BEGIN_STMT
  ret_15 = pfe_emac_local_is_timer_owner (emac_13(D), &is_owner);
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  if (ret_15 == 0)
    goto <bb 9>; [65.00%]
  else
    goto <bb 11>; [35.00%]

  <bb 9> [local count: 599920174]:
  is_owner.1_1 = is_owner;
  if (is_owner.1_1 == 1)
    goto <bb 10>; [32.03%]
  else
    goto <bb 11>; [67.97%]

  <bb 10> [local count: 192154432]:
  # DEBUG BEGIN_STMT
  emac_13(D)->i_clk_hz = i_clk_hz_8(D);
  # DEBUG BEGIN_STMT
  emac_13(D)->o_clk_hz = o_clk_hz_9(D);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 61
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (61);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = emac_13(D)->emac_base_va;
  ret_19 = pfe_emac_cfg_enable_ts (_2, eclk_10, i_clk_hz_8(D), o_clk_hz_9(D));
  # DEBUG ret => ret_19
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 61
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (61);

  <bb 11> [local count: 1073741824]:
  # ret_3 = PHI <22(7), ret_19(10), 115(9), 115(8)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  is_owner ={v} {CLOBBER};
  return ret_3;

}



;; Function pfe_emac_set_ts_freq_adjustment (pfe_emac_set_ts_freq_adjustment, funcdef_no=25, decl_uid=8938, cgraph_uid=26, symbol_order=30)

Modification phase of node pfe_emac_set_ts_freq_adjustment/30
pfe_emac_set_ts_freq_adjustment (struct pfe_emac_t * emac, uint32_t ppb, bool_t sgn)
{
  bool_t is_owner;
  errno_t ret;
  unsigned char is_owner.2_1;
  unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  is_owner = 0;
  # DEBUG BEGIN_STMT
  ret_11 = pfe_emac_local_is_timer_owner (emac_9(D), &is_owner);
  # DEBUG ret => ret_11
  # DEBUG BEGIN_STMT
  if (ret_11 == 0)
    goto <bb 3>; [65.00%]
  else
    goto <bb 5>; [35.00%]

  <bb 3> [local count: 697932186]:
  is_owner.2_1 = is_owner;
  if (is_owner.2_1 == 1)
    goto <bb 4>; [32.03%]
  else
    goto <bb 5>; [67.97%]

  <bb 4> [local count: 223547679]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 62
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (62);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  emac_9(D)->adj_ppb = ppb_12(D);
  # DEBUG BEGIN_STMT
  emac_9(D)->adj_sign = sgn_14(D);
  # DEBUG BEGIN_STMT
  _2 = emac_9(D)->emac_base_va;
  _3 = emac_9(D)->i_clk_hz;
  _4 = emac_9(D)->o_clk_hz;
  ret_17 = pfe_emac_cfg_adjust_ts_freq (_2, _3, _4, ppb_12(D), sgn_14(D));
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 62
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (62);

  <bb 5> [local count: 1073741824]:
  # ret_5 = PHI <ret_17(4), 115(3), 115(2)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  is_owner ={v} {CLOBBER};
  return ret_5;

}



;; Function pfe_emac_adjust_ts_time (pfe_emac_adjust_ts_time, funcdef_no=28, decl_uid=8952, cgraph_uid=29, symbol_order=33)

Modification phase of node pfe_emac_adjust_ts_time/33
pfe_emac_adjust_ts_time (struct pfe_emac_t * emac, uint32_t sec, uint32_t nsec, bool_t sgn)
{
  bool_t is_owner;
  errno_t ret;
  unsigned char is_owner.3_1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  is_owner = 0;
  # DEBUG BEGIN_STMT
  ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  if (ret_9 == 0)
    goto <bb 3>; [65.00%]
  else
    goto <bb 5>; [35.00%]

  <bb 3> [local count: 697932186]:
  is_owner.3_1 = is_owner;
  if (is_owner.3_1 == 1)
    goto <bb 4>; [32.03%]
  else
    goto <bb 5>; [67.97%]

  <bb 4> [local count: 223547679]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 63
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (63);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = emac_7(D)->emac_base_va;
  ret_14 = pfe_emac_cfg_adjust_ts_time (_2, sec_10(D), nsec_11(D), sgn_12(D));
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 63
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (63);

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <ret_14(4), 115(3), 115(2)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  is_owner ={v} {CLOBBER};
  return ret_3;

}



;; Function pfe_emac_set_ts_time (pfe_emac_set_ts_time, funcdef_no=29, decl_uid=8947, cgraph_uid=30, symbol_order=34)

Modification phase of node pfe_emac_set_ts_time/34
pfe_emac_set_ts_time (struct pfe_emac_t * emac, uint32_t sec, uint32_t nsec, uint16_t sec_hi)
{
  bool_t is_owner;
  errno_t ret;
  unsigned char is_owner.4_1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  is_owner = 0;
  # DEBUG BEGIN_STMT
  ret_9 = pfe_emac_local_is_timer_owner (emac_7(D), &is_owner);
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  if (ret_9 == 0)
    goto <bb 3>; [65.00%]
  else
    goto <bb 5>; [35.00%]

  <bb 3> [local count: 697932186]:
  is_owner.4_1 = is_owner;
  if (is_owner.4_1 == 1)
    goto <bb 4>; [32.03%]
  else
    goto <bb 5>; [67.97%]

  <bb 4> [local count: 223547679]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 64
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (64);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _2 = emac_7(D)->emac_base_va;
  ret_14 = pfe_emac_cfg_set_ts_time (_2, sec_10(D), nsec_11(D), sec_hi_12(D));
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 64
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (64);

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <ret_14(4), 115(3), 115(2)>
  # DEBUG mutex => NULL
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  is_owner ={v} {CLOBBER};
  return ret_3;

}



;; Function pfe_emac_pps0_configure (pfe_emac_pps0_configure, funcdef_no=70, decl_uid=9083, cgraph_uid=71, symbol_order=75)

Modification phase of node pfe_emac_pps0_configure/75
pfe_emac_pps0_configure (struct pfe_emac_t * emac, bool_t enable, uint32_t period, uint32_t pulse_width)
{
  errno_t ret;
  unsigned char _1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  _1 = pfe_emac_get_index (emac_9(D));
  if (_1 == 0)
    goto <bb 3>; [79.04%]
  else
    goto <bb 7>; [20.96%]

  <bb 3> [local count: 848685538]:
  # DEBUG BEGIN_STMT
  if (enable_13(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 424342769]:
  # DEBUG BEGIN_STMT
  _2 = emac_9(D)->emac_base_va;
  pfe_emac_cfg_pps0_set_period (_2, period_15(D));
  # DEBUG BEGIN_STMT
  _3 = emac_9(D)->emac_base_va;
  pfe_emac_cfg_pps0_set_pulse_width (_3, pulse_width_17(D));
  # DEBUG BEGIN_STMT
  _4 = emac_9(D)->emac_base_va;
  pfe_emac_cfg_pps0_configure (_4, 0, 3, 1);
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 424342769]:
  # DEBUG BEGIN_STMT
  _5 = emac_9(D)->emac_base_va;
  pfe_emac_cfg_pps0_configure (_5, 0, 0, 0);
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 225056286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] PPS output not available on given EMAC instance", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_emac.c", 1886, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 8> [local count: 1073741824]:
  # ret_6 = PHI <0(5), 22(7), 0(4)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_6;

}


