MEMORY {
	flash(rx): ORIGIN = 0x08000000, LENGTH = 16k
	sram(rwx): ORIGIN = 0x20000000, LENGTH = 4k
}

SYSCFG = 0x40010000;

GPIOF = 0x48001400;
GPIOE = 0x48001000;
GPIOD = 0x48000C00;
GPIOC = 0x48000800;
GPIOB = 0x48000400;
GPIOA = 0x48000000;

RCC = 0x40021000;

USB = 0x40005C00;
USB_BUFFER = 0x40006000;

CAN = 0x40006400;

USART1 = 0x40013800;
USART2 = 0x40004400;
USART3 = 0x40004800;
USART4 = 0x40004C00;
USART5 = 0x40005000;
USART6 = 0x40011400;
USART7 = 0x40011800;
USART8 = 0x40011C00;

ADC = 0x40012400;

SPI1 = 0x40013000;
I2C1 = 0x40005400;

TIM2 = 0x40000000;
TIM3 = 0x40000400;
TIM6 = 0x40001000;
TIM7 = 0x40001400;
TIM14 = 0x40002000;

INCLUDE "common.ld"
