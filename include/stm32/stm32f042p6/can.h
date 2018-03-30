#ifndef _STM32_STM32F042P6_CAN_H_
#define _STM32_STM32F042P6_CAN_H_

#include <stdint.h>

typedef union STM32CanMasterControl STM32CanMasterControl;
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

typedef union STM32CanMasterStatus STM32CanMasterStatus;
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

typedef union STM32CanTxStatus STM32CanTxStatus;
union STM32CanTxStatus {
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
		
		uint32_t tme : 3;
		
		uint32_t low : 3;
	};
};

typedef union STM32CanRxFifo STM32CanRxFifo;
union STM32CanRxFifo {
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

typedef union STM32CanTxMboxIndentifier STM32CanTxMboxIndentifier;
union STM32CanTxMboxIndentifier {
	uint32_t reg;
	struct {
		uint32_t txrq : 1;
		uint32_t rtr : 1;
		uint32_t ide : 1;
		uint32_t exid : 18;
		uint32_t stid : 11;
	};
};

typedef union STM32CanTxMboxDataLengthControlTimestamp STM32CanTxMboxDataLengthControlTimestamp;
union STM32CanTxMboxDataLengthControlTimestamp {
	uint32_t reg;
	struct {
		uint32_t dlc : 4;
		uint32_t : 12;
		uint32_t time : 16;
	};
};

typedef union STM32CanMboxData STM32CanMboxData;
union STM32CanMboxData {
	uint32_t reg;
	uint8_t data[4];
};

typedef union STM32CanRxFifoMboxIndentifier STM32CanRxFifoMboxIndentifier;
union STM32CanRxFifoMboxIndentifier {
	uint32_t reg;
	struct {
		uint32_t : 1;
		uint32_t rtr : 1;
		uint32_t ide : 1;
		uint32_t exid : 18;
		uint32_t stid : 11;
	};
};

typedef union STM32CanRxMboxDataLengthControlTimestamp STM32CanRxMboxDataLengthControlTimestamp;
union STM32CanRxMboxDataLengthControlTimestamp {
	uint32_t reg;
	struct {
		uint32_t dlc : 4;
		uint32_t : 4;
		uint32_t fmi : 8;
		uint32_t time : 16;
	};
};

typedef union STM32CanFilterMaster STM32CanFilterMaster;
union STM32CanFilterMaster {
	uint32_t reg;
	struct {
		uint32_t finit : 1;
		uint32_t : 7;
		uint32_t can2sb : 6;
		uint32_t : 18;
	};
};

typedef struct STM32CanTxMbox STM32CanTxMbox;
struct STM32CanTxMbox {
	STM32CanTxMboxIndentifier tir;
	STM32CanTxMboxDataLengthControlTimestamp tdtr;
	//STM32CanMboxData tdlr;
	//STM32CanMboxData tdhr;
	uint8_t data[8];
};

typedef struct STM32CanRxMbox STM32CanRxMbox;
struct STM32CanRxMbox {
	STM32CanRxFifoMboxIndentifier rir;
	STM32CanRxMboxDataLengthControlTimestamp rdtr;
	//STM32CanMboxData rdlr;
	//STM32CanMboxData rdhr;
	uint8_t data[8];
};

typedef struct STM32CAN STM32CAN;
struct STM32CAN {
	STM32CanMasterControl mcr;
	STM32CanMasterStatus msr;
	STM32CanTxStatus tsr;
	STM32CanRxFifo rf[2];
	STM32CanInterruptEnable ier;
	STM32CanErrorStatus esr;
	STM32CanBitTiming btr;
	
	uint32_t pad0[88];
	
	STM32CanTxMbox tx_mbox[3];
	STM32CanRxMbox rx_mbox[2];
	
	uint32_t pad1[12];
	
	uint32_t fm1r;
	uint32_t pad2;
	uint32_t fs1r;
	uint32_t pad3;
	uint32_t ffa1r;
	uint32_t pad4;
	uint32_t fa1r;
	uint32_t pad5;
	
	uint32_t pad6[7];
	
	struct {
		uint32_t fr0;
		uint32_t fr1;
	} fifo[28];
};

extern volatile STM32CAN CAN;

#endif
