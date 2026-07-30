
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  EthTrcv_WriteMiiIndication/1:
  Jump functions of caller  EthTrcv_ReadMiiIndication/0:

 Propagating constants:

Not considering EthTrcv_WriteMiiIndication for cloning; -fipa-cp-clone disabled.
Not considering EthTrcv_ReadMiiIndication for cloning; -fipa-cp-clone disabled.

overall_size: 6, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 3.000000
 - context independent values, size: 3, time_benefit: 4.000000

IPA lattices after all propagation:

Lattices:
  Node: EthTrcv_WriteMiiIndication/1:
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
  Node: EthTrcv_ReadMiiIndication/0:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

EthTrcv_WriteMiiIndication/1 (EthTrcv_WriteMiiIndication) @06d9fc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
EthTrcv_ReadMiiIndication/0 (EthTrcv_ReadMiiIndication) @06d9f9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function EthTrcv_ReadMiiIndication (EthTrcv_ReadMiiIndication, funcdef_no=0, decl_uid=5657, cgraph_uid=1, symbol_order=0)

Modification phase of node EthTrcv_ReadMiiIndication/0
EthTrcv_ReadMiiIndication (uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint16 RegVal)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function EthTrcv_WriteMiiIndication (EthTrcv_WriteMiiIndication, funcdef_no=1, decl_uid=5661, cgraph_uid=2, symbol_order=1)

Modification phase of node EthTrcv_WriteMiiIndication/1
EthTrcv_WriteMiiIndication (uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}


