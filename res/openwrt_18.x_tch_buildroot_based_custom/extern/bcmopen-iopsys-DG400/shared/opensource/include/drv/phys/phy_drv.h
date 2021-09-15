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
 *  Created on: Dec 2015
 *      Author: yuval.raviv@broadcom.com
 */

#ifndef __PHY_DRV_H__
#define __PHY_DRV_H__

#include "bus_drv.h"

#define PHY_CAP_10_HALF         (1 << 0)
#define PHY_CAP_10_FULL         (1 << 1)
#define PHY_CAP_100_HALF        (1 << 2)
#define PHY_CAP_100_FULL        (1 << 3)
#define PHY_CAP_1000_HALF       (1 << 4)
#define PHY_CAP_1000_FULL       (1 << 5)
#define PHY_CAP_2500            (1 << 6)
#define PHY_CAP_5000            (1 << 7)
#define PHY_CAP_10000           (1 << 8)
#define PHY_CAP_AUTONEG         (1 << 9)
#define PHY_CAP_PAUSE           (1 << 10)
#define PHY_CAP_REPEATER        (1 << 11)

extern int apd_enabled;
extern int eee_enabled;

typedef enum
{
    PHY_SPEED_UNKNOWN,
    PHY_SPEED_10,
    PHY_SPEED_100,
    PHY_SPEED_1000,
    PHY_SPEED_2500,
    PHY_SPEED_5000,
    PHY_SPEED_10000,
} phy_speed_t;

typedef enum
{
    PHY_DUPLEX_UNKNOWN,
    PHY_DUPLEX_HALF,
    PHY_DUPLEX_FULL,
} phy_duplex_t;

typedef enum
{
    PHY_MII_TYPE_UNKNOWN,
    PHY_MII_TYPE_MII,
    PHY_MII_TYPE_TMII,
    PHY_MII_TYPE_GMII,
    PHY_MII_TYPE_RGMII,
    PHY_MII_TYPE_SGMII,
    PHY_MII_TYPE_HSGMII,
    PHY_MII_TYPE_XFI,
    PHY_MII_TYPE_SERDES,
} phy_mii_type_t;

typedef enum
{
    PHY_TYPE_UNKNOWN,
    PHY_TYPE_6848_EPHY,
    PHY_TYPE_6848_EGPHY,
    PHY_TYPE_6848_SGMII,
    PHY_TYPE_PCS,
    PHY_TYPE_6858_EGPHY,
    PHY_TYPE_6836_EGPHY,
    PHY_TYPE_6836_SGMII,
    PHY_TYPE_6836_54810,
    PHY_TYPE_EXT1,
    PHY_TYPE_EXT2,
    PHY_TYPE_EXT3,
    PHY_TYPE_LPORT_SERDES,
    PHY_TYPE_53125,
    PHY_TYPE_PON,
    PHY_TYPE_MAX,
} phy_type_t;

typedef void (*link_change_cb_t)(void *ctx);

/* Phy device */
typedef struct phy_dev_s
{
    struct phy_drv_s *phy_drv;
    struct phy_dev_s *aux_phy;
    phy_mii_type_t mii_type;
    link_change_cb_t link_change_cb;
    void *link_change_ctx;
    uint32_t addr;
    void *priv;
    int link;
    phy_speed_t speed;
    phy_duplex_t duplex;
    int pause_rx;
    int pause_tx;
    int delay_rx;
    int delay_tx;
    int disable_hd;
} phy_dev_t;

/* Phy driver */
typedef struct phy_drv_s
{
    phy_type_t phy_type;
    char *name;
    int initialized;
    bus_drv_t *bus_drv;
    int (*read)(phy_dev_t *phy_dev, uint16_t reg, uint16_t *val);
    int (*write)(phy_dev_t *phy_dev, uint16_t reg, uint16_t val);
    int (*power_set)(phy_dev_t *phy_dev, int enable);
    int (*apd_set)(phy_dev_t *phy_dev, int enable);
    int (*eee_get)(phy_dev_t *phy_dev, int *enable);
    int (*eee_set)(phy_dev_t *phy_dev, int enable);
    int (*read_status)(phy_dev_t *phy_dev);
    int (*speed_set)(phy_dev_t *phy_dev, phy_speed_t speed, phy_duplex_t duplex);
    int (*caps_get)(phy_dev_t *phy_dev, uint32_t *caps);
    int (*caps_set)(phy_dev_t *phy_dev, uint32_t caps);
    int (*phyid_get)(phy_dev_t *phy_dev, uint32_t *phyid);
    int (*init)(phy_dev_t *phy_dev);
    int (*link_change_register)(phy_dev_t *phy_dev);
    int (*link_change_unregister)(phy_dev_t *phy_dev);
    int (*dev_add)(phy_dev_t *phy_dev);
    int (*dev_del)(phy_dev_t *phy_dev);
    int (*drv_init)(struct phy_drv_s *phy_drv);
} phy_drv_t;

typedef struct
{
    char *desc;
    uint16_t reg;
    uint16_t val;
} prog_entry_t;

phy_dev_t *phy_dev_get(phy_type_t phy_type, uint32_t addr);
phy_dev_t *phy_dev_add(phy_type_t phy_type, uint32_t addr, void *priv);
int phy_dev_del(phy_dev_t *phy_dev);

int phy_drivers_set(void);
int phy_drivers_init(void);
int phy_driver_set(phy_drv_t *phy_drv);
int phy_driver_init(phy_type_t phy_type);

char *phy_dev_mii_type_to_str(phy_mii_type_t mii_type);
char *phy_dev_speed_to_str(phy_speed_t speed);
char *phy_dev_duplex_to_str(phy_duplex_t duplex);

void phy_dev_print_status(phy_dev_t *phy_dev);
void phy_dev_prog(phy_dev_t *phy_dev, prog_entry_t *prog_entry);

void phy_dev_link_change_register(phy_dev_t *phy_dev, link_change_cb_t cb, void *ctx);
void phy_dev_link_change_unregister(phy_dev_t *phy_dev);
void phy_dev_link_change_notify(phy_dev_t *phy_dev);

typedef void (*phy_dev_work_func_t)(phy_dev_t *phy_dev);
int phy_dev_queue_work(phy_dev_t *phy_dev, phy_dev_work_func_t func);


static inline int phy_bus_read(phy_dev_t *phy_dev, uint16_t reg, uint16_t *val)
{
    if (!phy_dev->phy_drv->bus_drv)
        return 0;

    return phy_dev->phy_drv->bus_drv->c22_read(phy_dev->addr, reg, val);
}

static inline int phy_bus_write(phy_dev_t *phy_dev, uint16_t reg, uint16_t val)
{
    if (!phy_dev->phy_drv->bus_drv)
        return 0;

    return phy_dev->phy_drv->bus_drv->c22_write(phy_dev->addr, reg, val);
}

static inline int phy_bus_c45_read(phy_dev_t *phy_dev, uint16_t dev, uint16_t reg, uint16_t *val)
{
    if (!phy_dev->phy_drv->bus_drv)
        return 0;

    return phy_dev->phy_drv->bus_drv->c45_read(phy_dev->addr, dev, reg, val);
}

static inline int phy_bus_c45_write(phy_dev_t *phy_dev, uint16_t dev, uint16_t reg, uint16_t val)
{
    if (!phy_dev->phy_drv->bus_drv)
        return 0;

    return phy_dev->phy_drv->bus_drv->c45_write(phy_dev->addr, dev, reg, val);
}

static inline int phy_dev_read(phy_dev_t *phy_dev, uint16_t reg, uint16_t *val)
{
    if (phy_dev->phy_drv->read)
        return phy_dev->phy_drv->read(phy_dev, reg, val);
    else
        return phy_bus_read(phy_dev, reg, val); 
}

static inline int phy_dev_write(phy_dev_t *phy_dev, uint16_t reg, uint16_t val)
{
    if (phy_dev->phy_drv->write)
        return phy_dev->phy_drv->write(phy_dev, reg, val);
    else
        return phy_bus_write(phy_dev, reg, val);
}

static inline int phy_dev_power_set(phy_dev_t *phy_dev, int enable)
{
    if (!phy_dev->phy_drv->power_set)
        return 0;

    return phy_dev->phy_drv->power_set(phy_dev, enable);
}

static inline int phy_dev_apd_set(phy_dev_t *phy_dev, int enable)
{
    if (!phy_dev->phy_drv->apd_set)
        return 0;

    if (!apd_enabled)
        enable = 0;

    return phy_dev->phy_drv->apd_set(phy_dev, enable);
}

static inline int phy_dev_eee_get(phy_dev_t *phy_dev, int *enable)
{
    *enable = 0;

    if (!phy_dev->phy_drv->eee_get)
        return 0;

    if (!eee_enabled)
        return 0;

    return phy_dev->phy_drv->eee_get(phy_dev, enable);
}

static inline int phy_dev_eee_set(phy_dev_t *phy_dev, int enable)
{
    if (!phy_dev->phy_drv->eee_set)
        return 0;

    if (!eee_enabled)
        enable = 0;

    return phy_dev->phy_drv->eee_set(phy_dev, enable);
}

static inline int phy_dev_read_status(phy_dev_t *phy_dev)
{
    int ret = 0;
    phy_speed_t speed = phy_dev->speed;

    if (!phy_dev->phy_drv->read_status)
        goto Exit;

    if ((ret = phy_dev->phy_drv->read_status(phy_dev)))
        goto Exit;

    if (phy_dev->speed == speed)
        goto Exit;

    if (!phy_dev->aux_phy)
        goto Exit;

    if (!phy_dev->aux_phy->phy_drv->speed_set)
        goto Exit;

    if ((ret = phy_dev->aux_phy->phy_drv->speed_set(phy_dev->aux_phy, phy_dev->speed, phy_dev->duplex)))
        goto Exit;

Exit:
    return ret;
}

static inline int phy_dev_speed_set(phy_dev_t *phy_dev, phy_speed_t speed, phy_duplex_t duplex)
{
    if (!phy_dev->phy_drv->speed_set)
        return 0;

    return phy_dev->phy_drv->speed_set(phy_dev, speed, duplex);
}

static inline int phy_dev_caps_get(phy_dev_t *phy_dev, uint32_t *caps)
{
    *caps = 0;

    if (!phy_dev->phy_drv->caps_get)
        return 0;

    return phy_dev->phy_drv->caps_get(phy_dev, caps); 
}

static inline int phy_dev_caps_set(phy_dev_t *phy_dev, uint32_t caps)
{
    if (!phy_dev->phy_drv->caps_set)
        return 0;

    return phy_dev->phy_drv->caps_set(phy_dev, caps);
}

static inline int phy_dev_phyid_get(phy_dev_t *phy_dev, uint32_t *phyid)
{
    *phyid = 0;

    if (!phy_dev->phy_drv->phyid_get)
        return 0;

    return phy_dev->phy_drv->phyid_get(phy_dev, phyid); 
}

static inline int phy_dev_init(phy_dev_t *phy_dev)
{
    if (!phy_dev->phy_drv->init)
        return 0;

    phy_dev->link = 0;
    phy_dev->speed = PHY_SPEED_UNKNOWN;
    phy_dev->duplex = PHY_DUPLEX_UNKNOWN;

    return phy_dev->phy_drv->init(phy_dev) ||
        phy_dev_apd_set(phy_dev, 1) ||
        phy_dev_eee_set(phy_dev, 1);
}

static inline int phy_drv_dev_add(phy_dev_t *phy_dev)
{
    if (phy_dev->phy_drv->initialized)
        return 0;

    if (!phy_dev->phy_drv->dev_add)
        return 0;

    return phy_dev->phy_drv->dev_add(phy_dev);
}

static inline int phy_drv_dev_del(phy_dev_t *phy_dev)
{
    if (phy_dev->phy_drv->initialized)
        return 0;

    if (!phy_dev->phy_drv->dev_del)
        return 0;

    return phy_dev->phy_drv->dev_del(phy_dev);
}

static inline int phy_drv_init(phy_drv_t *phy_drv)
{
    if (phy_drv->initialized)
        return 0;

    if (!phy_drv->drv_init)
        return 0;

    return phy_drv->drv_init(phy_drv);
}

#endif
