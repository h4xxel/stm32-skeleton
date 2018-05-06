#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/usart.h>

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

void uart_putc(uint8_t c) {
	while(!USART2.isr.txe);
	USART2.tdr.tdr = c;
}

uint8_t uart_getc() {
	while(!USART2.isr.rxne);
	return USART2.rdr.rdr;
}

void uart_puts(char *s) {
	for(; *s; s++)
		uart_putc((uint8_t) *s);
}

int main() {
	setup_clock();
	
	RCC.ahb_enr.gpio_a_en = true;
	RCC.apb1_enr.usart2_en = true;
	
	
	USART2.brr.brr = 417;
	USART2.cr1.ue = true;
	USART2.cr1.te = true;
	USART2.cr1.re = true;
	
	for(;;) {
		uart_puts("arne\r\n");
		delay(1000000);
	}
	
	return 0;
}
