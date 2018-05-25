#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <core_cm0.h>
#include <stm32/usb.h>
#include <stm32/gpio.h>
#include <stm32/rcc.h>
#include <stm32/syscfg.h>
#include <stm32/interrupts.h>
#include <stm32-lib/usb.h>

#include "usb.h"


UsbDescriptorString string_lang = {
	4,
	USB_DESCRIPTOR_TYPE_STRING,
	{0x4909},
};

UsbDescriptorString string_manufacturer = {
	14,
	USB_DESCRIPTOR_TYPE_STRING,
	u"h4xxel",
};

UsbDescriptorString string_product = {
	8,
	USB_DESCRIPTOR_TYPE_STRING,
	u"lol",
};

UsbDescriptor *descriptor_table[] = {
	(UsbDescriptor *) &string_lang,
	(UsbDescriptor *) &string_manufacturer,
	(UsbDescriptor *) &string_product,
};

void usb_init() {
	USB.istr.reg = 0;
	RCC.apb2_enr.syscfg_en = true;
	SYSCFG.cfgr1.pa11_pa12_rmp = true;
	
	RCC.apb1_enr.usb_en = true;
	
	USB.cntr.pdwn = false;
	USB.cntr.reg = 0x8401;//0xFF81;
	delay(10000);
	USB.cntr.reg = 0x8400;//0xFF80;
	USB.istr.reg = 0x0;

	USB.btable.reg = 0x0;

	USB.bcdr.dppu = false;
}

void usb_setup_buffer(int buffer, uint32_t addr_tx, uint32_t size_tx, uint32_t addr_rx, USBRxBlockSize rx_block_size, int rx_blocks) {
	STM32USBBufferDescriptor btable = (void *) (USB_BUFFER + USB.btable.reg);
	
	if(rx_blocks < 1)
		return;
	
	btable[buffer].addr_tx = addr_tx;
	btable[buffer].count_tx = count_tx;
	btable[buffer].addr_rx = addr_rx;
	btable[buffer].count_rx.blsize = rx_block_size;
	btable[buffer].count_rx.blocks = (rx_block_size == USB_RX_BLOCK_SIZE_2B) ? rx_blocks : rx_blocks - 1;
}

void usb_enable() {
	USB.istr.reg = 0x0;
	NVIC_EnableIRQ(INTERRUPT_USB);
	NVIC_SetPriority(INTERRUPT_USB, 2);
	__enable_irq();
	//for(;;);
	USB.bcdr.dppu = true;
}

void isr_usb() {
	int endpoint;
	
	GPIOB.output.pin1 = 1;
	if(USB.istr.reset) {
		USB.endpoint[0].reg = 0x3230;
		usb_setup_buffer(0, 0x0, 0x0, 0x0, USB_RX_BLOCK_SIZE_32B, 4);
		return;
	}
	
	if(USB.istr.ctr) {
		/* Correct transfer */
		endpoint = USB.istr.ep_id;
	}
}