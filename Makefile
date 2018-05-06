TOPDIR	=	.
include config.mk

# Sub directories to build
SRCDIRS		=	src
#PLUGINSDIR	=	plugins
#MODULESDIR	=	submodules
EXAMPLESDIR	=	examples

SUBDIRS		=	$(SRCDIRS) $(PLUGINSDIR) $(MODULESDIR)

MODULES		=	$(wildcard $(addsuffix /*.a,$(MODULESDIR)))

AFILE		=	lib$(NAME).a

.PHONY: all clean install debug examples
.PHONY: $(SUBDIRS)

all: $(AFILE)
	@echo 
	@echo "Build complete."
	@echo 

examples:
	@+make all
	
	@echo " [ CD ] $(CURRENTPATH)examples/"
	@+make -C "$@" "CURRENTPATH=$(CURRENTPATH)examples/" all
	@echo " [ CD ] $(CURRENTPATH)"
	@echo 
	@echo "Build complete."
	@echo 

$(BINFILE): $(ELFFILE)
	@echo " [OCPY] $(BINFILE)"
	@$(OBJCOPY) -O binary $< $@

$(HEXFILE): $(ELFFILE)
	@echo " [OCPY] $(HEXFILE)"
	@$(OBJCOPY) -O ihex $< $@

$(ELFFILE): $(SUBDIRS)
	@echo " [ LD ] $(ELFFILE)"
	@$(CC) -o $(ELFFILE) $(CFLAGS) -Wl,--whole-archive $(addsuffix /out.a,$(SRCDIRS)) -Wl,--no-whole-archive $(MODULES) $(LDFLAGS)

$(AFILE): $(SRCDIRS) $(PLUGINSDIR) $(MODULESDIR)
	@echo " [ AR ] $(AFILE)"
	@$(AR) -cm $(AFILE) $(shell $(AR) t $(addsuffix /out.a,$(SRCDIRS)))

clean: $(SUBDIRS)
	@echo " [ RM ] $(ELFFILE) $(HEXFILE) $(BINFILE) $(AFILE)"
	@$(RM) $(ELFFILE) $(HEXFILE) $(BINFILE) $(AFILE)
	
	@echo
	@echo "Source tree cleaned."
	@echo

$(SUBDIRS):
	@echo " [ CD ] $(CURRENTPATH)$@/"
	@+make -C "$@" "CURRENTPATH=$(CURRENTPATH)$@/" $(MAKECMDGOALS)
	@echo " [ CD ] $(CURRENTPATH)"

