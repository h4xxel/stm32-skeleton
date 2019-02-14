#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/adc.h>
#include <stm32/usart.h>


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

void setup_adc() {
	RCC.apb2_enr.adc_en = true;
	delay(10000);
	
	if(ADC.cr.aden) {
		if(ADC.cr.adstart)
			ADC.cr.adstp;
		
		while(ADC.cr.adstp);
		
		ADC.cr.addis = true;
		
		while(ADC.cr.aden);
	}
	
	delay(10000);
	/* Calibrate ADC */
	ADC.cr.adcal = true;
	while(ADC.cr.adcal);
	
	
	/* Set up ADC clock to PCLK/4 */
	ADC.cfgr2.ckmode = 0x2;
	
	/* Set resolution 12 bits */
	ADC.cfgr1.res = 0x0;
	
	/* Enable ADC */
	ADC.cr.aden = true;
	while(!ADC.isr.adrdy);
	
	/* Set sampling time */
	ADC.smpr.smp = 0x7;
	
	ADC.ccr.ts_en = true;
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
	
	uart_putc('\r');
	uart_putc('\n');
}

void setup_uart() {
	RCC.apb1_enr.usart2_en = true;
	
	GPIOA.mode.pin2 = STM32_GPIO_MODE_ALT_FUNC;
	GPIOA.mode.pin3 = STM32_GPIO_MODE_ALT_FUNC;
	GPIOA.alt_func_low.pin2 = 0x1;
	GPIOA.alt_func_low.pin3 = 0x1;
	
	USART2.brr.brr = 417;
	USART2.cr1.ue = true;
	USART2.cr1.te = true;
	USART2.cr1.re = true;
}

int main() {
	uint16_t data;
	char *s = NULL;
	
	setup_clock();
	setup_adc();
	setup_uart();
	
	RCC.ahb_enr.gpio_b_en = true;
	//GPIOB.mode.pin1 = STM32_GPIO_MODE_ANALOG;
	ADC.chselr.chsel16 = true;
	
	RCC.ahb_enr.gpio_a_en = true;
	//~ GPIOA.output.pin4 = 0;
	
	//~ GPIOA.mode.pin4 = STM32_GPIO_MODE_OUTPUT;
	ADC.cr.adstart = true;
	
	for(;;) {
		while(!ADC.isr.eoseq);
		data = ADC.dr;
		ADC.isr.eoseq = 0x1;
		ADC.cr.adstart = true;
		
		s = uint_to_string(data);
		uart_puts(s);
	}
	
	return 0;
}
