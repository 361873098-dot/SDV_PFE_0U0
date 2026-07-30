
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  oal_mm_cache_get_line_size/21:
  Jump functions of caller  oal_mm_cache_flush/20:
  Jump functions of caller  oal_mm_cache_inval/19:
  Jump functions of caller  oal_mm_dev_unmap/18:
  Jump functions of caller  oal_mm_dev_map_cache/17:
  Jump functions of caller  oal_mm_dev_map/16:
  Jump functions of caller  oal_mm_phys_to_virt/15:
  Jump functions of caller  oal_mm_virt_to_phys/14:
  Jump functions of caller  oal_mm_virt_to_phys_contig/13:

 Propagating constants:

Not considering oal_mm_cache_get_line_size for cloning; -fipa-cp-clone disabled.
Function oal_mm_cache_flush/20 is not versionable, reason: not a tree_versionable_function.
Not considering oal_mm_cache_inval for cloning; -fipa-cp-clone disabled.
Not considering oal_mm_dev_unmap for cloning; -fipa-cp-clone disabled.
Function oal_mm_dev_map_cache/17 is not versionable, reason: not a tree_versionable_function.
Not considering oal_mm_dev_map for cloning; -fipa-cp-clone disabled.
Function oal_mm_phys_to_virt/15 is not versionable, reason: not a tree_versionable_function.
Function oal_mm_virt_to_phys/14 is not versionable, reason: not a tree_versionable_function.
Not considering oal_mm_virt_to_phys_contig for cloning; -fipa-cp-clone disabled.

overall_size: 41, max_new_size: 11001
 - context independent values, size: 0, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 3, time_benefit: 2.000000
 - context independent values, size: 2, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: oal_mm_cache_get_line_size/21:
  Node: oal_mm_cache_flush/20:
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
  Node: oal_mm_cache_inval/19:
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
  Node: oal_mm_dev_unmap/18:
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
  Node: oal_mm_dev_map_cache/17:
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
  Node: oal_mm_dev_map/16:
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
  Node: oal_mm_phys_to_virt/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: oal_mm_virt_to_phys/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: oal_mm_virt_to_phys_contig/13:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM

IPA decision stage:

 - Creating a specialized node of oal_mm_cache_inval/19 for all known contexts.

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

oal_mm_cache_inval.constprop.0/22 (oal_mm_cache_inval.constprop) @06e4bd20
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of oal_mm_cache_inval/19
  Availability: local
  Function flags: count:1073741824 (estimated locally) local icf_merged optimize_size
  Called by: oal_mm_cache_flush/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_mm_cache_get_line_size/21 (oal_mm_cache_get_line_size) @074d47e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_mm_cache_flush/20 (oal_mm_cache_flush) @074d42a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: oal_mm_cache_inval.constprop/22 (1073741824 (estimated locally),1.00 per call) 
oal_mm_cache_inval/19 (oal_mm_cache_inval) @074d4ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: 
oal_mm_dev_unmap/18 (oal_mm_dev_unmap) @074d4c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
oal_mm_dev_map_cache/17 (oal_mm_dev_map_cache) @074d49a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: oal_mm_dev_map/16 (1073741824 (estimated locally),1.00 per call) 
oal_mm_dev_map/16 (oal_mm_dev_map) @074d4700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: oal_mm_dev_map_cache/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
oal_mm_phys_to_virt/15 (oal_mm_phys_to_virt) @074d4460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: oal_mm_virt_to_phys_contig/13 (1073741824 (estimated locally),1.00 per call) 
oal_mm_virt_to_phys/14 (oal_mm_virt_to_phys) @074d41c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: oal_mm_virt_to_phys_contig/13 (1073741824 (estimated locally),1.00 per call) 
oal_mm_virt_to_phys_contig/13 (oal_mm_virt_to_phys_contig) @074cce00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: oal_mm_phys_to_virt/15 (1073741824 (estimated locally),1.00 per call) oal_mm_virt_to_phys/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function oal_mm_virt_to_phys_contig (oal_mm_virt_to_phys_contig, funcdef_no=11, decl_uid=5649, cgraph_uid=12, symbol_order=13)

Modification phase of node oal_mm_virt_to_phys_contig/13
oal_mm_virt_to_phys_contig (void * vaddr)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return vaddr_1(D);

}



;; Function oal_mm_virt_to_phys (oal_mm_virt_to_phys, funcdef_no=21, decl_uid=5651, cgraph_uid=13, symbol_order=14)

Modification phase of node oal_mm_virt_to_phys/14
oal_mm_virt_to_phys (void * vaddr)
{
  void * retval.9;

  <bb 2> [local count: 1073741824]:
  retval.9_2 = oal_mm_virt_to_phys_contig (vaddr_1(D)); [tail call]
  return retval.9_2;

}



;; Function oal_mm_phys_to_virt (oal_mm_phys_to_virt, funcdef_no=23, decl_uid=5653, cgraph_uid=14, symbol_order=15)

Modification phase of node oal_mm_phys_to_virt/15
oal_mm_phys_to_virt (void * paddr)
{
  void * retval.10;

  <bb 2> [local count: 1073741824]:
  retval.10_2 = oal_mm_virt_to_phys_contig (paddr_1(D)); [tail call]
  return retval.10_2;

}



;; Function oal_mm_dev_map (oal_mm_dev_map, funcdef_no=14, decl_uid=5656, cgraph_uid=15, symbol_order=16)

Modification phase of node oal_mm_dev_map/16
oal_mm_dev_map (void * paddr, const addr_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return paddr_1(D);

}



;; Function oal_mm_dev_map_cache (oal_mm_dev_map_cache, funcdef_no=25, decl_uid=5659, cgraph_uid=16, symbol_order=17)

Modification phase of node oal_mm_dev_map_cache/17
oal_mm_dev_map_cache (void * paddr, const addr_t len)
{
  void * retval.11;

  <bb 2> [local count: 1073741824]:
  retval.11_3 = oal_mm_dev_map (paddr_1(D), len_2(D)); [tail call]
  return retval.11_3;

}



;; Function oal_mm_dev_unmap (oal_mm_dev_unmap, funcdef_no=16, decl_uid=5662, cgraph_uid=17, symbol_order=18)

Modification phase of node oal_mm_dev_unmap/18
oal_mm_dev_unmap (void * paddr, const addr_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function oal_mm_cache_inval (oal_mm_cache_inval, funcdef_no=17, decl_uid=5666, cgraph_uid=18, symbol_order=19)

Modification phase of node oal_mm_cache_inval/19
oal_mm_cache_inval (const void * vaddr, const void * paddr, const addr_t len)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function oal_mm_cache_flush (oal_mm_cache_flush, funcdef_no=27, decl_uid=5670, cgraph_uid=19, symbol_order=20)

Modification phase of node oal_mm_cache_flush/20
oal_mm_cache_flush (const void * vaddr, const void * paddr, const addr_t len)
{
  <bb 2> [local count: 1073741824]:
  oal_mm_cache_inval (vaddr_1(D), paddr_2(D), len_3(D)); [tail call]
  return;

}



;; Function oal_mm_cache_get_line_size (oal_mm_cache_get_line_size, funcdef_no=19, decl_uid=5672, cgraph_uid=20, symbol_order=21)

Modification phase of node oal_mm_cache_get_line_size/21
oal_mm_cache_get_line_size ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 64;

}


