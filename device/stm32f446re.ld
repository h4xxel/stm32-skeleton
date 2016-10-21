MEMORY {
	flash(rx): ORIGIN = 0x08000000, LENGTH = 512k
	sram(rwx): ORIGIN = 0x20000000, LENGTH = 112k
	sram2(rwx): ORIGIN = 0x2001C000, LENGTH = 16k
}

INCLUDE "common.ld"