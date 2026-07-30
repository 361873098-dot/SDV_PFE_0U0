
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pfe_minihif_drv_start_tx/24:
  Jump functions of caller  pfe_minihif_drv_start_rx/23:
  Jump functions of caller  pfe_minihif_drv_init/22:
  Jump functions of caller  pfe_minihif_drv_attach_ring/21:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/20:
  Jump functions of caller  pfe_hm_report/19:
  Jump functions of caller  pfe_minihif_drv_create/18:
  Jump functions of caller  configure_minihif_hw/17:

 Propagating constants:

Not considering configure_minihif_hw for cloning; -fipa-cp-clone disabled.

overall_size: 88, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: configure_minihif_hw/17:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pfe_minihif_drv_start_tx/24 (pfe_minihif_drv_start_tx) @07730000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: configure_minihif_hw/17 (99587954 (estimated locally),0.09 per call) 
  Calls: 
pfe_minihif_drv_start_rx/23 (pfe_minihif_drv_start_rx) @07715ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: configure_minihif_hw/17 (150890839 (estimated locally),0.14 per call) 
  Calls: 
pfe_minihif_drv_init/22 (pfe_minihif_drv_init) @07715e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: configure_minihif_hw/17 (228622484 (estimated locally),0.21 per call) 
  Calls: 
pfe_minihif_drv_attach_ring/21 (pfe_minihif_drv_attach_ring) @07715d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: configure_minihif_hw/17 (467721939 (estimated locally),0.44 per call) configure_minihif_hw/17 (708669605 (estimated locally),0.66 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/20 (oal_util_raise_dem_for_drv_runtime_err) @07715c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: configure_minihif_hw/17 (20156602 (estimated locally),0.02 per call) configure_minihif_hw/17 (51302885 (estimated locally),0.05 per call) configure_minihif_hw/17 (77731644 (estimated locally),0.07 per call) configure_minihif_hw/17 (480047121 (estimated locally),0.45 per call) configure_minihif_hw/17 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_hm_report/19 (pfe_hm_report) @07715b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: configure_minihif_hw/17 (20156602 (estimated locally),0.02 per call) configure_minihif_hw/17 (51302885 (estimated locally),0.05 per call) configure_minihif_hw/17 (77731644 (estimated locally),0.07 per call) configure_minihif_hw/17 (480047121 (estimated locally),0.45 per call) configure_minihif_hw/17 (365072220 (estimated locally),0.34 per call) 
  Calls: 
pfe_minihif_drv_create/18 (pfe_minihif_drv_create) @07715a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: configure_minihif_hw/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
configure_minihif_hw/17 (configure_minihif_hw) @07715620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: minihif/16 (addr)minihif/16 (addr)minihif/16 (addr)minihif/16 (addr)minihif/16 (addr)minihif/16 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: oal_util_raise_dem_for_drv_runtime_err/20 (20156602 (estimated locally),0.02 per call) pfe_hm_report/19 (20156602 (estimated locally),0.02 per call) pfe_minihif_drv_start_tx/24 (99587954 (estimated locally),0.09 per call) oal_util_raise_dem_for_drv_runtime_err/20 (51302885 (estimated locally),0.05 per call) pfe_hm_report/19 (51302885 (estimated locally),0.05 per call) pfe_minihif_drv_start_rx/23 (150890839 (estimated locally),0.14 per call) oal_util_raise_dem_for_drv_runtime_err/20 (77731644 (estimated locally),0.07 per call) pfe_hm_report/19 (77731644 (estimated locally),0.07 per call) pfe_minihif_drv_init/22 (228622484 (estimated locally),0.21 per call) oal_util_raise_dem_for_drv_runtime_err/20 (480047121 (estimated locally),0.45 per call) pfe_hm_report/19 (480047121 (estimated locally),0.45 per call) pfe_minihif_drv_attach_ring/21 (467721939 (estimated locally),0.44 per call) pfe_minihif_drv_attach_ring/21 (708669605 (estimated locally),0.66 per call) oal_util_raise_dem_for_drv_runtime_err/20 (365072220 (estimated locally),0.34 per call) pfe_hm_report/19 (365072220 (estimated locally),0.34 per call) pfe_minihif_drv_create/18 (1073741824 (estimated locally),1.00 per call) 
minihif/16 (minihif) @07714048
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: configure_minihif_hw/17 (addr)configure_minihif_hw/17 (addr)configure_minihif_hw/17 (addr)configure_minihif_hw/17 (addr)configure_minihif_hw/17 (addr)configure_minihif_hw/17 (addr)
  Availability: available
  Varpool flags: initialized

;; Function configure_minihif_hw (configure_minihif_hw, funcdef_no=13, decl_uid=10977, cgraph_uid=14, symbol_order=17)

Modification phase of node configure_minihif_hw/17
configure_minihif_hw ()
{
  int _1;
  int _2;
  int _3;
  int _4;
  int _5;
  int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pfe_minihif_drv_create (&minihif, 9, 0);
  if (_1 != 0)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Minihifs creation failed\n", "src/minihif_hw_conf.c", 73, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 4> [local count: 708669605]:
  # DEBUG BEGIN_STMT
  _2 = pfe_minihif_drv_attach_ring (&minihif, 1, 873529344B, 873537536B, 104);
  if (_2 != 0)
    goto <bb 6>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 467721939]:
  _3 = pfe_minihif_drv_attach_ring (&minihif, 0, 873533440B, 873539584B, 16);
  if (_3 != 0)
    goto <bb 6>; [51.12%]
  else
    goto <bb 7>; [48.88%]

  <bb 6> [local count: 480047121]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] MINIHIF - fixed buffers configuration failed\n", "src/minihif_hw_conf.c", 81, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 228622484]:
  # DEBUG BEGIN_STMT
  _4 = pfe_minihif_drv_init (&minihif);
  if (_4 != 0)
    goto <bb 8>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 8> [local count: 77731644]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] minihif_drv_init failed\n", "src/minihif_hw_conf.c", 87, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 150890839]:
  # DEBUG BEGIN_STMT
  _5 = pfe_minihif_drv_start_rx (&minihif);
  if (_5 != 0)
    goto <bb 10>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 10> [local count: 51302885]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF driver reception start failed\n", "src/minihif_hw_conf.c", 92, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 99587954]:
  # DEBUG BEGIN_STMT
  _6 = pfe_minihif_drv_start_tx (&minihif);
  if (_6 != 0)
    goto <bb 12>; [20.24%]
  else
    goto <bb 13>; [79.76%]

  <bb 12> [local count: 20156602]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] HIF driver transmission start failed\n", "src/minihif_hw_conf.c", 97, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  return;

}


