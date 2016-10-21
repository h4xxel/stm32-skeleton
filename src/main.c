#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define RCC_BASE (0x40021000UL)
#define RCC_AHBENR *((volatile uint32_t *)(RCC_BASE + 0x14))

#define GPIOA_BASE (0x48000000UL)
#define GPIOA_MODE *((volatile uint32_t *)(GPIOA_BASE + 0x0))
#define GPIOA_ODR *((volatile uint32_t *)(GPIOA_BASE + 0x14))



void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
	RCC_AHBENR |= (1 << 17);
	GPIOA_MODE |= 0x00000005;
	for(;;) {
		GPIOA_ODR |= 0x3UL;
		delay(100000);
		GPIOA_ODR &= ~0x3UL;
		delay(100000);
	}
	
	return 0;
}
