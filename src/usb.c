#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/usb.h>
#include <stm32/gpio.h>
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

void isr_usb() {
	GPIOB.output.pin1 = 1;
}
