
IPA constant propagation start:
Determining dynamic type for call: mirror_5 = pfe_mirror_get_first (2, address.1_1);
  Starting walk at: mirror_5 = pfe_mirror_get_first (2, address.1_1);
  instance pointer: address.1_1  Outer instance pointer: address.1_1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pfe_mirror_put (mirror_5);
  Starting walk at: pfe_mirror_put (mirror_5);
  instance pointer: mirror_5  Outer instance pointer: mirror_5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mirror_5 = pfe_mirror_get_first (2, address.1_1);
Determining dynamic type for call: pfe_mirror_put (mirror_5);
  Starting walk at: pfe_mirror_put (mirror_5);
  instance pointer: mirror_5  Outer instance pointer: mirror_5 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pfe_mirror_put (mirror_5);
  Function call may change dynamic type:mirror_5 = pfe_mirror_get_first (2, address.1_1);
Determining dynamic type for call: _3 = pfe_mirror_get_first (1, name_7(D));
  Starting walk at: _3 = pfe_mirror_get_first (1, name_7(D));
  instance pointer: name_7(D)  Outer instance pointer: name_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:length_9 = autolibc_strnlen (name_7(D), 16);
Determining dynamic type for call: mirror_14 = pfe_mirror_allocate_mem (name_7(D), mirror_12);
  Starting walk at: mirror_14 = pfe_mirror_allocate_mem (name_7(D), mirror_12);
  instance pointer: name_7(D)  Outer instance pointer: name_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mirror_12 = isa_reserve (&pfe_mirror_db.mirrors);
  Function call may change dynamic type:_3 = pfe_mirror_get_first (1, name_7(D));
  Function call may change dynamic type:length_9 = autolibc_strnlen (name_7(D), 16);
Determining dynamic type for call: mirror_14 = pfe_mirror_allocate_mem (name_7(D), mirror_12);
  Starting walk at: mirror_14 = pfe_mirror_allocate_mem (name_7(D), mirror_12);
  instance pointer: mirror_12  Outer instance pointer: mirror_12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mirror_12 = isa_reserve (&pfe_mirror_db.mirrors);
  Function call may change dynamic type:_3 = pfe_mirror_get_first (1, name_7(D));
  Function call may change dynamic type:length_9 = autolibc_strnlen (name_7(D), 16);
Determining dynamic type for call: mirror_10 = pfe_mirror_db_get_by_crit (0, 0B);
  Starting walk at: mirror_10 = pfe_mirror_db_get_by_crit (0, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mirror_13 = pfe_mirror_db_get_by_crit (crit_10(D), arg_11(D));
  Starting walk at: mirror_13 = pfe_mirror_db_get_by_crit (crit_10(D), arg_11(D));
  instance pointer: arg_11(D)  Outer instance pointer: arg_11(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  autolibc_memcpy/43:
  Jump functions of caller  pfe_class_write_dmem/42:
  Jump functions of caller  __builtin_expect/41:
  Jump functions of caller  pfe_class_dmem_heap_free/40:
  Jump functions of caller  autolibc_strncpy/39:
  Jump functions of caller  isa_release/38:
  Jump functions of caller  pfe_class_dmem_heap_alloc/37:
  Jump functions of caller  isa_reserve/36:
  Jump functions of caller  autolibc_strnlen/35:
  Jump functions of caller  autolibc_strcmp/34:
  Jump functions of caller  isa_item/33:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/32:
  Jump functions of caller  pfe_hm_report/31:
  Jump functions of caller  isa_isempty/30:
  Jump functions of caller  isa_init/29:
  Jump functions of caller  autolibc_memset/28:
  Jump functions of caller  pfe_mirror_get_actions/27:
  Jump functions of caller  pfe_mirror_set_actions/26:
  Jump functions of caller  pfe_mirror_get_filter/25:
  Jump functions of caller  pfe_mirror_set_filter/24:
  Jump functions of caller  pfe_mirror_get_egress_port/23:
  Jump functions of caller  pfe_mirror_set_egress_port/22:
  Jump functions of caller  pfe_mirror_get_name/21:
  Jump functions of caller  pfe_mirror_get_address/20:
  Jump functions of caller  pfe_mirror_put_by_address/19:
    callsite  pfe_mirror_put_by_address/19 -> pfe_mirror_put/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_mirror_put_by_address/19 -> pfe_mirror_put/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_mirror_put_by_address/19 -> pfe_mirror_get_first/13 : 
       param 0: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_mirror_put/18:
  Jump functions of caller  pfe_mirror_destroy/17:
  Jump functions of caller  pfe_mirror_create/16:
    callsite  pfe_mirror_create/16 -> pfe_mirror_allocate_mem/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_mirror_create/16 -> pfe_mirror_get_first/13 : 
       param 0: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_mirror_allocate_mem/15:
  Jump functions of caller  pfe_mirror_get_next/14:
    callsite  pfe_mirror_get_next/14 -> pfe_mirror_db_get_by_crit/12 : 
       param 0: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  pfe_mirror_get_first/13:
    callsite  pfe_mirror_get_first/13 -> pfe_mirror_db_get_by_crit/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_mirror_db_get_by_crit/12:
  Jump functions of caller  pfe_mirror_deinit/11:
  Jump functions of caller  pfe_mirror_init/10:

 Propagating constants:

Not considering pfe_mirror_get_actions for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_set_actions for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_get_filter for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_set_filter for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_get_egress_port for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_set_egress_port for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_get_name for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_get_address for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_put_by_address for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_put for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_destroy for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_create for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_get_next for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_get_first for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_deinit for cloning; -fipa-cp-clone disabled.
Not considering pfe_mirror_init for cloning; -fipa-cp-clone disabled.

overall_size: 311, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pfe_mirror_get_actions/27:
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
  Node: pfe_mirror_set_actions/26:
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
  Node: pfe_mirror_get_filter/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_set_filter/24:
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
  Node: pfe_mirror_get_egress_port/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_set_egress_port/22:
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
  Node: pfe_mirror_get_name/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_get_address/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_put_by_address/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_put/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_destroy/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_create/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_mirror_allocate_mem/15:
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
  Node: pfe_mirror_get_next/14:
  Node: pfe_mirror_get_first/13:
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
  Node: pfe_mirror_db_get_by_crit/12:
    param [0]: VARIABLE
               0 [loc_time: 34, loc_size: 32, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0B [loc_time: 1, loc_size: 49, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pfe_mirror_deinit/11:
  Node: pfe_mirror_init/10:
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

autolibc_memcpy/43 (autolibc_memcpy) @073e8380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_get_actions/27 (354334802 (estimated locally),0.33 per call) pfe_mirror_set_actions/26 (354334802 (estimated locally),0.33 per call) 
  Calls: 
pfe_class_write_dmem/42 (pfe_class_write_dmem) @073ceee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_set_actions/26 (1073741824 (estimated locally),1.00 per call) pfe_mirror_set_filter/24 (1073741824 (estimated locally),1.00 per call) pfe_mirror_set_egress_port/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
__builtin_expect/41 (__builtin_expect) @073cea80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_put/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_class_dmem_heap_free/40 (pfe_class_dmem_heap_free) @073ce8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_destroy/17 (292079251 (estimated locally),0.27 per call) 
  Calls: 
autolibc_strncpy/39 (autolibc_strncpy) @073ce700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_allocate_mem/15 (762356696 (estimated locally),0.71 per call) 
  Calls: 
isa_release/38 (isa_release) @073ce620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_destroy/17 (292079251 (estimated locally),0.27 per call) pfe_mirror_allocate_mem/15 (311385129 (estimated locally),0.29 per call) 
  Calls: 
pfe_class_dmem_heap_alloc/37 (pfe_class_dmem_heap_alloc) @073ce540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_allocate_mem/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
isa_reserve/36 (isa_reserve) @073ce380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_create/16 (224695770 (estimated locally),0.21 per call) 
  Calls: 
autolibc_strnlen/35 (autolibc_strnlen) @073ce2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_create/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
autolibc_strcmp/34 (autolibc_strcmp) @073c12a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_db_get_by_crit/12 (240026838 (estimated locally),2.11 per call) 
  Calls: 
isa_item/33 (isa_item) @073c1000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_db_get_by_crit/12 (996582265 (estimated locally),8.77 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/32 (oal_util_raise_dem_for_drv_runtime_err) @073c1d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_create/16 (179851756 (estimated locally),0.17 per call) pfe_mirror_deinit/11 (189462818 (estimated locally),0.18 per call) pfe_mirror_allocate_mem/15 (311385129 (estimated locally),0.29 per call) pfe_mirror_db_get_by_crit/12 (240026838 (estimated locally),2.11 per call) 
  Calls: 
pfe_hm_report/31 (pfe_hm_report) @073c1c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_create/16 (179851756 (estimated locally),0.17 per call) pfe_mirror_deinit/11 (189462818 (estimated locally),0.18 per call) pfe_mirror_allocate_mem/15 (311385129 (estimated locally),0.29 per call) pfe_mirror_db_get_by_crit/12 (240026838 (estimated locally),2.11 per call) 
  Calls: 
isa_isempty/30 (isa_isempty) @073c1b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_deinit/11 (574129754 (estimated locally),0.53 per call) 
  Calls: 
isa_init/29 (isa_init) @073c19a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_init/10 (302365698 (estimated locally),0.28 per call) 
  Calls: 
autolibc_memset/28 (autolibc_memset) @073c18c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pfe_mirror_deinit/11 (574129754 (estimated locally),0.53 per call) pfe_mirror_init/10 (302365698 (estimated locally),0.28 per call) pfe_mirror_allocate_mem/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_mirror_get_actions/27 (pfe_mirror_get_actions) @073c1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memcpy/43 (354334802 (estimated locally),0.33 per call) 
pfe_mirror_set_actions/26 (pfe_mirror_set_actions) @073c11c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_write_dmem/42 (1073741824 (estimated locally),1.00 per call) autolibc_memcpy/43 (354334802 (estimated locally),0.33 per call) 
pfe_mirror_get_filter/25 (pfe_mirror_get_filter) @07327ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_mirror_set_filter/24 (pfe_mirror_set_filter) @073279a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_write_dmem/42 (1073741824 (estimated locally),1.00 per call) 
pfe_mirror_get_egress_port/23 (pfe_mirror_get_egress_port) @07327460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_mirror_set_egress_port/22 (pfe_mirror_set_egress_port) @07327e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_class_write_dmem/42 (1073741824 (estimated locally),1.00 per call) 
pfe_mirror_get_name/21 (pfe_mirror_get_name) @07327b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_mirror_get_address/20 (pfe_mirror_get_address) @073278c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_mirror_put_by_address/19 (pfe_mirror_put_by_address) @07327620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_mirror_put/18 (1073741824 (estimated locally),1.00 per call) pfe_mirror_put/18 (1073741824 (estimated locally),1.00 per call) pfe_mirror_get_first/13 (1073741824 (estimated locally),1.00 per call) 
pfe_mirror_put/18 (pfe_mirror_put) @07327380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_mirror_put_by_address/19 (1073741824 (estimated locally),1.00 per call) pfe_mirror_put_by_address/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: __builtin_expect/41 (1073741824 (estimated locally),1.00 per call) 
pfe_mirror_destroy/17 (pfe_mirror_destroy) @07327000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)pfe_mirror_db/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_release/38 (292079251 (estimated locally),0.27 per call) pfe_class_dmem_heap_free/40 (292079251 (estimated locally),0.27 per call) 
pfe_mirror_create/16 (pfe_mirror_create) @073bea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)pfe_mirror_db/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_mirror_allocate_mem/15 (120144828 (estimated locally),0.11 per call) isa_reserve/36 (224695770 (estimated locally),0.21 per call) pfe_mirror_get_first/13 (659512093 (estimated locally),0.61 per call) oal_util_raise_dem_for_drv_runtime_err/32 (179851756 (estimated locally),0.17 per call) pfe_hm_report/31 (179851756 (estimated locally),0.17 per call) autolibc_strnlen/35 (1073741824 (estimated locally),1.00 per call) 
pfe_mirror_allocate_mem/15 (pfe_mirror_allocate_mem) @073be0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_mirror_db/8 (read)pfe_mirror_db/8 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pfe_mirror_create/16 (120144828 (estimated locally),0.11 per call) 
  Calls: autolibc_strncpy/39 (762356696 (estimated locally),0.71 per call) isa_release/38 (311385129 (estimated locally),0.29 per call) oal_util_raise_dem_for_drv_runtime_err/32 (311385129 (estimated locally),0.29 per call) pfe_hm_report/31 (311385129 (estimated locally),0.29 per call) pfe_class_dmem_heap_alloc/37 (1073741824 (estimated locally),1.00 per call) autolibc_memset/28 (1073741824 (estimated locally),1.00 per call) 
pfe_mirror_get_next/14 (pfe_mirror_get_next) @073bec40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_mirror_db_get_by_crit/12 (792206719 (estimated locally),0.74 per call) 
pfe_mirror_get_first/13 (pfe_mirror_get_first) @073be9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)pfe_mirror_db/8 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_mirror_put_by_address/19 (1073741824 (estimated locally),1.00 per call) pfe_mirror_create/16 (659512093 (estimated locally),0.61 per call) 
  Calls: pfe_mirror_db_get_by_crit/12 (792206719 (estimated locally),0.74 per call) 
pfe_mirror_db_get_by_crit/12 (pfe_mirror_db_get_by_crit) @073be700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_mirror_db/8 (addr)pfe_mirror_db/8 (read)pfe_mirror_db/8 (write)pfe_mirror_db/8 (read)pfe_mirror_db/8 (write)pfe_mirror_db/8 (read)pfe_mirror_db/8 (read)
  Referring: 
  Availability: local
  Function flags: count:113634470 (estimated locally) body local optimize_size
  Called by: pfe_mirror_get_next/14 (792206719 (estimated locally),0.74 per call) pfe_mirror_get_first/13 (792206719 (estimated locally),0.74 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/32 (240026838 (estimated locally),2.11 per call) pfe_hm_report/31 (240026838 (estimated locally),2.11 per call) autolibc_strcmp/34 (240026838 (estimated locally),2.11 per call) isa_item/33 (996582265 (estimated locally),8.77 per call) 
pfe_mirror_deinit/11 (pfe_mirror_deinit) @073be380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)pfe_mirror_db/8 (addr)pfe_mirror_db/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: autolibc_memset/28 (574129754 (estimated locally),0.53 per call) oal_util_raise_dem_for_drv_runtime_err/32 (189462818 (estimated locally),0.18 per call) pfe_hm_report/31 (189462818 (estimated locally),0.18 per call) isa_isempty/30 (574129754 (estimated locally),0.53 per call) 
pfe_mirror_init/10 (pfe_mirror_init) @073be000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: pfe_mirror_db/8 (read)pfe_mirror_db/8 (addr)pfe_mirror_db/8 (write)pfe_mirror_db/8 (addr)pfe_mirror_db_isa_def/9 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: isa_init/29 (302365698 (estimated locally),0.28 per call) autolibc_memset/28 (302365698 (estimated locally),0.28 per call) 
pfe_mirror_db_isa_def/9 (pfe_mirror_db_isa_def) @073b3cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: pfe_mirror_db/8 (addr)pfe_mirror_db/8 (addr)
  Referring: pfe_mirror_init/10 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
pfe_mirror_db/8 (pfe_mirror_db) @073b3c18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_mirror_db_get_by_crit/12 (read)pfe_mirror_init/10 (addr)pfe_mirror_db_get_by_crit/12 (read)pfe_mirror_db_get_by_crit/12 (read)pfe_mirror_db_isa_def/9 (addr)pfe_mirror_db_isa_def/9 (addr)pfe_mirror_db_get_by_crit/12 (write)pfe_mirror_allocate_mem/15 (read)pfe_mirror_allocate_mem/15 (addr)pfe_mirror_init/10 (write)pfe_mirror_init/10 (addr)pfe_mirror_get_first/13 (write)pfe_mirror_create/16 (read)pfe_mirror_set_filter/24 (read)pfe_mirror_get_first/13 (read)pfe_mirror_get_next/14 (read)pfe_mirror_create/16 (addr)pfe_mirror_destroy/17 (addr)pfe_mirror_set_egress_port/22 (read)pfe_mirror_deinit/11 (addr)pfe_mirror_deinit/11 (addr)pfe_mirror_db_get_by_crit/12 (addr)pfe_mirror_db_get_by_crit/12 (read)pfe_mirror_db_get_by_crit/12 (write)pfe_mirror_init/10 (read)pfe_mirror_deinit/11 (read)pfe_mirror_destroy/17 (read)pfe_mirror_set_actions/26 (read)
  Availability: available
  Varpool flags:

;; Function pfe_mirror_db_get_by_crit (pfe_mirror_db_get_by_crit, funcdef_no=8, decl_uid=9438, cgraph_uid=9, symbol_order=12)

Modification phase of node pfe_mirror_db_get_by_crit/12
pfe_mirror_db_get_by_crit (pfe_mirror_db_crit_t crit, const void * arg)
{
  bool_t match;
  struct pfe_mirror_t * mirror;
  long unsigned int _2;
  long unsigned int _3;
  char[16] * _4;
  long int _5;
  unsigned int _6;
  unsigned int arg.0_7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 113634470]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG match => 0
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 3> [local count: 996582265]:
  # DEBUG BEGIN_STMT
  mirror_21 = isa_item (&pfe_mirror_db.mirrors, _9);
  # DEBUG mirror => mirror_21
  # DEBUG BEGIN_STMT
  if (mirror_21 == 0B)
    goto <bb 13>; [3.66%]
  else
    goto <bb 4>; [96.34%]

  <bb 4> [local count: 960107354]:
  # DEBUG BEGIN_STMT
  _2 = pfe_mirror_db.next_item;
  _3 = _2 + 1;
  pfe_mirror_db.next_item = _3;
  # DEBUG BEGIN_STMT
  switch (crit_23(D)) <default: <L9> [25.00%], case 0: <L18> [25.00%], case 1: <L3> [25.00%], case 2: <L6> [25.00%]>

  <bb 5> [local count: 240026838]:
<L3>:
  # DEBUG BEGIN_STMT
  _4 = &mirror_21->name;
  _5 = autolibc_strcmp (_4, arg_24(D));
  if (_5 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 6> [local count: 120013419]:
  # DEBUG BEGIN_STMT
  # DEBUG match => 1
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 240026838]:
<L6>:
  # DEBUG BEGIN_STMT
  _6 = mirror_21->phys_addr;
  arg.0_7 = (unsigned int) arg_24(D);
  if (_6 == arg.0_7)
    goto <bb 8>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 8> [local count: 81609125]:
  # DEBUG BEGIN_STMT
  # DEBUG match => 1
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 240026838]:
<L9>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Wrong criterion %u\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_mirror.c", 192, crit_23(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = pfe_mirror_db.mirrors.occupied_items_count;
  pfe_mirror_db.next_item = _8;
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 960107355]:
  # mirror_17 = PHI <mirror_21(4), mirror_21(6), mirror_21(7), mirror_21(5), mirror_21(9), mirror_21(8)>
  # match_30 = PHI <1(4), 1(6), 0(7), 0(5), 0(9), 1(8)>
<L18>:

  <bb 16> [local count: 1073741824]:
  # mirror_11 = PHI <mirror_17(11), mirror_18(D)(2)>
  # match_14 = PHI <match_30(11), 0(2)>
  # DEBUG match => match_14
  # DEBUG mirror => mirror_11
  # DEBUG BEGIN_STMT
  _9 = pfe_mirror_db.next_item;
  _10 = pfe_mirror_db.mirrors.occupied_items_count;
  if (_9 < _10)
    goto <bb 12>; [96.34%]
  else
    goto <bb 13>; [3.66%]

  <bb 12> [local count: 1034442874]:
  if (match_14 == 0)
    goto <bb 3>; [96.34%]
  else
    goto <bb 13>; [3.66%]

  <bb 13> [local count: 113634471]:
  # mirror_12 = PHI <mirror_21(3), mirror_11(16), mirror_11(12)>
  # match_25 = PHI <0(3), match_14(16), match_14(12)>
  # DEBUG mirror => mirror_12
  # DEBUG BEGIN_STMT
  if (match_25 == 0)
    goto <bb 14>; [29.00%]
  else
    goto <bb 15>; [71.00%]

  <bb 14> [local count: 32953997]:
  # DEBUG BEGIN_STMT
  # DEBUG mirror => 0B

  <bb 15> [local count: 113634471]:
  # mirror_13 = PHI <mirror_12(13), 0B(14)>
  # DEBUG mirror => mirror_13
  # DEBUG BEGIN_STMT
  return mirror_13;

}



;; Function pfe_mirror_init (pfe_mirror_init, funcdef_no=6, decl_uid=8917, cgraph_uid=7, symbol_order=10)

Modification phase of node pfe_mirror_init/10
pfe_mirror_init (struct pfe_class_t * class)
{
  errno_t ret;
  struct pfe_class_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pfe_mirror_db.class;
  if (_1 != 0B)
    goto <bb 4>; [71.84%]
  else
    goto <bb 3>; [28.16%]

  <bb 3> [local count: 302365698]:
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_mirror_db, 0, 800);
  # DEBUG BEGIN_STMT
  pfe_mirror_db.class = class_6(D);
  # DEBUG BEGIN_STMT
  isa_init (&pfe_mirror_db.mirrors, &pfe_mirror_db_isa_def);
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_2 = PHI <115(2), 0(3)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  return ret_2;

}



;; Function pfe_mirror_deinit (pfe_mirror_deinit, funcdef_no=7, decl_uid=8919, cgraph_uid=8, symbol_order=11)

Modification phase of node pfe_mirror_deinit/11
pfe_mirror_deinit ()
{
  struct pfe_class_t * _1;
  unsigned char _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pfe_mirror_db.class;
  if (_1 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  _2 = isa_isempty (&pfe_mirror_db.mirrors);
  if (_2 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 189462818]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] There are still entries in the database\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_mirror.c", 143, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  autolibc_memset (&pfe_mirror_db, 0, 800);

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function pfe_mirror_get_first (pfe_mirror_get_first, funcdef_no=9, decl_uid=8922, cgraph_uid=10, symbol_order=13)

Modification phase of node pfe_mirror_get_first/13
pfe_mirror_get_first (pfe_mirror_db_crit_t crit, const void * arg)
{
  struct pfe_mirror_t * mirror;
  struct pfe_class_t * _1;
  signed char _2;
  unsigned char _3;
  unsigned char _4;
  signed char _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mirror => 0B
  # DEBUG BEGIN_STMT
  _1 = pfe_mirror_db.class;
  if (_1 != 0B)
    goto <bb 3>; [73.78%]
  else
    goto <bb 5>; [26.22%]

  <bb 3> [local count: 792206719]:
  # DEBUG BEGIN_STMT
  pfe_mirror_db.next_item = 0;
  # DEBUG BEGIN_STMT
  mirror_13 = pfe_mirror_db_get_by_crit (crit_10(D), arg_11(D));
  # DEBUG mirror => mirror_13
  # DEBUG BEGIN_STMT
  if (mirror_13 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 554544703]:
  # DEBUG BEGIN_STMT
  _2 = mirror_13->ref_counter;
  _3 = (unsigned char) _2;
  _4 = _3 + 1;
  _5 = (signed char) _4;
  mirror_13->ref_counter = _5;

  <bb 5> [local count: 1073741824]:
  # mirror_6 = PHI <0B(2), mirror_13(3), mirror_13(4)>
  # DEBUG mirror => mirror_6
  # DEBUG BEGIN_STMT
  return mirror_6;

}



;; Function pfe_mirror_get_next (pfe_mirror_get_next, funcdef_no=10, decl_uid=8924, cgraph_uid=11, symbol_order=14)

Modification phase of node pfe_mirror_get_next/14
pfe_mirror_get_next ()
{
  struct pfe_mirror_t * mirror;
  struct pfe_class_t * _1;
  signed char _2;
  unsigned char _3;
  unsigned char _4;
  signed char _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mirror => 0B
  # DEBUG BEGIN_STMT
  _1 = pfe_mirror_db.class;
  if (_1 != 0B)
    goto <bb 3>; [73.78%]
  else
    goto <bb 5>; [26.22%]

  <bb 3> [local count: 792206719]:
  # DEBUG BEGIN_STMT
  mirror_10 = pfe_mirror_db_get_by_crit (0, 0B);
  # DEBUG mirror => mirror_10
  # DEBUG BEGIN_STMT
  if (mirror_10 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 554544703]:
  # DEBUG BEGIN_STMT
  _2 = mirror_10->ref_counter;
  _3 = (unsigned char) _2;
  _4 = _3 + 1;
  _5 = (signed char) _4;
  mirror_10->ref_counter = _5;

  <bb 5> [local count: 1073741824]:
  # mirror_6 = PHI <0B(2), mirror_10(3), mirror_10(4)>
  # DEBUG mirror => mirror_6
  # DEBUG BEGIN_STMT
  return mirror_6;

}



;; Function pfe_mirror_create (pfe_mirror_create, funcdef_no=12, decl_uid=8926, cgraph_uid=13, symbol_order=16)

Modification phase of node pfe_mirror_create/16
pfe_mirror_create (const char * name)
{
  uint32_t length;
  struct pfe_mirror_t * mirror;
  long unsigned int _1;
  struct pfe_class_t * _2;
  struct pfe_mirror_t * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mirror => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  length_9 = autolibc_strnlen (name_7(D), 16);
  # DEBUG length => length_9
  # DEBUG BEGIN_STMT
  _1 = length_9 + 4294967295;
  if (_1 > 14)
    goto <bb 3>; [16.75%]
  else
    goto <bb 4>; [83.25%]

  <bb 3> [local count: 179851756]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] PFE mirror name string is invalid\n", "./tools/tresos_mcore_bsw/plugins/Eth_43_PFE_TS_T40D11M14I0R0/src/pfe_mirror.c", 321, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 893890069]:
  # DEBUG BEGIN_STMT
  _2 = pfe_mirror_db.class;
  if (_2 != 0B)
    goto <bb 5>; [73.78%]
  else
    goto <bb 8>; [26.22%]

  <bb 5> [local count: 659512093]:
  # DEBUG BEGIN_STMT
  _3 = pfe_mirror_get_first (1, name_7(D));
  if (_3 == 0B)
    goto <bb 6>; [34.07%]
  else
    goto <bb 8>; [65.93%]

  <bb 6> [local count: 224695770]:
  # DEBUG BEGIN_STMT
  mirror_12 = isa_reserve (&pfe_mirror_db.mirrors);
  # DEBUG mirror => mirror_12
  # DEBUG BEGIN_STMT
  if (mirror_12 != 0B)
    goto <bb 7>; [53.47%]
  else
    goto <bb 8>; [46.53%]

  <bb 7> [local count: 120144828]:
  # DEBUG BEGIN_STMT
  mirror_14 = pfe_mirror_allocate_mem (name_7(D), mirror_12);
  # DEBUG mirror => mirror_14

  <bb 8> [local count: 1073741824]:
  # mirror_4 = PHI <0B(3), 0B(4), mirror_12(6), 0B(5), mirror_14(7)>
  # DEBUG mirror => mirror_4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return mirror_4;

}



;; Function pfe_mirror_destroy (pfe_mirror_destroy, funcdef_no=13, decl_uid=8928, cgraph_uid=14, symbol_order=17)

Modification phase of node pfe_mirror_destroy/17
pfe_mirror_destroy (struct pfe_mirror_t * mirror)
{
  errno_t ret;
  signed char _1;
  struct pfe_class_t * _2;
  unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  if (mirror_6(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = mirror_6(D)->ref_counter;
  if (_1 <= 1)
    goto <bb 4>; [38.86%]
  else
    goto <bb 5>; [61.14%]

  <bb 4> [local count: 292079251]:
  # DEBUG BEGIN_STMT
  _2 = pfe_mirror_db.class;
  _3 = mirror_6(D)->phys_addr;
  pfe_class_dmem_heap_free (_2, _3);
  # DEBUG BEGIN_STMT
  isa_release (&pfe_mirror_db.mirrors, mirror_6(D));
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 5> [local count: 1073741824]:
  # ret_4 = PHI <0(2), 0(4), 111(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_mirror_put (pfe_mirror_put, funcdef_no=14, decl_uid=8930, cgraph_uid=15, symbol_order=18)

Modification phase of node pfe_mirror_put/18
pfe_mirror_put (struct pfe_mirror_t * mirror)
{
  _Bool _1;
  long int _2;
  long int _3;
  signed char _4;
  unsigned char _5;
  unsigned char _6;
  signed char _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = mirror_9(D) != 0B;
  _2 = (long int) _1;
  _3 = __builtin_expect (_2, 1);
  if (_3 != 0)
    goto <bb 3>; [90.00%]
  else
    goto <bb 4>; [10.00%]

  <bb 3> [local count: 966367642]:
  # DEBUG BEGIN_STMT
  _4 = mirror_9(D)->ref_counter;
  _5 = (unsigned char) _4;
  _6 = _5 + 255;
  _7 = (signed char) _6;
  mirror_9(D)->ref_counter = _7;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function pfe_mirror_put_by_address (pfe_mirror_put_by_address, funcdef_no=15, decl_uid=8932, cgraph_uid=16, symbol_order=19)

Modification phase of node pfe_mirror_put_by_address/19
pfe_mirror_put_by_address (addr_t address)
{
  struct pfe_mirror_t * mirror;
  const void * address.1_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG mirror => 0B
  # DEBUG BEGIN_STMT
  address.1_1 = (const void *) address_2(D);
  mirror_5 = pfe_mirror_get_first (2, address.1_1);
  # DEBUG mirror => mirror_5
  # DEBUG BEGIN_STMT
  pfe_mirror_put (mirror_5);
  # DEBUG BEGIN_STMT
  pfe_mirror_put (mirror_5);
  return;

}



;; Function pfe_mirror_get_address (pfe_mirror_get_address, funcdef_no=16, decl_uid=8934, cgraph_uid=17, symbol_order=20)

Modification phase of node pfe_mirror_get_address/20
pfe_mirror_get_address (const struct pfe_mirror_t * mirror)
{
  uint32_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_3 = mirror_2(D)->phys_addr;
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_mirror_get_name (pfe_mirror_get_name, funcdef_no=17, decl_uid=8936, cgraph_uid=18, symbol_order=21)

Modification phase of node pfe_mirror_get_name/21
pfe_mirror_get_name (const struct pfe_mirror_t * mirror)
{
  const char * str;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  str_2 = &mirror_1(D)->name;
  # DEBUG str => str_2
  # DEBUG BEGIN_STMT
  return str_2;

}



;; Function pfe_mirror_set_egress_port (pfe_mirror_set_egress_port, funcdef_no=18, decl_uid=8939, cgraph_uid=19, symbol_order=22)

Modification phase of node pfe_mirror_set_egress_port/22
pfe_mirror_set_egress_port (struct pfe_mirror_t * mirror, pfe_ct_phy_if_id_t egress)
{
  errno_t ret;
  struct pfe_class_t * _1;
  unsigned int _2;
  struct pfe_ct_mirror_t * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mirror_5(D)->phys.e_phy_if = egress_6(D);
  # DEBUG BEGIN_STMT
  _1 = pfe_mirror_db.class;
  _2 = mirror_5(D)->phys_addr;
  _3 = &mirror_5(D)->phys;
  ret_9 = pfe_class_write_dmem (_1, -1, _2, _3, 72);
  # DEBUG ret => ret_9
  # DEBUG BEGIN_STMT
  return ret_9;

}



;; Function pfe_mirror_get_egress_port (pfe_mirror_get_egress_port, funcdef_no=19, decl_uid=8941, cgraph_uid=20, symbol_order=23)

Modification phase of node pfe_mirror_get_egress_port/23
pfe_mirror_get_egress_port (const struct pfe_mirror_t * mirror)
{
  pfe_ct_phy_if_id_t ret;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_3 = mirror_2(D)->phys.e_phy_if;
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  return ret_3;

}



;; Function pfe_mirror_set_filter (pfe_mirror_set_filter, funcdef_no=20, decl_uid=8944, cgraph_uid=21, symbol_order=24)

Modification phase of node pfe_mirror_set_filter/24
pfe_mirror_set_filter (struct pfe_mirror_t * mirror, uint32_t filter_address)
{
  errno_t ret;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  struct pfe_class_t * _10;
  unsigned int _11;
  struct pfe_ct_mirror_t * _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = filter_address_13(D) >> 24;
  _2 = filter_address_13(D) >> 8;
  _3 = _2 & 65280;
  _4 = _1 | _3;
  _5 = filter_address_13(D) << 8;
  _6 = _5 & 16711680;
  _7 = _4 | _6;
  _8 = filter_address_13(D) << 24;
  _9 = _7 | _8;
  mirror_15(D)->phys.flexible_filter = _9;
  # DEBUG BEGIN_STMT
  _10 = pfe_mirror_db.class;
  _11 = mirror_15(D)->phys_addr;
  _12 = &mirror_15(D)->phys;
  ret_18 = pfe_class_write_dmem (_10, -1, _11, _12, 72);
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  return ret_18;

}



;; Function pfe_mirror_get_filter (pfe_mirror_get_filter, funcdef_no=21, decl_uid=8946, cgraph_uid=22, symbol_order=25)

Modification phase of node pfe_mirror_get_filter/25
pfe_mirror_get_filter (const struct pfe_mirror_t * mirror)
{
  uint32_t ret;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = mirror_11(D)->phys.flexible_filter;
  _2 = _1 >> 24;
  _3 = _1 >> 8;
  _4 = _3 & 65280;
  _5 = _2 | _4;
  _6 = _1 << 8;
  _7 = _6 & 16711680;
  _8 = _5 | _7;
  _9 = _1 << 24;
  ret_12 = _8 | _9;
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  return ret_12;

}



;; Function pfe_mirror_set_actions (pfe_mirror_set_actions, funcdef_no=22, decl_uid=8950, cgraph_uid=23, symbol_order=26)

Modification phase of node pfe_mirror_set_actions/26
pfe_mirror_set_actions (struct pfe_mirror_t * mirror, pfe_ct_route_actions_t actions, const struct pfe_ct_route_actions_args_t * args)
{
  errno_t ret;
  struct pfe_ct_route_actions_args_t * _1;
  struct pfe_class_t * _2;
  unsigned int _3;
  struct pfe_ct_mirror_t * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mirror_7(D)->phys.actions = actions_8(D);
  # DEBUG BEGIN_STMT
  if (actions_8(D) != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _1 = &mirror_7(D)->phys.args;
  autolibc_memcpy (_1, args_10(D), 60);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = pfe_mirror_db.class;
  _3 = mirror_7(D)->phys_addr;
  _4 = &mirror_7(D)->phys;
  ret_13 = pfe_class_write_dmem (_2, -1, _3, _4, 72);
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  return ret_13;

}



;; Function pfe_mirror_get_actions (pfe_mirror_get_actions, funcdef_no=23, decl_uid=8954, cgraph_uid=24, symbol_order=27)

Modification phase of node pfe_mirror_get_actions/27
pfe_mirror_get_actions (const struct pfe_mirror_t * mirror, pfe_ct_route_actions_t * actions, struct pfe_ct_route_actions_args_t * args)
{
  long unsigned int _1;
  const struct pfe_ct_route_actions_args_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = mirror_5(D)->phys.actions;
  *actions_6(D) = _1;
  # DEBUG BEGIN_STMT
  if (_1 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _2 = &mirror_5(D)->phys.args;
  autolibc_memcpy (args_8(D), _2, 60);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}


