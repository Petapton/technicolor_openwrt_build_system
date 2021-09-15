/*
<:copyright-BRCM:2013:DUAL/GPL:standard

   Copyright (c) 2013 Broadcom 
   All Rights Reserved

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

#include <linux/gfp.h>
#include <linux/kobject.h>
#include <linux/slab.h>
#include <linux/sysfs.h>
#include "pmc_drv.h"
#include "BPCM.h"
#include "bcm_misc_hw_init.h"

struct bpcm_device {
        unsigned char *name;
        unsigned devno;
        unsigned zones;
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
        unsigned ucbid;
#endif
};

#define UCB_HAS_MST_SLV     (1<<8)
#define UCBID_MASK          0xff

/* device blocks with their device and zone numbers */
static const struct bpcm_device bpcm_devs[] = {
        /* name                dev                         zones                      */
#if defined(CONFIG_BCM963138) || defined(CONFIG_BCM963148)
        { "apm",               PMB_ADDR_APM,               PMB_ZONES_APM               },
        { "switch",            PMB_ADDR_SWITCH,            PMB_ZONES_SWITCH            },
        { "chip_clkrst",       PMB_ADDR_CHIP_CLKRST,       PMB_ZONES_CHIP_CLKRST       },
        { "sata",              PMB_ADDR_SATA,              PMB_ZONES_SATA              },
#if defined(CONFIG_BCM963138)
        { "aip",               PMB_ADDR_AIP,               PMB_ZONES_AIP               },
#elif defined(CONFIG_BCM963148)
        { "urb",               PMB_ADDR_URB,               PMB_ZONES_URB               },
        { "b15_cpu0",          PMB_ADDR_B15_CPU0,          PMB_ZONES_B15_CPU0          },
        { "b15_cpu1",          PMB_ADDR_B15_CPU1,          PMB_ZONES_B15_CPU1          },
        { "b15_l2",            PMB_ADDR_B15_L2,            PMB_ZONES_B15_L2            },
        { "b15_pll",           PMB_ADDR_B15_PLL,           PMB_ZONES_B15_PLL           },
#endif
        { "dect_ubus",         PMB_ADDR_DECT_UBUS,         PMB_ZONES_DECT_UBUS         },
        { "sar",               PMB_ADDR_SAR,               PMB_ZONES_SAR               },
        { "rdp",               PMB_ADDR_RDP,               PMB_ZONES_RDP               },
        { "memc",              PMB_ADDR_MEMC,              PMB_ZONES_MEMC              },
        { "periph",            PMB_ADDR_PERIPH,            PMB_ZONES_PERIPH            },
        { "syspll",            PMB_ADDR_SYSPLL,            PMB_ZONES_SYSPLL            },
        { "rdppll",            PMB_ADDR_RDPPLL,            PMB_ZONES_RDPPLL            },
        { "pcie0",             PMB_ADDR_PCIE0,             PMB_ZONES_PCIE0             },
        { "pcie1",             PMB_ADDR_PCIE1,             PMB_ZONES_PCIE1             },
        { "usb30_2x",          PMB_ADDR_USB30_2X,          PMB_ZONES_USB30_2X          },
        { "vdsl3_mips",        PMB_ADDR_VDSL3_MIPS,        PMB_ZONES_VDSL3_MIPS        },
        { "vdsl3_core",        PMB_ADDR_VDSL3_CORE,        PMB_ZONES_VDSL3_CORE        },
        { "vdsl3_afepll",      AFEPLL_PMB_ADDR_VDSL3_CORE, AFEPLL_PMB_ZONES_VDSL3_CORE },
#elif defined(CONFIG_BCM963381)
        { "chip_clkrst",       PMB_ADDR_CHIP_CLKRST,       PMB_ZONES_CHIP_CLKRST       },
        { "memc",              PMB_ADDR_MEMC,              PMB_ZONES_MEMC              },
        { "mips",              PMB_ADDR_MIPS,              PMB_ZONES_MIPS              },
        { "pcie0",             PMB_ADDR_PCIE0,             PMB_ZONES_PCIE0             },
        { "pcm",               PMB_ADDR_PCM,               PMB_ZONES_PCM               },
        { "periph",            PMB_ADDR_PERIPH,            PMB_ZONES_PERIPH            },
        { "sar",               PMB_ADDR_SAR,               PMB_ZONES_SAR               },
        { "switch",            PMB_ADDR_SWITCH,            PMB_ZONES_SWITCH            },
        { "syspll",            PMB_ADDR_SYSPLL,            PMB_ZONES_SYSPLL            },
        { "syspll1",           PMB_ADDR_SYSPLL1,           PMB_ZONES_SYSPLL1           },
        { "usb2x",             PMB_ADDR_USB2X,             PMB_ZONES_USB2X             },
        { "usb30",             PMB_ADDR_USB30,             PMB_ZONES_USB30             },
        { "vdsl3_afepll",      AFEPLL_PMB_ADDR_VDSL3_CORE, AFEPLL_PMB_ZONES_VDSL3_CORE },
        { "vdsl3_core",        PMB_ADDR_VDSL3_CORE,        PMB_ZONES_VDSL3_CORE        },
        { "vdsl3_mips",        PMB_ADDR_VDSL3_MIPS,        PMB_ZONES_VDSL3_MIPS        },
#elif defined(CONFIG_BCM96848)
        { "usb2x",             PMB_ADDR_USB2X,             PMB_ZONES_USB2X             },
        { "pcie0",             PMB_ADDR_PCIE0,             PMB_ZONES_PCIE0             },
        { "pcm",               PMB_ADDR_PCM,               PMB_ZONES_PCM               },
        { "periph",            PMB_ADDR_PERIPH,            PMB_ZONES_PERIPH            },
        { "chip_clkrst",       PMB_ADDR_CHIP_CLKRST,       PMB_ZONES_CHIP_CLKRST       },
        { "syspll0",           PMB_ADDR_SYSPLL0,           PMB_ZONES_SYSPLL0           },
        { "syspll1",           PMB_ADDR_SYSPLL1,           PMB_ZONES_SYSPLL1           },
        { "mips",              PMB_ADDR_MIPS,              PMB_ZONES_MIPS              },
        { "memc",              PMB_ADDR_MEMC,              PMB_ZONES_MEMC              },
        { "rdp",               PMB_ADDR_RDP,               PMB_ZONES_RDP               },
        { "wan",               PMB_ADDR_WAN,               PMB_ZONES_WAN               },
        { "sgmii",             PMB_ADDR_SGMII,             PMB_ZONES_SGMII             },
#elif defined CONFIG_BCM94908
        { "b53pll",            PMB_ADDR_B53PLL,            PMB_ZONES_B53PLL            },
        { "chip_clkrst",       PMB_ADDR_CHIP_CLKRST,       PMB_ZONES_CHIP_CLKRST       },
        { "crypto",            PMB_ADDR_CRYPTO,            PMB_ZONES_CRYPTO            },
        { "dqm",               PMB_ADDR_DQM,               PMB_ZONES_DQM               },
        { "fpm",               PMB_ADDR_FPM,               PMB_ZONES_FPM               },
        { "gmac",              PMB_ADDR_GMAC,              PMB_ZONES_GMAC              },
        { "i2spll",            PMB_ADDR_I2SPLL,            PMB_ZONES_I2SPLL            },
        { "memc",              PMB_ADDR_MEMC,              PMB_ZONES_MEMC              },
        { "pcie0",             PMB_ADDR_PCIE0,             PMB_ZONES_PCIE0             },
        { "pcie1",             PMB_ADDR_PCIE1,             PMB_ZONES_PCIE1             },
        { "pcie2",             PMB_ADDR_PCIE2,             PMB_ZONES_PCIE2             },
        { "pcm",               PMB_ADDR_PCM,               PMB_ZONES_PCM               },
        { "periph",            PMB_ADDR_PERIPH,            PMB_ZONES_PERIPH            },
        { "rdp",               PMB_ADDR_RDP,               PMB_ZONES_RDP               },
        { "rdppll",            PMB_ADDR_RDPPLL,            PMB_ZONES_RDPPLL            },
        { "sata",              PMB_ADDR_SATA,              PMB_ZONES_SATA              },
        { "sgmii",             PMB_ADDR_SGMII,             PMB_ZONES_SGMII             },
        { "switch",            PMB_ADDR_SWITCH,            PMB_ZONES_SWITCH            },
        { "swtpll",            PMB_ADDR_SWTPLL,            PMB_ZONES_SWTPLL            },
        { "syspll",            PMB_ADDR_SYSPLL,            PMB_ZONES_SYSPLL            },
        { "urb",               PMB_ADDR_URB,               PMB_ZONES_URB               },
        { "usb",               PMB_ADDR_USB,               PMB_ZONES_USB               },
#elif defined(CONFIG_BCM96858)
        { "periph",            PMB_ADDR_PERIPH,            PMB_ZONES_PERIPH,        0                                       },
        { "chip_clkrst",       PMB_ADDR_CHIP_CLKRST,       PMB_ZONES_CHIP_CLKRST,   0                                       },
        { "syspll",            PMB_ADDR_SYSPLL,            PMB_ZONES_SYSPLL,        0                                       },
        { "rdppll",            PMB_ADDR_RDPPLL,            PMB_ZONES_RDPPLL,        0                                       },
        { "unipll",            PMB_ADDR_UNIPLL,            PMB_ZONES_UNIPLL,        0                                       },
#if (CONFIG_BCM_CHIP_REV != 0x6858B0)
        { "apm",               PMB_ADDR_APM,               PMB_ZONES_APM,           UCB_NODE_ID_MST_APM | UCB_HAS_MST_SLV   },
        { "memc",              PMB_ADDR_MEMC,              PMB_ZONES_MEMC,          UCB_NODE_ID_SLV_MEMC                    },
        { "pcie1",             PMB_ADDR_PCIE1,             PMB_ZONES_PCIE1,         UCB_NODE_ID_MST_PCIE1 | UCB_HAS_MST_SLV },
#endif
        { "lport",             PMB_ADDR_LPORT,             PMB_ZONES_LPORT,         UCB_NODE_ID_SLV_LPORT                   },
        { "usb30",             PMB_ADDR_USB30_2X,          PMB_ZONES_USB30_2X,      UCB_NODE_ID_MST_USB | UCB_HAS_MST_SLV   },
        { "wan",               PMB_ADDR_WAN,               PMB_ZONES_WAN,           UCB_NODE_ID_SLV_WAN                     },
        { "xrdp",              PMB_ADDR_XRDP,              PMB_ZONES_XRDP,          0                                       },
        { "xrdp_qm",           PMB_ADDR_XRDP_QM,           PMB_ZONES_XRDP_QM,       0                                       },
        { "xrdp_rc_quad0",     PMB_ADDR_XRDP_RC_QUAD0,     PMB_ZONES_XRDP_RC_QUAD0, 0                                       },
        { "xrdp_rc_quad1",     PMB_ADDR_XRDP_RC_QUAD1,     PMB_ZONES_XRDP_RC_QUAD1, 0                                       },
        { "xrdp_rc_quad2",     PMB_ADDR_XRDP_RC_QUAD2,     PMB_ZONES_XRDP_RC_QUAD2, 0                                       },
        { "xrdp_rc_quad3",     PMB_ADDR_XRDP_RC_QUAD3,     PMB_ZONES_XRDP_RC_QUAD3, 0                                       },
        { "pcie0",             PMB_ADDR_PCIE0,             PMB_ZONES_PCIE0,         UCB_NODE_ID_MST_PCIE0 | UCB_HAS_MST_SLV },
        { "sata",              PMB_ADDR_SATA,              PMB_ZONES_SATA,          UCB_NODE_ID_MST_SATA | UCB_HAS_MST_SLV  },
        { "pcie_ubus",         PMB_ADDR_PCIE_UBUS,         PMB_ZONES_PCIE_UBUS,     UCB_NODE_ID_MST_PCIE2 | UCB_HAS_MST_SLV },
        { "orion_cpu0",        PMB_ADDR_ORION_CPU0,        PMB_ZONES_ORION_CPU0,    0                                       },
        { "orion_cpu1",        PMB_ADDR_ORION_CPU1,        PMB_ZONES_ORION_CPU1,    0                                       },
        { "orion_cpu2",        PMB_ADDR_ORION_CPU2,        PMB_ZONES_ORION_CPU2,    0                                       },
        { "orion_cpu3",        PMB_ADDR_ORION_CPU3,        PMB_ZONES_ORION_CPU3,    0                                       },
        { "orion_noncpu",      PMB_ADDR_ORION_NONCPU,      PMB_ZONES_ORION_NONCPU,  0                                       },
        { "orion_ars",         PMB_ADDR_ORION_ARS ,        PMB_ZONES_ORION_ARS,     0                                       },
        { "biupll",            PMB_ADDR_BIU_PLL,           PMB_ZONES_BIU_PLL,       0                                       },
        { "biu",               PMB_ADDR_BIU_BPCM,          PMB_ZONES_BIU_BPCM,      0                                       },
#elif defined(CONFIG_BCM96836)
        { "periph",            PMB_ADDR_PERIPH,            PMB_ZONES_PERIPH,        0                                       },
        { "chip_clkrst",       PMB_ADDR_CHIP_CLKRST,       PMB_ZONES_CHIP_CLKRST,   0                                       },
        { "syspll",            PMB_ADDR_SYSPLL,            PMB_ZONES_SYSPLL,        0                                       },
        { "rdppll",            PMB_ADDR_RDPPLL,            PMB_ZONES_RDPPLL,        0                                       },
        { "memc",              PMB_ADDR_MEMC,              PMB_ZONES_MEMC,          UCB_NODE_ID_SLV_MEMC                    },
        { "usb30",             PMB_ADDR_USB30_2X,          PMB_ZONES_USB30_2X,      UCB_NODE_ID_MST_USB | UCB_HAS_MST_SLV   },
        { "wan",               PMB_ADDR_WAN,               PMB_ZONES_WAN,           0                                       },
        { "xrdp",              PMB_ADDR_XRDP,              PMB_ZONES_XRDP,          0                                       },
        { "xrdp_rc0",          PMB_ADDR_XRDP_RC0,          PMB_ZONES_XRDP_RC0,      0                                       },
        { "xrdp_rc1",          PMB_ADDR_XRDP_RC1,          PMB_ZONES_XRDP_RC1,      0                                       },
        { "xrdp_rc2",          PMB_ADDR_XRDP_RC2,          PMB_ZONES_XRDP_RC2,      0                                       },
        { "xrdp_rc3",          PMB_ADDR_XRDP_RC3,          PMB_ZONES_XRDP_RC3,      0                                       },
        { "xrdp_rc4",          PMB_ADDR_XRDP_RC4,          PMB_ZONES_XRDP_RC4,      0                                       },
        { "xrdp_rc5",          PMB_ADDR_XRDP_RC5,          PMB_ZONES_XRDP_RC5,      0                                       },
        { "pcie0",             PMB_ADDR_PCIE0,             PMB_ZONES_PCIE0,         0                                       },
        { "pcie1",             PMB_ADDR_PCIE1,             PMB_ZONES_PCIE1,         0                                       },
        { "sata",              PMB_ADDR_SATA,              PMB_ZONES_SATA,          UCB_NODE_ID_MST_SATA | UCB_HAS_MST_SLV  },
        { "pcie_ubus",         PMB_ADDR_PCIE_UBUS,         PMB_ZONES_PCIE_UBUS,     UCB_NODE_ID_MST_SATA | UCB_HAS_MST_SLV  },
#endif
};

/* block common register templates */
static const struct attribute blockreg_attrs[] = {
        { "id",                  0644 }, /* offset = 0x00, actual offset =  0 */
        { "capabilities",        0644 }, /* offset = 0x04, actual offset =  1 */
#if defined(CONFIG_BCM96836)
        { "rsvd2",               0644 }, /* offset = 0x08, actual offset = 2 */
        { "rsvd3",               0644 }, /* offset = 0x0c, actual offset = 3 */
        { "control",             0644 }, /* offset = 0x10, actual offset = 4 */
        { "sr_control",          0644 }, /* offset = 0x14, actual offset = 5 */
        { "rsvd6",               0644 }, /* offset = 0x18, actual offset = 6 */
        { "rsvd7",               0644 }, /* offset = 0x1c, actual offset = 7 */
        { "client_sp0",          0644 }, /* offset = 0x20, actual offset = 8 */
        { "client_sp1",          0644 }, /* offset = 0x24, actual offset = 9 */
        { "client_sp2",          0644 }, /* offset = 0x28, actual offset = 10 */
        { "client_sp3",          0644 }, /* offset = 0x2c, actual offset = 11 */
#else
        { "control",             0644 }, /* offset = 0x08, actual offset =  2 */
        { "status",              0644 }, /* offset = 0x0c, actual offset =  3 */
        { "rosc_control",        0644 }, /* offset = 0x10, actual offset =  4 */
        { "rosc_thresh_h",       0644 }, /* offset = 0x14, actual offset =  5 */
        { "rosc_thresh_s",       0644 }, /* offset = 0x18, actual offset =  6 */
        { "rosc_count",          0644 }, /* offset = 0x1c, actual offset =  7 */
        { "pwd_control",         0644 }, /* offset = 0x20, actual offset =  8 */
        { "pwd_accum_control",   0644 }, /* offset = 0x24, actual offset =  9 */
        { "sr_control",          0644 }, /* offset = 0x28, actual offset = 10 */
        { "global_control",      0644 }, /* offset = 0x2c, actual offset = 11 */
        { "misc_control",        0644 }, /* offset = 0x30, actual offset = 12 */
        { "rsvd13",              0644 }, /* offset = 0x34, actual offset = 13 */
        { "rsvd14",              0644 }, /* offset = 0x38, actual offset = 14 */
        { "rsvd15",              0644 }, /* offset = 0x3c, actual offset = 15 */
#endif
};

/* block common register templates */
static const struct attribute zonereg_attrs[] = {
        { "control",             0644 },
        { "config1",             0644 },
        { "config2",             0644 },
        { "freq_scalar_control", 0644 },
};

/* attribute subclass with device and zone */
struct bpcm_attribute {
        struct attribute attr;
        ssize_t (*show)(struct kobject *kobj, struct kobj_attribute *attr,
                        char *buf);
        ssize_t (*store)(struct kobject *kobj, struct kobj_attribute *attr,
                         const char *buf, size_t count);
        int devno;
        int zoneno;
        int regno;
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
        int ucbid;
#endif
};

static ssize_t power_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
        struct bpcm_attribute *pmc = (struct bpcm_attribute *) attr;
        unsigned zone = pmc->zoneno >= 0 ? pmc->zoneno : 0;
        BPCM_PWR_ZONE_N_CONTROL control;
        int rc;

        rc = ReadZoneRegister(pmc->devno, zone, BPCMZoneRegOffset(control), &control.Reg32);
        if (rc)
                return sprintf(buf, "name %s, dev %d, error %x\n", pmc->attr.name, pmc->devno, rc);
        if (control.Reg32 == 0xdeaddead)
                return sprintf(buf, "%x\n", (unsigned) control.Reg32);
        return sprintf(buf, "%d\n", control.Bits.pwr_on_state);
}

static ssize_t power_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
        struct bpcm_attribute *pmc = (struct bpcm_attribute *) attr;
        unsigned value;

        if (kstrtouint(buf, 0, &value)) {
                printk("%s: not a number\n", buf);
                return -EEXIST;
        }

        if (value) {
                if (pmc->zoneno < 0)
                {
                        PowerOnDevice(pmc->devno);
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
                        ubus_register_port(pmc->ucbid & UCBID_MASK);
                        if (pmc->ucbid & UCB_HAS_MST_SLV)
                            ubus_register_port((pmc->ucbid & UCBID_MASK)+1);
#endif
                }
                else
                        PowerOnZone(pmc->devno, pmc->zoneno);
        } else {
                if (pmc->zoneno < 0)
                {
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
                        ubus_deregister_port(pmc->ucbid);
                        if (pmc->ucbid & UCB_HAS_MST_SLV)
                            ubus_deregister_port((pmc->ucbid & UCBID_MASK)+1);
#endif
                        PowerOffDevice(pmc->devno, 0); // dev, repower
                }
                else
                        PowerOffZone(pmc->devno, pmc->zoneno);
        }
        return count;
}

static ssize_t reset_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
        struct bpcm_attribute *pmc = (struct bpcm_attribute *) attr;
        unsigned zone = pmc->zoneno >= 0 ? pmc->zoneno : 0;
        BPCM_PWR_ZONE_N_CONTROL control;
        int rc;

        rc = ReadZoneRegister(pmc->devno, zone, BPCMZoneRegOffset(control), &control.Reg32);
        if (rc)
                return sprintf(buf, "name %s, dev %d, error %x\n", pmc->attr.name, pmc->devno, rc);
        if (control.Reg32 == 0xdeaddead)
                return sprintf(buf, "%x\n", (unsigned) control.Reg32);
        return sprintf(buf, "%d\n", control.Bits.reset_state);
}

static ssize_t reset_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
        struct bpcm_attribute *pmc = (struct bpcm_attribute *) attr;
        unsigned value;

        if (kstrtouint(buf, 0, &value)) {
                printk("%s: not a number\n", buf);
                return -EEXIST;
        }
        if (value) {
                if (pmc->zoneno < 0)
                        ResetDevice(pmc->devno);
                else
                        ResetZone(pmc->devno, pmc->zoneno);
        }
        return count;
}

/* node templates */
static const struct bpcm_attribute pseudo_attrs[] = {
        { { "power",       0644, }, power_show,       power_store },
        { { "reset",       0644, }, reset_show,       reset_store },
};

static ssize_t regs_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
        struct bpcm_attribute *pmc = (struct bpcm_attribute *) attr;
        uint32 value;
        int rc;

        if (pmc->zoneno < 0)
                rc = ReadBPCMRegister(pmc->devno, pmc->regno, &value);
        else
                rc = ReadZoneRegister(pmc->devno, pmc->zoneno, pmc->regno, &value);
        if (rc == 0)
                return sprintf(buf, "%x\n", (unsigned) value);
        else
                return sprintf(buf, "name %s, dev %d, error %x\n", pmc->attr.name, pmc->devno, rc);
}

static ssize_t regs_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
        struct bpcm_attribute *pmc = (struct bpcm_attribute *) attr;
        uint32 value;
        int rc;

        if (kstrtou32(buf, 0, (u32 *)&value)) {
                printk("%s: not a number\n", buf);
                return -EEXIST;
        }

        if (pmc->zoneno < 0)
                rc = WriteBPCMRegister(pmc->devno, pmc->regno, value);
        else
                rc = WriteZoneRegister(pmc->devno, pmc->zoneno, pmc->regno, value);
        if (rc)
                return 0;
        return count;
}

static int pmc_sysfs_init_zones(const struct bpcm_device *dev, struct kobject *kobj)
{
        unsigned z;
        unsigned r;
        int error;

        for (z = 0; z < dev->zones; z++) {
                unsigned char name[8];
                struct kobject *zoneobj;
                struct bpcm_attribute *pmcattr;

                /* create subdirectory for each zone */
                snprintf(name, sizeof name, "%s%d", "zone", z);
                zoneobj = kobject_create_and_add(name, kobj);
                if (zoneobj == 0)
                        return -ENOENT;

                /* create zone's power and reset nodes */
                r = ARRAY_SIZE(pseudo_attrs);
                pmcattr = kmalloc(r * sizeof *pmcattr, GFP_KERNEL);
                while (r--) {
                        sysfs_attr_init(&pmcattr[r].attr);
                        pmcattr[r] = pseudo_attrs[r];
                        pmcattr[r].devno = dev->devno;
                        pmcattr[r].zoneno = z;
                        pmcattr[r].regno = -1;
                        error = sysfs_create_file(zoneobj, (struct attribute *)&pmcattr[r]);
                }

                /* create some register nodes */
                r = ARRAY_SIZE(zonereg_attrs);
                pmcattr = kmalloc(r * sizeof *pmcattr, GFP_KERNEL);
                while (r--) {
                        sysfs_attr_init(&pmcattr[r].attr);
                        pmcattr[r].attr = zonereg_attrs[r];
                        pmcattr[r].store = regs_store;
                        pmcattr[r].show = regs_show;
                        pmcattr[r].devno = dev->devno;
                        pmcattr[r].zoneno = z;
                        pmcattr[r].regno = r;
                        error = sysfs_create_file(zoneobj, (struct attribute *)&pmcattr[r]);
                }
        }

        return error;
}

static int pmc_sysfs_init_block(const struct bpcm_device *dev, struct kobject *kobj)
{
        struct bpcm_attribute *pmcattr;
        struct kobject *blkobj;
        unsigned r;
        int error;

        /* create subdirectory for each block */
        blkobj = kobject_create_and_add(dev->name, kobj);
        if (blkobj == 0)
                return -ENOMEM;

        /* create block's power and reset nodes */
        if (dev->zones) {
                r = ARRAY_SIZE(pseudo_attrs);
                pmcattr = kmalloc(r * sizeof *pmcattr, GFP_KERNEL);
                while (r--) {
                        sysfs_attr_init(&pmcattr[r].attr);
                        pmcattr[r] = pseudo_attrs[r];
                        pmcattr[r].devno = dev->devno;
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96836)
                        pmcattr[r].ucbid = dev->ucbid;
#endif
                        pmcattr[r].zoneno = -1;
                        pmcattr[r].regno = -1;
                        error = sysfs_create_file(blkobj, (struct attribute *)&pmcattr[r]);
                }
        }

        /* create some register nodes */
        r = ARRAY_SIZE(blockreg_attrs);
        pmcattr = kmalloc(r * sizeof *pmcattr, GFP_KERNEL);
        while (r--) {
                sysfs_attr_init(&pmcattr[r].attr);
                pmcattr[r].attr = blockreg_attrs[r];
                pmcattr[r].store = regs_store;
                pmcattr[r].show = regs_show;
                pmcattr[r].devno = dev->devno;
                pmcattr[r].zoneno = -1;
                pmcattr[r].regno = r;
                error = sysfs_create_file(blkobj, (struct attribute *)&pmcattr[r]);
        }

        return pmc_sysfs_init_zones(dev, blkobj);
}

static ssize_t revision_show(struct kobject *kobj, struct kobj_attribute *kattr, char *buf)
{
        struct attribute *attr = (struct attribute *)kattr;
        int revision;
        int rc;

        rc = GetRevision(&revision);
        if (rc != kPMC_NO_ERROR)
                return sprintf(buf, "name %s, error %x\n", attr->name, rc);
        return sprintf(buf, "%x\n", revision);
}

static int pvtmon_convert(int sel, int value)
{
        switch (sel)  {
#if defined CONFIG_BCM963148 /*pvt2*/
        case 0:  return (38887551 - (466415 * value / 10)) / 100;
#else
        case 0:  return (41004000 - 48705 * value) / 100;
#endif
        case 1:  return (880 * value * 10) / (10 * 1024);
        case 2:  return (880 * value * 10) / (10 * 1024);
        case 3:  return (880 * value * 10) /  (7 * 1024);
        case 4:  return (880 * value * 10) /  (7 * 1024);
        case 5:  return (880 * value * 10) /  (4 * 1024);
        case 6:  return (880 * value * 10) /  (2 * 1024);
        case 8:  return value >> 16;
        default: return 0;
        }
}

static ssize_t pvtmon_show(struct kobject *kobj, struct kobj_attribute *kattr, char *buf)
{
        struct bpcm_attribute *pmc = (struct bpcm_attribute *) kattr;
        int rc, value, convert;

        rc = GetPVT(pmc->regno, &value);
        if (rc != kPMC_NO_ERROR)
                return sprintf(buf, "name %s, error %x\n", pmc->attr.name, rc);

        convert = pvtmon_convert(pmc->regno, value);
        return sprintf(buf, "%d\n", convert);
}

static const struct bpcm_attribute root_attrs[] = {
        { { "revision",    0444, }, revision_show,    NULL          },
        { { "select0",     0444, }, pvtmon_show,      NULL, 0, 0, 0 },
        { { "select1",     0444, }, pvtmon_show,      NULL, 0, 0, 1 },
        { { "select2",     0444, }, pvtmon_show,      NULL, 0, 0, 2 },
        { { "select3",     0444, }, pvtmon_show,      NULL, 0, 0, 3 },
        { { "select4",     0444, }, pvtmon_show,      NULL, 0, 0, 4 },
        { { "select5",     0444, }, pvtmon_show,      NULL, 0, 0, 5 },
        { { "select6",     0444, }, pvtmon_show,      NULL, 0, 0, 6 },
        { { "select8",     0444, }, pvtmon_show,      NULL, 0, 0, 8 },
};

#ifdef CONFIG_PM
extern
#endif
struct kobject *power_kobj;

static int __init pmc_sysfs_init(void)
{
        struct bpcm_attribute *pmcattr;
        struct kobject *bpcmkobj;
        unsigned d;
        int error;

        /* create power object ourselves? */
        if (!power_kobj) {
                power_kobj = kobject_create_and_add("power", NULL);
                if (!power_kobj)
                        return -ENOENT;
        }

        /* create bpcm subdirectory */
        bpcmkobj = kobject_create_and_add("bpcm", power_kobj);
        if (bpcmkobj == 0)
                return -ENOMEM;

        /* create root nodes */
        d = ARRAY_SIZE(root_attrs);
        pmcattr = kmalloc(d * sizeof *pmcattr, GFP_KERNEL);
        while (d--) {
                sysfs_attr_init(&pmcattr[d].attr);
                pmcattr[d] = root_attrs[d];
                error = sysfs_create_file(bpcmkobj, (struct attribute *)&pmcattr[d]);
        }

        for (d = 0; d < ARRAY_SIZE(bpcm_devs); d++)
                pmc_sysfs_init_block(&bpcm_devs[d], bpcmkobj);

        return 0;
}

late_initcall(pmc_sysfs_init);
