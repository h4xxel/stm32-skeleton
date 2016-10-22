#ifndef _STM32_STM32F446RE_USART_H_
#define _STM32_STM32F446RE_USART_H_

#include <stdint.h>

typedef union STM32USARTStatus STM32USARTStatus;
union STM32USARTStatus {
	uint32_t reg;
	struct {
		uint32_t pe : 1;
		uint32_t fe : 1;
		uint32_t nf : 1;
		uint32_t ore : 1;
		uint32_t idle : 1;
		uint32_t rxne : 1;
		uint32_t tc : 1;
		uint32_t txe : 1;
		uint32_t lbd : 1;
		uint32_t cts : 1;
		
		uint32_t : 22;
	};
};

typedef union STM32USARTData STM32USARTData;
union STM32USARTData {
	uint32_t reg;
	struct {
		uint32_t dr : 9;
		
		uint32_t : 24;
	};
};

typedef union STM32USARTBaudRate STM32USARTBaudRate;
union STM32USARTBaudRate {
	uint32_t reg;
	struct {
		uint32_t div_fraction : 4;
		uint32_t div_mantissa : 12;
		
		uint32_t : 16;
	};
};

typedef union STM32USARTControl1 STM32USARTControl1;
union STM32USARTControl1 {
	uint32_t reg;
	struct {
		uint32_t sbk : 1;
		uint32_t rwu : 1;
		uint32_t re : 1;
		uint32_t te : 1;
		uint32_t idle_ie : 1;
		uint32_t rxne_ie : 1;
		uint32_t tc_ie : 1;
		uint32_t txe_ie : 1;
		uint32_t pe_ie : 1;
		uint32_t ps : 1;
		uint32_t tce : 1;
		uint32_t wake : 1;
		uint32_t m : 1;
		uint32_t ue : 1;
		
		uint32_t : 1;
		
		uint32_t over8 : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32USARTControl2 STM32USARTControl2;
union STM32USARTControl2 {
	uint32_t reg;
	struct {
		uint32_t add : 4;
		uint32_t : 1;
		
		uint32_t lb_dl : 1;
		uint32_t lb_ie : 1;
		
		uint32_t : 1;
		
		uint32_t lb_cl : 1;
		uint32_t cpha : 1;
		uint32_t cpol : 1;
		uint32_t clk_en : 1;
		uint32_t stop : 2;
		uint32_t lin_en : 1;
		
		uint32_t : 17;
	};
};

typedef union STM32USARTControl3 STM32USARTControl3;
union STM32USARTControl3 {
	uint32_t reg;
	struct {
		uint32_t e_ie : 1;
		uint32_t ir_en : 1;
		uint32_t ir_lp : 1;
		uint32_t hdsel : 1;
		uint32_t nack : 1;
		uint32_t sc_en : 1;
		uint32_t dma_r : 1;
		uint32_t dma_t : 1;
		uint32_t rtse : 1;
		uint32_t ctse : 1;
		uint32_t cts_ie : 1;
		uint32_t onebit : 1;
		
		uint32_t : 20;
	};
};

typedef union STM32USARTGuardTimePrescaler STM32USARTGuardTimePrescaler;
union STM32USARTGuardTimePrescaler {
	uint32_t reg;
	struct {
		uint32_t psc : 8;
		uint32_t gt : 8;
		
		uint32_t : 16;
	};
};

typedef struct STM32USART STM32USART;
struct STM32USART {
	STM32USARTStatus status;
	STM32USARTData data;
	STM32USARTBaudRate baudrate;
	STM32USARTControl1 control1;
	STM32USARTControl2 control2;
	STM32USARTControl3 control3;
	STM32USARTGuardTimePrescaler guard_time_prescaler;
};

#endif
