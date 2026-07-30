
IPA constant propagation start:
Determining dynamic type for call: _13 = mem_link_valid (mem_23);
  Starting walk at: _13 = mem_link_valid (mem_23);
  instance pointer: mem_23  Outer instance pointer: mem_23 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: plug_holes (mem_23);
  Starting walk at: plug_holes (mem_23);
  instance pointer: mem_23  Outer instance pointer: mem_23 offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  memset/15:
  Jump functions of caller  mem_calloc/13:
    callsite  mem_calloc/13 -> mem_malloc/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  mem_malloc/12:
  Jump functions of caller  mem_trim/11:
  Jump functions of caller  mem_free/10:
    callsite  mem_free/10 -> plug_holes/7 : 
       param 0: PASS THROUGH: 0, op pointer_plus_expr 4294967288
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  mem_free/10 -> mem_link_valid/9 : 
       param 0: PASS THROUGH: 0, op pointer_plus_expr 4294967288
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  mem_link_valid/9:
  Jump functions of caller  mem_init/8:
  Jump functions of caller  plug_holes/7:

 Propagating constants:

Not considering mem_calloc for cloning; -fipa-cp-clone disabled.
Not considering mem_malloc for cloning; -fipa-cp-clone disabled.
Not considering mem_trim for cloning; -fipa-cp-clone disabled.
Not considering mem_free for cloning; -fipa-cp-clone disabled.
Not considering mem_init for cloning; -fipa-cp-clone disabled.

overall_size: 348, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: mem_calloc/13:
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
  Node: mem_malloc/12:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mem_trim/11:
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
  Node: mem_free/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mem_link_valid/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mem * ~[0B, 0B]
        AGGS VARIABLE
  Node: mem_init/8:
  Node: plug_holes/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mem * ~[0B, 0B]
        AGGS VARIABLE

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

memset/15 (memset) @06fe9b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mem_calloc/13 (313876736 (estimated locally),0.29 per call) 
  Calls: 
lwip_stats/14 (lwip_stats) @06fd7a20
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: mem_free/10 (write)mem_free/10 (read)mem_trim/11 (write)mem_trim/11 (read)mem_init/8 (write)mem_trim/11 (read)mem_trim/11 (write)mem_malloc/12 (read)mem_malloc/12 (write)mem_malloc/12 (read)mem_malloc/12 (write)mem_malloc/12 (read)mem_malloc/12 (write)mem_malloc/12 (read)mem_malloc/12 (write)mem_malloc/12 (read)mem_malloc/12 (write)
  Availability: not_available
  Varpool flags:
mem_calloc/13 (mem_calloc) @06fddc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: memset/15 (313876736 (estimated locally),0.29 per call) mem_malloc/12 (587014656 (estimated locally),0.55 per call) 
mem_malloc/12 (mem_malloc) @06fdd9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lfree/4 (read)ram/2 (read)lwip_stats/14 (read)lwip_stats/14 (write)lwip_stats/14 (read)lwip_stats/14 (write)lwip_stats/14 (read)lwip_stats/14 (write)lwip_stats/14 (read)lwip_stats/14 (write)ram_end/3 (read)lfree/4 (write)ram_end/3 (read)ram_end/3 (read)lwip_stats/14 (read)lwip_stats/14 (write)
  Referring: 
  Availability: available
  Function flags: count:1445416 (estimated locally) body optimize_size
  Called by: mem_calloc/13 (587014656 (estimated locally),0.55 per call) 
  Calls: 
mem_trim/11 (mem_trim) @06fd28c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ram/2 (read)ram_end/3 (read)lfree/4 (read)lfree/4 (write)lwip_stats/14 (read)lwip_stats/14 (write)lfree/4 (read)lfree/4 (write)lwip_stats/14 (read)lwip_stats/14 (write)
  Referring: 
  Availability: available
  Function flags: count:189773 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mem_free/10 (mem_free) @06f7ca80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ram/2 (read)ram_end/3 (read)lfree/4 (read)lfree/4 (write)lwip_stats/14 (read)lwip_stats/14 (write)
  Referring: 
  Availability: available
  Function flags: count:262176 (estimated locally) body optimize_size
  Called by: 
  Calls: plug_holes/7 (6711 (estimated locally),0.03 per call) mem_link_valid/9 (13422 (estimated locally),0.05 per call) 
mem_link_valid/9 (mem_link_valid) @06f7c2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ram/2 (read)ram_end/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: mem_free/10 (13422 (estimated locally),0.05 per call) 
  Calls: 
mem_init/8 (mem_init) @06f74ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ram_heap/1 (addr)ram/2 (write)ram_end/3 (write)lfree/4 (write)lwip_stats/14 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
plug_holes/7 (plug_holes) @06f74620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: ram/2 (read)ram_end/3 (read)lfree/4 (read)lfree/4 (write)lfree/4 (read)lfree/4 (write)
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: mem_free/10 (6711 (estimated locally),0.03 per call) 
  Calls: 
lfree/4 (lfree) @06f73240
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mem_trim/11 (write)mem_trim/11 (read)plug_holes/7 (write)plug_holes/7 (read)plug_holes/7 (write)mem_free/10 (read)mem_free/10 (write)mem_trim/11 (read)mem_trim/11 (write)plug_holes/7 (read)mem_init/8 (write)mem_malloc/12 (read)mem_malloc/12 (write)
  Availability: available
  Varpool flags:
ram_end/3 (ram_end) @06f71e58
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mem_init/8 (write)mem_trim/11 (read)mem_free/10 (read)plug_holes/7 (read)mem_link_valid/9 (read)mem_malloc/12 (read)mem_malloc/12 (read)mem_malloc/12 (read)
  Availability: available
  Varpool flags:
ram/2 (ram) @06f71dc8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mem_trim/11 (read)mem_free/10 (read)mem_link_valid/9 (read)mem_init/8 (write)plug_holes/7 (read)mem_malloc/12 (read)
  Availability: available
  Varpool flags:
ram_heap/1 (ram_heap) @06f71d38
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: mem_init/8 (addr)
  Availability: available
  Varpool flags:

;; Function mem_init (mem_init, funcdef_no=4, decl_uid=6381, cgraph_uid=5, symbol_order=8)

Modification phase of node mem_init/8
mem_init ()
{
  unsigned int ram_heap.0_1;
  unsigned int _2;
  unsigned int _3;
  u8_t * _4;
  struct mem * _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ram_heap.0_1 = (unsigned int) &ram_heap;
  _2 = ram_heap.0_1 + 3;
  _3 = _2 & 4294967292;
  _4 = (u8_t *) _3;
  ram = _4;
  # DEBUG BEGIN_STMT
  # DEBUG mem => _4
  # DEBUG BEGIN_STMT
  MEM[(struct mem *)_4].next = 32768;
  # DEBUG BEGIN_STMT
  MEM[(struct mem *)_4].prev = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct mem *)_4].used = 0;
  # DEBUG BEGIN_STMT
  # DEBUG ptr => 32768
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _16 = _4 + 32768;
  # DEBUG ptr => NULL
  ram_end = _16;
  # DEBUG BEGIN_STMT
  _16->used = 1;
  # DEBUG BEGIN_STMT
  _16->next = 32768;
  # DEBUG BEGIN_STMT
  _16->prev = 32768;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lfree = _4;
  # DEBUG BEGIN_STMT
  lwip_stats.mem.avail = 32768;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function mem_free (mem_free, funcdef_no=6, decl_uid=6391, cgraph_uid=7, symbol_order=10)

Modification phase of node mem_free/10
mem_free (void * rmem)
{
  struct mem * mem;
  unsigned int rmem.6_1;
  unsigned int _2;
  u8_t * ram.7_5;
  u8_t * _6;
  struct mem * ram_end.8_7;
  unsigned char _10;
  int _13;
  struct mem * lfree.9_16;
  short unsigned int _17;
  int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  short unsigned int _22;

  <bb 2> [local count: 262176]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (rmem_3(D) == 0B)
    goto <bb 16>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 214748]:
  # DEBUG BEGIN_STMT
  rmem.6_1 = (unsigned int) rmem_3(D);
  _2 = rmem.6_1 & 3;
  if (_2 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 17> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 107374]:
  # DEBUG BEGIN_STMT
  mem_23 = rmem_3(D) + 4294967288;
  # DEBUG mem => mem_23
  # DEBUG BEGIN_STMT
  ram.7_5 = ram;
  if (ram.7_5 > mem_23)
    goto <bb 7>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 53687]:
  _6 = rmem_3(D) + 12;
  ram_end.8_7 = ram_end;
  if (_6 > ram_end.8_7)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 80531]:

  <bb 8> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 21> [local count: 805306369]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 26844]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = MEM[(struct mem *)rmem_3(D) + 4294967288B].used;
  if (_10 == 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 18> [local count: 13422]:

  <bb 10> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 22> [local count: 134217728]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 13422]:
  # DEBUG BEGIN_STMT
  _13 = mem_link_valid (mem_23);
  if (_13 == 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 19> [local count: 6711]:

  <bb 12> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 67108864]:
  goto <bb 12>; [100.00%]

  <bb 13> [local count: 6711]:
  # DEBUG BEGIN_STMT
  MEM[(struct mem *)rmem_3(D) + 4294967288B].used = 0;
  # DEBUG BEGIN_STMT
  lfree.9_16 = lfree;
  if (lfree.9_16 > mem_23)
    goto <bb 14>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 14> [local count: 3355]:
  # DEBUG BEGIN_STMT
  lfree = mem_23;

  <bb 15> [local count: 6711]:
  # DEBUG BEGIN_STMT
  _17 = lwip_stats.mem.used;
  _18 = mem_23 - ram.7_5;
  _19 = (short unsigned int) _18;
  _20 = MEM[(struct mem *)rmem_3(D) + 4294967288B].next;
  _21 = _19 - _20;
  _22 = _17 + _21;
  lwip_stats.mem.used = _22;
  # DEBUG BEGIN_STMT
  plug_holes (mem_23);

  <bb 16> [local count: 54138]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function mem_trim (mem_trim, funcdef_no=7, decl_uid=6384, cgraph_uid=8, symbol_order=11)

Modification phase of node mem_trim/11
mem_trim (void * rmem, mem_size_t new_size)
{
  mem_size_t next;
  struct mem * mem;
  mem_size_t ptr2;
  mem_size_t newsize;
  mem_size_t size;
  short unsigned int _1;
  u8_t * ram.18_2;
  struct mem * ram_end.19_3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned char _6;
  short unsigned int _7;
  struct mem * lfree.22_8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  unsigned int _13;
  unsigned int _14;
  unsigned int _15;
  short unsigned int _16;
  struct mem * lfree.23_17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int _21;
  void * _22;
  struct mem * _38;
  int _40;
  sizetype _51;
  short unsigned int _57;
  sizetype _64;
  struct mem * _65;
  sizetype _66;
  struct mem * _67;
  sizetype _68;
  struct mem * _69;
  sizetype _70;
  struct mem * _71;
  sizetype _72;
  struct mem * _73;

  <bb 2> [local count: 189773]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = new_size_32(D) + 3;
  newsize_33 = _1 & 65532;
  # DEBUG newsize => newsize_33
  # DEBUG BEGIN_STMT
  if (newsize_33 <= 11)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 94886]:
  # DEBUG newsize => newsize_33
  # DEBUG BEGIN_STMT
  if (newsize_33 > 32768)
    goto <bb 28>; [17.38%]
  else
    goto <bb 4>; [82.62%]

  <bb 4> [local count: 173282]:
  # newsize_74 = PHI <newsize_33(3), 12(2)>
  # DEBUG newsize => NULL
  if (new_size_32(D) > newsize_74)
    goto <bb 28>; [17.38%]
  else
    goto <bb 5>; [82.62%]

  <bb 5> [local count: 143165]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ram.18_2 = ram;
  if (ram.18_2 > rmem_35(D))
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 107374]:
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 71583]:
  ram_end.19_3 = ram_end;
  if (ram_end.19_3 <= rmem_35(D))
    goto <bb 6>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 32> [local count: 1073741824]:

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT
  goto <bb 32>; [100.00%]

  <bb 9> [local count: 35791]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem_36 = rmem_35(D) + 4294967288;
  # DEBUG mem => mem_36
  # DEBUG BEGIN_STMT
  # DEBUG mem => mem_36
  # DEBUG INLINE_ENTRY mem_to_ptr
  # DEBUG BEGIN_STMT
  _40 = mem_36 - ram.18_2;
  _57 = (short unsigned int) _40;
  # DEBUG mem => NULL
  # DEBUG ptr => _57
  # DEBUG BEGIN_STMT
  _4 = MEM[(struct mem *)rmem_35(D) + 4294967288B].next;
  _5 = _4 - _57;
  size_37 = _5 + 65528;
  # DEBUG size => size_37
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (size_37 < newsize_74)
    goto <bb 29>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 29> [local count: 17896]:

  <bb 10> [local count: 178956971]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 178956971]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 17896]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (size_37 == newsize_74)
    goto <bb 28>; [20.97%]
  else
    goto <bb 12>; [79.03%]

  <bb 12> [local count: 14143]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ptr => _4
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _51 = (sizetype) _4;
  _38 = ram.18_2 + _51;
  # DEBUG ptr => NULL
  # DEBUG mem2 => _38
  # DEBUG BEGIN_STMT
  _6 = _38->used;
  if (_6 == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 13> [local count: 7071]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_4 == 32768)
    goto <bb 30>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 30> [local count: 2404]:

  <bb 14> [local count: 24043048]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 34> [local count: 24043048]:
  goto <bb 14>; [100.00%]

  <bb 15> [local count: 4667]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  next_49 = _38->next;
  # DEBUG next => next_49
  # DEBUG BEGIN_STMT
  _7 = _57 + newsize_74;
  ptr2_50 = _7 + 8;
  # DEBUG ptr2 => ptr2_50
  # DEBUG BEGIN_STMT
  lfree.22_8 = lfree;
  if (lfree.22_8 == _38)
    goto <bb 16>; [30.00%]
  else
    goto <bb 17>; [70.00%]

  <bb 16> [local count: 1400]:
  # DEBUG BEGIN_STMT
  # DEBUG ptr => ptr2_50
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _64 = (sizetype) ptr2_50;
  _65 = ram.18_2 + _64;
  # DEBUG ptr => NULL
  lfree = _65;

  <bb 17> [local count: 4667]:
  # DEBUG BEGIN_STMT
  # DEBUG ptr => ptr2_50
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _66 = (sizetype) ptr2_50;
  _67 = ram.18_2 + _66;
  # DEBUG ptr => NULL
  # DEBUG mem2 => _67
  # DEBUG BEGIN_STMT
  _67->used = 0;
  # DEBUG BEGIN_STMT
  _67->next = next_49;
  # DEBUG BEGIN_STMT
  _67->prev = _57;
  # DEBUG BEGIN_STMT
  MEM[(struct mem *)rmem_35(D) + 4294967288B].next = ptr2_50;
  # DEBUG BEGIN_STMT
  _9 = _67->next;
  if (_9 != 32768)
    goto <bb 18>; [66.00%]
  else
    goto <bb 19>; [34.00%]

  <bb 18> [local count: 3080]:
  # DEBUG BEGIN_STMT
  # DEBUG ptr => _9
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _68 = (sizetype) _9;
  _69 = ram.18_2 + _68;
  # DEBUG ptr => NULL
  _69->prev = ptr2_50;

  <bb 19> [local count: 4667]:
  # DEBUG BEGIN_STMT
  _10 = lwip_stats.mem.used;
  _11 = newsize_74 - size_37;
  _12 = _10 + _11;
  lwip_stats.mem.used = _12;
  goto <bb 28>; [100.00%]

  <bb 20> [local count: 7071]:
  # DEBUG BEGIN_STMT
  _13 = (unsigned int) newsize_74;
  _14 = _13 + 20;
  _15 = (unsigned int) size_37;
  if (_14 <= _15)
    goto <bb 21>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 21> [local count: 3536]:
  # DEBUG BEGIN_STMT
  _16 = _57 + newsize_74;
  ptr2_39 = _16 + 8;
  # DEBUG ptr2 => ptr2_39
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_4 == 32768)
    goto <bb 31>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 31> [local count: 1202]:

  <bb 22> [local count: 12021524]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 35> [local count: 12021524]:
  goto <bb 22>; [100.00%]

  <bb 23> [local count: 2334]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ptr => ptr2_39
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _70 = (sizetype) ptr2_39;
  _71 = ram.18_2 + _70;
  # DEBUG ptr => NULL
  # DEBUG mem2 => _71
  # DEBUG BEGIN_STMT
  lfree.23_17 = lfree;
  if (lfree.23_17 > _71)
    goto <bb 24>; [50.00%]
  else
    goto <bb 25>; [50.00%]

  <bb 24> [local count: 1167]:
  # DEBUG BEGIN_STMT
  lfree = _71;

  <bb 25> [local count: 2334]:
  # DEBUG BEGIN_STMT
  _71->used = 0;
  # DEBUG BEGIN_STMT
  _71->next = _4;
  # DEBUG BEGIN_STMT
  _71->prev = _57;
  # DEBUG BEGIN_STMT
  MEM[(struct mem *)rmem_35(D) + 4294967288B].next = ptr2_39;
  # DEBUG BEGIN_STMT
  _18 = _71->next;
  if (_18 != 32768)
    goto <bb 26>; [66.00%]
  else
    goto <bb 27>; [34.00%]

  <bb 26> [local count: 1540]:
  # DEBUG BEGIN_STMT
  # DEBUG ptr => _18
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _72 = (sizetype) _18;
  _73 = ram.18_2 + _72;
  # DEBUG ptr => NULL
  _73->prev = ptr2_39;

  <bb 27> [local count: 2334]:
  # DEBUG BEGIN_STMT
  _19 = lwip_stats.mem.used;
  _20 = newsize_74 - size_37;
  _21 = _19 + _20;
  lwip_stats.mem.used = _21;

  <bb 28> [local count: 60897]:
  # _22 = PHI <0B(4), rmem_35(D)(20), rmem_35(D)(11), rmem_35(D)(19), rmem_35(D)(27), 0B(3)>
  return _22;

}



;; Function mem_malloc (mem_malloc, funcdef_no=8, decl_uid=6386, cgraph_uid=9, symbol_order=12)

Modification phase of node mem_malloc/12
mem_malloc (mem_size_t size_in)
{
  struct mem * cur;
  mem_size_t size;
  mem_size_t ptr2;
  mem_size_t ptr;
  short unsigned int _1;
  struct mem * lfree.24_2;
  unsigned char _3;
  short unsigned int _4;
  unsigned int _5;
  struct mem * _6;
  unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  short unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  unsigned char _21;
  struct mem * ram_end.26_22;
  struct mem * ram_end.28_23;
  unsigned int mem.30_24;
  unsigned int _25;
  unsigned int _26;
  struct mem * ram_end.31_27;
  unsigned int ram_end.32_28;
  unsigned int _29;
  unsigned int _30;
  unsigned int _31;
  unsigned int _32;
  short unsigned int _33;
  short unsigned int _34;
  unsigned char _36;
  void * _38;
  short unsigned int _47;
  unsigned int _52;
  struct mem * _55;
  short unsigned int _57;
  int _72;
  void * _75;
  unsigned int _76;
  u8_t * ram.12_79;
  sizetype _81;
  struct mem * _82;
  sizetype _83;
  struct mem * _84;
  int _85;
  short unsigned int _86;
  sizetype _87;
  struct mem * _88;

  <bb 2> [local count: 1445416]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (size_in_50(D) == 0)
    goto <bb 33>; [17.38%]
  else
    goto <bb 3>; [82.62%]

  <bb 3> [local count: 1194202]:
  # DEBUG BEGIN_STMT
  _1 = size_in_50(D) + 3;
  size_51 = _1 & 65532;
  # DEBUG size => size_51
  # DEBUG BEGIN_STMT
  if (size_51 <= 11)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 597101]:
  # DEBUG size => size_51
  # DEBUG BEGIN_STMT
  if (size_51 > 32768)
    goto <bb 33>; [17.38%]
  else
    goto <bb 5>; [82.62%]

  <bb 5> [local count: 1090426]:
  # size_89 = PHI <size_51(4), 12(3)>
  # DEBUG size => NULL
  if (size_in_50(D) > size_89)
    goto <bb 33>; [17.38%]
  else
    goto <bb 6>; [82.62%]

  <bb 6> [local count: 900910]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lfree.24_2 = lfree;
  # DEBUG mem => lfree.24_2
  # DEBUG INLINE_ENTRY mem_to_ptr
  # DEBUG BEGIN_STMT
  ram.12_79 = ram;
  _72 = lfree.24_2 - ram.12_79;
  _57 = (short unsigned int) _72;
  # DEBUG mem => NULL
  # DEBUG ptr => _57
  goto <bb 31>; [100.00%]

  <bb 7> [local count: 10512241]:
  # DEBUG BEGIN_STMT
  # DEBUG ptr => ptr_35
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _55 = ram.12_79 + _30;
  # DEBUG ptr => NULL
  # DEBUG mem => _55
  # DEBUG BEGIN_STMT
  _3 = _55->used;
  if (_3 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 30>; [50.00%]

  <bb 8> [local count: 5256120]:
  _4 = _55->next;
  _5 = (unsigned int) _4;
  _7 = _5 - _30;
  _8 = _7 + 4294967288;
  if (_8 >= _31)
    goto <bb 9>; [5.50%]
  else
    goto <bb 30>; [94.50%]

  <bb 9> [local count: 289087]:
  # _47 = PHI <_4(8)>
  # _76 = PHI <_8(8)>
  # _52 = PHI <_31(8)>
  # ptr_67 = PHI <ptr_35(8)>
  # _6 = PHI <_55(8)>
  # DEBUG BEGIN_STMT
  _9 = _52 + 20;
  if (_9 <= _76)
    goto <bb 10>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 10> [local count: 144543]:
  # DEBUG BEGIN_STMT
  _10 = ptr_67 + size_89;
  ptr2_60 = _10 + 8;
  # DEBUG ptr2 => ptr2_60
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ptr2_60 == 32768)
    goto <bb 34>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 34> [local count: 49145]:

  <bb 11> [local count: 491448099]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 39> [local count: 491448099]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 95399]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ptr => ptr2_60
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _81 = (sizetype) ptr2_60;
  _82 = ram.12_79 + _81;
  # DEBUG ptr => NULL
  # DEBUG mem2 => _82
  # DEBUG BEGIN_STMT
  _82->used = 0;
  # DEBUG BEGIN_STMT
  _82->next = _47;
  # DEBUG BEGIN_STMT
  _82->prev = ptr_67;
  # DEBUG BEGIN_STMT
  _6->next = ptr2_60;
  # DEBUG BEGIN_STMT
  _6->used = 1;
  # DEBUG BEGIN_STMT
  _11 = _82->next;
  if (_11 != 32768)
    goto <bb 13>; [66.00%]
  else
    goto <bb 14>; [34.00%]

  <bb 13> [local count: 62963]:
  # DEBUG BEGIN_STMT
  # DEBUG ptr => _11
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _83 = (sizetype) _11;
  _84 = ram.12_79 + _83;
  # DEBUG ptr => NULL
  _84->prev = ptr2_60;

  <bb 14> [local count: 95399]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = lwip_stats.mem.used;
  _13 = _12 + size_89;
  _14 = _13 + 8;
  lwip_stats.mem.used = _14;
  # DEBUG BEGIN_STMT
  _15 = lwip_stats.mem.max;
  if (_14 > _15)
    goto <bb 15>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 15> [local count: 47699]:
  # DEBUG BEGIN_STMT
  lwip_stats.mem.max = _14;
  goto <bb 18>; [100.00%]

  <bb 16> [local count: 144543]:
  # DEBUG BEGIN_STMT
  _6->used = 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = lwip_stats.mem.used;
  _17 = _16 + _47;
  # DEBUG mem => _6
  # DEBUG INLINE_ENTRY mem_to_ptr
  # DEBUG BEGIN_STMT
  _85 = _6 - ram.12_79;
  _86 = (short unsigned int) _85;
  # DEBUG mem => NULL
  _18 = _17 - _86;
  lwip_stats.mem.used = _18;
  # DEBUG BEGIN_STMT
  _19 = lwip_stats.mem.max;
  if (_18 > _19)
    goto <bb 17>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 17> [local count: 72272]:
  # DEBUG BEGIN_STMT
  lwip_stats.mem.max = _18;

  <bb 18> [local count: 239942]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (lfree.24_2 == _6)
    goto <bb 38>; [30.00%]
  else
    goto <bb 25>; [70.00%]

  <bb 38> [local count: 71983]:
  goto <bb 20>; [100.00%]

  <bb 19> [local count: 600909]:
  # DEBUG BEGIN_STMT
  _20 = cur_37->next;
  # DEBUG ptr => _20
  # DEBUG INLINE_ENTRY ptr_to_mem
  # DEBUG BEGIN_STMT
  _87 = (sizetype) _20;
  _88 = ram.12_79 + _87;
  # DEBUG ptr => NULL
  # DEBUG cur => _88

  <bb 20> [local count: 672892]:
  # cur_37 = PHI <_88(19), lfree.24_2(38)>
  # DEBUG cur => cur_37
  # DEBUG BEGIN_STMT
  _21 = cur_37->used;
  if (_21 != 0)
    goto <bb 21>; [94.50%]
  else
    goto <bb 22>; [5.50%]

  <bb 21> [local count: 635882]:
  ram_end.26_22 = ram_end;
  if (ram_end.26_22 != cur_37)
    goto <bb 19>; [94.50%]
  else
    goto <bb 22>; [5.50%]

  <bb 22> [local count: 71983]:
  # _36 = PHI <_21(20), _21(21)>
  # cur_61 = PHI <cur_37(20), cur_37(21)>
  # DEBUG BEGIN_STMT
  lfree = cur_61;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ram_end.28_23 = ram_end;
  if (ram_end.28_23 != cur_61)
    goto <bb 23>; [70.00%]
  else
    goto <bb 25>; [30.00%]

  <bb 23> [local count: 50388]:
  if (_36 != 0)
    goto <bb 35>; [50.00%]
  else
    goto <bb 25>; [50.00%]

  <bb 35> [local count: 25194]:

  <bb 24> [local count: 251939422]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 40> [local count: 251939422]:
  goto <bb 24>; [100.00%]

  <bb 25> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem.30_24 = (unsigned int) _6;
  _25 = mem.30_24 + _52;
  _26 = _25 + 8;
  ram_end.31_27 = ram_end;
  ram_end.32_28 = (unsigned int) ram_end.31_27;
  if (_26 > ram_end.32_28)
    goto <bb 36>; [50.00%]
  else
    goto <bb 27>; [50.00%]

  <bb 36> [local count: 107374]:

  <bb 26> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 41> [local count: 1073741824]:
  goto <bb 26>; [100.00%]

  <bb 27> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _29 = mem.30_24 & 3;
  if (_29 != 0)
    goto <bb 37>; [66.00%]
  else
    goto <bb 29>; [34.00%]

  <bb 37> [local count: 70867]:

  <bb 28> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 42> [local count: 708669604]:
  goto <bb 28>; [100.00%]

  <bb 29> [local count: 36507]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _75 = _6 + 8;
  goto <bb 33>; [100.00%]

  <bb 30> [local count: 10223154]:
  # DEBUG BEGIN_STMT
  # DEBUG ptr => ptr_35
  # DEBUG INLINE_ENTRY NULL
  # DEBUG BEGIN_STMT
  # DEBUG ptr => NULL
  ptr_80 = _55->next;
  # DEBUG ptr => ptr_80

  <bb 31> [local count: 11124064]:
  # ptr_35 = PHI <_57(6), ptr_80(30)>
  # DEBUG ptr => ptr_35
  # DEBUG BEGIN_STMT
  _30 = (unsigned int) ptr_35;
  _31 = (unsigned int) size_89;
  _32 = 32768 - _31;
  if (_30 < _32)
    goto <bb 7>; [94.50%]
  else
    goto <bb 32>; [5.50%]

  <bb 32> [local count: 611824]:
  # DEBUG BEGIN_STMT
  _33 = lwip_stats.mem.err;
  _34 = _33 + 1;
  lwip_stats.mem.err = _34;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 1192836]:
  # _38 = PHI <0B(2), 0B(5), _75(29), 0B(32), 0B(4)>
  return _38;

}



;; Function mem_calloc (mem_calloc, funcdef_no=9, decl_uid=6389, cgraph_uid=10, symbol_order=13)

Modification phase of node mem_calloc/13
mem_calloc (mem_size_t count, mem_size_t size)
{
  size_t alloc_size;
  void * p;
  unsigned int _1;
  unsigned int _2;
  short unsigned int _3;
  void * _4;
  unsigned int _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) count_6(D);
  _2 = (unsigned int) size_7(D);
  alloc_size_8 = _1 * _2;
  # DEBUG alloc_size => alloc_size_8
  # DEBUG BEGIN_STMT
  _3 = (short unsigned int) alloc_size_8;
  _13 = alloc_size_8 & 65535;
  if (alloc_size_8 != _13)
    goto <bb 5>; [45.33%]
  else
    goto <bb 3>; [54.67%]

  <bb 3> [local count: 587014656]:
  # DEBUG BEGIN_STMT
  p_11 = mem_malloc (_3);
  # DEBUG p => p_11
  # DEBUG BEGIN_STMT
  if (p_11 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 313876736]:
  # DEBUG BEGIN_STMT
  memset (p_11, 0, alloc_size_8);

  <bb 5> [local count: 1073741824]:
  # _4 = PHI <0B(2), p_11(4), p_11(3)>
  return _4;

}


