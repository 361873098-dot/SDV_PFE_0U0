
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Gpt_ProcessCommonInterrupt/2:

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

Gpt_ProcessCommonInterrupt/2 (Gpt_ProcessCommonInterrupt) @06e60b60
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: PIT_1_ChannelConfig_PB_VS_0/1 (addr)PIT_1_ChannelConfig_PB_VS_0/1 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
PIT_1_ChannelConfig_PB_VS_0/1 (PIT_1_ChannelConfig_PB_VS_0) @06eb50d8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Gpt_ProcessCommonInterrupt/2 (addr)Gpt_ProcessCommonInterrupt/2 (addr)
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
PIT_1_InitConfig_PB_VS_0/0 (PIT_1_InitConfig_PB_VS_0) @06eb5000
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
