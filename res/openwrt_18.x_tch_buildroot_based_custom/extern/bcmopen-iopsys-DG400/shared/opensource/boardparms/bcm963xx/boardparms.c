/*
    Copyright 2000-2010 Broadcom Corporation

    <:label-BRCM:2011:DUAL/GPL:standard
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation (the "GPL").
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    
    A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
    writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
    
    :>
*/

/**************************************************************************
* File Name  : boardparms.c
*
* Description: This file contains the implementation for the BCM63xx board
*              parameter access functions.
*
* Updates    : 07/14/2003  Created.
***************************************************************************/

/* Includes. */
#include "boardparms.h"
#include "bp_defs.h"
#include "bcmSpiRes.h"
#if !defined(_CFE_)
#include "6802_map_part.h"
#endif


/* Variables */
#if 0
/* Sample structure with all elements present in a valid order */
/* Indentation is used to illustrate the groupings where parameters can be repeated */
/* use bp_elemTemplate to use another structure but do not split the groups */   
static bp_elem_t g_sample[] = {
  {bp_cpBoardId,               .u.cp = "SAMPLE"},
  {bp_ulGpioOverlay,           .u.ul = 0;
  {bp_usGpioLedAdsl,           .u.us = 0},
  {bp_usGpioLedAdslFail,       .u.us = 0},
  {bp_usGpioSecLedAdsl,        .u.us = 0},
  {bp_usGpioSecLedAdslFail,    .u.us = 0},
  {bp_usGpioLedSesWireless,    .u.us = 0},
  {bp_usGpioLedWanData,        .u.us = 0},
  {bp_usGpioLedWanError,       .u.us = 0},
  {bp_usGpioLedBlPowerOn,      .u.us = 0},
  {bp_usGpioLedBlStop,         .u.us = 0},
  {bp_usGpioFpgaReset,         .u.us = 0},
  {bp_usGpioLedGpon,           .u.us = 0},
  {bp_usGpioLedGponFail,       .u.us = 0},
  {bp_usGpioLedMoCA,           .u.us = 0},
  {bp_usGpioLedMoCAFail,       .u.us = 0},
  {bp_usGpioLedEpon,           .u.us = 0},
  {bp_usGpioLedEponFail,       .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = 0},
  {bp_usExtIntrSesBtnWireless, .u.us = 0},
  {bp_usMocaType0,             .u.us = 0}, // first MoCA chip always for WAN
    {bp_usExtIntrMocaHostIntr, .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr0,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr1,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_pMocaInit,             .u.ptr = (void*)mocaCmdSeq;
  {bp_usMocaType1,             .u.us = 0}, // MoCA LAN
    {bp_usExtIntrMocaHostIntr, .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr0,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_usExtIntrMocaSBIntr1,  .u.us = 0},
    {bp_usGpio_Intr,           .u.us = 0},
    {bp_pMocaInit,             .u.ptr = (void*)mocaCmdSeq;
  {bp_usAntInUseWireless,      .u.us = 0},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usGpioWirelessPowerDown, .u.us = 0},
  {bp_ucPhyType0,              .u.uc = 0}, // First switch
    {bp_ucPhyAddress,          .u.uc = 0},
    {bp_usConfigType,          .u.us = 0},
    {bp_ulPortMap,             .u.ul = 0},
    {bp_ulPhyId0,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
      {bp_pPhyInit             .u.ptr = (void *)g_phyinit},
    {bp_ulPhyId1,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
      {bp_pPhyInit             .u.ptr = (void *)g_phyinit},
    {bp_ulPhyId2,              .u.ul = 0},
    {bp_ulPhyId3,              .u.ul = 0},
    {bp_ulPhyId4,              .u.ul = 0},
    {bp_ulPhyId5,              .u.ul = 0},
      {bp_usPhyConnType        .u.us = 0},
      {bp_pPhyInit             .u.ptr = (void *)g_phyinit},
    {bp_ulPhyId6,              .u.ul = 0},
    {bp_ulPhyId7,              .u.ul = 0},
  {bp_ucPhyType1,              .u.uc = 0}, // Second switch
    {bp_ucPhyAddress,          .u.uc = 0},
    {bp_usConfigType,          .u.us = 0},
    {bp_ulPortMap,             .u.ul = 0},
    {bp_ulPhyId0,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
    {bp_ulPhyId1,              .u.ul = 0},
      {bp_usDuplexLed,         .u.us = 0},
      {bp_usSpeedLed100,       .u.us = 0},
      {bp_usSpeedLed1000,      .u.us = 0},
    {bp_ulPhyId2,              .u.ul = 0},
    {bp_ulPhyId3,              .u.ul = 0},
    {bp_ulPhyId4,              .u.ul = 0},
    {bp_ulPhyId5,              .u.ul = 0},
    {bp_ulPhyId6,              .u.ul = 0},
    {bp_ulPhyId7,              .u.ul = 0},
  {bp_ucDspType0,              .u.uc = 0}, // First VOIP DSP
    {bp_ucDspAddress,          .u.uc = 0},
    {bp_usGpioLedVoip,         .u.us = 0},
    {bp_usGpioVoip1Led,        .u.us = 0},
    {bp_usGpioVoip1LedFail,    .u.us = 0},
    {bp_usGpioVoip2Led,        .u.us = 0},
    {bp_usGpioVoip2LedFail,    .u.us = 0},
    {bp_usGpioPotsLed,         .u.us = 0},
    {bp_usGpioDectLed,         .u.us = 0},
  {bp_ucDspType1,              .u.uc = 0}, // Second VOIP DSP
    {bp_ucDspAddress,          .u.uc = 0},
    {bp_usGpioLedVoip,         .u.us = 0},
    {bp_usGpioVoip1Led,        .u.us = 0},
    {bp_usGpioVoip1LedFail,    .u.us = 0},
    {bp_usGpioVoip2Led,        .u.us = 0},
    {bp_usGpioVoip2LedFail,    .u.us = 0},
    {bp_usGpioPotsLed,         .u.us = 0},
    {bp_usGpioDectLed,         .u.us = 0},
  {bp_ulAfeId0,                .u.ul = 0},
  {bp_ulAfeId1,                .u.ul = 0},
  {bp_usGpioExtAFEReset,       .u.us = 0},
  {bp_usGpioExtAFELDPwr,       .u.us = 0},
  {bp_usGpioExtAFELDMode,      .u.us = 0},
  {bp_usGpioAFEVR5P3PwrEn,     .u.us = 0},
  {bp_usGpioLaserDis,          .u.us = 0},
  {bp_usGpioLaserTxPwrEn,      .u.us = 0},
  {bp_usGpioEponOpticalSD,     .u.us = 0},
  {bp_usVregSel1P2,            .u.us = 0},
  {bp_ucVreg1P8                .u.uc = 0},
  {bp_usVregAvsMin             .u.us = 0},
  {bp_usGpioFemtoReset,        .u.us = 0},
  {bp_usSerialLEDMuxSel        .u.us = 0},
  {bp_usBatteryEnable          .u.us = 0},
  {bp_elemTemplate             .u.bp_elemp = g_sample2},
  {bp_usXdResetGpio            .u.us = 0},  // active low or high is derived from gpio details
    {bp_cpXdResetName          .u.cp = "some_name"},
    {bp_usXdResetReleaseOnInit .u.us = 1},
  {bp_usXdGpio                 .u.us = 0},
    {bp_usXdGpioInitState      .u.us = 1},
    {bp_cpXdGpioInfo           .u.cp = "decription of this gpio"},
    {bp_cpXdGpioInfoState0     .u.cp = "info on state=0"},
    {bp_cpXdGpioInfoState1     .u.cp = "info on state=1"},
  {bp_last}
};

#endif

#if !defined(_CFE_)
// MoCA init command sequence
// Enable RGMII_0 to MOCA. 1Gbps
// Enable RGMII_1 to GPHY. 1Gbps
BpCmdElem moca6802InitSeq[] = {
    { CMD_WRITE, SUN_TOP_CTRL_SW_INIT_0_CLEAR, 0x0FFFFFFF }, //clear sw_init signals

    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_0, 0x11110011 }, //pinmux, rgmii, 3450
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_1, 0x11111111 }, //rgmii
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_2, 0x11111111 }, //rgmii
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_3, 0x22221111 }, // enable sideband all,0,1,2, rgmii
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_4, 0x10000022 }, // enable sideband 3,4, host intr

    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_CTRL_6, 0x00001100 }, // mdio, mdc

//    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_PAD_CTRL_2, 0x00555510 }, // set gpio 38,39,40 to PULL_NONE
    { CMD_WRITE, SUN_TOP_CTRL_PIN_MUX_PAD_CTRL_3, 0x2402 }, // Set GPIO 41 to PULL_UP

    { CMD_WRITE, SUN_TOP_CTRL_GENERAL_CTRL_NO_SCAN_0, 0x11 }, // , Use 2.5V for rgmii
    { CMD_WRITE, SUN_TOP_CTRL_GENERAL_CTRL_NO_SCAN_1, 0x3  }, // Disable GPHY LDO 
    { CMD_WRITE, SUN_TOP_CTRL_GENERAL_CTRL_NO_SCAN_5, 0x47 }, // set test_drive_sel to 16mA

    { CMD_WRITE, EPORT_REG_EMUX_CNTRL, 0x02 }, //  Select port mode. Activate both GPHY and MOCA phys.

    { CMD_WRITE, EPORT_REG_RGMII_0_CNTRL,  0x1 }, //  Enable rgmii0.
    { CMD_WRITE, EPORT_REG_RGMII_1_CNTRL,  0x0 }, //  Disable rgmii1.
#if defined(_BCM963138_) || defined(CONFIG_BCM963138) || defined(_BCM963148_) || defined(CONFIG_BCM963148) || defined(_BCM94908_) || defined(CONFIG_BCM94908)
    { CMD_WRITE, EPORT_REG_RGMII_0_RX_CLOCK_DELAY_CNTRL,  0xc0 }, // disable 2nd delay
#endif
    { CMD_WRITE, EPORT_REG_GPHY_CNTRL, 0x02A4C00F }, // Shutdown Gphy

    { CMD_WRITE, CLKGEN_PAD_CLOCK_DISABLE, 0x1 }, // Disable clkobsv output pin

    { CMD_WRITE, CLKGEN_LEAP_TOP_INST_CLOCK_DISABLE, 0x7 }, // Disable LEAP clocks

    { CMD_WRITE, PM_CONFIG,                0x4000 },   // disable uarts
    { CMD_WRITE, PM_CLK_CTRL,              0x1810c },  // disable second I2C port, PWMA and timers

    { CMD_END,  0, 0 }
};

#endif

#if defined(_BCM96838_) || defined(CONFIG_BCM96838)
//E8C reference design , 2L PCB, 4FE, 1xUSB, 1xWiFi, GPON, SIM CARD, NAND
static bp_elem_t g_bcm968380fhgu[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU"},  
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_72_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_47_AL},
  {bp_usExtIntrWifiOnOff ,     .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_71_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedEpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedUSB,            .u.us = BP_GPIO_53_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_11_AH},
  {bp_last}
};

//BCM968380FHGU_SI board.
static bp_elem_t g_bcm968380fhgu_si[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU_SI"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu},
  {bp_last}
};

//E8C reference design, 2L PCB,  4GE, 1xUSB, 1xWiFi, GPON, SIM CARD, NAND
static bp_elem_t g_bcm968380fggu[] = {
  {bp_cpBoardId,               .u.cp = "968380FGGU"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu},
  {bp_last}
};

static bp_elem_t g_bcm968380fggu_tri[] = {
  {bp_cpBoardId,               .u.cp = "968380FGGU_TRI"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x2f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId5,                .u.ul = 0x02 | BCM_WAN_PORT | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AL},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AL},
  {bp_usAePolarity,            .u.us = 1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu},
  {bp_last}
};

//E8C reference design, 4L PCB, 4GbE, 1xUSB, 1xWiFi, GPON, SIM CARD, NAND
static bp_elem_t g_bcm968380ffhg[] = {
  {bp_cpBoardId,               .u.cp = "968380FFHG"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fggu},
  {bp_last}
};

//E8C Reference design - 4L PCB, 4xGbE, 2xUSB, 2xWiFi, GPON, SIM CARD, 2xFXS
static bp_elem_t g_bcm968380gerg[] = {
  {bp_cpBoardId,               .u.cp = "968380GERG"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_47_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_39_AL},
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_48_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedEpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedUSB,            .u.us = BP_LED_3_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_11_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

//BCM968380MGEG board.
static bp_elem_t g_bcm968380mgeg[] = {
  {bp_cpBoardId,               .u.cp = "968380MGEG"},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380gerg},
  {bp_last}
};

//BCM968380GERG_SI board.
static bp_elem_t g_bcm968380gerg_si[] = {
  {bp_cpBoardId,               .u.cp = "968380GERG_SI"},
  {bp_usSpiSlaveSelectNum,     .u.us = 2}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 4},  
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380gerg},
  {bp_last}
};

//BCM968380F SV Board, big 6838SV board , GPON
static bp_elem_t g_bcm968380fsv_g[] = {
  {bp_cpBoardId,               .u.cp = "968380FSV_G"},
//for Active Ethernet use
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_AE},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
//for active ethernet use
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_GMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
//for active ethernet use
  {bp_ulPhyId5,                .u.ul = 0x2 | BCM_WAN_PORT | PHYCFG_VALID | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_1_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_0_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usTsync1025mhz,          .u.us = BP_PIN_TSYNC_1025MHZ_11},
  {bp_usTsync8khz,             .u.us = BP_PIN_TSYNC_8KHZ_4},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGpioTsyncPonUnstable,  .u.us = BP_GPIO_7_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_14_AH}, // uncomment to enable second UART
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH}, // uncomment to enable second UART       
//{bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPA}, an example of us eof shift register to output LEDs
  {bp_usSpiSlaveSelectNum,     .u.us = 4}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 67},
  {bp_last}
};

//TBD 
static bp_elem_t g_bcm968380sv_g[] = {
  {bp_cpBoardId,               .u.cp = "968380SV_G"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usSpiSlaveSelectNum,     .u.us = 4}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 67},  
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fsv_g}, //?????
  {bp_last}
};

//E8C Reference design  2L PCB, GPON, 2xFE, 1x FXS, SIM CARD, NAND, SPI NOR
static bp_elem_t g_bcm968385sfu[] = {
  {bp_cpBoardId,               .u.cp = "968385SFU"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_48_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedEpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedSim,            .u.us = BP_GPIO_4_AL},
  {bp_usGpioLedSim_ITMS,       .u.us = BP_GPIO_9_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_11_AH},
  {bp_last}
};

//BCM968385SFU_SI board.
static bp_elem_t g_bcm968385sfu_si[] = {
  {bp_cpBoardId,               .u.cp = "968385SFU_SI"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385sfu},
  {bp_last}
};

//E8C Reference design  2L PCB, GPON, 1x GbE, SIM CARD, NAND, SPI NOR
static bp_elem_t g_bcm968385gsp[] = {
  {bp_cpBoardId,               .u.cp = "968385GSP"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_NONE},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385sfu},
  {bp_last}
};

//R&D only
static bp_elem_t g_bcm968385sv_g[] = {
  {bp_cpBoardId,               .u.cp = "968385SV_G"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x04 | MAC_IF_GMII},
//  {bp_ulPhyId2,                .u.ul = 0x00 | PHYCFG_VALID |MAC_IF_GMII | PHY_EXTERNAL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_4_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_12_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usSpiSlaveSelectNum,     .u.us = 4}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},  
  {bp_last}
};

static bp_elem_t g_bcm968381sv_g[] = {
  {bp_cpBoardId,               .u.cp = "968381SV_G"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385sv_g},
  {bp_last}
};

static bp_elem_t g_bcm968380fttdps[] = {
  {bp_cpBoardId,               .u.cp = "968380FTTDPS"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x13},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulAttachedIdx,           .u.ul = 0},
/*
  {bp_ulPhyId0,                .u.ul = 0x7},
  {bp_ucPhyDevName,            .u.cp = "testme"},
  {bp_ulPhyId1,                .u.ul = 0x8},
*/
  {bp_ulAttachedIdx,           .u.ul = 4},
  {bp_ulPhyId0,                .u.ul = 0x0},
  {bp_ulPhyId1,                .u.ul = 0x1},
  {bp_ulPhyId2,                .u.ul = 0x2},
  {bp_ulPhyId3,                .u.ul = 0x3},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioSpromClk,          .u.us = BP_GPIO_68_AH}, /* for FTTDP */
  {bp_usGpioSpromData,         .u.us = BP_GPIO_69_AH}, /* for FTTDP */
  {bp_usGpioAttachedDevReset,  .u.us = BP_GPIO_0_AH}, /* for FTTDP */
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_last}
};

static bp_elem_t g_bcm968380dp2[] = {
  {bp_cpBoardId,               .u.cp = "968380DP2"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulAttachedIdx,           .u.ul = 4},
  {bp_ulPhyId0,                .u.ul = 0x0},
  {bp_ulPhyId1,                .u.ul = 0x1},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioSpromClk,          .u.us = BP_GPIO_68_AH}, /* for FTTDP */
  {bp_usGpioSpromData,         .u.us = BP_GPIO_69_AH}, /* for FTTDP */
  {bp_usGpioAttachedDevReset,  .u.us = BP_GPIO_67_AH}, /* for FTTDP */
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_last}
};

static bp_elem_t g_bcm965200f_cpe[] = {
  {bp_cpBoardId,               .u.cp = "965200F_CPE"},
  {bp_cpComment,               .u.cp = "(FCOPE_CPE)"},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x17},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 20000000},
  {bp_usSpiSlaveProtoRev,      .u.us = 2},
  {bp_usSpiSlaveSelectNum,     .u.us = 0},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_67_AL},
  {bp_last}
};

static bp_elem_t g_bcm965200f_co[] = {
  {bp_cpBoardId,               .u.cp = "965200F_CO"},
  {bp_cpComment,               .u.cp = "(FCOPE_CO)"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm965200f_cpe},
  {bp_last}
};

static bp_elem_t g_bcm965200dpf[] = {
  {bp_cpBoardId,               .u.cp = "965200DPF"},
  {bp_cpComment,               .u.cp = "(12L-CO,g.fast)"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 | PHY_INTERNAL | PHY_INTEGRATED_VALID | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  //{bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_ulAttachedIdx,           .u.ul = 1},
  {bp_ulPhyId0,                .u.ul = 6},
  {bp_ulPhyId1,                .u.ul = 7},
  {bp_ulPhyId2,                .u.ul = 8},
  {bp_ulAttachedIdx,           .u.ul = 2},
  {bp_ulPhyId0,                .u.ul = 3},
  {bp_ulPhyId1,                .u.ul = 4},
  {bp_ulPhyId2,                .u.ul = 5},
  {bp_ulAttachedIdx,           .u.ul = 3},
  {bp_ulPhyId0,                .u.ul = 0},
  {bp_ulPhyId1,                .u.ul = 1},
  {bp_ulPhyId2,                .u.ul = 2},
  {bp_ulAttachedIdx,           .u.ul = 4},
  {bp_ulPhyId0,                .u.ul = 9},
  {bp_ulPhyId1,                .u.ul = 10},
  {bp_ulPhyId2,                .u.ul = 11},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 20000000},
  {bp_usSpiSlaveProtoRev,      .u.us = 2},
  {bp_usSpiSlaveSelectNum,     .u.us = 0},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_67_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_68_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_72_AL},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usTsync8khz,             .u.us = BP_PIN_TSYNC_8KHZ_4},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_67_AL},
  {bp_cpXdResetName,           .u.cp = "DSP0_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_68_AL},
  {bp_cpXdResetName,           .u.cp = "DSP1_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_72_AL},
  {bp_cpXdResetName,           .u.cp = "DSP2_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_69_AL},
  {bp_cpXdResetName,           .u.cp = "AFE_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_70_AL},
  {bp_cpXdResetName,           .u.cp = "BCM54240_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdResetGpio,           .u.us = BP_GPIO_71_AL},
  {bp_cpXdResetName,           .u.cp = "BCM54220_RST_N"},
  {bp_usXdResetReleaseOnInit,  .u.us = 1},
  {bp_usXdGpio,                .u.us = BP_GPIO_54_AH},
  {bp_usXdGpioInitValue,       .u.us = 0},
  {bp_cpXdGpioInfo,            .u.cp = "DSP_CLK_SEL"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "DCXO"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "VCXO"},
  {bp_usXdGpio,                .u.us = BP_GPIO_2_AH},
  {bp_usXdGpioInitValue,       .u.us = 1},
  {bp_cpXdGpioInfo,            .u.cp = "DSP0_PWR"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "disable core power"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "enable core power"},
  {bp_usXdGpio,                .u.us = BP_GPIO_3_AH},
  {bp_usXdGpioInitValue,       .u.us = 1},
  {bp_cpXdGpioInfo,            .u.cp = "DSP1_PWR"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "disable core power"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "enable core power"},
  {bp_usXdGpio,                .u.us = BP_GPIO_7_AH},
  {bp_usXdGpioInitValue,       .u.us = 1},
  {bp_cpXdGpioInfo,            .u.cp = "DSP2_PWR"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "disable core power"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "enable core power"},
  {bp_usXdGpio,                .u.us = BP_GPIO_15_AH},
  {bp_usXdGpioInitValue,       .u.us = 0},
  {bp_cpXdGpioInfo,            .u.cp = "DSP2_SGMII_SEL"},
  {bp_cpXdGpioInfoValue0,      .u.cp = "bypass dsp2 sgmii"},
  {bp_cpXdGpioInfoValue1,      .u.cp = "connect dsp2 sgmii"},
  {bp_last}
};

static bp_elem_t g_bcm965200dpf2_co[] = {
  {bp_cpBoardId,               .u.cp = "965200DPF2_CO"},
  {bp_cpComment,               .u.cp = ""},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm965200f_cpe},
  {bp_last}
};

static bp_elem_t g_bcm965200dpf2_cpe[] = {
  {bp_cpBoardId,               .u.cp = "965200DPF2_CPE"},
  {bp_cpComment,               .u.cp = ""},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm965200f_cpe},
  {bp_last}
};

static bp_elem_t g_bcm968380fhgu_pg[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU_PG"},  
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_72_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_47_AL},
  {bp_usExtIntrWifiOnOff ,     .u.us = BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_71_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedGpon,           .u.us = BP_LED_5_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_15_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedUSB,            .u.us = BP_GPIO_53_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH}, 
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  /*{bp_usPmdMACEwakeEn,     .u.us = 1}, */
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_61_AH},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_35_AL},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_ENABLED | BP_PMD_APD_TYPE_FLYBACK},
  {bp_last}
};

static bp_elem_t g_bcm968380fhgu_dvt[] = {
  {bp_cpBoardId,               .u.cp = "968380FHGU_DVT"},  
  {bp_usRogueOnuEn,            .u.us = 0},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_51_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380fhgu_pg},
  {bp_last}
};

//BCM968381GREF board.
static bp_elem_t g_bcm968381gref[] = {
  {bp_cpBoardId,               .u.cp = "968381GREF"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385gsp},
  {bp_last}
};

static bp_elem_t g_bcm968380moca[] = {
  {bp_cpBoardId,               .u.cp = "968380MOCA"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
#if !defined(_CFE_)
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_7_AL},
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_4_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usExtIntrTrplxrTxFail,   .u.us = BP_EXT_INTR_4},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_12_AL},
  {bp_usExtIntrTrplxrSd,       .u.us = BP_EXT_INTR_5 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_13_AH},
  {bp_usTxLaserOnOutN,         .u.us = 1},
  {bp_usGpioPonReset,          .u.us = BP_GPIO_14_AH},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_16_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_16_AH},
  {bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPB},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedGpon,           .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA}, 
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_last}
};

static bp_elem_t g_bcm968380lte[] = {
  {bp_cpBoardId,               .u.cp = "968380LTE"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_4_AL},
  {bp_usTsync1pps,             .u.us = BP_PIN_TSYNC_1PPS_6},
  {bp_usGpio1ppsStable,        .u.us = BP_GPIO_7_AL},
  {bp_usGpioLedGpon,           .u.us = BP_GPIO_8_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_LED_2_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedUSB,            .u.us = BP_LED_3_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_11_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usWanNco10MClk,          .u.us = 1},
  {bp_usGpioVoip2Led,          .u.us = BP_LED_6_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_17_AL},
  {bp_usGpioLteReset,          .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_LED_0_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_33_AL},
  {bp_usGpioLedWanData,        .u.us = BP_LED_1_AL},
  {bp_usPinMux,                .u.us = BP_GPIO_34_AL},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usTrxSignalDetect,       .u.us = 1},
  {bp_usGpioStrapTxEn,         .u.us = BP_GPIO_58_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_57_AL},
#if 0 /* Gil for Gorden */
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_72_AL},
#endif 
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_59_AL},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_61_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_MII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_14_AH}, // uncomment to enable second UART
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH}, // uncomment to enable second UART 
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_last}
};

static bp_elem_t g_bcm968380gwan[] = {
  {bp_cpBoardId,               .u.cp = "968380GWAN"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usMiiInterfaceEn,        .u.us = 1},
  {bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPC},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_53_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x03 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_ulPhyId5,                .u.ul = 0x01 | BCM_WAN_PORT | PHYCFG_VALID | PHY_EXTERNAL | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968380gwan_opt[] = {
  {bp_cpBoardId,               .u.cp = "968380GWAN_OPT"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x03 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_ulPhyId5,                .u.ul = 0x02 | BCM_WAN_PORT | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_usAePolarity,            .u.us = 1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968380gwan},
  {bp_last}
};

static bp_elem_t g_bcm968389wlnvb[] = {
  {bp_cpBoardId,               .u.cp = "968389WLNVB"},
  {bp_ulOpticalWan,            .u.ul = BP_OPTICAL_WAN_GPON},
  {bp_usMiiInterfaceEn,        .u.us = 1},
  {bp_usSerialLEDMuxSel,       .u.us = BP_SERIAL_LED_MUX_GROUPC},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrWifiOnOff,      .u.us = BP_EXT_INTR_1},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_53_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioLedOpticalLinkFail,.u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x01 | BCM_WAN_PORT | PHYCFG_VALID | PHY_EXTERNAL | MAC_IF_SERDES}, /* WAN interface */
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_ulSimInterfaces,         .u.us = BP_SIMCARD_GROUPA},
  {bp_ulSlicInterfaces,        .u.us = BP_SLIC_GROUPD},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioPonRxEn,           .u.us = BP_GPIO_13_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usRogueOnuEn,            .u.us = 1},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968385pgsp[] = {
  {bp_cpBoardId,               .u.cp = "968385PGSP"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AH},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_61_AH},
  {bp_usExtIntrWanSignalDetected,     .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_35_AL},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_ENABLED | BP_PMD_APD_TYPE_FLYBACK},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968385gsp},
  {bp_last}
};


bp_elem_t * g_BoardParms[] = {g_bcm968380fhgu, g_bcm968380fhgu_si, g_bcm968380ffhg, g_bcm968380gerg, g_bcm968380mgeg, g_bcm968380gerg_si,
    g_bcm968380fsv_g, g_bcm968380sv_g, g_bcm968380fggu, g_bcm968380fggu_tri, g_bcm968385sfu, g_bcm968385sfu_si, g_bcm968385gsp, g_bcm968385sv_g,
    g_bcm968380fttdps, g_bcm968380dp2, g_bcm965200f_cpe, g_bcm965200f_co, g_bcm965200dpf, g_bcm965200dpf2_co, g_bcm965200dpf2_cpe, g_bcm968380fhgu_pg,
    g_bcm968380fhgu_dvt, g_bcm968381gref, g_bcm968381sv_g, g_bcm968380moca, g_bcm968380lte, g_bcm968380gwan, g_bcm968380gwan_opt, g_bcm968385pgsp, g_bcm968389wlnvb, 0};

#endif

#if defined(_BCM96848_) || defined(CONFIG_BCM96848)
static bp_elem_t g_bcm968480fhgu[] = {
  {bp_cpBoardId,                .u.cp = "968480FHGU"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x0f},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_MII},
  {bp_usOamIndex,               .u.us = 1},
  {bp_ucPhyDevName,             .u.cp = "eth1"},
  {bp_usLinkLed,                .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,               .u.us = 0},
  {bp_ucPhyDevName,             .u.cp = "eth0"},
  {bp_usLinkLed,                .u.us = BP_GPIO_9_AL},
  {bp_ulPhyId2,                 .u.ul = 0x03 | MAC_IF_MII},
  {bp_usOamIndex,               .u.us = 3},
  {bp_ucPhyDevName,             .u.cp = "eth3"},
  {bp_usLinkLed,                .u.us = BP_GPIO_54_AL},
  {bp_ulPhyId3,                 .u.ul = 0x04 | MAC_IF_MII},
  {bp_usOamIndex,               .u.us = 2},
  {bp_ucPhyDevName,             .u.cp = "eth2"},
  {bp_usLinkLed,                .u.us = BP_GPIO_52_AL},
  {bp_usGpioVoip1Led,           .u.us = BP_GPIO_10_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedUSB,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,     .u.us = BP_GPIO_12_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedSim,             .u.us = BP_GPIO_13_AL},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_14_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedEpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedWanData,         .u.us = BP_GPIO_17_AL | BP_LED_USE_GPIO},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_18_AH},
  {bp_usExtIntrSesBtnWireless,  .u.us = BP_EXT_INTR_6},
  {bp_usExtIntrWifiOnOff,       .u.us = BP_EXT_INTR_7},
  {bp_usSimVccEn,               .u.us = BP_GPIO_35_AH},
  {bp_usSimRst,                 .u.us = BP_GPIO_37_AH},
  {bp_usSimDat,                 .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                 .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,            .u.us = BP_GPIO_45_AH},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usTrxSignalDetect,        .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
  {bp_ucDspType0,               .u.uc =  BP_VOIP_DSP},
  {bp_ucDspAddress,             .u.uc =  0}, 
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_53_AH},
  {bp_usTsync1pps,              .u.us = BP_GPIO_6_AH},
  {bp_last}
};

static bp_elem_t g_bcm968480fhbb[] = {
  {bp_cpBoardId,               .u.cp = "968480FHBB"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_4_AL | BP_LED_USE_GPIO},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_usGpioLedSim,            .u.us = BP_GPIO_NONE},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_ENABLED | BP_PMD_APD_TYPE_FLYBACK},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968480fhgu},
  {bp_last}
};

static bp_elem_t g_bcm968480fhbbst[] = {
  {bp_cpBoardId,               .u.cp = "968480FHBBST"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_4_AL | BP_LED_USE_GPIO},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_usGpioLedSim,            .u.us = BP_GPIO_NONE},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_DISABLED | BP_PMD_APD_TYPE_BOOST},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968480fhgu},
  {bp_last}
};

static bp_elem_t g_bcm968485sfu[] = {
  {bp_cpBoardId,                .u.cp = "968485SFU"},
  {bp_usGponOpticsType ,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x03},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usLinkLed,                .u.us = BP_GPIO_34_AL},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_MII},
  {bp_usLinkLed,                .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSim,             .u.us = BP_GPIO_13_AL},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedEpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioVoip1Led,           .u.us = BP_GPIO_16_AL | BP_LED_USE_GPIO},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_18_AH},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_33_AL},
  {bp_usSimVccEn,               .u.us = BP_GPIO_35_AH},
  {bp_usSimRst,                 .u.us = BP_GPIO_37_AH},
  {bp_usSimDat,                 .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                 .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,            .u.us = BP_GPIO_45_AH},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usTrxSignalDetect,        .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5},
  {bp_ucDspType0,              .u.uc =  BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc =  0}, 
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968485sfbb[] = {
  {bp_cpBoardId,               .u.cp = "968485SFBB"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_4_AL | BP_LED_USE_GPIO},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968485sfu},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_ENABLED | BP_PMD_APD_TYPE_FLYBACK},
  {bp_last}
};

static bp_elem_t g_bcm968480sv[] = {
  {bp_cpBoardId,               .u.cp = "968480SV"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x2f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 1},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 0},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 3},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 2},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_17_AL},
  {bp_ulPhyId5,                .u.ul = 0x05 | BCM_WAN_PORT | MAC_IF_SERDES},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_usOamIndex,              .u.us = 5},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_usSimDat,                .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,           .u.us = BP_GPIO_45_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_10_AH | BP_LED_USE_GPIO},
  {bp_usSerialLedData,         .u.us = BP_GPIO_11_AH},
  {bp_usSimVccEn,              .u.us = BP_GPIO_35_AH},
  {bp_usSimVccVolSel,          .u.us = BP_GPIO_36_AH},
  {bp_usSimRst,                .u.us = BP_GPIO_37_AH},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_18_AH},
//  {bp_usMiiMdc,                .u.us = BP_GPIO_47_AH},
//  {bp_usMiiMdio,               .u.us = BP_GPIO_48_AH},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usProbeClk,              .u.us = BP_GPIO_74_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedUSB,            .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedSim,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedOpticalLinkStat,.u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioLedGpon,           .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usAePolarity,            .u.us = 0},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_usTsync1pps,             .u.us = BP_GPIO_6_AH},
  {bp_last}
};

static bp_elem_t g_bcm968480sv_sgmii[] = {
  {bp_cpBoardId,               .u.cp = "968480SV_SGMII"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x06 | MAC_IF_SGMII }, /* or MAC_IF_HSGMII */
  {bp_usOamIndex,              .u.us = 1},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 0},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 3},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 2},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_17_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968480sv},
  {bp_last}
};

static bp_elem_t g_bcm968485sv[] = {
  {bp_cpBoardId,               .u.cp = "968485SV"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_MII},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_usSimDat,                .u.us = BP_GPIO_43_AH},
  {bp_usSimClk,                .u.us = BP_GPIO_44_AH},
  {bp_usSimPresence,           .u.us = BP_GPIO_45_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_10_AH | BP_LED_USE_GPIO},
  {bp_usSerialLedData,         .u.us = BP_GPIO_11_AH},
  {bp_usSimVccEn,              .u.us = BP_GPIO_35_AH},
  {bp_usSimVccVolSel,          .u.us = BP_GPIO_36_AH},
  {bp_usSimRst,                .u.us = BP_GPIO_37_AH},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_18_AH},
//  {bp_usMiiMdc,                .u.us = BP_GPIO_47_AH},
//  {bp_usMiiMdio,               .u.us = BP_GPIO_48_AH},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usProbeClk,              .u.us = BP_GPIO_74_AH},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_1_AL},
//  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedSim,            .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioLedOpticalLinkStat,.u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0}, 
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_usSpiSlaveSelectNum,     .u.us = 6},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 12},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 67},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_usTsync1pps,             .u.us = BP_GPIO_6_AH},
  {bp_last}
};

static bp_elem_t g_bcm968481sp[] = {
  {bp_cpBoardId,                .u.cp = "968481SP"},
  {bp_usGponOpticsType ,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x01},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usLinkLed,                .u.us = BP_GPIO_34_AL},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_16_AH},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedEpon,            .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_33_AL},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
//  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5},
  {bp_usWirelessFlags,         .u.us = BP_WLAN_EXCLUDE_ONBOARD},
  {bp_last}
};

static bp_elem_t g_bcm968481spbb[] = {
  {bp_cpBoardId,               .u.cp = "968481SPBB"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_4_AL | BP_LED_USE_GPIO},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968481sp},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_ENABLED | BP_PMD_APD_TYPE_FLYBACK},
  {bp_last}
};

static bp_elem_t g_bcm968481psv[] = {
  {bp_cpBoardId,               .u.cp = "968481PSV"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x06 | MAC_IF_SGMII },
  {bp_usWanEarlyTxEn,          .u.us = BP_GPIO_10_AH},
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_14_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH},
  {bp_usWanNco10MClk,          .u.us = BP_GPIO_16_AH},
//  {bp_usMiiMdc,                .u.us = BP_GPIO_47_AH},
//  {bp_usMiiMdio,               .u.us = BP_GPIO_48_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 61},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usMs1588TodAlarm,        .u.us = BP_GPIO_65_AH},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_66_AH},
  {bp_usWanNcoProgMClk,        .u.us = BP_GPIO_67_AH},
  {bp_usProbeClk,              .u.us = BP_GPIO_74_AH},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968481psv_phy[] = {
  {bp_cpBoardId,               .u.cp = "968481PSV_PHY"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x07 | MAC_IF_SGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_usWanEarlyTxEn,          .u.us = BP_GPIO_10_AH},
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_14_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH},
  {bp_usWanNco10MClk,          .u.us = BP_GPIO_16_AH},
  {bp_usMiiMdc,                .u.us = BP_GPIO_47_AH},
  {bp_usMiiMdio,               .u.us = BP_GPIO_48_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 61},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usMs1588TodAlarm,        .u.us = BP_GPIO_65_AH},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_66_AH},
  {bp_usWanNcoProgMClk,        .u.us = BP_GPIO_67_AH},
  {bp_usProbeClk,              .u.us = BP_GPIO_74_AH},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968486sgu[] = {
  {bp_cpBoardId,                .u.cp = "968486SGU"},
  {bp_usGponOpticsType ,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x03},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_MII},
  {bp_usLinkLed,                .u.us = BP_GPIO_52_AL},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usLinkLed,                .u.us = BP_GPIO_9_AL},
  {bp_usGpioVoip1Led,           .u.us = BP_GPIO_10_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedUSB,             .u.us = BP_GPIO_11_AL},
  {bp_usGpioLedSesWireless,     .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedOpticalLinkStat, .u.us = BP_GPIO_14_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedGpon,            .u.us = BP_GPIO_15_AL | BP_LED_USE_GPIO},
  {bp_usGpioLedWanData,         .u.us = BP_GPIO_17_AL},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_18_AH},
  {bp_usExtIntrSesBtnWireless,  .u.us = BP_EXT_INTR_6},
  {bp_usExtIntrWifiOnOff,       .u.us = BP_EXT_INTR_7},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_51_AH},
  {bp_usTrxSignalDetect,        .u.us = BP_GPIO_53_AH},
  {bp_usTxLaserOnOutN,          .u.us = BP_GPIO_62_AH},
  {bp_usGpioI2cScl,             .u.us = BP_GPIO_63_AH},
  {bp_usGpioI2cSda,             .u.us = BP_GPIO_64_AH},
  {bp_ucDspType0,               .u.uc =  BP_VOIP_DSP},
  {bp_ucDspAddress,             .u.uc =  0},
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_4},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_53_AH},
  {bp_last}
};

static bp_elem_t g_bcm968481psfp[] = {
  {bp_cpBoardId,               .u.cp = "968481PSFP"},
  {bp_usGponOpticsType ,       .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_use_def_polarity},
  {bp_InvSerdesTxPol,          .u.us = pmd_use_def_polarity},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x01},
  {bp_ulPhyId0,                .u.ul = 0x06 | MAC_IF_SGMII },
  {bp_usTsync1pps,             .u.us = BP_GPIO_6_AH},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_10_AL},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_15_AH},
  {bp_usGpioWanSignalDetected, .u.us = BP_GPIO_53_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 0},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 60},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_61_AL},
  {bp_usTxLaserOnOutN,         .u.us = BP_GPIO_62_AH},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_68_AH},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_ENABLED | BP_PMD_APD_TYPE_FLYBACK},
  {bp_last}
  };

static bp_elem_t g_bcm968488sgw[] = {
  {bp_cpBoardId,               .u.cp = "968488SGW"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 1},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 0},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 3},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_usLinkLed,               .u.us = BP_GPIO_54_AL},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_MII},
  {bp_usOamIndex,              .u.us = 2},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_usLinkLed,               .u.us = BP_GPIO_52_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968486sgu},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm968480fhgu, g_bcm968480fhbb, g_bcm968485sfu, g_bcm968480sv, g_bcm968480sv_sgmii, g_bcm968485sv, g_bcm968481sp, 
    g_bcm968481spbb, g_bcm968485sfbb, g_bcm968481psv, g_bcm968481psv_phy, g_bcm968486sgu, g_bcm968481psfp, g_bcm968480fhbbst, g_bcm968488sgw, 0};
#endif

#if defined(_BCM96858_) || defined(CONFIG_BCM96858)
static bp_elem_t g_bcm968580xsv[] = {
  {bp_cpBoardId,                .u.cp = "968580XSV"},
  {bp_usPcmSdin,                .u.us = BP_GPIO_0_AH},
  {bp_usPcmSdout,               .u.us = BP_GPIO_1_AH},
  {bp_usPcmClk,                 .u.us = BP_GPIO_2_AH},
  {bp_usPcmFs,                  .u.us = BP_GPIO_3_AH},
  {bp_usGpioUart2Sdin,          .u.us = BP_GPIO_16_AH},
  {bp_usGpioUart2Sdout,         .u.us = BP_GPIO_17_AH},
  {bp_usGpioUart2Cts,           .u.us = BP_GPIO_18_AH},
  {bp_usGpioUart2Rts,           .u.us = BP_GPIO_19_AH},
  {bp_usGpioI2c2Scl,            .u.us = BP_GPIO_23_AH},
  {bp_usGpioI2c2Sda,            .u.us = BP_GPIO_24_AH},
  {bp_usSerialLedData,          .u.us = BP_GPIO_29_AH},
  {bp_usSerialLedClk,           .u.us = BP_GPIO_30_AH},
  {bp_usSerialLedMask,          .u.us = BP_GPIO_31_AH},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_50_AH},
  {bp_usGponOpticsType,         .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usSpiSlaveSelectNum,      .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 51},
  {bp_usSpiSlaveSelectNum,      .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 13},
  {bp_usSpiSlaveSelectNum,      .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 12},
  {bp_usSpiSlaveSelectNum,      .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 11},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_56_AH},
  {bp_usI2sSdata,               .u.us = BP_GPIO_59_AH},
  {bp_usI2sSclk,                .u.us = BP_GPIO_60_AH},
  {bp_usI2sLrck,                .u.us = BP_GPIO_61_AH},
  {bp_ulInterfaceEnable,        .u.ul = BP_PINMUX_FNTYPE_LPORT},
  {bp_usUsbPwrOn0,              .u.us = BP_GPIO_113_AH},
  {bp_usUsbPwrFlt0,             .u.us = BP_GPIO_114_AH},
  {bp_usUsbPwrOn1,              .u.us = BP_GPIO_115_AH},
  {bp_usUsbPwrFlt1,             .u.us = BP_GPIO_116_AH},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedEpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanData,         .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x0f},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed3,                .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_ALL},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed3,                .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_ALL},
  {bp_ulPhyId2,                 .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed3,                .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_ALL},
  {bp_ulPhyId3,                 .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed3,                .u.us = BP_SERIAL_GPIO_24_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_ALL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_20_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_24_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_25_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_27_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_28_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_29_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_30_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_31_AL},
  {bp_usGpio10GTxDis,          .u.us = BP_GPIO_52_AH},
  {bp_usSFPSerdesSIGDET0,      .u.us = BP_GPIO_57_AH},
  {bp_usSFPSerdesSIGDET1,      .u.us = BP_GPIO_58_AH},
  {bp_usSFPSerdesSIGDET2,      .u.us = BP_GPIO_59_AH},
  {bp_usSFPSerdesSIGDET3,      .u.us = BP_GPIO_60_AH},
  {bp_usSFPSerdesMODDEF0,      .u.us = BP_GPIO_24_AH},
  {bp_usSFPSerdesMODDEF1,      .u.us = BP_GPIO_25_AH},
  {bp_usSFPSerdesMODDEF2,      .u.us = BP_GPIO_26_AH},
  {bp_usSFPSerdesMODDEF3,      .u.us = BP_GPIO_27_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcm968580xsv_rgmii_phy[] = {
  {bp_cpBoardId,               .u.cp = "968580XSV_RGPHY"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x7f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 0},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 1},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 2},
  {bp_ucPhyDevName,            .u.cp = "eth2"},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usOamIndex,              .u.us = 3},
  {bp_ucPhyDevName,            .u.cp = "eth3"},
  {bp_ulPhyId4,                .u.ul = 0x05 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usOamIndex,              .u.us = 6},
  {bp_ucPhyDevName,            .u.cp = "eth6"},
  {bp_ulPhyId5,                .u.ul = 0x07 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usOamIndex,              .u.us = 4},
  {bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_ulPhyId6,                .u.ul = 0x06 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usOamIndex,              .u.us = 5},
  {bp_ucPhyDevName,            .u.cp = "eth5"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xsv},
  {bp_last}
};

static bp_elem_t g_bcm968580xsv_sgmii_phy[] = {
  {bp_cpBoardId,               .u.cp = "968580XSV_SGPHY"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x7f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x1c | MAC_IF_SGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId5,                .u.ul = 0x1a | MAC_IF_SGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId6,                .u.ul = 0x16 | MAC_IF_SGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xsv},
  {bp_last}
};

static bp_elem_t g_bcm968580xsv_hsgmii_phy[] = {
  {bp_cpBoardId,               .u.cp = "968580XSV_HSG"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x7f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x1c | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId5,                .u.ul = 0x1a | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId6,                .u.ul = 0x16 | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xsv},
  {bp_last}
};

static bp_elem_t g_bcm968580xsv_sgmii_opt[] = {
  {bp_cpBoardId,               .u.cp = "968580XSV_SGOPT"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x7f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x04 | MAC_IF_SGMII},
  {bp_ulPhyId5,                .u.ul = 0x05 | MAC_IF_SGMII},
  {bp_ulPhyId6,                .u.ul = 0x06 | MAC_IF_SGMII},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xsv},
  {bp_last}
};

static bp_elem_t g_bcm968580xsv_xfi_opt[] = {
  {bp_cpBoardId,               .u.cp = "968580XSV_XFI"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x04 | MAC_IF_XFI},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xsv},
  {bp_last}
};

static bp_elem_t g_bcm968580xref[] = {
  {bp_cpBoardId,                .u.cp = "968580XREF"},
  {bp_usPcmSdin,                .u.us = BP_GPIO_0_AH},
  {bp_usPcmSdout,               .u.us = BP_GPIO_1_AH},
  {bp_usPcmClk,                 .u.us = BP_GPIO_2_AH},
  {bp_usPcmFs,                  .u.us = BP_GPIO_3_AH},
  {bp_usGpioUart2Sdin,          .u.us = BP_GPIO_16_AH},
  {bp_usGpioUart2Sdout,         .u.us = BP_GPIO_17_AH},
  {bp_usGpioUart2Cts,           .u.us = BP_GPIO_18_AH},
  {bp_usGpioUart2Rts,           .u.us = BP_GPIO_19_AH},
  {bp_usGpioI2c2Scl,            .u.us = BP_GPIO_23_AH},
  {bp_usGpioI2c2Sda,            .u.us = BP_GPIO_24_AH},
  {bp_usSerialLedData,          .u.us = BP_GPIO_29_AH},
  {bp_usSerialLedClk,           .u.us = BP_GPIO_30_AH},
  {bp_usSerialLedMask,          .u.us = BP_GPIO_31_AH},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_49_AH},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_50_AH},
  {bp_usGponOpticsType,         .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usSpiSlaveSelectNum,      .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 106},
  {bp_usSpiSlaveSelectNum,      .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 51},
  {bp_usSpiSlaveSelectNum,      .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 13},
#ifdef CONFIG_BCM_TIME_SYNC_MODULE
  {bp_usTsync1pps,              .u.us = BP_GPIO_11_AH | BP_NONGPIO_PIN},
  {bp_usGpioTsyncPonUnstable,   .u.us = BP_GPIO_12_AH},
  {bp_usUart1Sdin,              .u.us = BP_GPIO_27_AH}, 
  {bp_usUart1Sdout,             .u.us = BP_GPIO_28_AH}, 
#else
  {bp_usSpiSlaveSelectNum,      .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 12},
  {bp_usSpiSlaveSelectNum,      .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 11},
#endif
  {bp_usExtIntrOpticalModulePresence, .u.us = BP_EXT_INTR_3 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_32_AL},
  {bp_usGpioOpticalModuleFixup, .u.us = BP_GPIO_55_AH},
  {bp_usExtIntrSesBtnWireless,  .u.us = BP_EXT_INTR_4 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_53_AL},
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_54_AL},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_56_AH},
  {bp_usI2sSdata,               .u.us = BP_GPIO_59_AH},
  {bp_usI2sSclk,                .u.us = BP_GPIO_60_AH},
  {bp_usI2sLrck,                .u.us = BP_GPIO_61_AH},
  {bp_ulInterfaceEnable,        .u.ul = BP_PINMUX_FNTYPE_LPORT},
  {bp_usUsbPwrOn0,              .u.us = BP_GPIO_113_AL},
  {bp_usUsbPwrFlt0,             .u.us = BP_GPIO_114_AL},
  {bp_usUsbPwrOn1,              .u.us = BP_GPIO_115_AL},
  {bp_usUsbPwrFlt1,             .u.us = BP_GPIO_116_AL},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedEpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanData,         .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioVoip1Led,           .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioVoip2Led,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedUSB,             .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedUSB2,            .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usGpioLedSesWireless,     .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_20_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x0f},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId2,                 .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId3,                 .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ucDspType0,               .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,             .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcm968580xref_old[] = {
  {bp_cpBoardId,               .u.cp = "968580XREF_OLD"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x04 | MAC_IF_XFI},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usGpio10GTxDis,          .u.us = BP_GPIO_52_AH},
  {bp_usSFPSerdesSIGDET1,      .u.us = BP_GPIO_58_AH},
  {bp_usSFPSerdesMODDEF1,      .u.us = BP_GPIO_25_AH},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref},
  {bp_last}
};

static bp_elem_t g_bcm968580xref_opt[] = {
  {bp_cpBoardId,               .u.cp = "968580XREF_OPT"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x7f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x04 | MAC_IF_XFI},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usGpio10GTxDis,          .u.us = BP_GPIO_52_AH},
  {bp_usSFPSerdesSIGDET1,      .u.us = BP_GPIO_58_AH},
  {bp_usSFPSerdesMODDEF1,      .u.us = BP_GPIO_25_AH},
  {bp_ulPhyId5,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref},
  {bp_last}
};

static bp_elem_t g_bcm968580xref_phy[] = {
  {bp_cpBoardId,               .u.cp = "968580XREF_PHY"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x7f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x1e | MAC_IF_XFI | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_10G},
  {bp_ulPhyId5,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref},
  {bp_last}
};

static bp_elem_t g_bcm968580xref_ae[] = {
  {bp_cpBoardId,               .u.cp = "968580XREF_AE"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x17f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_ulPhyId4,                .u.ul = 0x1e | MAC_IF_XFI | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_10G},
  {bp_ulPhyId5,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId8,                .u.ul = 0x1e | MAC_IF_XFI | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_WAN_ONLY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref},
  {bp_last}
};

static bp_elem_t g_bcm968580xref_pcix2[] = {
  {bp_cpBoardId,               .u.cp = "968580XREF_PCIx2"},
  {bp_ulPciFlags,              .u.ul =  BP_PCI0_DUAL_LANE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref},
  {bp_last}
};

static bp_elem_t g_bcm968580xrnd[] = {
  {bp_cpBoardId,                .u.cp = "968580XRND"},
  {bp_usPcmSdin,                .u.us = BP_GPIO_0_AH},
  {bp_usPcmSdout,               .u.us = BP_GPIO_1_AH},
  {bp_usPcmClk,                 .u.us = BP_GPIO_2_AH},
  {bp_usPcmFs,                  .u.us = BP_GPIO_3_AH},
  {bp_usGpioUart2Sdin,          .u.us = BP_GPIO_16_AH},
  {bp_usGpioUart2Sdout,         .u.us = BP_GPIO_17_AH},
  {bp_usGpioUart2Cts,           .u.us = BP_GPIO_18_AH},
  {bp_usGpioUart2Rts,           .u.us = BP_GPIO_19_AH},
  {bp_usGpioI2c2Scl,            .u.us = BP_GPIO_23_AH},
  {bp_usGpioI2c2Sda,            .u.us = BP_GPIO_24_AH},
  {bp_usSFPSerdesMODDEF1,       .u.us = BP_GPIO_25_AH},
  {bp_usUart1Sdin,              .u.us = BP_GPIO_27_AH},
  {bp_usUart1Sdout,             .u.us = BP_GPIO_28_AH},
  {bp_usSerialLedData,          .u.us = BP_GPIO_29_AH},
  {bp_usSerialLedClk,           .u.us = BP_GPIO_30_AH},
  {bp_usSerialLedMask,          .u.us = BP_GPIO_31_AH},
  {bp_usGpioWanSignalDetected,  .u.us = BP_GPIO_49_AH},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_50_AH},
  {bp_usGpio10GTxDis,           .u.us = BP_GPIO_52_AH},
  {bp_usGpioPonMuxOe,           .u.us = BP_GPIO_53_AH},
  {bp_usSFPSerdesSIGDET1,       .u.us = BP_GPIO_58_AH},
  {bp_usGpioPonMux0,            .u.us = BP_GPIO_59_AH},
  {bp_usGpioPonMux1,            .u.us = BP_GPIO_60_AH},
  {bp_usGponOpticsType,         .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usSpiSlaveSelectNum,      .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 51},
  {bp_usSpiSlaveSelectNum,      .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 13},
  {bp_usSpiSlaveSelectNum,      .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 12},
  {bp_usSpiSlaveSelectNum,      .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 11},
  {bp_usExtIntrResetToDefault,  .u.us = BP_EXT_INTR_5 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,              .u.us = BP_GPIO_54_AL},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_56_AH},
  {bp_ulInterfaceEnable,        .u.ul = BP_PINMUX_FNTYPE_LPORT},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedEpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanData,         .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedReserved,        .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x13},
  {bp_ulPhyId0,                 .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId1,                 .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId4,                 .u.ul = 0x04 | MAC_IF_XFI},
  {bp_usNetLed0,                .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedLink,             .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usNetLed1,                .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedActivity,         .u.ul = BP_NET_LED_SPEED_10G},
  {bp_ucDspAddress,             .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcm955040sv[] = {
  {bp_cpBoardId,                .u.cp = "955040SV"},
  {bp_usPcmSdin,                .u.us = BP_GPIO_0_AH},
  {bp_usPcmSdout,               .u.us = BP_GPIO_1_AH},
  {bp_usPcmClk,                 .u.us = BP_GPIO_2_AH},
  {bp_usPcmFs,                  .u.us = BP_GPIO_3_AH},
  {bp_usGpioUart2Sdin,          .u.us = BP_GPIO_16_AH},
  {bp_usGpioUart2Sdout,         .u.us = BP_GPIO_17_AH},
  {bp_usGpioUart2Cts,           .u.us = BP_GPIO_18_AH},
  {bp_usGpioUart2Rts,           .u.us = BP_GPIO_19_AH},
  {bp_usGpioI2c2Scl,            .u.us = BP_GPIO_23_AH},
  {bp_usGpioI2c2Sda,            .u.us = BP_GPIO_24_AH},
  {bp_usSerialLedData,          .u.us = BP_GPIO_29_AH},
  {bp_usSerialLedClk,           .u.us = BP_GPIO_30_AH},
  {bp_usSerialLedMask,          .u.us = BP_GPIO_31_AH},
  {bp_usGpioPonTxEn,            .u.us = BP_GPIO_50_AH},
  {bp_usGponOpticsType,         .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usSpiSlaveSelectNum,      .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 51},
  {bp_usSpiSlaveSelectNum,      .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 13},
  {bp_usSpiSlaveSelectNum,      .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 12},
  {bp_usSpiSlaveSelectNum,      .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum,  .u.us = 11},
  {bp_usRogueOnuEn,             .u.us = BP_GPIO_56_AH},
  {bp_usI2sSdata,               .u.us = BP_GPIO_59_AH},
  {bp_usI2sSclk,                .u.us = BP_GPIO_60_AH},
  {bp_usI2sLrck,                .u.us = BP_GPIO_61_AH},
  {bp_ulInterfaceEnable,        .u.ul = BP_PINMUX_FNTYPE_LPORT},
  {bp_usUsbPwrOn0,              .u.us = BP_GPIO_113_AH},
  {bp_usUsbPwrFlt0,             .u.us = BP_GPIO_114_AH},
  {bp_usUsbPwrOn1,              .u.us = BP_GPIO_115_AH},
  {bp_usUsbPwrFlt1,             .u.us = BP_GPIO_116_AH},
  {bp_usGpioLedOpticalLinkFail, .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedGpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedEpon,            .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanData,         .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x10},
  {bp_ulPhyId4,                 .u.ul = 0x05 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usGpio10GTxDis,          .u.us = BP_GPIO_52_AH},
  {bp_usSFPSerdesSIGDET0,      .u.us = BP_GPIO_57_AH},
  {bp_usSFPSerdesSIGDET1,      .u.us = BP_GPIO_58_AH},
  {bp_usSFPSerdesSIGDET2,      .u.us = BP_GPIO_59_AH},
  {bp_usSFPSerdesSIGDET3,      .u.us = BP_GPIO_60_AH},
  {bp_usSFPSerdesMODDEF0,      .u.us = BP_GPIO_24_AH},
  {bp_usSFPSerdesMODDEF1,      .u.us = BP_GPIO_25_AH},
  {bp_usSFPSerdesMODDEF2,      .u.us = BP_GPIO_26_AH},
  {bp_usSFPSerdesMODDEF3,      .u.us = BP_GPIO_27_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcm955040sv_hsgmii_phy[] = {
  {bp_cpBoardId,                .u.cp = "955040SV_HSG"},
  {bp_ucPhyType0,               .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,             .u.uc = 0x0},
  {bp_usConfigType,             .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,                .u.ul = 0x1f},
  {bp_ulPhyId0,                 .u.ul = 0x1e | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId1,                 .u.ul = 0x1c | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId2,                 .u.ul = 0x1a | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId3,                 .u.ul = 0x16 | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId4,                 .u.ul = 0x05 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_elemTemplate,             .u.bp_elemp = g_bcm955040sv},
  {bp_last}
};

static bp_elem_t g_bcm968580xpmd[] = {
  {bp_cpBoardId,               .u.cp = "968580XPMD"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_56_AH},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_32_AH},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_50_AL},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_TYPE_FLYBACK | BP_PMD_APD_REG_ENABLED},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref_old},
  {bp_last}
};

static bp_elem_t g_bcm968580xref_dpu[] = {
  {bp_cpBoardId,               .u.cp = "968580XREF_DPU"},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 10000000},
  {bp_usSpiSlaveProtoRev,      .u.us = 2},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_13_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref_opt},
  {bp_last}
};

static bp_elem_t g_bcm968580xref_dpug[] = {
  {bp_cpBoardId,               .u.cp = "968580XREF_DPG"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT},
  {bp_ulPhyId4,                .u.ul = 0x04 | MAC_IF_XFI},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_ATTACHED},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_10G},
  {bp_usGpio10GTxDis,          .u.us = BP_GPIO_52_AH},
  {bp_usSFPSerdesSIGDET1,      .u.us = BP_GPIO_58_AH},
  {bp_usSFPSerdesMODDEF1,      .u.us = BP_GPIO_25_AH},
  //{bp_ucPhyDevName,            .u.cp = "eth4"},
  {bp_ulAttachedIdx,           .u.ul = 4},
  {bp_ulPhyId0,                .u.ul = 0},
  {bp_ulPhyId1,                .u.ul = 1},
  {bp_ulPhyId2,                .u.ul = 2},
  {bp_ulAttachedIdx,           .u.ul = 1},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 10000000},
  {bp_usSpiSlaveProtoRev,      .u.us = 2},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_13_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968580xref},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm968580xsv, g_bcm968580xsv_rgmii_phy, g_bcm968580xsv_sgmii_phy, g_bcm968580xsv_hsgmii_phy, g_bcm968580xsv_sgmii_opt, g_bcm968580xsv_xfi_opt, g_bcm968580xref, g_bcm968580xref_old, g_bcm968580xref_opt, g_bcm968580xref_phy, g_bcm968580xref_ae, g_bcm968580xrnd, g_bcm955040sv, g_bcm955040sv_hsgmii_phy, g_bcm968580xpmd, g_bcm968580xref_dpu, g_bcm968580xref_dpug, g_bcm968580xref_pcix2, 0};
#endif

#if defined(_BCM96836_) || defined(CONFIG_BCM96836)
static bp_elem_t g_bcm968360sv[] = {
  {bp_cpBoardId,               .u.cp = "968360SV"},
  {bp_usI2sSdata,              .u.us = BP_GPIO_0_AH},
  {bp_usI2sSclk,               .u.us = BP_GPIO_1_AH},
  {bp_usI2sLrck,               .u.us = BP_GPIO_2_AH},
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_4_AH},
  {bp_usGpioUart2Rts,          .u.us = BP_GPIO_5_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_19_AL},
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_20_AL},
  {bp_usSerialLedData,         .u.us = BP_GPIO_26_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_27_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_28_AH},
  {bp_usMiiMdc,                .u.us = BP_GPIO_60_AH},
  {bp_usMiiMdio,               .u.us = BP_GPIO_61_AH},
  {bp_usUsbPwrFlt0,            .u.us = BP_GPIO_76_AL},
  {bp_usUsbPwrOn0,             .u.us = BP_GPIO_77_AL},
  {bp_usUsbPwrFlt1,            .u.us = BP_GPIO_78_AL},
  {bp_usUsbPwrOn1,             .u.us = BP_GPIO_79_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId4,                .u.ul = 0x07 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_20_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_24_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_25_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_27_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_28_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_29_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_30_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_31_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_15_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_last}
};

static bp_elem_t g_bcm968360sv_phy[] = {
  {bp_cpBoardId,               .u.cp = "968360SV_PHY"},
  {bp_usI2sSdata,              .u.us = BP_GPIO_0_AH},
  {bp_usI2sSclk,               .u.us = BP_GPIO_1_AH},
  {bp_usI2sLrck,               .u.us = BP_GPIO_2_AH},
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_4_AH},
  {bp_usGpioUart2Rts,          .u.us = BP_GPIO_5_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_19_AL},
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_20_AL},
  {bp_usSerialLedData,         .u.us = BP_GPIO_26_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_27_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_28_AH},
  {bp_usMiiMdc,                .u.us = BP_GPIO_60_AH},
  {bp_usMiiMdio,               .u.us = BP_GPIO_61_AH},
  {bp_usUsbPwrFlt0,            .u.us = BP_GPIO_76_AL},
  {bp_usUsbPwrOn0,             .u.us = BP_GPIO_77_AL},
  {bp_usUsbPwrFlt1,            .u.us = BP_GPIO_78_AL},
  {bp_usUsbPwrOn1,             .u.us = BP_GPIO_79_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x3f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId4,                .u.ul = 0x07 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId5,                .u.ul = 0x1e | MAC_IF_HSGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_ALL},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_ALL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_20_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_24_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_25_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_27_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_28_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_29_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_30_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_31_AL},
  {bp_last}
};

static bp_elem_t g_bcm968360gref[] = {
  {bp_cpBoardId,               .u.cp = "968360GREF"},
//  {bp_usI2sSdata,              .u.us = BP_GPIO_0_AH},
//  {bp_usI2sSclk,               .u.us = BP_GPIO_1_AH},
//  {bp_usI2sLrck,               .u.us = BP_GPIO_2_AH},
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_4_AH},
  {bp_usGpioUart2Rts,          .u.us = BP_GPIO_5_AH},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_12_AL},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_19_AL},
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_20_AL},
  {bp_usSerialLedData,         .u.us = BP_GPIO_26_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_27_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_28_AH},
  {bp_usMiiMdc,                .u.us = BP_GPIO_60_AH},
  {bp_usMiiMdio,               .u.us = BP_GPIO_61_AH},
  {bp_usUsbPwrFlt0,            .u.us = BP_GPIO_76_AL},
  {bp_usUsbPwrOn0,             .u.us = BP_GPIO_77_AL},
  {bp_usUsbPwrFlt1,            .u.us = BP_GPIO_78_AL},
  {bp_usUsbPwrOn1,             .u.us = BP_GPIO_79_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_INTERNAL_PHY},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId1,                .u.ul = 0x02 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId2,                .u.ul = 0x03 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId3,                .u.ul = 0x04 | MAC_IF_GMII},
  {bp_usNetLed0,               .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_ulNetLedLink,            .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_usNetLed1,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulNetLedActivity,        .u.ul = BP_NET_LED_SPEED_GBE},
  {bp_ulPhyId4,                .u.ul = 0x07 | MAC_IF_RGMII | PHY_EXTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_13_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_18_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_19_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_20_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_23_AL},
  {bp_usGpioPonTxEn,           .u.us = BP_GPIO_15_AH},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_LEGACY},
  {bp_usSpiSlaveSelectNum,     .u.us = 1},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 81},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcm968360pmd[] = {
  {bp_cpBoardId,               .u.cp = "968360PMD"},
  {bp_usGponOpticsType,        .u.us = BP_GPON_OPTICS_TYPE_PMD},
  {bp_InvSerdesRxPol,          .u.us = pmd_polarity_invert},
  {bp_InvSerdesTxPol,          .u.us = pmd_polarity_invert}, 
  {bp_usPmdMACEwakeEn,         .u.us = BP_GPIO_24_AH},
  {bp_usExtIntrPmdAlarm,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_TYPE_IRQ_SENSE_EDGE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_10_AH},
  {bp_usGpioPmdReset,          .u.us = BP_GPIO_21_AL},
  {bp_pmdFunc,                 .u.us = BP_PMD_APD_REG_DISABLED },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm968360gref},
  {bp_last}
};


bp_elem_t * g_BoardParms[] = {g_bcm968360sv, g_bcm968360sv_phy, g_bcm968360gref, g_bcm968360pmd, 0};
#endif

#if defined(_BCM963268_) || defined(CONFIG_BCM963268)

static char g_obsoleteStr[] = "(obsolete)";

static bp_elem_t g_bcm963268sv1[] = {
  {bp_cpBoardId,               .u.cp = "963268SV1"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv_17a[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV_17A"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0}, 
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306| BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_21},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv_30a[] = {
  {bp_cpBoardId ,              .u.cp = "963168MBV_30A"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0}, 
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv17a302[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV17A302"},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_17_AL},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_13_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_12_AH},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_17a},
  {bp_last}
};

static bp_elem_t g_bcm963167ref1[] = {
  {bp_cpBoardId,               .u.cp = "963167REF1"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE|BP_OVERLAY_VREG_CLK)},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 },
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_36_AL},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv17a302},
  {bp_last}
};

static bp_elem_t g_bcm963167ref3[] = {
  {bp_cpBoardId,               .u.cp = "963167REF3"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963167ref1},
  {bp_last}

};

static bp_elem_t g_bcm963167ref2[] = {
  {bp_cpBoardId,               .u.cp = "963167REF2"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},

  {bp_elemTemplate,            .u.bp_elemp = g_bcm963167ref1},
  {bp_last}

};

static bp_elem_t g_bcm963168mbv30a302[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV30A302"},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_17_AL},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_13_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_12_AH},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

static bp_elem_t g_bcm963268mbv[] = {
  {bp_cpBoardId,                 .u.cp = "963268MBV"},
  {bp_cpComment,               .u.cp = g_obsoleteStr},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId6,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_last}
};

static bp_elem_t g_bcm963168mbv3[] = {
  {bp_cpBoardId ,              .u.cp = "963168MBV3"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_17_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_20 }, 
  // LDMode is set to NONE in case the board we are inheriting from set them
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_NONE},  
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  // IntAFELDClk uses dedicated pin
  // IntAFELDData uses dedicated pin
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_8_AL},
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_11_AH},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_13_AL},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

static bp_elem_t g_bcm963168PLC[] = {
  {bp_cpBoardId ,              .u.cp = "963168PLC"},
  {bp_ulGpioOverlay,           .u.ul = (BP_OVERLAY_PHY |
                                        BP_OVERLAY_SERIAL_LEDS |
                                        BP_OVERLAY_USB_LED |
                                        BP_OVERLAY_USB_DEVICE |
                                        BP_OVERLAY_HS_SPI_SSB7_EXT_CS)},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  // Set unused inherited settings to BP_GPIO_NONE
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_NONE},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  //ExtIntr Config
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_39_AH },
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_40_AH },
  //Switch-phy Config - Ephy/Gphy
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  //Switch-phy Config - PLC
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT_3P3V},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulPortMaxRate,           .u.ul = 400000000},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY | PORT_FLAG_SOFT_SWITCHING},
  //Switch-phy Config - MOCA LAN
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },       
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},       
  {bp_ucPhyDevName,            .u.cp = "moca%d"},        
  //PLC Config
  {bp_usGpioPLCReset,          .u.us = BP_GPIO_18_AL},
  //MoCA Config - LAN
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},         
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},       
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_41_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_1},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},        
#endif         
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_19_AL},        
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_NONE},         
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},        
  {bp_usSpiSlaveSelectNum,     .u.us = 7},         
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},         
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},         
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},        
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},        
  //Voip SPI overrides
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

static bp_elem_t g_bcm963168PLC_MOCAW[] = {
  {bp_cpBoardId ,              .u.cp = "963168PLC_MOCAW"},
  {bp_ulGpioOverlay,           .u.ul = (BP_OVERLAY_PHY |
                                        BP_OVERLAY_SERIAL_LEDS |
                                        BP_OVERLAY_USB_LED |
                                        BP_OVERLAY_USB_DEVICE |
                                        BP_OVERLAY_HS_SPI_SSB6_EXT_CS |
                                        BP_OVERLAY_HS_SPI_SSB7_EXT_CS)},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_10_AH},
  // Set unused inherited settings to BP_GPIO_NONE
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_NONE},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_NONE},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_NONE},
  //ExtIntr Config
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_39_AH },
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_40_AH },
  //Switch-phy Config - Ephy/Gphy
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  //Switch-phy Config - MOCA WAN
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },       
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},       
  {bp_ucPhyDevName,            .u.cp = "moca%d"},        
  //Switch-phy Config - MOCA LAN
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },       
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},       
  {bp_ucPhyDevName,            .u.cp = "moca%d"},        
  //MoCA Config - WAN
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},  //first MoCA always for WAN
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},       
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_42_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_13_AH },
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},        
#endif         
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_44_AL},        
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_NONE},         
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},        
  {bp_usSpiSlaveSelectNum,     .u.us = 6},         
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},         
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},         
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},        
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},        
  //MoCA Config - LAN
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},         
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},       
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_41_AH },
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_1},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},        
#endif         
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_19_AL},        
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_NONE},         
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},        
  {bp_usSpiSlaveSelectNum,     .u.us = 7},         
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},         
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},         
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},        
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},        
  //Voip SPI overrides
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168mbv_30a},
  {bp_last}
};

#if 0
/* Uncomment "#define BP_GET_INT_AFE_DEFINED" in Boardparams.h when these bp_ids are in used:
* bp_usGpioIntAFELDPwr
* bp_usGpioIntAFELDMode
* bp_usGpioAFELDRelay
*/

static bp_elem_t g_bcm963268mbv6b[] = {
  {bp_cpBoardId,               .u.cp = "963168MBV6b"},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18},
  {bp_ulPhyId6,                .u.ul = 0x19},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_12_21},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_13_AH},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_12_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioAFELDRelay,      .u.us = BP_GPIO_39_AH},
  {bp_last}
};
#endif

static bp_elem_t g_bcm963168vx[] = {
  {bp_cpBoardId,               .u.cp = "963168VX"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

static bp_elem_t g_bcm963168vx_p300[] = {
  {bp_cpBoardId,               .u.cp = "963168VX_P300"},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168vx}, 
  {bp_last}
};

static bp_elem_t g_bcm963168vx_p400[] = {
  {bp_cpBoardId,               .u.cp = "963168VX_P400"},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168vx_p300},
  {bp_last}
};

static bp_elem_t g_bcm963168vx_ext1p8[] = {
  {bp_cpBoardId,               .u.cp = "963168VX_ext1p8"},
  {bp_ucVreg1P8,               .u.uc = BP_VREG_EXTERNAL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168vx},
  {bp_last}
};

static bp_elem_t g_bcm963168xf[] = {
  {bp_cpBoardId,               .u.cp = "963168XF"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},  
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_14_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_15_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioFemtoReset,        .u.us = BP_GPIO_8_AH},  
  {bp_last}
};

static bp_elem_t g_bcm963268sv2_extswitch[] = {
  {bp_cpBoardId,               .u.cp = "963268SV2_EXTSW"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_HS_SPI_SSB7_EXT_CS)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_usEphyBaseAddress,       .u.us = 0x08},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_9},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_10},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_11},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPhyId5,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = 0x19 | MAC_IF_RGMII},  
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_22_AH},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 781000},
  {bp_usSpiSlaveProtoRev,      .u.us = 0},   
  {bp_last}
};

static bp_elem_t g_dg301r0[] = {
  {bp_cpBoardId,               .u.cp = "DG301R0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioOverlay,           .u.ul = (BP_OVERLAY_PHY | BP_OVERLAY_INET_LED | BP_OVERLAY_DG301 | BP_OVERLAY_USB_DEVICE)},
//  {bp_usGpioSerialLedClock,    .u.us = BP_GPIO_0_AL},
//  {bp_usGpioSerialLedData,     .u.us = BP_GPIO_1_AL},
//  {bp_usGpioSerialLedLoad,     .u.us = BP_GPIO_23_AL},
//  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
//  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
//  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
//  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
//  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
//  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
//  {bp_usGpioWirelessPowerDown, .u.us = BP_GPIO_36_AL},
//  {bp_usGpioWpsButton,         .u.us = BP_GPIO_22_AL},
//  {bp_usGpioDectButton,        .u.us = BP_GPIO_20_AL},
//  {bp_usGpioInfoButton,        .u.us = BP_GPIO_37_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xF8},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_17 | PHY_INTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 | PHY_INTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 |  MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 |  MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_last}
};

static bp_elem_t g_vg50r0[] = {
  {bp_cpBoardId,               .u.cp = "VG50_R"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_VG50 |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedMoCA,           .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_2_AL},
//  {bp_usGpioLedVoip,           .u.us = BP_SERIAL_GPIO_1_AL},
//  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_0_AL},

  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usGpioDectLed,           .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioLedGpon,           .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x57},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_7 | PHY_INTEGRATED_VALID | MAC_IF_RGMII | PHY_EXTERNAL},  // 63168 only support external giga phy on port4 and port6
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_5 | PHY_INTEGRATED_VALID | MAC_IF_RGMII | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_AVMODE_COMBO | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_13_AH},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_12_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_last}
};


static bp_elem_t g_cg300r0[] = {
  {bp_cpBoardId,               .u.cp = "CG300R0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioOverlay,           .u.ul = 0 },
//  {bp_usGpioSerialLedClock,    .u.us = BP_GPIO_0_AL},
//  {bp_usGpioSerialLedData,     .u.us = BP_GPIO_1_AL},
//  {bp_usGpioSerialLedLoad,     .u.us = BP_GPIO_23_AL},
//  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
//  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
//  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
//  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
//  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
//  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},

//  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_38_AH},
//  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_39_AH},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE

  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH}, // uncomment to enable second UART
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH}, // uncomment to enable second UART

  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x48},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 },
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_cg301r0[] = {
  {bp_cpBoardId,               .u.cp = "CG301R0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioOverlay,           .u.ul = BP_OVERLAY_USB_POWER},

  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH}, // uncomment to enable second UART
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH}, // uncomment to enable second UART
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE

  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x48},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 },
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_dg301alr0[] = {
  {bp_cpBoardId,               .u.cp = "DG301ALR0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioOverlay,           .u.ul = (BP_OVERLAY_PHY | BP_OVERLAY_INET_LED | BP_OVERLAY_DG301 |BP_OVERLAY_USB_DEVICE)},
//  {bp_usGpioSerialLedClock,    .u.us = BP_GPIO_0_AL},
//  {bp_usGpioSerialLedData,     .u.us = BP_GPIO_1_AL},
//  {bp_usGpioSerialLedLoad,     .u.us = BP_GPIO_23_AL},
//  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
//  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
//  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
//  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
//  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
//  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
//  {bp_usGpioWirelessPowerDown, .u.us = BP_GPIO_36_AL},
//  {bp_usGpioWpsButton,         .u.us = BP_GPIO_22_AL},
//  {bp_usGpioDectButton,        .u.us = BP_GPIO_20_AL},
//  {bp_usGpioInfoButton,        .u.us = BP_GPIO_37_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xF8},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_17 | PHY_INTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 | PHY_INTERNAL | PHY_INTEGRATED_VALID},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 |  MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 |  MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_last}
};

static bp_mdio_init_t g_phyinit_DisableEG300RDB[] = {
  { .u.write.op = BP_MDIO_INIT_OP_WRITE, .u.write.reg = 0x1e, .u.write.data = 0x0087},
  { .u.write.op = BP_MDIO_INIT_OP_WRITE, .u.write.reg = 0x1f, .u.write.data = 0x8000},
  { .u.write.op = BP_MDIO_INIT_OP_WRITE, .u.write.reg = 0x18, .u.write.data = 0xf1e7},
  { .u.write.op = BP_MDIO_INIT_OP_WRITE, .u.write.reg = 0x1c, .u.write.data = 0xfea8},
  { .u.write.op = BP_MDIO_INIT_OP_WRITE, .u.write.reg = 0x1c, .u.write.data = 0xB401}, /* yellow led on if speed 1GB*/
  { .u.op.op = BP_MDIO_INIT_OP_NULL}  /* end of list */
};

static bp_mdio_init_t g_phyinit_EG300_gtxclk_enable[] = {
  { .u.write.op = BP_MDIO_INIT_OP_WRITE, .u.write.reg = 0x1c, .u.write.data = 0x8e00},
  { .u.op.op = BP_MDIO_INIT_OP_NULL}  /* end of list */
};

static bp_elem_t g_eg300r0[] = {
  {bp_cpBoardId,               .u.cp = "EG300R0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_usGpioOverlay,           .u.ul =(BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED) },
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH},

  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xFE}, /* 0x67 */

  /* Switch port 3 is connected to an internal PHY (0x04), connected
     to a n external PHY (0x01) operating backwards, and an external
     PHY (0x1c) with both RJ45 and and SFP ports. The switch port
     should be associated with the outer PHY, so that we can link
     status and the like directly. */
  /* Internal phy, indirectly connected to the RJ45/SFP port */
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_4 },
  /* The backwards connected intermediate phy */
  {bp_ulPhyId2,                .u.ul = 0x1  | MAC_IF_RGMII_1P8V | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_pPhyInit,                .u.ptr = (void *)g_phyinit_EG300_gtxclk_enable},
  /* External phy for RJ45/SFP port */
  {bp_ulPhyId3,                .u.ul = 0x1c | MAC_IF_RGMII | PHY_EXTERNAL },
  {bp_ulPhyId4,                .u.ul = 0x0  | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_ulPhyId5,                .u.ul = 0x8  | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  /* Magic init to make the phy work */
  {bp_pPhyInit,                .u.ptr = (void *)g_phyinit_DisableEG300RDB},
  {bp_ulPhyId6,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_EXTERNAL },
  {bp_ulPhyId7,                .u.ul = 0x19 | MAC_IF_RGMII | PHY_EXTERNAL },
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_last}
};

static bp_elem_t g_dg351r0[] = {
  {bp_cpBoardId,               .u.cp = "DG351R0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY | 
                                       BP_OVERLAY_USB_DEVICE)},
//  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
//  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
//  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
//  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
//  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_10_AL},
//  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
//  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
//  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x48},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x1f},
//  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXBJ | BP_AFE_FE_REV_6302_REV_7_2_30},
//  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
//  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_13_AH},
//  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_12_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  
//  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},  
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_14_AL},
  {bp_usGpioWirelessPowerDown, .u.us = BP_GPIO_9_AL},
  {bp_last}
};

static bp_elem_t g_vox25[] = {
  {bp_cpBoardId,               .u.cp = "VOX25"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usGphyBaseAddress,       .u.us = 0x08}, // 5bit phy address for Gphy is b'01xxx now
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12 | PHY_INTEGRATED_VALID | PHY_INTERNAL },
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_last}
};

static bp_elem_t g_dg200r0[] = {
  {bp_cpBoardId,               .u.cp = "DG200R0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_POWER)},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usGphyBaseAddress,       .u.us = 0x08}, // 5bit phy address for Gphy is b'01xxx now
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12 | PHY_INTEGRATED_VALID | PHY_INTERNAL },
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},    //ext switch 53124s
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_dg200alr0[] = {
  {bp_cpBoardId,               .u.cp = "DG200ALR0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_POWER)},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usGphyBaseAddress,       .u.us = 0x08}, // 5bit phy address for Gphy is b'01xxx now
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12 | PHY_INTEGRATED_VALID | PHY_INTERNAL },
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},    //ext switch 53124s
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_eg200r0[] = {
  {bp_cpBoardId,               .u.cp = "EG200R0"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_POWER)},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usGphyBaseAddress,       .u.us = 0x08}, // 5bit phy address for Gphy is b'01xxx now
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12 | PHY_INTEGRATED_VALID | PHY_INTERNAL },
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},    //ext switch 53124s
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
  	
 };

static bp_elem_t g_bcm963268bu[] = {
  {bp_cpBoardId,               .u.cp = "963268BU"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_INET_LED |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  // {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xFC},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 },
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

static bp_elem_t g_bcm963268bu_p300[] = {
  {bp_cpBoardId,               .u.cp = "963268BU_P300"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_INET_LED |
                                       BP_OVERLAY_EPHY_LED_0 |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usEphyBaseAddress,       .u.us = 0x10},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xF9},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_17 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4 | PHY_INTERNAL | PHY_INTEGRATED_VALID },
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_0 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = BP_PHY_ID_1 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL },
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

static bp_elem_t g_bcm963168xh[] = {
  {bp_cpBoardId,               .u.cp = "963168XH"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_PCIE_CLKREQ |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x58},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPhyId6,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},  
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168xh5[] = {
    {bp_cpBoardId,               .u.cp = "963168XH5"},
    {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
    {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                      BP_OVERLAY_GPHY_LED_0|
                                      BP_OVERLAY_USB_DEVICE|
                                      BP_OVERLAY_USB_LED|
                                      BP_OVERLAY_PCIE_CLKREQ |
                                      BP_OVERLAY_HS_SPI_SSB5_EXT_CS)},
    {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
    {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
    {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
    {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
    {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_10_AL},
    {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
    {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
    {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
    {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
    {bp_usWirelessFlags,         .u.us = 0},
    {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ulPortMap,               .u.ul = 0x58},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
    {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
    {bp_ulPhyId6,                .u.ul = BP_PHY_ID_25 | MAC_IF_RGMII},
    {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
    {bp_ulPortMap,               .u.ul = 0x0f},
    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
    {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
    {bp_ucDspAddress,            .u.uc = 0},
    {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
    {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
    {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
    {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},  
    {bp_usSpiSlaveSelectNum,     .u.us = 4},
    {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
    {bp_usSpiSlaveSelectNum,     .u.us = 7},
    {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
    {bp_last}
};

  static bp_elem_t g_bcm963168xm[] = {
    {bp_cpBoardId,               .u.cp = "963168XM"},
    {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
    {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                         BP_OVERLAY_USB_DEVICE|
                                         BP_OVERLAY_PCIE_CLKREQ |
                                         BP_OVERLAY_HS_SPI_SSB5_EXT_CS)},
    {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
    {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
    {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
    {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
    {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_10_AL},
    {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
    {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
    {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
    {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
    {bp_usWirelessFlags,         .u.us = 0},
    {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ulPortMap,               .u.ul = 0x58},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
    {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
    {bp_ulPhyId6,                .u.ul = BP_PHY_ID_25},
    {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},// Remember to make MDIO HW changes(install resistors R540, R541 and R553) BP_ENET_CONFIG_HS_SPI_SSB_5},
    {bp_ulPortMap,               .u.ul = 0x0f},
    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_0 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
    {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
    {bp_ucDspAddress,            .u.uc = 0},
    {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
    {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
    {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_ISIL1556 | BP_AFE_FE_AVMODE_VDSL | BP_AFE_FE_REV_12_21 | BP_AFE_FE_ANNEXA },
    {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_11_AL},  
    {bp_last}
  };


  static bp_elem_t g_bcm963168mp[] = {
  {bp_cpBoardId,               .u.cp = "963168MP"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {  bp_usGpio_Intr,             .u.us = BP_GPIO_32_AL },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,      .u.ptr = (void*)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },  
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {  bp_usGpio_Intr,             .u.us = BP_GPIO_33_AL },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S },    
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1F},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_SOFT_SWITCHING},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

  static bp_elem_t g_bcm963268v30a[] = {
  {bp_cpBoardId,               .u.cp = "963268V30A"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
                                       BP_OVERLAY_PHY |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_SERIAL_LEDS )},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN}, // FIXME
  {bp_usWirelessFlags,         .u.us = 0}, // FIXME
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xD8},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x00 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId6,                .u.ul = 0x18 | MAC_IF_RGMII},
  {bp_ulPhyId7,                .u.ul = 0x19 | MAC_IF_RGMII},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_6306 | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_6302_6306_REV_A_12_40},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_9_AL},  
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 17},
  {bp_last}
};

  static bp_elem_t g_bcm963168media[] = {
  {bp_cpBoardId,               .u.cp = "963168MEDIA"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PCIE_CLKREQ |
                                       BP_OVERLAY_PHY |                                       
                                       BP_OVERLAY_SERIAL_LEDS )},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN}, // FIXME
  {bp_usWirelessFlags,         .u.us = 0}, // FIXME
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x5F},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL}, 
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH},        
  {bp_last}
};


static bp_elem_t g_bcm963268sv2[] = {
  {bp_cpBoardId,               .u.cp = "963268SV2"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE)},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV1},
  {bp_usGpioExtAFEReset,       .u.us = BP_GPIO_17_AL},
  {bp_last}
};

static bp_elem_t g_bcm963168xfg3[] = {
  {bp_cpBoardId,               .u.cp = "963168XFG3"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_DEVICE  |
                                       BP_OVERLAY_PHY         |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1F},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1}, 
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},  
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},         
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = MII_DIRECT},  
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioExtAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_11_AH},  
  {bp_usGpioFemtoReset,        .u.us = BP_GPIO_8_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_7_2_30}, 
  {bp_last}
};

static bp_elem_t g_bcm963269bhr[] = {
  {bp_cpBoardId,               .u.cp = "963269BHR"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB4_EXT_CS |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  //{bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_NONE},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_42_AH},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_41_AH},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},  //first MoCA always for WAN
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_43_AH},
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_45_AH},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_3},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_44_AH},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_40_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN}, // LAN
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_SHARED | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_0},
  {bp_usExtIntrMocaSBIntr0,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_1},
  {bp_usExtIntrMocaSBIntr1,    .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_39_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xd8},
  {bp_usGphyBaseAddress,       .u.us = 0x08},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPhyId6,                .u.ul = RGMII_DIRECT},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_1},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_last}
};

static bp_elem_t g_bcm963168ach5[] = {
  {bp_cpBoardId,               .u.cp = "963168ACH5"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_GPHY_LED_0 |
                                       BP_OVERLAY_HS_SPI_SSB5_EXT_CS |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x18},
  {bp_usGphyBaseAddress,       .u.us = 0x08},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_12},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_HS_SPI_SSB_5},
  {bp_ulPortMap,               .u.ul = 0x1e},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_1 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_2 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_3 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_4 | CONNECTED_TO_EXTERN_SW},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_11_AH},
  {bp_usGpioIntAFELDMode,      .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168ac5[] = {
  {bp_cpBoardId,               .u.cp = "963168AC5"},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_5},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963168ach5},
  {bp_last}
};

static bp_elem_t g_bcm963168xn5[] = {
  {bp_cpBoardId,               .u.cp = "963168XN5"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_PHY |
                                       BP_OVERLAY_SERIAL_LEDS |
                                       BP_OVERLAY_USB_LED |
                                       BP_OVERLAY_USB_DEVICE |
                                       BP_OVERLAY_PCIE_CLKREQ)},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_13_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1},
  {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},
  {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_24 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_PIN_DSL_CTRL_5},
  {bp_usGpioIntAFELDMode,      .u.us = BP_PIN_DSL_CTRL_4},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

static bp_elem_t g_bcm963168xm5[] = {
    {bp_cpBoardId,               .u.cp = "963168XM5"},
    {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC},
    {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                         BP_OVERLAY_USB_DEVICE  |
                                         BP_OVERLAY_USB_LED     |
                                         BP_OVERLAY_EPHY_LED_0  |
                                         BP_OVERLAY_EPHY_LED_1  |
                                         BP_OVERLAY_EPHY_LED_2  |
                                         BP_OVERLAY_GPHY_LED_0  |
                                         BP_OVERLAY_PCIE_CLKREQ )},
    {bp_usGpioLedAdsl,           .u.us = BP_GPIO_20_AL},
    {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
    {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
    {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
    {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_18_AL},
    {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_3_AL},
    {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
    {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
    {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
    {bp_usWirelessFlags,         .u.us = 0},
    {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_ucPhyAddress,            .u.uc = 0x0},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ulPortMap,               .u.ul = 0x1f},
    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_1},
    {bp_ulPhyId1,                .u.ul = BP_PHY_ID_2},
    {bp_ulPhyId2,                .u.ul = BP_PHY_ID_3},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_4},
    {bp_ulPhyId4,                .u.ul = 0x18 | PHY_INTEGRATED_VALID | PHY_EXTERNAL | MAC_IF_RGMII},
    {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
    {bp_ucDspAddress,            .u.uc = 0},
    {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
    {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
    {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6301 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6301_REV_5_1_4},
    {bp_last}
};

static bp_elem_t g_bcm963168xm5_6302[] = {
    {bp_cpBoardId,               .u.cp = "963168XM5_6302"},
    {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_AVMODE_ADSL | BP_AFE_FE_REV_6302_REV_5_2_3},
    {bp_elemTemplate,            .u.bp_elemp = g_bcm963168xm5},
    {bp_last}
};

static bp_elem_t g_bcm963168wfar[] = {
  {bp_cpBoardId,               .u.cp = "963168WFAR"},
  {bp_ulDeviceOptions,         .u.ul = BP_DEVICE_OPTION_ENABLE_GMAC | BP_DEVICE_OPTION_DISABLE_LED_INVERSION},
  {bp_ulGpioOverlay,           .u.ul =(BP_OVERLAY_SERIAL_LEDS |
                                        BP_OVERLAY_GPHY_LED_0 |
                                        BP_OVERLAY_PCIE_CLKREQ )},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_20_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_21_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0}, 
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x08},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_INT | BP_AFE_LD_6302 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6302_REV_7_2_30},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 16},
  {bp_usSpiSlaveSelectNum,     .u.us = 7},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 9},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_dg301r0, g_vg50r0, g_cg300r0, g_cg301r0, g_dg301alr0, g_eg200r0, g_eg300r0, g_dg351r0, g_vox25, g_dg200r0, g_dg200alr0, g_bcm963268sv1, g_bcm963268mbv, g_bcm963168vx, g_bcm963168vx_p300, g_bcm963268bu, g_bcm963268bu_p300,
		g_bcm963268sv2_extswitch, g_bcm963168mbv_17a, g_bcm963168mbv_30a, g_bcm963168xh, g_bcm963168xh5, g_bcm963168mp, g_bcm963268v30a,
		g_bcm963168media, g_bcm963268sv2, g_bcm963168xfg3, g_bcm963168xf, g_bcm963168xm, g_bcm963168mbv3, g_bcm963168mbv17a302, g_bcm963168mbv30a302,
		g_bcm963168vx_p400, g_bcm963168vx_ext1p8, g_bcm963269bhr, g_bcm963168ach5, g_bcm963168ac5, g_bcm963168xn5, g_bcm963168xm5, g_bcm963168xm5_6302, g_bcm963168wfar, g_bcm963167ref1, g_bcm963167ref3, g_bcm963167ref2,
      g_bcm963168PLC, g_bcm963168PLC_MOCAW, 0};

#endif

#if defined(_BCM960333_) || defined(CONFIG_BCM960333)

static char g_obsoleteStr[] = "(obsolete)";

static bp_elem_t g_bcm960333plc_dut[] = {
  {bp_cpBoardId,               .u.cp = "960333PLC_DUT"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_5_AH},

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},
  {bp_ulPortMap,               .u.ul = 0x07},
  {bp_ulPhyId0,                .u.ul = 0},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_EXT_PHY},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_ulPhyId1,                .u.ul = 1},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_INT_PHY},
  {bp_ucPhyDevName,            .u.cp = "eth1"},
  {bp_ulPhyId2,                .u.ul = 2},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc0"},

  {bp_last}
};

static bp_elem_t g_bcm960333plc_ref[] = {
  {bp_cpBoardId,               .u.cp = "960333PLC_REF"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_5_AH},

  /* NOTE: This is the only option for this signal.
   *       power LED is driven by AON and is not assigned to any GPIO */
  {bp_usGpioLedBlPowerOn,          .u.us = BP_PIN_AON_POWER},

  /*
   * ON and OFF time values for Power LED blinking (in ms).
   * If undefined, the Power LED will stay solid ON.
   */
  /*
  {bp_ulLedBlPowerOnBlinkTimeOn,   .u.ul = 350},
  {bp_ulLedBlPowerOnBlinkTimeOff,  .u.ul = 650},
  */

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = 1},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_INT_PHY},
  {bp_ucPhyDevName,            .u.cp = "eth0"},
  {bp_usGpioLedLan,            .u.us = BP_GPIO_6_AH},
  {bp_ulPhyId1,                .u.ul = 2},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc0"},
  {bp_last}
};

static bp_elem_t g_bcm960500wifi_obsolete[] = {
  {bp_cpBoardId,               .u.cp = "960500PLC_WIFI"},
  {bp_cpComment,               .u.cp = g_obsoleteStr},  

  // buttons for 201
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL },
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,       .u.ptr = (void*)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,          .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};

static bp_elem_t g_bcm960500wifi[] = {
  {bp_cpBoardId,               .u.cp = "960500WIFI"}, // works for P104 or P201
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL },
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_2 | BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL },
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AH},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ptr = (void*)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usButtonIdx,             .u.us = 2},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_0_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ptr = (void*)"Button 2 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },    
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};

static bp_elem_t g_bcm960500wifi_ubus167[] = {
  {bp_cpBoardId,               .u.cp = "960500_UBUS167"},  // reduced list for P201

  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_11_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ptr = (void*)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};


static bp_elem_t g_bcm960500wifi_p201[] = {
  {bp_cpBoardId,               .u.cp = "960500WIFI_P201"},  // reduced list for P201

  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_1_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PLC_UKE | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_0_AL},
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,    .u.ptr = (void*)"Button 1 Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,        .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S },
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 1 },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm960333plc_ref},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm960333plc_dut, g_bcm960333plc_ref, g_bcm960500wifi_obsolete, g_bcm960500wifi, g_bcm960500wifi_ubus167, g_bcm960500wifi_p201, 0};
#endif

#if defined(_BCM947189_) || defined(CONFIG_BCM947189)
static bp_elem_t g_bcm947189ref[] = {
  /* Unmanaged switch in RGMII 0 */
  {bp_cpBoardId,               .u.cp = "947189REF"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},
    {bp_ulPortMap,             .u.ul = 0x1},
    {bp_ucPhyAddress,          .u.uc = 0x1e},
    /* Only one port definition: unmanaged switch */
    {bp_ulPhyId0,              .u.ul = 0x1e | MAC_IF_RGMII},
      {bp_usPhyConnType,       .u.us = PHY_CONN_TYPE_EXT_SW},
      {bp_ucPhyDevName,        .u.cp = "eth0"},
      {bp_usGpioPhyReset,      .u.us = 0x02},
  {bp_last}
};

static bp_elem_t g_bcm947189ref2[] = {
  /* GPHY in RGMII 0, PLC in RGMII 1 */
  {bp_cpBoardId,               .u.cp = "947189REF2"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY},
    {bp_ulPortMap,             .u.ul = 0x3},
    {bp_ulPhyId0,              .u.ul = 25 | MAC_IF_RGMII},
      {bp_usPhyConnType,       .u.us = PHY_CONN_TYPE_EXT_PHY},
      {bp_ucPhyDevName,        .u.cp = "eth0"},
      {bp_usGpioPhyReset,      .u.us = 0x02},
    {bp_ulPhyId1,              .u.ul = BP_PHY_ID_2 | MAC_IF_RGMII},
      {bp_usPhyConnType,       .u.us = PHY_CONN_TYPE_PLC},
      {bp_ucPhyDevName,        .u.cp = "plc0"},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm947189ref, g_bcm947189ref2, 0};
#endif

#if defined(_BCM963138_) || defined(CONFIG_BCM963138)

/* Only needed for internal GPHYs; by default internal GPHYs do not adv. 1000HD/100HD/10FD/10HD capabilities;
 * There are some NICs that will not negotiate 100FD - so need to advertise 100HD to link up with those NICs */
#define BCM963138_PHY_BASE             0x8

#if 1
static bp_elem_t g_bcm963138sv[] = {
  {bp_cpBoardId,               .u.cp = "963138SV"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH}, // uart2 is /dev/ttyS1
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH}, // stty 115200 < /dev/ttyS1 to set speed
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH}, 
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},                              
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_last}
};
#endif

static bp_elem_t  g_F104W[] = {
  {bp_cpBoardId,               .u.cp = "F104W"},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset
  {bp_usGpioReserved,          .u.us = BP_GPIO_33_AL},  // button wps
  {bp_usGpioReserved,          .u.us = BP_GPIO_31_AL},  // LED G.FAST link
  {bp_usGpioReserved,          .u.us = BP_GPIO_58_AL},  // LED G.FAST fail
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},  // LED G.FAST activity
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST | BP_AFE_LD_6303 |BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_14_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner // switch 0
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ucPhyAddress,            .u.uc = 0x1e},
#if defined (USE_RUNNER)
    {bp_ulPortMap,               .u.ul = 0x3},
#else
    {bp_ulPortMap,               .u.ul = 0x2},
#endif

    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
#if defined (USE_RUNNER)
        {bp_ulCrossbar,              .u.ul = 13},
        {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
        {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
        {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},
#else   // Dummy config goes nowhere and is not in portmap, not sure its needed.
        {bp_ulCrossbar,              .u.ul = 9},
        {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
#endif
      {bp_ulPhyId1,                     .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
        {bp_ulPortFlags,                .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch

  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},  // switch 1
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},    // Accessing SF2 as MMapped external switch
#if defined (USE_RUNNER)
    {bp_ulPortMap,               .u.ul = 0x7},
#else
    {bp_ulPortMap,               .u.ul = 0xf},
#endif
    {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
       {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
       {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},
    {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
       {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
       {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},
    {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
       {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
       {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},
       {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
#if  !defined (USE_RUNNER)
     {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
        {bp_ulCrossbar,              .u.ul = 13},
        {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
        {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
        {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16| BP_DDR_TEMP_EXTENDED_SRT},
  {bp_last}
};

static bp_elem_t  g_F104[] = {
  {bp_cpBoardId,               .u.cp = "F104"},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset
  {bp_usGpioReserved,          .u.us = BP_GPIO_33_AL},  // button wps
  {bp_usGpioReserved,          .u.us = BP_GPIO_31_AL},  // LED G.FAST link
  {bp_usGpioReserved,          .u.us = BP_GPIO_58_AL},  // LED G.FAST fail
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},  // LED G.FAST activity
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST | BP_AFE_LD_6303 |BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_14_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner // switch 0
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ucPhyAddress,            .u.uc = 0x1e},
#if defined (USE_RUNNER)
    {bp_ulPortMap,               .u.ul = 0x3},
#else
    {bp_ulPortMap,               .u.ul = 0x2},
#endif

    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
#if defined (USE_RUNNER)
        {bp_ulCrossbar,              .u.ul = 13},
        {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
        {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
        {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},
#else   // Dummy config goes nowhere and is not in portmap, not sure its needed.
        {bp_ulCrossbar,              .u.ul = 9},
        {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
#endif
      {bp_ulPhyId1,                     .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
        {bp_ulPortFlags,                .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch

  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},  // switch 1
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},    // Accessing SF2 as MMapped external switch
#if defined (USE_RUNNER)
    {bp_ulPortMap,               .u.ul = 0x7},
#else
    {bp_ulPortMap,               .u.ul = 0xf},
#endif
    {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
       {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
       {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},
    {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
       {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
       {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},
    {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
       {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
       {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},
       {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
#if  !defined (USE_RUNNER)
     {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
        {bp_ulCrossbar,              .u.ul = 13},
        {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
        {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
        {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16| BP_DDR_TEMP_EXTENDED_SRT},
  {bp_last}
};

static bp_elem_t g_DG400R0[] = {
  {bp_cpBoardId,               .u.cp = "DG400R0"},
	{bp_usGpioReserved,          .u.us = BP_GPIO_0_AH}, //Sercomm LED CLK inverted pins, need to handle SH part manually
	{bp_usGpioReserved,          .u.us = BP_GPIO_1_AH}, //Sercomm LED DAT inverted pins, need to handle SH part manually
	{bp_usGpioReserved,          .u.us = BP_GPIO_2_AH}, //Sercomm LED Mask inverted pins, need to handle SH part manually
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for voip
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for voip
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_10_AH},  // placeholder for voip
	{bp_usGpioReserved,          .u.us = BP_GPIO_27_AH}, //Sercomm GPIO Status LED green
	{bp_usGpioReserved,          .u.us = BP_GPIO_28_AH}, //Sercomm GPIO Status LED red
	{bp_usGpioReserved,          .u.us = BP_GPIO_16_AH}, //Sercomm PWM LED control
	//{bp_usGpioReserved,          .u.us = BP_GPIO_33_AL}, //Sercomm SX9512 reset
	{bp_usGpioReserved,          .u.us = BP_GPIO_36_AL}, //Sercomm SX9512 interrupt
	{bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, //Sercomm SX9512 I2C SDA
	{bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH }, //Sercomm SX9512 I2C SCL

  {bp_usGpioReserved,          .u.us = BP_GPIO_108_AL},   // GPHY4_SPD0 (wan_phy_green)
  {bp_usGpioReserved,          .u.us = BP_GPIO_109_AL},   // GPHY4_SPD1 (wan_phy_yellow)
  {bp_usGpioReserved,          .u.us = BP_GPIO_116_AH},   // Eth_LED_CTL
  {bp_usGpioReserved,          .u.us = BP_GPIO_118_AH},   // DECT_Control

  {bp_usGpioDectRst,           .u.us = BP_GPIO_3_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
//  {bp_usSpeedLed100,           .u.us = BP_GPIO_108_AL},   // Should have been GPIO 08 or 26 for hw control
//  {bp_usSpeedLed1000,          .u.us = BP_GPIO_109_AL},   // Should have been GPIO 09 or 27 for hw control
//  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_100_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_101_AL},
//  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_102_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_103_AL},
 // {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_104_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_105_AL},
 // {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_106_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_107_AL},
//  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  //{bp_ulPhyId5,                .u.ul = 0x0  | MAC_IF_RGMII },
  //{bp_ulPhyId7,                .u.ul = 0x19 | MAC_IF_RGMII },
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB | BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TEMP_EXTENDED_SRT},
  {bp_last}
};

static bp_elem_t g_DG400PRIME[] = {
  {bp_cpBoardId,               .u.cp = "DG400PRIMER0"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot

  {bp_usGpioReserved,          .u.us = BP_GPIO_133_AH}, // USB0_PWRON USB3.0
  {bp_usGpioReserved,          .u.us = BP_GPIO_135_AH}, // USB1_PWRON USB2.0 (side)

  {bp_usGpioDectRst,           .u.us = BP_GPIO_3_AL},   // DECT_RESET_B
  {bp_usGpioReserved,          .u.us = BP_GPIO_118_AH}, // DECT_Control

  {bp_usGpioReserved,          .u.us = BP_GPIO_33_AL},  // button wifi
  {bp_usGpioReserved,          .u.us = BP_GPIO_34_AL},  // button wps
  {bp_usGpioReserved,          .u.us = BP_GPIO_35_AL},  // button dect

  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH},

  {bp_usGpioReserved,          .u.us = BP_GPIO_76_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_77_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_78_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_79_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_80_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_81_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_82_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_83_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_84_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_85_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_86_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_87_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_88_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_89_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_90_AL}, // LED
  {bp_usGpioReserved,          .u.us = BP_GPIO_91_AL}, // LED

  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_NONE},

  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
//  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  // GPIO_33 + NAND_D1
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH }, // AE_LOS from PCIE

  {bp_usGpioReserved,          .u.us = BP_GPIO_24_AH }, // I2C SDA and sgmii fiber detect seletion for serder interface
  {bp_usGpioReserved,          .u.us = BP_GPIO_25_AH }, // I2C SCL

  {bp_usGpioI2cSda,            .u.us = BP_GPIO_52_AH }, // SX9512 I2C SDA
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_53_AH }, // SX9512 I2C SCL
//  {bp_usGpioReserved,          .u.us = BP_GPIO_54_AL},  // SX9512 interrupt



  {bp_usSpiSlaveSelectNum,     .u.us = 1},   // FXO1
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},   // FXO2
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},   // FXO3
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},

  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
    {bp_usConfigType,          .u.us = BP_ENET_CONFIG_MMAP},
    {bp_ucPhyAddress,          .u.uc = 0x1e},
    {bp_ulPortMap,             .u.ul = 0x3},

    {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
      {bp_ulCrossbar,          .u.ul = 9},
        {bp_ulCrossbarPhyId,   .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},

      {bp_ulCrossbar,              .u.ul = 10},
        {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
        {bp_usSpeedLed100,           .u.us = BP_GPIO_8_AL},   // indicate 1000bps led
        {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},

  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
      {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch

  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
    {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
    {bp_ulPortMap,               .u.ul = 0x0f},
    {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
      {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
      {bp_usLinkLed,               .u.us = BP_GPIO_10_AL},
    {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
      {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
      {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
    {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
      {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
      {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
    {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
      {bp_ulCrossbar,              .u.ul = 13},
      {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
      {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
      {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},

  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB | BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TEMP_EXTENDED_SRT},
  {bp_last}
};

static bp_elem_t g_EG400R0[] = {
  {bp_cpBoardId,               .u.cp = "EG400R0"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot

  {bp_usGpioReserved,          .u.us = BP_GPIO_133_AH}, // USB0_PWRON USB3.0
  {bp_usGpioReserved,          .u.us = BP_GPIO_135_AH}, // USB1_PWRON USB2.0 (side)

  {bp_usGpioDectRst,           .u.us = BP_GPIO_3_AL},   // DECT_RESET_B
  {bp_usGpioReserved,          .u.us = BP_GPIO_118_AH}, // DECT_Control
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_22_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_23_AH},

  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL},  // pinmux for PWM2 LED (?)

  {bp_usGpioReserved,          .u.us = BP_GPIO_19_AL},  // EXT_GREEN !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_20_AL},  // WIFI_GREEN !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_21_AL},  // WIFI_BLUE !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_107_AL}, // STATUS_RED !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_106_AL}, // STATUS_GREEN !?

  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  // GPIO_33 + NAND_D1 !?
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH }, // AE_LOS from PCIE

  {bp_usGpioReserved,          .u.us = BP_GPIO_24_AH }, // I2C SDA and sgmii fiber detect seletion for serder interface
  {bp_usGpioReserved,          .u.us = BP_GPIO_25_AH }, // I2C SCL

  {bp_usGpioI2cSda,            .u.us = BP_GPIO_52_AH }, // SX9512 I2C SDA
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_53_AH }, // SX9512 I2C SCL
  {bp_usGpioReserved,          .u.us = BP_GPIO_54_AL},  // SX9512 interrupt

  {bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_NONE},

  {bp_usSpiSlaveSelectNum,     .u.us = 1},   // FXO1
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},   // FXO2
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},   // FXO3
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},

  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
 /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_8_AL},   // indicate 1000bps led
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},

  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB | BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TEMP_EXTENDED_SRT},
  {bp_last}
};

static bp_elem_t g_SDX810_RGR0[] = {
  {bp_cpBoardId,               .u.cp = "SDX810_RGR0"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot

  {bp_usGpioReserved,          .u.us = BP_GPIO_133_AH}, // USB0_PWRON USB3.0
  {bp_usGpioReserved,          .u.us = BP_GPIO_135_AH}, // USB1_PWRON USB2.0 (side)

  {bp_usGpioDectRst,           .u.us = BP_GPIO_3_AL},   // DECT_RESET_B
  {bp_usGpioReserved,          .u.us = BP_GPIO_118_AH}, // DECT_Control
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_22_AH},
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_23_AH},

  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL},  // pinmux for PWM2 LED (?)

  {bp_usGpioReserved,          .u.us = BP_GPIO_19_AL},  // EXT_GREEN !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_20_AL},  // WIFI_GREEN !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_21_AL},  // WIFI_BLUE !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_107_AL}, // STATUS_RED !?
  {bp_usGpioReserved,          .u.us = BP_GPIO_106_AL}, // STATUS_GREEN !?

  {bp_usGpioReserved,          .u.us = BP_GPIO_32_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},  // GPIO_33 + NAND_D1 !?
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_36_AH }, // AE_LOS from PCIE

  {bp_usGpioReserved,          .u.us = BP_GPIO_24_AH }, // I2C SDA and sgmii fiber detect seletion for serder interface
  {bp_usGpioReserved,          .u.us = BP_GPIO_25_AH }, // I2C SCL

  {bp_usGpioI2cSda,            .u.us = BP_GPIO_52_AH }, // SX9512 I2C SDA
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_53_AH }, // SX9512 I2C SCL
  {bp_usGpioReserved,          .u.us = BP_GPIO_54_AL},  // SX9512 interrupt

  {bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_NONE},

  {bp_usSpiSlaveSelectNum,     .u.us = 1},   // FXO1
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},   // FXO2
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},   // FXO3
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},

  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
 /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_8_AL},   // indicate 1000bps led
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},

  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB | BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TEMP_EXTENDED_SRT},
  {bp_last}
};

#if 1

static bp_elem_t g_bcm963138dvt[] = {
  {bp_cpBoardId,               .u.cp = "963138DVT"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_18_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_20_AL}, // LED register bit 20, shifted serially
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
                                              // to avoid conflicting P0 and P11 phy address of 1
                                              // the intergrated Quad GPHY address is now 0x8, 0x9, 0xa, 0xb
                                              // the intergrated Single GPHY address 0xc
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138dvt_p300[] = {
  {bp_cpBoardId,               .u.cp = "963138DVT_P300"},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_27_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH}, 
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},   
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138dvt},
  {bp_last}
};


static bp_elem_t g_bcm963138ref_bmu[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_BMU"},
  {bp_usBatteryEnable,         .u.us = 1},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_22_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioAFEVR5P3PwrEn,     .u.us = BP_GPIO_37_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usVregSync,              .u.us = BP_GPIO_18_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x4) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_29_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_30_AL},
  {bp_usGpioDectLed,           .u.us = BP_GPIO_31_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138bmu_p202[] = {
  {bp_cpBoardId,               .u.cp = "963138BMU_P202"},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_bmu},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_lte[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_LTE"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3}, 
  {bp_usGpioLteReset,          .u.us = BP_GPIO_116_AH}, 
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH}, 
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_25_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x2f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /*{bp_usSpeedLed100,           .u.us = BP_GPIO_22_AL},*/ //GPIO22 not supported for speed LED in b0
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_23_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_24_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT}, // RGMII1 to MAC port in LTE chip
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_18_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_17_AL},
  {bp_usTsync1pps,             .u.us = BP_GPIO_4_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138lte_p302[] = {
  {bp_cpBoardId,               .u.cp = "963138LTE_P302"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGpioLteReset,          .u.us = BP_GPIO_3_AH},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x2f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_24_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId5,                .u.ul = RGMII_DIRECT}, // RGMII1 to MAC port in LTE chip
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_lte},
  {bp_last}
};

static bp_elem_t g_bcm963138lte2[] = {
  {bp_cpBoardId,               .u.cp = "963138LTE2"},
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_20_AH}, 
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_21_AH},
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_21_AL},
  {bp_usGpioSecLedAdslFail,    .u.us = BP_SERIAL_GPIO_22_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138lte_p302},
  {bp_last}
};

/* for B0 chip */
static bp_elem_t g_bcm963138ref_p402[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_P402"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for SF2 Port4 SPD1
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_25_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};


static bp_elem_t g_bcm963138ref_gfast[] = {
  {bp_cpBoardId,               .u.cp = "963138_GFAST"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_26_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_27_AL},  
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_14_AL},  
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};


static bp_elem_t g_bcm963138bg_gfast[] = {
  {bp_cpBoardId,               .u.cp = "963138BG_GFAST"},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_28_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x2},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x10},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_usVregSync,              .u.us = BP_GPIO_37_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_gfast_p40x[] = {
  {bp_cpBoardId,               .u.cp = "963138GFP40X"},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
 /* use the WAN LED from runner */
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_3_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_gfast},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_gfast_p40x_mem[] = {
  {bp_cpBoardId,               .u.cp = "138GFAST4G"},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_gfast_p40x},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_gfast_2[] = {
  {bp_cpBoardId,               .u.cp = "963138GFAST2"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_15_AH},
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_16_AH},
  {bp_usGpioSecLedWanData,     .u.us = BP_SERIAL_GPIO_19_AH},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_18_AH},
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_usGpioLedReserved,    .u.us = BP_SERIAL_GPIO_20_AH},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_17_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_8_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_9_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_14_AH},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_100_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_101_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_102_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_103_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_104_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_105_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_13_AH},
  {bp_usGpioAFELDRelay,	       .u.us = BP_GPIO_3_AH},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_116_AL | BP_LED_USE_GPIO },
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_118_AL | BP_LED_USE_GPIO },
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_usVregSync,              .u.us = BP_GPIO_37_AH},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};


static bp_elem_t g_bcm963138ref_gfast_4[] = {
  {bp_cpBoardId,               .u.cp = "963138GFAST4"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_gfast_2},
};

/* for B0 chip */
static bp_elem_t g_bcm963138ref_p502[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_P502"},
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH},
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},
  {bp_usGpioBtWake,            .u.us = BP_GPIO_116_AH},
  {bp_usGpioBtReset,           .u.us = BP_GPIO_118_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_25_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p402},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p802[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_P802"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_IRQ | BP_EXT_INTR_5},
  {bp_usGpioSfpDetect,         .u.us = BP_GPIO_109_AH},
  {bp_usExtIntrNfc,            .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_5},
  {bp_usGpioNfcWake,           .u.ul = BP_GPIO_7_AH},
  {bp_usGpioNfcPower,          .u.ul = BP_GPIO_8_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p502_plc[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_PLC"},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT_3P3V },
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p502_moca[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_MOCA"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x2},
//  {bp_ulPortMap,               .u.ul = 0x3},
//  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
//  	{bp_ucPhyDevName,            .u.cp = "moca%d"},
//  	{bp_ulCrossbar,              .u.ul = 12},
//  	{bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
//  	{bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
//  	/* use the WAN LED from runner */
//  	{bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
//  	{bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
//  	{bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  	{bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch

  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
	  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
	  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
	  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
	  {bp_ulCrossbar,              .u.ul = 13},
	  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
	  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
	  {bp_ucPhyDevName,            .u.cp = "moca%d"},
	  {bp_ulCrossbar,              .u.ul = 12},
	  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
	  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
	  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
	  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
	  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
	  /* use the WAN LED from runner */
//	  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
//	  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
//	  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
#if !defined(_CFE_)
	  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
	  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_115_AL},
	  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_60_AL},
	  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
	  {bp_usSpiSlaveSelectNum,     .u.us = 2},
	  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
	  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
	  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
	  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_p502_bhr[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_BHR"},
 
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  	{bp_ucPhyDevName,            .u.cp = "moca%d"},
  	{bp_ulCrossbar,              .u.ul = 12},
  	{bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  	{bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  	/* use the WAN LED from runner */
  	{bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  	{bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  	{bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  	{bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch

  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
	  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
	  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
	  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
	  {bp_ulCrossbar,              .u.ul = 13},
	  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
	  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
	  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
	  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
	  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
	  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_115_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_60_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_14_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_rnc[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_RNC"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3}, 
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_usGpioLteReset,          .u.us = BP_GPIO_110_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usVregSync,              .u.us = BP_GPIO_37_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  /* BT Uart */
  {bp_usGpioUart2Cts,          .u.ul = BP_GPIO_3_AH},
  {bp_usGpioUart2Rts,          .u.ul = BP_GPIO_4_AH},
  {bp_usGpioUart2Sdin,         .u.ul = BP_GPIO_5_AH},
  {bp_usGpioUart2Sdout,        .u.ul = BP_GPIO_6_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_rncp400[] = {
  {bp_cpBoardId,               .u.cp = "138REFrncP400"},
  {bp_usGpioReserved,          .u.us = BP_GPIO_17_AL},
  {bp_usGpioReserved,          .u.us = BP_GPIO_110_AL},
  {bp_usGpioBtWake,            .u.us = BP_GPIO_116_AH},
  {bp_usGpioBtReset,           .u.us = BP_GPIO_118_AH},
  {bp_usNtrRefIn,              .u.us = BP_GPIO_25_AL},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH},
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_rnc},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_bgw[] = {
  {bp_cpBoardId,               .u.cp = "963138REF_BGW"},
  {bp_usVregSync,              .u.us = BP_GPIO_18_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3}, 
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_26_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_16_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_29_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_30_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963138rref_gfast[] = {
  {bp_cpBoardId,               .u.cp = "63138RREF_GFAST"},
  {bp_usGpioAFELDRelay,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioAFELDPwrBoost,     .u.us = BP_GPIO_25_AH},
  {bp_usVregSync,              .u.us = BP_GPIO_18_AH},
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_26_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_GFAST_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  /* use the WAN LED from runner */
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xaf},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId5,                .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId7,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_16_AL},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_29_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_30_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_last}
};

static bp_elem_t g_bcm963138rref_rnc[] = {
  {bp_cpBoardId,               .u.cp = "63138RREF_RNC"},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40|BP_AFE_FE_RNC },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40|BP_AFE_FE_RNC },
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138rref_gfast},
  {bp_last}
};

/* single moca (lan) using p200 daughter card */
static bp_elem_t g_bcm963138ref_p502_moca_p200[] = {
  {bp_cpBoardId,               .u.cp = "963138P502_M200"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_13_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502_moca},
  {bp_last}
};

/* dual moca using p200 daughter cards */
static bp_elem_t g_bcm963138ref_p502_dual_moca_p200[] = {
  {bp_cpBoardId,               .u.cp = "138P502_DM200"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_115_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_61_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_13_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502_bhr},
  {bp_last}
};

static bp_elem_t g_bcm963138ref_3wlan[] = {
  {bp_cpBoardId,               .u.cp = "138REF_3WLAN"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  // {bp_usGpioLedReserved,       .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  // {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for SF2 Port4 SPD0
  // {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for SF2 Port4 SPD1
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_25_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usGphyBaseAddress,       .u.us = BCM963138_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_26_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_27_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_14_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963138_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963138_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963138_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 13},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963138_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963132ref_test[] = {
  {bp_cpBoardId,               .u.cp = "132REF_TEST"},
  {bp_ulMaxNumCpu,             .u.ul = 1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p802},
  {bp_last}
};

static bp_elem_t g_bcm963132ref_138_p502[] = {
  {bp_cpBoardId,               .u.cp = "132_138REF_P502"},
  {bp_ulMaxNumCpu,             .u.ul = 1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_p502},
  {bp_last}
};

static bp_elem_t g_bcm963132ref_138gfast2[] = {
  {bp_cpBoardId,               .u.cp = "132_138GFAST2"},
  {bp_ulMaxNumCpu,             .u.ul = 1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963138ref_gfast_2},
  {bp_last}
};

#endif

bp_elem_t * g_BoardParms[] = {g_bcm963138sv, g_bcm963138dvt, g_bcm963138ref_gfast_p40x, g_bcm963138ref_gfast_2,  g_bcm963138ref_gfast_p40x_mem, g_bcm963138ref_gfast_4,
g_bcm963138bg_gfast, g_bcm963138ref_p502, g_bcm963138ref_p802, g_bcm963138bmu_p202, g_bcm963138lte_p302, g_bcm963138lte2, g_bcm963138ref_p502_plc, g_bcm963138ref_p502_moca,
    g_bcm963138ref_p502_bhr, g_bcm963138dvt_p300, g_bcm963138ref_rnc, g_DG400R0, g_DG400PRIME, g_EG400R0, g_SDX810_RGR0, g_F104W, g_F104, g_bcm963138ref_rncp400, g_bcm963138ref_p502_moca_p200, g_bcm963138ref_p502_dual_moca_p200, g_bcm963138ref_3wlan, g_bcm963138ref_bgw, g_bcm963138rref_gfast, g_bcm963138rref_rnc,g_bcm963132ref_test, g_bcm963132ref_138_p502, g_bcm963132ref_138gfast2, 0};
#endif

#if defined(_BCM963381_) || defined(CONFIG_BCM963381)
static bp_elem_t g_bcm963381sv[] = {
  {bp_cpBoardId,               .u.cp = "963381SV"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 18},
  /*{bp_usGpioLedAdsl,           .u.us = BP_GPIO_10_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_12_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_8_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_9_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_11_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},*/
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x19 | MAC_IF_RGMII_1P8V | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },    
  {bp_last}
};

static bp_elem_t g_bcm963381dvt[] = {
  {bp_cpBoardId,               .u.cp = "963381DVT"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usSerialLedClk,          .u.us = BP_GPIO_16_AH},
  {bp_usSerialLedData,         .u.us = BP_GPIO_17_AH}, 
  {bp_usSerialLedMask,         .u.us = BP_GPIO_24_AH},
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_15_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_13_AL},/*does not work in A0*/
  {bp_usGpioLedWanError,       .u.us = BP_SERIAL_GPIO_14_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_SERIAL_GPIO_16_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 19},
  {bp_usSpiSlaveSelectNum,     .u.us = 2}, /* needed in case a SPI device is plugged  into J504 */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 18},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_5_AL}, /* these link/speed led do not work in A0 */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },    
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_17_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_18_AL}, 
  {bp_last}
};

static bp_elem_t g_bcm963381dvt_rgmii[] = {
  {bp_cpBoardId,               .u.cp = "963381DVT_RGMII"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_ulPhyId4,                .u.ul = 0x19 | MAC_IF_RGMII_1P8V | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381dvt},
  {bp_last}
};

static bp_elem_t g_bcm963381dvt_53125[] = {
  {bp_cpBoardId,               .u.cp = "963381DVT_53125"},
  {bp_cpComment,               .u.cp = "(incomplete)"},
  {bp_usEphyBaseAddress,       .u.us = 0x8},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x08},
  {bp_ulPhyId1,                .u.ul = 0x09},
  {bp_ulPhyId2,                .u.ul = 0x0a},
  {bp_ulPhyId3,                .u.ul = 0x0b},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT | EXTSW_CONNECTED},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  //{bp_usConfigType,            .u.us = BP_ENET_CONFIG_SPI_SSB_2},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MDIO},
  {bp_ulPortMap,               .u.ul = 0x03},
  {bp_ulPhyId0,                .u.ul = 0x00 | CONNECTED_TO_EXTERN_SW},
  {bp_ulPhyId1,                .u.ul = 0x01 | CONNECTED_TO_EXTERN_SW},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381dvt},
  {bp_last}
};


static bp_elem_t g_bcm963381ref1_a0[] = {
  {bp_cpBoardId,               .u.cp = "963381REF1_A0"},
  {bp_ulPinmuxTableSelect,     .u.ul = 1}, // default pinmux is 0
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_3_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_5_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_2_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_9_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usSerialLedData,         .u.us = BP_GPIO_17_AL}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_16_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_24_AH},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_16_AH},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_24_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_29_AH},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_22_AH},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },    
  {bp_last}
};

/* for A1 and B0 chip */
static bp_elem_t g_bcm963381ref1[] = {
  {bp_cpBoardId,               .u.cp = "963381REF1"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_16_AH},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AH},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_17_AH},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AH},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_1_AH},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AH},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_8_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_3_AH},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AH},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AH},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },   
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_12_AH}, 
  {bp_last}
};

static bp_elem_t g_bcm963381ref2[] = {
  {bp_cpBoardId,               .u.cp = "963381REF2"},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_1_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_8_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_3_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_9_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_10_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_ulPhyId4,                .u.ul = 0x18 | MAC_IF_RGMII_1P8V | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_13_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_12_AL}, 
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381ref1},
  {bp_last}
};

static bp_elem_t g_bcm963381bg_lte[] = {
  {bp_cpBoardId,               .u.cp = "963381BG_LTE"},
  {bp_usExtIntrLTE,            .u.us = BP_EXT_INTR_3},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381ref2},
  {bp_last}
};

static bp_elem_t g_bcm963381a_ref1[] = {
  {bp_cpBoardId,               .u.cp = "963381A_REF1"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, /* enable NAND interface even for SPI boot */
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_18_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_35_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_36_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_33_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_34_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_38_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_31_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_41_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_42_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AL}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AL},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },   
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_37_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_16_AL}, 
  {bp_last}
};

static bp_elem_t g_bcm963381ref3[] = {
  {bp_cpBoardId,               .u.cp = "963381REF3"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_40_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_17_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 19},
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_39_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_35_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_36_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_GPIO_33_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_34_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_GPIO_38_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_31_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_GPIO_41_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_42_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH}, 
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },   
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_13_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_12_AH}, 
  {bp_last}
};

static bp_elem_t g_bcm963381wp[] = {
  {bp_cpBoardId,               .u.cp = "963381WP"},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_24_AL},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_1_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x11},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_GPIO_5_AL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_ulPhyId4,                .u.ul = RGMII_DIRECT_3P3V | FORCE_LINK_1000FD},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulPortMaxRate,           .u.ul = 400000000},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY | PORT_FLAG_SOFT_SWITCHING},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_19_AL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963381ref3},
  {bp_last}
};

static bp_elem_t g_dg150v2r0[] = {                //v0.2 HW
  {bp_cpBoardId,               .u.cp = "DG150V2R0"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_HS_SPI},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_16_AH},
  {bp_usSerialLedData,         .u.us = BP_GPIO_17_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_24_AH},
  // The LED's controllable by peripheral_manager using the brcm led driver are
  // listed by the enum BOARD_LED_NAME (board.h). The enum value is translated
  // to the corresponding bp_usGpioXxxxx using a table bpLedInfo (bcm63xx_led.c)
  // and mapped to a gpio here below.
  // NOTE: LED's could also be controlled using /sys/class/leds/NN/brightness.
  {bp_usGpioLedAdsl,           .u.us = BP_SERIAL_GPIO_18_AL}, // sr 0 DSL
  {bp_usGpioSecLedAdsl,        .u.us = BP_SERIAL_GPIO_17_AL}, // sr 1 Ethernet
  {bp_usGpioDectLed,           .u.us = BP_SERIAL_GPIO_16_AL}, // sr 8 PWR_FAIL
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_15_AL}, // sr 3 ECO
  {bp_usGpioLedVoip,           .u.us = BP_SERIAL_GPIO_14_AL}, // sr 4 WLAN_WPS
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_13_AL}, // sr 5 INET_ACT
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_12_AL}, // sr 6 FX_1
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_11_AL}, // sr 7 GBE_WAN
  {bp_usAntInUseWireless,      .u.us = BP_WLAN_ANT_MAIN},
  {bp_usWirelessFlags,         .u.us = 0},
/*  {bp_usExtIntrResetToDefault2, .u.us = BP_GPIO_20_AL},*/
  {bp_usGpioReserved,          .u.us = BP_GPIO_20_AL},  // button reset for Linux
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,         .u.us = BP_EXT_INTR_0 | BP_EXT_INTR_TYPE_IRQ_LOW_LEVEL},
  {bp_usCfeResetToDefaultBtnIdx, .u.us = 0 },           // button reset for CFE
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* defined the spi select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 49},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 19},
  {bp_usSpiSlaveSelectNum,     .u.us = 2}, /* needed in case a SPI device is plugged  into J504 */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 18},
  {bp_ucPhyType0,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_ucPhyAddress,            .u.uc = 0x0},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = 0x01},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_5_AL}, /* these link/speed led do not work in A0 */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_ulPhyId1,                .u.ul = 0x02},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_8_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_ulPhyId2,                .u.ul = 0x03},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_9_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_ulPhyId3,                .u.ul = 0x04},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_ulPhyId4,                .u.ul = 0x0 | MAC_IF_RGMII | PHY_INTEGRATED_VALID | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_15_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_25_AH},
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_26_AH},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_50 },
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_last}
};

static bp_elem_t g_dg150alv2r0[] = {                //v0.2 HW
  {bp_cpBoardId,               .u.cp = "DG150ALV2R0"},
  {bp_elemTemplate,            .u.bp_elemp = g_dg150v2r0},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_dg150v2r0, g_dg150alv2r0, g_bcm963381sv, g_bcm963381dvt, g_bcm963381dvt_rgmii, g_bcm963381dvt_53125, g_bcm963381ref1_a0, g_bcm963381a_ref1, g_bcm963381ref1, g_bcm963381ref2, g_bcm963381ref3, g_bcm963381bg_lte, g_bcm963381wp, 0};
#endif

#if defined(_BCM963148_) || defined(CONFIG_BCM963148)

/* Only needed for internal GPHYs; by default internal GPHYs do not adv. 1000HD/100HD/10FD/10HD capabilities;
 * There are some NICs that will not negotiate 100FD - so need to advertise 100HD to link up with those NICs */
#define BCM963148_PHY_BASE             0x8

static bp_elem_t g_bcm963148sv[] = {
  {bp_cpBoardId,               .u.cp = "963148SV"},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_5_AH}, // uart2 is /dev/ttyS1
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_6_AH}, // stty 115200 < /dev/ttyS1 to set speed
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8

  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_last}
};

static bp_elem_t g_bcm963148dvt[] = {
  {bp_cpBoardId,               .u.cp = "963148DVT"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioLedWanError,       .u.us = BP_GPIO_16_AL},
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_18_AL},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_20_AL}, // LED register bit 20, shifted serially
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 },
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
                                              // to avoid conflicting P0 and P11 phy address of 1
                                              // the intergrated Quad GPHY address is now 0x8, 0x9, 0xa, 0xb
                                              // the intergrated Single GPHY address 0xc
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_last}
};

static bp_elem_t g_bcm963148dvt_p300[] = {
  {bp_cpBoardId,               .u.cp = "963148DVT_P300"},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_26_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_27_AL},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AL},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xbf},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulPhyId5,                .u.ul = 0x19 |  PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL}, // bottom right.
  {bp_ulPhyId7,                .u.ul = 0x0 |  PHY_INTEGRATED_VALID  | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148dvt},
  {bp_last}
};

static bp_elem_t g_bcm963148ref[] = {
  {bp_cpBoardId,               .u.cp = "963148REF"},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH}, // NOTE: bp_ulGpioOverlay is no longer used
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_17_AL}, // pinmux for PWM2 LED
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AL}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AL}, // placeholder for SF2 Port4 SPD1
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_29_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_30_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_31_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_27_AL},
  {bp_usGpioLedWanData,        .u.us = BP_GPIO_15_AL},
  {bp_usGpioSecLedWanData,     .u.us = BP_GPIO_19_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_117_AH }, /* i2c and sgmii fiber detect seletion for serder interface */
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_119_AH },
  {bp_usSgmiiDetect,           .u.us = BP_GPIO_28_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usSpiSlaveSelectNum,     .u.us = 5},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 7},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_25_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_usGpioPotsLed,           .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16},
  {bp_usUsbPwrFlt0,             .u.us = BP_GPIO_132_AL},
  {bp_usUsbPwrOn0,              .u.us = BP_GPIO_133_AL},
  {bp_usUsbPwrFlt1,             .u.us = BP_GPIO_134_AL},
  {bp_usUsbPwrOn1,              .u.us = BP_GPIO_135_AL},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_P502"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
#if 0 /* for RGMII daughter card */
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
  {bp_ulPhyId5,                .u.ul = 0x19 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},  /* make sure the phy id matches the one on the plug in rgmii phy daughter card */
#endif
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_bmu[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_BMU"},
  {bp_usBatteryEnable,         .u.us = 1},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_NAND}, // Enable NAND pinmux even on SPI boot
  {bp_usGpioLedBlPowerOn,      .u.us = BP_GPIO_22_AL},
  {bp_usGpioLedBlStop,         .u.us = BP_GPIO_23_AL},
  {bp_usExtIntrResetToDefault, .u.us = BP_EXT_INTR_0},
  {bp_usExtIntrSesBtnWireless, .u.us = BP_EXT_INTR_1},
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedAdsl,           .u.us = BP_GPIO_17_AL},
  {bp_usGpioSecLedAdsl,        .u.us = BP_GPIO_21_AL},
  {bp_ulAfeId0,                .u.ul = BP_AFE_CHIP_CH0 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_ulAfeId1,                .u.ul = BP_AFE_CHIP_CH1 | BP_AFE_LD_6303 | BP_AFE_LD_REV_6303_VR5P3 | BP_AFE_FE_ANNEXA | BP_AFE_FE_REV_6303_REV_12_3_40 }, 
  {bp_usGpioAFEVR5P3PwrEn,     .u.us = BP_GPIO_37_AH},
  {bp_usGpioIntAFELDPwr,       .u.us = BP_GPIO_52_AH}, // Line Driver 0 = "Int"
  {bp_usGpioIntAFELDData,      .u.us = BP_GPIO_53_AH},
  {bp_usGpioIntAFELDClk,       .u.us = BP_GPIO_55_AH},
  {bp_usGpioExtAFELDPwr,       .u.us = BP_GPIO_54_AH}, // Line Driver 1 = "Ext"
  {bp_usGpioExtAFELDData,      .u.us = BP_GPIO_9_AH},
  {bp_usGpioExtAFELDClk,       .u.us = BP_GPIO_10_AH},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 127},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 8},
  {bp_usVregSync,              .u.us = BP_GPIO_18_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM963148_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x4) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x0) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_0_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_1_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_28_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x1) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_2_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x2) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x3) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_29_AL},
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_30_AL},
  {bp_usGpioDectLed,           .u.us = BP_GPIO_31_AL},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_8},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_bmu_i2s[] = {
  {bp_cpBoardId,               .u.cp = "963148_BMUI2S"},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_I2S}, // Enable I2S pinmux
  {bp_usGpioVoip1Led,          .u.us = BP_GPIO_NONE}, 
  {bp_usGpioVoip2Led,          .u.us = BP_GPIO_NONE},
  {bp_usGpioDectLed,           .u.us = BP_GPIO_NONE},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_bmu},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_plc[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_PLC"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT_3P3V },
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_moca[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_MOCA"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_14_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_bhr[] = {
  {bp_cpBoardId,               .u.cp = "963148REF_BHR"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, /* use the WAN LED from runner */
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AL},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AL},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AL},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_HIGH},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_115_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_60_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 25},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_usMocaType1,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_D_LOW},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_4},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_110_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_14_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 26},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502_plc[] = {
  {bp_cpBoardId,               .u.cp = "963148P502_PLC"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x1f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId4,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_PLC},
  {bp_ucPhyDevName,            .u.cp = "plc%d"},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT_3P3V },
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_TX_INTERNAL_DELAY | PORT_FLAG_RX_INTERNAL_DELAY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_plc},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502_moca[] = {
  {bp_cpBoardId,               .u.cp = "963148P502_MOCA"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM963148_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_moca},
  {bp_last}
};

static bp_elem_t g_bcm963148ref_p502_bhr[] = {
  {bp_cpBoardId,               .u.cp = "963148P502_BHR"},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH}, // placeholder for SF2 Port4 SPD0
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH}, // placeholder for SF2 Port4 SPD1
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x3},
  {bp_ulPhyId0,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 12},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_20_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_21_AL},
  {bp_usLinkLed,               .u.us = BP_GPIO_22_AL},
  {bp_ulPhyId1,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM963148_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_10_AH},
  {bp_ulPhyId1,                .u.ul = (BCM963148_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_11_AH},
  {bp_ulPhyId2,                .u.ul = (BCM963148_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_12_AH},
  {bp_ulPhyId3,                .u.ul = (BCM963148_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_GPIO_13_AL},
  {bp_ulPhyId7,                .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm963148ref_bhr},
  {bp_last}
};


bp_elem_t * g_BoardParms[] = {g_bcm963148sv, g_bcm963148dvt, g_bcm963148ref, g_bcm963148ref_bmu, g_bcm963148ref_bmu_i2s, g_bcm963148ref_plc, g_bcm963148ref_moca, g_bcm963148ref_bhr, g_bcm963148dvt_p300, 
    g_bcm963148ref_p502, g_bcm963148ref_p502_plc, g_bcm963148ref_p502_moca, g_bcm963148ref_p502_bhr, 0};
#endif

#if defined(_BCM94908_) || defined(CONFIG_BCM94908)

#define BCM94908_PHY_BASE             0x8

static bp_elem_t g_bcm94908sv[] = {
  {bp_cpBoardId,               .u.cp = "94908SV"},
  {bp_ulCompatChipId,          .u.ul = 0x4908},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_EMMC}, 
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_I2S}, 
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGphyBaseAddress,       .u.us = BCM94908_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1},
  {bp_last}
};

static bp_elem_t g_bcm94908dvt[] = {
  {bp_cpBoardId,               .u.cp = "94908DVT"},
  {bp_ulCompatChipId,          .u.ul = 0x4908},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_23_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_PRESS  },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_26_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_PRESS  },
  /* GPIO 14 to 17 shared with SPI slave inteface. Disable 
   * it to make SPI slave work. Uncomment these lines if 
   * SPI slave interface is not used*/
  /*{bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_14_AL},
    {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_15_AL},*/
  {bp_usGpioSfpDetect,         .u.us = BP_GPIO_22_AH},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_20_AH},  // placeholder for GPHY4 Link/Act
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_26_AH},  // placeholder spare serial led
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_27_AH},  // placeholder spare serial led
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_28_AH},  // placeholder spare serial led
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_22_AH},  /* sw control led */
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_18_AH }, 
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_19_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 56},
  {bp_usGphyBaseAddress,       .u.us = BCM94908_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_10_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_11_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_21_AL},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},
  /* Uncomment this line if SPI slave interface is not used */  
  /*{bp_usLinkLed,               .u.us = BP_GPIO_16_AL},*/
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  /* Uncomment this line if SPI slave interface is not used */  
  /*{bp_usLinkLed,               .u.us = BP_GPIO_17_AL},*/
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_18_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  //{bp_ulCrossbar,              .u.ul = 11},
  //{bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_19_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_25_AH}, /* board schematic assign wrong channel26 which cause serial channel overflow */
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1},
  {bp_last}
};

static bp_elem_t g_bcm94908dvt_sfpwan[] = {
  {bp_cpBoardId,               .u.cp = "94908DVT_SFPWAN"},
  {bp_ulCompatChipId,          .u.ul = 0x4908},
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_23_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_PRESS  },
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_26_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_PRESS  },
  /* GPIO 14 to 17 shared with SPI slave inteface. Disable 
   * it to make SPI slave work. Uncomment these lines if 
   * SPI slave interface is not used*/
  /*{bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_14_AL},
    {bp_usGpioLedPwmReserved,    .u.us = BP_GPIO_15_AL},*/
  {bp_usGpioSfpDetect,         .u.us = BP_GPIO_22_AH},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_20_AH},  // placeholder for GPHY4 Link/Act
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_26_AH},  // placeholder spare serial led
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_27_AH},  // placeholder spare serial led
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_28_AH},  // placeholder spare serial led
  {bp_usGpioLedSesWireless,    .u.us = BP_GPIO_24_AL}, 
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_22_AH},  /* sw control led */
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_18_AH }, 
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_19_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 56},
  {bp_usGphyBaseAddress,       .u.us = BCM94908_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_GPIO_10_AL}, 
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_11_AL},  
  {bp_usLinkLed,               .u.us = BP_GPIO_21_AL},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},
  /* Uncomment this line if SPI slave interface is not used */  
  /*{bp_usLinkLed,               .u.us = BP_GPIO_16_AL},*/
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  /* Uncomment this line if SPI slave interface is not used */  
  /*{bp_usLinkLed,               .u.us = BP_GPIO_17_AL},*/
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_4_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_5_AL},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_18_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_GPIO_6_AL},
  {bp_usSpeedLed1000,          .u.us = BP_GPIO_7_AL},  
  //{bp_ulPhyId7,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  //{bp_ulCrossbar,              .u.ul = 11},
  //{bp_ulCrossbarPhyId,         .u.ul = 0x18 | PHY_INTEGRATED_VALID | MAC_IF_RGMII_1P8V | PHY_EXTERNAL},
  //{bp_ulCrossbar,              .u.ul = 9},
  //{bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_19_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_25_AH}, /* board schematic assign wrong channel26 which cause serial channel overflow */
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1},
  {bp_last}
};

static bp_elem_t g_bcm94908ref[] = {
  {bp_cpBoardId,               .u.cp = "94908REF"},
  {bp_ulCompatChipId,          .u.ul = 0x4908},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_EMMC}, 
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_10_AH},
  {bp_usGpioUart2Rts,          .u.us = BP_GPIO_11_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH}, // uart2 is /dev/ttyH0
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH}, // uart2 is /dev/ttyH0
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usGpioBtWake,            .u.us = BP_GPIO_9_AH},
  {bp_usGpioBtReset,           .u.us = BP_GPIO_8_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_30_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,  .u.ptr = (void*)"Button Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESET | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S},  
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_29_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_PRESS  },
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_30_AH},  // placeholder for GPHY4 Link/Act
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for GPHY4 Speed
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for GPHY4 Speed
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_12_AH}, 
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_16_AH},  /* sw control led */
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_18_AH }, 
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_19_AH },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 56},
  {bp_usSpiSlaveSelectNum,     .u.us = 2}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 23},
  {bp_usGphyBaseAddress,       .u.us = BCM94908_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  //{bp_ulCrossbar,              .u.ul = 9},
  //{bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_22_AH}, 
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_29_AH},
  {bp_usGpioLedAggregateLnk,   .u.us = BP_SERIAL_GPIO_24_AH},
  {bp_usGpioLedAggregateAct,   .u.us = BP_SERIAL_GPIO_25_AH},
  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_18_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_19_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1},
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 56},
  {bp_usSpiSlaveSelectNum,     .u.us = 2},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 23},
  {bp_usSpiSlaveSelectNum,     .u.us = 3},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 22},
  {bp_last}
};

static bp_elem_t g_bcm94908ref_extphy[] = {
  {bp_cpBoardId,               .u.cp = "94908REF_XPHY"},
  {bp_usMiiMdc,                .u.us = BP_GPIO_48_AH},
  {bp_usMiiMdio,               .u.us = BP_GPIO_49_AH},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_22_AH}, 
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_29_AH},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1e | PHY_EXTERNAL | PHY_TYPE_CL45GPHY},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm94908ref},
  {bp_last}
};

/* Board with 2.5GPHY connected to WAN port */
static bp_elem_t g_bcm94908ref_wan2p5g[] = {
  {bp_cpBoardId,               .u.cp = "94908REF_W2P5"},
  {bp_usMiiMdc,                .u.us = BP_GPIO_48_AH},
  {bp_usMiiMdio,               .u.us = BP_GPIO_49_AH},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 9},
  {bp_ulCrossbarPhyId,         .u.ul = 6 |  PHY_INTEGRATED_VALID | MAC_IF_SERDES | PHY_EXTERNAL},
  {bp_ulCrossbarPhyId,         .u.ul = 0x1e | PHY_EXTERNAL | PHY_TYPE_CL45GPHY},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_22_AH}, 
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_29_AH},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm94908ref},
  {bp_last}
};

static bp_elem_t g_bcm94908ref_moca[] = {
  {bp_cpBoardId,               .u.cp = "94908REF_MOCA"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_22_AH}, 
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x8f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_29_AH},
  {bp_ulPhyId7,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_LAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_EXT_D},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_20_AL},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_7_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_80_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 21},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm94908ref},
  {bp_last}
};

/* 94908REF_PLC has been hijacked to support MOCAWAN */
static bp_elem_t g_bcm94908ref_plc[] = {
  {bp_cpBoardId,               .u.cp = "94908REF_PLC"},
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ucPhyDevName,            .u.cp = "moca%d"},
  {bp_ulCrossbar,              .u.ul = 11},
  {bp_ulCrossbarPhyId,         .u.ul = RGMII_DIRECT | MAC_IF_RGMII_2P5V },
  {bp_usPhyConnType,           .u.us = PHY_CONN_TYPE_MOCA},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_22_AH}, 
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0xf},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_29_AH},
  {bp_usMocaType0,             .u.us = BP_MOCA_TYPE_WAN},
  {bp_usMocaRfBand,            .u.us = BP_MOCA_RF_BAND_EXT_D},
  {bp_usExtIntrMocaHostIntr,   .u.us = BP_EXT_INTR_TYPE_IRQ_HIGH_LEVEL | BP_EXT_INTR_2},
  {bp_usGpio_Intr,             .u.us = BP_GPIO_20_AL},
#if !defined(_CFE_)
  {bp_pMocaInit,               .u.ptr = (void*)moca6802InitSeq},
#endif
  {bp_usGpioSpiSlaveReset,     .u.us = BP_GPIO_7_AL},
  {bp_usGpioSpiSlaveBootMode,  .u.us = BP_GPIO_80_AL},
  {bp_usSpiSlaveBusNum,        .u.us = HS_SPI_BUS_NUM},
  {bp_usSpiSlaveSelectNum,     .u.us = 4},
  {bp_usSpiSlaveSelectGpioNum, .u.us = 21},
  {bp_usSpiSlaveMode,          .u.us = SPI_MODE_3},
  {bp_ulSpiSlaveCtrlState,     .u.ul = SPI_CONTROLLER_STATE_GATE_CLK_SSOFF},
  {bp_ulSpiSlaveMaxFreq,       .u.ul = 12500000},
  {bp_ucDspType0,              .u.uc = BP_VOIP_NO_DSP},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm94908ref},
  {bp_last}
};

static bp_elem_t g_bcm94906ref[] = {
  {bp_cpBoardId,               .u.cp = "94906REF"},
  {bp_ulCompatChipId,          .u.ul = 0x4906},
  {bp_ulInterfaceEnable,       .u.ul = BP_PINMUX_FNTYPE_EMMC}, 
  {bp_usSerialLedData,         .u.us = BP_GPIO_0_AH},
  {bp_usSerialLedClk,          .u.us = BP_GPIO_1_AH},
  {bp_usSerialLedMask,         .u.us = BP_GPIO_2_AH},
  {bp_usGpioBtReset,           .u.us = BP_GPIO_8_AH},
  {bp_usGpioBtWake,            .u.us = BP_GPIO_9_AH},
  {bp_usGpioUart2Cts,          .u.us = BP_GPIO_10_AH},
  {bp_usGpioUart2Rts,          .u.us = BP_GPIO_11_AH},
  {bp_usGpioUart2Sdin,         .u.us = BP_GPIO_12_AH}, // uart2 is /dev/ttyH0
  {bp_usGpioUart2Sdout,        .u.us = BP_GPIO_13_AH}, // uart2 is /dev/ttyH0
  {bp_usGpioI2cSda,            .u.us = BP_GPIO_18_AH }, 
  {bp_usGpioI2cScl,            .u.us = BP_GPIO_19_AH },
  {bp_usButtonIdx,             .u.us = 0},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_0 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_23_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_PRINT | BP_BTN_TRIG_PRESS },
  {      bp_ulButtonActionParm,  .u.ptr = (void*)"Button Press -- Hold for 5s to do restore to default" },
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESET | BP_BTN_TRIG_RELEASE | BP_BTN_TRIG_0S  },
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_RESTORE_DEFAULTS | BP_BTN_TRIG_HOLD | BP_BTN_TRIG_5S},  
  {bp_usButtonIdx,             .u.us = 1},
  {  bp_usButtonExtIntr,       .u.us = BP_EXT_INTR_1 },
  {  bp_usGpio_Intr,           .u.us = BP_GPIO_22_AL},
  {    bp_usButtonAction,      .u.us = BP_BTN_ACTION_SES | BP_BTN_TRIG_PRESS  },
  {bp_usSpiSlaveSelectNum,     .u.us = 1}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 56},
  {bp_usSpiSlaveSelectNum,     .u.us = 5}, /* define the SPI select for voice */
  {bp_usSpiSlaveSelectGpioNum, .u.us = 20},
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_30_AH},  // placeholder for GPHY4 Link/Act
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_9_AH},  // placeholder for GPHY4 Speed
  {bp_usGpioLedReserved,       .u.us = BP_SERIAL_GPIO_8_AH},  // placeholder for GPHY4 Speed
  {bp_usGpioLedSesWireless,    .u.us = BP_SERIAL_GPIO_12_AH}, 
  {bp_usGpioLedWanData,        .u.us = BP_SERIAL_GPIO_16_AH},  /* sw control led */
  {bp_usGphyBaseAddress,       .u.us = BCM94908_PHY_BASE},  // use phy addressses on SF2 with base address 0x8
  {bp_ucPhyType0,              .u.uc = BP_ENET_NO_PHY}, // Runner
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP},
  {bp_ucPhyAddress,            .u.uc = 0x1e},
  {bp_ulPortMap,               .u.ul = 0x9},
  {bp_ulPhyId0,                .u.ul = GMII_DIRECT | EXTSW_CONNECTED},
  {bp_ulPortFlags,             .u.ul = PORT_FLAG_MGMT }, // Managment port is on switch
  {bp_ulPhyId3,                .u.ul = BP_PHY_ID_NOT_SPECIFIED},
  {bp_ulCrossbar,              .u.ul = 10},
  {bp_ulCrossbarPhyId,         .u.ul = (BCM94908_PHY_BASE + 0x04) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  /* use the WAN LED from runner */
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_22_AH}, 
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_23_AH},
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_21_AH},
  {bp_ucPhyType1,              .u.uc = BP_ENET_EXTERNAL_SWITCH},
  {bp_usConfigType,            .u.us = BP_ENET_CONFIG_MMAP}, // Accessing SF2 as MMapped external switch
  {bp_ulPortMap,               .u.ul = 0x0f},
  {bp_ulPhyId0,                .u.ul = (BCM94908_PHY_BASE + 0x00) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_0_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_1_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_26_AH},
  {bp_ulPhyId1,                .u.ul = (BCM94908_PHY_BASE + 0x01) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_2_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_3_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_27_AH},
  {bp_ulPhyId2,                .u.ul = (BCM94908_PHY_BASE + 0x02) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_4_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_5_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_28_AH},
  {bp_ulPhyId3,                .u.ul = (BCM94908_PHY_BASE + 0x03) | (ADVERTISE_ALL_GMII | PHY_ADV_CFG_VALID)},
  {bp_usSpeedLed100,           .u.us = BP_SERIAL_GPIO_6_AH},
  {bp_usSpeedLed1000,          .u.us = BP_SERIAL_GPIO_7_AH},  
  {bp_usLinkLed,               .u.us = BP_SERIAL_GPIO_29_AH},

  {bp_usGpioLedAggregateLnk,   .u.us = BP_SERIAL_GPIO_24_AH},
  {bp_usGpioLedAggregateAct,   .u.us = BP_SERIAL_GPIO_25_AH},

  {bp_ucDspType0,              .u.uc = BP_VOIP_DSP},
  {bp_ucDspAddress,            .u.uc = 0},
  {bp_usGpioVoip1Led,          .u.us = BP_SERIAL_GPIO_18_AH},
  {bp_usGpioVoip2Led,          .u.us = BP_SERIAL_GPIO_19_AH},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1},
  {bp_last}
};

/* fake 4906REF board id. Used on 4908 board as 4906 board */
static bp_elem_t g_bcm94906ref_fake[] = {
  {bp_cpBoardId,               .u.cp = "94906REF_FAKE"},
  {bp_ulMaxNumCpu,             .u.ul = 2},
  {bp_ulMemoryConfig,          .u.ul = BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1},
  {bp_elemTemplate,            .u.bp_elemp = g_bcm94908ref},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm94908sv, g_bcm94908dvt, g_bcm94908dvt_sfpwan, g_bcm94908ref, g_bcm94908ref_extphy, g_bcm94908ref_moca, g_bcm94908ref_plc, g_bcm94906ref, g_bcm94906ref_fake, g_bcm94908ref_wan2p5g, 0};
#endif

#if defined(_BCM963158_) || defined(CONFIG_BCM963158)
static bp_elem_t g_bcm963158sv[] = {
  {bp_cpBoardId,               .u.cp = "963158SV"},
  {bp_last}
};

static bp_elem_t g_bcm963158ref[] = {
  {bp_cpBoardId,               .u.cp = "963158REF"},
  {bp_last}
};

bp_elem_t * g_BoardParms[] = {g_bcm963158sv, g_bcm963158ref, 0};
#endif
bp_elem_t * g_pCurrentBp = 0;


#if defined(_BCM963268_) || defined(CONFIG_BCM963268)
/* The unique part contains the subSytemId (boardId) and the BoardRev number */
static WLAN_SROM_ENTRY wlan_patch_unique_963268MBV[] = {
    {2,  0x5BB},
    {65, 0x1204},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963268V30A[] = {
    {2,  0x5E7},
    {65, 0x1101},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963268BU[] = {
    {2,  0x5A7},
    {65, 0x1201},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XH[] = {
    {2,  0x5E2},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XM[] = {
    {2,  0x61F},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XH5[] = {
    {2,  0x640},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XN5[] = {
    {2,  0x684},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XM5[] = {
    {2,  0x685},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168XM5_6302[] = {
    {2,  0x686},
    {48, 0x434f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963168MP[] = {
    {2,  0x5BB},
    {48, 0x433f},
    {65, 0x1100},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_CG300R0[] = {
    {2,   0x5A7},
    {65,  0x1201},
    {97,  0xFF39},
    {98,  0x15B5},
    {99,  0xFADB},
    {113, 0xFEB2},
    {114, 0x148E},
    {115, 0xFAA0},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_DG200R0[] = {
    {2,   0x5BB},
    {65,  0x1204},
    {97,  0x007d},
    {98,  0x1743},
    {99,  0xfb8f},
    {113, 0xff79},
    {114, 0x1651},
    {115, 0xfaf4},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_EG200R0[] = {
    {2,   0x5BB},
    {65,  0x1204},
    {97,  0x007d},
    {98,  0x1743},
    {99,  0xfb8f},
    {113, 0xff79},
    {114, 0x1651},
    {115, 0xfaf4},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_EG300R0[] = {
    {2,   0x5A7},
    {65,  0x1201},
    {97,  0xFF22},
    {98,  0x1590},
    {99,  0xFAB7},
    {113, 0xFF5F},
    {114, 0x1779},
    {115, 0xFAC1},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_VOX25[] = {
    {2,   0x5A7},
    {65,  0x1201},
    {97,  0xFF43},
    {98,  0x1778},
    {99,  0xFAB3},
    {113, 0xFF82},
    {114, 0x1838},
    {115, 0xFAB0},
    {0, 0}
};

/* The common part contains the entries that are valid for multiple boards */
static WLAN_SROM_ENTRY wlan_patch_common_963268MBV[] = {
    { 78,  0x0303}, 
    { 79,  0x0202}, 
    { 80,  0xff02},
    { 87,  0x0315}, 
    { 88,  0x0315},
    { 94,  0x001E},
    { 96,  0x2048}, 
    { 97,  0xFFB5}, 
    { 98,  0x175F},
    { 99,  0xFB29},
    { 100, 0x3E40},
    { 101, 0x403C},
    { 102, 0xFF15},
    { 103, 0x1455},
    { 104, 0xFB95},
    { 108, 0xFF28},
    { 109, 0x1315},
    { 110, 0xFBF0},
    { 112, 0x2048},
    { 113, 0xFFD7},
    { 114, 0x17D6},
    { 115, 0xFB67},
    { 116, 0x3E40},
    { 117, 0x403C},
    { 118, 0xFE87},
    { 119, 0x110F},
    { 120, 0xFB4B},
    { 124, 0xFF8D},
    { 125, 0x1146},
    { 126, 0xFCD6},
    { 161, 0x0000},
    { 162, 0x4444},
    { 163, 0x0000},
    { 164, 0x2222},
    { 165, 0x0000},
    { 166, 0x2222},
    { 167, 0x0000},
    { 168, 0x2222},
    { 169, 0x4000},
    { 170, 0x4444},
    { 171, 0x4000},
    { 172, 0x4444},
    { 177, 0x2000},
    { 178, 0x2222},
    { 179, 0x2000},
    { 180, 0x2222},
    { 185, 0x2000},
    { 186, 0x2222},
    { 187, 0x2000},
    { 188, 0x2222},
    { 193, 0x2000},
    { 194, 0x2222},
    { 195, 0x2000},
    { 196, 0x2222},
    { 201, 0x1111},
    { 202, 0x2222},
    { 203, 0x4446},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XH[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 87,  0x031f},
    { 88,  0x031f},
    { 93,  0x0202},
    { 96,  0x2064},
    { 97,  0xfe59},
    { 98,  0x1c81},
    { 99,  0xf911},
    { 112, 0x2064},
    { 113, 0xfe55},
    { 114, 0x1c00},
    { 115, 0xf92c},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XM[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 87,  0x031f},
    { 88,  0x031f},
    { 93,  0x0202},
    { 96,  0x205c},
    { 97,  0xfe94},
    { 98,  0x1c92},
    { 99,  0xf948},
    { 112, 0x205c},
    { 113, 0xfe81},
    { 114, 0x1be6},
    { 115, 0xf947},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XH5[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 78,  0x0300},
    { 87,  0x031f},
    { 88,  0x033f},
    { 93,  0x0202},
    { 97,  0xffb5},
    { 98,  0x175f},
    { 99,  0xfb29},
    { 100, 0x4060},
    { 101, 0x6060},
    { 102, 0xfee4},
    { 103, 0x1d2c},
    { 104, 0xfa0c},
    { 105, 0xfea2},
    { 106, 0x149a},
    { 107, 0xfafc},
    { 108, 0xfead},
    { 109, 0x1da8},
    { 110, 0xf986},
    { 113, 0xffd7},
    { 114, 0x17d6},
    { 115, 0xfb67},
    { 116, 0x4060},
    { 117, 0x6060},
    { 118, 0xfee4},
    { 119, 0x1d2c},
    { 120, 0xfa0c},
    { 121, 0xfea2},
    { 122, 0x149a},
    { 123, 0xfafc},
    { 124, 0xfead},
    { 125, 0x1da8},
    { 126, 0xf986},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XN5[] = {
    { 66,  0x2200},
    { 67,  0x8000},
    { 78,  0x0300},
    { 87,  0x031f},
    { 88,  0x033f},
    { 96,  0x4054},
    { 97,  0xffb5},
    { 98,  0x175f},
    { 99,  0xfb29},
    { 100,  0x405c},
    { 101,  0x5c5c},
    { 102,  0xfedf},
    { 103,  0x1670},
    { 104,  0xfabf},
    { 105,  0xfeb2},
    { 106,  0x1691},
    { 107,  0xfa6a},
    { 108,  0xfec0},
    { 109,  0x16cd},
    { 110,  0xfaa5},
    { 112,  0x404e},
    { 113,  0xffd7},
    { 114,  0x17d6},
    { 115,  0xfb67},
    { 116,  0x405c},
    { 117,  0x5c5c},
    { 118,  0xfeb2},
    { 119,  0x1691},
    { 120,  0xfa6a},
    { 121,  0xfeb2},
    { 122,  0x1691},
    { 123,  0xfa6a},
    { 124,  0xfe60},
    { 125,  0x1685},
    { 126,  0xfa09},
    { 161,  0x0000},
    { 162,  0x0000},
    { 163,  0x8888},
    { 164,  0x8888},
    { 165,  0x8888},
    { 166,  0x8888},
    { 167,  0x8888},
    { 168,  0x8888},
    { 169,  0x0000},
    { 170,  0x0000},
    { 171,  0x0000},
    { 172,  0x0000},
    { 177,  0x0000},
    { 178,  0x8888},
    { 179,  0x8888},
    { 180,  0x8888},
    { 181,  0x8888},
    { 182,  0x8888},
    { 183,  0x8888},
    { 184,  0x8888},
    { 185,  0x8888},
    { 186,  0x8888},
    { 187,  0x0000},
    { 188,  0x8888},
    { 189,  0x8888},
    { 190,  0x8888},
    { 191,  0x8888},
    { 192,  0x8888},
    { 193,  0x8888},
    { 194,  0x8888},
    { 195,  0x8888},
    { 196,  0x8888},
    { 197,  0x0000},
    { 198,  0x8888},
    { 199,  0x8888},
    { 200,  0x8888},
    { 201,  0x2222},
    { 202,  0x2222},
    { 203,  0x2222},
    { 204,  0x2222},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168XM5[] = {
    { 66,  0x3200},
    { 67,  0x8000},
    { 78,  0x0300},
    { 87,  0x031f},
    { 88,  0x033f},
    { 93,  0x0202},
    { 96,  0x405c},
    { 97,  0xffb5},
    { 98,  0x175f},
    { 99,  0xfb29},
    { 100,  0x405c},
    { 101,  0x5c5c},
    { 102,  0xfedd},
    { 103,  0x1a8b},
    { 104,  0xfa70},
    { 105,  0xfea2},
    { 106,  0x149a},
    { 107,  0xfafc},
    { 108,  0xfee7},
    { 109,  0x1a87},
    { 110,  0xfa84},
    { 112,  0x405c},
    { 113,  0xffd7},
    { 114,  0x17d6},
    { 115,  0xfb67},
    { 116,  0x405c},
    { 117,  0x5c5c},
    { 118,  0xfedd},
    { 119,  0x1a8b},
    { 120,  0xfa70},
    { 121,  0xfea2},
    { 122,  0x149a},
    { 123,  0xfafc},
    { 124,  0xfee7},
    { 125,  0x1a87},
    { 126,  0xfa84},
    { 161, 0x0000},
    { 162, 0x0000},
    { 169, 0x0000},
    { 170, 0x0000},
    { 171, 0x0000},
    { 172, 0x0000},
    { 203, 0x1111},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963168MP[] = {
    { 78,  0x0303}, 
    { 79,  0x0202}, 
    { 80,  0xff02},
    { 87,  0x0315}, 
    { 88,  0x0315},
    { 96,  0x2048}, 
    { 97,  0xffb5},
    { 98,  0x168c},
    { 99,  0xfb31},
    { 100, 0x3E40},
    { 101, 0x403C},
    { 102, 0xFF15},
    { 103, 0x1455},
    { 104, 0xFB95},
    { 108, 0xFF28},
    { 109, 0x1315},
    { 110, 0xFBF0},
    { 112, 0x2048},
    { 113, 0xffd7},
    { 114, 0x17b6},
    { 115, 0xfb68},
    { 116, 0x3E40},
    { 117, 0x403C},
    { 118, 0xFE87},
    { 119, 0x110F},
    { 120, 0xFB4B},
    { 124, 0xFF8D},
    { 125, 0x1146},
    { 126, 0xFCD6},
    { 161, 0x0000},
    { 162, 0x4444},
    { 163, 0x0000},
    { 164, 0x2222},
    { 165, 0x0000},
    { 166, 0x2222},
    { 167, 0x0000},
    { 168, 0x2222},
    { 169, 0x4000},
    { 170, 0x4444},
    { 171, 0x4000},
    { 172, 0x4444},
    { 177, 0x2000},
    { 178, 0x2222},
    { 179, 0x2000},
    { 180, 0x2222},
    { 185, 0x2000},
    { 186, 0x2222},
    { 187, 0x2000},
    { 188, 0x2222},
    { 193, 0x2000},
    { 194, 0x2222},
    { 195, 0x2000},
    { 196, 0x2222},
    { 201, 0x1111},
    { 202, 0x2222},
    { 203, 0x4446},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_963167REF2[] = {
    {97,  0xfe97},
    {98,  0x189e},
    {99,  0xfa0c},
    {113, 0xfe8b},
    {114, 0x187b},
    {115, 0xfa0a},
    {0, 0}
};

#endif

#if defined(_BCM96838_) || defined(CONFIG_BCM96838)
/* The unique part contains the subSytemId (boardId) and the BoardRev number */
static WLAN_SROM_ENTRY wlan_patch_unique_968380GERG[] = {
    {   2, 0x05e9},
    {  65, 0x1256},
    {0, 0}
};

/* The common part contains the entries that are valid for multiple boards */
static WLAN_SROM_ENTRY wlan_patch_common_968380GERG[] = {
    { 113, 0xfe94},
    { 114, 0x1904},
    { 115, 0xfa18},
    { 162, 0x4444},
    { 170, 0x4444},
    { 172, 0x4444},
    {0, 0}
};
#endif

#if defined(_BCM963138_) || defined(CONFIG_BCM963138)
static WLAN_SROM_ENTRY wlan_patch_unique_963138REF[] = {
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963138REF[] = {
    { 66,  0x200},
    { 68,  0x9800},
    { 87,  0x41f},
    { 96,  0x204A},
    { 97,  0xFE9B}, 
    { 98,  0x17D5},
    { 99,  0xFAAD},
    { 112, 0x204A},
    { 113, 0xFE74},
    { 114, 0x1646},
    { 115, 0xFAC2},
    { 162, 0x4444},
    { 170, 0x4444},
    { 172, 0x4444},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_DG400R0[] = {
    {79,  0x0000},
    {80,  0x0000},
    {87,  0x0415},
    {96,  0x204a},
    {97,  0xfe48},
    {98,  0x14c8},
    {99,  0xfab7},
    {112, 0x204a},
    {113, 0xfe92},
    {114, 0x1688},
    {115, 0xfa9b},
    {161, 0x2200},
    {162, 0x4442},
    {169, 0x4222},
    {170, 0x6644},
    {171, 0x4222},
    {172, 0x6644},
    {173, 0x4222},
    {174, 0x6644},
    {175, 0x4222},
    {176, 0x6644},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_EG400R0[] = {
    { 97,  0xFE6d},
    { 98,  0x17f9},
    { 99,  0xFA40},
    { 113, 0xFE65},
    { 114, 0x180a},
    { 115, 0xFA2e},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_EG400[] = { {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_SDX810_RGR0[] = {
    { 97,  0xFE6d},
    { 98,  0x17f9},
    { 99,  0xFA40},
    { 113, 0xFE65},
    { 114, 0x180a},
    { 115, 0xFA2e},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_SDX810_RG[] = { {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_F104W[] = {
        { 97, 0xfe53},
        { 98, 0x152f},
        { 99, 0xfaa2},
        { 113, 0xfea6},
        { 114, 0x1832},
        { 115, 0xfa59},
        {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_unique_F104W[] = { {0, 0}
};

#endif

#if defined(_BCM963381_) || defined(CONFIG_BCM963381)
static WLAN_SROM_ENTRY wlan_patch_unique_963381REF[] = {
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_963381[] = {
    { 97,  0xfe46},
    { 98,  0x170e},
    { 99,  0xfa44},
    { 113, 0xfe87},
    { 114, 0x1932},
    { 115, 0xfa2d},
    {0, 0}
};

static WLAN_SROM_ENTRY wlan_patch_common_DG150V2[] = {
    { 97, 0xfe67},
    { 98, 0x178b},
    { 99, 0xfa3f},
    { 113, 0xfe8c},
    { 114, 0x18c7},
    { 115, 0xfa2e},
    {0, 0}
};
#endif


static WLAN_SROM_ENTRY wlan_patch_LAST[] = {
    {0, 0}
};

/* this data structure could be moved to boardparams structure in the future */
/* does not require to rebuild cfe here if more srom entries are needed */
WLAN_SROM_PATCH_INFO wlanPaInfo[]={
#if defined(_BCM963268_) || defined(CONFIG_BCM963268)
    {"963268MBV",      0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV_17A",  0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV_30A",  0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV3",     0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV17A302",0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MBV30A302",0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963268V30A",     0x6362, 220, wlan_patch_unique_963268V30A,    wlan_patch_common_963268MBV},
    {"DG200R0",        0x6362, 220, wlan_patch_unique_DG200R0,       wlan_patch_common_963268MBV},
    {"DG200ALR0",      0x6362, 220, wlan_patch_unique_DG200R0,       wlan_patch_common_963268MBV},
    {"DG301R0",        0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"DG301ALR0",      0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"VG50_R",         0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"CG300R0",        0x6362, 220, wlan_patch_unique_CG300R0,       wlan_patch_common_963268MBV},
    {"CG301R0",        0x6362, 220, wlan_patch_unique_CG300R0,       wlan_patch_common_963268MBV},
    {"EG300R0",        0x6362, 220, wlan_patch_unique_EG300R0,       wlan_patch_common_963268MBV},
    {"EG200R0",        0x6362, 220, wlan_patch_unique_EG200R0,       wlan_patch_common_963268MBV},
    {"963268BU",       0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963268BU_P300",  0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168AC5",      0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168ACH5",     0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168XH",       0x6362, 220, wlan_patch_unique_963168XH,      wlan_patch_common_963168XH},
    {"963167REF1",     0x6362, 220, wlan_patch_unique_963168XH,      wlan_patch_common_963168XH},
    {"963167REF2",     0x6362, 220, wlan_patch_unique_963167REF2,    wlan_patch_common_963168XH},
    {"963167REF3",     0x6362, 220, wlan_patch_unique_963268BU,      wlan_patch_common_963268MBV},
    {"963168XM",       0x6362, 220, wlan_patch_unique_963168XM,      wlan_patch_common_963168XM},
    {"963168XH5",      0x6362, 220, wlan_patch_unique_963168XH5,     wlan_patch_common_963168XH5},
    {"963168XN5",      0x6362, 220, wlan_patch_unique_963168XN5,     wlan_patch_common_963168XN5},
    {"963168XM5",      0x6362, 220, wlan_patch_unique_963168XM5,     wlan_patch_common_963168XM5},
    {"963168XM5_6302", 0x6362, 220, wlan_patch_unique_963168XM5_6302,wlan_patch_common_963168XM5},
    {"VOX25",          0x6362, 220, wlan_patch_unique_VOX25,         wlan_patch_common_963168MP},
    {"963168WFAR",     0x6362, 220, wlan_patch_unique_963268MBV,     wlan_patch_common_963268MBV},
    {"963168MP",       0x6362, 220, wlan_patch_unique_963168MP,      wlan_patch_common_963168MP},
#endif

#if defined(_BCM96838_) || defined(CONFIG_BCM96838)
    {"968380GERG",     0xa8d1, 220, wlan_patch_unique_968380GERG,       wlan_patch_common_968380GERG},
#endif

#if defined(_BCM963138_) || defined(CONFIG_BCM963138)
    {"963138REF_LTE",     0xa8d1, 220, wlan_patch_unique_963138REF,     wlan_patch_common_963138REF},
    {"963138LTE_P302",     0xa8d1, 220, wlan_patch_unique_963138REF,     wlan_patch_common_963138REF},
    {"DG400R0",        0xa8d1, 220, wlan_patch_unique_DG400R0,       wlan_patch_common_963138REF},
    {"EG400R0",        0xa8d1, 220, wlan_patch_unique_EG400R0,       wlan_patch_common_EG400},
    {"SDX810_RGR0",    0xa8d1, 220, wlan_patch_unique_SDX810_RGR0,   wlan_patch_common_SDX810_RG},
    {"F104W",          0xa8d1, 220, wlan_patch_unique_F104W,         wlan_patch_common_F104W},
#endif

#if defined(_BCM963381_) || defined(CONFIG_BCM963381)
    {"963381REF1",     0xa8d1, 220, wlan_patch_unique_963381REF,     wlan_patch_common_963381},
    {"963381A_REF1",     0xa8d1, 220, wlan_patch_unique_963381REF,     wlan_patch_common_963381},
    {"963381REF1_A0",     0xa8d1, 220, wlan_patch_unique_963381REF,     wlan_patch_common_963381},
    {"DG150V2R0",      0xa8d1, 220, wlan_patch_unique_963381REF,     wlan_patch_common_DG150V2},
#endif

    {"", 0, 0, wlan_patch_LAST, wlan_patch_LAST}, /* last entry*/
};


WLAN_PCI_PATCH_INFO wlanPciInfo[]={
#if defined(_BCM963268_) || defined(CONFIG_BCM963268)
    /* this is the patch to boardtype(boardid) for 63268MBV */
    {"963268MBV", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV_17A */
    {"963168MBV_17A", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV_30A */
    {"963168MBV_30A", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV3 */
    {"963168MBV3", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV17A302 */
    {"963168MBV17A302", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MBV30A302 */
    {"963168MBV30A302", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963268V30A */
    {"963268V30A", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5E714e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63268BU */
    {"963268BU", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A714e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63168ACH5 */
    {"963168ACH5", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A714e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168VX */
    {"963168VX", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A814e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168VX_P300 */
    {"963168VX_P300", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A814e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168VX_P400 */
    {"963168VX_P400", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5A814e4},
    {"",       0,      0}}},    
    /* this is the patch to boardtype(boardid) for 63168XH */
    {"963168XH", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5E214e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63168XM */
    {"963168XM", 0x435f14e4, 64,
    {{"subpciids", 11, 0x61f14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XH5 */
    {"963168XH5", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x64014e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XN5 */
    {"963168XN5", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x68414e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XM5 */
    {"963168XM5", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x68514e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168XM5_6302 */
    {"963168XM5_6302", 0x435f14e4, 64,
    {{"deviceids", 0, 0x434f14e4},
    {"subpciids", 11, 0x68614e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 963168MP */
    {"963168MP", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
    /* this is the patch to boardtype(boardid) for 63168WFAR */
    {"963168WFAR", 0x435f14e4, 64,
    {{"subpciids", 11, 0x5BB14e4},
    {"",       0,      0}}},
#endif
    {"",                 0, 0, {{"",       0,      0}}}, /* last entry*/
};

