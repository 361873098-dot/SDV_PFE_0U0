1. Example Description
    This application demonstrates the basic usage of Thermal driver.
    The application includes an EB Tresos project that configures the Mcu, Platform and Thermal drivers.
    If the result is correct, the program will go through to the end of code without stuck in loop, and with bStatus variable set as "True".
    1.1 The application software functionality
            - Mcu_Init, Mcu_InitClock, Mcu_DistributePllClock, Mcu_SetMode
                    Initialize the clock sources, the clock tree and to configure the clock gating of the peripherals.
                    The clock configuration that is used will enable and use the PLL as source clock.
            - Platform_Init
                    Initialize the interrupt controller and to apply the interrupt configuration according to the Platform configuration.
            - Platform_InstallIrqHandler
                    Install the ISR for TMU used by the Thermal driver
            - Thermal_Init
                    Initialize the Thermal Driver.
            - Thermal_EnableNotifications
                    Enables the notification mechanism for the requested temperature threshold.
                    A high temperature threshold is set to a value lower than the normal ambient temperature,
                    to trigger the high temperature interrupt notification.
            - Wait for a notification to occur.
            - Thermal_DisableNotifications
            - Thermal_GetTemp
                    Get the temperature from all the configured monitoring sites.
            - Thermal_GetTempMinMaxLevel
                    Get the minimum and the maximum measured temperatures.
            - Check that temperature is within current platform range using K2C function to convert into Celsius degrees.
            - Thermal_Deinit
                    Returns Thermal HW Unit to a state comparable to its power on reset state.

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - Motherboard: S32GRV PLATEVB PCB RevA SCH RevB
            - Daughter card: S32G-PROCEVB-S PCB RevX3 SCH RevB1
            - Silicon: P32G274AABVUC 1P77B SBCH2250B (Rev 2.1)
        2.1.2 Connections
            No special wiring connections are needed for this example.
        2.1.3 Debugger
            - must be connected to the J48 20-pin JTAG Cortex Debug connector.
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
                Ex: TRESOS_DIR = C:/EB/tresos27_1_0
            - GCC_DIR The path to the GCC instalation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
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
