#ifndef _STM32_STM32F044P6_RCC_H_
#define _STM32_STM32F044P6_RCC_H_

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
		
		uint32_t : 6;
	};
};

typedef union STM32RCCClockConfig STM32RCCClockConfig;
union STM32RCCClockConfig {
	uint32_t reg;
	struct {
		uint32_t sw : 2;
		uint32_t sws : 2;
		uint32_t hpre : 4;
		uint32_t ppre : 3;
		uint32_t  : 3;
		uint32_t adc_pre : 1;
		uint32_t pllsrc0 : 1;
		uint32_t pllsrc1 : 1;
		uint32_t pllxtpre : 1;
		uint32_t pllmul : 4;
		uint32_t : 2;
		uint32_t mco : 4;
		uint32_t mco_pre : 3;
		uint32_t pll_nodiv : 1;
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
		uint32_t hsi_14_rdy_if : 1;
		uint32_t hsi_48_rdy_if : 1;
		uint32_t css_if : 1;
		
		uint32_t lsi_rdy_ie : 1;
		uint32_t lse_rdy_ie : 1;
		uint32_t hsi_rdy_ie : 1;
		uint32_t hse_rdy_ie : 1;
		uint32_t pll_rdy_ie : 1;
		uint32_t hsi_14_rdy_ie : 1;
		uint32_t hsi_48_rdy_ie : 1;
		uint32_t : 1;
		
		uint32_t lsi_rdy_c : 1;
		uint32_t lse_rdy_c : 1;
		uint32_t hsi_rdy_c : 1;
		uint32_t hse_rdy_c : 1;
		uint32_t pll_rdy_c: 1;
		uint32_t hsi_14_rdy_c : 1;
		uint32_t hsi_48_rdy_c : 1;
		uint32_t css_c : 1;
		
		uint32_t : 8;
	};
};

typedef union STM32RCCAHBReset STM32RCCAHBReset;
union STM32RCCAHBReset {
	uint32_t reg;
	struct {
		uint32_t : 17;
		
		uint32_t gpio_a_rst : 1;
		uint32_t gpio_b_rst : 1;
		uint32_t gpio_c_rst : 1;
		uint32_t gpio_d_rst : 1;
		uint32_t gpio_e_rst : 1;
		uint32_t gpio_f_rst : 1;
		
		uint32_t : 1;
		
		uint32_t tsc_rst : 1;
		
		uint32_t : 7;
		
	};
};

typedef union STM32RCCAPB1Reset STM32RCCAPB1Reset;
union STM32RCCAPB1Reset {
	uint32_t reg;
	struct {
		uint32_t tm2_rst : 1;
		uint32_t tm3_rst : 1;
		uint32_t : 2;
		uint32_t tm6_rst : 1;
		uint32_t tm7_rst : 1;
		uint32_t : 2;
		uint32_t tm14_rst : 1;
		
		uint32_t : 2;
		
		uint32_t wwdg_rst : 1;
		
		uint32_t : 2;
		
		uint32_t spi2_rst : 1;
		
		uint32_t : 2;
		
		uint32_t usart2_rst : 1;
		uint32_t usart3_rst : 1;
		uint32_t usart4_rst : 1;
		uint32_t usart5_rst : 1;
		
		uint32_t i2c1_rst : 1;
		uint32_t i2c2_rst : 1;
		uint32_t usb_rst : 1;
		
		uint32_t : 1;
		
		uint32_t can_rst : 1;
		
		uint32_t : 1;
		
		uint32_t crs_rst : 1;
		uint32_t pwr_rst : 1;
		uint32_t dac_rst : 1;
		uint32_t cec_rst : 1;
		
		uint32_t : 1;
	};
};

typedef union STM32RCCAPB2Reset STM32RCCAPB2Reset;
union STM32RCCAPB2Reset {
	uint32_t reg;
	struct {
		uint32_t syscfg_rst : 1;
		
		uint32_t : 5;
		
		uint32_t usart6_rst : 1;
		uint32_t usart7_rst : 1;
		uint32_t usart8_rst : 1;
		uint32_t adc_rst : 1;
		
		uint32_t : 1;
		
		uint32_t tim1_rst : 1;
		uint32_t spi1_rst : 1;
		
		uint32_t : 1;
		
		uint32_t usart1_rst : 1;
		
		uint32_t : 1;
		
		uint32_t tim15_rst : 1;
		uint32_t tim16_rst : 1;
		uint32_t tim17_rst : 1;
		
		uint32_t : 3;
		
		uint32_t dbgmcu_rst : 1;
		
		uint32_t : 9;
	};
};

typedef union STM32RCCAHBEnable STM32RCCAHBEnable;
union STM32RCCAHBEnable {
	uint32_t reg;
	struct {
		uint32_t : 17;
		
		uint32_t gpio_a_en : 1;
		uint32_t gpio_b_en : 1;
		uint32_t gpio_c_en : 1;
		uint32_t gpio_d_en : 1;
		uint32_t gpio_e_en : 1;
		uint32_t gpio_f_en : 1;
		
		uint32_t : 1;
		
		uint32_t tsc_en : 1;
		
		uint32_t : 7;
		
	};
};

typedef union STM32RCCAPB1Enable STM32RCCAPB1Enable;
union STM32RCCAPB1Enable {
	uint32_t reg;
	struct {
		uint32_t tm2_en : 1;
		uint32_t tm3_en : 1;
		uint32_t : 2;
		uint32_t tm6_en : 1;
		uint32_t tm7_en : 1;
		uint32_t : 2;
		uint32_t tm14_en : 1;
		
		uint32_t : 2;
		
		uint32_t wwdg_en : 1;
		
		uint32_t : 2;
		
		uint32_t spi2_en : 1;
		
		uint32_t : 2;
		
		uint32_t usart2_en : 1;
		uint32_t usart3_en : 1;
		uint32_t usart4_en : 1;
		uint32_t usart5_en : 1;
		
		uint32_t i2c1_en : 1;
		uint32_t i2c2_en : 1;
		uint32_t usb_en : 1;
		
		uint32_t : 1;
		
		uint32_t can_en : 1;
		
		uint32_t : 1;
		
		uint32_t crs_en : 1;
		uint32_t pwr_en : 1;
		uint32_t dac_en : 1;
		uint32_t cec_en : 1;
		
		uint32_t : 1;
	};
};

typedef union STM32RCCAPB2Enable STM32RCCAPB2Enable;
union STM32RCCAPB2Enable {
	uint32_t reg;
	struct {
		uint32_t syscfg_en : 1;
		
		uint32_t : 5;
		
		uint32_t usart6_en : 1;
		uint32_t usart7_en : 1;
		uint32_t usart8_en : 1;
		uint32_t adc_en : 1;
		
		uint32_t : 1;
		
		uint32_t tim1_en : 1;
		uint32_t spi1_en : 1;
		
		uint32_t : 1;
		
		uint32_t usart1_en : 1;
		
		uint32_t : 1;
		
		uint32_t tim15_en : 1;
		uint32_t tim16_en : 1;
		uint32_t tim17_en : 1;
		
		uint32_t : 3;
		
		uint32_t dbgmcu_en : 1;
		
		uint32_t : 9;
	};
};

typedef union STM32RCCBackupDomainControl STM32RCCBackupDomainControl;
union STM32RCCBackupDomainControl {
	uint32_t reg;
	struct {
		uint32_t lse_on : 1;
		uint32_t lse_rdy : 1;
		uint32_t lse_byp : 1;
		uint32_t lse_drv : 1;
		
		uint32_t : 4;
		
		uint32_t rtc_sel : 2;
		
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
		uint32_t obl_rst_flag : 1;
		uint32_t pin_rst_flag : 1;
		uint32_t por_rst_flag : 1;
		uint32_t sft_rst_flag : 1;
		uint32_t iwdg_rst_flag : 1;
		uint32_t wwdg_rst_flag : 1;
		uint32_t lpwdg_rst_flag : 1;
	};
};

typedef union STM32RCCClockConfig2 STM32RCCClockConfig2;
union STM32RCCClockConfig2 {
	uint32_t reg;
	struct {
		uint32_t prediv : 4;
		
		uint32_t : 28;
	};
};

typedef union STM32RCCClockConfig3 STM32RCCClockConfig3;
union STM32RCCClockConfig3 {
	uint32_t reg;
	struct {
		uint32_t usart1_sw : 2;
		
		uint32_t : 2;
		
		uint32_t i2c1_sw : 1;
		uint32_t : 1;
		uint32_t cec_sw : 1;
		uint32_t usb_sw : 1;
		uint32_t adc_sw : 1;
		
		uint32_t : 7;
		
		uint32_t usart2_sw : 2;
		uint32_t usart3_sw : 2;
		
		uint32_t : 12;
	};
};

typedef union STM32RCCClockControl2 STM32RCCClockControl2;
union STM32RCCClockControl2 {
	uint32_t reg;
	struct {
		uint32_t hsi_14_on : 1;
		uint32_t hsi_14_rdy : 1;
		uint32_t hsi_14_dis : 1;
		uint32_t hsi_14_trim : 5;
		uint32_t hsi_14_cal : 8;
		
		uint32_t hsi_48_on : 1;
		uint32_t hsi_48_rdy : 1;
		
		uint32_t : 6;
		
		uint32_t hsi_48_cal : 8;
	};
};

typedef struct STM32RCC STM32RCC;
struct STM32RCC {
	STM32RCCClockControl cr;
	STM32RCCClockConfig cfgr;
	STM32RCCClockInterrupt cir;
	
	STM32RCCAPB2Reset apb2_rstr;
	STM32RCCAPB1Reset apb1_rstr;
	
	STM32RCCAHBEnable ahb_enr;
	
	STM32RCCAPB2Enable apb2_enr;
	STM32RCCAPB1Enable apb1_enr;
	
	STM32RCCBackupDomainControl bdcr;
	STM32RCCClockControlStatus csr;
	
	STM32RCCAHBReset ahb_rstr;
	
	STM32RCCClockConfig2 cfgr2;
	STM32RCCClockConfig3 cfgr3;
	STM32RCCClockControl2 cr2;
};



extern volatile STM32RCC RCC;

#endif
