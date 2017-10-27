#ifndef _STM32_STM32F042P6_USB_H_
#define _STM32_STM32F042P6_USB_H_

#include <stdint.h>

typedef union STM32USBEndpoint STM32USBEndpoint;
union STM32USBEndpoint {
	uint32_t reg;
	struct {
		uint32_t address : 4;
		uint32_t stat_tx : 2;
		uint32_t dotg_tx : 1;
		uint32_t ctr_tx : 1;
		uint32_t ep_kind : 1;
		uint32_t ep_type : 2;
		uint32_t setup : 1;
		uint32_t stat_rx : 2;
		uint32_t dotg_rx : 1;
		uint32_t ctr_rx : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32USBControl STM32USBControl;
union STM32USBControl {
	uint32_t reg;
	struct {
		uint32_t fres : 1;
		uint32_t pdwn : 1;
		uint32_t lpmode : 1;
		uint32_t fsusp : 1;
		uint32_t resume : 1;
		uint32_t : 1;
		uint32_t l1reqm : 1;
		uint32_t esofm : 1;
		uint32_t sofm : 1;
		uint32_t resetm : 1;
		uint32_t suspm : 1;
		uint32_t wkupm : 1;
		uint32_t errm : 1;
		uint32_t pmaovrm : 1;
		uint32_t ctrm : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32USBInterruptStatus STM32USBInterruptStatus;
union STM32USBInterruptStatus {
	uint32_t reg;
	struct {
		uint32_t ep_id : 4;
		uint32_t dir : 1;
		uint32_t : 2;
		uint32_t l1req : 1;
		uint32_t esof : 1;
		uint32_t sof : 1;
		uint32_t reset : 1;
		uint32_t susp : 1;
		uint32_t wkup : 1;
		uint32_t err : 1;
		uint32_t pmaovr : 1;
		uint32_t ctr : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32USBFrameNumber STM32USBFrameNumber;
union STM32USBFrameNumber {
	uint32_t reg;
	struct {
		uint32_t fn : 11;
		uint32_t lsof : 2;
		uint32_t lck : 1;
		uint32_t rxdm : 1;
		uint32_t rxdp : 1;
		
		uint32_t : 16;
	};
};

typedef union STM32USBDeviceAddress STM32USBDeviceAddress;
union STM32USBDeviceAddress {
	uint32_t reg;
	struct {
		uint32_t add : 7;
		uint32_t ef : 1;
		
		uint32_t : 24;
	};
};

typedef union STM32USBBufferTable STM32USBBufferTable;
union STM32USBBufferTable {
	uint32_t reg;
	struct {
		uint32_t btable : 16;
		
		uint32_t : 16;
	};
};

typedef union STM32USBLPMControlStatus STM32USBLPMControlStatus;
union STM32USBLPMControlStatus {
	uint32_t reg;
	struct {
		uint32_t lpmen : 1;
		uint32_t lpmack : 1;
		uint32_t : 1;
		uint32_t remwake : 1;
		uint32_t besl : 4;
		
		uint32_t : 24;
	};
}

typedef union STM32USBBatteryChargingDetector STM32USBBatteryChargingDetector;
union STM32USBBatteryChargingDetector {
	uint32_t reg;
	struct {
		uint32_t bcden : 1;
		uint32_t dcden : 1;
		uint32_t pden : 1;
		uint32_t sden : 1;
		uint32_t dcdet : 1;
		uint32_t pdet : 1;
		uint32_t sdet : 1;
		uint32_t ps2det : 1;
		uint32_t : 7;
		uint32_t dppu : 1;
		
		uint32_t : 16;
	};
}

typedef struct STM32USB STM32USB;
struct STM32USB {
	STM32USBEndpoint endpoint[8];
	uint32_t pad[8];
	STM32USBControl cntr;
	STM32USBInterruptStatus istr;
	STM32USBFrameNumber fnr;
	STM32USBDeviceAddress daddr;
	STM32USBBufferTable btable;
	STM32USBLPMControlStatus lpmcsr;
	STM32USBBatteryChargingDetector bcdr;
};



STM32SPI USB;

#endif
