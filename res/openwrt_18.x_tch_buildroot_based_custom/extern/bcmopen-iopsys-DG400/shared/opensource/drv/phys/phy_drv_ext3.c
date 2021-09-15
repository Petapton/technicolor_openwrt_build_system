/*
   Copyright (c) 2015 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2015:DUAL/GPL:standard
    
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

/*
 *  Created on: Jan 2016
 *      Author: yuval.raviv@broadcom.com
 */

/*
 * Phy driver for external 1G/2.5G/5G/10G phys: BCM84860, BCM84861, BCM84880, BCM84881
 */

#define SUPPORT_BCM8486X    1
#define SUPPORT_BCM8488X    1

#include "phy_drv.h"

#ifdef SUPPORT_BCM8486X
#include "bcm8486x_firmware.h"
#endif
#ifdef SUPPORT_BCM8488X
#include "bcm8488x_firmware.h"
#endif

typedef enum
{
    UNKNOWN,
    BCM84860,
    BCM84861,
    BCM84880,
    BCM84881,
} bcm848xx_type_t;

static uint32_t enabled_phys;
static bcm848xx_type_t bcm848xx_type;

#define SUPPORT_MGBASET     (bcm848xx_type == BCM84860 || bcm848xx_type == BCM84861)
#define SUPPORT_10GBASET    (bcm848xx_type == BCM84861 || bcm848xx_type == BCM84881)

#define BUS_WRITE(a, b, c, d)       if ((ret = _bus_write(a, b, c, d))) goto Exit;
#define BUS_WRITE_ALL(a, b, c, d)   if ((ret = _bus_write_all(a, b, c, d))) goto Exit;

#define PHY_READ(a, b, c, d)        if ((ret = phy_bus_c45_read(a, b, c, d))) goto Exit;
#define PHY_WRITE(a, b, c, d)       if ((ret = phy_bus_c45_write(a, b, c, d))) goto Exit;

/* Command codes */
#define CMD_GET_PAIR_SWAP                           0x8000
#define CMD_SET_PAIR_SWAP                           0x8001
#define CMD_GET_1588_ENABLE                         0x8004
#define CMD_SET_1588_ENABLE                         0x8005
#define CMD_GET_SHORT_REACH_MODE_ENABLE             0x8006
#define CMD_SET_SHORT_REACH_MODE_ENABLE             0x8007
#define CMD_GET_EEE_MODE                            0x8008
#define CMD_SET_EEE_MODE                            0x8009
#define CMD_GET_EMI_MODE_ENABLE                     0x800A
#define CMD_SET_EMI_MODE_ENABLE                     0x800B
#define CMD_GET_SUB_LF_RF_STATUS                    0x800D
#define CMD_GET_SERDES_KR_MODE_ENABLE               0x800E
#define CMD_SET_SERDES_KR_MODE_ENABLE               0x800F
#define CMD_CLEAR_SUB_LF_RF                         0x8010
#define CMD_SET_SUB_LF_RF                           0x8011
#define CMD_READ_INDIRECT_GPHY_REG_BITS             0x8014
#define CMD_WRITE_INDIRECT_GPHY_REG_BITS            0x8015
#define CMD_GET_XFI_2P5G_5G_MODE                    0x8016	
#define CMD_SET_XFI_2P5G_5G_MODE                    0x8017
#define CMD_GET_TWO_PAIR_1G_MODE                    0x8018
#define CMD_SET_TWO_PAIR_1G_MODE                    0x8019
#define CMD_SET_EEE_STATISTICS                      0x801A
#define CMD_GET_EEE_STATISTICS                      0x801B
#define CMD_SET_JUMBO_PACKET                        0x801C
#define CMD_GET_JUMBO_PACKET                        0x801D
#define CMD_GET_MSE                                 0x801E
#define CMD_GET_PAUSE_FRAME_MODE                    0x801F
#define CMD_SET_PAUSE_FRAME_MODE                    0x8020
#define CMD_GET_LED_TYPE                            0x8021
#define CMD_SET_LED_TYPE                            0x8022
#define CMD_GET_MGBASE_T_802_3BZ_TYPE               0x8023
#define CMD_SET_MGBASE_T_802_3BZ_TYPE               0x8024
#define CMD_GET_MSE_GPHY                            0x8025
#define CMD_SET_USXGMII                             0x8026
#define CMD_GET_USXGMII                             0x8027
#define CMD_GET_XL_MODE                             0x8029
#define CMD_SET_XL_MODE                             0x802A
#define CMD_GET_XFI_TX_FILTERS                      0x802B
#define CMD_SET_XFI_TX_FILTERS                      0x802C
#define CMD_GET_XFI_POLARITY                        0x802D
#define CMD_SET_XFI_POLARITY                        0x802E
#define CMD_GET_CURRENT_VOLTAGE                     0x802F
#define CMD_GET_SNR                                 0x8030
#define CMD_GET_CURRENT_TEMP                        0x8031
#define CMD_SET_UPPER_TEMP_WARNING_LEVEL            0x8032
#define CMD_GET_UPPER_TEMP_WARNING_LEVEL            0x8033
#define CMD_SET_LOWER_TEMP_WARNING_LEVEL            0x8034
#define CMD_GET_LOWER_TEMP_WARNING_LEVEL            0x8035
#define CMD_GET_HW_FR_EMI_MODE_ENABLE               0x803A
#define CMD_SET_HW_FR_EMI_MODE_ENABLE               0x803B
#define CMD_GET_CUSTOMER_REQUESTED_TX_PWR_ADJUST    0x8040
#define CMD_SET_CUSTOMER_REQUESTED_TX_PWR_ADJUST    0x8041
#define CMD_GET_DYNAMIC_PARTITION_SELECT            0x8042
#define CMD_SET_DYNAMIC_PARTITION_SELECT            0x8043
#define CMD_RESET_STAT_LOG                          0xC017

/* Command hanlder status codes */
#define CMD_RECEIVED                                0x0001
#define CMD_IN_PROGRESS                             0x0002
#define CMD_COMPLETE_PASS                           0x0004
#define CMD_COMPLETE_ERROR                          0x0008
#define CMD_SYSTEM_BUSY                             0xBBBB

static int _wait_for_cmd_ready(phy_dev_t *phy_dev)
{ 
    int ret, i;
    uint16_t val;

    for (i = 0; i < 1000; i++)
    {
        /* Read status of command */
        PHY_READ(phy_dev, 0x1e, 0x4037, &val);

        if (val != CMD_IN_PROGRESS && val != CMD_SYSTEM_BUSY)
            return 0;

        udelay(2000);
    }

    printk("Timed out waiting for command ready");

Exit:
    return -1;
}

static uint16_t _wait_for_cmd_complete(phy_dev_t *phy_dev)
{ 
    int ret, i;
    uint16_t val = 0;

    for (i = 0; i < 1000; i++)
    {
        /* Read status of command */
        PHY_READ(phy_dev, 0x1e, 0x4037, &val);

        if (val == CMD_COMPLETE_PASS || val == CMD_COMPLETE_ERROR)
            goto Exit;

        udelay(2000);
    }

    printk("Timed out waiting for command complete\n");

Exit:
    return val;
}

static int cmd_handler(phy_dev_t *phy_dev, uint16_t cmd_code, uint16_t *data1, uint16_t *data2, uint16_t *data3, uint16_t *data4, uint16_t *data5)
{	 
    int ret;
    uint16_t cmd_status = 0;

    /* Make sure command interface is open */
    if ((ret = _wait_for_cmd_ready(phy_dev)))
        goto Exit;

	switch (cmd_code)
    {
    case CMD_SET_PAIR_SWAP:
    case CMD_SET_1588_ENABLE:
    case CMD_SET_SHORT_REACH_MODE_ENABLE:
    case CMD_SET_EEE_MODE:		
    case CMD_SET_EMI_MODE_ENABLE:
    case CMD_SET_SERDES_KR_MODE_ENABLE:
    case CMD_CLEAR_SUB_LF_RF:
    case CMD_SET_SUB_LF_RF:
    case CMD_WRITE_INDIRECT_GPHY_REG_BITS:
    case CMD_SET_XFI_2P5G_5G_MODE:
    case CMD_SET_TWO_PAIR_1G_MODE:
    case CMD_SET_PAUSE_FRAME_MODE:
    case CMD_SET_LED_TYPE:
    case CMD_SET_MGBASE_T_802_3BZ_TYPE:
    case CMD_SET_USXGMII:
    case CMD_SET_EEE_STATISTICS:
    case CMD_SET_JUMBO_PACKET:
    case CMD_SET_XL_MODE:
    case CMD_SET_XFI_TX_FILTERS:
    case CMD_SET_XFI_POLARITY:
    case CMD_SET_UPPER_TEMP_WARNING_LEVEL:
    case CMD_SET_LOWER_TEMP_WARNING_LEVEL:
    case CMD_SET_HW_FR_EMI_MODE_ENABLE:
    case CMD_SET_CUSTOMER_REQUESTED_TX_PWR_ADJUST:
    case CMD_SET_DYNAMIC_PARTITION_SELECT:
    {
        if (data1)
            PHY_WRITE(phy_dev, 0x1e, 0x4038, *data1);
        if (data2)
            PHY_WRITE(phy_dev, 0x1e, 0x4039, *data2);
        if (data3)
            PHY_WRITE(phy_dev, 0x1e, 0x403a, *data3);
        if (data4)
            PHY_WRITE(phy_dev, 0x1e, 0x403b, *data4);
        if (data5)
            PHY_WRITE(phy_dev, 0x1e, 0x403c, *data5);

        PHY_WRITE(phy_dev, 0x1e, 0x4005, cmd_code);
        cmd_status = _wait_for_cmd_complete(phy_dev);

        break;
    }
    case CMD_GET_PAIR_SWAP:
    case CMD_GET_1588_ENABLE:
    case CMD_GET_SHORT_REACH_MODE_ENABLE:
    case CMD_GET_EEE_MODE:		
    case CMD_GET_EMI_MODE_ENABLE:
    case CMD_GET_SERDES_KR_MODE_ENABLE:
    case CMD_GET_SUB_LF_RF_STATUS:
    case CMD_GET_XFI_2P5G_5G_MODE:
    case CMD_GET_TWO_PAIR_1G_MODE:
    case CMD_GET_PAUSE_FRAME_MODE:
    case CMD_GET_LED_TYPE:
    case CMD_GET_MGBASE_T_802_3BZ_TYPE:
    case CMD_GET_MSE_GPHY:
    case CMD_GET_USXGMII:
    case CMD_GET_JUMBO_PACKET:
    case CMD_GET_MSE:
    case CMD_GET_XL_MODE:
    case CMD_GET_XFI_TX_FILTERS:
    case CMD_GET_XFI_POLARITY:
    case CMD_GET_CURRENT_VOLTAGE:
    case CMD_GET_SNR:
    case CMD_GET_CURRENT_TEMP:
    case CMD_GET_UPPER_TEMP_WARNING_LEVEL:
    case CMD_GET_LOWER_TEMP_WARNING_LEVEL:
    case CMD_GET_HW_FR_EMI_MODE_ENABLE:
    case CMD_GET_CUSTOMER_REQUESTED_TX_PWR_ADJUST:
    case CMD_GET_DYNAMIC_PARTITION_SELECT:
    case CMD_RESET_STAT_LOG:
    {
        PHY_WRITE(phy_dev, 0x1e, 0x4005, cmd_code);
        cmd_status = _wait_for_cmd_complete(phy_dev);

        if (data1)
            PHY_READ(phy_dev, 0x1e, 0x4038, data1);
        if (data2)
            PHY_READ(phy_dev, 0x1e, 0x4039, data2);
        if (data3)
            PHY_READ(phy_dev, 0x1e, 0x403a, data3);
        if (data4)
            PHY_READ(phy_dev, 0x1e, 0x403b, data4);
        if (data5)
            PHY_READ(phy_dev, 0x1e, 0x403c, data5);

        break;
    }
    case CMD_READ_INDIRECT_GPHY_REG_BITS:
    {
        if (data1)
            PHY_WRITE(phy_dev, 0x1e, 0x4038, *data1);
        if (data2)
            PHY_WRITE(phy_dev, 0x1e, 0x4039, *data2);
        if (data3)
            PHY_WRITE(phy_dev, 0x1e, 0x403a, *data3);
        if (data4)
            PHY_WRITE(phy_dev, 0x1e, 0x403b, *data4);

        PHY_WRITE(phy_dev, 0x1e, 0x4005, cmd_code);
        cmd_status = _wait_for_cmd_complete(phy_dev);

        if (data5)
            PHY_READ(phy_dev, 0x1e, 0x403c, data5);

        break;
    }
    case CMD_GET_EEE_STATISTICS:
    {
        if (data1)
            PHY_WRITE(phy_dev, 0x1e, 0x4038, *data1);

        PHY_WRITE(phy_dev, 0x1e, 0x4005, cmd_code);
        cmd_status = _wait_for_cmd_complete(phy_dev);

        if (data2)
            PHY_READ(phy_dev, 0x1e, 0x4039, data2);
        if (data3)
            PHY_READ(phy_dev, 0x1e, 0x403a, data3);
        if (data4)
            PHY_READ(phy_dev, 0x1e, 0x403b, data4);
        if (data5)
            PHY_READ(phy_dev, 0x1e, 0x403c, data5);

        break;
    }
    default:
        printk("Unsupported cmd code: 0x%x\n", cmd_code);
        break;
    }

    if (cmd_status != CMD_COMPLETE_PASS)
    {
        printk("Failed to execute cmd code: 0x%x\n", cmd_code);
        return -1;
    }

Exit:
    return ret;
}

static int _phy_power_set(phy_dev_t *phy_dev, int enable)
{
    uint16_t val;
    int ret;

    PHY_READ(phy_dev, 0x07, 0xffe0, &val);

    if (enable)
        val &= ~(1 << 11); /* Power up */
    else
        val |= (1 << 11); /* Power down */

    PHY_WRITE(phy_dev, 0x07, 0xffe0, val);

Exit:
    return ret;
}

static int _phy_force_auto_mdix_set(phy_dev_t *phy_dev, int enable)
{
    int ret;
    uint16_t data1, data2, data3, data4, data5;

    data1 = 0x18;
    data2 = 0x07;
    data3 = 0xffff;
    data4 = 0;
    data5 = 0;

    if ((ret = cmd_handler(phy_dev, CMD_READ_INDIRECT_GPHY_REG_BITS, &data1, &data2, &data3, &data4, &data5)))
        goto Exit;

	if (enable)
        data5 |= (1 << 9); /* Auto-MDIX enabled */
    else
        data5 &= ~(1 << 9); /* Auto-MDIX disabled */

    if ((ret = cmd_handler(phy_dev, CMD_WRITE_INDIRECT_GPHY_REG_BITS, &data1, &data2, &data3, &data4, &data5)))
        goto Exit;

Exit:
    return ret;
}

static int _phy_eth_wirespeed_set(phy_dev_t *phy_dev, int enable)
{
    int ret;
    uint16_t data1, data2, data3, data4, data5;

    data1 = 0x18;
    data2 = 0x07;
    data3 = 0xffff;
    data4 = 0;
    data5 = 0;

    if ((ret = cmd_handler(phy_dev, CMD_READ_INDIRECT_GPHY_REG_BITS, &data1, &data2, &data3, &data4, &data5)))
        goto Exit;

	if (enable)
        data5 |= (1 << 4); /* Ethernet@Wirespeed enabled */
    else
        data5 &= ~(1 << 4); /* Ethernet@Wirespeed disabled */

    if ((ret = cmd_handler(phy_dev, CMD_WRITE_INDIRECT_GPHY_REG_BITS, &data1, &data2, &data3, &data4, &data5)))
        goto Exit;

Exit:
    return ret;
}

static int _phy_apd_set(phy_dev_t *phy_dev, int enable)
{
    int ret;
    uint16_t data1, data2, data3, data4, data5;

    data1 = 0x1c;
    data2 = 0x0a;
    data3 = 0xffff;
    data4 = 0;
    data5 = 0;

    if ((ret = cmd_handler(phy_dev, CMD_READ_INDIRECT_GPHY_REG_BITS, &data1, &data2, &data3, &data4, &data5)))
        goto Exit;

	if (enable)
    {
        data5 |= (1 << 5); /* Auto power-down mode enabled */
        data5 |= (1 << 8); /* Enable energy detect single link pulse */
	}
    else
    {
        data5 &= ~(1 << 5); /* Auto power-down mode disabled */
        data5 &= ~(1 << 8); /* Disable energy detect single link pulse */
	}

    if ((ret = cmd_handler(phy_dev, CMD_WRITE_INDIRECT_GPHY_REG_BITS, &data1, &data2, &data3, &data4, &data5)))
        goto Exit;

Exit:
    return ret;
}

static int _phy_eee_get(phy_dev_t *phy_dev, int *enable)
{
    int ret;
    uint16_t val, mask;

    /* EEE Resolution Status */
    PHY_READ(phy_dev, 7, 0x803e, &val);

    /* Check if the link partner auto-negotiated EEE capability */
    mask = SUPPORT_MGBASET ? 0x0e : 0x3e;
    *enable = val & mask ? 1 : 0;

Exit:
    return ret;
}

static int _phy_eee_mode_get(phy_dev_t *phy_dev, uint16_t *mode)
{
    int ret;
    uint16_t data1, data2, data3, data4;

    /* Get EEE mode */
    if ((ret = cmd_handler(phy_dev, CMD_GET_EEE_MODE, &data1, &data2, &data3, &data4, NULL)))
        goto Exit;

    *mode = data1;

Exit:
    return ret;
}

static int _phy_eee_mode_set(phy_dev_t *phy_dev, uint32_t caps)
{
    int ret;
    uint16_t val, data1, data2, data3, data4;
    uint8_t mode;

    val = 0;
    mode = 1; /* Native EEE */

    val |= ((caps & PHY_CAP_100_HALF) || (caps & PHY_CAP_100_FULL)) ? (mode << 2) : 0;
    val |= ((caps & PHY_CAP_1000_HALF) || (caps & PHY_CAP_1000_FULL)) ? (mode << 2) : 0;
    val |= ((caps & PHY_CAP_2500) ? mode << (SUPPORT_MGBASET ? 0 : 6) : 0);
    val |= ((caps & PHY_CAP_5000) ? mode << (SUPPORT_MGBASET ? 0 : 4) : 0);
    val |= ((caps & PHY_CAP_10000)) ? (mode << 0) : 0;

    data1 = val;
    data2 = 0;
    data3 = 0;
    data4 = 0;

    /* Set EEE mode */
    if ((ret = cmd_handler(phy_dev, CMD_SET_EEE_MODE, &data1, &data2, &data3, &data4, NULL)))
        goto Exit;

Exit:
    return ret;
}

int _phy_caps_get(phy_dev_t *phy_dev, uint32_t *pcaps);

static int _phy_eee_set(phy_dev_t *phy_dev, int enable)
{
    int ret;
    uint16_t val;
    uint32_t caps;

    if ((ret = _phy_caps_get(phy_dev, &caps)))
        goto Exit;

    if ((ret = _phy_eee_mode_set(phy_dev, enable ? caps : 0)))
        goto Exit;

    /* Restart auto negotiation to kick off EEE settings */
    PHY_READ(phy_dev, 0x07, 0xffe0, &val);
    val |= (1 << 9);
    PHY_WRITE(phy_dev, 0x07, 0xffe0, val);

Exit:
    return ret;
}

static int _phy_read_status(phy_dev_t *phy_dev)
{
    int ret, mode;
    uint16_t val;
    phy_speed_t speed = phy_dev->speed;

    phy_dev->link = 0;
    phy_dev->speed = PHY_SPEED_UNKNOWN;
    phy_dev->duplex = PHY_DUPLEX_UNKNOWN;
    phy_dev->pause_rx = 0;
    phy_dev->pause_tx = 0;

    /* Read the status register */
    PHY_READ(phy_dev, 0x1e, 0x400d, &val);

    /* Copper link status */
    phy_dev->link = ((val >> 5) & 0x1);

    if (!phy_dev->link)
        goto Exit;

    /* Copper speed */
    mode = ((val >> 2) & 0x7);

    if (mode == 0)
        phy_dev->speed = PHY_SPEED_10;
    else if (mode == 1)
        phy_dev->speed = PHY_SPEED_2500;
    else if (mode == 2)
        phy_dev->speed = PHY_SPEED_100;
    else if (mode == 3)
        phy_dev->speed = PHY_SPEED_5000;
    else if (mode == 4)
        phy_dev->speed = PHY_SPEED_1000;
    else if (mode == 6)
        phy_dev->speed = PHY_SPEED_10000;
    else
        goto Exit;

    if (phy_dev->speed != speed)
    {
        /* Enable pause frame mode in 5GBASE-T mode */
        val = phy_dev->speed == PHY_SPEED_5000 ? 1 : 0;

        if ((ret = cmd_handler(phy_dev, CMD_SET_PAUSE_FRAME_MODE, &val, NULL, NULL, NULL, NULL)))
            goto Exit;
    }

    /* Read the 1000BASE-T auxiliary status summary register */
    PHY_READ(phy_dev, 0x07, 0xfff9, &val);

    if (phy_dev->speed > PHY_SPEED_1000)
    {
        phy_dev->duplex = PHY_DUPLEX_FULL;
    }
    else
    {
        mode = ((val >> 8) & 0x7);

        if (mode == 3 || mode == 6)
            phy_dev->duplex = PHY_DUPLEX_HALF;
        else if (mode == 5 || mode == 7)
            phy_dev->duplex = PHY_DUPLEX_FULL;
    }

    if (phy_dev->speed == PHY_SPEED_5000)
    {
        phy_dev->pause_rx = 1;
        phy_dev->pause_tx = 1;
    }
    else
    {
        phy_dev->pause_rx = ((val >> 1) & 0x1);
        phy_dev->pause_tx = ((val >> 0) & 0x1);
    }

Exit:
    return ret;
}

int _phy_caps_get(phy_dev_t *phy_dev, uint32_t *pcaps)
{
    int ret;
    uint16_t val;
    uint32_t caps = 0;

    /* 1000Base-T/100Base-TX MII control */
    PHY_READ(phy_dev, 0x07, 0xffe0, &val);

    if (val & (1 << 12))
        caps |= PHY_CAP_AUTONEG;

    /* Copper auto-negotiation advertisement */
    PHY_READ(phy_dev, 0x07, 0xffe4, &val);

    if (val & (1 << 10))
        caps |= PHY_CAP_PAUSE;

    if (val & (1 << 7))
        caps |= PHY_CAP_100_HALF;

    if (val & (1 << 8))
        caps |= PHY_CAP_100_FULL;

    /* 1000Base-T control */
    PHY_READ(phy_dev, 0x07, 0xffe9, &val);

    if (val & (1 << 8))
        caps |= PHY_CAP_1000_HALF;

    if (val & (1 << 9))
        caps |= PHY_CAP_1000_FULL;

    if (val & (1 << 10))
        caps |= PHY_CAP_REPEATER;

    /* MGBASE-T AN control */
    PHY_READ(phy_dev, 0x1e, 0x0000, &val);

    if (val & (1 << 1))
        caps |= PHY_CAP_2500;

    if (val & (1 << 2))
        caps |= PHY_CAP_5000;

    /* 10GBase-T AN control */
    PHY_READ(phy_dev, 0x07, 0x0020, &val);

    if (val & (1 << 7))
        caps |= PHY_CAP_2500;

    if (val & (1 << 8))
        caps |= PHY_CAP_5000;

    if (val & (1 << 12))
        caps |= PHY_CAP_10000;

    *pcaps = caps;
Exit:
    return ret;
}

int _phy_caps_set(phy_dev_t *phy_dev, uint32_t caps)
{
    int ret;
    uint16_t val, mode;

    /* Don't advertise 10G speed when the phy does not support it */
    if (!SUPPORT_10GBASET)
        caps &= ~PHY_CAP_10000;

    /* Don't advertise 5G/10G speeds when the mac in HSGMII mode */
    if (phy_dev->mii_type == PHY_MII_TYPE_HSGMII)
        caps &= ~(PHY_CAP_5000 | PHY_CAP_10000);

    /* Don't advertise 2.5G/5G/10G speeds when the mac in SGMII mode */
    if (phy_dev->mii_type == PHY_MII_TYPE_SGMII)
        caps &= ~(PHY_CAP_2500 | PHY_CAP_5000 | PHY_CAP_10000);

    /* Copper auto-negotiation advertisement */
    PHY_READ(phy_dev, 0x07, 0xffe4, &val);

    val &= ~((1 << 7) | (1 << 8) | (1 << 10));

    if (caps & PHY_CAP_100_HALF)
        val |= phy_dev->disable_hd ? 0 : (1 << 7);

    if (caps & PHY_CAP_100_FULL)
        val |= (1 << 8);

    if (caps & PHY_CAP_PAUSE)
        val |= (1 << 10);

    PHY_WRITE(phy_dev, 0x07, 0xffe4, val);

    /* 1000Base-T control */
    PHY_READ(phy_dev, 0x07, 0xffe9, &val);

    val &= ~((1 << 8) | (1 << 9) | (1 << 10));

    if (caps & PHY_CAP_1000_HALF)
        val |= phy_dev->disable_hd ? 0 : (1 << 8);

    if (caps & PHY_CAP_1000_FULL)
        val |= (1 << 9);

    if (caps & PHY_CAP_REPEATER)
        val |= (1 << 10);

    PHY_WRITE(phy_dev, 0x07, 0xffe9, val);

    /* MGBASE-T AN control */
    PHY_READ(phy_dev, 0x1e, 0x0000, &val);

    val &= ~((1 << 0) | (1 << 1) | (1 << 2));

    if (SUPPORT_MGBASET)
    {
        val |= (1 << 0); /* Enable MGBASE-T mode */

        if (caps & PHY_CAP_2500)
            val |= (1 << 1);

        if (caps & PHY_CAP_5000)
            val |= (1 << 2);
    }

    PHY_WRITE(phy_dev, 0x1e, 0x0000, val);

    /* 10GBase-T AN control */
    PHY_READ(phy_dev, 0x07, 0x0020, &val);

    val &= ~((1 << 7) | (1 << 8) | (1 << 12));

    if (!SUPPORT_MGBASET)
    {
        if (caps & PHY_CAP_2500)
            val |= (1 << 7);

        if (caps & PHY_CAP_5000)
            val |= (1 << 8);
    }

    if (caps & PHY_CAP_10000)
        val |= (1 << 12);

    PHY_WRITE(phy_dev, 0x07, 0x0020, val);

    /* 1000Base-T/100Base-TX MII control */
    PHY_READ(phy_dev, 0x07, 0xffe0, &val);

    val &= ~(1 << 12);

    if (caps & PHY_CAP_AUTONEG)
        val |= (1 << 12);

    PHY_WRITE(phy_dev, 0x07, 0xffe0, val);

    if (!(caps & PHY_CAP_AUTONEG))
        goto Exit;

    /* Check if EEE mode is configured */
    if ((ret = _phy_eee_mode_get(phy_dev, &mode)))
        goto Exit;

    /* Reset the EEE mode according to the phy capabilites, if it was set before */
    if (mode && (ret = _phy_eee_mode_set(phy_dev, caps)))
        goto Exit;

    /* Restart auto negotiation */
    val |= (1 << 9);
    PHY_WRITE(phy_dev, 0x07, 0xffe0, val);

Exit:
    return ret;
}

static int _phy_speed_set(phy_dev_t *phy_dev, phy_speed_t speed, phy_duplex_t duplex)
{
    int ret;
    uint32_t caps;

    if (speed == PHY_SPEED_UNKNOWN)
    {
        speed = PHY_SPEED_10000;
        duplex = PHY_DUPLEX_FULL;
    }

    if ((ret = _phy_caps_get(phy_dev, &caps)))
        goto Exit;

    caps &= ~(PHY_CAP_100_HALF | PHY_CAP_100_FULL |
        PHY_CAP_1000_HALF | PHY_CAP_1000_FULL |
        PHY_CAP_2500 | PHY_CAP_5000 | PHY_CAP_10000);

    caps |= PHY_CAP_AUTONEG;

    switch (speed)
    {
    case PHY_SPEED_10000:
        caps |= PHY_CAP_10000;
    case PHY_SPEED_5000:
        caps |= PHY_CAP_5000;
    case PHY_SPEED_2500:
        caps |= PHY_CAP_2500;
    case PHY_SPEED_1000:
        caps |= PHY_CAP_1000_HALF | ((duplex == PHY_DUPLEX_FULL) ? PHY_CAP_1000_FULL : 0);
    case PHY_SPEED_100:
        caps |= PHY_CAP_100_HALF | ((duplex == PHY_DUPLEX_FULL) ? PHY_CAP_100_FULL : 0);
        break;
    default:
        printk("Ignoring unsupported speed\n");
        goto Exit;
        break;
    }

    if ((ret = _phy_caps_set(phy_dev, caps)))
        goto Exit;

Exit:
    return ret;
}

static int _phy_phyid_get(phy_dev_t *phy_dev, uint32_t *phyid)
{
    int ret;
    uint16_t phyid1, phyid2;

    PHY_READ(phy_dev, 0x07, 0xffe2, &phyid1);
    PHY_READ(phy_dev, 0x07, 0xffe3, &phyid2);

    *phyid = phyid1 << 16 | phyid2;

Exit:
    return ret;
}

static int _phy_set_mode(phy_dev_t *phy_dev, int line_side)
{
    int ret;
    uint16_t val1, val2, val3;

    val1 = line_side ? 0x0001 : 0x2004;
    val2 = line_side ? 0x0001 : 0x2004;
    val3 = line_side ? 0x1002 : 0x2004;

    /* Set base-pointer mode */
    PHY_WRITE(phy_dev, 0x1e, 0x4110, val1);
    PHY_WRITE(phy_dev, 0x1e, 0x4111, val2);
    PHY_WRITE(phy_dev, 0x1e, 0x4113, val3);

Exit:
    return ret;
}

static int _phy_init(phy_dev_t *phy_dev)
{
    int ret, i;
    uint16_t val;
    phy_speed_t speed = PHY_SPEED_UNKNOWN;

    /* Reset the phy */
    PHY_WRITE(phy_dev, 0x01, 0x0000, 0x8000);

    /* Verify that the processor is running */
    i = 1000;
    do 
    {
        udelay(2000);
        PHY_READ(phy_dev, 0x01, 0x0000, &val);
        ret = (val != 0x2040);
    } while (ret && i--);

    if (ret)
        goto Exit;

    /* Set base-pointer mode to line side to access PMD/PCS/AN for BASE-T */
    if ((ret = _phy_set_mode(phy_dev, 1)))
        goto Exit;

    /* Enable Force Auto-MDIX mode */
    if ((ret = _phy_force_auto_mdix_set(phy_dev, 1)))
        goto Exit;

    /* Enable Ethernet@Wirespeed mode */
    if ((ret = _phy_eth_wirespeed_set(phy_dev, 1)))
        goto Exit;

    if ((ret = _phy_caps_set(phy_dev, PHY_CAP_PAUSE | PHY_CAP_REPEATER)))
        goto Exit;

    switch (phy_dev->mii_type)
    {
    case PHY_MII_TYPE_SGMII:
        speed = PHY_SPEED_1000;
        break;
    case PHY_MII_TYPE_HSGMII:
        speed = PHY_SPEED_2500;
        break;
    case PHY_MII_TYPE_XFI:
        speed = PHY_SPEED_10000;
        break;
    default:
        printk("Unsupported MII type: %d\n", phy_dev->mii_type);
        break;
    }

    if ((ret = _phy_speed_set(phy_dev, speed, PHY_DUPLEX_FULL)))
        goto Exit;

Exit:
    return ret;
}

extern phy_drv_t phy_drv_ext3;

static int inline _bus_read(uint32_t addr, uint16_t dev, uint16_t reg, uint16_t *val)
{
    return phy_drv_ext3.bus_drv->c45_read(addr, dev, reg, val);
}

static int inline _bus_write(uint32_t addr, uint16_t dev, uint16_t reg, uint16_t val)
{
    return phy_drv_ext3.bus_drv->c45_write(addr, dev, reg, val);
}

static int _bus_read_all(uint32_t phy_map, uint16_t dev, uint16_t reg, uint16_t val, uint32_t mask)
{
    int ret;
    uint32_t i;
    uint16_t _val;

    for (i = 0; i < 32; i++)
    {
        if (!(phy_map & (1 << i)))
            continue;

        if ((ret = _bus_read(i + 1, dev, reg, &_val)))
            return ret;

        if ((_val & mask) != val)
            return -1;
    }

    return 0;
}

static int _bus_write_all(uint32_t phy_map, uint16_t dev, uint16_t reg, uint16_t val)
{
    int ret;
    uint32_t i;

    for (i = 0; i < 32; i++)
    {
        if (!(phy_map & (1 << i)))
            continue;

        if ((ret = _bus_write(i + 1, dev, reg, val)))
            return ret;
    }

    return 0;
}

static int _firmware_load(uint32_t phy_map, unsigned int *firmware_image, unsigned int firmware_size)
{
    int i, cnt, step, ret;

    cnt = firmware_size / sizeof(unsigned int);
    step = cnt / 100;

    /* Download firmware with broadcast mode to up to 32 phys, according to the phy map */
    printk("Loading firmware into phys: map=0x%x\n", phy_map);

    /* 1. Turn on broadcast mode to accept write operations for addr = 0 */
    printk("Turn on broadcast mode to accept write operations\n");

    BUS_WRITE_ALL(phy_map, 0x1e, 0x4117, 0xf003);
    BUS_WRITE_ALL(phy_map, 0x1e, 0x4107, 0x0401);

    /* 2. Halt the BCM848XX processors operation */
    printk("Halt the phys processors operation\n");

    BUS_WRITE_ALL(phy_map, 0x1e, 0x4188, 0x48f0);
    BUS_WRITE_ALL(phy_map, 0x1e, 0x4186, 0x8000);
    BUS_WRITE_ALL(phy_map, 0x1e, 0x4181, 0x017c);
    BUS_WRITE_ALL(phy_map, 0x1e, 0x4181, 0x0040);

    BUS_WRITE(0, 0x01, 0xa819, 0x0000);
    BUS_WRITE(0, 0x01, 0xa81a, 0xc300);
    BUS_WRITE(0, 0x01, 0xa81b, 0x0010);
    BUS_WRITE(0, 0x01, 0xa81c, 0x0000);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x0000);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0x1018);
    BUS_WRITE(0, 0x01, 0xa81c, 0xe59f);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x0004);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0x1f11);
    BUS_WRITE(0, 0x01, 0xa81c, 0xee09);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x0008);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0x0000);
    BUS_WRITE(0, 0x01, 0xa81c, 0xe3a0);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x000c);

    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0x1806);
    BUS_WRITE(0, 0x01, 0xa81c, 0xe3a0);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x0010);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0x0002);
    BUS_WRITE(0, 0x01, 0xa81c, 0xe8a0);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x0014);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0x0001);
    BUS_WRITE(0, 0x01, 0xa81c, 0xe150);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x0018);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0xfffc);
    BUS_WRITE(0, 0x01, 0xa81c, 0x3aff);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x001c);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0xfffe);
    BUS_WRITE(0, 0x01, 0xa81c, 0xeaff);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);
    BUS_WRITE(0, 0x01, 0xa819, 0x0020);
    BUS_WRITE(0, 0x01, 0xa81a, 0xffff);
    BUS_WRITE(0, 0x01, 0xa81b, 0x0021);
    BUS_WRITE(0, 0x01, 0xa81c, 0x0004);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);

    BUS_WRITE_ALL(phy_map, 0x1e, 0x4181, 0x0000);

    /* 3. Upload the firmware into the on-chip memory of the devices */
    printk("Upload the firmware into the on-chip memory\n");

    BUS_WRITE(0, 0x01, 0xa81a, 0x0000);
    BUS_WRITE(0, 0x01, 0xa819, 0x0000);
    BUS_WRITE(0, 0x01, 0xa817, 0x0038);

    for (i = 0; i < cnt; i++)
    {
        BUS_WRITE(0, 0x01, 0xA81C, firmware_image[i] >> 16); /* upper 16 bits */
        BUS_WRITE(0, 0x01, 0xA81B, firmware_image[i] & 0xffff); /* lower 16 bits */

        if (i == i / step * step)
            printk("\r%d%%", i / step);
    }
    printk("\n");

    BUS_WRITE(0, 0x01, 0xa817, 0x0000);
    BUS_WRITE(0, 0x01, 0xa819, 0x0000);
    BUS_WRITE(0, 0x01, 0xa81a, 0xc300);
    BUS_WRITE(0, 0x01, 0xa81b, 0x0000);
    BUS_WRITE(0, 0x01, 0xa81c, 0x0000);
    BUS_WRITE(0, 0x01, 0xa817, 0x0009);

    /* 4. Reset the processors to start execution of the code in the on-chip memory */
    printk("Reset the processors to start execution of the code in the on-chip memory\n");

    BUS_WRITE(0, 0x01, 0xa008, 0x0000);
    BUS_WRITE_ALL(phy_map, 0x1e, 0x8004, 0x5555);
    BUS_WRITE(0, 0x01, 0x0000, 0x8000);

    /* 5. Verify that the processors are running */
    printk("Verify that the processors are running: ");

    i = 1000;
    do 
    {
        udelay(2000);
        ret  = _bus_read_all(phy_map, 0x01, 0x0000, 0x2040, 0xffff);
    } while (ret && i--);

    printk("%s\n", ret ? "Failed" : "OK");

    if (ret)
        goto Exit;

    /* 6. Verify that the firmware has been loaded into the on-chip memory with a good CRC */
    printk("Verify that the firmware has been loaded with good CRC: ");

    i = 1000;
    do 
    {
        udelay(2000);
        ret  = _bus_read_all(phy_map, 0x1e, 0x400d, 0x4000, 0xc000);
    } while (ret && i--);

    printk("%s\n", ret ? "Failed" : "OK");

    if (ret)
        goto Exit;

    printk("Firmware loading completed successfully\n");

Exit:
    return ret;
}

static int _phy_cfg(uint32_t phy_map)
{
    unsigned int *firmware_image = NULL;
    unsigned int firmware_size = 0;
    char *firmware_verison = NULL;

    if (!phy_map)
        return 0;

    printk("BCM848XX phy driver initialization\n");

    if (_bus_read_all(phy_map, 0x07, 0xffe2, 0xae02, 0xffff))
        goto Error;

    if (!_bus_read_all(phy_map, 0x07, 0xffe3, 0x5048, 0xffff))
        bcm848xx_type = BCM84860;
    else if (!_bus_read_all(phy_map, 0x07, 0xffe3, 0x5040, 0xffff))
        bcm848xx_type = BCM84861;
    else if (!_bus_read_all(phy_map, 0x07, 0xffe3, 0x5158, 0xffff))
        bcm848xx_type = BCM84880;
    else if (!_bus_read_all(phy_map, 0x07, 0xffe3, 0x5150, 0xffff))
        bcm848xx_type = BCM84881;
    
    switch (bcm848xx_type)
    {
    case BCM84860:
    case BCM84861:
#ifdef SUPPORT_BCM8486X
        firmware_image = bcm8486x_firmware;
        firmware_size = sizeof(bcm8486x_firmware);
        firmware_verison = bcm8486x_version;
#endif
        break;
    case BCM84880:
    case BCM84881:
#ifdef SUPPORT_BCM8488X
        firmware_image = bcm8488x_firmware;
        firmware_size = sizeof(bcm8488x_firmware);
        firmware_verison = bcm8488x_version;
#endif
        break;
    default:
        goto Error;
        break;
    }

    if (!firmware_image || !firmware_size || !firmware_verison)
    {
        printk("Firmware for this phy was not compiled: type=%d\n", bcm848xx_type);
        return 0;
    }

    printk("Firmware version: %s\n", firmware_verison);
    return _firmware_load(phy_map, firmware_image, firmware_size);

Error:
    printk("Failed to detect supported phys\n");
    return -1;
}

static int _phy_dev_add(phy_dev_t *phy_dev)
{
    enabled_phys |= (1 << (phy_dev->addr - 1));

    return 0;
}

static int _phy_dev_del(phy_dev_t *phy_dev)
{
    enabled_phys &= ~(1 << (phy_dev->addr - 1));

    return 0;
}

static int _phy_drv_init(phy_drv_t *phy_drv)
{
    if (_phy_cfg(enabled_phys))
    {
        printk("Failed to initialize the 848XX driver\n");
        return -1;
    }

    phy_drv->initialized = 1;

    return 0;
}

phy_drv_t phy_drv_ext3 =
{
    .phy_type = PHY_TYPE_EXT3,
    .name = "EXT3",
    .power_set = _phy_power_set,
    .apd_set = _phy_apd_set,
    .eee_get = _phy_eee_get,
    .eee_set = _phy_eee_set,
    .read_status = _phy_read_status,
    .speed_set = _phy_speed_set,
    .caps_get = _phy_caps_get,
    .caps_set = _phy_caps_set,
    .phyid_get = _phy_phyid_get,
    .init = _phy_init,
    .dev_add = _phy_dev_add,
    .dev_del = _phy_dev_del,
    .drv_init = _phy_drv_init,
};
