#ifndef _STM32_STM32F042P6_USART_H_
#define _STM32_STM32F042P6_USART_H_

#include <stdint.h>

typedef union STM32UsartCR1 STM32UsartCR1;
union STM32UsartCR1 {
	uint32_t reg;
	struct {
		uint32_t ue : 1;
		uint32_t : 1;
		uint32_t re : 1;
		uint32_t te : 1;
		uint32_t idle_ie : 1;
		uint32_t rxne_ie : 1;
		uint32_t tc_ie : 1;
		uint32_t txe_ie : 1;
		uint32_t pe_ie : 1;
		uint32_t ps : 1;
		uint32_t pce : 1;
		uint32_t wake : 1;
		uint32_t m0 : 1;
		uint32_t mme : 1;
		uint32_t cm_ie : 1;
		uint32_t over8 : 1;
		uint32_t dedt0 : 1;
		uint32_t dedt1 : 1;
		uint32_t dedt2 : 1;
		uint32_t dedt3 : 1;
		uint32_t dedt4 : 1;
		uint32_t deat0 : 1;
		uint32_t deat1 : 1;
		uint32_t deat2 : 1;
		uint32_t deat3 : 1;
		uint32_t deat4 : 1;
		uint32_t rto_ie : 1;
		uint32_t eob_ie : 1;
		uint32_t m1 : 1;
		uint32_t : 3;
	};
};

typedef union STM32UsartCR2 STM32UsartCR2;
union STM32UsartCR2 {
	uint32_t reg;
	struct {
		uint32_t : 4;
		uint32_t addm7 : 1;
		uint32_t bldl : 1;
		uint32_t lbd_ie : 1;
		uint32_t : 1;
		uint32_t lbcl : 1;
		uint32_t cpha : 1;
		uint32_t cpol : 1;
		uint32_t clken : 1;
		uint32_t stop : 2;
		uint32_t linen : 1;
		uint32_t swap : 1;
		uint32_t rxinv : 1;
		uint32_t txinv : 1;
		uint32_t datainv : 1;
		uint32_t msbfirst : 1;
		uint32_t abren : 1;
		uint32_t abrmod0 : 1;
		uint32_t abrmod1 : 1;
		uint32_t rtoen : 1;
		uint32_t add : 8;
	};
};

typedef union STM32UsartCR3 STM32UsartCR3;
union STM32UsartCR3 {
	uint32_t reg;
	struct {
		uint32_t e_ie : 1;
		uint32_t iren : 1;
		uint32_t irlp : 1;
		uint32_t hdsel : 1;
		uint32_t nack : 1;
		uint32_t scen : 1;
		uint32_t dmar : 1;
		uint32_t dmat : 1;
		uint32_t rtse : 1;
		uint32_t crse : 1;
		uint32_t cts_ie : 1;
		uint32_t onebit : 1;
		uint32_t ovrdis : 1;
		uint32_t ddre : 1;
		uint32_t dem : 1;
		uint32_t dep : 1;
		uint32_t : 1;
		uint32_t scarcnt : 3;
		uint32_t wus : 2;
		uint32_t wuf_ie : 1;
		uint32_t : 9;
	};
};

typedef union STM32UsartBRR STM32UsartBRR;
union STM32UsartBRR {
	uint32_t reg;
	struct {
		uint32_t brr : 16;
		uint32_t : 16;
	};
};


typedef union STM32UsartGTPR STM32UsartGTPR;
union STM32UsartGTPR {
	uint32_t reg;
	struct {
		uint32_t psc : 8;
		uint32_t gt : 8;
		uint32_t : 16;
	};
};

typedef union STM32UsartRTOR STM32UsartRTOR;
union STM32UsartRTOR {
	uint32_t reg;
	struct {
		uint32_t rto : 24;
		uint32_t blen : 8;
	};
};

typedef union STM32UsartRQR STM32UsartRQR;
union STM32UsartRQR {
	uint32_t reg;
	struct {
		uint32_t abrrq : 1;
		uint32_t sbkrq : 1;
		uint32_t mmrq : 1;
		uint32_t rxfrq : 1;
		uint32_t txfrq : 1;
		uint32_t : 27;
	};
};

typedef union STM32UsartISR STM32UsartISR;
union STM32UsartISR {
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
		uint32_t lbdf : 1;
		uint32_t cts_if : 1;
		uint32_t cts : 1;
		uint32_t rtof : 1;
		uint32_t eobf : 1;
		uint32_t : 1;
		uint32_t abre : 1;
		uint32_t abrf : 1;
		uint32_t busy : 1;
		uint32_t cmf : 1;
		uint32_t sbkf : 1;
		uint32_t rwu : 1;
		uint32_t wuf : 1;
		uint32_t teack : 1;
		uint32_t reack : 1;
		uint32_t : 9;
	};
};

typedef union STM32UsartICR STM32UsartICR;
union STM32UsartICR {
	uint32_t reg;
	struct {
		uint32_t pecf : 1;
		uint32_t fecf : 1;
		uint32_t ncf : 1;
		uint32_t orecf : 1;
		uint32_t idlecf : 1;
		uint32_t : 1;
		uint32_t tccf : 1;
		uint32_t : 1;
		uint32_t lbdcf : 1;
		uint32_t ctscf : 1;
		uint32_t : 1;
		uint32_t rtocf : 1;
		uint32_t eobcf : 1;
		uint32_t : 4;
		uint32_t cmcf : 1;
		uint32_t : 2;
		uint32_t wucf : 1;
		uint32_t : 11;
	};
};

typedef union STM32UsartRDR STM32UsartRDR;
union STM32UsartRDR {
	uint32_t reg;
	struct {
		uint32_t rdr : 9;
		uint32_t : 23;
	};
};

typedef union STM32UsartTDR STM32UsartTDR;
union STM32UsartTDR {
	uint32_t reg;
	struct {
		uint32_t tdr : 9;
		uint32_t : 23;
	};
};


typedef struct STM32USART STM32USART;
struct STM32USART {
	STM32UsartCR1 cr1;
	STM32UsartCR2 cr2;
	STM32UsartCR3 cr3;
	STM32UsartBRR brr;
	STM32UsartGTPR gtpr;
	STM32UsartRTOR rtor;
	STM32UsartRQR rqr;
	STM32UsartISR isr;
	STM32UsartICR icr;
	STM32UsartRDR rdr;
	STM32UsartTDR tdr;
};

extern volatile STM32USART USART1;
extern volatile STM32USART USART2;
extern volatile STM32USART USART3;
extern volatile STM32USART USART4;
extern volatile STM32USART USART5;
extern volatile STM32USART USART6;
extern volatile STM32USART USART7;
extern volatile STM32USART USART8;

#endif
