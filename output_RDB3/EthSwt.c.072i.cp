
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  EthSwt_EthTxFinishedIndication/5:
  Jump functions of caller  EthSwt_EthTxProcessFrame/4:
  Jump functions of caller  EthSwt_EthTxAdaptBufferLength/3:
  Jump functions of caller  EthSwt_EthTxPrepareFrame/2:
  Jump functions of caller  EthSwt_EthRxFinishedIndication/1:
  Jump functions of caller  EthSwt_EthRxProcessFrame/0:

 Propagating constants:

Function EthSwt_EthTxFinishedIndication/5 is not versionable, reason: not a tree_versionable_function.
Function EthSwt_EthTxProcessFrame/4 is not versionable, reason: not a tree_versionable_function.
Not considering EthSwt_EthTxAdaptBufferLength for cloning; -fipa-cp-clone disabled.
Not considering EthSwt_EthTxPrepareFrame for cloning; -fipa-cp-clone disabled.
Not considering EthSwt_EthRxFinishedIndication for cloning; -fipa-cp-clone disabled.
Not considering EthSwt_EthRxProcessFrame for cloning; -fipa-cp-clone disabled.

overall_size: 29, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: -1, time_benefit: 4.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 1, time_benefit: 2.000000
 - context independent values, size: 4, time_benefit: 4.000000

IPA lattices after all propagation:

Lattices:
  Node: EthSwt_EthTxFinishedIndication/5:
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
  Node: EthSwt_EthTxProcessFrame/4:
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
  Node: EthSwt_EthTxAdaptBufferLength/3:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: EthSwt_EthTxPrepareFrame/2:
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
  Node: EthSwt_EthRxFinishedIndication/1:
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
  Node: EthSwt_EthRxProcessFrame/0:
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

IPA decision stage:

 - Creating a specialized node of EthSwt_EthTxPrepareFrame/2 for all known contexts.

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

EthSwt_EthTxPrepareFrame.constprop.0/6 (EthSwt_EthTxPrepareFrame.constprop) @06e6d7e0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of EthSwt_EthTxPrepareFrame/2
  Availability: local
  Function flags: count:1073741824 (estimated locally) local icf_merged optimize_size
  Called by: EthSwt_EthTxProcessFrame/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
EthSwt_EthTxFinishedIndication/5 (EthSwt_EthTxFinishedIndication) @06e237e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: EthSwt_EthRxFinishedIndication/1 (1073741824 (estimated locally),1.00 per call) 
EthSwt_EthTxProcessFrame/4 (EthSwt_EthTxProcessFrame) @06e23540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: EthSwt_EthTxPrepareFrame.constprop/6 (1073741824 (estimated locally),1.00 per call) 
EthSwt_EthTxAdaptBufferLength/3 (EthSwt_EthTxAdaptBufferLength) @06e232a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
EthSwt_EthTxPrepareFrame/2 (EthSwt_EthTxPrepareFrame) @06e23000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: 
EthSwt_EthRxFinishedIndication/1 (EthSwt_EthRxFinishedIndication) @06e20b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: EthSwt_EthTxFinishedIndication/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
EthSwt_EthRxProcessFrame/0 (EthSwt_EthRxProcessFrame) @06e20d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function EthSwt_EthRxProcessFrame (EthSwt_EthRxProcessFrame, funcdef_no=0, decl_uid=5658, cgraph_uid=1, symbol_order=0)

Modification phase of node EthSwt_EthRxProcessFrame/0
EthSwt_EthRxProcessFrame (uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8 * * DataPtr, uint16 * LengthPtr, boolean * IsMgmtFrameOnlyPtr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *IsMgmtFrameOnlyPtr_2(D) = 0;
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function EthSwt_EthRxFinishedIndication (EthSwt_EthRxFinishedIndication, funcdef_no=1, decl_uid=5661, cgraph_uid=2, symbol_order=1)

Modification phase of node EthSwt_EthRxFinishedIndication/1
EthSwt_EthRxFinishedIndication (uint8 CtrlIdx, Eth_BufIdxType BufIdx)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function EthSwt_EthTxPrepareFrame (EthSwt_EthTxPrepareFrame, funcdef_no=2, decl_uid=5666, cgraph_uid=3, symbol_order=2)

Modification phase of node EthSwt_EthTxPrepareFrame/2
EthSwt_EthTxPrepareFrame (uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8 * * DataPtr, uint16 * LengthPtr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function EthSwt_EthTxAdaptBufferLength (EthSwt_EthTxAdaptBufferLength, funcdef_no=3, decl_uid=5668, cgraph_uid=4, symbol_order=3)

Modification phase of node EthSwt_EthTxAdaptBufferLength/3
EthSwt_EthTxAdaptBufferLength (uint16 * LengthPtr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function EthSwt_EthTxProcessFrame (EthSwt_EthTxProcessFrame, funcdef_no=9, decl_uid=5673, cgraph_uid=5, symbol_order=4)

Modification phase of node EthSwt_EthTxProcessFrame/4
EthSwt_EthTxProcessFrame (uint8 CtrlIdx, Eth_BufIdxType BufIdx, uint8 * * DataPtr, uint16 * LengthPtr)
{
  Std_ReturnType retval.7;

  <bb 2> [local count: 1073741824]:
  retval.7_5 = EthSwt_EthTxPrepareFrame (CtrlIdx_1(D), BufIdx_2(D), DataPtr_3(D), LengthPtr_4(D)); [tail call]
  return retval.7_5;

}



;; Function EthSwt_EthTxFinishedIndication (EthSwt_EthTxFinishedIndication, funcdef_no=7, decl_uid=5676, cgraph_uid=6, symbol_order=5)

Modification phase of node EthSwt_EthTxFinishedIndication/5
EthSwt_EthTxFinishedIndication (uint8 CtrlIdx, Eth_BufIdxType BufIdx)
{
  Std_ReturnType retval.6;

  <bb 2> [local count: 1073741824]:
  retval.6_3 = EthSwt_EthRxFinishedIndication (CtrlIdx_1(D), BufIdx_2(D)); [tail call]
  return retval.6_3;

}


