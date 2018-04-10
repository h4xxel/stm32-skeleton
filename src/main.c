#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/can.h>

#include "can.h"

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
	uint8_t data[] = "THE GAME";
	setup_clock();
	
	GPIOB.output.pin1 = 0;
	
	RCC.ahb_enr.gpio_b_en = true;
	GPIOB.mode.pin1 = STM32_GPIO_MODE_OUTPUT;
	can_setup(5, 3, 2);
	//can_set_filter_ident(0, 0xDEAD, 0xBEEF, true);
	
	for(;;) {
		can_send(0xBEEF, true, 8, data);
		//can_recv(0, data, NULL, NULL, NULL, NULL);
		GPIOB.output.pin1 = 1;
		delay(1000000);
		//can_recv(0, data, NULL, NULL, NULL, NULL);
		GPIOB.output.pin1 = 0;
		delay(1000000);
	}
	
	return 0;
}
