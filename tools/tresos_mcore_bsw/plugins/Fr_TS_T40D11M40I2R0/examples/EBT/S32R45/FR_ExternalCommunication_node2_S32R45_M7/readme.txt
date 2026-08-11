1. Example Description
        Transmit and receive the frame between two nodes.
        The hardware setup for this example is two boards connected together with a Flexray cable. One board will run example for node 1, the other board will run example for node 2. This is because Flexray does not support loopbacking.
        This example uses for a board (Node 2).
    1.1 The application software functionality.
        - Initialize pins to provide the external clock to Tx, Rx signals via the function Port_Init.
        - Initialize clock to Tx, Rx signals via the function Mcu_Init.
        - Initialize timeout OsIf_Init.
        - Initialize Fr module Fr_Init.
        - Initialize controller, initialize Tx and Rx buffer via the function Fr_ControllerInit.
        - Invokes the controller CHI command 'ALLOW_COLDSTART via the function Fr_AllowColdstart.
        - Starts communication to sync with other node in bus via the function Fr_StartCommunication.
        - Wait POC status is FR_POCSTATE_NORMAL_ACTIVE via the function Fr_GetPOCStatus and check in the loop.
        - Wait time slot to receive the frame.
        - Get and verify receive frame via Fr_ReceiveRxLPdu.
        - Stop communication by the function Fr_AbortCommunication.
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - X-S32R45-PROC-S PCB RevB RevX5 SCH RevB1 (Mini-module)
            - S32GRV-PLATEVB PCB Rev A SCH RevB (Mother-board)
        2.2.2 Connections
            Connect all jumper for J43,J44,J24,J25.
            Using Connector Housing cable to connect port Flexray (J3,J4 or P1,P2) between two boards.
        2.2.3 Debugger
            The debugger must be connected to J190 20-pin JTAG Cortex Debug connector in Mini-module.
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
                Ex: TRESOS_DIR = C:/EB/tresos26
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.3/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
    3.1 Project parameters
        1. Go to the example folder and locate project_parameters.mk.
        2. In project_parameters.mk, update the "replace_<tool_type>_dir" lines for all required tools.
            For example, when running with GCC, update the following:
                - GCC_DIR The path to the GCC installation dir
                - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                - T32_DIR The path to the T32 installation dir
    3.2 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate subdirectory
    3.3 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.4 Running the application on the board
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.5 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
