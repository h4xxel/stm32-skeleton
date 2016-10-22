#ifndef _STM32_STM32F446RE_RCC_H_
#define _STM32_STM32F446RE_RCC_H_

#include <stdint.h>

typedef union STM32RCCClockControl STM32RCCClockControl;
union STM32RCCClockControl {
	uint32_t reg;
	struct {
		uint32_t hsi_on : 1;
		uint32_t hsi_rdy : 1;
		uint32_t : 1;
		uint32_t hsi_trim : 5;
		uint32_t hsi_cal : 8;
		
		uint32_t hse_on : 1;
		uint32_t hse_rdy : 1;
		uint32_t hse_byp : 1;
		uint32_t css_on : 1;
		
		uint32_t : 4;
		
		uint32_t pll_on : 1;
		uint32_t pll_rdy : 1;
		uint32_t pll_i2s_on : 1;
		uint32_t pll_i2s_rdy : 1;
		uint32_t pll_sai_on : 1;
		uint32_t pll_sai_rdy : 1;
		
		uint32_t : 2;
	};
};

typedef union STM32RCCPLLConfig STM32RCCPLLConfig;
union STM32RCCPLLConfig {
	uint32_t reg;
	struct {
		uint32_t pll_m : 6;
		uint32_t pll_n : 9;
		uint32_t : 1;
		uint32_t pll_p : 2;
		uint32_t : 4;
		uint32_t pll_src : 1;
		uint32_t : 1;
		uint32_t pll_q : 4;
		uint32_t pll_r : 3;
		uint32_t : 1;
	};
};

typedef union STM32RCCClockConfig STM32RCCClockConfig;
union STM32RCCClockConfig {
	uint32_t reg;
	struct {
		uint32_t sw : 2;
		uint32_t sws : 2;
		uint32_t hpre : 4;
		uint32_t : 2;
		uint32_t ppre1 : 3;
		uint32_t ppre2 : 3;
		uint32_t rtcpre : 5;
		uint32_t mco1 : 2;
		uint32_t : 1;
		uint32_t mco1_pre : 3;
		uint32_t mco2_pre : 3;
		uint32_t mco2 : 2;
	};
};

typedef union STM32RCCClockInterrupt STM32RCCClockInterrupt;
union STM32RCCClockInterrupt {
	uint32_t reg;
	struct {
		uint32_t lsi_rdy_if : 1;
		uint32_t lse_rdy_if : 1;
		uint32_t hsi_rdy_if : 1;
		uint32_t hse_rdy_if : 1;
		uint32_t pll_rdy_if: 1;
		uint32_t pll_i2s_rdy_if : 1;
		uint32_t pll_sai_rdy_if : 1;
		uint32_t css_if : 1;
		
		uint32_t lsi_rdy_ie : 1;
		uint32_t lse_rdy_ie : 1;
		uint32_t hsi_rdy_ie : 1;
		uint32_t hse_rdy_ie : 1;
		uint32_t pll_rdy_ie : 1;
		uint32_t pll_i2s_rdy_ie : 1;
		uint32_t pll_sai_rdy_ie : 1;
		uint32_t : 1;
		
		uint32_t lsi_rdy_c : 1;
		uint32_t lse_rdy_c : 1;
		uint32_t hsi_rdy_c : 1;
		uint32_t hse_rdy_c : 1;
		uint32_t pll_rdy_c: 1;
		uint32_t pll_i2s_rdy_c : 1;
		uint32_t pll_sai_rdy_c : 1;
		uint32_t css_c : 1;
		
		uint32_t : 8;
	};
};

typedef union STM32RCCAHB1Reset STM32RCCAHB1Reset;
union STM32RCCAHB1Reset {
	uint32_t reg;
	struct {
		uint32_t gpio_a_rst : 1;
		uint32_t gpio_b_rst : 1;
		uint32_t gpio_c_rst : 1;
		uint32_t gpio_d_rst : 1;
		uint32_t gpio_e_rst : 1;
		uint32_t gpio_f_rst : 1;
		uint32_t gpio_g_rst : 1;
		uint32_t gpio_h_rst : 1;
		
		uint32_t : 4;
		
		uint32_t crc_rst : 1;
		
		uint32_t : 8;
		
		uint32_t dma1_rst : 1;
		uint32_t dma2_rst : 1;
		
		uint32_t : 6;
		
		uint32_t otghs_rst : 1;
		
		uint32_t : 2;
		
	};
};

typedef union STM32RCCAHB2Reset STM32RCCAHB2Reset;
union STM32RCCAHB2Reset {
	uint32_t reg;
	struct {
		uint32_t dcm_rst : 1;
		uint32_t : 6;
		uint32_t otgfs_rst : 1;
		uint32_t : 24;
	};
};

typedef union STM32RCCAHB3Reset STM32RCCAHB3Reset;
union STM32RCCAHB3Reset {
	uint32_t reg;
	struct {
		uint32_t fmc_rst : 1;
		uint32_t qspi_rst : 1;
		uint32_t : 30;
	};
};

typedef union STM32RCCAPB1Reset STM32RCCAPB1Reset;
union STM32RCCAPB1Reset {
	uint32_t reg;
	struct {
		uint32_t tm2_rst : 1;
		uint32_t tm3_rst : 1;
		uint32_t tm4_rst : 1;
		uint32_t tm5_rst : 1;
		uint32_t tm6_rst : 1;
		uint32_t tm7_rst : 1;
		uint32_t tm12_rst : 1;
		uint32_t tm13_rst : 1;
		uint32_t tm14_rst : 1;
		
		uint32_t : 2;
		
		uint32_t wwdg_rst : 1;
		
		uint32_t : 2;
		
		uint32_t spi2_rst : 1;
		uint32_t spi3_rst : 1;
		
		uint32_t spdif_rx_rst : 1;
		
		uint32_t uart2_rst : 1;
		uint32_t uart3_rst : 1;
		uint32_t uart4_rst : 1;
		uint32_t uart5_rst : 1;
		
		uint32_t i2c1_rst : 1;
		uint32_t i2c2_rst : 1;
		uint32_t i2c3_rst : 1;
		
		uint32_t fmpi2c1_rst : 1;
		
		uint32_t can1_rst : 1;
		uint32_t can2_rst : 1;
		
		uint32_t cec_rst : 1;
		uint32_t pwr_rst : 1;
		uint32_t dac_rst : 1;
		
		uint32_t : 2;
	};
};

typedef union STM32RCCAPB2Reset STM32RCCAPB2Reset;
union STM32RCCAPB2Reset {
	uint32_t reg;
	struct {
		uint32_t tm1_rst : 1;
		uint32_t tm8_rst : 1;
		
		uint32_t : 2;
		
		uint32_t usart1_rst : 1;
		uint32_t usart6_rst : 1;
		
		uint32_t : 2;
		
		uint32_t adc_rst : 1;
		
		uint32_t : 2;
		
		uint32_t sdio_rst : 1;
		uint32_t spi1_rst : 1;
		uint32_t spi45_rst : 1;
		uint32_t syscfg_rst : 1;
		
		uint32_t : 1;
		
		uint32_t tmr9_rst : 1;
		uint32_t tmr10_rst : 1;
		uint32_t tmr11_rst : 1;
		
		uint32_t : 3;
		
		uint32_t sai1_rst : 1;
		uint32_t sai2_rst : 1;
		
		uint32_t : 8;
	};
};

typedef union STM32RCCAHB1Enable STM32RCCAHB1Enable;
union STM32RCCAHB1Enable {
	uint32_t reg;
	struct {
		uint32_t gpio_a_en : 1;
		uint32_t gpio_b_en : 1;
		uint32_t gpio_c_en : 1;
		uint32_t gpio_d_en : 1;
		uint32_t gpio_e_en : 1;
		uint32_t gpio_f_en : 1;
		uint32_t gpio_g_en : 1;
		uint32_t gpio_h_en : 1;
		
		uint32_t : 4;
		
		uint32_t crc_en : 1;
		
		uint32_t : 8;
		
		uint32_t dma1_en : 1;
		uint32_t dma2_en : 1;
		
		uint32_t : 6;
		
		uint32_t otghs_en : 1;
		
		uint32_t : 2;
		
	};
};

typedef union STM32RCCAHB2Enable STM32RCCAHB2Enable;
union STM32RCCAHB2Enable {
	uint32_t reg;
	struct {
		uint32_t dcm_en : 1;
		uint32_t : 6;
		uint32_t otgfs_en : 1;
		uint32_t : 24;
	};
};

typedef union STM32RCCAHB3Enable STM32RCCAHB3Enable;
union STM32RCCAHB3Enable {
	uint32_t reg;
	struct {
		uint32_t fmc_en : 1;
		uint32_t qspi_en : 1;
		uint32_t : 30;
	};
};

typedef union STM32RCCAPB1Enable STM32RCCAPB1Enable;
union STM32RCCAPB1Enable {
	uint32_t reg;
	struct {
		uint32_t tm2_en : 1;
		uint32_t tm3_en : 1;
		uint32_t tm4_en : 1;
		uint32_t tm5_en : 1;
		uint32_t tm6_en : 1;
		uint32_t tm7_en : 1;
		uint32_t tm12_en : 1;
		uint32_t tm13_en : 1;
		uint32_t tm14_en : 1;
		
		uint32_t : 2;
		
		uint32_t wwdg_en : 1;
		
		uint32_t : 2;
		
		uint32_t spi2_en : 1;
		uint32_t spi3_en : 1;
		
		uint32_t spdif_rx_en : 1;
		
		uint32_t uart2_en : 1;
		uint32_t uart3_en : 1;
		uint32_t uart4_en : 1;
		uint32_t uart5_en : 1;
		
		uint32_t i2c1_en : 1;
		uint32_t i2c2_en : 1;
		uint32_t i2c3_en : 1;
		
		uint32_t fmpi2c1_en : 1;
		
		uint32_t can1_en : 1;
		uint32_t can2_en : 1;
		
		uint32_t cec_en : 1;
		uint32_t pwr_en : 1;
		uint32_t dac_en : 1;
		
		uint32_t : 2;
	};
};

typedef union STM32RCCAPB2Enable STM32RCCAPB2Enable;
union STM32RCCAPB2Enable {
	uint32_t reg;
	struct {
		uint32_t tm1_en : 1;
		uint32_t tm8_en : 1;
		
		uint32_t : 2;
		
		uint32_t usart1_en : 1;
		uint32_t usart6_en : 1;
		
		uint32_t : 2;
		
		uint32_t adc_en : 1;
		
		uint32_t : 2;
		
		uint32_t sdio_en : 1;
		uint32_t spi1_en : 1;
		uint32_t spi45_en : 1;
		uint32_t syscfg_en : 1;
		
		uint32_t : 1;
		
		uint32_t tmr9_en : 1;
		uint32_t tmr10_en : 1;
		uint32_t tmr11_en : 1;
		
		uint32_t : 3;
		
		uint32_t sai1_en : 1;
		uint32_t sai2_en : 1;
		
		uint32_t : 8;
	};
};

typedef union STM32RCCBackupDomainControl STM32RCCBackupDomainControl;
union STM32RCCBackupDomainControl {
	uint32_t reg;
	struct {
		uint32_t lse_on : 1;
		uint32_t lse_rdy : 1;
		uint32_t lse_byp : 1;
		uint32_t lse_mod : 1;
		
		uint32_t : 4;
		
		uint32_t rtc_sel0 : 1;
		uint32_t rtc_sel1 : 1;
		
		uint32_t : 5;
		
		uint32_t rtc_en : 1;
		uint32_t bd_rst : 1;
		
		uint32_t : 15;
	};
};

typedef union STM32RCCClockControlStatus STM32RCCClockControlStatus;
union STM32RCCClockControlStatus {
	uint32_t reg;
	struct {
		uint32_t lsi_on : 1;
		uint32_t lsi_rdy : 1;
		
		uint32_t : 22;
		
		uint32_t rmv_flag : 1;
		uint32_t bor_rst_flag : 1;
		uint32_t pad_rst_flag : 1;
		uint32_t por_rst_flag : 1;
		uint32_t sft_rst_flag : 1;
		uint32_t wdg_rst_flag : 1;
		uint32_t wwdg_rst_flag : 1;
		uint32_t lpwdg_rst_flag : 1;
	};
};

typedef union STM32RCCSpreadSpectrum STM32RCCSpreadSpectrum;
union STM32RCCSpreadSpectrum {
	uint32_t reg;
	struct {
		uint32_t modper : 13;
		uint32_t incstep : 15;
		
		uint32_t : 2;
		
		uint32_t spread_sel : 1;
		uint32_t sscg_en : 1;
	};
};

typedef union STM32RCCDedicatedClockConfig STM32RCCDedicatedClockConfig;
union STM32RCCDedicatedClockConfig {
	uint32_t reg;
	struct {
		uint32_t pll_i2s_divq : 5;
		
		uint32_t : 3;
		
		uint32_t pll_sai_divq : 5;
		
		uint32_t : 7;
		
		uint32_t sai1_src : 2;
		uint32_t sai2_src : 2;
		
		uint32_t timpre : 1;
		
		uint32_t i2s1_src: 2;
		uint32_t i2s2_src: 2;
		
		uint32_t : 3;
	};
};

typedef union STM32RCCClocksGatedEnable STM32RCCClocksGatedEnable;
union STM32RCCClocksGatedEnable {
	uint32_t reg;
	struct {
		uint32_t ahb2_apb1_cken : 1;
		uint32_t ahb2_apb2_cken : 1;
		uint32_t cm4dbg_cken : 1;
		uint32_t spare_cken : 1;
		uint32_t sram_cken : 1;
		uint32_t flitf_cken : 1;
		uint32_t rcc_cken : 1;
		
		uint32_t : 25;
	};
};

typedef union STM32RCCDedicatedClockConfig2 STM32RCCDedicatedClockConfig2;
union STM32RCCDedicatedClockConfig2 {
	uint32_t reg;
	struct {
		uint32_t : 22;
		uint32_t fmp_i2c1_sel : 2;
		
		uint32_t : 2;
		
		uint32_t cec_sel : 1;
		uint32_t ck48m_sel : 1;
		uint32_t sdio_sel : 1;
		uint32_t spdif_rx_sel : 1;
		
		uint32_t : 2;
	};
};

typedef struct STM32RCC STM32RCC;
struct STM32RCC {
	STM32RCCClockControl cr;
	STM32RCCPLLConfig pll_cfgr;
	STM32RCCClockConfig cfgr;
	STM32RCCClockInterrupt cir;
	STM32RCCAHB1Reset ahb1_rstr;
	STM32RCCAHB2Reset ahb2_rstr;
	STM32RCCAHB3Reset ahb3_rstr;
	uint32_t _reserved0;
	STM32RCCAPB1Reset apb1_rstr;
	STM32RCCAPB2Reset apb2_rstr;
	uint32_t _reserved1[2];
	STM32RCCAHB1Enable ahb1_enr;
	STM32RCCAHB2Enable ahb2_enr;
	STM32RCCAHB3Enable ahb3_enr;
	uint32_t _reserved2;
	STM32RCCAPB1Enable apb1_enr;
	STM32RCCAPB2Enable apb2_enr;
	uint32_t _reserved3[2];
	STM32RCCAHB1Enable ahb1_lpenr;
	STM32RCCAHB2Enable ahb2_lpenr;
	STM32RCCAHB3Enable ahb3_lpenr;
	uint32_t _reserved4;
	STM32RCCAPB1Enable apb1_lpenr;
	STM32RCCAPB2Enable apb2_lpenr;
	uint32_t _reserved5[2];
	STM32RCCBackupDomainControl bdcr;
	STM32RCCClockControlStatus csr;
	uint32_t _reserved6[2];
	STM32RCCSpreadSpectrum ss_cgr;
	STM32RCCPLLConfig pll_i2c_cfgr;
	STM32RCCPLLConfig pll_sai_cfgr;
	STM32RCCDedicatedClockConfig dck_cfgr;
	STM32RCCClocksGatedEnable ck_gatenr;
	STM32RCCDedicatedClockConfig2 dck_cfgr2;
};

#endif
