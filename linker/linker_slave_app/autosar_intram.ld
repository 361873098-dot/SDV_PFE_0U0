/*
 *  Copyright 2020-2023 NXP
 *
 *  NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 *
 *  This file contains sample code only. It is not part of the production code deliverables.
 */

/*
* GHS Linker Command File:
* 0x20100000	0x2010FFFF	64KB	M7_0 TCM Backdoor
* 0x20180000	0x2018FFFF	64KB	M7_1 TCM Backdoor
* 0x20200000	0x2020FFFF	64KB	M7_2 TCM Backdoor
* 0x24000000	0x33FFFFFF	262144	Standby RAM (32K)
* 0x34000000	0x34800000	8MB	Internal SRAM
*/

DEFAULTS
{
    int_results_reserve = 0x100
}

MEMORY
{
    int_itcm                            : ORIGIN = 0x00000000, LENGTH = 0x00000000 /* 0KB - Not Supported */
    int_dtcm                            : ORIGIN = 0x20000000, LENGTH = 0x0000E000 /* 56KB  */
    int_dtcm_stack                      : ORIGIN = 0x2000E000, LENGTH = 0x00002000 /* 8KB  */
    int_sram_shareable                  : ORIGIN = 0x22C00000, LENGTH = 0x00004000 /* 16KB  */
    int_sram_bmu_mem                    : ORIGIN = 0x34000000, LENGTH = 0x00080000 /* 512KB */
    int_sram_pfe_rt_poll_linux          : ORIGIN = 0x34080000, LENGTH = 0x00020000 /* 128KB PFE rt poll linux */
    int_sram_slave_no_cacheable         : ORIGIN = 0x340A0000, LENGTH = 0x00060000 /* 384KB */
    int_sram_ipcf_linux                 : ORIGIN = 0x34100000, LENGTH = 0x00100000 /* 1MB IPCF linux */
    int_sram_ipcf_mcal                  : ORIGIN = 0x34200000, LENGTH = 0x00100000 /* 1MB IPCF mcal */
    int_sram_atf                        : ORIGIN = 0x34300000, LENGTH = 0x00090000 /* 576KB ATF */
    int_sram_master_no_cacheable        : ORIGIN = 0x34390000, LENGTH = 0x0006F000 /* 444KB */
    int_sram_slave_shared_log_stat      : ORIGIN = 0x343FF000, LENGTH = 0x00000800 /* 2KB */
    int_sram_master_shared_log_stat     : ORIGIN = 0x343FF800, LENGTH = 0x00000800 /* 2KB */
    int_sram_stack_c0                   : ORIGIN = 0x34400000, LENGTH = 0x00002000 /* 8KB */
    int_sram_stack_c1                   : ORIGIN = 0x34402000, LENGTH = 0x00002000 /* 8KB */
    int_sram_stack_c2                   : ORIGIN = 0x34404000, LENGTH = 0x00002000 /* 8KB */
    int_sram_stack_c3                   : ORIGIN = 0x34406000, LENGTH = 0x00002000 /* 8KB */
    int_sram_end_stack_not_use          : ORIGIN = 0x34408000, LENGTH = 0x00008000 /* 32KB not used */
    int_sram_firmware                   : ORIGIN = 0x34410000, LENGTH = 0x00010000 /* PFE firmware 64KB */
    int_sram_master                     : ORIGIN = 0x34420000, LENGTH = 0x001E0000 /* 1920KB */
    int_sram_slave                      : ORIGIN = 0x34600000, LENGTH = 0x00200000 /* 2MB */
    ram_rsvd2                           : ORIGIN = 0x34800000, LENGTH = 0          /* End of SRAM */

    LLCE_CAN_SHAREDMEMORY   : ORIGIN = 0x43800000 LENGTH = 0x3D000
    LLCE_LIN_SHAREDMEMORY   : ORIGIN = 0x4383D000 LENGTH = 0x3000
    LLCE_BOOT_END           : ORIGIN = 0x43840000 LENGTH = 0x50
}

SECTIONS
{
    .core_loop                                   ALIGN(4)     : > int_sram_slave
    .startup                                     ALIGN(4)     : > . /* Reset code*/
    .systeminit                                  ALIGN(4)     : > . /* SystemInit */
    .text.startup                                ALIGN(4)     : > .
    .text                                        ALIGN(4)     : > .
    .ghtws.text                                  ALIGN(4)     : > .
    .mcal_text                                   ALIGN(4)     : > .

    .rodata                                      ALIGN(4)     : > .
    .mcal_const_cfg                              ALIGN(4)     : > .
    .mcal_const                                  ALIGN(4)     : > .
    .init_table                                  ALIGN(4)     : > .
    .zero_table                                  ALIGN(4)     : > .

    .acfls_code_rom                              ALIGN(4)     : > .
    .aceep_code_rom                              ALIGN(4)     : > .
    .acmcu_code_rom                              ALIGN(4)     : > .
    .ramcode                                 ABS ALIGN(4)     : > .
    .data                                        ALIGN(4)     : > .
    .mcal_data                                   ALIGN(4)     : > .
    .bss                               (NOLOAD)  ALIGN(16)    : > .
    .mcal_bss                          (NOLOAD)  ALIGN(16)    : > .

    .intc_vector                               ALIGN(4096)    : > int_sram_slave_no_cacheable
    /* Make sure that this section is placed within supported memory range 0x40000 to 0xBFFFFFFF */
    .pfe_buf_mem                               ALIGN(4)       : > .
    .pfe_bd_mem                                ALIGN(4)       : > .
    .mcal_bss_no_cacheable            (NOLOAD) ALIGN(16)      : > .
    .mcal_data_no_cacheable                    ALIGN(4)       : > .
    .mcal_const_no_cacheable                   ALIGN(4)       : > .
    .pfe_ddr_pool                              ALIGN(4096)    : > .

    .llce_boot_end                                            : > LLCE_BOOT_END
    .can_43_llce_sharedmemory                                 : > LLCE_CAN_SHAREDMEMORY
    .lin_43_llce_sharedmemory                                 : > LLCE_LIN_SHAREDMEMORY

    .mcal_shared_bss                  (NOLOAD) ALIGN(16)      : > int_sram_shareable
    .mcal_shared_data                          ALIGN(16)      : > .

    .intc_vector_dtcm   (NOLOAD) ALIGN(2048) PAD(SIZEOF(.intc_vector)) : > int_dtcm

    __Stack_dtcm_end         = ADDR(int_dtcm_stack);
    __Stack_dtcm_start       = ADDR(int_dtcm_stack) + SIZEOF(int_dtcm_stack);

    __Stack_end_c0           = ADDR(int_sram_stack_c0);
    __Stack_start_c0         = ADDR(int_sram_stack_c0) + SIZEOF(int_sram_stack_c0);
    __Stack_end_c1           = ADDR(int_sram_stack_c1);
    __Stack_start_c1         = ADDR(int_sram_stack_c1) + SIZEOF(int_sram_stack_c1);
    __Stack_end_c2           = ADDR(int_sram_stack_c2);
    __Stack_start_c2         = ADDR(int_sram_stack_c2) + SIZEOF(int_sram_stack_c2);
    __Stack_end_c3           = 0;
    __Stack_start_c3         = 0;

    __INT_SRAM_START         = ADDR(int_sram_slave);
    __INT_SRAM_END           = ADDR(ram_rsvd2);

    __INT_ITCM_START         = ADDR(int_itcm);
    __INT_ITCM_END           = ADDR(int_itcm) + SIZEOF(int_itcm);

    __INT_DTCM_START         = ADDR(int_dtcm);
    __INT_DTCM_END           = ADDR(int_dtcm) + SIZEOF(int_dtcm) + SIZEOF(int_dtcm_stack);

    __RAM_SHAREABLE_START    = ADDR(int_sram_shareable);
    __RAM_SHAREABLE_END      = ADDR(int_sram_shareable) + SIZEOF(int_sram_shareable) - 1;
    __ROM_SHAREABLE_START    = 0;
    __ROM_SHAREABLE_END      = 0;
    __RAM_NO_CACHEABLE_START = ADDR(int_sram_slave_no_cacheable);
    __RAM_NO_CACHEABLE_END   = ADDR(int_sram_slave_no_cacheable) + SIZEOF(int_sram_slave_no_cacheable) - 1;
    __SHARED_LOG_STATISTICS  = ADDR(int_sram_slave_shared_log_stat);
    __ROM_NO_CACHEABLE_START = 0;
    __ROM_NO_CACHEABLE_END   = 0;
    __RAM_CACHEABLE_START    = ADDR(int_sram_slave);
    __RAM_CACHEABLE_END      = ADDR(int_sram_slave) + SIZEOF(int_sram_slave) - 1;
    __ROM_CACHEABLE_START    = 0;
    __ROM_CACHEABLE_END      = 0;

    __BSS_SRAM_START         = ADDR(.bss);
    __BSS_SRAM_SIZE          = SIZEOF(.bss)+SIZEOF(.mcal_bss);
    __BSS_SRAM_END           = __BSS_SRAM_START + __BSS_SRAM_SIZE;

    __BSS_SRAM_NC_START      = ADDR(.mcal_bss_no_cacheable);
    __BSS_SRAM_NC_SIZE       = SIZEOF(.mcal_bss_no_cacheable);
    __BSS_SRAM_NC_END        = __BSS_SRAM_NC_START + __BSS_SRAM_NC_SIZE;

    __BSS_SRAM_SH_START      = ADDR(.mcal_shared_bss);
    __BSS_SRAM_SH_SIZE       = SIZEOF(.mcal_shared_bss);
    __BSS_SRAM_SH_END        = __BSS_SRAM_SH_START + __BSS_SRAM_SH_SIZE;

    __RAM_INTERRUPT_START    = ADDR(.intc_vector_dtcm);
    __INIT_INTERRUPT_START   = ADDR(.intc_vector);
    __INIT_INTERRUPT_END     = ADDR(.intc_vector) + SIZEOF(.intc_vector);

    __INIT_TABLE             = ADDR(.init_table);
    __ZERO_TABLE             = ADDR(.zero_table);

    __RAM_INIT               = 0;
    __ITCM_INIT              = 0;
    __DTCM_INIT              = 1;

    __RAM_DTCM_START         = 0;
    __RAM_DTCM_END           = 0;
    __ROM_DTCM_START         = 0;
    __ROM_DTCM_END           = 0;

   /* Discard boot header in RAM */
   /DISCARD/ : { *(.boot_header) }

   __INDEX_COPY_CORE2       = 3;    /* This symbol is used to initialize data of ITCM/DTCM for secondary cores */
}
