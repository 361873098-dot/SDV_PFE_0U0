
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_hif_nocpy_cfg_stop_all_chnl_dma/41:
  Jump functions of caller  pfe_hif_nocpy_cfg_get_emac_timer_ownership/40:
  Jump functions of caller  pfe_hif_nocpy_cfg_set_emac_timer_ownership/39:
  Jump functions of caller  pfe_hif_nocpy_cfg_get_rx_cnt/38:
  Jump functions of caller  pfe_hif_nocpy_cfg_get_tx_cnt/37:
  Jump functions of caller  pfe_hif_nocpy_chnl_cfg_get_text_stat/36:
  Jump functions of caller  pfe_hif_nocpy_cfg_is_tx_dma_active/35:
  Jump functions of caller  pfe_hif_nocpy_cfg_is_rx_dma_active/34:
  Jump functions of caller  pfe_hif_nocpy_cfg_get_tx_bd_ring_addr/33:
  Jump functions of caller  pfe_hif_nocpy_cfg_set_tx_bd_ring_addr/32:
  Jump functions of caller  pfe_hif_nocpy_cfg_get_rx_bd_ring_addr/31:
  Jump functions of caller  pfe_hif_nocpy_cfg_set_rx_bd_ring_addr/30:
  Jump functions of caller  pfe_hif_nocpy_cfg_tx_irq_unmask/29:
  Jump functions of caller  pfe_hif_nocpy_cfg_tx_irq_mask/28:
  Jump functions of caller  pfe_hif_nocpy_cfg_rx_irq_unmask/27:
  Jump functions of caller  pfe_hif_nocpy_cfg_rx_irq_mask/26:
  Jump functions of caller  pfe_hif_nocpy_cfg_tx_dma_start/25:
  Jump functions of caller  pfe_hif_nocpy_cfg_rx_dma_start/24:
  Jump functions of caller  pfe_hif_nocpy_cfg_rx_disable/23:
    callsite  pfe_hif_nocpy_cfg_rx_disable/23 -> pfe_hif_nocpy_cfg_rx_irq_mask/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_nocpy_cfg_rx_enable/22:
  Jump functions of caller  pfe_hif_nocpy_cfg_tx_disable/21:
    callsite  pfe_hif_nocpy_cfg_tx_disable/21 -> pfe_hif_nocpy_cfg_tx_irq_mask/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_nocpy_cfg_tx_enable/20:
  Jump functions of caller  pfe_hif_nocpy_cfg_fini/19:
  Jump functions of caller  pfe_hif_nocpy_cfg_init/18:
    callsite  pfe_hif_nocpy_cfg_init/18 -> pfe_hif_nocpy_cfg_tx_disable/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pfe_hif_nocpy_cfg_init/18 -> pfe_hif_nocpy_cfg_rx_disable/23 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pfe_hif_nocpy_cfg_irq_unmask/17:
  Jump functions of caller  pfe_hif_nocpy_cfg_irq_mask/16:
  Jump functions of caller  pfe_hif_nocpy_cfg_isr/15:

 Propagating constants:

Not considering pfe_hif_nocpy_cfg_stop_all_chnl_dma for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_get_emac_timer_ownership for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_set_emac_timer_ownership for cloning; -fipa-cp-clone disabled.
Function pfe_hif_nocpy_cfg_get_rx_cnt/38 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_hif_nocpy_cfg_get_tx_cnt for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_chnl_cfg_get_text_stat for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_is_tx_dma_active for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_is_rx_dma_active for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_get_tx_bd_ring_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_set_tx_bd_ring_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_get_rx_bd_ring_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_set_rx_bd_ring_addr for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_tx_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_tx_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_rx_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_rx_irq_mask for cloning; -fipa-cp-clone disabled.
Function pfe_hif_nocpy_cfg_tx_dma_start/25 is not versionable, reason: not a tree_versionable_function.
Not considering pfe_hif_nocpy_cfg_rx_dma_start for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_rx_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_rx_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_tx_disable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_tx_enable for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_fini for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_init for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_irq_unmask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_irq_mask for cloning; -fipa-cp-clone disabled.
Not considering pfe_hif_nocpy_cfg_isr for cloning; -fipa-cp-clone disabled.

overall_size: 216, max_new_size: 11001
 - context independent values, size: 2, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 4.000000
 - context independent values, size: 2, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: pfe_hif_nocpy_cfg_stop_all_chnl_dma/41:
  Node: pfe_hif_nocpy_cfg_get_emac_timer_ownership/40:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_set_emac_timer_ownership/39:
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
  Node: pfe_hif_nocpy_cfg_get_rx_cnt/38:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_get_tx_cnt/37:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_chnl_cfg_get_text_stat/36:
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
  Node: pfe_hif_nocpy_cfg_is_tx_dma_active/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_is_rx_dma_active/34:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_get_tx_bd_ring_addr/33:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_set_tx_bd_ring_addr/32:
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
  Node: pfe_hif_nocpy_cfg_get_rx_bd_ring_addr/31:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_set_rx_bd_ring_addr/30:
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
  Node: pfe_hif_nocpy_cfg_tx_irq_unmask/29:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_tx_irq_mask/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_rx_irq_unmask/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_rx_irq_mask/26:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_tx_dma_start/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_rx_dma_start/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_rx_disable/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_rx_enable/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_tx_disable/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_tx_enable/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_fini/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_init/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_irq_unmask/17:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_irq_mask/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pfe_hif_nocpy_cfg_isr/15:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_hif_nocpy_cfg_stop_all_chnl_dma/41 (pfe_hif_nocpy_cfg_stop_all_chnl_dma) @07684460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_get_emac_timer_ownership/40 (pfe_hif_nocpy_cfg_get_emac_timer_ownership) @07684e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: hif_nocpy_timer_ownership/14 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_set_emac_timer_ownership/39 (pfe_hif_nocpy_cfg_set_emac_timer_ownership) @07684b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: hif_nocpy_timer_ownership/14 (read)hif_nocpy_timer_ownership/14 (write)hif_nocpy_timer_ownership/14 (read)hif_nocpy_timer_ownership/14 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_get_rx_cnt/38 (pfe_hif_nocpy_cfg_get_rx_cnt) @076848c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_hif_nocpy_cfg_get_tx_cnt/37 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_nocpy_cfg_get_tx_cnt/37 (pfe_hif_nocpy_cfg_get_tx_cnt) @07684620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_hif_nocpy_cfg_get_rx_cnt/38 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_nocpy_chnl_cfg_get_text_stat/36 (pfe_hif_nocpy_chnl_cfg_get_text_stat) @07684380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_is_tx_dma_active/35 (pfe_hif_nocpy_cfg_is_tx_dma_active) @076840e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_is_rx_dma_active/34 (pfe_hif_nocpy_cfg_is_rx_dma_active) @076808c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_get_tx_bd_ring_addr/33 (pfe_hif_nocpy_cfg_get_tx_bd_ring_addr) @07680ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_set_tx_bd_ring_addr/32 (pfe_hif_nocpy_cfg_set_tx_bd_ring_addr) @07680b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_get_rx_bd_ring_addr/31 (pfe_hif_nocpy_cfg_get_rx_bd_ring_addr) @076807e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_set_rx_bd_ring_addr/30 (pfe_hif_nocpy_cfg_set_rx_bd_ring_addr) @07680460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_tx_irq_unmask/29 (pfe_hif_nocpy_cfg_tx_irq_unmask) @076800e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_tx_irq_mask/28 (pfe_hif_nocpy_cfg_tx_irq_mask) @07678540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_nocpy_cfg_tx_disable/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_nocpy_cfg_rx_irq_unmask/27 (pfe_hif_nocpy_cfg_rx_irq_unmask) @07678d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_rx_irq_mask/26 (pfe_hif_nocpy_cfg_rx_irq_mask) @076788c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_nocpy_cfg_rx_disable/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_nocpy_cfg_tx_dma_start/25 (pfe_hif_nocpy_cfg_tx_dma_start) @07678460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: pfe_hif_nocpy_cfg_rx_dma_start/24 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_nocpy_cfg_rx_dma_start/24 (pfe_hif_nocpy_cfg_rx_dma_start) @076781c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: pfe_hif_nocpy_cfg_tx_dma_start/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pfe_hif_nocpy_cfg_rx_disable/23 (pfe_hif_nocpy_cfg_rx_disable) @07673c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_nocpy_cfg_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_nocpy_cfg_rx_irq_mask/26 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_nocpy_cfg_rx_enable/22 (pfe_hif_nocpy_cfg_rx_enable) @076730e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_tx_disable/21 (pfe_hif_nocpy_cfg_tx_disable) @07673b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pfe_hif_nocpy_cfg_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: pfe_hif_nocpy_cfg_tx_irq_mask/28 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_nocpy_cfg_tx_enable/20 (pfe_hif_nocpy_cfg_tx_enable) @076737e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_fini/19 (pfe_hif_nocpy_cfg_fini) @07673380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_init/18 (pfe_hif_nocpy_cfg_init) @07673000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pfe_hif_nocpy_cfg_tx_disable/21 (1073741824 (estimated locally),1.00 per call) pfe_hif_nocpy_cfg_rx_disable/23 (1073741824 (estimated locally),1.00 per call) 
pfe_hif_nocpy_cfg_irq_unmask/17 (pfe_hif_nocpy_cfg_irq_unmask) @0766c460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_irq_mask/16 (pfe_hif_nocpy_cfg_irq_mask) @0766c000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pfe_hif_nocpy_cfg_isr/15 (pfe_hif_nocpy_cfg_isr) @07662d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
hif_nocpy_timer_ownership/14 (hif_nocpy_timer_ownership) @07665090
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: pfe_hif_nocpy_cfg_set_emac_timer_ownership/39 (write)pfe_hif_nocpy_cfg_set_emac_timer_ownership/39 (read)pfe_hif_nocpy_cfg_set_emac_timer_ownership/39 (write)pfe_hif_nocpy_cfg_set_emac_timer_ownership/39 (read)pfe_hif_nocpy_cfg_get_emac_timer_ownership/40 (read)
  Availability: available
  Varpool flags: initialized

;; Function pfe_hif_nocpy_cfg_isr (pfe_hif_nocpy_cfg_isr, funcdef_no=12, decl_uid=10005, cgraph_uid=13, symbol_order=15)

Modification phase of node pfe_hif_nocpy_cfg_isr/15
pfe_hif_nocpy_cfg_isr (addr_t base_va, pfe_hif_chnl_event_t * events)
{
  errno_t ret;
  uint32_t reg_en;
  uint32_t reg_src;
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  <unnamed type> _10;
  unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 2
  # DEBUG BEGIN_STMT
  *events_17(D) = 0;
  # DEBUG BEGIN_STMT
  _1 = base_va_19(D) + 56;
  _2 = (volatile uint32_t *) _1;
  reg_en_20 ={v} *_2;
  # DEBUG reg_en => reg_en_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_19(D) + 52;
  _4 = (volatile uint32_t *) _3;
  reg_src_22 ={v} *_4;
  # DEBUG reg_src => reg_src_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_4 ={v} reg_src_22;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = ~reg_src_22;
  _6 = _5 & reg_en_20;
  *_2 ={v} _6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = reg_en_20 & reg_src_22;
  _8 = _7 & 6;
  if (_8 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  *events_17(D) = 1;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 4> [local count: 1073741824]:
  # ret_12 = PHI <2(2), 0(3)>
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  _9 = _7 & 24;
  if (_9 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _10 = *events_17(D);
  _11 = _10 | 2;
  *events_17(D) = _11;
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0

  <bb 6> [local count: 1073741824]:
  # ret_13 = PHI <ret_12(4), 0(5)>
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  return ret_13;

}



;; Function pfe_hif_nocpy_cfg_irq_mask (pfe_hif_nocpy_cfg_irq_mask, funcdef_no=13, decl_uid=10007, cgraph_uid=14, symbol_order=16)

Modification phase of node pfe_hif_nocpy_cfg_irq_mask/16
pfe_hif_nocpy_cfg_irq_mask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 56;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  reg_6 = _3 & 4294967294;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_irq_unmask (pfe_hif_nocpy_cfg_irq_unmask, funcdef_no=14, decl_uid=10009, cgraph_uid=15, symbol_order=17)

Modification phase of node pfe_hif_nocpy_cfg_irq_unmask/17
pfe_hif_nocpy_cfg_irq_unmask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 56;
  _2 = (volatile uint32_t *) _1;
  _3 ={v} *_2;
  reg_6 = _3 | 1;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} reg_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_fini (pfe_hif_nocpy_cfg_fini, funcdef_no=16, decl_uid=10013, cgraph_uid=17, symbol_order=19)

Modification phase of node pfe_hif_nocpy_cfg_fini/19
pfe_hif_nocpy_cfg_fini (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 56;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_tx_enable (pfe_hif_nocpy_cfg_tx_enable, funcdef_no=17, decl_uid=10015, cgraph_uid=18, symbol_order=20)

Modification phase of node pfe_hif_nocpy_cfg_tx_enable/20
pfe_hif_nocpy_cfg_tx_enable (addr_t base_va)
{
  uint32_t regval;
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 4;
  _2 = (volatile uint32_t *) _1;
  regval_5 ={v} *_2;
  # DEBUG regval => regval_5
  # DEBUG BEGIN_STMT
  # DEBUG regval => regval_5 | 1
  # DEBUG BEGIN_STMT
  regval_6 = regval_5 | 3;
  # DEBUG regval => regval_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} regval_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_rx_enable (pfe_hif_nocpy_cfg_rx_enable, funcdef_no=19, decl_uid=10019, cgraph_uid=20, symbol_order=22)

Modification phase of node pfe_hif_nocpy_cfg_rx_enable/22
pfe_hif_nocpy_cfg_rx_enable (addr_t base_va)
{
  uint32_t regval;
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 32;
  _2 = (volatile uint32_t *) _1;
  regval_5 ={v} *_2;
  # DEBUG regval => regval_5
  # DEBUG BEGIN_STMT
  # DEBUG regval => regval_5 | 1
  # DEBUG BEGIN_STMT
  regval_6 = regval_5 | 3;
  # DEBUG regval => regval_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} regval_6;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_rx_dma_start (pfe_hif_nocpy_cfg_rx_dma_start, funcdef_no=21, decl_uid=10023, cgraph_uid=22, symbol_order=24)

Modification phase of node pfe_hif_nocpy_cfg_rx_dma_start/24
pfe_hif_nocpy_cfg_rx_dma_start (addr_t base_va)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_tx_dma_start (pfe_hif_nocpy_cfg_tx_dma_start, funcdef_no=40, decl_uid=10025, cgraph_uid=23, symbol_order=25)

Modification phase of node pfe_hif_nocpy_cfg_tx_dma_start/25
pfe_hif_nocpy_cfg_tx_dma_start (addr_t base_va)
{
  <bb 2> [local count: 1073741824]:
  pfe_hif_nocpy_cfg_rx_dma_start (base_va_1(D)); [tail call]
  return;

}



;; Function pfe_hif_nocpy_cfg_rx_irq_mask (pfe_hif_nocpy_cfg_rx_irq_mask, funcdef_no=23, decl_uid=10027, cgraph_uid=24, symbol_order=26)

Modification phase of node pfe_hif_nocpy_cfg_rx_irq_mask/26
pfe_hif_nocpy_cfg_rx_irq_mask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 56;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 & 4294967289;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_rx_disable (pfe_hif_nocpy_cfg_rx_disable, funcdef_no=20, decl_uid=10021, cgraph_uid=21, symbol_order=23)

Modification phase of node pfe_hif_nocpy_cfg_rx_disable/23
pfe_hif_nocpy_cfg_rx_disable (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 32;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hif_nocpy_cfg_rx_irq_mask (base_va_3(D));
  return;

}



;; Function pfe_hif_nocpy_cfg_rx_irq_unmask (pfe_hif_nocpy_cfg_rx_irq_unmask, funcdef_no=24, decl_uid=10029, cgraph_uid=25, symbol_order=27)

Modification phase of node pfe_hif_nocpy_cfg_rx_irq_unmask/27
pfe_hif_nocpy_cfg_rx_irq_unmask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 56;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 | 6;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_tx_irq_mask (pfe_hif_nocpy_cfg_tx_irq_mask, funcdef_no=25, decl_uid=10031, cgraph_uid=26, symbol_order=28)

Modification phase of node pfe_hif_nocpy_cfg_tx_irq_mask/28
pfe_hif_nocpy_cfg_tx_irq_mask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 56;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 & 4294967271;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_tx_disable (pfe_hif_nocpy_cfg_tx_disable, funcdef_no=18, decl_uid=10017, cgraph_uid=19, symbol_order=21)

Modification phase of node pfe_hif_nocpy_cfg_tx_disable/21
pfe_hif_nocpy_cfg_tx_disable (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 4;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hif_nocpy_cfg_tx_irq_mask (base_va_3(D));
  return;

}



;; Function pfe_hif_nocpy_cfg_init (pfe_hif_nocpy_cfg_init, funcdef_no=15, decl_uid=10011, cgraph_uid=16, symbol_order=18)

Modification phase of node pfe_hif_nocpy_cfg_init/18
pfe_hif_nocpy_cfg_init (addr_t base_va)
{
  uint32_t regval;
  unsigned int _1;
  volatile uint32_t * _2;
  unsigned int _3;
  volatile uint32_t * _4;
  unsigned int _5;
  volatile uint32_t * _6;
  unsigned int _7;
  volatile uint32_t * _8;
  unsigned int _9;
  volatile uint32_t * _10;
  unsigned int _11;
  volatile uint32_t * _12;
  unsigned int _13;
  volatile uint32_t * _14;
  unsigned int _15;
  volatile uint32_t * _16;
  unsigned int _17;
  volatile uint32_t * _18;
  unsigned int _19;
  volatile uint32_t * _20;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_21(D) + 56;
  _2 = (volatile uint32_t *) _1;
  *_2 ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = base_va_21(D) + 52;
  _4 = (volatile uint32_t *) _3;
  *_4 ={v} 4294967295;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hif_nocpy_cfg_rx_disable (base_va_21(D));
  # DEBUG BEGIN_STMT
  pfe_hif_nocpy_cfg_tx_disable (base_va_21(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = base_va_21(D) + 96;
  _6 = (volatile uint32_t *) _5;
  *_6 ={v} 4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = base_va_21(D) + 100;
  _8 = (volatile uint32_t *) _7;
  *_8 ={v} 3221782576;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = base_va_21(D) + 104;
  _10 = (volatile uint32_t *) _9;
  *_10 ={v} 3221815312;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = base_va_21(D) + 112;
  _12 = (volatile uint32_t *) _11;
  *_12 ={v} 3221749768;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = base_va_21(D) + 60;
  _14 = (volatile uint32_t *) _13;
  *_14 ={v} 67109888;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 = base_va_21(D) + 32;
  _16 = (volatile uint32_t *) _15;
  *_16 ={v} 2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = base_va_21(D) + 4;
  _18 = (volatile uint32_t *) _17;
  *_18 ={v} 2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = base_va_21(D) + 148;
  _20 = (volatile uint32_t *) _19;
  regval_34 ={v} *_20;
  # DEBUG regval => regval_34
  # DEBUG BEGIN_STMT
  regval_35 = regval_34 | 1;
  # DEBUG regval => regval_35
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_20 ={v} regval_35;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *_2 ={v} 4294967264;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hif_nocpy_cfg_tx_irq_unmask (pfe_hif_nocpy_cfg_tx_irq_unmask, funcdef_no=26, decl_uid=10033, cgraph_uid=27, symbol_order=29)

Modification phase of node pfe_hif_nocpy_cfg_tx_irq_unmask/29
pfe_hif_nocpy_cfg_tx_irq_unmask (addr_t base_va)
{
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 56;
  _2 = (volatile uint32_t *) _1;
  reg_6 ={v} *_2;
  # DEBUG reg => reg_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = reg_6 | 24;
  *_2 ={v} _3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_set_rx_bd_ring_addr (pfe_hif_nocpy_cfg_set_rx_bd_ring_addr, funcdef_no=27, decl_uid=10036, cgraph_uid=28, symbol_order=30)

Modification phase of node pfe_hif_nocpy_cfg_set_rx_bd_ring_addr/30
pfe_hif_nocpy_cfg_set_rx_bd_ring_addr (addr_t base_va, const void * rx_ring_pa)
{
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int rx_ring_pa.0_3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 36;
  _2 = (volatile uint32_t *) _1;
  rx_ring_pa.0_3 = (long unsigned int) rx_ring_pa_5(D);
  *_2 ={v} rx_ring_pa.0_3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_get_rx_bd_ring_addr (pfe_hif_nocpy_cfg_get_rx_bd_ring_addr, funcdef_no=28, decl_uid=10041, cgraph_uid=29, symbol_order=31)

Modification phase of node pfe_hif_nocpy_cfg_get_rx_bd_ring_addr/31
pfe_hif_nocpy_cfg_get_rx_bd_ring_addr (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  uint32_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 36;
  _2 = (volatile uint32_t *) _1;
  _5 ={v} *_2;
  return _5;

}



;; Function pfe_hif_nocpy_cfg_set_tx_bd_ring_addr (pfe_hif_nocpy_cfg_set_tx_bd_ring_addr, funcdef_no=29, decl_uid=10039, cgraph_uid=30, symbol_order=32)

Modification phase of node pfe_hif_nocpy_cfg_set_tx_bd_ring_addr/32
pfe_hif_nocpy_cfg_set_tx_bd_ring_addr (addr_t base_va, const void * tx_ring_pa)
{
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int tx_ring_pa.1_3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = base_va_4(D) + 16;
  _2 = (volatile uint32_t *) _1;
  tx_ring_pa.1_3 = (long unsigned int) tx_ring_pa_5(D);
  *_2 ={v} tx_ring_pa.1_3;
  # DEBUG BEGIN_STMT
  return;

}



;; Function pfe_hif_nocpy_cfg_get_tx_bd_ring_addr (pfe_hif_nocpy_cfg_get_tx_bd_ring_addr, funcdef_no=30, decl_uid=10043, cgraph_uid=31, symbol_order=33)

Modification phase of node pfe_hif_nocpy_cfg_get_tx_bd_ring_addr/33
pfe_hif_nocpy_cfg_get_tx_bd_ring_addr (addr_t base_va)
{
  unsigned int _1;
  volatile uint32_t * _2;
  uint32_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = base_va_3(D) + 16;
  _2 = (volatile uint32_t *) _1;
  _5 ={v} *_2;
  return _5;

}



;; Function pfe_hif_nocpy_cfg_is_rx_dma_active (pfe_hif_nocpy_cfg_is_rx_dma_active, funcdef_no=31, decl_uid=10045, cgraph_uid=32, symbol_order=34)

Modification phase of node pfe_hif_nocpy_cfg_is_rx_dma_active/34
pfe_hif_nocpy_cfg_is_rx_dma_active (addr_t base_va)
{
  bool_t ret;
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 48;
  _2 = (volatile uint32_t *) _1;
  reg_7 ={v} *_2;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  _3 = reg_7 & 3932160;
  if (_3 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1

  <bb 4> [local count: 1073741824]:
  # ret_4 = PHI <0(2), 1(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_hif_nocpy_cfg_is_tx_dma_active (pfe_hif_nocpy_cfg_is_tx_dma_active, funcdef_no=32, decl_uid=10047, cgraph_uid=33, symbol_order=35)

Modification phase of node pfe_hif_nocpy_cfg_is_tx_dma_active/35
pfe_hif_nocpy_cfg_is_tx_dma_active (addr_t base_va)
{
  bool_t ret;
  uint32_t reg;
  unsigned int _1;
  volatile uint32_t * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ret => 0
  # DEBUG BEGIN_STMT
  _1 = base_va_5(D) + 20;
  _2 = (volatile uint32_t *) _1;
  reg_7 ={v} *_2;
  # DEBUG reg => reg_7
  # DEBUG BEGIN_STMT
  _3 = reg_7 & 3932160;
  if (_3 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 1

  <bb 4> [local count: 1073741824]:
  # ret_4 = PHI <0(2), 1(3)>
  # DEBUG ret => ret_4
  # DEBUG BEGIN_STMT
  return ret_4;

}



;; Function pfe_hif_nocpy_chnl_cfg_get_text_stat (pfe_hif_nocpy_chnl_cfg_get_text_stat, funcdef_no=33, decl_uid=10052, cgraph_uid=34, symbol_order=36)

Modification phase of node pfe_hif_nocpy_chnl_cfg_get_text_stat/36
pfe_hif_nocpy_chnl_cfg_get_text_stat (addr_t base_va, const char_t * buf, uint32_t size, uint8_t verb_level)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pfe_hif_nocpy_cfg_get_tx_cnt (pfe_hif_nocpy_cfg_get_tx_cnt, funcdef_no=34, decl_uid=10054, cgraph_uid=35, symbol_order=37)

Modification phase of node pfe_hif_nocpy_cfg_get_tx_cnt/37
pfe_hif_nocpy_cfg_get_tx_cnt (addr_t base_va)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 4294967295;

}



;; Function pfe_hif_nocpy_cfg_get_rx_cnt (pfe_hif_nocpy_cfg_get_rx_cnt, funcdef_no=42, decl_uid=10056, cgraph_uid=36, symbol_order=38)

Modification phase of node pfe_hif_nocpy_cfg_get_rx_cnt/38
pfe_hif_nocpy_cfg_get_rx_cnt (addr_t base_va)
{
  uint32_t retval.32;

  <bb 2> [local count: 1073741824]:
  retval.32_2 = pfe_hif_nocpy_cfg_get_tx_cnt (base_va_1(D)); [tail call]
  return retval.32_2;

}



;; Function pfe_hif_nocpy_cfg_set_emac_timer_ownership (pfe_hif_nocpy_cfg_set_emac_timer_ownership, funcdef_no=36, decl_uid=10059, cgraph_uid=37, symbol_order=39)

Modification phase of node pfe_hif_nocpy_cfg_set_emac_timer_ownership/39
pfe_hif_nocpy_cfg_set_emac_timer_ownership (pfe_ct_phy_if_id_t emac, bool_t value)
{
  errno_t ret;
  unsigned int _1;
  unsigned int _2;
  unsigned char _3;
  unsigned char hif_nocpy_timer_ownership.2_4;
  unsigned char _5;
  unsigned int _6;
  unsigned int _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char hif_nocpy_timer_ownership.3_10;
  unsigned char _11;
  unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ret => 22
  # DEBUG BEGIN_STMT
  _15 = (unsigned int) emac_14(D);
  if (emac_14(D) <= 2)
    goto <bb 3>; [65.00%]
  else
    goto <bb 6>; [35.00%]

  <bb 3> [local count: 697932186]:
<L0>:
  # DEBUG BEGIN_STMT
  # DEBUG emac_idx => emac_14(D)
  # DEBUG BEGIN_STMT
  if (value_16(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 348966093]:
  # DEBUG BEGIN_STMT
  _1 = _15 + 4;
  _2 = 1 << _1;
  _3 = (unsigned char) _2;
  hif_nocpy_timer_ownership.2_4 = hif_nocpy_timer_ownership;
  _5 = _3 | hif_nocpy_timer_ownership.2_4;
  hif_nocpy_timer_ownership = _5;
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 348966093]:
  # DEBUG BEGIN_STMT
  _6 = _15 + 4;
  _7 = 1 << _6;
  _8 = (unsigned char) _7;
  _9 = ~_8;
  hif_nocpy_timer_ownership.3_10 = hif_nocpy_timer_ownership;
  _11 = _9 & hif_nocpy_timer_ownership.3_10;
  hif_nocpy_timer_ownership = _11;

  <bb 6> [local count: 1073741824]:
  # ret_12 = PHI <0(5), 22(2), 0(4)>
  # DEBUG ret => ret_12
  # DEBUG BEGIN_STMT
  return ret_12;

}



;; Function pfe_hif_nocpy_cfg_get_emac_timer_ownership (pfe_hif_nocpy_cfg_get_emac_timer_ownership, funcdef_no=37, decl_uid=10061, cgraph_uid=38, symbol_order=40)

Modification phase of node pfe_hif_nocpy_cfg_get_emac_timer_ownership/40
pfe_hif_nocpy_cfg_get_emac_timer_ownership (pfe_ct_phy_if_id_t emac)
{
  bool_t val;
  unsigned char hif_nocpy_timer_ownership.4_1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  _Bool _5;
  unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG val => 0
  # DEBUG BEGIN_STMT
  _8 = (unsigned int) emac_7(D);
  if (emac_7(D) <= 2)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
<L0>:
  # DEBUG BEGIN_STMT
  # DEBUG emac_idx => emac_7(D)
  # DEBUG BEGIN_STMT
  hif_nocpy_timer_ownership.4_1 = hif_nocpy_timer_ownership;
  _2 = (unsigned int) hif_nocpy_timer_ownership.4_1;
  _3 = _8 + 4;
  _4 = _2 >> _3;
  _5 = (_Bool) _4;
  val_10 = (bool_t) _5;
  # DEBUG val => val_10
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # val_6 = PHI <val_10(3), 0(2)>
  # DEBUG val => val_6
  # DEBUG BEGIN_STMT
  return val_6;

}



;; Function pfe_hif_nocpy_cfg_stop_all_chnl_dma (pfe_hif_nocpy_cfg_stop_all_chnl_dma, funcdef_no=38, decl_uid=10063, cgraph_uid=39, symbol_order=41)

Modification phase of node pfe_hif_nocpy_cfg_stop_all_chnl_dma/41
pfe_hif_nocpy_cfg_stop_all_chnl_dma ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)1175257092B] ={v} 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(volatile uint32_t *)1175257120B] ={v} 0;
  # DEBUG BEGIN_STMT
  return;

}


