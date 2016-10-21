#ifndef _STM32_GPIO_H_
#define _STM32_GPIO_H_

#include <stdint.h>

typedef union STM32GPIOMode STM32GPIOMode;
union STM32GPIOMode {
	uint32_t reg;
	struct {
		uint32_t pin0 : 2;
		uint32_t pin1 : 2;
		uint32_t pin2 : 2;
		uint32_t pin3 : 2;
		uint32_t pin4 : 2;
		uint32_t pin5 : 2;
		uint32_t pin6 : 2;
		uint32_t pin7 : 2;
		uint32_t pin8 : 2;
		uint32_t pin9 : 2;
		uint32_t pin10 : 2;
		uint32_t pin11 : 2;
		uint32_t pin12 : 2;
		uint32_t pin13 : 2;
		uint32_t pin14 : 2;
		uint32_t pin15 : 2;
	};
};

enum {
	STM32_GPIO_MODE_INPUT,
	STM32_GPIO_MODE_OUTPUT,
	STM32_GPIO_MODE_ALT_FUNC,
	STM32_GPIO_MODE_ANALOG,
};

typedef union STM32GPIOOutputType STM32GPIOOutputType;
union STM32GPIOOutputType {
	uint32_t reg;
	struct {
		uint32_t pin0 : 1;
		uint32_t pin1 : 1;
		uint32_t pin2 : 1;
		uint32_t pin3 : 1;
		uint32_t pin4 : 1;
		uint32_t pin5 : 1;
		uint32_t pin6 : 1;
		uint32_t pin7 : 1;
		uint32_t pin8 : 1;
		uint32_t pin9 : 1;
		uint32_t pin10 : 1;
		uint32_t pin11 : 1;
		uint32_t pin12 : 1;
		uint32_t pin13 : 1;
		uint32_t pin14 : 1;
		uint32_t pin15 : 1;
		uint32_t : 16;
	};
};

enum {
	STM32_GPIO_OUTPUT_TYPE_PUSH_PULL,
	STM32_GPIO_OUTPUT_TYPE_OPEN_DRAIN,
};

typedef union STM32GPIOSpeed STM32GPIOSpeed;
union STM32GPIOSpeed {
	uint32_t reg;
	struct {
		uint32_t pin0 : 2;
		uint32_t pin1 : 2;
		uint32_t pin2 : 2;
		uint32_t pin3 : 2;
		uint32_t pin4 : 2;
		uint32_t pin5 : 2;
		uint32_t pin6 : 2;
		uint32_t pin7 : 2;
		uint32_t pin8 : 2;
		uint32_t pin9 : 2;
		uint32_t pin10 : 2;
		uint32_t pin11 : 2;
		uint32_t pin12 : 2;
		uint32_t pin13 : 2;
		uint32_t pin14 : 2;
		uint32_t pin15 : 2;
	};
};

typedef union STM32GPIOPullUpDown STM32GPIOPullUpDown;
union STM32GPIOPullUpDown {
	uint32_t reg;
	struct {
		uint32_t pin0 : 2;
		uint32_t pin1 : 2;
		uint32_t pin2 : 2;
		uint32_t pin3 : 2;
		uint32_t pin4 : 2;
		uint32_t pin5 : 2;
		uint32_t pin6 : 2;
		uint32_t pin7 : 2;
		uint32_t pin8 : 2;
		uint32_t pin9 : 2;
		uint32_t pin10 : 2;
		uint32_t pin11 : 2;
		uint32_t pin12 : 2;
		uint32_t pin13 : 2;
		uint32_t pin14 : 2;
		uint32_t pin15 : 2;
	};
};

enum {
	STM32_GPIO_PULL_NONE,
	STM32_GPIO_PULL_UP,
	STM32_GPIO_PULL_DOWN,
};

typedef union STM32GPIOInputData STM32GPIOInputData;
union STM32GPIOInputData {
	uint32_t reg;
	struct {
		uint32_t pin0 : 1;
		uint32_t pin1 : 1;
		uint32_t pin2 : 1;
		uint32_t pin3 : 1;
		uint32_t pin4 : 1;
		uint32_t pin5 : 1;
		uint32_t pin6 : 1;
		uint32_t pin7 : 1;
		uint32_t pin8 : 1;
		uint32_t pin9 : 1;
		uint32_t pin10 : 1;
		uint32_t pin11 : 1;
		uint32_t pin12 : 1;
		uint32_t pin13 : 1;
		uint32_t pin14 : 1;
		uint32_t pin15 : 1;
		uint32_t : 16;
	};
};

typedef union STM32GPIOOutputData STM32GPIOOutputData;
union STM32GPIOOutputData {
	uint32_t reg;
	struct {
		uint32_t pin0 : 1;
		uint32_t pin1 : 1;
		uint32_t pin2 : 1;
		uint32_t pin3 : 1;
		uint32_t pin4 : 1;
		uint32_t pin5 : 1;
		uint32_t pin6 : 1;
		uint32_t pin7 : 1;
		uint32_t pin8 : 1;
		uint32_t pin9 : 1;
		uint32_t pin10 : 1;
		uint32_t pin11 : 1;
		uint32_t pin12 : 1;
		uint32_t pin13 : 1;
		uint32_t pin14 : 1;
		uint32_t pin15 : 1;
		uint32_t : 16;
	};
};

typedef union STM32GPIOBitSetReset STM32GPIOBitSetReset;
union STM32GPIOBitSetReset {
	uint32_t reg;
	struct {
		uint32_t pin0_set : 1;
		uint32_t pin1_set : 1;
		uint32_t pin2_set : 1;
		uint32_t pin3_set : 1;
		uint32_t pin4_set : 1;
		uint32_t pin5_set : 1;
		uint32_t pin6_set : 1;
		uint32_t pin7_set : 1;
		uint32_t pin8_set : 1;
		uint32_t pin9_set : 1;
		uint32_t pin10_set : 1;
		uint32_t pin11_set : 1;
		uint32_t pin12_set : 1;
		uint32_t pin13_set : 1;
		uint32_t pin14_set : 1;
		uint32_t pin15_set : 1;
		uint32_t pin0_reset : 1;
		uint32_t pin1_reset : 1;
		uint32_t pin2_reset : 1;
		uint32_t pin3_reset : 1;
		uint32_t pin4_reset : 1;
		uint32_t pin5_reset : 1;
		uint32_t pin6_reset : 1;
		uint32_t pin7_reset : 1;
		uint32_t pin8_reset : 1;
		uint32_t pin9_reset : 1;
		uint32_t pin10_reset : 1;
		uint32_t pin11_reset : 1;
		uint32_t pin12_reset : 1;
		uint32_t pin13_reset : 1;
		uint32_t pin14_reset : 1;
		uint32_t pin15_reset : 1;
	};
};

typedef union STM32GPIOLock STM32GPIOLock;
union STM32GPIOLock {
	uint32_t reg;
	struct {
		uint32_t pin0 : 1;
		uint32_t pin1 : 1;
		uint32_t pin2 : 1;
		uint32_t pin3 : 1;
		uint32_t pin4 : 1;
		uint32_t pin5 : 1;
		uint32_t pin6 : 1;
		uint32_t pin7 : 1;
		uint32_t pin8 : 1;
		uint32_t pin9 : 1;
		uint32_t pin10 : 1;
		uint32_t pin11 : 1;
		uint32_t pin12 : 1;
		uint32_t pin13 : 1;
		uint32_t pin14 : 1;
		uint32_t pin15 : 1;
		uint32_t lock_key : 1;
		uint32_t : 15;
	};
};

typedef union STM32GPIOAltFuncLow STM32GPIOAltFuncLow;
union STM32GPIOAltFuncLow {
	uint32_t reg;
	struct {
		uint32_t pin0 : 4;
		uint32_t pin1 : 4;
		uint32_t pin2 : 4;
		uint32_t pin3 : 4;
		uint32_t pin4 : 4;
		uint32_t pin5 : 4;
		uint32_t pin6 : 4;
		uint32_t pin7 : 4;
	};
};

typedef union STM32GPIOAltFuncHigh STM32GPIOAltFuncHigh;
union STM32GPIOAltFuncHigh {
	uint32_t reg;
	struct {
		uint32_t pin8 : 4;
		uint32_t pin9 : 4;
		uint32_t pin10 : 4;
		uint32_t pin11 : 4;
		uint32_t pin12 : 4;
		uint32_t pin13 : 4;
		uint32_t pin14 : 4;
		uint32_t pin15 : 4;
	};
};

typedef struct STM32GPIO STM32GPIO;
struct STM32GPIO {
	STM32GPIOMode mode;
	STM32GPIOOutputType output_type;
	STM32GPIOSpeed speed;
	STM32GPIOPullUpDown pull_up_down;
	STM32GPIOInputData input;
	STM32GPIOOutputData output;
	STM32GPIOBitSetReset bit_set_reset;
	STM32GPIOLock lock;
	STM32GPIOAltFuncLow alt_func_low;
	STM32GPIOAltFuncHigh alt_func_high;
};

#endif
