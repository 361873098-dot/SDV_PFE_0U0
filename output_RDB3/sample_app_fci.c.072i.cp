
IPA constant propagation start:
Determining dynamic type for call: sample_fci_phy_if_print_all (cl_14);
  Starting walk at: sample_fci_phy_if_print_all (cl_14);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_log_if_print_all (cl_14);
  Starting walk at: sample_fci_log_if_print_all (cl_14);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Starting walk at: _3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Starting walk at: _3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  instance pointer: "emac1"  Outer instance pointer: "emac1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Starting walk at: _4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Starting walk at: _4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  instance pointer: "emac2"  Outer instance pointer: "emac2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Starting walk at: _5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Starting walk at: _5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  instance pointer: "hif0"  Outer instance pointer: "hif0" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Starting walk at: _6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Starting walk at: _6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  instance pointer: "hif1"  Outer instance pointer: "hif1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Starting walk at: _7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Starting walk at: _7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  instance pointer: "hif2"  Outer instance pointer: "hif2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Starting walk at: _8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Starting walk at: _8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  instance pointer: "hif3"  Outer instance pointer: "hif3" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Starting walk at: _9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  instance pointer: "emac1"  Outer instance pointer: "emac1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  instance pointer: "emac2"  Outer instance pointer: "emac2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  instance pointer: "hif0"  Outer instance pointer: "hif0" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  instance pointer: "hif1"  Outer instance pointer: "hif1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  instance pointer: "hif2"  Outer instance pointer: "hif2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Starting walk at: sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  instance pointer: "hif3"  Outer instance pointer: "hif3" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "emac1");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "emac1");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "emac1");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "emac1");
  instance pointer: "emac1"  Outer instance pointer: "emac1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "emac2");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "emac2");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "emac2");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "emac2");
  instance pointer: "emac2"  Outer instance pointer: "emac2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif0");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif0");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif0");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif0");
  instance pointer: "hif0"  Outer instance pointer: "hif0" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif1");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif1");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif1");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif1");
  instance pointer: "hif1"  Outer instance pointer: "hif1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif2");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif2");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif2");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif2");
  instance pointer: "hif2"  Outer instance pointer: "hif2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif3");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif3");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_enable (cl_14, "hif3");
  Starting walk at: sample_fci_phy_if_enable (cl_14, "hif3");
  instance pointer: "hif3"  Outer instance pointer: "hif3" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "emac1");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "emac1");
  instance pointer: "emac1"  Outer instance pointer: "emac1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "emac2");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "emac2");
  instance pointer: "emac2"  Outer instance pointer: "emac2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif0");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif0");
  instance pointer: "hif0"  Outer instance pointer: "hif0" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif1");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif1");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif1");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif1");
  instance pointer: "hif1"  Outer instance pointer: "hif1" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif2");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif2");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif2");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif2");
  instance pointer: "hif2"  Outer instance pointer: "hif2" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif3");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif3");
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_promisc_on (cl_14, "hif3");
  Starting walk at: sample_fci_phy_if_promisc_on (cl_14, "hif3");
  instance pointer: "hif3"  Outer instance pointer: "hif3" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = sample_fci_bd_get (cl_14, 1, &bd);
  Starting walk at: _10 = sample_fci_bd_get (cl_14, 1, &bd);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _10 = sample_fci_bd_get (cl_14, 1, &bd);
  Starting walk at: _10 = sample_fci_bd_get (cl_14, 1, &bd);
  instance pointer: &bd  Outer instance pointer: bd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: sample_fci_phy_if_print_all (cl_14);
  Starting walk at: sample_fci_phy_if_print_all (cl_14);
  instance pointer: cl_14  Outer instance pointer: cl_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_10 = sample_fci_bd_get (cl_14, 1, &bd);
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_promisc_on (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif3");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif1");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "hif0");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac2");
  Function call may change dynamic type:sample_fci_phy_if_enable (cl_14, "emac1");
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  Function call may change dynamic type:sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  Function call may change dynamic type:_9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  Function call may change dynamic type:_8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  Function call may change dynamic type:_7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  Function call may change dynamic type:_6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  Function call may change dynamic type:_5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  Function call may change dynamic type:_4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  Function call may change dynamic type:_3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  Function call may change dynamic type:sample_fci_log_if_print_all (cl_14);
  Function call may change dynamic type:sample_fci_phy_if_print_all (cl_14);
  Function call may change dynamic type:_1 = fci_register_cb (cl_14, sample_fci_callback);
  Function call may change dynamic type:cl_14 = fci_open (0, 0);
Determining dynamic type for call: _1 = sample_fci_bd_get (cl_5(D), vlan_6(D), &bd);
  Starting walk at: _1 = sample_fci_bd_get (cl_5(D), vlan_6(D), &bd);
  instance pointer: cl_5(D)  Outer instance pointer: cl_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_bd_get (cl_5(D), vlan_6(D), &bd);
  Starting walk at: _1 = sample_fci_bd_get (cl_5(D), vlan_6(D), &bd);
  instance pointer: &bd  Outer instance pointer: bd offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: if_id_27 = sample_fci_phy_if_get_id (cl_24(D), phy_if_25(D));
  Starting walk at: if_id_27 = sample_fci_phy_if_get_id (cl_24(D), phy_if_25(D));
  instance pointer: cl_24(D)  Outer instance pointer: cl_24(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: if_id_27 = sample_fci_phy_if_get_id (cl_24(D), phy_if_25(D));
  Starting walk at: if_id_27 = sample_fci_phy_if_get_id (cl_24(D), phy_if_25(D));
  instance pointer: phy_if_25(D)  Outer instance pointer: phy_if_25(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_bd_get (cl_24(D), vlan_28(D), &bd);
  Starting walk at: _1 = sample_fci_bd_get (cl_24(D), vlan_28(D), &bd);
  instance pointer: cl_24(D)  Outer instance pointer: cl_24(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:if_id_27 = sample_fci_phy_if_get_id (cl_24(D), phy_if_25(D));
Determining dynamic type for call: _1 = sample_fci_bd_get (cl_24(D), vlan_28(D), &bd);
  Starting walk at: _1 = sample_fci_bd_get (cl_24(D), vlan_28(D), &bd);
  instance pointer: &bd  Outer instance pointer: bd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:if_id_27 = sample_fci_phy_if_get_id (cl_24(D), phy_if_25(D));
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  instance pointer: cl_11(D)  Outer instance pointer: cl_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  instance pointer: name_12(D)  Outer instance pointer: name_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  instance pointer: &cmd  Outer instance pointer: cmd offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_15(D), name_16(D), &rep);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_15(D), name_16(D), &rep);
  instance pointer: cl_15(D)  Outer instance pointer: cl_15(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_15(D), name_16(D), &rep);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_15(D), name_16(D), &rep);
  instance pointer: name_16(D)  Outer instance pointer: name_16(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_15(D), name_16(D), &rep);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_15(D), name_16(D), &rep);
  instance pointer: &rep  Outer instance pointer: rep offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_5(D), name_6(D), &rep);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_5(D), name_6(D), &rep);
  instance pointer: cl_5(D)  Outer instance pointer: cl_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_5(D), name_6(D), &rep);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_5(D), name_6(D), &rep);
  instance pointer: name_6(D)  Outer instance pointer: name_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_5(D), name_6(D), &rep);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_5(D), name_6(D), &rep);
  instance pointer: &rep  Outer instance pointer: rep offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  instance pointer: cl_11(D)  Outer instance pointer: cl_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  instance pointer: name_12(D)  Outer instance pointer: name_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  Starting walk at: _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  instance pointer: &cmd  Outer instance pointer: cmd offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  autolibc_memcpy/21:
  Jump functions of caller  autolibc_strcmp/20:
  Jump functions of caller  fci_query/19:
  Jump functions of caller  fci_write/18:
  Jump functions of caller  fci_register_cb/17:
  Jump functions of caller  oal_util_raise_dem_for_drv_runtime_err/16:
  Jump functions of caller  pfe_hm_report/15:
  Jump functions of caller  fci_open/14:
  Jump functions of caller  SampleAppFciTestTask/13:
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_print_all/3 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_get/10 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_promisc_on/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif3"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_promisc_on/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_promisc_on/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_promisc_on/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif0"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_promisc_on/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "emac2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_promisc_on/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "emac1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_enable/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif3"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_enable/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_enable/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_enable/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif0"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_enable/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "emac2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_enable/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "emac1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_set_mode/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif3"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_set_mode/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_set_mode/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_set_mode/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "hif0"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_set_mode/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "emac2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_set_mode/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "emac1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_set_policy/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_add_if/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: "hif3"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_add_if/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: "hif2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_add_if/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: "hif1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_add_if/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: "hif0"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_add_if/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: "emac2"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_bd_add_if/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: "emac1"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_log_if_print_all/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  SampleAppFciTestTask/13 -> sample_fci_phy_if_print_all/3 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  sample_fci_bd_set_policy/12:
    callsite  sample_fci_bd_set_policy/12 -> sample_fci_bd_get/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  sample_fci_bd_add_if/11:
    callsite  sample_fci_bd_add_if/11 -> sample_fci_bd_get/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  sample_fci_bd_add_if/11 -> sample_fci_phy_if_get_id/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  sample_fci_bd_get/10:
  Jump functions of caller  sample_fci_phy_if_promisc_on/8:
    callsite  sample_fci_phy_if_promisc_on/8 -> sample_fci_phy_if_get_by_name/4 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  sample_fci_phy_if_get_id/7:
    callsite  sample_fci_phy_if_get_id/7 -> sample_fci_phy_if_get_by_name/4 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  sample_fci_phy_if_set_mode/6:
    callsite  sample_fci_phy_if_set_mode/6 -> sample_fci_phy_if_get_by_name/4 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  sample_fci_phy_if_enable/5:
    callsite  sample_fci_phy_if_enable/5 -> sample_fci_phy_if_get_by_name/4 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  sample_fci_phy_if_get_by_name/4:
  Jump functions of caller  sample_fci_phy_if_print_all/3:
  Jump functions of caller  sample_fci_log_if_print_all/2:
  Jump functions of caller  sample_fci_callback/1:

 Propagating constants:

Not considering SampleAppFciTestTask for cloning; -fipa-cp-clone disabled.
Not considering sample_fci_callback for cloning; -fipa-cp-clone disabled.

overall_size: 841, max_new_size: 11001
 - context independent values, size: 37, time_benefit: 5.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 57, time_benefit: 3.174705
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 25, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 70, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 3, time_benefit: 3.000000

IPA lattices after all propagation:

Lattices:
  Node: SampleAppFciTestTask/13:
  Node: sample_fci_bd_set_policy/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint16 [1, 1]
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
    param [3]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint8 [1, 1]
        AGGS VARIABLE
    param [4]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         uint8 [0, 0]
        AGGS VARIABLE
    param [5]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint8 [1, 1]
        AGGS VARIABLE
  Node: sample_fci_bd_add_if/11:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint16 [1, 1]
        AGGS VARIABLE
    param [2]: "emac1" [loc_time: 4, loc_size: 69, prop_time: 0, prop_size: 0]
               "emac2" [loc_time: 4, loc_size: 69, prop_time: 0, prop_size: 0]
               "hif0" [loc_time: 4, loc_size: 69, prop_time: 0, prop_size: 0]
               "hif1" [loc_time: 4, loc_size: 69, prop_time: 0, prop_size: 0]
               "hif2" [loc_time: 4, loc_size: 69, prop_time: 0, prop_size: 0]
               "hif3" [loc_time: 4, loc_size: 69, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         char * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         bool_t [0, 0]
        AGGS VARIABLE
  Node: sample_fci_bd_get/10:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         uint16 [1, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_l2_bd_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: sample_fci_phy_if_promisc_on/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: "emac1" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "emac2" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif0" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif1" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif2" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif3" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         char * ~[0B, 0B]
        AGGS VARIABLE
  Node: sample_fci_phy_if_get_id/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: "hif3" [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
               "hif2" [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
               "hif1" [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
               "hif0" [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
               "emac2" [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
               "emac1" [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         char * ~[0B, 0B]
        AGGS VARIABLE
  Node: sample_fci_phy_if_set_mode/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: "emac1" [loc_time: 2, loc_size: 76, prop_time: 0, prop_size: 0]
               "emac2" [loc_time: 2, loc_size: 76, prop_time: 0, prop_size: 0]
               "hif0" [loc_time: 2, loc_size: 76, prop_time: 0, prop_size: 0]
               "hif1" [loc_time: 2, loc_size: 76, prop_time: 0, prop_size: 0]
               "hif2" [loc_time: 2, loc_size: 76, prop_time: 0, prop_size: 0]
               "hif3" [loc_time: 2, loc_size: 76, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         char * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         fpp_phy_if_op_mode_t [1, 1]
        AGGS VARIABLE
  Node: sample_fci_phy_if_enable/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: "emac1" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "emac2" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif0" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif1" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif2" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif3" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         char * ~[0B, 0B]
        AGGS VARIABLE
  Node: sample_fci_phy_if_get_by_name/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: "hif3" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif2" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif1" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "hif0" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "emac2" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
               "emac1" [loc_time: 1, loc_size: 77, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         char * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct fpp_phy_if_cmd_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: sample_fci_phy_if_print_all/3:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: sample_fci_log_if_print_all/2:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: sample_fci_callback/1:
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

 - Creating a specialized node of sample_fci_bd_set_policy/12 for all known contexts.
    replacing param #1 vlan with const 1
    replacing param #2 uh with const 0
    replacing param #3 um with const 1
    replacing param #4 mh with const 0
    replacing param #5 mm with const 1
 - Creating a specialized node of sample_fci_bd_add_if/11 for all known contexts.
    replacing param #1 vlan with const 1
    replacing param #3 tag with const 0
 - Creating a specialized node of sample_fci_bd_get/10 for all known contexts.
    replacing param #1 vlan with const 1
 - Creating a specialized node of sample_fci_phy_if_set_mode/6 for all known contexts.
    replacing param #2 mode with const 1
Propagated bits info for function sample_fci_phy_if_set_mode.constprop/25:
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function sample_fci_bd_get.constprop/24:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function sample_fci_bd_add_if.constprop/23:
 param 1: value = 0x1, mask = 0x0
 param 3: value = 0x0, mask = 0x0
Propagated bits info for function sample_fci_bd_set_policy.constprop/22:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x0, mask = 0x0
 param 3: value = 0x1, mask = 0x0
 param 4: value = 0x0, mask = 0x0
 param 5: value = 0x1, mask = 0x0
Propagated bits info for function sample_fci_bd_set_policy/12:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x0, mask = 0x0
 param 3: value = 0x1, mask = 0x0
 param 4: value = 0x0, mask = 0x0
 param 5: value = 0x1, mask = 0x0
Propagated bits info for function sample_fci_bd_add_if/11:
 param 1: value = 0x1, mask = 0x0
 param 3: value = 0x0, mask = 0x0
Propagated bits info for function sample_fci_bd_get/10:
 param 1: value = 0x1, mask = 0x0
 param 2: value = 0x0, mask = 0xfffffffc
Propagated bits info for function sample_fci_phy_if_set_mode/6:
 param 2: value = 0x1, mask = 0x0
Propagated bits info for function sample_fci_phy_if_get_by_name/4:
 param 2: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: sample_fci_bd_set_policy/12 sample_fci_bd_add_if/11 sample_fci_bd_get/10 sample_fci_phy_if_set_mode/6
Reclaiming variables:
Clearing address taken flags:
Symbol table:

sample_fci_phy_if_set_mode.constprop.0/25 (sample_fci_phy_if_set_mode.constprop) @0728a8c0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of sample_fci_phy_if_set_mode/6
  Availability: local
  Function flags: count:1073741823 (estimated locally) local optimize_size
  Called by: SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) 
  Calls: sample_fci_phy_if_get_by_name/4 (1073741823 (estimated locally),1.00 per call) fci_write/18 (536870911 (estimated locally),0.50 per call) pfe_hm_report/15 (268435456 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/16 (268435456 (estimated locally),0.25 per call) fci_write/18 (268435456 (estimated locally),0.25 per call) pfe_hm_report/15 (88583700 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/16 (88583700 (estimated locally),0.08 per call) fci_write/18 (268435456 (estimated locally),0.25 per call) pfe_hm_report/15 (88583700 (estimated locally),0.08 per call) oal_util_raise_dem_for_drv_runtime_err/16 (88583700 (estimated locally),0.08 per call) pfe_hm_report/15 (536870911 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (536870911 (estimated locally),0.50 per call) 
sample_fci_bd_get.constprop.0/24 (sample_fci_bd_get.constprop) @0728a700
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of sample_fci_bd_get/10
  Availability: local
  Function flags: count:114863532 (estimated locally) local optimize_size
  Called by: SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) sample_fci_bd_set_policy.constprop/22 (1073741824 (estimated locally),1.00 per call) sample_fci_bd_add_if.constprop/23 (790703480 (estimated locally),0.74 per call) 
  Calls: fci_query/19 (114863532 (estimated locally),1.00 per call) fci_query/19 (958878293 (estimated locally),8.35 per call) 
sample_fci_bd_add_if.constprop.0/23 (sample_fci_bd_add_if.constprop) @070e7620
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of sample_fci_bd_add_if/11
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: SampleAppFciTestTask/13 (580471273 (estimated locally),0.54 per call) SampleAppFciTestTask/13 (383111040 (estimated locally),0.36 per call) SampleAppFciTestTask/13 (252853286 (estimated locally),0.24 per call) SampleAppFciTestTask/13 (166883169 (estimated locally),0.16 per call) SampleAppFciTestTask/13 (110142891 (estimated locally),0.10 per call) SampleAppFciTestTask/13 (72694308 (estimated locally),0.07 per call) 
  Calls: sample_fci_phy_if_get_id/7 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/15 (283038345 (estimated locally),0.26 per call) oal_util_raise_dem_for_drv_runtime_err/16 (283038345 (estimated locally),0.26 per call) sample_fci_bd_get.constprop/24 (790703480 (estimated locally),0.74 per call) pfe_hm_report/15 (160038384 (estimated locally),0.15 per call) oal_util_raise_dem_for_drv_runtime_err/16 (160038384 (estimated locally),0.15 per call) fci_write/18 (630665096 (estimated locally),0.59 per call) pfe_hm_report/15 (127646615 (estimated locally),0.12 per call) oal_util_raise_dem_for_drv_runtime_err/16 (127646615 (estimated locally),0.12 per call) 
sample_fci_bd_set_policy.constprop.0/22 (sample_fci_bd_set_policy.constprop) @06ea0540
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of sample_fci_bd_set_policy/12
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: SampleAppFciTestTask/13 (47978243 (estimated locally),0.04 per call) 
  Calls: sample_fci_bd_get.constprop/24 (1073741824 (estimated locally),1.00 per call) pfe_hm_report/15 (365072220 (estimated locally),0.34 per call) oal_util_raise_dem_for_drv_runtime_err/16 (365072220 (estimated locally),0.34 per call) fci_write/18 (708669605 (estimated locally),0.66 per call) pfe_hm_report/15 (143434728 (estimated locally),0.13 per call) oal_util_raise_dem_for_drv_runtime_err/16 (143434728 (estimated locally),0.13 per call) 
autolibc_memcpy/21 (autolibc_memcpy) @07107b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sample_fci_phy_if_get_by_name/4 (55807731 (estimated locally),0.24 per call) 
  Calls: 
autolibc_strcmp/20 (autolibc_strcmp) @07107a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sample_fci_phy_if_get_by_name/4 (1014686025 (estimated locally),4.42 per call) 
  Calls: 
fci_query/19 (fci_query) @07107700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sample_fci_bd_get.constprop/24 (114863532 (estimated locally),1.00 per call) sample_fci_bd_get.constprop/24 (958878293 (estimated locally),8.35 per call) sample_fci_phy_if_get_by_name/4 (958878293 (estimated locally),4.17 per call) sample_fci_phy_if_get_by_name/4 (114863532 (estimated locally),0.50 per call) sample_fci_phy_if_print_all/3 (955630223 (estimated locally),4.05 per call) sample_fci_phy_if_print_all/3 (118111600 (estimated locally),0.50 per call) sample_fci_log_if_print_all/2 (955630223 (estimated locally),4.05 per call) sample_fci_log_if_print_all/2 (118111600 (estimated locally),0.50 per call) 
  Calls: 
fci_write/18 (fci_write) @07107620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sample_fci_phy_if_set_mode.constprop/25 (536870911 (estimated locally),0.50 per call) sample_fci_phy_if_set_mode.constprop/25 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_set_mode.constprop/25 (268435456 (estimated locally),0.25 per call) sample_fci_bd_add_if.constprop/23 (630665096 (estimated locally),0.59 per call) sample_fci_bd_set_policy.constprop/22 (708669605 (estimated locally),0.66 per call) sample_fci_phy_if_promisc_on/8 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_promisc_on/8 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_promisc_on/8 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_enable/5 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_enable/5 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_enable/5 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_get_by_name/4 (114863532 (estimated locally),0.50 per call) sample_fci_phy_if_get_by_name/4 (229727064 (estimated locally),1.00 per call) sample_fci_phy_if_print_all/3 (236223201 (estimated locally),1.00 per call) sample_fci_phy_if_print_all/3 (236223200 (estimated locally),1.00 per call) sample_fci_log_if_print_all/2 (118111601 (estimated locally),0.50 per call) sample_fci_log_if_print_all/2 (236223200 (estimated locally),1.00 per call) 
  Calls: 
fci_register_cb/17 (fci_register_cb) @07107380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SampleAppFciTestTask/13 (879501929 (estimated locally),0.82 per call) 
  Calls: 
oal_util_raise_dem_for_drv_runtime_err/16 (oal_util_raise_dem_for_drv_runtime_err) @071072a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sample_fci_phy_if_set_mode.constprop/25 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_set_mode.constprop/25 (88583700 (estimated locally),0.08 per call) sample_fci_phy_if_set_mode.constprop/25 (88583700 (estimated locally),0.08 per call) sample_fci_phy_if_set_mode.constprop/25 (536870911 (estimated locally),0.50 per call) sample_fci_bd_add_if.constprop/23 (283038345 (estimated locally),0.26 per call) sample_fci_bd_add_if.constprop/23 (160038384 (estimated locally),0.15 per call) sample_fci_bd_add_if.constprop/23 (127646615 (estimated locally),0.12 per call) sample_fci_bd_set_policy.constprop/22 (365072220 (estimated locally),0.34 per call) sample_fci_bd_set_policy.constprop/22 (143434728 (estimated locally),0.13 per call) SampleAppFciTestTask/13 (10766318 (estimated locally),0.01 per call) SampleAppFciTestTask/13 (16312603 (estimated locally),0.02 per call) SampleAppFciTestTask/13 (24716065 (estimated locally),0.02 per call) SampleAppFciTestTask/13 (37448583 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (56740277 (estimated locally),0.05 per call) SampleAppFciTestTask/13 (85970117 (estimated locally),0.08 per call) SampleAppFciTestTask/13 (130257754 (estimated locally),0.12 per call) SampleAppFciTestTask/13 (197360233 (estimated locally),0.18 per call) SampleAppFciTestTask/13 (299030656 (estimated locally),0.28 per call) SampleAppFciTestTask/13 (194239896 (estimated locally),0.18 per call) sample_fci_phy_if_promisc_on/8 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_promisc_on/8 (177167401 (estimated locally),0.17 per call) sample_fci_phy_if_promisc_on/8 (88583701 (estimated locally),0.08 per call) sample_fci_phy_if_promisc_on/8 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_enable/5 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_enable/5 (177167401 (estimated locally),0.17 per call) sample_fci_phy_if_enable/5 (88583701 (estimated locally),0.08 per call) sample_fci_phy_if_enable/5 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_get_by_name/4 (37904965 (estimated locally),0.16 per call) sample_fci_phy_if_get_by_name/4 (114863532 (estimated locally),0.50 per call) sample_fci_phy_if_print_all/3 (77953656 (estimated locally),0.33 per call) sample_fci_phy_if_print_all/3 (118111600 (estimated locally),0.50 per call) sample_fci_log_if_print_all/2 (38976828 (estimated locally),0.17 per call) sample_fci_log_if_print_all/2 (118111600 (estimated locally),0.50 per call) 
  Calls: 
pfe_hm_report/15 (pfe_hm_report) @071071c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sample_fci_phy_if_set_mode.constprop/25 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_set_mode.constprop/25 (88583700 (estimated locally),0.08 per call) sample_fci_phy_if_set_mode.constprop/25 (88583700 (estimated locally),0.08 per call) sample_fci_phy_if_set_mode.constprop/25 (536870911 (estimated locally),0.50 per call) sample_fci_bd_add_if.constprop/23 (283038345 (estimated locally),0.26 per call) sample_fci_bd_add_if.constprop/23 (160038384 (estimated locally),0.15 per call) sample_fci_bd_add_if.constprop/23 (127646615 (estimated locally),0.12 per call) sample_fci_bd_set_policy.constprop/22 (365072220 (estimated locally),0.34 per call) sample_fci_bd_set_policy.constprop/22 (143434728 (estimated locally),0.13 per call) SampleAppFciTestTask/13 (10766318 (estimated locally),0.01 per call) SampleAppFciTestTask/13 (16312603 (estimated locally),0.02 per call) SampleAppFciTestTask/13 (24716065 (estimated locally),0.02 per call) SampleAppFciTestTask/13 (37448583 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (56740277 (estimated locally),0.05 per call) SampleAppFciTestTask/13 (85970117 (estimated locally),0.08 per call) SampleAppFciTestTask/13 (130257754 (estimated locally),0.12 per call) SampleAppFciTestTask/13 (197360233 (estimated locally),0.18 per call) SampleAppFciTestTask/13 (299030656 (estimated locally),0.28 per call) SampleAppFciTestTask/13 (194239896 (estimated locally),0.18 per call) sample_fci_phy_if_promisc_on/8 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_promisc_on/8 (177167401 (estimated locally),0.17 per call) sample_fci_phy_if_promisc_on/8 (88583701 (estimated locally),0.08 per call) sample_fci_phy_if_promisc_on/8 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_enable/5 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_enable/5 (177167401 (estimated locally),0.17 per call) sample_fci_phy_if_enable/5 (88583701 (estimated locally),0.08 per call) sample_fci_phy_if_enable/5 (268435456 (estimated locally),0.25 per call) sample_fci_phy_if_get_by_name/4 (37904965 (estimated locally),0.16 per call) sample_fci_phy_if_get_by_name/4 (114863532 (estimated locally),0.50 per call) sample_fci_phy_if_print_all/3 (77953656 (estimated locally),0.33 per call) sample_fci_phy_if_print_all/3 (118111600 (estimated locally),0.50 per call) sample_fci_log_if_print_all/2 (38976828 (estimated locally),0.17 per call) sample_fci_log_if_print_all/2 (118111600 (estimated locally),0.50 per call) 
  Calls: 
fci_open/14 (fci_open) @071070e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: SampleAppFciTestTask/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SampleAppFciTestTask/13 (SampleAppFciTestTask) @070f5b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sample_fci_callback/1 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: sample_fci_phy_if_print_all/3 (20899323 (estimated locally),0.02 per call) oal_util_raise_dem_for_drv_runtime_err/16 (10766318 (estimated locally),0.01 per call) pfe_hm_report/15 (10766318 (estimated locally),0.01 per call) sample_fci_bd_get.constprop/24 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_promisc_on/8 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_promisc_on/8 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_promisc_on/8 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_promisc_on/8 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_promisc_on/8 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_promisc_on/8 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_enable/5 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_enable/5 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_enable/5 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_enable/5 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_enable/5 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_enable/5 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_set_mode.constprop/25 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_set_mode.constprop/25 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_set_mode.constprop/25 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_set_mode.constprop/25 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_set_mode.constprop/25 (31665641 (estimated locally),0.03 per call) sample_fci_phy_if_set_mode.constprop/25 (31665641 (estimated locally),0.03 per call) oal_util_raise_dem_for_drv_runtime_err/16 (16312603 (estimated locally),0.02 per call) pfe_hm_report/15 (16312603 (estimated locally),0.02 per call) sample_fci_bd_set_policy.constprop/22 (47978243 (estimated locally),0.04 per call) oal_util_raise_dem_for_drv_runtime_err/16 (24716065 (estimated locally),0.02 per call) pfe_hm_report/15 (24716065 (estimated locally),0.02 per call) sample_fci_bd_add_if.constprop/23 (72694308 (estimated locally),0.07 per call) oal_util_raise_dem_for_drv_runtime_err/16 (37448583 (estimated locally),0.03 per call) pfe_hm_report/15 (37448583 (estimated locally),0.03 per call) sample_fci_bd_add_if.constprop/23 (110142891 (estimated locally),0.10 per call) oal_util_raise_dem_for_drv_runtime_err/16 (56740277 (estimated locally),0.05 per call) pfe_hm_report/15 (56740277 (estimated locally),0.05 per call) sample_fci_bd_add_if.constprop/23 (166883169 (estimated locally),0.16 per call) oal_util_raise_dem_for_drv_runtime_err/16 (85970117 (estimated locally),0.08 per call) pfe_hm_report/15 (85970117 (estimated locally),0.08 per call) sample_fci_bd_add_if.constprop/23 (252853286 (estimated locally),0.24 per call) oal_util_raise_dem_for_drv_runtime_err/16 (130257754 (estimated locally),0.12 per call) pfe_hm_report/15 (130257754 (estimated locally),0.12 per call) sample_fci_bd_add_if.constprop/23 (383111040 (estimated locally),0.36 per call) oal_util_raise_dem_for_drv_runtime_err/16 (197360233 (estimated locally),0.18 per call) pfe_hm_report/15 (197360233 (estimated locally),0.18 per call) sample_fci_bd_add_if.constprop/23 (580471273 (estimated locally),0.54 per call) sample_fci_log_if_print_all/2 (580471273 (estimated locally),0.54 per call) sample_fci_phy_if_print_all/3 (580471273 (estimated locally),0.54 per call) oal_util_raise_dem_for_drv_runtime_err/16 (299030656 (estimated locally),0.28 per call) pfe_hm_report/15 (299030656 (estimated locally),0.28 per call) fci_register_cb/17 (879501929 (estimated locally),0.82 per call) oal_util_raise_dem_for_drv_runtime_err/16 (194239896 (estimated locally),0.18 per call) pfe_hm_report/15 (194239896 (estimated locally),0.18 per call) fci_open/14 (1073741824 (estimated locally),1.00 per call) 
sample_fci_bd_set_policy/12 (sample_fci_bd_set_policy) @070e7ee0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sample_fci_bd_add_if/11 (sample_fci_bd_add_if) @070e7e00
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sample_fci_bd_get/10 (sample_fci_bd_get) @070e78c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sample_fci_phy_if_promisc_on/8 (sample_fci_phy_if_promisc_on) @070e72a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/16 (536870913 (estimated locally),0.50 per call) pfe_hm_report/15 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (177167401 (estimated locally),0.17 per call) pfe_hm_report/15 (177167401 (estimated locally),0.17 per call) fci_write/18 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (88583701 (estimated locally),0.08 per call) pfe_hm_report/15 (88583701 (estimated locally),0.08 per call) fci_write/18 (268435456 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/16 (268435456 (estimated locally),0.25 per call) pfe_hm_report/15 (268435456 (estimated locally),0.25 per call) fci_write/18 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_get_by_name/4 (1073741824 (estimated locally),1.00 per call) 
sample_fci_phy_if_get_id/7 (sample_fci_phy_if_get_id) @06fd1ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: sample_fci_bd_add_if.constprop/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: sample_fci_phy_if_get_by_name/4 (1073741824 (estimated locally),1.00 per call) 
sample_fci_phy_if_set_mode/6 (sample_fci_phy_if_set_mode) @06fd1c40
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sample_fci_phy_if_enable/5 (sample_fci_phy_if_enable) @06fd1620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) SampleAppFciTestTask/13 (31665641 (estimated locally),0.03 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/16 (536870913 (estimated locally),0.50 per call) pfe_hm_report/15 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (177167401 (estimated locally),0.17 per call) pfe_hm_report/15 (177167401 (estimated locally),0.17 per call) fci_write/18 (536870913 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (88583701 (estimated locally),0.08 per call) pfe_hm_report/15 (88583701 (estimated locally),0.08 per call) fci_write/18 (268435456 (estimated locally),0.25 per call) oal_util_raise_dem_for_drv_runtime_err/16 (268435456 (estimated locally),0.25 per call) pfe_hm_report/15 (268435456 (estimated locally),0.25 per call) fci_write/18 (536870913 (estimated locally),0.50 per call) sample_fci_phy_if_get_by_name/4 (1073741824 (estimated locally),1.00 per call) 
sample_fci_phy_if_get_by_name/4 (sample_fci_phy_if_get_by_name) @06fc8e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:229727064 (estimated locally) body local optimize_size
  Called by: sample_fci_phy_if_set_mode.constprop/25 (1073741823 (estimated locally),1.00 per call) sample_fci_phy_if_promisc_on/8 (1073741824 (estimated locally),1.00 per call) sample_fci_phy_if_enable/5 (1073741824 (estimated locally),1.00 per call) sample_fci_phy_if_get_id/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/16 (37904965 (estimated locally),0.16 per call) pfe_hm_report/15 (37904965 (estimated locally),0.16 per call) fci_write/18 (114863532 (estimated locally),0.50 per call) fci_query/19 (958878293 (estimated locally),4.17 per call) autolibc_memcpy/21 (55807731 (estimated locally),0.24 per call) autolibc_strcmp/20 (1014686025 (estimated locally),4.42 per call) fci_query/19 (114863532 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (114863532 (estimated locally),0.50 per call) pfe_hm_report/15 (114863532 (estimated locally),0.50 per call) fci_write/18 (229727064 (estimated locally),1.00 per call) 
sample_fci_phy_if_print_all/3 (sample_fci_phy_if_print_all) @06fc8d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:236223200 (estimated locally) body local optimize_size
  Called by: SampleAppFciTestTask/13 (20899323 (estimated locally),0.02 per call) SampleAppFciTestTask/13 (580471273 (estimated locally),0.54 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/16 (77953656 (estimated locally),0.33 per call) pfe_hm_report/15 (77953656 (estimated locally),0.33 per call) fci_write/18 (236223201 (estimated locally),1.00 per call) fci_query/19 (955630223 (estimated locally),4.05 per call) fci_query/19 (118111600 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (118111600 (estimated locally),0.50 per call) pfe_hm_report/15 (118111600 (estimated locally),0.50 per call) fci_write/18 (236223200 (estimated locally),1.00 per call) 
sample_fci_log_if_print_all/2 (sample_fci_log_if_print_all) @06fc88c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:236223200 (estimated locally) body local optimize_size
  Called by: SampleAppFciTestTask/13 (580471273 (estimated locally),0.54 per call) 
  Calls: oal_util_raise_dem_for_drv_runtime_err/16 (38976828 (estimated locally),0.17 per call) pfe_hm_report/15 (38976828 (estimated locally),0.17 per call) fci_write/18 (118111601 (estimated locally),0.50 per call) fci_query/19 (955630223 (estimated locally),4.05 per call) fci_query/19 (118111600 (estimated locally),0.50 per call) oal_util_raise_dem_for_drv_runtime_err/16 (118111600 (estimated locally),0.50 per call) pfe_hm_report/15 (118111600 (estimated locally),0.50 per call) fci_write/18 (236223200 (estimated locally),1.00 per call) 
sample_fci_callback/1 (sample_fci_callback) @06fc8460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: SampleAppFciTestTask/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 

;; Function sample_fci_callback (sample_fci_callback, funcdef_no=1, decl_uid=7303, cgraph_uid=2, symbol_order=1)

Modification phase of node sample_fci_callback/1
sample_fci_callback (short unsigned int fcode, short unsigned int len, short unsigned int * payload)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 1;

}



;; Function sample_fci_phy_if_print_all (sample_fci_phy_if_print_all, funcdef_no=3, decl_uid=7263, cgraph_uid=4, symbol_order=3)

Modification phase of node sample_fci_phy_if_print_all/3
sample_fci_phy_if_print_all (struct FCI_CLIENT * cl)
{
  int ret;
  short unsigned int replen;
  struct fpp_phy_if_cmd_t cmd;
  struct fpp_phy_if_cmd_t rep;

  <bb 2> [local count: 236223200]:
  # DEBUG BEGIN_STMT
  rep = {};
  cmd = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_10 = fci_write (cl_8(D), 21, 0, 0B);
  # DEBUG ret => ret_10
  if (ret_10 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_LOCK_SESSION failed: %d\n", "src/sample_app_fci.c", 183, ret_10, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  cmd.action = 6;
  # DEBUG BEGIN_STMT
  ret_13 = fci_query (cl_8(D), 61696, 140, &cmd, &replen, &rep);
  # DEBUG ret => ret_13
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  cmd.action = 7;
  # DEBUG BEGIN_STMT
  ret_16 = fci_query (cl_8(D), 61696, 140, &cmd, &replen, &rep);
  # DEBUG ret => ret_16

  <bb 6> [local count: 1073741824]:
  # ret_1 = PHI <ret_13(4), ret_16(5)>
  # DEBUG ret => ret_1
  # DEBUG BEGIN_STMT
  if (ret_1 == 0)
    goto <bb 5>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 236223201]:
  # DEBUG BEGIN_STMT
  ret_20 = fci_write (cl_8(D), 22, 0, 0B);
  # DEBUG ret => ret_20
  if (ret_20 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 77953656]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_UNLOCK_SESSION failed: %d\n", "src/sample_app_fci.c", 206, ret_20, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 9> [local count: 236223201]:
  # DEBUG BEGIN_STMT
  rep ={v} {CLOBBER};
  cmd ={v} {CLOBBER};
  replen ={v} {CLOBBER};
  return;

}



;; Function sample_fci_phy_if_get_by_name (sample_fci_phy_if_get_by_name, funcdef_no=4, decl_uid=7274, cgraph_uid=5, symbol_order=4)

Modification phase of node sample_fci_phy_if_get_by_name/4
Adjusting mask for param 2 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
Setting nonnull for 2
sample_fci_phy_if_get_by_name (struct FCI_CLIENT * cl, char * name, struct fpp_phy_if_cmd_t * phy_if)
{
  int retval;
  int ret;
  short unsigned int replen;
  struct fpp_phy_if_cmd_t cmd;
  struct fpp_phy_if_cmd_t rep;
  long int _1;

  <bb 2> [local count: 229727064]:
  # DEBUG BEGIN_STMT
  rep = {};
  cmd = {};
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG retval => 0
  # DEBUG BEGIN_STMT
  ret_13 = fci_write (cl_11(D), 21, 0, 0B);
  # DEBUG ret => ret_13
  if (ret_13 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_LOCK_SESSION failed: %d\n", "src/sample_app_fci.c", 226, ret_13, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  cmd.action = 6;
  # DEBUG BEGIN_STMT
  ret_16 = fci_query (cl_11(D), 61696, 140, &cmd, &replen, &rep);
  # DEBUG ret => ret_16
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = autolibc_strcmp (name_17(D), &rep.name);
  if (_1 == 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 6> [local count: 55807731]:
  # DEBUG BEGIN_STMT
  autolibc_memcpy (phy_if_22(D), &rep, 140);
  # DEBUG BEGIN_STMT
  # DEBUG retval => 1
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  cmd.action = 7;
  # DEBUG BEGIN_STMT
  ret_21 = fci_query (cl_11(D), 61696, 140, &cmd, &replen, &rep);
  # DEBUG ret => ret_21

  <bb 8> [local count: 1073741824]:
  # ret_2 = PHI <ret_16(4), ret_21(7)>
  # DEBUG ret => ret_2
  # DEBUG BEGIN_STMT
  if (ret_2 == 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 114863532]:
  # retval_3 = PHI <1(6), 0(8)>
  # DEBUG retval => retval_3
  # DEBUG BEGIN_STMT
  ret_25 = fci_write (cl_11(D), 22, 0, 0B);
  # DEBUG ret => ret_25
  if (ret_25 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_UNLOCK_SESSION failed: %d\n", "src/sample_app_fci.c", 253, ret_25, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 11> [local count: 229727064]:
  # retval_4 = PHI <0(3), retval_3(9), retval_3(10)>
  # DEBUG retval => retval_4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  rep ={v} {CLOBBER};
  cmd ={v} {CLOBBER};
  replen ={v} {CLOBBER};
  return retval_4;

}



;; Function sample_fci_phy_if_enable (sample_fci_phy_if_enable, funcdef_no=5, decl_uid=7266, cgraph_uid=6, symbol_order=5)

Modification phase of node sample_fci_phy_if_enable/5
Setting nonnull for 1
sample_fci_phy_if_enable (struct FCI_CLIENT * cl, char * name)
{
  int ret;
  struct fpp_phy_if_cmd_t cmd;
  int _1;
  int _2;
  <unnamed type> _3;
  long unsigned int _4;
  long unsigned int _5;
  <unnamed type> _6;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = fci_write (cl_11(D), 21, 0, 0B);
  if (_2 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_LOCK_SESSION failed\n", "src/sample_app_fci.c", 275, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  cmd.action = 4;
  # DEBUG BEGIN_STMT
  _3 = cmd.flags;
  _4 = (long unsigned int) _3;
  _5 = _4 | 16777216;
  _6 = (<unnamed type>) _5;
  cmd.flags = _6;
  # DEBUG BEGIN_STMT
  ret_20 = fci_write (cl_11(D), 61696, 140, &cmd);
  # DEBUG ret => ret_20
  if (ret_20 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 88583701]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] %s enable failed: %d\n", "src/sample_app_fci.c", 284, name_12(D), ret_20, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 7> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = fci_write (cl_11(D), 22, 0, 0B);
  if (_7 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 8> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_UNLOCK_SESSION failed\n", "src/sample_app_fci.c", 291, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] %s not found\n", "src/sample_app_fci.c", 296, name_12(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  cmd ={v} {CLOBBER};
  return;

}



;; Function sample_fci_phy_if_promisc_on (sample_fci_phy_if_promisc_on, funcdef_no=8, decl_uid=7280, cgraph_uid=9, symbol_order=8)

Modification phase of node sample_fci_phy_if_promisc_on/8
Setting nonnull for 1
sample_fci_phy_if_promisc_on (struct FCI_CLIENT * cl, char * name)
{
  int ret;
  struct fpp_phy_if_cmd_t cmd;
  int _1;
  int _2;
  <unnamed type> _3;
  long unsigned int _4;
  long unsigned int _5;
  <unnamed type> _6;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = sample_fci_phy_if_get_by_name (cl_11(D), name_12(D), &cmd);
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 = fci_write (cl_11(D), 21, 0, 0B);
  if (_2 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_LOCK_SESSION failed\n", "src/sample_app_fci.c", 384, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  cmd.action = 4;
  # DEBUG BEGIN_STMT
  _3 = cmd.flags;
  _4 = (long unsigned int) _3;
  _5 = _4 | 33554432;
  _6 = (<unnamed type>) _5;
  cmd.flags = _6;
  # DEBUG BEGIN_STMT
  ret_20 = fci_write (cl_11(D), 61696, 140, &cmd);
  # DEBUG ret => ret_20
  if (ret_20 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 88583701]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] %s promisc mode failed: %d\n", "src/sample_app_fci.c", 393, name_12(D), ret_20, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 7> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = fci_write (cl_11(D), 22, 0, 0B);
  if (_7 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 8> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_UNLOCK_SESSION failed\n", "src/sample_app_fci.c", 400, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] %s not found\n", "src/sample_app_fci.c", 405, name_12(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  cmd ={v} {CLOBBER};
  return;

}



;; Function sample_fci_bd_get.constprop (sample_fci_bd_get.constprop.0, funcdef_no=15, decl_uid=7544, cgraph_uid=25, symbol_order=24)

Modification phase of node sample_fci_bd_get.constprop/24
Adjusting mask for param 2 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 2
sample_fci_bd_get.constprop (struct FCI_CLIENT * cl, struct fpp_l2_bd_cmd_t * bd)
{
  struct fpp_l2_bd_cmd_t cmd;
  short unsigned int replen;
  int ret;
  uint16 vlan;
  short unsigned int _4;
  short unsigned int _5;
  int _8;

  <bb 7> [local count: 114863532]:
  # DEBUG vlan => 1

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  replen = 36;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  cmd.action = 6;
  # DEBUG BEGIN_STMT
  ret_3 = fci_query (cl_1(D), 61952, 36, &cmd, &replen, bd_2(D));
  # DEBUG ret => ret_3
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _4 = bd_2(D)->vlan;
  _5 = _4 r>> 8;
  if (_5 == 1)
    goto <bb 6>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  cmd.action = 7;
  # DEBUG BEGIN_STMT
  ret_6 = fci_query (cl_1(D), 61952, 36, &cmd, &replen, bd_2(D));
  # DEBUG ret => ret_6

  <bb 5> [local count: 1073741824]:
  # ret_7 = PHI <ret_3(2), ret_6(4)>
  # DEBUG ret => ret_7
  # DEBUG BEGIN_STMT
  if (ret_7 == 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863532]:
  # _8 = PHI <1(3), 0(5)>
  cmd ={v} {CLOBBER};
  replen ={v} {CLOBBER};
  return _8;

}



;; Function sample_fci_bd_add_if.constprop (sample_fci_bd_add_if.constprop.0, funcdef_no=16, decl_uid=7543, cgraph_uid=24, symbol_order=23)

Modification phase of node sample_fci_bd_add_if.constprop/23
Setting nonnull for 2
sample_fci_bd_add_if.constprop (struct FCI_CLIENT * cl, char * phy_if)
{
  int if_id;
  int ret;
  struct fpp_l2_bd_cmd_t bd;
  uint16 vlan;
  bool_t tag;
  int _4;
  long unsigned int _5;
  int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  int _24;

  <bb 12> [local count: 1073741824]:
  # DEBUG tag => 0
  # DEBUG vlan => 1

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if_id_3 = sample_fci_phy_if_get_id (cl_1(D), phy_if_2(D));
  # DEBUG if_id => if_id_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (if_id_3 < 0)
    goto <bb 3>; [26.36%]
  else
    goto <bb 4>; [73.64%]

  <bb 3> [local count: 283038345]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Could not get interface ID\n", "src/sample_app_fci.c", 492, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 790703480]:
  # DEBUG BEGIN_STMT
  _4 = sample_fci_bd_get (cl_1(D), 1, &bd);
  if (_4 == 0)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 160038384]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Can\'t get bridge domain\n", "src/sample_app_fci.c", 498, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 630665096]:
  # DEBUG BEGIN_STMT
  bd.action = 4;
  # DEBUG BEGIN_STMT
  _5 = bd.if_list;
  _6 = 1 << if_id_3;
  _7 = (long unsigned int) _6;
  _8 = _7 >> 24;
  _9 = _7 >> 8;
  _10 = _9 & 65280;
  _11 = _8 | _10;
  _12 = _7 << 8;
  _13 = _12 & 16711680;
  _14 = _11 | _13;
  _15 = _7 << 24;
  _16 = _14 | _15;
  _17 = _5 | _16;
  bd.if_list = _17;
  # DEBUG BEGIN_STMT
  if (0 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 315332548]:
  # DEBUG BEGIN_STMT
  _18 = bd.untag_if_list;
  _19 = ~_16;
  _20 = _18 & _19;
  bd.untag_if_list = _20;
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 315332548]:
  # DEBUG BEGIN_STMT
  _21 = bd.untag_if_list;
  _22 = _16 | _21;
  bd.untag_if_list = _22;

  <bb 9> [local count: 630665096]:
  # DEBUG BEGIN_STMT
  ret_23 = fci_write (cl_1(D), 61952, 36, &bd);
  # DEBUG ret => ret_23
  # DEBUG BEGIN_STMT
  if (ret_23 != 0)
    goto <bb 10>; [20.24%]
  else
    goto <bb 11>; [79.76%]

  <bb 10> [local count: 127646615]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_L2_BD failed: %d\n", "src/sample_app_fci.c", 517, ret_23, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  # _24 = PHI <0(3), 0(5), 1(9), 0(10)>
  bd ={v} {CLOBBER};
  return _24;

}



;; Function sample_fci_phy_if_set_mode.constprop (sample_fci_phy_if_set_mode.constprop.0, funcdef_no=14, decl_uid=7545, cgraph_uid=26, symbol_order=25)

Modification phase of node sample_fci_phy_if_set_mode.constprop/25
Setting nonnull for 1
sample_fci_phy_if_set_mode.constprop (struct FCI_CLIENT * cl, char * name)
{
  struct fpp_phy_if_cmd_t rep;
  int ret;
  fpp_phy_if_op_mode_t mode;
  int _3;

  <bb 11> [local count: 1073741823]:
  # DEBUG mode => 1

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = sample_fci_phy_if_get_by_name (cl_1(D), name_2(D), &rep);
  if (_3 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  ret_4 = fci_write (cl_1(D), 21, 0, 0B);
  # DEBUG ret => ret_4
  if (ret_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_LOCK_SESSION failed: %d\n", "src/sample_app_fci.c", 317, ret_4, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  rep.action = 4;
  # DEBUG BEGIN_STMT
  rep.mode = 1;
  # DEBUG BEGIN_STMT
  ret_5 = fci_write (cl_1(D), 61696, 140, &rep);
  # DEBUG ret => ret_5
  if (ret_5 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] Mode change failed: %d\n", "src/sample_app_fci.c", 327, ret_5, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 7> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ret_6 = fci_write (cl_1(D), 22, 0, 0B);
  # DEBUG ret => ret_6
  if (ret_6 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 8> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] FPP_CMD_IF_UNLOCK_SESSION failed: %d\n", "src/sample_app_fci.c", 333, ret_6, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] %s not found\n", "src/sample_app_fci.c", 339, name_2(D), "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  rep ={v} {CLOBBER};
  return;

}



;; Function SampleAppFciTestTask (SampleAppFciTestTask, funcdef_no=13, decl_uid=7259, cgraph_uid=14, symbol_order=13)

Modification phase of node SampleAppFciTestTask/13
SampleAppFciTestTask ()
{
  struct fpp_l2_bd_cmd_t bd;
  struct FCI_CLIENT * cl;
  int _1;
  Std_ReturnType _2;
  int _3;
  int _4;
  int _5;
  int _6;
  int _7;
  int _8;
  int _9;
  int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG stdRet => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  cl_14 = fci_open (0, 0);
  # DEBUG cl => cl_14
  # DEBUG BEGIN_STMT
  if (cl_14 == 0B)
    goto <bb 3>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 3> [local count: 194239896]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] fci_open() failed\n", "src/sample_app_fci.c", 780, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 4> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  _1 = fci_register_cb (cl_14, sample_fci_callback);
  if (_1 != 0)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 299030656]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] fci_register_cb() failed\n", "src/sample_app_fci.c", 786, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 6> [local count: 580471273]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_print_all (cl_14);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sample_fci_log_if_print_all (cl_14);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = sample_fci_bd_add_if (cl_14, 1, "emac1", 0);
  if (_3 == 0)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 197360233]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_add_if failed\n", "src/sample_app_fci.c", 812, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 8> [local count: 383111040]:
  # DEBUG BEGIN_STMT
  _4 = sample_fci_bd_add_if (cl_14, 1, "emac2", 0);
  if (_4 == 0)
    goto <bb 9>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 9> [local count: 130257754]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_add_if failed\n", "src/sample_app_fci.c", 817, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 10> [local count: 252853286]:
  # DEBUG BEGIN_STMT
  _5 = sample_fci_bd_add_if (cl_14, 1, "hif0", 0);
  if (_5 == 0)
    goto <bb 11>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 11> [local count: 85970117]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_add_if failed\n", "src/sample_app_fci.c", 822, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 12> [local count: 166883169]:
  # DEBUG BEGIN_STMT
  _6 = sample_fci_bd_add_if (cl_14, 1, "hif1", 0);
  if (_6 == 0)
    goto <bb 13>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 13> [local count: 56740277]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_add_if failed\n", "src/sample_app_fci.c", 827, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 14> [local count: 110142891]:
  # DEBUG BEGIN_STMT
  _7 = sample_fci_bd_add_if (cl_14, 1, "hif2", 0);
  if (_7 == 0)
    goto <bb 15>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 15> [local count: 37448583]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_add_if failed\n", "src/sample_app_fci.c", 832, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 16> [local count: 72694308]:
  # DEBUG BEGIN_STMT
  _8 = sample_fci_bd_add_if (cl_14, 1, "hif3", 0);
  if (_8 == 0)
    goto <bb 17>; [34.00%]
  else
    goto <bb 18>; [66.00%]

  <bb 17> [local count: 24716065]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_add_if failed\n", "src/sample_app_fci.c", 837, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 18> [local count: 47978243]:
  # DEBUG BEGIN_STMT
  _9 = sample_fci_bd_set_policy (cl_14, 1, 0, 1, 0, 1);
  if (_9 == 0)
    goto <bb 19>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 19> [local count: 16312603]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_set_policy failed\n", "src/sample_app_fci.c", 844, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 20> [local count: 31665641]:
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_set_mode (cl_14, "emac1", 1);
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_set_mode (cl_14, "emac2", 1);
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_set_mode (cl_14, "hif0", 1);
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_set_mode (cl_14, "hif1", 1);
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_set_mode (cl_14, "hif2", 1);
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_set_mode (cl_14, "hif3", 1);
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_enable (cl_14, "emac1");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_enable (cl_14, "emac2");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_enable (cl_14, "hif0");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_enable (cl_14, "hif1");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_enable (cl_14, "hif2");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_enable (cl_14, "hif3");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_promisc_on (cl_14, "emac1");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_promisc_on (cl_14, "emac2");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_promisc_on (cl_14, "hif0");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_promisc_on (cl_14, "hif1");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_promisc_on (cl_14, "hif2");
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_promisc_on (cl_14, "hif3");
  # DEBUG BEGIN_STMT
  _10 = sample_fci_bd_get (cl_14, 1, &bd);
  if (_10 == 0)
    goto <bb 21>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 21> [local count: 10766318]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pfe_hm_report (1, 2, 1, "[%s:%d] sample_fci_bd_get failed\n", "src/sample_app_fci.c", 875, "");
  # DEBUG BEGIN_STMT
  oal_util_raise_dem_for_drv_runtime_err ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 23>; [100.00%]

  <bb 22> [local count: 20899323]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sample_fci_phy_if_print_all (cl_14);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 1073741824]:
  # _2 = PHI <1(3), 1(5), 0(22), 1(7), 1(9), 1(11), 1(13), 1(15), 1(17), 1(19), 1(21)>
  bd ={v} {CLOBBER};
  return _2;

}


