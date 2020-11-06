# SPDX-License-Identifier: GPL-2.0-only

ifeq ($(CONFIG_HAVE_ACPI_TABLES),y)

ramstage-y += acpi.c
ramstage-y += acpigen.c
ramstage-y += acpigen_dsm.c
ramstage-y += acpigen_ps2_keybd.c
ramstage-y += device.c
ramstage-y += pld.c
ramstage-y += sata.c

ifneq ($(wildcard src/mainboard/$(MAINBOARDDIR)/acpi_tables.c),)
ramstage-srcs += src/mainboard/$(MAINBOARDDIR)/acpi_tables.c
endif
$(eval $(call asl_template,dsdt))
ifneq ($(wildcard src/mainboard/$(MAINBOARDDIR)/fadt.c),)
ramstage-srcs += src/mainboard/$(MAINBOARDDIR)/fadt.c
endif

endif # CONFIG_GENERATE_ACPI_TABLES