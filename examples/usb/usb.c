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

#define USB_INTERRUPT_FLAG_CLEAR(a) do {USB.istr.reg = ~(1 << (a));} while(0)

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
	USB.cntr.reg = 0x8C01;//0xFF81;
	delay(10000);
	USB.cntr.reg = 0x8C00;//0xFF80;
	USB.istr.reg = 0x0;

	USB.btable.reg = 0x0;

	USB.bcdr.dppu = false;
}

void usb_setup_buffer(int buffer, uint32_t addr_tx, uint32_t size_tx, uint32_t addr_rx, USBRxBlockSize rx_block_size, int rx_blocks) {
	STM32USBBufferDescriptor *btable = (void *) (USB_BUFFER + USB.btable.reg);
	
	if(rx_blocks < 1)
		return;
	
	btable[buffer].addr_tx = addr_tx;
	btable[buffer].count_tx = size_tx;
	btable[buffer].addr_rx = addr_rx;
	btable[buffer].count_rx.blsize = rx_block_size;
	btable[buffer].count_rx.num_block = (rx_block_size == USB_RX_BLOCK_SIZE_2B) ? rx_blocks : rx_blocks - 1;
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
	
	if(!USB.istr.reg)
		return;
	
	if(USB.istr.reset) {
		usb_setup_buffer(0, 0x0, 0x0, 0x0, USB_RX_BLOCK_SIZE_32B, 4);
		USB.endpoint[0].reg = 0x3230;
		USB_INTERRUPT_FLAG_CLEAR(STM32_USB_INTERRUPT_FLAG_BIT_RESET);
		return;
	}
	
	if(USB.istr.susp) {
		USB.cntr.reg |= 0x08;
		USB_INTERRUPT_FLAG_CLEAR(STM32_USB_INTERRUPT_FLAG_BIT_SUSP);
		return;
	}
	
	if(USB.istr.ctr) {
		/* Correct transfer */
		GPIOB.output.pin1 = 1;
		endpoint = USB.istr.ep_id;
		
		USB.endpoint[endpoint].reg = 0x0;
		
		//USB_INTERRUPT_FLAG_CLEAR(STM32_USB_INTERRUPT_FLAG_BIT_CTR);
		return;
	}
}