include $(TOPDIR)/common.mk

#Name of the project
NAME		=	project

#Installer can be STLINK or UART
INSTALLER	=	STLINK

#Serial device for programming
TTYDEV		?=	/dev/ttyUSB0

#Microcontroller
DEVICE		=	stm32f446re
CPUCORE		=	cortex-m4

#Toolchain to use
TARGET		=	arm-none-eabi-

#Compiler flags
LDFLAGS		+=	
CFLAGS		+=	-Wall -std=c99 -g -O0 -DDEBUG
CXXFLAGS	+=	-Wall -std=c99 -g -O0 -DDEBUG
ASFLAGS		+=	
