#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/usart.h>

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
	RCC.ahb1_enr.gpio_a_en = true;
	
	GPIOA.mode.pin5 = STM32_GPIO_MODE_OUTPUT;
	for(;;) {
		GPIOA.output.pin5 = true;
		delay(1000000);
		GPIOA.output.pin5 = false;
		delay(1000000);
	}
	
	return 0;
}
