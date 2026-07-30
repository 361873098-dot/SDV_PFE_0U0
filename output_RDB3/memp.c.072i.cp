
IPA constant propagation start:
Determining dynamic type for call: do_memp_free_pool (_1, mem_4(D));
  Starting walk at: do_memp_free_pool (_1, mem_4(D));
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool (_1, mem_4(D));
  Starting walk at: do_memp_free_pool (_1, mem_4(D));
  instance pointer: mem_4(D)  Outer instance pointer: mem_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool (desc_3(D), mem_5(D));
  Starting walk at: do_memp_free_pool (desc_3(D), mem_5(D));
  instance pointer: desc_3(D)  Outer instance pointer: desc_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool (desc_3(D), mem_5(D));
  Starting walk at: do_memp_free_pool (desc_3(D), mem_5(D));
  instance pointer: mem_5(D)  Outer instance pointer: mem_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  Starting walk at: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  instance pointer: desc_7(D)  Outer instance pointer: desc_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  Starting walk at: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  instance pointer: mem_5(D)  Outer instance pointer: mem_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: memp_7 = do_memp_malloc_pool (_1);
  Starting walk at: memp_7 = do_memp_malloc_pool (_1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = do_memp_malloc_pool (desc_2(D));
  Starting walk at: _5 = do_memp_malloc_pool (desc_2(D));
  instance pointer: desc_2(D)  Outer instance pointer: desc_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = do_memp_malloc_pool.part.0 (desc_16(D));
  Starting walk at: _2 = do_memp_malloc_pool.part.0 (desc_16(D));
  instance pointer: desc_16(D)  Outer instance pointer: desc_16(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: memp_init_pool (_2);
  Starting walk at: memp_init_pool (_2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memp_init_pool (_2);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  do_memp_free_pool.part.0/56:
  Jump functions of caller  do_memp_malloc_pool.part.0/55:
  Jump functions of caller  memp_free/53:
    callsite  memp_free/53 -> do_memp_free_pool/51 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_free_pool/52:
    callsite  memp_free_pool/52 -> do_memp_free_pool/51 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  do_memp_free_pool/51:
    callsite  do_memp_free_pool/51 -> do_memp_free_pool.part.0/56 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_malloc/50:
    callsite  memp_malloc/50 -> do_memp_malloc_pool/48 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_malloc_pool/49:
    callsite  memp_malloc_pool/49 -> do_memp_malloc_pool/48 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  do_memp_malloc_pool/48:
    callsite  do_memp_malloc_pool/48 -> do_memp_malloc_pool.part.0/55 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_init/47:
    callsite  memp_init/47 -> memp_init_pool/46 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_init_pool/46:

 Propagating constants:

Not considering memp_free for cloning; -fipa-cp-clone disabled.
Not considering memp_free_pool for cloning; -fipa-cp-clone disabled.
Not considering memp_malloc for cloning; -fipa-cp-clone disabled.
Not considering memp_malloc_pool for cloning; -fipa-cp-clone disabled.
Not considering memp_init for cloning; -fipa-cp-clone disabled.
Not considering memp_init_pool for cloning; -fipa-cp-clone disabled.

overall_size: 126, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: do_memp_free_pool.part.0/56:
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
  Node: do_memp_malloc_pool.part.0/55:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: memp_free/53:
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
  Node: memp_free_pool/52:
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
  Node: do_memp_free_pool/51:
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
  Node: memp_malloc/50:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: memp_malloc_pool/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: do_memp_malloc_pool/48:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: memp_init/47:
  Node: memp_init_pool/46:
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

do_memp_free_pool.part.0/56 (do_memp_free_pool.part.0) @072698c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: do_memp_free_pool/51 (107374 (estimated locally),0.50 per call) 
  Calls: 
do_memp_malloc_pool.part.0/55 (do_memp_malloc_pool.part.0) @06f47620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: do_memp_malloc_pool/48 (28485 (estimated locally),0.15 per call) 
  Calls: 
lwip_stats/54 (lwip_stats) @07236000
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: memp_init/47 (write)
  Availability: not_available
  Varpool flags:
memp_free/53 (memp_free) @07231460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: memp_pools/45 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_free_pool/51 (489336361 (estimated locally),0.46 per call) 
memp_free_pool/52 (memp_free_pool) @072311c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_free_pool/51 (172997 (estimated locally),0.48 per call) 
do_memp_free_pool/51 (do_memp_free_pool) @07226e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: memp_free/53 (489336361 (estimated locally),0.46 per call) memp_free_pool/52 (172997 (estimated locally),0.48 per call) 
  Calls: do_memp_free_pool.part.0/56 (107374 (estimated locally),0.50 per call) 
memp_malloc/50 (memp_malloc) @072262a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: memp_pools/45 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_malloc_pool/48 (752370897 (estimated locally),0.70 per call) 
memp_malloc_pool/49 (memp_malloc_pool) @07226d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_malloc_pool/48 (123389 (estimated locally),0.53 per call) 
do_memp_malloc_pool/48 (do_memp_malloc_pool) @07226a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:191173 (estimated locally) body local optimize_size
  Called by: memp_malloc/50 (752370897 (estimated locally),0.70 per call) memp_malloc_pool/49 (123389 (estimated locally),0.53 per call) 
  Calls: do_memp_malloc_pool.part.0/55 (28485 (estimated locally),0.15 per call) 
memp_init/47 (memp_init) @072267e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: memp_pools/45 (read)lwip_stats/54 (write)
  Referring: 
  Availability: available
  Function flags: count:89442694 (estimated locally) body optimize_size
  Called by: 
  Calls: memp_init_pool/46 (984299131 (estimated locally),11.00 per call) 
memp_init_pool/46 (memp_init_pool) @07226460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: memp_init/47 (984299131 (estimated locally),11.00 per call) 
  Calls: 
memp_pools/45 (memp_pools) @072223f0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_UDP_PCB/4 (addr)memp_TCP_PCB/8 (addr)memp_TCP_PCB_LISTEN/12 (addr)memp_TCP_SEG/16 (addr)memp_ALTCP_PCB/20 (addr)memp_REASSDATA/24 (addr)memp_FRAG_PBUF/28 (addr)memp_IGMP_GROUP/32 (addr)memp_SYS_TIMEOUT/36 (addr)memp_PBUF/40 (addr)memp_PBUF_POOL/44 (addr)
  Referring: memp_malloc/50 (read)memp_init/47 (read)memp_free/53 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_PBUF_POOL/44 (memp_PBUF_POOL) @07222360
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_PBUF_POOL/42 (addr)memp_memory_PBUF_POOL_base/41 (addr)memp_tab_PBUF_POOL/43 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_PBUF_POOL/43 (memp_tab_PBUF_POOL) @07222288
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF_POOL/44 (addr)
  Availability: available
  Varpool flags:
memp_stats_PBUF_POOL/42 (memp_stats_PBUF_POOL) @072221f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF_POOL/44 (addr)
  Availability: available
  Varpool flags:
memp_memory_PBUF_POOL_base/41 (memp_memory_PBUF_POOL_base) @07222168
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_PBUF_POOL/44 (addr)
  Availability: available
  Varpool flags:
memp_PBUF/40 (memp_PBUF) @07222090
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_PBUF/38 (addr)memp_memory_PBUF_base/37 (addr)memp_tab_PBUF/39 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_PBUF/39 (memp_tab_PBUF) @07215f78
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF/40 (addr)
  Availability: available
  Varpool flags:
memp_stats_PBUF/38 (memp_stats_PBUF) @07215ee8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF/40 (addr)
  Availability: available
  Varpool flags:
memp_memory_PBUF_base/37 (memp_memory_PBUF_base) @07215e58
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_PBUF/40 (addr)
  Availability: available
  Varpool flags:
memp_SYS_TIMEOUT/36 (memp_SYS_TIMEOUT) @07215d80
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_SYS_TIMEOUT/34 (addr)memp_memory_SYS_TIMEOUT_base/33 (addr)memp_tab_SYS_TIMEOUT/35 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_SYS_TIMEOUT/35 (memp_tab_SYS_TIMEOUT) @07215ca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_SYS_TIMEOUT/36 (addr)
  Availability: available
  Varpool flags:
memp_stats_SYS_TIMEOUT/34 (memp_stats_SYS_TIMEOUT) @07215c18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_SYS_TIMEOUT/36 (addr)
  Availability: available
  Varpool flags:
memp_memory_SYS_TIMEOUT_base/33 (memp_memory_SYS_TIMEOUT_base) @07215b88
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_SYS_TIMEOUT/36 (addr)
  Availability: available
  Varpool flags:
memp_IGMP_GROUP/32 (memp_IGMP_GROUP) @07215ab0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_IGMP_GROUP/30 (addr)memp_memory_IGMP_GROUP_base/29 (addr)memp_tab_IGMP_GROUP/31 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_IGMP_GROUP/31 (memp_tab_IGMP_GROUP) @072159d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_IGMP_GROUP/32 (addr)
  Availability: available
  Varpool flags:
memp_stats_IGMP_GROUP/30 (memp_stats_IGMP_GROUP) @07215948
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_IGMP_GROUP/32 (addr)
  Availability: available
  Varpool flags:
memp_memory_IGMP_GROUP_base/29 (memp_memory_IGMP_GROUP_base) @072158b8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_IGMP_GROUP/32 (addr)
  Availability: available
  Varpool flags:
memp_FRAG_PBUF/28 (memp_FRAG_PBUF) @072157e0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_FRAG_PBUF/26 (addr)memp_memory_FRAG_PBUF_base/25 (addr)memp_tab_FRAG_PBUF/27 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_FRAG_PBUF/27 (memp_tab_FRAG_PBUF) @07215708
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_FRAG_PBUF/28 (addr)
  Availability: available
  Varpool flags:
memp_stats_FRAG_PBUF/26 (memp_stats_FRAG_PBUF) @07215678
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_FRAG_PBUF/28 (addr)
  Availability: available
  Varpool flags:
memp_memory_FRAG_PBUF_base/25 (memp_memory_FRAG_PBUF_base) @072155e8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_FRAG_PBUF/28 (addr)
  Availability: available
  Varpool flags:
memp_REASSDATA/24 (memp_REASSDATA) @07215510
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_REASSDATA/22 (addr)memp_memory_REASSDATA_base/21 (addr)memp_tab_REASSDATA/23 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_REASSDATA/23 (memp_tab_REASSDATA) @07215438
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_REASSDATA/24 (addr)
  Availability: available
  Varpool flags:
memp_stats_REASSDATA/22 (memp_stats_REASSDATA) @072153a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_REASSDATA/24 (addr)
  Availability: available
  Varpool flags:
memp_memory_REASSDATA_base/21 (memp_memory_REASSDATA_base) @07215318
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_REASSDATA/24 (addr)
  Availability: available
  Varpool flags:
memp_ALTCP_PCB/20 (memp_ALTCP_PCB) @07215240
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_ALTCP_PCB/18 (addr)memp_memory_ALTCP_PCB_base/17 (addr)memp_tab_ALTCP_PCB/19 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_ALTCP_PCB/19 (memp_tab_ALTCP_PCB) @07215168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_ALTCP_PCB/20 (addr)
  Availability: available
  Varpool flags:
memp_stats_ALTCP_PCB/18 (memp_stats_ALTCP_PCB) @072150d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_ALTCP_PCB/20 (addr)
  Availability: available
  Varpool flags:
memp_memory_ALTCP_PCB_base/17 (memp_memory_ALTCP_PCB_base) @07215048
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_ALTCP_PCB/20 (addr)
  Availability: available
  Varpool flags:
memp_TCP_SEG/16 (memp_TCP_SEG) @071faf30
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_TCP_SEG/14 (addr)memp_memory_TCP_SEG_base/13 (addr)memp_tab_TCP_SEG/15 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_TCP_SEG/15 (memp_tab_TCP_SEG) @071fae58
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_SEG/16 (addr)
  Availability: available
  Varpool flags:
memp_stats_TCP_SEG/14 (memp_stats_TCP_SEG) @071fadc8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_SEG/16 (addr)
  Availability: available
  Varpool flags:
memp_memory_TCP_SEG_base/13 (memp_memory_TCP_SEG_base) @071fad38
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_TCP_SEG/16 (addr)
  Availability: available
  Varpool flags:
memp_TCP_PCB_LISTEN/12 (memp_TCP_PCB_LISTEN) @071fac60
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_TCP_PCB_LISTEN/10 (addr)memp_memory_TCP_PCB_LISTEN_base/9 (addr)memp_tab_TCP_PCB_LISTEN/11 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_TCP_PCB_LISTEN/11 (memp_tab_TCP_PCB_LISTEN) @071fab88
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB_LISTEN/12 (addr)
  Availability: available
  Varpool flags:
memp_stats_TCP_PCB_LISTEN/10 (memp_stats_TCP_PCB_LISTEN) @071faaf8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB_LISTEN/12 (addr)
  Availability: available
  Varpool flags:
memp_memory_TCP_PCB_LISTEN_base/9 (memp_memory_TCP_PCB_LISTEN_base) @071faa68
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_TCP_PCB_LISTEN/12 (addr)
  Availability: available
  Varpool flags:
memp_TCP_PCB/8 (memp_TCP_PCB) @071fa990
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_TCP_PCB/6 (addr)memp_memory_TCP_PCB_base/5 (addr)memp_tab_TCP_PCB/7 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_TCP_PCB/7 (memp_tab_TCP_PCB) @071fa8b8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB/8 (addr)
  Availability: available
  Varpool flags:
memp_stats_TCP_PCB/6 (memp_stats_TCP_PCB) @071fa828
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB/8 (addr)
  Availability: available
  Varpool flags:
memp_memory_TCP_PCB_base/5 (memp_memory_TCP_PCB_base) @071fa798
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_TCP_PCB/8 (addr)
  Availability: available
  Varpool flags:
memp_UDP_PCB/4 (memp_UDP_PCB) @071fa6c0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_UDP_PCB/2 (addr)memp_memory_UDP_PCB_base/1 (addr)memp_tab_UDP_PCB/3 (addr)
  Referring: memp_pools/45 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_UDP_PCB/3 (memp_tab_UDP_PCB) @071fa5e8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_UDP_PCB/4 (addr)
  Availability: available
  Varpool flags:
memp_stats_UDP_PCB/2 (memp_stats_UDP_PCB) @071fa558
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_UDP_PCB/4 (addr)
  Availability: available
  Varpool flags:
memp_memory_UDP_PCB_base/1 (memp_memory_UDP_PCB_base) @071fa4c8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_UDP_PCB/4 (addr)
  Availability: available
  Varpool flags:

;; Function do_memp_malloc_pool (do_memp_malloc_pool, funcdef_no=3, decl_uid=7851, cgraph_uid=4, symbol_order=48)

Modification phase of node do_memp_malloc_pool/48
do_memp_malloc_pool (const struct memp_desc * desc)
{
  struct memp * memp;
  struct memp * * _1;
  void * _2;
  struct memp * _3;
  unsigned int memp.1_4;
  unsigned int _5;
  struct stats_mem * _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _11;
  void * _12;

  <bb 2> [local count: 191173]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = desc_16(D)->tab;
  memp_17 = *_1;
  # DEBUG memp => memp_17
  # DEBUG BEGIN_STMT
  if (memp_17 != 0B)
    goto <bb 3>; [85.10%]
  else
    goto <bb 8>; [14.90%]

  <bb 3> [local count: 162688]:
  # DEBUG BEGIN_STMT
  _3 = memp_17->next;
  *_1 = _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memp.1_4 = (unsigned int) memp_17;
  _5 = memp.1_4 & 3;
  if (_5 != 0)
    goto <bb 10>; [66.00%]
  else
    goto <bb 5>; [34.00%]

  <bb 10> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 55314]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = desc_16(D)->stats;
  _7 = _6->used;
  _8 = _7 + 1;
  _6->used = _8;
  # DEBUG BEGIN_STMT
  _11 = _6->max;
  if (_8 > _11)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 27657]:
  # DEBUG BEGIN_STMT
  _6->max = _8;

  <bb 7> [local count: 55314]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 28485]:
  _2 = do_memp_malloc_pool.part.0 (desc_16(D));

  <bb 9> [local count: 83799]:
  # _12 = PHI <memp_17(7), _2(8)>
  return _12;

}



;; Function do_memp_free_pool (do_memp_free_pool, funcdef_no=6, decl_uid=7865, cgraph_uid=7, symbol_order=51)

Modification phase of node do_memp_free_pool/51
do_memp_free_pool (const struct memp_desc * desc, void * mem)
{
  unsigned int mem.2_1;
  unsigned int _2;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem.2_1 = (unsigned int) mem_5(D);
  _2 = mem.2_1 & 3;
  if (_2 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  return;

}



;; Function memp_init_pool (memp_init_pool, funcdef_no=1, decl_uid=6416, cgraph_uid=2, symbol_order=46)

Modification phase of node memp_init_pool/46
memp_init_pool (const struct memp_desc * desc)
{
  struct memp * memp;
  int i;
  struct memp * * _1;
  u8_t * _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;
  struct memp * _6;
  short unsigned int _7;
  sizetype _8;
  short unsigned int _9;
  int _10;
  struct stats_mem * _11;
  short unsigned int _12;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = desc_17(D)->tab;
  *_1 = 0B;
  # DEBUG BEGIN_STMT
  _2 = desc_17(D)->base;
  _3 = (unsigned int) _2;
  _4 = _3 + 3;
  _5 = _4 & 4294967292;
  memp_19 = (struct memp *) _5;
  # DEBUG memp => memp_19
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _6 = *_1;
  memp_14->next = _6;
  # DEBUG BEGIN_STMT
  *_1 = memp_14;
  # DEBUG BEGIN_STMT
  _7 = desc_17(D)->size;
  _8 = (sizetype) _7;
  memp_23 = memp_14 + _8;
  # DEBUG memp => memp_23
  # DEBUG BEGIN_STMT
  i_24 = i_13 + 1;
  # DEBUG i => i_24

  <bb 4> [local count: 1073741824]:
  # i_13 = PHI <0(2), i_24(3)>
  # memp_14 = PHI <memp_19(2), memp_23(3)>
  # DEBUG memp => memp_14
  # DEBUG i => i_13
  # DEBUG BEGIN_STMT
  _9 = desc_17(D)->num;
  _10 = (int) _9;
  if (_10 > i_13)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # _12 = PHI <_9(4)>
  # DEBUG BEGIN_STMT
  _11 = desc_17(D)->stats;
  _11->avail = _12;
  return;

}



;; Function memp_init (memp_init, funcdef_no=2, decl_uid=6541, cgraph_uid=3, symbol_order=47)

Modification phase of node memp_init/47
memp_init ()
{
  u16_t i;
  int _1;
  const struct memp_desc * _2;
  struct stats_mem * _3;

  <bb 2> [local count: 89442694]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 984299131]:
  # DEBUG BEGIN_STMT
  _1 = (int) i_4;
  _2 = memp_pools[_1];
  memp_init_pool (_2);
  # DEBUG BEGIN_STMT
  _3 = _2->stats;
  lwip_stats.memp[_1] = _3;
  # DEBUG BEGIN_STMT
  i_9 = i_4 + 1;
  # DEBUG i => i_9

  <bb 4> [local count: 1073741824]:
  # i_4 = PHI <0(2), i_9(3)>
  # DEBUG i => i_4
  # DEBUG BEGIN_STMT
  if (i_4 != 11)
    goto <bb 3>; [91.67%]
  else
    goto <bb 5>; [8.33%]

  <bb 5> [local count: 89442694]:
  return;

}



;; Function memp_malloc_pool (memp_malloc_pool, funcdef_no=4, decl_uid=6418, cgraph_uid=5, symbol_order=49)

Modification phase of node memp_malloc_pool/49
memp_malloc_pool (const struct memp_desc * desc)
{
  void * _5;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (desc_2(D) == 0B)
    goto <bb 5>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = do_memp_malloc_pool (desc_2(D));
  return _5;

}



;; Function memp_malloc (memp_malloc, funcdef_no=5, decl_uid=6543, cgraph_uid=6, symbol_order=50)

Modification phase of node memp_malloc/50
memp_malloc (memp_t type)
{
  void * memp;
  const struct memp_desc * _1;
  void * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (type_4(D) > 10)
    goto <bb 4>; [29.93%]
  else
    goto <bb 3>; [70.07%]

  <bb 3> [local count: 752370897]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = memp_pools[type_4(D)];
  memp_7 = do_memp_malloc_pool (_1);
  # DEBUG memp => memp_7
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # _2 = PHI <0B(2), memp_7(3)>
  return _2;

}



;; Function memp_free_pool (memp_free_pool, funcdef_no=7, decl_uid=6421, cgraph_uid=8, symbol_order=52)

Modification phase of node memp_free_pool/52
memp_free_pool (const struct memp_desc * desc, void * mem)
{
  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (desc_3(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_5(D) == 0B)
    goto <bb 6>; [30.95%]
  else
    goto <bb 5>; [69.05%]

  <bb 5> [local count: 172997]:
  # DEBUG BEGIN_STMT
  do_memp_free_pool (desc_3(D), mem_5(D));

  <bb 6> [local count: 250539]:
  return;

}



;; Function memp_free (memp_free, funcdef_no=8, decl_uid=6546, cgraph_uid=9, symbol_order=53)

Modification phase of node memp_free/53
memp_free (memp_t type, void * mem)
{
  const struct memp_desc * _1;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (type_3(D) > 10)
    goto <bb 5>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_4(D) == 0B)
    goto <bb 5>; [30.95%]
  else
    goto <bb 4>; [69.05%]

  <bb 4> [local count: 489336361]:
  # DEBUG BEGIN_STMT
  _1 = memp_pools[type_3(D)];
  do_memp_free_pool (_1, mem_4(D));

  <bb 5> [local count: 1073741824]:
  return;

}


