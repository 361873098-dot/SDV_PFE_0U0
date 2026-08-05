1. Example Description
    This application demonstrates the basic usage of the CanTrcv TJA1145A. It is not part of the production code deliverables.
    The application includes an DS project that configures the Base, Dem, Dio, Port, CanIf, EcuM, EcuC, Mcu, Platform, Port, Platform, Spi, CanTrcv_tja1145a drivers.
    This application demonstrates communication between can_0(tja1145a) and can_2(tja1153atk) in Real Time Drivers.
    1.1 The application software functionality
            - Port_Init
                    Initialize all pins using the Port driver
            - Mcu_Init
                    This function is to make the configuration setting for power down, clock and Ram sections visible within the MCU driver.
            - Mcu_InitClock
                    This function intializes the PLL and MCU specific clock options the clock setting is provided from the configuration structure.
            - Mcu_DistributePllClock
                    This function activates the PLL clock to the MCU clock distribution.
            - Mcu_SetMode
                    This function activates MCU power mode from config structure selected by McuMode parameter.
            - Platform_Init
                    Initializes the paltform settings based on user configuration.
            - Spi_Init
                    This function initializes the SPI driver using the pre-established configurations.
            - Can_43_FLEXCAN_Init
                    Initialize all the controllers.
            - CanTrcv_43_tja1145a_Init
                    Initializes all transceivers configured in ConfigPtr parameter.
            - CanTrcv_43_tja1145a_GetOpMode
                    Gets the mode of the Transceiver and returns it in OpMode.
            - SetMode_TJA115X
                    Put cantrcv_tja115x in standby mode by setting EN and STB pins in low level.
            - TJA115x_DRV_EnterConfigVanilla
                    Enter configuration mode on vanilla device, i.e.: Transmit CAN message for baudrate auto-detection.
            - Use TJA115x_CMD60_CONFIG_ID_CANID default and Tja115x_Can_SendFct function to configure of spoofing protection (command byte = 0x10.
            - TJA115x_DRV_LeaveConfig
                    Transmit message command to leave configuration mode.
            - SetMode_TJA115X
                    Put cantrcv_tja115x in normal mode by setting EN and STB pins in high level
            - Can_43_FLEXCAN_SetControllerMode
                    Set the FlexCAN_0 and FlexCAN_2 instance in START mode, allowing to participate to bus transfers.
            - Can_43_FLEXCAN_Write
                    Transmit information on CAN bus
            - Can_43_FLEXCAN_MainFunction_Write
                    Service for performs the polling of TX confirmation and TX cancellation confirmation when CAN_TX_PROCESSING is set to POLLING.
            - Can_43_FLEXCAN_MainFunction_Read
                    Service for performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
            - Can_43_FLEXCAN_SetControllerMode
                     Set the FlexCAN instance in STOP mode, this will prevent instance to participate to bus transactions and disable module clocks.
            - CanTrcv_43_tja1145a_DeInit
                     De-initialize all the transceivers. CanTrcv_43_tja1145a_DeInit shall de-initialize all the transceivers and set the driver in UNINIT state.
            - Spi_DeInit
                     The function de-initialize the SPI peripheral instance specified. All registers of SPI peripheral will be reset.
            - Exit_Example
    1.2 The application description
            - The application uses the SPI driver to configure cantrcv_tja1145a and use the FlexCan driver to config cantrcv_tja1153atk. After configuration are finish, the example will setup data for can_2 (tja1145a) to transmit the data to can_0.
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - S32K3XXEVB-T172
            - X-TJA1145A-EVB
        2.1.2 Prerequisites
            - Lauterbach base probe with Cortex-M debug probe
        2.1.3 Connections
            -          NXP TJA1145A BOARD     | S32K3X4-EVB     
                ------------------------------|-----------------
                RXD-      J3.2                | J38.13 (CAN2-TX)        
                TXD-      J3.1                | J38.11 (CAN2-RX)
                CANH-     J1.1                | J32-1          
                CANL-     J1.2                | J32-2          
                SPI_CLK-  J3-5                | J4-11          
                SPI_MOSI- J3-4                | J4-7               
                SPI_MISO- J3-3                | J4-9          
                SPI_CS-   J3-6                | J4-5              
                VCC-      J3.8                | J39-13
                VIO-      J3.9                | J4-19
                GND-      J3.12               | J2-9
                                              | CAN0_EN (TJA1153ATK)
                                              | CAN0_STB (TJA1153ATK)

        2.2.4 Debugger
           Connect Lauterbach to JTAG port on the board.
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
                Ex: TRESOS_DIR = C:/EB/tresos_29
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.3/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
            - PLUGINS_DIR The path to the Tresos plugins directory
                Ex: PLUGINS_DIR = C:/EB/tresos_29/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
                2. Copy CanTrcv_43_tja1145a_MemMap.h  file from rtd_update folder inside installed package to C:/NXP/SW32K3_RTD_4.4_R21-11_3.0.0/eclipse/plugins/BaseNXP_TS_T40D34M30I0R0/include folder
                3. Copy SchM_CanTrcv_tja1145a.h and SchM_CanTrcv_tja1145a.c files from rtd_update folder inside installed package to C:/NXP/SW32K3_RTD_4.4_R21-11_3.0.0/eclipse/plugins/Rte_TS_T40D34M30I0R0/ folders
3. Building the example application
    3.1 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.2 Running the application on the board
        To execute the example application load the executable file to the evaluation board using the Lauterbach debugger and the debug/test.cmm script.
    3.3 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
