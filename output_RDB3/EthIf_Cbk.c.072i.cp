
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Lwip_EthIf_RxIndication/28:
  Jump functions of caller  EthIf_GetRxMgmtObject/26:
  Jump functions of caller  EthIf_GetTxMgmtObject/25:
  Jump functions of caller  EthIf_SwitchPortModeIndication/24:
  Jump functions of caller  EthIf_TrcvModeIndication/23:
  Jump functions of caller  EthIf_CtrlModeIndication/22:
  Jump functions of caller  EthIf_TxConfirmation/21:
  Jump functions of caller  EthIf_RxIndication/20:

 Propagating constants:

Not considering EthIf_GetRxMgmtObject for cloning; -fipa-cp-clone disabled.
Not considering EthIf_GetTxMgmtObject for cloning; -fipa-cp-clone disabled.
Not considering EthIf_SwitchPortModeIndication for cloning; -fipa-cp-clone disabled.
Function EthIf_TrcvModeIndication/23 is not versionable, reason: not a tree_versionable_function.
Not considering EthIf_CtrlModeIndication for cloning; -fipa-cp-clone disabled.
Not considering EthIf_TxConfirmation for cloning; -fipa-cp-clone disabled.
Not considering EthIf_RxIndication for cloning; -fipa-cp-clone disabled.

overall_size: 43, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 3.000000
 - context independent values, size: 3, time_benefit: 3.000000
 - context independent values, size: 3, time_benefit: 3.000000
 - context independent values, size: 1, time_benefit: 2.000000
 - context independent values, size: 9, time_benefit: 2.000000

IPA lattices after all propagation:

Lattices:
  Node: EthIf_GetRxMgmtObject/26:
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
  Node: EthIf_GetTxMgmtObject/25:
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
  Node: EthIf_SwitchPortModeIndication/24:
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
  Node: EthIf_TrcvModeIndication/23:
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
  Node: EthIf_CtrlModeIndication/22:
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
  Node: EthIf_TxConfirmation/21:
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
  Node: EthIf_RxIndication/20:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfeTxConfCtr/29 (pfeTxConfCtr) @0aaad828
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: EthIf_TxConfirmation/21 (read)
  Availability: not_available
  Varpool flags:
Lwip_EthIf_RxIndication/28 (Lwip_EthIf_RxIndication) @0aaaa9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: EthIf_RxIndication/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfeRxCtr/27 (pfeRxCtr) @0aaad678
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: EthIf_RxIndication/20 (read)
  Availability: not_available
  Varpool flags:
EthIf_GetRxMgmtObject/26 (EthIf_GetRxMgmtObject) @0aaaa540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
EthIf_GetTxMgmtObject/25 (EthIf_GetTxMgmtObject) @0aaaa2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
EthIf_SwitchPortModeIndication/24 (EthIf_SwitchPortModeIndication) @0aaaa000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
EthIf_TrcvModeIndication/23 (EthIf_TrcvModeIndication) @0aa0ac40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: EthIf_CtrlModeIndication/22 (1073741824 (estimated locally),1.00 per call) 
EthIf_CtrlModeIndication/22 (EthIf_CtrlModeIndication) @0aa0a2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: EthIf_TrcvModeIndication/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
EthIf_TxConfirmation/21 (EthIf_TxConfirmation) @0aa0ae00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfeTxConfCtr/29 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
EthIf_RxIndication/20 (EthIf_RxIndication) @0aa0ab60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfeRxCtr/27 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Lwip_EthIf_RxIndication/28 (1073741824 (estimated locally),1.00 per call) 
txMgmtObject/19 (txMgmtObject) @0aa08900
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: txGlobalMgmtObject/18 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized
txGlobalMgmtObject/18 (txGlobalMgmtObject) @0aa08870
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: txMgmtObject/19 (addr)
  Availability: available
  Varpool flags:
MgmtInfoNotifications/17 (MgmtInfoNotifications) @0aa087e0
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized
EgressNotifications/16 (EgressNotifications) @0aa08750
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized
IngressNotifications/15 (IngressNotifications) @0aa086c0
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized

;; Function EthIf_RxIndication (EthIf_RxIndication, funcdef_no=13, decl_uid=9450, cgraph_uid=14, symbol_order=20)

Modification phase of node EthIf_RxIndication/20
EthIf_RxIndication (uint8 CtrlIdx, Eth_FrameType FrameType, boolean IsBroadcast, uint8 * PhysAddrPtr, Eth_DataType * DataPtr, uint16 LenByte)
{
  volatile uint32_t * pfeRxCtr.0_1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pfeRxCtr.0_1 = pfeRxCtr;
  _2 = (unsigned int) CtrlIdx_8(D);
  _3 = _2 * 4;
  _4 = pfeRxCtr.0_1 + _3;
  _5 ={v} *_4;
  _6 = _5 + 1;
  *_4 ={v} _6;
  # DEBUG BEGIN_STMT
  Lwip_EthIf_RxIndication (CtrlIdx_8(D), FrameType_10(D), IsBroadcast_11(D), PhysAddrPtr_12(D), DataPtr_13(D), LenByte_14(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function EthIf_TxConfirmation (EthIf_TxConfirmation, funcdef_no=14, decl_uid=9454, cgraph_uid=15, symbol_order=21)

Modification phase of node EthIf_TxConfirmation/21
EthIf_TxConfirmation (uint8 CtrlIdx, Eth_BufIdxType BufIdx, Std_ReturnType Result)
{
  volatile uint32_t * pfeTxConfCtr.1_1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pfeTxConfCtr.1_1 = pfeTxConfCtr;
  _2 = (unsigned int) CtrlIdx_8(D);
  _3 = _2 * 4;
  _4 = pfeTxConfCtr.1_1 + _3;
  _5 ={v} *_4;
  _6 = _5 + 1;
  *_4 ={v} _6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function EthIf_CtrlModeIndication (EthIf_CtrlModeIndication, funcdef_no=15, decl_uid=9457, cgraph_uid=16, symbol_order=22)

Modification phase of node EthIf_CtrlModeIndication/22
EthIf_CtrlModeIndication (uint8 CtrlIdx, Eth_ModeType CtrlMode)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function EthIf_TrcvModeIndication (EthIf_TrcvModeIndication, funcdef_no=21, decl_uid=9460, cgraph_uid=17, symbol_order=23)

Modification phase of node EthIf_TrcvModeIndication/23
EthIf_TrcvModeIndication (uint8 TrcvIdx, EthTrcv_ModeType TrcvMode)
{
  <bb 2> [local count: 1073741824]:
  EthIf_CtrlModeIndication (TrcvIdx_1(D), TrcvMode_2(D)); [tail call]
  return;

}



;; Function EthIf_SwitchPortModeIndication (EthIf_SwitchPortModeIndication, funcdef_no=17, decl_uid=9464, cgraph_uid=18, symbol_order=24)

Modification phase of node EthIf_SwitchPortModeIndication/24
EthIf_SwitchPortModeIndication (uint8 SwitchIdx, uint8 SwitchPortIdx, EthTrcv_ModeType PortMode)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function EthIf_GetTxMgmtObject (EthIf_GetTxMgmtObject, funcdef_no=18, decl_uid=9468, cgraph_uid=19, symbol_order=25)

Modification phase of node EthIf_GetTxMgmtObject/25
EthIf_GetTxMgmtObject (uint8 CtrlIdx, Eth_BufIdxType BufIdx, struct EthSwt_MgmtObjectType * * MgmtObjectPtr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Result => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 1;

}



;; Function EthIf_GetRxMgmtObject (EthIf_GetRxMgmtObject, funcdef_no=19, decl_uid=9472, cgraph_uid=20, symbol_order=26)

Modification phase of node EthIf_GetRxMgmtObject/26
EthIf_GetRxMgmtObject (uint8 CtrlIdx, Eth_DataType * DataPtr, struct EthSwt_MgmtObjectType * * MgmtObjectPtr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Result => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 1;

}


