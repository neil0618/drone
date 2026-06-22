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
    .text :
    {
        _stext = .;
        KEEP(*(.isr_vector))
        *(.text)
        *(.text*)
        _etext = .;
    } > FLASH

    .rodata :
    {
        _srodata = .;
        *(.rodata)
        *(.rodata*)
        _erodata = .;
    } > FLASH

    .data :
    {
        _sdata = .;
        *(.data)
        *(.data*)
        _edata = .;
    } > SRAM1 AT > FLASH

    _sidata = LOADADDR(.data);

    .bss :
    {
        _sbss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > SRAM1

    ._stack :
    {
        . = ALIGN(8);
        _estack = ORIGIN(SRAM1) + LENGTH(SRAM1);
    } > SRAM1

    ASSERT(_etext <= ORIGIN(FLASH) + LENGTH(FLASH), "ERROR: FLASH overflow after .text")
    ASSERT(_erodata <= ORIGIN(FLASH) + LENGTH(FLASH), "ERROR: FLASH overflow after .rodata")
    ASSERT((_sidata + (_edata - _sdata)) <= ORIGIN(FLASH) + LENGTH(FLASH), "ERROR: FLASH overflow after .data LMA")

    ASSERT(_edata <= ORIGIN(SRAM1) + LENGTH(SRAM1), "ERROR: SRAM1 overflow after .data")
    ASSERT(_ebss <= ORIGIN(SRAM1) + LENGTH(SRAM1), "ERROR: SRAM1 overflow after .bss")

    ASSERT((_estack - _ebss) >= 0x800, "ERROR: Insufficient space for stack, minimum 2KB required")
}