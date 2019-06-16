#ifndef STM32_STM32F042P6_TIM_6_7_
#define STM32_STM32F042P6_TIM_6_7_

#include <stdint.h>

typedef union STM32Tim67CR1 STM32Tim67CR1;
union STM32Tim67CR1 {
	uint32_t reg;
	struct {
		uint32_t cen : 1;
		uint32_t udis : 1;
		uint32_t urs : 1;
		uint32_t opm : 1;
		uint32_t  : 3;
		uint32_t arpe : 1;
		
		uint32_t : 24;
	};
};

typedef union STM32Tim67CR2 STM32Tim67CR2;
union STM32Tim67CR2 {
	uint32_t reg;
	struct {
		uint32_t : 4;
		uint32_t mms : 3;
		
		uint32_t : 25;
	};
};

typedef union STM32Tim67DIER STM32Tim67DIER;
union STM32Tim67DIER {
	uint32_t reg;
	struct {
		uint32_t uie : 1;
		uint32_t : 7;
		uint32_t ude : 1;
		
		uint32_t : 23;
	};
};

typedef union STM32Tim67SR STM32Tim67SR;
union STM32Tim67SR {
	uint32_t reg;
	struct {
		uint32_t uif : 1;
		
		uint32_t : 31;
	};
};

typedef union STM32Tim67EGR STM32Tim67EGR;
union STM32Tim67EGR {
	uint32_t reg;
	struct {
		uint32_t ug : 1;
		
		uint32_t : 31;
	};
};

typedef struct STM32Tim67 STM32Tim67;
struct STM32Tim67 {
	STM32Tim67CR1 cr1;
	STM32Tim67CR2 cr2;
	STM32Tim67DIER dier;
	STM32Tim67SR sr;
	STM32Tim67EGR egr;
	uint32_t cnt;
	uint32_t psc;
	uint32_t arr;
};

extern volatile STM32Tim67 TIM6;
extern volatile STM32Tim67 TIM7;

#endif
