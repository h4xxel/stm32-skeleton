MEMORY {
	flash(rx): ORIGIN = 0x08000000, LENGTH = 32k
	sram(rwx): ORIGIN = 0x20000000, LENGTH = 6k
}

INCLUDE "common.ld"