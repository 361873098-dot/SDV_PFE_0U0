
IPA constant propagation start:
Determining dynamic type for call: DestroyHifDrv (prCommonChnlIRQ.8_5, prCommonHifDrv.9_6);
  Starting walk at: DestroyHifDrv (prCommonChnlIRQ.8_5, prCommonHifDrv.9_6);
  instance pointer: prCommonChnlIRQ.8_5  Outer instance pointer: prCommonChnlIRQ.8_5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Eth_PFE_LLD_DisableController (0);
  Function call may change dynamic type:prHif_4 = pfe_platform_get_phy_if_by_id (ptrPlatform.6_3, 6);
  Function call may change dynamic type:pfe_phy_if_disable (prHif_4);
Determining dynamic type for call: DestroyHifDrv (prCommonChnlIRQ.8_5, prCommonHifDrv.9_6);
  Starting walk at: DestroyHifDrv (prCommonChnlIRQ.8_5, prCommonHifDrv.9_6);
  instance pointer: prCommonHifDrv.9_6  Outer instance pointer: prCommonHifDrv.9_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Eth_PFE_LLD_DisableController (0);
  Function call may change dynamic type:prHif_4 = pfe_platform_get_phy_if_by_id (ptrPlatform.6_3, 6);
  Function call may change dynamic type:pfe_phy_if_disable (prHif_4);
Determining dynamic type for call: _15 = IsRxChecksumValid (RxPacket_1(D), _14);
  Starting walk at: _15 = IsRxChecksumValid (RxPacket_1(D), _14);
  instance pointer: RxPacket_1(D)  Outer instance pointer: RxPacket_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = IsRxChecksumValid (RxPacket_1(D), _14);
  Starting walk at: _15 = IsRxChecksumValid (RxPacket_1(D), _14);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_16 = ConfigureSchedulerAndShaper_SetShaper (pstate_5(D), u8SchIdx_10(D), pSchInput_7(D));
  Starting walk at: ret_16 = ConfigureSchedulerAndShaper_SetShaper (pstate_5(D), u8SchIdx_10(D), pSchInput_7(D));
  instance pointer: pstate_5(D)  Outer instance pointer: pstate_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = pfe_tmu_sch_set_input_weight (_4, _6, u8SchIdx_10(D), _8, _9);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Failed to set scheduler input weight\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 1250, "");
Determining dynamic type for call: ret_16 = ConfigureSchedulerAndShaper_SetShaper (pstate_5(D), u8SchIdx_10(D), pSchInput_7(D));
  Starting walk at: ret_16 = ConfigureSchedulerAndShaper_SetShaper (pstate_5(D), u8SchIdx_10(D), pSchInput_7(D));
  instance pointer: pSchInput_7(D)  Outer instance pointer: pSchInput_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = pfe_tmu_sch_set_input_weight (_4, _6, u8SchIdx_10(D), _8, _9);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Failed to set scheduler input weight\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 1250, "");
Determining dynamic type for call: ret_15 = ConfigureSchedulerAndShaper_SetFifo.isra.0 (pstate_5(D), u8SchIdx_10(D), _14, _13);
  Starting walk at: ret_15 = ConfigureSchedulerAndShaper_SetFifo.isra.0 (pstate_5(D), u8SchIdx_10(D), _14, _13);
  instance pointer: pstate_5(D)  Outer instance pointer: pstate_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_11 = pfe_tmu_sch_set_input_weight (_4, _6, u8SchIdx_10(D), _8, _9);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Failed to set scheduler input weight\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 1250, "");
Determining dynamic type for call: RetVal_23 = EmacTsAdjustRatio (u8CtrlIdx_16(D), prEmac_18, pRateRatioPtr_21(D));
  Starting walk at: RetVal_23 = EmacTsAdjustRatio (u8CtrlIdx_16(D), prEmac_18, pRateRatioPtr_21(D));
  instance pointer: prEmac_18  Outer instance pointer: prEmac_18 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = pfe_emac_adjust_ts_time (prEmac_18, _7, _9, _11);
Determining dynamic type for call: RetVal_23 = EmacTsAdjustRatio (u8CtrlIdx_16(D), prEmac_18, pRateRatioPtr_21(D));
  Starting walk at: RetVal_23 = EmacTsAdjustRatio (u8CtrlIdx_16(D), prEmac_18, pRateRatioPtr_21(D));
  instance pointer: pRateRatioPtr_21(D)  Outer instance pointer: pRateRatioPtr_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = pfe_emac_adjust_ts_time (prEmac_18, _7, _9, _11);
Determining dynamic type for call: Error_24 = GetTxTimeStamp (u8CtrlIdx_20(D), BufIdx_22, _5, _6);
  Starting walk at: Error_24 = GetTxTimeStamp (u8CtrlIdx_20(D), BufIdx_22, _5, _6);
  instance pointer: _5  Outer instance pointer: &aarTxBuf[_1][BufIdx_22].TimeQual offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (18);
  Function call may change dynamic type:oal_mutex_unlock.part.0 (18);
  Function call may change dynamic type:oal_mutex_lock.part.0 (18);
  Function call may change dynamic type:Error_24 = GetTxTimeStamp (u8CtrlIdx_20(D), BufIdx_22, _5, _6);
  Function call may change dynamic type:oal_mutex_unlock.part.0 (21);
  Function call may change dynamic type:EthIf_TxConfirmation (_12, BufIdx_22, 0);
  Function call may change dynamic type:oal_mutex_lock.part.0 (21);
Determining dynamic type for call: Error_24 = GetTxTimeStamp (u8CtrlIdx_20(D), BufIdx_22, _5, _6);
  Starting walk at: Error_24 = GetTxTimeStamp (u8CtrlIdx_20(D), BufIdx_22, _5, _6);
  instance pointer: _6  Outer instance pointer: &aarTxBuf[_1][BufIdx_22].TimeStamp offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_mutex_lock.part.0 (18);
  Function call may change dynamic type:oal_mutex_unlock.part.0 (18);
  Function call may change dynamic type:oal_mutex_lock.part.0 (18);
  Function call may change dynamic type:Error_24 = GetTxTimeStamp (u8CtrlIdx_20(D), BufIdx_22, _5, _6);
  Function call may change dynamic type:oal_mutex_unlock.part.0 (21);
  Function call may change dynamic type:EthIf_TxConfirmation (_12, BufIdx_22, 0);
  Function call may change dynamic type:oal_mutex_lock.part.0 (21);
Determining dynamic type for call: ReportReception_ProcessPacket.isra.0 (u8CtrlIdx_11(D), RxPacket_16);
  Starting walk at: ReportReception_ProcessPacket.isra.0 (u8CtrlIdx_11(D), RxPacket_16);
  instance pointer: RxPacket_16  Outer instance pointer: RxPacket_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:RxPacket_16 = pfe_hif_drv_client_receive_pkt (prClient_13, _2);
  Function call may change dynamic type:RxPacket_16 = pfe_hif_drv_client_receive_pkt (prClient_13, _2);
  Function call may change dynamic type:ReportReception_ProcessPacket.isra.0 (u8CtrlIdx_11(D), RxPacket_16);
Determining dynamic type for call: checksum_valid_12 = IsRxChecksumValidIpV6 (RxPacket_11(D), Protocol_10);
  Starting walk at: checksum_valid_12 = IsRxChecksumValidIpV6 (RxPacket_11(D), Protocol_10);
  instance pointer: RxPacket_11(D)  Outer instance pointer: RxPacket_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: checksum_valid_14 = IsRxChecksumValidIpV4 (RxPacket_11(D), Protocol_13);
  Starting walk at: checksum_valid_14 = IsRxChecksumValidIpV4 (RxPacket_11(D), Protocol_13);
  instance pointer: RxPacket_11(D)  Outer instance pointer: RxPacket_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_hif_pkt_udpv6_csum_valid (RxPacket_9(D));
  Starting walk at: _1 = pfe_hif_pkt_udpv6_csum_valid (RxPacket_9(D));
  instance pointer: RxPacket_9(D)  Outer instance pointer: RxPacket_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_hif_pkt_tcpv6_csum_valid (RxPacket_9(D));
  Starting walk at: _2 = pfe_hif_pkt_tcpv6_csum_valid (RxPacket_9(D));
  instance pointer: RxPacket_9(D)  Outer instance pointer: RxPacket_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_hif_pkt_icmp_csum_valid (RxPacket_9(D));
  Starting walk at: _3 = pfe_hif_pkt_icmp_csum_valid (RxPacket_9(D));
  instance pointer: RxPacket_9(D)  Outer instance pointer: RxPacket_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pfe_hif_pkt_udpv4_csum_valid (RxPacket_9(D));
  Starting walk at: _1 = pfe_hif_pkt_udpv4_csum_valid (RxPacket_9(D));
  instance pointer: RxPacket_9(D)  Outer instance pointer: RxPacket_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = pfe_hif_pkt_tcpv4_csum_valid (RxPacket_9(D));
  Starting walk at: _2 = pfe_hif_pkt_tcpv4_csum_valid (RxPacket_9(D));
  instance pointer: RxPacket_9(D)  Outer instance pointer: RxPacket_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = pfe_hif_pkt_icmp_csum_valid (RxPacket_9(D));
  Starting walk at: _3 = pfe_hif_pkt_icmp_csum_valid (RxPacket_9(D));
  instance pointer: RxPacket_9(D)  Outer instance pointer: RxPacket_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = GetTxBuffer (u8CtrlIdx_12(D), u8QueuIdx_13(D), &BufIdx);
  Starting walk at: _4 = GetTxBuffer (u8CtrlIdx_12(D), u8QueuIdx_13(D), &BufIdx);
  instance pointer: &BufIdx  Outer instance pointer: BufIdx offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pfe_emac_is_broad (PhysAddrPtr_13(D));
  Starting walk at: _5 = pfe_emac_is_broad (PhysAddrPtr_13(D));
  instance pointer: PhysAddrPtr_13(D)  Outer instance pointer: PhysAddrPtr_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = pfe_emac_is_zero (PhysAddrPtr_13(D));
  Starting walk at: _6 = pfe_emac_is_zero (PhysAddrPtr_13(D));
  instance pointer: PhysAddrPtr_13(D)  Outer instance pointer: PhysAddrPtr_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = pfe_emac_is_multi (PhysAddrPtr_13(D));
  Starting walk at: _7 = pfe_emac_is_multi (PhysAddrPtr_13(D));
  instance pointer: PhysAddrPtr_13(D)  Outer instance pointer: PhysAddrPtr_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: u8ReturnStatus_17 = UpdatePhysAddrFilter_RemoveMulti.isra.0 (_27, PhysAddrPtr_13(D));
  Starting walk at: u8ReturnStatus_17 = UpdatePhysAddrFilter_RemoveMulti.isra.0 (_27, PhysAddrPtr_13(D));
  instance pointer: _27  Outer instance pointer: _27 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: u8ReturnStatus_17 = UpdatePhysAddrFilter_RemoveMulti.isra.0 (_27, PhysAddrPtr_13(D));
  Starting walk at: u8ReturnStatus_17 = UpdatePhysAddrFilter_RemoveMulti.isra.0 (_27, PhysAddrPtr_13(D));
  instance pointer: PhysAddrPtr_13(D)  Outer instance pointer: PhysAddrPtr_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: u8ReturnStatus_19 = UpdatePhysAddrFilter_AddMulti.isra.0 (_26, PhysAddrPtr_13(D));
  Starting walk at: u8ReturnStatus_19 = UpdatePhysAddrFilter_AddMulti.isra.0 (_26, PhysAddrPtr_13(D));
  instance pointer: _26  Outer instance pointer: _26 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: u8ReturnStatus_19 = UpdatePhysAddrFilter_AddMulti.isra.0 (_26, PhysAddrPtr_13(D));
  Starting walk at: u8ReturnStatus_19 = UpdatePhysAddrFilter_AddMulti.isra.0 (_26, PhysAddrPtr_13(D));
  instance pointer: PhysAddrPtr_13(D)  Outer instance pointer: PhysAddrPtr_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: u8ReturnStatus_21 = UpdatePhysAddrFilter_Close.isra.0 (_30);
  Starting walk at: u8ReturnStatus_21 = UpdatePhysAddrFilter_Close.isra.0 (_30);
  instance pointer: _30  Outer instance pointer: &arPfeInterface[_1] offset: 192 (bits) vtbl reference: 
Determining dynamic type for call: u8ReturnStatus_23 = UpdatePhysAddrFilter_RemoveBroad.isra.0 (_29);
  Starting walk at: u8ReturnStatus_23 = UpdatePhysAddrFilter_RemoveBroad.isra.0 (_29);
  instance pointer: _29  Outer instance pointer: _29 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: u8ReturnStatus_25 = UpdatePhysAddrFilter_AddBroad.isra.0 (_28);
  Starting walk at: u8ReturnStatus_25 = UpdatePhysAddrFilter_AddBroad.isra.0 (_28);
  instance pointer: _28  Outer instance pointer: _28 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
  Starting walk at: bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
  instance pointer: pCtrlCfg_24  Outer instance pointer: pCtrlCfg_24 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: bResult_32 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: bResult_32 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: prPfeDev_21  Outer instance pointer: &arPfeInterface[_1] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: bResult_32 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: bResult_32 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: &client_queue  Outer instance pointer: client_queue offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: bResult_32 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: bResult_32 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: &client_fifo_queue  Outer instance pointer: client_fifo_queue offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: _13 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: _13 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: prPfeDev_21  Outer instance pointer: &arPfeInterface[_1] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: _13 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: _13 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: &client_queue  Outer instance pointer: client_queue offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: _13 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: _13 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: &client_fifo_queue  Outer instance pointer: client_fifo_queue offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: bResult_37 = EnableController_Aux (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: bResult_37 = EnableController_Aux (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: prPfeDev_21  Outer instance pointer: &arPfeInterface[_1] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: bResult_37 = EnableController_Aux (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: bResult_37 = EnableController_Aux (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: &client_queue  Outer instance pointer: client_queue offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: bResult_37 = EnableController_Aux (prPfeDev_21, &client_queue, &client_fifo_queue);
  Starting walk at: bResult_37 = EnableController_Aux (prPfeDev_21, &client_queue, &client_fifo_queue);
  instance pointer: &client_fifo_queue  Outer instance pointer: client_fifo_queue offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
Determining dynamic type for call: _14 = EnableController_Common (prPfeDev_18(D));
  Starting walk at: _14 = EnableController_Common (prPfeDev_18(D));
  instance pointer: prPfeDev_18(D)  Outer instance pointer: prPfeDev_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = pfe_hif_drv_client_set_inject_if (_10, _12);
  Function call may change dynamic type:_10 = pfe_hif_drv_client_register (_1, _3, pclient_queue_19(D), pclient_fifo_queue_20(D), _9, ClientEventHdlr, prPfeDev_18(D));
Determining dynamic type for call: _3 = EnableController_Common (prPfeDev_7(D));
  Starting walk at: _3 = EnableController_Common (prPfeDev_7(D));
  instance pointer: prPfeDev_7(D)  Outer instance pointer: prPfeDev_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pfe_hif_drv_aux_client_register (_1, pclient_queue_8(D), pclient_fifo_queue_9(D), ClientEventHdlr, prPfeDev_7(D));
Determining dynamic type for call: _3 = InitializeTxHeaders (_1, _2);
  Starting walk at: _3 = InitializeTxHeaders (_1, _2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _13 = Eth_PFE_LLD_EMACPrepare_Config (prEmac_20, _12);
  Starting walk at: _13 = Eth_PFE_LLD_EMACPrepare_Config (prEmac_20, _12);
  instance pointer: prEmac_20  Outer instance pointer: prEmac_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:prEmac_20 = pfe_platform_get_phy_if_by_id (ptrPlatform.64_7, _9);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not get EMAC %u\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2437, _3, "");
  Function call may change dynamic type:prEmac_20 = pfe_platform_get_phy_if_by_id (ptrPlatform.64_7, _9);
  Function call may change dynamic type:_13 = Eth_PFE_LLD_EMACPrepare_Config (prEmac_20, _12);
Determining dynamic type for call: _13 = Eth_PFE_LLD_EMACPrepare_Config (prEmac_20, _12);
  Starting walk at: _13 = Eth_PFE_LLD_EMACPrepare_Config (prEmac_20, _12);
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:prEmac_20 = pfe_platform_get_phy_if_by_id (ptrPlatform.64_7, _9);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not get EMAC %u\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2437, _3, "");
  Function call may change dynamic type:prEmac_20 = pfe_platform_get_phy_if_by_id (ptrPlatform.64_7, _9);
  Function call may change dynamic type:_13 = Eth_PFE_LLD_EMACPrepare_Config (prEmac_20, _12);
Determining dynamic type for call: InterfacePrepare_InitTSQueue (prPfeDev_24);
  Starting walk at: InterfacePrepare_InitTSQueue (prPfeDev_24);
  instance pointer: prPfeDev_24  Outer instance pointer: &arPfeInterface[_3] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memcpy (_4, _7, 6);
Determining dynamic type for call: _20 = InterfacePrepare_MasterConfigEMAC (prPfeDev_24);
  Starting walk at: _20 = InterfacePrepare_MasterConfigEMAC (prPfeDev_24);
  instance pointer: prPfeDev_24  Outer instance pointer: &arPfeInterface[_3] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_15 = pfe_platform_get_phy_if_by_id (ptrPlatform.30_8, temp_phy_id_36);
  Function call may change dynamic type:InterfacePrepare_InitTSQueue (prPfeDev_24);
  Function call may change dynamic type:autolibc_memcpy (_4, _7, 6);
Determining dynamic type for call: res_17 = InterfacePrepare_InitEmacMasterLink (prPfeDev_15(D));
  Starting walk at: res_17 = InterfacePrepare_InitEmacMasterLink (prPfeDev_15(D));
  instance pointer: prPfeDev_15(D)  Outer instance pointer: prPfeDev_15(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_19 = InterfacePrepare_InitEmacMasterRx (prPfeDev_15(D));
  Starting walk at: res_19 = InterfacePrepare_InitEmacMasterRx (prPfeDev_15(D));
  instance pointer: prPfeDev_15(D)  Outer instance pointer: prPfeDev_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_17 = InterfacePrepare_InitEmacMasterLink (prPfeDev_15(D));
Determining dynamic type for call: _2 = CreateHifDrv (6, _1, &prCommonHifChnl, &prCommonChnlIRQ, &prCommonHifDrv);
  Starting walk at: _2 = CreateHifDrv (6, _1, &prCommonHifChnl, &prCommonChnlIRQ, &prCommonHifDrv);
  instance pointer: &prCommonHifChnl  Outer instance pointer: prCommonHifChnl offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:retVal_9 = PlatformDrvPrepare_ShutdownConfigInit ();
Determining dynamic type for call: _2 = CreateHifDrv (6, _1, &prCommonHifChnl, &prCommonChnlIRQ, &prCommonHifDrv);
  Starting walk at: _2 = CreateHifDrv (6, _1, &prCommonHifChnl, &prCommonChnlIRQ, &prCommonHifDrv);
  instance pointer: &prCommonChnlIRQ  Outer instance pointer: prCommonChnlIRQ offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:retVal_9 = PlatformDrvPrepare_ShutdownConfigInit ();
Determining dynamic type for call: _2 = CreateHifDrv (6, _1, &prCommonHifChnl, &prCommonChnlIRQ, &prCommonHifDrv);
  Starting walk at: _2 = CreateHifDrv (6, _1, &prCommonHifChnl, &prCommonChnlIRQ, &prCommonHifDrv);
  instance pointer: &prCommonHifDrv  Outer instance pointer: prCommonHifDrv offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:retVal_9 = PlatformDrvPrepare_ShutdownConfigInit ();
Determining dynamic type for call: ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Starting walk at: ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  instance pointer: &state  Outer instance pointer: state offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Function call may change dynamic type:ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
Determining dynamic type for call: ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Starting walk at: ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  instance pointer: pSch_30  Outer instance pointer: pSch_30 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Function call may change dynamic type:ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
Determining dynamic type for call: ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
  Starting walk at: ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
  instance pointer: &state  Outer instance pointer: state offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Function call may change dynamic type:ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
Determining dynamic type for call: ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
  Starting walk at: ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
  instance pointer: _13  Outer instance pointer: _13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Function call may change dynamic type:ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
Determining dynamic type for call: ret_40 = ConfigureSchedulerAndShaper_MapUnusedInputs (&state, 1);
  Starting walk at: ret_40 = ConfigureSchedulerAndShaper_MapUnusedInputs (&state, 1);
  instance pointer: &state  Outer instance pointer: state offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Function call may change dynamic type:ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
Determining dynamic type for call: ret_42 = ConfigureSchedulerAndShaper_MapUnusedInputs (&state, 0);
  Starting walk at: ret_42 = ConfigureSchedulerAndShaper_MapUnusedInputs (&state, 0);
  instance pointer: &state  Outer instance pointer: state offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_40 = ConfigureSchedulerAndShaper_MapUnusedInputs (&state, 1);
  Function call may change dynamic type:ret_34 = ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0 (&state, iftmp.47_21, pSch_30);
  Function call may change dynamic type:ret_36 = ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0 (&state, iftmp.47_21, _44, _13);
Determining dynamic type for call: ret_60 = ConfigureSchedulerAndShaper_SetFifo.isra.0 (pstate_44(D), u8SchIdx_53(D), _70, _34);
  Starting walk at: ret_60 = ConfigureSchedulerAndShaper_SetFifo.isra.0 (pstate_44(D), u8SchIdx_53(D), _70, _34);
  instance pointer: pstate_44(D)  Outer instance pointer: pstate_44(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_58 = pfe_tmu_shp_set_idle_slope (_30, _31, _32, _33);
  Function call may change dynamic type:ret_56 = pfe_tmu_shp_set_position (_26, _27, _28, u8TempShpPos_54);
  Function call may change dynamic type:ret_51 = pfe_tmu_shp_set_limits (_17, _18, _19, _20, _21);
  Function call may change dynamic type:ret_48 = pfe_tmu_shp_enable (_9, _10, _11);
Determining dynamic type for call: prIRQ_12 = CreateHifDrv_Isr (u32IrqVector_10(D), prHifChnl_9);
  Starting walk at: prIRQ_12 = CreateHifDrv_Isr (u32IrqVector_10(D), prHifChnl_9);
  instance pointer: prHifChnl_9  Outer instance pointer: prHifChnl_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:prHifChnl_9 = pfe_hif_get_channel (_2, _3);
Determining dynamic type for call: prHifDrv_14 = CreateHifDrv_Init (prHifChnl_9, prIRQ_12);
  Starting walk at: prHifDrv_14 = CreateHifDrv_Init (prHifChnl_9, prIRQ_12);
  instance pointer: prHifChnl_9  Outer instance pointer: prHifChnl_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:prIRQ_12 = CreateHifDrv_Isr (u32IrqVector_10(D), prHifChnl_9);
  Function call may change dynamic type:prHifChnl_9 = pfe_hif_get_channel (_2, _3);
Determining dynamic type for call: prHifDrv_14 = CreateHifDrv_Init (prHifChnl_9, prIRQ_12);
  Starting walk at: prHifDrv_14 = CreateHifDrv_Init (prHifChnl_9, prIRQ_12);
  instance pointer: prIRQ_12  Outer instance pointer: prIRQ_12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:prIRQ_12 = CreateHifDrv_Isr (u32IrqVector_10(D), prHifChnl_9);
  Function call may change dynamic type:prHifChnl_9 = pfe_hif_get_channel (_2, _3);
Determining dynamic type for call: DestroyHifDrv (prIRQ_23(D), prHifDrv_11);
  Starting walk at: DestroyHifDrv (prIRQ_23(D), prHifDrv_11);
  instance pointer: prIRQ_23(D)  Outer instance pointer: prIRQ_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_drv_init() failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 585, "");
  Function call may change dynamic type:_1 = pfe_hif_drv_init (prHifDrv_11);
  Function call may change dynamic type:prHifDrv_11 = pfe_hif_drv_create (prHifChnl_9(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not get HIF driver instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 581, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t initialize IDEX\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 602, "");
  Function call may change dynamic type:_6 = pfe_idex_init (prHifDrv_11, _3, _5, pfe_platform_idex_rpc_cbk, ptrPlatform.23_4, 0B);
  Function call may change dynamic type:_2 = pfe_hif_drv_start (prHifDrv_11);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] HIF driver start failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 598, "");
Determining dynamic type for call: DestroyHifDrv (prIRQ_23(D), prHifDrv_11);
  Starting walk at: DestroyHifDrv (prIRQ_23(D), prHifDrv_11);
  instance pointer: prHifDrv_11  Outer instance pointer: prHifDrv_11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] pfe_hif_drv_init() failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 585, "");
  Function call may change dynamic type:_1 = pfe_hif_drv_init (prHifDrv_11);
  Function call may change dynamic type:prHifDrv_11 = pfe_hif_drv_create (prHifChnl_9(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Could not get HIF driver instance\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 581, "");
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t initialize IDEX\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 602, "");
  Function call may change dynamic type:_6 = pfe_idex_init (prHifDrv_11, _3, _5, pfe_platform_idex_rpc_cbk, ptrPlatform.23_4, 0B);
  Function call may change dynamic type:_2 = pfe_hif_drv_start (prHifDrv_11);
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] HIF driver start failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 598, "");
Determining dynamic type for call: _1 = pfe_emac_is_broad (addr_5(D));
  Starting walk at: _1 = pfe_emac_is_broad (addr_5(D));
  instance pointer: addr_5(D)  Outer instance pointer: addr_5(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Eth_PFE_LLD_ShutdownDriver.part.0/558:
    callsite  Eth_PFE_LLD_ShutdownDriver.part.0/558 -> Eth_PFE_LLD_DisableController/103 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Eth_PFE_LLD_ShutdownDriver.part.0/558 -> DestroyHifDrv/48 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  CheckDemStatus.part.0/554:
    callsite  CheckDemStatus.part.0/554 -> DetectErrorsAndLostFrame/71 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ReportReception_ProcessPacket.isra.0/553:
    callsite  ReportReception_ProcessPacket.isra.0/553 -> IsRxChecksumValid/121 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ReportReception_ProcessPacket.isra.0/553 -> ReportReception_GetBypassVLANTag/122 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  UpdatePhysAddrFilter_Close.isra.0/552:
  Jump functions of caller  UpdatePhysAddrFilter_RemoveBroad.isra.0/551:
  Jump functions of caller  UpdatePhysAddrFilter_AddBroad.isra.0/550:
  Jump functions of caller  UpdatePhysAddrFilter_RemoveMulti.isra.0/549:
  Jump functions of caller  EnableController_Common.part.0/548:
  Jump functions of caller  ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547:
    callsite  ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 -> ConfigureSchedulerAndShaper_SetShaper/66 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 -> ConfigureSchedulerAndShaper_SetFifo.isra.0/545 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546:
  Jump functions of caller  ConfigureSchedulerAndShaper_SetFifo.isra.0/545:
    callsite  ConfigureSchedulerAndShaper_SetFifo.isra.0/545 -> ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546 : 
  Jump functions of caller  ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544:
  Jump functions of caller  UpdatePhysAddrFilter_AddMulti.isra.0/543:
  Jump functions of caller  pfe_hif_chnl_from_phy_id.part.0/537:
  Jump functions of caller  oal_mutex_unlock.part.0/536:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  oal_mutex_lock.part.0/535:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 ();
  Jump functions of caller  pfe_hif_set_master_up/534:
  Jump functions of caller  pfe_hif_get_master_detect_cfg/533:
  Jump functions of caller  pfe_hif_chnl_cfg_tx_disable/532:
  Jump functions of caller  pfe_hif_chnl_cfg_rx_disable/531:
  Jump functions of caller  pfe_idex_send_dummy_frame/530:
  Jump functions of caller  pfe_hif_chnl_cfg_get_rx_bdp_rd_fifo_cnt/529:
  Jump functions of caller  pfe_hif_chnl_cfg_rx_enable/528:
  Jump functions of caller  pfe_if_db_unlock/527:
  Jump functions of caller  pfe_phy_if_get_phy/526:
  Jump functions of caller  pfe_hif_get_channel_phy/525:
  Jump functions of caller  autolibc_memset/524:
  Jump functions of caller  pfe_tmu_get_queue_stats/523:
  Jump functions of caller  pfe_tmu_get_special_stats/522:
  Jump functions of caller  pfe_tmu_get_stat_value/521:
  Jump functions of caller  pfe_rtable_get_stats/520:
  Jump functions of caller  pfe_l2br_get_domain_stats/519:
  Jump functions of caller  pfe_l2br_get_stats/518:
  Jump functions of caller  pfe_l2br_get_number_entries/517:
  Jump functions of caller  pfe_wdt_get_stat_value/516:
  Jump functions of caller  pfe_gpi_get_special_stats/515:
  Jump functions of caller  pfe_gpi_shp_get_drop_cnt/514:
  Jump functions of caller  pfe_gpi_get_stat_value/513:
  Jump functions of caller  pfe_bmu_get_special_stats/512:
  Jump functions of caller  pfe_bmu_get_stat_value/511:
  Jump functions of caller  __builtin_expect/510:
  Jump functions of caller  pfe_class_get_stats/509:
  Jump functions of caller  oal_util_parse_ptp/508:
  Jump functions of caller  pfe_emac_set_ts_freq_adjustment/507:
  Jump functions of caller  pfe_emac_adjust_ts_time/506:
  Jump functions of caller  pfe_emac_get_ts_time/505:
  Jump functions of caller  pfe_emac_set_ts_time/504:
  Jump functions of caller  pfe_emac_mdio_read45/503:
  Jump functions of caller  pfe_emac_mdio_write45/502:
  Jump functions of caller  pfe_emac_mdio_read22/501:
  Jump functions of caller  pfe_emac_mdio_unlock/500:
  Jump functions of caller  pfe_emac_mdio_write22/499:
  Jump functions of caller  pfe_emac_mdio_lock/498:
  Jump functions of caller  pfe_hif_irq_unmask/497:
  Jump functions of caller  pfe_hif_isr/496:
  Jump functions of caller  pfe_hif_irq_mask/495:
  Jump functions of caller  pfe_util_irq_unmask/494:
  Jump functions of caller  pfe_util_isr/493:
  Jump functions of caller  pfe_util_irq_mask/492:
  Jump functions of caller  pfe_class_irq_unmask/491:
  Jump functions of caller  pfe_class_isr/490:
  Jump functions of caller  pfe_class_irq_mask/489:
  Jump functions of caller  pfe_bmu_irq_unmask/488:
  Jump functions of caller  pfe_bmu_isr/487:
  Jump functions of caller  pfe_bmu_irq_mask/486:
  Jump functions of caller  pfe_host_fail_stop_irq_unmask/485:
  Jump functions of caller  pfe_host_fail_stop_isr/484:
  Jump functions of caller  pfe_host_fail_stop_irq_mask/483:
  Jump functions of caller  pfe_fw_fail_stop_irq_unmask/482:
  Jump functions of caller  pfe_fw_fail_stop_isr/481:
  Jump functions of caller  pfe_fw_fail_stop_irq_mask/480:
  Jump functions of caller  pfe_fail_stop_irq_unmask/479:
  Jump functions of caller  pfe_fail_stop_isr/478:
  Jump functions of caller  pfe_fail_stop_irq_mask/477:
  Jump functions of caller  pfe_parity_irq_unmask/476:
  Jump functions of caller  pfe_parity_isr/475:
  Jump functions of caller  pfe_parity_irq_mask/474:
  Jump functions of caller  pfe_bus_err_irq_unmask/473:
  Jump functions of caller  pfe_bus_err_isr/472:
  Jump functions of caller  pfe_bus_err_irq_mask/471:
  Jump functions of caller  pfe_emac_irq_unmask/470:
  Jump functions of caller  pfe_emac_isr/469:
  Jump functions of caller  pfe_emac_irq_mask/468:
  Jump functions of caller  pfe_wdt_irq_unmask/467:
  Jump functions of caller  pfe_wdt_isr/466:
  Jump functions of caller  pfe_wdt_irq_mask/465:
  Jump functions of caller  pfe_ecc_err_irq_unmask/464:
  Jump functions of caller  pfe_ecc_err_isr/463:
  Jump functions of caller  pfe_ecc_err_irq_mask/462:
  Jump functions of caller  pfe_emac_get_stat_value/461:
  Jump functions of caller  pfe_hif_drv_client_ptp_ts_db_tick_iteration/460:
  Jump functions of caller  Dem_SetEventStatus/459:
  Jump functions of caller  EthIf_CtrlModeIndication/458:
  Jump functions of caller  pfe_rtable_do_timeouts/457:
  Jump functions of caller  pfe_hif_drv_client_get_ts/456:
  Jump functions of caller  pfe_hif_drv_client_tx_done/455:
  Jump functions of caller  pfe_hif_drv_client_receive_tx_conf/454:
  Jump functions of caller  pfe_hif_pkt_free/453:
  Jump functions of caller  EthIf_RxIndication/452:
  Jump functions of caller  pfe_hif_drv_client_has_rx_pkt/450:
  Jump functions of caller  pfe_hif_drv_client_rx_done/449:
  Jump functions of caller  pfe_hif_drv_client_receive_pkt/448:
  Jump functions of caller  pfe_hif_drv_client_xmit_pkt/447:
  Jump functions of caller  EthIf_TxConfirmation/446:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/445:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/444:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/443:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/442:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/441:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/440:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/439:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/438:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/437:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/436:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/435:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/434:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/433:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/432:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/431:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/430:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/429:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/428:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/427:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/426:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/425:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/424:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/423:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/422:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/421:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/420:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/419:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/418:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/417:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/416:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/415:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/414:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/413:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/412:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/411:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/410:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/409:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/408:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/407:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/406:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/405:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/404:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/403:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/402:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/401:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/400:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/399:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/398:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/397:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/396:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/395:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/394:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/393:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/392:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/391:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/390:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/389:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/388:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/387:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/386:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/385:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/384:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/383:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/382:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/381:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/380:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/379:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/378:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/377:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/376:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/375:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/374:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/373:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/372:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/371:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/370:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/369:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/368:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/367:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/366:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/365:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/364:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/363:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/362:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/361:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/360:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/359:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/358:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/357:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/356:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/355:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/354:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/353:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/352:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/351:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/350:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/349:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/348:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/347:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/346:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/345:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/344:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/343:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/342:
  Jump functions of caller  SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/341:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/340:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/339:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/338:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/337:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/336:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/335:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/334:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/333:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/332:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/331:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/330:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/329:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/328:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/327:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/326:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/325:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/324:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/323:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/322:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/321:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/320:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/319:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/318:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/317:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/316:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/315:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/314:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/313:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/312:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/311:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/310:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/309:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/308:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/307:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/306:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/305:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/304:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/303:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/302:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/301:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/300:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/299:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/298:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/297:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/296:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/295:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/294:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/293:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/292:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/291:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/290:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/289:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/288:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/287:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/286:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/285:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/284:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/283:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/282:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/281:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/280:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/279:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/278:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/277:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/276:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/275:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/274:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/273:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/272:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/271:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/270:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/269:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/268:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/267:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/266:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/265:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/264:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/263:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/262:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/261:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/260:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/259:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/258:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/257:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/256:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/255:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/254:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/253:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/252:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/251:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/250:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/249:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/248:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/247:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/246:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/245:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/244:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/243:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/242:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/241:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/240:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/239:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/238:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/237:
  Jump functions of caller  SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/236:
  Jump functions of caller  pfe_phy_if_flush_mac_addrs/235:
  Jump functions of caller  pfe_phy_if_allmulti_disable/234:
  Jump functions of caller  pfe_phy_if_allmulti_enable/233:
  Jump functions of caller  Det_ReportError/232:
  Jump functions of caller  pfe_phy_if_del_mac_addr/231:
  Jump functions of caller  autolibc_memcmp/230:
  Jump functions of caller  pfe_hif_drv_client_unregister/229:
  Jump functions of caller  pfe_hif_drv_client_set_inject_if/228:
  Jump functions of caller  pfe_hif_drv_client_register/227:
  Jump functions of caller  pfe_phy_if_get_id/226:
  Jump functions of caller  pfe_hif_drv_init_tx_header/225:
  Jump functions of caller  pfe_hif_drv_aux_client_register/223:
  Jump functions of caller  fifo_create/222:
  Jump functions of caller  pfe_tmu_shp_set_idle_slope/220:
  Jump functions of caller  pfe_tmu_shp_set_position/219:
  Jump functions of caller  pfe_tmu_shp_set_limits/218:
  Jump functions of caller  pfe_tmu_shp_enable/217:
  Jump functions of caller  pfe_tmu_sch_bind_queue/215:
  Jump functions of caller  pfe_tmu_sch_bind_sch_output/214:
  Jump functions of caller  pfe_tmu_sch_set_input_weight/213:
  Jump functions of caller  pfe_tmu_sch_set_algo/212:
  Jump functions of caller  pfe_tmu_sch_set_rate_mode/211:
  Jump functions of caller  pfe_log_if_get_name/210:
  Jump functions of caller  pfe_log_if_set_egress_ifs/209:
  Jump functions of caller  pfe_phy_if_get_name/208:
  Jump functions of caller  pfe_phy_if_get_default_log_if/207:
  Jump functions of caller  pfe_phy_if_add_mac_addr/206:
  Jump functions of caller  pfe_phy_if_promisc_disable/205:
  Jump functions of caller  pfe_phy_if_promisc_enable/204:
  Jump functions of caller  pfe_emac_set_link_duplex/203:
  Jump functions of caller  pfe_emac_set_link_speed/202:
  Jump functions of caller  pfe_phy_if_get_emac/201:
  Jump functions of caller  pfe_phy_if_loopback_enable/200:
  Jump functions of caller  autolibc_memcpy/199:
  Jump functions of caller  pfe_phy_if_enable/197:
  Jump functions of caller  pfe_platform_idex_rpc_cbk/196:
  Jump functions of caller  pfe_idex_init/195:
  Jump functions of caller  pfe_hif_drv_start/194:
  Jump functions of caller  pfe_hif_drv_init/193:
  Jump functions of caller  pfe_hif_drv_create/192:
  Jump functions of caller  pfe_hif_chnl_isr/191:
  Jump functions of caller  pfe_hif_chnl_irq_mask/190:
  Jump functions of caller  oal_irq_add_handler/189:
  Jump functions of caller  oal_irq_create/188:
  Jump functions of caller  pfe_hif_chnl_irq_unmask/187:
  Jump functions of caller  oal_mm_dev_unmap/186:
  Jump functions of caller  oal_mm_dev_map/185:
  Jump functions of caller  pfe_hif_drv_destroy/183:
  Jump functions of caller  pfe_idex_fini/182:
  Jump functions of caller  pfe_hif_chnl_tx_irq_unmask/181:
  Jump functions of caller  pfe_hif_chnl_rx_irq_unmask/180:
  Jump functions of caller  pfe_hif_chnl_tx_enable/179:
  Jump functions of caller  pfe_hif_chnl_rx_enable/178:
  Jump functions of caller  pfe_hif_chnl_inspect_hw_state/177:
  Jump functions of caller  pfe_hif_get_channel/176:
  Jump functions of caller  pfe_phy_if_disable/175:
  Jump functions of caller  pfe_platform_get_phy_if_by_id/174:
  Jump functions of caller  pfe_platform_remove/173:
  Jump functions of caller  pfe_platform_remove_sw_if/172:
  Jump functions of caller  oal_irq_destroy/171:
  Jump functions of caller  pfe_platform_get_instance/170:
  Jump functions of caller  pfe_platform_init/169:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/167:
  Jump functions of caller  pfe_hm_report/166:
  Jump functions of caller  Eth_43_PFE_LLD_SetMasterUp/164:
  Jump functions of caller  Eth_PFE_LLD_ChannelBdFlushRx/163:
    callsite  Eth_PFE_LLD_ChannelBdFlushRx/163 -> ChannelBdFlushRxExecute/78 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Eth_PFE_LLD_ChannelBdFlushRx/163 -> ChannelBdFlushRxPrepare/77 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_GetTxErrorCounterValues/162:
    callsite  Eth_PFE_LLD_GetTxErrorCounterValues/162 -> Eth_PFE_LLD_GetEmacInstanceByControllerId/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_GetTxStats/161:
    callsite  Eth_PFE_LLD_GetTxStats/161 -> Eth_PFE_LLD_GetEmacInstanceByControllerId/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_GetRxStats/160:
    callsite  Eth_PFE_LLD_GetRxStats/160 -> Eth_PFE_LLD_GetEmacInstanceByControllerId/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_GetCounterValues/159:
    callsite  Eth_PFE_LLD_GetCounterValues/159 -> Eth_PFE_LLD_GetEmacInstanceByControllerId/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Eth_43_PFE_LLD_GetTmuStats/158:
  Jump functions of caller  Eth_43_PFE_LLD_GetRtableStats/157:
  Jump functions of caller  Eth_43_PFE_LLD_GetL2BridgeDomainStats/156:
  Jump functions of caller  Eth_43_PFE_LLD_GetL2BridgeStats/155:
  Jump functions of caller  Eth_43_PFE_LLD_GetWdtStats/154:
  Jump functions of caller  Eth_43_PFE_LLD_GetGpiStats/153:
  Jump functions of caller  Eth_43_PFE_LLD_GetBmuStats/152:
  Jump functions of caller  Eth_43_PFE_LLD_GetClassStats/151:
  Jump functions of caller  Eth_PFE_LLD_GetPlatform/150:
  Jump functions of caller  Eth_43_PFE_LLD_GetTxTimeStamp/149:
  Jump functions of caller  Eth_43_PFE_LLD_GetRxTimeStamp/148:
  Jump functions of caller  Eth_43_PFE_LLD_EnableEgressTimeStamp/147:
  Jump functions of caller  Eth_43_PFE_LLD_SetCorrectionTime/146:
    callsite  Eth_43_PFE_LLD_SetCorrectionTime/146 -> EmacTsAdjustRatio/145 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  EmacTsAdjustRatio/145:
  Jump functions of caller  Eth_43_PFE_LLD_GetCurrentTime/144:
  Jump functions of caller  Eth_43_PFE_LLD_SetGlobalTime/143:
  Jump functions of caller  Eth_43_PFE_LLD_ReadMii45/142:
  Jump functions of caller  Eth_43_PFE_LLD_WriteMii45/141:
  Jump functions of caller  Eth_43_PFE_LLD_ReadMii/140:
  Jump functions of caller  Eth_43_PFE_LLD_WriteMii/139:
  Jump functions of caller  Eth_PFE_LLD_MainFunction/138:
    callsite  Eth_PFE_LLD_MainFunction/138 -> Eth_PFE_LLD_PollerFunction/137 : 
    callsite  Eth_PFE_LLD_MainFunction/138 -> Eth_PFE_LLD_ReportTransmissionTS/126 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_MainFunction/138 -> CheckDemStatus/72 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_PollerFunction/137:
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_HIF/136 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_UTIL/135 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_CLASS/134 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_BMU/133 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_FAILSTOP/132 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_PARITY/131 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_BUS/130 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_EMAC/129 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_WDG/128 : 
    callsite  Eth_PFE_LLD_PollerFunction/137 -> Eth_PFE_LLD_PollerFunction_ECC/127 : 
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_HIF/136:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_UTIL/135:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_CLASS/134:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_BMU/133:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_FAILSTOP/132:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_PARITY/131:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_BUS/130:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_EMAC/129:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_WDG/128:
  Jump functions of caller  Eth_PFE_LLD_PollerFunction_ECC/127:
  Jump functions of caller  Eth_PFE_LLD_ReportTransmissionTS/126:
    callsite  Eth_PFE_LLD_ReportTransmissionTS/126 -> oal_mutex_unlock.part.0/536 : 
       param 0: CONST: 18
         value: 0x12, mask: 0x0
         Unknown VR
    callsite  Eth_PFE_LLD_ReportTransmissionTS/126 -> oal_mutex_unlock.part.0/536 : 
       param 0: CONST: 21
         value: 0x15, mask: 0x0
         Unknown VR
    callsite  Eth_PFE_LLD_ReportTransmissionTS/126 -> oal_mutex_lock.part.0/535 : 
       param 0: CONST: 21
         value: 0x15, mask: 0x0
         Unknown VR
    callsite  Eth_PFE_LLD_ReportTransmissionTS/126 -> GetTxTimeStamp/64 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
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
    callsite  Eth_PFE_LLD_ReportTransmissionTS/126 -> oal_mutex_lock.part.0/535 : 
       param 0: CONST: 18
         value: 0x12, mask: 0x0
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_ReportTransmission/125:
    callsite  Eth_PFE_LLD_ReportTransmission/125 -> oal_mutex_unlock.part.0/536 : 
       param 0: CONST: 20
         value: 0x14, mask: 0x0
         Unknown VR
    callsite  Eth_PFE_LLD_ReportTransmission/125 -> oal_mutex_lock.part.0/535 : 
       param 0: CONST: 20
         value: 0x14, mask: 0x0
         Unknown VR
    callsite  Eth_PFE_LLD_ReportTransmission/125 -> TxReqQueueDelete/59 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_ReportReception/124:
    callsite  Eth_PFE_LLD_ReportReception/124 -> ReportReception_ProcessPacket.isra.0/553 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ReportReception_GetBypassVLANTag/122:
  Jump functions of caller  IsRxChecksumValid/121:
    callsite  IsRxChecksumValid/121 -> IsRxChecksumValidIpV6/120 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  IsRxChecksumValid/121 -> IsRxChecksumValidIpV4/119 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  IsRxChecksumValidIpV6/120:
    callsite  IsRxChecksumValidIpV6/120 -> pfe_hif_pkt_icmp_csum_valid/18 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  IsRxChecksumValidIpV6/120 -> pfe_hif_pkt_tcpv6_csum_valid/17 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  IsRxChecksumValidIpV6/120 -> pfe_hif_pkt_udpv6_csum_valid/15 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  IsRxChecksumValidIpV4/119:
    callsite  IsRxChecksumValidIpV4/119 -> pfe_hif_pkt_icmp_csum_valid/18 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  IsRxChecksumValidIpV4/119 -> pfe_hif_pkt_tcpv4_csum_valid/16 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  IsRxChecksumValidIpV4/119 -> pfe_hif_pkt_udpv4_csum_valid/14 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_Transmit/118:
    callsite  Eth_PFE_LLD_Transmit/118 -> TxReqFailed/56 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_Transmit/118 -> TxReqTrigger/55 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op plus_expr 14
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  Eth_PFE_LLD_Transmit/118 -> TxReqTsQueueWrite/54 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_ReleaseTxBuffer/117:
  Jump functions of caller  Eth_43_PFE_LLD_GetTxBufferSize/116:
  Jump functions of caller  Eth_43_PFE_LLD_GetTxFifoIdx/115:
  Jump functions of caller  Eth_43_PFE_LLD_GetLmemHdrSize/114:
  Jump functions of caller  Eth_PFE_LLD_ProvideBufferDataArea/113:
    callsite  Eth_PFE_LLD_ProvideBufferDataArea/113 -> GetTxBuffer/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  Eth_PFE_LLD_UpdatePhysAddrFilter/112:
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> UpdatePhysAddrFilter_RemoveMulti.isra.0/549 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> UpdatePhysAddrFilter_AddMulti.isra.0/543 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> pfe_emac_is_multi/7 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> UpdatePhysAddrFilter_Close.isra.0/552 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> pfe_emac_is_zero/5 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> UpdatePhysAddrFilter_RemoveBroad.isra.0/551 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> UpdatePhysAddrFilter_AddBroad.isra.0/550 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Eth_PFE_LLD_UpdatePhysAddrFilter/112 -> pfe_emac_is_broad/6 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_SetPhysAddr/106:
  Jump functions of caller  Eth_PFE_LLD_GetPhysicalAddress/105:
  Jump functions of caller  Eth_PFE_LLD_CheckControllerIsActive/104:
  Jump functions of caller  Eth_PFE_LLD_DisableController/103:
    callsite  Eth_PFE_LLD_DisableController/103 -> ReleaseAllCtrlTxBuffers/53 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_EnableController/102:
    callsite  Eth_PFE_LLD_EnableController/102 -> EnableController_HifEmac/101 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  Eth_PFE_LLD_EnableController/102 -> EnableController_HifEmac/101 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  Eth_PFE_LLD_EnableController/102 -> EnableController_Aux/100 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  Eth_PFE_LLD_EnableController/102 -> EnableController_InitFifos/98 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  EnableController_HifEmac/101:
    callsite  EnableController_HifEmac/101 -> EnableController_Common/99 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  EnableController_Aux/100:
    callsite  EnableController_Aux/100 -> EnableController_Common/99 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  EnableController_Common/99:
    callsite  EnableController_Common/99 -> EnableController_Common.part.0/548 : 
    callsite  EnableController_Common/99 -> InitializeTxHeaders/50 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  EnableController_InitFifos/98:
  Jump functions of caller  Eth_PFE_LLD_CheckInitializationStatus/97:
  Jump functions of caller  Eth_PFE_LLD_CheckAccessToController/96:
  Jump functions of caller  Eth_PFE_LLD_Check_Driver_Init/95:
  Jump functions of caller  Eth_PFE_LLD_ConfigureController/94:
  Jump functions of caller  Eth_PFE_LLD_EMACPrepare/93:
    callsite  Eth_PFE_LLD_EMACPrepare/93 -> Eth_PFE_LLD_EMACPrepare_Config/92 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Eth_PFE_LLD_EMACPrepare_Config/92:
  Jump functions of caller  Eth_PFE_LLD_InterfacePrepare/91:
    callsite  Eth_PFE_LLD_InterfacePrepare/91 -> InterfacePrepare_MasterConfigEMAC/89 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  Eth_PFE_LLD_InterfacePrepare/91 -> InterfacePrepare_InitTSQueue/87 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  InterfacePrepare_InitEmacMasterLink/90:
  Jump functions of caller  InterfacePrepare_MasterConfigEMAC/89:
    callsite  InterfacePrepare_MasterConfigEMAC/89 -> ConfigureSchedulerAndShaper/70 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  InterfacePrepare_MasterConfigEMAC/89 -> InterfacePrepare_InitEmacMasterRx/88 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  InterfacePrepare_MasterConfigEMAC/89 -> InterfacePrepare_InitEmacMasterLink/90 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  InterfacePrepare_InitEmacMasterRx/88:
  Jump functions of caller  InterfacePrepare_InitTSQueue/87:
  Jump functions of caller  Eth_PFE_LLD_DeInit/86:
    callsite  Eth_PFE_LLD_DeInit/86 -> Eth_PFE_LLD_ShutdownDriver/75 : 
    callsite  Eth_PFE_LLD_DeInit/86 -> Eth_PFE_LLD_Check_Driver_Init/95 : 
  Jump functions of caller  Eth_PFE_LLD_PlatformDrvPrepare/85:
    callsite  Eth_PFE_LLD_PlatformDrvPrepare/85 -> PlatformDrvPrepare_EnablePhyIf/83 : 
    callsite  Eth_PFE_LLD_PlatformDrvPrepare/85 -> CreateHifDrv/47 : 
       param 0: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: &prCommonHifChnl
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: CONST: &prCommonChnlIRQ
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 4: CONST: &prCommonHifDrv
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  Eth_PFE_LLD_PlatformDrvPrepare/85 -> PlatformDrvPrepare_ShutdownConfigInit/84 : 
  Jump functions of caller  PlatformDrvPrepare_ShutdownConfigInit/84:
    callsite  PlatformDrvPrepare_ShutdownConfigInit/84 -> hal_ip_ready_set/1 : 
       param 0: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  PlatformDrvPrepare_ShutdownConfigInit/84 -> ConfigureTxBuffers/49 : 
    callsite  PlatformDrvPrepare_ShutdownConfigInit/84 -> Eth_PFE_LLD_ShutdownDriver/75 : 
  Jump functions of caller  PlatformDrvPrepare_EnablePhyIf/83:
  Jump functions of caller  Eth_PFE_LLD_InitEMACs/82:
  Jump functions of caller  Eth_PFE_LLD_InitInterfaces/81:
  Jump functions of caller  Eth_PFE_LLD_GetTxBufTsRef/80:
  Jump functions of caller  Eth_PFE_LLD_GetTxBufMeta/79:
  Jump functions of caller  ChannelBdFlushRxExecute/78:
  Jump functions of caller  ChannelBdFlushRxPrepare/77:
  Jump functions of caller  Eth_PFE_LLD_GetEmacInstanceByControllerId/76:
  Jump functions of caller  Eth_PFE_LLD_ShutdownDriver/75:
    callsite  Eth_PFE_LLD_ShutdownDriver/75 -> Eth_PFE_LLD_ShutdownDriver.part.0/558 : 
    callsite  Eth_PFE_LLD_ShutdownDriver/75 -> Eth_PFE_LLD_DetectHardReset/74 : 
  Jump functions of caller  Eth_PFE_LLD_DetectHardReset/74:
  Jump functions of caller  CheckDemStatus/72:
    callsite  CheckDemStatus/72 -> CheckDemStatus.part.0/554 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  DetectErrorsAndLostFrame/71:
    callsite  DetectErrorsAndLostFrame/71 -> Eth_PFE_LLD_GetEmacInstanceByControllerId/76 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ConfigureSchedulerAndShaper/70:
    callsite  ConfigureSchedulerAndShaper/70 -> ConfigureSchedulerAndShaper_MapUnusedInputs/69 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  ConfigureSchedulerAndShaper/70 -> ConfigureSchedulerAndShaper_MapUnusedInputs/69 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  ConfigureSchedulerAndShaper/70 -> ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  ConfigureSchedulerAndShaper/70 -> ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  ConfigureSchedulerAndShaper_MapUnusedInputs/69:
  Jump functions of caller  ConfigureSchedulerAndShaper_SetShaper/66:
    callsite  ConfigureSchedulerAndShaper_SetShaper/66 -> ConfigureSchedulerAndShaper_SetFifo.isra.0/545 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  GetTxTimeStamp/64:
  Jump functions of caller  ClientEventHdlr/63:
    callsite  ClientEventHdlr/63 -> ClientEventHdlr_ETS/62 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ClientEventHdlr/63 -> ClientEventHdlr_TX/61 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  ClientEventHdlr/63 -> ClientEventHdlr_RX/60 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ClientEventHdlr_ETS/62:
    callsite  ClientEventHdlr_ETS/62 -> Eth_PFE_LLD_ReportTransmissionTS/126 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ClientEventHdlr_TX/61:
    callsite  ClientEventHdlr_TX/61 -> Eth_PFE_LLD_ReportTransmission/125 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  ClientEventHdlr_RX/60:
    callsite  ClientEventHdlr_RX/60 -> Eth_PFE_LLD_ReportReception/124 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  TxReqQueueDelete/59:
  Jump functions of caller  TxReqQueueWrite/57:
  Jump functions of caller  TxReqFailed/56:
  Jump functions of caller  TxReqTrigger/55:
    callsite  TxReqTrigger/55 -> TxReqQueueWrite/57 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  TxReqTsQueueWrite/54:
    callsite  TxReqTsQueueWrite/54 -> oal_mutex_unlock.part.0/536 : 
       param 0: CONST: 17
         value: 0x11, mask: 0x0
         Unknown VR
    callsite  TxReqTsQueueWrite/54 -> oal_mutex_lock.part.0/535 : 
       param 0: CONST: 17
         value: 0x11, mask: 0x0
         Unknown VR
  Jump functions of caller  ReleaseAllCtrlTxBuffers/53:
  Jump functions of caller  GetTxBuffer/51:
    callsite  GetTxBuffer/51 -> oal_mutex_unlock.part.0/536 : 
       param 0: CONST: 19
         value: 0x13, mask: 0x0
         Unknown VR
    callsite  GetTxBuffer/51 -> oal_mutex_lock.part.0/535 : 
       param 0: CONST: 19
         value: 0x13, mask: 0x0
         Unknown VR
  Jump functions of caller  InitializeTxHeaders/50:
  Jump functions of caller  ConfigureTxBuffers/49:
  Jump functions of caller  DestroyHifDrv/48:
  Jump functions of caller  CreateHifDrv/47:
    callsite  CreateHifDrv/47 -> CreateHifDrv_Init/45 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  CreateHifDrv/47 -> CreateHifDrv_Isr/46 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  CreateHifDrv/47 -> pfe_hif_chnl_from_phy_id/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  CreateHifDrv_Isr/46:
  Jump functions of caller  CreateHifDrv_Init/45:
    callsite  CreateHifDrv_Init/45 -> DestroyHifDrv/48 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  CommonHifChnlISR/44:
  Jump functions of caller  pfe_hif_chnl_from_phy_id/24:
    callsite  pfe_hif_chnl_from_phy_id/24 -> pfe_hif_chnl_from_phy_id.part.0/537 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_hif_pkt_icmp_csum_valid/18:
  Jump functions of caller  pfe_hif_pkt_tcpv6_csum_valid/17:
  Jump functions of caller  pfe_hif_pkt_tcpv4_csum_valid/16:
  Jump functions of caller  pfe_hif_pkt_udpv6_csum_valid/15:
  Jump functions of caller  pfe_hif_pkt_udpv4_csum_valid/14:
  Jump functions of caller  pfe_emac_is_multi/7:
    callsite  pfe_emac_is_multi/7 -> pfe_emac_is_broad/6 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_emac_is_broad/6:
  Jump functions of caller  pfe_emac_is_zero/5:
  Jump functions of caller  hal_ip_ready_set/1:

 Propagating constants:

Not considering Eth_43_PFE_LLD_SetMasterUp for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_ChannelBdFlushRx for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetTxErrorCounterValues for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetTxStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetRxStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetCounterValues for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetTmuStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetRtableStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetL2BridgeDomainStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetL2BridgeStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetWdtStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetGpiStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetBmuStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetClassStats for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetPlatform for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetTxTimeStamp for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetRxTimeStamp for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_EnableEgressTimeStamp for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_SetCorrectionTime for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetCurrentTime for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_SetGlobalTime for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_ReadMii45 for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_WriteMii45 for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_ReadMii for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_WriteMii for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_MainFunction for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_ReportTransmissionTS for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_ReportTransmission for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_ReportReception for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_Transmit for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_ReleaseTxBuffer for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetTxBufferSize for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetTxFifoIdx for cloning; -fipa-cp-clone disabled.
Not considering Eth_43_PFE_LLD_GetLmemHdrSize for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_ProvideBufferDataArea for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_UpdatePhysAddrFilter for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_SetPhysAddr for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetPhysicalAddress for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_CheckControllerIsActive for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_DisableController for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_EnableController for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_CheckInitializationStatus for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_CheckAccessToController for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_Check_Driver_Init for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_ConfigureController for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_EMACPrepare for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_InterfacePrepare for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_DeInit for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_PlatformDrvPrepare for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_InitEMACs for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_InitInterfaces for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetTxBufTsRef for cloning; -fipa-cp-clone disabled.
Not considering Eth_PFE_LLD_GetTxBufMeta for cloning; -fipa-cp-clone disabled.
Not considering ClientEventHdlr for cloning; -fipa-cp-clone disabled.
Not considering CommonHifChnlISR for cloning; -fipa-cp-clone disabled.

overall_size: 4497, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 1, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 14, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 16, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 21, time_benefit: 1.000000
 - context independent values, size: 36, time_benefit: 4.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 2, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 2, time_benefit: 4.565600
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 14, time_benefit: 2.400000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: Eth_PFE_LLD_ShutdownDriver.part.0/558:
  Node: CheckDemStatus.part.0/554:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
    param [1]: 7 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               6 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               5 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               4 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               3 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               2 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               1 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               0 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x7, mask = 0x7
         ErrorIdType [0, 7]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ReportReception_ProcessPacket.isra.0/553:
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
  Node: UpdatePhysAddrFilter_Close.isra.0/552:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct pfe_phy_if_t * const * ~[0B, 0B]
        AGGS VARIABLE
  Node: UpdatePhysAddrFilter_RemoveBroad.isra.0/551:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: UpdatePhysAddrFilter_AddBroad.isra.0/550:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: UpdatePhysAddrFilter_RemoveMulti.isra.0/549:
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
  Node: EnableController_Common.part.0/548:
  Node: ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct ConfigureSchedulerAndShaper_StateType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         uint8 [0, 1]
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
  Node: ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546:
  Node: ConfigureSchedulerAndShaper_SetFifo.isra.0/545:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct ConfigureSchedulerAndShaper_StateType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         uint8 [0, 1]
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
  Node: ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const pfe_ct_phy_if_id_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         uint8 [0, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: UpdatePhysAddrFilter_AddMulti.isra.0/543:
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
  Node: pfe_hif_chnl_from_phy_id.part.0/537:
    param [0]: 6 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x6, mask = 0x0
         pfe_ct_phy_if_id_t [6, 6]
        AGGS VARIABLE
  Node: oal_mutex_unlock.part.0/536:
    param [0]: 19 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               17 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               20 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               21 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               18 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x12, mask = 0x7
         const oal_mutex_t [17, 21]
        AGGS VARIABLE
  Node: oal_mutex_lock.part.0/535:
    param [0]: 19 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               17 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               20 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               18 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
               21 [loc_time: 1, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x15, mask = 0x7
         const oal_mutex_t [17, 21]
        AGGS VARIABLE
  Node: Eth_43_PFE_LLD_SetMasterUp/164:
  Node: Eth_PFE_LLD_ChannelBdFlushRx/163:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_GetTxErrorCounterValues/162:
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
  Node: Eth_PFE_LLD_GetTxStats/161:
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
  Node: Eth_PFE_LLD_GetRxStats/160:
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
  Node: Eth_PFE_LLD_GetCounterValues/159:
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
  Node: Eth_43_PFE_LLD_GetTmuStats/158:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_43_PFE_LLD_GetRtableStats/157:
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
  Node: Eth_43_PFE_LLD_GetL2BridgeDomainStats/156:
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
  Node: Eth_43_PFE_LLD_GetL2BridgeStats/155:
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
  Node: Eth_43_PFE_LLD_GetWdtStats/154:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_43_PFE_LLD_GetGpiStats/153:
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
  Node: Eth_43_PFE_LLD_GetBmuStats/152:
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
  Node: Eth_43_PFE_LLD_GetClassStats/151:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_GetPlatform/150:
  Node: Eth_43_PFE_LLD_GetTxTimeStamp/149:
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
  Node: Eth_43_PFE_LLD_GetRxTimeStamp/148:
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
  Node: Eth_43_PFE_LLD_EnableEgressTimeStamp/147:
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
  Node: Eth_43_PFE_LLD_SetCorrectionTime/146:
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
  Node: EmacTsAdjustRatio/145:
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
  Node: Eth_43_PFE_LLD_GetCurrentTime/144:
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
  Node: Eth_43_PFE_LLD_SetGlobalTime/143:
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
  Node: Eth_43_PFE_LLD_ReadMii45/142:
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
  Node: Eth_43_PFE_LLD_WriteMii45/141:
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
  Node: Eth_43_PFE_LLD_ReadMii/140:
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
  Node: Eth_43_PFE_LLD_WriteMii/139:
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
  Node: Eth_PFE_LLD_MainFunction/138:
  Node: Eth_PFE_LLD_PollerFunction/137:
  Node: Eth_PFE_LLD_PollerFunction_HIF/136:
  Node: Eth_PFE_LLD_PollerFunction_UTIL/135:
  Node: Eth_PFE_LLD_PollerFunction_CLASS/134:
  Node: Eth_PFE_LLD_PollerFunction_BMU/133:
  Node: Eth_PFE_LLD_PollerFunction_FAILSTOP/132:
  Node: Eth_PFE_LLD_PollerFunction_PARITY/131:
  Node: Eth_PFE_LLD_PollerFunction_BUS/130:
  Node: Eth_PFE_LLD_PollerFunction_EMAC/129:
  Node: Eth_PFE_LLD_PollerFunction_WDG/128:
  Node: Eth_PFE_LLD_PollerFunction_ECC/127:
  Node: Eth_PFE_LLD_ReportTransmissionTS/126:
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
  Node: Eth_PFE_LLD_ReportTransmission/125:
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
  Node: Eth_PFE_LLD_ReportReception/124:
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
  Node: ReportReception_GetBypassVLANTag/122:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: IsRxChecksumValid/121:
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
  Node: IsRxChecksumValidIpV6/120:
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
  Node: IsRxChecksumValidIpV4/119:
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
  Node: Eth_PFE_LLD_Transmit/118:
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
  Node: Eth_PFE_LLD_ReleaseTxBuffer/117:
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
  Node: Eth_43_PFE_LLD_GetTxBufferSize/116:
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
  Node: Eth_43_PFE_LLD_GetTxFifoIdx/115:
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
  Node: Eth_43_PFE_LLD_GetLmemHdrSize/114:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_ProvideBufferDataArea/113:
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
  Node: Eth_PFE_LLD_UpdatePhysAddrFilter/112:
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
  Node: Eth_PFE_LLD_SetPhysAddr/106:
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
  Node: Eth_PFE_LLD_GetPhysicalAddress/105:
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
  Node: Eth_PFE_LLD_CheckControllerIsActive/104:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_DisableController/103:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_EnableController/102:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: EnableController_HifEmac/101:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct trPfeDev * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_client_rx_tx_count * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_client_fifo_queue * ~[0B, 0B]
        AGGS VARIABLE
  Node: EnableController_Aux/100:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct trPfeDev * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_client_rx_tx_count * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_client_fifo_queue * ~[0B, 0B]
        AGGS VARIABLE
  Node: EnableController_Common/99:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct trPfeDev * ~[0B, 0B]
        AGGS VARIABLE
  Node: EnableController_InitFifos/98:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Eth_PFE_LLD_CheckInitializationStatus/97:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_CheckAccessToController/96:
  Node: Eth_PFE_LLD_Check_Driver_Init/95:
  Node: Eth_PFE_LLD_ConfigureController/94:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_EMACPrepare/93:
  Node: Eth_PFE_LLD_EMACPrepare_Config/92:
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
  Node: Eth_PFE_LLD_InterfacePrepare/91:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: InterfacePrepare_InitEmacMasterLink/90:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct trPfeDev * ~[0B, 0B]
        AGGS VARIABLE
  Node: InterfacePrepare_MasterConfigEMAC/89:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct trPfeDev * ~[0B, 0B]
        AGGS VARIABLE
  Node: InterfacePrepare_InitEmacMasterRx/88:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct trPfeDev * ~[0B, 0B]
        AGGS VARIABLE
  Node: InterfacePrepare_InitTSQueue/87:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct trPfeDev * ~[0B, 0B]
        AGGS VARIABLE
  Node: Eth_PFE_LLD_DeInit/86:
  Node: Eth_PFE_LLD_PlatformDrvPrepare/85:
  Node: PlatformDrvPrepare_ShutdownConfigInit/84:
  Node: PlatformDrvPrepare_EnablePhyIf/83:
  Node: Eth_PFE_LLD_InitEMACs/82:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_InitInterfaces/81:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Eth_PFE_LLD_GetTxBufTsRef/80:
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
  Node: Eth_PFE_LLD_GetTxBufMeta/79:
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
  Node: ChannelBdFlushRxExecute/78:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ChannelBdFlushRxPrepare/77:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Eth_PFE_LLD_GetEmacInstanceByControllerId/76:
    param [0]: VARIABLE
               0 [loc_time: 49, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Eth_PFE_LLD_ShutdownDriver/75:
  Node: Eth_PFE_LLD_DetectHardReset/74:
  Node: CheckDemStatus/72:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
               1 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
               2 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
               3 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
               4 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
               5 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
               6 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
               7 [loc_time: 2, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x7, mask = 0x7
         ErrorIdType [0, 7]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: DetectErrorsAndLostFrame/71:
    param [0]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
    param [1]: 0 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
               1 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
               2 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
               3 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
               4 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
               5 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
               6 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
               7 [loc_time: 2, loc_size: 17, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x7, mask = 0x7
         ErrorIdType [0, 7]
        AGGS VARIABLE
  Node: ConfigureSchedulerAndShaper/70:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: ConfigureSchedulerAndShaper_MapUnusedInputs/69:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct ConfigureSchedulerAndShaper_StateType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: 1 [loc_time: 1, loc_size: 39, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 39, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         uint8 [0, 1]
        AGGS VARIABLE
  Node: ConfigureSchedulerAndShaper_SetShaper/66:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct ConfigureSchedulerAndShaper_StateType * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         uint8 [0, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: GetTxTimeStamp/64:
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
         Eth_TimeStampQualType * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct Eth_TimeStampType * ~[0B, 0B]
        AGGS VARIABLE
  Node: ClientEventHdlr/63:
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
  Node: ClientEventHdlr_ETS/62:
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
  Node: ClientEventHdlr_TX/61:
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
  Node: ClientEventHdlr_RX/60:
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
  Node: TxReqQueueDelete/59:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: TxReqQueueWrite/57:
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
  Node: TxReqFailed/56:
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
  Node: TxReqTrigger/55:
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
  Node: TxReqTsQueueWrite/54:
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
  Node: ReleaseAllCtrlTxBuffers/53:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: GetTxBuffer/51:
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
         Eth_BufIdxType * const ~[0B, 0B]
        AGGS VARIABLE
  Node: InitializeTxHeaders/50:
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
  Node: ConfigureTxBuffers/49:
  Node: DestroyHifDrv/48:
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
  Node: CreateHifDrv/47:
    param [0]: 6 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x6, mask = 0x0
         pfe_ct_phy_if_id_t [6, 6]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: &prCommonHifChnl [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_chnl_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: &prCommonChnlIRQ [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct oal_irq_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [4]: &prCommonHifDrv [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct pfe_hif_drv_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: CreateHifDrv_Isr/46:
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
  Node: CreateHifDrv_Init/45:
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
  Node: CommonHifChnlISR/44:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_chnl_from_phy_id/24:
    param [0]: 6 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x6, mask = 0x0
         pfe_ct_phy_if_id_t [6, 6]
        AGGS VARIABLE
  Node: pfe_hif_pkt_icmp_csum_valid/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_pkt_tcpv6_csum_valid/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_pkt_tcpv4_csum_valid/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_pkt_udpv6_csum_valid/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_pkt_udpv4_csum_valid/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_emac_is_multi/7:
    param [0]: VARIABLE
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
  Node: pfe_emac_is_zero/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: hal_ip_ready_set/1:
    param [0]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         bool_t [1, 1]
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of CheckDemStatus/72 for all known contexts.
    replacing param #0 u8CtrlIdx with const 0
 - Creating a specialized node of CheckDemStatus.part.0/554 for all known contexts.
    replacing param #0 u8CtrlIdx with const 0
 - Creating a specialized node of DetectErrorsAndLostFrame/71 for all known contexts.
    replacing param #0 u8CtrlIdx with const 0
 - Creating a specialized node of CreateHifDrv/47 for all known contexts.
    replacing param #0 HifId with const 6
    replacing param #2 pprHifChnl with const &prCommonHifChnl
    replacing param #3 pprIRQ with const &prCommonChnlIRQ
    replacing param #4 pprHifDrv with const &prCommonHifDrv
 - Creating a specialized node of pfe_hif_chnl_from_phy_id/24 for all known contexts.
    replacing param #0 phy with const 6
Introduced new external node (__builtin_unreachable/580).
 - Creating a specialized node of pfe_hif_chnl_from_phy_id.part.0/537 for all known contexts.
    replacing param #0 phy with const 6
 - Creating a specialized node of hal_ip_ready_set/1 for all known contexts.
    replacing param #0 on with const 1
Propagated bits info for function hal_ip_ready_set.constprop/582:
 param 0: value = 0x1, mask = 0x0
Propagated bits info for function pfe_hif_chnl_from_phy_id.part.0.constprop/581:
 param 0: value = 0x6, mask = 0x0
Propagated bits info for function pfe_hif_chnl_from_phy_id.constprop/579:
 param 0: value = 0x6, mask = 0x0
Propagated bits info for function CreateHifDrv.constprop/578:
 param 0: value = 0x6, mask = 0x0
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
 param 4: value = 0x0, mask = 0xfffffffc
Propagated bits info for function DetectErrorsAndLostFrame.constprop/577:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x7, mask = 0x7
Propagated bits info for function CheckDemStatus.part.0.constprop/576:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x7, mask = 0x7
Propagated bits info for function CheckDemStatus.constprop/575:
 param 0: value = 0x0, mask = 0x0
 param 2: value = 0x7, mask = 0x7
Propagated bits info for function CheckDemStatus.part.0/554:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x7, mask = 0x7
Propagated bits info for function ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0x1
Propagated bits info for function ConfigureSchedulerAndShaper_SetFifo.isra.0/545:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0x1
Propagated bits info for function ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0x1
Propagated bits info for function pfe_hif_chnl_from_phy_id.part.0/537:
 param 0: value = 0x6, mask = 0x0
Propagated bits info for function oal_mutex_unlock.part.0/536:
 param 0: value = 0x12, mask = 0x7
Propagated bits info for function oal_mutex_lock.part.0/535:
 param 0: value = 0x15, mask = 0x7
Propagated bits info for function EnableController_HifEmac/101:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function EnableController_Aux/100:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function EnableController_Common/99:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function InterfacePrepare_InitEmacMasterLink/90:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function InterfacePrepare_MasterConfigEMAC/89:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function InterfacePrepare_InitEmacMasterRx/88:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function InterfacePrepare_InitTSQueue/87:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function CheckDemStatus/72:
 param 0: value = 0x0, mask = 0x0
 param 2: value = 0x7, mask = 0x7
Propagated bits info for function DetectErrorsAndLostFrame/71:
 param 0: value = 0x0, mask = 0x0
 param 1: value = 0x7, mask = 0x7
Propagated bits info for function ConfigureSchedulerAndShaper_MapUnusedInputs/69:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0x1
Propagated bits info for function ConfigureSchedulerAndShaper_SetShaper/66:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0x1
Propagated bits info for function GetTxTimeStamp/64:
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
Propagated bits info for function GetTxBuffer/51:
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function CreateHifDrv/47:
 param 0: value = 0x6, mask = 0x0
 param 2: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x0, mask = 0xfffffffc
 param 4: value = 0x0, mask = 0xfffffffc
Propagated bits info for function pfe_hif_chnl_from_phy_id/24:
 param 0: value = 0x6, mask = 0x0
Propagated bits info for function hal_ip_ready_set/1:
 param 0: value = 0x1, mask = 0x0

IPA constant propagation end

Reclaiming functions: pfe_hif_chnl_from_phy_id.part.0.constprop/581 CheckDemStatus.part.0/554 pfe_hif_chnl_from_phy_id.part.0/537 CheckDemStatus/72 DetectErrorsAndLostFrame/71 CreateHifDrv/47 pfe_hif_chnl_from_phy_id/24 hal_ip_ready_set/1
Reclaiming variables:
Clearing address taken flags:
Symbol table:

hal_ip_ready_set.constprop.0/582 (hal_ip_ready_set.constprop) @0d9c8b60
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of hal_ip_ready_set/1
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: PlatformDrvPrepare_ShutdownConfigInit/84 (177167401 (estimated locally),0.17 per call) 
  Calls: oal_mm_dev_map/185 (1073741824 (estimated locally),1.00 per call) oal_mm_dev_unmap/186 (751619278 (estimated locally),0.70 per call) 
__builtin_unreachable/580 (__builtin_unreachable) @0d9c8460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_chnl_from_phy_id.constprop/579 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_from_phy_id.constprop.0/579 (pfe_hif_chnl_from_phy_id.constprop) @0d9c8000
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of pfe_hif_chnl_from_phy_id/24
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: CreateHifDrv.constprop/578 (1073741824 (estimated locally),1.00 per call) 
  Calls: __builtin_unreachable/580 (0 (precise),0.00 per call) 
CreateHifDrv.constprop.0/578 (CreateHifDrv.constprop) @0d9c17e0
  Type: function definition analyzed
  Visibility:
  References: ptrPlatform/35 (read)prCommonHifChnl/37 (addr)prCommonChnlIRQ/38 (addr)prCommonHifDrv/39 (addr)
  Referring: 
  Clone of CreateHifDrv/47
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Eth_PFE_LLD_PlatformDrvPrepare/85 (524845004 (estimated locally),0.49 per call) 
  Calls: pfe_hif_chnl_from_phy_id.constprop/579 (1073741824 (estimated locally),1.00 per call) pfe_hif_get_channel/176 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/166 (322122547 (estimated locally),0.30 per call) oal_util_raise_dem_for_drv_runtime_err/167 (322122547 (estimated locally),0.30 per call) CreateHifDrv_Isr/46 (751619278 (estimated locally),0.70 per call) CreateHifDrv_Init/45 (401890828 (estimated locally),0.37 per call) pfe_hif_chnl_irq_unmask/187 (214891025 (estimated locally),0.20 per call) 
DetectErrorsAndLostFrame.constprop.0/577 (DetectErrorsAndLostFrame.constprop) @07949e00
  Type: function definition analyzed
  Visibility:
  References: u32StatId/28 (read)u32DemErrorCounters/43 (read)u32DemErrorCounters/43 (write)
  Referring: 
  Clone of DetectErrorsAndLostFrame/71
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: CheckDemStatus.part.0.constprop/576 (1073741824 (estimated locally),1.00 per call) 
  Calls: Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (1073741824 (estimated locally),1.00 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) 
CheckDemStatus.part.0.constprop.0/576 (CheckDemStatus.part.0.constprop) @079499a0
  Type: function definition analyzed
  Visibility: artificial
  References: 
  Referring: 
  Clone of CheckDemStatus.part.0/554
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 local split_part optimize_size
  Called by: CheckDemStatus.constprop/575 (217325344 (estimated locally),0.20 per call) 
  Calls: Dem_SetEventStatus/459 (536870913 (estimated locally),0.50 per call) Dem_SetEventStatus/459 (536870913 (estimated locally),0.50 per call) DetectErrorsAndLostFrame.constprop/577 (1073741824 (estimated locally),1.00 per call) 
CheckDemStatus.constprop.0/575 (CheckDemStatus.constprop) @0793db60
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of CheckDemStatus/72
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) Eth_PFE_LLD_MainFunction/138 (176285970 (estimated locally),5.66 per call) 
  Calls: CheckDemStatus.part.0.constprop/576 (217325344 (estimated locally),0.20 per call) 
Eth_PFE_LLD_ShutdownDriver.part.0/558 (Eth_PFE_LLD_ShutdownDriver.part.0) @0d96ba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: arPfeInterface/41 (read)eSavedMode/42 (write)ptrPlatform/35 (read)Eth_PFE_LLD_bIrqInitStatus/27 (write)prCommonChnlIRQ/38 (read)prCommonHifDrv/39 (read)prCommonHifDrv/39 (write)ptrPlatform/35 (read)ptrPlatform/35 (write)u32RtrTimeoutTimeMs/40 (write)
  Referring: 
  Availability: local
  Function flags: count:536870913 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver/75 (536870912 (estimated locally),0.50 per call) 
  Calls: Eth_PFE_LLD_DisableController/103 (287064877 (estimated locally),0.53 per call) pfe_platform_get_phy_if_by_id/174 (287064877 (estimated locally),0.53 per call) pfe_phy_if_disable/175 (153493589 (estimated locally),0.29 per call) DestroyHifDrv/48 (536870913 (estimated locally),1.00 per call) pfe_platform_remove/173 (287064877 (estimated locally),0.53 per call) 
CSWTCH.392/557 (CSWTCH.392) @0de397e0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: Eth_PFE_LLD_InitInterfaces/81 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
CheckDemStatus.part.0/554 (CheckDemStatus.part.0) @0756eee0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) first_run:1 body split_part optimize_size
  Called by: 
  Calls: 
ReportReception_ProcessPacket.isra.0/553 (ReportReception_ProcessPacket.isra.0) @070b31c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: mac_broadcast.12908/451 (addr)Eth_43_PFE_InternalCfgPtr/184 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ReportReception/124 (574129754 (estimated locally),5.00 per call) 
  Calls: pfe_hif_pkt_free/453 (1073741824 (estimated locally),1.00 per call) EthIf_RxIndication/452 (536870913 (estimated locally),0.50 per call) autolibc_memcmp/230 (536870913 (estimated locally),0.50 per call) IsRxChecksumValid/121 (1073741824 (estimated locally),1.00 per call) ReportReception_GetBypassVLANTag/122 (1073741824 (estimated locally),1.00 per call) 
UpdatePhysAddrFilter_Close.isra.0/552 (UpdatePhysAddrFilter_Close.isra.0) @0de17ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: rPlatformCfg/36 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (29232621 (estimated locally),0.03 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (177167401 (estimated locally),0.17 per call) pfe_hm_report/166 (177167401 (estimated locally),0.17 per call) pfe_phy_if_flush_mac_addrs/235 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/167 (536870913 (estimated locally),0.50 per call) pfe_hm_report/166 (536870913 (estimated locally),0.50 per call) pfe_phy_if_allmulti_disable/234 (1073741824 (estimated locally),1.00 per call) 
UpdatePhysAddrFilter_RemoveBroad.isra.0/551 (UpdatePhysAddrFilter_RemoveBroad.isra.0) @0de179a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (88583700 (estimated locally),0.08 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (354334802 (estimated locally),0.33 per call) pfe_hm_report/166 (354334802 (estimated locally),0.33 per call) pfe_phy_if_allmulti_disable/234 (1073741824 (estimated locally),1.00 per call) 
UpdatePhysAddrFilter_AddBroad.isra.0/550 (UpdatePhysAddrFilter_AddBroad.isra.0) @0de17460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (88583700 (estimated locally),0.08 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (354334802 (estimated locally),0.33 per call) pfe_hm_report/166 (354334802 (estimated locally),0.33 per call) pfe_phy_if_allmulti_enable/233 (1073741824 (estimated locally),1.00 per call) 
UpdatePhysAddrFilter_RemoveMulti.isra.0/549 (UpdatePhysAddrFilter_RemoveMulti.isra.0) @0ddf4e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: rPlatformCfg/36 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (29675540 (estimated locally),0.03 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (354334802 (estimated locally),0.33 per call) pfe_hm_report/166 (354334802 (estimated locally),0.33 per call) pfe_phy_if_del_mac_addr/231 (1073741824 (estimated locally),1.00 per call) 
EnableController_Common.part.0/548 (EnableController_Common.part.0) @0ddf4380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: EnableController_Common/99 (354334800 (estimated locally),0.33 per call) 
  Calls: pfe_hm_report/166 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/167 (1073741824 (estimated locally),1.00 per call) 
ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0) @070b39a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ConfigureSchedulerAndShaper/70 (958878292 (estimated locally),69.69 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (142359287 (estimated locally),0.13 per call) pfe_hm_report/166 (142359287 (estimated locally),0.13 per call) pfe_tmu_sch_bind_sch_output/214 (431391779 (estimated locally),0.40 per call) ConfigureSchedulerAndShaper_SetShaper/66 (222232129 (estimated locally),0.21 per call) ConfigureSchedulerAndShaper_SetFifo.isra.0/545 (165864442 (estimated locally),0.15 per call) oal_util_raise_dem_for_drv_runtime_err/167 (167807293 (estimated locally),0.16 per call) pfe_hm_report/166 (167807293 (estimated locally),0.16 per call) pfe_tmu_sch_set_input_weight/213 (508506948 (estimated locally),0.47 per call) 
ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546 (ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0) @070b3700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: ConfigureSchedulerAndShaper_SetFifo.isra.0/545 (354334800 (estimated locally),0.33 per call) 
  Calls: pfe_hm_report/166 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/167 (1073741824 (estimated locally),1.00 per call) 
ConfigureSchedulerAndShaper_SetFifo.isra.0/545 (ConfigureSchedulerAndShaper_SetFifo.isra.0) @070b3460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (165864442 (estimated locally),0.15 per call) ConfigureSchedulerAndShaper_SetShaper/66 (7178971 (estimated locally),0.06 per call) 
  Calls: ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546 (354334800 (estimated locally),0.33 per call) pfe_tmu_sch_bind_queue/215 (1073741824 (estimated locally),1.00 per call) 
ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0) @073a27e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ConfigureSchedulerAndShaper/70 (114863532 (estimated locally),8.35 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (177167401 (estimated locally),0.17 per call) pfe_hm_report/166 (177167401 (estimated locally),0.17 per call) pfe_tmu_sch_set_algo/212 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/167 (536870913 (estimated locally),0.50 per call) pfe_hm_report/166 (536870913 (estimated locally),0.50 per call) pfe_tmu_sch_set_rate_mode/211 (1073741824 (estimated locally),1.00 per call) 
UpdatePhysAddrFilter_AddMulti.isra.0/543 (UpdatePhysAddrFilter_AddMulti.isra.0) @07569ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: rPlatformCfg/36 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (29675540 (estimated locally),0.03 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (262422502 (estimated locally),0.24 per call) pfe_hm_report/166 (262422502 (estimated locally),0.24 per call) pfe_phy_if_add_mac_addr/206 (1073741824 (estimated locally),1.00 per call) 
oal_mutex_unlock.part.0/536 (oal_mutex_unlock.part.0) @070a21c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Eth_PFE_LLD_ReportTransmissionTS/126 (1073741824 (estimated locally),9.09 per call) Eth_PFE_LLD_ReportTransmissionTS/126 (97557347 (estimated locally),0.83 per call) Eth_PFE_LLD_ReportTransmission/125 (178593000 (estimated locally),1.55 per call) TxReqTsQueueWrite/54 (1073741824 (estimated locally),1.00 per call) GetTxBuffer/51 (11952894 (estimated locally),0.10 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
oal_mutex_lock.part.0/535 (oal_mutex_lock.part.0) @06e3ea80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Eth_PFE_LLD_ReportTransmissionTS/126 (97557347 (estimated locally),0.83 per call) Eth_PFE_LLD_ReportTransmissionTS/126 (1073741824 (estimated locally),9.09 per call) Eth_PFE_LLD_ReportTransmission/125 (178593000 (estimated locally),1.55 per call) TxReqTsQueueWrite/54 (1073741824 (estimated locally),1.00 per call) GetTxBuffer/51 (11952894 (estimated locally),0.10 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
pfe_hif_set_master_up/534 (pfe_hif_set_master_up) @0db5d620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_SetMasterUp/164 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_hif_get_master_detect_cfg/533 (pfe_hif_get_master_detect_cfg) @0db5d540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_SetMasterUp/164 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_tx_disable/532 (pfe_hif_chnl_cfg_tx_disable) @0db5d380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxExecute/78 (8289751 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_rx_disable/531 (pfe_hif_chnl_cfg_rx_disable) @0db5d2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxExecute/78 (8289751 (estimated locally),1.00 per call) 
  Calls: 
pfe_idex_send_dummy_frame/530 (pfe_idex_send_dummy_frame) @0db5d1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxExecute/78 (73230328 (estimated locally),8.83 per call) 
  Calls: 
pfe_hif_chnl_cfg_get_rx_bdp_rd_fifo_cnt/529 (pfe_hif_chnl_cfg_get_rx_bdp_rd_fifo_cnt) @0db5d0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxExecute/78 (1073741824 (estimated locally),129.53 per call) ChannelBdFlushRxExecute/78 (8289750 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_rx_enable/528 (pfe_hif_chnl_cfg_rx_enable) @0db40460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxPrepare/77 (217214212 (estimated locally),0.20 per call) 
  Calls: 
pfe_if_db_unlock/527 (pfe_if_db_unlock) @0db40ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxPrepare/77 (217214212 (estimated locally),0.20 per call) 
  Calls: 
pfe_phy_if_get_phy/526 (pfe_phy_if_get_phy) @0db40e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxPrepare/77 (751619277 (estimated locally),0.70 per call) 
  Calls: 
pfe_hif_get_channel_phy/525 (pfe_hif_get_channel_phy) @0db40d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ChannelBdFlushRxExecute/78 (8289750 (estimated locally),1.00 per call) ChannelBdFlushRxPrepare/77 (751619277 (estimated locally),0.70 per call) 
  Calls: 
autolibc_memset/524 (autolibc_memset) @0db40700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetTmuStats/158 (314968206 (estimated locally),8.47 per call) 
  Calls: 
pfe_tmu_get_queue_stats/523 (pfe_tmu_get_queue_stats) @0db40620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetTmuStats/158 (954449109 (estimated locally),25.66 per call) 
  Calls: 
pfe_tmu_get_special_stats/522 (pfe_tmu_get_special_stats) @0db40540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) 
  Calls: 
pfe_tmu_get_stat_value/521 (pfe_tmu_get_stat_value) @0db40380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetTmuStats/158 (19889080 (estimated locally),0.53 per call) 
  Calls: 
pfe_rtable_get_stats/520 (pfe_rtable_get_stats) @0db401c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetRtableStats/157 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_l2br_get_domain_stats/519 (pfe_l2br_get_domain_stats) @0db40000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetL2BridgeDomainStats/156 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_l2br_get_stats/518 (pfe_l2br_get_stats) @0db17c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetL2BridgeStats/155 (516716778 (estimated locally),0.48 per call) 
  Calls: 
pfe_l2br_get_number_entries/517 (pfe_l2br_get_number_entries) @0db17a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetL2BridgeStats/155 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_wdt_get_stat_value/516 (pfe_wdt_get_stat_value) @0db17620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetWdtStats/154 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_gpi_get_special_stats/515 (pfe_gpi_get_special_stats) @0db17e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) 
  Calls: 
pfe_gpi_shp_get_drop_cnt/514 (pfe_gpi_shp_get_drop_cnt) @0db17d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) 
  Calls: 
pfe_gpi_get_stat_value/513 (pfe_gpi_get_stat_value) @0db17b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetGpiStats/153 (676457350 (estimated locally),0.63 per call) 
  Calls: 
pfe_bmu_get_special_stats/512 (pfe_bmu_get_special_stats) @0db179a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetBmuStats/152 (32534377 (estimated locally),0.63 per call) 
  Calls: 
pfe_bmu_get_stat_value/511 (pfe_bmu_get_stat_value) @0db177e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetBmuStats/152 (1041207449 (estimated locally),20.16 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) Eth_43_PFE_LLD_GetBmuStats/152 (32534378 (estimated locally),0.63 per call) 
  Calls: 
__builtin_expect/510 (__builtin_expect) @0db17700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetL2BridgeStats/155 (574129754 (estimated locally),0.53 per call) Eth_43_PFE_LLD_GetGpiStats/153 (751619278 (estimated locally),0.70 per call) Eth_43_PFE_LLD_GetBmuStats/152 (36149309 (estimated locally),0.70 per call) 
  Calls: 
pfe_class_get_stats/509 (pfe_class_get_stats) @0db17540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetClassStats/151 (574129754 (estimated locally),0.53 per call) 
  Calls: 
oal_util_parse_ptp/508 (oal_util_parse_ptp) @0db171c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetRxTimeStamp/148 (731110809 (estimated locally),0.68 per call) 
  Calls: 
pfe_emac_set_ts_freq_adjustment/507 (pfe_emac_set_ts_freq_adjustment) @0db01ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EmacTsAdjustRatio/145 (59351079 (estimated locally),0.06 per call) 
  Calls: 
pfe_emac_adjust_ts_time/506 (pfe_emac_adjust_ts_time) @0db01d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_SetCorrectionTime/146 (242773027 (estimated locally),0.23 per call) 
  Calls: 
pfe_emac_get_ts_time/505 (pfe_emac_get_ts_time) @0db01b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetCurrentTime/144 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_emac_set_ts_time/504 (pfe_emac_set_ts_time) @0db019a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_SetGlobalTime/143 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_emac_mdio_read45/503 (pfe_emac_mdio_read45) @0db017e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_ReadMii45/142 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_emac_mdio_write45/502 (pfe_emac_mdio_write45) @0db01620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_WriteMii45/141 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_emac_mdio_read22/501 (pfe_emac_mdio_read22) @0db01460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_ReadMii/140 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_emac_mdio_unlock/500 (pfe_emac_mdio_unlock) @0db012a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_ReadMii45/142 (217325345 (estimated locally),0.20 per call) Eth_43_PFE_LLD_WriteMii45/141 (217325345 (estimated locally),0.20 per call) Eth_43_PFE_LLD_ReadMii/140 (217325345 (estimated locally),0.20 per call) Eth_43_PFE_LLD_WriteMii/139 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_emac_mdio_write22/499 (pfe_emac_mdio_write22) @0db011c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_WriteMii/139 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_emac_mdio_lock/498 (pfe_emac_mdio_lock) @0db010e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_ReadMii45/142 (217325345 (estimated locally),0.20 per call) Eth_43_PFE_LLD_WriteMii45/141 (217325345 (estimated locally),0.20 per call) Eth_43_PFE_LLD_ReadMii/140 (217325345 (estimated locally),0.20 per call) Eth_43_PFE_LLD_WriteMii/139 (217325345 (estimated locally),0.20 per call) 
  Calls: 
pfe_hif_irq_unmask/497 (pfe_hif_irq_unmask) @0dafbee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_HIF/136 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_isr/496 (pfe_hif_isr) @0dafbe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_HIF/136 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_irq_mask/495 (pfe_hif_irq_mask) @0dafbd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_HIF/136 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_util_irq_unmask/494 (pfe_util_irq_unmask) @0dafbb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_UTIL/135 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_util_isr/493 (pfe_util_isr) @0dafba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_UTIL/135 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_util_irq_mask/492 (pfe_util_irq_mask) @0dafb9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_UTIL/135 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_class_irq_unmask/491 (pfe_class_irq_unmask) @0dafb7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_CLASS/134 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_class_isr/490 (pfe_class_isr) @0dafb700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_CLASS/134 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_class_irq_mask/489 (pfe_class_irq_mask) @0dafb620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_CLASS/134 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bmu_irq_unmask/488 (pfe_bmu_irq_unmask) @0dafb460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_BMU/133 (286345 (estimated locally),0.00 per call) 
  Calls: 
pfe_bmu_isr/487 (pfe_bmu_isr) @0dafb380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_BMU/133 (286345 (estimated locally),0.00 per call) 
  Calls: 
pfe_bmu_irq_mask/486 (pfe_bmu_irq_mask) @0dafb2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_BMU/133 (286345 (estimated locally),0.00 per call) 
  Calls: 
pfe_host_fail_stop_irq_unmask/485 (pfe_host_fail_stop_irq_unmask) @0dafb0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_host_fail_stop_isr/484 (pfe_host_fail_stop_isr) @0dafb000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_host_fail_stop_irq_mask/483 (pfe_host_fail_stop_irq_mask) @0daf5c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fw_fail_stop_irq_unmask/482 (pfe_fw_fail_stop_irq_unmask) @0daf5ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fw_fail_stop_isr/481 (pfe_fw_fail_stop_isr) @0daf5e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fw_fail_stop_irq_mask/480 (pfe_fw_fail_stop_irq_mask) @0daf5d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fail_stop_irq_unmask/479 (pfe_fail_stop_irq_unmask) @0daf5b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fail_stop_isr/478 (pfe_fail_stop_isr) @0daf5a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_fail_stop_irq_mask/477 (pfe_fail_stop_irq_mask) @0daf59a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_parity_irq_unmask/476 (pfe_parity_irq_unmask) @0daf57e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_PARITY/131 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_parity_isr/475 (pfe_parity_isr) @0daf5700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_PARITY/131 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_parity_irq_mask/474 (pfe_parity_irq_mask) @0daf5620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_PARITY/131 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bus_err_irq_unmask/473 (pfe_bus_err_irq_unmask) @0daf5460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_BUS/130 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bus_err_isr/472 (pfe_bus_err_isr) @0daf5380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_BUS/130 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bus_err_irq_mask/471 (pfe_bus_err_irq_mask) @0daf52a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_BUS/130 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_emac_irq_unmask/470 (pfe_emac_irq_unmask) @0daf50e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_EMAC/129 (430597315 (estimated locally),1.60 per call) 
  Calls: 
pfe_emac_isr/469 (pfe_emac_isr) @0daf5000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_EMAC/129 (430597315 (estimated locally),1.60 per call) 
  Calls: 
pfe_emac_irq_mask/468 (pfe_emac_irq_mask) @0dae8000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_EMAC/129 (430597315 (estimated locally),1.60 per call) 
  Calls: 
pfe_wdt_irq_unmask/467 (pfe_wdt_irq_unmask) @0dae8e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_WDG/128 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_wdt_isr/466 (pfe_wdt_isr) @0dae8d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_WDG/128 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_wdt_irq_mask/465 (pfe_wdt_irq_mask) @0dae8c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_WDG/128 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_ecc_err_irq_unmask/464 (pfe_ecc_err_irq_unmask) @0dae8a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_ECC/127 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_ecc_err_isr/463 (pfe_ecc_err_isr) @0dae89a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_ECC/127 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_ecc_err_irq_mask/462 (pfe_ecc_err_irq_mask) @0dae88c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_PollerFunction_ECC/127 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_emac_get_stat_value/461 (pfe_emac_get_stat_value) @0dae8540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: DetectErrorsAndLostFrame.constprop/577 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxStats/161 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxStats/161 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxStats/161 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetTxStats/161 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetRxStats/160 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetCounterValues/159 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_drv_client_ptp_ts_db_tick_iteration/460 (pfe_hif_drv_client_ptp_ts_db_tick_iteration) @0dae82a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_MainFunction/138 (176285971 (estimated locally),5.66 per call) 
  Calls: 
Dem_SetEventStatus/459 (Dem_SetEventStatus) @0dae81c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CheckDemStatus.part.0.constprop/576 (536870913 (estimated locally),0.50 per call) CheckDemStatus.part.0.constprop/576 (536870913 (estimated locally),0.50 per call) Eth_PFE_LLD_MainFunction/138 (17840140 (estimated locally),0.57 per call) Eth_PFE_LLD_MainFunction/138 (17840140 (estimated locally),0.57 per call) 
  Calls: 
EthIf_CtrlModeIndication/458 (EthIf_CtrlModeIndication) @0dae80e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_MainFunction/138 (86168583 (estimated locally),2.77 per call) 
  Calls: 
pfe_rtable_do_timeouts/457 (pfe_rtable_do_timeouts) @0daceee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_MainFunction/138 (7190091 (estimated locally),0.23 per call) 
  Calls: 
pfe_hif_drv_client_get_ts/456 (pfe_hif_drv_client_get_ts) @0dacee00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_43_PFE_LLD_GetRxTimeStamp/148 (594027532 (estimated locally),0.55 per call) GetTxTimeStamp/64 (731110809 (estimated locally),0.68 per call) 
  Calls: 
pfe_hif_drv_client_tx_done/455 (pfe_hif_drv_client_tx_done) @0dace700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ReportTransmission/125 (114863532 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_drv_client_receive_tx_conf/454 (pfe_hif_drv_client_receive_tx_conf) @0dace620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ReportTransmission/125 (1044213930 (estimated locally),9.09 per call) 
  Calls: 
pfe_hif_pkt_free/453 (pfe_hif_pkt_free) @0dabb9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ReportReception_ProcessPacket.isra.0/553 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
EthIf_RxIndication/452 (EthIf_RxIndication) @0dabb8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ReportReception_ProcessPacket.isra.0/553 (536870913 (estimated locally),0.50 per call) 
  Calls: 
mac_broadcast.12908/451 (mac_broadcast) @0dac0948
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ReportReception_ProcessPacket.isra.0/553 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_hif_drv_client_has_rx_pkt/450 (pfe_hif_drv_client_has_rx_pkt) @0dabb700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ReportReception/124 (18952483 (estimated locally),0.17 per call) 
  Calls: 
pfe_hif_drv_client_rx_done/449 (pfe_hif_drv_client_rx_done) @0dabb620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ReportReception/124 (114863532 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_drv_client_receive_pkt/448 (pfe_hif_drv_client_receive_pkt) @0dabb540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ReportReception/124 (1073741824 (estimated locally),9.35 per call) 
  Calls: 
pfe_hif_drv_client_xmit_pkt/447 (pfe_hif_drv_client_xmit_pkt) @0dabb0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: TxReqTrigger/55 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
EthIf_TxConfirmation/446 (EthIf_TxConfirmation) @0dab3d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ReportTransmissionTS/126 (97557347 (estimated locally),0.83 per call) Eth_PFE_LLD_ReportTransmission/125 (178593000 (estimated locally),1.55 per call) Eth_PFE_LLD_Transmit/118 (173198851 (estimated locally),0.16 per call) TxReqFailed/56 (354334802 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/445 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0dab37e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/444 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0dab3700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/443 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0dab3620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/442 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @0dab3540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/441 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @0dab3460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/440 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @0dab3380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/439 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @0dab32a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/438 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @0dab31c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/437 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @0dab30e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/436 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @0dab3000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/435 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @0dab2ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/434 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @0dab2e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/433 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @0dab2d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/432 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @0dab2c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/431 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @0dab2b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/430 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @0dab2a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/429 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @0dab29a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/428 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @0dab28c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/427 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @0dab27e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/426 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @0dab2700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/425 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @0dab2620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/424 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @0dab2540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/423 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @0dab2460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/422 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @0dab2380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/421 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @0dab22a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/420 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @0dab21c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/419 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @0dab20e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/418 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @0dab2000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/417 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @0dab1ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/416 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @0dab1e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/415 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @0dab1d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/414 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @0dab1c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/413 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @0dab1b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/412 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @0dab1a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/411 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @0dab19a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/410 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @0dab18c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/409 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @0dab17e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/408 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @0dab1700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/407 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @0dab1620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/406 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @0dab1540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/405 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @0dab1460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/404 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @0dab1380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/403 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @0dab12a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/402 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @0dab11c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/401 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @0dab10e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/400 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @0dab1000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/399 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @0dab0ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/398 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @0dab0e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/397 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @0dab0d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/396 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @0dab0c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/395 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @0dab0b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/394 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @0dab0a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/393 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @0dab09a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/392 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @0dab08c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/391 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @0dab07e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/390 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @0dab0700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/389 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @0dab0620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/388 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @0dab0540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/387 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @0dab0460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/386 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @0dab0380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/385 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @0dab02a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/384 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @0dab01c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/383 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @0dab00e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/382 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @0dab0000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/381 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @0daafee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/380 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @0daafe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/379 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @0daafd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/378 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @0daafc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/377 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @0daafb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/376 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @0daafa80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/375 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @0daaf9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/374 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @0daaf8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/373 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @0daaf7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/372 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @0daaf700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/371 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @0daaf620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/370 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @0daaf540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/369 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @0daaf460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/368 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0daaf380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/367 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @0daaf2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/366 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @0daaf1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/365 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @0daaf0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/364 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @0daaf000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/363 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @0daae0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/362 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @0daaeee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/361 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @0daaee00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/360 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @0daaed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/359 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @0daaec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/358 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @0daaeb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/357 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0daaea80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/356 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0daae9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/355 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0daae8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/354 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0daae7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/353 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0daae700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/352 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0daae620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/351 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0daae540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/350 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0daae460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/349 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0daae380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/348 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0daae2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/347 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0daae1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/346 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0daae000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/345 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0daacee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/344 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0daace00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/343 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0daacd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/342 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0daacc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/341 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0daacb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/340 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104) @0daac9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/339 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103) @0daac8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/338 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102) @0daac7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/337 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101) @0daac700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/336 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100) @0daac620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/335 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99) @0daac540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/334 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98) @0daac460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/333 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97) @0daac380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/332 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96) @0daac2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/331 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95) @0daac1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/330 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94) @0daac0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/329 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93) @0daac000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/328 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92) @0daabee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/327 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91) @0daabe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/326 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90) @0daabd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/325 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89) @0daabc40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/324 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88) @0daabb60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/323 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87) @0daaba80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/322 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86) @0daab9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/321 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85) @0daab8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/320 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84) @0daab7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/319 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83) @0daab700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/318 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82) @0daab620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/317 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81) @0daab540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/316 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80) @0daab460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/315 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79) @0daab380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/314 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78) @0daab2a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/313 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77) @0daab1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/312 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76) @0daab0e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/311 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75) @0daab000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/310 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74) @0daa5ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/309 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73) @0daa5e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/308 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72) @0daa5d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/307 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71) @0daa5c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/306 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70) @0daa5b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/305 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69) @0daa5a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/304 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68) @0daa59a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/303 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67) @0daa58c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/302 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66) @0daa57e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/301 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65) @0daa5700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/300 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64) @0daa5620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/299 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63) @0daa5540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/298 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62) @0daa5460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/297 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61) @0daa5380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/296 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60) @0daa52a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/295 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59) @0daa51c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/294 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58) @0daa50e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/293 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57) @0daa5000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/292 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56) @0daa3ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/291 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55) @0daa3e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/290 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54) @0daa3d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/289 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53) @0daa3c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/288 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52) @0daa3b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/287 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51) @0daa3a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/286 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50) @0daa39a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/285 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49) @0daa38c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/284 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48) @0daa37e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/283 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47) @0daa3700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/282 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46) @0daa3620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/281 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45) @0daa3540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/280 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44) @0daa3460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/279 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43) @0daa3380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/278 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42) @0daa32a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/277 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41) @0daa31c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/276 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40) @0daa30e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/275 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39) @0daa3000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/274 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38) @0daa2ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/273 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37) @0daa2e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/272 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36) @0daa2d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/271 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35) @0daa2c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/270 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34) @0daa2b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/269 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33) @0daa2a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/268 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32) @0daa29a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/267 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31) @0daa28c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/266 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30) @0daa27e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/265 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29) @0daa2700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/264 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28) @0daa2620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/263 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27) @0daa2540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/262 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26) @0daa2460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/261 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25) @0daa2380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/260 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24) @0daa22a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/259 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23) @0daa21c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/258 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22) @0daa20e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/257 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21) @0daa2000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/256 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20) @0daa12a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/255 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19) @0daa1ee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/254 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18) @0daa1e00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/253 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17) @0daa1d20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/252 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16) @0daa1c40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/251 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15) @0daa1b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/250 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14) @0daa1a80
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/249 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13) @0daa19a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/248 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12) @0daa18c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/247 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11) @0daa17e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/246 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10) @0daa1700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/245 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09) @0daa1620
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/244 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08) @0daa1540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/243 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07) @0daa1460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/242 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06) @0daa1380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/241 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05) @0daa11c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/240 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04) @0daa10e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/239 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03) @0daa1000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/238 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02) @0da8fee0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/237 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01) @0da8fe00
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/236 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00) @0da8fd20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
pfe_phy_if_flush_mac_addrs/235 (pfe_phy_if_flush_mac_addrs) @0da8f700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: UpdatePhysAddrFilter_Close.isra.0/552 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_phy_if_allmulti_disable/234 (pfe_phy_if_allmulti_disable) @0da8f460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: UpdatePhysAddrFilter_Close.isra.0/552 (1073741824 (estimated locally),1.00 per call) UpdatePhysAddrFilter_RemoveBroad.isra.0/551 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_allmulti_enable/233 (pfe_phy_if_allmulti_enable) @0da8f2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: UpdatePhysAddrFilter_AddBroad.isra.0/550 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Det_ReportError/232 (Det_ReportError) @0da8f000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (29232621 (estimated locally),0.03 per call) 
  Calls: 
pfe_phy_if_del_mac_addr/231 (pfe_phy_if_del_mac_addr) @0da7bd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_SetPhysAddr/106 (316753838 (estimated locally),0.30 per call) UpdatePhysAddrFilter_RemoveMulti.isra.0/549 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_memcmp/230 (autolibc_memcmp) @0da7bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_SetPhysAddr/106 (1073741823 (estimated locally),1.00 per call) ReportReception_ProcessPacket.isra.0/553 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_hif_drv_client_unregister/229 (pfe_hif_drv_client_unregister) @0da7b700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_DisableController/103 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_drv_client_set_inject_if/228 (pfe_hif_drv_client_set_inject_if) @0da7b540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EnableController_HifEmac/101 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_drv_client_register/227 (pfe_hif_drv_client_register) @0da7b460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EnableController_HifEmac/101 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_get_id/226 (pfe_phy_if_get_id) @0da7b380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EnableController_HifEmac/101 (574129754 (estimated locally),0.53 per call) EnableController_HifEmac/101 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_drv_init_tx_header/225 (pfe_hif_drv_init_tx_header) @0da7b1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InitializeTxHeaders/50 (955630223 (estimated locally),16.18 per call) 
  Calls: 
Eth_43_PFE_StaticConfig/224 (Eth_43_PFE_StaticConfig) @0da75678
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ClientEventHdlr_TX/61 (read)ClientEventHdlr_ETS/62 (read)ClientEventHdlr_RX/60 (read)Eth_PFE_LLD_MainFunction/138 (read)
  Availability: not_available
  Varpool flags: read-only
pfe_hif_drv_aux_client_register/223 (pfe_hif_drv_aux_client_register) @0da5eb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EnableController_Aux/100 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
fifo_create/222 (fifo_create) @0da5e9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EnableController_InitFifos/98 (0 (precise),0.00 per call) EnableController_InitFifos/98 (0 (precise),0.00 per call) 
  Calls: 
pfe_tmu_shp_set_idle_slope/220 (pfe_tmu_shp_set_idle_slope) @0da5e0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetShaper/66 (14357941 (estimated locally),0.12 per call) 
  Calls: 
pfe_tmu_shp_set_position/219 (pfe_tmu_shp_set_position) @0da5e000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetShaper/66 (28715883 (estimated locally),0.25 per call) 
  Calls: 
pfe_tmu_shp_set_limits/218 (pfe_tmu_shp_set_limits) @0da4cee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetShaper/66 (57431766 (estimated locally),0.50 per call) 
  Calls: 
pfe_tmu_shp_enable/217 (pfe_tmu_shp_enable) @0da4ce00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetShaper/66 (55807731 (estimated locally),0.49 per call) 
  Calls: 
*.LC0/216 (*.LC0) @0da58798
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: ConfigureSchedulerAndShaper_SetShaper/66 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_tmu_sch_bind_queue/215 (pfe_tmu_sch_bind_queue) @0da4cc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_MapUnusedInputs/69 (114863531 (estimated locally),1.93 per call) ConfigureSchedulerAndShaper_SetFifo.isra.0/545 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_tmu_sch_bind_sch_output/214 (pfe_tmu_sch_bind_sch_output) @0da4ca80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (431391779 (estimated locally),0.40 per call) 
  Calls: 
pfe_tmu_sch_set_input_weight/213 (pfe_tmu_sch_set_input_weight) @0da4c9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (508506948 (estimated locally),0.47 per call) 
  Calls: 
pfe_tmu_sch_set_algo/212 (pfe_tmu_sch_set_algo) @0da4c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_tmu_sch_set_rate_mode/211 (pfe_tmu_sch_set_rate_mode) @0da4c700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_log_if_get_name/210 (pfe_log_if_get_name) @0da4c460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InterfacePrepare_InitEmacMasterRx/88 (54750298 (estimated locally),0.05 per call) 
  Calls: 
pfe_log_if_set_egress_ifs/209 (pfe_log_if_set_egress_ifs) @0da4c380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InterfacePrepare_InitEmacMasterRx/88 (261213256 (estimated locally),0.24 per call) 
  Calls: 
pfe_phy_if_get_name/208 (pfe_phy_if_get_name) @0da4c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InterfacePrepare_InitEmacMasterRx/88 (60279982 (estimated locally),0.06 per call) 
  Calls: 
pfe_phy_if_get_default_log_if/207 (pfe_phy_if_get_default_log_if) @0da4c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InterfacePrepare_InitEmacMasterRx/88 (321493238 (estimated locally),0.30 per call) 
  Calls: 
pfe_phy_if_add_mac_addr/206 (pfe_phy_if_add_mac_addr) @0da4c0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_SetPhysAddr/106 (104528766 (estimated locally),0.10 per call) InterfacePrepare_InitEmacMasterRx/88 (719407022 (estimated locally),0.67 per call) UpdatePhysAddrFilter_AddMulti.isra.0/543 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_promisc_disable/205 (pfe_phy_if_promisc_disable) @0da4c000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InterfacePrepare_InitEmacMasterRx/88 (536870911 (estimated locally),0.50 per call) 
  Calls: 
pfe_phy_if_promisc_enable/204 (pfe_phy_if_promisc_enable) @066aa700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InterfacePrepare_InitEmacMasterRx/88 (536870911 (estimated locally),0.50 per call) 
  Calls: 
pfe_emac_set_link_duplex/203 (pfe_emac_set_link_duplex) @066aad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_EMACPrepare_Config/92 (567069901 (estimated locally),0.53 per call) InterfacePrepare_InitEmacMasterLink/90 (567069901 (estimated locally),0.53 per call) 
  Calls: 
pfe_emac_set_link_speed/202 (pfe_emac_set_link_speed) @066aac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_EMACPrepare_Config/92 (872415231 (estimated locally),0.81 per call) InterfacePrepare_InitEmacMasterLink/90 (872415231 (estimated locally),0.81 per call) 
  Calls: 
pfe_phy_if_get_emac/201 (pfe_phy_if_get_emac) @066aab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_EMACPrepare_Config/92 (1073741823 (estimated locally),1.00 per call) InterfacePrepare_InitEmacMasterLink/90 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_phy_if_loopback_enable/200 (pfe_phy_if_loopback_enable) @066aa9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: InterfacePrepare_MasterConfigEMAC/89 (177167401 (estimated locally),0.17 per call) 
  Calls: 
autolibc_memcpy/199 (autolibc_memcpy) @066aa620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_Transmit/118 (548896821 (estimated locally),0.51 per call) Eth_PFE_LLD_Transmit/118 (548896821 (estimated locally),0.51 per call) Eth_PFE_LLD_SetPhysAddr/106 (58306146 (estimated locally),0.05 per call) Eth_PFE_LLD_SetPhysAddr/106 (220117073 (estimated locally),0.20 per call) Eth_PFE_LLD_GetPhysicalAddress/105 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_InterfacePrepare/91 (620612038 (estimated locally),0.58 per call) 
  Calls: 
Eth_43_PFE_CtrlState/198 (Eth_43_PFE_CtrlState) @066ac360
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: ClientEventHdlr_TX/61 (read)ClientEventHdlr_RX/60 (read)Eth_PFE_LLD_Check_Driver_Init/95 (read)Eth_PFE_LLD_DeInit/86 (write)ClientEventHdlr_ETS/62 (read)
  Availability: not_available
  Varpool flags:
pfe_phy_if_enable/197 (pfe_phy_if_enable) @066aa380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_EnableController/102 (6659191 (estimated locally),0.01 per call) PlatformDrvPrepare_EnablePhyIf/83 (751619277 (estimated locally),0.70 per call) 
  Calls: 
pfe_platform_idex_rpc_cbk/196 (pfe_platform_idex_rpc_cbk) @066aa1c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: CreateHifDrv_Init/45 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
pfe_idex_init/195 (pfe_idex_init) @066aa0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv_Init/45 (460623539 (estimated locally),0.43 per call) 
  Calls: 
pfe_hif_drv_start/194 (pfe_hif_drv_start) @066aa000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv_Init/45 (648765548 (estimated locally),0.60 per call) 
  Calls: 
pfe_hif_drv_init/193 (pfe_hif_drv_init) @06699460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv_Init/45 (913754293 (estimated locally),0.85 per call) 
  Calls: 
pfe_hif_drv_create/192 (pfe_hif_drv_create) @06699380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv_Init/45 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_isr/191 (pfe_hif_chnl_isr) @06699e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CommonHifChnlISR/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_irq_mask/190 (pfe_hif_chnl_irq_mask) @06699d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: TxReqFailed/56 (354334802 (estimated locally),0.33 per call) CommonHifChnlISR/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_irq_add_handler/189 (oal_irq_add_handler) @06699b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv_Isr/46 (913754293 (estimated locally),0.85 per call) 
  Calls: 
oal_irq_create/188 (oal_irq_create) @06699a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv_Isr/46 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_irq_unmask/187 (pfe_hif_chnl_irq_unmask) @066998c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv.constprop/578 (214891025 (estimated locally),0.20 per call) TxReqFailed/56 (354334802 (estimated locally),0.33 per call) CommonHifChnlISR/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_mm_dev_unmap/186 (oal_mm_dev_unmap) @06699700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: hal_ip_ready_set.constprop/582 (751619278 (estimated locally),0.70 per call) 
  Calls: 
oal_mm_dev_map/185 (oal_mm_dev_map) @06699620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: hal_ip_ready_set.constprop/582 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Eth_43_PFE_InternalCfgPtr/184 (Eth_43_PFE_InternalCfgPtr) @0669d048
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Eth_43_PFE_LLD_ReadMii45/142 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_43_PFE_LLD_SetGlobalTime/143 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (read)InterfacePrepare_InitEmacMasterLink/90 (read)ReportReception_ProcessPacket.isra.0/553 (read)ConfigureTxBuffers/49 (read)InterfacePrepare_InitEmacMasterRx/88 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (read)InterfacePrepare_InitTSQueue/87 (read)Eth_43_PFE_LLD_ReadMii/140 (read)InterfacePrepare_InitEmacMasterLink/90 (read)Eth_43_PFE_LLD_SetCorrectionTime/146 (read)TxReqFailed/56 (read)Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_EMACPrepare/93 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_ConfigureController/94 (read)ConfigureSchedulerAndShaper/70 (read)InterfacePrepare_MasterConfigEMAC/89 (read)Eth_PFE_LLD_CheckInitializationStatus/97 (read)Eth_PFE_LLD_EMACPrepare/93 (read)Eth_PFE_LLD_EnableController/102 (read)Eth_PFE_LLD_SetPhysAddr/106 (read)EnableController_HifEmac/101 (read)InitializeTxHeaders/50 (read)Eth_PFE_LLD_UpdatePhysAddrFilter/112 (read)Eth_PFE_LLD_Transmit/118 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_43_PFE_LLD_WriteMii45/141 (read)Eth_43_PFE_LLD_WriteMii/139 (read)Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_EnableController/102 (read)Eth_PFE_LLD_ReportTransmission/125 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_43_PFE_LLD_GetCurrentTime/144 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (read)
  Availability: not_available
  Varpool flags:
pfe_hif_drv_destroy/183 (pfe_hif_drv_destroy) @066990e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: DestroyHifDrv/48 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_idex_fini/182 (pfe_idex_fini) @06699000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: DestroyHifDrv/48 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_chnl_tx_irq_unmask/181 (pfe_hif_chnl_tx_irq_unmask) @0668cee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_DetectHardReset/74 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_irq_unmask/180 (pfe_hif_chnl_rx_irq_unmask) @0668ce00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_DetectHardReset/74 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_tx_enable/179 (pfe_hif_chnl_tx_enable) @0668cd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_DetectHardReset/74 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_enable/178 (pfe_hif_chnl_rx_enable) @0668cc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_DetectHardReset/74 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_inspect_hw_state/177 (pfe_hif_chnl_inspect_hw_state) @0668cb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_DetectHardReset/74 (306987179 (estimated locally),0.29 per call) 
  Calls: 
pfe_hif_get_channel/176 (pfe_hif_get_channel) @0668ca80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv.constprop/578 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_DetectHardReset/74 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_phy_if_disable/175 (pfe_phy_if_disable) @0668c8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver.part.0/558 (153493589 (estimated locally),0.29 per call) ChannelBdFlushRxPrepare/77 (434428425 (estimated locally),0.40 per call) 
  Calls: 
pfe_platform_get_phy_if_by_id/174 (pfe_platform_get_phy_if_by_id) @0668c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver.part.0/558 (287064877 (estimated locally),0.53 per call) Eth_PFE_LLD_EMACPrepare/93 (265751101 (estimated locally),0.95 per call) Eth_PFE_LLD_InterfacePrepare/91 (204801972 (estimated locally),0.19 per call) PlatformDrvPrepare_EnablePhyIf/83 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
pfe_platform_remove/173 (pfe_platform_remove) @0668c620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver/75 (536870913 (estimated locally),0.50 per call) Eth_PFE_LLD_ShutdownDriver.part.0/558 (287064877 (estimated locally),0.53 per call) 
  Calls: 
pfe_platform_remove_sw_if/172 (pfe_platform_remove_sw_if) @0668c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver/75 (536870913 (estimated locally),0.50 per call) 
  Calls: 
oal_irq_destroy/171 (oal_irq_destroy) @0668c460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver/75 (287064877 (estimated locally),0.27 per call) CreateHifDrv_Isr/46 (153053844 (estimated locally),0.14 per call) DestroyHifDrv/48 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_platform_get_instance/170 (pfe_platform_get_instance) @0668c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: PlatformDrvPrepare_ShutdownConfigInit/84 (177167401 (estimated locally),0.17 per call) 
  Calls: 
pfe_platform_init/169 (pfe_platform_init) @0668c0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: PlatformDrvPrepare_ShutdownConfigInit/84 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_class_fw_binary/168 (pfe_class_fw_binary) @066879d8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: PlatformDrvPrepare_ShutdownConfigInit/84 (addr)
  Availability: not_available
  Varpool flags: read-only
oal_util_raise_dem_for_drv_runtime_err/167 (oal_util_raise_dem_for_drv_runtime_err) @0da3d2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv.constprop/578 (322122547 (estimated locally),0.30 per call) Eth_43_PFE_LLD_GetL2BridgeStats/155 (57412975 (estimated locally),0.05 per call) Eth_43_PFE_LLD_GetGpiStats/153 (75161928 (estimated locally),0.07 per call) Eth_43_PFE_LLD_GetBmuStats/152 (3614931 (estimated locally),0.07 per call) Eth_43_PFE_LLD_GetRxTimeStamp/148 (137083277 (estimated locally),0.13 per call) Eth_43_PFE_LLD_ReadMii45/142 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_ReadMii45/142 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii45/141 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii45/141 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_ReadMii/140 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_ReadMii/140 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii/139 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii/139 (71717364 (estimated locally),0.07 per call) Eth_PFE_LLD_Transmit/118 (181135951 (estimated locally),0.17 per call) Eth_PFE_LLD_Transmit/118 (524845004 (estimated locally),0.49 per call) Eth_PFE_LLD_PlatformDrvPrepare/85 (173198851 (estimated locally),0.16 per call) PlatformDrvPrepare_ShutdownConfigInit/84 (30880278 (estimated locally),0.03 per call) PlatformDrvPrepare_ShutdownConfigInit/84 (177167401 (estimated locally),0.17 per call) Eth_PFE_LLD_CheckInitializationStatus/97 (172618805 (estimated locally),0.16 per call) Eth_PFE_LLD_CheckInitializationStatus/97 (110420388 (estimated locally),0.10 per call) Eth_PFE_LLD_EMACPrepare/93 (79725330 (estimated locally),0.29 per call) Eth_PFE_LLD_InterfacePrepare/91 (35696984 (estimated locally),0.03 per call) Eth_PFE_LLD_InterfacePrepare/91 (265976587 (estimated locally),0.25 per call) Eth_PFE_LLD_InterfacePrepare/91 (187153200 (estimated locally),0.17 per call) ChannelBdFlushRxExecute/78 (4027668 (estimated locally),0.49 per call) ChannelBdFlushRxExecute/78 (10146860 (estimated locally),1.22 per call) ChannelBdFlushRxPrepare/77 (217214212 (estimated locally),0.20 per call) ChannelBdFlushRxPrepare/77 (186183611 (estimated locally),0.17 per call) ChannelBdFlushRxPrepare/77 (131007240 (estimated locally),0.12 per call) ChannelBdFlushRxPrepare/77 (322122547 (estimated locally),0.30 per call) EmacTsAdjustRatio/145 (209084376 (estimated locally),0.19 per call) UpdatePhysAddrFilter_Close.isra.0/552 (177167401 (estimated locally),0.17 per call) UpdatePhysAddrFilter_Close.isra.0/552 (536870913 (estimated locally),0.50 per call) UpdatePhysAddrFilter_RemoveBroad.isra.0/551 (354334802 (estimated locally),0.33 per call) UpdatePhysAddrFilter_AddBroad.isra.0/550 (354334802 (estimated locally),0.33 per call) UpdatePhysAddrFilter_RemoveMulti.isra.0/549 (354334802 (estimated locally),0.33 per call) EnableController_HifEmac/101 (287064877 (estimated locally),0.27 per call) EnableController_Common.part.0/548 (1073741824 (estimated locally),1.00 per call) InterfacePrepare_MasterConfigEMAC/89 (116930485 (estimated locally),0.11 per call) InterfacePrepare_MasterConfigEMAC/89 (58465242 (estimated locally),0.05 per call) ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (142359287 (estimated locally),0.13 per call) ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (167807293 (estimated locally),0.16 per call) ConfigureSchedulerAndShaper_SetShaper/66 (7178971 (estimated locally),0.06 per call) ConfigureSchedulerAndShaper_SetShaper/66 (14357941 (estimated locally),0.12 per call) ConfigureSchedulerAndShaper_SetShaper/66 (28715883 (estimated locally),0.25 per call) ConfigureSchedulerAndShaper_SetShaper/66 (57431766 (estimated locally),0.50 per call) ConfigureSchedulerAndShaper_MapUnusedInputs/69 (6317494 (estimated locally),0.11 per call) ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546 (1073741824 (estimated locally),1.00 per call) ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (177167401 (estimated locally),0.17 per call) ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (536870913 (estimated locally),0.50 per call) InterfacePrepare_InitEmacMasterRx/88 (54750298 (estimated locally),0.05 per call) InterfacePrepare_InitEmacMasterRx/88 (60279982 (estimated locally),0.06 per call) InterfacePrepare_InitEmacMasterRx/88 (99519890 (estimated locally),0.09 per call) InterfacePrepare_InitEmacMasterRx/88 (177167401 (estimated locally),0.17 per call) InterfacePrepare_InitEmacMasterRx/88 (177167401 (estimated locally),0.17 per call) UpdatePhysAddrFilter_AddMulti.isra.0/543 (262422502 (estimated locally),0.24 per call) Eth_PFE_LLD_EMACPrepare_Config/92 (118857851 (estimated locally),0.11 per call) Eth_PFE_LLD_EMACPrepare_Config/92 (305345331 (estimated locally),0.28 per call) Eth_PFE_LLD_EMACPrepare_Config/92 (201326592 (estimated locally),0.19 per call) InterfacePrepare_InitEmacMasterLink/90 (118857851 (estimated locally),0.11 per call) InterfacePrepare_InitEmacMasterLink/90 (305345331 (estimated locally),0.28 per call) InterfacePrepare_InitEmacMasterLink/90 (201326592 (estimated locally),0.19 per call) PlatformDrvPrepare_EnablePhyIf/83 (248034361 (estimated locally),0.23 per call) PlatformDrvPrepare_EnablePhyIf/83 (322122547 (estimated locally),0.30 per call) CreateHifDrv_Init/45 (77154443 (estimated locally),0.07 per call) CreateHifDrv_Init/45 (188142009 (estimated locally),0.18 per call) CreateHifDrv_Init/45 (264988745 (estimated locally),0.25 per call) CreateHifDrv_Init/45 (159987532 (estimated locally),0.15 per call) CreateHifDrv_Isr/46 (153053844 (estimated locally),0.14 per call) CreateHifDrv_Isr/46 (159987532 (estimated locally),0.15 per call) 
  Calls: 
pfe_hm_report/166 (pfe_hm_report) @0da3d000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: CreateHifDrv.constprop/578 (322122547 (estimated locally),0.30 per call) Eth_43_PFE_LLD_GetL2BridgeStats/155 (57412975 (estimated locally),0.05 per call) Eth_43_PFE_LLD_GetGpiStats/153 (75161928 (estimated locally),0.07 per call) Eth_43_PFE_LLD_GetBmuStats/152 (3614931 (estimated locally),0.07 per call) Eth_43_PFE_LLD_GetRxTimeStamp/148 (137083277 (estimated locally),0.13 per call) Eth_43_PFE_LLD_ReadMii45/142 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_ReadMii45/142 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii45/141 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii45/141 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_ReadMii/140 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_ReadMii/140 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii/139 (71717364 (estimated locally),0.07 per call) Eth_43_PFE_LLD_WriteMii/139 (71717364 (estimated locally),0.07 per call) Eth_PFE_LLD_Transmit/118 (181135951 (estimated locally),0.17 per call) Eth_PFE_LLD_Transmit/118 (524845004 (estimated locally),0.49 per call) Eth_PFE_LLD_PlatformDrvPrepare/85 (173198851 (estimated locally),0.16 per call) PlatformDrvPrepare_ShutdownConfigInit/84 (30880278 (estimated locally),0.03 per call) PlatformDrvPrepare_ShutdownConfigInit/84 (177167401 (estimated locally),0.17 per call) Eth_PFE_LLD_CheckInitializationStatus/97 (172618805 (estimated locally),0.16 per call) Eth_PFE_LLD_CheckInitializationStatus/97 (110420388 (estimated locally),0.10 per call) Eth_PFE_LLD_EMACPrepare/93 (79725330 (estimated locally),0.29 per call) Eth_PFE_LLD_InterfacePrepare/91 (35696984 (estimated locally),0.03 per call) Eth_PFE_LLD_InterfacePrepare/91 (265976587 (estimated locally),0.25 per call) Eth_PFE_LLD_InterfacePrepare/91 (187153200 (estimated locally),0.17 per call) ChannelBdFlushRxExecute/78 (4027668 (estimated locally),0.49 per call) ChannelBdFlushRxExecute/78 (10146860 (estimated locally),1.22 per call) ChannelBdFlushRxPrepare/77 (217214212 (estimated locally),0.20 per call) ChannelBdFlushRxPrepare/77 (186183611 (estimated locally),0.17 per call) ChannelBdFlushRxPrepare/77 (131007240 (estimated locally),0.12 per call) ChannelBdFlushRxPrepare/77 (322122547 (estimated locally),0.30 per call) EmacTsAdjustRatio/145 (209084376 (estimated locally),0.19 per call) UpdatePhysAddrFilter_Close.isra.0/552 (177167401 (estimated locally),0.17 per call) UpdatePhysAddrFilter_Close.isra.0/552 (536870913 (estimated locally),0.50 per call) UpdatePhysAddrFilter_RemoveBroad.isra.0/551 (354334802 (estimated locally),0.33 per call) UpdatePhysAddrFilter_AddBroad.isra.0/550 (354334802 (estimated locally),0.33 per call) UpdatePhysAddrFilter_RemoveMulti.isra.0/549 (354334802 (estimated locally),0.33 per call) EnableController_HifEmac/101 (287064877 (estimated locally),0.27 per call) EnableController_Common.part.0/548 (1073741824 (estimated locally),1.00 per call) InterfacePrepare_MasterConfigEMAC/89 (116930485 (estimated locally),0.11 per call) InterfacePrepare_MasterConfigEMAC/89 (58465242 (estimated locally),0.05 per call) ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (142359287 (estimated locally),0.13 per call) ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (167807293 (estimated locally),0.16 per call) ConfigureSchedulerAndShaper_SetShaper/66 (7178971 (estimated locally),0.06 per call) ConfigureSchedulerAndShaper_SetShaper/66 (14357941 (estimated locally),0.12 per call) ConfigureSchedulerAndShaper_SetShaper/66 (28715883 (estimated locally),0.25 per call) ConfigureSchedulerAndShaper_SetShaper/66 (57431766 (estimated locally),0.50 per call) ConfigureSchedulerAndShaper_MapUnusedInputs/69 (6317494 (estimated locally),0.11 per call) ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546 (1073741824 (estimated locally),1.00 per call) ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (177167401 (estimated locally),0.17 per call) ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (536870913 (estimated locally),0.50 per call) InterfacePrepare_InitEmacMasterRx/88 (54750298 (estimated locally),0.05 per call) InterfacePrepare_InitEmacMasterRx/88 (60279982 (estimated locally),0.06 per call) InterfacePrepare_InitEmacMasterRx/88 (99519890 (estimated locally),0.09 per call) InterfacePrepare_InitEmacMasterRx/88 (177167401 (estimated locally),0.17 per call) InterfacePrepare_InitEmacMasterRx/88 (177167401 (estimated locally),0.17 per call) UpdatePhysAddrFilter_AddMulti.isra.0/543 (262422502 (estimated locally),0.24 per call) Eth_PFE_LLD_EMACPrepare_Config/92 (118857851 (estimated locally),0.11 per call) Eth_PFE_LLD_EMACPrepare_Config/92 (305345331 (estimated locally),0.28 per call) Eth_PFE_LLD_EMACPrepare_Config/92 (201326592 (estimated locally),0.19 per call) InterfacePrepare_InitEmacMasterLink/90 (118857851 (estimated locally),0.11 per call) InterfacePrepare_InitEmacMasterLink/90 (305345331 (estimated locally),0.28 per call) InterfacePrepare_InitEmacMasterLink/90 (201326592 (estimated locally),0.19 per call) PlatformDrvPrepare_EnablePhyIf/83 (248034361 (estimated locally),0.23 per call) PlatformDrvPrepare_EnablePhyIf/83 (322122547 (estimated locally),0.30 per call) CreateHifDrv_Init/45 (77154443 (estimated locally),0.07 per call) CreateHifDrv_Init/45 (188142009 (estimated locally),0.18 per call) CreateHifDrv_Init/45 (264988745 (estimated locally),0.25 per call) CreateHifDrv_Init/45 (159987532 (estimated locally),0.15 per call) CreateHifDrv_Isr/46 (153053844 (estimated locally),0.14 per call) CreateHifDrv_Isr/46 (159987532 (estimated locally),0.15 per call) 
  Calls: 
bDetectBmuInit/165 (bDetectBmuInit) @066873a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Eth_PFE_LLD_PlatformDrvPrepare/85 (write)
  Availability: not_available
  Varpool flags:
Eth_43_PFE_LLD_SetMasterUp/164 (Eth_43_PFE_LLD_SetMasterUp) @0da3d700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_set_master_up/534 (217325345 (estimated locally),0.20 per call) pfe_hif_get_master_detect_cfg/533 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_ChannelBdFlushRx/163 (Eth_PFE_LLD_ChannelBdFlushRx) @0da3d460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ChannelBdFlushRxExecute/78 (354334802 (estimated locally),0.33 per call) ChannelBdFlushRxPrepare/77 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_GetTxErrorCounterValues/162 (Eth_PFE_LLD_GetTxErrorCounterValues) @0da3d1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_GetTxStats/161 (Eth_PFE_LLD_GetTxStats) @0da25ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_GetRxStats/160 (Eth_PFE_LLD_GetRxStats) @0da259a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_GetCounterValues/159 (Eth_PFE_LLD_GetCounterValues) @0da25380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) pfe_emac_get_stat_value/461 (574129754 (estimated locally),0.53 per call) Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (1073741824 (estimated locally),1.00 per call) 
Eth_43_PFE_LLD_GetTmuStats/158 (Eth_43_PFE_LLD_GetTmuStats) @0da25e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:37196709 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memset/524 (314968206 (estimated locally),8.47 per call) pfe_tmu_get_queue_stats/523 (954449109 (estimated locally),25.66 per call) pfe_tmu_get_special_stats/522 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) pfe_tmu_get_stat_value/521 (19889080 (estimated locally),0.53 per call) 
Eth_43_PFE_LLD_GetRtableStats/157 (Eth_43_PFE_LLD_GetRtableStats) @0da25b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_rtable_get_stats/520 (574129754 (estimated locally),0.53 per call) 
Eth_43_PFE_LLD_GetL2BridgeDomainStats/156 (Eth_43_PFE_LLD_GetL2BridgeDomainStats) @0da258c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_get_domain_stats/519 (574129754 (estimated locally),0.53 per call) 
Eth_43_PFE_LLD_GetL2BridgeStats/155 (Eth_43_PFE_LLD_GetL2BridgeStats) @0da25620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_l2br_get_stats/518 (516716778 (estimated locally),0.48 per call) oal_util_raise_dem_for_drv_runtime_err/167 (57412975 (estimated locally),0.05 per call) pfe_hm_report/166 (57412975 (estimated locally),0.05 per call) __builtin_expect/510 (574129754 (estimated locally),0.53 per call) pfe_l2br_get_number_entries/517 (574129754 (estimated locally),0.53 per call) 
Eth_43_PFE_LLD_GetWdtStats/154 (Eth_43_PFE_LLD_GetWdtStats) @0da252a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) pfe_wdt_get_stat_value/516 (574129754 (estimated locally),0.53 per call) 
Eth_43_PFE_LLD_GetGpiStats/153 (Eth_43_PFE_LLD_GetGpiStats) @0da25000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_gpi_get_special_stats/515 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_shp_get_drop_cnt/514 (676457350 (estimated locally),0.63 per call) pfe_gpi_shp_get_drop_cnt/514 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) pfe_gpi_get_stat_value/513 (676457350 (estimated locally),0.63 per call) oal_util_raise_dem_for_drv_runtime_err/167 (75161928 (estimated locally),0.07 per call) pfe_hm_report/166 (75161928 (estimated locally),0.07 per call) __builtin_expect/510 (751619278 (estimated locally),0.70 per call) 
Eth_43_PFE_LLD_GetBmuStats/152 (Eth_43_PFE_LLD_GetBmuStats) @0da127e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:51641870 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_bmu_get_special_stats/512 (32534377 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (1041207449 (estimated locally),20.16 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) pfe_bmu_get_stat_value/511 (32534378 (estimated locally),0.63 per call) oal_util_raise_dem_for_drv_runtime_err/167 (3614931 (estimated locally),0.07 per call) pfe_hm_report/166 (3614931 (estimated locally),0.07 per call) __builtin_expect/510 (36149309 (estimated locally),0.70 per call) 
Eth_43_PFE_LLD_GetClassStats/151 (Eth_43_PFE_LLD_GetClassStats) @0da12ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_get_stats/509 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_GetPlatform/150 (Eth_PFE_LLD_GetPlatform) @0da12c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_43_PFE_LLD_GetTxTimeStamp/149 (Eth_43_PFE_LLD_GetTxTimeStamp) @0da129a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBuf/31 (read)aarTxBuf/31 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_43_PFE_LLD_GetRxTimeStamp/148 (Eth_43_PFE_LLD_GetRxTimeStamp) @0da12700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (read)arPfeInterface/41 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_drv_client_get_ts/456 (594027532 (estimated locally),0.55 per call) oal_util_raise_dem_for_drv_runtime_err/167 (137083277 (estimated locally),0.13 per call) pfe_hm_report/166 (137083277 (estimated locally),0.13 per call) oal_util_parse_ptp/508 (731110809 (estimated locally),0.68 per call) 
Eth_43_PFE_LLD_EnableEgressTimeStamp/147 (Eth_43_PFE_LLD_EnableEgressTimeStamp) @0da12380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBuf/31 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_43_PFE_LLD_SetCorrectionTime/146 (Eth_43_PFE_LLD_SetCorrectionTime) @0da120e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: EmacTsAdjustRatio/145 (243685707 (estimated locally),0.23 per call) pfe_emac_adjust_ts_time/506 (242773027 (estimated locally),0.23 per call) 
EmacTsAdjustRatio/145 (EmacTsAdjustRatio) @0da0a460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: Eth_43_PFE_LLD_SetCorrectionTime/146 (243685707 (estimated locally),0.23 per call) 
  Calls: pfe_emac_set_ts_freq_adjustment/507 (59351079 (estimated locally),0.06 per call) oal_util_raise_dem_for_drv_runtime_err/167 (209084376 (estimated locally),0.19 per call) pfe_hm_report/166 (209084376 (estimated locally),0.19 per call) 
Eth_43_PFE_LLD_GetCurrentTime/144 (Eth_43_PFE_LLD_GetCurrentTime) @0da0ac40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_get_ts_time/505 (217325345 (estimated locally),0.20 per call) 
Eth_43_PFE_LLD_SetGlobalTime/143 (Eth_43_PFE_LLD_SetGlobalTime) @0da0a7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_emac_set_ts_time/504 (217325345 (estimated locally),0.20 per call) 
Eth_43_PFE_LLD_ReadMii45/142 (Eth_43_PFE_LLD_ReadMii45) @0da0a380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_unlock/500 (217325345 (estimated locally),0.20 per call) pfe_emac_mdio_read45/503 (217325345 (estimated locally),0.20 per call) oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_lock/498 (217325345 (estimated locally),0.20 per call) 
Eth_43_PFE_LLD_WriteMii45/141 (Eth_43_PFE_LLD_WriteMii45) @0d9ff460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_unlock/500 (217325345 (estimated locally),0.20 per call) pfe_emac_mdio_write45/502 (217325345 (estimated locally),0.20 per call) oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_lock/498 (217325345 (estimated locally),0.20 per call) 
Eth_43_PFE_LLD_ReadMii/140 (Eth_43_PFE_LLD_ReadMii) @0d9ff9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_unlock/500 (217325345 (estimated locally),0.20 per call) pfe_emac_mdio_read22/501 (217325345 (estimated locally),0.20 per call) oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_lock/498 (217325345 (estimated locally),0.20 per call) 
Eth_43_PFE_LLD_WriteMii/139 (Eth_43_PFE_LLD_WriteMii) @0d9ff380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_unlock/500 (217325345 (estimated locally),0.20 per call) pfe_emac_mdio_write22/499 (217325345 (estimated locally),0.20 per call) oal_util_raise_dem_for_drv_runtime_err/167 (71717364 (estimated locally),0.07 per call) pfe_hm_report/166 (71717364 (estimated locally),0.07 per call) pfe_emac_mdio_lock/498 (217325345 (estimated locally),0.20 per call) 
Eth_PFE_LLD_MainFunction/138 (Eth_PFE_LLD_MainFunction) @0d9f9e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)u32RtrTimeoutTimeMs/40 (read)u32RtrTimeoutTimeMs/40 (write)u32RtrTimeoutTimeMs/40 (read)u32RtrTimeoutTimeMs/40 (write)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (read)eSavedMode/42 (read)eSavedMode/42 (write)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_StaticConfig/224 (read)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (read)
  Referring: 
  Availability: available
  Function flags: count:31125933 (estimated locally) body optimize_size
  Called by: 
  Calls: Eth_PFE_LLD_PollerFunction/137 (21788154 (estimated locally),0.70 per call) pfe_hif_drv_client_ptp_ts_db_tick_iteration/460 (176285971 (estimated locally),5.66 per call) Eth_PFE_LLD_ReportTransmissionTS/126 (955630224 (estimated locally),30.70 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) CheckDemStatus.constprop/575 (176285970 (estimated locally),5.66 per call) Dem_SetEventStatus/459 (17840140 (estimated locally),0.57 per call) Dem_SetEventStatus/459 (17840140 (estimated locally),0.57 per call) EthIf_CtrlModeIndication/458 (86168583 (estimated locally),2.77 per call) pfe_rtable_do_timeouts/457 (7190091 (estimated locally),0.23 per call) 
Eth_PFE_LLD_PollerFunction/137 (Eth_PFE_LLD_PollerFunction) @0d9f28c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_MainFunction/138 (21788154 (estimated locally),0.70 per call) 
  Calls: Eth_PFE_LLD_PollerFunction_HIF/136 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_UTIL/135 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_CLASS/134 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_BMU/133 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_PARITY/131 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_BUS/130 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_EMAC/129 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_WDG/128 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_PollerFunction_ECC/127 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_PollerFunction_HIF/136 (Eth_PFE_LLD_PollerFunction_HIF) @0d9f2620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_irq_unmask/497 (574129754 (estimated locally),0.53 per call) pfe_hif_isr/496 (574129754 (estimated locally),0.53 per call) pfe_hif_irq_mask/495 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_PollerFunction_UTIL/135 (Eth_PFE_LLD_PollerFunction_UTIL) @0d9f2380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_util_irq_unmask/494 (574129754 (estimated locally),0.53 per call) pfe_util_isr/493 (574129754 (estimated locally),0.53 per call) pfe_util_irq_mask/492 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_PollerFunction_CLASS/134 (Eth_PFE_LLD_PollerFunction_CLASS) @0d9f20e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_class_irq_unmask/491 (574129754 (estimated locally),0.53 per call) pfe_class_isr/490 (574129754 (estimated locally),0.53 per call) pfe_class_irq_mask/489 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_PollerFunction_BMU/133 (Eth_PFE_LLD_PollerFunction_BMU) @0d9ede00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:357878150 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_bmu_irq_unmask/488 (286345 (estimated locally),0.00 per call) pfe_bmu_isr/487 (286345 (estimated locally),0.00 per call) pfe_bmu_irq_mask/486 (286345 (estimated locally),0.00 per call) 
Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (Eth_PFE_LLD_PollerFunction_FAILSTOP) @0d9edb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_host_fail_stop_irq_unmask/485 (574129754 (estimated locally),0.53 per call) pfe_host_fail_stop_isr/484 (574129754 (estimated locally),0.53 per call) pfe_host_fail_stop_irq_mask/483 (574129754 (estimated locally),0.53 per call) pfe_fw_fail_stop_irq_unmask/482 (574129754 (estimated locally),0.53 per call) pfe_fw_fail_stop_isr/481 (574129754 (estimated locally),0.53 per call) pfe_fw_fail_stop_irq_mask/480 (574129754 (estimated locally),0.53 per call) pfe_fail_stop_irq_unmask/479 (574129754 (estimated locally),0.53 per call) pfe_fail_stop_isr/478 (574129754 (estimated locally),0.53 per call) pfe_fail_stop_irq_mask/477 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_PollerFunction_PARITY/131 (Eth_PFE_LLD_PollerFunction_PARITY) @0d9ed8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_parity_irq_unmask/476 (574129754 (estimated locally),0.53 per call) pfe_parity_isr/475 (574129754 (estimated locally),0.53 per call) pfe_parity_irq_mask/474 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_PollerFunction_BUS/130 (Eth_PFE_LLD_PollerFunction_BUS) @0d9ed620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_bus_err_irq_unmask/473 (574129754 (estimated locally),0.53 per call) pfe_bus_err_isr/472 (574129754 (estimated locally),0.53 per call) pfe_bus_err_irq_mask/471 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_PollerFunction_EMAC/129 (Eth_PFE_LLD_PollerFunction_EMAC) @0d9ed380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:268435456 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_emac_irq_unmask/470 (430597315 (estimated locally),1.60 per call) pfe_emac_isr/469 (430597315 (estimated locally),1.60 per call) pfe_emac_irq_mask/468 (430597315 (estimated locally),1.60 per call) 
Eth_PFE_LLD_PollerFunction_WDG/128 (Eth_PFE_LLD_PollerFunction_WDG) @0d9ed0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_wdt_irq_unmask/467 (574129754 (estimated locally),0.53 per call) pfe_wdt_isr/466 (574129754 (estimated locally),0.53 per call) pfe_wdt_irq_mask/465 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_PollerFunction_ECC/127 (Eth_PFE_LLD_PollerFunction_ECC) @0d9dc9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PollerFunction/137 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_ecc_err_irq_unmask/464 (574129754 (estimated locally),0.53 per call) pfe_ecc_err_isr/463 (574129754 (estimated locally),0.53 per call) pfe_ecc_err_irq_mask/462 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_ReportTransmissionTS/126 (Eth_PFE_LLD_ReportTransmissionTS) @0d9dc0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (read)arPfeInterface/41 (read)aarTxBuf/31 (addr)aarTxBuf/31 (addr)arPfeInterface/41 (read)arPfeInterface/41 (write)arPfeInterface/41 (read)arPfeInterface/41 (write)arPfeInterface/41 (write)aarTxBuf/31 (read)Eth_43_PFE_InternalCfgPtr/184 (read)aarTxBuf/31 (write)aarTxBuf/31 (write)
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: Eth_PFE_LLD_MainFunction/138 (955630224 (estimated locally),30.70 per call) ClientEventHdlr_ETS/62 (108662672 (estimated locally),0.10 per call) 
  Calls: oal_mutex_unlock.part.0/536 (1073741824 (estimated locally),9.09 per call) oal_mutex_unlock.part.0/536 (97557347 (estimated locally),0.83 per call) EthIf_TxConfirmation/446 (97557347 (estimated locally),0.83 per call) oal_mutex_lock.part.0/535 (97557347 (estimated locally),0.83 per call) GetTxTimeStamp/64 (719407023 (estimated locally),6.09 per call) oal_mutex_lock.part.0/535 (1073741824 (estimated locally),9.09 per call) 
Eth_PFE_LLD_ReportTransmission/125 (Eth_PFE_LLD_ReportTransmission) @0d9dcc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (read)aarTxBuf/31 (read)aarTxBuf/31 (write)aarTxBuf/31 (read)aarTxBuf/31 (read)Eth_43_PFE_InternalCfgPtr/184 (read)aarTxBuf/31 (write)u16TxQueueRead/34 (read)arTxReqQueue/32 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: ClientEventHdlr_TX/61 (91268055 (estimated locally),0.08 per call) 
  Calls: oal_mutex_unlock.part.0/536 (178593000 (estimated locally),1.55 per call) EthIf_TxConfirmation/446 (178593000 (estimated locally),1.55 per call) oal_mutex_lock.part.0/535 (178593000 (estimated locally),1.55 per call) TxReqQueueDelete/59 (958878294 (estimated locally),8.35 per call) pfe_hif_drv_client_tx_done/455 (114863532 (estimated locally),1.00 per call) pfe_hif_drv_client_receive_tx_conf/454 (1044213930 (estimated locally),9.09 per call) 
Eth_PFE_LLD_ReportReception/124 (Eth_PFE_LLD_ReportReception) @0d9dc8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: ClientEventHdlr_RX/60 (108662672 (estimated locally),0.10 per call) 
  Calls: pfe_hif_drv_client_has_rx_pkt/450 (18952483 (estimated locally),0.17 per call) pfe_hif_drv_client_rx_done/449 (114863532 (estimated locally),1.00 per call) ReportReception_ProcessPacket.isra.0/553 (574129754 (estimated locally),5.00 per call) pfe_hif_drv_client_receive_pkt/448 (1073741824 (estimated locally),9.35 per call) 
ReportReception_GetBypassVLANTag/122 (ReportReception_GetBypassVLANTag) @0d9dc2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ReportReception_ProcessPacket.isra.0/553 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
IsRxChecksumValid/121 (IsRxChecksumValid) @0d9dc000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: ReportReception_ProcessPacket.isra.0/553 (1073741824 (estimated locally),1.00 per call) 
  Calls: IsRxChecksumValidIpV6/120 (240947665 (estimated locally),0.22 per call) IsRxChecksumValidIpV4/119 (365072220 (estimated locally),0.34 per call) 
IsRxChecksumValidIpV6/120 (IsRxChecksumValidIpV6) @0d9d17e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: IsRxChecksumValid/121 (240947665 (estimated locally),0.22 per call) 
  Calls: pfe_hif_pkt_icmp_csum_valid/18 (365072220 (estimated locally),0.34 per call) pfe_hif_pkt_tcpv6_csum_valid/17 (365072220 (estimated locally),0.34 per call) pfe_hif_pkt_udpv6_csum_valid/15 (365072220 (estimated locally),0.34 per call) 
IsRxChecksumValidIpV4/119 (IsRxChecksumValidIpV4) @0d9d12a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: IsRxChecksumValid/121 (365072220 (estimated locally),0.34 per call) 
  Calls: pfe_hif_pkt_icmp_csum_valid/18 (365072220 (estimated locally),0.34 per call) pfe_hif_pkt_tcpv4_csum_valid/16 (365072220 (estimated locally),0.34 per call) pfe_hif_pkt_udpv4_csum_valid/14 (365072220 (estimated locally),0.34 per call) 
Eth_PFE_LLD_Transmit/118 (Eth_PFE_LLD_Transmit) @0d9d1ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (addr)aarTxBuf/31 (read)aarTxBuf/31 (read)Eth_43_PFE_InternalCfgPtr/184 (read)aarTxBuf/31 (write)aarTxBuf/31 (read)aarTxBuf/31 (write)aarTxBuf/31 (write)aarTxBuf/31 (read)aarTxBuf/31 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: TxReqFailed/56 (181135951 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/167 (181135951 (estimated locally),0.17 per call) pfe_hm_report/166 (181135951 (estimated locally),0.17 per call) TxReqTrigger/55 (548896821 (estimated locally),0.51 per call) TxReqTsQueueWrite/54 (181135951 (estimated locally),0.17 per call) autolibc_memcpy/199 (548896821 (estimated locally),0.51 per call) autolibc_memcpy/199 (548896821 (estimated locally),0.51 per call) EthIf_TxConfirmation/446 (173198851 (estimated locally),0.16 per call) oal_util_raise_dem_for_drv_runtime_err/167 (524845004 (estimated locally),0.49 per call) pfe_hm_report/166 (524845004 (estimated locally),0.49 per call) 
Eth_PFE_LLD_ReleaseTxBuffer/117 (Eth_PFE_LLD_ReleaseTxBuffer) @0d9d19a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBuf/31 (read)aarTxBuf/31 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_43_PFE_LLD_GetTxBufferSize/116 (Eth_43_PFE_LLD_GetTxBufferSize) @0d9d1700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBufPool/30 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_43_PFE_LLD_GetTxFifoIdx/115 (Eth_43_PFE_LLD_GetTxFifoIdx) @0d9d1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBuf/31 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_43_PFE_LLD_GetLmemHdrSize/114 (Eth_43_PFE_LLD_GetLmemHdrSize) @0d9d11c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_PFE_LLD_ProvideBufferDataArea/113 (Eth_PFE_LLD_ProvideBufferDataArea) @0d9c8c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBufPool/30 (read)aarTxBuf/31 (read)aarTxBuf/31 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GetTxBuffer/51 (354334802 (estimated locally),0.33 per call) 
Eth_PFE_LLD_UpdatePhysAddrFilter/112 (Eth_PFE_LLD_UpdatePhysAddrFilter) @0d9c80e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (addr)Eth_43_PFE_InternalCfgPtr/184 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: Det_ReportError/232 (29232621 (estimated locally),0.03 per call) UpdatePhysAddrFilter_RemoveMulti.isra.0/549 (29675540 (estimated locally),0.03 per call) UpdatePhysAddrFilter_AddMulti.isra.0/543 (29675540 (estimated locally),0.03 per call) pfe_emac_is_multi/7 (88583700 (estimated locally),0.08 per call) UpdatePhysAddrFilter_Close.isra.0/552 (29232621 (estimated locally),0.03 per call) pfe_emac_is_zero/5 (177167401 (estimated locally),0.17 per call) UpdatePhysAddrFilter_RemoveBroad.isra.0/551 (88583700 (estimated locally),0.08 per call) UpdatePhysAddrFilter_AddBroad.isra.0/550 (88583700 (estimated locally),0.08 per call) pfe_emac_is_broad/6 (354334802 (estimated locally),0.33 per call) 
Eth_PFE_LLD_SetPhysAddr/106 (Eth_PFE_LLD_SetPhysAddr) @0d9c1e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (addr)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (read)rPlatformCfg/36 (read)arPfeInterface/41 (read)rPlatformCfg/36 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/199 (58306146 (estimated locally),0.05 per call) pfe_phy_if_add_mac_addr/206 (104528766 (estimated locally),0.10 per call) pfe_phy_if_del_mac_addr/231 (316753838 (estimated locally),0.30 per call) autolibc_memcpy/199 (220117073 (estimated locally),0.20 per call) autolibc_memcmp/230 (1073741823 (estimated locally),1.00 per call) 
Eth_PFE_LLD_GetPhysicalAddress/105 (Eth_PFE_LLD_GetPhysicalAddress) @0d9c19a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/199 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_CheckControllerIsActive/104 (Eth_PFE_LLD_CheckControllerIsActive) @0d9c1700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_PFE_LLD_DisableController/103 (Eth_PFE_LLD_DisableController) @0d9c1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (write)arPfeInterface/41 (read)arPfeInterface/41 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver.part.0/558 (287064877 (estimated locally),0.53 per call) 
  Calls: ReleaseAllCtrlTxBuffers/53 (1073741824 (estimated locally),1.00 per call) pfe_hif_drv_client_unregister/229 (574129754 (estimated locally),0.53 per call) 
Eth_PFE_LLD_EnableController/102 (Eth_PFE_LLD_EnableController) @0d9c11c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (addr)arPfeInterface/41 (read)arPfeInterface/41 (read)Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: EnableController_HifEmac/101 (39171712 (estimated locally),0.04 per call) pfe_phy_if_enable/197 (6659191 (estimated locally),0.01 per call) EnableController_HifEmac/101 (20179367 (estimated locally),0.02 per call) EnableController_Aux/100 (29232621 (estimated locally),0.03 per call) EnableController_InitFifos/98 (177167401 (estimated locally),0.17 per call) 
EnableController_HifEmac/101 (EnableController_HifEmac) @0d9b4a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ClientEventHdlr/63 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_EnableController/102 (39171712 (estimated locally),0.04 per call) Eth_PFE_LLD_EnableController/102 (20179367 (estimated locally),0.02 per call) 
  Calls: EnableController_Common/99 (287064877 (estimated locally),0.27 per call) oal_util_raise_dem_for_drv_runtime_err/167 (287064877 (estimated locally),0.27 per call) pfe_hm_report/166 (287064877 (estimated locally),0.27 per call) pfe_hif_drv_client_set_inject_if/228 (574129754 (estimated locally),0.53 per call) pfe_phy_if_get_id/226 (574129754 (estimated locally),0.53 per call) pfe_hif_drv_client_register/227 (1073741824 (estimated locally),1.00 per call) pfe_phy_if_get_id/226 (1073741824 (estimated locally),1.00 per call) 
EnableController_Aux/100 (EnableController_Aux) @0d9b4c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ClientEventHdlr/63 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_EnableController/102 (29232621 (estimated locally),0.03 per call) 
  Calls: EnableController_Common/99 (574129754 (estimated locally),0.53 per call) pfe_hif_drv_aux_client_register/223 (1073741824 (estimated locally),1.00 per call) 
EnableController_Common/99 (EnableController_Common) @0d9b49a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: EnableController_HifEmac/101 (287064877 (estimated locally),0.27 per call) EnableController_Aux/100 (574129754 (estimated locally),0.53 per call) 
  Calls: EnableController_Common.part.0/548 (354334800 (estimated locally),0.33 per call) InitializeTxHeaders/50 (1073741824 (estimated locally),1.00 per call) 
EnableController_InitFifos/98 (EnableController_InitFifos) @0d9b4620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_EnableController/102 (177167401 (estimated locally),0.17 per call) 
  Calls: fifo_create/222 (0 (precise),0.00 per call) fifo_create/222 (0 (precise),0.00 per call) 
Eth_PFE_LLD_CheckInitializationStatus/97 (Eth_PFE_LLD_CheckInitializationStatus) @0d9b4380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (read)arPfeInterface/41 (read)arPfeInterface/41 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (172618805 (estimated locally),0.16 per call) pfe_hm_report/166 (172618805 (estimated locally),0.16 per call) oal_util_raise_dem_for_drv_runtime_err/167 (110420388 (estimated locally),0.10 per call) pfe_hm_report/166 (110420388 (estimated locally),0.10 per call) 
Eth_PFE_LLD_CheckAccessToController/96 (Eth_PFE_LLD_CheckAccessToController) @0d9af9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_PFE_LLD_Check_Driver_Init/95 (Eth_PFE_LLD_Check_Driver_Init) @0d9afee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_CtrlState/198 (read)
  Referring: 
  Availability: available
  Function flags: count:566398813 (estimated locally) body optimize_size
  Called by: Eth_PFE_LLD_DeInit/86 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Eth_PFE_LLD_ConfigureController/94 (Eth_PFE_LLD_ConfigureController) @0d9afc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: arPfeInterface/41 (read)Eth_43_PFE_InternalCfgPtr/184 (read)u32DemErrorCounters/43 (write)
  Referring: 
  Availability: available
  Function flags: count:350860930 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_PFE_LLD_EMACPrepare/93 (Eth_PFE_LLD_EMACPrepare) @0d9af8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)Eth_43_PFE_InternalCfgPtr/184 (read)
  Referring: 
  Availability: available
  Function flags: count:278666874 (estimated locally) body optimize_size
  Called by: 
  Calls: Eth_PFE_LLD_EMACPrepare_Config/92 (186025771 (estimated locally),0.67 per call) oal_util_raise_dem_for_drv_runtime_err/167 (79725330 (estimated locally),0.29 per call) pfe_hm_report/166 (79725330 (estimated locally),0.29 per call) pfe_platform_get_phy_if_by_id/174 (265751101 (estimated locally),0.95 per call) 
Eth_PFE_LLD_EMACPrepare_Config/92 (Eth_PFE_LLD_EMACPrepare_Config) @0d9af540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_EMACPrepare/93 (186025771 (estimated locally),0.67 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (118857851 (estimated locally),0.11 per call) pfe_hm_report/166 (118857851 (estimated locally),0.11 per call) pfe_emac_set_link_duplex/203 (567069901 (estimated locally),0.53 per call) oal_util_raise_dem_for_drv_runtime_err/167 (305345331 (estimated locally),0.28 per call) pfe_hm_report/166 (305345331 (estimated locally),0.28 per call) pfe_emac_set_link_speed/202 (872415231 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/167 (201326592 (estimated locally),0.19 per call) pfe_hm_report/166 (201326592 (estimated locally),0.19 per call) pfe_phy_if_get_emac/201 (1073741823 (estimated locally),1.00 per call) 
Eth_PFE_LLD_InterfacePrepare/91 (Eth_PFE_LLD_InterfacePrepare) @0d9af000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ptrPlatform/35 (read)prCommonHifDrv/39 (read)arPfeInterface/41 (addr)arPfeInterface/41 (write)arPfeInterface/41 (addr)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (write)arPfeInterface/41 (write)arPfeInterface/41 (write)ptrPlatform/35 (read)arPfeInterface/41 (write)arPfeInterface/41 (write)prCommonHifChnl/37 (read)arPfeInterface/41 (write)prCommonChnlIRQ/38 (read)arPfeInterface/41 (write)prCommonHifDrv/39 (read)arPfeInterface/41 (write)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (write)arPfeInterface/41 (write)arPfeInterface/41 (write)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (write)arPfeInterface/41 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: InterfacePrepare_MasterConfigEMAC/89 (82658518 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/167 (35696984 (estimated locally),0.03 per call) pfe_hm_report/166 (35696984 (estimated locally),0.03 per call) pfe_platform_get_phy_if_by_id/174 (204801972 (estimated locally),0.19 per call) InterfacePrepare_InitTSQueue/87 (620612038 (estimated locally),0.58 per call) autolibc_memcpy/199 (620612038 (estimated locally),0.58 per call) oal_util_raise_dem_for_drv_runtime_err/167 (265976587 (estimated locally),0.25 per call) pfe_hm_report/166 (265976587 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/167 (187153200 (estimated locally),0.17 per call) pfe_hm_report/166 (187153200 (estimated locally),0.17 per call) 
InterfacePrepare_InitEmacMasterLink/90 (InterfacePrepare_InitEmacMasterLink) @0d9a57e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)Eth_43_PFE_InternalCfgPtr/184 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: InterfacePrepare_MasterConfigEMAC/89 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (118857851 (estimated locally),0.11 per call) pfe_hm_report/166 (118857851 (estimated locally),0.11 per call) pfe_emac_set_link_duplex/203 (567069901 (estimated locally),0.53 per call) oal_util_raise_dem_for_drv_runtime_err/167 (305345331 (estimated locally),0.28 per call) pfe_hm_report/166 (305345331 (estimated locally),0.28 per call) pfe_emac_set_link_speed/202 (872415231 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/167 (201326592 (estimated locally),0.19 per call) pfe_hm_report/166 (201326592 (estimated locally),0.19 per call) pfe_phy_if_get_emac/201 (1073741823 (estimated locally),1.00 per call) 
InterfacePrepare_MasterConfigEMAC/89 (InterfacePrepare_MasterConfigEMAC) @0d9a50e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_InterfacePrepare/91 (82658518 (estimated locally),0.08 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (116930485 (estimated locally),0.11 per call) pfe_hm_report/166 (116930485 (estimated locally),0.11 per call) ConfigureSchedulerAndShaper/70 (354334802 (estimated locally),0.33 per call) oal_util_raise_dem_for_drv_runtime_err/167 (58465242 (estimated locally),0.05 per call) pfe_hm_report/166 (58465242 (estimated locally),0.05 per call) pfe_phy_if_loopback_enable/200 (177167401 (estimated locally),0.17 per call) InterfacePrepare_InitEmacMasterRx/88 (354334802 (estimated locally),0.33 per call) InterfacePrepare_InitEmacMasterLink/90 (1073741824 (estimated locally),1.00 per call) 
InterfacePrepare_InitEmacMasterRx/88 (InterfacePrepare_InitEmacMasterRx) @0d99cee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)rPlatformCfg/36 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: InterfacePrepare_MasterConfigEMAC/89 (354334802 (estimated locally),0.33 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (54750298 (estimated locally),0.05 per call) pfe_hm_report/166 (54750298 (estimated locally),0.05 per call) pfe_log_if_get_name/210 (54750298 (estimated locally),0.05 per call) pfe_log_if_set_egress_ifs/209 (261213256 (estimated locally),0.24 per call) oal_util_raise_dem_for_drv_runtime_err/167 (60279982 (estimated locally),0.06 per call) pfe_hm_report/166 (60279982 (estimated locally),0.06 per call) pfe_phy_if_get_name/208 (60279982 (estimated locally),0.06 per call) pfe_phy_if_get_default_log_if/207 (321493238 (estimated locally),0.30 per call) oal_util_raise_dem_for_drv_runtime_err/167 (99519890 (estimated locally),0.09 per call) pfe_hm_report/166 (99519890 (estimated locally),0.09 per call) pfe_phy_if_add_mac_addr/206 (719407022 (estimated locally),0.67 per call) oal_util_raise_dem_for_drv_runtime_err/167 (177167401 (estimated locally),0.17 per call) pfe_hm_report/166 (177167401 (estimated locally),0.17 per call) pfe_phy_if_promisc_disable/205 (536870911 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/167 (177167401 (estimated locally),0.17 per call) pfe_hm_report/166 (177167401 (estimated locally),0.17 per call) pfe_phy_if_promisc_enable/204 (536870911 (estimated locally),0.50 per call) 
InterfacePrepare_InitTSQueue/87 (InterfacePrepare_InitTSQueue) @0d99c540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)
  Referring: 
  Availability: local
  Function flags: count:178912235 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_InterfacePrepare/91 (620612038 (estimated locally),0.58 per call) 
  Calls: 
Eth_PFE_LLD_DeInit/86 (Eth_PFE_LLD_DeInit) @0d99c2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Eth_43_PFE_CtrlState/198 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Eth_PFE_LLD_ShutdownDriver/75 (354334802 (estimated locally),0.33 per call) Eth_PFE_LLD_Check_Driver_Init/95 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_PlatformDrvPrepare/85 (Eth_PFE_LLD_PlatformDrvPrepare) @0d99c000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: bDetectBmuInit/165 (write)rPlatformCfg/36 (read)prCommonHifChnl/37 (addr)prCommonChnlIRQ/38 (addr)prCommonHifDrv/39 (addr)prCommonHifDrv/39 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: PlatformDrvPrepare_EnablePhyIf/83 (440185405 (estimated locally),0.41 per call) oal_util_raise_dem_for_drv_runtime_err/167 (173198851 (estimated locally),0.16 per call) pfe_hm_report/166 (173198851 (estimated locally),0.16 per call) CreateHifDrv.constprop/578 (524845004 (estimated locally),0.49 per call) PlatformDrvPrepare_ShutdownConfigInit/84 (1073741824 (estimated locally),1.00 per call) 
PlatformDrvPrepare_ShutdownConfigInit/84 (PlatformDrvPrepare_ShutdownConfigInit) @0d98fee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_class_fw_binary/168 (addr)rPlatformCfg/36 (write)rPlatformCfg/36 (write)rPlatformCfg/36 (write)rPlatformCfg/36 (write)rPlatformCfg/36 (addr)ptrPlatform/35 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PlatformDrvPrepare/85 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (30880278 (estimated locally),0.03 per call) pfe_hm_report/166 (30880278 (estimated locally),0.03 per call) pfe_platform_get_instance/170 (177167401 (estimated locally),0.17 per call) hal_ip_ready_set.constprop/582 (177167401 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/167 (177167401 (estimated locally),0.17 per call) pfe_hm_report/166 (177167401 (estimated locally),0.17 per call) pfe_platform_init/169 (354334802 (estimated locally),0.33 per call) ConfigureTxBuffers/49 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_ShutdownDriver/75 (1073741824 (estimated locally),1.00 per call) 
PlatformDrvPrepare_EnablePhyIf/83 (PlatformDrvPrepare_EnablePhyIf) @0d98fa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_PlatformDrvPrepare/85 (440185405 (estimated locally),0.41 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (248034361 (estimated locally),0.23 per call) pfe_hm_report/166 (248034361 (estimated locally),0.23 per call) pfe_phy_if_enable/197 (751619277 (estimated locally),0.70 per call) oal_util_raise_dem_for_drv_runtime_err/167 (322122547 (estimated locally),0.30 per call) pfe_hm_report/166 (322122547 (estimated locally),0.30 per call) pfe_platform_get_phy_if_by_id/174 (1073741823 (estimated locally),1.00 per call) 
Eth_PFE_LLD_InitEMACs/82 (Eth_PFE_LLD_InitEMACs) @0d98f540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:268435456 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_PFE_LLD_InitInterfaces/81 (Eth_PFE_LLD_InitInterfaces) @0d974d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: CSWTCH.392/557 (read)
  Referring: 
  Availability: available
  Function flags: count:59055800 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_PFE_LLD_GetTxBufTsRef/80 (Eth_PFE_LLD_GetTxBufTsRef) @0d974ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBuf/31 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Eth_PFE_LLD_GetTxBufMeta/79 (Eth_PFE_LLD_GetTxBufMeta) @0d974c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: aarTxBuf/31 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ChannelBdFlushRxExecute/78 (ChannelBdFlushRxExecute) @0d9749a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:8289750 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ChannelBdFlushRx/163 (354334802 (estimated locally),0.33 per call) 
  Calls: pfe_hif_chnl_cfg_tx_disable/532 (8289751 (estimated locally),1.00 per call) pfe_hif_chnl_cfg_rx_disable/531 (8289751 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/167 (4027668 (estimated locally),0.49 per call) pfe_hm_report/166 (4027668 (estimated locally),0.49 per call) pfe_hif_chnl_cfg_get_rx_bdp_rd_fifo_cnt/529 (1073741824 (estimated locally),129.53 per call) oal_util_raise_dem_for_drv_runtime_err/167 (10146860 (estimated locally),1.22 per call) pfe_hm_report/166 (10146860 (estimated locally),1.22 per call) pfe_idex_send_dummy_frame/530 (73230328 (estimated locally),8.83 per call) pfe_hif_chnl_cfg_get_rx_bdp_rd_fifo_cnt/529 (8289750 (estimated locally),1.00 per call) pfe_hif_get_channel_phy/525 (8289750 (estimated locally),1.00 per call) 
ChannelBdFlushRxPrepare/77 (ChannelBdFlushRxPrepare) @0d974380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ChannelBdFlushRx/163 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_chnl_cfg_rx_enable/528 (217214212 (estimated locally),0.20 per call) pfe_if_db_unlock/527 (217214212 (estimated locally),0.20 per call) oal_util_raise_dem_for_drv_runtime_err/167 (217214212 (estimated locally),0.20 per call) pfe_hm_report/166 (217214212 (estimated locally),0.20 per call) pfe_phy_if_disable/175 (434428425 (estimated locally),0.40 per call) oal_util_raise_dem_for_drv_runtime_err/167 (186183611 (estimated locally),0.17 per call) pfe_hm_report/166 (186183611 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/167 (131007240 (estimated locally),0.12 per call) pfe_hm_report/166 (131007240 (estimated locally),0.12 per call) pfe_phy_if_get_phy/526 (751619277 (estimated locally),0.70 per call) pfe_hif_get_channel_phy/525 (751619277 (estimated locally),0.70 per call) oal_util_raise_dem_for_drv_runtime_err/167 (322122547 (estimated locally),0.30 per call) pfe_hm_report/166 (322122547 (estimated locally),0.30 per call) 
Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (Eth_PFE_LLD_GetEmacInstanceByControllerId) @0d96bb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: DetectErrorsAndLostFrame.constprop/577 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_GetTxErrorCounterValues/162 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_GetTxStats/161 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_GetRxStats/160 (1073741824 (estimated locally),1.00 per call) Eth_PFE_LLD_GetCounterValues/159 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Eth_PFE_LLD_ShutdownDriver/75 (Eth_PFE_LLD_ShutdownDriver) @0d96b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: prCommonChnlIRQ/38 (read)ptrPlatform/35 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_DeInit/86 (354334802 (estimated locally),0.33 per call) PlatformDrvPrepare_ShutdownConfigInit/84 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_platform_remove/173 (536870913 (estimated locally),0.50 per call) pfe_platform_remove_sw_if/172 (536870913 (estimated locally),0.50 per call) oal_irq_destroy/171 (287064877 (estimated locally),0.27 per call) Eth_PFE_LLD_ShutdownDriver.part.0/558 (536870912 (estimated locally),0.50 per call) Eth_PFE_LLD_DetectHardReset/74 (1073741824 (estimated locally),1.00 per call) 
Eth_PFE_LLD_DetectHardReset/74 (Eth_PFE_LLD_DetectHardReset) @0d96bd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver/75 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_chnl_tx_irq_unmask/181 (0 (precise),0.00 per call) pfe_hif_chnl_rx_irq_unmask/180 (0 (precise),0.00 per call) pfe_hif_chnl_tx_enable/179 (0 (precise),0.00 per call) pfe_hif_chnl_rx_enable/178 (0 (precise),0.00 per call) pfe_hif_chnl_inspect_hw_state/177 (306987179 (estimated locally),0.29 per call) pfe_hif_get_channel/176 (574129754 (estimated locally),0.53 per call) 
CheckDemStatus/72 (CheckDemStatus) @0d96b7e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
DetectErrorsAndLostFrame/71 (DetectErrorsAndLostFrame) @0d96b540
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
ConfigureSchedulerAndShaper/70 (ConfigureSchedulerAndShaper) @0d96b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)
  Referring: 
  Availability: local
  Function flags: count:13759443 (estimated locally) body local optimize_size
  Called by: InterfacePrepare_MasterConfigEMAC/89 (354334802 (estimated locally),0.33 per call) 
  Calls: ConfigureSchedulerAndShaper_MapUnusedInputs/69 (1498403 (estimated locally),0.11 per call) ConfigureSchedulerAndShaper_MapUnusedInputs/69 (4540616 (estimated locally),0.33 per call) ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (958878292 (estimated locally),69.69 per call) ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (114863532 (estimated locally),8.35 per call) 
ConfigureSchedulerAndShaper_MapUnusedInputs/69 (ConfigureSchedulerAndShaper_MapUnusedInputs) @07949ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:59489074 (estimated locally) body local optimize_size
  Called by: ConfigureSchedulerAndShaper/70 (1498403 (estimated locally),0.11 per call) ConfigureSchedulerAndShaper/70 (4540616 (estimated locally),0.33 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/167 (6317494 (estimated locally),0.11 per call) pfe_hm_report/166 (6317494 (estimated locally),0.11 per call) pfe_tmu_sch_bind_queue/215 (114863531 (estimated locally),1.93 per call) 
ConfigureSchedulerAndShaper_SetShaper/66 (ConfigureSchedulerAndShaper_SetShaper) @07949540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ptrPlatform/35 (read)ptrPlatform/35 (read)*.LC0/216 (read)ptrPlatform/35 (read)ptrPlatform/35 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (222232129 (estimated locally),0.21 per call) 
  Calls: ConfigureSchedulerAndShaper_SetFifo.isra.0/545 (7178971 (estimated locally),0.06 per call) oal_util_raise_dem_for_drv_runtime_err/167 (7178971 (estimated locally),0.06 per call) pfe_hm_report/166 (7178971 (estimated locally),0.06 per call) pfe_tmu_shp_set_idle_slope/220 (14357941 (estimated locally),0.12 per call) oal_util_raise_dem_for_drv_runtime_err/167 (14357941 (estimated locally),0.12 per call) pfe_hm_report/166 (14357941 (estimated locally),0.12 per call) pfe_tmu_shp_set_position/219 (28715883 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/167 (28715883 (estimated locally),0.25 per call) pfe_hm_report/166 (28715883 (estimated locally),0.25 per call) pfe_tmu_shp_set_limits/218 (57431766 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/167 (57431766 (estimated locally),0.50 per call) pfe_hm_report/166 (57431766 (estimated locally),0.50 per call) pfe_tmu_shp_enable/217 (55807731 (estimated locally),0.49 per call) 
GetTxTimeStamp/64 (GetTxTimeStamp) @0793d0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: arPfeInterface/41 (read)aarTxBuf/31 (read)aarTxBuf/31 (read)aarTxBuf/31 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ReportTransmissionTS/126 (719407023 (estimated locally),6.09 per call) 
  Calls: pfe_hif_drv_client_get_ts/456 (731110809 (estimated locally),0.68 per call) 
ClientEventHdlr/63 (ClientEventHdlr) @0793dd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: EnableController_Aux/100 (addr)EnableController_HifEmac/101 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ClientEventHdlr_ETS/62 (268435456 (estimated locally),0.25 per call) ClientEventHdlr_TX/61 (268435456 (estimated locally),0.25 per call) ClientEventHdlr_RX/60 (268435456 (estimated locally),0.25 per call) 
ClientEventHdlr_ETS/62 (ClientEventHdlr_ETS) @0793da80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_StaticConfig/224 (read)Eth_43_PFE_CtrlState/198 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: ClientEventHdlr/63 (268435456 (estimated locally),0.25 per call) 
  Calls: Eth_PFE_LLD_ReportTransmissionTS/126 (108662672 (estimated locally),0.10 per call) 
ClientEventHdlr_TX/61 (ClientEventHdlr_TX) @0793d700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_StaticConfig/224 (read)Eth_43_PFE_CtrlState/198 (read)arPfeInterface/41 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: ClientEventHdlr/63 (268435456 (estimated locally),0.25 per call) 
  Calls: Eth_PFE_LLD_ReportTransmission/125 (91268055 (estimated locally),0.08 per call) 
ClientEventHdlr_RX/60 (ClientEventHdlr_RX) @0793d380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_StaticConfig/224 (read)Eth_43_PFE_CtrlState/198 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: ClientEventHdlr/63 (268435456 (estimated locally),0.25 per call) 
  Calls: Eth_PFE_LLD_ReportReception/124 (108662672 (estimated locally),0.10 per call) 
TxReqQueueDelete/59 (TxReqQueueDelete) @0793d000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: u16TxQueueRead/34 (read)arTxReqQueue/32 (write)u16TxQueueRead/34 (write)u16TxQueueRead/34 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ReportTransmission/125 (958878294 (estimated locally),8.35 per call) 
  Calls: 
TxReqQueueWrite/57 (TxReqQueueWrite) @07932540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: u16TxQueueWrite/33 (read)arTxReqQueue/32 (addr)u16TxQueueWrite/33 (write)u16TxQueueWrite/33 (write)arTxReqQueue/32 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: TxReqTrigger/55 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
TxReqFailed/56 (TxReqFailed) @07932000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: aarTxBuf/31 (read)arPfeInterface/41 (read)Eth_43_PFE_InternalCfgPtr/184 (read)arPfeInterface/41 (read)aarTxBuf/31 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_Transmit/118 (181135951 (estimated locally),0.17 per call) 
  Calls: pfe_hif_chnl_irq_unmask/187 (354334802 (estimated locally),0.33 per call) EthIf_TxConfirmation/446 (354334802 (estimated locally),0.33 per call) pfe_hif_chnl_irq_mask/190 (354334802 (estimated locally),0.33 per call) 
TxReqTrigger/55 (TxReqTrigger) @07932c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: aarTxBuf/31 (read)aarTxBuf/31 (read)arPfeInterface/41 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_Transmit/118 (548896821 (estimated locally),0.51 per call) 
  Calls: pfe_hif_drv_client_xmit_pkt/447 (1073741824 (estimated locally),1.00 per call) TxReqQueueWrite/57 (1073741824 (estimated locally),1.00 per call) 
TxReqTsQueueWrite/54 (TxReqTsQueueWrite) @079329a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: aarTxBuf/31 (read)arPfeInterface/41 (read)arPfeInterface/41 (write)arPfeInterface/41 (read)arPfeInterface/41 (write)arPfeInterface/41 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_Transmit/118 (181135951 (estimated locally),0.17 per call) 
  Calls: oal_mutex_unlock.part.0/536 (1073741824 (estimated locally),1.00 per call) oal_mutex_lock.part.0/535 (1073741824 (estimated locally),1.00 per call) 
ReleaseAllCtrlTxBuffers/53 (ReleaseAllCtrlTxBuffers) @07932700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: aarTxBuf/31 (write)
  Referring: 
  Availability: local
  Function flags: count:214748364 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_DisableController/103 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GetTxBuffer/51 (GetTxBuffer) @079321c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: aarTxBufPool/30 (read)aarTxBufPool/30 (read)aarTxBufPool/30 (read)aarTxBuf/31 (read)aarTxBuf/31 (write)aarTxBufPool/30 (read)aarTxBufPool/30 (read)aarTxBufPool/30 (write)aarTxBufPool/30 (write)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ProvideBufferDataArea/113 (354334802 (estimated locally),0.33 per call) 
  Calls: oal_mutex_unlock.part.0/536 (11952894 (estimated locally),0.10 per call) oal_mutex_lock.part.0/535 (11952894 (estimated locally),0.10 per call) 
InitializeTxHeaders/50 (InitializeTxHeaders) @07818c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Eth_43_PFE_InternalCfgPtr/184 (read)aarTxBuf/31 (read)aarTxBuf/31 (read)aarTxBufPool/30 (read)
  Referring: 
  Availability: local
  Function flags: count:59046942 (estimated locally) body local optimize_size
  Called by: EnableController_Common/99 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_drv_init_tx_header/225 (955630223 (estimated locally),16.18 per call) 
ConfigureTxBuffers/49 (ConfigureTxBuffers) @078181c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: auTxBufMem/29 (addr)Eth_43_PFE_InternalCfgPtr/184 (read)aarTxBufPool/30 (write)aarTxBufPool/30 (write)aarTxBufPool/30 (write)aarTxBufPool/30 (read)aarTxBufPool/30 (write)aarTxBufPool/30 (write)aarTxBufPool/30 (write)aarTxBufPool/30 (read)aarTxBufPool/30 (read)aarTxBufPool/30 (read)aarTxBuf/31 (write)aarTxBuf/31 (write)aarTxBuf/31 (write)arTxReqQueue/32 (write)arTxReqQueue/32 (write)u16TxQueueWrite/33 (write)u16TxQueueRead/34 (write)
  Referring: 
  Availability: local
  Function flags: count:107358075 (estimated locally) body local optimize_size
  Called by: PlatformDrvPrepare_ShutdownConfigInit/84 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
DestroyHifDrv/48 (DestroyHifDrv) @07818b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_ShutdownDriver.part.0/558 (536870913 (estimated locally),1.00 per call) CreateHifDrv_Init/45 (690272729 (estimated locally),0.64 per call) 
  Calls: oal_irq_destroy/171 (574129754 (estimated locally),0.53 per call) pfe_hif_drv_destroy/183 (574129754 (estimated locally),0.53 per call) pfe_idex_fini/182 (574129754 (estimated locally),0.53 per call) 
CreateHifDrv/47 (CreateHifDrv) @078188c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
CreateHifDrv_Isr/46 (CreateHifDrv_Isr) @07818540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: CommonHifChnlISR/44 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: CreateHifDrv.constprop/578 (751619278 (estimated locally),0.70 per call) 
  Calls: oal_irq_destroy/171 (153053844 (estimated locally),0.14 per call) oal_util_raise_dem_for_drv_runtime_err/167 (153053844 (estimated locally),0.14 per call) pfe_hm_report/166 (153053844 (estimated locally),0.14 per call) oal_irq_add_handler/189 (913754293 (estimated locally),0.85 per call) oal_util_raise_dem_for_drv_runtime_err/167 (159987532 (estimated locally),0.15 per call) pfe_hm_report/166 (159987532 (estimated locally),0.15 per call) oal_irq_create/188 (1073741824 (estimated locally),1.00 per call) 
CreateHifDrv_Init/45 (CreateHifDrv_Init) @078180e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: rPlatformCfg/36 (read)ptrPlatform/35 (read)pfe_platform_idex_rpc_cbk/196 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: CreateHifDrv.constprop/578 (401890828 (estimated locally),0.37 per call) 
  Calls: DestroyHifDrv/48 (690272729 (estimated locally),0.64 per call) oal_util_raise_dem_for_drv_runtime_err/167 (77154443 (estimated locally),0.07 per call) pfe_hm_report/166 (77154443 (estimated locally),0.07 per call) pfe_idex_init/195 (460623539 (estimated locally),0.43 per call) oal_util_raise_dem_for_drv_runtime_err/167 (188142009 (estimated locally),0.18 per call) pfe_hm_report/166 (188142009 (estimated locally),0.18 per call) pfe_hif_drv_start/194 (648765548 (estimated locally),0.60 per call) oal_util_raise_dem_for_drv_runtime_err/167 (264988745 (estimated locally),0.25 per call) pfe_hm_report/166 (264988745 (estimated locally),0.25 per call) pfe_hif_drv_init/193 (913754293 (estimated locally),0.85 per call) oal_util_raise_dem_for_drv_runtime_err/167 (159987532 (estimated locally),0.15 per call) pfe_hm_report/166 (159987532 (estimated locally),0.15 per call) pfe_hif_drv_create/192 (1073741824 (estimated locally),1.00 per call) 
CommonHifChnlISR/44 (CommonHifChnlISR) @0780fc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: CreateHifDrv_Isr/46 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_irq_unmask/187 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_isr/191 (1073741824 (estimated locally),1.00 per call) pfe_hif_chnl_irq_mask/190 (1073741824 (estimated locally),1.00 per call) 
u32DemErrorCounters/43 (u32DemErrorCounters) @077e6e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: DetectErrorsAndLostFrame.constprop.0/577 (write)DetectErrorsAndLostFrame.constprop.0/577 (read)Eth_PFE_LLD_ConfigureController/94 (write)
  Availability: available
  Varpool flags:
eSavedMode/42 (eSavedMode) @077e6d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Eth_PFE_LLD_ShutdownDriver.part.0/558 (write)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (write)
  Availability: available
  Varpool flags:
arPfeInterface/41 (arPfeInterface) @077e6cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Eth_PFE_LLD_EnableController/102 (read)TxReqFailed/56 (read)GetTxTimeStamp/64 (read)ClientEventHdlr_TX/61 (read)TxReqFailed/56 (read)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_ConfigureController/94 (read)Eth_PFE_LLD_CheckInitializationStatus/97 (read)Eth_PFE_LLD_DisableController/103 (write)Eth_PFE_LLD_ShutdownDriver.part.0/558 (read)Eth_PFE_LLD_CheckControllerIsActive/104 (read)Eth_PFE_LLD_GetPhysicalAddress/105 (addr)TxReqTsQueueWrite/54 (write)Eth_PFE_LLD_SetPhysAddr/106 (read)Eth_PFE_LLD_UpdatePhysAddrFilter/112 (addr)Eth_PFE_LLD_ReportTransmission/125 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (write)TxReqTrigger/55 (read)Eth_PFE_LLD_Transmit/118 (addr)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_ReportReception/124 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_SetPhysAddr/106 (addr)Eth_PFE_LLD_SetPhysAddr/106 (read)TxReqTsQueueWrite/54 (read)TxReqTsQueueWrite/54 (write)TxReqTsQueueWrite/54 (read)TxReqTsQueueWrite/54 (write)Eth_PFE_LLD_InterfacePrepare/91 (addr)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (addr)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_InterfacePrepare/91 (write)Eth_PFE_LLD_CheckInitializationStatus/97 (read)Eth_PFE_LLD_CheckInitializationStatus/97 (read)Eth_PFE_LLD_EnableController/102 (addr)Eth_PFE_LLD_EnableController/102 (read)Eth_PFE_LLD_EnableController/102 (read)Eth_PFE_LLD_DisableController/103 (write)Eth_PFE_LLD_DisableController/103 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (write)Eth_PFE_LLD_ReportTransmissionTS/126 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (write)Eth_43_PFE_LLD_GetRxTimeStamp/148 (read)Eth_43_PFE_LLD_GetRxTimeStamp/148 (read)
  Availability: available
  Varpool flags:
u32RtrTimeoutTimeMs/40 (u32RtrTimeoutTimeMs) @077e6c60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Eth_PFE_LLD_ShutdownDriver.part.0/558 (write)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (write)Eth_PFE_LLD_MainFunction/138 (read)Eth_PFE_LLD_MainFunction/138 (write)
  Availability: available
  Varpool flags: initialized
prCommonHifDrv/39 (prCommonHifDrv) @077e6bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_ShutdownDriver.part.0/558 (read)Eth_PFE_LLD_ShutdownDriver.part.0/558 (write)Eth_PFE_LLD_PlatformDrvPrepare/85 (addr)Eth_PFE_LLD_PlatformDrvPrepare/85 (write)CreateHifDrv.constprop.0/578 (addr)
  Availability: available
  Varpool flags: initialized
prCommonChnlIRQ/38 (prCommonChnlIRQ) @077e6b40
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_ShutdownDriver/75 (read)Eth_PFE_LLD_ShutdownDriver.part.0/558 (read)Eth_PFE_LLD_PlatformDrvPrepare/85 (addr)CreateHifDrv.constprop.0/578 (addr)
  Availability: available
  Varpool flags: initialized
prCommonHifChnl/37 (prCommonHifChnl) @077e6ab0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_PlatformDrvPrepare/85 (addr)CreateHifDrv.constprop.0/578 (addr)
  Availability: available
  Varpool flags: initialized
rPlatformCfg/36 (rPlatformCfg) @077e6a20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: UpdatePhysAddrFilter_Close.isra.0/552 (read)PlatformDrvPrepare_ShutdownConfigInit/84 (addr)InterfacePrepare_InitEmacMasterRx/88 (read)Eth_PFE_LLD_PlatformDrvPrepare/85 (read)UpdatePhysAddrFilter_RemoveMulti.isra.0/549 (read)UpdatePhysAddrFilter_AddMulti.isra.0/543 (read)CreateHifDrv_Init/45 (read)PlatformDrvPrepare_ShutdownConfigInit/84 (write)PlatformDrvPrepare_ShutdownConfigInit/84 (write)Eth_PFE_LLD_SetPhysAddr/106 (read)Eth_PFE_LLD_SetPhysAddr/106 (read)PlatformDrvPrepare_ShutdownConfigInit/84 (write)PlatformDrvPrepare_ShutdownConfigInit/84 (write)
  Availability: available
  Varpool flags: initialized
ptrPlatform/35 (ptrPlatform) @077e6948
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_PFE_LLD_EMACPrepare/93 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_HIF/136 (read)Eth_PFE_LLD_InterfacePrepare/91 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_PFE_LLD_DetectHardReset/74 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_PFE_LLD_GetEmacInstanceByControllerId/76 (read)CreateHifDrv_Init/45 (read)Eth_PFE_LLD_PollerFunction_UTIL/135 (read)Eth_PFE_LLD_PollerFunction_HIF/136 (read)ChannelBdFlushRxPrepare/77 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)CreateHifDrv.constprop.0/578 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)ConfigureSchedulerAndShaper_MapUnusedInputs/69 (read)PlatformDrvPrepare_EnablePhyIf/83 (read)Eth_PFE_LLD_PollerFunction_UTIL/135 (read)Eth_PFE_LLD_PollerFunction_HIF/136 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)ConfigureSchedulerAndShaper_SetFifo.isra.0/545 (read)ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (read)ChannelBdFlushRxExecute/78 (read)Eth_PFE_LLD_ShutdownDriver.part.0/558 (read)Eth_PFE_LLD_ShutdownDriver/75 (write)Eth_43_PFE_LLD_GetRtableStats/157 (read)Eth_43_PFE_LLD_SetMasterUp/164 (read)ConfigureSchedulerAndShaper_SetRateModeAlgo.isra.0/544 (read)ConfigureSchedulerAndShaper_SetShaper/66 (read)ConfigureSchedulerAndShaper_SetShaper/66 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (read)ConfigureSchedulerAndShaper_SetSchedulerInput.isra.0/547 (read)Eth_PFE_LLD_PollerFunction_UTIL/135 (read)ConfigureSchedulerAndShaper_SetShaper/66 (read)Eth_PFE_LLD_PollerFunction_ECC/127 (read)Eth_PFE_LLD_PollerFunction_ECC/127 (read)Eth_PFE_LLD_PollerFunction_ECC/127 (read)ConfigureSchedulerAndShaper_SetShaper/66 (read)Eth_PFE_LLD_PollerFunction_WDG/128 (read)Eth_PFE_LLD_PollerFunction_WDG/128 (read)Eth_PFE_LLD_PollerFunction_WDG/128 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_PFE_LLD_PollerFunction_EMAC/129 (read)Eth_PFE_LLD_PollerFunction_EMAC/129 (read)Eth_PFE_LLD_PollerFunction_EMAC/129 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetL2BridgeDomainStats/156 (read)Eth_43_PFE_LLD_SetMasterUp/164 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_PFE_LLD_PollerFunction_BUS/130 (read)Eth_PFE_LLD_PollerFunction_BUS/130 (read)Eth_PFE_LLD_PollerFunction_BUS/130 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_PFE_LLD_PollerFunction_PARITY/131 (read)Eth_PFE_LLD_PollerFunction_PARITY/131 (read)Eth_PFE_LLD_PollerFunction_PARITY/131 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_BMU/133 (read)Eth_PFE_LLD_PollerFunction_BMU/133 (read)Eth_PFE_LLD_PollerFunction_BMU/133 (read)Eth_PFE_LLD_PollerFunction_FAILSTOP/132 (read)Eth_PFE_LLD_PollerFunction_CLASS/134 (read)Eth_PFE_LLD_PollerFunction_CLASS/134 (read)Eth_PFE_LLD_PollerFunction_CLASS/134 (read)PlatformDrvPrepare_ShutdownConfigInit/84 (write)Eth_PFE_LLD_MainFunction/138 (read)Eth_43_PFE_LLD_WriteMii/139 (read)Eth_43_PFE_LLD_ReadMii/140 (read)Eth_43_PFE_LLD_WriteMii45/141 (read)Eth_43_PFE_LLD_ReadMii45/142 (read)Eth_43_PFE_LLD_SetGlobalTime/143 (read)Eth_43_PFE_LLD_GetCurrentTime/144 (read)Eth_PFE_LLD_ShutdownDriver.part.0/558 (read)Eth_43_PFE_LLD_SetCorrectionTime/146 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_PFE_LLD_ShutdownDriver.part.0/558 (write)Eth_PFE_LLD_GetPlatform/150 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetL2BridgeStats/155 (read)Eth_43_PFE_LLD_GetL2BridgeStats/155 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetGpiStats/153 (read)Eth_43_PFE_LLD_GetClassStats/151 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetBmuStats/152 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetWdtStats/154 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)Eth_43_PFE_LLD_GetTmuStats/158 (read)
  Availability: available
  Varpool flags: initialized
u16TxQueueRead/34 (u16TxQueueRead) @077e68b8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: ConfigureTxBuffers/49 (write)TxReqQueueDelete/59 (write)TxReqQueueDelete/59 (read)TxReqQueueDelete/59 (write)Eth_PFE_LLD_ReportTransmission/125 (read)
  Availability: available
  Varpool flags:
u16TxQueueWrite/33 (u16TxQueueWrite) @077e6828
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: ConfigureTxBuffers/49 (write)TxReqQueueWrite/57 (read)TxReqQueueWrite/57 (write)TxReqQueueWrite/57 (write)
  Availability: available
  Varpool flags:
arTxReqQueue/32 (arTxReqQueue) @077e6798
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: ConfigureTxBuffers/49 (write)TxReqQueueWrite/57 (write)TxReqQueueDelete/59 (write)ConfigureTxBuffers/49 (write)TxReqQueueWrite/57 (addr)Eth_PFE_LLD_ReportTransmission/125 (read)
  Availability: available
  Varpool flags:
aarTxBuf/31 (aarTxBuf) @077e6708
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: ReleaseAllCtrlTxBuffers/53 (write)Eth_PFE_LLD_GetTxBufMeta/79 (addr)Eth_PFE_LLD_Transmit/118 (write)Eth_PFE_LLD_ReportTransmission/125 (read)Eth_PFE_LLD_ReportTransmission/125 (write)ConfigureTxBuffers/49 (write)GetTxBuffer/51 (write)ConfigureTxBuffers/49 (write)TxReqTsQueueWrite/54 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (write)Eth_43_PFE_LLD_EnableEgressTimeStamp/147 (write)TxReqFailed/56 (write)TxReqTrigger/55 (read)Eth_PFE_LLD_Transmit/118 (read)Eth_PFE_LLD_ReportTransmission/125 (read)Eth_PFE_LLD_ProvideBufferDataArea/113 (read)Eth_PFE_LLD_ProvideBufferDataArea/113 (write)GetTxTimeStamp/64 (read)InitializeTxHeaders/50 (read)Eth_43_PFE_LLD_GetTxFifoIdx/115 (read)TxReqTrigger/55 (read)Eth_PFE_LLD_ReleaseTxBuffer/117 (read)Eth_PFE_LLD_ReleaseTxBuffer/117 (write)Eth_PFE_LLD_Transmit/118 (write)Eth_PFE_LLD_Transmit/118 (write)Eth_PFE_LLD_Transmit/118 (read)Eth_PFE_LLD_ReportTransmission/125 (read)Eth_PFE_LLD_ReportTransmission/125 (write)ConfigureTxBuffers/49 (write)GetTxBuffer/51 (read)InitializeTxHeaders/50 (read)TxReqFailed/56 (read)Eth_PFE_LLD_GetTxBufTsRef/80 (addr)GetTxTimeStamp/64 (read)GetTxTimeStamp/64 (read)Eth_PFE_LLD_Transmit/118 (read)Eth_PFE_LLD_Transmit/118 (read)Eth_PFE_LLD_Transmit/118 (write)Eth_PFE_LLD_ReportTransmissionTS/126 (addr)Eth_PFE_LLD_ReportTransmissionTS/126 (addr)Eth_PFE_LLD_ReportTransmissionTS/126 (read)Eth_PFE_LLD_ReportTransmissionTS/126 (write)Eth_43_PFE_LLD_GetTxTimeStamp/149 (read)Eth_43_PFE_LLD_GetTxTimeStamp/149 (read)
  Availability: available
  Varpool flags:
aarTxBufPool/30 (aarTxBufPool) @077e6678
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: GetTxBuffer/51 (write)ConfigureTxBuffers/49 (read)InitializeTxHeaders/50 (read)ConfigureTxBuffers/49 (write)ConfigureTxBuffers/49 (write)ConfigureTxBuffers/49 (write)ConfigureTxBuffers/49 (read)ConfigureTxBuffers/49 (write)ConfigureTxBuffers/49 (write)ConfigureTxBuffers/49 (write)ConfigureTxBuffers/49 (read)ConfigureTxBuffers/49 (read)GetTxBuffer/51 (read)GetTxBuffer/51 (read)GetTxBuffer/51 (read)GetTxBuffer/51 (read)GetTxBuffer/51 (read)GetTxBuffer/51 (write)Eth_43_PFE_LLD_GetTxBufferSize/116 (read)Eth_PFE_LLD_ProvideBufferDataArea/113 (read)
  Availability: available
  Varpool flags:
auTxBufMem/29 (auTxBufMem) @077e65e8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: ConfigureTxBuffers/49 (addr)
  Availability: available
  Varpool flags:
u32StatId/28 (u32StatId) @077e6558
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: DetectErrorsAndLostFrame.constprop.0/577 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Eth_PFE_LLD_bIrqInitStatus/27 (Eth_PFE_LLD_bIrqInitStatus) @077e6480
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: Eth_PFE_LLD_ShutdownDriver.part.0/558 (write)
  Availability: available
  Varpool flags: initialized
pfe_hif_chnl_from_phy_id/24 (pfe_hif_chnl_from_phy_id) @070b5460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_pkt_icmp_csum_valid/18 (pfe_hif_pkt_icmp_csum_valid) @0756ec40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: IsRxChecksumValidIpV6/120 (365072220 (estimated locally),0.34 per call) IsRxChecksumValidIpV4/119 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_hif_pkt_tcpv6_csum_valid/17 (pfe_hif_pkt_tcpv6_csum_valid) @0756e9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: IsRxChecksumValidIpV6/120 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_hif_pkt_tcpv4_csum_valid/16 (pfe_hif_pkt_tcpv4_csum_valid) @0756e700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: IsRxChecksumValidIpV4/119 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_hif_pkt_udpv6_csum_valid/15 (pfe_hif_pkt_udpv6_csum_valid) @0756e460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: IsRxChecksumValidIpV6/120 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_hif_pkt_udpv4_csum_valid/14 (pfe_hif_pkt_udpv4_csum_valid) @0756e1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: IsRxChecksumValidIpV4/119 (365072220 (estimated locally),0.34 per call) 
  Calls: 
SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/9 (SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @072e59d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/341 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/342 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/343 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/344 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/345 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/346 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/347 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/348 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/349 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/350 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/351 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/352 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/353 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/354 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/355 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/356 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/357 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/358 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/359 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/360 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/361 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/362 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/363 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/364 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/365 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/366 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/367 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/368 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/369 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/370 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/371 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/372 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/373 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/374 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/375 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/376 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/377 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/378 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/379 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/380 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/381 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/382 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/383 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/384 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/385 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/386 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/387 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/388 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/389 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/390 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/391 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/392 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/393 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/394 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/395 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/396 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/397 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/398 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/399 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/400 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/401 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/402 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/403 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/404 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/405 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/406 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/407 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/408 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/409 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/410 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/411 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/412 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/413 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/414 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/415 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/416 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/417 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/418 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/419 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/420 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/421 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/422 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/423 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/424 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/425 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/426 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/427 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/428 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/429 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/430 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/431 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/432 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/433 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/434 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/435 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/436 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/437 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/438 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/439 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/440 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/441 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/442 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/443 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/444 (addr)SchM_Exit_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/445 (addr)
  Referring: oal_mutex_unlock.part.0/536 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID/8 (SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_ID) @072e5900
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_00/236 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_01/237 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_02/238 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_03/239 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_04/240 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_05/241 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_06/242 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_07/243 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_08/244 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_09/245 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_10/246 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_11/247 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_12/248 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_13/249 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_14/250 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_15/251 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_16/252 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_17/253 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_18/254 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_19/255 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_20/256 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_21/257 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_22/258 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_23/259 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_24/260 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_25/261 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_26/262 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_27/263 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_28/264 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_29/265 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_30/266 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_31/267 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_32/268 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_33/269 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_34/270 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_35/271 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_36/272 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_37/273 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_38/274 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_39/275 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_40/276 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_41/277 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_42/278 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_43/279 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_44/280 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_45/281 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_46/282 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_47/283 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_48/284 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_49/285 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_50/286 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_51/287 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_52/288 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_53/289 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_54/290 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_55/291 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_56/292 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_57/293 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_58/294 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_59/295 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_60/296 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_61/297 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_62/298 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_63/299 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_64/300 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_65/301 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_66/302 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_67/303 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_68/304 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_69/305 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_70/306 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_71/307 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_72/308 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_73/309 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_74/310 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_75/311 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_76/312 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_77/313 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_78/314 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_79/315 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_80/316 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_81/317 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_82/318 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_83/319 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_84/320 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_85/321 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_86/322 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_87/323 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_88/324 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_89/325 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_90/326 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_91/327 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_92/328 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_93/329 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_94/330 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_95/331 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_96/332 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_97/333 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_98/334 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_99/335 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_100/336 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_101/337 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_102/338 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_103/339 (addr)SchM_Enter_Eth_43_PFE_ETH_EXCLUSIVE_AREA_104/340 (addr)
  Referring: oal_mutex_lock.part.0/535 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_emac_is_multi/7 (pfe_emac_is_multi) @0727ec40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (88583700 (estimated locally),0.08 per call) 
  Calls: pfe_emac_is_broad/6 (1073741824 (estimated locally),1.00 per call) 
pfe_emac_is_broad/6 (pfe_emac_is_broad) @0727e9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (354334802 (estimated locally),0.33 per call) pfe_emac_is_multi/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_emac_is_zero/5 (pfe_emac_is_zero) @0727e700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Eth_PFE_LLD_UpdatePhysAddrFilter/112 (177167401 (estimated locally),0.17 per call) 
  Calls: 
hal_ip_ready_set/1 (hal_ip_ready_set) @0709aee0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function Eth_PFE_LLD_GetEmacInstanceByControllerId (Eth_PFE_LLD_GetEmacInstanceByControllerId, funcdef_no=56, decl_uid=12313, cgraph_uid=57, symbol_order=76)

Modification phase of node Eth_PFE_LLD_GetEmacInstanceByControllerId/76
Eth_PFE_LLD_GetEmacInstanceByControllerId (uint8 u8CtrlIdx)
{
  pfe_ct_phy_if_id_t emac_id;
  struct pfe_emac_t * prEmac;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.120_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.122_5;
  int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.120_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_9(D);
  _3 = Eth_43_PFE_InternalCfgPtr.120_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [55.78%]
  else
    goto <bb 4>; [44.22%]

  <bb 3> [local count: 598933190]:
  # DEBUG BEGIN_STMT
  emac_id_10 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_10
  # DEBUG BEGIN_STMT
  ptrPlatform.122_5 = ptrPlatform;
  _6 = (int) emac_id_10;
  prEmac_11 = ptrPlatform.122_5->emac[_6];
  # DEBUG prEmac => prEmac_11

  <bb 4> [local count: 1073741824]:
  # prEmac_7 = PHI <0B(2), prEmac_11(3)>
  # DEBUG prEmac => prEmac_7
  # DEBUG BEGIN_STMT
  return prEmac_7;

}



;; Function CommonHifChnlISR (CommonHifChnlISR, funcdef_no=24, decl_uid=12243, cgraph_uid=25, symbol_order=44)

Modification phase of node CommonHifChnlISR/44
CommonHifChnlISR (void * arg)
{
  bool_t handled;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG chnl => arg_3(D)
  # DEBUG BEGIN_STMT
  # DEBUG handled => 0
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_irq_mask (arg_3(D));
  # DEBUG BEGIN_STMT
  _1 = pfe_hif_chnl_isr (arg_3(D));
  if (_1 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG handled => 1

  <bb 4> [local count: 1073741824]:
  # handled_2 = PHI <0(2), 1(3)>
  # DEBUG handled => handled_2
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_irq_unmask (arg_3(D));
  # DEBUG BEGIN_STMT
  return handled_2;

}



;; Function ConfigureSchedulerAndShaper_MapUnusedInputs (ConfigureSchedulerAndShaper_MapUnusedInputs, funcdef_no=49, decl_uid=12260, cgraph_uid=50, symbol_order=69)

Modification phase of node ConfigureSchedulerAndShaper_MapUnusedInputs/69
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0x1
Setting nonnull for 0
Setting value range of param 1 [0, 1]
ConfigureSchedulerAndShaper_MapUnusedInputs (struct ConfigureSchedulerAndShaper_StateType * pstate, uint8 u8SchIdx)
{
  uint8 u8SchInput;
  uint8 u8Fifo;
  errno_t ret;
  int _1;
  int _2;
  _Bool _3;
  int _5;
  _Bool _6;
  int _7;
  struct pfe_platform_t * ptrPlatform.61_8;
  struct pfe_tmu_t * _9;
  <unnamed type> _10;

  <bb 2> [local count: 59489074]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG u8Fifo => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG u8SchInput => 0
  goto <bb 12>; [100.00%]

  <bb 3> [local count: 425420489]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8SchIdx_25(D);
  _2 = (int) u8SchInput_19;
  _3 = pstate_26(D)->is_input_used[_1][_2];
  if (_3 != 0)
    goto <bb 11>; [73.00%]
  else
    goto <bb 14>; [27.00%]

  <bb 14> [local count: 114863532]:
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 958878291]:
  # DEBUG BEGIN_STMT
  u8Fifo_27 = u8Fifo_15 + 1;
  # DEBUG u8Fifo => u8Fifo_27

  <bb 5> [local count: 1073741824]:
  # u8Fifo_15 = PHI <u8Fifo_27(4), u8Fifo_18(14)>
  # DEBUG u8Fifo => u8Fifo_15
  # DEBUG BEGIN_STMT
  if (u8Fifo_15 <= 7)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686024]:
  _5 = (int) u8Fifo_15;
  _6 = pstate_26(D)->is_queue_used[_5];
  if (_6 != 0)
    goto <bb 4>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 114863532]:
  # u8Fifo_4 = PHI <u8Fifo_15(5), u8Fifo_15(6)>
  # DEBUG BEGIN_STMT
  if (u8Fifo_4 <= 7)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _7 = (int) u8Fifo_4;
  pstate_26(D)->is_queue_used[_7] = 1;

  <bb 9> [local count: 114863531]:
  # u8Fifo_16 = PHI <u8Fifo_4(8), 255(7)>
  # DEBUG u8Fifo => u8Fifo_16
  # DEBUG BEGIN_STMT
  ptrPlatform.61_8 = ptrPlatform;
  _9 = ptrPlatform.61_8->tmu;
  _10 = pstate_26(D)->emac_id;
  ret_30 = pfe_tmu_sch_bind_queue (_9, _10, u8SchIdx_25(D), u8SchInput_19, u8Fifo_16);
  # DEBUG ret => ret_30
  # DEBUG BEGIN_STMT
  if (ret_30 != 0)
    goto <bb 10>; [5.50%]
  else
    goto <bb 11>; [94.50%]

  <bb 10> [local count: 6317494]:
  # ret_11 = PHI <ret_30(9)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Failed to connect queue to scheduler input\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 1347, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 419102995]:
  # ret_12 = PHI <ret_13(3), ret_30(9)>
  # u8Fifo_17 = PHI <u8Fifo_18(3), u8Fifo_16(9)>
  # DEBUG u8Fifo => u8Fifo_17
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  u8SchInput_33 = u8SchInput_19 + 1;
  # DEBUG u8SchInput => u8SchInput_33

  <bb 12> [local count: 478592068]:
  # ret_13 = PHI <0(2), ret_12(11)>
  # u8Fifo_18 = PHI <0(2), u8Fifo_17(11)>
  # u8SchInput_19 = PHI <0(2), u8SchInput_33(11)>
  # DEBUG u8SchInput => u8SchInput_19
  # DEBUG u8Fifo => u8Fifo_18
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  if (u8SchInput_19 != 8)
    goto <bb 3>; [88.89%]
  else
    goto <bb 13>; [11.11%]

  <bb 13> [local count: 59489073]:
  # ret_14 = PHI <ret_11(10), ret_13(12)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  return ret_14;

}



;; Function InitializeTxHeaders (InitializeTxHeaders, funcdef_no=30, decl_uid=12204, cgraph_uid=31, symbol_order=50)

Modification phase of node InitializeTxHeaders/50
InitializeTxHeaders (const uint8 u8CtrlIdx, struct pfe_hif_drv_client_t * client)
{
  struct pfe_ct_hif_tx_hdr_t * pTxHeader;
  uint16 u16IndexOffset;
  uint8 u8Queue;
  uint8 u8NumFifo;
  uint16 u16Buff;
  uint8 u8Fifo;
  boolean bFail;
  errno_t ret;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.73_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  int _5;
  int _6;
  int _8;
  int _9;
  unsigned int _10;
  long unsigned int _11;
  short unsigned int _12;
  short unsigned int _29;

  <bb 2> [local count: 59046942]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG bFail => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG u16IndexOffset => 0
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.73_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_27(D);
  _3 = Eth_43_PFE_InternalCfgPtr.73_1->pController[_2];
  u8NumFifo_28 = _3->EthCtrlEgressFifoCnt;
  # DEBUG u8NumFifo => u8NumFifo_28
  # DEBUG BEGIN_STMT
  # DEBUG u8Fifo => 0
  goto <bb 9>; [100.00%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  _5 = (int) u8Fifo_21;
  # DEBUG D#15 => &aarTxBufPool[_2][_5]
  # DEBUG prPool => D#15
  # DEBUG BEGIN_STMT
  _6 = (int) u16IndexOffset_23;
  # DEBUG BEGIN_STMT
  # DEBUG u16Buff => 0
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _8 = (int) u16Buff_22;
  _9 = _6 + _8;
  _10 = aarTxBuf[_2][_9].BufAddr;
  pTxHeader_32 = (struct pfe_ct_hif_tx_hdr_t *) _10;
  # DEBUG pTxHeader => pTxHeader_32
  # DEBUG BEGIN_STMT
  u8Queue_33 = aarTxBuf[_2][_9].u8Fifo;
  # DEBUG u8Queue => u8Queue_33
  # DEBUG BEGIN_STMT
  _11 = (long unsigned int) u8Queue_33;
  ret_36 = pfe_hif_drv_init_tx_header (client_34(D), pTxHeader_32, _11);
  # DEBUG ret => ret_36
  # DEBUG BEGIN_STMT
  if (ret_36 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 477815111]:
  # DEBUG BEGIN_STMT
  # DEBUG bFail => 1

  <bb 6> [local count: 955630223]:
  # bFail_18 = PHI <bFail_19(4), 1(5)>
  # DEBUG bFail => bFail_18
  # DEBUG BEGIN_STMT
  u16Buff_37 = u16Buff_22 + 1;
  # DEBUG u16Buff => u16Buff_37

  <bb 7> [local count: 1073741824]:
  # ret_15 = PHI <ret_16(3), ret_36(6)>
  # bFail_19 = PHI <bFail_20(3), bFail_18(6)>
  # u16Buff_22 = PHI <0(3), u16Buff_37(6)>
  # DEBUG u16Buff => u16Buff_22
  # DEBUG bFail => bFail_19
  # DEBUG ret => ret_15
  # DEBUG BEGIN_STMT
  _12 = MEM[(struct trTxBufPool *)&aarTxBufPool][_2][_5].u16BufNumber;
  if (_12 > u16Buff_22)
    goto <bb 4>; [89.00%]
  else
    goto <bb 8>; [11.00%]

  <bb 8> [local count: 118111601]:
  # _29 = PHI <_12(7)>
  # ret_4 = PHI <ret_15(7)>
  # bFail_14 = PHI <bFail_19(7)>
  # DEBUG BEGIN_STMT
  u16IndexOffset_30 = u16IndexOffset_23 + _29;
  # DEBUG u16IndexOffset => u16IndexOffset_30
  # DEBUG BEGIN_STMT
  u8Fifo_31 = u8Fifo_21 + 1;
  # DEBUG u8Fifo => u8Fifo_31

  <bb 9> [local count: 177158543]:
  # ret_16 = PHI <0(2), ret_4(8)>
  # bFail_20 = PHI <0(2), bFail_14(8)>
  # u8Fifo_21 = PHI <0(2), u8Fifo_31(8)>
  # u16IndexOffset_23 = PHI <0(2), u16IndexOffset_30(8)>
  # DEBUG u16IndexOffset => u16IndexOffset_23
  # DEBUG u8Fifo => u8Fifo_21
  # DEBUG bFail => bFail_20
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  if (u8Fifo_21 < u8NumFifo_28)
    goto <bb 3>; [66.67%]
  else
    goto <bb 10>; [33.33%]

  <bb 10> [local count: 59046942]:
  # ret_13 = PHI <ret_16(9)>
  # bFail_7 = PHI <bFail_20(9)>
  # DEBUG BEGIN_STMT
  if (bFail_7 != 0)
    goto <bb 11>; [35.00%]
  else
    goto <bb 12>; [65.00%]

  <bb 11> [local count: 20666430]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2

  <bb 12> [local count: 59046942]:
  # ret_17 = PHI <ret_13(10), 2(11)>
  # DEBUG ret => ret_17
  # DEBUG BEGIN_STMT
  return ret_17;

}



;; Function oal_mutex_lock.part.0 (oal_mutex_lock.part.0, funcdef_no=145, decl_uid=14292, cgraph_uid=508, symbol_order=535)

Modification phase of node oal_mutex_lock.part.0/535
Adjusting mask for param 0 to 0x7
Setting value range of param 0 [17, 21]
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



;; Function oal_mutex_unlock.part.0 (oal_mutex_unlock.part.0, funcdef_no=146, decl_uid=14297, cgraph_uid=509, symbol_order=536)

Modification phase of node oal_mutex_unlock.part.0/536
Adjusting mask for param 0 to 0x7
Setting value range of param 0 [17, 21]
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



;; Function ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0 (ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0, funcdef_no=151, decl_uid=14383, cgraph_uid=519, symbol_order=546)

Modification phase of node ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0/546
ConfigureSchedulerAndShaper_SetFifo.isra.0.part.0 ()
{
  errno_t ret;
  const struct Eth_43_PFE_SchedulerInputInfoCfgType * pSchInput;
  struct ConfigureSchedulerAndShaper_StateType * pstate;
  uint8 u8SchIdx;
  const uint8 ISRA.350;
  uint8 u8FifoIdx;

  <bb 4> [local count: 1073741824]:
  # DEBUG D#13 s=> pstate
  # DEBUG pstate => D#13
  # DEBUG D#12 s=> u8SchIdx
  # DEBUG u8SchIdx => D#12
  # DEBUG D#11 s=> ISRA.350
  # DEBUG ISRA.350 => D#11
  # DEBUG D#10 s=> u8FifoIdx
  # DEBUG u8FifoIdx => D#10

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Failed to connect queue to scheduler input\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 1168, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT

  <bb 3> [local count: 1073741824]:
  return;

}



;; Function EnableController_Common.part.0 (EnableController_Common.part.0, funcdef_no=153, decl_uid=14410, cgraph_uid=521, symbol_order=548)

Modification phase of node EnableController_Common.part.0/548
EnableController_Common.part.0 ()
{
  boolean bResult;
  const struct trPfeDev * prPfeDev;

  <bb 4> [local count: 1073741824]:
  # DEBUG D#17 s=> prPfeDev
  # DEBUG prPfeDev => D#17

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Initialize TX headers failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2646, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG bResult => 0

  <bb 3> [local count: 1073741824]:
  # bResult_1 = PHI <0(2)>
  # DEBUG bResult => bResult_1
  # DEBUG BEGIN_STMT
  return bResult_1;

}



;; Function EnableController_HifEmac (EnableController_HifEmac, funcdef_no=81, decl_uid=12295, cgraph_uid=82, symbol_order=101)

Modification phase of node EnableController_HifEmac/101
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 2 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
Setting nonnull for 2
EnableController_HifEmac (struct trPfeDev * prPfeDev, struct pfe_hif_drv_client_rx_tx_count * pclient_queue, struct pfe_hif_drv_client_fifo_queue * pclient_fifo_queue)
{
  boolean bResult;
  struct pfe_hif_drv_t * _1;
  struct pfe_phy_if_t * _2;
  <unnamed type> _3;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.76_4;
  unsigned char _5;
  int _6;
  const struct Eth_43_PFE_CtrlCfgType * _7;
  _Bool _8;
  unsigned char _9;
  struct pfe_hif_drv_client_t * _10;
  struct pfe_phy_if_t * _11;
  <unnamed type> _12;
  int _13;
  _Bool _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG bResult => 0
  # DEBUG BEGIN_STMT
  _1 = prPfeDev_18(D)->prHifDrv;
  _2 = prPfeDev_18(D)->prPhyIf;
  _3 = pfe_phy_if_get_id (_2);
  Eth_43_PFE_InternalCfgPtr.76_4 = Eth_43_PFE_InternalCfgPtr;
  _5 = prPfeDev_18(D)->u8CtrlIdx;
  _6 = (int) _5;
  _7 = Eth_43_PFE_InternalCfgPtr.76_4->pController[_6];
  _8 = _7->EthCtrlAcceptAllTraffic;
  _9 = (unsigned char) _8;
  _10 = pfe_hif_drv_client_register (_1, _3, pclient_queue_19(D), pclient_fifo_queue_20(D), _9, ClientEventHdlr, prPfeDev_18(D));
  prPfeDev_18(D)->prClient = _10;
  # DEBUG BEGIN_STMT
  if (_10 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _11 = prPfeDev_18(D)->prPhyIf;
  _12 = pfe_phy_if_get_id (_11);
  _13 = pfe_hif_drv_client_set_inject_if (_10, _12);
  if (_13 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 287064877]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t set inject interface\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2700, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 287064877]:
  # DEBUG BEGIN_STMT
  _14 = EnableController_Common (prPfeDev_18(D));
  if (_14 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 143532438]:
  # DEBUG BEGIN_STMT
  # DEBUG bResult => 1

  <bb 7> [local count: 1073741824]:
  # bResult_15 = PHI <0(2), 0(4), 0(5), 1(6)>
  # DEBUG bResult => bResult_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  prPfeDev_18(D)->bStarted = bResult_15;
  # DEBUG BEGIN_STMT
  return bResult_15;

}



;; Function CheckDemStatus.part.0.constprop (CheckDemStatus.part.0.constprop.0, funcdef_no=165, decl_uid=14644, cgraph_uid=548, symbol_order=576)

Modification phase of node CheckDemStatus.part.0.constprop/576
Adjusting mask for param 1 to 0x7
Setting value range of param 1 [0, 7]
CheckDemStatus.part.0.constprop (ErrorIdType errorId, uint32 demId)
{
  uint32 demConfig;
  uint8 u8CtrlIdx;
  _Bool _2;
  short unsigned int _4;
  short unsigned int _5;

  <bb 7> [local count: 1073741824]:
  # DEBUG u8CtrlIdx => 0

  <bb 2> [local count: 1073741824]:
  # DEBUG D#25 s=> demConfig
  # DEBUG demConfig => D#25

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = DetectErrorsAndLostFrame (0, errorId_1(D));
  if (_2 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _4 = (short unsigned int) demId_3(D);
  Dem_SetEventStatus (_4, 3);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _5 = (short unsigned int) demId_3(D);
  Dem_SetEventStatus (_5, 2);

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function Eth_PFE_LLD_GetTxBufMeta (Eth_PFE_LLD_GetTxBufMeta, funcdef_no=59, decl_uid=11401, cgraph_uid=60, symbol_order=79)

Modification phase of node Eth_PFE_LLD_GetTxBufMeta/79
Eth_PFE_LLD_GetTxBufMeta (const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
  int _1;
  struct trTxMeta * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_2(D);
  _4 = &aarTxBuf[_1][BufIdx_3(D)].rMeta;
  return _4;

}



;; Function Eth_PFE_LLD_GetTxBufTsRef (Eth_PFE_LLD_GetTxBufTsRef, funcdef_no=60, decl_uid=11256, cgraph_uid=61, symbol_order=80)

Modification phase of node Eth_PFE_LLD_GetTxBufTsRef/80
Eth_PFE_LLD_GetTxBufTsRef (const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
  int _1;
  struct Eth_PFE_LLD_trTxTsRef * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_2(D);
  _4 = &aarTxBuf[_1][BufIdx_3(D)].rTsRef;
  return _4;

}



;; Function Eth_PFE_LLD_InitInterfaces (Eth_PFE_LLD_InitInterfaces, funcdef_no=61, decl_uid=11268, cgraph_uid=62, symbol_order=81)

Modification phase of node Eth_PFE_LLD_InitInterfaces/81
Eth_PFE_LLD_InitInterfaces (const struct Eth_43_PFE_ConfigType * cfgPtr)
{
  uint8_t u8EmacIdx;
  const pfe_ct_phy_if_id_t PhyIf;
  uint8 u8MiiMode;
  uint8 u8CtrlCount;
  const struct Eth_43_PFE_CtrlCfgType * _2;
  unsigned char _3;
  <unnamed type> _5;
  long unsigned int _6;
  long unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  unsigned char _16;
  unsigned int _19;

  <bb 2> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG u8MiiMode => 0
  # DEBUG BEGIN_STMT
  MEM[(uint32 *)1074252292B] = 0;
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlCount => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _2 = cfgPtr_20(D)->pController[0];
  PhyIf_21 = _2->EthCtrlPhyIfID;
  # DEBUG PhyIf => PhyIf_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = PhyIf_21;
  if (_3 <= 2)
    goto <bb 4>; [67.00%]
  else
    goto <bb 11>; [33.00%]

  <bb 11> [local count: 334846388]:
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 679839637]:
<L27>:
  u8EmacIdx_24 = PhyIf_21;
  # DEBUG u8EmacIdx => NULL
  # DEBUG BEGIN_STMT
  _5 = _2->EthCtrlMiiType;
  _19 = _5 + 4294967295;
  if (_19 <= 3)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 339919818]:
<L29>:
  u8MiiMode_4 = 0;
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 339919818]:
<L30>:
  _16 = CSWTCH.392[_19];
  u8MiiMode_22 = _16;

  <bb 7> [local count: 679839637]:
  # u8MiiMode_13 = PHI <u8MiiMode_22(6), u8MiiMode_4(5)>
<L31>:
<L17>:
  # DEBUG u8MiiMode => u8MiiMode_13
  # DEBUG BEGIN_STMT
  _6 = MEM[(uint32 *)1074252292B];
  _7 = (long unsigned int) u8MiiMode_13;
  _8 = (unsigned int) u8EmacIdx_24;
  _9 = _8 * 4;
  _10 = _7 << _9;
  _11 = _6 | _10;
  MEM[(uint32 *)1074252292B] = _11;

  <bb 8> [local count: 738895437]:
  # u8CtrlCount_14 = PHI <0(2), 1(7)>
<L24>:

  <bb 9> [local count: 1073741824]:
  # u8CtrlCount_12 = PHI <u8CtrlCount_14(8), 1(11)>
<L25>:
  # DEBUG u8EmacIdx => NULL
  # DEBUG u8CtrlCount => u8CtrlCount_12
  # DEBUG BEGIN_STMT
  if (u8CtrlCount_12 == 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 10> [local count: 59055800]:
  return;

}



;; Function Eth_PFE_LLD_InitEMACs (Eth_PFE_LLD_InitEMACs, funcdef_no=62, decl_uid=11270, cgraph_uid=63, symbol_order=82)

Modification phase of node Eth_PFE_LLD_InitEMACs/82
Eth_PFE_LLD_InitEMACs (const struct Eth_43_PFE_ConfigType * cfgPtr)
{
  uint8 u8EmacIdx;
  const struct Eth_43_PFE_EmacCfg * _1;
  unsigned int _2;
  unsigned int _3;
  const struct Eth_43_PFE_EmacCfg * _4;
  <unnamed type> _5;
  long unsigned int _6;
  unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;

  <bb 2> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG u8EmacIdx => 0
  # DEBUG BEGIN_STMT
  # DEBUG u8MiiMode => 0
  # DEBUG BEGIN_STMT
  # DEBUG u8EmacIdx => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  _1 = cfgPtr_22(D)->emac;
  _2 = (unsigned int) u8EmacIdx_18;
  _3 = _2 * 20;
  _4 = _1 + _3;
  _5 = _4->EthCtrlMiiType;
  switch (_5) <default: <L9> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%], case 3: <L4> [25.00%]>

  <bb 4> [local count: 201326592]:
<L1>:
  # DEBUG BEGIN_STMT
  # DEBUG u8MiiMode => 1
  # DEBUG BEGIN_STMT
  _6 = MEM[(uint32 *)1074252292B];
  _7 = _2 * 4;
  _8 = 1 << _7;
  _9 = _6 | _8;
  MEM[(uint32 *)1074252292B] = _9;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 201326592]:
<L2>:
  # DEBUG BEGIN_STMT
  # DEBUG u8MiiMode => 9
  # DEBUG BEGIN_STMT
  _10 = MEM[(uint32 *)1074252292B];
  _11 = _2 * 4;
  _12 = 9 << _11;
  _13 = _10 | _12;
  MEM[(uint32 *)1074252292B] = _13;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 201326592]:
<L4>:
  # DEBUG BEGIN_STMT
  # DEBUG u8MiiMode => 2
  # DEBUG BEGIN_STMT
  _14 = MEM[(uint32 *)1074252292B];
  _15 = _2 * 4;
  _16 = 2 << _15;
  _17 = _14 | _16;
  MEM[(uint32 *)1074252292B] = _17;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 805306369]:
<L9>:
  # DEBUG u8MiiMode => NULL
  # DEBUG BEGIN_STMT
  u8EmacIdx_26 = u8EmacIdx_18 + 1;
  # DEBUG u8EmacIdx => u8EmacIdx_26

  <bb 8> [local count: 1073741824]:
  # u8EmacIdx_18 = PHI <0(2), u8EmacIdx_26(7)>
  # DEBUG u8EmacIdx => u8EmacIdx_18
  # DEBUG BEGIN_STMT
  if (u8EmacIdx_18 != 3)
    goto <bb 3>; [75.00%]
  else
    goto <bb 9>; [25.00%]

  <bb 9> [local count: 268435456]:
  return;

}



;; Function Eth_PFE_LLD_InterfacePrepare (Eth_PFE_LLD_InterfacePrepare, funcdef_no=71, decl_uid=11313, cgraph_uid=72, symbol_order=91)

Modification phase of node Eth_PFE_LLD_InterfacePrepare/91
Eth_PFE_LLD_InterfacePrepare (uint8 u8CtrlIdx)
{
  pfe_ct_phy_if_id_t temp_phy_id;
  struct trPfeDev * prPfeDev;
  struct pfe_platform_t * ptrPlatform.27_1;
  struct pfe_hif_drv_t * prCommonHifDrv.28_2;
  int _3;
  uint8_t[6] * _4;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.29_5;
  const struct Eth_43_PFE_CtrlCfgType * _6;
  const uint8[6] * _7;
  struct pfe_platform_t * ptrPlatform.30_8;
  struct pfe_hif_chnl_t * prCommonHifChnl.31_9;
  struct oal_irq_t * prCommonChnlIRQ.32_10;
  struct pfe_hif_drv_t * prCommonHifDrv.33_11;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.34_12;
  const struct Eth_43_PFE_CtrlCfgType * _13;
  <unnamed type> _14;
  struct pfe_phy_if_t * _15;
  unsigned int _16;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.37_17;
  const struct Eth_43_PFE_CtrlCfgType * _18;
  <unnamed type> _19;
  int _20;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ptrPlatform.27_1 = ptrPlatform;
  if (ptrPlatform.27_1 == 0B)
    goto <bb 3>; [17.43%]
  else
    goto <bb 4>; [82.57%]

  <bb 3> [local count: 187153200]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Platform driver not prepared\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2325, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 4> [local count: 886588625]:
  # DEBUG BEGIN_STMT
  prCommonHifDrv.28_2 = prCommonHifDrv;
  if (prCommonHifDrv.28_2 == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 5> [local count: 265976587]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Common HIF driver not prepared\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2329, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 6> [local count: 620612038]:
  # DEBUG BEGIN_STMT
  _3 = (int) u8CtrlIdx_23(D);
  prPfeDev_24 = &arPfeInterface[_3];
  # DEBUG prPfeDev => prPfeDev_24
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].bInterfacePrepared = 0;
  # DEBUG BEGIN_STMT
  _4 = &MEM[(struct trPfeDev *)&arPfeInterface][_3].au8MacAddr;
  Eth_43_PFE_InternalCfgPtr.29_5 = Eth_43_PFE_InternalCfgPtr;
  _6 = Eth_43_PFE_InternalCfgPtr.29_5->pController[_3];
  _7 = &_6->EthMACAddress;
  autolibc_memcpy (_4, _7, 6);
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].u8CtrlIdx = u8CtrlIdx_23(D);
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].bStarted = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].prClient = 0B;
  # DEBUG BEGIN_STMT
  InterfacePrepare_InitTSQueue (prPfeDev_24);
  # DEBUG BEGIN_STMT
  ptrPlatform.30_8 = ptrPlatform;
  MEM[(struct trPfeDev *)&arPfeInterface][_3].prPlatform = ptrPlatform.30_8;
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].HifId = 6;
  # DEBUG BEGIN_STMT
  prCommonHifChnl.31_9 = prCommonHifChnl;
  MEM[(struct trPfeDev *)&arPfeInterface][_3].prHifChnl = prCommonHifChnl.31_9;
  # DEBUG BEGIN_STMT
  prCommonChnlIRQ.32_10 = prCommonChnlIRQ;
  MEM[(struct trPfeDev *)&arPfeInterface][_3].prHifChnlIRQ = prCommonChnlIRQ.32_10;
  # DEBUG BEGIN_STMT
  prCommonHifDrv.33_11 = prCommonHifDrv;
  MEM[(struct trPfeDev *)&arPfeInterface][_3].prHifDrv = prCommonHifDrv.33_11;
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.34_12 = Eth_43_PFE_InternalCfgPtr;
  _13 = Eth_43_PFE_InternalCfgPtr.34_12->pController[_3];
  _14 = _13->EthCtrlType;
  if (_14 == 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 7> [local count: 415810065]:
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].prPhyIf = 0B;
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].bInterfacePrepared = 1;
  goto <bb 14>; [100.00%]

  <bb 8> [local count: 204801972]:
  # DEBUG BEGIN_STMT
  temp_phy_id_36 = _13->EthCtrlPhyIfID;
  # DEBUG temp_phy_id => temp_phy_id_36
  # DEBUG BEGIN_STMT
  _15 = pfe_platform_get_phy_if_by_id (ptrPlatform.30_8, temp_phy_id_36);
  MEM[(struct trPfeDev *)&arPfeInterface][_3].prPhyIf = _15;
  # DEBUG BEGIN_STMT
  if (_15 == 0B)
    goto <bb 9>; [17.43%]
  else
    goto <bb 10>; [82.57%]

  <bb 9> [local count: 35696984]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = (unsigned int) temp_phy_id_36;
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get EMAC/HIF %u\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2365, _16, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 10> [local count: 169104989]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.37_17 = Eth_43_PFE_InternalCfgPtr;
  _18 = Eth_43_PFE_InternalCfgPtr.37_17->pController[_3];
  _19 = _18->EthCtrlType;
  if (_19 == 1)
    goto <bb 11>; [51.12%]
  else
    goto <bb 12>; [48.88%]

  <bb 11> [local count: 86446470]:
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].bInterfacePrepared = 1;
  goto <bb 14>; [100.00%]

  <bb 12> [local count: 82658518]:
  # DEBUG BEGIN_STMT
  _20 = InterfacePrepare_MasterConfigEMAC (prPfeDev_24);
  if (_20 == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 41329259]:
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_3].bInterfacePrepared = 1;

  <bb 14> [local count: 1073741824]:
  return;

}



;; Function Eth_PFE_LLD_EMACPrepare (Eth_PFE_LLD_EMACPrepare, funcdef_no=73, decl_uid=11315, cgraph_uid=74, symbol_order=93)

Modification phase of node Eth_PFE_LLD_EMACPrepare/93
Eth_PFE_LLD_EMACPrepare ()
{
  const pfe_ct_phy_if_id_t emac_ids[3];
  const struct pfe_phy_if_t * prEmac;
  uint8 u8EmacIdx;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.63_1;
  const struct Eth_43_PFE_EmacCfg * _2;
  unsigned int _3;
  unsigned int _4;
  const struct Eth_43_PFE_EmacCfg * _5;
  <unnamed type> _6;
  struct pfe_platform_t * ptrPlatform.64_7;
  int _8;
  <unnamed type> _9;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.65_10;
  const struct Eth_43_PFE_EmacCfg * _11;
  const struct Eth_43_PFE_EmacCfg * _12;
  int _13;

  <bb 2> [local count: 278666874]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(pfe_ct_phy_if_id_t[3] *)&emac_ids] = 0;
  MEM[(pfe_ct_phy_if_id_t[3] *)&emac_ids + 1B] = 1;
  MEM[(pfe_ct_phy_if_id_t[3] *)&emac_ids + 2B] = 2;
  # DEBUG BEGIN_STMT
  # DEBUG u8EmacIdx => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 805306368]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.63_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = Eth_43_PFE_InternalCfgPtr.63_1->emac;
  _3 = (unsigned int) u8EmacIdx_14;
  _4 = _3 * 20;
  _5 = _2 + _4;
  _6 = _5->EthCtrlSpeed;
  if (_6 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 4> [local count: 265751101]:
  # DEBUG BEGIN_STMT
  ptrPlatform.64_7 = ptrPlatform;
  _8 = (int) u8EmacIdx_14;
  _9 = emac_ids[_8];
  prEmac_20 = pfe_platform_get_phy_if_by_id (ptrPlatform.64_7, _9);
  # DEBUG prEmac => prEmac_20
  # DEBUG BEGIN_STMT
  if (prEmac_20 == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 5> [local count: 79725330]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get EMAC %u\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2437, _3, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 186025771]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.65_10 = Eth_43_PFE_InternalCfgPtr;
  _11 = Eth_43_PFE_InternalCfgPtr.65_10->emac;
  _12 = _11 + _4;
  _13 = Eth_PFE_LLD_EMACPrepare_Config (prEmac_20, _12);
  if (_13 == 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 7> [local count: 795074950]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u8EmacIdx_24 = u8EmacIdx_14 + 1;
  # DEBUG u8EmacIdx => u8EmacIdx_24

  <bb 8> [local count: 1073741824]:
  # u8EmacIdx_14 = PHI <0(2), u8EmacIdx_24(7)>
  # DEBUG u8EmacIdx => u8EmacIdx_14
  # DEBUG BEGIN_STMT
  if (u8EmacIdx_14 != 3)
    goto <bb 3>; [75.00%]
  else
    goto <bb 9>; [25.00%]

  <bb 9> [local count: 278666874]:
  emac_ids ={v} {CLOBBER};
  return;

}



;; Function Eth_PFE_LLD_ConfigureController (Eth_PFE_LLD_ConfigureController, funcdef_no=74, decl_uid=11262, cgraph_uid=75, symbol_order=94)

Modification phase of node Eth_PFE_LLD_ConfigureController/94
Eth_PFE_LLD_ConfigureController (const uint8 u8CtrlIdx)
{
  uint32 u32Count;
  Std_ReturnType Status;
  int _1;
  _Bool _2;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.67_3;
  const struct Eth_43_PFE_CtrlCfgType * _4;
  <unnamed type> _5;

  <bb 2> [local count: 350860930]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_10(D);
  _2 = arPfeInterface[_1].bInterfacePrepared;
  if (_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 175430465]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0

  <bb 4> [local count: 350860930]:
  # Status_6 = PHI <1(2), 0(3)>
  # DEBUG Status => Status_6
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.67_3 = Eth_43_PFE_InternalCfgPtr;
  _4 = Eth_43_PFE_InternalCfgPtr.67_3->pController[_1];
  _5 = _4->EthCtrlType;
  if (_5 == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 8> [local count: 119292716]:
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 954449109]:
  # DEBUG BEGIN_STMT
  u32DemErrorCounters[_1][u32Count_7] = 0;
  # DEBUG BEGIN_STMT
  u32Count_13 = u32Count_7 + 1;
  # DEBUG u32Count => u32Count_13

  <bb 6> [local count: 1073741824]:
  # u32Count_7 = PHI <u32Count_13(5), 0(8)>
  # DEBUG u32Count => u32Count_7
  # DEBUG BEGIN_STMT
  if (u32Count_7 != 8)
    goto <bb 5>; [88.89%]
  else
    goto <bb 7>; [11.11%]

  <bb 7> [local count: 350860930]:
  # DEBUG BEGIN_STMT
  return Status_6;

}



;; Function Eth_PFE_LLD_Check_Driver_Init (Eth_PFE_LLD_Check_Driver_Init, funcdef_no=75, decl_uid=11242, cgraph_uid=76, symbol_order=95)

Modification phase of node Eth_PFE_LLD_Check_Driver_Init/95
Eth_PFE_LLD_Check_Driver_Init ()
{
  boolean bDrvInitialized;
  uint8 u8CtrlIdx;
  <unnamed type> _1;

  <bb 2> [local count: 566398813]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG bDrvInitialized => 0
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 ={v} Eth_43_PFE_CtrlState[0];
  if (_1 == 1)
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 507343012]:

  <bb 4> [local count: 1073741824]:
  # u8CtrlIdx_2 = PHI <0(2), 1(6)>
  # DEBUG u8CtrlIdx => u8CtrlIdx_2
  # DEBUG BEGIN_STMT
  if (u8CtrlIdx_2 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 566398813]:
  # bDrvInitialized_3 = PHI <1(3), 0(4)>
  # DEBUG bDrvInitialized => bDrvInitialized_3
  # DEBUG BEGIN_STMT
  return bDrvInitialized_3;

}



;; Function Eth_PFE_LLD_CheckAccessToController (Eth_PFE_LLD_CheckAccessToController, funcdef_no=76, decl_uid=11244, cgraph_uid=77, symbol_order=96)

Modification phase of node Eth_PFE_LLD_CheckAccessToController/96
Eth_PFE_LLD_CheckAccessToController ()
{
  long unsigned int _1;
  long unsigned int _2;
  _Bool _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG partitionStat => 0
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(volatile uint32_t *)1074300168B];
  _2 = _1 & 1;
  _3 = (_Bool) _2;
  # DEBUG partitionStat => _3
  # DEBUG BEGIN_STMT
  return _3;

}



;; Function Eth_PFE_LLD_CheckInitializationStatus (Eth_PFE_LLD_CheckInitializationStatus, funcdef_no=77, decl_uid=11264, cgraph_uid=78, symbol_order=97)

Modification phase of node Eth_PFE_LLD_CheckInitializationStatus/97
Eth_PFE_LLD_CheckInitializationStatus (const uint8 u8CtrlIdx)
{
  boolean bControllerAvailable;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.69_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  _Bool _5;
  struct pfe_phy_if_t * _6;
  _Bool _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG bControllerAvailable => 0
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.69_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_11(D);
  _3 = Eth_43_PFE_InternalCfgPtr.69_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 <= 1)
    goto <bb 3>; [41.00%]
  else
    goto <bb 5>; [59.00%]

  <bb 3> [local count: 440234148]:
  # DEBUG BEGIN_STMT
  _5 = arPfeInterface[_2].bInterfacePrepared;
  if (_5 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 4> [local count: 220117074]:
  # DEBUG BEGIN_STMT
  # DEBUG bControllerAvailable => 1
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 633507677]:
  # DEBUG BEGIN_STMT
  _6 = arPfeInterface[_2].prPhyIf;
  if (_6 == 0B)
    goto <bb 6>; [17.43%]
  else
    goto <bb 7>; [82.57%]

  <bb 6> [local count: 110420388]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Physical interface not created, u8CtrlIdx=%hhu\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2566, _2, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 523087288]:
  # DEBUG BEGIN_STMT
  _7 = arPfeInterface[_2].bInterfacePrepared;
  if (_7 != 0)
    goto <bb 9>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 8> [local count: 172618805]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Function Eth_PFE_LLD_InterfacePrepare failed, u8CtrlIdx=%hhu\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2570, _2, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  # bControllerAvailable_8 = PHI <1(4), 0(6), 0(8), 1(7), 0(3)>
  # DEBUG bControllerAvailable => bControllerAvailable_8
  # DEBUG BEGIN_STMT
  return bControllerAvailable_8;

}



;; Function Eth_PFE_LLD_EnableController (Eth_PFE_LLD_EnableController, funcdef_no=82, decl_uid=11260, cgraph_uid=83, symbol_order=102)

Modification phase of node Eth_PFE_LLD_EnableController/102
Eth_PFE_LLD_EnableController (const uint8 u8CtrlIdx)
{
  struct pfe_hif_drv_client_fifo_queue client_fifo_queue;
  struct pfe_hif_drv_client_rx_tx_count client_queue;
  const struct Eth_43_PFE_CtrlCfgType * pCtrlCfg;
  struct trPfeDev * prPfeDev;
  boolean bResult;
  int _1;
  _Bool _2;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.70_3;
  unsigned char _4;
  long unsigned int _5;
  const struct Eth_43_PFE_EgressTxCfgType * _6;
  volatile struct fifo_t * _7;
  const struct Eth_43_PFE_IngressCfgType * _8;
  volatile struct fifo_t * _9;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.71_10;
  const struct Eth_43_PFE_CtrlCfgType * _11;
  <unnamed type> _12;
  _Bool _13;
  struct pfe_phy_if_t * _14;
  int _15;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_20(D);
  prPfeDev_21 = &arPfeInterface[_1];
  # DEBUG prPfeDev => prPfeDev_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  bResult_23 = MEM[(struct trPfeDev *)&arPfeInterface][_1].bInterfacePrepared;
  # DEBUG bResult => bResult_23
  # DEBUG BEGIN_STMT
  if (bResult_23 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 3> [local count: 536870911]:
  _2 = MEM[(struct trPfeDev *)&arPfeInterface][_1].bStarted;
  if (_2 != 0)
    goto <bb 12>; [67.00%]
  else
    goto <bb 4>; [33.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.70_3 = Eth_43_PFE_InternalCfgPtr;
  pCtrlCfg_24 = Eth_43_PFE_InternalCfgPtr.70_3->pController[_1];
  # DEBUG pCtrlCfg => pCtrlCfg_24
  # DEBUG BEGIN_STMT
  bResult_26 = EnableController_InitFifos (pCtrlCfg_24);
  # DEBUG bResult => bResult_26
  # DEBUG BEGIN_STMT
  if (bResult_26 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 5> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _4 = pCtrlCfg_24->EthCtrlEgressFifoCnt;
  _5 = (long unsigned int) _4;
  client_queue.txq_num = _5;
  client_queue.rxq_num = 1;
  # DEBUG BEGIN_STMT
  _6 = pCtrlCfg_24->pEgressCfg;
  _7 = _6->EthCtrlConfigEgressFifo;
  client_fifo_queue.txq_fifo = _7;
  _8 = pCtrlCfg_24->pIngressCfg;
  _9 = _8->EthCtrlConfigIngressFifo;
  client_fifo_queue.rxq_fifo = _9;
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.71_10 = Eth_43_PFE_InternalCfgPtr;
  _11 = Eth_43_PFE_InternalCfgPtr.71_10->pController[_1];
  _12 = _11->EthCtrlType;
  if (_12 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 29232621]:
  # DEBUG BEGIN_STMT
  bResult_37 = EnableController_Aux (prPfeDev_21, &client_queue, &client_fifo_queue);
  # DEBUG bResult => bResult_37
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 59351079]:
  # DEBUG BEGIN_STMT
  if (_12 == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 8> [local count: 20179367]:
  # DEBUG BEGIN_STMT
  _13 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  if (_13 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 9> [local count: 6659191]:
  # DEBUG BEGIN_STMT
  _14 = MEM[(struct trPfeDev *)&arPfeInterface][_1].prPhyIf;
  _15 = pfe_phy_if_enable (_14);
  bResult_35 = _15 == 0;
  # DEBUG bResult => bResult_35
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 39171712]:
  # DEBUG BEGIN_STMT
  bResult_32 = EnableController_HifEmac (prPfeDev_21, &client_queue, &client_fifo_queue);
  # DEBUG bResult => bResult_32

  <bb 11> [local count: 88583700]:
  # bResult_16 = PHI <bResult_37(6), bResult_35(9), bResult_32(10), 0(8)>
  # DEBUG bResult => bResult_16
  client_queue ={v} {CLOBBER};
  client_fifo_queue ={v} {CLOBBER};

  <bb 12> [local count: 1073741824]:
  # bResult_17 = PHI <bResult_23(2), 1(3), bResult_26(4), bResult_16(11)>
  # DEBUG bResult => bResult_17
  # DEBUG BEGIN_STMT
  return bResult_17;

}



;; Function Eth_PFE_LLD_DisableController (Eth_PFE_LLD_DisableController, funcdef_no=83, decl_uid=11266, cgraph_uid=84, symbol_order=103)

Modification phase of node Eth_PFE_LLD_DisableController/103
Eth_PFE_LLD_DisableController (const uint8 u8CtrlIdx)
{
  int _1;
  struct pfe_hif_drv_client_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_4(D);
  # DEBUG D#28 => &arPfeInterface[_1]
  # DEBUG prPfeDev => D#28
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_1].bStarted = 0;
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct trPfeDev *)&arPfeInterface][_1].prClient;
  if (_2 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_client_unregister (_2);
  # DEBUG BEGIN_STMT
  MEM[(struct trPfeDev *)&arPfeInterface][_1].prClient = 0B;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ReleaseAllCtrlTxBuffers (u8CtrlIdx_4(D));
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Eth_PFE_LLD_ShutdownDriver (Eth_PFE_LLD_ShutdownDriver, funcdef_no=55, decl_uid=12311, cgraph_uid=56, symbol_order=75)

Modification phase of node Eth_PFE_LLD_ShutdownDriver/75
Eth_PFE_LLD_ShutdownDriver ()
{
  boolean bDetectHardReset;
  struct oal_irq_t * prCommonChnlIRQ.3_1;
  int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG prHif => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  bDetectHardReset_8 = Eth_PFE_LLD_DetectHardReset ();
  # DEBUG bDetectHardReset => bDetectHardReset_8
  # DEBUG BEGIN_STMT
  if (bDetectHardReset_8 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870912]:
  Eth_PFE_LLD_ShutdownDriver.part.0 ();
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  prCommonChnlIRQ.3_1 = prCommonChnlIRQ;
  if (prCommonChnlIRQ.3_1 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 5> [local count: 287064877]:
  # DEBUG BEGIN_STMT
  oal_irq_destroy (prCommonChnlIRQ.3_1);

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  pfe_platform_remove_sw_if ();
  # DEBUG BEGIN_STMT
  _2 = pfe_platform_remove ();
  if (_2 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  ptrPlatform = 0B;

  <bb 8> [local count: 1073741824]:
  return;

}



;; Function Eth_PFE_LLD_PlatformDrvPrepare (Eth_PFE_LLD_PlatformDrvPrepare, funcdef_no=65, decl_uid=11309, cgraph_uid=66, symbol_order=85)

Modification phase of node Eth_PFE_LLD_PlatformDrvPrepare/85
Eth_PFE_LLD_PlatformDrvPrepare ()
{
  Std_ReturnType retVal;
  long unsigned int _1;
  _Bool _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  bDetectBmuInit ={v} 0;
  # DEBUG BEGIN_STMT
  retVal_9 = PlatformDrvPrepare_ShutdownConfigInit ();
  # DEBUG retVal => retVal_9
  # DEBUG BEGIN_STMT
  if (retVal_9 != 1)
    goto <bb 3>; [48.88%]
  else
    goto <bb 5>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _1 = rPlatformCfg.irq_vector_hif_chnls[0];
  _2 = CreateHifDrv (6, _1, &prCommonHifChnl, &prCommonChnlIRQ, &prCommonHifDrv);
  if (_2 != 0)
    goto <bb 5>; [67.00%]
  else
    goto <bb 4>; [33.00%]

  <bb 4> [local count: 173198851]:
  # DEBUG BEGIN_STMT
  prCommonHifDrv = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Failed to create hif driver\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 2109, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 900542973]:
  # DEBUG retVal => retVal_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (retVal_9 != 1)
    goto <bb 6>; [48.88%]
  else
    goto <bb 7>; [51.12%]

  <bb 6> [local count: 440185405]:
  # DEBUG BEGIN_STMT
  retVal_15 = PlatformDrvPrepare_EnablePhyIf ();
  # DEBUG retVal => retVal_15

  <bb 7> [local count: 1073741824]:
  # retVal_3 = PHI <retVal_9(5), retVal_15(6), 1(4)>
  # DEBUG retVal => retVal_3
  # DEBUG BEGIN_STMT
  return retVal_3;

}



;; Function Eth_PFE_LLD_DeInit (Eth_PFE_LLD_DeInit, funcdef_no=66, decl_uid=11311, cgraph_uid=67, symbol_order=86)

Modification phase of node Eth_PFE_LLD_DeInit/86
Eth_PFE_LLD_DeInit ()
{
  boolean bDrvInitialized;
  uint8 u8Ctr;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG bDrvInitialized => 0
  # DEBUG BEGIN_STMT
  bDrvInitialized_6 = Eth_PFE_LLD_Check_Driver_Init ();
  # DEBUG bDrvInitialized => bDrvInitialized_6
  # DEBUG BEGIN_STMT
  if (bDrvInitialized_6 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 7> [local count: 354334802]:
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_CtrlState[0] ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG u8Ctr => 1

  <bb 4> [local count: 708669605]:
  # u8Ctr_1 = PHI <1(3), 0(7)>
  # DEBUG u8Ctr => u8Ctr_1
  # DEBUG BEGIN_STMT
  if (u8Ctr_1 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Eth_PFE_LLD_ShutdownDriver ();

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function Eth_PFE_LLD_CheckControllerIsActive (Eth_PFE_LLD_CheckControllerIsActive, funcdef_no=84, decl_uid=11258, cgraph_uid=85, symbol_order=104)

Modification phase of node Eth_PFE_LLD_CheckControllerIsActive/104
Eth_PFE_LLD_CheckControllerIsActive (const uint8 u8CtrlIdx)
{
  Eth_ModeType eReturnValue;
  int _1;
  _Bool _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_4(D);
  _2 = arPfeInterface[_1].bStarted;
  if (_2 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG eReturnValue => 0

  <bb 4> [local count: 1073741824]:
  # eReturnValue_3 = PHI <1(2), 0(3)>
  # DEBUG eReturnValue => eReturnValue_3
  # DEBUG BEGIN_STMT
  return eReturnValue_3;

}



;; Function Eth_PFE_LLD_GetPhysicalAddress (Eth_PFE_LLD_GetPhysicalAddress, funcdef_no=85, decl_uid=11273, cgraph_uid=86, symbol_order=105)

Modification phase of node Eth_PFE_LLD_GetPhysicalAddress/105
Eth_PFE_LLD_GetPhysicalAddress (const uint8 u8CtrlIdx, uint8 * pu8PhysAddr)
{
  int _1;
  uint8_t[6] * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_3(D);
  _2 = &arPfeInterface[_1].au8MacAddr;
  autolibc_memcpy (pu8PhysAddr_5(D), _2, 6);
  return;

}



;; Function Eth_PFE_LLD_SetPhysAddr (Eth_PFE_LLD_SetPhysAddr, funcdef_no=86, decl_uid=11276, cgraph_uid=87, symbol_order=106)

Modification phase of node Eth_PFE_LLD_SetPhysAddr/106
Eth_PFE_LLD_SetPhysAddr (const uint8 u8CtrlIdx, const uint8 * pPhysAddrPtr)
{
  errno_t res;
  boolean bReturnStatus;
  int _1;
  uint8_t[6] * _2;
  long int _3;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.77_4;
  const struct Eth_43_PFE_CtrlCfgType * _5;
  <unnamed type> _6;
  struct pfe_phy_if_t * _7;
  <unnamed type> _8;
  int _9;
  struct pfe_phy_if_t * _10;
  <unnamed type> _11;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG bReturnStatus => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_14(D);
  # DEBUG D#29 => &arPfeInterface[_1]
  # DEBUG prPfeDev => D#29
  # DEBUG BEGIN_STMT
  _2 = &MEM[(struct trPfeDev *)&arPfeInterface][_1].au8MacAddr;
  _3 = autolibc_memcmp (_2, pPhysAddrPtr_16(D), 6);
  if (_3 == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.77_4 = Eth_43_PFE_InternalCfgPtr;
  _5 = Eth_43_PFE_InternalCfgPtr.77_4->pController[_1];
  _6 = _5->EthCtrlType;
  if (_6 <= 1)
    goto <bb 4>; [41.00%]
  else
    goto <bb 5>; [59.00%]

  <bb 4> [local count: 220117073]:
  # DEBUG BEGIN_STMT
  autolibc_memcpy (_2, pPhysAddrPtr_16(D), 6);
  # DEBUG BEGIN_STMT
  # DEBUG bReturnStatus => 1
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 316753838]:
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct trPfeDev *)&arPfeInterface][_1].prPhyIf;
  _8 = rPlatformCfg.local_hif;
  _9 = pfe_phy_if_del_mac_addr (_7, _2, _8);
  if (_9 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 6> [local count: 104528766]:
  # DEBUG BEGIN_STMT
  _10 = MEM[(struct trPfeDev *)&arPfeInterface][_1].prPhyIf;
  _11 = rPlatformCfg.local_hif;
  res_20 = pfe_phy_if_add_mac_addr (_10, pPhysAddrPtr_16(D), _11);
  # DEBUG res => res_20
  # DEBUG BEGIN_STMT
  if (res_20 == 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 7> [local count: 70034274]:
  if (res_20 == 116)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 58306146]:
  # DEBUG BEGIN_STMT
  autolibc_memcpy (_2, pPhysAddrPtr_16(D), 6);
  # DEBUG BEGIN_STMT
  # DEBUG bReturnStatus => 1

  <bb 9> [local count: 1073741824]:
  # bReturnStatus_12 = PHI <1(2), 1(4), 0(7), 0(5), 1(8)>
  # DEBUG bReturnStatus => bReturnStatus_12
  # DEBUG BEGIN_STMT
  return bReturnStatus_12;

}



;; Function Eth_PFE_LLD_UpdatePhysAddrFilter (Eth_PFE_LLD_UpdatePhysAddrFilter, funcdef_no=92, decl_uid=11280, cgraph_uid=93, symbol_order=112)

Modification phase of node Eth_PFE_LLD_UpdatePhysAddrFilter/112
Eth_PFE_LLD_UpdatePhysAddrFilter (uint8 u8CtrlIdx, const uint8 * PhysAddrPtr, Eth_FilterActionType Action)
{
  struct trPfeDev * prPfeDev;
  Std_ReturnType u8ReturnStatus;
  int _1;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.78_2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  struct pfe_phy_if_t * _26;
  struct pfe_phy_if_t * _27;
  struct pfe_phy_if_t * _28;
  struct pfe_phy_if_t * _29;
  struct pfe_phy_if_t * const * _30;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG u8ReturnStatus => 1
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_10(D);
  prPfeDev_11 = &arPfeInterface[_1];
  # DEBUG prPfeDev => prPfeDev_11
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.78_2 = Eth_43_PFE_InternalCfgPtr;
  _3 = Eth_43_PFE_InternalCfgPtr.78_2->pController[_1];
  _4 = _3->EthCtrlType;
  if (_4 == 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  if (_4 == 1)
    goto <bb 16>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _5 = pfe_emac_is_broad (PhysAddrPtr_13(D));
  if (_5 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 5> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  if (Action_15(D) == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _28 = MEM[(struct pfe_phy_if_t * *)prPfeDev_11 + 24B];
  # DEBUG D#19 => prPfeDev_11
  u8ReturnStatus_25 = UpdatePhysAddrFilter_AddBroad.isra.0 (_28);
  # DEBUG u8ReturnStatus => u8ReturnStatus_25
  goto <bb 16>; [100.00%]

  <bb 7> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _29 = MEM[(struct pfe_phy_if_t * *)prPfeDev_11 + 24B];
  # DEBUG D#20 => prPfeDev_11
  u8ReturnStatus_23 = UpdatePhysAddrFilter_RemoveBroad.isra.0 (_29);
  # DEBUG u8ReturnStatus => u8ReturnStatus_23
  goto <bb 16>; [100.00%]

  <bb 8> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _6 = pfe_emac_is_zero (PhysAddrPtr_13(D));
  if (_6 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 9> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  if (Action_15(D) == 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 10> [local count: 29232621]:
  # DEBUG BEGIN_STMT
  _30 = &MEM[(struct pfe_phy_if_t * *)prPfeDev_11 + 24B];
  # DEBUG D#21 => prPfeDev_11
  u8ReturnStatus_21 = UpdatePhysAddrFilter_Close.isra.0 (_30);
  # DEBUG u8ReturnStatus => u8ReturnStatus_21
  goto <bb 16>; [100.00%]

  <bb 11> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_is_multi (PhysAddrPtr_13(D));
  if (_7 != 0)
    goto <bb 12>; [67.00%]
  else
    goto <bb 15>; [33.00%]

  <bb 12> [local count: 59351079]:
  # DEBUG BEGIN_STMT
  if (Action_15(D) == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 29675540]:
  # DEBUG BEGIN_STMT
  _26 = MEM[(struct pfe_phy_if_t * *)prPfeDev_11 + 24B];
  # DEBUG D#3 => prPfeDev_11
  u8ReturnStatus_19 = UpdatePhysAddrFilter_AddMulti.isra.0 (_26, PhysAddrPtr_13(D));
  # DEBUG u8ReturnStatus => u8ReturnStatus_19
  goto <bb 16>; [100.00%]

  <bb 14> [local count: 29675540]:
  # DEBUG BEGIN_STMT
  _27 = MEM[(struct pfe_phy_if_t * *)prPfeDev_11 + 24B];
  # DEBUG D#18 => prPfeDev_11
  u8ReturnStatus_17 = UpdatePhysAddrFilter_RemoveMulti.isra.0 (_27, PhysAddrPtr_13(D));
  # DEBUG u8ReturnStatus => u8ReturnStatus_17
  goto <bb 16>; [100.00%]

  <bb 15> [local count: 29232621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Det_ReportError (88, 0, 18, 4);

  <bb 16> [local count: 1073741824]:
  # u8ReturnStatus_8 = PHI <1(2), 1(3), u8ReturnStatus_23(7), u8ReturnStatus_21(10), u8ReturnStatus_17(14), 1(15), u8ReturnStatus_25(6), 1(9), u8ReturnStatus_19(13)>
  # DEBUG u8ReturnStatus => u8ReturnStatus_8
  # DEBUG BEGIN_STMT
  return u8ReturnStatus_8;

}



;; Function Eth_PFE_LLD_ProvideBufferDataArea (Eth_PFE_LLD_ProvideBufferDataArea, funcdef_no=93, decl_uid=11305, cgraph_uid=94, symbol_order=113)

Modification phase of node Eth_PFE_LLD_ProvideBufferDataArea/113
Eth_PFE_LLD_ProvideBufferDataArea (const uint8 u8CtrlIdx, const uint8 u8QueuIdx, Eth_BufIdxType * const pBufIdx, uint8 * * pData, uint16 * const pLength)
{
  boolean bRetVal;
  sint32 s32BufLen;
  Eth_BufIdxType BufIdx;
  uint8 * pBuffer;
  long int tx_buffer_size.80_1;
  short unsigned int _2;
  long int _3;
  _Bool _4;
  long unsigned int BufIdx.81_5;
  unsigned int _6;
  uint8 * _7;
  short unsigned int _8;
  int _14;
  int _21;
  long unsigned int _27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG pBuffer => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG bRetVal => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG lmem_header_size => 0
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => u8CtrlIdx_12(D)
  # DEBUG u8FifoIdx => u8QueuIdx_13(D)
  # DEBUG INLINE_ENTRY Eth_43_PFE_LLD_GetTxBufferSize
  # DEBUG BEGIN_STMT
  _21 = (int) u8CtrlIdx_12(D);
  _14 = (int) u8QueuIdx_13(D);
  _27 = aarTxBufPool[_21][_14].u32BufSize;
  # DEBUG u8CtrlIdx => NULL
  # DEBUG u8FifoIdx => NULL
  # DEBUG tx_buffer_size => _27
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tx_buffer_size.80_1 = (long int) _27;
  s32BufLen_15 = tx_buffer_size.80_1 + -30;
  # DEBUG s32BufLen => s32BufLen_15
  # DEBUG BEGIN_STMT
  _2 = *pLength_16(D);
  _3 = (long int) _2;
  if (_3 <= s32BufLen_15)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _4 = GetTxBuffer (u8CtrlIdx_12(D), u8QueuIdx_13(D), &BufIdx);
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  BufIdx.81_5 = BufIdx;
  _6 = aarTxBuf[_21][BufIdx.81_5].BufAddr;
  pBuffer_18 = (uint8 *) _6;
  # DEBUG pBuffer => pBuffer_18
  # DEBUG BEGIN_STMT
  _7 = pBuffer_18 + 30;
  *pData_19(D) = _7;
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => u8CtrlIdx_12(D)
  # DEBUG BufIdx => BufIdx.81_5
  # DEBUG INLINE_ENTRY Eth_PFE_LLD_GetTxBufMeta
  # DEBUG BEGIN_STMT
  # DEBUG D#31 => &aarTxBuf[_21][BufIdx.81_5].rMeta
  # DEBUG u8CtrlIdx => NULL
  # DEBUG BufIdx => NULL
  # DEBUG prTxMeta => D#31
  # DEBUG BEGIN_STMT
  MEM[(struct trTxMeta *)&aarTxBuf][_21][BufIdx.81_5].rMeta.bDoTS = 0;
  # DEBUG BEGIN_STMT
  *pBufIdx_23(D) = BufIdx.81_5;
  # DEBUG BEGIN_STMT
  # DEBUG bRetVal => 1

  <bb 5> [local count: 1073741824]:
  # bRetVal_9 = PHI <0(2), 0(3), 1(4)>
  # DEBUG bRetVal => bRetVal_9
  # DEBUG BEGIN_STMT
  _8 = (short unsigned int) s32BufLen_15;
  *pLength_16(D) = _8;
  # DEBUG BEGIN_STMT
  BufIdx ={v} {CLOBBER};
  return bRetVal_9;

}



;; Function Eth_43_PFE_LLD_GetLmemHdrSize (Eth_43_PFE_LLD_GetLmemHdrSize, funcdef_no=94, decl_uid=11286, cgraph_uid=95, symbol_order=114)

Modification phase of node Eth_43_PFE_LLD_GetLmemHdrSize/114
Eth_43_PFE_LLD_GetLmemHdrSize (const uint8 u8CtrlIdx)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG lmem_header_size => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Eth_43_PFE_LLD_GetTxFifoIdx (Eth_43_PFE_LLD_GetTxFifoIdx, funcdef_no=95, decl_uid=11289, cgraph_uid=96, symbol_order=115)

Modification phase of node Eth_43_PFE_LLD_GetTxFifoIdx/115
Eth_43_PFE_LLD_GetTxFifoIdx (const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
  int _1;
  uint8 _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_2(D);
  _5 = aarTxBuf[_1][BufIdx_4(D)].u8Fifo;
  return _5;

}



;; Function Eth_43_PFE_LLD_GetTxBufferSize (Eth_43_PFE_LLD_GetTxBufferSize, funcdef_no=96, decl_uid=11292, cgraph_uid=97, symbol_order=116)

Modification phase of node Eth_43_PFE_LLD_GetTxBufferSize/116
Eth_43_PFE_LLD_GetTxBufferSize (const uint8 u8CtrlIdx, const uint8 u8FifoIdx)
{
  int _1;
  int _2;
  uint32 _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_3(D);
  _2 = (int) u8FifoIdx_4(D);
  _6 = aarTxBufPool[_1][_2].u32BufSize;
  return _6;

}



;; Function Eth_PFE_LLD_ReleaseTxBuffer (Eth_PFE_LLD_ReleaseTxBuffer, funcdef_no=97, decl_uid=11250, cgraph_uid=98, symbol_order=117)

Modification phase of node Eth_PFE_LLD_ReleaseTxBuffer/117
Eth_PFE_LLD_ReleaseTxBuffer (const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx)
{
  const uint8 status;
  boolean res;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG res => 0
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_4(D);
  status_7 = aarTxBuf[_1][BufIdx_6(D)].u8Status;
  # DEBUG status => status_7
  # DEBUG BEGIN_STMT
  if (status_7 <= 1)
    goto <bb 3>; [41.00%]
  else
    goto <bb 4>; [59.00%]

  <bb 3> [local count: 440234148]:
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => u8CtrlIdx_4(D)
  # DEBUG BufIdx => BufIdx_6(D)
  # DEBUG INLINE_ENTRY ReleaseTxBuffer
  # DEBUG BEGIN_STMT
  aarTxBuf[_1][BufIdx_6(D)].u8Status = 0;
  # DEBUG u8CtrlIdx => NULL
  # DEBUG BufIdx => NULL
  # DEBUG BEGIN_STMT
  # DEBUG res => 1

  <bb 4> [local count: 1073741824]:
  # res_2 = PHI <0(2), 1(3)>
  # DEBUG res => res_2
  # DEBUG BEGIN_STMT
  return res_2;

}



;; Function Eth_PFE_LLD_Transmit (Eth_PFE_LLD_Transmit, funcdef_no=98, decl_uid=11299, cgraph_uid=99, symbol_order=118)

Modification phase of node Eth_PFE_LLD_Transmit/118
Eth_PFE_LLD_Transmit (const uint8 u8CtrlIdx, const Eth_BufIdxType BufIdx, const Eth_FrameType u16Type, const uint16 u16Length, const boolean bConfirm, const uint8 * pDest)
{
  errno_t Status;
  uint8 * framePtr;
  uint16 u16frameLength;
  uint8 u8NewBufStatus;
  const uint8 * apu8MacAddr;
  Std_ReturnType RetVal;
  int _1;
  unsigned int _2;
  long unsigned int _3;
  unsigned char _4;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.85_5;
  const struct Eth_43_PFE_CtrlCfgType * _6;
  unsigned char _7;
  _Bool _8;
  _Bool _9;
  uint8 * _10;
  short unsigned int _11;
  unsigned char _12;
  unsigned char _13;
  _Bool _14;
  int iftmp.86_17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG lmem_header_size => 0
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_20(D);
  apu8MacAddr_21 = &arPfeInterface[_1].au8MacAddr;
  # DEBUG apu8MacAddr => apu8MacAddr_21
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => u8CtrlIdx_20(D)
  # DEBUG BufIdx => BufIdx_23(D)
  # DEBUG INLINE_ENTRY Eth_PFE_LLD_GetTxBufMeta
  # DEBUG BEGIN_STMT
  # DEBUG D#32 => &aarTxBuf[_1][BufIdx_23(D)].rMeta
  # DEBUG u8CtrlIdx => NULL
  # DEBUG BufIdx => NULL
  # DEBUG prTxMeta => D#32
  # DEBUG BEGIN_STMT
  # DEBUG u8NewBufStatus => 20
  # DEBUG BEGIN_STMT
  u16frameLength_25 = u16Length_24(D) + 14;
  # DEBUG u16frameLength => u16frameLength_25
  # DEBUG BEGIN_STMT
  _2 = aarTxBuf[_1][BufIdx_23(D)].BufAddr;
  _3 = _2 + 16;
  framePtr_26 = (uint8 *) _3;
  # DEBUG framePtr => framePtr_26
  # DEBUG BEGIN_STMT
  _4 = aarTxBuf[_1][BufIdx_23(D)].u8Status;
  if (_4 != 1)
    goto <bb 3>; [48.88%]
  else
    goto <bb 5>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Attempted to transmit buffer with wrong status\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 3277, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (bConfirm_27(D) != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 4> [local count: 173198851]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.85_5 = Eth_43_PFE_InternalCfgPtr;
  _6 = Eth_43_PFE_InternalCfgPtr.85_5->pController[_1];
  _7 = _6->EthCtrlEthIfIdx;
  EthIf_TxConfirmation (_7, BufIdx_23(D), 1);
  goto <bb 12>; [100.00%]

  <bb 5> [local count: 548896821]:
  # DEBUG BEGIN_STMT
  MEM[(struct trTxMeta *)&aarTxBuf][_1][BufIdx_23(D)].rMeta.bDoTxIndication = bConfirm_27(D);
  # DEBUG BEGIN_STMT
  _8 = MEM[(struct trTxMeta *)&aarTxBuf][_1][BufIdx_23(D)].rMeta.bDoTS;
  if (_8 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 274448410]:
  if (bConfirm_27(D) != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 411672615]:

  <bb 8> [local count: 548896821]:
  # iftmp.86_17 = PHI <1(6), 0(7)>
  _9 = (_Bool) iftmp.86_17;
  MEM[(struct trTxMeta *)&aarTxBuf][_1][BufIdx_23(D)].rMeta.bDoTS = _9;
  # DEBUG BEGIN_STMT
  autolibc_memcpy (framePtr_26, pDest_30(D), 6);
  # DEBUG BEGIN_STMT
  _10 = framePtr_26 + 6;
  autolibc_memcpy (_10, apu8MacAddr_21, 6);
  # DEBUG BEGIN_STMT
  _11 = u16Type_33(D) >> 8;
  _12 = (unsigned char) _11;
  MEM[(uint8 *)framePtr_26 + 12B] = _12;
  # DEBUG BEGIN_STMT
  _13 = (unsigned char) u16Type_33(D);
  MEM[(uint8 *)framePtr_26 + 13B] = _13;
  # DEBUG BEGIN_STMT
  aarTxBuf[_1][BufIdx_23(D)].TimeQual = 1;
  # DEBUG BEGIN_STMT
  _14 = MEM[(struct trTxMeta *)&aarTxBuf][_1][BufIdx_23(D)].rMeta.bDoTS;
  if (_14 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 181135951]:
  # DEBUG BEGIN_STMT
  TxReqTsQueueWrite (u8CtrlIdx_20(D), BufIdx_23(D));
  # DEBUG BEGIN_STMT
  # DEBUG u8NewBufStatus => 28

  <bb 10> [local count: 548896821]:
  # u8NewBufStatus_16 = PHI <20(8), 28(9)>
  # DEBUG u8NewBufStatus => u8NewBufStatus_16
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  aarTxBuf[_1][BufIdx_23(D)].u8Status = u8NewBufStatus_16;
  # DEBUG BEGIN_STMT
  Status_40 = TxReqTrigger (u8CtrlIdx_20(D), BufIdx_23(D), u16frameLength_25);
  # DEBUG Status => Status_40
  # DEBUG BEGIN_STMT
  if (Status_40 != 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 11> [local count: 181135951]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Transmission has failed (%d)\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 3315, Status_40, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TxReqFailed (u8CtrlIdx_20(D), BufIdx_23(D));

  <bb 12> [local count: 1073741824]:
  # RetVal_15 = PHI <1(4), 1(11), 0(10), 1(3)>
  # DEBUG RetVal => RetVal_15
  # DEBUG BEGIN_STMT
  return RetVal_15;

}



;; Function Eth_PFE_LLD_ReportReception (Eth_PFE_LLD_ReportReception, funcdef_no=104, decl_uid=11284, cgraph_uid=105, symbol_order=124)

Modification phase of node Eth_PFE_LLD_ReportReception/124
Eth_PFE_LLD_ReportReception (const uint8 u8CtrlIdx, uint8 u8FifoIdx, const boolean bIrq)
{
  struct pfe_hif_drv_client_t * prClient;
  const struct pfe_hif_pkt_t * RxPacket;
  Eth_RxStatusType RetVal;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned char _4;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_11(D);
  prClient_13 = arPfeInterface[_1].prClient;
  # DEBUG prClient => prClient_13

  <bb 3> [local count: 1073741824]:
  # RetVal_5 = PHI <1(2), RetVal_6(12)>
  # DEBUG RetVal => RetVal_5
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = (long unsigned int) u8FifoIdx_14(D);
  RxPacket_16 = pfe_hif_drv_client_receive_pkt (prClient_13, _2);
  # DEBUG RxPacket => RxPacket_16
  # DEBUG BEGIN_STMT
  if (RxPacket_16 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG D#23 => u8FifoIdx_14(D)
  ReportReception_ProcessPacket.isra.0 (u8CtrlIdx_11(D), RxPacket_16);
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0

  <bb 5> [local count: 1073741824]:
  # RetVal_6 = PHI <RetVal_5(3), 0(4)>
  # DEBUG RetVal => RetVal_6
  # DEBUG BEGIN_STMT
  if (bIrq_18(D) != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686023]:
  if (RxPacket_16 != 0B)
    goto <bb 12>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 12> [local count: 958878292]:
  goto <bb 3>; [100.00%]

  <bb 7> [local count: 114863532]:
  # _3 = PHI <_2(5), _2(6)>
  # RetVal_21 = PHI <RetVal_6(5), RetVal_6(6)>
  # DEBUG BEGIN_STMT
  pfe_hif_drv_client_rx_done (prClient_13);
  # DEBUG BEGIN_STMT
  if (bIrq_18(D) != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 57431766]:
  if (RetVal_21 == 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 9> [local count: 18952483]:
  # DEBUG BEGIN_STMT
  _4 = pfe_hif_drv_client_has_rx_pkt (prClient_13, _3);
  if (_4 == 1)
    goto <bb 10>; [21.72%]
  else
    goto <bb 11>; [78.28%]

  <bb 10> [local count: 4116479]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 2

  <bb 11> [local count: 114863532]:
  # RetVal_7 = PHI <RetVal_21(7), RetVal_21(8), 0(9), 2(10)>
  # DEBUG RetVal => RetVal_7
  # DEBUG BEGIN_STMT
  return RetVal_7;

}



;; Function Eth_PFE_LLD_ReportTransmission (Eth_PFE_LLD_ReportTransmission, funcdef_no=105, decl_uid=11247, cgraph_uid=106, symbol_order=125)

Modification phase of node Eth_PFE_LLD_ReportTransmission/125
Eth_PFE_LLD_ReportTransmission (const uint8 u8CtrlIdx, const uint8 u8FifoIdx)
{
  Std_ReturnType Status;
  uint8 u8BufStatus;
  Eth_BufIdxType BufIdx;
  const struct Eth_PFE_LLD_trTxRefData * prRefData;
  const struct pfe_hif_drv_client_t * prClient;
  int _1;
  long unsigned int _2;
  short unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  short unsigned int _6;
  unsigned char _7;
  _Bool _8;
  _Bool _9;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.89_10;
  const struct Eth_43_PFE_CtrlCfgType * _11;
  unsigned char _12;
  short unsigned int _25;
  int _32;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_16(D);
  prClient_18 = arPfeInterface[_1].prClient;
  # DEBUG prClient => prClient_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG bStillSearching => 1

  <bb 3> [local count: 1044213930]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = (long unsigned int) u8FifoIdx_19(D);
  prRefData_21 = pfe_hif_drv_client_receive_tx_conf (prClient_18, _2);
  # DEBUG prRefData => prRefData_21
  # DEBUG BEGIN_STMT
  if (prRefData_21 == 0B)
    goto <bb 5>; [11.00%]
  else
    goto <bb 4>; [89.00%]

  <bb 4> [local count: 929350397]:
  # DEBUG BEGIN_STMT
  _3 = prRefData_21->u16BufIdx;
  BufIdx_22 = (Eth_BufIdxType) _3;
  # DEBUG BufIdx => BufIdx_22
  # DEBUG BEGIN_STMT
  _4 = aarTxBuf[_1][BufIdx_22].u8Status;
  _5 = _4 & 251;
  aarTxBuf[_1][BufIdx_22].u8Status = _5;
  # DEBUG BEGIN_STMT
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  pfe_hif_drv_client_tx_done (prClient_18);
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 6> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  u8BufStatus_27 = aarTxBuf[_1][BufIdx_26].u8Status;
  # DEBUG u8BufStatus => u8BufStatus_27
  # DEBUG BEGIN_STMT
  _7 = u8BufStatus_27 & 4;
  if (_7 == 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 14>; [5.50%]

  <bb 7> [local count: 958878294]:
  # DEBUG BEGIN_STMT
  TxReqQueueDelete (u8CtrlIdx_16(D));
  # DEBUG BEGIN_STMT
  if (u8BufStatus_27 == 16)
    goto <bb 9>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 632859674]:
  if (u8BufStatus_27 == 2)
    goto <bb 9>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 9> [local count: 541190909]:
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => u8CtrlIdx_16(D)
  # DEBUG BufIdx => BufIdx_26
  # DEBUG INLINE_ENTRY Eth_PFE_LLD_GetTxBufMeta
  # DEBUG BEGIN_STMT
  # DEBUG D#34 => &aarTxBuf[_1][BufIdx_26].rMeta
  # DEBUG u8CtrlIdx => NULL
  # DEBUG BufIdx => NULL
  # DEBUG prTxMeta => D#34
  # DEBUG BEGIN_STMT
  _8 = MEM[(const struct trTxMeta *)&aarTxBuf][_1][BufIdx_26].rMeta.bDoTxIndication;
  if (_8 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 178593000]:
  # DEBUG BEGIN_STMT
  _9 = u8BufStatus_27 == 2;
  Status_29 = (Std_ReturnType) _9;
  # DEBUG Status => Status_29
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 20
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (20);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.89_10 = Eth_43_PFE_InternalCfgPtr;
  _11 = Eth_43_PFE_InternalCfgPtr.89_10->pController[_1];
  _12 = _11->EthCtrlEthIfIdx;
  EthIf_TxConfirmation (_12, BufIdx_26, Status_29);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 20
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (20);

  <bb 11> [local count: 541190909]:
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  aarTxBuf[_1][BufIdx_26].u8Status = 0;

  <bb 12> [local count: 958878294]:

  <bb 13> [local count: 1073741824]:
  # DEBUG bStillSearching => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => u8CtrlIdx_16(D)
  # DEBUG INLINE_ENTRY TxReqQueueRead
  # DEBUG BEGIN_STMT
  _25 = u16TxQueueRead[_1];
  _32 = (int) _25;
  # DEBUG D#33 => &arTxReqQueue[_1][_32]
  # DEBUG prRefPtr => D#33
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => NULL
  # DEBUG prRefPtr => NULL
  # DEBUG prRefData => D#33
  # DEBUG BEGIN_STMT
  _6 = MEM[(const struct Eth_PFE_LLD_trTxRefData *)&arTxReqQueue][_1][_32].u16BufIdx;
  BufIdx_26 = (Eth_BufIdxType) _6;
  # DEBUG BufIdx => BufIdx_26
  # DEBUG BEGIN_STMT
  if (BufIdx_26 == 65535)
    goto <bb 14>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 14> [local count: 114863532]:
  # DEBUG bStillSearching => NULL
  return;

}



;; Function Eth_PFE_LLD_ReportTransmissionTS (Eth_PFE_LLD_ReportTransmissionTS, funcdef_no=106, decl_uid=11253, cgraph_uid=107, symbol_order=126)

Modification phase of node Eth_PFE_LLD_ReportTransmissionTS/126
Eth_PFE_LLD_ReportTransmissionTS (const uint8 u8CtrlIdx, const uint8 u8FifoIdx)
{
  bool_t bContinue;
  errno_t Error;
  uint8 u8BufStatus;
  Eth_BufIdxType BufIdx;
  int _1;
  int _2;
  short unsigned int _3;
  int _4;
  Eth_TimeStampQualType * _5;
  struct Eth_TimeStampType * _6;
  short unsigned int _7;
  int _8;
  short unsigned int _9;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.90_10;
  const struct Eth_43_PFE_CtrlCfgType * _11;
  unsigned char _12;
  unsigned char _13;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG bContinue => 1

  <bb 3> [local count: 1073741824]:
  # bContinue_14 = PHI <1(2), 1(13)>
  # DEBUG bContinue => bContinue_14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 18
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (18);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_20(D);
  _2 = (int) u8FifoIdx_21(D);
  _3 = arPfeInterface[_1].u16TSQueueRead[_2];
  _4 = (int) _3;
  BufIdx_22 = arPfeInterface[_1].TSQueue[_2][_4];
  # DEBUG BufIdx => BufIdx_22
  # DEBUG BEGIN_STMT
  if (BufIdx_22 == 65535)
    goto <bb 11>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 4> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  _5 = &aarTxBuf[_1][BufIdx_22].TimeQual;
  _6 = &aarTxBuf[_1][BufIdx_22].TimeStamp;
  Error_24 = GetTxTimeStamp (u8CtrlIdx_20(D), BufIdx_22, _5, _6);
  # DEBUG Error => Error_24
  # DEBUG BEGIN_STMT
  if (Error_24 == 118)
    goto <bb 11>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 5> [local count: 482002705]:
  # DEBUG BEGIN_STMT
  _7 = arPfeInterface[_1].u16TSQueueRead[_2];
  _8 = (int) _7;
  arPfeInterface[_1].TSQueue[_2][_8] = 65535;
  # DEBUG BEGIN_STMT
  _9 = arPfeInterface[_1].u16TSQueueRead[_2];
  if (_9 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 241001352]:
  # DEBUG BEGIN_STMT
  arPfeInterface[_1].u16TSQueueRead[_2] = 0;
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 241001352]:
  # DEBUG BEGIN_STMT
  arPfeInterface[_1].u16TSQueueRead[_2] = 1;

  <bb 8> [local count: 482002705]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u8BufStatus_28 = aarTxBuf[_1][BufIdx_22].u8Status;
  # DEBUG u8BufStatus => u8BufStatus_28
  # DEBUG BEGIN_STMT
  if (u8BufStatus_28 == 24)
    goto <bb 9>; [20.24%]
  else
    goto <bb 10>; [79.76%]

  <bb 9> [local count: 97557347]:
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 21
  # DEBUG INLINE_ENTRY oal_mutex_lock
  # DEBUG BEGIN_STMT
  oal_mutex_lock.part.0 (21);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.90_10 = Eth_43_PFE_InternalCfgPtr;
  _11 = Eth_43_PFE_InternalCfgPtr.90_10->pController[_1];
  _12 = _11->EthCtrlEthIfIdx;
  EthIf_TxConfirmation (_12, BufIdx_22, 0);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 21
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (21);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  aarTxBuf[_1][BufIdx_22].u8Status = 0;
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 384445357]:
  # DEBUG BEGIN_STMT
  _13 = u8BufStatus_28 & 247;
  aarTxBuf[_1][BufIdx_22].u8Status = _13;

  <bb 11> [local count: 1073741824]:
  # bContinue_15 = PHI <0(3), 0(4), bContinue_14(9), bContinue_14(10)>
  # DEBUG bContinue => bContinue_15
  # DEBUG BEGIN_STMT
  # DEBUG mutex => 18
  # DEBUG INLINE_ENTRY oal_mutex_unlock
  # DEBUG BEGIN_STMT
  oal_mutex_unlock.part.0 (18);
  # DEBUG BEGIN_STMT
  # DEBUG mutex => NULL
  # DEBUG BEGIN_STMT
  if (bContinue_15 == 1)
    goto <bb 13>; [89.00%]
  else
    goto <bb 12>; [11.00%]

  <bb 13> [local count: 955630223]:
  goto <bb 3>; [100.00%]

  <bb 12> [local count: 118111601]:
  return;

}



;; Function ClientEventHdlr (ClientEventHdlr, funcdef_no=43, decl_uid=12192, cgraph_uid=44, symbol_order=63)

Modification phase of node ClientEventHdlr/63
ClientEventHdlr (struct pfe_hif_drv_client_t * prClient, void * pvArg, uint32 u32Event, uint32 u32QueueIdx)
{
  uint8 u8ClientIdx;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetValue => 0
  # DEBUG BEGIN_STMT
  # DEBUG prPfeDev => pvArg_5(D)
  # DEBUG BEGIN_STMT
  u8ClientIdx_7 = MEM[(const struct trPfeDev *)pvArg_5(D)].u8CtrlIdx;
  # DEBUG u8ClientIdx => u8ClientIdx_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (u32Event_8(D)) <default: <L6> [25.00%], case 0: <L0> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) u32QueueIdx_9(D);
  ClientEventHdlr_RX (u8ClientIdx_7, _1);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  _2 = (unsigned char) u32QueueIdx_9(D);
  ClientEventHdlr_TX (u8ClientIdx_7, _2);
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  _3 = (unsigned char) u32QueueIdx_9(D);
  ClientEventHdlr_ETS (u8ClientIdx_7, _3);
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L6>:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Eth_PFE_LLD_MainFunction (Eth_PFE_LLD_MainFunction, funcdef_no=118, decl_uid=11307, cgraph_uid=119, symbol_order=138)

Modification phase of node Eth_PFE_LLD_MainFunction/138
Eth_PFE_LLD_MainFunction ()
{
  Eth_ModeType eReturnValue;
  uint8 u8NumsFifo;
  uint8 u8FifoIdx;
  uint8 u8CtrlIdx;
  uint8 u8EthIfCtrlIdx;
  struct pfe_platform_t * ptrPlatform.91_1;
  long unsigned int u32RtrTimeoutTimeMs.92_2;
  long unsigned int _3;
  struct pfe_rtable_t * _4;
  long unsigned int u32RtrTimeoutTimeMs.95_5;
  long unsigned int _6;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.96_7;
  const struct Eth_43_PFE_CtrlCfgType * _9;
  <unnamed type> _10;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.97_11;
  const struct Eth_43_PFE_CtrlCfgType * _12;
  long unsigned int _13;
  long unsigned int _14;
  short unsigned int _15;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.99_16;
  const struct Eth_43_PFE_CtrlCfgType * _17;
  long unsigned int _18;
  long unsigned int _19;
  short unsigned int _20;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.101_21;
  const struct Eth_43_PFE_CtrlCfgType * _22;
  long unsigned int _23;
  long unsigned int _24;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.103_25;
  const struct Eth_43_PFE_CtrlCfgType * _26;
  long unsigned int _27;
  long unsigned int _28;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.105_29;
  const struct Eth_43_PFE_CtrlCfgType * _30;
  long unsigned int _31;
  long unsigned int _32;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.107_33;
  const struct Eth_43_PFE_CtrlCfgType * _34;
  long unsigned int _35;
  long unsigned int _36;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.109_37;
  const struct Eth_43_PFE_CtrlCfgType * _38;
  long unsigned int _39;
  long unsigned int _40;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.111_41;
  const struct Eth_43_PFE_CtrlCfgType * _42;
  long unsigned int _43;
  long unsigned int _44;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.113_45;
  const struct Eth_43_PFE_CtrlCfgType * _46;
  long unsigned int _47;
  long unsigned int _48;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.115_49;
  const struct Eth_43_PFE_CtrlCfgType * _50;
  long unsigned int _51;
  long unsigned int _52;
  const struct Eth_43_PFE_StaticCtrlCfgType * _53;
  _Bool _54;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.117_55;
  const struct Eth_43_PFE_CtrlCfgType * _56;
  struct pfe_hif_drv_client_t * _57;
  _Bool _89;
  long unsigned int _91;
  _Bool _92;

  <bb 2> [local count: 31125933]:
  # DEBUG BEGIN_STMT
  ptrPlatform.91_1 = ptrPlatform;
  if (ptrPlatform.91_1 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 23>; [30.00%]

  <bb 3> [local count: 21788153]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32RtrTimeoutTimeMs.92_2 = u32RtrTimeoutTimeMs;
  if (u32RtrTimeoutTimeMs.92_2 <= 899)
    goto <bb 4>; [67.00%]
  else
    goto <bb 6>; [33.00%]

  <bb 4> [local count: 14598063]:
  # DEBUG BEGIN_STMT
  _3 = u32RtrTimeoutTimeMs.92_2 + 100;
  u32RtrTimeoutTimeMs = _3;

  <bb 5> [local count: 21788153]:
  # u8CtrlIdx_60 = PHI <0(6), 0(4)>
  goto <bb 21>; [100.00%]

  <bb 6> [local count: 7190091]:
  # DEBUG BEGIN_STMT
  _4 = ptrPlatform.91_1->rtable;
  pfe_rtable_do_timeouts (_4);
  # DEBUG BEGIN_STMT
  u32RtrTimeoutTimeMs.95_5 = u32RtrTimeoutTimeMs;
  _6 = u32RtrTimeoutTimeMs.95_5 + 4294966396;
  u32RtrTimeoutTimeMs = _6;
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 176285971]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.96_7 = Eth_43_PFE_InternalCfgPtr;
  _9 = Eth_43_PFE_InternalCfgPtr.96_7->pController[0];
  u8EthIfCtrlIdx_72 = _9->EthCtrlEthIfIdx;
  # DEBUG u8EthIfCtrlIdx => u8EthIfCtrlIdx_72
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => 0
  # DEBUG INLINE_ENTRY Eth_PFE_LLD_CheckControllerIsActive
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _89 = arPfeInterface[0].bStarted;
  if (_89 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 88142985]:
  # DEBUG BEGIN_STMT
  # DEBUG eReturnValue => 0

  <bb 9> [local count: 176285971]:
  # eReturnValue_90 = PHI <1(7), 0(8)>
  # DEBUG eReturnValue => eReturnValue_90
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => NULL
  # DEBUG eReturnValue => NULL
  # DEBUG eCurrentMode => eReturnValue_90
  # DEBUG BEGIN_STMT
  _10 = eSavedMode[0];
  if (_10 != eReturnValue_90)
    goto <bb 10>; [48.88%]
  else
    goto <bb 11>; [51.12%]

  <bb 10> [local count: 86168583]:
  # DEBUG BEGIN_STMT
  eSavedMode[0] = eReturnValue_90;
  # DEBUG BEGIN_STMT
  EthIf_CtrlModeIndication (u8EthIfCtrlIdx_72, eReturnValue_90);

  <bb 11> [local count: 176285971]:
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY Eth_PFE_LLD_CheckAccessToController
  # DEBUG BEGIN_STMT
  # DEBUG partitionStat => 0
  # DEBUG BEGIN_STMT
  _91 ={v} MEM[(volatile uint32_t *)1074300168B];
  _92 = (_Bool) _91;
  # DEBUG partitionStat => _92
  # DEBUG BEGIN_STMT
  if (_92 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 88142985]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.97_11 = Eth_43_PFE_InternalCfgPtr;
  _12 = Eth_43_PFE_InternalCfgPtr.97_11->pController[0];
  _13 = _12->ETH_43_PFE_DEM_E_ACCESS_Cfg.state;
  if (_13 == 1)
    goto <bb 13>; [20.24%]
  else
    goto <bb 16>; [79.76%]

  <bb 13> [local count: 17840140]:
  # DEBUG BEGIN_STMT
  _14 = _12->ETH_43_PFE_DEM_E_ACCESS_Cfg.id;
  _15 = (short unsigned int) _14;
  Dem_SetEventStatus (_15, 3);
  goto <bb 16>; [100.00%]

  <bb 14> [local count: 88142985]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.99_16 = Eth_43_PFE_InternalCfgPtr;
  _17 = Eth_43_PFE_InternalCfgPtr.99_16->pController[0];
  _18 = _17->ETH_43_PFE_DEM_E_ACCESS_Cfg.state;
  if (_18 == 1)
    goto <bb 15>; [20.24%]
  else
    goto <bb 16>; [79.76%]

  <bb 15> [local count: 17840140]:
  # DEBUG BEGIN_STMT
  _19 = _17->ETH_43_PFE_DEM_E_ACCESS_Cfg.id;
  _20 = (short unsigned int) _19;
  Dem_SetEventStatus (_20, 2);

  <bb 16> [local count: 176285970]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.101_21 = Eth_43_PFE_InternalCfgPtr;
  _22 = Eth_43_PFE_InternalCfgPtr.101_21->pController[0];
  _23 = _22->ETH_43_PFE_E_RX_FRAMES_LOST_Cfg.state;
  _24 = _22->ETH_43_PFE_E_RX_FRAMES_LOST_Cfg.id;
  CheckDemStatus (0, _23, 0, _24);
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.103_25 = Eth_43_PFE_InternalCfgPtr;
  _26 = Eth_43_PFE_InternalCfgPtr.103_25->pController[0];
  _27 = _26->ETH_43_PFE_E_CRC_Cfg.state;
  _28 = _26->ETH_43_PFE_E_CRC_Cfg.id;
  CheckDemStatus (0, _27, 1, _28);
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.105_29 = Eth_43_PFE_InternalCfgPtr;
  _30 = Eth_43_PFE_InternalCfgPtr.105_29->pController[0];
  _31 = _30->ETH_43_PFE_E_UNDERSIZEFRAME_Cfg.state;
  _32 = _30->ETH_43_PFE_E_UNDERSIZEFRAME_Cfg.id;
  CheckDemStatus (0, _31, 2, _32);
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.107_33 = Eth_43_PFE_InternalCfgPtr;
  _34 = Eth_43_PFE_InternalCfgPtr.107_33->pController[0];
  _35 = _34->ETH_43_PFE_E_OVERSIZEFRAME_Cfg.state;
  _36 = _34->ETH_43_PFE_E_OVERSIZEFRAME_Cfg.id;
  CheckDemStatus (0, _35, 3, _36);
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.109_37 = Eth_43_PFE_InternalCfgPtr;
  _38 = Eth_43_PFE_InternalCfgPtr.109_37->pController[0];
  _39 = _38->ETH_43_PFE_E_ALIGNMENT_Cfg.state;
  _40 = _38->ETH_43_PFE_E_ALIGNMENT_Cfg.id;
  CheckDemStatus (0, _39, 4, _40);
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.111_41 = Eth_43_PFE_InternalCfgPtr;
  _42 = Eth_43_PFE_InternalCfgPtr.111_41->pController[0];
  _43 = _42->ETH_43_PFE_E_SINGLECOLLISION_Cfg.state;
  _44 = _42->ETH_43_PFE_E_SINGLECOLLISION_Cfg.id;
  CheckDemStatus (0, _43, 5, _44);
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.113_45 = Eth_43_PFE_InternalCfgPtr;
  _46 = Eth_43_PFE_InternalCfgPtr.113_45->pController[0];
  _47 = _46->ETH_43_PFE_E_MULTIPLECOLLISION_Cfg.state;
  _48 = _46->ETH_43_PFE_E_MULTIPLECOLLISION_Cfg.id;
  CheckDemStatus (0, _47, 6, _48);
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.115_49 = Eth_43_PFE_InternalCfgPtr;
  _50 = Eth_43_PFE_InternalCfgPtr.115_49->pController[0];
  _51 = _50->ETH_43_PFE_E_LATECOLLISION_Cfg.state;
  _52 = _50->ETH_43_PFE_E_LATECOLLISION_Cfg.id;
  CheckDemStatus (0, _51, 7, _52);
  # DEBUG BEGIN_STMT
  _53 = Eth_43_PFE_StaticConfig.pController[0];
  _54 = _53->EnableTxInterrupt;
  if (_54 != 0)
    goto <bb 17>; [67.00%]
  else
    goto <bb 20>; [33.00%]

  <bb 17> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.117_55 = Eth_43_PFE_InternalCfgPtr;
  _56 = Eth_43_PFE_InternalCfgPtr.117_55->pController[0];
  u8NumsFifo_85 = _56->EthCtrlEgressFifoCnt;
  # DEBUG u8NumsFifo => u8NumsFifo_85
  # DEBUG BEGIN_STMT
  # DEBUG u8FifoIdx => 0
  goto <bb 19>; [100.00%]

  <bb 18> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  Eth_PFE_LLD_ReportTransmissionTS (0, u8FifoIdx_59);
  # DEBUG BEGIN_STMT
  u8FifoIdx_87 = u8FifoIdx_59 + 1;
  # DEBUG u8FifoIdx => u8FifoIdx_87

  <bb 19> [local count: 1073741824]:
  # u8FifoIdx_59 = PHI <0(17), u8FifoIdx_87(18)>
  # DEBUG u8FifoIdx => u8FifoIdx_59
  # DEBUG BEGIN_STMT
  if (u8FifoIdx_59 < u8NumsFifo_85)
    goto <bb 18>; [89.00%]
  else
    goto <bb 20>; [11.00%]

  <bb 20> [local count: 176285971]:
  # DEBUG BEGIN_STMT
  _57 = arPfeInterface[0].prClient;
  pfe_hif_drv_client_ptp_ts_db_tick_iteration (_57);
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => 1

  <bb 21> [local count: 198074125]:
  # u8CtrlIdx_58 = PHI <u8CtrlIdx_60(5), 1(20)>
  # DEBUG u8CtrlIdx => u8CtrlIdx_58
  # DEBUG BEGIN_STMT
  if (u8CtrlIdx_58 == 0)
    goto <bb 7>; [89.00%]
  else
    goto <bb 22>; [11.00%]

  <bb 22> [local count: 21788154]:
  # DEBUG BEGIN_STMT
  Eth_PFE_LLD_PollerFunction ();

  <bb 23> [local count: 31125934]:
  return;

}



;; Function Eth_43_PFE_LLD_WriteMii (Eth_43_PFE_LLD_WriteMii, funcdef_no=119, decl_uid=11320, cgraph_uid=120, symbol_order=139)

Modification phase of node Eth_43_PFE_LLD_WriteMii/139
Eth_43_PFE_LLD_WriteMii (uint8 u8CtrlIdx, uint8 u8TrcvIdx, uint8 u8RegIdx, uint16 u16RegVal)
{
  pfe_ct_phy_if_id_t emac_id;
  uint32 u32Key;
  struct pfe_emac_t * prEmac;
  Std_ReturnType RetVal;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.173_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.175_5;
  int _6;
  int _7;
  long unsigned int u32Key.176_8;
  int _9;
  long unsigned int u32Key.177_10;
  int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  u32Key = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.173_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_18(D);
  _3 = Eth_43_PFE_InternalCfgPtr.173_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  emac_id_19 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_19
  # DEBUG BEGIN_STMT
  ptrPlatform.175_5 = ptrPlatform;
  _6 = (int) emac_id_19;
  prEmac_20 = ptrPlatform.175_5->emac[_6];
  # DEBUG prEmac => prEmac_20
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_mdio_lock (prEmac_20, &u32Key);
  if (_7 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Lock the MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4085, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key.176_8 = u32Key;
  _9 = pfe_emac_mdio_write22 (prEmac_20, u8TrcvIdx_24(D), u8RegIdx_25(D), u16RegVal_26(D), u32Key.176_8);
  if (_9 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 108662672]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0

  <bb 7> [local count: 217325345]:
  # RetVal_12 = PHI <1(5), 0(6)>
  # DEBUG RetVal => RetVal_12
  # DEBUG BEGIN_STMT
  u32Key.177_10 = u32Key;
  _11 = pfe_emac_mdio_unlock (prEmac_20, u32Key.177_10);
  if (_11 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unlock the locked MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4097, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 9> [local count: 1073741824]:
  # RetVal_13 = PHI <1(2), RetVal_12(7), RetVal_12(8)>
  # DEBUG RetVal => RetVal_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key ={v} {CLOBBER};
  return RetVal_13;

}



;; Function Eth_43_PFE_LLD_ReadMii (Eth_43_PFE_LLD_ReadMii, funcdef_no=120, decl_uid=11325, cgraph_uid=121, symbol_order=140)

Modification phase of node Eth_43_PFE_LLD_ReadMii/140
Eth_43_PFE_LLD_ReadMii (uint8 u8CtrlIdx, uint8 u8TrcvIdx, uint8 u8RegIdx, uint16 * pu16RegValPtr)
{
  pfe_ct_phy_if_id_t emac_id;
  uint32 u32Key;
  struct pfe_emac_t * prEmac;
  Std_ReturnType RetVal;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.178_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.180_5;
  int _6;
  int _7;
  long unsigned int u32Key.181_8;
  int _9;
  long unsigned int u32Key.182_10;
  int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  u32Key = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.178_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_18(D);
  _3 = Eth_43_PFE_InternalCfgPtr.178_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  emac_id_19 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_19
  # DEBUG BEGIN_STMT
  ptrPlatform.180_5 = ptrPlatform;
  _6 = (int) emac_id_19;
  prEmac_20 = ptrPlatform.180_5->emac[_6];
  # DEBUG prEmac => prEmac_20
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_mdio_lock (prEmac_20, &u32Key);
  if (_7 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Lock the MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4135, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key.181_8 = u32Key;
  _9 = pfe_emac_mdio_read22 (prEmac_20, u8TrcvIdx_24(D), u8RegIdx_25(D), pu16RegValPtr_26(D), u32Key.181_8);
  if (_9 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 108662672]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0

  <bb 7> [local count: 217325345]:
  # RetVal_12 = PHI <1(5), 0(6)>
  # DEBUG RetVal => RetVal_12
  # DEBUG BEGIN_STMT
  u32Key.182_10 = u32Key;
  _11 = pfe_emac_mdio_unlock (prEmac_20, u32Key.182_10);
  if (_11 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unlock the locked MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4147, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 9> [local count: 1073741824]:
  # RetVal_13 = PHI <1(2), RetVal_12(7), RetVal_12(8)>
  # DEBUG RetVal => RetVal_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key ={v} {CLOBBER};
  return RetVal_13;

}



;; Function Eth_43_PFE_LLD_WriteMii45 (Eth_43_PFE_LLD_WriteMii45, funcdef_no=121, decl_uid=11331, cgraph_uid=122, symbol_order=141)

Modification phase of node Eth_43_PFE_LLD_WriteMii45/141
Eth_43_PFE_LLD_WriteMii45 (uint8 u8CtrlIdx, uint8 u8TrcvIdx, uint8 u8DevIdx, uint16 u16RegIdx, uint16 u16RegVal)
{
  pfe_ct_phy_if_id_t emac_id;
  uint32 u32Key;
  struct pfe_emac_t * prEmac;
  Std_ReturnType RetVal;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.183_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.185_5;
  int _6;
  int _7;
  long unsigned int u32Key.186_8;
  int _9;
  long unsigned int u32Key.187_10;
  int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  u32Key = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.183_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_18(D);
  _3 = Eth_43_PFE_InternalCfgPtr.183_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  emac_id_19 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_19
  # DEBUG BEGIN_STMT
  ptrPlatform.185_5 = ptrPlatform;
  _6 = (int) emac_id_19;
  prEmac_20 = ptrPlatform.185_5->emac[_6];
  # DEBUG prEmac => prEmac_20
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_mdio_lock (prEmac_20, &u32Key);
  if (_7 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Lock the MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4189, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key.186_8 = u32Key;
  _9 = pfe_emac_mdio_write45 (prEmac_20, u8TrcvIdx_24(D), u8DevIdx_25(D), u16RegIdx_26(D), u16RegVal_27(D), u32Key.186_8);
  if (_9 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 108662672]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0

  <bb 7> [local count: 217325345]:
  # RetVal_12 = PHI <1(5), 0(6)>
  # DEBUG RetVal => RetVal_12
  # DEBUG BEGIN_STMT
  u32Key.187_10 = u32Key;
  _11 = pfe_emac_mdio_unlock (prEmac_20, u32Key.187_10);
  if (_11 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unlock the locked MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4201, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 9> [local count: 1073741824]:
  # RetVal_13 = PHI <1(2), RetVal_12(7), RetVal_12(8)>
  # DEBUG RetVal => RetVal_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key ={v} {CLOBBER};
  return RetVal_13;

}



;; Function Eth_43_PFE_LLD_ReadMii45 (Eth_43_PFE_LLD_ReadMii45, funcdef_no=122, decl_uid=11337, cgraph_uid=123, symbol_order=142)

Modification phase of node Eth_43_PFE_LLD_ReadMii45/142
Eth_43_PFE_LLD_ReadMii45 (uint8 u8CtrlIdx, uint8 u8TrcvIdx, uint8 u8DevIdx, uint16 u16RegIdx, uint16 * pu16RegValPtr)
{
  pfe_ct_phy_if_id_t emac_id;
  uint32 u32Key;
  struct pfe_emac_t * prEmac;
  Std_ReturnType RetVal;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.188_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.190_5;
  int _6;
  int _7;
  long unsigned int u32Key.191_8;
  int _9;
  long unsigned int u32Key.192_10;
  int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  u32Key = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.188_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_18(D);
  _3 = Eth_43_PFE_InternalCfgPtr.188_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  emac_id_19 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_19
  # DEBUG BEGIN_STMT
  ptrPlatform.190_5 = ptrPlatform;
  _6 = (int) emac_id_19;
  prEmac_20 = ptrPlatform.190_5->emac[_6];
  # DEBUG prEmac => prEmac_20
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_mdio_lock (prEmac_20, &u32Key);
  if (_7 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Lock the MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4241, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key.191_8 = u32Key;
  _9 = pfe_emac_mdio_read45 (prEmac_20, u8TrcvIdx_24(D), u8DevIdx_25(D), u16RegIdx_26(D), pu16RegValPtr_27(D), u32Key.191_8);
  if (_9 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 108662672]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0

  <bb 7> [local count: 217325345]:
  # RetVal_12 = PHI <1(5), 0(6)>
  # DEBUG RetVal => RetVal_12
  # DEBUG BEGIN_STMT
  u32Key.192_10 = u32Key;
  _11 = pfe_emac_mdio_unlock (prEmac_20, u32Key.192_10);
  if (_11 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 71717364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unlock the locked MDIO bus failed\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4253, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 9> [local count: 1073741824]:
  # RetVal_13 = PHI <1(2), RetVal_12(7), RetVal_12(8)>
  # DEBUG RetVal => RetVal_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u32Key ={v} {CLOBBER};
  return RetVal_13;

}



;; Function Eth_43_PFE_LLD_SetGlobalTime (Eth_43_PFE_LLD_SetGlobalTime, funcdef_no=123, decl_uid=11340, cgraph_uid=124, symbol_order=143)

Modification phase of node Eth_43_PFE_LLD_SetGlobalTime/143
Eth_43_PFE_LLD_SetGlobalTime (uint8 u8CtrlIdx, const struct Eth_TimeStampType * pTimeStampPtr)
{
  pfe_ct_phy_if_id_t emac_id;
  struct pfe_emac_t * prEmac;
  Std_ReturnType RetVal;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.193_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.195_5;
  int _6;
  long unsigned int _7;
  long unsigned int _8;
  short unsigned int _9;
  int _10;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.193_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_14(D);
  _3 = Eth_43_PFE_InternalCfgPtr.193_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  emac_id_15 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_15
  # DEBUG BEGIN_STMT
  ptrPlatform.195_5 = ptrPlatform;
  _6 = (int) emac_id_15;
  prEmac_16 = ptrPlatform.195_5->emac[_6];
  # DEBUG prEmac => prEmac_16
  # DEBUG BEGIN_STMT
  _7 = pTimeStampPtr_17(D)->seconds;
  _8 = pTimeStampPtr_17(D)->nanoseconds;
  _9 = pTimeStampPtr_17(D)->secondsHi;
  _10 = pfe_emac_set_ts_time (prEmac_16, _7, _8, _9);
  if (_10 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 108662672]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0

  <bb 5> [local count: 1073741824]:
  # RetVal_11 = PHI <1(2), 1(3), 0(4)>
  # DEBUG RetVal => RetVal_11
  # DEBUG BEGIN_STMT
  return RetVal_11;

}



;; Function Eth_43_PFE_LLD_GetCurrentTime (Eth_43_PFE_LLD_GetCurrentTime, funcdef_no=124, decl_uid=11348, cgraph_uid=125, symbol_order=144)

Modification phase of node Eth_43_PFE_LLD_GetCurrentTime/144
Eth_43_PFE_LLD_GetCurrentTime (uint8 u8CtrlIdx, Eth_TimeStampQualType * timeQualPtr, struct Eth_TimeStampType * timeStampPtr)
{
  pfe_ct_phy_if_id_t emac_id;
  struct pfe_emac_t * prEmac;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.196_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.198_5;
  int _6;
  uint32 * _7;
  uint32 * _8;
  uint16 * _9;
  int _10;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.196_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_13(D);
  _3 = Eth_43_PFE_InternalCfgPtr.196_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  emac_id_14 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_14
  # DEBUG BEGIN_STMT
  ptrPlatform.198_5 = ptrPlatform;
  _6 = (int) emac_id_14;
  prEmac_15 = ptrPlatform.198_5->emac[_6];
  # DEBUG prEmac => prEmac_15
  # DEBUG BEGIN_STMT
  _7 = &timeStampPtr_16(D)->seconds;
  _8 = &timeStampPtr_16(D)->nanoseconds;
  _9 = &timeStampPtr_16(D)->secondsHi;
  _10 = pfe_emac_get_ts_time (prEmac_15, _7, _8, _9);
  if (_10 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 108662672]:
  # DEBUG BEGIN_STMT
  *timeQualPtr_18(D) = 0;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Eth_43_PFE_LLD_SetCorrectionTime (Eth_43_PFE_LLD_SetCorrectionTime, funcdef_no=126, decl_uid=11344, cgraph_uid=127, symbol_order=146)

Modification phase of node Eth_43_PFE_LLD_SetCorrectionTime/146
Eth_43_PFE_LLD_SetCorrectionTime (uint8 u8CtrlIdx, const struct Eth_TimeIntDiffType * pTimeOffsetPtr, const struct Eth_RateRatioType * pRateRatioPtr)
{
  pfe_ct_phy_if_id_t emac_id;
  struct pfe_emac_t * prEmac;
  Std_ReturnType RetVal;
  const struct Eth_43_PFE_ConfigType * Eth_43_PFE_InternalCfgPtr.199_1;
  int _2;
  const struct Eth_43_PFE_CtrlCfgType * _3;
  <unnamed type> _4;
  struct pfe_platform_t * ptrPlatform.201_5;
  int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  _Bool _10;
  unsigned char _11;
  int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Eth_43_PFE_InternalCfgPtr.199_1 = Eth_43_PFE_InternalCfgPtr;
  _2 = (int) u8CtrlIdx_16(D);
  _3 = Eth_43_PFE_InternalCfgPtr.199_1->pController[_2];
  _4 = _3->EthCtrlType;
  if (_4 == 2)
    goto <bb 3>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  emac_id_17 = _3->EthCtrlPhyIfID;
  # DEBUG emac_id => emac_id_17
  # DEBUG BEGIN_STMT
  ptrPlatform.201_5 = ptrPlatform;
  _6 = (int) emac_id_17;
  prEmac_18 = ptrPlatform.201_5->emac[_6];
  # DEBUG prEmac => prEmac_18
  # DEBUG BEGIN_STMT
  _7 = pTimeOffsetPtr_19(D)->diff.seconds;
  if (_7 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 4> [local count: 244598388]:
  _8 = pTimeOffsetPtr_19(D)->diff.nanoseconds;
  if (_8 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 6> [local count: 242773027]:
  # DEBUG BEGIN_STMT
  _9 = pTimeOffsetPtr_19(D)->diff.nanoseconds;
  _10 = pTimeOffsetPtr_19(D)->sign;
  _11 = (unsigned char) _10;
  _12 = pfe_emac_adjust_ts_time (prEmac_18, _7, _9, _11);
  if (_12 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 243685707]:
  # DEBUG RetVal => NULL
  # DEBUG BEGIN_STMT
  RetVal_23 = EmacTsAdjustRatio (u8CtrlIdx_16(D), prEmac_18, pRateRatioPtr_21(D));
  # DEBUG RetVal => RetVal_23

  <bb 10> [local count: 1073741824]:
  # RetVal_13 = PHI <RetVal_23(9), 1(2), 1(6)>
  # DEBUG RetVal => RetVal_13
  # DEBUG BEGIN_STMT
  return RetVal_13;

}



;; Function Eth_43_PFE_LLD_EnableEgressTimeStamp (Eth_43_PFE_LLD_EnableEgressTimeStamp, funcdef_no=127, decl_uid=11361, cgraph_uid=128, symbol_order=147)

Modification phase of node Eth_43_PFE_LLD_EnableEgressTimeStamp/147
Eth_43_PFE_LLD_EnableEgressTimeStamp (uint8 u8CtrlIdx, Eth_BufIdxType BufIdx)
{
  int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG u8CtrlIdx => u8CtrlIdx_2(D)
  # DEBUG BufIdx => BufIdx_3(D)
  # DEBUG INLINE_ENTRY Eth_PFE_LLD_GetTxBufMeta
  # DEBUG BEGIN_STMT
  _4 = (int) u8CtrlIdx_2(D);
  # DEBUG D#35 => &aarTxBuf[_4][BufIdx_3(D)].rMeta
  # DEBUG u8CtrlIdx => NULL
  # DEBUG BufIdx => NULL
  # DEBUG prTxMeta => D#35
  # DEBUG BEGIN_STMT
  MEM[(struct trTxMeta *)&aarTxBuf][_4][BufIdx_3(D)].rMeta.bDoTS = 1;
  return;

}



;; Function Eth_43_PFE_LLD_GetRxTimeStamp (Eth_43_PFE_LLD_GetRxTimeStamp, funcdef_no=128, decl_uid=11353, cgraph_uid=129, symbol_order=148)

Modification phase of node Eth_43_PFE_LLD_GetRxTimeStamp/148
Eth_43_PFE_LLD_GetRxTimeStamp (uint8 u8CtrlIdx, const Eth_DataType * DataPtr, Eth_TimeStampQualType * timeQualPtr, struct Eth_TimeStampType * timeStampPtr)
{
  uint16 PtpSeqId;
  uint16 PtpSrcPortId;
  uint8 PtpMsgType;
  errno_t RetVal;
  struct oal_util_ptp_header_t * pu8PtpHead;
  int _1;
  struct pfe_hif_drv_client_t * _2;
  uint8 * _3;
  int _4;
  struct oal_util_ptp_header_t * pu8PtpHead.202_5;
  <unnamed-unsigned:4> _6;
  short unsigned int _7;
  short unsigned int _8;
  struct pfe_hif_drv_client_t * _9;
  uint32 * _10;
  uint32 * _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG pu8Packet => DataPtr_15(D)
  # DEBUG BEGIN_STMT
  pu8PtpHead = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 2
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_18(D);
  _2 = arPfeInterface[_1].prClient;
  if (_2 != 0B)
    goto <bb 3>; [68.09%]
  else
    goto <bb 10>; [31.91%]

  <bb 3> [local count: 731110809]:
  # DEBUG BEGIN_STMT
  _3 = DataPtr_15(D) + 4294967282;
  _4 = oal_util_parse_ptp (_3, 106, &pu8PtpHead);
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 365555404]:
  # DEBUG BEGIN_STMT
  pu8PtpHead = 0B;

  <bb 5> [local count: 731110809]:
  # DEBUG BEGIN_STMT
  pu8PtpHead.202_5 = pu8PtpHead;
  if (pu8PtpHead.202_5 == 0B)
    goto <bb 6>; [18.75%]
  else
    goto <bb 7>; [81.25%]

  <bb 6> [local count: 137083277]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unrecognized PTP frame\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4447, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *timeQualPtr_27(D) = 1;
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 594027532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = pu8PtpHead.202_5->byte1.messageType;
  PtpMsgType_21 = (uint8) _6;
  # DEBUG PtpMsgType => PtpMsgType_21
  # DEBUG BEGIN_STMT
  _7 = pu8PtpHead.202_5->sourcePortID;
  PtpSrcPortId_22 = _7 r>> 8;
  # DEBUG PtpSrcPortId => PtpSrcPortId_22
  # DEBUG BEGIN_STMT
  _8 = pu8PtpHead.202_5->sequenceID;
  PtpSeqId_23 = _8 r>> 8;
  # DEBUG PtpSeqId => PtpSeqId_23
  # DEBUG BEGIN_STMT
  _9 = arPfeInterface[_1].prClient;
  _10 = &timeStampPtr_24(D)->seconds;
  _11 = &timeStampPtr_24(D)->nanoseconds;
  RetVal_26 = pfe_hif_drv_client_get_ts (_9, 1, PtpMsgType_21, PtpSrcPortId_22, PtpSeqId_23, _10, _11);
  # DEBUG RetVal => RetVal_26
  # DEBUG BEGIN_STMT
  if (RetVal_26 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 297013766]:
  # DEBUG BEGIN_STMT
  timeStampPtr_24(D)->secondsHi = 0;
  # DEBUG BEGIN_STMT
  *timeQualPtr_27(D) = 0;
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 297013766]:
  # DEBUG BEGIN_STMT
  *timeQualPtr_27(D) = 1;

  <bb 10> [local count: 1073741824]:
  # RetVal_12 = PHI <2(2), 2(6), 0(8), RetVal_26(9)>
  # DEBUG RetVal => RetVal_12
  # DEBUG BEGIN_STMT
  pu8PtpHead ={v} {CLOBBER};
  return RetVal_12;

}



;; Function Eth_43_PFE_LLD_GetTxTimeStamp (Eth_43_PFE_LLD_GetTxTimeStamp, funcdef_no=129, decl_uid=11358, cgraph_uid=130, symbol_order=149)

Modification phase of node Eth_43_PFE_LLD_GetTxTimeStamp/149
Eth_43_PFE_LLD_GetTxTimeStamp (uint8 u8CtrlIdx, Eth_BufIdxType BufIdx, Eth_TimeStampQualType * timeQualPtr, struct Eth_TimeStampType * timeStampPtr)
{
  int _1;
  <unnamed type> _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8CtrlIdx_3(D);
  _2 = aarTxBuf[_1][BufIdx_5(D)].TimeQual;
  *timeQualPtr_6(D) = _2;
  # DEBUG BEGIN_STMT
  *timeStampPtr_8(D) = aarTxBuf[_1][BufIdx_5(D)].TimeStamp;
  return;

}



;; Function Eth_PFE_LLD_GetPlatform (Eth_PFE_LLD_GetPlatform, funcdef_no=130, decl_uid=11363, cgraph_uid=131, symbol_order=150)

Modification phase of node Eth_PFE_LLD_GetPlatform/150
Eth_PFE_LLD_GetPlatform ()
{
  void * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = ptrPlatform;
  return _2;

}



;; Function Eth_43_PFE_LLD_GetClassStats (Eth_43_PFE_LLD_GetClassStats, funcdef_no=131, decl_uid=11365, cgraph_uid=132, symbol_order=151)

Modification phase of node Eth_43_PFE_LLD_GetClassStats/151
Eth_43_PFE_LLD_GetClassStats (struct pfe_ct_classify_stats_t * stat)
{
  Std_ReturnType retVal;
  struct pfe_platform_t * ptrPlatform.206_1;
  struct pfe_class_t * _2;
  int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  ptrPlatform.206_1 = ptrPlatform;
  if (ptrPlatform.206_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = ptrPlatform.206_1->classifier;
  _3 = pfe_class_get_stats (_2, stat_7(D));
  if (_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 287064877]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 0

  <bb 5> [local count: 1073741824]:
  # retVal_4 = PHI <1(2), 1(3), 0(4)>
  # DEBUG retVal => retVal_4
  # DEBUG BEGIN_STMT
  return retVal_4;

}



;; Function Eth_43_PFE_LLD_GetBmuStats (Eth_43_PFE_LLD_GetBmuStats, funcdef_no=132, decl_uid=11384, cgraph_uid=133, symbol_order=152)

Modification phase of node Eth_43_PFE_LLD_GetBmuStats/152
Eth_43_PFE_LLD_GetBmuStats (uint8 u8BmuIndex, struct Eth_43_PFE_BmuStatsType * stat)
{
  struct pfe_bmu_stats_special_t special_stats;
  uint32 reg_value;
  uint8 i;
  Std_ReturnType retVal;
  struct pfe_platform_t * ptrPlatform.208_1;
  _Bool _2;
  long int _3;
  long int _4;
  int _5;
  struct pfe_bmu_t * _6;
  long unsigned int _7;
  struct pfe_platform_t * ptrPlatform.210_8;
  struct pfe_bmu_t * _9;
  long unsigned int _10;
  struct pfe_platform_t * ptrPlatform.211_11;
  struct pfe_bmu_t * _12;
  long unsigned int _13;
  struct pfe_platform_t * ptrPlatform.212_14;
  struct pfe_bmu_t * _15;
  long unsigned int _16;
  struct pfe_platform_t * ptrPlatform.213_17;
  struct pfe_bmu_t * _18;
  long unsigned int _19;
  struct pfe_platform_t * ptrPlatform.214_20;
  struct pfe_bmu_t * _21;
  long unsigned int _22;
  struct pfe_platform_t * ptrPlatform.215_23;
  struct pfe_bmu_t * _24;
  long unsigned int _25;
  long unsigned int _26;
  struct pfe_platform_t * ptrPlatform.216_27;
  struct pfe_bmu_t * _28;
  long unsigned int _29;
  struct pfe_platform_t * ptrPlatform.217_30;
  struct pfe_bmu_t * _31;
  long unsigned int _32;
  struct pfe_platform_t * ptrPlatform.218_33;
  struct pfe_bmu_t * _34;
  long unsigned int _35;
  struct pfe_platform_t * ptrPlatform.219_36;
  struct pfe_bmu_t * _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  int _41;
  struct pfe_platform_t * ptrPlatform.221_42;
  struct pfe_bmu_t * _43;
  int _44;
  long unsigned int _45;
  long unsigned int _46;
  long unsigned int _47;
  long unsigned int _48;
  long unsigned int _49;
  long unsigned int _50;

  <bb 2> [local count: 51641870]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  special_stats = {};
  # DEBUG BEGIN_STMT
  ptrPlatform.208_1 = ptrPlatform;
  if (ptrPlatform.208_1 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 12>; [30.00%]

  <bb 3> [local count: 36149309]:
  # DEBUG BEGIN_STMT
  _2 = u8BmuIndex_57(D) > 1;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 0);
  if (_4 != 0)
    goto <bb 4>; [10.00%]
  else
    goto <bb 5>; [90.00%]

  <bb 4> [local count: 3614931]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] BMU index out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4545, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 5> [local count: 32534378]:
  # DEBUG BEGIN_STMT
  _5 = (int) u8BmuIndex_57(D);
  _6 = ptrPlatform.208_1->bmu[_5];
  _7 = pfe_bmu_get_stat_value (_6, 224);
  stat_59(D)->bmu_debug_bus = _7;
  # DEBUG BEGIN_STMT
  ptrPlatform.210_8 = ptrPlatform;
  _9 = ptrPlatform.210_8->bmu[_5];
  _10 = pfe_bmu_get_stat_value (_9, 12);
  stat_59(D)->buff_base = _10;
  # DEBUG BEGIN_STMT
  ptrPlatform.211_11 = ptrPlatform;
  _12 = ptrPlatform.211_11->bmu[_5];
  _13 = pfe_bmu_get_stat_value (_12, 72);
  stat_59(D)->buff_remain = _13;
  # DEBUG BEGIN_STMT
  ptrPlatform.212_14 = ptrPlatform;
  _15 = ptrPlatform.212_14->bmu[_5];
  _16 = pfe_bmu_get_stat_value (_15, 60);
  stat_59(D)->buff_allocated = _16;
  # DEBUG BEGIN_STMT
  ptrPlatform.213_17 = ptrPlatform;
  _18 = ptrPlatform.213_17->bmu[_5];
  _19 = pfe_bmu_get_stat_value (_18, 80);
  stat_59(D)->low_watermark = _19;
  # DEBUG BEGIN_STMT
  ptrPlatform.214_20 = ptrPlatform;
  _21 = ptrPlatform.214_20->bmu[_5];
  _22 = pfe_bmu_get_stat_value (_21, 84);
  stat_59(D)->high_watermark = _22;
  # DEBUG BEGIN_STMT
  ptrPlatform.215_23 = ptrPlatform;
  _24 = ptrPlatform.215_23->bmu[_5];
  _25 = pfe_bmu_get_stat_value (_24, 24);
  _26 = _25 & 65535;
  stat_59(D)->irq_threshold = _26;
  # DEBUG BEGIN_STMT
  ptrPlatform.216_27 = ptrPlatform;
  _28 = ptrPlatform.216_27->bmu[_5];
  _29 = pfe_bmu_get_stat_value (_28, 56);
  stat_59(D)->free_error_add = _29;
  # DEBUG BEGIN_STMT
  ptrPlatform.217_30 = ptrPlatform;
  _31 = ptrPlatform.217_30->bmu[_5];
  _32 = pfe_bmu_get_stat_value (_31, 32);
  stat_59(D)->irq_source = _32;
  # DEBUG BEGIN_STMT
  ptrPlatform.218_33 = ptrPlatform;
  _34 = ptrPlatform.218_33->bmu[_5];
  _35 = pfe_bmu_get_stat_value (_34, 36);
  stat_59(D)->irq_enable = _35;
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 1041207449]:
  # DEBUG BEGIN_STMT
  ptrPlatform.219_36 = ptrPlatform;
  _37 = ptrPlatform.219_36->bmu[_5];
  _38 = (long unsigned int) i_52;
  _39 = _38 + 24;
  _40 = _39 * 4;
  reg_value_93 = pfe_bmu_get_stat_value (_37, _40);
  # DEBUG reg_value => reg_value_93
  # DEBUG BEGIN_STMT
  _41 = (int) i_52;
  stat_59(D)->master_buf_count[_41] = reg_value_93;
  # DEBUG BEGIN_STMT
  i_95 = i_52 + 1;
  # DEBUG i => i_95

  <bb 7> [local count: 1073741824]:
  # i_52 = PHI <0(5), i_95(6)>
  # DEBUG i => i_52
  # DEBUG BEGIN_STMT
  if (i_52 != 32)
    goto <bb 6>; [96.97%]
  else
    goto <bb 8>; [3.03%]

  <bb 8> [local count: 32534377]:
  # DEBUG BEGIN_STMT
  ptrPlatform.221_42 = ptrPlatform;
  _43 = ptrPlatform.221_42->bmu[_5];
  _44 = pfe_bmu_get_special_stats (_43, &special_stats);
  if (_44 == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 16267189]:
  # DEBUG BEGIN_STMT
  _45 = special_stats.revision;
  stat_59(D)->revision = _45;
  # DEBUG BEGIN_STMT
  _46 = special_stats.version;
  stat_59(D)->version = _46;
  # DEBUG BEGIN_STMT
  _47 = special_stats.id;
  stat_59(D)->id = _47;
  # DEBUG BEGIN_STMT
  _48 = special_stats.free_error_cnt;
  stat_59(D)->free_error_cnt = _48;
  # DEBUG BEGIN_STMT
  _49 = special_stats.active_buff;
  stat_59(D)->active_buff = _49;
  # DEBUG BEGIN_STMT
  _50 = special_stats.buff_size;
  stat_59(D)->buff_size = _50;
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 16267189]:
  # DEBUG BEGIN_STMT
  stat_59(D)->revision = 4294967295;
  # DEBUG BEGIN_STMT
  stat_59(D)->version = 4294967295;
  # DEBUG BEGIN_STMT
  stat_59(D)->id = 4294967295;
  # DEBUG BEGIN_STMT
  stat_59(D)->free_error_cnt = 4294967295;
  # DEBUG BEGIN_STMT
  stat_59(D)->active_buff = 4294967295;
  # DEBUG BEGIN_STMT
  stat_59(D)->buff_size = 4294967295;

  <bb 12> [local count: 51641869]:
  # retVal_51 = PHI <1(2), 1(4), 0(10), 0(9)>
  # DEBUG retVal => retVal_51
  # DEBUG BEGIN_STMT
  special_stats ={v} {CLOBBER};
  return retVal_51;

}



;; Function Eth_43_PFE_LLD_GetGpiStats (Eth_43_PFE_LLD_GetGpiStats, funcdef_no=133, decl_uid=11381, cgraph_uid=134, symbol_order=153)

Modification phase of node Eth_43_PFE_LLD_GetGpiStats/153
Eth_43_PFE_LLD_GetGpiStats (uint8 u8GpiIndex, struct Eth_43_PFE_GpiStatsType * stat)
{
  struct pfe_gpi_special_stats_t special_stats;
  Std_ReturnType retVal;
  struct pfe_platform_t * ptrPlatform.222_1;
  _Bool _2;
  long int _3;
  long int _4;
  int _5;
  struct pfe_gpi_t * _6;
  long unsigned int _7;
  struct pfe_platform_t * ptrPlatform.224_8;
  struct pfe_gpi_t * _9;
  long unsigned int _10;
  struct pfe_platform_t * ptrPlatform.225_11;
  struct pfe_gpi_t * _12;
  long unsigned int _13;
  struct pfe_platform_t * ptrPlatform.226_14;
  struct pfe_gpi_t * _15;
  long unsigned int _16;
  struct pfe_platform_t * ptrPlatform.227_17;
  struct pfe_gpi_t * _18;
  long unsigned int _19;
  struct pfe_platform_t * ptrPlatform.228_20;
  struct pfe_gpi_t * _21;
  long unsigned int _22;
  struct pfe_platform_t * ptrPlatform.229_23;
  struct pfe_gpi_t * _24;
  long unsigned int _25;
  struct pfe_platform_t * ptrPlatform.230_26;
  struct pfe_gpi_t * _27;
  long unsigned int _28;
  struct pfe_platform_t * ptrPlatform.231_29;
  struct pfe_gpi_t * _30;
  long unsigned int _31;
  struct pfe_platform_t * ptrPlatform.232_32;
  struct pfe_gpi_t * _33;
  long unsigned int _34;
  struct pfe_platform_t * ptrPlatform.233_35;
  struct pfe_gpi_t * _36;
  long unsigned int _37;
  struct pfe_platform_t * ptrPlatform.234_38;
  struct pfe_gpi_t * _39;
  long unsigned int _40;
  struct pfe_platform_t * ptrPlatform.235_41;
  struct pfe_gpi_t * _42;
  long unsigned int _43;
  struct pfe_platform_t * ptrPlatform.236_44;
  struct pfe_gpi_t * _45;
  long unsigned int _46;
  struct pfe_platform_t * ptrPlatform.237_47;
  struct pfe_gpi_t * _48;
  long unsigned int _49;
  struct pfe_platform_t * ptrPlatform.238_50;
  struct pfe_gpi_t * _51;
  uint32_t * _52;
  int _53;
  struct pfe_platform_t * ptrPlatform.239_54;
  struct pfe_gpi_t * _55;
  uint32_t * _56;
  int _57;
  struct pfe_platform_t * ptrPlatform.240_58;
  struct pfe_gpi_t * _59;
  long unsigned int _60;
  struct pfe_platform_t * ptrPlatform.241_61;
  struct pfe_gpi_t * _62;
  long unsigned int _63;
  struct pfe_platform_t * ptrPlatform.242_64;
  struct pfe_gpi_t * _65;
  long unsigned int _66;
  struct pfe_platform_t * ptrPlatform.243_67;
  struct pfe_gpi_t * _68;
  long unsigned int _69;
  struct pfe_platform_t * ptrPlatform.244_70;
  struct pfe_gpi_t * _71;
  long unsigned int _72;
  struct pfe_platform_t * ptrPlatform.245_73;
  struct pfe_gpi_t * _74;
  long unsigned int _75;
  struct pfe_platform_t * ptrPlatform.246_76;
  struct pfe_gpi_t * _77;
  long unsigned int _78;
  struct pfe_platform_t * ptrPlatform.247_79;
  struct pfe_gpi_t * _80;
  int _81;
  long unsigned int _82;
  long unsigned int _83;
  long unsigned int _84;
  long unsigned int _85;
  long unsigned int _86;
  long unsigned int _87;
  long unsigned int _88;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  special_stats = {};
  # DEBUG BEGIN_STMT
  ptrPlatform.222_1 = ptrPlatform;
  if (ptrPlatform.222_1 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 13>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _2 = u8GpiIndex_95(D) > 2;
  _3 = (long int) _2;
  _4 = __builtin_expect (_3, 0);
  if (_4 != 0)
    goto <bb 4>; [10.00%]
  else
    goto <bb 5>; [90.00%]

  <bb 4> [local count: 75161928]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Gpi index out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4606, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 5> [local count: 676457350]:
  # DEBUG BEGIN_STMT
  _5 = (int) u8GpiIndex_95(D);
  _6 = ptrPlatform.222_1->gpi[_5];
  _7 = pfe_gpi_get_stat_value (_6, 88);
  stat_97(D)->fifo_debug = _7;
  # DEBUG BEGIN_STMT
  ptrPlatform.224_8 = ptrPlatform;
  _9 = ptrPlatform.224_8->gpi[_5];
  _10 = pfe_gpi_get_stat_value (_9, 112);
  stat_97(D)->tx_debug_reg1 = _10;
  # DEBUG BEGIN_STMT
  ptrPlatform.225_11 = ptrPlatform;
  _12 = ptrPlatform.225_11->gpi[_5];
  _13 = pfe_gpi_get_stat_value (_12, 116);
  stat_97(D)->tx_debug_reg2 = _13;
  # DEBUG BEGIN_STMT
  ptrPlatform.226_14 = ptrPlatform;
  _15 = ptrPlatform.226_14->gpi[_5];
  _16 = pfe_gpi_get_stat_value (_15, 120);
  stat_97(D)->tx_debug_reg3 = _16;
  # DEBUG BEGIN_STMT
  ptrPlatform.227_17 = ptrPlatform;
  _18 = ptrPlatform.227_17->gpi[_5];
  _19 = pfe_gpi_get_stat_value (_18, 124);
  stat_97(D)->tx_debug_reg4 = _19;
  # DEBUG BEGIN_STMT
  ptrPlatform.228_20 = ptrPlatform;
  _21 = ptrPlatform.228_20->gpi[_5];
  _22 = pfe_gpi_get_stat_value (_21, 128);
  stat_97(D)->tx_debug_reg5 = _22;
  # DEBUG BEGIN_STMT
  ptrPlatform.229_23 = ptrPlatform;
  _24 = ptrPlatform.229_23->gpi[_5];
  _25 = pfe_gpi_get_stat_value (_24, 132);
  stat_97(D)->tx_debug_reg6 = _25;
  # DEBUG BEGIN_STMT
  ptrPlatform.230_26 = ptrPlatform;
  _27 = ptrPlatform.230_26->gpi[_5];
  _28 = pfe_gpi_get_stat_value (_27, 144);
  stat_97(D)->rx_debug_reg1 = _28;
  # DEBUG BEGIN_STMT
  ptrPlatform.231_29 = ptrPlatform;
  _30 = ptrPlatform.231_29->gpi[_5];
  _31 = pfe_gpi_get_stat_value (_30, 148);
  stat_97(D)->rx_debug_reg2 = _31;
  # DEBUG BEGIN_STMT
  ptrPlatform.232_32 = ptrPlatform;
  _33 = ptrPlatform.232_32->gpi[_5];
  _34 = pfe_gpi_get_stat_value (_33, 84);
  stat_97(D)->fifo_status = _34;
  # DEBUG BEGIN_STMT
  ptrPlatform.233_35 = ptrPlatform;
  _36 = ptrPlatform.233_35->gpi[_5];
  _37 = pfe_gpi_get_stat_value (_36, 424);
  stat_97(D)->iqos_queue_status = _37;
  # DEBUG BEGIN_STMT
  ptrPlatform.234_38 = ptrPlatform;
  _39 = ptrPlatform.234_38->gpi[_5];
  _40 = pfe_gpi_get_stat_value (_39, 428);
  stat_97(D)->iqos_class_drop_cnt = _40;
  # DEBUG BEGIN_STMT
  ptrPlatform.235_41 = ptrPlatform;
  _42 = ptrPlatform.235_41->gpi[_5];
  _43 = pfe_gpi_get_stat_value (_42, 432);
  stat_97(D)->iqos_lmem_drop_cnt = _43;
  # DEBUG BEGIN_STMT
  ptrPlatform.236_44 = ptrPlatform;
  _45 = ptrPlatform.236_44->gpi[_5];
  _46 = pfe_gpi_get_stat_value (_45, 436);
  stat_97(D)->iqos_dmem_drop_cnt = _46;
  # DEBUG BEGIN_STMT
  ptrPlatform.237_47 = ptrPlatform;
  _48 = ptrPlatform.237_47->gpi[_5];
  _49 = pfe_gpi_get_stat_value (_48, 440);
  stat_97(D)->iqos_rxf_drop_cnt = _49;
  # DEBUG BEGIN_STMT
  ptrPlatform.238_50 = ptrPlatform;
  _51 = ptrPlatform.238_50->gpi[_5];
  _52 = &stat_97(D)->iqos_shp0_drop_cnt;
  _53 = pfe_gpi_shp_get_drop_cnt (_51, 0, _52);
  if (_53 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 338228675]:
  # DEBUG BEGIN_STMT
  stat_97(D)->iqos_shp0_drop_cnt = 4294967295;

  <bb 7> [local count: 676457350]:
  # DEBUG BEGIN_STMT
  ptrPlatform.239_54 = ptrPlatform;
  _55 = ptrPlatform.239_54->gpi[_5];
  _56 = &stat_97(D)->iqos_shp1_drop_cnt;
  _57 = pfe_gpi_shp_get_drop_cnt (_55, 1, _56);
  if (_57 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 338228675]:
  # DEBUG BEGIN_STMT
  stat_97(D)->iqos_shp1_drop_cnt = 4294967295;

  <bb 9> [local count: 676457350]:
  # DEBUG BEGIN_STMT
  ptrPlatform.240_58 = ptrPlatform;
  _59 = ptrPlatform.240_58->gpi[_5];
  _60 = pfe_gpi_get_stat_value (_59, 452);
  stat_97(D)->iqos_manage_pkts = _60;
  # DEBUG BEGIN_STMT
  ptrPlatform.241_61 = ptrPlatform;
  _62 = ptrPlatform.241_61->gpi[_5];
  _63 = pfe_gpi_get_stat_value (_62, 456);
  stat_97(D)->iqos_unmanage_pkts = _63;
  # DEBUG BEGIN_STMT
  ptrPlatform.242_64 = ptrPlatform;
  _65 = ptrPlatform.242_64->gpi[_5];
  _66 = pfe_gpi_get_stat_value (_65, 460);
  stat_97(D)->iqos_reserved_pkts = _66;
  # DEBUG BEGIN_STMT
  ptrPlatform.243_67 = ptrPlatform;
  _68 = ptrPlatform.243_67->gpi[_5];
  _69 = pfe_gpi_get_stat_value (_68, 84);
  stat_97(D)->tx_underrun = _69;
  # DEBUG BEGIN_STMT
  ptrPlatform.244_70 = ptrPlatform;
  _71 = ptrPlatform.244_70->gpi[_5];
  _72 = pfe_gpi_get_stat_value (_71, 80);
  stat_97(D)->aseq_length = _72;
  # DEBUG BEGIN_STMT
  ptrPlatform.245_73 = ptrPlatform;
  _74 = ptrPlatform.245_73->gpi[_5];
  _75 = pfe_gpi_get_stat_value (_74, 316);
  stat_97(D)->enable_reg_1588 = _75;
  # DEBUG BEGIN_STMT
  ptrPlatform.246_76 = ptrPlatform;
  _77 = ptrPlatform.246_76->gpi[_5];
  _78 = pfe_gpi_get_stat_value (_77, 108);
  stat_97(D)->overrun_drop_cnt = _78;
  # DEBUG BEGIN_STMT
  ptrPlatform.247_79 = ptrPlatform;
  _80 = ptrPlatform.247_79->gpi[_5];
  _81 = pfe_gpi_get_special_stats (_80, &special_stats);
  if (_81 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 338228675]:
  # DEBUG BEGIN_STMT
  _82 = special_stats.revision;
  stat_97(D)->revision = _82;
  # DEBUG BEGIN_STMT
  _83 = special_stats.version;
  stat_97(D)->version = _83;
  # DEBUG BEGIN_STMT
  _84 = special_stats.id;
  stat_97(D)->id = _84;
  # DEBUG BEGIN_STMT
  _85 = special_stats.tx_fifo_packets;
  stat_97(D)->tx_fifo_packets = _85;
  # DEBUG BEGIN_STMT
  _86 = special_stats.rx_fifo_packets;
  stat_97(D)->rx_fifo_packets = _86;
  # DEBUG BEGIN_STMT
  _87 = special_stats.tx_fifo_level;
  stat_97(D)->tx_fifo_level = _87;
  # DEBUG BEGIN_STMT
  _88 = special_stats.rx_fifo_level;
  stat_97(D)->rx_fifo_level = _88;
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 338228675]:
  # DEBUG BEGIN_STMT
  stat_97(D)->revision = 4294967295;
  # DEBUG BEGIN_STMT
  stat_97(D)->version = 4294967295;
  # DEBUG BEGIN_STMT
  stat_97(D)->id = 4294967295;
  # DEBUG BEGIN_STMT
  stat_97(D)->tx_fifo_packets = 4294967295;
  # DEBUG BEGIN_STMT
  stat_97(D)->rx_fifo_packets = 4294967295;
  # DEBUG BEGIN_STMT
  stat_97(D)->tx_fifo_level = 4294967295;
  # DEBUG BEGIN_STMT
  stat_97(D)->rx_fifo_level = 4294967295;

  <bb 13> [local count: 1073741824]:
  # retVal_89 = PHI <1(2), 1(4), 0(11), 0(10)>
  # DEBUG retVal => retVal_89
  # DEBUG BEGIN_STMT
  special_stats ={v} {CLOBBER};
  return retVal_89;

}



;; Function Eth_43_PFE_LLD_GetWdtStats (Eth_43_PFE_LLD_GetWdtStats, funcdef_no=134, decl_uid=11378, cgraph_uid=135, symbol_order=154)

Modification phase of node Eth_43_PFE_LLD_GetWdtStats/154
Eth_43_PFE_LLD_GetWdtStats (struct Eth_43_PFE_WdtStatsType * stat)
{
  Std_ReturnType retVal;
  struct pfe_platform_t * ptrPlatform.248_1;
  struct pfe_wdt_t * _2;
  long unsigned int _3;
  struct pfe_platform_t * ptrPlatform.250_4;
  struct pfe_wdt_t * _5;
  long unsigned int _6;
  struct pfe_platform_t * ptrPlatform.251_7;
  struct pfe_wdt_t * _8;
  long unsigned int _9;
  struct pfe_platform_t * ptrPlatform.252_10;
  struct pfe_wdt_t * _11;
  long unsigned int _12;
  struct pfe_platform_t * ptrPlatform.253_13;
  struct pfe_wdt_t * _14;
  long unsigned int _15;
  struct pfe_platform_t * ptrPlatform.254_16;
  struct pfe_wdt_t * _17;
  long unsigned int _18;
  struct pfe_platform_t * ptrPlatform.255_19;
  struct pfe_wdt_t * _20;
  long unsigned int _21;
  struct pfe_platform_t * ptrPlatform.256_22;
  struct pfe_wdt_t * _23;
  long unsigned int _24;
  struct pfe_platform_t * ptrPlatform.257_25;
  struct pfe_wdt_t * _26;
  long unsigned int _27;
  struct pfe_platform_t * ptrPlatform.258_28;
  struct pfe_wdt_t * _29;
  long unsigned int _30;
  struct pfe_platform_t * ptrPlatform.259_31;
  struct pfe_wdt_t * _32;
  long unsigned int _33;
  struct pfe_platform_t * ptrPlatform.260_34;
  struct pfe_wdt_t * _35;
  long unsigned int _36;
  struct pfe_platform_t * ptrPlatform.261_37;
  struct pfe_wdt_t * _38;
  long unsigned int _39;
  struct pfe_platform_t * ptrPlatform.262_40;
  struct pfe_wdt_t * _41;
  long unsigned int _42;
  struct pfe_platform_t * ptrPlatform.263_43;
  struct pfe_wdt_t * _44;
  long unsigned int _45;
  struct pfe_platform_t * ptrPlatform.264_46;
  struct pfe_wdt_t * _47;
  long unsigned int _48;
  struct pfe_platform_t * ptrPlatform.265_49;
  struct pfe_wdt_t * _50;
  long unsigned int _51;
  struct pfe_platform_t * ptrPlatform.266_52;
  struct pfe_wdt_t * _53;
  long unsigned int _54;
  struct pfe_platform_t * ptrPlatform.267_55;
  struct pfe_wdt_t * _56;
  long unsigned int _57;
  struct pfe_platform_t * ptrPlatform.268_58;
  struct pfe_wdt_t * _59;
  long unsigned int _60;
  struct pfe_platform_t * ptrPlatform.269_61;
  struct pfe_wdt_t * _62;
  long unsigned int _63;
  struct pfe_platform_t * ptrPlatform.270_64;
  struct pfe_wdt_t * _65;
  long unsigned int _66;
  struct pfe_platform_t * ptrPlatform.271_67;
  struct pfe_wdt_t * _68;
  long unsigned int _69;
  struct pfe_platform_t * ptrPlatform.272_70;
  struct pfe_wdt_t * _71;
  long unsigned int _72;
  struct pfe_platform_t * ptrPlatform.273_73;
  struct pfe_wdt_t * _74;
  long unsigned int _75;
  struct pfe_platform_t * ptrPlatform.274_76;
  struct pfe_wdt_t * _77;
  long unsigned int _78;
  struct pfe_platform_t * ptrPlatform.275_79;
  struct pfe_wdt_t * _80;
  long unsigned int _81;
  struct pfe_platform_t * ptrPlatform.276_82;
  struct pfe_wdt_t * _83;
  long unsigned int _84;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  ptrPlatform.248_1 = ptrPlatform;
  if (ptrPlatform.248_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = ptrPlatform.248_1->wdt;
  _3 = pfe_wdt_get_stat_value (_2, 0);
  stat_89(D)->wdp_version = _3;
  # DEBUG BEGIN_STMT
  ptrPlatform.250_4 = ptrPlatform;
  _5 = ptrPlatform.250_4->wdt;
  _6 = pfe_wdt_get_stat_value (_5, 84);
  stat_89(D)->wdt_int_en = _6;
  # DEBUG BEGIN_STMT
  ptrPlatform.251_7 = ptrPlatform;
  _8 = ptrPlatform.251_7->wdt;
  _9 = pfe_wdt_get_stat_value (_8, 88);
  stat_89(D)->class_wdt_int_en = _9;
  # DEBUG BEGIN_STMT
  ptrPlatform.252_10 = ptrPlatform;
  _11 = ptrPlatform.252_10->wdt;
  _12 = pfe_wdt_get_stat_value (_11, 92);
  stat_89(D)->upe_wdt_int_en = _12;
  # DEBUG BEGIN_STMT
  ptrPlatform.253_13 = ptrPlatform;
  _14 = ptrPlatform.253_13->wdt;
  _15 = pfe_wdt_get_stat_value (_14, 96);
  stat_89(D)->hgpi_wdt_int_en = _15;
  # DEBUG BEGIN_STMT
  ptrPlatform.254_16 = ptrPlatform;
  _17 = ptrPlatform.254_16->wdt;
  _18 = pfe_wdt_get_stat_value (_17, 100);
  stat_89(D)->hif_wdt_int_en = _18;
  # DEBUG BEGIN_STMT
  ptrPlatform.255_19 = ptrPlatform;
  _20 = ptrPlatform.255_19->wdt;
  _21 = pfe_wdt_get_stat_value (_20, 104);
  stat_89(D)->tlite_wdt_int_en = _21;
  # DEBUG BEGIN_STMT
  ptrPlatform.256_22 = ptrPlatform;
  _23 = ptrPlatform.256_22->wdt;
  _24 = pfe_wdt_get_stat_value (_23, 108);
  stat_89(D)->hncpy_wdt_int_en = _24;
  # DEBUG BEGIN_STMT
  ptrPlatform.257_25 = ptrPlatform;
  _26 = ptrPlatform.257_25->wdt;
  _27 = pfe_wdt_get_stat_value (_26, 112);
  stat_89(D)->bmu1_wdt_int_en = _27;
  # DEBUG BEGIN_STMT
  ptrPlatform.258_28 = ptrPlatform;
  _29 = ptrPlatform.258_28->wdt;
  _30 = pfe_wdt_get_stat_value (_29, 116);
  stat_89(D)->bmu2_wdt_int_en = _30;
  # DEBUG BEGIN_STMT
  ptrPlatform.259_31 = ptrPlatform;
  _32 = ptrPlatform.259_31->wdt;
  _33 = pfe_wdt_get_stat_value (_32, 120);
  stat_89(D)->emac0_wdt_int_en = _33;
  # DEBUG BEGIN_STMT
  ptrPlatform.260_34 = ptrPlatform;
  _35 = ptrPlatform.260_34->wdt;
  _36 = pfe_wdt_get_stat_value (_35, 124);
  stat_89(D)->emac1_wdt_int_en = _36;
  # DEBUG BEGIN_STMT
  ptrPlatform.261_37 = ptrPlatform;
  _38 = ptrPlatform.261_37->wdt;
  _39 = pfe_wdt_get_stat_value (_38, 128);
  stat_89(D)->emac2_wdt_int_en = _39;
  # DEBUG BEGIN_STMT
  ptrPlatform.262_40 = ptrPlatform;
  _41 = ptrPlatform.262_40->wdt;
  _42 = pfe_wdt_get_stat_value (_41, 308);
  stat_89(D)->ext_gpt_wdt_int_en = _42;
  # DEBUG BEGIN_STMT
  ptrPlatform.263_43 = ptrPlatform;
  _44 = ptrPlatform.263_43->wdt;
  _45 = pfe_wdt_get_stat_value (_44, 320);
  stat_89(D)->lmem_wdt_int_en = _45;
  # DEBUG BEGIN_STMT
  ptrPlatform.264_46 = ptrPlatform;
  _47 = ptrPlatform.264_46->wdt;
  _48 = pfe_wdt_get_stat_value (_47, 132);
  stat_89(D)->wdt_int_src = _48;
  # DEBUG BEGIN_STMT
  ptrPlatform.265_49 = ptrPlatform;
  _50 = ptrPlatform.265_49->wdt;
  _51 = pfe_wdt_get_stat_value (_50, 136);
  stat_89(D)->wdt_timer_val_upe = _51;
  # DEBUG BEGIN_STMT
  ptrPlatform.266_52 = ptrPlatform;
  _53 = ptrPlatform.266_52->wdt;
  _54 = pfe_wdt_get_stat_value (_53, 140);
  stat_89(D)->wdt_timer_val_bmu = _54;
  # DEBUG BEGIN_STMT
  ptrPlatform.267_55 = ptrPlatform;
  _56 = ptrPlatform.267_55->wdt;
  _57 = pfe_wdt_get_stat_value (_56, 144);
  stat_89(D)->wdt_timer_val_hif = _57;
  # DEBUG BEGIN_STMT
  ptrPlatform.268_58 = ptrPlatform;
  _59 = ptrPlatform.268_58->wdt;
  _60 = pfe_wdt_get_stat_value (_59, 148);
  stat_89(D)->wdt_timer_val_tlite = _60;
  # DEBUG BEGIN_STMT
  ptrPlatform.269_61 = ptrPlatform;
  _62 = ptrPlatform.269_61->wdt;
  _63 = pfe_wdt_get_stat_value (_62, 152);
  stat_89(D)->wdt_timer_val_hif_ncpy = _63;
  # DEBUG BEGIN_STMT
  ptrPlatform.270_64 = ptrPlatform;
  _65 = ptrPlatform.270_64->wdt;
  _66 = pfe_wdt_get_stat_value (_65, 156);
  stat_89(D)->wdt_timer_val_class = _66;
  # DEBUG BEGIN_STMT
  ptrPlatform.271_67 = ptrPlatform;
  _68 = ptrPlatform.271_67->wdt;
  _69 = pfe_wdt_get_stat_value (_68, 160);
  stat_89(D)->wdt_timer_val_gpi = _69;
  # DEBUG BEGIN_STMT
  ptrPlatform.272_70 = ptrPlatform;
  _71 = ptrPlatform.272_70->wdt;
  _72 = pfe_wdt_get_stat_value (_71, 312);
  stat_89(D)->wdt_timer_val_gpt = _72;
  # DEBUG BEGIN_STMT
  ptrPlatform.273_73 = ptrPlatform;
  _74 = ptrPlatform.273_73->wdt;
  _75 = pfe_wdt_get_stat_value (_74, 324);
  stat_89(D)->wdt_timer_val_lmem = _75;
  # DEBUG BEGIN_STMT
  ptrPlatform.274_76 = ptrPlatform;
  _77 = ptrPlatform.274_76->wdt;
  _78 = pfe_wdt_get_stat_value (_77, 328);
  stat_89(D)->wdt_timer_val_route_lmem = _78;
  # DEBUG BEGIN_STMT
  ptrPlatform.275_79 = ptrPlatform;
  _80 = ptrPlatform.275_79->wdt;
  _81 = pfe_wdt_get_stat_value (_80, 164);
  stat_89(D)->wsp_dbug_bus1_g3 = _81;
  # DEBUG BEGIN_STMT
  ptrPlatform.276_82 = ptrPlatform;
  _83 = ptrPlatform.276_82->wdt;
  _84 = pfe_wdt_get_stat_value (_83, 152);
  stat_89(D)->wsp_dbug_bus1 = _84;
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 0

  <bb 4> [local count: 1073741824]:
  # retVal_85 = PHI <1(2), 0(3)>
  # DEBUG retVal => retVal_85
  # DEBUG BEGIN_STMT
  return retVal_85;

}



;; Function Eth_43_PFE_LLD_GetL2BridgeStats (Eth_43_PFE_LLD_GetL2BridgeStats, funcdef_no=135, decl_uid=11376, cgraph_uid=136, symbol_order=155)

Modification phase of node Eth_43_PFE_LLD_GetL2BridgeStats/155
Eth_43_PFE_LLD_GetL2BridgeStats (struct Eth_43_PFE_L2BridgeStatsType * stat, uint32 index_entry)
{
  uint32 number_entry;
  Std_ReturnType retVal;
  struct pfe_platform_t * ptrPlatform.277_1;
  struct pfe_l2br_t * _2;
  _Bool _3;
  long int _4;
  long int _5;
  struct pfe_platform_t * ptrPlatform.279_6;
  struct pfe_l2br_t * _7;
  int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ptrPlatform.277_1 = ptrPlatform;
  if (ptrPlatform.277_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = ptrPlatform.277_1->l2_bridge;
  number_entry_13 = pfe_l2br_get_number_entries (_2);
  # DEBUG number_entry => number_entry_13
  # DEBUG BEGIN_STMT
  _3 = number_entry_13 <= index_entry_14(D);
  _4 = (long int) _3;
  _5 = __builtin_expect (_4, 0);
  if (_5 != 0)
    goto <bb 4>; [10.00%]
  else
    goto <bb 5>; [90.00%]

  <bb 4> [local count: 57412975]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Entry index out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/Eth_PFE_LLD.c", 4733, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 516716778]:
  # DEBUG BEGIN_STMT
  ptrPlatform.279_6 = ptrPlatform;
  _7 = ptrPlatform.279_6->l2_bridge;
  _8 = pfe_l2br_get_stats (_7, stat_15(D), index_entry_14(D));
  if (_8 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 258358389]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 0

  <bb 7> [local count: 1073741824]:
  # retVal_9 = PHI <1(2), 1(4), 1(5), 0(6)>
  # DEBUG retVal => retVal_9
  # DEBUG BEGIN_STMT
  return retVal_9;

}



;; Function Eth_43_PFE_LLD_GetL2BridgeDomainStats (Eth_43_PFE_LLD_GetL2BridgeDomainStats, funcdef_no=136, decl_uid=11373, cgraph_uid=137, symbol_order=156)

Modification phase of node Eth_43_PFE_LLD_GetL2BridgeDomainStats/156
Eth_43_PFE_LLD_GetL2BridgeDomainStats (struct pfe_ct_vlan_stats_t * stat, uint8 index_vlan)
{
  Std_ReturnType retVal;
  struct pfe_platform_t * ptrPlatform.280_1;
  struct pfe_l2br_t * _2;
  int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  ptrPlatform.280_1 = ptrPlatform;
  if (ptrPlatform.280_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = ptrPlatform.280_1->l2_bridge;
  _3 = pfe_l2br_get_domain_stats (_2, stat_7(D), index_vlan_8(D));
  if (_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 287064877]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 0

  <bb 5> [local count: 1073741824]:
  # retVal_4 = PHI <1(2), 1(3), 0(4)>
  # DEBUG retVal => retVal_4
  # DEBUG BEGIN_STMT
  return retVal_4;

}



;; Function Eth_43_PFE_LLD_GetRtableStats (Eth_43_PFE_LLD_GetRtableStats, funcdef_no=137, decl_uid=11370, cgraph_uid=138, symbol_order=157)

Modification phase of node Eth_43_PFE_LLD_GetRtableStats/157
Eth_43_PFE_LLD_GetRtableStats (struct pfe_ct_conntrack_stats_t * stat, uint8 conntrack_index)
{
  Std_ReturnType retVal;
  struct pfe_platform_t * ptrPlatform.282_1;
  struct pfe_rtable_t * _2;
  int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  ptrPlatform.282_1 = ptrPlatform;
  if (ptrPlatform.282_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = ptrPlatform.282_1->rtable;
  _3 = pfe_rtable_get_stats (_2, stat_7(D), conntrack_index_8(D));
  if (_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 287064877]:
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 0

  <bb 5> [local count: 1073741824]:
  # retVal_4 = PHI <1(2), 1(3), 0(4)>
  # DEBUG retVal => retVal_4
  # DEBUG BEGIN_STMT
  return retVal_4;

}



;; Function Eth_43_PFE_LLD_GetTmuStats (Eth_43_PFE_LLD_GetTmuStats, funcdef_no=138, decl_uid=11367, cgraph_uid=139, symbol_order=158)

Modification phase of node Eth_43_PFE_LLD_GetTmuStats/158
Eth_43_PFE_LLD_GetTmuStats (struct Eth_43_PFE_TmuStatsType * stat)
{
  struct pfe_tmu_queue_stats queue_stats;
  struct pfe_tmu_stats_special_t special_stats;
  Std_ReturnType retVal;
  uint32 j;
  uint32 i;
  struct pfe_platform_t * ptrPlatform.284_1;
  struct pfe_tmu_t * _3;
  long unsigned int _4;
  struct pfe_platform_t * ptrPlatform.286_5;
  struct pfe_tmu_t * _6;
  long unsigned int _7;
  struct pfe_platform_t * ptrPlatform.287_8;
  struct pfe_tmu_t * _9;
  long unsigned int _10;
  struct pfe_platform_t * ptrPlatform.288_11;
  struct pfe_tmu_t * _12;
  long unsigned int _13;
  struct pfe_platform_t * ptrPlatform.289_14;
  struct pfe_tmu_t * _15;
  long unsigned int _16;
  struct pfe_platform_t * ptrPlatform.290_17;
  struct pfe_tmu_t * _18;
  long unsigned int _19;
  struct pfe_platform_t * ptrPlatform.291_20;
  struct pfe_tmu_t * _21;
  long unsigned int _22;
  struct pfe_platform_t * ptrPlatform.292_23;
  struct pfe_tmu_t * _24;
  long unsigned int _25;
  struct pfe_platform_t * ptrPlatform.293_26;
  struct pfe_tmu_t * _27;
  long unsigned int _28;
  struct pfe_platform_t * ptrPlatform.294_29;
  struct pfe_tmu_t * _30;
  long unsigned int _31;
  struct pfe_platform_t * ptrPlatform.295_32;
  struct pfe_tmu_t * _33;
  long unsigned int _34;
  struct pfe_platform_t * ptrPlatform.296_35;
  struct pfe_tmu_t * _36;
  int _37;
  long unsigned int _38;
  long unsigned int _39;
  struct pfe_platform_t * ptrPlatform.297_40;
  struct pfe_tmu_t * _41;
  int _42;
  uint8_t[32] * _43;

  <bb 2> [local count: 37196709]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG retVal => 1
  # DEBUG BEGIN_STMT
  special_stats = {};
  # DEBUG BEGIN_STMT
  queue_stats = {};
  # DEBUG BEGIN_STMT
  ptrPlatform.284_1 = ptrPlatform;
  if (ptrPlatform.284_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 14>; [46.53%]

  <bb 3> [local count: 19889080]:
  # DEBUG BEGIN_STMT
  _3 = ptrPlatform.284_1->tmu;
  _4 = pfe_tmu_get_stat_value (_3, 524296);
  stat_56(D)->tmu_phy_inq_pktptr = _4;
  # DEBUG BEGIN_STMT
  ptrPlatform.286_5 = ptrPlatform;
  _6 = ptrPlatform.286_5->tmu;
  _7 = pfe_tmu_get_stat_value (_6, 524300);
  stat_56(D)->tmu_phy_inq_pktinfo = _7;
  # DEBUG BEGIN_STMT
  ptrPlatform.287_8 = ptrPlatform;
  _9 = ptrPlatform.287_8->tmu;
  _10 = pfe_tmu_get_stat_value (_9, 524304);
  stat_56(D)->tmu_phy_inq_stat = _10;
  # DEBUG BEGIN_STMT
  ptrPlatform.288_11 = ptrPlatform;
  _12 = ptrPlatform.288_11->tmu;
  _13 = pfe_tmu_get_stat_value (_12, 524612);
  stat_56(D)->tmu_dbg_bus_stop = _13;
  # DEBUG BEGIN_STMT
  ptrPlatform.289_14 = ptrPlatform;
  _15 = ptrPlatform.289_14->tmu;
  _16 = pfe_tmu_get_stat_value (_15, 524616);
  stat_56(D)->tmu_dbg_bus_pp0 = _16;
  # DEBUG BEGIN_STMT
  ptrPlatform.290_17 = ptrPlatform;
  _18 = ptrPlatform.290_17->tmu;
  _19 = pfe_tmu_get_stat_value (_18, 524620);
  stat_56(D)->tmu_dbg_bus_pp1 = _19;
  # DEBUG BEGIN_STMT
  ptrPlatform.291_20 = ptrPlatform;
  _21 = ptrPlatform.291_20->tmu;
  _22 = pfe_tmu_get_stat_value (_21, 524624);
  stat_56(D)->tmu_dbg_bus_pp2 = _22;
  # DEBUG BEGIN_STMT
  ptrPlatform.292_23 = ptrPlatform;
  _24 = ptrPlatform.292_23->tmu;
  _25 = pfe_tmu_get_stat_value (_24, 524628);
  stat_56(D)->tmu_dbg_bus_pp3 = _25;
  # DEBUG BEGIN_STMT
  ptrPlatform.293_26 = ptrPlatform;
  _27 = ptrPlatform.293_26->tmu;
  _28 = pfe_tmu_get_stat_value (_27, 524632);
  stat_56(D)->tmu_dbg_bus_pp4 = _28;
  # DEBUG BEGIN_STMT
  ptrPlatform.294_29 = ptrPlatform;
  _30 = ptrPlatform.294_29->tmu;
  _31 = pfe_tmu_get_stat_value (_30, 524636);
  stat_56(D)->tmu_dbg_bus_pp5 = _31;
  # DEBUG BEGIN_STMT
  ptrPlatform.295_32 = ptrPlatform;
  _33 = ptrPlatform.295_32->tmu;
  _34 = pfe_tmu_get_stat_value (_33, 524344);
  stat_56(D)->ctrl = _34;
  # DEBUG BEGIN_STMT
  ptrPlatform.296_35 = ptrPlatform;
  _36 = ptrPlatform.296_35->tmu;
  _37 = pfe_tmu_get_special_stats (_36, &special_stats);
  if (_37 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 9944540]:
  # DEBUG BEGIN_STMT
  _38 = special_stats.version;
  stat_56(D)->version = _38;
  # DEBUG BEGIN_STMT
  _39 = special_stats.id;
  stat_56(D)->id = _39;
  # DEBUG BEGIN_STMT
  stat_56(D)->revision = _38;

  <bb 13> [local count: 19889080]:
  # i_47 = PHI <0(5), 0(4)>
  goto <bb 15>; [100.00%]

  <bb 5> [local count: 9944540]:
  # DEBUG BEGIN_STMT
  stat_56(D)->version = 4294967295;
  # DEBUG BEGIN_STMT
  stat_56(D)->id = 4294967295;
  # DEBUG BEGIN_STMT
  stat_56(D)->revision = 4294967295;
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 954449109]:
  # DEBUG BEGIN_STMT
  ptrPlatform.297_40 = ptrPlatform;
  _41 = ptrPlatform.297_40->tmu;
  _42 = pfe_tmu_get_queue_stats (_41, i_44, j_45, &queue_stats);
  if (_42 == 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 9>; [33.00%]

  <bb 8> [local count: 639480904]:
  # DEBUG BEGIN_STMT
  stat_56(D)->aQueue[i_44][j_45] = queue_stats;
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 314968206]:
  # DEBUG BEGIN_STMT
  stat_56(D)->aQueue[i_44][j_45].mode = 4294967295;
  # DEBUG BEGIN_STMT
  stat_56(D)->aQueue[i_44][j_45].min = 4294967295;
  # DEBUG BEGIN_STMT
  stat_56(D)->aQueue[i_44][j_45].max = 4294967295;
  # DEBUG BEGIN_STMT
  stat_56(D)->aQueue[i_44][j_45].level = 4294967295;
  # DEBUG BEGIN_STMT
  stat_56(D)->aQueue[i_44][j_45].drops = 4294967295;
  # DEBUG BEGIN_STMT
  stat_56(D)->aQueue[i_44][j_45].tx = 4294967295;
  # DEBUG BEGIN_STMT
  _43 = &stat_56(D)->aQueue[i_44][j_45].zprob;
  autolibc_memset (_43, 255, 32);

  <bb 10> [local count: 954449110]:
  # DEBUG BEGIN_STMT
  j_95 = j_45 + 1;
  # DEBUG j => j_95

  <bb 11> [local count: 1073741824]:
  # j_45 = PHI <j_95(10), 0(16)>
  # DEBUG j => j_45
  # DEBUG BEGIN_STMT
  if (j_45 != 8)
    goto <bb 7>; [88.89%]
  else
    goto <bb 12>; [11.11%]

  <bb 12> [local count: 119292717]:
  # DEBUG BEGIN_STMT
  i_85 = i_44 + 1;
  # DEBUG i => i_85

  <bb 15> [local count: 139181797]:
  # i_44 = PHI <i_47(13), i_85(12)>
  # DEBUG i => i_44
  # DEBUG BEGIN_STMT
  if (i_44 != 6)
    goto <bb 16>; [85.71%]
  else
    goto <bb 14>; [14.29%]

  <bb 16> [local count: 119292718]:
  goto <bb 11>; [100.00%]

  <bb 14> [local count: 37196707]:
  # retVal_46 = PHI <1(2), 0(15)>
  # DEBUG retVal => retVal_46
  # DEBUG BEGIN_STMT
  special_stats ={v} {CLOBBER};
  queue_stats ={v} {CLOBBER};
  return retVal_46;

}



;; Function Eth_PFE_LLD_GetCounterValues (Eth_PFE_LLD_GetCounterValues, funcdef_no=139, decl_uid=11387, cgraph_uid=140, symbol_order=159)

Modification phase of node Eth_PFE_LLD_GetCounterValues/159
Eth_PFE_LLD_GetCounterValues (uint8 u8CtrlIdx, struct Eth_CounterType * CounterPtr)
{
  const uint32_t tx_count_good;
  const uint32_t tx_count_good_bad;
  struct pfe_emac_t * prEmac;
  long unsigned int _1;
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

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  prEmac_16 = Eth_PFE_LLD_GetEmacInstanceByControllerId (u8CtrlIdx_15(D));
  # DEBUG prEmac => prEmac_16
  # DEBUG BEGIN_STMT
  if (prEmac_16 == 0B)
    goto <bb 3>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 3> [local count: 499612071]:
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->DropPktBufOverrun = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->DropPktCrc = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->UndersizePkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->OversizePkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->AlgnmtErr = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->SqeTestErr = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->DiscInbdPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->ErrInbdPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->DiscOtbdPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->ErrOtbdPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->SnglCollPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->MultCollPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->DfrdPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->LatCollPkt = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr0 = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr1 = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr2 = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr3 = 4294967295;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  tx_count_good_bad_18 = pfe_emac_get_stat_value (prEmac_16, 1816);
  # DEBUG tx_count_good_bad => tx_count_good_bad_18
  # DEBUG BEGIN_STMT
  tx_count_good_20 = pfe_emac_get_stat_value (prEmac_16, 1896);
  # DEBUG tx_count_good => tx_count_good_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tx_count_good_bad_18 - tx_count_good_20;
  CounterPtr_21(D)->ErrOtbdPkt = _1;
  # DEBUG BEGIN_STMT
  _2 = pfe_emac_get_stat_value (prEmac_16, 2004);
  CounterPtr_21(D)->DropPktBufOverrun = _2;
  # DEBUG BEGIN_STMT
  _3 = pfe_emac_get_stat_value (prEmac_16, 1940);
  CounterPtr_21(D)->DropPktCrc = _3;
  # DEBUG BEGIN_STMT
  _4 = pfe_emac_get_stat_value (prEmac_16, 1956);
  CounterPtr_21(D)->UndersizePkt = _4;
  # DEBUG BEGIN_STMT
  _5 = pfe_emac_get_stat_value (prEmac_16, 1960);
  CounterPtr_21(D)->OversizePkt = _5;
  # DEBUG BEGIN_STMT
  _6 = pfe_emac_get_stat_value (prEmac_16, 1944);
  CounterPtr_21(D)->AlgnmtErr = _6;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->SqeTestErr = 4294967295;
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_get_stat_value (prEmac_16, 2004);
  CounterPtr_21(D)->DiscInbdPkt = _7;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->ErrInbdPkt = 4294967295;
  # DEBUG BEGIN_STMT
  _8 = pfe_emac_get_stat_value (prEmac_16, 1864);
  CounterPtr_21(D)->DiscOtbdPkt = _8;
  # DEBUG BEGIN_STMT
  _9 = pfe_emac_get_stat_value (prEmac_16, 1868);
  CounterPtr_21(D)->SnglCollPkt = _9;
  # DEBUG BEGIN_STMT
  _10 = pfe_emac_get_stat_value (prEmac_16, 1872);
  CounterPtr_21(D)->MultCollPkt = _10;
  # DEBUG BEGIN_STMT
  _11 = pfe_emac_get_stat_value (prEmac_16, 1876);
  CounterPtr_21(D)->DfrdPkt = _11;
  # DEBUG BEGIN_STMT
  _12 = pfe_emac_get_stat_value (prEmac_16, 1880);
  CounterPtr_21(D)->LatCollPkt = _12;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr0 = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr1 = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr2 = 4294967295;
  # DEBUG BEGIN_STMT
  CounterPtr_21(D)->HwDepCtr3 = 4294967295;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Eth_PFE_LLD_GetRxStats (Eth_PFE_LLD_GetRxStats, funcdef_no=140, decl_uid=11390, cgraph_uid=141, symbol_order=160)

Modification phase of node Eth_PFE_LLD_GetRxStats/160
Eth_PFE_LLD_GetRxStats (uint8 u8CtrlIdx, struct Eth_RxStatsType * RxStatsPtr)
{
  const uint32_t rx_align_err;
  const uint32_t rx_crc_err;
  struct pfe_emac_t * prEmac;
  long unsigned int _1;
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
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int iftmp.298_18;
  long unsigned int iftmp.298_27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  prEmac_22 = Eth_PFE_LLD_GetEmacInstanceByControllerId (u8CtrlIdx_21(D));
  # DEBUG prEmac => prEmac_22
  # DEBUG BEGIN_STMT
  if (prEmac_22 == 0B)
    goto <bb 3>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 3> [local count: 499612071]:
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsDropEvents = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsOctets = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsPkts = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsBroadcastPkts = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsMulticastPkts = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsCrcAlignErrors = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsUndersizePkts = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsOversizePkts = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsFragments = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsJabbers = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsCollisions = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsPkts64Octets = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsPkts65to127Octets = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsPkts128to255Octets = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsPkts256to511Octets = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsPkts512to1023Octets = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsPkts1024to1518Octets = 4294967295;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxUnicastFrames = 4294967295;
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  rx_crc_err_24 = pfe_emac_get_stat_value (prEmac_22, 1940);
  # DEBUG rx_crc_err => rx_crc_err_24
  # DEBUG BEGIN_STMT
  rx_align_err_26 = pfe_emac_get_stat_value (prEmac_22, 1944);
  # DEBUG rx_align_err => rx_align_err_26
  # DEBUG BEGIN_STMT
  _1 = ~rx_align_err_26;
  if (_1 >= rx_crc_err_24)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 287064877]:
  iftmp.298_27 = rx_crc_err_24 + rx_align_err_26;

  <bb 6> [local count: 574129754]:
  # iftmp.298_18 = PHI <iftmp.298_27(5), 4294967295(4)>
  RxStatsPtr_28(D)->RxStatsCrcAlignErrors = iftmp.298_18;
  # DEBUG BEGIN_STMT
  _2 = pfe_emac_get_stat_value (prEmac_22, 2004);
  RxStatsPtr_28(D)->RxStatsDropEvents = _2;
  # DEBUG BEGIN_STMT
  _3 = pfe_emac_get_stat_value (prEmac_22, 1924);
  RxStatsPtr_28(D)->RxStatsOctets = _3;
  # DEBUG BEGIN_STMT
  _4 = pfe_emac_get_stat_value (prEmac_22, 1920);
  RxStatsPtr_28(D)->RxStatsPkts = _4;
  # DEBUG BEGIN_STMT
  _5 = pfe_emac_get_stat_value (prEmac_22, 1932);
  RxStatsPtr_28(D)->RxStatsBroadcastPkts = _5;
  # DEBUG BEGIN_STMT
  _6 = pfe_emac_get_stat_value (prEmac_22, 1936);
  RxStatsPtr_28(D)->RxStatsMulticastPkts = _6;
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_get_stat_value (prEmac_22, 1956);
  RxStatsPtr_28(D)->RxStatsUndersizePkts = _7;
  # DEBUG BEGIN_STMT
  _8 = pfe_emac_get_stat_value (prEmac_22, 1960);
  RxStatsPtr_28(D)->RxStatsOversizePkts = _8;
  # DEBUG BEGIN_STMT
  _9 = pfe_emac_get_stat_value (prEmac_22, 1948);
  RxStatsPtr_28(D)->RxStatsFragments = _9;
  # DEBUG BEGIN_STMT
  _10 = pfe_emac_get_stat_value (prEmac_22, 1952);
  RxStatsPtr_28(D)->RxStatsJabbers = _10;
  # DEBUG BEGIN_STMT
  RxStatsPtr_28(D)->RxStatsCollisions = 4294967295;
  # DEBUG BEGIN_STMT
  _11 = pfe_emac_get_stat_value (prEmac_22, 1964);
  RxStatsPtr_28(D)->RxStatsPkts64Octets = _11;
  # DEBUG BEGIN_STMT
  _12 = pfe_emac_get_stat_value (prEmac_22, 1968);
  RxStatsPtr_28(D)->RxStatsPkts65to127Octets = _12;
  # DEBUG BEGIN_STMT
  _13 = pfe_emac_get_stat_value (prEmac_22, 1972);
  RxStatsPtr_28(D)->RxStatsPkts128to255Octets = _13;
  # DEBUG BEGIN_STMT
  _14 = pfe_emac_get_stat_value (prEmac_22, 1976);
  RxStatsPtr_28(D)->RxStatsPkts256to511Octets = _14;
  # DEBUG BEGIN_STMT
  _15 = pfe_emac_get_stat_value (prEmac_22, 1980);
  RxStatsPtr_28(D)->RxStatsPkts512to1023Octets = _15;
  # DEBUG BEGIN_STMT
  _16 = pfe_emac_get_stat_value (prEmac_22, 1984);
  RxStatsPtr_28(D)->RxStatsPkts1024to1518Octets = _16;
  # DEBUG BEGIN_STMT
  _17 = pfe_emac_get_stat_value (prEmac_22, 1988);
  RxStatsPtr_28(D)->RxUnicastFrames = _17;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Eth_PFE_LLD_GetTxStats (Eth_PFE_LLD_GetTxStats, funcdef_no=141, decl_uid=11393, cgraph_uid=142, symbol_order=161)

Modification phase of node Eth_PFE_LLD_GetTxStats/161
Eth_PFE_LLD_GetTxStats (uint8 u8CtrlIdx, struct Eth_TxStatsType * TxStatsPtr)
{
  const uint32_t tx_bc_good_bad;
  const uint32_t tx_mc_good_bad;
  struct pfe_emac_t * prEmac;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int iftmp.299_4;
  long unsigned int iftmp.299_13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  prEmac_8 = Eth_PFE_LLD_GetEmacInstanceByControllerId (u8CtrlIdx_7(D));
  # DEBUG prEmac => prEmac_8
  # DEBUG BEGIN_STMT
  if (prEmac_8 == 0B)
    goto <bb 3>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 3> [local count: 499612071]:
  # DEBUG BEGIN_STMT
  TxStatsPtr_14(D)->TxNumberOfOctets = 4294967295;
  # DEBUG BEGIN_STMT
  TxStatsPtr_14(D)->TxNUcastPkts = 4294967295;
  # DEBUG BEGIN_STMT
  TxStatsPtr_14(D)->TxUniCastPkts = 4294967295;
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  tx_mc_good_bad_10 = pfe_emac_get_stat_value (prEmac_8, 1856);
  # DEBUG tx_mc_good_bad => tx_mc_good_bad_10
  # DEBUG BEGIN_STMT
  tx_bc_good_bad_12 = pfe_emac_get_stat_value (prEmac_8, 1860);
  # DEBUG tx_bc_good_bad => tx_bc_good_bad_12
  # DEBUG BEGIN_STMT
  _1 = ~tx_mc_good_bad_10;
  if (_1 >= tx_bc_good_bad_12)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 287064877]:
  iftmp.299_13 = tx_mc_good_bad_10 + tx_bc_good_bad_12;

  <bb 6> [local count: 574129754]:
  # iftmp.299_4 = PHI <iftmp.299_13(5), 4294967295(4)>
  TxStatsPtr_14(D)->TxNUcastPkts = iftmp.299_4;
  # DEBUG BEGIN_STMT
  _2 = pfe_emac_get_stat_value (prEmac_8, 1812);
  TxStatsPtr_14(D)->TxNumberOfOctets = _2;
  # DEBUG BEGIN_STMT
  _3 = pfe_emac_get_stat_value (prEmac_8, 1852);
  TxStatsPtr_14(D)->TxUniCastPkts = _3;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Eth_PFE_LLD_GetTxErrorCounterValues (Eth_PFE_LLD_GetTxErrorCounterValues, funcdef_no=142, decl_uid=11396, cgraph_uid=143, symbol_order=162)

Modification phase of node Eth_PFE_LLD_GetTxErrorCounterValues/162
Eth_PFE_LLD_GetTxErrorCounterValues (uint8 u8CtrlIdx, struct Eth_TxErrorCounterValuesType * TxErrorCounterValuesPtr)
{
  const uint32_t tx_count_good;
  const uint32_t tx_count_good_bad;
  struct pfe_emac_t * prEmac;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG prEmac => 0B
  # DEBUG BEGIN_STMT
  prEmac_11 = Eth_PFE_LLD_GetEmacInstanceByControllerId (u8CtrlIdx_10(D));
  # DEBUG prEmac => prEmac_11
  # DEBUG BEGIN_STMT
  if (prEmac_11 == 0B)
    goto <bb 3>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 3> [local count: 499612071]:
  # DEBUG BEGIN_STMT
  TxErrorCounterValuesPtr_16(D)->TxDroppedNoErrorPkts = 4294967295;
  # DEBUG BEGIN_STMT
  TxErrorCounterValuesPtr_16(D)->TxDroppedErrorPkts = 4294967295;
  # DEBUG BEGIN_STMT
  TxErrorCounterValuesPtr_16(D)->TxDeferredTrans = 4294967295;
  # DEBUG BEGIN_STMT
  TxErrorCounterValuesPtr_16(D)->TxSingleCollision = 4294967295;
  # DEBUG BEGIN_STMT
  TxErrorCounterValuesPtr_16(D)->TxMultipleCollision = 4294967295;
  # DEBUG BEGIN_STMT
  TxErrorCounterValuesPtr_16(D)->TxLateCollision = 4294967295;
  # DEBUG BEGIN_STMT
  TxErrorCounterValuesPtr_16(D)->TxExcessiveCollison = 4294967295;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  tx_count_good_bad_13 = pfe_emac_get_stat_value (prEmac_11, 1816);
  # DEBUG tx_count_good_bad => tx_count_good_bad_13
  # DEBUG BEGIN_STMT
  tx_count_good_15 = pfe_emac_get_stat_value (prEmac_11, 1896);
  # DEBUG tx_count_good => tx_count_good_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = tx_count_good_bad_13 - tx_count_good_15;
  TxErrorCounterValuesPtr_16(D)->TxDroppedErrorPkts = _1;
  # DEBUG BEGIN_STMT
  _2 = pfe_emac_get_stat_value (prEmac_11, 1864);
  TxErrorCounterValuesPtr_16(D)->TxDroppedNoErrorPkts = _2;
  # DEBUG BEGIN_STMT
  _3 = pfe_emac_get_stat_value (prEmac_11, 1876);
  TxErrorCounterValuesPtr_16(D)->TxDeferredTrans = _3;
  # DEBUG BEGIN_STMT
  _4 = pfe_emac_get_stat_value (prEmac_11, 1868);
  TxErrorCounterValuesPtr_16(D)->TxSingleCollision = _4;
  # DEBUG BEGIN_STMT
  _5 = pfe_emac_get_stat_value (prEmac_11, 1872);
  TxErrorCounterValuesPtr_16(D)->TxMultipleCollision = _5;
  # DEBUG BEGIN_STMT
  _6 = pfe_emac_get_stat_value (prEmac_11, 1880);
  TxErrorCounterValuesPtr_16(D)->TxLateCollision = _6;
  # DEBUG BEGIN_STMT
  _7 = pfe_emac_get_stat_value (prEmac_11, 1884);
  TxErrorCounterValuesPtr_16(D)->TxExcessiveCollison = _7;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Eth_PFE_LLD_ChannelBdFlushRx (Eth_PFE_LLD_ChannelBdFlushRx, funcdef_no=143, decl_uid=11398, cgraph_uid=144, symbol_order=163)

Modification phase of node Eth_PFE_LLD_ChannelBdFlushRx/163
Eth_PFE_LLD_ChannelBdFlushRx (pfe_ct_phy_if_id_t DestHifChnl)
{
  Std_ReturnType Ret;
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Ret => 1
  # DEBUG BEGIN_STMT
  _1 = ChannelBdFlushRxPrepare (DestHifChnl_5(D));
  if (_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Ret_8 = ChannelBdFlushRxExecute (DestHifChnl_5(D));
  # DEBUG Ret => Ret_8

  <bb 4> [local count: 1073741824]:
  # Ret_2 = PHI <1(2), Ret_8(3)>
  # DEBUG Ret => Ret_2
  # DEBUG BEGIN_STMT
  return Ret_2;

}



;; Function Eth_43_PFE_LLD_SetMasterUp (Eth_43_PFE_LLD_SetMasterUp, funcdef_no=144, decl_uid=11403, cgraph_uid=145, symbol_order=164)

Modification phase of node Eth_43_PFE_LLD_SetMasterUp/164
Eth_43_PFE_LLD_SetMasterUp ()
{
  struct pfe_platform_t * ptrPlatform.303_1;
  struct pfe_hif_t * _2;
  unsigned char _3;
  struct pfe_platform_t * ptrPlatform.304_4;
  struct pfe_hif_t * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ptrPlatform.303_1 = ptrPlatform;
  _2 = ptrPlatform.303_1->hif;
  _3 = pfe_hif_get_master_detect_cfg (_2);
  if (_3 == 1)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  ptrPlatform.304_4 = ptrPlatform;
  _5 = ptrPlatform.304_4->hif;
  pfe_hif_set_master_up (_5);

  <bb 4> [local count: 1073741824]:
  return;

}


