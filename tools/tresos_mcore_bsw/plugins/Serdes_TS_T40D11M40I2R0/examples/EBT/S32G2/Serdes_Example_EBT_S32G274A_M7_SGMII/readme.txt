1 Introduction
==============
This example application demonstrates the usage of the Serdes driver for S32G2 in SGMII mode.

1.1 Supported hardware
----------------------
The application supports S32G Daughter Board - S32G-PROCEVB-S PCB RevX3 SCH RevB1

1.3 Supported compilers
-----------------------
  - GCC version 9.2.0, part of NXP Design Studio 3.5

1.4 Dependencies
----------------
  - RTD for S32G:
    - RTD 4.0.2 S32G2
        Required plugins: BaseNXP Mcu Rte Platform Serdes Port Eth EthIf EthSwt EthTrcv Dem Det

2 Functional description for PCIe Endpoint support
====================================================
The demo configures the Serdes PHY and the GMAC module in SGMII (mode 3). Serdes is configured in loopback mode(loopback is applied to PMA).


3 Configuring and Building the application
==========================================
The application contains Tresos configuration project in folder TestProject.
Before the application can be configured and built, paths need to be configured in the file  project_parameters.mk.
To generate the configuration use the comand:
make generate
To build the application use the comand:
make build
To clean the build use the comand:
make clean

4 Running the application
=========================


4.1 Hardware setup
------------------


4.2 Jumper settings
-------------------

The following jumper setings are required for this demo. Only differences from the board's default settings are noted.

 - J96:     2-3
 - J165:    1-2
 - SW12:    1 OFF, 2 ON, 3 OFF, 4 OFF
 - SW13:    1 ON, 2 OFF, 3 OFF, 4 OFF
 - SW14:    1 OFF,  2 OFF
 - SW15:    1 OFF, 2 OFF
 - SW6:     1 OFF, 2 OFF, 3 OFF, 4 OFF, 5 OFF, 6 OFF, 7 ON,  8 OFF
 - SW7:     1 OFF, 2 OFF, 3 OFF, 4 OFF, 5 OFF, 6 OFF, 7 OFF, 8 OFF
 - SW8:     1 ON,  2 ON,  3 ON,  4 OFF, 5 OFF, 6 OFF, 7 ON,  8 OFF
 - SW9:     1 OFF, 2 OFF, 3 OFF, 4 OFF, 5 OFF, 6 OFF, 7 OFF, 8 OFF

4.3 Testing the demo
----------------------------

The demo run successfully if Status variable has value ETH_RECEIVE, this is an indication that the Eth transmitted and received the packets successfully.

5 Notes
=======

On S32G2 platform there are 4 MACs and all of them support SGMII.

S32G2 mapping to XPCS:
+--------+-------+-------+
| SerDes | XPCS0 | XPCS1 |
+--------+-------+-------+
|      0 | GMAC  | PFE2  |
|      1 | PFE0  | PFE1  |
+--------+-------+-------+

 - APIs are provisional and subject to change in future releases.
