#include <stdint.h>

#include <stm32/interrupts.h>
#include <stm32/exceptions.h>

void _start();
extern uint32_t __stack_end__;

void unhandled_irq(void) {
	return;
}

extern void (* const __exceptions[])(void);
void (* const __exceptions[])(void)  __attribute__ ((section(".exceptions"))) = {
	/* ARM Cortex M exception vectors*/
	(void (*)(void)) & __stack_end__,	
	_start,
	
	[EXCEPTION_NMI] = unhandled_irq,
	[EXCEPTION_HARD_FAULT] = unhandled_irq,
	[EXCEPTION_MEM_MANAGE] = unhandled_irq,
	[EXCEPTION_BUS_FAULT] = unhandled_irq,
	[EXCEPTION_USAGE_FAULT] = unhandled_irq,
	[EXCEPTION_SV_CALL] = unhandled_irq,
	[EXCEPTION_DEBUG_MONITOR] = unhandled_irq,
	[EXCEPTION_PEND_SV] = unhandled_irq,
	[EXCEPTION_SYSTICK] = unhandled_irq,
};

extern void (* const __interrupts[])(void);
void (* const __interrupts[INTERRUPTS])(void)  __attribute__ ((section(".interrupts"))) = {
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