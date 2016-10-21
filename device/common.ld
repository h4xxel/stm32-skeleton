/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2010, Roel Verdult
 * Modified 2016, Axel Isaksson (Adapted for STM32)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the
 * names of its contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

sram_top = ORIGIN(sram) + LENGTH(sram);
ENTRY(_start)

SECTIONS
{
	.text :
	{
		KEEP(*(.exceptions))
		KEEP(*(.interrupts))
		. = ALIGN(256);
		KEEP(*(.runtime))
		*(.text*)
		*(.rodata*)
	} > flash

	/*
	 * More information about Special Section Indexes is available in the
	 * free "ELF for the ARM Architecture" document from ARM Limited
	 * http://simplemachines.it/doc/aaelf.pdf
	 *
	 */
	.ARM.extab : { *(.ARM.extab* .gnu.linkonce.armextab.*) } > flash
	__exidx_start__ = .;
	.ARM.exidx : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) } > flash
	__exidx_end__ = .;

	_etext = .;
		
	.data : AT (__exidx_end__)
	{
		__data_init_start__ = LOADADDR (.data);
		PROVIDE(__data_init_start__ = __data_init_start__);
		__data_start__ = .;
		*(vtable)
		*(.data*)
		__data_end__ = .;
	} > sram

	/* zero initialized data */
	.bss :
	{
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		__bss_end__ = .;
	} > sram
	
	end = .;

	/* For GDB compatibility we decrease the top with 16 bytes */
	__stack_end__ = sram_top - 16;
}