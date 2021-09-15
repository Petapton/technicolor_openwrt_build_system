/*
* <:copyright-BRCM:2013:DUAL/GPL:standard
* 
*    Copyright (c) 2013 Broadcom 
*    All Rights Reserved
* 
* Unless you and Broadcom execute a separate written software license
* agreement governing use of this software, this software is licensed
* to you under the terms of the GNU General Public License version 2
* (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
* with the following added to such license:
* 
*    As a special exception, the copyright holders of this software give
*    you permission to link this software with independent modules, and
*    to copy and distribute the resulting executable under terms of your
*    choice, provided that you also meet, for each linked independent
*    module, the terms and conditions of the license of that module.
*    An independent module is a module which is not derived from this
*    software.  The special exception does not apply to any modifications
*    of the software.
* 
* Not withstanding the above, under no circumstances may you combine
* this software in any way with any other Broadcom software provided
* under a license other than the GPL, without Broadcom's express prior
* written consent.
* 
* :>
*/

#include "bcm_OS_Deps.h"
#include <linux/bcm_log.h>
#include <rdpa_api.h>
#include <rdpa_epon.h>
#include <autogen/rdpa_ag_epon.h>
#include <linux/blog_rule.h>
#include "boardparms.h"
#include "board.h"
#include "clk_rst.h"
#include "wan_drv.h"
#ifdef CONFIG_BCM_TIME_SYNC_MODULE
#include "time_sync.h"
#endif
//TODO:Remove the FTTD runner code when ready
#if defined(G9991)
#include "access_macros.h"
#endif

/* init system params */
#define BP_NO_EXT_SW 30
#define RDPA_SWITCHING_MODE_PSP_KEY "SwitchingMode"
#define RDPA_IPCLASS_METHOD_PSP_KEY "IpClassMethod"
#define RDPA_US_DDR_QUEUE_ENABLE "UsDDRQueueEn"

typedef enum
{
    mw_wan_rate_none,
    mw_wan_rate_1g,
    mw_wan_rate_2_5g,
    mw_wan_rate_10g
}mw_wan_rate;

typedef enum
{
    mw_wan_type_none,
    mw_wan_type_gbe,
    mw_wan_type_epon_ae,
    mw_wan_type_epon,
    mw_wan_type_gpon,
    mw_wan_type_xgpon1,
    mw_wan_type_ngpon2,
    mw_wan_type_xgs,
    mw_wan_type_auto
}mw_wan_type;

static int emac_map = 0;
static int emacs_num = 0;
static int ext_sw_pid = BP_NO_EXT_SW;
#if !defined(CONFIG_BCM963138) && !defined(CONFIG_BCM963148) && !defined(CONFIG_BCM94908)
/* scratchpad defaults */
char *wan_default_type = "GPON";
static char *wan_oe_default_emac = "EMAC0";
char *epon_default_speed = EPON_SPEED_NORMAL;
char *wan_default_rate = "0101";

#define base(x) ((x >= '0' && x <= '9') ? '0' : \
    (x >= 'a' && x <= 'f') ? 'a' - 10 : \
    (x >= 'A' && x <= 'F') ? 'A' - 10 : \
    '\255')

#define TOHEX(x) (x - base(x))
#endif

static int rdpa_get_init_system_bp_params(void)
{
    int rc = 0;
    int i, cnt;
    const ETHERNET_MAC_INFO* EnetInfos;
    EnetInfos = BpGetEthernetMacInfoArrayPtr();
    if (EnetInfos == NULL)
        return rc;

    emac_map = EnetInfos[0].sw.port_map & 0xFF;
    for (i = 0; i < BP_MAX_SWITCH_PORTS; ++i)
    {
        if (((1<<i) & emac_map) && ((int)EnetInfos[0].sw.phy_id[i] & EXTSW_CONNECTED))
            ext_sw_pid = i;
    }
    if (EnetInfos[0].ucPhyType != BP_ENET_NO_PHY)
    {
        bitcount(cnt, EnetInfos[0].sw.port_map);
        emacs_num += cnt;
    }

    return rc;
}

#if !defined(CONFIG_BCM963138) && !defined(CONFIG_BCM963148) && !defined(CONFIG_BCM94908)
static int scratchpad_get_or_init(char *sp_key, char *buf, int max_len,
    char *default_val, int init_only)
{
    int count = 0;

    if (!init_only)
    {
        count = kerSysScratchPadGet(sp_key, buf, max_len - 1);
        if (count > 0)
            buf[count] = '\0';
    }

    /* init_only or read from scratch pad failed */
    if (count <= 0)
    {
        count = kerSysScratchPadSet(sp_key, default_val, strlen(default_val));
        init_only = 1;
        if (count)
        {
            printk("Could not set PSP %s to %s, rc=%d", sp_key, default_val,
                    count);
            return count;
        }

        if (buf)
            strncpy(buf, default_val, max_len);
    }

    printk("scratchpad %s%s - %s \n", init_only ? "init " : "", sp_key, buf ? :
            default_val);

    return 0;
}

static int rdpa_pon_car_mode_cfg(void)
{
    int rc;
    rdpa_system_init_cfg_t init_cfg;
    rdpa_system_cfg_t sys_cfg;
    bdmf_object_handle system_obj;

    rc = rdpa_system_get(&system_obj);
    if (rc)
    {
        printk("%s %s Failed to get RDPA System object rc(%d)\n", __FILE__, __FUNCTION__, rc);
        return rc;
    }

    rc = rdpa_system_cfg_get(system_obj, &sys_cfg);
    if (rc)
    {
        printk("Failed to getting RDPA System cfg\n");
        goto Exit;
    }

    rc = rdpa_system_init_cfg_get(system_obj, &init_cfg);
    if (rc)
    {
        printk("Failed to getting RDPA System init cfg\n");
        goto Exit;
    }

    if (init_cfg.ip_class_method == rdpa_method_fc)
        sys_cfg.car_mode = 1;
    else
        sys_cfg.car_mode = 0;

    rc = rdpa_system_cfg_set(system_obj, &sys_cfg);
    if(rc)
        printk("%s %s Failed to set RDPA System car mode rc(%d)\n", __FILE__, __FUNCTION__, rc);

Exit:
    if (system_obj)
        bdmf_put(system_obj);

    return rc;
}

serdes_wan_type_t wan_to_serdes_wan_type(mw_wan_type wan_type, mw_wan_rate dn_rate, 
        mw_wan_rate up_rate)
{
    serdes_wan_type_t rc_wan_type = SERDES_WAN_TYPE_NONE;
    switch (wan_type)
    {
        case mw_wan_type_gpon:
            rc_wan_type = SERDES_WAN_TYPE_GPON;
            break;
        case mw_wan_type_xgpon1:
            rc_wan_type = SERDES_WAN_TYPE_XGPON_10G_2_5G;
            break;
        case mw_wan_type_ngpon2:
            if ((dn_rate == mw_wan_rate_10g) && (up_rate == mw_wan_rate_10g))
                rc_wan_type = SERDES_WAN_TYPE_NGPON_10G_10G;
            else if ((dn_rate == mw_wan_rate_10g) && (up_rate == mw_wan_rate_2_5g))
                rc_wan_type = SERDES_WAN_TYPE_NGPON_10G_2_5G;
            else
            {
                printk("Scratchpad: WAN type set to NGPON2 with an invalid WAN rate. Reverting to 10/10\n");
                rc_wan_type = SERDES_WAN_TYPE_NGPON_10G_10G;
            }
            break;
        case mw_wan_type_xgs:
            if ((dn_rate == mw_wan_rate_10g) && (up_rate == mw_wan_rate_10g))
                rc_wan_type = SERDES_WAN_TYPE_NGPON_10G_10G;
            else if ((dn_rate == mw_wan_rate_10g) && (up_rate == mw_wan_rate_2_5g))
                rc_wan_type = SERDES_WAN_TYPE_NGPON_10G_2_5G;
            else
            {
                printk("Scratchpad: WAN type set to XGS with an invalid WAN rate. Reverting to 10/10\n");
                rc_wan_type = SERDES_WAN_TYPE_NGPON_10G_10G;
            }
            break;
        case mw_wan_type_epon:
            rc_wan_type = (dn_rate == mw_wan_rate_10g) ? 
                ((up_rate == mw_wan_rate_10g) ? SERDES_WAN_TYPE_EPON_10G_SYM : SERDES_WAN_TYPE_EPON_10G_ASYM) : 
                ((dn_rate == mw_wan_rate_2_5g) ? SERDES_WAN_TYPE_EPON_2G : SERDES_WAN_TYPE_EPON_1G);
            break;
        case mw_wan_type_epon_ae:
            if ((dn_rate == mw_wan_rate_10g) && (up_rate == mw_wan_rate_10g))
                rc_wan_type = SERDES_WAN_TYPE_AE_10G;
            else if ((dn_rate == mw_wan_rate_1g) && (up_rate == mw_wan_rate_1g))
                rc_wan_type = SERDES_WAN_TYPE_AE;
            else if ((dn_rate == mw_wan_rate_2_5g) && (up_rate == mw_wan_rate_2_5g))
                rc_wan_type = SERDES_WAN_TYPE_AE_2_5G;
            else
                printk("Scratchpad: WAN type set to EPON AE mode with an invalid WAN rate.\n");
            break;
        case mw_wan_type_gbe:
            rc_wan_type = SERDES_WAN_TYPE_AE;
            break;
        default:
            break;
    }

    return rc_wan_type;
}

rdpa_wan_type wan_to_rdpa_wan_type (mw_wan_type wan_type, 
			mw_wan_rate up_rate)
{
    rdpa_wan_type rc_wan_type = rdpa_wan_none;
    switch (wan_type)
    {
        case mw_wan_type_gbe:
            rc_wan_type = rdpa_wan_gbe;
            break;
        case mw_wan_type_epon:
            rc_wan_type = (up_rate == mw_wan_rate_10g) ? 
				rdpa_wan_xepon : rdpa_wan_epon;
            break;
        case mw_wan_type_epon_ae:
            rc_wan_type = rdpa_wan_xepon_ae;
            break;
        case mw_wan_type_gpon:
            rc_wan_type = rdpa_wan_gpon;
            break;
        case mw_wan_type_xgpon1:
        case mw_wan_type_ngpon2:
        case mw_wan_type_xgs:
            rc_wan_type = rdpa_wan_xgpon;
            break;
        default:
            break;
    }

    return rc_wan_type;
}

int wan_scratchpad_get(mw_wan_type *wan_type, mw_wan_rate *dn_rate, 
			mw_wan_rate* up_rate, rdpa_emac *wan_emac)
{
    int rc;
    char buf[PSP_BUFLEN_16];
#define RATE_STR_LEN 2
#define PSP_RATE_STR_LEN 4
    
    *wan_type = mw_wan_type_none;
    if (wan_emac)
        *wan_emac = rdpa_emac_none;

    rc = scratchpad_get_or_init(RDPA_WAN_RATE_PSP_KEY, buf, sizeof(buf), wan_default_rate, 0);
    if (!rc)
    {/* WanRate is not necessary for non-10G platform*/
        if (strlen(buf) >= PSP_RATE_STR_LEN)
        {
            if (!strncmp(buf, RDPA_WAN_RATE_10G, RATE_STR_LEN))
                *dn_rate = mw_wan_rate_10g;
            else if(!strncmp(buf, RDPA_WAN_RATE_2_5G, RATE_STR_LEN))
                *dn_rate = mw_wan_rate_2_5g;
            else if(!strncmp(buf, RDPA_WAN_RATE_1G, RATE_STR_LEN))
                *dn_rate = mw_wan_rate_1g;
            else
                *dn_rate = mw_wan_rate_1g;
        
            if (!strncmp(&buf[RATE_STR_LEN], RDPA_WAN_RATE_10G, RATE_STR_LEN))
                *up_rate = mw_wan_rate_10g;
            else if (!strncmp(&buf[RATE_STR_LEN], RDPA_WAN_RATE_2_5G, RATE_STR_LEN))
                *up_rate = mw_wan_rate_2_5g;
            else if (!strncmp(&buf[RATE_STR_LEN], RDPA_WAN_RATE_1G, RATE_STR_LEN))
                *up_rate = mw_wan_rate_1g;
            else 
                *up_rate = mw_wan_rate_1g;
        }
    }

    rc = scratchpad_get_or_init(RDPA_WAN_TYPE_PSP_KEY, buf, sizeof(buf), wan_default_type, 0);
    if (rc)
        return rc;

    if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_GBE))
    {
        *wan_type = mw_wan_type_gbe;
        rc = scratchpad_get_or_init(RDPA_WAN_OEMAC_PSP_KEY, buf, sizeof(buf), wan_oe_default_emac, 0);
        if (rc)
            return rc;

        if (!strncmp(buf ,"EMAC",4) && (strlen(buf) == strlen("EMACX")))
        {
            if (wan_emac)
                *wan_emac = (rdpa_emac)(TOHEX(buf[4]));
        }
        else if(!strcmp(buf ,"EPONMAC"))
        {
          *wan_type = mw_wan_type_epon_ae;
        }
        else
        {
            printk("%s %s Wrong EMAC string in ScrachPad - ###(%s)###\n", __FILE__, __FUNCTION__, buf);
            return -1;
        }
    }
    /* saved for backward compatibility */
    else if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_AE))
    {
        *wan_type = mw_wan_type_gbe;
        rc = scratchpad_get_or_init(RDPA_WAN_TYPE_PSP_KEY, NULL, 0, "GBE", 1);
        if (rc)
            return rc;
        rc = scratchpad_get_or_init(RDPA_WAN_OEMAC_PSP_KEY, NULL, 0, "EMAC5", 1);
        if (rc)
            return rc;
        
        if (wan_emac)
            *wan_emac = rdpa_emac5;
    }
    else if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_GPON))
        *wan_type = mw_wan_type_gpon;
    else if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_XGPON1))
    {
        *wan_type = mw_wan_type_xgpon1;
    }
    else if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_NGPON2))
    {
        *wan_type = mw_wan_type_ngpon2;
    }
    else if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_XGS))
    {
        *wan_type = mw_wan_type_xgs;
    }
    else if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_EPON))
    {
        *wan_type = mw_wan_type_epon;
        
        if (*dn_rate == mw_wan_rate_none) 
        {/* WanRate has higher priority, if it's valid, ignore epon_speed configuration */
            rc = scratchpad_get_or_init(RDPA_EPON_SPEED_PSP_KEY, buf, sizeof(buf), epon_default_speed, 0);
            if (rc)
                return rc;
            
            if (!strcmp(buf, EPON_SPEED_TURBO))
                *dn_rate = mw_wan_rate_2_5g;
            else
                *dn_rate = mw_wan_rate_1g;
        }
    }
    else if (!strcmp(buf ,RDPA_WAN_TYPE_VALUE_AUTO))
        return 0; /* returns wan_type = rdpa_wan_none */

    /* Scratchpad string not identified */
    if (*wan_type == mw_wan_type_none)
        return -1;

    return 0;
}

int switching_mode_get(rdpa_vlan_switching *switching_mode, rdpa_wan_type wan_type)
{
#ifndef BRCM_CMS_BUILD
    char buf[PSP_BUFLEN_16];
#endif
    char switchDefault[16];

    *switching_mode = rdpa_switching_none;
    strcpy(switchDefault, "NONE");

#if defined(CONFIG_EPON_SFU)
    if (wan_type == rdpa_wan_epon || wan_type == rdpa_wan_xepon || wan_type == rdpa_wan_xepon_ae)
    {
        *switching_mode = rdpa_mac_based_switching;
        strcpy(switchDefault, "MAC");
    }
#endif

#ifndef BRCM_CMS_BUILD
    scratchpad_get_or_init(RDPA_SWITCHING_MODE_PSP_KEY, buf, sizeof(buf), switchDefault, 0);

    if (!strcmp(buf ,"NONE"))
    {
        *switching_mode = rdpa_switching_none;
    }
    else if (!strcmp(buf ,"MAC"))
    {
        *switching_mode = rdpa_mac_based_switching;
    }
    else if (!strcmp(buf ,"VLAN"))
    {
        *switching_mode = rdpa_vlan_aware_switching;
    }
#endif

    return 0;
}

int ipclass_method_get(rdpa_ip_class_method *ipclass_method)
{

    char buf[PSP_BUFLEN_16];
    char ipClassDefault[16];

#if defined(CONFIG_GPON_SFU) || defined(CONFIG_EPON_SFU)
    *ipclass_method = rdpa_method_none;
    strcpy(ipClassDefault, "NONE");
#else
    *ipclass_method = rdpa_method_fc;
    strcpy(ipClassDefault, "FC");
#endif

    scratchpad_get_or_init(RDPA_IPCLASS_METHOD_PSP_KEY, buf, sizeof(buf), ipClassDefault, 0);

    if (!strcmp(buf ,"NONE"))
    {
        *ipclass_method = rdpa_method_none;
    }
    else if (!strcmp(buf ,"FC"))
    {
        *ipclass_method = rdpa_method_fc;
    }
    else if (!strcmp(buf ,"MIXED"))
    {
        *ipclass_method = rdpa_method_mixed;
    }

    return 0;
}

#ifndef BRCM_CMS_BUILD
static int us_ddr_queue_enable_get(bdmf_boolean * us_ddr_queue_enable)
{
    int rc = 0;
    char buf[6];
    char usDDRQueueEnableDefault[6];

    *us_ddr_queue_enable = BDMF_FALSE;

    strcpy(usDDRQueueEnableDefault, "NO");
    rc = scratchpad_get_or_init(RDPA_US_DDR_QUEUE_ENABLE, buf, sizeof(buf), usDDRQueueEnableDefault, 0);   
    if (rc)
        return rc;

    if (!strcmp(buf ,"YES"))
    {
        *us_ddr_queue_enable = BDMF_TRUE;
    }

    return rc;
}
#endif

int rdpa_init_system_fiber(void)
{
    mw_wan_rate dn_rate = mw_wan_rate_none;
    mw_wan_rate up_rate = mw_wan_rate_none;
    mw_wan_type wan_type;
    rdpa_wan_type wan_rdpa_type;
    serdes_wan_type_t serdes_wan_type;
    int rc;
    rdpa_emac wan_emac;
    bdmf_object_handle rdpa_system=NULL;
    rdpa_system_init_cfg_t sys_init_cfg={};

    rc = wan_scratchpad_get(&wan_type, &dn_rate, &up_rate, &wan_emac);
    if (rc)
        return rc;

    serdes_wan_type = wan_to_serdes_wan_type(wan_type, dn_rate, up_rate);
    if (serdes_wan_type == SERDES_WAN_TYPE_NONE)
    {
    	printk("%s:%d wan_type not fiber\n", __FUNCTION__, __LINE__);
    	return -1;
    }

    /* some cases need more condition */
    if ((serdes_wan_type == SERDES_WAN_TYPE_AE) && (wan_emac != rdpa_emac5) && (wan_type != mw_wan_type_epon_ae))
        return 0;

    rc = wan_serdes_config(serdes_wan_type);
    if (rc)
        return rc;

    wan_rdpa_type = wan_to_rdpa_wan_type(wan_type, up_rate);
    if (wan_rdpa_type == rdpa_wan_gpon || wan_rdpa_type == rdpa_wan_epon || 
		wan_rdpa_type == rdpa_wan_xgpon || wan_rdpa_type == rdpa_wan_xepon ||
		wan_rdpa_type == rdpa_wan_xepon_ae)
    {
        rc = rdpa_pon_car_mode_cfg();
        if (rc)
            printk("%s %s Failed to configure rdpa pon car mode rc(%d)\n", __FILE__, __FUNCTION__, rc);
    }

    /* CMS MCPD is expected to work with group_ip_src_ip only in GPON SFU */
    if (rdpa_system_get(&rdpa_system)) {
       printk("%s:%d failed to get BDMF system object rc=%d\n", __FUNCTION__, __LINE__, rc);
       return -1;
    }
    rdpa_system_init_cfg_get(rdpa_system, &sys_init_cfg);
    bdmf_put(rdpa_system);
    if ((wan_rdpa_type == rdpa_wan_gpon || wan_rdpa_type == rdpa_wan_xgpon) && 
		sys_init_cfg.ip_class_method == rdpa_method_none)
    {
        bdmf_object_handle iptv;

        rc = rdpa_iptv_get(&iptv);
        /* Do nothing if there is no iptv system object. */
        if (rc) {
           printk("%s:%d No IPTV object to configure rc=%d\n", __FUNCTION__, __LINE__, rc);
            return 0;
        } 
        rdpa_iptv_lookup_method_set(iptv, iptv_lookup_method_group_ip_src_ip);
        bdmf_put(iptv);
    }
    
    return rc;
}
EXPORT_SYMBOL(rdpa_init_system_fiber);

int rdpa_init_system(void)
{
    BDMF_MATTR(rdpa_system_attrs, rdpa_system_drv());
    bdmf_object_handle rdpa_system_obj = NULL;
    bdmf_object_handle rdpa_filter_obj = NULL;
    bdmf_object_handle rdpa_tc_to_queue_obj = NULL;
    bdmf_object_handle rdpa_pbit_to_queue_obj = NULL;
    BDMF_MATTR(rdpa_filter_attrs, rdpa_filter_drv());
    BDMF_MATTR(rdpa_tc_to_queue_attrs, rdpa_tc_to_queue_drv());
    BDMF_MATTR(rdpa_pbit_to_queue_attrs, rdpa_pbit_to_queue_drv());
#if defined(G9991) && !defined(XRDP)
    uint32_t fttdp_addr, fttdp_val;
#endif
    int rc,i;
    rdpa_system_init_cfg_t sys_init_cfg = {};
#ifdef XRDP
    bdmf_object_handle rdpa_cpu_port_obj = NULL;
    BDMF_MATTR(rdpa_port_attrs, rdpa_port_drv());
#endif

    mw_wan_type wan_type;
    rdpa_system_cfg_t sys_cfg = {};
    bdmf_object_handle cpu =  NULL;
    mw_wan_rate dn_rate = mw_wan_rate_none;
    mw_wan_rate up_rate = mw_wan_rate_none;

    rc = rdpa_get_init_system_bp_params();
    rc = rc ? : wan_scratchpad_get(&wan_type, &dn_rate, &up_rate, &sys_init_cfg.gbe_wan_emac);
    if (rc)
        goto exit;

    sys_cfg.mtu_size = RDPA_MTU;

#ifndef XRDP
    sys_cfg.inner_tpid = 0x8100;
    sys_cfg.outer_tpid = 0x88a8;
#else
    sys_cfg.ic_dbg_stats = 1;
#endif
    sys_cfg.car_mode = 1;
    
    /* GBE EMAC5 cannot be configured in system init, must be configed later via port object! */
    if (sys_init_cfg.gbe_wan_emac == rdpa_emac5)
        sys_init_cfg.gbe_wan_emac = rdpa_emac_none;

    sys_init_cfg.enabled_emac = emac_map;

    sys_init_cfg.runner_ext_sw_cfg.emac_id = (ext_sw_pid == BP_NO_EXT_SW) ? rdpa_emac_none:(rdpa_emac)ext_sw_pid;
    sys_init_cfg.runner_ext_sw_cfg.enabled = (ext_sw_pid == BP_NO_EXT_SW) ? 0 : 1;
#if defined(G9991)
    sys_init_cfg.runner_ext_sw_cfg.enabled = 1;
    sys_init_cfg.runner_ext_sw_cfg.type = rdpa_brcm_fttdp;
#else
    sys_init_cfg.runner_ext_sw_cfg.type = rdpa_brcm_hdr_opcode_0;
#endif

    rc = switching_mode_get(&sys_init_cfg.switching_mode, wan_to_rdpa_wan_type(wan_type, up_rate));
    if (rc)
        goto exit;

    rc = ipclass_method_get(&sys_init_cfg.ip_class_method);
    if (rc)
        goto exit;
        
#ifndef BRCM_CMS_BUILD
    rc = us_ddr_queue_enable_get(&sys_init_cfg.us_ddr_queue_enable);
    if (rc)
        goto exit;
#endif

    rdpa_system_cfg_set(rdpa_system_attrs, &sys_cfg);
    rdpa_system_init_cfg_set(rdpa_system_attrs, &sys_init_cfg);

    rc = bdmf_new_and_set(rdpa_system_drv(), NULL, rdpa_system_attrs, &rdpa_system_obj);
    if (rc)
    {
        printk("%s %s Failed to create rdpa system object rc(%d)\n", __FILE__, __FUNCTION__, rc);
        goto exit;
    }

#ifdef XRDP
    rdpa_port_index_set(rdpa_port_attrs, rdpa_if_cpu);
    rc = bdmf_new_and_set(rdpa_port_drv(), NULL, rdpa_port_attrs, &rdpa_cpu_port_obj);
    if (rc < 0)
    {
        BDMF_TRACE_ERR("Failed to create cpu port object\n");
        goto exit;
    }
#endif

    rc = rdpa_cpu_get(rdpa_cpu_host, &cpu);

    /*CPU Interrupts are no longer automatically connected as part of CPU object
     *creation. They need to be explicitly using below rdpa call.*/
    rc = rc ? rc : rdpa_cpu_int_connect_set(cpu, 1 /*true*/);
    if (rc < 0)
    {
        BDMF_TRACE_ERR("Failed to connect cpu interrupts\n");
        goto exit;
    }

#ifdef XRDP
    rc = rdpa_port_cpu_obj_set(rdpa_cpu_port_obj, cpu);
    if (rc)
    {
        BDMF_TRACE_ERR("Failed to connect cpu port object and cpu host object\n");
        goto exit;
    }
#endif

    rc = bdmf_new_and_set(rdpa_filter_drv(), NULL, rdpa_filter_attrs, &rdpa_filter_obj);
    if (rc)
        printk("%s %s Failed to create rdpa filter object rc(%d)\n", __FILE__, __FUNCTION__, rc);

    /* Configure tc to q table - id 0 direction DS */
    rdpa_tc_to_queue_table_set(rdpa_tc_to_queue_attrs, 0);
    rdpa_tc_to_queue_dir_set(rdpa_tc_to_queue_attrs, rdpa_dir_ds); 
    rc = bdmf_new_and_set(rdpa_tc_to_queue_drv(), NULL, rdpa_tc_to_queue_attrs, &rdpa_tc_to_queue_obj);
    if (rc)
    {        
        printk("%s %s Failed to create rdpa tc_to_queue object rc(%d)\n", __FILE__, __FUNCTION__, rc);
        goto exit;
    }

    /* Configure pbit to q table - id 0 direction DS */
    rdpa_pbit_to_queue_table_set(rdpa_pbit_to_queue_attrs, 0);
    rc = bdmf_new_and_set(rdpa_pbit_to_queue_drv(), NULL, rdpa_pbit_to_queue_attrs, &rdpa_pbit_to_queue_obj);
    if (rc)
    {        
        printk("%s %s Failed to create rdpa pbit_to_queue object rc(%d)\n", __FILE__, __FUNCTION__, rc);
        goto exit;
    }

    for (i = 0; i < 8; ++i)
    {
        rdpa_tc_to_queue_tc_map_set(rdpa_tc_to_queue_obj, i, 0);
        rdpa_pbit_to_queue_pbit_map_set(rdpa_pbit_to_queue_obj, i, 0);
    }

exit:
    if (rc && rdpa_system_obj)
        bdmf_destroy(rdpa_system_obj);

//TODO:Remove the FTTD runner code when ready
#if defined(G9991) && !defined(XRDP)
    fttdp_addr = 0xb30d1818;
    fttdp_val = 0x19070019;
    WRITE_32(fttdp_addr, fttdp_val);
    fttdp_addr = 0xb30e1018;
    fttdp_val = 0x00002c2c;
    WRITE_32(fttdp_addr, fttdp_val);
    fttdp_addr = 0xb30e101c;
    fttdp_val = 0x00001013;
    WRITE_32(fttdp_addr, fttdp_val);
    fttdp_addr = 0xb30e1020;
    fttdp_val = 0x00001919;
    WRITE_32(fttdp_addr, fttdp_val);
#endif

    return rc;
}

#elif defined(CONFIG_BCM963138) || defined(CONFIG_BCM963148)

int rdpa_init_system(void)
{
    BDMF_MATTR(rdpa_system_attrs, rdpa_system_drv());
    bdmf_object_handle rdpa_system_obj = NULL;
    int rc;
    rdpa_system_init_cfg_t sys_init_cfg = {};
    bdmf_object_handle rdpa_port_object = NULL;
    BDMF_MATTR(rdpa_port_attrs, rdpa_port_drv());
    rdpa_port_dp_cfg_t port_cfg = {};
    bdmf_object_handle cpu =  NULL;

    rc = rdpa_get_init_system_bp_params();
    if (rc)
        goto exit;

    /* wan_type is set to the rdpa_if_wan0 type but it is not used to identify the WAN */
    sys_init_cfg.gbe_wan_emac = rdpa_emac0;
    sys_init_cfg.enabled_emac = emac_map;
    sys_init_cfg.runner_ext_sw_cfg.emac_id = (ext_sw_pid == BP_NO_EXT_SW) ? rdpa_emac_none:(rdpa_emac)ext_sw_pid;
    sys_init_cfg.runner_ext_sw_cfg.enabled = (ext_sw_pid == BP_NO_EXT_SW) ? 0 : 1;
    sys_init_cfg.runner_ext_sw_cfg.type = rdpa_brcm_hdr_opcode_0;
    sys_init_cfg.switching_mode = rdpa_switching_none;
    sys_init_cfg.ip_class_method = rdpa_method_fc;

    rdpa_system_init_cfg_set(rdpa_system_attrs, &sys_init_cfg);

    rc = bdmf_new_and_set(rdpa_system_drv(), NULL, rdpa_system_attrs, &rdpa_system_obj);
    if (rc)
    {
        printk("%s %s Failed to create rdpa system object rc(%d)\n", __FILE__, __FUNCTION__, rc);
        goto exit;
    }

    rc = rdpa_cpu_get(rdpa_cpu_host, &cpu);

    /*CPU Interrupts are no longer automatically connected as part of CPU object
     *creation. They need to be explicitly using below rdpa call.*/
    rc = rc ? rc : rdpa_cpu_int_connect_set(cpu, 1 /*true*/);
    if (rc < 0)
    {
        BDMF_TRACE_RET(BDMF_ERR_INTERNAL, "Failed to connect cpu interrupts\n");
        goto exit;
    }

    if (emac_map & (1<<rdpa_emac0)) /* Only create the Ethernet WAN port if specified in board parameters */
    {
        rdpa_port_index_set(rdpa_port_attrs, rdpa_if_wan0);
        rdpa_port_wan_type_set(rdpa_port_attrs, rdpa_wan_gbe);
        port_cfg.emac = rdpa_emac0;
        rdpa_port_cfg_set(rdpa_port_attrs, &port_cfg);
        rc = bdmf_new_and_set(rdpa_port_drv(), NULL, rdpa_port_attrs, &rdpa_port_object);
        if (rc)
        {
            printk("%s %s Failed to create rdpa wan port rc(%d)\n", __FILE__, __FUNCTION__, rc);
            goto exit;
        }
    }

exit:
    if (rc && rdpa_system_obj)
        bdmf_destroy(rdpa_system_obj);
    return rc;
}

#else /*CONFIG_BCM94908:*/
int rdpa_init_system(void)
{
    BDMF_MATTR(rdpa_system_attrs, rdpa_system_drv());
    bdmf_object_handle rdpa_system_obj = NULL;
    int rc;
    rdpa_system_init_cfg_t sys_init_cfg = {};

    bdmf_object_handle rdpa_port_object = NULL;
    BDMF_MATTR(rdpa_port_attrs, rdpa_port_drv());
    rdpa_port_dp_cfg_t port_cfg = {};
    bdmf_object_handle cpu =  NULL;

    rc = rdpa_get_init_system_bp_params();
    if (rc)
        goto exit;

    /* wan_type is set to the rdpa_if_wan0 type but it is not used to identify the WAN */
    sys_init_cfg.gbe_wan_emac = rdpa_emac3;
    sys_init_cfg.runner_ext_sw_cfg.emac_id = rdpa_emac0;
    sys_init_cfg.enabled_emac = 0xf;
    sys_init_cfg.runner_ext_sw_cfg.enabled = 1;
    sys_init_cfg.runner_ext_sw_cfg.type = rdpa_brcm_hdr_opcode_0;
    sys_init_cfg.switching_mode = rdpa_switching_none;
    sys_init_cfg.ip_class_method = rdpa_method_fc;

    rdpa_system_init_cfg_set(rdpa_system_attrs, &sys_init_cfg);

    rc = bdmf_new_and_set(rdpa_system_drv(), NULL, rdpa_system_attrs, &rdpa_system_obj);
    if (rc)
    {
        printk("%s %s Failed to create rdpa system object rc(%d)\n", __FILE__, __FUNCTION__, rc);
        goto exit;
    }

    rc = rdpa_cpu_get(rdpa_cpu_host, &cpu);

    /*CPU Interrupts are no longer automatically connected as part of CPU object
     *creation. They need to be explicitly using below rdpa call.*/
    rc = rc ? rc : rdpa_cpu_int_connect_set(cpu, 1 /*true*/);
    if (rc < 0)
    {
        BDMF_TRACE_RET(BDMF_ERR_INTERNAL, "Failed to connect cpu interrupts\n");
        goto exit;
    }

    rdpa_port_index_set(rdpa_port_attrs, rdpa_if_wan0);
    rdpa_port_wan_type_set(rdpa_port_attrs, rdpa_wan_gbe);
    port_cfg.emac = rdpa_emac3;
    rdpa_port_cfg_set(rdpa_port_attrs, &port_cfg);
    rc = bdmf_new_and_set(rdpa_port_drv(), NULL, rdpa_port_attrs, &rdpa_port_object);
    if (rc)
    {
        printk("%s %s Failed to create rdpa wan port rc(%d)\n", __FILE__, __FUNCTION__, rc);
        goto exit;
    }

exit:
    if (rc && rdpa_system_obj)
        bdmf_destroy(rdpa_system_obj);
    return rc;
}

#endif

