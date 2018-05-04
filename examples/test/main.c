#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/can.h>

#include <stm32-lib/can.h>

//#define SENDER

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
	int i;
	setup_clock();
	
	//~ RCC.ahb_enr.gpio_a_en = true;
	//~ GPIOA.output.pin4 = 0;
	
	//~ GPIOA.mode.pin4 = STM32_GPIO_MODE_OUTPUT;
	
	//~ for(;;) {
		//~ for(i = 0; i < 20; i++) {
			//~ GPIOA.output.pin4 = 0x1;
			//~ delay(10000);
			//~ GPIOA.output.pin4 = 0x0;
			//~ delay(10000);
		//~ }
		
		//~ delay(1000000);
	//~ }
	
	GPIOB.output.pin1 = 0;
	
	RCC.ahb_enr.gpio_b_en = true;
	GPIOB.mode.pin1 = STM32_GPIO_MODE_OUTPUT;
	
	
	for(;;) {
		GPIOB.output.pin1 = 1;
		delay(1000000);
		GPIOB.output.pin1 = 0;
		delay(1000000);
	}
	
	return 0;
}
