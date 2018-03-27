#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/can.h>
#include <stm32/rcc.h>
#include <stm32/syscfg.h>
#include <stm32/gpio.h>

void can_setup(uint32_t baudrate) {
	/* Enable GPIO and CAN */
	RCC.ahb_enr.gpio_a_en = true;
	RCC.apb1_enr.can_en = true;
	
	/* Remap PA11 PA12 pins */
	RCC.apb2_enr.syscfg_en = true;
	SYSCFG.cfgr1.pa11_pa12_rmp = true;
	
	/* Setup pin functions */
	GPIOA.mode.pin11 = STM32_GPIO_MODE_ALT_FUNC;
	GPIOA.mode.pin12 = STM32_GPIO_MODE_ALT_FUNC;
	GPIOA.alt_func_high.pin11 = 0x4;
	GPIOA.alt_func_high.pin12 = 0x4;
	
	GPIOA.pull_up_down.pin11 = STM32_GPIO_PULL_NONE;
	GPIOA.pull_up_down.pin12 = STM32_GPIO_PULL_NONE;
	
	GPIOA.speed.pin11 = 0x3;
	GPIOA.speed.pin12 = 0x3;
	
	GPIOA.output_type.pin11 = STM32_GPIO_OUTPUT_TYPE_PUSH_PULL;
	GPIOA.output_type.pin12 = STM32_GPIO_OUTPUT_TYPE_PUSH_PULL;
}

void can_initialize() {
	
}

void can_transmit(size_t len, uint8_t *buf) {
	
}
