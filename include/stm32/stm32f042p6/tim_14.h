#ifndef STM32_STM32F042P6_TIM_14_
#define STM32_STM32F042P6_TIM_14_

#include <stdint.h>

typedef union STM32Tim14CR1 STM32Tim14CR1;
union STM32Tim14CR1 {
	uint32_t reg;
	struct {
		uint32_t cen : 1;
		uint32_t udis : 1;
		uint32_t urs : 1;
		uint32_t : 1;
		uint32_t : 3;
		uint32_t arpe : 1;
		uint32_t ckd : 2;
		
		uint32_t : 22;
	};
};

typedef union STM32Tim14DIER STM32Tim14DIER;
union STM32Tim14DIER {
	uint32_t reg;
	struct {
		uint32_t uie : 1;
		uint32_t cc1ie : 1;
		uint32_t : 30;
	};
};

typedef union STM32Tim14SR STM32Tim14SR;
union STM32Tim14SR {
	uint32_t reg;
	struct {
		uint32_t uif : 1;
		uint32_t cc1if : 1;
		uint32_t : 7;
		uint32_t cc1of : 1;
		uint32_t : 22;
	};
};

typedef union STM32Tim14EGR STM32Tim14EGR;
union STM32Tim14EGR {
	uint32_t reg;
	struct {
		uint32_t ug : 1;
		uint32_t cc1g : 1;
		
		uint32_t : 30;
	};
};

typedef union STM32Tim14CMMR1OutputCompare STM32Tim14CMMR1OutputCompare;
union STM32Tim14CMMR1OutputCompare {
	uint32_t reg;
	struct {
		uint32_t cc1s : 2;
		uint32_t oc1fe : 1;
		uint32_t oc1pe : 1;
		uint32_t oc1m : 3;
		
		uint32_t : 25;
	};
};

typedef union STM32Tim14CMMR1InputCapture STM32Tim14CMMR1InputCapture;
union STM32Tim14CMMR1InputCapture {
	uint32_t reg;
	struct {
		uint32_t cc1s : 2;
		uint32_t ic1psc : 2;
		uint32_t ic1f : 4;
		
		uint32_t : 24;
	};
};

typedef union STM32Tim14CCER STM32Tim14CCER;
union STM32Tim14CCER {
	uint32_t reg;
	struct {
		uint32_t cc1e : 1;
		uint32_t cc1p : 1;
		uint32_t  : 1;
		uint32_t cc1np : 1;
		
		uint32_t : 28;
	};
};

typedef union STM32Tim14OR STM32Tim14OR;
union STM32Tim14OR {
	uint32_t reg;
	struct {
		uint32_t ti1_rmp : 2;
		
		uint32_t : 30;
	};
};

typedef struct STM32Tim14 STM32Tim14;
struct STM32Tim14 {
	STM32Tim14CR1 cr1;
	uint32_t _reserved0[2];
	STM32Tim14DIER dier;
	STM32Tim14SR sr;
	STM32Tim14EGR egr;
	union {
		STM32Tim14CMMR1InputCapture cmmr1_output_compare;
		STM32Tim14CMMR1InputCapture cmmr1_input_capture;
	};
	uint32_t _reserved1;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
	uint32_t _reserved2;
	uint32_t crr1;
	uint32_t _reserved3;
	STM32Tim14OR or;
};

extern volatile STM32Tim14 TIM14;

#endif
