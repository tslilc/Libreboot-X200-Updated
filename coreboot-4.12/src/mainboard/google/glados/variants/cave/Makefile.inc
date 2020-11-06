##
##
##
## SPDX-License-Identifier: GPL-2.0-only

romstage-y += variant.c
ramstage-y += variant.c
smm-y += variant.c

SPD_BIN = $(obj)/spd.bin

# SPD data by index.  No method for board identification yet
SPD_SOURCES = micron_4GiB_dimm_MT52L256M32D1PF  # 0b0000
SPD_SOURCES += samsung_dimm_K4E8E324EB-EGCF     # 0b0001
SPD_SOURCES += micron_8GiB_dimm_MT52L512M32D2PF # 0b0010
SPD_SOURCES += samsung_dimm_K4E6E304EB-EGCF     # 0b0011
SPD_SOURCES += micron_16GiB_dimm_MT52L1G32D4PG  # 0b0100
SPD_SOURCES += hynix_dimm_H9CCNNNCLTMLAR        # 0b0101

SPD_DEPS := $(foreach f, $(SPD_SOURCES), src/mainboard/$(MAINBOARDDIR)/spd/$(f).spd.hex)

# Include spd ROM data
$(SPD_BIN): $(SPD_DEPS)
	for f in $+; \
	  do for c in $$(cat $$f | grep -v ^#); \
	    do printf $$(printf '\%o' 0x$$c); \
	  done; \
	done > $@

cbfs-files-y += spd.bin
spd.bin-file := $(SPD_BIN)
spd.bin-type := spd