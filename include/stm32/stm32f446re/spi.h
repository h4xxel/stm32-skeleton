#ifndef _STM32_STM32F446RE_SPI_H_
#define _STM32_STM32F446RE_SPI_H_

#include <stdint.h>

typedef union STM32SPIControl1 STM32SPIControl1;
union STM32SPIControl1 {
	uint32_t reg;
	struct {
		uint32_t cpha : 1;
		uint32_t cpol : 1;
		uint32_t mstr : 1;
		uint32_t br : 3;
		uint32_t spe : 1;
		uint32_t lsb_first : 1;
		uint32_t ssi : 1;
		uint32_t ssm : 1;
		uint32_t rxonly : 1;
		uint32_t ddf : 1;
		uint32_t crc_next : 1;
		uint32_t crc_en : 1;
		uint32_t bidi_oe : 1;
		uint32_t bidi_mode : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32SPIControl2 STM32SPIControl2;
union STM32SPIControl2 {
	uint32_t reg;
	struct {
		uint32_t rx_dma_en : 1;
		uint32_t tx_dma_en : 1;
		uint32_t ssoe : 1;
		uint32_t : 1;
		uint32_t frf : 1;
		uint32_t err_ie : 1;
		uint32_t rxne_ie : 1;
		uint32_t txe_ie : 1;
		
		uint32_t : 24;
	};
};

typedef union STM32SPIStatus STM32SPIStatus;
union STM32SPIStatus {
	uint32_t reg;
	struct {
		uint32_t rxne : 1;
		uint32_t txe : 1;
		uint32_t chside : 1;
		uint32_t udr : 1;
		uint32_t crc_err : 1;
		uint32_t modf : 1;
		uint32_t ovr : 1;
		uint32_t bsy : 1;
		uint32_t fre : 1;
		
		uint32_t : 23;
	};
};

typedef union STM32SPIData STM32SPIData;
union STM32SPIData {
	uint32_t reg;
	struct {
		uint32_t data : 16;
		
		uint32_t : 16;
	};
};

typedef union STM32SPICRCPolynomial STM32SPICRCPolynomial;
union STM32SPICRCPolynomial {
	uint32_t reg;
	struct {
		uint32_t poly : 16;
		
		uint32_t : 16;
	};
};

typedef union STM32SPICRC STM32SPICRC;
union STM32SPICRC {
	uint32_t reg;
	struct {
		uint32_t crc : 16;
		
		uint32_t : 16;
	};
};

typedef union STM32SPII2SConfig STM32SPII2SConfig;
union STM32SPII2SConfig {
	uint32_t reg;
	struct {
		uint32_t ch_len : 1;
		uint32_t dat_len : 2;
		uint32_t ckpol : 1;
		uint32_t i2s_std : 2;
		uint32_t : 1;
		uint32_t pcm_sync : 1;
		uint32_t i2s_cfg : 2;
		uint32_t i2s_en : 1;
		uint32_t i2s_mod : 1;
		uint32_t astr_en : 1;
		
		uint32_t : 19;
	};
};

typedef union STM32SPII2SPrescaler STM32SPII2SPrescaler;
union STM32SPII2SPrescaler {
	uint32_t reg;
	struct {
		uint32_t i2s_div : 8;
		uint32_t odd : 1;
		uint32_t mck_oe : 1;
		
		uint32_t : 22;
	};
};


typedef struct STM32SPI STM32SPI;
struct STM32SPI {
	STM32SPIControl1 control1;
	STM32SPIControl2 control2;
	STM32SPIStatus status;
	STM32SPIData data;
	STM32SPICRCPolynomial crc_poly;
	STM32SPICRC rx_crc;
	STM32SPICRC tx_crc;
	STM32SPII2SConfig i2s_config;
	STM32SPII2SPrescaler i2s_prescaler;
};



STM32SPI SPI1;
STM32SPI SPI2_I2S2;
STM32SPI SPI3_I2S3;
STM32SPI SPI4;

#endif
