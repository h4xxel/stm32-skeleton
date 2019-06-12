TOPDIR	=	$(shell DIR=.; while [ ! "`readlink -f \"$${DIR}\"`" = "/" -a ! -f "$${DIR}/config.mk" ]; do DIR="../$${DIR}"; done; echo "$${DIR}")
ifeq ($(shell readlink -f "$(TOPDIR)"),/)
	$(error Could not find the project top directory with config.mk)
endif
include $(TOPDIR)/config.mk

# Extra per-directory make configuration
-include extra.mk

# Sub directories to build
SUBDIRS		=	$(patsubst %/,%,$(foreach subdir,$(wildcard */Makefile),$(dir $(subdir))))
ELFFILES		=	$(addsuffix .elf,$(SUBDIRS))
HEXFILES		=	$(addsuffix .hex,$(SUBDIRS))
BINFILES		=	$(addsuffix .bin,$(SUBDIRS))

INSTALLS		=	$(addprefix install/,$(SUBDIRS))

.PHONY: all clean
.PHONY: $(SUBDIRS) $(INSTALLS)
.SUFFIXES:

all: $(ELFFILES) $(HEXFILES) $(BINFILES)
	@echo 
	@echo "Examples build complete."
	@echo 

clean: $(SUBDIRS)
	@echo " [ RM ] $(ELFFILES) $(HEXFILES) $(BINFILES)"
	@$(RM) $(ELFFILES) $(HEXFILES) $(BINFILES)
	
	@echo
	@echo "Examples source tree cleaned."
	@echo

$(INSTALLS):
	@echo " [INST] $(@F)"
	@$(INSTALL-$(INSTALLER))

$(SUBDIRS):
	@echo " [ CD ] $(CURRENTPATH)$@/"
	@+make -C "$@" "CURRENTPATH=$(CURRENTPATH)$@/" $(MAKECMDGOALS)

%.elf: $(SUBDIRS)
	@echo " [ LD ] $@"
	@$(CC) -o $@ $(CFLAGS) -Wl,--whole-archive $*/out.a -Wl,--no-whole-archive $(LDFLAGS)

%.hex: %.elf
	@echo " [OCPY] $@"
	@$(OBJCOPY) -O ihex $< $@

%.bin: %.elf
	@echo " [OCPY] $@"
	@$(OBJCOPY) -O binary $< $@

