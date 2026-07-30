
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  autolibc_memcpy/18:
  Jump functions of caller  pfe_class_read_dmem/17:
  Jump functions of caller  pfe_class_dmem_heap_free/16:
  Jump functions of caller  pfe_class_write_dmem/15:
  Jump functions of caller  autolibc_memset/14:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/13:
  Jump functions of caller  pfe_hm_report/12:
  Jump functions of caller  pfe_class_dmem_heap_alloc/11:
  Jump functions of caller  pfe_fp_table_get_statistics/10:
  Jump functions of caller  pfe_fp_destroy_table/9:
  Jump functions of caller  pfe_fp_table_write_rule/8:
  Jump functions of caller  pfe_fp_create_table/7:
  Jump functions of caller  pfe_fp_init/6:

 Propagating constants:

Not considering pfe_fp_table_get_statistics for cloning; -fipa-cp-clone disabled.
Not considering pfe_fp_destroy_table for cloning; -fipa-cp-clone disabled.
Not considering pfe_fp_table_write_rule for cloning; -fipa-cp-clone disabled.
Not considering pfe_fp_create_table for cloning; -fipa-cp-clone disabled.
Not considering pfe_fp_init for cloning; -fipa-cp-clone disabled.

overall_size: 130, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_fp_table_get_statistics/10:
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
  Node: pfe_fp_destroy_table/9:
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
  Node: pfe_fp_table_write_rule/8:
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
  Node: pfe_fp_create_table/7:
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
  Node: pfe_fp_init/6:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

autolibc_memcpy/18 (autolibc_memcpy) @072c8c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_table_get_statistics/10 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_class_read_dmem/17 (pfe_class_read_dmem) @072c8b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_table_get_statistics/10 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_dmem_heap_free/16 (pfe_class_dmem_heap_free) @072c87e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_destroy_table/9 (1073741824 (estimated locally),1.00 per call) pfe_fp_create_table/7 (177167401 (estimated locally),0.17 per call) 
  Calls: 
pfe_class_write_dmem/15 (pfe_class_write_dmem) @072c8700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_table_write_rule/8 (1073741824 (estimated locally),1.00 per call) pfe_fp_create_table/7 (536870913 (estimated locally),0.50 per call) 
  Calls: 
autolibc_memset/14 (autolibc_memset) @072c8620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_table_get_statistics/10 (1073741824 (estimated locally),1.00 per call) pfe_fp_create_table/7 (536870913 (estimated locally),0.50 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/13 (oal_util_raise_dem_for_drv_runtime_err) @072c8540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_table_get_statistics/10 (536870913 (estimated locally),0.50 per call) pfe_fp_table_write_rule/8 (354334802 (estimated locally),0.33 per call) pfe_fp_create_table/7 (177167401 (estimated locally),0.17 per call) pfe_fp_create_table/7 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_hm_report/12 (pfe_hm_report) @072c8460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_table_get_statistics/10 (536870913 (estimated locally),0.50 per call) pfe_fp_table_write_rule/8 (354334802 (estimated locally),0.33 per call) pfe_fp_create_table/7 (177167401 (estimated locally),0.17 per call) pfe_fp_create_table/7 (536870913 (estimated locally),0.50 per call) 
  Calls: 
pfe_class_dmem_heap_alloc/11 (pfe_class_dmem_heap_alloc) @072c8380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_fp_create_table/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_fp_table_get_statistics/10 (pfe_fp_table_get_statistics) @072abc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/18 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/13 (536870913 (estimated locally),0.50 per call) pfe_hm_report/12 (536870913 (estimated locally),0.50 per call) pfe_class_read_dmem/17 (1073741824 (estimated locally),1.00 per call) autolibc_memset/14 (1073741824 (estimated locally),1.00 per call) 
pfe_fp_destroy_table/9 (pfe_fp_destroy_table) @072abe00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_dmem_heap_free/16 (1073741824 (estimated locally),1.00 per call) 
pfe_fp_table_write_rule/8 (pfe_fp_table_write_rule) @072abb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/13 (354334802 (estimated locally),0.33 per call) pfe_hm_report/12 (354334802 (estimated locally),0.33 per call) pfe_class_write_dmem/15 (1073741824 (estimated locally),1.00 per call) 
pfe_fp_create_table/7 (pfe_fp_create_table) @072ab7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_dmem_heap_free/16 (177167401 (estimated locally),0.17 per call) oal_util_raise_dem_for_drv_runtime_err/13 (177167401 (estimated locally),0.17 per call) pfe_hm_report/12 (177167401 (estimated locally),0.17 per call) pfe_class_write_dmem/15 (536870913 (estimated locally),0.50 per call) autolibc_memset/14 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/13 (536870913 (estimated locally),0.50 per call) pfe_hm_report/12 (536870913 (estimated locally),0.50 per call) pfe_class_dmem_heap_alloc/11 (1073741824 (estimated locally),1.00 per call) 
pfe_fp_init/6 (pfe_fp_init) @072ab380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function pfe_fp_init (pfe_fp_init, funcdef_no=4, decl_uid=7960, cgraph_uid=5, symbol_order=6)

Modification phase of node pfe_fp_init/6
pfe_fp_init ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_fp_create_table (pfe_fp_create_table, funcdef_no=5, decl_uid=7963, cgraph_uid=6, symbol_order=7)

Modification phase of node pfe_fp_create_table/7
pfe_fp_create_table (struct pfe_class_t * class, uint16_t rules_count)
{
  errno_t res;
  struct pfe_ct_fp_table_t temp;
  uint32_t size;
  addr_t addr;
  long unsigned int _1;
  long unsigned int _2;
  unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) rules_count_15(D);
  _2 = _1 * 12;
  size_16 = _2 + 16;
  # DEBUG size => size_16
  # DEBUG BEGIN_STMT
  addr_20 = pfe_class_dmem_heap_alloc (class_18(D), size_16);
  # DEBUG addr => addr_20
  # DEBUG BEGIN_STMT
  if (addr_20 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Not enough DMEM memory\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_fp.c", 77, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  temp.count = rules_count_15(D);
  # DEBUG BEGIN_STMT
  temp.reserved16 = 0;
  # DEBUG BEGIN_STMT
  _3 = addr_20 + 16;
  _4 = _3 >> 24;
  _5 = _3 >> 8;
  _6 = _5 & 65280;
  _7 = _4 | _6;
  _8 = _3 << 8;
  _9 = _8 & 16711680;
  _10 = _7 | _9;
  _11 = _3 << 24;
  _12 = _10 | _11;
  temp.rules = _12;
  # DEBUG BEGIN_STMT
  autolibc_memset (&temp.fp_stats, 0, 8);
  # DEBUG BEGIN_STMT
  res_26 = pfe_class_write_dmem (class_18(D), -1, addr_20, &temp, 16);
  # DEBUG res => res_26
  # DEBUG BEGIN_STMT
  if (res_26 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Cannot write to DMEM\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_fp.c", 89, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_class_dmem_heap_free (class_18(D), addr_20);
  # DEBUG BEGIN_STMT
  # DEBUG addr => 0

  <bb 6> [local count: 1073741824]:
  # addr_13 = PHI <0(3), addr_20(4), 0(5)>
  # DEBUG addr => addr_13
  # DEBUG BEGIN_STMT
  temp ={v} {CLOBBER};
  return addr_13;

}



;; Function pfe_fp_table_write_rule (pfe_fp_table_write_rule, funcdef_no=6, decl_uid=7968, cgraph_uid=7, symbol_order=8)

Modification phase of node pfe_fp_table_write_rule/8
pfe_fp_table_write_rule (struct pfe_class_t * class, uint32_t table_address, const struct pfe_ct_fp_rule_t * rule, uint16_t position)
{
  errno_t res;
  addr_t addr;
  struct pfe_ct_fp_rule_t temp;
  long unsigned int _1;
  long unsigned int _2;
  short unsigned int _3;
  unsigned char _4;
  unsigned char _5;
  unsigned int _6;
  unsigned int _7;
  unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = rule_12(D)->data;
  temp.data = _1;
  # DEBUG BEGIN_STMT
  _2 = rule_12(D)->mask;
  temp.mask = _2;
  # DEBUG BEGIN_STMT
  _3 = rule_12(D)->offset;
  temp.offset = _3;
  # DEBUG BEGIN_STMT
  _4 = rule_12(D)->next_idx;
  temp.next_idx = _4;
  # DEBUG BEGIN_STMT
  _5 = rule_12(D)->flags;
  temp.flags = _5;
  # DEBUG BEGIN_STMT
  _6 = (unsigned int) position_18(D);
  _7 = _6 * 12;
  _8 = _7 + table_address_19(D);
  addr_20 = _8 + 16;
  # DEBUG addr => addr_20
  # DEBUG BEGIN_STMT
  res_23 = pfe_class_write_dmem (class_21(D), -1, addr_20, &temp, 12);
  # DEBUG res => res_23
  # DEBUG BEGIN_STMT
  if (res_23 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Cannot write to DMEM\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_fp.c", 127, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG addr => 0

  <bb 4> [local count: 1073741824]:
  # addr_9 = PHI <addr_20(2), 0(3)>
  # DEBUG addr => addr_9
  # DEBUG BEGIN_STMT
  temp ={v} {CLOBBER};
  return addr_9;

}



;; Function pfe_fp_destroy_table (pfe_fp_destroy_table, funcdef_no=7, decl_uid=7971, cgraph_uid=8, symbol_order=9)

Modification phase of node pfe_fp_destroy_table/9
pfe_fp_destroy_table (const struct pfe_class_t * class, uint32_t table_address)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pfe_class_dmem_heap_free (class_2(D), table_address_3(D));
  return;

}



;; Function pfe_fp_table_get_statistics (pfe_fp_table_get_statistics, funcdef_no=8, decl_uid=7976, cgraph_uid=9, symbol_order=10)

Modification phase of node pfe_fp_table_get_statistics/10
pfe_fp_table_get_statistics (struct pfe_class_t * class, uint32_t pe_idx, uint32_t table_address, struct pfe_ct_class_flexi_parser_stats_t * stats)
{
  errno_t res;
  struct pfe_ct_fp_table_t temp;
  signed int pe_idx.0_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&temp.fp_stats, 0, 8);
  # DEBUG BEGIN_STMT
  # DEBUG addr => table_address_5(D)
  # DEBUG BEGIN_STMT
  pe_idx.0_1 = (signed int) pe_idx_6(D);
  # DEBUG BEGIN_STMT
  res_9 = pfe_class_read_dmem (class_7(D), pe_idx.0_1, &temp, table_address_5(D), 16);
  # DEBUG res => res_9
  # DEBUG BEGIN_STMT
  if (res_9 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Cannot read from DMEM\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_fp.c", 159, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  autolibc_memcpy (stats_10(D), &temp.fp_stats, 8);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  temp ={v} {CLOBBER};
  return res_9;

}


