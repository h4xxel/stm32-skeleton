include $(TOPDIR)/common.mk

#Name of the project
NAME		=	stm32

#Installer can be STLINK, USB or UART
INSTALLER	=	USB

#Serial device for programming
TTYDEV		?=	/dev/ttyUSB0

#Microcontroller
DEVICE		=	stm32f042p6
CPUCORE		=	cortex-m0

#Toolchain to use
TARGET		=	arm-none-eabi-

#Compiler flags
LDFLAGS		+=	
CFLAGS		+=	-Wall -std=c11 -g -O0 -DDEBUG
CXXFLAGS	+=	-Wall -std=c11 -g -O0 -DDEBUG
ASFLAGS		+=	
