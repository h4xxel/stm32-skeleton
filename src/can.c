#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <stm32/can.h>
#include <stm32/rcc.h>
#include <stm32/syscfg.h>
#include <stm32/gpio.h>

static int filter_number[2] = {0, 0};
static int free_filter_bank = 0;

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
	
	/* Reset CAN peripheral */
	CAN.mcr.reset = true;
	while(CAN.mcr.reset);
	
	/* Set init mode */
	CAN.mcr.inrq = true;
	CAN.mcr.sleep = false;
	while(!CAN.msr.inak);
	while(CAN.msr.slak);
	
	CAN.fmr.finit = true;
	CAN.fmr.can2sb = 1;
	CAN.fa1r = 0x0;
	free_filter_bank = 0;
	filter_number[0] = 0;
	filter_number[1] = 0;
	
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
	
	/* Set normal mode */
	CAN.mcr.inrq = true;
	while(CAN.msr.inak);
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
		CAN.tx_mbox[mbox].tir.stid = id >> 18;
		CAN.tx_mbox[mbox].tir.exid = id;
	} else {
		CAN.tx_mbox[mbox].tir.stid = id;
		CAN.tx_mbox[mbox].tir.exid = 0;
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

int can_recv(uint8_t fifo, uint8_t *data, uint8_t *matched_filter, bool *extended_id, uint32_t *id, uint16_t *timestamp) {
	uint8_t _matched_filter;
	uint32_t _id;
	bool _extended_id;
	uint16_t _timestamp;
	int len, i;
	
	if(fifo > 1)
		return -1;
	
	/* Wait until old fifos properly released*/
	while(CAN.rf[fifo].rfom);
	/* Wait until message available */
	while(CAN.rf[fifo].fmp == 0);
	
	/* ID */
	_extended_id = CAN.rx_mbox[fifo].rir.ide;
	if(_extended_id)
		_id = CAN.rx_mbox[fifo].rir.reg >> 3;
	else
		_id = CAN.rx_mbox[fifo].rir.stid;
	
	if(extended_id)
		*extended_id = _extended_id;
	
	if(id)
		*id = _id;
	
	/* Filter */
	_matched_filter = CAN.rx_mbox[fifo].rdtr.fmi;
	if(matched_filter)
		*matched_filter = _matched_filter;
	
	/* Data */
	len = CAN.rx_mbox[fifo].rdtr.dlc;
	
	if(data) {
		for(i = 0; i < len; i++)
			data[i] = CAN.rx_mbox[fifo].data[i];
	}
	
	/* Timestamp */
	_timestamp = CAN.rx_mbox[fifo].rdtr.time;
	if(timestamp)
		*timestamp = _timestamp;
	
	/*Release FIFO*/
	CAN.rf[fifo].rfom = true;
	
	return len;
}

int can_try_recv(uint8_t fifo, uint8_t *data, uint8_t *matched_filter, bool *extended_id, uint32_t *id, uint16_t *timestamp) {
	if(fifo > 1)
		return -1;
	
	/* Wait until old fifos properly released*/
	while(CAN.rf[fifo].rfom);
	
	if(CAN.rf[fifo].fmp == 0)
		return -1;
	
	return can_recv(fifo, data, matched_filter, extended_id, id, timestamp);
}

static void _set_filter(uint8_t filter, uint8_t fifo, uint32_t ident1, uint32_t ident2, bool extended_id, bool ident) {
	//TODO: support 16 bit filters
	
	CAN.fmr.finit = true;
	CAN.fa1r &= ~(1 << filter);
	
	if(ident) {
		CAN.fm1r |= (1 << filter);
	} else {
		CAN.fm1r &= ~(1 << filter);
	}
	
	CAN.fs1r |= (1 << filter);
	
	if(fifo == 0) {
		CAN.ffa1r &= ~(1 << filter);
	} else {
		CAN.ffa1r |= (1 << filter);
	}
	
	if(extended_id) {
		CAN.filter[filter].fr0 = (ident1 << 21) | ((ident1 & 0x1FFFF800) >> 8) | (1 < 2);
		CAN.filter[filter].fr1 = (ident2 << 21) | ((ident2 & 0x1FFFF800) >> 8) | (1 < 2);
	} else {
		CAN.filter[filter].fr0 = (ident1 << 21);
		CAN.filter[filter].fr1 = (ident2 << 21);
	}
	
	CAN.fa1r |= (1 << filter);
	CAN.fmr.finit = false;
}

int can_set_filter_mask(uint8_t fifo, uint32_t mask, uint32_t ident, bool extended_id) {
	int number;
	
	if(fifo > 1)
		return -1;
	
	_set_filter(free_filter_bank, fifo, ident, mask, extended_id, true);
	
	number = filter_number[fifo];
	filter_number[fifo]++;
	
	return number;
}

int can_set_filter_ident(uint8_t fifo, uint32_t ident1, uint32_t ident2, bool extended_id) {
	int number;
	
	if(fifo > 1)
		return -1;
	
	_set_filter(free_filter_bank, fifo, ident1, ident2, extended_id, true);
	
	number = filter_number[fifo];
	filter_number[fifo] += 2;
	
	free_filter_bank++;
	
	return number;
}
