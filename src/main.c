#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/gpio.h>
#include <stm32/rcc.h>

#define RCC_BASE (0x40023800UL)
#define GPIOA_BASE (0x40020000UL)

extern volatile STM32GPIO GPIOA;
extern volatile STM32RCC RCC;

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
	RCC.ahb1_enr.gpio_a_en = true;
	
	GPIOA.mode.pin5 = STM32_GPIO_MODE_OUTPUT;
	for(;;) {
		GPIOA.output.pin5 = true;
		delay(100000);
		GPIOA.output.pin5 = false;
		delay(100000);
	}
	
	return 0;
}
