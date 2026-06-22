/* The first function executed on power on or reset */
ENTRY(Reset_Handler)

/* Defines memory locations and sizes of FLASH, SRAM1 and SRAM2 */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM1 (rwx) : ORIGIN = 0x20000000, LENGTH = 112K
    SRAM2 (rwx) : ORIGIN = 0x2001C000, LENGTH = 16K
}

SECTIONS
{
    /* Vector table and executable instructions from the code go into FLASH */
    .text :
    {
        _stext = .;
        KEEP(*(.isr_vector))
        *(.text)
        *(.text*)
        _etext = .;
    } > FLASH

    /* Read only data goes into FLASH */
    .rodata :
    {
        _srodata = .;
        *(.rodata)
        *(.rodata*)
        _erodata = .;
    } > FLASH

    /* Initialized data goes into FLASH and is copied to SRAM1 on startup by Reset_Handler */
    .data :
    {
        _sdata = .;
        *(.data)
        *(.data*)
        _edata = .;
    } > SRAM1 AT > FLASH /* .data Load Memory Address (LMA) goes into FLASH and .data Virtual Memory Address (VMA) goes into SRAM1 */

    _sidata = LOADADDR(.data); /* Location where .data LMA goes in FLASH */

    /* Uninitialized data (which is zeroed on startup) goes into SRAM1 */
    .bss :
    {
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON) /* Legacy uninitialized globals which are caught as a safety net */
        _ebss = .;
    } > SRAM1

    /* Stack at the top of SRAM1, grows downwards */
    ._stack :
    {
        . = ALIGN(8); /* Cortex-M4 Application Binary Interface (ABI) requires 8 byte aligned stack */
        _estack = ORIGIN(SRAM1) + LENGTH(SRAM1);
    } > SRAM1

    /* Checks for overflow in FLASH */
    ASSERT(_etext <= ORIGIN(FLASH) + LENGTH(FLASH), "ERROR: FLASH overflow after .text")
    ASSERT(_erodata <= ORIGIN(FLASH) + LENGTH(FLASH), "ERROR: FLASH overflow after .rodata")
    ASSERT((_sidata + (_edata - _sdata)) <= ORIGIN(FLASH) + LENGTH(FLASH), "ERROR: FLASH overflow after .data LMA")

    /* Checks for overflow in SRAM1 */
    ASSERT(_edata <= ORIGIN(SRAM1) + LENGTH(SRAM1), "ERROR: SRAM1 overflow after .data")
    ASSERT(_ebss <= ORIGIN(SRAM1) + LENGTH(SRAM1), "ERROR: SRAM1 overflow after .bss")

    /* Checks for minimum 2KB space for the stack*/
    ASSERT((_estack - _ebss) >= 0x800, "ERROR: Insufficient space for stack, minimum 2KB required")
}