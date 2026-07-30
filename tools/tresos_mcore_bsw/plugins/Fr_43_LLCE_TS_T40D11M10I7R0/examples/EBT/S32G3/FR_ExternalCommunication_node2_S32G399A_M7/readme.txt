1. Example Description
        Transmit and receive the frame between two nodes.
        The hardware setup for this example is two boards connected together with a Flexray cable. One board will run example for node 1, the other board will run example for node 2. This is because Flexray does not support loopbacking.
        This example uses for a board (Node 2).
    1.1 The application software functionality.
        - Initialize pins to provide the external clock to Tx, Rx signals via the function Port_Init.
        - Initialize clock to Tx, Rx signals via the function Mcu_Init.
        - Initialize timeout OsIf_Init.
        - Initialize Fr module Fr_43_LLCE_Init.
        - Initialize controller, initialize Tx and Rx buffer via the function Fr_43_LLCE_ControllerInit.
		- Configurations for IRQ routing, priority and enable through Platform plugin via the function Platform_Init.
        - Invokes the controller CHI command ALLOW_COLDSTART via the function Fr_43_LLCE_AllowColdstart.
        - Starts communication to sync with other node in bus via the function Fr_43_LLCE_StartCommunication.
        - Wait POC status is FR_POCSTATE_NORMAL_ACTIVE via the function Fr_43_LLCE_GetPOCStatus and check in the loop.
        - Wait time slot to Transmit the frame
        - Transmit the frame via Fr_43_LLCE_TransmitTxLPdu
        - Wait time slot to Verify the Transmit frame
        - Verify Transmit frame via Fr_43_LLCE_CheckTxLPduStatus.
        - Stop communication by the function Fr_43_LLCE_AbortCommunication.
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - S32G-PROCEVB-S PCB RevX3 SCH RevB1 (Mini-module)
            - S32GRV-PLATEVB PCB Rev A SCH RevB (Mother-board)
        2.2.2 Connections
            In mother board, j43: jumper(1-2, 3-4, 5-6)
							 j44: jumper(1-2, 3-4, 5-6)
            Using female Connector Housing cable to connect port Flexray between two boards.
        2.2.3 Debugger
            The debugger must be connected to J48 20-pin JTAG Cortex Debug connector.
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed in the Tresos Studio plugins directory
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder
                    e. Optional* - Select "Copy projects into workspace"
                    f. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR =  C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
			- T32_DIR The path to the T32 dir
                Ex: T32_DIR =  E:/t32/t32_s32cc
			- LLCE_BIN_LOCATION The path to the llce bin location dir
                Ex: LLCE_BIN_LOCATION =  C:/NXP/S32G_LLCE_1.0.7/firmware/llce_bin/s32g2/bin/ghs/enablemen
			- LLCE_INTERFACE_LOCATION The path to the llce interface location dir
                Ex: LLCE_INTERFACE_LOCATION =  C:/NXP/S32G_LLCE_1.0.7/firmware/llce_interface
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32G_RTD_4.4_4.0.2/eclipse/plugins
			- PLUGINS_DIR_ADDON The path to the LLCE plugins directory
                Ex: PLUGINS_DIR_ADDON = ../../../../../(default)
			- AR_PKG_NAME The package name for the RTD release
                Ex: AR_PKG_NAME = TS_T40D11M40I2R0
			- AR_PKG_NAME_ADDON The package name for the LLCE release
                Ex: AR_PKG_NAME_ADDON = TS_T40D11M10I7R0
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate subdirectory
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.3 Running the application on the board
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
