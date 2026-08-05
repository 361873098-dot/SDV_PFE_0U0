/**************************************************************************************
*
*   Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2013 Freescale Semiconductor Inc.
*   Copyright 2017,2023 NXP.
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct derivation
*      thereof.
*
*  Description:  GCC linker command file for AUTOSAR OS/S32XXv44
*
**************************************************************************************/
MEMORY
{
    IPCFsharedRAM (rw)  : ORIGIN = 0x34100000, LENGTH = 0x00200000
    OsInternalRAM (rwx) :   org = 0x34300000,  len = 0x30000 /* 192K of memory */
}

SECTIONS
{

     /* Interrupt vectors table */
    .all :
    {

    *(.vector)
    *(.startup)             /* reset code */
    *(.systeminit)      /* SystemInit */
    *(.text.startup)

    /* Code and constant area (all code and constant sections shall be placed between .osbegincode and .osendcode sections). */
    . = ALIGN(0x20);
    *(.osbegincode)  /* for mem protection only */
    *(.ostext)

    *(.oshook)
    *(.osrodata)
    *(.syscall)
    *(.secinfo)
    *(.rodata)
    *(.ossrodata)
    *(.sapp_c32)
    *(.sapp_c16)
    *(.sapp_cU)
    *(.sapp_c8)
    *(.text)
    *(.appcode)
    *(.ROM.data)


    *(.osendcode)    /* for mem protection only */


    /* ------------------------------------ OS stack area ------------------------------------ */
    . = ALIGN(0x20);
    *(.osstack)

    . = ALIGN(0x20);
    *(.osstack2)

    OS_NONCACHE_BSS_START  = . ;
    . = ALIGN(0x20);
    *(.osbeginnoncache)
    *(.osnoncacheablebss)
    . = ALIGN(0x20);
    *(.osendnoncache)
    OS_NONCACHE_BSS_END    = . ;

    /* ------------------------------------ OS application data ------------------------------------ */
/* Begin of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #1 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #2 for applications. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #1 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #1 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */

/* Begin of the RAM area #2 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */
/* End of the RAM area #2 for applications of the second core. Do not edit or delete this comment: it is used by the SysGen for GCC */




    /* -------------------------------------- Default data/bss --------------------------------- */
    *(.data)
    *(.osdata)                           /* it is empty */
    *(.ossdata)

    . = ALIGN(0x20);
    *(.sapp_v32_data)
    *(.sapp_v16_data)
    *(.sapp_vU_data)
    *(.sapp_v8_data)

    /* ------------------------------------ BSS sections ------------------------------------ */
    _bss_start = .;
    *(.osbss)
    *(.ossbss)

    . = ALIGN(0x20);
    *(.bss)
    *(.sbss)

    . = ALIGN(0x20);
    *(.sapp_v32_bss)
    *(.sapp_v16_bss)
    *(.sapp_vU_bss)
    *(.sapp_v8_bss)

    _bss_end = .;


    /* ------------------------------------ main stacks section ------------------------------------ */
    . = ALIGN(16);
    _Stack_end  = .;
    OS_MAIN_STACK_MIN = .;

    KEEP(*(.stack_main))

    _Stack_start = .; /* stack grows downward */
    OS_MAIN_STACK_MAX  = .;

    . = ALIGN(16);
    _Stack2_end  = .;
    OS2_MAIN_STACK_MIN = .;

    KEEP(*(.stack2_main))

    _Stack2_start = .; /* stack2 grows downward */
    OS2_MAIN_STACK_MAX  = .;

    } >OsInternalRAM

}

