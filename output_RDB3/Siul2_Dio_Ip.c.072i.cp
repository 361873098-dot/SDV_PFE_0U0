
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01/12:
  Jump functions of caller  SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01/11:
  Jump functions of caller  Siul2_Dio_Ip_MaskedWritePins/10:
    callsite  Siul2_Dio_Ip_MaskedWritePins/10 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  Siul2_Dio_Ip_MaskedWritePins/10 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_ReadPin/9:
    callsite  Siul2_Dio_Ip_ReadPin/9 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_ReadPins/8:
    callsite  Siul2_Dio_Ip_ReadPins/8 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_TogglePins/7:
    callsite  Siul2_Dio_Ip_TogglePins/7 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_ClearPins/6:
    callsite  Siul2_Dio_Ip_ClearPins/6 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_SetPins/5:
    callsite  Siul2_Dio_Ip_SetPins/5 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_GetPinsOutput/4:
    callsite  Siul2_Dio_Ip_GetPinsOutput/4 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_WritePins/3:
    callsite  Siul2_Dio_Ip_WritePins/3 -> Siul2_Dio_Ip_Rev_Bit_16/1 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  Siul2_Dio_Ip_WritePin/2:
  Jump functions of caller  Siul2_Dio_Ip_Rev_Bit_16/1:

 Propagating constants:

Not considering Siul2_Dio_Ip_MaskedWritePins for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_ReadPin for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_ReadPins for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_TogglePins for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_ClearPins for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_SetPins for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_GetPinsOutput for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_WritePins for cloning; -fipa-cp-clone disabled.
Not considering Siul2_Dio_Ip_WritePin for cloning; -fipa-cp-clone disabled.

overall_size: 101, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Siul2_Dio_Ip_MaskedWritePins/10:
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
  Node: Siul2_Dio_Ip_ReadPin/9:
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
  Node: Siul2_Dio_Ip_ReadPins/8:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Siul2_Dio_Ip_TogglePins/7:
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
  Node: Siul2_Dio_Ip_ClearPins/6:
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
  Node: Siul2_Dio_Ip_SetPins/5:
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
  Node: Siul2_Dio_Ip_GetPinsOutput/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Siul2_Dio_Ip_WritePins/3:
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
  Node: Siul2_Dio_Ip_WritePin/2:
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
  Node: Siul2_Dio_Ip_Rev_Bit_16/1:
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

SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01/12 (SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01) @07112c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Siul2_Dio_Ip_WritePin/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01/11 (SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01) @07112b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Siul2_Dio_Ip_WritePin/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Siul2_Dio_Ip_MaskedWritePins/10 (Siul2_Dio_Ip_MaskedWritePins) @07112700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Siul2_Dio_Ip_au32BaseAdresses/0 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_ReadPin/9 (Siul2_Dio_Ip_ReadPin) @07112460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_ReadPins/8 (Siul2_Dio_Ip_ReadPins) @071121c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_TogglePins/7 (Siul2_Dio_Ip_TogglePins) @06e7ee00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_ClearPins/6 (Siul2_Dio_Ip_ClearPins) @06e7e8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_SetPins/5 (Siul2_Dio_Ip_SetPins) @06e7e380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_GetPinsOutput/4 (Siul2_Dio_Ip_GetPinsOutput) @06e7ed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_WritePins/3 (Siul2_Dio_Ip_WritePins) @06e7ea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Siul2_Dio_Ip_Rev_Bit_16/1 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_WritePin/2 (Siul2_Dio_Ip_WritePin) @06e7e7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01/12 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01/11 (1073741824 (estimated locally),1.00 per call) 
Siul2_Dio_Ip_Rev_Bit_16/1 (Siul2_Dio_Ip_Rev_Bit_16) @06e7e540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:119292716 (estimated locally) body local optimize_size
  Called by: Siul2_Dio_Ip_MaskedWritePins/10 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_MaskedWritePins/10 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_ReadPin/9 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_ReadPins/8 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_TogglePins/7 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_ClearPins/6 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_SetPins/5 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_GetPinsOutput/4 (1073741824 (estimated locally),1.00 per call) Siul2_Dio_Ip_WritePins/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Siul2_Dio_Ip_au32BaseAdresses/0 (Siul2_Dio_Ip_au32BaseAdresses) @06e7d900
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: Siul2_Dio_Ip_MaskedWritePins/10 (read)
  Availability: available
  Varpool flags: initialized

;; Function Siul2_Dio_Ip_Rev_Bit_16 (Siul2_Dio_Ip_Rev_Bit_16, funcdef_no=0, decl_uid=6048, cgraph_uid=1, symbol_order=1)

Modification phase of node Siul2_Dio_Ip_Rev_Bit_16/1
Siul2_Dio_Ip_Rev_Bit_16 (uint16 value)
{
  uint16 ret;
  uint8 i;
  int _1;
  int _2;
  int _3;
  unsigned int _4;
  unsigned int _5;
  unsigned int _6;
  unsigned int _7;
  unsigned int _8;
  short unsigned int _9;
  int _11;
  unsigned int _12;
  unsigned int _13;
  unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;

  <bb 2> [local count: 119292716]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 954449108]:
  # DEBUG BEGIN_STMT
  _1 = (int) value_20(D);
  _2 = (int) i_17;
  _3 = _1 >> _2;
  _4 = (unsigned int) _3;
  _5 = _4 & 1;
  _6 = (unsigned int) i_17;
  _7 = 15 - _6;
  _8 = _5 << _7;
  _9 = (short unsigned int) _8;
  _11 = _1 << _2;
  _12 = (unsigned int) _11;
  _13 = _12 & 32768;
  _14 = _13 >> _7;
  _15 = (short unsigned int) _14;
  _16 = _9 | _15;
  ret_21 = _16 | ret_18;
  # DEBUG ret => ret_21
  # DEBUG BEGIN_STMT
  i_22 = i_17 + 1;
  # DEBUG i => i_22

  <bb 4> [local count: 1073741824]:
  # i_17 = PHI <0(2), i_22(3)>
  # ret_18 = PHI <0(2), ret_21(3)>
  # DEBUG ret => ret_18
  # DEBUG i => i_17
  # DEBUG BEGIN_STMT
  if (i_17 != 8)
    goto <bb 3>; [88.89%]
  else
    goto <bb 5>; [11.11%]

  <bb 5> [local count: 119292717]:
  # ret_10 = PHI <ret_18(4)>
  # DEBUG BEGIN_STMT
  return ret_10;

}



;; Function Siul2_Dio_Ip_WritePin (Siul2_Dio_Ip_WritePin, funcdef_no=1, decl_uid=6013, cgraph_uid=2, symbol_order=2)

Modification phase of node Siul2_Dio_Ip_WritePin/2
Siul2_Dio_Ip_WritePin (struct Siul2_Dio_Ip_GpioType * const base, Siul2_Dio_Ip_PinsChannelType pin, Siul2_Dio_Ip_PinsLevelType value)
{
  Siul2_Dio_Ip_PinsChannelType pinsValues;
  unsigned int _1;
  unsigned int _2;
  int _3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned int _6;
  unsigned int _7;
  short unsigned int _8;
  unsigned char _19;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_01 ();
  # DEBUG BEGIN_STMT
  pinsValues_12 ={v} base_11(D)->PGPDO;
  # DEBUG pinsValues => pinsValues_12
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) pin_13(D);
  _2 = 15 - _1;
  _3 = 1 << _2;
  _4 = (short unsigned int) _3;
  _5 = ~_4;
  pinsValues_14 = _5 & pinsValues_12;
  # DEBUG pinsValues => pinsValues_14
  # DEBUG BEGIN_STMT
  _19 = value_15(D) & 1;
  _6 = (unsigned int) _19;
  _7 = _6 << _2;
  _8 = (short unsigned int) _7;
  pinsValues_16 = _8 | pinsValues_14;
  # DEBUG pinsValues => pinsValues_16
  # DEBUG BEGIN_STMT
  base_11(D)->PGPDO ={v} pinsValues_16;
  # DEBUG BEGIN_STMT
  SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_01 ();
  return;

}



;; Function Siul2_Dio_Ip_WritePins (Siul2_Dio_Ip_WritePins, funcdef_no=2, decl_uid=6016, cgraph_uid=3, symbol_order=3)

Modification phase of node Siul2_Dio_Ip_WritePins/3
Siul2_Dio_Ip_WritePins (struct Siul2_Dio_Ip_GpioType * const base, Siul2_Dio_Ip_PinsChannelType pins)
{
  short unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Siul2_Dio_Ip_Rev_Bit_16 (pins_3(D));
  base_4(D)->PGPDO ={v} _1;
  return;

}



;; Function Siul2_Dio_Ip_GetPinsOutput (Siul2_Dio_Ip_GetPinsOutput, funcdef_no=3, decl_uid=6018, cgraph_uid=4, symbol_order=4)

Modification phase of node Siul2_Dio_Ip_GetPinsOutput/4
Siul2_Dio_Ip_GetPinsOutput (const struct Siul2_Dio_Ip_GpioType * const base)
{
  Siul2_Dio_Ip_PinsChannelType returnValue;
  short unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  _1 ={v} base_3(D)->PGPDO;
  returnValue_4 = Siul2_Dio_Ip_Rev_Bit_16 (_1);
  # DEBUG returnValue => returnValue_4
  # DEBUG BEGIN_STMT
  return returnValue_4;

}



;; Function Siul2_Dio_Ip_SetPins (Siul2_Dio_Ip_SetPins, funcdef_no=4, decl_uid=6021, cgraph_uid=5, symbol_order=5)

Modification phase of node Siul2_Dio_Ip_SetPins/5
Siul2_Dio_Ip_SetPins (struct Siul2_Dio_Ip_GpioType * const base, Siul2_Dio_Ip_PinsChannelType pins)
{
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = Siul2_Dio_Ip_Rev_Bit_16 (pins_4(D));
  _1 ={v} base_6(D)->PGPDO;
  _2 = _1 | _5;
  base_6(D)->PGPDO ={v} _2;
  return;

}



;; Function Siul2_Dio_Ip_ClearPins (Siul2_Dio_Ip_ClearPins, funcdef_no=5, decl_uid=6024, cgraph_uid=6, symbol_order=6)

Modification phase of node Siul2_Dio_Ip_ClearPins/6
Siul2_Dio_Ip_ClearPins (struct Siul2_Dio_Ip_GpioType * const base, Siul2_Dio_Ip_PinsChannelType pins)
{
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Siul2_Dio_Ip_Rev_Bit_16 (pins_5(D));
  _6 = ~_1;
  _2 ={v} base_7(D)->PGPDO;
  _3 = _2 & _6;
  base_7(D)->PGPDO ={v} _3;
  return;

}



;; Function Siul2_Dio_Ip_TogglePins (Siul2_Dio_Ip_TogglePins, funcdef_no=6, decl_uid=6027, cgraph_uid=7, symbol_order=7)

Modification phase of node Siul2_Dio_Ip_TogglePins/7
Siul2_Dio_Ip_TogglePins (struct Siul2_Dio_Ip_GpioType * const base, Siul2_Dio_Ip_PinsChannelType pins)
{
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = Siul2_Dio_Ip_Rev_Bit_16 (pins_4(D));
  _1 ={v} base_6(D)->PGPDO;
  _2 = _1 ^ _5;
  base_6(D)->PGPDO ={v} _2;
  return;

}



;; Function Siul2_Dio_Ip_ReadPins (Siul2_Dio_Ip_ReadPins, funcdef_no=7, decl_uid=6029, cgraph_uid=8, symbol_order=8)

Modification phase of node Siul2_Dio_Ip_ReadPins/8
Siul2_Dio_Ip_ReadPins (const struct Siul2_Dio_Ip_GpioType * const base)
{
  Siul2_Dio_Ip_PinsChannelType returnValue;
  short unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  _1 ={v} base_3(D)->PGPDI;
  returnValue_4 = Siul2_Dio_Ip_Rev_Bit_16 (_1);
  # DEBUG returnValue => returnValue_4
  # DEBUG BEGIN_STMT
  return returnValue_4;

}



;; Function Siul2_Dio_Ip_ReadPin (Siul2_Dio_Ip_ReadPin, funcdef_no=8, decl_uid=6037, cgraph_uid=9, symbol_order=9)

Modification phase of node Siul2_Dio_Ip_ReadPin/9
Siul2_Dio_Ip_ReadPin (const struct Siul2_Dio_Ip_GpioType * const base, Siul2_Dio_Ip_PinsChannelType pin)
{
  Siul2_Dio_Ip_PinsLevelType returnValue;
  short unsigned int _1;
  short unsigned int _2;
  int _3;
  int _4;
  int _5;
  int _6;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG returnValue => 0
  # DEBUG BEGIN_STMT
  _1 ={v} base_9(D)->PGPDI;
  _2 = Siul2_Dio_Ip_Rev_Bit_16 (_1);
  _3 = (int) _2;
  _4 = (int) pin_10(D);
  _5 = 1 << _4;
  _6 = _3 & _5;
  _7 = _6 >> _4;
  returnValue_11 = (Siul2_Dio_Ip_PinsLevelType) _7;
  # DEBUG returnValue => returnValue_11
  # DEBUG BEGIN_STMT
  return returnValue_11;

}



;; Function Siul2_Dio_Ip_MaskedWritePins (Siul2_Dio_Ip_MaskedWritePins, funcdef_no=9, decl_uid=6034, cgraph_uid=10, symbol_order=10)

Modification phase of node Siul2_Dio_Ip_MaskedWritePins/10
Siul2_Dio_Ip_MaskedWritePins (uint8 u8Siul2Instance, uint8 u8PortId, Siul2_Dio_Ip_PinsChannelType pins, Siul2_Dio_Ip_PinsChannelType mask)
{
  uint32 pinsRev;
  uint32 maskRev;
  struct SIUL2_Type * base;
  int _1;
  long unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  long unsigned int _5;
  int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) u8Siul2Instance_8(D);
  _2 = Siul2_Dio_Ip_au32BaseAdresses[_1];
  base_10 = (struct SIUL2_Type *) _2;
  # DEBUG base => base_10
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = Siul2_Dio_Ip_Rev_Bit_16 (mask_11(D));
  maskRev_12 = (uint32) _3;
  # DEBUG maskRev => maskRev_12
  # DEBUG BEGIN_STMT
  _4 = Siul2_Dio_Ip_Rev_Bit_16 (pins_13(D));
  pinsRev_14 = (uint32) _4;
  # DEBUG pinsRev => pinsRev_14
  # DEBUG BEGIN_STMT
  _5 = maskRev_12 << 16;
  _6 = (int) u8PortId_15(D);
  _7 = _5 | pinsRev_14;
  base_10->MPGPDO[_6] ={v} _7;
  return;

}


