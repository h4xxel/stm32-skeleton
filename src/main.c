#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <core_cm0.h>

#include <stm32/syscfg.h>
#include <stm32/rcc.h>
#include <stm32/gpio.h>
#include <stm32/usb.h>
#include <stm32/interrupts.h>

void delay(volatile uint32_t i) {
	for(; i > 0; i--);
}

int main() {
	USB.istr.reg = 0;
	RCC.apb2_enr.syscfg_en = true;
	SYSCFG.cfgr1.pa11_pa12_rmp = true;
	
	RCC.ahb_enr.gpio_b_en = true;
	GPIOB.mode.pin1 = STM32_GPIO_MODE_OUTPUT;
	GPIOB.output.pin1 = 0;
	
	//Start 48 MHz internal clock
	RCC.cr2.hsi_48_on = true;
	while(!RCC.cr2.hsi_48_rdy);
	
	//Switch system clock to 48 MHz
	RCC.cfgr.sw = 3;
	while(RCC.cfgr.sws != 3);
	
	RCC.apb1_enr.usb_en = true;
	//~ NVIC_EnableIRQ(INTERRUPT_USB);
	//~ NVIC_SetPriority(INTERRUPT_USB, 2);
	//~ __enable_irq();
	USB.cntr.pdwn = false;
	USB.cntr.reg = 0xFF81;
	delay(10000);
	USB.cntr.reg = 0xFF80;
	USB.istr.reg = 0x0;
	
	USB.btable.reg = 0x0;
	
	USB.bcdr.dppu = false;
	
	USB.endpoint[0].reg = 0x3230;
	
	
	delay(10000);
	USB.bcdr.dppu = true;
	
	while(USB.istr.reg == 0);
	GPIOB.output.pin1 = 1;
	
	
	for(;;) {
	}
	
	return 0;
}
