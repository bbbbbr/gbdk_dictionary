# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"

ifndef GBDK_HOME
	GBDK_HOME = ../../gbdk2020/gbdk-2020-git/build/gbdk/
endif

LCC = $(GBDK_HOME)bin/lcc

# Configure platform specific LCC flags here:
LCCFLAGS_gb      = -Wl-yt0x1B -autobank # Set an MBC for banking (1B-ROM+MBC5+RAM+BATT)
LCCFLAGS_pocket  = -Wl-yt0x1B -autobank # Usually the same as required for .gb
LCCFLAGS_duck    = -Wl-yt0x1B -autobank # Usually the same as required for .gb
LCCFLAGS_gbc     = -Wl-yt0x1B -Wm-yc -autobank # Same as .gb with: -Wm-yc (gb & gbc) or Wm-yC (gbc exclusive)
LCCFLAGS_sms     =
LCCFLAGS_gg      =
LCCFLAGS_nes     = -autobank


# make CART_TYPE=<cart type>
ifndef CART_TYPE
	CART_TYPE=mbc5
endif


# Set ROM Title / Name
LCCFLAGS_gb    += -Wm-yn"WORD_LOOKUP"


# Targets can be forced with this override, but normally they will be controlled per-cart type above
#
# Set platforms to build here, spaced separated. (These are in the separate Makefile.targets)
# They can also be built/cleaned individually: "make gg" and "make gg-clean"
# Possible are: gb gbc pocket megaduck sms gg
TARGETS=gb # pocket


LCCFLAGS += $(LCCFLAGS_$(EXT)) # This adds the current platform specific LCC Flags

LCCFLAGS += -Wl-j -Wm-yoA -Wm-ya4 -Wb-ext=.rel -Wb-v # MBC + Autobanking related flags


GBDK_DEBUG = ON
ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif

CFLAGS = -Wf-MMD -Wf-Wp-MP # Header file dependency output (-MMD) for Makefile use + per-header Phoney rules (-MP)


# You can set the name of the ROM file here
PROJECTNAME = word_lookup


# EXT?=gb # Only sets extension to default (game boy .gb) if not populated
SRCDIR      = src
OBJDIR      = obj/$(EXT)
RESOBJSRC   = obj/$(EXT)/res
RESDIR      = res
BUILD_DIR   = build
BINDIR      = $(BUILD_DIR)/$(EXT)
TOOLS_DIR    = tools
SRC_DICT_DIR = $(SRCDIR)/dict
MKDIRS       = $(OBJDIR) $(BINDIR) $(RESOBJSRC) $(TOOLS_DIR) $(SRC_DICT_DIR)  # See bottom of Makefile for directory auto-creation
OUTPUT_NAME  = $(BINDIR)/$(PROJECTNAME).$(EXT)

BINS	    = $(OBJDIR)/$(PROJECTNAME).$(EXT)
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s)))
OBJS        = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o)


CFLAGS += -I$(OBJDIR)

# Builds all targets sequentially
all: $(TARGETS)
	echo $(GBDK_HOME)


# Dependencies (using output from -Wf-MMD -Wf-Wp-MP)
DEPS = $(OBJS:%.o=%.d)

-include $(DEPS)

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) $(CFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) $(CFLAGS) -S -o $@ $<


# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o $(OUTPUT_NAME) $(OBJS)


clean:
	@echo Cleaning
	@for target in $(TARGETS); do \
		$(MAKE) $$target-clean; \
	done

dicttionary: dict

dict:
	$(info $(shell mkdir -p $(SRC_DIR)))
	$(info $(shell mkdir -p $(SRC_DICT_DIR)))
	python3 $(TOOLS_DIR)/wordlist_split_compact.py $(TOOLS_DIR)/wordlist.txt --min 3 --max 6 --output_folder $(SRC_DICT_DIR)

romusage:
	romusage $(BINDIR)/gb/$(PROJECTNAME).gb -sRp -g 

# Include available build targets
include Makefile.targets


# create necessary directories after Makefile is parsed but before build
# info prevents the command from being pasted into the makefile
ifneq ($(strip $(EXT)),)           # Only make the directories if EXT has been set by a target
$(info $(shell mkdir -p $(MKDIRS)))
endif
