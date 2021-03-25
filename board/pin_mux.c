/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: LPC54608J512
package_id: LPC54608J512ET180
mcu_data: ksdk2_0
processor_version: 0.0.11
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"



/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: A12, peripheral: USBHSH, signal: USB_PORTPWRN, pin_signal: PIO4_9/ENET_TXD1/FC2_RXD_SDA_MOSI/USB1_PORTPWRN/USB1_FRAME/SCT0_GPI2, mode: pullUp, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: K12, peripheral: USBHSH, signal: USB_OVERCURRENTN, pin_signal: PIO1_1/FC3_RXD_SDA_MOSI/CTIMER0_CAP3/SCT0_GPI5/USB1_OVERCURRENTN, mode: pullUp, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: A2, peripheral: FLEXCOMM0, signal: TXD_SCL_MISO, pin_signal: PIO0_30/FC0_TXD_SCL_MISO/CTIMER0_MAT0/SCT0_OUT9/TRACEDATA(1), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: B13, peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI, pin_signal: PIO0_29/FC0_RXD_SDA_MOSI/CTIMER2_MAT3/SCT0_OUT8/TRACEDATA(2), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: E9, peripheral: EMC, signal: 'EMC_D, 0', pin_signal: PIO0_2/FC3_TXD_SCL_MISO/CTIMER0_CAP1/SCT0_OUT0/SCT0_GPI2/EMC_D(0), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: A10, peripheral: EMC, signal: 'EMC_D, 1', pin_signal: PIO0_3/FC3_RXD_SDA_MOSI/CTIMER0_MAT1/SCT0_OUT1/SCT0_GPI3/EMC_D(1), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: C8, peripheral: EMC, signal: 'EMC_D, 2', pin_signal: PIO0_4/CAN0_RD/FC4_SCK/CTIMER3_CAP0/SCT0_GPI4/EMC_D(2)/ENET_MDC, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: E7, peripheral: EMC, signal: 'EMC_D, 3', pin_signal: PIO0_5/CAN0_TD/FC4_RXD_SDA_MOSI/CTIMER3_MAT0/SCT0_GPI5/EMC_D(3)/ENET_MDIO, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: A5, peripheral: EMC, signal: 'EMC_D, 4', pin_signal: PIO0_6/FC3_SCK/CTIMER3_CAP1/CTIMER4_MAT0/SCT0_GPI6/EMC_D(4)/ENET_RX_DV, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: H12, peripheral: EMC, signal: 'EMC_D, 5', pin_signal: PIO0_7/FC3_RTS_SCL_SSEL1/SD_CLK/FC5_SCK/FC1_SCK/PDM1_CLK/EMC_D(5)/ENET_RX_CLK, mode: inactive,
    invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: H10, peripheral: EMC, signal: 'EMC_D, 6', pin_signal: PIO0_8/FC3_SSEL3/SD_CMD/FC5_RXD_SDA_MOSI/SWO/PDM1_DATA/EMC_D(6), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: G12, peripheral: EMC, signal: 'EMC_D, 7', pin_signal: PIO0_9/FC3_SSEL2/SD_POW_EN/FC5_TXD_SCL_MISO/SCI1_IO/EMC_D(7), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: L4, peripheral: EMC, signal: EMC_WE, pin_signal: PIO0_15/FC6_CTS_SDA_SSEL0/UTICK_CAP2/CTIMER4_CAP0/SCT0_OUT2/EMC_WEN/ENET_TX_EN/ADC0_3, mode: inactive,
    invert: disabled, glitch_filter: disabled, open_drain: disabled}
  - {pin_num: C14, peripheral: EMC, signal: 'EMC_A, 0', pin_signal: PIO0_18/FC4_CTS_SDA_SSEL0/SD_WR_PRT/CTIMER1_MAT0/SCT0_OUT1/SCI1_SCLK/EMC_A(0), mode: inactive,
    invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: C6, peripheral: EMC, signal: 'EMC_A, 1', pin_signal: PIO0_19/FC4_RTS_SCL_SSEL1/UTICK_CAP0/CTIMER0_MAT2/SCT0_OUT2/EMC_A(1)/FC7_TXD_SCL_MISO_WS, mode: inactive,
    invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: D13, peripheral: EMC, signal: 'EMC_A, 2', pin_signal: PIO0_20/FC3_CTS_SDA_SSEL0/CTIMER1_MAT1/CTIMER3_CAP3/SCT0_GPI2/SCI0_IO/EMC_A(2)/FC7_RXD_SDA_MOSI_DATA,
    mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: C13, peripheral: EMC, signal: 'EMC_A, 3', pin_signal: PIO0_21/FC3_RTS_SCL_SSEL1/UTICK_CAP3/CTIMER3_MAT3/SCT0_GPI3/SCI0_SCLK/EMC_A(3)/FC7_SCK, mode: inactive,
    invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: D4, peripheral: EMC, signal: 'EMC_D, 11', pin_signal: PIO1_4/FC0_SCK/SD_D(0)/CTIMER2_MAT1/SCT0_OUT0/FREQME_GPIO_CLK_A/EMC_D(11), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: E4, peripheral: EMC, signal: 'EMC_A, 4', pin_signal: PIO1_5/FC0_RXD_SDA_MOSI/SD_D(2)/CTIMER2_MAT0/SCT0_GPI0/EMC_A(4), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: G4, peripheral: EMC, signal: 'EMC_A, 5', pin_signal: PIO1_6/FC0_TXD_SCL_MISO/SD_D(3)/CTIMER2_MAT1/SCT0_GPI3/EMC_A(5), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: N1, peripheral: EMC, signal: 'EMC_A, 6', pin_signal: PIO1_7/FC0_RTS_SCL_SSEL1/SD_D(1)/CTIMER2_MAT2/SCT0_GPI4/EMC_A(6), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: P8, peripheral: EMC, signal: 'EMC_A, 7', pin_signal: PIO1_8/FC0_CTS_SDA_SSEL0/SD_CLK/SCT0_OUT1/FC4_SSEL2/EMC_A(7), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: K6, peripheral: EMC, signal: EMC_CAS, pin_signal: PIO1_9/ENET_TXD0/FC1_SCK/CTIMER1_CAP0/SCT0_OUT2/FC4_CTS_SDA_SSEL0/EMC_CASN, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: L1, peripheral: EMC, signal: 'EMC_D, 8', pin_signal: PIO1_19/FC8_SCK/SCT0_OUT7/CTIMER3_MAT1/SCT0_GPI7/FC4_SCK/EMC_D(8), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: M1, peripheral: EMC, signal: 'EMC_D, 9', pin_signal: PIO1_20/FC7_RTS_SCL_SSEL1/CTIMER3_CAP2/FC4_TXD_SCL_MISO/EMC_D(9), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: N8, peripheral: EMC, signal: 'EMC_D, 10', pin_signal: PIO1_21/FC7_CTS_SDA_SSEL0/CTIMER3_MAT2/FC4_RXD_SDA_MOSI/EMC_D(10), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: N9, peripheral: EMC, signal: EMC_RAS, pin_signal: PIO1_10/ENET_TXD1/FC1_RXD_SDA_MOSI/CTIMER1_MAT0/SCT0_OUT3/EMC_RASN, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: B4, peripheral: EMC, signal: 'EMC_CLK, 0', pin_signal: PIO1_11/ENET_TX_EN/FC1_TXD_SCL_MISO/CTIMER1_CAP1/USB0_VBUS/EMC_CLK(0), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: K9, peripheral: EMC, signal: 'EMC_DYCS, 0', pin_signal: PIO1_12/ENET_RXD0/FC6_SCK/CTIMER1_MAT1/USB0_PORTPWRN/EMC_DYCSN(0), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: G10, peripheral: EMC, signal: 'EMC_DQM, 0', pin_signal: PIO1_13/ENET_RXD1/FC6_RXD_SDA_MOSI_DATA/CTIMER1_CAP2/USB0_OVERCURRENTN/USB0_FRAME/EMC_DQM(0),
    mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: C12, peripheral: EMC, signal: 'EMC_DQM, 1', pin_signal: PIO1_14/ENET_RX_DV/UTICK_CAP2/CTIMER1_MAT2/FC5_CTS_SDA_SSEL0/USB0_UP_LED/EMC_DQM(1), mode: inactive,
    invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: A11, peripheral: EMC, signal: 'EMC_CKE, 0', pin_signal: PIO1_15/ENET_RX_CLK/UTICK_CAP3/CTIMER1_CAP3/FC5_RTS_SCL_SSEL1/FC4_RTS_SCL_SSEL1/EMC_CKE(0),
    mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: B7, peripheral: EMC, signal: 'EMC_A, 10', pin_signal: PIO1_16/ENET_MDC/FC6_TXD_SCL_MISO_WS/CTIMER1_MAT3/SD_CMD/EMC_A(10), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: M10, peripheral: EMC, signal: 'EMC_A, 11', pin_signal: PIO1_23/FC2_SCK/SCT0_OUT0/ENET_MDIO/FC3_SSEL2/EMC_A(11), mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: fast, open_drain: disabled}
  - {pin_num: N14, peripheral: EMC, signal: 'EMC_A, 12', pin_signal: PIO1_24/FC2_RXD_SDA_MOSI/SCT0_OUT1/FC3_SSEL3/EMC_A(12), mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: fast, open_drain: disabled}
  - {pin_num: M12, peripheral: EMC, signal: 'EMC_A, 13', pin_signal: PIO1_25/FC2_TXD_SCL_MISO/SCT0_OUT2/UTICK_CAP0/EMC_A(13), mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: fast, open_drain: disabled}
  - {pin_num: E12, peripheral: EMC, signal: 'EMC_D, 12', pin_signal: PIO1_28/FC7_SCK/SD_D(5)/CTIMER0_CAP2/EMC_D(12), mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: fast, open_drain: disabled}
  - {pin_num: C11, peripheral: EMC, signal: 'EMC_D, 13', pin_signal: PIO1_29/FC7_RXD_SDA_MOSI_DATA/SD_D(6)/SCT0_GPI6/USB1_PORTPWRN/USB1_FRAME/EMC_D(13), mode: inactive,
    invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: A8, peripheral: EMC, signal: 'EMC_D, 14', pin_signal: PIO1_30/FC7_TXD_SCL_MISO_WS/SD_D(7)/SCT0_GPI7/USB1_OVERCURRENTN/USB1_UP_LED/EMC_D(14), mode: inactive,
    invert: disabled, glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: C5, peripheral: EMC, signal: 'EMC_D, 15', pin_signal: PIO1_31/MCLK/CTIMER0_MAT2/SCT0_OUT6/FC8_CTS_SDA_SSEL0/EMC_D(15), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: J10, peripheral: EMC, signal: 'EMC_A, 8', pin_signal: PIO1_26/FC2_CTS_SDA_SSEL0/SCT0_OUT3/CTIMER0_CAP3/UTICK_CAP1/EMC_A(8), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: F10, peripheral: EMC, signal: 'EMC_A, 9', pin_signal: PIO1_27/FC2_RTS_SCL_SSEL1/SD_D(4)/CTIMER0_MAT3/CLKOUT/EMC_A(9), mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: fast, open_drain: disabled}
  - {pin_num: P9, peripheral: EMC, signal: 'EMC_A, 14', pin_signal: PIO3_25/CTIMER4_CAP2/FC4_SCK/EMC_A(14), mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: fast, open_drain: disabled}
  - {pin_num: K3, peripheral: LCD, signal: LCD_PWR, pin_signal: PIO2_11/LCD_PWR/SD_VOLT(0)/FC5_SCK, mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: standard,
    open_drain: disabled}
  - {pin_num: P7, peripheral: LCD, signal: LCD_DCLK, pin_signal: PIO2_13/LCD_DCLK/SD_VOLT(2)/FC5_TXD_SCL_MISO, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: L7, peripheral: LCD, signal: LCD_FP, pin_signal: PIO2_14/LCD_FP/USB0_FRAME/USB0_PORTPWRN/CTIMER0_MAT2/FC5_CTS_SDA_SSEL0, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: M8, peripheral: LCD, signal: LCD_AC, pin_signal: PIO2_15/LCD_AC/USB0_UP_LED/USB0_OVERCURRENTN/CTIMER0_MAT3/FC5_RTS_SCL_SSEL1, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: L8, peripheral: LCD, signal: LCD_LP, pin_signal: PIO2_16/LCD_LP/USB1_FRAME/USB1_PORTPWRN/CTIMER1_MAT3/FC8_SCK, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: L10, peripheral: LCD, signal: 'LCD_VD, 3', pin_signal: PIO2_21/LCD_VD(3)/FC3_CTS_SDA_SSEL0/MCLK/CTIMER3_MAT3, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: K10, peripheral: LCD, signal: 'LCD_VD, 4', pin_signal: PIO2_22/LCD_VD(4)/SCT0_OUT7/CTIMER2_CAP0, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: M14, peripheral: LCD, signal: 'LCD_VD, 5', pin_signal: PIO2_23/LCD_VD(5)/SCT0_OUT8, mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: standard,
    open_drain: disabled}
  - {pin_num: K14, peripheral: LCD, signal: 'LCD_VD, 6', pin_signal: PIO2_24/LCD_VD(6)/SCT0_OUT9, mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: standard,
    open_drain: disabled}
  - {pin_num: J11, peripheral: LCD, signal: 'LCD_VD, 7', pin_signal: PIO2_25/LCD_VD(7)/USB0_VBUS, mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: standard,
    open_drain: disabled}
  - {pin_num: G13, peripheral: LCD, signal: 'LCD_VD, 10', pin_signal: PIO2_28/LCD_VD(10)/FC7_CTS_SDA_SSEL0/CTIMER2_CAP2, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: G11, peripheral: LCD, signal: 'LCD_VD, 11', pin_signal: PIO2_29/LCD_VD(11)/FC7_RTS_SCL_SSEL1/FC8_TXD_SCL_MISO/CTIMER2_CAP3/CLKOUT, mode: inactive, invert: disabled,
    glitch_filter: disabled, slew_rate: standard, open_drain: disabled}
  - {pin_num: F12, peripheral: LCD, signal: 'LCD_VD, 12', pin_signal: PIO2_30/LCD_VD(12)/CTIMER2_MAT2, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: D14, peripheral: LCD, signal: 'LCD_VD, 13', pin_signal: PIO2_31/LCD_VD(13), mode: inactive, invert: disabled, glitch_filter: disabled, slew_rate: standard,
    open_drain: disabled}
  - {pin_num: D12, peripheral: LCD, signal: 'LCD_VD, 14', pin_signal: PIO3_0/LCD_VD(14)/PDM0_CLK/CTIMER1_MAT0, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: D11, peripheral: LCD, signal: 'LCD_VD, 15', pin_signal: PIO3_1/LCD_VD(15)/PDM0_DATA/CTIMER1_MAT1, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: B10, peripheral: LCD, signal: 'LCD_VD, 19', pin_signal: PIO3_5/LCD_VD(19)/FC8_RTS_SCL_SSEL1/CTIMER4_MAT1, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: C9, peripheral: LCD, signal: 'LCD_VD, 20', pin_signal: PIO3_6/LCD_VD(20)/LCD_VD(0)/CTIMER4_MAT2, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: B8, peripheral: LCD, signal: 'LCD_VD, 21', pin_signal: PIO3_7/LCD_VD(21)/LCD_VD(1)/CTIMER4_CAP2, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: A7, peripheral: LCD, signal: 'LCD_VD, 22', pin_signal: PIO3_8/LCD_VD(22)/LCD_VD(2)/CTIMER4_CAP3, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: C7, peripheral: LCD, signal: 'LCD_VD, 23', pin_signal: PIO3_9/LCD_VD(23)/LCD_VD(3)/CTIMER0_CAP2, mode: inactive, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
  - {pin_num: C2, peripheral: FLEXCOMM2, signal: CTS_SDA_SSEL0, pin_signal: PIO3_23/FC2_CTS_SDA_SSEL0/UTICK_CAP3, invert: disabled, glitch_filter: disabled, i2c_slew: i2c,
    i2c_drive: high, i2c_filter: enabled}
  - {pin_num: E2, peripheral: FLEXCOMM2, signal: RTS_SCL_SSEL1, pin_signal: PIO3_24/FC2_RTS_SCL_SSEL1/CTIMER4_CAP0/USB0_VBUS, invert: disabled, glitch_filter: disabled,
    i2c_slew: i2c, i2c_drive: high, i2c_filter: enabled}
  - {pin_num: H14, peripheral: GPIO, signal: 'PIO2, 27', pin_signal: PIO2_27/LCD_VD(9)/FC9_SCK/FC3_SSEL2, mode: pullUp, invert: disabled, glitch_filter: disabled,
    slew_rate: standard, open_drain: disabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Core #0 (ARM Cortex-M4) */
#define IOCON_PIO_FUNC7 0x07u         /*!<@brief Selects pin function 7 */
#define IOCON_PIO_FUNC3 0x03u         /*!<@brief Selects pin function 3 */
void BOARD_InitPins(void)
{
    /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */
    CLOCK_EnableClock(kCLOCK_Iocon);

    const uint32_t port4_pin9_config = (/* Pin is configured as USB1_PORTPWRN */
                                        IOCON_PIO_FUNC3 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT4 PIN9 (coords: A12) is configured as USB1_PORTPWRN */
    IOCON_PinMuxSet(IOCON, 4U, 9U, port4_pin9_config);

    const uint32_t port1_pin1_config = (/* Pin is configured as USB1_OVERCURRENTN */
                                        IOCON_PIO_FUNC7 |
                                        /* Selects pull-up function */
                                        IOCON_PIO_MODE_PULLUP |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN1 (coords: K12) is configured as USB1_OVERCURRENTN */
    IOCON_PinMuxSet(IOCON, 1U, 1U, port1_pin1_config);

    const uint32_t port0_pin15_config = (/* Pin is configured as EMC_WEN */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN15 (coords: L4) is configured as EMC_WEN */
    IOCON_PinMuxSet(IOCON, 0U, 15U, port0_pin15_config);

    const uint32_t port0_pin18_config = (/* Pin is configured as EMC_A(0) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN18 (coords: C14) is configured as EMC_A(0) */
    IOCON_PinMuxSet(IOCON, 0U, 18U, port0_pin18_config);

    const uint32_t port0_pin19_config = (/* Pin is configured as EMC_A(1) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN19 (coords: C6) is configured as EMC_A(1) */
    IOCON_PinMuxSet(IOCON, 0U, 19U, port0_pin19_config);

    const uint32_t port0_pin2_config = (/* Pin is configured as EMC_D(0) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN2 (coords: E9) is configured as EMC_D(0) */
    IOCON_PinMuxSet(IOCON, 0U, 2U, port0_pin2_config);

    const uint32_t port0_pin20_config = (/* Pin is configured as EMC_A(2) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN20 (coords: D13) is configured as EMC_A(2) */
    IOCON_PinMuxSet(IOCON, 0U, 20U, port0_pin20_config);

    const uint32_t port0_pin21_config = (/* Pin is configured as EMC_A(3) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN21 (coords: C13) is configured as EMC_A(3) */
    IOCON_PinMuxSet(IOCON, 0U, 21U, port0_pin21_config);

    const uint32_t port0_pin29_config = (/* Pin is configured as FC0_RXD_SDA_MOSI */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN29 (coords: B13) is configured as FC0_RXD_SDA_MOSI */
    IOCON_PinMuxSet(IOCON, 0U, 29U, port0_pin29_config);

    const uint32_t port0_pin3_config = (/* Pin is configured as EMC_D(1) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN3 (coords: A10) is configured as EMC_D(1) */
    IOCON_PinMuxSet(IOCON, 0U, 3U, port0_pin3_config);

    const uint32_t port0_pin30_config = (/* Pin is configured as FC0_TXD_SCL_MISO */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN30 (coords: A2) is configured as FC0_TXD_SCL_MISO */
    IOCON_PinMuxSet(IOCON, 0U, 30U, port0_pin30_config);

    const uint32_t port0_pin4_config = (/* Pin is configured as EMC_D(2) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN4 (coords: C8) is configured as EMC_D(2) */
    IOCON_PinMuxSet(IOCON, 0U, 4U, port0_pin4_config);

    const uint32_t port0_pin5_config = (/* Pin is configured as EMC_D(3) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN5 (coords: E7) is configured as EMC_D(3) */
    IOCON_PinMuxSet(IOCON, 0U, 5U, port0_pin5_config);

    const uint32_t port0_pin6_config = (/* Pin is configured as EMC_D(4) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN6 (coords: A5) is configured as EMC_D(4) */
    IOCON_PinMuxSet(IOCON, 0U, 6U, port0_pin6_config);

    const uint32_t port0_pin7_config = (/* Pin is configured as EMC_D(5) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN7 (coords: H12) is configured as EMC_D(5) */
    IOCON_PinMuxSet(IOCON, 0U, 7U, port0_pin7_config);

    const uint32_t port0_pin8_config = (/* Pin is configured as EMC_D(6) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN8 (coords: H10) is configured as EMC_D(6) */
    IOCON_PinMuxSet(IOCON, 0U, 8U, port0_pin8_config);

    const uint32_t port0_pin9_config = (/* Pin is configured as EMC_D(7) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN9 (coords: G12) is configured as EMC_D(7) */
    IOCON_PinMuxSet(IOCON, 0U, 9U, port0_pin9_config);

    const uint32_t port1_pin10_config = (/* Pin is configured as EMC_RASN */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN10 (coords: N9) is configured as EMC_RASN */
    IOCON_PinMuxSet(IOCON, 1U, 10U, port1_pin10_config);

    const uint32_t port1_pin11_config = (/* Pin is configured as EMC_CLK(0) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN11 (coords: B4) is configured as EMC_CLK(0) */
    IOCON_PinMuxSet(IOCON, 1U, 11U, port1_pin11_config);

    const uint32_t port1_pin12_config = (/* Pin is configured as EMC_DYCSN(0) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN12 (coords: K9) is configured as EMC_DYCSN(0) */
    IOCON_PinMuxSet(IOCON, 1U, 12U, port1_pin12_config);

    const uint32_t port1_pin13_config = (/* Pin is configured as EMC_DQM(0) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN13 (coords: G10) is configured as EMC_DQM(0) */
    IOCON_PinMuxSet(IOCON, 1U, 13U, port1_pin13_config);

    const uint32_t port1_pin14_config = (/* Pin is configured as EMC_DQM(1) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN14 (coords: C12) is configured as EMC_DQM(1) */
    IOCON_PinMuxSet(IOCON, 1U, 14U, port1_pin14_config);

    const uint32_t port1_pin15_config = (/* Pin is configured as EMC_CKE(0) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN15 (coords: A11) is configured as EMC_CKE(0) */
    IOCON_PinMuxSet(IOCON, 1U, 15U, port1_pin15_config);

    const uint32_t port1_pin16_config = (/* Pin is configured as EMC_A(10) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN16 (coords: B7) is configured as EMC_A(10) */
    IOCON_PinMuxSet(IOCON, 1U, 16U, port1_pin16_config);

    const uint32_t port1_pin19_config = (/* Pin is configured as EMC_D(8) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN19 (coords: L1) is configured as EMC_D(8) */
    IOCON_PinMuxSet(IOCON, 1U, 19U, port1_pin19_config);

    const uint32_t port1_pin20_config = (/* Pin is configured as EMC_D(9) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN20 (coords: M1) is configured as EMC_D(9) */
    IOCON_PinMuxSet(IOCON, 1U, 20U, port1_pin20_config);

    const uint32_t port1_pin21_config = (/* Pin is configured as EMC_D(10) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN21 (coords: N8) is configured as EMC_D(10) */
    IOCON_PinMuxSet(IOCON, 1U, 21U, port1_pin21_config);

    const uint32_t port1_pin23_config = (/* Pin is configured as EMC_A(11) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN23 (coords: M10) is configured as EMC_A(11) */
    IOCON_PinMuxSet(IOCON, 1U, 23U, port1_pin23_config);

    const uint32_t port1_pin24_config = (/* Pin is configured as EMC_A(12) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN24 (coords: N14) is configured as EMC_A(12) */
    IOCON_PinMuxSet(IOCON, 1U, 24U, port1_pin24_config);

    const uint32_t port1_pin25_config = (/* Pin is configured as EMC_A(13) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN25 (coords: M12) is configured as EMC_A(13) */
    IOCON_PinMuxSet(IOCON, 1U, 25U, port1_pin25_config);

    const uint32_t port1_pin26_config = (/* Pin is configured as EMC_A(8) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN26 (coords: J10) is configured as EMC_A(8) */
    IOCON_PinMuxSet(IOCON, 1U, 26U, port1_pin26_config);

    const uint32_t port1_pin27_config = (/* Pin is configured as EMC_A(9) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN27 (coords: F10) is configured as EMC_A(9) */
    IOCON_PinMuxSet(IOCON, 1U, 27U, port1_pin27_config);

    const uint32_t port1_pin28_config = (/* Pin is configured as EMC_D(12) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN28 (coords: E12) is configured as EMC_D(12) */
    IOCON_PinMuxSet(IOCON, 1U, 28U, port1_pin28_config);

    const uint32_t port1_pin29_config = (/* Pin is configured as EMC_D(13) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN29 (coords: C11) is configured as EMC_D(13) */
    IOCON_PinMuxSet(IOCON, 1U, 29U, port1_pin29_config);

    const uint32_t port1_pin30_config = (/* Pin is configured as EMC_D(14) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN30 (coords: A8) is configured as EMC_D(14) */
    IOCON_PinMuxSet(IOCON, 1U, 30U, port1_pin30_config);

    const uint32_t port1_pin31_config = (/* Pin is configured as EMC_D(15) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN31 (coords: C5) is configured as EMC_D(15) */
    IOCON_PinMuxSet(IOCON, 1U, 31U, port1_pin31_config);

    const uint32_t port1_pin4_config = (/* Pin is configured as EMC_D(11) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN4 (coords: D4) is configured as EMC_D(11) */
    IOCON_PinMuxSet(IOCON, 1U, 4U, port1_pin4_config);

    const uint32_t port1_pin5_config = (/* Pin is configured as EMC_A(4) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN5 (coords: E4) is configured as EMC_A(4) */
    IOCON_PinMuxSet(IOCON, 1U, 5U, port1_pin5_config);

    const uint32_t port1_pin6_config = (/* Pin is configured as EMC_A(5) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN6 (coords: G4) is configured as EMC_A(5) */
    IOCON_PinMuxSet(IOCON, 1U, 6U, port1_pin6_config);

    const uint32_t port1_pin7_config = (/* Pin is configured as EMC_A(6) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN7 (coords: N1) is configured as EMC_A(6) */
    IOCON_PinMuxSet(IOCON, 1U, 7U, port1_pin7_config);

    const uint32_t port1_pin8_config = (/* Pin is configured as EMC_A(7) */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN8 (coords: P8) is configured as EMC_A(7) */
    IOCON_PinMuxSet(IOCON, 1U, 8U, port1_pin8_config);

    const uint32_t port1_pin9_config = (/* Pin is configured as EMC_CASN */
                                        IOCON_PIO_FUNC6 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT1 PIN9 (coords: K6) is configured as EMC_CASN */
    IOCON_PinMuxSet(IOCON, 1U, 9U, port1_pin9_config);

    const uint32_t port2_pin11_config = (/* Pin is configured as LCD_PWR */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN11 (coords: K3) is configured as LCD_PWR */
    IOCON_PinMuxSet(IOCON, 2U, 11U, port2_pin11_config);

    const uint32_t port2_pin13_config = (/* Pin is configured as LCD_DCLK */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN13 (coords: P7) is configured as LCD_DCLK */
    IOCON_PinMuxSet(IOCON, 2U, 13U, port2_pin13_config);

    const uint32_t port2_pin14_config = (/* Pin is configured as LCD_FP */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN14 (coords: L7) is configured as LCD_FP */
    IOCON_PinMuxSet(IOCON, 2U, 14U, port2_pin14_config);

    const uint32_t port2_pin15_config = (/* Pin is configured as LCD_AC */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN15 (coords: M8) is configured as LCD_AC */
    IOCON_PinMuxSet(IOCON, 2U, 15U, port2_pin15_config);

    const uint32_t port2_pin16_config = (/* Pin is configured as LCD_LP */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN16 (coords: L8) is configured as LCD_LP */
    IOCON_PinMuxSet(IOCON, 2U, 16U, port2_pin16_config);

    const uint32_t port2_pin21_config = (/* Pin is configured as LCD_VD(3) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN21 (coords: L10) is configured as LCD_VD(3) */
    IOCON_PinMuxSet(IOCON, 2U, 21U, port2_pin21_config);

    const uint32_t port2_pin22_config = (/* Pin is configured as LCD_VD(4) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN22 (coords: K10) is configured as LCD_VD(4) */
    IOCON_PinMuxSet(IOCON, 2U, 22U, port2_pin22_config);

    const uint32_t port2_pin23_config = (/* Pin is configured as LCD_VD(5) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN23 (coords: M14) is configured as LCD_VD(5) */
    IOCON_PinMuxSet(IOCON, 2U, 23U, port2_pin23_config);

    const uint32_t port2_pin24_config = (/* Pin is configured as LCD_VD(6) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN24 (coords: K14) is configured as LCD_VD(6) */
    IOCON_PinMuxSet(IOCON, 2U, 24U, port2_pin24_config);

    const uint32_t port2_pin25_config = (/* Pin is configured as LCD_VD(7) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN25 (coords: J11) is configured as LCD_VD(7) */
    IOCON_PinMuxSet(IOCON, 2U, 25U, port2_pin25_config);

    const uint32_t port2_pin27_config = (/* Pin is configured as PIO2_27 */
                                         IOCON_PIO_FUNC0 |
                                         /* Selects pull-up function */
                                         IOCON_PIO_MODE_PULLUP |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN27 (coords: H14) is configured as PIO2_27 */
    IOCON_PinMuxSet(IOCON, 2U, 27U, port2_pin27_config);

    const uint32_t port2_pin28_config = (/* Pin is configured as LCD_VD(10) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN28 (coords: G13) is configured as LCD_VD(10) */
    IOCON_PinMuxSet(IOCON, 2U, 28U, port2_pin28_config);

    const uint32_t port2_pin29_config = (/* Pin is configured as LCD_VD(11) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN29 (coords: G11) is configured as LCD_VD(11) */
    IOCON_PinMuxSet(IOCON, 2U, 29U, port2_pin29_config);

    const uint32_t port2_pin30_config = (/* Pin is configured as LCD_VD(12) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN30 (coords: F12) is configured as LCD_VD(12) */
    IOCON_PinMuxSet(IOCON, 2U, 30U, port2_pin30_config);

    const uint32_t port2_pin31_config = (/* Pin is configured as LCD_VD(13) */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT2 PIN31 (coords: D14) is configured as LCD_VD(13) */
    IOCON_PinMuxSet(IOCON, 2U, 31U, port2_pin31_config);

    const uint32_t port3_pin0_config = (/* Pin is configured as LCD_VD(14) */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN0 (coords: D12) is configured as LCD_VD(14) */
    IOCON_PinMuxSet(IOCON, 3U, 0U, port3_pin0_config);

    const uint32_t port3_pin1_config = (/* Pin is configured as LCD_VD(15) */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN1 (coords: D11) is configured as LCD_VD(15) */
    IOCON_PinMuxSet(IOCON, 3U, 1U, port3_pin1_config);

    const uint32_t port3_pin23_config = (/* Pin is configured as FC2_CTS_SDA_SSEL0 */
                                         IOCON_PIO_FUNC1 |
                                         /* I2C mode */
                                         IOCON_PIO_I2CSLEW_I2C |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* High drive: 20 mA */
                                         IOCON_PIO_I2CDRIVE_HIGH |
                                         /* I2C 50 ns glitch filter enabled */
                                         IOCON_PIO_I2CFILTER_EN);
    /* PORT3 PIN23 (coords: C2) is configured as FC2_CTS_SDA_SSEL0 */
    IOCON_PinMuxSet(IOCON, 3U, 23U, port3_pin23_config);

    const uint32_t port3_pin24_config = (/* Pin is configured as FC2_RTS_SCL_SSEL1 */
                                         IOCON_PIO_FUNC1 |
                                         /* I2C mode */
                                         IOCON_PIO_I2CSLEW_I2C |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* High drive: 20 mA */
                                         IOCON_PIO_I2CDRIVE_HIGH |
                                         /* I2C 50 ns glitch filter enabled */
                                         IOCON_PIO_I2CFILTER_EN);
    /* PORT3 PIN24 (coords: E2) is configured as FC2_RTS_SCL_SSEL1 */
    IOCON_PinMuxSet(IOCON, 3U, 24U, port3_pin24_config);

    const uint32_t port3_pin25_config = (/* Pin is configured as EMC_A(14) */
                                         IOCON_PIO_FUNC6 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Input filter disabled */
                                         IOCON_PIO_INPFILT_OFF |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN25 (coords: P9) is configured as EMC_A(14) */
    IOCON_PinMuxSet(IOCON, 3U, 25U, port3_pin25_config);

    const uint32_t port3_pin5_config = (/* Pin is configured as LCD_VD(19) */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN5 (coords: B10) is configured as LCD_VD(19) */
    IOCON_PinMuxSet(IOCON, 3U, 5U, port3_pin5_config);

    const uint32_t port3_pin6_config = (/* Pin is configured as LCD_VD(20) */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN6 (coords: C9) is configured as LCD_VD(20) */
    IOCON_PinMuxSet(IOCON, 3U, 6U, port3_pin6_config);

    const uint32_t port3_pin7_config = (/* Pin is configured as LCD_VD(21) */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN7 (coords: B8) is configured as LCD_VD(21) */
    IOCON_PinMuxSet(IOCON, 3U, 7U, port3_pin7_config);

    const uint32_t port3_pin8_config = (/* Pin is configured as LCD_VD(22) */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN8 (coords: A7) is configured as LCD_VD(22) */
    IOCON_PinMuxSet(IOCON, 3U, 8U, port3_pin8_config);

    const uint32_t port3_pin9_config = (/* Pin is configured as LCD_VD(23) */
                                        IOCON_PIO_FUNC1 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Input filter disabled */
                                        IOCON_PIO_INPFILT_OFF |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT3 PIN9 (coords: C7) is configured as LCD_VD(23) */
    IOCON_PinMuxSet(IOCON, 3U, 9U, port3_pin9_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
