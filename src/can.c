#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/can.h>
#include <stm32/rcc.h>
#include <stm32/syscfg.h>
#include <stm32/gpio.h>

void can_setup(uint16_t baud_rate_prescale, uint8_t ts1, uint8_t ts2) {
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
	
	/* Set init mode */
	CAN.mcr.inrq = true;
	CAN.mcr.sleep = false;
	while(!CAN.msr.inak);
	while(CAN.msr.slak);
	
	/* Set baudrate */
	/*
		Baudrate = 1/NominalBitTime
		NominalBitTime = 1*tq + tbs1 + tbs2
		tq is Time Quanta, smallest time unit
		tq = (BRP + 1) * tPCLK
		tbs1 = (TS1 + 1) * tq
		tbs2 = (TS2 + 1) * tq
	*/
	CAN.btr.ts1 = ts1;
	CAN.btr.ts2 = ts2;
	CAN.btr.brp = baud_rate_prescale;
	CAN.btr.sjw = 2;
}

void can_initialize() {
	
}

void can_transmit(uint32_t id, bool extended_id, size_t len, uint8_t *buf) {
	int mbox;
	uint8_t empty;
	volatile uint8_t *to;
	
	if(len > 8)
		return;
	
	/* Find empty mailbox */
	do {
		mbox = CAN.tsr.code;
		empty = CAN.tsr.tme;
	} while(!(empty & (1 << mbox)));
	
	/* ID */
	if(extended_id) {
		CAN.tx_mbox[mbox].tir.stid = id;
		CAN.tx_mbox[mbox].tir.exid = 0;
	} else {
		CAN.tx_mbox[mbox].tir.stid = id >> 18;
		CAN.tx_mbox[mbox].tir.exid = id;
	}
	
	CAN.tx_mbox[mbox].tir.ide = extended_id;
	CAN.tx_mbox[mbox].tir.rtr = false;
	
	/* Data */
	CAN.tx_mbox[mbox].tdtr.dlc = len;
	to = CAN.tx_mbox[mbox].data;
	while(len--)
		*to++ = *buf++;
	
	/* Request transmission of mailbox */
	CAN.tx_mbox[mbox].tir.txrq = true;
}
