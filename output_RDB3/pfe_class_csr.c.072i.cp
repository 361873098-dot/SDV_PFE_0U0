
IPA constant propagation start:
Determining dynamic type for call: ret_24 = pfe_class_cfg_validate_rtable_len (rtable_len_22(D), &rtable_idx);
  Starting walk at: ret_24 = pfe_class_cfg_validate_rtable_len (rtable_len_22(D), &rtable_idx);
  instance pointer: &rtable_idx  Outer instance pointer: rtable_idx offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/26:
  Jump functions of caller  pfe_hm_report/25:
  Jump functions of caller  pfe_feature_mgr_is_available/24:
  Jump functions of caller  pfe_class_cfg_bridge_lookup_disable/23:
  Jump functions of caller  pfe_class_cfg_bridge_lookup_enable/22:
  Jump functions of caller  pfe_class_cfg_rtable_lookup_disable/21:
  Jump functions of caller  pfe_class_cfg_rtable_lookup_enable/20:
  Jump functions of caller  pfe_class_cfg_set_def_vlan/19:
  Jump functions of caller  pfe_class_cfg_set_rtable/18:
    callsite  pfe_class_cfg_set_rtable/18 -> pfe_class_cfg_validate_rtable_len/17 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_class_cfg_set_rtable/18 -> pfe_class_cfg_rtable_lookup_disable/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_class_cfg_validate_rtable_len/17:
  Jump functions of caller  pfe_class_cfg_disable/16:
  Jump functions of caller  pfe_class_cfg_enable/15:
  Jump functions of caller  pfe_class_cfg_reset/14:
  Jump functions of caller  pfe_class_cfg_set_config/13:

 Propagating constants:

Not considering pfe_class_cfg_bridge_lookup_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_bridge_lookup_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_rtable_lookup_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_rtable_lookup_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_set_def_vlan for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_set_rtable for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_reset for cloning; -fipa-cp-clone disabled.
Not considering pfe_class_cfg_set_config for cloning; -fipa-cp-clone disabled.

overall_size: 191, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_class_cfg_bridge_lookup_disable/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_class_cfg_bridge_lookup_enable/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_class_cfg_rtable_lookup_disable/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_class_cfg_rtable_lookup_enable/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_class_cfg_set_def_vlan/19:
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
  Node: pfe_class_cfg_set_rtable/18:
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
  Node: pfe_class_cfg_validate_rtable_len/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         uint8_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: pfe_class_cfg_disable/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_class_cfg_enable/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_class_cfg_reset/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_class_cfg_set_config/13:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

oal_util_raise_dem_for_drv_runtime_err/26 (oal_util_raise_dem_for_drv_runtime_err) @0765a1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_class_cfg_set_rtable/18 (129493381 (estimated locally),0.12 per call) pfe_class_cfg_set_rtable/18 (150787712 (estimated locally),0.14 per call) pfe_class_cfg_validate_rtable_len/17 (9487202 (estimated locally),0.11 per call) pfe_class_cfg_validate_rtable_len/17 (12003039 (estimated locally),0.13 per call) 
  Calls: 
pfe_hm_report/25 (pfe_hm_report) @0765a0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_class_cfg_set_rtable/18 (129493381 (estimated locally),0.12 per call) pfe_class_cfg_set_rtable/18 (150787712 (estimated locally),0.14 per call) pfe_class_cfg_validate_rtable_len/17 (9487202 (estimated locally),0.11 per call) pfe_class_cfg_validate_rtable_len/17 (12003039 (estimated locally),0.13 per call) 
  Calls: 
pfe_feature_mgr_is_available/24 (pfe_feature_mgr_is_available) @07633e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_class_cfg_set_config/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_cfg_bridge_lookup_disable/23 (pfe_class_cfg_bridge_lookup_disable) @076339a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_class_cfg_bridge_lookup_enable/22 (pfe_class_cfg_bridge_lookup_enable) @07633540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_class_cfg_rtable_lookup_disable/21 (pfe_class_cfg_rtable_lookup_disable) @076330e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_class_cfg_set_rtable/18 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_class_cfg_rtable_lookup_enable/20 (pfe_class_cfg_rtable_lookup_enable) @0762c1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_class_cfg_set_def_vlan/19 (pfe_class_cfg_set_def_vlan) @0762cb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_class_cfg_set_rtable/18 (pfe_class_cfg_set_rtable) @0762c700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_cfg_validate_rtable_len/17 (439125929 (estimated locally),0.41 per call) oal_util_raise_dem_for_drv_runtime_err/26 (129493381 (estimated locally),0.12 per call) pfe_hm_report/25 (129493381 (estimated locally),0.12 per call) oal_util_raise_dem_for_drv_runtime_err/26 (150787712 (estimated locally),0.14 per call) pfe_hm_report/25 (150787712 (estimated locally),0.14 per call) pfe_class_cfg_rtable_lookup_disable/21 (354334802 (estimated locally),0.33 per call) 
pfe_class_cfg_validate_rtable_len/17 (pfe_class_cfg_validate_rtable_len) @0762c0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:89800788 (estimated locally) body local optimize_size
  Called by: pfe_class_cfg_set_rtable/18 (439125929 (estimated locally),0.41 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/26 (9487202 (estimated locally),0.11 per call) pfe_hm_report/25 (9487202 (estimated locally),0.11 per call) oal_util_raise_dem_for_drv_runtime_err/26 (12003039 (estimated locally),0.13 per call) pfe_hm_report/25 (12003039 (estimated locally),0.13 per call) 
pfe_class_cfg_disable/16 (pfe_class_cfg_disable) @0759f8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_class_cfg_enable/15 (pfe_class_cfg_enable) @0759fd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_class_cfg_reset/14 (pfe_class_cfg_reset) @0759fa80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_class_cfg_set_config/13 (pfe_class_cfg_set_config) @0759f7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_feature_mgr_is_available/24 (1073741824 (estimated locally),1.00 per call) 

;; Function pfe_class_cfg_set_config (pfe_class_cfg_set_config, funcdef_no=11, decl_uid=9446, cgraph_uid=12, symbol_order=13)

Modification phase of node pfe_class_cfg_set_config/13
pfe_class_cfg_set_config (addr_t base_va, const struct pfe_class_cfg_t * cfg)
{
  uint32_t regval;
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  volatile uint32_t * _6;
  unsigned int _7;
  volatile uint32_t * _8;
  unsigned int _9;
  volatile uint32_t * _10;
  unsigned int _11;
  volatile uint32_t * _12;
  unsigned int _13;
  volatile uint32_t * _14;
  unsigned int _15;
  volatile uint32_t * _16;
  unsigned int _17;
  volatile uint32_t * _18;
  unsigned int _19;
  volatile uint32_t * _20;
  unsigned int _21;
  volatile uint32_t * _22;
  unsigned int _23;
  volatile uint32_t * _24;
  short unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  short unsigned int _28;
  long unsigned int _29;
  unsigned int _30;
  volatile uint32_t * _31;
  long unsigned int _32;
  unsigned int _33;
  volatile uint32_t * _34;
  unsigned int _35;
  volatile uint32_t * _36;
  unsigned int _37;
  volatile uint32_t * _38;
  unsigned int _39;
  volatile uint32_t * _40;
  unsigned char _41;
  unsigned char _42;
  unsigned int _43;
  volatile uint32_t * _44;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_46(D) + 590412;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 3221782580;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_46(D) + 589920;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} 33554432;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = base_va_46(D) + 589924;
  _6 = (volatile uint32_t *) _5;
  *_6 ={v} 100664320;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = base_va_46(D) + 589856;
  _8 = (volatile uint32_t *) _7;
  *_8 ={v} 33554432;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = base_va_46(D) + 589860;
  _10 = (volatile uint32_t *) _9;
  *_10 ={v} 100664320;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = base_va_46(D) + 590100;
  _12 = (volatile uint32_t *) _11;
  *_12 ={v} 3221749768;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = base_va_46(D) + 590348;
  _14 = (volatile uint32_t *) _13;
  *_14 ={v} 24;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = base_va_46(D) + 590340;
  _16 = (volatile uint32_t *) _15;
  *_16 ={v} 20;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = base_va_46(D) + 590576;
  _18 = (volatile uint32_t *) _17;
  *_18 ={v} 960;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = base_va_46(D) + 590416;
  _20 = (volatile uint32_t *) _19;
  *_20 ={v} 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _21 = base_va_46(D) + 590336;
  _22 = (volatile uint32_t *) _21;
  *_22 ={v} 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = base_va_46(D) + 590496;
  _24 = (volatile uint32_t *) _23;
  *_24 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = cfg_60(D)->ro_header_size;
  _26 = (long unsigned int) _25;
  _27 = _26 << 16;
  _28 = cfg_60(D)->lmem_header_size;
  _29 = (long unsigned int) _28;
  _30 = base_va_46(D) + 589844;
  _31 = (volatile uint32_t *) _30;
  _32 = _27 | _29;
  *_31 ={v} _32;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _33 = base_va_46(D) + 590404;
  _34 = (volatile uint32_t *) _33;
  *_34 ={v} 256;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _35 = base_va_46(D) + 590488;
  _36 = (volatile uint32_t *) _35;
  *_36 ={v} 2292744448;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _37 = base_va_46(D) + 590492;
  _38 = (volatile uint32_t *) _37;
  *_38 ={v} 37120;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _39 = base_va_46(D) + 591116;
  _40 = (volatile uint32_t *) _39;
  regval_65 ={v} *_40;
  # DEBUG regval => regval_65
  # DEBUG BEGIN_STMT
  _41 = pfe_feature_mgr_is_available ("drv_run_on_g3");
  if (_41 == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  regval_69 = regval_65 & 4294950927;
  # DEBUG regval => regval_69
  # DEBUG BEGIN_STMT
  # DEBUG regval => regval_69 | 8192
  # DEBUG BEGIN_STMT
  regval_70 = regval_69 | 8195;
  # DEBUG regval => regval_70
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_40 ={v} regval_70;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _42 = cfg_60(D)->g2_ordered_class_writes;
  if (_42 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  regval_67 = regval_65 | 3;
  # DEBUG regval => regval_67
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_40 ={v} regval_67;
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _43 = base_va_46(D) + 590396;
  _44 = (volatile uint32_t *) _43;
  *_44 ={v} 45072;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_reset (pfe_class_cfg_reset, funcdef_no=12, decl_uid=9448, cgraph_uid=13, symbol_order=14)

Modification phase of node pfe_class_cfg_reset/14
pfe_class_cfg_reset (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 589828;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 2;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_enable (pfe_class_cfg_enable, funcdef_no=13, decl_uid=9450, cgraph_uid=14, symbol_order=15)

Modification phase of node pfe_class_cfg_enable/15
pfe_class_cfg_enable (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 589828;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 1;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_disable (pfe_class_cfg_disable, funcdef_no=14, decl_uid=9452, cgraph_uid=15, symbol_order=16)

Modification phase of node pfe_class_cfg_disable/16
pfe_class_cfg_disable (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 589828;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_set_def_vlan (pfe_class_cfg_set_def_vlan, funcdef_no=17, decl_uid=9460, cgraph_uid=18, symbol_order=19)

Modification phase of node pfe_class_cfg_set_def_vlan/19
pfe_class_cfg_set_def_vlan (addr_t base_va, uint16_t vlan)
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) vlan_7(D);
  _2 = _1 << 1;
  _3 = _2 & 8190;
  _4 = base_va_8(D) + 590408;
  _5 = (volatile uint32_t *) _4;
  _6 = _3 | 1;
  *_5 ={v} _6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_rtable_lookup_enable (pfe_class_cfg_rtable_lookup_enable, funcdef_no=18, decl_uid=9462, cgraph_uid=19, symbol_order=20)

Modification phase of node pfe_class_cfg_rtable_lookup_enable/20
pfe_class_cfg_rtable_lookup_enable (const addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 590396;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 | 8;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_rtable_lookup_disable (pfe_class_cfg_rtable_lookup_disable, funcdef_no=19, decl_uid=9464, cgraph_uid=20, symbol_order=21)

Modification phase of node pfe_class_cfg_rtable_lookup_disable/21
pfe_class_cfg_rtable_lookup_disable (const addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 590396;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 & 4294967287;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_set_rtable (pfe_class_cfg_set_rtable, funcdef_no=16, decl_uid=9457, cgraph_uid=17, symbol_order=18)

Modification phase of node pfe_class_cfg_set_rtable/18
pfe_class_cfg_set_rtable (addr_t base_va, addr_t rtable_pa, uint32_t rtable_len, uint32_t entry_size)
{
  uint8_t rtable_idx;
  errno_t ret;
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;
  unsigned int _4;
  volatile uint32_t * _5;
  unsigned char rtable_idx.0_6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  unsigned int _10;
  volatile uint32_t * _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (rtable_pa_15(D) == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  pfe_class_cfg_rtable_lookup_disable (base_va_17(D));
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  if (entry_size_16(D) > 1023)
    goto <bb 5>; [20.96%]
  else
    goto <bb 6>; [79.04%]

  <bb 5> [local count: 150787712]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Entry size exceeds maximum value\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_class_csr.c", 213, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 568619311]:
  # DEBUG BEGIN_STMT
  _1 = base_va_17(D) + 590396;
  _2 = (volatile uint32_t *) _1;
  reg_19 ={v} *_2;
  # DEBUG reg => reg_19
  # DEBUG BEGIN_STMT
  _3 = reg_19 & 8;
  if (_3 != 0)
    goto <bb 7>; [67.00%]
  else
    goto <bb 9>; [33.00%]

  <bb 7> [local count: 380974938]:
  # DEBUG BEGIN_STMT
  if (entry_size_16(D) != 128)
    goto <bb 8>; [33.99%]
  else
    goto <bb 9>; [66.01%]

  <bb 8> [local count: 129493381]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FATAL: Route table entry length exceeds 128bytes\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_class_csr.c", 224, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 439125929]:
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  ret_24 = pfe_class_cfg_validate_rtable_len (rtable_len_22(D), &rtable_idx);
  # DEBUG ret => ret_24
  # DEBUG BEGIN_STMT
  if (ret_24 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 219562964]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = base_va_17(D) + 590392;
  _5 = (volatile uint32_t *) _4;
  *_5 ={v} rtable_pa_15(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rtable_idx.0_6 = rtable_idx;
  _7 = (long unsigned int) rtable_idx.0_6;
  _8 = _7 << 16;
  _9 = entry_size_16(D);
  _10 = base_va_17(D) + 590388;
  _11 = (volatile uint32_t *) _10;
  _12 = _8 | _9;
  *_11 ={v} _12;

  <bb 11> [local count: 1073741824]:
  # ret_13 = PHI <0(3), 22(5), 22(8), ret_24(9), 0(10)>
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rtable_idx ={v} {CLOBBER};
  return ret_13;

}



;; Function pfe_class_cfg_bridge_lookup_enable (pfe_class_cfg_bridge_lookup_enable, funcdef_no=20, decl_uid=9466, cgraph_uid=21, symbol_order=22)

Modification phase of node pfe_class_cfg_bridge_lookup_enable/22
pfe_class_cfg_bridge_lookup_enable (const addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 590396;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 | 32;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_class_cfg_bridge_lookup_disable (pfe_class_cfg_bridge_lookup_disable, funcdef_no=21, decl_uid=9468, cgraph_uid=22, symbol_order=23)

Modification phase of node pfe_class_cfg_bridge_lookup_disable/23
pfe_class_cfg_bridge_lookup_disable (const addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 590396;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 & 4294967263;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}


