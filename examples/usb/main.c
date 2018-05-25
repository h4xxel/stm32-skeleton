#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/syscfg.h>
#include <stm32/usb.h>

#include "usb.h"

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

void setup_clock() {
	/* Set up internal 48 MHz as system and peripheral clock */
	RCC.cr2.hsi_48_on = true;
	while(!RCC.cr2.hsi_48_rdy);
	
	RCC.cfgr.sw = 0x3;
	while(RCC.cfgr.sw != 0x3);
	
	RCC.cfgr.hpre = 0x0;
	RCC.cfgr.ppre = 0x0;
}

int main() {
	setup_clock();
	
	RCC.ahb_enr.gpio_b_en = true;
	GPIOB.mode.pin1 = STM32_GPIO_MODE_OUTPUT;
	GPIOB.output.pin1 = 0;
	
	usb_init();
	
	delay(10000);
	
	usb_enable();
	
	for(;;);
	
	return 0;
}
