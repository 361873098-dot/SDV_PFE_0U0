
IPA constant propagation start:
Determining dynamic type for call: Port_Ipw_SetMode (u8MscrSiulInstance_28, u16MscrIdx_27, PinIndex_26(D), PinMode_29(D), pConfigPtr_25(D));
  Starting walk at: Port_Ipw_SetMode (u8MscrSiulInstance_28, u16MscrIdx_27, PinIndex_26(D), PinMode_29(D), pConfigPtr_25(D));
  instance pointer: pConfigPtr_25(D)  Outer instance pointer: pConfigPtr_25(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Port_Ipw_Init_UnusedPins (pConfigPtr_22(D));
  Starting walk at: Port_Ipw_Init_UnusedPins (pConfigPtr_22(D));
  instance pointer: pConfigPtr_22(D)  Outer instance pointer: pConfigPtr_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Siul2_Port_Ip_Init (15, _7);
Determining dynamic type for call: Port_Ipw_SetGpioPadOutput (PinIndex_19(D), pConfigPtr_18(D));
  Starting walk at: Port_Ipw_SetGpioPadOutput (PinIndex_19(D), pConfigPtr_18(D));
  instance pointer: pConfigPtr_18(D)  Outer instance pointer: pConfigPtr_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Port_Ipw_SetGpioDirChangeability (u8MscrSiulInstance_13(D), u16MscrIdx_15(D), 1);
Determining dynamic type for call: Port_Ipw_SetGpioPadOutput (PinIndex_19(D), pConfigPtr_18(D));
  Starting walk at: Port_Ipw_SetGpioPadOutput (PinIndex_19(D), pConfigPtr_18(D));
  instance pointer: pConfigPtr_18(D)  Outer instance pointer: pConfigPtr_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Port_Ipw_SetGpioDirChangeability (u8MscrSiulInstance_13(D), u16MscrIdx_15(D), 1);
Determining dynamic type for call: Port_Ipw_SetPinDirection (PinIndex_19(D), ePadDirection_20, pConfigPtr_18(D));
  Starting walk at: Port_Ipw_SetPinDirection (PinIndex_19(D), ePadDirection_20, pConfigPtr_18(D));
  instance pointer: pConfigPtr_18(D)  Outer instance pointer: pConfigPtr_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Port_Ipw_SetGpioPadOutput (PinIndex_19(D), pConfigPtr_18(D));
  Function call may change dynamic type:Port_Ipw_SetGpioDirChangeability (u8MscrSiulInstance_13(D), u16MscrIdx_15(D), 1);
  Function call may change dynamic type:Port_Ipw_SetGpioPadOutput (PinIndex_19(D), pConfigPtr_18(D));
Determining dynamic type for call: Port_Ipw_SetGpioMode (u8MscrSiulInstance_4(D), u16MscrIdx_5(D), PinIndex_10(D), pConfigPtr_11(D));
  Starting walk at: Port_Ipw_SetGpioMode (u8MscrSiulInstance_4(D), u16MscrIdx_5(D), PinIndex_10(D), pConfigPtr_11(D));
  instance pointer: pConfigPtr_11(D)  Outer instance pointer: pConfigPtr_11(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00/27:
  Jump functions of caller  SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00/26:
  Jump functions of caller  Det_ReportError/20:
  Jump functions of caller  Siul2_Port_Ip_Init/18:
  Jump functions of caller  Port_Ipw_SetAsUsedPin/17:
  Jump functions of caller  Port_Ipw_SetAsUnusedPin/16:
  Jump functions of caller  Port_Ipw_RefreshPortDirection/15:
  Jump functions of caller  Port_Ipw_SetGpioPadOutput/14:
  Jump functions of caller  Port_Ipw_SetGpioDirChangeability/13:
  Jump functions of caller  Port_Ipw_SetPinMode/12:
    callsite  Port_Ipw_SetPinMode/12 -> Port_Ipw_SetMode/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Port_Ipw_SetPinDirection/11:
  Jump functions of caller  Port_Ipw_Init/10:
    callsite  Port_Ipw_Init/10 -> Port_Ipw_Init_UnusedPins/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Port_Ipw_SetAltMode/9:
  Jump functions of caller  Port_Ipw_SetOnlyInputMode/8:
    callsite  Port_Ipw_SetOnlyInputMode/8 -> Port_Ipw_SetGpioDirChangeability/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Port_Ipw_SetGpioMode/7:
    callsite  Port_Ipw_SetGpioMode/7 -> Port_Ipw_SetPinDirection/11 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Port_Ipw_SetGpioMode/7 -> Port_Ipw_SetGpioPadOutput/14 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Port_Ipw_SetGpioMode/7 -> Port_Ipw_SetGpioPadOutput/14 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Port_Ipw_SetGpioMode/7 -> Port_Ipw_SetGpioDirChangeability/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Port_Ipw_SetInputMode/6:
    callsite  Port_Ipw_SetInputMode/6 -> Port_Ipw_SetGpioDirChangeability/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Port_Ipw_SetInoutMode/5:
    callsite  Port_Ipw_SetInoutMode/5 -> Port_Ipw_SetGpioDirChangeability/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Port_Ipw_SetInoutMode/5 -> Port_Ipw_GetIndexForInoutEntry/3 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Port_Ipw_SetMode/4:
    callsite  Port_Ipw_SetMode/4 -> Port_Ipw_SetGpioDirChangeability/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Port_Ipw_SetMode/4 -> Port_Ipw_SetAltMode/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Port_Ipw_SetMode/4 -> Port_Ipw_SetOnlyInputMode/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  Port_Ipw_SetMode/4 -> Port_Ipw_SetGpioMode/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Port_Ipw_SetMode/4 -> Port_Ipw_SetInputMode/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Port_Ipw_SetMode/4 -> Port_Ipw_SetInoutMode/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Port_Ipw_GetIndexForInoutEntry/3:
  Jump functions of caller  Port_Ipw_Init_UnusedPins/2:

 Propagating constants:

Not considering Port_Ipw_SetAsUsedPin for cloning; -fipa-cp-clone disabled.
Not considering Port_Ipw_SetAsUnusedPin for cloning; -fipa-cp-clone disabled.
Not considering Port_Ipw_RefreshPortDirection for cloning; -fipa-cp-clone disabled.
Not considering Port_Ipw_SetGpioPadOutput for cloning; -fipa-cp-clone disabled.
Not considering Port_Ipw_SetGpioDirChangeability for cloning; -fipa-cp-clone disabled.
Not considering Port_Ipw_SetPinMode for cloning; -fipa-cp-clone disabled.
Not considering Port_Ipw_SetPinDirection for cloning; -fipa-cp-clone disabled.
Not considering Port_Ipw_Init for cloning; -fipa-cp-clone disabled.

overall_size: 522, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Port_Ipw_SetAsUsedPin/17:
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
  Node: Port_Ipw_SetAsUnusedPin/16:
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
  Node: Port_Ipw_RefreshPortDirection/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Port_Ipw_SetGpioPadOutput/14:
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
  Node: Port_Ipw_SetGpioDirChangeability/13:
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
  Node: Port_Ipw_SetPinMode/12:
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
  Node: Port_Ipw_SetPinDirection/11:
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
  Node: Port_Ipw_Init/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Port_Ipw_SetAltMode/9:
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
  Node: Port_Ipw_SetOnlyInputMode/8:
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
  Node: Port_Ipw_SetGpioMode/7:
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
  Node: Port_Ipw_SetInputMode/6:
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
  Node: Port_Ipw_SetInoutMode/5:
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
  Node: Port_Ipw_SetMode/4:
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
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Port_Ipw_GetIndexForInoutEntry/3:
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
  Node: Port_Ipw_Init_UnusedPins/2:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00/27 (SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00) @074fc1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Port_Ipw_SetGpioDirChangeability/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00/26 (SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00) @074fc0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Port_Ipw_SetGpioDirChangeability/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Port_apInMuxSettings/25 (Port_apInMuxSettings) @074ee8b8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Port_Ipw_SetInputMode/6 (read)
  Availability: not_available
  Varpool flags: read-only
Port_apInMuxSettingsIndex/24 (Port_apInMuxSettingsIndex) @074ee870
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Port_Ipw_SetInputMode/6 (read)
  Availability: not_available
  Varpool flags: read-only
Port_au16NumInoutMuxSettings/23 (Port_au16NumInoutMuxSettings) @074ee750
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Port_Ipw_GetIndexForInoutEntry/3 (read)
  Availability: not_available
  Varpool flags: read-only
Port_apInoutMuxSettings/22 (Port_apInoutMuxSettings) @074ee3a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Port_Ipw_GetIndexForInoutEntry/3 (read)Port_Ipw_SetInoutMode/5 (read)
  Availability: not_available
  Varpool flags: read-only
Port_apSiul2InstancePinModeAvailability/21 (Port_apSiul2InstancePinModeAvailability) @0744ed38
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Port_Ipw_SetPinMode/12 (read)
  Availability: not_available
  Varpool flags: read-only
Det_ReportError/20 (Det_ReportError) @07446700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Port_Ipw_SetAsUsedPin/17 (159060892 (estimated locally),0.15 per call) Port_Ipw_SetAsUsedPin/17 (237404317 (estimated locally),0.22 per call) Port_Ipw_SetAsUsedPin/17 (354334802 (estimated locally),0.33 per call) Port_Ipw_SetAsUnusedPin/16 (159060892 (estimated locally),0.15 per call) Port_Ipw_SetAsUnusedPin/16 (237404317 (estimated locally),0.22 per call) Port_Ipw_SetAsUnusedPin/16 (354334802 (estimated locally),0.33 per call) Port_Ipw_SetPinMode/12 (159060893 (estimated locally),0.15 per call) Port_Ipw_SetPinMode/12 (237404317 (estimated locally),0.22 per call) Port_Ipw_SetPinMode/12 (354334802 (estimated locally),0.33 per call) Port_Ipw_SetPinDirection/11 (237404317 (estimated locally),0.22 per call) Port_Ipw_SetPinDirection/11 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Port_au32Siul2BaseAddr/19 (Port_au32Siul2BaseAddr) @0744e1f8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Port_Ipw_SetAsUnusedPin/16 (read)Port_Ipw_RefreshPortDirection/15 (read)Port_Ipw_Init_UnusedPins/2 (read)Port_Ipw_Init_UnusedPins/2 (read)Port_Ipw_SetGpioMode/7 (read)Port_Ipw_SetInputMode/6 (read)Port_Ipw_SetAltMode/9 (read)Port_Ipw_SetGpioPadOutput/14 (read)Port_Ipw_SetAsUnusedPin/16 (read)Port_Ipw_SetPinDirection/11 (read)Port_Ipw_SetInputMode/6 (read)Port_Ipw_SetOnlyInputMode/8 (read)Port_Ipw_SetInoutMode/5 (read)Port_Ipw_SetInoutMode/5 (read)Port_Ipw_SetAsUsedPin/17 (read)Port_Ipw_SetAsUsedPin/17 (read)
  Availability: not_available
  Varpool flags: read-only
Siul2_Port_Ip_Init/18 (Siul2_Port_Ip_Init) @07446460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Port_Ipw_Init/10 (41279180 (estimated locally),1.00 per call) 
  Calls: 
Port_Ipw_SetAsUsedPin/17 (Port_Ipw_SetAsUsedPin) @07446000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_au32Siul2BaseAddr/19 (read)Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: Det_ReportError/20 (159060892 (estimated locally),0.15 per call) Det_ReportError/20 (237404317 (estimated locally),0.22 per call) Det_ReportError/20 (354334802 (estimated locally),0.33 per call) 
Port_Ipw_SetAsUnusedPin/16 (Port_Ipw_SetAsUnusedPin) @0741ab60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_au32Siul2BaseAddr/19 (read)Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: Det_ReportError/20 (159060892 (estimated locally),0.15 per call) Det_ReportError/20 (237404317 (estimated locally),0.22 per call) Det_ReportError/20 (354334802 (estimated locally),0.33 per call) 
Port_Ipw_RefreshPortDirection/15 (Port_Ipw_RefreshPortDirection) @0741a620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Port_Ipw_SetGpioPadOutput/14 (Port_Ipw_SetGpioPadOutput) @0741a0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Port_Ipw_SetGpioMode/7 (86669348 (estimated locally),0.08 per call) Port_Ipw_SetGpioMode/7 (217325345 (estimated locally),0.20 per call) 
  Calls: 
Port_Ipw_SetGpioDirChangeability/13 (Port_Ipw_SetGpioDirChangeability) @0741ad20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_Ipw_au16GPIODirChangeability/1 (read)Port_Ipw_au16GPIODirChangeability/1 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Port_Ipw_SetMode/4 (178956971 (estimated locally),0.17 per call) Port_Ipw_SetGpioMode/7 (1073741823 (estimated locally),1.00 per call) Port_Ipw_SetOnlyInputMode/8 (1073741824 (estimated locally),1.00 per call) Port_Ipw_SetInputMode/6 (1073741824 (estimated locally),1.00 per call) Port_Ipw_SetInoutMode/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00/27 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00/26 (1073741824 (estimated locally),1.00 per call) 
Port_Ipw_SetPinMode/12 (Port_Ipw_SetPinMode) @0741aa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_apSiul2InstancePinModeAvailability/21 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Port_Ipw_SetMode/4 (100275047 (estimated locally),0.09 per call) Det_ReportError/20 (159060893 (estimated locally),0.15 per call) Det_ReportError/20 (237404317 (estimated locally),0.22 per call) Det_ReportError/20 (354334802 (estimated locally),0.33 per call) 
Port_Ipw_SetPinDirection/11 (Port_Ipw_SetPinDirection) @0741a7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_Ipw_au16GPIODirChangeability/1 (read)Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: Port_Ipw_SetGpioMode/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: Det_ReportError/20 (237404317 (estimated locally),0.22 per call) Det_ReportError/20 (354334802 (estimated locally),0.33 per call) 
Port_Ipw_Init/10 (Port_Ipw_Init) @0741a540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Port_Ipw_au16GPIODirChangeability/1 (write)
  Referring: 
  Availability: available
  Function flags: count:41279181 (estimated locally) body optimize_size
  Called by: 
  Calls: Port_Ipw_Init_UnusedPins/2 (41279180 (estimated locally),1.00 per call) Siul2_Port_Ip_Init/18 (41279180 (estimated locally),1.00 per call) 
Port_Ipw_SetAltMode/9 (Port_Ipw_SetAltMode) @0741a2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Port_Ipw_SetMode/4 (178956971 (estimated locally),0.17 per call) 
  Calls: 
Port_Ipw_SetOnlyInputMode/8 (Port_Ipw_SetOnlyInputMode) @0741a000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Port_Ipw_SetMode/4 (178956971 (estimated locally),0.17 per call) 
  Calls: Port_Ipw_SetGpioDirChangeability/13 (1073741824 (estimated locally),1.00 per call) 
Port_Ipw_SetGpioMode/7 (Port_Ipw_SetGpioMode) @07407c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: Port_Ipw_SetMode/4 (178956971 (estimated locally),0.17 per call) 
  Calls: Port_Ipw_SetPinDirection/11 (1073741824 (estimated locally),1.00 per call) Port_Ipw_SetGpioPadOutput/14 (86669348 (estimated locally),0.08 per call) Port_Ipw_SetGpioPadOutput/14 (217325345 (estimated locally),0.20 per call) Port_Ipw_SetGpioDirChangeability/13 (1073741823 (estimated locally),1.00 per call) 
Port_Ipw_SetInputMode/6 (Port_Ipw_SetInputMode) @07407700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Port_au32Siul2BaseAddr/19 (read)Port_apInMuxSettingsIndex/24 (read)Port_apInMuxSettings/25 (read)Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Port_Ipw_SetMode/4 (178956971 (estimated locally),0.17 per call) 
  Calls: Port_Ipw_SetGpioDirChangeability/13 (1073741824 (estimated locally),1.00 per call) 
Port_Ipw_SetInoutMode/5 (Port_Ipw_SetInoutMode) @07407e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Port_au32Siul2BaseAddr/19 (read)Port_apInoutMuxSettings/22 (read)Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Port_Ipw_SetMode/4 (178956971 (estimated locally),0.17 per call) 
  Calls: Port_Ipw_SetGpioDirChangeability/13 (1073741824 (estimated locally),1.00 per call) Port_Ipw_GetIndexForInoutEntry/3 (1073741824 (estimated locally),1.00 per call) 
Port_Ipw_SetMode/4 (Port_Ipw_SetMode) @07407b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073527120 (estimated locally) body local optimize_size
  Called by: Port_Ipw_SetPinMode/12 (100275047 (estimated locally),0.09 per call) 
  Calls: Port_Ipw_SetGpioDirChangeability/13 (178956971 (estimated locally),0.17 per call) Port_Ipw_SetAltMode/9 (178956971 (estimated locally),0.17 per call) Port_Ipw_SetOnlyInputMode/8 (178956971 (estimated locally),0.17 per call) Port_Ipw_SetGpioMode/7 (178956971 (estimated locally),0.17 per call) Port_Ipw_SetInputMode/6 (178956971 (estimated locally),0.17 per call) Port_Ipw_SetInoutMode/5 (178956971 (estimated locally),0.17 per call) 
Port_Ipw_GetIndexForInoutEntry/3 (Port_Ipw_GetIndexForInoutEntry) @074078c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Port_apInoutMuxSettings/22 (read)Port_au16NumInoutMuxSettings/23 (read)
  Referring: 
  Availability: local
  Function flags: count:78030430 (estimated locally) body local optimize_size
  Called by: Port_Ipw_SetInoutMode/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Port_Ipw_Init_UnusedPins/2 (Port_Ipw_Init_UnusedPins) @07407620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Port_au32Siul2BaseAddr/19 (read)Port_au32Siul2BaseAddr/19 (read)
  Referring: 
  Availability: local
  Function flags: count:118111602 (estimated locally) body local optimize_size
  Called by: Port_Ipw_Init/10 (41279180 (estimated locally),1.00 per call) 
  Calls: 
Port_Ipw_au16GPIODirChangeability/1 (Port_Ipw_au16GPIODirChangeability) @073bd5a0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Port_Ipw_Init/10 (write)Port_Ipw_SetPinDirection/11 (read)Port_Ipw_SetGpioDirChangeability/13 (read)Port_Ipw_SetGpioDirChangeability/13 (write)
  Availability: available
  Varpool flags:

;; Function Port_Ipw_Init (Port_Ipw_Init, funcdef_no=9, decl_uid=6201, cgraph_uid=10, symbol_order=10)

Modification phase of node Port_Ipw_Init/10
Port_Ipw_Init (const struct Port_ConfigType * pConfigPtr)
{
  struct SIUL2_Type * imcrBase;
  uint8 u8Imcr;
  uint16 u16ImcrIdx;
  uint8 u8ImcrSiulInstance;
  uint16 u16Counter;
  const Port_Siul2_ImcrConfigType * _1;
  sizetype _2;
  const Port_Siul2_ImcrConfigType * _3;
  unsigned int _4;
  int _5;
  short unsigned int _6;
  const struct Siul2_Port_Ip_PinSettingsConfig * _7;
  int _8;
  int _9;
  short unsigned int _20;

  <bb 2> [local count: 41279181]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG imcrBase => 1074380800B
  # DEBUG BEGIN_STMT
  # DEBUG u8ImcrSiulInstance => 0
  goto <bb 11>; [100.00%]

  <bb 3> [local count: 668072387]:
  # DEBUG BEGIN_STMT
  _1 = pConfigPtr_22(D)->pImcrConfig[_5];
  _2 = (sizetype) u16ImcrIdx_13;
  _3 = _1 + _2;
  u8Imcr_29 = *_3;
  # DEBUG u8Imcr => u8Imcr_29
  # DEBUG BEGIN_STMT
  if (u8Imcr_29 != 255)
    goto <bb 4>; [66.00%]
  else
    goto <bb 8>; [34.00%]

  <bb 4> [local count: 440927775]:
  # DEBUG BEGIN_STMT
  if (u16ImcrIdx_13 <= 83)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 220463888]:
  # DEBUG BEGIN_STMT
  # DEBUG imcrBase => 1140916224B

  <bb 6> [local count: 440927775]:
  # imcrBase_14 = PHI <1074380800B(4), 1140916224B(5)>
  # DEBUG imcrBase => imcrBase_14
  # DEBUG BEGIN_STMT
  if (u16ImcrIdx_13 <= 495)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 220463888]:
  # DEBUG BEGIN_STMT
  _20 = u16ImcrIdx_13 & 511;
  _4 = (unsigned int) _20;
  imcrBase_14->IMCR[_4] ={v} 0;

  <bb 8> [local count: 668072387]:
  # DEBUG BEGIN_STMT
  u16ImcrIdx_31 = u16ImcrIdx_13 + 1;
  # DEBUG u16ImcrIdx => u16ImcrIdx_31

  <bb 9> [local count: 750643132]:
  # u16ImcrIdx_13 = PHI <u16ImcrIdx_31(8), 0(19)>
  # DEBUG u16ImcrIdx => u16ImcrIdx_13
  # DEBUG BEGIN_STMT
  _5 = (int) u8ImcrSiulInstance_11;
  _6 = pConfigPtr_22(D)->au16NumImcrs[_5];
  if (_6 > u16ImcrIdx_13)
    goto <bb 3>; [89.00%]
  else
    goto <bb 10>; [11.00%]

  <bb 10> [local count: 82570744]:
  # DEBUG BEGIN_STMT
  u8ImcrSiulInstance_28 = u8ImcrSiulInstance_11 + 1;
  # DEBUG u8ImcrSiulInstance => u8ImcrSiulInstance_28

  <bb 11> [local count: 123849926]:
  # u8ImcrSiulInstance_11 = PHI <0(2), u8ImcrSiulInstance_28(10)>
  # DEBUG u8ImcrSiulInstance => u8ImcrSiulInstance_11
  # DEBUG BEGIN_STMT
  if (u8ImcrSiulInstance_11 != 2)
    goto <bb 19>; [66.67%]
  else
    goto <bb 12>; [33.33%]

  <bb 19> [local count: 82570745]:
  goto <bb 9>; [100.00%]

  <bb 12> [local count: 41279180]:
  # DEBUG BEGIN_STMT
  _7 = pConfigPtr_22(D)->IpConfigPtr;
  Siul2_Port_Ip_Init (15, _7);
  # DEBUG BEGIN_STMT
  Port_Ipw_Init_UnusedPins (pConfigPtr_22(D));
  # DEBUG BEGIN_STMT
  # DEBUG u8ImcrSiulInstance => 0
  goto <bb 16>; [100.00%]

  <bb 13> [local count: 991171080]:
  # DEBUG BEGIN_STMT
  _8 = (int) u8ImcrSiulInstance_12;
  _9 = (int) u16Counter_10;
  Port_Ipw_au16GPIODirChangeability[_8][_9] = 0;
  # DEBUG BEGIN_STMT
  u16Counter_27 = u16Counter_10 + 1;
  # DEBUG u16Counter => u16Counter_27

  <bb 14> [local count: 1073741824]:
  # u16Counter_10 = PHI <u16Counter_27(13), 0(18)>
  # DEBUG u16Counter => u16Counter_10
  # DEBUG BEGIN_STMT
  if (u16Counter_10 != 12)
    goto <bb 13>; [92.31%]
  else
    goto <bb 15>; [7.69%]

  <bb 15> [local count: 82570746]:
  # DEBUG BEGIN_STMT
  u8ImcrSiulInstance_25 = u8ImcrSiulInstance_12 + 1;
  # DEBUG u8ImcrSiulInstance => u8ImcrSiulInstance_25

  <bb 16> [local count: 123849926]:
  # u8ImcrSiulInstance_12 = PHI <0(12), u8ImcrSiulInstance_25(15)>
  # DEBUG u8ImcrSiulInstance => u8ImcrSiulInstance_12
  # DEBUG BEGIN_STMT
  if (u8ImcrSiulInstance_12 != 2)
    goto <bb 18>; [66.67%]
  else
    goto <bb 17>; [33.33%]

  <bb 18> [local count: 82570746]:
  goto <bb 14>; [100.00%]

  <bb 17> [local count: 41279181]:
  return;

}



;; Function Port_Ipw_SetPinDirection (Port_Ipw_SetPinDirection, funcdef_no=10, decl_uid=6205, cgraph_uid=11, symbol_order=11)

Modification phase of node Port_Ipw_SetPinDirection/11
Port_Ipw_SetPinDirection (Port_PinType PinIndex, Port_PinDirectionType eDirection, const struct Port_ConfigType * pConfigPtr)
{
  uint16 u16PinChangeDirFlagWord;
  uint8 u8PinDescBitOffset;
  Std_ReturnType PinDirError;
  uint32 u32LocalMSCR;
  uint8 u8MscrSiulInstance;
  uint16 u16MscrIdx;
  const struct Port_Siul2_PinConfigType * _1;
  long unsigned int _2;
  const struct Port_Siul2_PinConfigType * _3;
  short unsigned int _4;
  long unsigned int _5;
  const uint32 * _6;
  long unsigned int _7;
  const uint32 * _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned char _11;
  int _12;
  short unsigned int _13;
  unsigned char _14;
  int _15;
  _Bool _16;
  int _17;
  long unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  volatile uint32 * _26;
  long unsigned int _35;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  _1 = pConfigPtr_31(D)->pUsedPadConfig;
  _2 = PinIndex_32(D) * 24;
  _3 = _1 + _2;
  u16MscrIdx_33 = _3->u16MscrIdx;
  # DEBUG u16MscrIdx => u16MscrIdx_33
  # DEBUG BEGIN_STMT
  u8MscrSiulInstance_34 = _3->u8MscrSiulInstance;
  # DEBUG u8MscrSiulInstance => u8MscrSiulInstance_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG PinDirError => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG CoreId => 0
  # DEBUG BEGIN_STMT
  _4 = pConfigPtr_31(D)->u16NumPins;
  _5 = (long unsigned int) _4;
  if (_5 <= PinIndex_32(D))
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 1, 10);
  goto <bb 16>; [100.00%]

  <bb 4> [local count: 719407022]:
  # DEBUG BEGIN_STMT
  _6 = pConfigPtr_31(D)->pau32Port_PinToPartitionMap;
  _7 = PinIndex_32(D) * 4;
  _8 = _6 + _7;
  _9 = *_8;
  _10 = _9 & 1;
  if (_10 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 1, 240);
  goto <bb 16>; [100.00%]

  <bb 6> [local count: 482002704]:
  # DEBUG BEGIN_STMT
  _11 = (unsigned char) u16MscrIdx_33;
  u8PinDescBitOffset_36 = _11 & 15;
  # DEBUG u8PinDescBitOffset => u8PinDescBitOffset_36
  # DEBUG BEGIN_STMT
  _12 = (int) u8MscrSiulInstance_34;
  _13 = u16MscrIdx_33 >> 4;
  _14 = (unsigned char) _13;
  _15 = (int) _14;
  u16PinChangeDirFlagWord_37 = Port_Ipw_au16GPIODirChangeability[_12][_15];
  # DEBUG u16PinChangeDirFlagWord => u16PinChangeDirFlagWord_37
  # DEBUG BEGIN_STMT
  _16 = _3->bDC;
  if (_16 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 241001352]:
  _17 = (int) u8PinDescBitOffset_36;
  _18 = 1 << _17;
  _19 = (short unsigned int) _18;
  _20 = _19 & u16PinChangeDirFlagWord_37;
  if (_20 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 8> [local count: 361502028]:
  # DEBUG BEGIN_STMT
  _21 = Port_au32Siul2BaseAddr[_12];
  _22 = (long unsigned int) u16MscrIdx_33;
  _23 = _22 << 2;
  _24 = _21 + _23;
  _25 = _24 + 576;
  _26 = (volatile uint32 *) _25;
  u32LocalMSCR_38 ={v} *_26;
  # DEBUG u32LocalMSCR => u32LocalMSCR_38
  # DEBUG BEGIN_STMT
  if (eDirection_39(D) == 1)
    goto <bb 9>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 9> [local count: 122910689]:
  # DEBUG BEGIN_STMT
  u32LocalMSCR_43 = u32LocalMSCR_38 & 4294443007;
  # DEBUG u32LocalMSCR => u32LocalMSCR_43
  # DEBUG BEGIN_STMT
  u32LocalMSCR_44 = u32LocalMSCR_43 | 2097152;
  # DEBUG u32LocalMSCR => u32LocalMSCR_44
  goto <bb 15>; [100.00%]

  <bb 10> [local count: 238591338]:
  # DEBUG BEGIN_STMT
  if (eDirection_39(D) == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 119295669]:
  # DEBUG BEGIN_STMT
  # DEBUG u32LocalMSCR => u32LocalMSCR_38 | 524288
  # DEBUG BEGIN_STMT
  _35 = u32LocalMSCR_38 & 4292870143;
  u32LocalMSCR_42 = _35 | 524288;
  # DEBUG u32LocalMSCR => u32LocalMSCR_42
  goto <bb 15>; [100.00%]

  <bb 12> [local count: 119295669]:
  # DEBUG BEGIN_STMT
  if (eDirection_39(D) == 2)
    goto <bb 13>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 13> [local count: 40560528]:
  # DEBUG BEGIN_STMT
  # DEBUG u32LocalMSCR => u32LocalMSCR_38 | 524288
  # DEBUG BEGIN_STMT
  u32LocalMSCR_41 = u32LocalMSCR_38 | 2621440;
  # DEBUG u32LocalMSCR => u32LocalMSCR_41
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 78735142]:
  # DEBUG BEGIN_STMT
  # DEBUG u32LocalMSCR => u32LocalMSCR_38 & 4294443007
  # DEBUG BEGIN_STMT
  u32LocalMSCR_40 = u32LocalMSCR_38 & 4292345855;
  # DEBUG u32LocalMSCR => u32LocalMSCR_40

  <bb 15> [local count: 361502028]:
  # u32LocalMSCR_27 = PHI <u32LocalMSCR_44(9), u32LocalMSCR_42(11), u32LocalMSCR_41(13), u32LocalMSCR_40(14)>
  # DEBUG u32LocalMSCR => u32LocalMSCR_27
  # DEBUG BEGIN_STMT
  *_26 ={v} u32LocalMSCR_27;

  <bb 16> [local count: 1073741824]:
  # PinDirError_28 = PHI <0(3), 0(5), 0(15), 1(7)>
  # DEBUG PinDirError => PinDirError_28
  # DEBUG BEGIN_STMT
  return PinDirError_28;

}



;; Function Port_Ipw_SetGpioDirChangeability (Port_Ipw_SetGpioDirChangeability, funcdef_no=12, decl_uid=6413, cgraph_uid=13, symbol_order=13)

Modification phase of node Port_Ipw_SetGpioDirChangeability/13
Port_Ipw_SetGpioDirChangeability (uint8 u8ImcrSiulInstance, uint16 u16MscrIdx, boolean bStatus)
{
  uint8 u8PinBitOffset;
  uint16 u16PinDirFlagWord;
  unsigned char _1;
  int _2;
  unsigned char _3;
  int _4;
  int _5;
  long unsigned int _6;
  short unsigned int _7;
  int _8;
  long unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00 ();
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) u16MscrIdx_15(D);
  u8PinBitOffset_16 = _1 & 15;
  # DEBUG u8PinBitOffset => u8PinBitOffset_16
  # DEBUG BEGIN_STMT
  _2 = (int) u8ImcrSiulInstance_17(D);
  _3 = _1 >> 4;
  _4 = (int) _3;
  u16PinDirFlagWord_18 = Port_Ipw_au16GPIODirChangeability[_2][_4];
  # DEBUG u16PinDirFlagWord => u16PinDirFlagWord_18
  # DEBUG BEGIN_STMT
  if (bStatus_19(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _5 = (int) u8PinBitOffset_16;
  _6 = 1 << _5;
  _7 = (short unsigned int) _6;
  u16PinDirFlagWord_21 = _7 | u16PinDirFlagWord_18;
  # DEBUG u16PinDirFlagWord => u16PinDirFlagWord_21
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 = (int) u8PinBitOffset_16;
  _9 = 1 << _8;
  _10 = (short unsigned int) _9;
  _11 = ~_10;
  u16PinDirFlagWord_20 = _11 & u16PinDirFlagWord_18;
  # DEBUG u16PinDirFlagWord => u16PinDirFlagWord_20

  <bb 5> [local count: 1073741824]:
  # u16PinDirFlagWord_12 = PHI <u16PinDirFlagWord_21(3), u16PinDirFlagWord_20(4)>
  # DEBUG u16PinDirFlagWord => u16PinDirFlagWord_12
  # DEBUG BEGIN_STMT
  Port_Ipw_au16GPIODirChangeability[_2][_4] = u16PinDirFlagWord_12;
  # DEBUG BEGIN_STMT
  SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00 ();
  return;

}



;; Function Port_Ipw_SetGpioPadOutput (Port_Ipw_SetGpioPadOutput, funcdef_no=13, decl_uid=6416, cgraph_uid=14, symbol_order=14)

Modification phase of node Port_Ipw_SetGpioPadOutput/14
Port_Ipw_SetGpioPadOutput (Port_PinType PinIndex, const struct Port_ConfigType * pConfigPtr)
{
  uint8 u8LocalPDO;
  uint8 u8MscrSiulInstance;
  uint16 u16MscrIdx;
  const struct Port_Siul2_PinConfigType * _1;
  long unsigned int _2;
  const struct Port_Siul2_PinConfigType * _3;
  int _4;
  long unsigned int _5;
  short unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  volatile uint8 * _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pConfigPtr_13(D)->pUsedPadConfig;
  _2 = PinIndex_14(D) * 24;
  _3 = _1 + _2;
  u16MscrIdx_15 = _3->u16MscrIdx;
  # DEBUG u16MscrIdx => u16MscrIdx_15
  # DEBUG BEGIN_STMT
  u8MscrSiulInstance_16 = _3->u8MscrSiulInstance;
  # DEBUG u8MscrSiulInstance => u8MscrSiulInstance_16
  # DEBUG BEGIN_STMT
  u8LocalPDO_17 = _3->u8PDO;
  # DEBUG u8LocalPDO => u8LocalPDO_17
  # DEBUG BEGIN_STMT
  if (u8LocalPDO_17 != 2)
    goto <bb 3>; [66.00%]
  else
    goto <bb 4>; [34.00%]

  <bb 3> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _4 = (int) u8MscrSiulInstance_16;
  _5 = Port_au32Siul2BaseAddr[_4];
  _6 = u16MscrIdx_15 ^ 3;
  _7 = (long unsigned int) _6;
  _8 = _5 + _7;
  _9 = _8 + 4864;
  _10 = (volatile uint8 *) _9;
  *_10 ={v} u8LocalPDO_17;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Port_Ipw_SetPinMode (Port_Ipw_SetPinMode, funcdef_no=11, decl_uid=6217, cgraph_uid=12, symbol_order=12)

Modification phase of node Port_Ipw_SetPinMode/12
Port_Ipw_SetPinMode (Port_PinType PinIndex, Port_PinModeType PinMode, const struct Port_ConfigType * pConfigPtr)
{
  uint8 u8PinDescBitOffset;
  uint16 u16PinDescWord;
  uint8 u8MscrSiulInstance;
  uint16 u16MscrIdx;
  Std_ReturnType PinModeError;
  const struct Port_Siul2_PinConfigType * _1;
  long unsigned int _2;
  const struct Port_Siul2_PinConfigType * _3;
  short unsigned int _4;
  long unsigned int _5;
  const uint32 * _6;
  long unsigned int _7;
  const uint32 * _8;
  long unsigned int _9;
  long unsigned int _10;
  _Bool _11;
  unsigned char _12;
  int _13;
  const uint16[21][12] * _14;
  int _15;
  short unsigned int _16;
  int _17;
  int _18;
  long unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG PinModeError => 0
  # DEBUG BEGIN_STMT
  _1 = pConfigPtr_25(D)->pUsedPadConfig;
  _2 = PinIndex_26(D) * 24;
  _3 = _1 + _2;
  u16MscrIdx_27 = _3->u16MscrIdx;
  # DEBUG u16MscrIdx => u16MscrIdx_27
  # DEBUG BEGIN_STMT
  u8MscrSiulInstance_28 = _3->u8MscrSiulInstance;
  # DEBUG u8MscrSiulInstance => u8MscrSiulInstance_28
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG CoreId => 0
  # DEBUG BEGIN_STMT
  _4 = pConfigPtr_25(D)->u16NumPins;
  _5 = (long unsigned int) _4;
  if (_5 <= PinIndex_26(D))
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 4, 10);
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  _6 = pConfigPtr_25(D)->pau32Port_PinToPartitionMap;
  _7 = PinIndex_26(D) * 4;
  _8 = _6 + _7;
  _9 = *_8;
  _10 = _9 & 1;
  if (_10 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 4, 240);
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 482002705]:
  # DEBUG BEGIN_STMT
  _11 = _3->bMC;
  if (_11 != 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 7> [local count: 159060893]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 4, 14);
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 322941812]:
  # DEBUG BEGIN_STMT
  if (PinMode_29(D) > 20)
    goto <bb 11>; [35.00%]
  else
    goto <bb 9>; [65.00%]

  <bb 9> [local count: 209912178]:
  # DEBUG BEGIN_STMT
  _12 = (unsigned char) u16MscrIdx_27;
  u8PinDescBitOffset_30 = _12 & 15;
  # DEBUG u8PinDescBitOffset => u8PinDescBitOffset_30
  # DEBUG BEGIN_STMT
  _13 = (int) u8MscrSiulInstance_28;
  _14 = Port_apSiul2InstancePinModeAvailability[_13];
  _15 = (int) PinMode_29(D);
  _16 = u16MscrIdx_27 >> 4;
  _17 = (int) _16;
  u16PinDescWord_31 = *_14[_15][_17];
  # DEBUG u16PinDescWord => u16PinDescWord_31
  # DEBUG BEGIN_STMT
  _18 = (int) u8PinDescBitOffset_30;
  _19 = 1 << _18;
  _20 = (short unsigned int) _19;
  _21 = _20 & u16PinDescWord_31;
  if (_21 != 0)
    goto <bb 10>; [47.77%]
  else
    goto <bb 11>; [52.23%]

  <bb 10> [local count: 100275047]:
  # DEBUG BEGIN_STMT
  Port_Ipw_SetMode (u8MscrSiulInstance_28, u16MscrIdx_27, PinIndex_26(D), PinMode_29(D), pConfigPtr_25(D));

  <bb 11> [local count: 1073741824]:
  # PinModeError_22 = PHI <0(3), 0(5), 0(7), 13(8), 0(10), 13(9)>
  # DEBUG PinModeError => PinModeError_22
  # DEBUG BEGIN_STMT
  return PinModeError_22;

}



;; Function Port_Ipw_RefreshPortDirection (Port_Ipw_RefreshPortDirection, funcdef_no=14, decl_uid=6207, cgraph_uid=15, symbol_order=15)

Modification phase of node Port_Ipw_RefreshPortDirection/15
Port_Ipw_RefreshPortDirection (const struct Port_ConfigType * pConfigPtr)
{
  uint32 u32LocalMSCR;
  uint8 u8MscrSiulInstance;
  uint16 u16MscrIdx;
  uint16 u16PinIndex;
  uint16 u16NumPins;
  const struct Port_Siul2_PinConfigType * _1;
  unsigned int _2;
  unsigned int _3;
  const struct Port_Siul2_PinConfigType * _4;
  _Bool _5;
  int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  volatile uint32 * _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  u16NumPins_23 = pConfigPtr_22(D)->u16NumPins;
  # DEBUG u16NumPins => u16NumPins_23
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG u16PinIndex => 0
  goto <bb 12>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = pConfigPtr_22(D)->pUsedPadConfig;
  _2 = (unsigned int) u16PinIndex_16;
  _3 = _2 * 24;
  _4 = _1 + _3;
  _5 = _4->bDC;
  if (_5 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 477815111]:
  # DEBUG BEGIN_STMT
  u16MscrIdx_24 = _4->u16MscrIdx;
  # DEBUG u16MscrIdx => u16MscrIdx_24
  # DEBUG BEGIN_STMT
  u8MscrSiulInstance_25 = _4->u8MscrSiulInstance;
  # DEBUG u8MscrSiulInstance => u8MscrSiulInstance_25
  # DEBUG BEGIN_STMT
  _6 = (int) u8MscrSiulInstance_25;
  _7 = Port_au32Siul2BaseAddr[_6];
  _8 = (long unsigned int) u16MscrIdx_24;
  _9 = _8 << 2;
  _10 = _7 + _9;
  _11 = _10 + 576;
  _12 = (volatile uint32 *) _11;
  u32LocalMSCR_26 ={v} *_12;
  # DEBUG u32LocalMSCR => u32LocalMSCR_26
  # DEBUG BEGIN_STMT
  _13 = _4->u32MSCR;
  _14 = _13 & 2097152;
  if (_14 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 238907556]:
  # DEBUG BEGIN_STMT
  u32LocalMSCR_28 = u32LocalMSCR_26 | 2097152;
  # DEBUG u32LocalMSCR => u32LocalMSCR_28
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 238907556]:
  # DEBUG BEGIN_STMT
  u32LocalMSCR_27 = u32LocalMSCR_26 & 4292870143;
  # DEBUG u32LocalMSCR => u32LocalMSCR_27

  <bb 7> [local count: 477815111]:
  # u32LocalMSCR_17 = PHI <u32LocalMSCR_28(5), u32LocalMSCR_27(6)>
  # DEBUG u32LocalMSCR => u32LocalMSCR_17
  # DEBUG BEGIN_STMT
  _15 = _13 & 524288;
  if (_15 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 238907556]:
  # DEBUG BEGIN_STMT
  u32LocalMSCR_30 = u32LocalMSCR_17 | 524288;
  # DEBUG u32LocalMSCR => u32LocalMSCR_30
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 238907556]:
  # DEBUG BEGIN_STMT
  u32LocalMSCR_29 = u32LocalMSCR_17 & 4294443007;
  # DEBUG u32LocalMSCR => u32LocalMSCR_29

  <bb 10> [local count: 477815111]:
  # u32LocalMSCR_18 = PHI <u32LocalMSCR_30(8), u32LocalMSCR_29(9)>
  # DEBUG u32LocalMSCR => u32LocalMSCR_18
  # DEBUG BEGIN_STMT
  *_12 ={v} u32LocalMSCR_18;

  <bb 11> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  u16PinIndex_32 = u16PinIndex_16 + 1;
  # DEBUG u16PinIndex => u16PinIndex_32

  <bb 12> [local count: 1073741824]:
  # u16PinIndex_16 = PHI <0(2), u16PinIndex_32(11)>
  # DEBUG u16PinIndex => u16PinIndex_16
  # DEBUG BEGIN_STMT
  if (u16PinIndex_16 < u16NumPins_23)
    goto <bb 3>; [89.00%]
  else
    goto <bb 13>; [11.00%]

  <bb 13> [local count: 118111601]:
  return;

}



;; Function Port_Ipw_SetAsUnusedPin (Port_Ipw_SetAsUnusedPin, funcdef_no=15, decl_uid=6210, cgraph_uid=16, symbol_order=16)

Modification phase of node Port_Ipw_SetAsUnusedPin/16
Port_Ipw_SetAsUnusedPin (Port_PinType PinIndex, const struct Port_ConfigType * pConfigPtr)
{
  uint8 u8MscrSiulInstance;
  uint32 u32LocalMSCR;
  uint8 u8LocalPDO;
  uint16 u16MscrIdx;
  const struct Port_Siul2_PinConfigType * _1;
  long unsigned int _2;
  const struct Port_Siul2_PinConfigType * _3;
  const struct Port_Siul2_UnUsedPinConfigType * _4;
  short unsigned int _5;
  long unsigned int _6;
  const uint32 * _7;
  long unsigned int _8;
  const uint32 * _9;
  long unsigned int _10;
  long unsigned int _11;
  _Bool _12;
  int _13;
  long unsigned int _14;
  short unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  volatile uint8 * _19;
  int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  volatile uint32 * _26;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  _1 = pConfigPtr_30(D)->pUsedPadConfig;
  _2 = PinIndex_31(D) * 24;
  _3 = _1 + _2;
  u16MscrIdx_32 = _3->u16MscrIdx;
  # DEBUG u16MscrIdx => u16MscrIdx_32
  # DEBUG BEGIN_STMT
  _4 = pConfigPtr_30(D)->pUnusedPadConfig;
  u8LocalPDO_33 = _4->u8PDO;
  # DEBUG u8LocalPDO => u8LocalPDO_33
  # DEBUG BEGIN_STMT
  u32LocalMSCR_34 = _4->u32MSCR;
  # DEBUG u32LocalMSCR => u32LocalMSCR_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u8MscrSiulInstance_35 = _3->u8MscrSiulInstance;
  # DEBUG u8MscrSiulInstance => u8MscrSiulInstance_35
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG CoreId => 0
  # DEBUG BEGIN_STMT
  _5 = pConfigPtr_30(D)->u16NumPins;
  _6 = (long unsigned int) _5;
  if (_6 <= PinIndex_31(D))
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 5, 10);
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 719407022]:
  # DEBUG BEGIN_STMT
  _7 = pConfigPtr_30(D)->pau32Port_PinToPartitionMap;
  _8 = PinIndex_31(D) * 4;
  _9 = _7 + _8;
  _10 = *_9;
  _11 = _10 & 1;
  if (_11 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 5, 240);
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 482002704]:
  # DEBUG BEGIN_STMT
  _12 = _3->bMC;
  if (_12 != 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 7> [local count: 159060892]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 5, 14);
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 322941812]:
  # DEBUG BEGIN_STMT
  if (u8LocalPDO_33 != 2)
    goto <bb 9>; [66.00%]
  else
    goto <bb 10>; [34.00%]

  <bb 9> [local count: 213141596]:
  # DEBUG BEGIN_STMT
  _13 = (int) u8MscrSiulInstance_35;
  _14 = Port_au32Siul2BaseAddr[_13];
  _15 = u16MscrIdx_32 ^ 3;
  _16 = (long unsigned int) _15;
  _17 = _14 + _16;
  _18 = _17 + 4864;
  _19 = (volatile uint8 *) _18;
  *_19 ={v} u8LocalPDO_33;

  <bb 10> [local count: 322941812]:
  # DEBUG BEGIN_STMT
  _20 = (int) u8MscrSiulInstance_35;
  _21 = Port_au32Siul2BaseAddr[_20];
  _22 = (long unsigned int) u16MscrIdx_32;
  _23 = _22 << 2;
  _24 = _21 + _23;
  _25 = _24 + 576;
  _26 = (volatile uint32 *) _25;
  *_26 ={v} u32LocalMSCR_34;

  <bb 11> [local count: 1073741824]:
  return;

}



;; Function Port_Ipw_SetAsUsedPin (Port_Ipw_SetAsUsedPin, funcdef_no=16, decl_uid=6213, cgraph_uid=17, symbol_order=17)

Modification phase of node Port_Ipw_SetAsUsedPin/17
Port_Ipw_SetAsUsedPin (Port_PinType PinIndex, const struct Port_ConfigType * pConfigPtr)
{
  uint8 u8MscrSiulInstance;
  uint32 u32LocalMSCR;
  uint8 u8LocalPDO;
  uint16 u16MscrIdx;
  const struct Port_Siul2_PinConfigType * _1;
  long unsigned int _2;
  const struct Port_Siul2_PinConfigType * _3;
  short unsigned int _4;
  long unsigned int _5;
  const uint32 * _6;
  long unsigned int _7;
  const uint32 * _8;
  long unsigned int _9;
  long unsigned int _10;
  _Bool _11;
  _Bool _12;
  int _13;
  long unsigned int _14;
  short unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  volatile uint8 * _19;
  int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  volatile uint32 * _26;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  _1 = pConfigPtr_30(D)->pUsedPadConfig;
  _2 = PinIndex_31(D) * 24;
  _3 = _1 + _2;
  u16MscrIdx_32 = _3->u16MscrIdx;
  # DEBUG u16MscrIdx => u16MscrIdx_32
  # DEBUG BEGIN_STMT
  u8LocalPDO_33 = _3->u8PDO;
  # DEBUG u8LocalPDO => u8LocalPDO_33
  # DEBUG BEGIN_STMT
  u32LocalMSCR_34 = _3->u32MSCR;
  # DEBUG u32LocalMSCR => u32LocalMSCR_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  u8MscrSiulInstance_35 = _3->u8MscrSiulInstance;
  # DEBUG u8MscrSiulInstance => u8MscrSiulInstance_35
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG CoreId => 0
  # DEBUG BEGIN_STMT
  _4 = pConfigPtr_30(D)->u16NumPins;
  _5 = (long unsigned int) _4;
  if (_5 <= PinIndex_31(D))
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 6, 10);
  goto <bb 12>; [100.00%]

  <bb 4> [local count: 719407022]:
  # DEBUG BEGIN_STMT
  _6 = pConfigPtr_30(D)->pau32Port_PinToPartitionMap;
  _7 = PinIndex_31(D) * 4;
  _8 = _6 + _7;
  _9 = *_8;
  _10 = _9 & 1;
  if (_10 == 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 237404317]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 6, 240);
  goto <bb 12>; [100.00%]

  <bb 6> [local count: 482002704]:
  # DEBUG BEGIN_STMT
  _11 = _3->bMC;
  if (_11 != 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 7> [local count: 159060892]:
  # DEBUG BEGIN_STMT
  Det_ReportError (124, 0, 6, 14);
  goto <bb 12>; [100.00%]

  <bb 8> [local count: 322941812]:
  # DEBUG BEGIN_STMT
  _12 = _3->bGPIO;
  if (_12 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 9> [local count: 161470906]:
  # DEBUG BEGIN_STMT
  if (u8LocalPDO_33 != 2)
    goto <bb 10>; [66.00%]
  else
    goto <bb 11>; [34.00%]

  <bb 10> [local count: 106570798]:
  # DEBUG BEGIN_STMT
  _13 = (int) u8MscrSiulInstance_35;
  _14 = Port_au32Siul2BaseAddr[_13];
  _15 = u16MscrIdx_32 ^ 3;
  _16 = (long unsigned int) _15;
  _17 = _14 + _16;
  _18 = _17 + 4864;
  _19 = (volatile uint8 *) _18;
  *_19 ={v} u8LocalPDO_33;

  <bb 11> [local count: 322941812]:
  # DEBUG BEGIN_STMT
  _20 = (int) u8MscrSiulInstance_35;
  _21 = Port_au32Siul2BaseAddr[_20];
  _22 = (long unsigned int) u16MscrIdx_32;
  _23 = _22 << 2;
  _24 = _21 + _23;
  _25 = _24 + 576;
  _26 = (volatile uint32 *) _25;
  *_26 ={v} u32LocalMSCR_34;

  <bb 12> [local count: 1073741824]:
  return;

}


