#ifndef _STM32_STM32F042P6_CAN_H_
#define _STM32_STM32F042P6_CAN_H_

#include <stdint.h>

typedef union STM32CanMasterControl STM32MasterControl;
union STM32CanMasterControl {
	uint32_t reg;
	struct {
		uint32_t inrq : 1;
		uint32_t sleep : 1;
		uint32_t txfp : 1;
		uint32_t rflm : 1;
		uint32_t nart : 1;
		uint32_t awum : 1;
		uint32_t abom : 1;
		uint32_t ttcm : 1;
		
		uint32_t : 7;
		
		uint32_t reset : 1;
		uint32_t dbf : 1;
		
		uint32_t : 15;
	};
};

typedef union STM32CanMasterStatus STM32MasterStatus;
union STM32CanMasterStatus {
	uint32_t reg;
	struct {
		uint32_t inak : 1;
		uint32_t slak : 1;
		uint32_t erri : 1;
		uint32_t wkui : 1;
		uint32_t slaki : 1;
		uint32_t : 3;
		uint32_t txm : 1;
		uint32_t rxm : 1;
		uint32_t samp : 1;
		uint32_t rx : 1;
		
		uint32_t : 20;
	};
};

typedef union STM32CanTransmitStatus STM32TransmitStatus;
union STM32TransmitStatus {
	uint32_t reg;
	struct {
		uint32_t rqcp0 : 1;
		uint32_t txok0 : 1;
		uint32_t alst0 : 1;
		uint32_t terr0 : 1;
		uint32_t : 3;
		uint32_t abrq0 : 1;
		
		uint32_t rqcp1 : 1;
		uint32_t txok1 : 1;
		uint32_t alst1 : 1;
		uint32_t terr1 : 1;
		uint32_t : 3;
		uint32_t abrq1 : 1;
		
		uint32_t rqcp2 : 1;
		uint32_t txok2 : 1;
		uint32_t alst2 : 1;
		uint32_t terr2 : 1;
		uint32_t : 3;
		uint32_t abrq2 : 1;
		
		uint32_t code : 2;
		
		uint32_t tme0 : 1;
		uint32_t tme1 : 1;
		uint32_t tme2 : 1;
		
		uint32_t low0 : 1;
		uint32_t low1 : 1;
		uint32_t low2 : 1;
	};
};

typedef union STM32CanReceiveFifo STM32CanReceiveFifo;
union STM32CanReceiveFifo {
	uint32_t reg;
	struct {
		uint32_t fmp : 2;
		uint32_t : 1;
		uint32_t full : 1;
		uint32_t fovr : 1;
		uint32_t rfom : 1;
		
		uint32_t : 26;
	};
};

typedef union STM32CanInterruptEnable STM32CanInterruptEnable;
union STM32CanInterruptEnable {
	uint32_t reg;
	struct {
		uint32_t tme_ie : 1;
		
		uint32_t fmp_ie0 : 1;
		uint32_t ff_ie0 : 1;
		uint32_t fov_ie0 : 1;
		
		uint32_t fmp_ie1 : 1;
		uint32_t ff_ie1 : 1;
		uint32_t fov_ie1 : 1;
		
		uint32_t ewg_ie : 1;
		uint32_t epv_ie : 1;
		uint32_t bof_ie : 1;
		uint32_t lec_ie : 1;
		
		uint32_t : 3;
		
		uint32_t err_ie : 1;
		uint32_t wku_ie : 1;
		uint32_t slk_ie : 1;
		
		uint32_t : 14;
	};
};

typedef union STM32CanErrorStatus STM32CanErrorStatus;
union STM32CanErrorStatus {
	uint32_t reg;
	struct {
		uint32_t ewgf : 1;
		uint32_t epvf : 1;
		uint32_t boff : 1;
		
		uint32_t : 1;
		
		uint32_t lec : 3;
		
		uint32_t : 9;
		
		uint32_t tec : 8;
		uint32_t rec : 8;
	};
};

typedef union STM32CanBitTiming STM32CanBitTiming;
union STM32CanBitTiming {
	uint32_t reg;
	struct {
		uint32_t brp : 10;
		
		uint32_t : 6;
		
		uint32_t ts1 : 4;
		uint32_t ts2 : 3;
		
		uint32_t : 1;
		
		uint32_t sjw : 2;
		
		uint32_t : 4;
		
		uint32_t lbkm : 1;
		uint32_t silm : 1;
	};
};



#endif
