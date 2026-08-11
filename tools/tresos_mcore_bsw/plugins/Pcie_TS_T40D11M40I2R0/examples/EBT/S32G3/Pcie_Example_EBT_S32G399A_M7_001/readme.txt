1. Example Description
    This example application demonstrates the usage of the PCIe driver for S32G3 in Endpoint (EP) mode.

    1.1 The application software functionality
        - The demo configures the Serdes PHY and the PCIe module for Endpoint mode, and presents a single PCIe Function to the Root Complex (RC). 
        - The BAR registers and the Internal Address Translation Unit (IATU) are configured to map some regions in the internal memory for usage by the Root Complex. 
        - After Serdes / PCIe initialization the Root Complex is able to configure the Endpoint, and also to read or write in the allocated memory regions, effectively using them as shared memory.
        - After initialization, the example project waits for the RC to communicate the address and size of an allocated region in the RC memory where the EP can read and write data. These parameters are written by RC in the first locations of the memory region configured in BAR0. 
        - After the RC data is received, the EP configures an outbound window to access this region and then does some DMA reads and writes. The transfered data is checked for correctness.
        - Finally, the example sends a few MSI interrupts to the RC to test the MSI feature.
        - The example checks the status of all API calls and also the correctness of the data and updates the variable u32NumFailedApiCalls. If this variable is 0 in the end of the example, it means the example passed.
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - S32G EVB Daughter Board - X-S32G-PROCEVB-S 700-32170 REV X3
            - Silicon: P32G399AACVUC 0P72B
            - RDB2 board: 700-47440 REV X2 (used as Root Complex)
        2.2.2 Connections
            N/A
        2.2.3 Debugger
            The debugger must be connected to J64 20-pin JTAG Cortex Debug connector.
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed in the Tresos Studio plugins directory
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" in General folder and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder
                    e. Optional* - Select "Copy projects into workspace" 
                    f. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Elektrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos27
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/NXP/gcc-9.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the command: make generate
            4. The output files of the generation shall be generated in the /generate subfolder
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the command: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subfolder
    3.3 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.

4. Running the application

    4.1 Hardware setup

        There are two boards required for this test: an EVB which runs the demo application in Endpoint mode, and an RDB2 board for the root complex. The demo is available only using an RDB as RC, other configurations are not supported. 
        The EVB PCIe X1 connector (U50) must be inserted in the RDB PCIe X1 connector (P1). The boards must be powered independently. 
        A micro-USB cable must connect the computer to the UART0 connector on the RDB2 (J2 - the second of the 3 USB connectors). 
        The LTB debugger is attached to the EVB for downloading the application.
        Both RC and EP will use PCIE1 instance.

    4.2 Jumper settings

        The following jumper settings are required for this demo. Only differences from the board's default settings are noted.

        RDB2:
         - switch SW17:  OFF
         - switch SW8:   OFF
        EVB:
         - J96:     2-3
         - J165:    1-2
         - SW12:    1 OFF, 2 ON, 3 ON, 4 ON
         - SW13:    1 OFF, 2 ON, 3 ON, 4 ON
         - SW14:    1 ON,  2 OFF
         - SW15:    1 OFF, 2 OFF
         - SW6:     1 OFF, 2 OFF, 3 OFF, 4 OFF, 5 OFF, 6 OFF, 7 ON,  8 OFF 
         - SW7:     1 OFF, 2 OFF, 3 OFF, 4 OFF, 5 OFF, 6 OFF, 7 OFF, 8 OFF 
         - SW8:     1 ON,  2 ON,  3 ON,  4 OFF, 5 OFF, 6 OFF, 7 ON,  8 OFF 
         - SW9:     1 OFF, 2 OFF, 3 OFF, 4 OFF, 5 OFF, 6 OFF, 7 OFF, 8 OFF 

    4.3 Root complex settings

        The RDB2 used as RC runs a linux image - auto_linux_bsp30.0_s32g2_pfe. The linux image must be copied on an SD card, from which the RDB will boot.
        The SD card must contain:
         - a 120MB region of unallocated space starting from address 0, in which the linux image will be copied
         - one 120MB FAT partition after the unallocated region, for storing other files needed by the demo

        The linux image must be copied in the unallocated region from the beginning of the SD card, for example using the dd command:

        dd if=<path_to_linux_image>/fsl-image-auto-s32g274ardb2.sdcard of=/dev/<sd_device> conv=notrunc

        A custom module used for the demo must be installed over Linux. The module, s32gep.ko, is included in the example folder together with some mini-scripts for installing and removing it. These files must be copied in the FAT partition of the SD card, to be installed after Linux boots.

        Also a terminal application is needed to communicate with the RDB2 board. The terminal settings must be:
        Speed:          115200
        Data:           8 bit
        Parity:         none
        Stop bits:      1 bit
        Flow control:   none

        The SD card is inserted in the SD card slot on the RDB2 board. When the RDB2 is powered on, it will boot from the card. When the message "Hit any key to stop autoboot" appears, hit any key to stop autoboot (EX. Hit the enter key on terminal console). Then check PCI settings using the command:

        printenv hwconfig

        To change the PCI settings, use the commands:

        setenv hwconfig "pcie1:mode=rc,clock=ext"
        saveenv
        reset

        After the reset the new settings will be used: pcie0 - unused; pcie1 in RC mode.

    4.4 Starting the Endpoint

        To start the Endpoint (EVB) you should first start the RDB2 and stop it in uboot (press a key at the message "Hit any key to stop autoboot"). This is because the EVB will be reset via the PCI connection when the RDB2 powers up.
        Open T32 and using the included script (debug\run.cmm), load the binary file obtained after building the example application. Run the application. The Endpoint is now initialized and configured, and it is waiting for RC to start.
        Now that the Endpoint is up and running you can start Linux on the RDB2 by typing the command

        boot

        After the linux boots, login as root and then load the s32gep.ko module. First mount the SD card, then install the module:
        mkdir ~/mnt
        mount /dev/mmcblk0p1 ~/mnt
        cd mnt/
        ./insert-s32gep.sh

        As soon as the module is installed, the example will start to run. The linux console will print messages about the received MSI interrupts. The example success can be verified by checking the variable u32NumFailedApiCalls in T32.

        Note that before shutting down the RDB board it is good practice to remove the module and unmount the device:
        ./remove-s32gep.sh
        cd ..
        umount /dev/mmcblk0p1

    4.5 Testing the Endpoint

        After the DMA transfers are completed the endpoint demo ends, but the PCIe module remains active and you can further test it with linux commands.
        The endpoint BDF (bus, device, function) identifier will be 01:00.0. You can check this with:

        lspci -t

        To display the endpoint properties you can use command:

        lspci -vvv -s 01:00.0

        This will display the base addresses and size of the allocated memory regions.
                Region 0: Memory at 4800100000 (32-bit, non-prefetchable) [size=64K]
                Region 1: Memory at 4800110000 (32-bit, non-prefetchable) [size=64K]
        Memory transaction are already enabled by the s32gep.ko module so you can start to read and write in the endpoint shared memory. For example:
        Read:
        devmem2 0x4800100000
        Write:
        devmem2 0x4800100000 w 0x12345678
        Note that the addresses from the examples above are in the range displayed by the lspci command.
