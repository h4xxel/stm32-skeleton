#include <stdint.h>
#include <stddef.h>

#include <interrupts.h>

int main();
extern uint32_t __stack_end__;

__attribute__((section(".runtime")))
void _start() {
	extern uint8_t __data_init_start__;
	extern uint8_t __data_start__;
	extern uint8_t __data_end__;
	extern uint8_t __bss_start__;
	extern uint8_t __bss_end__;
	uint8_t *cur, *target, *data;

	/* Clear .bss */
	cur = &__bss_start__;
	target = &__bss_end__;
	while(cur != target)
		*cur++ = 0;
	
	/* Initialize variables with compile time defined content */
	data = &__data_init_start__;
	cur = &__data_start__;
	target = &__data_end__;
	while(cur != target)
		*cur++ = *data++;
	
	/* Done setting everything up! */
	main();
	for(;;);
}

void unhandled_irq(void) {
	return;
}

extern void (* const __exceptions[])(void);
void (* const __exceptions[])(void)  __attribute__ ((section(".exceptions"))) = {
	/* ARM Cortex M0 exception vectors*/
	(void (*)(void)) & __stack_end__,	
	_start,
	unhandled_irq,	//NMI
	unhandled_irq,	//Hard fault
	NULL,		//Reserved
	NULL,		//Reserved
	NULL,		//Reserved
	NULL,		//Reserved
	NULL,		//Reserved
	NULL,		//Reserved
	NULL,		//Reserved
	unhandled_irq,	//SVCall
	NULL,		//Reserved
	NULL,		//Reserved
	unhandled_irq,	//PendSV
	unhandled_irq,	//The SysTick
};

extern void (* const __interrupts[])(void);
void (* const __interrupts[32])(void)  __attribute__ ((section(".interrupts"))) = {
	/* Peripheral interrupt vectors */
	[INTERRUPT_WWDG] = unhandled_irq,
	[INTERRUPT_PVD_VVDIO2] = unhandled_irq,
	[INTERRUPT_RTC] = unhandled_irq,
	[INTERRUPT_FLASH] = unhandled_irq,
	[INTERRUPT_RCC_CRS] = unhandled_irq,
	[INTERRUPT_EXTI0_1] = unhandled_irq,
	[INTERRUPT_EXTI2_3] = unhandled_irq,
	[INTERRUPT_EXTI4_15] = unhandled_irq,
	[INTERRUPT_TSC] = unhandled_irq,
	[INTERRUPT_DMA_CH1] = unhandled_irq,
	[INTERRUPT_DMA_CH23] = unhandled_irq,
	[INTERRUPT_DMA_CH4_5_6_7] = unhandled_irq,
	[INTERRUPT_ADC_COMP] = unhandled_irq,
	[INTERRUPT_TIM1_BRK_UP_TRG_COM] = unhandled_irq,
	[INTERRUPT_TIM1_CC] = unhandled_irq,
	[INTERRUPT_TIM2] = unhandled_irq,
	[INTERRUPT_TIM3] = unhandled_irq,
	[INTERRUPT_TIM6_DAC] = unhandled_irq,
	[INTERRUPT_TIM7] = unhandled_irq,
	[INTERRUPT_TIM14] = unhandled_irq,
	[INTERRUPT_TIM15] = unhandled_irq,
	[INTERRUPT_TIM16] = unhandled_irq,
	[INTERRUPT_TIM17] = unhandled_irq,
	[INTERRUPT_I2C1] = unhandled_irq,
	[INTERRUPT_I2C2] = unhandled_irq,
	[INTERRUPT_SPI1] = unhandled_irq,
	[INTERRUPT_SPI2] = unhandled_irq,
	[INTERRUPT_USART1] = unhandled_irq,
	[INTERRUPT_USART2] = unhandled_irq,
	[INTERRUPT_USART3_4_5_6_7_8] = unhandled_irq,
	[INTERRUPT_CEC_CAN] = unhandled_irq,
	[INTERRUPT_USB] = unhandled_irq,
};

