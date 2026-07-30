
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Serdes_Ip_SetXpcsMode.part.0/58:
  Jump functions of caller  Serdes_Ip_SetPowerDownMode/57:
  Jump functions of caller  Serdes_Ip_SetPowerSaveMode/56:
  Jump functions of caller  Serdes_Ip_SetPowerUpMode/55:
  Jump functions of caller  Serdes_Ip_PcsAnEnable/54:
  Jump functions of caller  Serdes_Ip_PcsAnAutoSwDisable/53:
  Jump functions of caller  Serdes_Ip_PcsAnSetLinkTimer/52:
  Jump functions of caller  Serdes_Ip_PcsAnRestart/51:
  Jump functions of caller  Serdes_Ip_PcsSpeedSelect/50:
  Jump functions of caller  Serdes_Ip_PcsSetHd/49:
  Jump functions of caller  Serdes_Ip_PcsSetFd/48:
  Jump functions of caller  Serdes_Ip_PcsAnDisable/47:
  Jump functions of caller  Serdes_Ip_PcsMiiBusControlEnable/46:
  Jump functions of caller  Serdes_Ip_PmaLoopbackDisable/45:
  Jump functions of caller  Serdes_Ip_PmaIssueRxReset/44:
  Jump functions of caller  Serdes_Ip_PcsResetFinalizeAsync/43:
  Jump functions of caller  Serdes_Ip_PcsResetIssue/42:
  Jump functions of caller  Serdes_Ip_PcsPmaInitGen2/41:
  Jump functions of caller  Serdes_Ip_PmaLoopbackEnable/40:
  Jump functions of caller  Serdes_Ip_PcsWaitForPowerGood/39:
  Jump functions of caller  Serdes_Ip_PhyInit/38:
  Jump functions of caller  Serdes_Ip_PciePhySelectCRInterface/37:
  Jump functions of caller  Serdes_Ip_PcieWaitReadMpllState/36:
  Jump functions of caller  Serdes_Ip_PcieSetRefUsePad/35:
  Jump functions of caller  Serdes_Ip_PcieClearRefUsePad/34:
  Jump functions of caller  Serdes_Ip_PcieDeassertWarmReset/33:
  Jump functions of caller  Serdes_Ip_PcieAssertWarmReset/32:
  Jump functions of caller  Serdes_Ip_TimeoutExpired/31:
  Jump functions of caller  Serdes_Ip_StartTimeout/30:
  Jump functions of caller  Serdes_Ip_SetMode/29:
    callsite  Serdes_Ip_SetMode/29 -> Serdes_Ip_SetXpcsMode/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Serdes_Ip_SetMode/29 -> Serdes_Ip_SetXpcsMode/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Serdes_Ip_MainFunction/28:
    callsite  Serdes_Ip_MainFunction/28 -> Serdes_Ip_LinkUp/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Serdes_Ip_MainFunction/28 -> Serdes_Ip_WaitSecondXpcsVendorReset/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Serdes_Ip_MainFunction/28 -> Serdes_Ip_WaitFirstXpcsVendorReset/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Serdes_Ip_MainFunction/28 -> Serdes_Ip_IssueXpcsVendorReset/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Serdes_Ip_MainFunction/28 -> Serdes_Ip_WaitDeviceReset_TrustedCall/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Serdes_Ip_GetStatus/27:
  Jump functions of caller  Serdes_Ip_GetJobResult/26:
  Jump functions of caller  Serdes_Ip_Init/25:
    callsite  Serdes_Ip_Init/25 -> Serdes_Ip_SsModeConfigure_TrustedCall/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Serdes_Ip_Init/25 -> Serdes_Ip_SetXpcsSerdes1/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Serdes_Ip_SsModeConfigure_TrustedCall/24:
    callsite  Serdes_Ip_SsModeConfigure_TrustedCall/24 -> Serdes_Ip_WaitPrstAssert/3 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x15
         VR  [5, 17]
    callsite  Serdes_Ip_SsModeConfigure_TrustedCall/24 -> Serdes_Ip_WaitPrstAssert/3 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x14
         VR  [4, 16]
  Jump functions of caller  Serdes_Ip_SetXpcsMode/23:
    callsite  Serdes_Ip_SetXpcsMode/23 -> Serdes_Ip_SetXpcsMode.part.0/58 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Serdes_Ip_LinkUp/22:
    callsite  Serdes_Ip_LinkUp/22 -> Serdes_Ip_ANOption/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Serdes_Ip_LinkUp/22 -> Serdes_Ip_SetSpeedDuplex/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Serdes_Ip_LinkUp/22 -> Serdes_Ip_MiiBusControlEnable/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Serdes_Ip_LinkUp/22 -> Serdes_Ip_LoopbackMode/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Serdes_Ip_LinkUp/22 -> Serdes_Ip_IssueRxReset/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Serdes_Ip_ANOption/21:
    callsite  Serdes_Ip_ANOption/21 -> Serdes_Ip_ANSettingsXpcs1/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Serdes_Ip_ANOption/21 -> Serdes_Ip_ANSettingsXpcs0/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Serdes_Ip_ANSettingsXpcs1/20:
  Jump functions of caller  Serdes_Ip_ANSettingsXpcs0/19:
  Jump functions of caller  Serdes_Ip_SetSpeedDuplex/18:
    callsite  Serdes_Ip_SetSpeedDuplex/18 -> Serdes_Ip_InitSpeedDuplex/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x44500000
         VR  [1077936128, 1141899264]
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Serdes_Ip_SetSpeedDuplex/18 -> Serdes_Ip_InitSpeedDuplex/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x44500000
         VR  [1077936128, 1141899264]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Serdes_Ip_MiiBusControlEnable/17:
  Jump functions of caller  Serdes_Ip_IssueRxReset/16:
  Jump functions of caller  Serdes_Ip_LoopbackMode/15:
  Jump functions of caller  Serdes_Ip_WaitSecondXpcsVendorReset/14:
  Jump functions of caller  Serdes_Ip_WaitFirstXpcsVendorReset/13:
  Jump functions of caller  Serdes_Ip_IssueXpcsVendorReset/12:
    callsite  Serdes_Ip_IssueXpcsVendorReset/12 -> Serdes_Ip_IssueReset/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Serdes_Ip_IssueXpcsVendorReset/12 -> Serdes_Ip_CheckSerdesClock/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Serdes_Ip_IssueXpcsVendorReset/12 -> Serdes_Ip_SetSerdesPcieMode/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Serdes_Ip_IssueReset/11:
  Jump functions of caller  Serdes_Ip_CheckSerdesClock/10:
    callsite  Serdes_Ip_CheckSerdesClock/10 -> Serdes_Ip_CheckSerdesXpcsClock/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Serdes_Ip_CheckSerdesXpcsClock/9:
  Jump functions of caller  Serdes_Ip_SetSerdesPcieMode/8:
    callsite  Serdes_Ip_SetSerdesPcieMode/8 -> Serdes_Ip_Pcie_Phy_Init/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Serdes_Ip_Pcie_Phy_Init/7:
  Jump functions of caller  Serdes_Ip_WaitDeviceReset_TrustedCall/6:
    callsite  Serdes_Ip_WaitDeviceReset_TrustedCall/6 -> Serdes_Ip_CheckPrstDeassert/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x14
         VR  [4, 16]
       param 1: UNKNOWN
         value: 0x0, mask: 0x15
         VR  [5, 17]
  Jump functions of caller  Serdes_Ip_SetXpcsSerdes1/5:
  Jump functions of caller  Serdes_Ip_CheckPrstDeassert/4:
  Jump functions of caller  Serdes_Ip_WaitPrstAssert/3:
  Jump functions of caller  Serdes_Ip_InitSpeedDuplex/2:

 Propagating constants:

Not considering Serdes_Ip_SetMode for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ip_MainFunction for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ip_GetStatus for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ip_GetJobResult for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ip_Init for cloning; -fipa-cp-clone disabled.
Not considering Serdes_Ip_SsModeConfigure_TrustedCall for cloning; -fipa-cp-clone disabled.

overall_size: 717, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Serdes_Ip_SetXpcsMode.part.0/58:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 11, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         uint32 [0, 1]
        AGGS VARIABLE
  Node: Serdes_Ip_SetMode/29:
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
  Node: Serdes_Ip_MainFunction/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Serdes_Ip_GetStatus/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Serdes_Ip_GetJobResult/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Serdes_Ip_Init/25:
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
  Node: Serdes_Ip_SsModeConfigure_TrustedCall/24:
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
  Node: Serdes_Ip_SetXpcsMode/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 1, loc_size: 26, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 26, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         uint32 [0, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_LinkUp/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_ANOption/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_ANSettingsXpcs1/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_ANSettingsXpcs0/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_SetSpeedDuplex/18:
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
  Node: Serdes_Ip_MiiBusControlEnable/17:
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
  Node: Serdes_Ip_IssueRxReset/16:
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
  Node: Serdes_Ip_LoopbackMode/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         uint32 [0, 255]
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
  Node: Serdes_Ip_WaitSecondXpcsVendorReset/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_WaitFirstXpcsVendorReset/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_IssueXpcsVendorReset/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_IssueReset/11:
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
  Node: Serdes_Ip_CheckSerdesClock/10:
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
  Node: Serdes_Ip_CheckSerdesXpcsClock/9:
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
  Node: Serdes_Ip_SetSerdesPcieMode/8:
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
  Node: Serdes_Ip_Pcie_Phy_Init/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_WaitDeviceReset_TrustedCall/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Serdes_Ip_SetXpcsSerdes1/5:
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
  Node: Serdes_Ip_CheckPrstDeassert/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x14
         uint32 [4, 16]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x15
         uint32 [5, 17]
        AGGS VARIABLE
  Node: Serdes_Ip_WaitPrstAssert/3:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x15
         uint32 [4, 17]
        AGGS VARIABLE
  Node: Serdes_Ip_InitSpeedDuplex/2:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x44500000
         uint32 [1077936128, 1141899264]
        AGGS VARIABLE
    param [1]: 0 [loc_time: 1, loc_size: 19, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 19, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         uint32 [0, 1]
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

IPA decision stage:

Propagated bits info for function Serdes_Ip_SetXpcsMode.part.0/58:
 param 1: value = 0x1, mask = 0x1
Propagated bits info for function Serdes_Ip_SetXpcsMode/23:
 param 1: value = 0x1, mask = 0x1
Propagated bits info for function Serdes_Ip_LoopbackMode/15:
 param 0: value = 0x0, mask = 0xff
Propagated bits info for function Serdes_Ip_CheckPrstDeassert/4:
 param 0: value = 0x0, mask = 0x14
 param 1: value = 0x0, mask = 0x15
Propagated bits info for function Serdes_Ip_WaitPrstAssert/3:
 param 0: value = 0x0, mask = 0x15
Propagated bits info for function Serdes_Ip_InitSpeedDuplex/2:
 param 0: value = 0x0, mask = 0x44500000
 param 1: value = 0x1, mask = 0x1

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Serdes_Ip_SetXpcsMode.part.0/58 (Serdes_Ip_SetXpcsMode.part.0) @077d8e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Serdes_Ip_SetXpcsMode/23 (268435456 (estimated locally),0.25 per call) 
  Calls: Serdes_Ip_SetPowerUpMode/55 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ip_SetPowerDownMode/57 (Serdes_Ip_SetPowerDownMode) @076b0ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_SetXpcsMode/23 (268435456 (estimated locally),0.25 per call) 
  Calls: 
Serdes_Ip_SetPowerSaveMode/56 (Serdes_Ip_SetPowerSaveMode) @076b0e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_SetXpcsMode/23 (268435456 (estimated locally),0.25 per call) 
  Calls: 
Serdes_Ip_SetPowerUpMode/55 (Serdes_Ip_SetPowerUpMode) @076b0d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_SetXpcsMode.part.0/58 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PcsAnEnable/54 (Serdes_Ip_PcsAnEnable) @076b09a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_ANSettingsXpcs1/20 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_ANSettingsXpcs0/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PcsAnAutoSwDisable/53 (Serdes_Ip_PcsAnAutoSwDisable) @076b08c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_ANSettingsXpcs1/20 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_ANSettingsXpcs0/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PcsAnSetLinkTimer/52 (Serdes_Ip_PcsAnSetLinkTimer) @076b07e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_ANSettingsXpcs1/20 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_ANSettingsXpcs0/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PcsAnRestart/51 (Serdes_Ip_PcsAnRestart) @076b0540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_ANOption/21 (287064877 (estimated locally),0.27 per call) Serdes_Ip_ANOption/21 (287064877 (estimated locally),0.27 per call) 
  Calls: 
Serdes_Ip_PcsSpeedSelect/50 (Serdes_Ip_PcsSpeedSelect) @076b02a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_InitSpeedDuplex/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PcsSetHd/49 (Serdes_Ip_PcsSetHd) @076b01c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_InitSpeedDuplex/2 (708669604 (estimated locally),0.66 per call) 
  Calls: 
Serdes_Ip_PcsSetFd/48 (Serdes_Ip_PcsSetFd) @076b00e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_InitSpeedDuplex/2 (365072220 (estimated locally),0.34 per call) 
  Calls: 
Serdes_Ip_PcsAnDisable/47 (Serdes_Ip_PcsAnDisable) @0769de00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_MiiBusControlEnable/17 (708669605 (estimated locally),0.66 per call) Serdes_Ip_MiiBusControlEnable/17 (708669605 (estimated locally),0.66 per call) 
  Calls: 
Serdes_Ip_PcsMiiBusControlEnable/46 (Serdes_Ip_PcsMiiBusControlEnable) @0769dd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_MiiBusControlEnable/17 (708669605 (estimated locally),0.66 per call) Serdes_Ip_MiiBusControlEnable/17 (708669605 (estimated locally),0.66 per call) 
  Calls: 
Serdes_Ip_PmaLoopbackDisable/45 (Serdes_Ip_PmaLoopbackDisable) @0769da80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_IssueRxReset/16 (536870913 (estimated locally),0.50 per call) Serdes_Ip_IssueRxReset/16 (536870913 (estimated locally),0.50 per call) 
  Calls: 
Serdes_Ip_PmaIssueRxReset/44 (Serdes_Ip_PmaIssueRxReset) @0769d9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_IssueRxReset/16 (708669605 (estimated locally),0.66 per call) Serdes_Ip_IssueRxReset/16 (708669605 (estimated locally),0.66 per call) 
  Calls: 
Serdes_Ip_PcsResetFinalizeAsync/43 (Serdes_Ip_PcsResetFinalizeAsync) @0769d540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_WaitSecondXpcsVendorReset/14 (365072220 (estimated locally),0.34 per call) Serdes_Ip_WaitSecondXpcsVendorReset/14 (365072220 (estimated locally),0.34 per call) Serdes_Ip_WaitFirstXpcsVendorReset/13 (633507677 (estimated locally),0.59 per call) Serdes_Ip_WaitFirstXpcsVendorReset/13 (440234148 (estimated locally),0.41 per call) 
  Calls: 
Serdes_Ip_PcsResetIssue/42 (Serdes_Ip_PcsResetIssue) @0769d380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_IssueReset/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PcsPmaInitGen2/41 (Serdes_Ip_PcsPmaInitGen2) @0769d2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_IssueReset/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PmaLoopbackEnable/40 (Serdes_Ip_PmaLoopbackEnable) @0769d1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_IssueReset/11 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_IssueReset/11 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_LoopbackMode/15 (354334802 (estimated locally),0.33 per call) Serdes_Ip_LoopbackMode/15 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Serdes_Ip_PcsWaitForPowerGood/39 (Serdes_Ip_PcsWaitForPowerGood) @0769d000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_CheckSerdesXpcsClock/9 (273804165 (estimated locally),0.26 per call) Serdes_Ip_CheckSerdesXpcsClock/9 (1073741823 (estimated locally),1.00 per call) Serdes_Ip_CheckSerdesXpcsClock/9 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PhyInit/38 (Serdes_Ip_PhyInit) @07588e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_Pcie_Phy_Init/7 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Serdes_Ip_PciePhySelectCRInterface/37 (Serdes_Ip_PciePhySelectCRInterface) @07588d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_Pcie_Phy_Init/7 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Serdes_Ip_PcieWaitReadMpllState/36 (Serdes_Ip_PcieWaitReadMpllState) @07588c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_Pcie_Phy_Init/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_PcieSetRefUsePad/35 (Serdes_Ip_PcieSetRefUsePad) @07588a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_SetSerdesPcieMode/8 (268435456 (estimated locally),0.25 per call) 
  Calls: 
Serdes_Ip_PcieClearRefUsePad/34 (Serdes_Ip_PcieClearRefUsePad) @075889a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_SetSerdesPcieMode/8 (268435456 (estimated locally),0.25 per call) 
  Calls: 
Serdes_Ip_PcieDeassertWarmReset/33 (Serdes_Ip_PcieDeassertWarmReset) @07588700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_IssueXpcsVendorReset/12 (118111601 (estimated locally),0.41 per call) 
  Calls: 
Serdes_Ip_PcieAssertWarmReset/32 (Serdes_Ip_PcieAssertWarmReset) @07588620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_IssueXpcsVendorReset/12 (118111600 (estimated locally),0.41 per call) 
  Calls: 
Serdes_Ip_TimeoutExpired/31 (Serdes_Ip_TimeoutExpired) @075750e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_WaitPrstAssert/3 (1073741824 (estimated locally),9.35 per call) 
  Calls: 
Serdes_Ip_StartTimeout/30 (Serdes_Ip_StartTimeout) @07575ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Serdes_Ip_WaitPrstAssert/3 (114863532 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_SetMode/29 (Serdes_Ip_SetMode) @075757e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_SetXpcsMode/23 (378925637 (estimated locally),0.35 per call) Serdes_Ip_SetXpcsMode/23 (378925637 (estimated locally),0.35 per call) 
Serdes_Ip_MainFunction/28 (Serdes_Ip_MainFunction) @07575540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073636847 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_LinkUp/22 (87501006 (estimated locally),0.08 per call) Serdes_Ip_WaitSecondXpcsVendorReset/14 (87501006 (estimated locally),0.08 per call) Serdes_Ip_WaitFirstXpcsVendorReset/13 (87501006 (estimated locally),0.08 per call) Serdes_Ip_IssueXpcsVendorReset/12 (87501006 (estimated locally),0.08 per call) Serdes_Ip_WaitDeviceReset_TrustedCall/6 (87501006 (estimated locally),0.08 per call) 
Serdes_Ip_GetStatus/27 (Serdes_Ip_GetStatus) @075752a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Serdes_Ip_DriverStatePtr/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Serdes_Ip_GetJobResult/26 (Serdes_Ip_GetJobResult) @07575000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Serdes_Ip_DriverStatePtr/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Serdes_Ip_Init/25 (Serdes_Ip_Init) @0756d700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_aInitFlags/1 (write)Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_aInitFlags/1 (write)Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_aInitFlags/1 (write)Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_aInitFlags/1 (write)Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: Serdes_Ip_SsModeConfigure_TrustedCall/24 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_SetXpcsSerdes1/5 (217325345 (estimated locally),0.20 per call) 
Serdes_Ip_SsModeConfigure_TrustedCall/24 (Serdes_Ip_SsModeConfigure_TrustedCall) @0756dd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: Serdes_Ip_Init/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_WaitPrstAssert/3 (118111600 (estimated locally),1.00 per call) Serdes_Ip_WaitPrstAssert/3 (118111600 (estimated locally),1.00 per call) 
Serdes_Ip_SetXpcsMode/23 (Serdes_Ip_SetXpcsMode) @0756d620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_SetMode/29 (378925637 (estimated locally),0.35 per call) Serdes_Ip_SetMode/29 (378925637 (estimated locally),0.35 per call) 
  Calls: Serdes_Ip_SetPowerDownMode/57 (268435456 (estimated locally),0.25 per call) Serdes_Ip_SetPowerSaveMode/56 (268435456 (estimated locally),0.25 per call) Serdes_Ip_SetXpcsMode.part.0/58 (268435456 (estimated locally),0.25 per call) 
Serdes_Ip_LinkUp/22 (Serdes_Ip_LinkUp) @0756d0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_MainFunction/28 (87501006 (estimated locally),0.08 per call) 
  Calls: Serdes_Ip_ANOption/21 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_SetSpeedDuplex/18 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_MiiBusControlEnable/17 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_LoopbackMode/15 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_IssueRxReset/16 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ip_ANOption/21 (Serdes_Ip_ANOption) @07569e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_LinkUp/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_PcsAnRestart/51 (287064877 (estimated locally),0.27 per call) Serdes_Ip_ANSettingsXpcs1/20 (287064877 (estimated locally),0.27 per call) Serdes_Ip_PcsAnRestart/51 (287064877 (estimated locally),0.27 per call) Serdes_Ip_ANSettingsXpcs0/19 (287064877 (estimated locally),0.27 per call) 
Serdes_Ip_ANSettingsXpcs1/20 (Serdes_Ip_ANSettingsXpcs1) @075699a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_ANOption/21 (287064877 (estimated locally),0.27 per call) 
  Calls: Serdes_Ip_PcsAnEnable/54 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PcsAnAutoSwDisable/53 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PcsAnSetLinkTimer/52 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ip_ANSettingsXpcs0/19 (Serdes_Ip_ANSettingsXpcs0) @07569460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_ANOption/21 (287064877 (estimated locally),0.27 per call) 
  Calls: Serdes_Ip_PcsAnEnable/54 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PcsAnAutoSwDisable/53 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PcsAnSetLinkTimer/52 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ip_SetSpeedDuplex/18 (Serdes_Ip_SetSpeedDuplex) @07562ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_LinkUp/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_InitSpeedDuplex/2 (496068723 (estimated locally),0.46 per call) Serdes_Ip_InitSpeedDuplex/2 (496068723 (estimated locally),0.46 per call) 
Serdes_Ip_MiiBusControlEnable/17 (Serdes_Ip_MiiBusControlEnable) @07562a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_LinkUp/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_PcsAnDisable/47 (708669605 (estimated locally),0.66 per call) Serdes_Ip_PcsAnDisable/47 (708669605 (estimated locally),0.66 per call) Serdes_Ip_PcsMiiBusControlEnable/46 (708669605 (estimated locally),0.66 per call) Serdes_Ip_PcsMiiBusControlEnable/46 (708669605 (estimated locally),0.66 per call) 
Serdes_Ip_IssueRxReset/16 (Serdes_Ip_IssueRxReset) @07562460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_aInitFlags/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_LinkUp/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_PmaLoopbackDisable/45 (536870913 (estimated locally),0.50 per call) Serdes_Ip_PmaLoopbackDisable/45 (536870913 (estimated locally),0.50 per call) Serdes_Ip_PmaIssueRxReset/44 (708669605 (estimated locally),0.66 per call) Serdes_Ip_PmaIssueRxReset/44 (708669605 (estimated locally),0.66 per call) 
Serdes_Ip_LoopbackMode/15 (Serdes_Ip_LoopbackMode) @0755ce00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_LinkUp/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_PmaLoopbackEnable/40 (354334802 (estimated locally),0.33 per call) Serdes_Ip_PmaLoopbackEnable/40 (354334802 (estimated locally),0.33 per call) 
Serdes_Ip_WaitSecondXpcsVendorReset/14 (Serdes_Ip_WaitSecondXpcsVendorReset) @0755c9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_MainFunction/28 (87501006 (estimated locally),0.08 per call) 
  Calls: Serdes_Ip_PcsResetFinalizeAsync/43 (365072220 (estimated locally),0.34 per call) Serdes_Ip_PcsResetFinalizeAsync/43 (365072220 (estimated locally),0.34 per call) 
Serdes_Ip_WaitFirstXpcsVendorReset/13 (Serdes_Ip_WaitFirstXpcsVendorReset) @0755c540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_MainFunction/28 (87501006 (estimated locally),0.08 per call) 
  Calls: Serdes_Ip_PcsResetFinalizeAsync/43 (633507677 (estimated locally),0.59 per call) Serdes_Ip_PcsResetFinalizeAsync/43 (440234148 (estimated locally),0.41 per call) 
Serdes_Ip_IssueXpcsVendorReset/12 (Serdes_Ip_IssueXpcsVendorReset) @0755c0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: local
  Function flags: count:288077074 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_MainFunction/28 (87501006 (estimated locally),0.08 per call) 
  Calls: Serdes_Ip_PcieDeassertWarmReset/33 (118111601 (estimated locally),0.41 per call) Serdes_Ip_PcieAssertWarmReset/32 (118111600 (estimated locally),0.41 per call) Serdes_Ip_IssueReset/11 (47532717 (estimated locally),0.16 per call) Serdes_Ip_CheckSerdesClock/10 (288077074 (estimated locally),1.00 per call) Serdes_Ip_SetSerdesPcieMode/8 (288077074 (estimated locally),1.00 per call) 
Serdes_Ip_IssueReset/11 (Serdes_Ip_IssueReset) @07554c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (read)Serdes_Ip_aInitFlags/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_IssueXpcsVendorReset/12 (47532717 (estimated locally),0.16 per call) 
  Calls: Serdes_Ip_PcsResetIssue/42 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PcsPmaInitGen2/41 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PmaLoopbackEnable/40 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PmaLoopbackEnable/40 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ip_CheckSerdesClock/10 (Serdes_Ip_CheckSerdesClock) @07554620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_aInitFlags/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_IssueXpcsVendorReset/12 (288077074 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_CheckSerdesXpcsClock/9 (177167401 (estimated locally),0.17 per call) 
Serdes_Ip_CheckSerdesXpcsClock/9 (Serdes_Ip_CheckSerdesXpcsClock) @07554380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_CheckSerdesClock/10 (177167401 (estimated locally),0.17 per call) 
  Calls: Serdes_Ip_PcsWaitForPowerGood/39 (273804165 (estimated locally),0.26 per call) Serdes_Ip_PcsWaitForPowerGood/39 (1073741823 (estimated locally),1.00 per call) Serdes_Ip_PcsWaitForPowerGood/39 (1073741823 (estimated locally),1.00 per call) 
Serdes_Ip_SetSerdesPcieMode/8 (Serdes_Ip_SetSerdesPcieMode) @0754ee00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_aInitFlags/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_IssueXpcsVendorReset/12 (288077074 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_Pcie_Phy_Init/7 (536870913 (estimated locally),0.50 per call) Serdes_Ip_PcieSetRefUsePad/35 (268435456 (estimated locally),0.25 per call) Serdes_Ip_PcieClearRefUsePad/34 (268435456 (estimated locally),0.25 per call) 
Serdes_Ip_Pcie_Phy_Init/7 (Serdes_Ip_Pcie_Phy_Init) @0754e7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_SetSerdesPcieMode/8 (536870913 (estimated locally),0.50 per call) 
  Calls: Serdes_Ip_PhyInit/38 (354334802 (estimated locally),0.33 per call) Serdes_Ip_PciePhySelectCRInterface/37 (354334802 (estimated locally),0.33 per call) Serdes_Ip_PcieWaitReadMpllState/36 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ip_WaitDeviceReset_TrustedCall/6 (Serdes_Ip_WaitDeviceReset_TrustedCall) @0754e0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_DriverStatePtr/0 (write)Serdes_Ip_DriverStatePtr/0 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_MainFunction/28 (87501006 (estimated locally),0.08 per call) 
  Calls: Serdes_Ip_CheckPrstDeassert/4 (1073741824 (estimated locally),1.00 per call) 
Serdes_Ip_SetXpcsSerdes1/5 (Serdes_Ip_SetXpcsSerdes1) @07531c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_aInitFlags/1 (write)Serdes_Ip_aInitFlags/1 (write)Serdes_Ip_aInitFlags/1 (read)Serdes_Ip_aInitFlags/1 (write)Serdes_Ip_aInitFlags/1 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_Init/25 (217325345 (estimated locally),0.20 per call) 
  Calls: 
Serdes_Ip_CheckPrstDeassert/4 (Serdes_Ip_CheckPrstDeassert) @075319a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_WaitDeviceReset_TrustedCall/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Serdes_Ip_WaitPrstAssert/3 (Serdes_Ip_WaitPrstAssert) @07531700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_SsModeConfigure_TrustedCall/24 (118111600 (estimated locally),1.00 per call) Serdes_Ip_SsModeConfigure_TrustedCall/24 (118111600 (estimated locally),1.00 per call) 
  Calls: Serdes_Ip_TimeoutExpired/31 (1073741824 (estimated locally),9.35 per call) Serdes_Ip_StartTimeout/30 (114863532 (estimated locally),1.00 per call) 
Serdes_Ip_InitSpeedDuplex/2 (Serdes_Ip_InitSpeedDuplex) @07531460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: Serdes_Ip_SetSpeedDuplex/18 (496068723 (estimated locally),0.46 per call) Serdes_Ip_SetSpeedDuplex/18 (496068723 (estimated locally),0.46 per call) 
  Calls: Serdes_Ip_PcsSpeedSelect/50 (1073741824 (estimated locally),1.00 per call) Serdes_Ip_PcsSetHd/49 (708669604 (estimated locally),0.66 per call) Serdes_Ip_PcsSetFd/48 (365072220 (estimated locally),0.34 per call) 
Serdes_Ip_aInitFlags/1 (Serdes_Ip_aInitFlags) @0752e558
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Serdes_Ip_IssueRxReset/16 (read)Serdes_Ip_CheckSerdesClock/10 (read)Serdes_Ip_IssueRxReset/16 (read)Serdes_Ip_SetXpcsSerdes1/5 (write)Serdes_Ip_SetSerdesPcieMode/8 (read)Serdes_Ip_SetXpcsSerdes1/5 (read)Serdes_Ip_SetXpcsSerdes1/5 (write)Serdes_Ip_SetXpcsSerdes1/5 (write)Serdes_Ip_SetXpcsSerdes1/5 (read)Serdes_Ip_SetXpcsSerdes1/5 (write)Serdes_Ip_IssueReset/11 (read)Serdes_Ip_Init/25 (read)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (read)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (read)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (read)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (read)
  Availability: available
  Varpool flags:
Serdes_Ip_DriverStatePtr/0 (Serdes_Ip_DriverStatePtr) @0752e4c8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Serdes_Ip_SetSpeedDuplex/18 (read)Serdes_Ip_LinkUp/22 (read)Serdes_Ip_IssueXpcsVendorReset/12 (write)Serdes_Ip_IssueXpcsVendorReset/12 (write)Serdes_Ip_WaitFirstXpcsVendorReset/13 (write)Serdes_Ip_WaitFirstXpcsVendorReset/13 (write)Serdes_Ip_LinkUp/22 (write)Serdes_Ip_LinkUp/22 (write)Serdes_Ip_LinkUp/22 (write)Serdes_Ip_LinkUp/22 (read)Serdes_Ip_SetXpcsMode/23 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_GetJobResult/26 (read)Serdes_Ip_ANOption/21 (read)Serdes_Ip_ANOption/21 (read)Serdes_Ip_WaitSecondXpcsVendorReset/14 (write)Serdes_Ip_SetXpcsMode.part.0/58 (write)Serdes_Ip_SetXpcsMode/23 (write)Serdes_Ip_GetStatus/27 (read)Serdes_Ip_WaitFirstXpcsVendorReset/13 (write)Serdes_Ip_IssueXpcsVendorReset/12 (write)Serdes_Ip_WaitDeviceReset_TrustedCall/6 (write)Serdes_Ip_CheckSerdesXpcsClock/9 (write)Serdes_Ip_MainFunction/28 (read)Serdes_Ip_MainFunction/28 (read)Serdes_Ip_WaitDeviceReset_TrustedCall/6 (write)Serdes_Ip_LinkUp/22 (write)Serdes_Ip_SetXpcsMode.part.0/58 (read)Serdes_Ip_Init/25 (write)Serdes_Ip_CheckSerdesXpcsClock/9 (write)Serdes_Ip_IssueReset/11 (read)Serdes_Ip_IssueXpcsVendorReset/12 (write)Serdes_Ip_IssueXpcsVendorReset/12 (write)Serdes_Ip_IssueXpcsVendorReset/12 (write)Serdes_Ip_WaitSecondXpcsVendorReset/14 (read)Serdes_Ip_WaitSecondXpcsVendorReset/14 (write)Serdes_Ip_IssueXpcsVendorReset/12 (read)Serdes_Ip_IssueXpcsVendorReset/12 (write)Serdes_Ip_WaitFirstXpcsVendorReset/13 (read)Serdes_Ip_WaitFirstXpcsVendorReset/13 (write)Serdes_Ip_SetSpeedDuplex/18 (read)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_Init/25 (write)Serdes_Ip_SetMode/29 (read)Serdes_Ip_SetMode/29 (read)
  Availability: available
  Varpool flags:

;; Function Serdes_Ip_WaitPrstAssert (Serdes_Ip_WaitPrstAssert, funcdef_no=1, decl_uid=6595, cgraph_uid=2, symbol_order=3)

Modification phase of node Serdes_Ip_WaitPrstAssert/3
Adjusting mask for param 0 to 0x15
Setting value range of param 0 [4, 17]
Serdes_Ip_WaitPrstAssert (uint32 PrstReg)
{
  boolean ResetStatus;
  boolean Timeout;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int TimeoutTicks.8_4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(uint32 *)1074233408B];
  _2 = 1 << PrstReg_11(D);
  _3 = _1 | _2;
  MEM[(uint32 *)1074233408B] = _3;
  # DEBUG BEGIN_STMT
  Serdes_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.8_4 = TimeoutTicks;
  Timeout_15 = Serdes_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.8_4);
  # DEBUG Timeout => Timeout_15
  # DEBUG BEGIN_STMT
  if (Timeout_15 != 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 1014686025]:
  _5 = MEM[(uint32 *)1074233664B];
  _6 = _2 & _5;
  if (_2 != _6)
    goto <bb 6>; [94.50%]
  else
    goto <bb 5>; [5.50%]

  <bb 6> [local count: 958878293]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _7 = MEM[(uint32 *)1074233664B];
  _8 = _2 & _7;
  ResetStatus_16 = _2 == _8;
  # DEBUG ResetStatus => ResetStatus_16
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return ResetStatus_16;

}



;; Function Serdes_Ip_InitSpeedDuplex (Serdes_Ip_InitSpeedDuplex, funcdef_no=0, decl_uid=6591, cgraph_uid=1, symbol_order=2)

Modification phase of node Serdes_Ip_InitSpeedDuplex/2
Adjusting mask for param 0 to 0x44500000
Adjusting mask for param 1 to 0x1
Setting value range of param 0 [1077936128, 1141899264]
Setting value range of param 1 [0, 1]
Serdes_Ip_InitSpeedDuplex (uint32 SerdesBase, uint32 Pcs, Serdes_Ip_MacSpeedType Speed, Serdes_Ip_MacDuplexType Duplex)
{
  uint32 SpeedSelect;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG SpeedSelect => 0
  # DEBUG BEGIN_STMT
  if (Duplex_3(D) == 2)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  Serdes_Ip_PcsSetFd (SerdesBase_5(D), Pcs_6(D));
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  Serdes_Ip_PcsSetHd (SerdesBase_5(D), Pcs_6(D));

  <bb 5> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  if (Speed_9(D) == 1)
    goto <bb 8>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  if (Speed_9(D) == 2)
    goto <bb 8>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 7> [local count: 467721938]:
  # DEBUG BEGIN_STMT
  # DEBUG SpeedSelect => 1

  <bb 8> [local count: 1073741824]:
  # SpeedSelect_1 = PHI <100(5), 10(6), 1(7)>
  # DEBUG SpeedSelect => SpeedSelect_1
  # DEBUG BEGIN_STMT
  Serdes_Ip_PcsSpeedSelect (SerdesBase_5(D), Pcs_6(D), SpeedSelect_1);
  return;

}



;; Function Serdes_Ip_SetXpcsMode (Serdes_Ip_SetXpcsMode, funcdef_no=21, decl_uid=6704, cgraph_uid=22, symbol_order=23)

Modification phase of node Serdes_Ip_SetXpcsMode/23
Adjusting mask for param 1 to 0x1
Setting value range of param 1 [0, 1]
Serdes_Ip_SetXpcsMode (uint8 Instance, uint32 Xpcs, Serdes_Ip_XpcsModeType XpcsMode)
{
  int _2;
  int _3;
  long unsigned int iftmp.52_4;
  long unsigned int iftmp.53_5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  switch (XpcsMode_6(D)) <default: <L14> [25.00%], case 1: <L0> [25.00%], case 2: <L4> [25.00%], case 3: <L8> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG D#1 => XpcsMode_6(D)
  Serdes_Ip_SetXpcsMode.part.0 (Instance_8(D), Xpcs_10(D));
  goto <bb 10>; [100.00%]

  <bb 4> [local count: 268435456]:
<L4>:
  # DEBUG BEGIN_STMT
  if (Instance_8(D) == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 134217728]:

  <bb 6> [local count: 268435456]:
  # iftmp.52_4 = PHI <1077936128(4), 1141899264(5)>
  Serdes_Ip_SetPowerSaveMode (iftmp.52_4, Xpcs_10(D));
  # DEBUG BEGIN_STMT
  _2 = (int) Instance_8(D);
  Serdes_Ip_DriverStatePtr[_2].XPCSMode = 2;
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 268435456]:
<L8>:
  # DEBUG BEGIN_STMT
  if (Instance_8(D) == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 134217728]:

  <bb 9> [local count: 268435456]:
  # iftmp.53_5 = PHI <1077936128(7), 1141899264(8)>
  Serdes_Ip_SetPowerDownMode (iftmp.53_5, Xpcs_10(D));
  # DEBUG BEGIN_STMT
  _3 = (int) Instance_8(D);
  Serdes_Ip_DriverStatePtr[_3].XPCSMode = 3;
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
<L14>:
  return;

}



;; Function Serdes_Ip_SsModeConfigure_TrustedCall (Serdes_Ip_SsModeConfigure_TrustedCall, funcdef_no=22, decl_uid=6584, cgraph_uid=23, symbol_order=24)

Modification phase of node Serdes_Ip_SsModeConfigure_TrustedCall/24
Serdes_Ip_SsModeConfigure_TrustedCall (uint8 Instance, Serdes_Ip_ModeType Mode, uint32 IntClks)
{
  volatile uint32 Wait;
  uint32 Config;
  boolean ResetStatus;
  boolean WaitPrstAssertPeriph5;
  boolean WaitPrstAssertPeriph4;
  long unsigned int _1;
  long unsigned int Wait.4_2;
  long unsigned int _3;
  long unsigned int Wait.5_4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  uint32 iftmp.0_9;
  uint32 iftmp.1_10;
  int iftmp.2_11;
  uint32 * iftmp.3_12;
  long unsigned int iftmp.6_13;
  long unsigned int iftmp.7_14;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Config => 0
  # DEBUG BEGIN_STMT
  Wait ={v} 80000;
  # DEBUG BEGIN_STMT
  # DEBUG Config => Mode_18(D)
  # DEBUG BEGIN_STMT
  _1 = IntClks_19(D) & 1048576;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  Config_20 = Mode_18(D) | 8388608;
  # DEBUG Config => Config_20

  <bb 4> [local count: 118111600]:
  # Config_8 = PHI <Mode_18(D)(2), Config_20(3)>
  # DEBUG Config => Config_8
  # DEBUG BEGIN_STMT
  if (Instance_21(D) == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 59055800]:

  <bb 6> [local count: 118111600]:
  # iftmp.0_9 = PHI <4(4), 16(5)>
  WaitPrstAssertPeriph4_23 = Serdes_Ip_WaitPrstAssert (iftmp.0_9);
  # DEBUG WaitPrstAssertPeriph4 => WaitPrstAssertPeriph4_23
  # DEBUG BEGIN_STMT
  if (Instance_21(D) == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 59055800]:

  <bb 8> [local count: 118111600]:
  # iftmp.1_10 = PHI <5(6), 17(7)>
  WaitPrstAssertPeriph5_25 = Serdes_Ip_WaitPrstAssert (iftmp.1_10);
  # DEBUG WaitPrstAssertPeriph5 => WaitPrstAssertPeriph5_25
  # DEBUG BEGIN_STMT
  if (WaitPrstAssertPeriph4_23 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 59055800]:
  if (WaitPrstAssertPeriph5_25 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 10> [local count: 88583700]:

  <bb 11> [local count: 118111600]:
  # iftmp.2_11 = PHI <1(9), 0(10)>
  ResetStatus_26 = (boolean) iftmp.2_11;
  # DEBUG ResetStatus => ResetStatus_26
  # DEBUG BEGIN_STMT
  if (Instance_21(D) == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 59055800]:

  <bb 13> [local count: 118111600]:
  # iftmp.3_12 = PHI <1078460656B(11), 1142423792B(12)>
  *iftmp.3_12 = Config_8;
  # DEBUG BEGIN_STMT
  Wait ={v} 100;
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  Wait.4_2 ={v} Wait;
  _3 = Wait.4_2 + 4294967295;
  Wait ={v} _3;

  <bb 15> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Wait.5_4 ={v} Wait;
  if (Wait.5_4 != 0)
    goto <bb 14>; [89.00%]
  else
    goto <bb 16>; [11.00%]

  <bb 16> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  _5 = MEM[(uint32 *)1074233408B];
  if (Instance_21(D) == 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 17> [local count: 59055800]:

  <bb 18> [local count: 118111601]:
  # iftmp.6_13 = PHI <4294967279(16), 4294901759(17)>
  _6 = _5 & iftmp.6_13;
  # DEBUG BEGIN_STMT
  if (Instance_21(D) == 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 19> [local count: 59055800]:

  <bb 20> [local count: 118111601]:
  # iftmp.7_14 = PHI <4294967263(18), 4294836223(19)>
  _7 = _6 & iftmp.7_14;
  MEM[(uint32 *)1074233408B] = _7;
  # DEBUG BEGIN_STMT
  return ResetStatus_26;

}



;; Function Serdes_Ip_Init (Serdes_Ip_Init, funcdef_no=23, decl_uid=6571, cgraph_uid=24, symbol_order=25)

Modification phase of node Serdes_Ip_Init/25
Serdes_Ip_Init (uint8 Instance, const struct Serdes_Ip_ConfigType * Serdes)
{
  Serdes_Ip_ModeType Mode;
  boolean ResetStatus;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  const struct Serdes_Ip_XpcsConfigType * _7;
  <unnamed type> _8;
  const struct Serdes_Ip_XpcsConfigType * _9;
  <unnamed type> _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_24(D);
  Serdes_Ip_DriverStatePtr[_1].SerdesCfg = Serdes_26(D);
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].DriverStatus = 2;
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].Job = 0;
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].XPCSMode = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Mode_31 = Serdes_26(D)->SerdesMode;
  # DEBUG Mode => Mode_31
  # DEBUG BEGIN_STMT
  if (Instance_24(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  _2 = Serdes_Ip_aInitFlags[0];
  _3 = _2 | 1024;
  # DEBUG BEGIN_STMT
  _4 = _3 | 262144;
  Serdes_Ip_aInitFlags[0] = _4;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  _5 = Serdes_Ip_aInitFlags[1];
  _6 = _5 | 263168;
  Serdes_Ip_aInitFlags[1] = _6;

  <bb 5> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  if (Instance_24(D) == 1)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  _7 = Serdes_26(D)->XPCS0;
  _8 = _7->XpcsSpeed;
  _9 = Serdes_26(D)->XPCS1;
  _10 = _9->XpcsSpeed;
  Serdes_Ip_SetXpcsSerdes1 (_8, _10);

  <bb 7> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  if (Mode_31 == 4)
    goto <bb 9>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 8> [local count: 708669604]:
  if (Mode_31 == 2)
    goto <bb 9>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 9> [local count: 606019886]:
  # DEBUG BEGIN_STMT
  _11 = Serdes_Ip_aInitFlags[_1];
  _12 = Serdes_26(D)->PhyReferenceClock;
  _13 = _11 | _12;
  _14 = _13 | 4194304;
  Serdes_Ip_aInitFlags[_1] = _14;
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 467721938]:
  # DEBUG BEGIN_STMT
  _15 = Serdes_Ip_aInitFlags[_1];
  _16 = Serdes_26(D)->PhyReferenceClock;
  _17 = _15 | _16;
  _18 = _17 | 2097152;
  Serdes_Ip_aInitFlags[_1] = _18;

  <bb 11> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _19 = Serdes_Ip_aInitFlags[_1];
  ResetStatus_38 = Serdes_Ip_SsModeConfigure_TrustedCall (Instance_24(D), Mode_31, _19);
  # DEBUG ResetStatus => ResetStatus_38
  # DEBUG BEGIN_STMT
  if (ResetStatus_38 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].DriverStatus = 1;
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].Job = 1;
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].JobResult = 2;
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].DriverStatus = 1;
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].Job = 1;
  # DEBUG BEGIN_STMT
  Serdes_Ip_DriverStatePtr[_1].JobResult = 4;

  <bb 14> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Serdes_Ip_GetJobResult (Serdes_Ip_GetJobResult, funcdef_no=24, decl_uid=6573, cgraph_uid=25, symbol_order=26)

Modification phase of node Serdes_Ip_GetJobResult/26
Serdes_Ip_GetJobResult (uint8 Instance)
{
  int _1;
  Serdes_Ip_JobResultType _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  _4 = Serdes_Ip_DriverStatePtr[_1].JobResult;
  return _4;

}



;; Function Serdes_Ip_GetStatus (Serdes_Ip_GetStatus, funcdef_no=25, decl_uid=6575, cgraph_uid=26, symbol_order=27)

Modification phase of node Serdes_Ip_GetStatus/27
Serdes_Ip_GetStatus (uint8 Instance)
{
  int _1;
  Serdes_Ip_StatusType _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  _4 = Serdes_Ip_DriverStatePtr[_1].DriverStatus;
  return _4;

}



;; Function Serdes_Ip_MainFunction (Serdes_Ip_MainFunction, funcdef_no=26, decl_uid=6577, cgraph_uid=27, symbol_order=28)

Modification phase of node Serdes_Ip_MainFunction/28
Serdes_Ip_MainFunction (uint8 Instance)
{
  Serdes_Ip_StatusType Status;
  <unnamed type> _1;
  int _6;
  <unnamed type> _13;

  <bb 2> [local count: 1073636847]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 2
  # DEBUG BEGIN_STMT
  # DEBUG Instance => Instance_5(D)
  # DEBUG INLINE_ENTRY Serdes_Ip_GetJobResult
  # DEBUG BEGIN_STMT
  _6 = (int) Instance_5(D);
  _13 = Serdes_Ip_DriverStatePtr[_6].JobResult;
  # DEBUG Instance => NULL
  # DEBUG SerdesJobResult => _13
  # DEBUG BEGIN_STMT
  if (_13 == 2)
    goto <bb 3>; [48.89%]
  else
    goto <bb 9>; [51.11%]

  <bb 3> [local count: 524901054]:
  # DEBUG BEGIN_STMT
  _1 = Serdes_Ip_DriverStatePtr[_6].Job;
  switch (_1) <default: <L10> [16.67%], case 1: <L1> [16.67%], case 2: <L2> [16.67%], case 3: <L3> [16.67%], case 4: <L4> [16.67%], case 5: <L5> [16.67%]>

  <bb 4> [local count: 87501006]:
<L1>:
  # DEBUG BEGIN_STMT
  Serdes_Ip_WaitDeviceReset_TrustedCall (Instance_5(D));
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 5> [local count: 87501006]:
<L2>:
  # DEBUG BEGIN_STMT
  Serdes_Ip_IssueXpcsVendorReset (Instance_5(D));
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 87501006]:
<L3>:
  # DEBUG BEGIN_STMT
  Serdes_Ip_WaitFirstXpcsVendorReset (Instance_5(D));
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 87501006]:
<L4>:
  # DEBUG BEGIN_STMT
  Serdes_Ip_WaitSecondXpcsVendorReset (Instance_5(D));
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 87501006]:
<L5>:
  # DEBUG BEGIN_STMT
  Status_8 = Serdes_Ip_LinkUp (Instance_5(D));
  # DEBUG Status => Status_8
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  # Status_2 = PHI <2(2), 2(4), 2(5), 2(6), 2(7), Status_8(8), 2(3)>
<L10>:
  # DEBUG Status => Status_2
  # DEBUG BEGIN_STMT
  return Status_2;

}



;; Function Serdes_Ip_SetMode (Serdes_Ip_SetMode, funcdef_no=27, decl_uid=6580, cgraph_uid=28, symbol_order=29)

Modification phase of node Serdes_Ip_SetMode/29
Serdes_Ip_SetMode (uint8 Instance, Serdes_Ip_XpcsModeType XpcsMode)
{
  Serdes_Ip_ModeType Mode;
  int _1;
  const struct Serdes_Ip_ConfigType * _2;
  const struct Serdes_Ip_XpcsConfigType * _3;
  const struct Serdes_Ip_ConfigType * _4;
  const struct Serdes_Ip_XpcsConfigType * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_8(D);
  _2 = Serdes_Ip_DriverStatePtr[_1].SerdesCfg;
  Mode_10 = _2->SerdesMode;
  # DEBUG Mode => Mode_10
  # DEBUG BEGIN_STMT
  if (Mode_10 != 2)
    goto <bb 3>; [66.00%]
  else
    goto <bb 5>; [34.00%]

  <bb 3> [local count: 708669605]:
  _3 = _2->XPCS0;
  if (_3 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 378925637]:
  # DEBUG BEGIN_STMT
  Serdes_Ip_SetXpcsMode (Instance_8(D), 0, XpcsMode_11(D));

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Mode_10 != 1)
    goto <bb 6>; [66.00%]
  else
    goto <bb 8>; [34.00%]

  <bb 6> [local count: 708669605]:
  _4 = Serdes_Ip_DriverStatePtr[_1].SerdesCfg;
  _5 = _4->XPCS1;
  if (_5 != 0B)
    goto <bb 7>; [53.47%]
  else
    goto <bb 8>; [46.53%]

  <bb 7> [local count: 378925637]:
  # DEBUG BEGIN_STMT
  Serdes_Ip_SetXpcsMode (Instance_8(D), 1, XpcsMode_11(D));

  <bb 8> [local count: 1073741824]:
  return;

}


