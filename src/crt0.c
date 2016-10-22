#include <stdint.h>
#include <stddef.h>

#include <stm32/interrupts.h>
#include <stm32/exceptions.h>

int main();
extern uint32_t __stack_end__;

__attribute__((section(".runtime")))
void _start() {
	extern uint8_t __data_init_start__;
	extern uint8_t __data_start__;
	extern uint8_t __data_end__;
	extern uint8_t __bss_start__;
	extern uint8_t __bss_end__;
	uint8_t *dest, *source;

	/* Clear .bss */
	dest = &__bss_start__;
	while(dest != &__bss_end__)
		*dest++ = 0;
	
	/* Initialize variables with compile time defined content */
	source = &__data_init_start__;
	dest = &__data_start__;
	while(dest != &__data_end__)
		*dest++ = *source++;
	
	/* Done setting everything up! */
	main();
	for(;;);
}

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
	[INTERRUPT_PVD] = unhandled_irq,
	[INTERRUPT_TAMP_STAMP] = unhandled_irq,
	[INTERRUPT_RTC_WKUP] = unhandled_irq,
	[INTERRUPT_FLASH] = unhandled_irq,
	[INTERRUPT_RCC] = unhandled_irq,

	[INTERRUPT_EXTI0] = unhandled_irq,
	[INTERRUPT_EXTI1] = unhandled_irq,
	[INTERRUPT_EXTI2] = unhandled_irq,
	[INTERRUPT_EXTI3] = unhandled_irq,
	[INTERRUPT_EXTI4] = unhandled_irq,
	[INTERRUPT_EXTI4] = unhandled_irq,

	[INTERRUPT_DMA1_STREAM0] = unhandled_irq,
	[INTERRUPT_DMA1_STREAM1] = unhandled_irq,
	[INTERRUPT_DMA1_STREAM2] = unhandled_irq,
	[INTERRUPT_DMA1_STREAM3] = unhandled_irq,
	[INTERRUPT_DMA1_STREAM4] = unhandled_irq,
	[INTERRUPT_DMA1_STREAM5] = unhandled_irq,
	[INTERRUPT_DMA1_STREAM6] = unhandled_irq,

	[INTERRUPT_ADC] = unhandled_irq,

	[INTERRUPT_CAN1_TX] = unhandled_irq,
	[INTERRUPT_CAN1_RX0] = unhandled_irq,
	[INTERRUPT_CAN1_RX1] = unhandled_irq,
	[INTERRUPT_CAN1_SCE] = unhandled_irq,

	[INTERRUPT_EXTI9_5] = unhandled_irq,

	[INTERRUPT_TIM1_BRK_TIM9] = unhandled_irq,
	[INTERRUPT_TIM1_UP_TIM10] = unhandled_irq,
	[INTERRUPT_TIM1_TRG_COM_TIM11] = unhandled_irq,
	[INTERRUPT_TIM1_CC] = unhandled_irq,
	[INTERRUPT_TIM2] = unhandled_irq,
	[INTERRUPT_TIM3] = unhandled_irq,
	[INTERRUPT_TIM4] = unhandled_irq,

	[INTERRUPT_I2C1_EV] = unhandled_irq,
	[INTERRUPT_I2C1_ER] = unhandled_irq,
	[INTERRUPT_I2C2_EV] = unhandled_irq,
	[INTERRUPT_I2C2_ER] = unhandled_irq,

	[INTERRUPT_SPI1] = unhandled_irq,
	[INTERRUPT_SPI2] = unhandled_irq,

	[INTERRUPT_USART1] = unhandled_irq,
	[INTERRUPT_USART2] = unhandled_irq,
	[INTERRUPT_USART3] = unhandled_irq,

	[INTERRUPT_EXTI15_10] = unhandled_irq,

	[INTERRUPT_RTC_ALARM] = unhandled_irq,
	[INTERRUPT_OTG_FS_WKUP] = unhandled_irq,

	[INTERRUPT_TIM8_BRK_TIM12] = unhandled_irq,
	[INTERRUPT_TIM8_UP_TIM13] = unhandled_irq,
	[INTERRUPT_TIM8_TRG_COM_TIM14] = unhandled_irq,
	[INTERRUPT_TIM8_CC] = unhandled_irq,

	[INTERRUPT_DMA1_STREAM7] = unhandled_irq,
	[INTERRUPT_FMC] = unhandled_irq,
	[INTERRUPT_SDIO] = unhandled_irq,
	[INTERRUPT_TIM5] = unhandled_irq,
	[INTERRUPT_SPI3] = unhandled_irq,
	[INTERRUPT_UART4] = unhandled_irq,
	[INTERRUPT_UART5] = unhandled_irq,
	[INTERRUPT_TIM6_DAC] = unhandled_irq,
	[INTERRUPT_TIM7] = unhandled_irq,

	[INTERRUPT_DMA2_STREAM0] = unhandled_irq,
	[INTERRUPT_DMA2_STREAM1] = unhandled_irq,
	[INTERRUPT_DMA2_STREAM2] = unhandled_irq,
	[INTERRUPT_DMA2_STREAM3] = unhandled_irq,
	[INTERRUPT_DMA2_STREAM4] = unhandled_irq,

	[INTERRUPT_CAN2_TX] = unhandled_irq,
	[INTERRUPT_CAN2_RX0] = unhandled_irq,
	[INTERRUPT_CAN2_RX1] = unhandled_irq,
	[INTERRUPT_CAN2_SCE] = unhandled_irq,

	[INTERRUPT_OTG_FS] = unhandled_irq,

	[INTERRUPT_DMA2_STREAM5] = unhandled_irq,
	[INTERRUPT_DMA2_STREAM6] = unhandled_irq,
	[INTERRUPT_DMA2_STREAM7] = unhandled_irq,

	[INTERRUPT_USART6] = unhandled_irq,

	[INTERRUPT_I2C3_EV] = unhandled_irq,
	[INTERRUPT_I2C3_ER] = unhandled_irq,

	[INTERRUPT_OTG_HS_EP1_OUT] = unhandled_irq,
	[INTERRUPT_OTG_HS_EP1_IN] = unhandled_irq,
	[INTERRUPT_OTG_HS] = unhandled_irq,

	[INTERRUPT_DMCI] = unhandled_irq,

	[INTERRUPT_FPU] = unhandled_irq,

	[INTERRUPT_SPI4] = unhandled_irq,

	[INTERRUPT_SAI1] = unhandled_irq,
	[INTERRUPT_SAI2] = unhandled_irq,

	[INTERRUPT_QSPI] = unhandled_irq,
	[INTERRUPT_HDMI_CEC] = unhandled_irq,
	[INTERRUPT_SPDIF_RX] = unhandled_irq,

	[INTERRUPT_FMPI2C1] = unhandled_irq,
	[INTERRUPT_FMPI2C1_ERROR] = unhandled_irq,
};

