#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/usb.h>
#include <stm32/gpio.h>
#include <stm32-lib/usb.h>


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
	//~ NVIC_EnableIRQ(INTERRUPT_USB);
	//~ NVIC_SetPriority(INTERRUPT_USB, 2);
	//~ __enable_irq();
	USB.cntr.pdwn = false;
	USB.cntr.reg = 0xFF81;
	delay(10000);
	USB.cntr.reg = 0xFF80;
	USB.istr.reg = 0x0;

	USB.btable.reg = 0x0;

	USB.bcdr.dppu = false;

	USB.endpoint[0].reg = 0x3230;
}

void isr_usb() {
	GPIOB.output.pin1 = 1;
}