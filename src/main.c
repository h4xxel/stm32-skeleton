#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/usart.h>
#include <stm32/i2c.h>
#include <stm32/spi.h>

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

void uart_putc(char c) {
	while(!UART2.status.txe);
	UART2.data.reg = c;
}

void uart_init(uint32_t baud_rate) {
	RCC.apb1_enr.uart2_en = true;
	//hard code baud rate...
	//8.6875 for 115200 at 16 MHz
	//frac = 5
	//mantissa = 8
	//over8 = 0
	UART2.control1.ue = true;
	UART2.control1.m = 0;
	UART2.baudrate.div_fraction = 5;
	UART2.baudrate.div_mantissa = 8;
	UART2.control1.over8 = false;
	UART2.control1.te = true;
	
	GPIOA.mode.pin2 = 0x2;
	GPIOA.mode.pin3 = 0x2;
	
	GPIOA.alt_func_low.pin2 = 7;
	GPIOA.alt_func_low.pin3 = 7;
	
	//PA2
	//PA3
}

int main() {
	//AHB runs at 16 MHz, APB1 too
	
	RCC.ck_gatenr.ahb2_apb1_cken = true;
	RCC.ahb1_enr.gpio_a_en = true;
	uart_init(0);
	
	GPIOA.mode.pin5 = STM32_GPIO_MODE_OUTPUT;
	for(;;) {
		uart_putc('A');
		uart_putc('R');
		uart_putc('N');
		uart_putc('E');
		uart_putc('\r');
		uart_putc('\n');
		GPIOA.output.pin5 ^= 1;
	}
	
	return 0;
}
