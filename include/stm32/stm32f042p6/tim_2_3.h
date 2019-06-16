#ifndef STM32_STM32F042P6_TIM_2_3_
#define STM32_STM32F042P6_TIM_2_3_

#include <stdint.h>

typedef union STM32Tim23CR1 STM32Tim23CR1;
union STM32Tim23CR1 {
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

typedef union STM32Tim23CR2 STM32Tim23CR2;
union STM32Tim23CR2 {
	uint32_t reg;
	struct {
		uint32_t : 3;
		uint32_t ccds : 1;
		uint32_t mms : 3;
		uint32_t ti1s : 1;
		
		uint32_t : 24;
	};
};

typedef union STM32Tim23SMCR STM32Tim23SMCR;
union STM32Tim23SMCR {
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

typedef union STM32Tim23DIER STM32Tim23DIER;
union STM32Tim23DIER {
	uint32_t reg;
	struct {
		uint32_t uie : 1;
		uint32_t cc1ie : 1;
		uint32_t cc2ie : 1;
		uint32_t cc3ie : 1;
		uint32_t cc4ie : 1;
		uint32_t  : 1;
		uint32_t tie : 1;
		uint32_t  : 1;
		uint32_t ude : 1;
		uint32_t cc1de : 1;
		uint32_t cc2de : 1;
		uint32_t cc3de : 1;
		uint32_t cc4de : 1;
		uint32_t  : 1;
		uint32_t tde : 1;
		uint32_t : 17;
	};
};

typedef union STM32Tim23SR STM32Tim23SR;
union STM32Tim23SR {
	uint32_t reg;
	struct {
		uint32_t uif : 1;
		uint32_t cc1if : 1;
		uint32_t cc2if : 1;
		uint32_t cc3if : 1;
		uint32_t cc4if : 1;
		uint32_t  : 1;
		uint32_t tif : 1;
		uint32_t  : 1;
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

typedef union STM32Tim23EGR STM32Tim23EGR;
union STM32Tim23EGR {
	uint32_t reg;
	struct {
		uint32_t ug : 1;
		uint32_t cc1g : 1;
		uint32_t cc2g : 1;
		uint32_t cc3g : 1;
		uint32_t cc4g : 1;
		uint32_t  : 1;
		uint32_t tg : 1;
		
		uint32_t : 25;
	};
};

typedef union STM32Tim23CMMR1OutputCompare STM32Tim23CMMR1OutputCompare;
union STM32Tim23CMMR1OutputCompare {
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

typedef union STM32Tim23CMMR1InputCapture STM32Tim23CMMR1InputCapture;
union STM32Tim23CMMR1InputCapture {
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

typedef union STM32Tim23CMMR2OutputCompare STM32Tim23CMMR2OutputCompare;
union STM32Tim23CMMR2OutputCompare {
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

typedef union STM32Tim23CMMR2InputCapture STM32Tim23CMMR2InputCapture;
union STM32Tim23CMMR2InputCapture {
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

typedef union STM32Tim23CCER STM32Tim23CCER;
union STM32Tim23CCER {
	uint32_t reg;
	struct {
		uint32_t cc1e : 1;
		uint32_t cc1p : 1;
		uint32_t  : 1;
		uint32_t cc1np : 1;
		uint32_t cc2e : 1;
		uint32_t cc2p : 1;
		uint32_t  : 1;
		uint32_t cc2np : 1;
		uint32_t cc3e : 1;
		uint32_t cc3p : 1;
		uint32_t  : 1;
		uint32_t cc3np : 1;
		uint32_t cc4e : 1;
		uint32_t cc4p : 1;
		uint32_t  : 1;
		uint32_t cc4np : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32Tim23DCR STM32Tim23DCR;
union STM32Tim23DCR {
	uint32_t reg;
	struct {
		uint32_t dba: 5;
		uint32_t  : 3;
		
		uint32_t dbl : 5;
		uint32_t : 3;
		
		uint32_t : 16;
	};
};

typedef struct STM32Tim23 STM32Tim23;
struct STM32Tim23 {
	STM32Tim23CR1 cr1;
	STM32Tim23CR2 cr2;
	STM32Tim23SMCR smcr;
	STM32Tim23DIER dier;
	STM32Tim23SR sr;
	STM32Tim23EGR egr;
	
	union {
		STM32Tim23CMMR1OutputCompare cmmr1_output_compare;
		STM32Tim23CMMR1OutputCompare cmmr1_input_capture;
	};
	
	union {
		STM32Tim23CMMR2OutputCompare cmmr2_output_compare;
		STM32Tim23CMMR2OutputCompare cmmr2_input_capture;
	};
	
	STM32Tim23CCER ccer;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t _reserved0;
	uint32_t crr1;
	uint32_t crr2;
	uint32_t crr3;
	uint32_t crr4;
	uint32_t _reserved1;
	STM32Tim23DCR dcr;
	uint32_t dmar;
};

extern volatile STM32Tim23 TIM2;
extern volatile STM32Tim23 TIM3;

#endif
