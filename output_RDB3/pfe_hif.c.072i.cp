
IPA constant propagation start:
Determining dynamic type for call: pfe_hif_clear_master_up (hif_13(D));
  Starting walk at: pfe_hif_clear_master_up (hif_13(D));
  instance pointer: hif_13(D)  Outer instance pointer: hif_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_hif_clear_emac_timer_ownership (hif_13(D));
  Starting walk at: pfe_hif_clear_emac_timer_ownership (hif_13(D));
  instance pointer: hif_13(D)  Outer instance pointer: hif_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_hif_clear_master_up (hif_13(D));
Determining dynamic type for call: ret_12 = pfe_hif_create_bind_chnl (&hif_instance, channels_mask_4(D));
  Starting walk at: ret_12 = pfe_hif_create_bind_chnl (&hif_instance, channels_mask_4(D));
  instance pointer: &hif_instance  Outer instance pointer: hif_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_10 = pfe_hif_cfg_init (cbus_base_va_7(D));
  Function call may change dynamic type:autolibc_memset (&hif_instance, 0, 384);
Determining dynamic type for call: pfe_hif_destroy_chnl (&hif_instance, 0);
  Starting walk at: pfe_hif_destroy_chnl (&hif_instance, 0);
  instance pointer: &hif_instance  Outer instance pointer: hif_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] HIF configuration failed: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif.c", 241, ret_10, "");
  Function call may change dynamic type:ret_10 = pfe_hif_cfg_init (cbus_base_va_7(D));
  Function call may change dynamic type:autolibc_memset (&hif_instance, 0, 384);
Determining dynamic type for call: pfe_hif_destroy_chnl (hif_22(D), ii_7);
  Starting walk at: pfe_hif_destroy_chnl (hif_22(D), ii_7);
  instance pointer: hif_22(D)  Outer instance pointer: hif_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:oal_util_raise_dem_for_drv_runtime_err ();
  Function call may change dynamic type:pfe_hm_report (1, 2, 1, "[%s:%d] Couldn\'t create channel\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif.c", 176, "");
  Function call may change dynamic type:ret_27 = pfe_hif_chnl_create_mcal (_3, _4, ii.0_5, 0B);
  Function call may change dynamic type:pfe_hif_chnl_tx_disable (_3);
  Function call may change dynamic type:pfe_hif_chnl_rx_disable (_3);
  Function call may change dynamic type:ret_27 = pfe_hif_chnl_create_mcal (_3, _4, ii.0_5, 0B);
  Function call may change dynamic type:autolibc_memset (_10, 0, 64);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_hif_chnl_cfg_set_emac_timer_ownership/45:
  Jump functions of caller  pfe_hif_chnl_cfg_set_hif_occupied/44:
  Jump functions of caller  pfe_hif_chnl_cfg_set_master_up/43:
  Jump functions of caller  pfe_hif_cfg_stop_all_chnl_dma/42:
  Jump functions of caller  pfe_hif_chnl_tx_disable/41:
  Jump functions of caller  pfe_hif_chnl_rx_disable/40:
  Jump functions of caller  pfe_hif_chnl_create_mcal/39:
  Jump functions of caller  pfe_hif_cfg_fini/38:
  Jump functions of caller  pfe_hif_chnl_destroy/37:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/36:
  Jump functions of caller  pfe_hm_report/35:
  Jump functions of caller  pfe_hif_cfg_init/34:
  Jump functions of caller  autolibc_memset/33:
  Jump functions of caller  pfe_hif_cfg_irq_unmask/32:
  Jump functions of caller  pfe_hif_cfg_irq_mask/31:
  Jump functions of caller  pfe_hif_cfg_isr/30:
  Jump functions of caller  pfe_hif_clear_emac_timer_ownership/29:
  Jump functions of caller  pfe_hif_init_emac_timer_ownership/28:
  Jump functions of caller  pfe_hif_set_master_up/27:
  Jump functions of caller  pfe_hif_clear_master_up/26:
  Jump functions of caller  pfe_hif_destroy/25:
    callsite  pfe_hif_destroy/25 -> pfe_hif_clear_emac_timer_ownership/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_destroy/25 -> pfe_hif_clear_master_up/26 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_get_channel_phy/24:
  Jump functions of caller  pfe_hif_get_channel/23:
  Jump functions of caller  pfe_hif_create/22:
    callsite  pfe_hif_create/22 -> pfe_hif_create_bind_chnl/21 : 
       param 0: CONST: &hif_instance
         value: 0x0, mask: 0xffffffc0
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_create/22 -> pfe_hif_destroy_chnl/20 : 
       param 0: CONST: &hif_instance
         value: 0x0, mask: 0xffffffc0
         VR  ~[0, 0]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pfe_hif_create_bind_chnl/21:
    callsite  pfe_hif_create_bind_chnl/21 -> pfe_hif_destroy_chnl/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
  Jump functions of caller  pfe_hif_destroy_chnl/20:
  Jump functions of caller  pfe_hif_get_master_detect_cfg/19:
  Jump functions of caller  pfe_hif_set_master_detect_cfg/18:
  Jump functions of caller  pfe_hif_irq_unmask/17:
  Jump functions of caller  pfe_hif_irq_mask/16:
  Jump functions of caller  pfe_hif_isr/15:

 Propagating constants:

Not considering pfe_hif_clear_emac_timer_ownership for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_init_emac_timer_ownership for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_set_master_up for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_clear_master_up for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_get_channel_phy for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_get_channel for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_get_master_detect_cfg for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_set_master_detect_cfg for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_isr for cloning; -fipa-cp-clone disabled.

overall_size: 265, max_new_size: 11001
 - context independent values, size: 44, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 19, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: pfe_hif_clear_emac_timer_ownership/29:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_init_emac_timer_ownership/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_set_master_up/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_clear_master_up/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_destroy/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_get_channel_phy/24:
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
  Node: pfe_hif_get_channel/23:
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
  Node: pfe_hif_create/22:
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
  Node: pfe_hif_create_bind_chnl/21:
    param [0]: &hif_instance [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xffffffc0
         struct pfe_hif_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_hif_destroy_chnl/20:
    param [0]: &hif_instance [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xffffffc0
         struct pfe_hif_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 67, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         int32_t [0, 3]
        AGGS VARIABLE
  Node: pfe_hif_get_master_detect_cfg/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_set_master_detect_cfg/18:
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
  Node: pfe_hif_irq_unmask/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_irq_mask/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_isr/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

 - Creating a specialized node of pfe_hif_create_bind_chnl/21 for all known contexts.
    replacing param #0 hif with const &hif_instance
 - Creating a specialized node of pfe_hif_destroy_chnl/20 for all known contexts.
    replacing param #0 hif with const &hif_instance
Propagated bits info for function pfe_hif_destroy_chnl.constprop/47:
 param 0: value = 0x0, mask = 0xffffffc0
 param 1: value = 0x0, mask = 0x3
Propagated bits info for function pfe_hif_create_bind_chnl.constprop/46:
 param 0: value = 0x0, mask = 0xffffffc0
Propagated bits info for function pfe_hif_create_bind_chnl/21:
 param 0: value = 0x0, mask = 0xffffffc0
Propagated bits info for function pfe_hif_destroy_chnl/20:
 param 0: value = 0x0, mask = 0xffffffc0
 param 1: value = 0x0, mask = 0x3

IPA constant propagation end

Reclaiming functions: pfe_hif_create_bind_chnl/21 pfe_hif_destroy_chnl/20
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_hif_destroy_chnl.constprop.0/47 (pfe_hif_destroy_chnl.constprop) @070929a0
  Type: function definition analyzed
  Visibility:
  References: hif_instance/14 (addr)
  Referring: 
  Clone of pfe_hif_destroy_chnl/20
  Availability: local
  Function flags: count:118111600 (estimated locally) local optimize_size
  Called by: pfe_hif_create/22 (170234250 (estimated locally),0.16 per call) pfe_hif_create_bind_chnl.constprop/46 (0 (precise),0.00 per call) 
  Calls: pfe_hif_chnl_destroy/37 (0 (precise),0.00 per call) pfe_hif_cfg_fini/38 (118111601 (estimated locally),1.00 per call) 
pfe_hif_create_bind_chnl.constprop.0/46 (pfe_hif_create_bind_chnl.constprop) @06e55d20
  Type: function definition analyzed
  Visibility:
  References: hif_instance/14 (addr)
  Referring: 
  Clone of pfe_hif_create_bind_chnl/21
  Availability: local
  Function flags: count:214748364 (estimated locally) local optimize_size
  Called by: pfe_hif_create/22 (416780405 (estimated locally),0.39 per call) 
  Calls: pfe_hif_chnl_create_mcal/39 (0 (precise),0.00 per call) pfe_hm_report/35 (0 (precise),0.00 per call) oal_util_raise_dem_for_drv_runtime_err/36 (0 (precise),0.00 per call) pfe_hif_destroy_chnl.constprop/47 (0 (precise),0.00 per call) pfe_hif_chnl_rx_disable/40 (0 (precise),0.00 per call) pfe_hif_chnl_tx_disable/41 (0 (precise),0.00 per call) autolibc_memset/33 (858993459 (estimated locally),4.00 per call) 
pfe_hif_chnl_cfg_set_emac_timer_ownership/45 (pfe_hif_chnl_cfg_set_emac_timer_ownership) @076762a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_clear_emac_timer_ownership/29 (141733921 (estimated locally),0.54 per call) pfe_hif_init_emac_timer_ownership/28 (141733921 (estimated locally),0.54 per call) 
  Calls: 
pfe_hif_chnl_cfg_set_hif_occupied/44 (pfe_hif_chnl_cfg_set_hif_occupied) @076760e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_set_master_up/27 (429496729 (estimated locally),2.00 per call) 
  Calls: 
pfe_hif_chnl_cfg_set_master_up/43 (pfe_hif_chnl_cfg_set_master_up) @07669ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_set_master_up/27 (429496729 (estimated locally),2.00 per call) pfe_hif_set_master_up/27 (429496729 (estimated locally),2.00 per call) pfe_hif_clear_master_up/26 (858993459 (estimated locally),4.00 per call) 
  Calls: 
pfe_hif_cfg_stop_all_chnl_dma/42 (pfe_hif_cfg_stop_all_chnl_dma) @07669d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_destroy/25 (214748364 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_chnl_tx_disable/41 (pfe_hif_chnl_tx_disable) @076699a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_create_bind_chnl.constprop/46 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_rx_disable/40 (pfe_hif_chnl_rx_disable) @076698c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_create_bind_chnl.constprop/46 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_chnl_create_mcal/39 (pfe_hif_chnl_create_mcal) @076697e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_create_bind_chnl.constprop/46 (0 (precise),0.00 per call) 
  Calls: 
pfe_hif_cfg_fini/38 (pfe_hif_cfg_fini) @07669620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_destroy_chnl.constprop/47 (118111601 (estimated locally),1.00 per call) pfe_hif_destroy/25 (214748365 (estimated locally),0.53 per call) 
  Calls: 
pfe_hif_chnl_destroy/37 (pfe_hif_chnl_destroy) @07669540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_destroy_chnl.constprop/47 (0 (precise),0.00 per call) pfe_hif_destroy/25 (0 (precise),0.00 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/36 (oal_util_raise_dem_for_drv_runtime_err) @07669380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_create_bind_chnl.constprop/46 (0 (precise),0.00 per call) pfe_hif_create/22 (69810718 (estimated locally),0.07 per call) pfe_hif_create/22 (170234250 (estimated locally),0.16 per call) 
  Calls: 
pfe_hm_report/35 (pfe_hm_report) @076692a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_create_bind_chnl.constprop/46 (0 (precise),0.00 per call) pfe_hif_create/22 (69810718 (estimated locally),0.07 per call) pfe_hif_create/22 (170234250 (estimated locally),0.16 per call) 
  Calls: 
pfe_hif_cfg_init/34 (pfe_hif_cfg_init) @076691c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_create/22 (587014656 (estimated locally),0.55 per call) 
  Calls: 
autolibc_memset/33 (autolibc_memset) @076690e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_create_bind_chnl.constprop/46 (858993459 (estimated locally),4.00 per call) pfe_hif_create/22 (587014656 (estimated locally),0.55 per call) 
  Calls: 
pfe_hif_cfg_irq_unmask/32 (pfe_hif_cfg_irq_unmask) @076400e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_irq_unmask/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_cfg_irq_mask/31 (pfe_hif_cfg_irq_mask) @07640e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_irq_mask/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_cfg_isr/30 (pfe_hif_cfg_isr) @07640c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_hif_isr/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_clear_emac_timer_ownership/29 (pfe_hif_clear_emac_timer_ownership) @076407e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:261993004 (estimated locally) body optimize_size
  Called by: pfe_hif_destroy/25 (214748364 (estimated locally),0.53 per call) 
  Calls: pfe_hif_chnl_cfg_set_emac_timer_ownership/45 (141733921 (estimated locally),0.54 per call) 
pfe_hif_init_emac_timer_ownership/28 (pfe_hif_init_emac_timer_ownership) @07640540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:261993004 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_set_emac_timer_ownership/45 (141733921 (estimated locally),0.54 per call) 
pfe_hif_set_master_up/27 (pfe_hif_set_master_up) @076402a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:214748364 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_chnl_cfg_set_master_up/43 (429496729 (estimated locally),2.00 per call) pfe_hif_chnl_cfg_set_hif_occupied/44 (429496729 (estimated locally),2.00 per call) pfe_hif_chnl_cfg_set_master_up/43 (429496729 (estimated locally),2.00 per call) 
pfe_hif_clear_master_up/26 (pfe_hif_clear_master_up) @07640000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:214748364 (estimated locally) body optimize_size
  Called by: pfe_hif_destroy/25 (214748364 (estimated locally),0.53 per call) 
  Calls: pfe_hif_chnl_cfg_set_master_up/43 (858993459 (estimated locally),4.00 per call) 
pfe_hif_destroy/25 (pfe_hif_destroy) @0759c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:401624021 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_cfg_fini/38 (214748365 (estimated locally),0.53 per call) pfe_hif_chnl_destroy/37 (0 (precise),0.00 per call) pfe_hif_cfg_stop_all_chnl_dma/42 (214748364 (estimated locally),0.53 per call) pfe_hif_clear_emac_timer_ownership/29 (214748364 (estimated locally),0.53 per call) pfe_hif_clear_master_up/26 (214748364 (estimated locally),0.53 per call) 
pfe_hif_get_channel_phy/24 (pfe_hif_get_channel_phy) @0759c2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_get_channel/23 (pfe_hif_get_channel) @0759cee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:369004231 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_create/22 (pfe_hif_create) @0759cc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: hif_instance/14 (addr)hif_instance/14 (write)hif_instance/14 (addr)hif_instance/14 (addr)hif_instance/14 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/36 (69810718 (estimated locally),0.07 per call) pfe_hm_report/35 (69810718 (estimated locally),0.07 per call) pfe_hif_create_bind_chnl.constprop/46 (416780405 (estimated locally),0.39 per call) pfe_hif_destroy_chnl.constprop/47 (170234250 (estimated locally),0.16 per call) oal_util_raise_dem_for_drv_runtime_err/36 (170234250 (estimated locally),0.16 per call) pfe_hm_report/35 (170234250 (estimated locally),0.16 per call) pfe_hif_cfg_init/34 (587014656 (estimated locally),0.55 per call) autolibc_memset/33 (587014656 (estimated locally),0.55 per call) 
pfe_hif_create_bind_chnl/21 (pfe_hif_create_bind_chnl) @0759c7e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:214748364 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_destroy_chnl/20 (pfe_hif_destroy_chnl) @0759c460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_get_master_detect_cfg/19 (pfe_hif_get_master_detect_cfg) @0759c1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_set_master_detect_cfg/18 (pfe_hif_set_master_detect_cfg) @07596ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_irq_unmask/17 (pfe_hif_irq_unmask) @075969a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_cfg_irq_unmask/32 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_irq_mask/16 (pfe_hif_irq_mask) @07596e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_cfg_irq_mask/31 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_isr/15 (pfe_hif_isr) @07596b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_cfg_isr/30 (1073741824 (estimated locally),1.00 per call) 
hif_instance/14 (hif_instance) @0754aa68
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_hif_create/22 (addr)pfe_hif_create/22 (write)pfe_hif_create/22 (addr)pfe_hif_create/22 (addr)pfe_hif_create/22 (addr)pfe_hif_create_bind_chnl.constprop.0/46 (addr)pfe_hif_destroy_chnl.constprop.0/47 (addr)
  Availability: available
  Varpool flags:

;; Function pfe_hif_destroy_chnl.constprop (pfe_hif_destroy_chnl.constprop.0, funcdef_no=27, decl_uid=10175, cgraph_uid=45, symbol_order=47)

Modification phase of node pfe_hif_destroy_chnl.constprop/47
Adjusting mask for param 1 to 0x3
Setting value range of param 1 [0, 3]
pfe_hif_destroy_chnl.constprop (int32_t count)
{
  int32_t ii;
  uint32_t channels_mask;
  struct pfe_hif_t * hif;
  <unnamed type> _3;
  long unsigned int _5;
  struct pfe_hif_chnl_t * _7;
  <unnamed type> _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned int _13;

  <bb 8> [local count: 118111600]:
  # DEBUG hif => &hif_instance

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG ii => count_1(D)
  # DEBUG BEGIN_STMT
  channels_mask_2 = 1 << count_1(D);
  # DEBUG channels_mask => channels_mask_2
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _3 = hif_instance.configured_channels_mask;
  _5 = _3 & channels_mask_4;
  if (_5 != 0)
    goto <bb 4>; [0.00%]
  else
    goto <bb 5>; [100.00%]

  <bb 4> [count: 0]:
  # DEBUG BEGIN_STMT
  _7 = &hif_instance.channels[ii_6];
  pfe_hif_chnl_destroy (_7);
  # DEBUG BEGIN_STMT
  _8 = hif_instance.configured_channels_mask;
  _9 = ~channels_mask_4;
  _10 = _8 & _9;
  hif_instance.configured_channels_mask = _10;

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  channels_mask_11 = channels_mask_4 >> 1;
  # DEBUG channels_mask => channels_mask_11
  # DEBUG BEGIN_STMT
  ii_12 = ii_6 + -1;
  # DEBUG ii => ii_12

  <bb 6> [local count: 1073741824]:
  # ii_6 = PHI <count_1(D)(2), ii_12(5)>
  # channels_mask_4 = PHI <channels_mask_2(2), channels_mask_11(5)>
  # DEBUG channels_mask => channels_mask_4
  # DEBUG ii => ii_6
  # DEBUG BEGIN_STMT
  if (ii_6 >= 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  _13 = hif_instance.cbus_base_va;
  pfe_hif_cfg_fini (_13);
  return;

}



;; Function pfe_hif_isr (pfe_hif_isr, funcdef_no=12, decl_uid=8088, cgraph_uid=13, symbol_order=15)

Modification phase of node pfe_hif_isr/15
pfe_hif_isr (struct pfe_hif_t * hif)
{
  errno_t ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = hif_3(D)->cbus_base_va;
  ret_5 = pfe_hif_cfg_isr (_1);
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_hif_irq_mask (pfe_hif_irq_mask, funcdef_no=13, decl_uid=8090, cgraph_uid=14, symbol_order=16)

Modification phase of node pfe_hif_irq_mask/16
pfe_hif_irq_mask (struct pfe_hif_t * hif)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = hif_3(D)->cbus_base_va;
  pfe_hif_cfg_irq_mask (_1);
  return;

}



;; Function pfe_hif_irq_unmask (pfe_hif_irq_unmask, funcdef_no=14, decl_uid=8092, cgraph_uid=15, symbol_order=17)

Modification phase of node pfe_hif_irq_unmask/17
pfe_hif_irq_unmask (struct pfe_hif_t * hif)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = hif_3(D)->cbus_base_va;
  pfe_hif_cfg_irq_unmask (_1);
  return;

}



;; Function pfe_hif_set_master_detect_cfg (pfe_hif_set_master_detect_cfg, funcdef_no=15, decl_uid=8103, cgraph_uid=16, symbol_order=18)

Modification phase of node pfe_hif_set_master_detect_cfg/18
pfe_hif_set_master_detect_cfg (struct pfe_hif_t * hif, bool_t on)
{
  _Bool _1;
  unsigned char _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = on_3(D) == 0;
  _2 = (unsigned char) _1;
  hif_5(D)->disable_master_detect = _2;
  return;

}



;; Function pfe_hif_get_master_detect_cfg (pfe_hif_get_master_detect_cfg, funcdef_no=16, decl_uid=8105, cgraph_uid=17, symbol_order=19)

Modification phase of node pfe_hif_get_master_detect_cfg/19
pfe_hif_get_master_detect_cfg (const struct pfe_hif_t * hif)
{
  unsigned char _1;
  _Bool _2;
  bool_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = hif_4(D)->disable_master_detect;
  _2 = _1 == 0;
  _5 = (bool_t) _2;
  return _5;

}



;; Function pfe_hif_create (pfe_hif_create, funcdef_no=19, decl_uid=8078, cgraph_uid=20, symbol_order=22)

Modification phase of node pfe_hif_create/22
pfe_hif_create (addr_t cbus_base_va, pfe_hif_chnl_id_t channels_mask)
{
  errno_t ret;
  struct pfe_hif_t * hif;
  long unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  # DEBUG BEGIN_STMT
  _1 = channels_mask_4(D) & 4294967280;
  if (_1 != 0)
    goto <bb 7>; [45.33%]
  else
    goto <bb 3>; [54.67%]

  <bb 3> [local count: 587014656]:
  # DEBUG BEGIN_STMT
  # DEBUG hif => &hif_instance
  # DEBUG BEGIN_STMT
  autolibc_memset (&hif_instance, 0, 384);
  # DEBUG BEGIN_STMT
  hif_instance.cbus_base_va = cbus_base_va_7(D);
  # DEBUG BEGIN_STMT
  ret_10 = pfe_hif_cfg_init (cbus_base_va_7(D));
  # DEBUG ret => ret_10
  # DEBUG BEGIN_STMT
  if (ret_10 != 0)
    goto <bb 4>; [29.00%]
  else
    goto <bb 5>; [71.00%]

  <bb 4> [local count: 170234250]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF configuration failed: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif.c", 241, ret_10, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hif_destroy_chnl (&hif_instance, 0);
  # DEBUG BEGIN_STMT
  # DEBUG hif => 0B
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 416780405]:
  # DEBUG BEGIN_STMT
  ret_12 = pfe_hif_create_bind_chnl (&hif_instance, channels_mask_4(D));
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  if (ret_12 != 0)
    goto <bb 6>; [16.75%]
  else
    goto <bb 7>; [83.25%]

  <bb 6> [local count: 69810718]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF configuration failed: %d\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_hif.c", 251, ret_12, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG hif => 0B

  <bb 7> [local count: 1073741824]:
  # hif_2 = PHI <0B(2), 0B(4), &hif_instance(5), 0B(6)>
  # DEBUG hif => hif_2
  # DEBUG BEGIN_STMT
  return hif_2;

}



;; Function pfe_hif_get_channel (pfe_hif_get_channel, funcdef_no=20, decl_uid=8081, cgraph_uid=21, symbol_order=23)

Modification phase of node pfe_hif_get_channel/23
pfe_hif_get_channel (struct pfe_hif_t * hif, pfe_hif_chnl_id_t channel_id)
{
  struct pfe_hif_chnl_t * entry;
  uint32_t ii;
  <unnamed type> _1;
  long unsigned int _2;
  unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 369004231]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG entry => 0B
  # DEBUG BEGIN_STMT
  _1 = hif_9(D)->configured_channels_mask;
  _2 = _1 & channel_id_10(D);
  if (_2 != 0)
    goto <bb 8>; [71.00%]
  else
    goto <bb 7>; [29.00%]

  <bb 8> [local count: 261993004]:
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 858993460]:
  # DEBUG BEGIN_STMT
  _3 = 1 << ii_5;
  _4 = _3 & channel_id_10(D);
  if (_4 != 0)
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 47244640]:
  # ii_7 = PHI <ii_5(3)>
  # DEBUG BEGIN_STMT
  entry_12 = &hif_9(D)->channels[ii_7];
  # DEBUG entry => entry_12
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 811748819]:
  # DEBUG BEGIN_STMT
  ii_11 = ii_5 + 1;
  # DEBUG ii => ii_11

  <bb 6> [local count: 1073741824]:
  # ii_5 = PHI <ii_11(5), 0(8)>
  # DEBUG ii => ii_5
  # DEBUG BEGIN_STMT
  if (ii_5 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 7>; [20.00%]

  <bb 7> [local count: 369004233]:
  # entry_6 = PHI <0B(2), entry_12(4), 0B(6)>
  # DEBUG entry => entry_6
  # DEBUG BEGIN_STMT
  return entry_6;

}



;; Function pfe_hif_get_channel_phy (pfe_hif_get_channel_phy, funcdef_no=21, decl_uid=8084, cgraph_uid=22, symbol_order=24)

Modification phase of node pfe_hif_get_channel_phy/24
pfe_hif_get_channel_phy (struct pfe_hif_t * hif, pfe_ct_phy_if_id_t phy)
{
  struct pfe_hif_chnl_t * ret;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0B
  # DEBUG BEGIN_STMT
  _1 = phy_5(D) + 250;
  if (_1 <= 3)
    goto <bb 3>; [71.00%]
  else
    goto <bb 4>; [29.00%]

  <bb 3> [local count: 762356696]:
  # DEBUG BEGIN_STMT
  _2 = (long unsigned int) phy_5(D);
  _3 = _2 + 4294967290;
  ret_7 = &hif_6(D)->channels[_3];
  # DEBUG ret => ret_7

  <bb 4> [local count: 1073741824]:
  # ret_4 = PHI <0B(2), ret_7(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_hif_clear_master_up (pfe_hif_clear_master_up, funcdef_no=23, decl_uid=8094, cgraph_uid=24, symbol_order=26)

Modification phase of node pfe_hif_clear_master_up/26
pfe_hif_clear_master_up (const struct pfe_hif_t * hif)
{
  uint32_t ii;
  unsigned int _1;

  <bb 2> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  _1 = hif_5(D)->cbus_base_va;
  pfe_hif_chnl_cfg_set_master_up (_1, ii_2, 0);
  # DEBUG BEGIN_STMT
  ii_7 = ii_2 + 1;
  # DEBUG ii => ii_7

  <bb 4> [local count: 1073741824]:
  # ii_2 = PHI <0(2), ii_7(3)>
  # DEBUG ii => ii_2
  # DEBUG BEGIN_STMT
  if (ii_2 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 5>; [20.00%]

  <bb 5> [local count: 214748365]:
  return;

}



;; Function pfe_hif_set_master_up (pfe_hif_set_master_up, funcdef_no=24, decl_uid=8096, cgraph_uid=25, symbol_order=27)

Modification phase of node pfe_hif_set_master_up/27
pfe_hif_set_master_up (const struct pfe_hif_t * hif)
{
  uint32_t ii;
  <unnamed type> _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned int _4;
  unsigned int _5;
  unsigned int _6;

  <bb 2> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  _1 = hif_11(D)->configured_channels_mask;
  _2 = _1 >> ii_7;
  _3 = _2 & 1;
  if (_3 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 429496729]:
  # DEBUG BEGIN_STMT
  _4 = hif_11(D)->cbus_base_va;
  pfe_hif_chnl_cfg_set_master_up (_4, ii_7, 1);
  # DEBUG BEGIN_STMT
  _5 = hif_11(D)->cbus_base_va;
  pfe_hif_chnl_cfg_set_hif_occupied (_5, ii_7, 1);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 429496729]:
  # DEBUG BEGIN_STMT
  _6 = hif_11(D)->cbus_base_va;
  pfe_hif_chnl_cfg_set_master_up (_6, ii_7, 1);

  <bb 6> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  ii_15 = ii_7 + 1;
  # DEBUG ii => ii_15

  <bb 7> [local count: 1073741824]:
  # ii_7 = PHI <0(2), ii_15(6)>
  # DEBUG ii => ii_7
  # DEBUG BEGIN_STMT
  if (ii_7 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 8>; [20.00%]

  <bb 8> [local count: 214748365]:
  return;

}



;; Function pfe_hif_init_emac_timer_ownership (pfe_hif_init_emac_timer_ownership, funcdef_no=25, decl_uid=8098, cgraph_uid=26, symbol_order=28)

Modification phase of node pfe_hif_init_emac_timer_ownership/28
pfe_hif_init_emac_timer_ownership (const struct pfe_hif_t * hif)
{
  pfe_ct_phy_if_id_t emac_id;
  uint32_t chnl_id;
  <unnamed type> _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned int _4;

  <bb 2> [local count: 261993004]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG chnl_id => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  _1 = hif_11(D)->configured_channels_mask;
  _2 = _1 >> chnl_id_6;
  _3 = _2 & 1;
  if (_3 != 0)
    goto <bb 4>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 4> [local count: 47244640]:
  # chnl_id_5 = PHI <chnl_id_6(3)>
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 141733921]:
  # DEBUG BEGIN_STMT
  _4 = hif_11(D)->cbus_base_va;
  pfe_hif_chnl_cfg_set_emac_timer_ownership (_4, chnl_id_5, emac_id_7, 1);
  # DEBUG BEGIN_STMT
  emac_id_14 = emac_id_7 + 1;
  # DEBUG emac_id => emac_id_14

  <bb 6> [local count: 188978561]:
  # emac_id_7 = PHI <emac_id_14(5), 0(4)>
  # DEBUG emac_id => emac_id_7
  # DEBUG BEGIN_STMT
  if (emac_id_7 <= 2)
    goto <bb 5>; [75.00%]
  else
    goto <bb 9>; [25.00%]

  <bb 7> [local count: 811748819]:
  # DEBUG BEGIN_STMT
  chnl_id_12 = chnl_id_6 + 1;
  # DEBUG chnl_id => chnl_id_12

  <bb 8> [local count: 1073741824]:
  # chnl_id_6 = PHI <0(2), chnl_id_12(7)>
  # DEBUG chnl_id => chnl_id_6
  # DEBUG BEGIN_STMT
  if (chnl_id_6 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 9>; [20.00%]

  <bb 9> [local count: 261993005]:
  return;

}



;; Function pfe_hif_clear_emac_timer_ownership (pfe_hif_clear_emac_timer_ownership, funcdef_no=26, decl_uid=8100, cgraph_uid=27, symbol_order=29)

Modification phase of node pfe_hif_clear_emac_timer_ownership/29
pfe_hif_clear_emac_timer_ownership (const struct pfe_hif_t * hif)
{
  pfe_ct_phy_if_id_t emac_id;
  uint32_t chnl_id;
  <unnamed type> _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned int _4;

  <bb 2> [local count: 261993004]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG chnl_id => 0
  goto <bb 8>; [100.00%]

  <bb 3> [local count: 858993459]:
  # DEBUG BEGIN_STMT
  _1 = hif_11(D)->configured_channels_mask;
  _2 = _1 >> chnl_id_6;
  _3 = _2 & 1;
  if (_3 != 0)
    goto <bb 4>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 4> [local count: 47244640]:
  # chnl_id_5 = PHI <chnl_id_6(3)>
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 141733921]:
  # DEBUG BEGIN_STMT
  _4 = hif_11(D)->cbus_base_va;
  pfe_hif_chnl_cfg_set_emac_timer_ownership (_4, chnl_id_5, emac_id_7, 0);
  # DEBUG BEGIN_STMT
  emac_id_14 = emac_id_7 + 1;
  # DEBUG emac_id => emac_id_14

  <bb 6> [local count: 188978561]:
  # emac_id_7 = PHI <emac_id_14(5), 0(4)>
  # DEBUG emac_id => emac_id_7
  # DEBUG BEGIN_STMT
  if (emac_id_7 <= 2)
    goto <bb 5>; [75.00%]
  else
    goto <bb 9>; [25.00%]

  <bb 7> [local count: 811748819]:
  # DEBUG BEGIN_STMT
  chnl_id_12 = chnl_id_6 + 1;
  # DEBUG chnl_id => chnl_id_12

  <bb 8> [local count: 1073741824]:
  # chnl_id_6 = PHI <0(2), chnl_id_12(7)>
  # DEBUG chnl_id => chnl_id_6
  # DEBUG BEGIN_STMT
  if (chnl_id_6 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 9>; [20.00%]

  <bb 9> [local count: 261993005]:
  return;

}



;; Function pfe_hif_destroy (pfe_hif_destroy, funcdef_no=22, decl_uid=8086, cgraph_uid=23, symbol_order=25)

Modification phase of node pfe_hif_destroy/25
pfe_hif_destroy (struct pfe_hif_t * hif)
{
  uint32_t channels_mask;
  uint32_t ii;
  <unnamed type> _1;
  long unsigned int _2;
  struct pfe_hif_chnl_t * _3;
  <unnamed type> _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned int _7;

  <bb 2> [local count: 401624021]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG channels_mask => 1
  # DEBUG BEGIN_STMT
  if (hif_13(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 3> [local count: 214748364]:
  # DEBUG BEGIN_STMT
  pfe_hif_clear_master_up (hif_13(D));
  # DEBUG BEGIN_STMT
  pfe_hif_clear_emac_timer_ownership (hif_13(D));
  # DEBUG BEGIN_STMT
  pfe_hif_cfg_stop_all_chnl_dma ();
  # DEBUG BEGIN_STMT
  # DEBUG ii => 0
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 858993460]:
  # DEBUG BEGIN_STMT
  _1 = hif_13(D)->configured_channels_mask;
  _2 = _1 & channels_mask_9;
  if (_2 != 0)
    goto <bb 5>; [0.00%]
  else
    goto <bb 6>; [100.00%]

  <bb 5> [count: 0]:
  # DEBUG BEGIN_STMT
  _3 = &hif_13(D)->channels[ii_8];
  pfe_hif_chnl_destroy (_3);
  # DEBUG BEGIN_STMT
  _4 = hif_13(D)->configured_channels_mask;
  _5 = ~channels_mask_9;
  _6 = _4 & _5;
  hif_13(D)->configured_channels_mask = _6;

  <bb 6> [local count: 858993460]:
  # DEBUG BEGIN_STMT
  channels_mask_21 = channels_mask_9 << 1;
  # DEBUG channels_mask => channels_mask_21
  # DEBUG BEGIN_STMT
  ii_22 = ii_8 + 1;
  # DEBUG ii => ii_22

  <bb 7> [local count: 1073741824]:
  # ii_8 = PHI <0(3), ii_22(6)>
  # channels_mask_9 = PHI <1(3), channels_mask_21(6)>
  # DEBUG channels_mask => channels_mask_9
  # DEBUG ii => ii_8
  # DEBUG BEGIN_STMT
  if (ii_8 != 4)
    goto <bb 4>; [80.00%]
  else
    goto <bb 8>; [20.00%]

  <bb 8> [local count: 214748365]:
  # DEBUG BEGIN_STMT
  _7 = hif_13(D)->cbus_base_va;
  pfe_hif_cfg_fini (_7);

  <bb 9> [local count: 401624022]:
  return;

}


