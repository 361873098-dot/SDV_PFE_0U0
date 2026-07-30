
IPA constant propagation start:
Determining dynamic type for call: _5 = turn_hif_phyif_on_off.isra.0 (hif_drv_16(D), 0);
  Starting walk at: _5 = turn_hif_phyif_on_off.isra.0 (hif_drv_16(D), 0);
  instance pointer: hif_drv_16(D)  Outer instance pointer: hif_drv_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = check_rings.isra.0 (_30);
Determining dynamic type for call: _13 = turn_hif_phyif_on_off.isra.0 (hif_drv_16(D), 1);
  Starting walk at: _13 = turn_hif_phyif_on_off.isra.0 (hif_drv_16(D), 1);
  instance pointer: hif_drv_16(D)  Outer instance pointer: hif_drv_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_12 = pfe_hif_chnl_create_minihif (_6, 1175027712, _9, _10, _11);
  Function call may change dynamic type:_5 = turn_hif_phyif_on_off.isra.0 (hif_drv_16(D), 0);
  Function call may change dynamic type:_4 = check_rings.isra.0 (_30);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  turn_hif_phyif_on_off.isra.0/40:
  Jump functions of caller  check_rings.isra.0/39:
  Jump functions of caller  pfe_hif_chnl_tx_enable/38:
  Jump functions of caller  pfe_hif_chnl_rx_enable/37:
  Jump functions of caller  pfe_phy_if_disable/36:
  Jump functions of caller  pfe_phy_if_enable/35:
  Jump functions of caller  pfe_platform_get_phy_if_by_id/34:
  Jump functions of caller  Eth_43_PFE_GetPlatform/33:
  Jump functions of caller  pfe_hif_chnl_tx_disable/32:
  Jump functions of caller  pfe_hif_chnl_rx_disable/31:
  Jump functions of caller  pfe_hif_chnl_destroy_chnl/30:
  Jump functions of caller  pfe_hif_chnl_create_minihif/29:
  Jump functions of caller  pfe_hif_ring_create_minihif/28:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/27:
  Jump functions of caller  pfe_hm_report/26:
  Jump functions of caller  __builtin_expect/25:
  Jump functions of caller  pfe_minihif_get_hif_id/24:
  Jump functions of caller  pfe_minihif_drv_stop/23:
  Jump functions of caller  pfe_minihif_drv_start_tx/22:
  Jump functions of caller  pfe_minihif_drv_start_rx/21:
  Jump functions of caller  pfe_minihif_drv_init/20:
    callsite  pfe_minihif_drv_init/20 -> turn_hif_phyif_on_off.isra.0/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  pfe_minihif_drv_init/20 -> turn_hif_phyif_on_off.isra.0/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  pfe_minihif_drv_init/20 -> check_rings.isra.0/39 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pfe_minihif_drv_attach_ring/19:
  Jump functions of caller  pfe_minihif_drv_create/18:

 Propagating constants:

Not considering pfe_minihif_get_hif_id for cloning; -fipa-cp-clone disabled.
Not considering pfe_minihif_drv_stop for cloning; -fipa-cp-clone disabled.
Not considering pfe_minihif_drv_start_tx for cloning; -fipa-cp-clone disabled.
Not considering pfe_minihif_drv_start_rx for cloning; -fipa-cp-clone disabled.
Not considering pfe_minihif_drv_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_minihif_drv_attach_ring for cloning; -fipa-cp-clone disabled.
Not considering pfe_minihif_drv_create for cloning; -fipa-cp-clone disabled.

overall_size: 307, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: turn_hif_phyif_on_off.isra.0/40:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 0 [loc_time: 2, loc_size: 35, prop_time: 0, prop_size: 0]
               1 [loc_time: 2, loc_size: 35, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         bool_t [0, 1]
        AGGS VARIABLE
  Node: check_rings.isra.0/39:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_minihif_get_hif_id/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_minihif_drv_stop/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_minihif_drv_start_tx/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_minihif_drv_start_rx/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_minihif_drv_init/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_minihif_drv_attach_ring/19:
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
  Node: pfe_minihif_drv_create/18:
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

IPA decision stage:

Propagated bits info for function turn_hif_phyif_on_off.isra.0/40:
 param 1: value = 0x1, mask = 0x1

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

turn_hif_phyif_on_off.isra.0/40 (turn_hif_phyif_on_off.isra.0) @070edee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_minihif_drv_init/20 (0 (precise),0.00 per call) pfe_minihif_drv_init/20 (461633822 (estimated locally),0.43 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/27 (133371506 (estimated locally),0.12 per call) pfe_hm_report/26 (133371506 (estimated locally),0.12 per call) pfe_phy_if_disable/36 (636314438 (estimated locally),0.59 per call) oal_util_raise_dem_for_drv_runtime_err/27 (68706533 (estimated locally),0.06 per call) pfe_hm_report/26 (68706533 (estimated locally),0.06 per call) pfe_phy_if_enable/35 (327798347 (estimated locally),0.31 per call) oal_util_raise_dem_for_drv_runtime_err/27 (109629040 (estimated locally),0.10 per call) pfe_hm_report/26 (109629040 (estimated locally),0.10 per call) pfe_platform_get_phy_if_by_id/34 (1073741824 (estimated locally),1.00 per call) Eth_43_PFE_GetPlatform/33 (1073741824 (estimated locally),1.00 per call) 
check_rings.isra.0/39 (check_rings.isra.0) @06e55a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_minihif_drv_init/20 (966367642 (estimated locally),0.90 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/27 (225056286 (estimated locally),0.21 per call) pfe_hm_report/26 (225056286 (estimated locally),0.21 per call) 
pfe_hif_chnl_tx_enable/38 (pfe_hif_chnl_tx_enable) @078928c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_start_tx/22 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_enable/37 (pfe_hif_chnl_rx_enable) @07892700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_start_rx/21 (0 (precise),0.00 per call) 
  Calls: 
pfe_phy_if_disable/36 (pfe_phy_if_disable) @07892540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: turn_hif_phyif_on_off.isra.0/40 (636314438 (estimated locally),0.59 per call) 
  Calls: 
pfe_phy_if_enable/35 (pfe_phy_if_enable) @07892460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: turn_hif_phyif_on_off.isra.0/40 (327798347 (estimated locally),0.31 per call) 
  Calls: 
pfe_platform_get_phy_if_by_id/34 (pfe_platform_get_phy_if_by_id) @07892380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: turn_hif_phyif_on_off.isra.0/40 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Eth_43_PFE_GetPlatform/33 (Eth_43_PFE_GetPlatform) @078922a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: turn_hif_phyif_on_off.isra.0/40 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_chnl_tx_disable/32 (pfe_hif_chnl_tx_disable) @07892000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_stop/23 (0 (precise),0.00 per call) pfe_minihif_drv_init/20 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_disable/31 (pfe_hif_chnl_rx_disable) @078861c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_stop/23 (0 (precise),0.00 per call) pfe_minihif_drv_init/20 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_destroy_chnl/30 (pfe_hif_chnl_destroy_chnl) @07886ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_init/20 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_create_minihif/29 (pfe_hif_chnl_create_minihif) @07886e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_init/20 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_ring_create_minihif/28 (pfe_hif_ring_create_minihif) @07886c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_attach_ring/19 (0 (precise),0.00 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/27 (oal_util_raise_dem_for_drv_runtime_err) @078869a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_stop/23 (966367642 (estimated locally),0.90 per call) pfe_minihif_drv_stop/23 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_start_tx/22 (966367642 (estimated locally),0.90 per call) pfe_minihif_drv_start_tx/22 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_start_rx/21 (966367642 (estimated locally),0.90 per call) pfe_minihif_drv_start_rx/21 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_init/20 (0 (precise),0.00 per call) pfe_minihif_drv_init/20 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_attach_ring/19 (0 (precise),0.00 per call) pfe_minihif_drv_attach_ring/19 (1073741823 (estimated locally),1.00 per call) pfe_minihif_drv_create/18 (178204069 (estimated locally),0.17 per call) pfe_minihif_drv_create/18 (116157390 (estimated locally),0.11 per call) pfe_minihif_drv_create/18 (107374182 (estimated locally),0.10 per call) turn_hif_phyif_on_off.isra.0/40 (133371506 (estimated locally),0.12 per call) turn_hif_phyif_on_off.isra.0/40 (68706533 (estimated locally),0.06 per call) turn_hif_phyif_on_off.isra.0/40 (109629040 (estimated locally),0.10 per call) check_rings.isra.0/39 (225056286 (estimated locally),0.21 per call) 
  Calls: 
pfe_hm_report/26 (pfe_hm_report) @078868c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_stop/23 (966367642 (estimated locally),0.90 per call) pfe_minihif_drv_stop/23 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_start_tx/22 (966367642 (estimated locally),0.90 per call) pfe_minihif_drv_start_tx/22 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_start_rx/21 (966367642 (estimated locally),0.90 per call) pfe_minihif_drv_start_rx/21 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_init/20 (0 (precise),0.00 per call) pfe_minihif_drv_init/20 (107374182 (estimated locally),0.10 per call) pfe_minihif_drv_attach_ring/19 (0 (precise),0.00 per call) pfe_minihif_drv_attach_ring/19 (1073741823 (estimated locally),1.00 per call) pfe_minihif_drv_create/18 (178204069 (estimated locally),0.17 per call) pfe_minihif_drv_create/18 (116157390 (estimated locally),0.11 per call) pfe_minihif_drv_create/18 (107374182 (estimated locally),0.10 per call) turn_hif_phyif_on_off.isra.0/40 (133371506 (estimated locally),0.12 per call) turn_hif_phyif_on_off.isra.0/40 (68706533 (estimated locally),0.06 per call) turn_hif_phyif_on_off.isra.0/40 (109629040 (estimated locally),0.10 per call) check_rings.isra.0/39 (225056286 (estimated locally),0.21 per call) 
  Calls: 
__builtin_expect/25 (__builtin_expect) @078867e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_minihif_drv_stop/23 (1073741824 (estimated locally),1.00 per call) pfe_minihif_drv_start_tx/22 (1073741824 (estimated locally),1.00 per call) pfe_minihif_drv_start_rx/21 (1073741824 (estimated locally),1.00 per call) pfe_minihif_drv_init/20 (1073741824 (estimated locally),1.00 per call) pfe_minihif_drv_attach_ring/19 (0 (precise),0.00 per call) pfe_minihif_drv_attach_ring/19 (869730877 (estimated locally),0.81 per call) pfe_minihif_drv_attach_ring/19 (869730877 (estimated locally),0.81 per call) pfe_minihif_drv_attach_ring/19 (966367642 (estimated locally),0.90 per call) pfe_minihif_drv_attach_ring/19 (1073741824 (estimated locally),1.00 per call) pfe_minihif_drv_create/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_minihif_get_hif_id/24 (pfe_minihif_get_hif_id) @07886380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_minihif_drv_stop/23 (pfe_minihif_drv_stop) @078860e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_rx_disable/31 (0 (precise),0.00 per call) pfe_hif_chnl_tx_disable/32 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/27 (966367642 (estimated locally),0.90 per call) pfe_hm_report/26 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/27 (107374182 (estimated locally),0.10 per call) pfe_hm_report/26 (107374182 (estimated locally),0.10 per call) __builtin_expect/25 (1073741824 (estimated locally),1.00 per call) 
pfe_minihif_drv_start_tx/22 (pfe_minihif_drv_start_tx) @0787ce00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_tx_enable/38 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/27 (966367642 (estimated locally),0.90 per call) pfe_hm_report/26 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/27 (107374182 (estimated locally),0.10 per call) pfe_hm_report/26 (107374182 (estimated locally),0.10 per call) __builtin_expect/25 (1073741824 (estimated locally),1.00 per call) 
pfe_minihif_drv_start_rx/21 (pfe_minihif_drv_start_rx) @0787c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_rx_enable/37 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/27 (966367642 (estimated locally),0.90 per call) pfe_hm_report/26 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/27 (107374182 (estimated locally),0.10 per call) pfe_hm_report/26 (107374182 (estimated locally),0.10 per call) __builtin_expect/25 (1073741824 (estimated locally),1.00 per call) 
pfe_minihif_drv_init/20 (pfe_minihif_drv_init) @0787c380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_tx_disable/32 (0 (precise),0.00 per call) pfe_hif_chnl_rx_disable/31 (0 (precise),0.00 per call) pfe_hif_chnl_destroy_chnl/30 (0 (precise),0.00 per call) turn_hif_phyif_on_off.isra.0/40 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/27 (0 (precise),0.00 per call) pfe_hm_report/26 (0 (precise),0.00 per call) pfe_hif_chnl_create_minihif/29 (0 (precise),0.00 per call) turn_hif_phyif_on_off.isra.0/40 (461633822 (estimated locally),0.43 per call) check_rings.isra.0/39 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/27 (107374182 (estimated locally),0.10 per call) pfe_hm_report/26 (107374182 (estimated locally),0.10 per call) __builtin_expect/25 (1073741824 (estimated locally),1.00 per call) 
pfe_minihif_drv_attach_ring/19 (pfe_minihif_drv_attach_ring) @07705620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/27 (0 (precise),0.00 per call) pfe_hm_report/26 (0 (precise),0.00 per call) __builtin_expect/25 (0 (precise),0.00 per call) pfe_hif_ring_create_minihif/28 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/27 (1073741823 (estimated locally),1.00 per call) pfe_hm_report/26 (1073741823 (estimated locally),1.00 per call) __builtin_expect/25 (869730877 (estimated locally),0.81 per call) __builtin_expect/25 (869730877 (estimated locally),0.81 per call) __builtin_expect/25 (966367642 (estimated locally),0.90 per call) __builtin_expect/25 (1073741824 (estimated locally),1.00 per call) 
pfe_minihif_drv_create/18 (pfe_minihif_drv_create) @07705b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/27 (178204069 (estimated locally),0.17 per call) pfe_hm_report/26 (178204069 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/27 (116157390 (estimated locally),0.11 per call) pfe_hm_report/26 (116157390 (estimated locally),0.11 per call) oal_util_raise_dem_for_drv_runtime_err/27 (107374182 (estimated locally),0.10 per call) pfe_hm_report/26 (107374182 (estimated locally),0.10 per call) __builtin_expect/25 (1073741824 (estimated locally),1.00 per call) 

;; Function turn_hif_phyif_on_off.isra.0 (turn_hif_phyif_on_off.isra.0, funcdef_no=23, decl_uid=11148, cgraph_uid=38, symbol_order=40)

Modification phase of node turn_hif_phyif_on_off.isra.0/40
Adjusting mask for param 1 to 0x1
Setting value range of param 1 [0, 1]
turn_hif_phyif_on_off.isra.0 (pfe_ct_phy_if_id_t * ISRA.5, bool_t enable)
{
  const struct pfe_platform_t * pPlatform;
  struct pfe_phy_if_t * prHif;
  errno_t ret;
  <unnamed type> _3;
  int _6;
  int _7;

  <bb 10> [local count: 1073741824]:
  # DEBUG hif_drv s=> hif_drv

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  pPlatform_1 = Eth_43_PFE_GetPlatform ();
  # DEBUG pPlatform => pPlatform_1
  # DEBUG BEGIN_STMT
  _3 = *ISRA.5_21(D);
  prHif_4 = pfe_platform_get_phy_if_by_id (pPlatform_1, _3);
  # DEBUG prHif => prHif_4
  # DEBUG BEGIN_STMT
  if (prHif_4 == 0B)
    goto <bb 3>; [10.21%]
  else
    goto <bb 4>; [89.79%]

  <bb 3> [local count: 109629040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t get physical interface for the HIF\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 101, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 964112785]:
  # DEBUG BEGIN_STMT
  if (enable_5(D) == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 5> [local count: 327798347]:
  # DEBUG BEGIN_STMT
  _6 = pfe_phy_if_enable (prHif_4);
  if (_6 != 0)
    goto <bb 6>; [20.96%]
  else
    goto <bb 9>; [79.04%]

  <bb 6> [local count: 68706533]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Failed to enable physical interface for the HIF\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 111, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 636314438]:
  # DEBUG BEGIN_STMT
  _7 = pfe_phy_if_disable (prHif_4);
  if (_7 != 0)
    goto <bb 8>; [20.96%]
  else
    goto <bb 9>; [79.04%]

  <bb 8> [local count: 133371506]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Failed to disable physical interface for the HIF\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 119, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117

  <bb 9> [local count: 1073741824]:
  # ret_8 = PHI <117(3), 0(5), 117(6), 0(7), 117(8)>
  # DEBUG ret => ret_8
  # DEBUG BEGIN_STMT
  return ret_8;

}



;; Function pfe_minihif_drv_create (pfe_minihif_drv_create, funcdef_no=15, decl_uid=10958, cgraph_uid=16, symbol_order=18)

Modification phase of node pfe_minihif_drv_create/18
pfe_minihif_drv_create (struct pfe_minihif_drv_t * hif_drv, pfe_ct_phy_if_id_t id, bool_t bd_access)
{
  errno_t ret;
  _Bool _1;
  long int _2;
  long int _3;
  unsigned char _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_drv_7(D) == 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] NULL argument received\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 141, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 9>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  if (bd_access_8(D) == 1)
    goto <bb 5>; [12.02%]
  else
    goto <bb 6>; [87.98%]

  <bb 5> [local count: 116157390]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] This implementation does not support datapath API\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 148, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 9>; [100.00%]

  <bb 6> [local count: 850210252]:
  # DEBUG BEGIN_STMT
  _4 = id_9(D) + 250;
  if (_4 > 3)
    goto <bb 7>; [20.96%]
  else
    goto <bb 8>; [79.04%]

  <bb 7> [local count: 178204069]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Unsupported HIF channel\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 155, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 672006183]:
  # DEBUG BEGIN_STMT
  hif_drv_7(D)->id = id_9(D);
  # DEBUG BEGIN_STMT
  hif_drv_7(D)->rx_ring_created = 0;
  # DEBUG BEGIN_STMT
  hif_drv_7(D)->tx_ring_created = 0;
  # DEBUG BEGIN_STMT
  hif_drv_7(D)->init_done = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 9> [local count: 1073741824]:
  # ret_5 = PHI <22(3), 22(5), 22(7), 0(8)>
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_minihif_drv_attach_ring (pfe_minihif_drv_attach_ring, funcdef_no=16, decl_uid=10964, cgraph_uid=17, symbol_order=19)

Modification phase of node pfe_minihif_drv_attach_ring/19
pfe_minihif_drv_attach_ring (struct pfe_minihif_drv_t * hif_drv, bool_t is_rx, void * bd_base_va, void * wb_bd_base_va, uint32_t length)
{
  errno_t ret;
  struct pfe_hif_ring_t * ring;
  _Bool _1;
  long int _2;
  long int _3;
  _Bool _4;
  long int _5;
  long int _6;
  _Bool _7;
  long int _8;
  long int _9;
  <unnamed type> _10;
  _Bool _11;
  long int _12;
  long int _13;
  _Bool _14;
  long int _15;
  long int _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_drv_20(D) == 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 7>; [10.00%]
  else
    goto <bb 3>; [90.00%]

  <bb 3> [local count: 966367642]:
  _4 = bd_base_va_21(D) == 0B;
  _5 = (long int) _4;
  _6 = __builtin_expect (_5, 0);
  if (_6 != 0)
    goto <bb 7>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 4> [local count: 869730877]:
  _7 = wb_bd_base_va_22(D) == 0B;
  _8 = (long int) _7;
  _9 = __builtin_expect (_8, 0);
  if (_9 != 0)
    goto <bb 5>; [100.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [local count: 869730877]:
  _10 = hif_drv_20(D)->id;
  _11 = _10 != 4;
  _12 = (long int) _11;
  _13 = __builtin_expect (_12, 0);
  if (_13 != 0)
    goto <bb 7>; [100.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  if (is_rx_24(D) == 1)
    goto <bb 8>; [0.00%]
  else
    goto <bb 9>; [0.00%]

  <bb 7> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] NULL argument received\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 191, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 15>; [100.00%]

  <bb 8> [count: 0]:
  # DEBUG BEGIN_STMT
  ring_26 = &hif_drv_20(D)->rx_ring;
  # DEBUG ring => ring_26
  goto <bb 10>; [0.00%]

  <bb 9> [count: 0]:
  # DEBUG BEGIN_STMT
  ring_25 = &hif_drv_20(D)->tx_ring;
  # DEBUG ring => ring_25

  <bb 10> [count: 0]:
  # ring_17 = PHI <ring_26(8), ring_25(9)>
  # DEBUG ring => ring_17
  # DEBUG BEGIN_STMT
  ret_29 = pfe_hif_ring_create_minihif (ring_17, bd_base_va_21(D), wb_bd_base_va_22(D), length_27(D), is_rx_24(D));
  # DEBUG ret => ret_29
  # DEBUG BEGIN_STMT
  _14 = ret_29 == 0;
  _15 = (long int) _14;
  _16 = __builtin_expect (_15, 1);
  if (_16 != 0)
    goto <bb 11>; [0.00%]
  else
    goto <bb 14>; [0.00%]

  <bb 11> [count: 0]:
  # DEBUG BEGIN_STMT
  if (is_rx_24(D) == 1)
    goto <bb 12>; [0.00%]
  else
    goto <bb 13>; [0.00%]

  <bb 12> [count: 0]:
  # DEBUG BEGIN_STMT
  hif_drv_20(D)->rx_ring_created = 1;
  goto <bb 15>; [0.00%]

  <bb 13> [count: 0]:
  # DEBUG BEGIN_STMT
  hif_drv_20(D)->tx_ring_created = 1;
  goto <bb 15>; [0.00%]

  <bb 14> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not create BD ring\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 218, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 15> [local count: 1073741823]:
  # ret_18 = PHI <22(7), ret_29(13), ret_29(14), ret_29(12)>
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return ret_18;

}



;; Function pfe_minihif_drv_init (pfe_minihif_drv_init, funcdef_no=17, decl_uid=10966, cgraph_uid=18, symbol_order=20)

Modification phase of node pfe_minihif_drv_init/20
pfe_minihif_drv_init (struct pfe_minihif_drv_t * hif_drv)
{
  errno_t ret;
  _Bool _1;
  long int _2;
  long int _3;
  int _4;
  int _5;
  struct pfe_hif_chnl_t * _6;
  <unnamed type> _7;
  long unsigned int _8;
  long unsigned int _9;
  struct pfe_hif_ring_t * _10;
  struct pfe_hif_ring_t * _11;
  int _12;
  int _13;
  unsigned char _30;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_drv_16(D) == 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] NULL argument received\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 235, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _30 = MEM[(unsigned char *)hif_drv_16(D) + 256B];
  # DEBUG D#1 => hif_drv_16(D)
  _4 = check_rings.isra.0 (_30);
  if (_4 != 0)
    goto <bb 11>; [52.23%]
  else
    goto <bb 5>; [47.77%]

  <bb 5> [local count: 461633822]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => hif_drv_16(D)
  _5 = turn_hif_phyif_on_off.isra.0 (hif_drv_16(D), 0);
  if (_5 != 0)
    goto <bb 11>; [100.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  _6 = &hif_drv_16(D)->channel;
  _7 = hif_drv_16(D)->id;
  _8 = (long unsigned int) _7;
  _9 = _8 + 4294967290;
  _10 = &hif_drv_16(D)->rx_ring;
  _11 = &hif_drv_16(D)->tx_ring;
  _12 = pfe_hif_chnl_create_minihif (_6, 1175027712, _9, _10, _11);
  if (_12 != 0)
    goto <bb 7>; [0.00%]
  else
    goto <bb 8>; [0.00%]

  <bb 7> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] pfe_minihif_drv_init() failed to create minihif channel\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 262, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 11>; [0.00%]

  <bb 8> [count: 0]:
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => hif_drv_16(D)
  _13 = turn_hif_phyif_on_off.isra.0 (hif_drv_16(D), 1);
  if (_13 != 0)
    goto <bb 9>; [0.00%]
  else
    goto <bb 10>; [0.00%]

  <bb 9> [count: 0]:
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_destroy_chnl (_6);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 117
  goto <bb 11>; [0.00%]

  <bb 10> [count: 0]:
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_rx_disable (_6);
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_tx_disable (_6);
  # DEBUG BEGIN_STMT
  hif_drv_16(D)->init_done = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 11> [local count: 1073741824]:
  # ret_14 = PHI <22(3), 22(4), 117(5), 117(7), 117(9), 0(10)>
  # DEBUG ret => ret_14
  # DEBUG BEGIN_STMT
  return ret_14;

}



;; Function pfe_minihif_drv_start_rx (pfe_minihif_drv_start_rx, funcdef_no=18, decl_uid=10968, cgraph_uid=19, symbol_order=21)

Modification phase of node pfe_minihif_drv_start_rx/21
pfe_minihif_drv_start_rx (struct pfe_minihif_drv_t * hif_drv)
{
  errno_t ret;
  _Bool _1;
  long int _2;
  long int _3;
  unsigned char _4;
  struct pfe_hif_chnl_t * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_drv_8(D) == 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] NULL argument received\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 292, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _4 = hif_drv_8(D)->init_done;
  if (_4 == 0)
    goto <bb 5>; [100.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Minihif not initialized\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 297, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  _5 = &hif_drv_8(D)->channel;
  ret_11 = pfe_hif_chnl_rx_enable (_5);
  # DEBUG ret => ret_11

  <bb 7> [local count: 1073741824]:
  # ret_6 = PHI <22(3), 22(5), ret_11(6)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_minihif_drv_start_tx (pfe_minihif_drv_start_tx, funcdef_no=19, decl_uid=10970, cgraph_uid=20, symbol_order=22)

Modification phase of node pfe_minihif_drv_start_tx/22
pfe_minihif_drv_start_tx (struct pfe_minihif_drv_t * hif_drv)
{
  errno_t ret;
  _Bool _1;
  long int _2;
  long int _3;
  unsigned char _4;
  struct pfe_hif_chnl_t * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_drv_8(D) == 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] NULL argument received\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 318, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _4 = hif_drv_8(D)->init_done;
  if (_4 == 0)
    goto <bb 5>; [100.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Minihif not initialized\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 323, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  _5 = &hif_drv_8(D)->channel;
  ret_11 = pfe_hif_chnl_tx_enable (_5);
  # DEBUG ret => ret_11

  <bb 7> [local count: 1073741824]:
  # ret_6 = PHI <22(3), 22(5), ret_11(6)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_minihif_drv_stop (pfe_minihif_drv_stop, funcdef_no=20, decl_uid=10974, cgraph_uid=21, symbol_order=23)

Modification phase of node pfe_minihif_drv_stop/23
pfe_minihif_drv_stop (struct pfe_minihif_drv_t * hif_drv)
{
  errno_t ret;
  _Bool _1;
  long int _2;
  long int _3;
  unsigned char _4;
  struct pfe_hif_chnl_t * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_drv_8(D) == 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] NULL argument received\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 344, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _4 = hif_drv_8(D)->init_done;
  if (_4 == 0)
    goto <bb 5>; [100.00%]
  else
    goto <bb 6>; [0.00%]

  <bb 5> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Minihif not initialized\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_minihif_drv.c", 349, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  goto <bb 7>; [100.00%]

  <bb 6> [count: 0]:
  # DEBUG BEGIN_STMT
  _5 = &hif_drv_8(D)->channel;
  pfe_hif_chnl_tx_disable (_5);
  # DEBUG BEGIN_STMT
  pfe_hif_chnl_rx_disable (_5);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 7> [local count: 1073741824]:
  # ret_6 = PHI <22(3), 22(5), 0(6)>
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_minihif_get_hif_id (pfe_minihif_get_hif_id, funcdef_no=21, decl_uid=10972, cgraph_uid=22, symbol_order=24)

Modification phase of node pfe_minihif_get_hif_id/24
pfe_minihif_get_hif_id (const struct pfe_minihif_drv_t * hif_drv)
{
  pfe_ct_phy_if_id_t ret;
  <unnamed type> _1;
  unsigned char _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (hif_drv_4(D) == 0B)
    goto <bb 5>; [18.75%]
  else
    goto <bb 3>; [81.25%]

  <bb 3> [local count: 872415233]:
  # DEBUG BEGIN_STMT
  _1 = hif_drv_4(D)->id;
  _2 = _1 + 250;
  if (_2 > 3)
    goto <bb 5>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 567069902]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => _1

  <bb 5> [local count: 1073741824]:
  # ret_3 = PHI <10(2), 10(3), _1(4)>
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}


