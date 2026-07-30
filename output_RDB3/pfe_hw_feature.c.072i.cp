
IPA constant propagation start:
Determining dynamic type for call: feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  Starting walk at: feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  instance pointer: "drv_run_on_g3"  Outer instance pointer: "drv_run_on_g3" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  Starting walk at: feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  instance pointer: "Active if running on S32G3"  Outer instance pointer: "Active if running on S32G3" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  Starting walk at: feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  instance pointer: hw_features_10(D)  Outer instance pointer: hw_features_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: feature_20 = pfe_hw_feature_create ("jumbo_frames", "Active if we handle jumbo frames", 0, 0, _4);
  Starting walk at: feature_20 = pfe_hw_feature_create ("jumbo_frames", "Active if we handle jumbo frames", 0, 0, _4);
  instance pointer: "jumbo_frames"  Outer instance pointer: "jumbo_frames" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: feature_20 = pfe_hw_feature_create ("jumbo_frames", "Active if we handle jumbo frames", 0, 0, _4);
  Starting walk at: feature_20 = pfe_hw_feature_create ("jumbo_frames", "Active if we handle jumbo frames", 0, 0, _4);
  instance pointer: "Active if we handle jumbo frames"  Outer instance pointer: "Active if we handle jumbo frames" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: feature_20 = pfe_hw_feature_create ("jumbo_frames", "Active if we handle jumbo frames", 0, 0, _4);
  Starting walk at: feature_20 = pfe_hw_feature_create ("jumbo_frames", "Active if we handle jumbo frames", 0, 0, _4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Silicon HW version is unknown: 0x%x\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hw_feature.c", 97, val_14, "");

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_hw_feature_create.part.0/29:
  Jump functions of caller  autolibc_memset/28:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/27:
  Jump functions of caller  pfe_hm_report/26:
  Jump functions of caller  pfe_hw_feature_set_val/25:
  Jump functions of caller  pfe_hw_feature_enabled/24:
  Jump functions of caller  pfe_hw_feature_get_val/23:
  Jump functions of caller  pfe_hw_feature_get_def_val/22:
  Jump functions of caller  pfe_hw_feature_get_flags/21:
  Jump functions of caller  pfe_hw_feature_get_desc/20:
  Jump functions of caller  pfe_hw_feature_get_name/19:
  Jump functions of caller  pfe_hw_feature_init_all/18:
    callsite  pfe_hw_feature_init_all/18 -> pfe_hw_feature_create/16 : 
       param 0: CONST: "jumbo_frames"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: "Active if we handle jumbo frames"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op pointer_plus_expr 12
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  pfe_hw_feature_init_all/18 -> pfe_hw_feature_create/16 : 
       param 0: CONST: "drv_run_on_g3"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: "Active if running on S32G3"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hw_feature_destroy/17:
  Jump functions of caller  pfe_hw_feature_create/16:
    callsite  pfe_hw_feature_create/16 -> pfe_hw_feature_create.part.0/29 : 

 Propagating constants:

Not considering pfe_hw_feature_set_val for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_enabled for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_get_val for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_get_def_val for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_get_flags for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_get_desc for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_get_name for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_init_all for cloning; -fipa-cp-clone disabled.
Not considering pfe_hw_feature_destroy for cloning; -fipa-cp-clone disabled.

overall_size: 107, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000
 - context independent values, size: 13, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_hw_feature_create.part.0/29:
  Node: pfe_hw_feature_set_val/25:
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
  Node: pfe_hw_feature_enabled/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hw_feature_get_val/23:
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
  Node: pfe_hw_feature_get_def_val/22:
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
  Node: pfe_hw_feature_get_flags/21:
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
  Node: pfe_hw_feature_get_desc/20:
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
  Node: pfe_hw_feature_get_name/19:
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
  Node: pfe_hw_feature_init_all/18:
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
  Node: pfe_hw_feature_destroy/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hw_feature_create/16:
    param [0]: "drv_run_on_g3" [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               "jumbo_frames" [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const char * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: "Active if running on S32G3" [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               "Active if we handle jumbo frames" [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         const char * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
               0 [loc_time: 2, loc_size: 15, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         pfe_ct_feature_flags_t [0, 1]
        AGGS VARIABLE
    param [3]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8_t [0, 0]
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of pfe_hw_feature_create/16 for all known contexts.
    replacing param #3 def_val with const 0
Propagated bits info for function pfe_hw_feature_create.constprop/32:
 param 2: value = 0x0, mask = 0x1
 param 3: value = 0x0, mask = 0x0
Propagated bits info for function pfe_hw_feature_create/16:
 param 2: value = 0x0, mask = 0x1
 param 3: value = 0x0, mask = 0x0

IPA constant propagation end

Reclaiming functions: pfe_hw_feature_create/16
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_hw_feature_create.constprop.0/32 (pfe_hw_feature_create.constprop) @06f799a0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of pfe_hw_feature_create/16
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: pfe_hw_feature_init_all/18 (1073741824 (estimated locally),1.00 per call) pfe_hw_feature_init_all/18 (872415233 (estimated locally),0.81 per call) 
  Calls: autolibc_memset/28 (751619278 (estimated locally),0.70 per call) pfe_hw_feature_create.part.0/29 (322122544 (estimated locally),0.30 per call) 
pfe_hw_feature_create.part.0/29 (pfe_hw_feature_create.part.0) @06dd2d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pfe_hw_feature_create.constprop/32 (322122544 (estimated locally),0.30 per call) 
  Calls: pfe_hm_report/26 (1073741824 (estimated locally),1.00 per call) oal_util_raise_dem_for_drv_runtime_err/27 (1073741824 (estimated locally),1.00 per call) 
autolibc_memset/28 (autolibc_memset) @077ab0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hw_feature_create.constprop/32 (751619278 (estimated locally),0.70 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/27 (oal_util_raise_dem_for_drv_runtime_err) @07801b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hw_feature_init_all/18 (281448133 (estimated locally),0.26 per call) pfe_hw_feature_create.part.0/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hm_report/26 (pfe_hm_report) @078018c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hw_feature_init_all/18 (281448133 (estimated locally),0.26 per call) pfe_hw_feature_create.part.0/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hw_feature_set_val/25 (pfe_hw_feature_set_val) @07801d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_enabled/24 (pfe_hw_feature_enabled) @07801a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_get_val/23 (pfe_hw_feature_get_val) @078017e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_get_def_val/22 (pfe_hw_feature_get_def_val) @07801540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_get_flags/21 (pfe_hw_feature_get_flags) @078012a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_get_desc/20 (pfe_hw_feature_get_desc) @07801000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_get_name/19 (pfe_hw_feature_get_name) @069c7a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_init_all/18 (pfe_hw_feature_init_all) @069c7e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hw_feature_create.constprop/32 (872415233 (estimated locally),0.81 per call) oal_util_raise_dem_for_drv_runtime_err/27 (281448133 (estimated locally),0.26 per call) pfe_hm_report/26 (281448133 (estimated locally),0.26 per call) pfe_hw_feature_create.constprop/32 (1073741824 (estimated locally),1.00 per call) 
pfe_hw_feature_destroy/17 (pfe_hw_feature_destroy) @069c79a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hw_feature_create/16 (pfe_hw_feature_create) @069c7700
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function pfe_hw_feature_create.part.0 (pfe_hw_feature_create.part.0, funcdef_no=23, decl_uid=11157, cgraph_uid=27, symbol_order=29)

Modification phase of node pfe_hw_feature_create.part.0/29
pfe_hw_feature_create.part.0 ()
{
  const char * name;
  const char * descr;
  pfe_ct_feature_flags_t flags;
  uint8_t def_val;
  struct pfe_hw_feature_t * feature;

  <bb 4> [local count: 1073741824]:
  # DEBUG D#10 s=> name
  # DEBUG name => D#10
  # DEBUG D#9 s=> descr
  # DEBUG descr => D#9
  # DEBUG D#8 s=> flags
  # DEBUG flags => D#8
  # DEBUG D#7 s=> def_val
  # DEBUG def_val => D#7
  # DEBUG D#6 s=> feature
  # DEBUG feature => D#6

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Cannot allocate %u bytes of memory for feature\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hw_feature.c", 60, 12, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 3> [local count: 1073741824]:
  return;

}



;; Function pfe_hw_feature_destroy (pfe_hw_feature_destroy, funcdef_no=14, decl_uid=7974, cgraph_uid=15, symbol_order=17)

Modification phase of node pfe_hw_feature_destroy/17
pfe_hw_feature_destroy (const struct pfe_hw_feature_t * feature)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hw_feature_init_all (pfe_hw_feature_init_all, funcdef_no=15, decl_uid=7969, cgraph_uid=16, symbol_order=18)

Modification phase of node pfe_hw_feature_init_all/18
pfe_hw_feature_init_all (const uint32_t * cbus_base, struct pfe_hw_feature_t * hw_features, uint32_t * hw_features_count)
{
  uint8_t on_g3;
  struct pfe_hw_feature_t * feature;
  uint32_t val;
  errno_t ret;
  unsigned int cbus_base.0_1;
  unsigned int _2;
  volatile uint32_t * _3;
  struct pfe_hw_feature_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG on_g3 => 0
  # DEBUG BEGIN_STMT
  feature_12 = pfe_hw_feature_create ("drv_run_on_g3", "Active if running on S32G3", 1, 0, hw_features_10(D));
  # DEBUG feature => feature_12
  # DEBUG BEGIN_STMT
  if (feature_12 != 0B)
    goto <bb 3>; [81.25%]
  else
    goto <bb 9>; [18.75%]

  <bb 3> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  cbus_base.0_1 = (unsigned int) cbus_base_13(D);
  _2 = cbus_base.0_1 + 606208;
  _3 = (volatile uint32_t *) _2;
  val_14 ={v} *_3;
  # DEBUG val => val_14
  # DEBUG BEGIN_STMT
  if (val_14 == 328448)
    goto <bb 6>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 575794054]:
  # DEBUG BEGIN_STMT
  if (val_14 == 257)
    goto <bb 6>; [51.12%]
  else
    goto <bb 5>; [48.88%]

  <bb 5> [local count: 281448133]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Silicon HW version is unknown: 0x%x\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hw_feature.c", 97, val_14, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 6> [local count: 872415233]:
  # on_g3_6 = PHI <0(3), 1(4), 0(5)>
  # DEBUG on_g3 => on_g3_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG feature => feature_12
  # DEBUG val => on_g3_6
  # DEBUG INLINE_ENTRY pfe_hw_feature_set_val
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  feature_12->val = on_g3_6;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG feature => NULL
  # DEBUG val => NULL
  # DEBUG BEGIN_STMT
  *hw_features_count_17(D) = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = hw_features_10(D) + 12;
  feature_20 = pfe_hw_feature_create ("jumbo_frames", "Active if we handle jumbo frames", 0, 0, _4);
  # DEBUG feature => feature_20
  # DEBUG BEGIN_STMT
  if (feature_20 != 0B)
    goto <bb 8>; [81.25%]
  else
    goto <bb 9>; [18.75%]

  <bb 8> [local count: 708837377]:
  # DEBUG BEGIN_STMT
  *hw_features_count_17(D) = 2;

  <bb 9> [local count: 1073741824]:
  # ret_5 = PHI <11(2), 0(8), 11(6)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_hw_feature_get_name (pfe_hw_feature_get_name, funcdef_no=16, decl_uid=7977, cgraph_uid=17, symbol_order=19)

Modification phase of node pfe_hw_feature_get_name/19
pfe_hw_feature_get_name (const struct pfe_hw_feature_t * feature, const char * * name)
{
  const char * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = feature_3(D)->name;
  *name_4(D) = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hw_feature_get_desc (pfe_hw_feature_get_desc, funcdef_no=17, decl_uid=7980, cgraph_uid=18, symbol_order=20)

Modification phase of node pfe_hw_feature_get_desc/20
pfe_hw_feature_get_desc (const struct pfe_hw_feature_t * feature, const char * * desc)
{
  const char * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = feature_3(D)->description;
  *desc_4(D) = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hw_feature_get_flags (pfe_hw_feature_get_flags, funcdef_no=18, decl_uid=7983, cgraph_uid=19, symbol_order=21)

Modification phase of node pfe_hw_feature_get_flags/21
pfe_hw_feature_get_flags (const struct pfe_hw_feature_t * feature, pfe_ct_feature_flags_t * flags)
{
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = feature_3(D)->flags;
  *flags_4(D) = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hw_feature_get_def_val (pfe_hw_feature_get_def_val, funcdef_no=19, decl_uid=7986, cgraph_uid=20, symbol_order=22)

Modification phase of node pfe_hw_feature_get_def_val/22
pfe_hw_feature_get_def_val (const struct pfe_hw_feature_t * feature, uint8_t * def_val)
{
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = feature_3(D)->def_val;
  *def_val_4(D) = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hw_feature_get_val (pfe_hw_feature_get_val, funcdef_no=20, decl_uid=7989, cgraph_uid=21, symbol_order=23)

Modification phase of node pfe_hw_feature_get_val/23
pfe_hw_feature_get_val (const struct pfe_hw_feature_t * feature, uint8_t * val)
{
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = feature_3(D)->val;
  *val_4(D) = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hw_feature_enabled (pfe_hw_feature_enabled, funcdef_no=21, decl_uid=7991, cgraph_uid=22, symbol_order=24)

Modification phase of node pfe_hw_feature_enabled/24
pfe_hw_feature_enabled (const struct pfe_hw_feature_t * feature)
{
  bool_t is_enable;
  unsigned char _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG feature => feature_3(D)
  # DEBUG val => &val
  # DEBUG INLINE_ENTRY pfe_hw_feature_get_val
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = feature_3(D)->val;
  # DEBUG val => _4
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG feature => NULL
  # DEBUG val => NULL
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG is_enable => 0

  <bb 4> [local count: 1073741824]:
  # is_enable_1 = PHI <0(3), 1(2)>
  # DEBUG is_enable => is_enable_1
  # DEBUG BEGIN_STMT
  # DEBUG D#11 => {CLOBBER}
  # DEBUG val => D#11
  return is_enable_1;

}



;; Function pfe_hw_feature_set_val (pfe_hw_feature_set_val, funcdef_no=22, decl_uid=7972, cgraph_uid=23, symbol_order=25)

Modification phase of node pfe_hw_feature_set_val/25
pfe_hw_feature_set_val (struct pfe_hw_feature_t * feature, uint8_t val)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  feature_2(D)->val = val_3(D);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  return 0;

}


