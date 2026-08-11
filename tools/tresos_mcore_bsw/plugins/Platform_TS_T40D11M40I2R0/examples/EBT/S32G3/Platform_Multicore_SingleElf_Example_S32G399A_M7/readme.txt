1. Example Description
    This application demonstrates the usage of a subset of Real Time Drivers.
    The application includes an EB Tresos project that configures the BaseNXP Platform Mcu EcuC Gpt Port Os Dio Resource Det Rte.
    This is a simple application which shows the usage of multicore feature on EB tresos for S32G399 derivative.
    Each core will configure and use its resources to blink 2 LEDs continuously with 1Hz frequency in PIT/STM interrupt.
    1.1 The application software functionality
            - For CM7_0: 
                + Calling Mcu_Init(), Mcu_InitClock(), Mcu_DistributePllClock(), Mcu_SetMode() APIs to initialize the system.
                + Enabling core CM7_1
                + Execute main_core0 task to blink LED with 1Hz frequency
            - For CM7_1:
                + Execute main_core1 task to blink LED with 1Hz frequency
            - Validation Point
                Receive 5 interrupts occuring for each interrupt source (both PIT,STM)
                    IsPassed = True (Verify that the Platform/MPU result returned corresponds to the expected value)

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - S32G-VNP-RDB3 PCB 53060 RevC SCH RevF, S32G3 silicon (Rev 1.1)
            - P32G399AACVUC SBAU2235 1P72B TIAUSBA
            - 1 PE Micro debugger
        2.1.2 Connections
            - Powered board through power Adapter 12V
        2.1.3 Debugger
            - Connect PE micro debugger to the board
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
            - TRESOS_DIR the installation path of the Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos/29.0.0
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = D:/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
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
