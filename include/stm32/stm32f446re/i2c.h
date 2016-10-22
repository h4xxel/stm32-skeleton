#ifndef _STM32_STM32F446RE_I2C_H_
#define _STM32_STM32F446RE_I2C_H_

#include <stdint.h>

typedef union STM32I2CControl1 STM32I2CControl1;
union STM32I2CControl1 {
	uint32_t reg;
	struct {
		uint32_t pe : 1;
		uint32_t smbus : 1;
		uint32_t : 1;
		uint32_t smbtype : 1;
		uint32_t enarp : 1;
		uint32_t enpec : 1;
		uint32_t engc : 1;
		uint32_t no_stretch : 1;
		uint32_t start : 1;
		uint32_t stop : 1;
		uint32_t ack : 1;
		uint32_t pos : 1;
		uint32_t pec : 1;
		uint32_t alert : 1;
		uint32_t : 1;
		uint32_t sw_rst : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32I2CControl2 STM32I2CControl2;
union STM32I2CControl2 {
	uint32_t reg;
	struct {
		uint32_t freq : 6;
		
		uint32_t : 2;
		
		uint32_t iterr_en : 1;
		uint32_t itevt_en : 1;
		uint32_t itbuf_en : 1;
		uint32_t dma_en : 1;
		uint32_t last : 1;
		
		uint32_t : 19;
	};
};

typedef union STM32I2COwnAddress1 STM32I2COwnAddress1;
union STM32I2COwnAddress1 {
	uint32_t reg;
	struct {
		uint32_t add0 : 1;
		uint32_t add : 9;
		
		uint32_t : 5;
		
		uint32_t add_mode : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32I2COwnAddress2 STM32I2COwnAddress2;
union STM32I2COwnAddress2 {
	uint32_t reg;
	struct {
		uint32_t endual : 1;
		uint32_t add : 7;
		
		uint32_t : 24;
	};
};

typedef union STM32I2CData STM32I2CData;
union STM32I2CData {
	uint32_t reg;
	struct {
		uint32_t data : 8;
		
		uint32_t : 24;
	};
};

typedef union STM32I2CStatus1 STM32I2CStatus1;
union STM32I2CStatus1 {
	uint32_t reg;
	struct {
		uint32_t sb : 1;
		uint32_t addr : 1;
		uint32_t btf : 1;
		uint32_t add10 : 1;
		uint32_t stopf : 1;
		uint32_t : 1;
		uint32_t rxne : 1;
		uint32_t txe : 1;
		uint32_t berr : 1;
		uint32_t arlo : 1;
		uint32_t af : 1;
		uint32_t ovr : 1;
		uint32_t pecerr : 1;
		uint32_t : 1;
		uint32_t timeout : 1;
		uint32_t smbalert : 1;
		
		uint32_t : 16;
	};
};


typedef union STM32I2CStatus2 STM32I2CStatus2;
union STM32I2CStatus2 {
	uint32_t reg;
	struct {
		uint32_t msl : 1;
		uint32_t busy : 1;
		uint32_t tra : 1;
		uint32_t : 1;
		uint32_t gencall : 1;
		uint32_t smbdefault: 1;
		uint32_t smbhost : 1;
		uint32_t dualf : 1;
		
		uint32_t pec : 8;
		
		uint32_t : 16;
	};
};

typedef union STM32I2CClockControl STM32I2CClockControl;
union STM32I2CClockControl {
	uint32_t reg;
	struct {
		uint32_t ccr : 12;
		uint32_t : 2;
		uint32_t duty : 1;
		uint32_t f_s : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32I2CRiseTime STM32I2CRiseTime;
union STM32I2CRiseTime {
	uint32_t reg;
	struct {
		uint32_t trise : 6;
		
		uint32_t : 26;
	};
};

typedef union STM32I2CFilter STM32I2CFilter;
union STM32I2CFilter {
	uint32_t reg;
	struct {
		uint32_t dnf : 4;
		uint32_t anoff : 1;
		
		uint32_t : 27;
	};
};


typedef struct STM32I2C STM32I2C;
struct STM32I2C {
	STM32I2CControl1 control1;
	STM32I2CControl2 control2;
	STM32I2COwnAddress1 oar1;
	STM32I2COwnAddress2 oar2;
	STM32I2CData data;
	STM32I2CStatus1 status1;
	STM32I2CStatus2 status2;
	STM32I2CClockControl clock_control;
	STM32I2CRiseTime rise_time;
	STM32I2CFilter filter;
};



extern volatile STM32I2C I2C1;
extern volatile STM32I2C I2C2;
extern volatile STM32I2C I2C3;

#endif
