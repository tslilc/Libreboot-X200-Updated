/* SPDX-License-Identifier: GPL-2.0-only */

#include <commonlib/helpers.h>
#include <baseboard/variants.h>

/*
 * Pad configuration in ramstage. The order largely follows the 'GPIO Muxing'
 * table found in EDS vol 1, but some pins aren't grouped functionally in
 * the table so those were moved for more logical grouping.
 */
static const struct pad_config gpio_table[] = {

	/* Southwest Community */

	/* EXT_WAKE0_1V8# */
	PAD_CFG_NF_IOSSTATE(GPIO_205, UP_20K, DEEP, NF1, MASK),
	/* EXT_WAKE1_1V8# */
	PAD_CFG_NF_IOSSTATE(GPIO_206, UP_20K, DEEP, NF1, MASK),
	/* LAN_WAKE_1V8# */
	PAD_CFG_NF_IOSSTATE(GPIO_207, UP_20K, DEEP, NF1, MASK),
	/* PCIE_WAKE3_1V8# */
	PAD_CFG_NF_IOSSTATE(GPIO_208, UP_20K, DEEP, NF1, MASK),

	/* EMMC_CLK */
	PAD_CFG_NF_IOSSTATE(GPIO_156, DN_20K, DEEP, NF1, Tx0RxDCRx0),
	/* EMMC_D0 */
	PAD_CFG_NF_IOSSTATE(GPIO_157, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_D1 */
	PAD_CFG_NF_IOSSTATE(GPIO_158, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_D2 */
	PAD_CFG_NF_IOSSTATE(GPIO_159, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_D3 */
	PAD_CFG_NF_IOSSTATE(GPIO_160, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_D4 */
	PAD_CFG_NF_IOSSTATE(GPIO_161, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_D5 */
	PAD_CFG_NF_IOSSTATE(GPIO_162, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_D6 */
	PAD_CFG_NF_IOSSTATE(GPIO_163, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_D7 */
	PAD_CFG_NF_IOSSTATE(GPIO_164, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_CMD */
	PAD_CFG_NF_IOSSTATE(GPIO_165, UP_20K, DEEP, NF1, HIZCRx1),
	/* EMMC_RCLK */
	PAD_CFG_NF_IOSSTATE(GPIO_182, DN_20K, DEEP, NF1, HIZCRx0),

	/* SDIO -- not connected */
	PAD_CFG_NF_IOSSTATE(GPIO_166, DN_20K, DEEP, NF1, Tx0RxDCRx0),
	PAD_CFG_NF_IOSSTATE(GPIO_167, UP_20K, DEEP, NF1, HIZCRx1),
	PAD_CFG_NF_IOSSTATE(GPIO_168, UP_20K, DEEP, NF1, HIZCRx1),
	PAD_CFG_NF_IOSSTATE(GPIO_169, UP_20K, DEEP, NF1, HIZCRx1),
	PAD_CFG_NF_IOSSTATE(GPIO_170, UP_20K, DEEP, NF1, HIZCRx1),
	PAD_CFG_NF_IOSSTATE(GPIO_171, UP_20K, DEEP, NF1, HIZCRx1),

	/* SDCARD_CLK */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_172, DN_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* SDCARD_D0 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_173, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* SDCARD_D1 */
	PAD_CFG_NF_IOSSTATE(GPIO_174, UP_20K, DEEP, NF1, HIZCRx1),
	/* SDCARD_D2 */
	PAD_CFG_NF_IOSSTATE(GPIO_175, UP_20K, DEEP, NF1, HIZCRx1),
	/* SDCARD_D3 */
	PAD_CFG_NF_IOSSTATE(GPIO_176, UP_20K, DEEP, NF1, HIZCRx1),
	/* SDCARD_CD_1V8# */
	PAD_CFG_NF(GPIO_177, NONE, DEEP, NF1),
	/* SDCARD_CMD */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_178, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* Not connected */
	PAD_CFG_NF(GPIO_179, DN_20K, DEEP, NF1),
	/* SDCARD_WP_1V8 */
	PAD_CFG_GPI_GPIO_DRIVER(GPIO_186, DN_20K, DEEP),
	/* SD_PWR_EN_1V8 - Always enabled SDCard. */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_183, 0, DEEP, UP_20K),

	/* West Community */

	/* I2C_PM_DATA_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_124, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_PM_CLK_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_125, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_CAM0_DATA_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_126, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_CAM0_CLK_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_127, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_CAM1_DATA_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_128, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_CAM1_CLK_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_129, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_GP_DATA_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_130, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_GP_CLK_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_131, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_LCD_DATA_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_132, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* I2C_LCD_CLK_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_133, UP_1K, DEEP, NF1, Tx1RxDCRx1,
				    MASK),
	/* Not connected */
	PAD_CFG_GPIO_DRIVER_HI_Z(GPIO_134, UP_20K, DEEP, Tx0RxDCRx0, MASK),
	/* Not connected */
	PAD_CFG_GPIO_DRIVER_HI_Z(GPIO_135, UP_20K, DEEP, Tx0RxDCRx0, MASK),
	/* GPIO_PWRBTN# */
	PAD_CFG_GPI_SCI_IOS(GPIO_136, UP_20K, DEEP, EDGE_SINGLE, INVERT,
			    TxDRxE, SAME),

	/* HDA_BCLK_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_146, DN_20K, DEEP, NF3, MASK, SAME),
	/* HDA_WS_SYNC_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_147, DN_20K, DEEP, NF3, MASK, SAME),
	/* HDA_SDI_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_148, DN_20K, DEEP, NF3, MASK, SAME),
	/* HDA_SDO_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_149, DN_20K, DEEP, NF3, MASK, SAME),

	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_150, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_151, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_152, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_153, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_154, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_155, DN_20K, DEEP, OFF),

	/* PCIE_CLKREQ[0:3]_N */
	PAD_CFG_NF(GPIO_209, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPIO_210, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPIO_211, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPIO_212, UP_20K, DEEP, NF1),

	/* OSC_CLK_OUT_[0:4] -- not connected */
	PAD_CFG_GPI_INT(OSC_CLK_OUT_0, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(OSC_CLK_OUT_1, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(OSC_CLK_OUT_2, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(OSC_CLK_OUT_3, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(OSC_CLK_OUT_4, DN_20K, DEEP, OFF),

	/* PM_CHARGER_PRSNT */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_AC_PRESENT, DN_20K, DEEP, NF1, MASK,
				    SAME),
	/* PM_BATLOW# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_BATLOW_B, UP_20K, DEEP, NF1, MASK,
				    SAME),
	/* PMU_PLTRST# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_PLTRST_B, NONE, DEEP, NF1, MASK, SAME),
	/* PMU_PWRBTN# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_PWRBTN_B, UP_20K, DEEP, NF1, MASK,
				    SAME),
	/* SYS_RESET# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_RESETBUTTON_B, NONE, DEEP, NF1, MASK,
				    SAME),
	/* PMU_SLP_S0# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_SLP_S0_B, NONE, DEEP, NF1, MASK, SAME),
	/* PMU_SLP_S3# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_SLP_S3_B, NONE, DEEP, NF1, MASK, SAME),
	/* PMU_SLP_S4# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_SLP_S4_B, NONE, DEEP, NF1, MASK, SAME),
	/* CLK_32K_SUS */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_SUSCLK, NONE, DEEP, NF1, MASK, SAME),
	/* EMMC_PWR_EN# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMU_WAKE_B, DN_20K, DEEP, NF1, MASK, SAME),
	/* SUS_STAT# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SUS_STAT_B, NONE, DEEP, NF1, MASK, SAME),
	/* SUSPWRDNACK */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SUSPWRDNACK, NONE, DEEP, NF1, MASK, SAME),

	/* Northwest Community */

	/* DDI0_DDC_DATA_1V8 - I2C Data for HDMI - Connected to a MUX SEL IC to
	 * choose between DDI0_AUXP (Port 0: Display Port Auxiliary Channel for
	 * DP/HDMI) controlled by resistor stuffing options.
	 */
	PAD_CFG_NF(GPIO_187, UP_20K, DEEP, NF1),
	/* DDI0_DDC_CLK_1V8  - I2C Clock for HDMI - Connected to a MUX SEL IC
	 * to choose between DDI0_AUXN controlled by resistor stuffing options.
	 */
	PAD_CFG_NF(GPIO_188, UP_20K, DEEP, NF1),
	/* DDI1_DDC_DATA_1V8 - I2C Data for HDMI - Connected to a MUX SEL IC to
	 * choose between DDI1_AUXN.
	 */
	PAD_CFG_NF(GPIO_189, UP_20K, DEEP, NF1),
	/* DDI1_DDC_CLK_1V8  - I2C Clock for HDMI - Connected to a MUX SEL IC
	 * to choose between DDI1_AUXP.
	 */
	PAD_CFG_NF(GPIO_190, UP_20K, DEEP, NF1),

	/* Not connected */
	PAD_CFG_NF(GPIO_191, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPIO_192, DN_20K, DEEP, NF1),
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_193, DN_20K, DEEP, NF1, Tx0RxDCRx0,
				    SAME),
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_194, DN_20K, DEEP, NF1, Tx0RxDCRx0,
				    SAME),
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_195, DN_20K, DEEP, NF1, Tx0RxDCRx0,
				    SAME),

	/* EDP_VDD_EN_1V8  (DNI) - Alternative stuffing option for
	 * PTN3460 LVDS_VDD_EN.
	 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_196, 1, DEEP, UP_20K),
	/* EDP_BKLT_EN_1V8 (DNI) - Alternative stuffing option for
	 * PTN3460 LVDS_BKLT_EN
	 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_197, 1, DEEP, UP_20K),
	/* EDP_BKLT_CTRL_1V8 - Alternative stuffing option for
	 * PTN3460 LVDS_BKLT_CTRL
	 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_198, 1, DEEP, UP_20K),

	/* DDI1_HPD# - Connect to DP1_HPD Hot plug detection signal of SMARC
	 * Connector.
	 */
	PAD_CFG_NF(GPIO_199, UP_20K, DEEP, NF2),
	/* DDI0_HPD# - Connect to DP0_HPD Hot plug detection signal of SMARC
	 * Connector.
	 */
	PAD_CFG_NF(GPIO_200, UP_20K, DEEP, NF2),

	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_201, DN_20K, DEEP, NF1, Tx0RxDCRx0,
				    SAME),
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_202, DN_20K, DEEP, NF1, Tx0RxDCRx0,
				    SAME),

	/* USB2_OC0_1V8# - Connected to (USB0_OC#:MUX_SEL[USB2_OTG_0/USB2_6]),
	 * (USB1_OC#:USB1), (USB2_OC#:USB2)
	 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_203, UP_20K, DEEP, NF1, MASK, SAME),
	/* USB2_OC1_1V8# - Connected to (USB3_OC#:USB3), (USB4_OC#:USB4),
	 * (USB5_OC#:USB5). NOTE: USB2_7_WIBU do not have OC.
	 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_204, UP_20K, DEEP, NF1, MASK, SAME),

	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMC_SPI_FS0, UP_20K, DEEP, NF1, TxLASTRxE,
				    SAME),
	/* EDP_HPD# - from HPDRX pin of PTN3460 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMC_SPI_FS1, UP_20K, DEEP, NF2, TxLASTRxE,
				    SAME),
	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMC_SPI_FS2, UP_20K, DEEP, NF1, TxLASTRxE,
				    SAME),
	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMC_SPI_RXD, DN_20K, DEEP, NF1, TxLASTRxE,
				    SAME),
	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMC_SPI_TXD, DN_20K, DEEP, NF1, TxLASTRxE,
				    SAME),
	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMC_SPI_CLK, DN_20K, DEEP, NF1, TxLASTRxE,
				    SAME),

	/* Not connected */
	PAD_CFG_NF(PMIC_PWRGOOD, UP_20K, DEEP, NF1),
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_214, 1, DEEP, DN_20K),
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_215, 1, DEEP, DN_20K),
	/* THERMTRIP_1V8# - Connected to CPLD */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PMIC_THERMTRIP_B, UP_20K, DEEP, NF1,
				    TxLASTRxE, SAME),
	/* PROCHOT_CPU#  - Connected to CPLD */
	PAD_CFG_NF_IOSSTATE_IOSTERM(PROCHOT_B, UP_20K, DEEP, NF1, HIZCRx1,
				    SAME),

	/* Not connected */
	PAD_CFG_GPI_INT(PMIC_I2C_SCL, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(PMIC_I2C_SDA, DN_20K, DEEP, OFF),

	/* I2S_MCLK - Connected to SMARC Connector I2S0_CLK  - Digital audio
	 * clock
	 */
	PAD_CFG_NF(GPIO_74, DN_20K, DEEP, NF1),
	/* I2S_BCLK - Connected to SMARC Connector I2S0_LRCK - Left & Right
	 * audio synchronization clock
	 */
	PAD_CFG_NF(GPIO_75, DN_20K, DEEP, NF1),
	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_76, DN_20K, DEEP, OFF),
	/* I2S_SDI - Connected to SMARC Connector I2S0_SDI - Digital audio
	 * Input
	 */
	PAD_CFG_NF(GPIO_77, DN_20K, DEEP, NF1),
	/* I2S_SD0 & STRAP_GPIO_78 (int. PU)  - Connected to SMARC Connector
	 * I2S0_SDO - Digital audio Output
	 */
	PAD_CFG_NF(GPIO_78, DN_20K, DEEP, NF1),

	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_79, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_80, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_81, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_82 (int. PD) */
	PAD_CFG_GPI_INT(GPIO_82, DN_20K, DEEP, OFF),
	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_83, DN_20K, DEEP, OFF),

	/* HDA_RST_1V8# - MUX SEL with CPLD pin and then goto GPIO4/HDA_RST#
	 * pin of SMARC connector
	 */
	PAD_CFG_NF(GPIO_84, UP_20K, DEEP, NF2),
	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_85, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_86, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_87, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_88 (int. PU) */
	PAD_CFG_GPI_INT(GPIO_88, DN_20K, DEEP, OFF),

	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_89, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_90, DN_20K, DEEP, OFF),
	PAD_CFG_GPI_INT(GPIO_91, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_92 (int. PD) */
	PAD_CFG_GPI_INT(GPIO_92, DN_20K, DEEP, OFF),

	/* CS0 for BIOS SPI. Connected to CPLD. CPLD then MUX SEL to either SPI
	 * FLASH CHIP on module (SPI_CS_MODULE_1V8#) or to the carrier board
	 * SPI FLASH Chip (SPI_CS_EXT_1V8#).
	 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_97, NATIVE, DEEP, NF1, MASK, SAME),
	/* CS1 for BIOS SPI. Connected to CPLD. Not used, because we use 1x16MB
	 * Flash and not 2x8MB Flash.
	 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_98, NATIVE, DEEP, NF1, MASK, SAME),
	/* FST_SPI_MISO_1V8 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_99, NATIVE, DEEP, NF1, MASK, SAME),
	/* FST_SPI_MOSI_1V8.  Support dual mode. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_100, NATIVE, DEEP, NF1, MASK, SAME),
	/* FST_SPI_IO2.  Not support quad mode, external pulled-up. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_101, NATIVE, DEEP, NF1, MASK, SAME),
	/* FST_SPI_IO3.  Not support quad mode, external pulled-up. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_102, NATIVE, DEEP, NF1, MASK, SAME),
	/* FST_SPI_CLK_1V8.  Goes to both module SPI chip and carrier board. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_103, NATIVE, DEEP, NF1, MASK, SAME),
	/* FST_SPI_CLK_FB */
	PAD_CFG_NF_IOSSTATE_IOSTERM(FST_SPI_CLK_FB, NONE, DEEP, NF1, MASK,
				    SAME),

	/* SIO_SPI_CLK_1V8 - Connected to ESPI_CK of SMARC connector. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_104, DN_20K, DEEP, NF1, HIZCRx0, ENPD),
	/* SIO_SPI_FS0_1V8 - Connected to ESPI_CS0# of SMARC connector. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_105, DN_20K, DEEP, NF1, HIZCRx0, ENPD),
	/* SIO_SPI_FS1_1V8 - Connected to FST_SPI_CS2_N of SMARC connector. */
	PAD_CFG_NF(GPIO_106, NATIVE, DEEP, NF3),
	/* SIO_SPI_MISO_1V8 - Connected to ESPI_IO_0 of SMARC connector. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_109, DN_20K, DEEP, NF1, HIZCRx0, ENPD),
	/* SIO_SPI_MOSI_1V8 - Connected to ESPI_IO_1 of SMARC connector. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_110, DN_20K, DEEP, NF1, HIZCRx0, ENPD),

	/* STRAP_GPIO_111 */
	PAD_CFG_GPI_INT(GPIO_111, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_112 */
	PAD_CFG_GPI_INT(GPIO_112, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_113 */
	PAD_CFG_GPI_INT(GPIO_113, DN_20K, DEEP, OFF),
	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_116, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_117 */
	PAD_CFG_GPI_INT(GPIO_117, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_118 */
	PAD_CFG_GPI_INT(GPIO_118, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_119 */
	PAD_CFG_GPI_INT(GPIO_119, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_120 */
	PAD_CFG_GPI_INT(GPIO_120, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_121 */
	PAD_CFG_GPI_INT(GPIO_121, DN_20K, DEEP, OFF),
	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_122, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_123 */
	PAD_CFG_GPI_INT(GPIO_123, UP_20K, DEEP, OFF),

	/* North Community */

	/* Debug tracing. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_5, DN_20K, DEEP, NF1, HIZCRx0, SAME),
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_6, DN_20K, DEEP, NF1, HIZCRx0, SAME),
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_7, DN_20K, DEEP, NF1, HIZCRx0, SAME),
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_8, DN_20K, DEEP, NF1, HIZCRx0, SAME),

	/* OTG_SEL_1V8 - Connected to a USB MUX to select between USB2_DP0 (OTG)
	 * and USB2_DP6. 1:OTG, 0:USB
	 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_9, 1, DEEP, UP_20K),
	/* EN_I2CPM_EXT_1V8 - Connected to OE pin of I2C Re-driver.
	 * Allow/Disallow I2C signal to pass through to SMARC Connector.
	 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_10, 1, DEEP, UP_20K),
	/* EN_SMB_EXT_1V8 - Connected to OE pin of I2C Re-driver.
	 * Allow/Disallow SMBUS signal to pass through to SMARC Connector.
	 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_11, 0, DEEP, UP_20K),
	/* BOOT_SEL2_1V8# - Three Module pins allow the Carrier board user to
	 * select from eight possible boot devices.
	 */
	PAD_CFG_GPI_INT(GPIO_12, UP_20K, DEEP, OFF),
	/* BOOT_SEL1_1V8# - BOOT_SEL pins shall be weakly pulled up on the
	 * Module and the pin states decoded by Module logic.
	 */
	PAD_CFG_GPI_INT(GPIO_13, UP_20K, DEEP, OFF),
	/* BOOT_SEL0_1V8# - For details refer to
	 * SMARC_Hardware_Specification_V200.pdf page 38 chapter 4.17 Boot
	 * Select
	 */
	PAD_CFG_GPI_INT(GPIO_14, UP_20K, DEEP, OFF),
	/* GPIO_CPLD_TCK_1V8 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_15, 0, DEEP, DN_20K),
	/* GPIO_CPLD_TMS_1V8 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_16, 0, DEEP, DN_20K),
	/* GPIO_CPLD_TDI_1V8 */
	PAD_CFG_GPI_INT(GPIO_17, DN_20K, DEEP, OFF),
	/* GPIO_CPLD_TDO_1V8 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_18, 0, DEEP, DN_20K),
	/* PM_TEST_1V8# connect to the SMARC Connector TEST# pin.
	 * Held low by Carrier to invoke Module vendor specific test function.
	 * Pulled up on Module. Driven by OD part on Carrier.
	 */
	PAD_CFG_GPI_INT(GPIO_19, UP_20K, DEEP, OFF),
	/* MCERR_1V8 - ICT Test Point */
	PAD_CFG_GPI_INT(GPIO_20, DN_20K, DEEP, OFF),
	/* IERR_1V8 - ICT Test Point */
	PAD_CFG_GPI_INT(GPIO_21, DN_20K, DEEP, OFF),
	/* SLEEP_CPU_1V8# - Connect to the SMARC Connector SLEEP# pin.
	 * Sleep indicator from Carrier board. May be sourced from user Sleep
	 * button or Carrier logic. Carrier to float the line in in-active
	 * state. Active low, level sensitive. Should be de-bounced on the
	 * Module. Pulled up on Module. Driven by Open Drain (OD) part on
	 * Carrier.
	 */
	PAD_CFG_GPI_SCI_IOS(GPIO_22, UP_20K, DEEP, EDGE_SINGLE, INVERT, TxDRxE,
			    SAME),
	/* LID_CPU_1V8# - Connect to the SMARC Connector LID# pin.
	 * Lid open/close indication to Module. Low indicates lid closure
	 * (which system may use to initiate a sleep state). Carrier to float
	 * the line in in-active state. Active low, level sensitive. Should be
	 * de-bounced on the Module Pulled up on Module. Driven by OD part on
	 * Carrier.
	 */
	PAD_CFG_GPI_SCI_IOS(GPIO_23, UP_20K, DEEP, EDGE_BOTH, INVERT, TxDRxE,
			    SAME),
	/* WDT_IRQ1_1V8# (NMI) - Trigger by CPLD Watchdog module when enabled
	 * and timeout.
	 */
	PAD_CFG_GPI_NMI(GPIO_24, UP_20K, DEEP, LEVEL, INVERT),
	/* WDT_IRQ0_1V8# (SCI) - Refer to Kontron_CPLD.pdf Chapter 6 Watchdog
	 * Module Description, for how to use it.
	 */
	PAD_CFG_GPI_SCI(GPIO_25, UP_20K, DEEP, LEVEL, INVERT),
	/* SATA_LED# - Connect to the SMARC Connector SATA_ACT# pin.
	 * Active low SATA activity indicator. If implemented, shall be able to
	 * sink 24mA or more Carrier LED current.
	 */
	PAD_CFG_NF(GPIO_26, DN_20K, DEEP, NF5),

	/* SMB_ALERT_GPIO# */
	PAD_CFG_GPI_INT(GPIO_27, UP_20K, DEEP, OFF),
	/* GPIO_28_DEBUG - Connect to HOOK5 (ClkOut#) pin of XDP connector */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_28, 1, DEEP, UP_20K),
	/* GPIO_29_DEBUG - Connect to HOOK4 (ClkOut) pin of XDP connector */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_29, 0, DEEP, DN_20K),

	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_30, DN_20K, DEEP, OFF),
	/* CPU_GPIO_1_1V8 (DNI) - Connect to CPLD PIN_K6 (Unused in CPLD) */
	PAD_CFG_GPI_INT(GPIO_31, DN_20K, DEEP, OFF),
	/* CPU_GPIO_2_1V8 (DNI) - Connect to CPLD PIN_J6 (Unused in CPLD) */
	PAD_CFG_GPI_INT(GPIO_32, DN_20K, DEEP, OFF),
	/* Not connected */
	PAD_CFG_GPI_INT(GPIO_33, DN_20K, DEEP, OFF),

	/* STRAP_GPIO_34 (int. PD) */
	PAD_CFG_GPI_INT(GPIO_34, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_35 (int. PD) */
	PAD_CFG_GPI_INT(GPIO_35, DN_20K, DEEP, OFF),
	/* STRAP_GPIO_36 (int. PD) */
	PAD_CFG_GPI_INT(GPIO_36, DN_20K, DEEP, OFF),
	/* Not connected */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_37, 0, DEEP, DN_20K),

	/* GPIO_VALID (CPLD=gpio_valid/pi_gpio_en)- This pin Enable the CPLD
	 * GPIO to the SMARC Connector.
	 */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_62, 1, DEEP, UP_20K),
	/* LVDS_ENABLE_1V8# connect to PTN3460 DP to LVDS converter chip. */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_63, 0, DEEP, DN_20K),
	/* Not connected */
	PAD_CFG_GPIO_DRIVER_HI_Z(GPIO_64, DN_20K, DEEP, HIZCRx0, SAME),
	/* Not connected */
	PAD_CFG_GPIO_DRIVER_HI_Z(GPIO_65, DN_20K, DEEP, HIZCRx0, SAME),
	/* CAM_CS0_CS1_SEL - Serial Cameras interfaces Select - to select
	 * between the two MIPI CSI camera interfaces on the SMARC connector. */
	PAD_CFG_GPO_GPIO_DRIVER(GPIO_66, 0, DEEP, DN_20K),
	/* MCSI0_RST_1V8# - Reset the MIPI CSI camera interfaces 0 */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_67, 0, DEEP, DN_20K, HIZCRx0, SAME),
	/* MCSI1_RST_1V8# - Reset the MIPI CSI camera interfaces 1 */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_68, 0, DEEP, DN_20K, HIZCRx0, SAME),
	/* MCSI0_PWR_1V8# - Power for the MIPI CSI camera interfaces 0 */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_69, 0, DEEP, DN_20K, Tx1RxDCRx1,
				     SAME),
	/* MCSI1_PWR_1V8# - Power for the MIPI CSI camera interfaces 1 */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_70, 0, DEEP, DN_20K, Tx1RxDCRx1,
				     SAME),
	/* Not connected */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_71, 0, DEEP, DN_20K, HIZCRx0, SAME),
	/* Not connected */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_72, 0, DEEP, DN_20K, HIZCRx0, SAME),
	/* Not connected */
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_73, 0, DEEP, DN_20K, HIZCRx0, SAME),

	/* JTAG_TCK to XDP Header TCK0 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(TCK, DN_20K, DEEP, NF1, MASK, SAME),
	/* JTAG_TRST# to XDP Header TRST# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(TRST_B, DN_20K, DEEP, NF1, MASK, SAME),
	/* JTAG_TMS to XDP Header TMS */
	PAD_CFG_NF_IOSSTATE_IOSTERM(TMS, UP_20K, DEEP, NF1, MASK, SAME),
	/* JTAG_TDI to XDP Header TDI */
	PAD_CFG_NF_IOSSTATE_IOSTERM(TDI, UP_20K, DEEP, NF1, MASK, SAME),
	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(CX_PMODE, NONE, DEEP, NF1, MASK, SAME),
	/* TAG_PREQ# to XDP Header OBSFN_A0 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(CX_PREQ_B, UP_20K, DEEP, NF1, MASK, SAME),
	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(JTAGX, UP_20K, DEEP, NF1, MASK, SAME),
	/* JTAG_PRDY# to XDP Header OBSFN_A1 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(CX_PRDY_B, UP_20K, DEEP, NF1, MASK, SAME),
	/* JTAG_TDO to XDP Header TDO */
	PAD_CFG_NF_IOSSTATE_IOSTERM(TDO, UP_20K, DEEP, NF1, MASK, SAME),

	/* Not connected */
	PAD_CFG_GPIO_DRIVER_HI_Z(CNV_BRI_DT, DN_20K, DEEP, MASK, SAME),
	/* PM_FORCE_RECOV_1V8# from SMARC Connector FORCE_RECOV#.
	 * A low on the Module FORCE_RECOV# pin may invoke the SOC native Force
	 * Recovery mode.
	 * For x86 systems this signal may be used to load BIOS defaults.
	 */
	PAD_CFG_GPIO_DRIVER_HI_Z(CNV_BRI_RSP, UP_20K, DEEP, MASK, SAME),
	/* Not connected */
	PAD_CFG_GPIO_DRIVER_HI_Z(CNV_RGI_DT, DN_20K, DEEP, MASK, SAME),
	/* EMMC_RST# to EMMC IC's RST# pin */
	PAD_CFG_NF_IOSSTATE_IOSTERM(CNV_RGI_RSP, UP_20K, DEEP, NF1, MASK, SAME),

	/* SVID0_ALERT# - Connect to the SVID VR chip. */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SVID0_ALERT_B, NONE, DEEP, NF1, MASK, SAME),
	/* SVID0_DATA */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SVID0_DATA, UP_20K, DEEP, NF1, MASK, SAME),
	/* SVID0_CLK */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SVID0_CLK, UP_20K, DEEP, NF1, MASK, SAME),
};

const struct pad_config *variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}

/* GPIOs needed prior to ramstage. */
static const struct pad_config early_gpio_table[] = {

	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_0, DN_20K, PWROK, NF1, HIZCRx0, SAME),
	/* OBSDATA_A0 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_1, DN_20K, PWROK, NF1, HIZCRx0, SAME),
	/* OBSDATA_A1 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_2, DN_20K, PWROK, NF1, HIZCRx0, SAME),
	/* OBSDATA_A2 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_3, DN_20K, PWROK, NF1, HIZCRx0, SAME),
	/* OBSDATA_A3 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_4, DN_20K, PWROK, NF1, HIZCRx0, SAME),

	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_38, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* STRAP_GPIO_39 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_39, DN_20K, DEEP, NF1, TxLASTRxE,
				    DISPUPD),
	/* STRAP_GPIO_40 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_40, DN_20K, DEEP, NF1, TxLASTRxE,
				    DISPUPD),
	/* Not connected */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_41, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* CPU_UART1_RX to SMARC Connector SER0_RX */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_42, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* CPU_UART1_TX to SMARC Connector SER0_TX */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_43, DN_20K, DEEP, NF1, TxLASTRxE,
				    DISPUPD),
	/* CPU_UART1_RTS_1V8# to SMARC Connector SER0_RTS# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_44, UP_20K, DEEP, NF1, TxLASTRxE,
				    DISPUPD),
	/* CPU_UART1_CTS_1V8# to SMARC Connector SER0_CTS# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_45, UP_20K, DEEP, NF1, HIZCRx0,
				    DISPUPD),
	/* CPU_UART2_RX_1V8   to SMARC Connector SER2_RX */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_46, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* CPU_UART2_TX_1V8   to SMARC Connector SER2_TX */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_47, DN_20K, DEEP, NF1, TxLASTRxE,
				    DISPUPD),
	/* CPU_UART2_RTS_1V8# to SMARC Connector SER2_RTS# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_48, DN_20K, DEEP, NF1, TxLASTRxE,
				    DISPUPD),
	/* CPU_UART2_CTS_1V8# to SMARC Connector SER2_CTS# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_49, UP_20K, DEEP, NF1, HIZCRx0,
				    DISPUPD),

	/* Board ID - GPIO_223 */
	PAD_CFG_GPI_INT(PMIC_RESET_B, DN_20K, DEEP, OFF),
	/* Board ID - GPIO_213 */
	PAD_CFG_GPI_INT(GPIO_213, DN_20K, DEEP, OFF),
	/* Board ID - GPIO_224 */
	PAD_CFG_GPI_INT(PMIC_STDBY, DN_20K, DEEP, OFF),

	/* CPU_GPIO_137 - Kontron config : 0:ECC, 1:no ECC (default) */
	PAD_CFG_GPIO_DRIVER_HI_Z(GPIO_137, UP_20K, DEEP, Tx0RxDCRx0, ENPU),
	/* CPU_GPIO_138 - Kontron config - RAM Type BIT0 */
	PAD_CFG_GPIO_DRIVER_HI_Z(GPIO_138, UP_20K, DEEP, Tx0RxDCRx0, ENPU),
	/* CPU_GPIO_139 - Kontron config - RAM Type BIT1 */
	PAD_CFG_GPIO_DRIVER_HI_Z(GPIO_139, UP_20K, DEEP, Tx0RxDCRx0, ENPU),

	/* SMB_ALERT_CPU# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SMB_ALERTB, UP_20K, DEEP, NF1, MASK, SAME),
	/* SMB_CLK_S5 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SMB_CLK, UP_20K, DEEP, NF1, MASK, SAME),
	/* SMB_DATA_S5 */
	PAD_CFG_NF_IOSSTATE_IOSTERM(SMB_DATA, UP_20K, DEEP, NF1, MASK, SAME),

	/* LPC_SERIRQ_CPU */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_ILB_SERIRQ, UP_20K, DEEP, NF1, MASK,
				    SAME),
	/* CLK_25M_LPC_TPM_CPU */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_CLKOUT0, NONE, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* CLK_25M_LPC_CPLD_CPU */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_CLKOUT1, NONE, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* LPC_AD0_CPU */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_AD0, UP_20K, DEEP, NF1, HIZCRx1,
			DISPUPD),
	/* LPC_AD1_CPU */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_AD1, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* LPC_AD2_CPU */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_AD2, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* LPC_AD3_CPU */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_AD3, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* LPC_CLKRUN# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_CLKRUNB, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
	/* LPC_FRAME_CPU# */
	PAD_CFG_NF_IOSSTATE_IOSTERM(LPC_FRAMEB, UP_20K, DEEP, NF1, HIZCRx1,
				    DISPUPD),
};

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}