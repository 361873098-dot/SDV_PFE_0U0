
IPA constant propagation start:

IPA structures before propagation:

Jump functions:

 Propagating constants:


overall_size: 0, max_new_size: 11001

IPA lattices after all propagation:

Lattices:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

ipwConfig/2 (ipwConfig) @0758f2d0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Platform_uConfiguration/0 (addr)
  Availability: not_available
  Varpool flags: read-only
Platform_Config/1 (Platform_Config) @0758f1b0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Platform_uConfiguration/0 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Platform_uConfiguration/0 (Platform_uConfiguration) @0758f120
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: ipwConfig/2 (addr)
  Referring: Platform_Config/1 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
