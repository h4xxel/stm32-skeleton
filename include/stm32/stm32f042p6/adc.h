#ifndef _STM32_STM32F042P6_ADC_H_
#define _STM32_STM32F042P6_ADC_H_

typedef union STM32ADCInterruptStatus STM32ADCInterruptStatus;
union STM32ADCInterruptStatus {
	uint32_t reg;
	struct {
		uint32_t adrdy : 1;
		uint32_t eosmp : 1;
		uint32_t eoc : 1;
		uint32_t eoseq : 1;
		uint32_t : 2;
		uint32_t awd : 1;
	};
};

typedef union STM32ADCInterruptEnable STM32ADCInterruptEnable;
union STM32ADCInterruptEnable {
	uint32_t reg;
	struct {
		uint32_t adrdy_ie : 1;
		uint32_t eosmp_ie : 1;
		uint32_t eoc_ie : 1;
		uint32_t ovr_ie : 1;
		uint32_t : 2;
		uint32_t awd_ie : 1;
	 };
};

typedef union STM32ADCControl STM32ADCControl ;
union STM32ADCControl {
	uint32_t reg;
	struct {
		uint32_t aden : 1;
		uint32_t addis : 1;
		uint32_t adstart : 1;
		uint32_t : 1;
		uint32_t adstp : 1;
		uint32_t : 26;
		uint32_t adcal : 1;
	};
};

typedef union STM32ADCConfiguration1 STM32ADCConfiguration1;
union STM32ADCConfiguration1 {
	uint32_t reg;
	struct {
		uint32_t dmaen : 1;
		uint32_t dmacfg : 1;
		uint32_t scandir : 1;
		uint32_t res : 2;
		uint32_t align : 1;
		uint32_t extsel : 3;
		uint32_t : 1;
		uint32_t exten : 2;
		uint32_t ovrmod : 1;
		uint32_t cont : 1;
		uint32_t wait : 1;
		uint32_t autoff : 1;
		uint32_t discen : 1;
		uint32_t : 5;
		uint32_t awdsgl : 1;
		uint32_t awden : 1;
		uint32_t : 2;
		uint32_t awdch : 5;
		uint32_t : 1;
	};
};

typedef union STM32ADCConfiguration2 STM32ADCConfiguration2;
union STM32ADCConfiguration2 {
	uint32_t reg;
	struct {
		uint32_t : 30;
		uint32_t ckmode : 2;
	};
};

typedef union STM32ADCSamplingTime STM32ADCSamplingTime;
union STM32ADCSamplingTime {
	uint32_t reg;
	struct {
		uint32_t smp : 3;
	};
};

typedef union STM32ADCWatchdogThreshold STM32ADCWatchdogThreshold;
union STM32ADCWatchdogThreshold {
	uint32_t reg;
	struct {
		uint32_t lt : 12;
		uint32_t : 4;
		uint32_t ht : 12;
		uint32_t : 4;
	};
};


typedef union STM32ADCChannelSelection STM32ADCChannelSelection;
union STM32ADCChannelSelection {
	uint32_t reg;
	struct {
		uint32_t chsel0 : 1;
		uint32_t chsel1 : 1;
		uint32_t chsel2 : 1;
		uint32_t chsel3 : 1;
		uint32_t chsel4 : 1;
		uint32_t chsel5 : 1;
		uint32_t chsel6 : 1;
		uint32_t chsel7 : 1;
		uint32_t chsel8 : 1;
		uint32_t chsel9 : 1;
		uint32_t chsel10 : 1;
		uint32_t chsel11 : 1;
		uint32_t chsel12 : 1;
		uint32_t chsel13 : 1;
		uint32_t chsel14 : 1;
		uint32_t chsel15 : 1;
		uint32_t chsel16 : 1;
		uint32_t chsel17 : 1;
		uint32_t chsel18 : 1;
	};
};

typedef union STM32ADCCommonConfiguration STM32ADCCommonConfiguration;
union STM32ADCCommonConfiguration {
	uint32_t reg;
	struct {
		uint32_t : 22;
		uint32_t vref_en : 1;
		uint32_t ts_en : 1;
		uint32_t vbat_en : 1;
	};
};


typedef struct STM32ADC STM32ADC;
struct STM32ADC {
	STM32ADCInterruptStatus isr;
	STM32ADCInterruptEnable ier;
	STM32ADCControl cr;
	STM32ADCConfiguration1 cfgr1;
	STM32ADCConfiguration2 cfgr2;
	STM32ADCSamplingTime smpr;
	uint32_t res[2];
	STM32ADCWatchdogThreshold tr;
	uint32_t res1;
	STM32ADCChannelSelection chselr;
	uint32_t res2[5];
	uint32_t dr;
	uint32_t res3[176];
	STM32ADCCommonConfiguration ccr;
	
};

extern volatile STM32ADC ADC;

#endif
