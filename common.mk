# Common variables
MAKEFLAGS	+=	--no-print-directory

# Tools
AS		=	$(TARGET)as
AR		=	$(TARGET)ar
LD		=	$(TARGET)ld
CC		=	$(TARGET)gcc
CXX		=	$(TARGET)g++
OBJCOPY		=	$(TARGET)objcopy
OBJDUMP		=	$(TARGET)objdump

INSTALL-UART	=	stm32loader -p $(TTYDEV) -e -w -v $(BINFILE)
INSTALL-STLINK	=	st-flash --serial $(TTYDEV) --format ihex write $(HEXFILE)
INSTALL-USB	=	dfu-util -a 0 -s 0x08000000 -D $(BINFILE)
DEBUGCMD	=	st-util

#Binaries
ELFFILE		=	$(NAME).elf
BINFILE		=	$(NAME).bin
HEXFILE		=	$(NAME).hex

#General flags
LDFLAGS		=	-L$(TOPDIR)/device -L$(TOPDIR) -T$(LINKSCRIPT) -nostartfiles
CFLAGS		=	-D__NEWLIB__ -ffreestanding -I$(TOPDIR)/include \
			-mcpu=$(CPUCORE) -mthumb -DDEVICE=$(DEVICE)
CXXFLAGS	:=	$(CFLAGS)
ASFLAGS		=	-mcpu=$(CPUCORE) -mthumb

#Linkscript
LINKSCRIPT	=	$(TOPDIR)/device/$(DEVICE).ld

#Makefile tools
MKDIR		=	mkdir -p
RMDIR		=	rmdir --ignore-fail-on-non-empty
