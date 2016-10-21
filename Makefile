TOPDIR	=	.
include config.mk

# Sub directories to build
SRCDIRS		=	src
#PLUGINSDIR	=	plugins
#MODULESDIR	=	submodules

SUBDIRS		=	$(SRCDIRS) $(PLUGINSDIR) $(MODULESDIR)

MODULES		=	$(wildcard $(addsuffix /*.a,$(MODULESDIR)))

.PHONY: all clean install-uart install-stlink debug
.PHONY: $(SUBDIRS)

all: $(HEXFILE) $(BINFILE)
	@echo "Build complete."
	@echo 

$(BINFILE): $(ELFFILE)
	@echo " [OBJC] $(BINFILE)"
	@$(OBJCOPY) -O binary $< $@

$(HEXFILE): $(ELFFILE)
	@echo " [OBJC] $(HEXFILE)"
	@$(OBJCOPY) -O ihex $< $@

$(ELFFILE): $(SUBDIRS)
	@echo " [ LD ] $(ELFFILE)"
	@$(CC) -o $(ELFFILE) $(CFLAGS) -Wl,--whole-archive $(addsuffix /out.a,$(SRCDIRS)) -Wl,--no-whole-archive $(MODULES) $(LDFLAGS)
	

clean: $(SUBDIRS)
	@echo " [ RM ] $(ELFFILE) $(HEXFILE) $(BINFILE)"
	@$(RM) $(ELFFILE) $(HEXFILE) $(BINFILE)
	
	@echo
	@echo "Source tree cleaned."
	@echo

install:
	@echo " [INST] $(NAME)"
	@$(INSTALL-$(INSTALLER))

$(SUBDIRS):
	@echo " [ CD ] $(CURRENTPATH)$@/"
	@+make -C "$@" "CURRENTPATH=$(CURRENTPATH)$@/" $(MAKECMDGOALS)
	@echo " [ CD ] $(CURRENTPATH)"
