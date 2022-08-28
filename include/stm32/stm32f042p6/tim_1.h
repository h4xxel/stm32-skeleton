#ifndef STM32_STM32F042P6_TIM_1_
#define STM32_STM32F042P6_TIM_1_

#include <stdint.h>

typedef union STM32Tim1CR1 STM32Tim1CR1;
union STM32Tim1CR1 {
	uint32_t reg;
	struct {
		uint32_t cen : 1;
		uint32_t udis : 1;
		uint32_t urs : 1;
		uint32_t opm : 1;
		uint32_t dir: 1;
		uint32_t cms : 2;
		uint32_t arpe : 1;
		uint32_t ckd: 2;
		
		uint32_t : 22;
	};
};

typedef union STM32Tim1CR2 STM32Tim1CR2;
union STM32Tim1CR2 {
	uint32_t reg;
	struct {
		uint32_t ccpc : 1;
		uint32_t : 1;
		uint32_t ccus : 1;
		uint32_t ccds : 1;
		uint32_t mms : 3;
		uint32_t ti1s : 1;
		uint32_t ois1 : 1;
		uint32_t ois1n : 1;
		uint32_t ois2 : 1;
		uint32_t ois2n : 1;
		uint32_t ois3 : 1;
		uint32_t ois3n : 1;
		uint32_t ois4 : 1;
		uint32_t : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim1SMCR STM32Tim1SMCR;
union STM32Tim1SMCR {
	uint32_t reg;
	struct {
		uint32_t sms : 3;
		uint32_t occs : 1;
		uint32_t ts : 3;
		uint32_t msm : 1;
		uint32_t etf : 4;
		uint32_t etps : 2;
		uint32_t ece : 1;
		uint32_t etp : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim1DIER STM32Tim1DIER;
union STM32Tim1DIER {
	uint32_t reg;
	struct {
		uint32_t uie : 1;
		uint32_t cc1ie : 1;
		uint32_t cc2ie : 1;
		uint32_t cc3ie : 1;
		uint32_t cc4ie : 1;
		uint32_t comie : 1;
		uint32_t tie : 1;
		uint32_t bie : 1;
		uint32_t ude : 1;
		uint32_t cc1de : 1;
		uint32_t cc2de : 1;
		uint32_t cc3de : 1;
		uint32_t cc4de : 1;
		uint32_t comde : 1;
		uint32_t tde : 1;
		uint32_t : 17;
	};
};

typedef union STM32Tim1SR STM32Tim1SR;
union STM32Tim1SR {
	uint32_t reg;
	struct {
		uint32_t uif : 1;
		uint32_t cc1if : 1;
		uint32_t cc2if : 1;
		uint32_t cc3if : 1;
		uint32_t cc4if : 1;
		uint32_t comif : 1;
		uint32_t tif : 1;
		uint32_t bif : 1;
		uint32_t  : 1;
		uint32_t cc1of : 1;
		uint32_t cc2of : 1;
		uint32_t cc3of : 1;
		uint32_t cc4of : 1;
		uint32_t  : 1;
		uint32_t  : 1;
		uint32_t : 17;
	};
};

typedef union STM32Tim1EGR STM32Tim1EGR;
union STM32Tim1EGR {
	uint32_t reg;
	struct {
		uint32_t ug : 1;
		uint32_t cc1g : 1;
		uint32_t cc2g : 1;
		uint32_t cc3g : 1;
		uint32_t cc4g : 1;
		uint32_t com : 1;
		uint32_t tg : 1;
		uint32_t bg : 1;
		
		uint32_t : 24;
	};
};

typedef union STM32Tim1CMMR1OutputCompare STM32Tim1CMMR1OutputCompare;
union STM32Tim1CMMR1OutputCompare {
	uint32_t reg;
	struct {
		uint32_t cc1s : 2;
		uint32_t oc1fe : 1;
		uint32_t oc1pe : 1;
		uint32_t oc1m : 2;
		uint32_t oc1ce : 1;
		
		uint32_t cc2s : 2;
		uint32_t oc2fe : 1;
		uint32_t oc2pe : 1;
		uint32_t oc2m : 2;
		uint32_t oc2ce : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim1CMMR1InputCapture STM32Tim1CMMR1InputCapture;
union STM32Tim1CMMR1InputCapture {
	uint32_t reg;
	struct {
		uint32_t cc1s : 2;
		uint32_t ic1psc : 2;
		uint32_t ic1f : 4;
		
		uint32_t cc2s : 2;
		uint32_t ic2psc : 2;
		uint32_t ic2f : 4;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim1CMMR2OutputCompare STM32Tim1CMMR2OutputCompare;
union STM32Tim1CMMR2OutputCompare {
	uint32_t reg;
	struct {
		uint32_t cc3s : 2;
		uint32_t oc3fe : 1;
		uint32_t oc3pe : 1;
		uint32_t oc3m : 2;
		uint32_t oc3ce : 1;
		
		uint32_t cc4s : 2;
		uint32_t oc4fe : 1;
		uint32_t oc4pe : 1;
		uint32_t oc4m : 2;
		uint32_t oc4ce : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim1CMMR2InputCapture STM32Tim1CMMR2InputCapture;
union STM32Tim1CMMR2InputCapture {
	uint32_t reg;
	struct {
		uint32_t cc3s : 2;
		uint32_t ic3psc : 2;
		uint32_t ic3f : 4;
		
		uint32_t cc4s : 2;
		uint32_t ic4psc : 2;
		uint32_t ic4f : 4;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim1CCER STM32Tim1CCER;
union STM32Tim1CCER {
	uint32_t reg;
	struct {
		uint32_t cc1e : 1;
		uint32_t cc1p : 1;
		uint32_t cc1ne : 1;
		uint32_t cc1np : 1;
		uint32_t cc2e : 1;
		uint32_t cc2p : 1;
		uint32_t cc2ne : 1;
		uint32_t cc2np : 1;
		uint32_t cc3e : 1;
		uint32_t cc3p : 1;
		uint32_t cc3ne : 1;
		uint32_t cc3np : 1;
		uint32_t cc4e : 1;
		uint32_t cc4p : 1;
		uint32_t cc4ne : 1;
		uint32_t cc4np : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim1BDTR STM32Tim1BDTR;
union STM32Tim1BDTR {
	uint32_t reg;
	struct {
		uint32_t dt : 8;
		uint32_t lock : 2;
		uint32_t ossi : 1;
		uint32_t ossr : 1;
		uint32_t bke : 1;
		uint32_t bkp : 1;
		uint32_t aoe : 1;
		uint32_t moe : 1;

		uint32_t : 16;
	};
}

typedef union STM32Tim1DCR STM32Tim1DCR;
union STM32Tim1DCR {
	uint32_t reg;
	struct {
		uint32_t dba: 5;
		uint32_t  : 3;
		
		uint32_t dbl : 5;
		uint32_t : 3;
		
		uint32_t : 16;
	};
};

typedef struct STM32Tim1 STM32Tim1;
struct STM32Tim1 {
	STM32Tim1CR1 cr1;
	STM32Tim1CR2 cr2;
	STM32Tim1SMCR smcr;
	STM32Tim1DIER dier;
	STM32Tim1SR sr;
	STM32Tim1EGR egr;
	
	union {
		STM32Tim1CMMR1OutputCompare cmmr1_output_compare;
		STM32Tim1CMMR1OutputCompare cmmr1_input_capture;
	};
	
	union {
		STM32Tim1CMMR2OutputCompare cmmr2_output_compare;
		STM32Tim1CMMR2OutputCompare cmmr2_input_capture;
	};
	
	STM32Tim1CCER ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t rcr;
	uint32_t crr1;
	uint32_t crr2;
	uint32_t crr3;
	uint32_t crr4;
	STM32Tim1BDTR bdtr;
	STM32Tim1DCR dcr;
	uint32_t dmar;
};

extern volatile STM32Tim1 TIM1;

#endif
