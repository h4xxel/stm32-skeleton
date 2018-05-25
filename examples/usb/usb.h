#ifndef USB_H_
#define USB_H_

typedef enum USBRxBlockSize USBRxBlockSize;
enum USBRxBlockSize {
	USB_RX_BLOCK_SIZE_2B,
	USB_RX_BLOCK_SIZE_32B,
};

void usb_init();
void usb_enable();

void isr_usb();

#endif
