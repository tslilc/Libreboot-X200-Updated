bootblock-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CSE) += cse.c
romstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CSE) += cse.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_CSE) += cse.c
ramstage-$(CONFIG_SOC_INTEL_CSE_CUSTOM_SKU) += custom_bp.c
smm-$(CONFIG_SOC_INTEL_COMMON_BLOCK_HECI_DISABLE_IN_SMM) += disable_heci.c