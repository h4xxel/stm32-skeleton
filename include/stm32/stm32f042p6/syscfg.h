#ifndef _STM32_STM32F042P6_SYSCFG_H_
#define _STM32_STM32F042P6_SYSCFG_H_

#include <stdint.h>

typedef union STM32SyscfgCfgr1 STM32SyscfgCfgr1;
union STM32SyscfgCfgr1 {
	uint32_t reg;
	struct {
		uint32_t mem_mode : 2;
		uint32_t : 2;
		uint32_t pa11_pa12_rmp : 1;
		uint32_t : 1;
		uint32_t irda_env_sel : 2;
		uint32_t adc_dma_rmp : 2;
		
		uint32_t : 24;
	};
};

typedef struct STM32Syscfg STM32Syscfg;
struct STM32Syscfg {
	STM32SyscfgCfgr1 cfgr1;
};

extern volatile STM32Syscfg SYSCFG;

#endif
