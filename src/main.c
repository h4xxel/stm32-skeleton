#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/gpio.h>

#define RCC_BASE (0x40023800UL)
#define RCC_AHB1ENR *((volatile uint32_t *)(RCC_BASE + 0x30))

#define GPIOA_BASE (0x40020000UL)

volatile STM32GPIO *GPIOA = (volatile void *) GPIOA_BASE;

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
	RCC_AHB1ENR |= (1 << 0);
	
	GPIOA->mode.pin5 = STM32_GPIO_MODE_OUTPUT;
	for(;;) {
		GPIOA->output.pin5 = true;
		delay(100000);
		GPIOA->output.pin5 = false;
		delay(100000);
	}
	
	return 0;
}
