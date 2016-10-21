# Makefile configurations
MAKEFLAGS	+=	--no-print-directory

TTYDEV		?=	/dev/ttyUSB0

# Tools
TARGET		=	arm-none-eabi-
AS		=	$(TARGET)as
AR		=	$(TARGET)ar
CC		=	$(TARGET)gcc
CXX		=	$(TARGET)g++
OBJCOPY		=	$(TARGET)objcopy
OBJDUMP		=	$(TARGET)objdump
INSTALL		=	stm32loader
DEBUGCMD	=	st-flash

#Binaries
ELFFILE		=	node.elf
BINFILE		=	node.bin
HEXFILE		=	node.hex

#Link script
LINKSCRIPT	=	link.ld

#General flags
LDFLAGS		=	-T$(LINKSCRIPT) -nostartfiles
CFLAGS		=	-Wall -std=c99 -g -O0 -DDEBUG -D__NEWLIB__ -ffreestanding -mthumb -mcpu=cortex-m0 -I$(TOPDIR)/include
CXXFLAGS	=	$(CFLAGS)
ASFLAGS		=	-mthumb -mcpu=cortex-m0
DEBUGFLAGS	=	--serial $(TTYDEV) --format ihex write
INSTALLFLAGS	=	-p $(TTYDEV) -e -w -v 

#Makefile tools
MKDIR		=	mkdir -p
RMDIR		=	rmdir --ignore-fail-on-non-empty
