ENTRY(nomain)

SECTIONS
{
    . = 0x08048000 + SIZEOF_HEADERS;

    TINYTEXT : {
        *(.text)
        *(.data)
        *(.rodata)
    }

    /DISCARD/ : {
        *(.comment)
    }
}