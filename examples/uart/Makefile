TOPDIR	=	$(shell DIR=.; while [ ! "`readlink -f \"$${DIR}\"`" = "/" -a ! -f "$${DIR}/config.mk" ]; do DIR="../$${DIR}"; done; echo "$${DIR}")
ifeq ($(shell readlink -f "$(TOPDIR)"),/)
	$(error Could not find the project top directory with config.mk)
endif
include $(TOPDIR)/config.mk

# Extra per-directory make configuration
-include extra.mk

# Find all source files automatically
CFILES          = $(wildcard *.c)
ASFILES         = $(wildcard *.S)
SYMSFILES	= $(wildcard *.syms)

# Object file names
OBJFILES	= $(CFILES:.c=.c.o)
OBJFILES	+=$(ASFILES:.S=.S.o)
OBJFILES	+=$(SYMSFILES:.syms=.syms.o)

OUTFILE		= out.a	

# Sub directories to build
SUBDIRS		= $(foreach dir,$(wildcard */Makefile),$(dir $(dir)))

LIBS		= $(addsuffix $(OUTFILE),$(SUBDIRS))

# Hidden directory for dependency files
DEPDIR = .deps
df = $(DEPDIR)/$(*F)

.PHONY: all clean
.PHONY: $(SUBDIRS)
.SUFFIXES:

# Standard targets
all: $(OUTFILE)
	@echo

clean: $(SUBDIRS)
	@echo " [ RM ] $(OBJFILES) $(OUTFILE)"
	@$(RM) $(OBJFILES) $(OUTFILE)
	@$(RM) -R $(DEPDIR)
	@echo 

# Generate static library
$(OUTFILE): $(OBJFILES) $(SUBDIRS)
	@echo " [ AR ] $(CURRENTPATH)$(OUTFILE)"
	@$(RM) $(OUTFILE)
	@$(AR) -cqT $(OUTFILE) $(OBJFILES) $(LIBS)

# Compile all subdirectories
$(SUBDIRS):
	@echo " [ CD ] $(CURRENTPATH)$@"
	@+make -C "$@" "CURRENTPATH=$(CURRENTPATH)$@" $(MAKECMDGOALS)
	@echo " [ CD ] $(CURRENTPATH)"

$(DEPDIR):
	@mkdir -p $@

# Compile C files
%.c.o: %.c | $(DEPDIR)
	@echo " [ CC ] $(CURRENTPATH)$<"
	@$(CC) -c $(CFLAGS) -MD -o $@ $<
	@cp $*.c.d $(df).c.P; sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' < $*.c.d >> $(df).c.P; $(RM) $*.c.d

# Compile ASM files with C pre-processor directives
%.S.o: %.S | $(DEPDIR)
	@echo " [ AS ] $(CURRENTPATH)$<"
	@$(CC) -c $(ASFLAGS) -MD -o $@ $<
	@cp $*.S.d $(df).S.P; sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' < $*.S.d >> $(df).S.P; $(RM) $*.S.d

# Link symbol lists to object files
%.syms.o: %.syms
	@$(LD) -o $@ -r --just-symbols=$<

# Check dependencies
-include $(CFILES:%.c=$(DEPDIR)/%.c.P)
-include $(ASMFILES:%.S=$(DEPDIR)/%.S.P)
