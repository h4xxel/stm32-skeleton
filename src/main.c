#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>

#include "usb.h"

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
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
