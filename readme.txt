#  Copyright 2020-2024 NXP
#
#  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
#  be used strictly in accordance with the applicable license terms. By
#  expressly accepting such terms or by downloading, installing, activating
#  and/or otherwise using the software, you are agreeing that you have read,
#  and that you agree to comply with and are bound by, such license terms. If
#  you do not agree to be bound by the applicable license terms, then you may
#  not retain, install, activate or otherwise use the software.


1 Introduction
==============
Example application demonstrates configuration of PFE MCAL driver and its integration with other MCAL drivers. It uses Port driver to configure pins, Serdes driver to configure serdes hardware peripheral and Mcu driver to configure PFE clock.

All files in the example_application project are provided as sample code only. They are not part of the production code deliverables.

EMAC names used in this document refers to EVB or EVB3 application. For RDB and RDB3, EMAC1 is used instead of EMAC0, EMAC2 is used instead of EMAC1

Configuration of the example application was changed to configure L2 bridge and use AUX controller by default (FCI_L2BR_TEST=TRUE).
There are two sets of the PFE Eth configurations stored in folder eth_pfe_configs. When "make generate"
command is executed, relevant Eth_1.xdm file is copied to configuration project:
 - in case of FCI_L2BR_TEST=TRUE, configuration from 00_pfe_fci_l2br_test is used, which is optimized for
   using AUX controller (controller index 2, most of the buffers are allocated to this controller) In this
   configuration the other controllers will not receive any frames except PTP.
 - in case of FCI_L2BR_TEST=FALSE, configuration from 01_pfe_normal is used, which is optimized for using
   the EMAC controllers (controller index 0 and 1, most of the buffers are allocated to this controllers).
   In this configuration the AUX controller will not receive any frames from EMACs.
For more information about the option FCI_L2BR_TEST, see chapter "MCAL FCI demo" below.
For more information about using the AUX controller, see chapter "AUX Controller" in "User Manual for S32G PFE MCAL 4.4 Driver".


1.1 Supported hardware
----------------------
1) EVB (S32G2), which consists of 2 boards:
 - Platform board:
    - S32GRV-PLATEVB 700-30081 REV A
      Requires fix – Errata E-PLATGRV-0001
 - Processor board, there are 2 versions:
    - X-S32G-PROCEVB-S 700-32170 REV X3
      Requires fix – Errata E-S32G-EVB-001
    - X-S32G-PROCEVB-S 700-32170 REV A4
 - Use HW=EVB (default target HW) parameter when running make

2) RDB2 (S32G2):
  - S32G-VNP-RDB2 REV D
  - Use HW=RDB2 parameter when running make

3) EVB3 (S32G3):
 - Processor board
    - S32G-PROCEVB3-S SCH-50784 REV A
 - Use HW=EVB3 parameter when running make

4) RDB3 (S32G3):
 - X-S32G-VNP-RDB3 SCH-53060 REV E1
 - Use HW=RDB3 parameter when running make

5) RDB2 (S32G2 Rev2_1):
 - X-S32G-VNP-RDB3 SCH-47440 REV E
 - Use HW=RDB2 parameter when running make

6) RDB3 (S32G3 Rev1_1):
 - X-S32G-VNP-RDB3 SCH-53060 REV F
 - Use HW=RDB3 parameter when running make

1.2 Supported compilers
-----------------------
  - Greenhills
  - GCC
  - Windriver diab

1.3 Dependencies
----------------
  - MCAL for S32G:
    - SW32G_RTD_4.4_4.0.2

1.4 Known issues
----------------
  There are no known issues in this app.

1.5 Functional description
--------------------------
The application configures the hardware, then it sends and receives Ethernet frames on EMAC0 and EMAC1 interfaces. Counters are incremented with each received/transmitted frame, with each Tx confirmation and with each Tx error. Each controller has its set of counters, for example:
  pfeRxCtr = (14, 14)
  pfeTxCtr = (14, 14)
  pfeTxConfCtr = (14, 14)
  pfeTxErrorCtr = (0, 0)

Inbound traffic, in order to be received, must be addressed to interface's MAC address or to broadcast MAC address. Alternatively the controller can be configured to promiscuous mode to receive any traffic.

Outbound traffic consists of invalid IPv4 frames.

+-----------------------------+
| EMACs used                  |
+--------------+--------------+
| RDB2, RDB3   | EVB, EVB3    |
+--------------+--------------+
| EMAC1, EMAC2 | EMAC0, EMAC1 |
+--------------+--------------+

EMAC0 is connected to the SGMII (SERDES PCIe) PHY on the processor board. This is the default configuration
EMAC0 is also connected to Ethernet switch sja1105p on platform board, which is connected to ports: 2x BroadReach, RGMII-ADD-2 and RGMII-ADD-3.
To enable this configuration, update the following:
-in the PFE configuration
    change EthCtrlMacLayerSubType for EthCtrlConfig_0 from SERIAL to REDUCED
-in the Mcu configuration:
    change McuGENCTRL1 Source from SERDES_1_XPCS_0_TX to PFEMAC0_TX_DIV_CLK
    change McuCgm2ClockMux4 Source from SERDES_1_XPCS_0_CDR to PFE_MAC_0_EXT_RX_CLK
Refer to chapter [23.7.2.3.1 PFE_MAC_0 clocking overview] in S32G2_RM for more information
If sja1105p switch driver is not integrated to application, then transmission and reception on EMAC0 will not work in this configuration.

EMAC1 is connected to RGMII port on processor board.

1.5.1 MCAL FCI demo
-------------------
The FCI API is enabled in the provided Tresos configuration project. It can be disabled in
EthVendorSpecific area. The user can also configure routing table parameters and buffer count.

Now, the example application can be build with the parameter FCI_L2BR_TEST=TRUE (default). If enabled, the application 
sets up the L2 bridge for the default domain (VLAN 1), adds emac0 (emac1 for RDB), emac1 (emac2 for RDB) and all standard HIFs (hif0 to hif3).
to the bridge domain, and sets the domain policies: 
forward for unicast hit, flood for unicast miss, forward for multicast hit and flood for multicast cast miss.
It is recommended to also add DEBUG=TRUE when using this option. To show this functionality is working on single instance driver (master), you should
connect some other endpoint(s) to send and receive traffic. Or run master-slave scenario where master is build with FCI_L2BR_TEST=TRUE and you can observe
that packets send by master AUX interface (through hif0) are forwarded to slave through hif1 and received on slave AUX interface (slave source code must be
modified to see AUX RX traffic).

The example application can also build with the parameter FCI_RTABLE_TEST=TRUE. If enabled, the Application will register 2 routes + 1 single conntrack and
configure hif0 (if SLAVE_DRIVER=FALSE) or hif1 (if SLAVE_DRIVER=TRUE) as IP router mode. Whereby, any packet which have source IP address, destination IP
address, source port and destination port match the respective conntrack will be forwarded via physical interface given by matching route.
- We can observe that this functionality is working on Master driver by transmitting the packets which have IP addresses and ports match the conntrack as bellow:
  + Case 1: Any packet which has (source IP address = 11.41.48.100, destination IP address = 12.41.48.100, source port = 11 and destination port = 12) and transmitted
    by Master AUX interface (through hif0) will be sent back to hif0 by the FW. Then AUX interface of Master will receive the frame (RX counter of AUX interface of
    Master 'pfeRxCtr[3U]' will increase).
  + Case 2: Any packet which has (source IP address = 12.41.48.100, destination IP address = 11.41.48.100, source port = 12 and destination port = 11) and transmitted
    by Master AUX interface (through hif0) will be sent to emac1 by the FW.
- We can observe that this functionality is working on Slave driver (we should build Master with FCI_RTABLE_TEST=FALSE and Slave with FCI_RTABLE_TEST=TRUE)
  by transmitting the packets which have IP addresses and ports match the conntrack as bellow:
  + Case 1: Any packet which has (source IP address = 11.41.48.100, destination IP address = 12.41.48.100, source port = 11 and destination port = 12) and transmitted
    by Slave AUX interface (through hif1) will be sent back to hif1 by the FW. Then AUX interface of Slave will receive the frame (RX counter of AUX interface of
    Slave 'pfeRxCtr[3U]' will increase).
  + Case 2: Any packet which has (source IP address = 12.41.48.100, destination IP address = 11.41.48.100, source port = 12 and destination port = 11) and transmitted
    by Slave AUX interface (through hif1) will be sent to emac1 by the FW.

1.5.2 PFE configuration for PFE to LLCE or LLCE to PFE routing
--------------------------------------------------------------
To use PFE to LLCE routing (Ethernet to CAN) or LLCE to PFE routing (CAN to Ethernet), the HIF channel used by LLCE must be configured using the minihif driver.
This is done in the source file minihif_hw_conf.c. The hardware configurations will include:
 - initialize PFE HW used by LLCE
 - configure buffer descriptors (BD) for minihif with BD access permission is FALSE
 - configure the EMACs
 - configure packet steering and filtering

To enable PFE-LLCE hardware configuration, the application needs to build with the parameter CONFIG_MINIHIF=TRUE. Besides, the HIF channel used by LLCE can be
selected with parameter CONFIG_MINIHIF_HW=<hif_instance> (The valid values for <hif_instance> are HIF1/HIF2/HIF3). The HIF interface selected for minihif should
NOT be configured in a controller in tresos.

1.5.3 Master-slave demo
-----------------------
The example application demonstrates Master-slave scenario run in one board.
To run and debug with Master and slave application, user needs to do the following steps.
  - Step 1: After installing RTD drivers, copy the installed RTD driver plugins and PFE driver plugin to Tresos plugins directory
    + Otherwise the example application Makefile will not find them
    + Typically <RTD installation folder>\eclipse\plugins to <EB tresos>\plugins - without this it is not possible to build RTD drivers
  - Step 2: Configure for parameters in the Makefile and project_parameters.mk
    + In project_parameters.mk: ensure that all paths and package names are correct in user's environment
    + In Makefile: At the beginning of this file, there are some options to configure features used in the application. User needs to configure appropriate value for those options (see section 3.2 for more detail about meaning of those options)
    For example, if user wants to switch to other hardware platform, user can change the value of HW=EVB, EVB3, RDB2 or RDB3
  - Step 3: Build the master/slave application
    + Open Cygwin or any cmd window and direct to the application's directory, for example: cd "<user_path>\example_application"
    + To build master application:
      + Configure SLAVE_DRIVER ?= FALSE in Makefile
      + Enter the following commands on terminal
        make clean_all (To clean the built output folder and source generated folder)
        make generate (To generate the sources and headers)
        make build (To compile all related files and create the binary file (.elf))
    + To build slave application:
      + Configure SLAVE_DRIVER ?= TRUE in Makefile
      + Do the same commands with master application
    After step 2, without any errors, user will have main_<target HW platform>.elf and slave_app_<target HW platform>.elf
  - Step 4: Run and debug the application with Lauterbach TRACE32
    + Open t32marm.exe (in TRACE32 directory: <T32_dir>\bin\windows or <T32_dir>bin\windows64)
    + On the Menu bar, select File -> Run Script
    + Open "<user_path>\example_application" and choose script to run:
      + 'run_main_<target HW platform>.cmm' (where target is EVB, RDB2, RDB3, EVB3 based on your hardware) is used to run Master application
      + 'run_slave_app_<target HW platform>.cmm' (same as above) is used to run Master-slave application
    + Once the program is loaded and run, users could pause by pressing Break and use the following commands to switch to other Master or Slave application
      SYStem.CPU S32G274A-M7-1
      SYS.Attach
      Data.LOAD.Elf <user_path>\example_application\output_slave_<target HW platform>\slave_app_<target HW platform>.elf /noregister /NoCODE

    Note 1: M7-0 core is used for Master and M7-1 core is used for slave
    Note 2: Both applications will transmit frames on both EMAC0 and EMAC1. If a cable is plugged between EMAC0 and EMAC1, the RX counters will show twice the number of transmitted frames
    Note 3: Use 'go main' to open the debug windows, use 'list <function name>' to open the window with the function user want to debug

1.5.4 lwIP demo
To enable use of lwIP and iPerf 2, user needs to do the following steps.
  - Step 1: After installing RTD drivers, copy the installed RTD driver plugins and PFE driver plugin to Tresos plugins directory
    + Otherwise the example application Makefile will not find them
    + Typically <RTD installation folder>\eclipse\plugins to <EB tresos>\plugins - without this it is not possible to build RTD drivers
  - Step 2: Configure for parameters in the Makefile and project_parameters.mk
    + In project_parameters.mk: ensure that all paths and package names are correct in user's environment
    + In Makefile: At the beginning of this file, there are some options to configure features used in the application. User needs to configure appropriate value for those options (see section 3.2 for more detail about meaning of those options)
  - Step 3: Build the lwIP demo application
    + Get the lwIP repository and place it in the parent folder or specify LWIP_DIR in the command line
      Official lwIP repository: https://github.com/lwip-tcpip/lwip
      Official lwIP website: https://savannah.nongnu.org/projects/lwip/
      Reccomended lwIP version = STABLE-2_1_3_RELEASE
    + Open Cygwin or any cmd window and direct to the application's directory, for example: cd "<user_path>\example_application"
    + To build lwIP demo application:
      + Configure following macros:
	    + Set LWIP=TRUE, IP_ADDRESS_CTRL_2, LWIP_DEFAULT_GATEWAY_2, and LWIP_MASK in the command line (This refers 
          to Controller 2, which is the AUX controller and it shall be used for normal traffic. There are also 
          controllers 0 and 1, which in default configuration can be used only for management/PTP traffic.)
      + Example values for these parameters
        IP_ADDRESS_CTRL_0=169.254.45.182 - Based on the gateway
        LWIP_DEFAULT_GATEWAY_0=169.254.45.181 - Based on PC port ip
        LWIP_MASK=255.255.255.0
      + Enter the following commands on terminal
        make clean_all (To clean the built output folder and source generated folder)
        make generate (To generate the sources and headers)
        make build (To compile all related files and create the binary file (.elf))
  - Step 4: Run and debug the application with Lauterbach TRACE32
    + Open t32marm.exe (in TRACE32 directory: <T32_dir>\bin\windows or <T32_dir>bin\windows64)
    + On the Menu bar, select File -> Run Script
    + Open "<user_path>\example_application" and choose script to run:
      + 'run_main_<target HW platform>.cmm' (where target is EVB, RDB2, RDB3, EVB3 based on your hardware) is used to run application.
    + Once the program is loaded and run, user can use iPerf 2 to test the performance

    Note 1: Users can also set up the other macros (IP_ADDRESS_CTRL_0, LWIP_DEFAULT_GATEWAY_0, IP_ADDRESS_CTRL_1 and
    LWIP_DEFAULT_GATEWAY_1) if they are interested in using the EMAC ports directly In that case the driver should be
    reconfigured. See chapter "AUX Controller" in the user manual for more information.
    Note 2: Port to Controller relation is dependand upon type of board used. (For more information see section 1.5 Functional description).
    Note 3: Reccomended iPerf version: iPerf 2.0.9. Example iPerf 2 command: iperf.exe -c 169.254.45.182 -b 200M -p 5001 -t 30 -i 5
    Note 4: lwIP demo application also replies to ping.
    Note 5: lwIP demo application can only be build with GCC.
    Note 6: If the IP addresses are not configured by user, default addresses are used.

    Example of iPerf 2 output:
    ------------------------------------------------------------
    Client connecting to 169.254.45.182, TCP port 5001
    TCP window size:  208 KByte (default)
    ------------------------------------------------------------
    [  3] local 169.254.45.181 port 64928 connected with 169.254.45.182 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0- 5.0 sec  85.4 MBytes   143 Mbits/sec
    [  3]  5.0-10.0 sec  90.3 MBytes   151 Mbits/sec
    [  3] 10.0-15.0 sec  90.2 MBytes   151 Mbits/sec
    [  3] 15.0-20.0 sec  90.3 MBytes   151 Mbits/sec
    [  3] 20.0-25.0 sec  90.2 MBytes   151 Mbits/sec
    [  3] 25.0-30.0 sec  90.2 MBytes   151 Mbits/sec
    [  3]  0.0-30.0 sec   537 MBytes   150 Mbits/sec

2 Configuration
===============
Application contains 8 tresos configuration projects MasterProject_<target HW platform> and SlaveProject_<target HW platform>.
Either it can be imported to Tresos and configuration can be generated from there, or it can be generated using makefile, command "make generate HW=<target HW platform>".
To generate the slave project, use "make generate SLAVE_DRIVER=TRUE"
Note that using makefile requires prior configuration of paths, see chapter 3.

3 Build
=======
Application can be built using makefile. Before the makefile is run, paths need to be configured: either modify file project_parameters.mk or provide the paths on command line.

3.1 Make commands
-----------------
  - To build the application with default options and GCC compiler:
    make HW=<target HW platform>
  - To clean the build:
    make clean
  - To clean the build and generated configuration:
    make clean_all
Note: add SLAVE_DRIVER=TRUE to the make command to build or clean the slave app

3.2 Options for the make command
--------------------------------
  - "make help" prints all the possible options
  - To select target hardware platform:
    HW=EVB
    HW=EVB3
    HW=RDB2
    HW=RDB3 (default)
  - To build in debug mode with debug log for PFE driver:
    DEBUG=TRUE
  - To select compiler
    COMPILER=GCC (default)
    COMPILER=GHS
    COMPILER=DIAB
  - Connectivity options:
    USE_SJA1105P_DRIVER=TRUE USE_SERDES_DRIVER=FALSE
        These options are required to be able to TX/RX on MAC0 via sja1105p.
        The switch driver must be integrated and PFE/Mcu configuration updated in tresos
    LOOPBACK_TEST=TRUE
        This option can be be used to RX frames on MAC1 without any cable
        Configuration parameter EthEmacLoopEn must be set for both controllers in tresos
        Both MAC0 and MAC1 will receive their own frames back.
    FCI_L2BR_TEST=FALSE
        This option can be used to disable FCI L2 bridge demo, see section 1.5.1
    FCI_RTABLE_TEST=TRUE
        This option can be used to enable FCI routing table demo, see section 1.5.1
  - To configure PFE hardware to be used by LLCE
    CONFIG_MINIHIF=TRUE
        This option can be used to configure the PFE hardware to be used by LLCE, see section 1.5.2
    CONFIG_MINIHIF_HW=HIF1 (HIF2/HIF3)
        This option can be used to select HIF channel used by LLCE (default is HIF3), see section 1.5.2
  - To generate and build the slave app:
    SLAVE_DRIVER=TRUE
  - Text statistics option:
    TEXT_STATS=FALSE (default)
    TEXT_STATS=TRUE allow to print miscellaneous statistics for PFE (only when DEBUG=TRUE also !)
  - To use serdes drivers
    USE_SERDES_DRIVER=TRUE
  - To configurate the verbosity level:
    VERBOSITY_LEVEL=8 (default)
  - To enable or disable the setting of many initiation functions
    CONFIGURE_SOC=TRUE
  - To enable or disable user mode support
    USER_MODE=TRUE
    Note: The user needs to turn on each module's user_mode_support=true and re-generate the sources
  - Configure GPT channel
    SWITCH_TASK_GPT_CHANNEL_CFG=0 (default): used for the transfering task
    TM_STUB_GPT_CHANNEL_CFG=1     (default): used for the delay inside the drivers
  - To generate and build lwip app:
    LWIP=TRUE
    Lwip options:
    LWIP_STATUS_CALLBACK = 1 (only when DEBUG=TRUE also !)
        This option will report every status change to net interfaces
    DEBUG=TRUE when LWIP = TRUE will also enable iperf status report.

4 Running the application
=========================
Scripts (CMM_FILE) for Lauterbach debugger (TRACE32 for ARM) is provided
run_main_EVB.cmm        run standalone app (S32G2)
run_main_EVB3.cmm       run standalone app (S32G3)
run_main_RDB2.cmm       run standalone app (S32G2)
run_main_RDB3.cmm       run standalone app (S32G3)

run_slave_app_EVB.cmm   run master/slave app (S32G2)
run_slave_app_EVB3.cmm  run master/slave app (S32G3)
run_slave_app_RDB2.cmm  run master/slave app (S32G2)
run_slave_app_RDB3.cmm  run master/slave app (S32G3)


4.1 Steps for running the application
-------------------------------------
 1) Connect debugger
 2) Power-on the EVB, to ensure reliable connection on switch ports, specific power-on sequence is required to workaround a known issue with transceiver connection on EVB:
    - Make sure the EVB is off for at least 30 s.
    - Power on the platform board only
    - Power on the processor board
 3) Open TRACE32 for ARM windows, run script with command: cd.do EXAMPLE_APPLICATION_PATH/CMM_FILE
 4) Hit Run button
 5) The application is running
    - Frame counters are displayed, including counters from switch (if used).
    - If the application was built with DEBUG=TRUE, debug messages will be displayed.
