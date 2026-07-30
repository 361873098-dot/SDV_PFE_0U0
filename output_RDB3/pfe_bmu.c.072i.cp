
IPA constant propagation start:
Determining dynamic type for call: pfe_bmu_reset (bmu_16);
  Starting walk at: pfe_bmu_reset (bmu_16);
  instance pointer: bmu_16  Outer instance pointer: &bmu_instance[bmu_index_15(D)] offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:autolibc_memset (bmu_16, 0, 32);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_bmu_cfg_get_special_stats/44:
  Jump functions of caller  pfe_bmu_cfg_get_stat_value/43:
  Jump functions of caller  pfe_bmu_cfg_fini/42:
  Jump functions of caller  pfe_bmu_cfg_free_buf/41:
  Jump functions of caller  pfe_bmu_cfg_alloc_buf/40:
  Jump functions of caller  pfe_bmu_cfg_enable/39:
  Jump functions of caller  pfe_bmu_cfg_reset/38:
  Jump functions of caller  pfe_bmu_cfg_init/37:
  Jump functions of caller  pfe_bmu_cfg_disable/36:
  Jump functions of caller  autolibc_memset/35:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/34:
  Jump functions of caller  pfe_hm_report/33:
  Jump functions of caller  __builtin_expect/32:
  Jump functions of caller  pfe_bmu_cfg_irq_unmask/31:
  Jump functions of caller  pfe_bmu_cfg_irq_mask/30:
  Jump functions of caller  pfe_bmu_cfg_isr/29:
  Jump functions of caller  pfe_bmu_get_special_stats/28:
  Jump functions of caller  pfe_bmu_get_stat_value/27:
  Jump functions of caller  pfe_bmu_destroy/26:
  Jump functions of caller  pfe_bmu_free_buf/25:
  Jump functions of caller  pfe_bmu_get_buf_size/24:
  Jump functions of caller  pfe_bmu_get_pa/23:
  Jump functions of caller  pfe_bmu_get_va/22:
  Jump functions of caller  pfe_bmu_alloc_buf/21:
  Jump functions of caller  pfe_bmu_disable/20:
  Jump functions of caller  pfe_bmu_enable/19:
  Jump functions of caller  pfe_bmu_reset/18:
  Jump functions of caller  pfe_bmu_create/17:
    callsite  pfe_bmu_create/17 -> pfe_bmu_reset/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  pfe_bmu_irq_unmask/16:
  Jump functions of caller  pfe_bmu_irq_mask/15:
  Jump functions of caller  pfe_bmu_isr/14:

 Propagating constants:

Not considering pfe_bmu_get_special_stats for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_get_stat_value for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_free_buf for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_get_buf_size for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_get_pa for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_get_va for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_alloc_buf for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_reset for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_bmu_isr for cloning; -fipa-cp-clone disabled.

overall_size: 135, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_bmu_get_special_stats/28:
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
  Node: pfe_bmu_get_stat_value/27:
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
  Node: pfe_bmu_destroy/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_free_buf/25:
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
  Node: pfe_bmu_get_buf_size/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_get_pa/23:
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
  Node: pfe_bmu_get_va/22:
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
  Node: pfe_bmu_alloc_buf/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_disable/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_enable/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_reset/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_create/17:
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
  Node: pfe_bmu_irq_unmask/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_irq_mask/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_bmu_isr/14:
    param [0]: BOTTOM
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

pfe_bmu_cfg_get_special_stats/44 (pfe_bmu_cfg_get_special_stats) @07576000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_get_special_stats/28 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_get_stat_value/43 (pfe_bmu_cfg_get_stat_value) @0755be00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_get_stat_value/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_fini/42 (pfe_bmu_cfg_fini) @0755bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_destroy/26 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pfe_bmu_cfg_free_buf/41 (pfe_bmu_cfg_free_buf) @0755ba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_free_buf/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_alloc_buf/40 (pfe_bmu_cfg_alloc_buf) @0755b620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_alloc_buf/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_enable/39 (pfe_bmu_cfg_enable) @0755b380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_enable/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_reset/38 (pfe_bmu_cfg_reset) @0755b1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_reset/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_init/37 (pfe_bmu_cfg_init) @0755b000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_create/17 (966367642 (estimated locally),0.90 per call) 
  Calls: 
pfe_bmu_cfg_disable/36 (pfe_bmu_cfg_disable) @075530e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_destroy/26 (574129754 (estimated locally),0.53 per call) pfe_bmu_disable/20 (1073741824 (estimated locally),1.00 per call) pfe_bmu_create/17 (966367642 (estimated locally),0.90 per call) 
  Calls: 
autolibc_memset/35 (autolibc_memset) @07553ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_create/17 (966367642 (estimated locally),0.90 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/34 (oal_util_raise_dem_for_drv_runtime_err) @07553e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_create/17 (107374182 (estimated locally),0.10 per call) 
  Calls: 
pfe_hm_report/33 (pfe_hm_report) @07553d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_create/17 (107374182 (estimated locally),0.10 per call) 
  Calls: 
__builtin_expect/32 (__builtin_expect) @07553c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_create/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_irq_unmask/31 (pfe_bmu_cfg_irq_unmask) @07553a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_irq_unmask/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_irq_mask/30 (pfe_bmu_cfg_irq_mask) @075538c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_irq_mask/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_cfg_isr/29 (pfe_bmu_cfg_isr) @07553700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_bmu_isr/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_bmu_get_special_stats/28 (pfe_bmu_get_special_stats) @075532a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_get_special_stats/44 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_get_stat_value/27 (pfe_bmu_get_stat_value) @07553000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_get_stat_value/43 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_destroy/26 (pfe_bmu_destroy) @075509a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_fini/42 (574129754 (estimated locally),0.53 per call) pfe_bmu_cfg_disable/36 (574129754 (estimated locally),0.53 per call) 
pfe_bmu_free_buf/25 (pfe_bmu_free_buf) @07550380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_free_buf/41 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_get_buf_size/24 (pfe_bmu_get_buf_size) @07550ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: 
pfe_bmu_get_pa/23 (pfe_bmu_get_pa) @07550c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: 
pfe_bmu_get_va/22 (pfe_bmu_get_va) @075508c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: 
pfe_bmu_alloc_buf/21 (pfe_bmu_alloc_buf) @07550540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body hot optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_alloc_buf/40 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_disable/20 (pfe_bmu_disable) @075502a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_disable/36 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_enable/19 (pfe_bmu_enable) @07550000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_enable/39 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_reset/18 (pfe_bmu_reset) @074e68c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: pfe_bmu_create/17 (966367642 (estimated locally),0.90 per call) 
  Calls: pfe_bmu_cfg_reset/38 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_create/17 (pfe_bmu_create) @074e6380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: bmu_instance/13 (addr)bmu_instance/13 (write)bmu_instance/13 (write)bmu_instance/13 (write)bmu_instance/13 (write)bmu_instance/13 (write)bmu_instance/13 (write)bmu_instance/13 (write)bmu_instance/13 (write)bmu_instance/13 (read)bmu_instance/13 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_init/37 (966367642 (estimated locally),0.90 per call) pfe_bmu_cfg_disable/36 (966367642 (estimated locally),0.90 per call) pfe_bmu_reset/18 (966367642 (estimated locally),0.90 per call) autolibc_memset/35 (966367642 (estimated locally),0.90 per call) oal_util_raise_dem_for_drv_runtime_err/34 (107374182 (estimated locally),0.10 per call) pfe_hm_report/33 (107374182 (estimated locally),0.10 per call) __builtin_expect/32 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_irq_unmask/16 (pfe_bmu_irq_unmask) @074e6a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_irq_unmask/31 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_irq_mask/15 (pfe_bmu_irq_mask) @074e67e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_irq_mask/30 (1073741824 (estimated locally),1.00 per call) 
pfe_bmu_isr/14 (pfe_bmu_isr) @074e6540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body unlikely_executed optimize_size
  Called by: 
  Calls: pfe_bmu_cfg_isr/29 (1073741824 (estimated locally),1.00 per call) 
bmu_instance/13 (bmu_instance) @074e4438
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_bmu_create/17 (addr)pfe_bmu_create/17 (write)pfe_bmu_create/17 (write)pfe_bmu_create/17 (write)pfe_bmu_create/17 (write)pfe_bmu_create/17 (write)pfe_bmu_create/17 (write)pfe_bmu_create/17 (write)pfe_bmu_create/17 (write)pfe_bmu_create/17 (read)pfe_bmu_create/17 (read)
  Availability: available
  Varpool flags:

;; Function pfe_bmu_isr (pfe_bmu_isr, funcdef_no=11, decl_uid=9470, cgraph_uid=12, symbol_order=14) (unlikely executed)

Modification phase of node pfe_bmu_isr/14
__attribute__((cold))
pfe_bmu_isr (struct pfe_bmu_t * bmu)
{
  errno_t ret;
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bmu_4(D)->bmu_base_va;
  _2 = bmu_4(D)->cbus_base_va;
  ret_6 = pfe_bmu_cfg_isr (_1, _2);
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_bmu_irq_mask (pfe_bmu_irq_mask, funcdef_no=12, decl_uid=9472, cgraph_uid=13, symbol_order=15)

Modification phase of node pfe_bmu_irq_mask/15
pfe_bmu_irq_mask (struct pfe_bmu_t * bmu)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  pfe_bmu_cfg_irq_mask (_1);
  return;

}



;; Function pfe_bmu_irq_unmask (pfe_bmu_irq_unmask, funcdef_no=13, decl_uid=9474, cgraph_uid=14, symbol_order=16)

Modification phase of node pfe_bmu_irq_unmask/16
pfe_bmu_irq_unmask (struct pfe_bmu_t * bmu)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  pfe_bmu_cfg_irq_unmask (_1);
  return;

}



;; Function pfe_bmu_reset (pfe_bmu_reset, funcdef_no=15, decl_uid=9478, cgraph_uid=16, symbol_order=18) (unlikely executed)

Modification phase of node pfe_bmu_reset/18
__attribute__((cold))
pfe_bmu_reset (struct pfe_bmu_t * bmu)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  pfe_bmu_cfg_reset (_1);
  # DEBUG ret => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_bmu_create (pfe_bmu_create, funcdef_no=14, decl_uid=9468, cgraph_uid=15, symbol_order=17) (unlikely executed)

Modification phase of node pfe_bmu_create/17
__attribute__((cold))
pfe_bmu_create (addr_t cbus_base_va, addr_t bmu_base, const struct pfe_bmu_cfg_t * cfg, uint32_t bmu_index)
{
  struct pfe_bmu_t * bmu;
  _Bool _1;
  long int _2;
  long int _3;
  unsigned int _4;
  unsigned int _5;
  unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned int _11;
  unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bmu_index_15(D) > 1;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 0);
  if (_3 != 0)
    goto <bb 3>; [10.00%]
  else
    goto <bb 4>; [90.00%]

  <bb 3> [local count: 107374182]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] BMU index out of range\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_bmu.c", 143, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG bmu => 0B
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  bmu_16 = &bmu_instance[bmu_index_15(D)];
  # DEBUG bmu => bmu_16
  # DEBUG BEGIN_STMT
  autolibc_memset (bmu_16, 0, 32);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].cbus_base_va = cbus_base_va_19(D);
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].bmu_base_offset = bmu_base_21(D);
  # DEBUG BEGIN_STMT
  _4 = cbus_base_va_19(D) + bmu_base_21(D);
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].bmu_base_va = _4;
  # DEBUG BEGIN_STMT
  _5 = cfg_24(D)->pool_pa;
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].pool_base_pa = _5;
  # DEBUG BEGIN_STMT
  _6 = cfg_24(D)->pool_va;
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].pool_base_va = _6;
  # DEBUG BEGIN_STMT
  _7 = _6 - _5;
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].pool_va_offset = _7;
  # DEBUG BEGIN_STMT
  _8 = cfg_24(D)->buf_size;
  _9 = cfg_24(D)->max_buf_cnt;
  # DEBUG BEGIN_STMT
  _10 = _8 * _9;
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].pool_size = _10;
  # DEBUG BEGIN_STMT
  MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].buf_size = _8;
  # DEBUG BEGIN_STMT
  pfe_bmu_reset (bmu_16);
  # DEBUG BEGIN_STMT
  _11 = MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].bmu_base_va;
  pfe_bmu_cfg_disable (_11);
  # DEBUG BEGIN_STMT
  _12 = MEM[(struct pfe_bmu_t *)&bmu_instance][bmu_index_15(D)].bmu_base_va;
  pfe_bmu_cfg_init (_12, cfg_24(D));

  <bb 5> [local count: 1073741824]:
  # bmu_13 = PHI <0B(3), bmu_16(4)>
  # DEBUG bmu => bmu_13
  # DEBUG BEGIN_STMT
  return bmu_13;

}



;; Function pfe_bmu_enable (pfe_bmu_enable, funcdef_no=16, decl_uid=9476, cgraph_uid=17, symbol_order=19) (unlikely executed)

Modification phase of node pfe_bmu_enable/19
__attribute__((cold))
pfe_bmu_enable (struct pfe_bmu_t * bmu)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  pfe_bmu_cfg_enable (_1);
  return;

}



;; Function pfe_bmu_disable (pfe_bmu_disable, funcdef_no=17, decl_uid=9480, cgraph_uid=18, symbol_order=20) (unlikely executed)

Modification phase of node pfe_bmu_disable/20
__attribute__((cold))
pfe_bmu_disable (struct pfe_bmu_t * bmu)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  pfe_bmu_cfg_disable (_1);
  return;

}



;; Function pfe_bmu_alloc_buf (pfe_bmu_alloc_buf, funcdef_no=18, decl_uid=9482, cgraph_uid=19, symbol_order=21) (hot)

Modification phase of node pfe_bmu_alloc_buf/21
__attribute__((hot))
pfe_bmu_alloc_buf (const struct pfe_bmu_t * bmu)
{
  void * ret;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  ret_5 = pfe_bmu_cfg_alloc_buf (_1);
  # DEBUG ret => ret_5
  # DEBUG BEGIN_STMT
  return ret_5;

}



;; Function pfe_bmu_get_va (pfe_bmu_get_va, funcdef_no=19, decl_uid=9485, cgraph_uid=20, symbol_order=22) (hot)

Modification phase of node pfe_bmu_get_va/22
__attribute__((pure, hot))
pfe_bmu_get_va (const struct pfe_bmu_t * bmu, addr_t pa)
{
  void * ret;
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bmu_4(D)->pool_va_offset;
  _2 = _1 + pa_5(D);
  ret_6 = (void *) _2;
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_bmu_get_pa (pfe_bmu_get_pa, funcdef_no=20, decl_uid=9488, cgraph_uid=21, symbol_order=23) (hot)

Modification phase of node pfe_bmu_get_pa/23
__attribute__((pure, hot))
pfe_bmu_get_pa (const struct pfe_bmu_t * bmu, addr_t va)
{
  void * ret;
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bmu_4(D)->pool_va_offset;
  _2 = va_5(D) - _1;
  ret_6 = (void *) _2;
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  return ret_6;

}



;; Function pfe_bmu_get_buf_size (pfe_bmu_get_buf_size, funcdef_no=21, decl_uid=9490, cgraph_uid=22, symbol_order=24) (unlikely executed)

Modification phase of node pfe_bmu_get_buf_size/24
__attribute__((pure, cold))
pfe_bmu_get_buf_size (const struct pfe_bmu_t * bmu)
{
  uint32_t len;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  len_3 = bmu_2(D)->buf_size;
  # DEBUG len => len_3
  # DEBUG BEGIN_STMT
  return len_3;

}



;; Function pfe_bmu_free_buf (pfe_bmu_free_buf, funcdef_no=22, decl_uid=9493, cgraph_uid=23, symbol_order=25) (hot)

Modification phase of node pfe_bmu_free_buf/25
__attribute__((hot))
pfe_bmu_free_buf (const struct pfe_bmu_t * bmu, addr_t buffer)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  pfe_bmu_cfg_free_buf (_1, buffer_4(D));
  return;

}



;; Function pfe_bmu_destroy (pfe_bmu_destroy, funcdef_no=23, decl_uid=9501, cgraph_uid=24, symbol_order=26) (unlikely executed)

Modification phase of node pfe_bmu_destroy/26
__attribute__((cold))
pfe_bmu_destroy (struct pfe_bmu_t * bmu)
{
  unsigned int _1;
  unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (bmu_4(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _1 = bmu_4(D)->bmu_base_va;
  pfe_bmu_cfg_disable (_1);
  # DEBUG BEGIN_STMT
  _2 = bmu_4(D)->bmu_base_va;
  pfe_bmu_cfg_fini (_2);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function pfe_bmu_get_stat_value (pfe_bmu_get_stat_value, funcdef_no=24, decl_uid=9496, cgraph_uid=25, symbol_order=27)

Modification phase of node pfe_bmu_get_stat_value/27
pfe_bmu_get_stat_value (const struct pfe_bmu_t * bmu, uint32_t stat_id)
{
  uint32_t stat_value;
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  stat_value_6 = pfe_bmu_cfg_get_stat_value (_1, stat_id_4(D));
  # DEBUG stat_value => stat_value_6
  # DEBUG BEGIN_STMT
  return stat_value_6;

}



;; Function pfe_bmu_get_special_stats (pfe_bmu_get_special_stats, funcdef_no=25, decl_uid=9499, cgraph_uid=26, symbol_order=28)

Modification phase of node pfe_bmu_get_special_stats/28
pfe_bmu_get_special_stats (const struct pfe_bmu_t * bmu, struct pfe_bmu_stats_special_t * special_stats)
{
  unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = bmu_3(D)->bmu_base_va;
  pfe_bmu_cfg_get_special_stats (_1, special_stats_4(D));
  # DEBUG BEGIN_STMT
  return 0;

}


