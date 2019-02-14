#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/usart.h>
#include <stm32/can.h>

#include <stm32-lib/can.h>

/* Convert 8.8 bit fixed point to string representation*/
char *uint_to_string(uint16_t num) {
	uint32_t n;
	char *tmp;
	static char buf[10];
	
	n = num;
	tmp = buf + 8;
	*tmp = 0;
	do {
		*--tmp = (n  % 10) + '0';
		n /= 10;
	} while(n);
	
	return tmp;
}


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
	
	uart_putc('\n');
}

int main() {
	uint8_t data[] = "        ";
	setup_clock();
	
	RCC.ahb_enr.gpio_a_en = true;
	RCC.apb1_enr.usart2_en = true;
	
	GPIOA.mode.pin2 = STM32_GPIO_MODE_ALT_FUNC;
	GPIOA.mode.pin3 = STM32_GPIO_MODE_ALT_FUNC;
	GPIOA.alt_func_low.pin2 = 0x1;
	GPIOA.alt_func_low.pin3 = 0x1;
	
	USART2.brr.brr = 417;
	USART2.cr1.ue = true;
	USART2.cr1.te = true;
	USART2.cr1.re = true;
	
	can_setup(47, 3, 2);
	can_set_filter_ident(0, 0xBEEF, 0xBABE, true);
	
	for(;;) {
		can_recv(0, data, NULL, NULL, NULL, NULL);
		uart_puts(uint_to_string(*((uint16_t *) &data)));
	}
	
	return 0;
}
