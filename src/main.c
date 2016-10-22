#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/gpio.h>
#include <stm32/rcc.h>

#define RCC_BASE (0x40023800UL)
#define GPIOA_BASE (0x40020000UL)

volatile STM32GPIO *GPIOA = (volatile void *) GPIOA_BASE;
volatile STM32RCC *RCC = (volatile void *) RCC_BASE;

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
	RCC->ahb1_enr.gpio_a_en = true;
	
	GPIOA->mode.pin5 = STM32_GPIO_MODE_OUTPUT;
	for(;;) {
		GPIOA->output.pin5 = true;
		delay(1000000);
		GPIOA->output.pin5 = false;
		delay(1000000);
	}
	
	return 0;
}
