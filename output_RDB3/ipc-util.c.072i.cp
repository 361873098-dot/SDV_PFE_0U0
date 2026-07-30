
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  ipc_memcpy/0:

 Propagating constants:

Not considering ipc_memcpy for cloning; -fipa-cp-clone disabled.

overall_size: 14, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: ipc_memcpy/0:
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


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

ipc_memcpy/0 (ipc_memcpy) @06e2d9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:241044082 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function ipc_memcpy (ipc_memcpy, funcdef_no=0, decl_uid=5753, cgraph_uid=1, symbol_order=0)

Modification phase of node ipc_memcpy/0
ipc_memcpy (void * dst, const void * src, uint32 data_size)
{
  uint32 i;
  const uint8 * _1;
  uint8 * _2;
  unsigned char _3;

  <bb 2> [local count: 241044082]:
  # DEBUG BEGIN_STMT
  # DEBUG tmp_dst => dst_7(D)
  # DEBUG BEGIN_STMT
  # DEBUG tmp_src => src_8(D)
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG BEGIN_STMT
  if (dst_7(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 168730857]:
  if (src_8(D) != 0B)
    goto <bb 7>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 7> [local count: 118111600]:
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = src_8(D) + i_4;
  _2 = dst_7(D) + i_4;
  _3 = *_1;
  *_2 = _3;
  # DEBUG BEGIN_STMT
  i_12 = i_4 + 1;
  # DEBUG i => i_12

  <bb 5> [local count: 1073741824]:
  # i_4 = PHI <i_12(4), 0(7)>
  # DEBUG i => i_4
  # DEBUG BEGIN_STMT
  if (i_4 < data_size_10(D))
    goto <bb 4>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 6> [local count: 241044082]:
  return;

}


