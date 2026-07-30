
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

SerdesConfig0/1 (SerdesConfig0) @075401f8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Serdes_Ipw_ChannelConfig0/0 (addr)
  Availability: not_available
  Varpool flags: read-only
Serdes_Ipw_ChannelConfig0/0 (Serdes_Ipw_ChannelConfig0) @075400d8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: SerdesConfig0/1 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
