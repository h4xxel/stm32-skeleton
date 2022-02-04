#ifndef _STM32_STM32F042P6_SPI_H_
#define _STM32_STM32F042P6_SPI_H_

#include <stdint.h>

typedef union STM32SpiCR1 STM32SpiCR1;
union STM32SpiCR1 {
	uint32_t reg;
	struct {
		uint32_t cpha : 1;
		uint32_t cpol : 1;
		uint32_t mstr : 1;
		uint32_t br : 3;
		uint32_t spe : 1;
		uint32_t lsbfirst : 1;
		uint32_t ssi : 1;
		uint32_t ssm : 1;
		uint32_t rxonly : 1;
		uint32_t crcl : 1;
		uint32_t crcnext : 1;
		uint32_t crcen : 1;
		uint32_t bidioe : 1;
		uint32_t bidimode : 1;
		uint32_t : 16;
	};
};

typedef union STM32SpiCR2 STM32SpiCR2;
union STM32SpiCR2 {
	uint32_t reg;
	struct {
		uint32_t rxdmaen : 1;
		uint32_t txdmaen : 1;
		uint32_t ssoe : 1;
		uint32_t nssp : 1;
		uint32_t frf : 1;
		uint32_t errie : 1;
		uint32_t rxneie : 1;
		uint32_t txeie : 1;
		uint32_t ds : 4;
		uint32_t frxth : 1;
		uint32_t ldma_rx : 1;
		uint32_t ldma_tx : 1;
		uint32_t : 17;
	};
};

typedef union STM32SpiSR STM32SpiSR;
union STM32SpiSR {
	uint32_t reg;
	struct {
		uint32_t rxne : 1;
		uint32_t txe : 1;
		uint32_t : 2;
		uint32_t crcerr : 1;
		uint32_t modf : 1;
		uint32_t ovr : 1;
		uint32_t bsy : 1;
		uint32_t fre : 1;
		uint32_t frvl : 2;
		uint32_t ftvl : 2;
		uint32_t : 3;
		uint32_t : 16;
	};
};

typedef union STM32SpiDR STM32SpiDR;
union STM32SpiDR {
	uint32_t reg;
	struct {
		uint32_t dr : 16;
		uint32_t : 16;
	};
};

typedef union STM32SpiCRCPR STM32SpiCRCPR;
union STM32SpiCRCPR {
	uint32_t reg;
	struct {
		uint32_t crcp : 16;
		uint32_t : 16;
	};
};

typedef union STM32SpiRxCRC STM32SpiRxCRCR;
union STM32SpiRxCRCR {
	uint32_t reg;
	struct {
		uint32_t rxcrc : 16;
		uint32_t : 16;
	};
};

typedef union STM32SpiTxCRCR STM32SpiTxCRCR;
union STM32SpiTxCRCR {
	uint32_t reg;
	struct {
		uint32_t txcrc : 16;
		uint32_t : 16;
	};
};

typedef struct STM32USART STM32USART;
struct STM32USART {
	STM32SpiCR1 cr1;
	STM32SpiCR2 cr2;
	STM32SpiSR sr;
	STM32SpiDR dr;
	STM32SpiCRCPR crcpr;
	STM32SpiRxCRCR rxcrcr;
	STM32SpiTxCRCR txcrcr;
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
