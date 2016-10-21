#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define RCC_BASE (0x40023800UL)
#define RCC_AHB1ENR *((volatile uint32_t *)(RCC_BASE + 0x30))

#define GPIOA_BASE (0x40020000UL)
#define GPIOA_MODE *((volatile uint32_t *)(GPIOA_BASE + 0x0))
#define GPIOA_ODR *((volatile uint32_t *)(GPIOA_BASE + 0x14))



void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
	RCC_AHB1ENR |= (1 << 0);
	GPIOA_MODE |= 0x1 << (5*2);
	for(;;) {
		GPIOA_ODR |= (1 << 5);
		delay(100000);
		GPIOA_ODR &= ~(1 << 5);
		delay(100000);
	}
	
	return 0;
}
