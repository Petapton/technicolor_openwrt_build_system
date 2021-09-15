/*
 * <:copyright-BRCM:2015:DUAL/GPL:standard
 * 
 *    Copyright (c) 2015 Broadcom 
 *    All Rights Reserved
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation (the "GPL").
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * 
 * A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
 * writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 * 
 * :>
 */

// BCMFORMAT: notabs reindent:uncrustify:bcm_minimal_i4.cfg

#include "boardparms.h"
#include "bcm_map_part.h"
#include "bcm_misc_hw_init.h"

#ifdef _CFE_
#include "lib_types.h"
#include "lib_printf.h"
#include "lib_string.h"
#include "cfe_timer.h"
#include "bcm_map.h"
#define printk  printf
#define udelay  cfe_usleep
#else // Linux
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <bcm_map_part.h>
#include <linux/string.h>
#include <linux/delay.h>
#include "board.h"
#include "rdpa_types.h"
#include "lport_defs.h"
#endif

//#define ENABLE_UBUS_REMAP_DEBUG_LOG     
#ifdef  ENABLE_UBUS_REMAP_DEBUG_LOG
#define UBUS_REMAP_DEBUG_LOG(fmt, ...) printk("%s:%d "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define UBUS_REMAP_DEBUG_LOG(fmt, ...)  
#endif

extern unsigned long getMemorySize(void);
#define MST_START_DDR_ADDR              0

#ifndef _CFE_
#if defined(CONFIG_BCM96836) || defined(_BCM96836_)
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include "proc_cmd.h"


#define PROC_DIR            "driver/ubus"
#define UBUS_PROC_FILE      "ubus_cmd"
static struct proc_dir_entry *proc_dir;
static struct proc_dir_entry *cmd_proc_file;
static int ubus_proc_cmd_remap_master_all(int argc, char *argv[]);
static int ubus_proc_cmd_remap_master_x(int argc, char *argv[]);
static int ubus_proc_cmd_remap_master_reset_all(int argc, char *argv[]);


unsigned int g_board_size_power_of_2;
EXPORT_SYMBOL(g_board_size_power_of_2);

static struct proc_cmd_ops ubus_remap_command_entries[] = 
{
    { .name = "remap_master_x",         .do_command	= ubus_proc_cmd_remap_master_x },
    { .name = "remap_master_all",       .do_command	= ubus_proc_cmd_remap_master_all},
    { .name = "remap_master_reset_all", .do_command	= ubus_proc_cmd_remap_master_reset_all},
};

static struct proc_cmd_table ubus_remap_command_table = 
{
    .module_name = "ubus_masters",
    .size = sizeof(ubus_remap_command_entries) / sizeof(ubus_remap_command_entries[0]),
    .ops = ubus_remap_command_entries
};
#endif
#endif

#if defined(__KERNEL__) && defined(CONFIG_BCM_PON_XRDP)
struct device *rdp_dummy_dev = NULL;
EXPORT_SYMBOL(rdp_dummy_dev);
#endif

#if defined(_BCM94908_) || defined(CONFIG_BCM94908)
static void bcm_set_padctrl(unsigned int pin_num, unsigned int pad_ctrl)
{
    unsigned int tp_blk_data_lsb;
    //printk("set pad ctrl %d to %d\n",pin_num, pad_ctrl);
    tp_blk_data_lsb= 0;
    tp_blk_data_lsb |= pin_num;
    tp_blk_data_lsb |= (pad_ctrl << PAD_CTRL_SHIFT);
    GPIO->TestPortBlockDataMSB = 0;
    GPIO->TestPortBlockDataLSB = tp_blk_data_lsb;
    GPIO->TestPortCmd = LOAD_PAD_CTRL_CMD;
}

static void bcm_misc_hw_rcal(void)
{
    /* start the resistor calibrator by setting RSTB and then clearing the PWRDN bit */
    TOPCTRL->RescalIPCtrl |= RESCAL_RSTB;
    udelay(10);
    TOPCTRL->RescalIPCtrl &= ~RESCAL_PWRDN;
}

static void bcm_misc_hw_xmii_pads_init(void)
{
    const ETHERNET_MAC_INFO *Enet;
    int i,j;
    int u, found = 0;
    uint32_t rgmii_ctrl = 0;
    uint32_t tp_data = 0;
    int n, errcnt;
    unsigned short Function[BP_PINMUX_MAX];
    unsigned int Muxinfo[BP_PINMUX_MAX];

    // Check for network ports requiring MAC interfaces to be active
    if ( (Enet = BpGetEthernetMacInfoArrayPtr()) != NULL)
    {
        for (i = 0 ; i < BP_MAX_ENET_MACS ; i++) {
            for (j = 0; j < BP_MAX_CROSSBAR_EXT_PORTS ; j++) {
                u = BP_CROSSBAR_PORT_TO_PHY_PORT(j);
                /* 4908 only has one xGMII port, phy port 11, on the crossbar */
                if (Enet[i].sw.crossbar[j].switch_port != BP_CROSSBAR_NOT_DEFINED && u == 11)
                {
                    switch (Enet[i].sw.crossbar[j].phy_id & MAC_IFACE)
                    {
                        case MAC_IF_RGMII_1P8V :
                            tp_data = PAD_SLEW_RATE_CTRL;  //rgmii_pad_amp_en
                            break;
                        case MAC_IF_RGMII_2P5V :
                            rgmii_ctrl = RGMII_PAD_MODEHV;
                            break;
                        case MAC_IF_RGMII_3P3V :
                            tp_data = PAD_HYST_ENABLE; //rgmii_pad_sel_gmii
                            rgmii_ctrl = RGMII_PAD_MODEHV;
                            break;
                    }
                    /* drive strength selection */
                    tp_data |= 0x6<<PAD_DRIVE_STRENGTH_SHIFT;
                    /* enable rgmii pad */ 
                    rgmii_ctrl |= RGMII_PAD_ENABLE;
                    found = 1;
                    break;
                }
            }
        }
    }

    if( found ) {
   
        TOPCTRL->RGMIICtrl = rgmii_ctrl;

        /* rgmii pin pad control using pinmux tp interface */
        if (BP_SUCCESS == BpGetIfacePinmux (BP_PINMUX_FNTYPE_xMII | u, BP_PINMUX_MAX,  &n, &errcnt, Function, Muxinfo)) {
            for (i = n-1 ; 0 <= i ; i--) {
                if( BP_PINMUX_PADCTL == (Muxinfo[i] & BP_PINMUX_OP_MASK) )
                    bcm_set_padctrl((Muxinfo[i] & BP_PINMUX_PIN_MASK), tp_data>>PAD_CTRL_SHIFT);
            }
        }
    }
    
    return;
}
#endif

static void bcm_misc_hw_set_intr_mux(uint16_t extintr, uint16_t gpio)
{
    int sel0, sel1, intnum;
    uint32_t mask, value;

    gpio = gpio&BP_GPIO_NUM_MASK;

    sel0 = gpio % EXT_IRQ_SLOT_SIZE; // select one gpio pin in the slot
    sel1 = gpio / EXT_IRQ_SLOT_SIZE; // select the slot

    intnum = extintr - BP_EXT_INTR_0;

    mask = ~(EXT_IRQ_MUX_SEL0_MASK<<(EXT_IRQ_MUX_SEL0_SHIFT*intnum));
    value = sel0<<(EXT_IRQ_MUX_SEL0_SHIFT*intnum);
    PERF->ExtIrqMuxSel0 &= mask;
    PERF->ExtIrqMuxSel0 |= value;

    mask = ~(EXT_IRQ_MUX_SEL1_MASK<<(EXT_IRQ_MUX_SEL1_SHIFT*intnum));
    value = sel1<<(EXT_IRQ_MUX_SEL1_SHIFT*intnum);
    PERF->ExtIrqMuxSel1 &= mask;
    PERF->ExtIrqMuxSel1 |= value;

    return;
}

void bcm_misc_hw_intr_mux_init(void)
{
    int i = 0, rc = 0;
    void* token = NULL;
    uint16_t extintr, gpio;

    for(;;)
    {
        rc = BpGetExtIntrNumGpio(i, &token, &extintr, &gpio);
        if( rc == BP_MAX_ITEM_EXCEEDED )
                break;
        else if( rc == BP_SUCCESS )
        {
            if( gpio != BP_NOT_DEFINED )
                bcm_misc_hw_set_intr_mux(extintr, gpio);
            else
                printk("Error no gpio number defined for external interrupt %d!\n", extintr);
        }
        else 
        {
            token = NULL;
            i++;
        }
    }

    return;
}

#ifndef _CFE_
int bcm_misc_xfi_port_get(void)
{
    int iter;
    const ETHERNET_MAC_INFO *emac_info;

    if (!(emac_info = BpGetEthernetMacInfoArrayPtr()))
        return rdpa_emac_none;

    for (iter = 0; iter < LPORT_NUM_OF_PORTS && iter < BP_MAX_SWITCH_PORTS; iter++)
    {
        if ((emac_info->sw.port_map & (1 << iter)) &&
            ((emac_info->sw.phy_id[iter] & MAC_IFACE) == MAC_IF_XFI))
        {
            return (rdpa_emac)(rdpa_emac0 + iter);
        }
    }

    return rdpa_emac_none;
}
EXPORT_SYMBOL(bcm_misc_xfi_port_get);

int bcm_misc_g9991_debug_port_get(void)
{
    int iter;
    const ETHERNET_MAC_INFO *emac_info;

    if (!(emac_info = BpGetEthernetMacInfoArrayPtr()))
        return -1;

    for (iter = 0; iter < BP_MAX_SWITCH_PORTS; iter++)
    {
        if (emac_info->sw.port_map & (1 << iter) &&
            emac_info->sw.port_flags[iter] & PORT_FLAG_MGMT)
        {
            return (rdpa_emac)(rdpa_emac0 + iter);
        }
    }

    return -1;
}
EXPORT_SYMBOL(bcm_misc_g9991_debug_port_get);

uint32_t bcm_misc_g9991_phys_port_vec_get(void)
{
    uint32_t vec = 0;
    int iter;
    const ETHERNET_MAC_INFO *emac_info;

    if (!(emac_info = BpGetEthernetMacInfoArrayPtr()))
        return 0;

    for (iter = 0; iter < BP_MAX_SWITCH_PORTS; iter++)
    {
        if (emac_info->sw.port_map & (1 << iter) &&
            emac_info->sw.port_flags[iter] & PORT_FLAG_ATTACHED)
        {
            vec |= (1 << iter);
        }
    }

    return vec;
}
EXPORT_SYMBOL(bcm_misc_g9991_phys_port_vec_get);

int runner_reserved_memory_get(uint8_t **bm_base_addr,
                               uint8_t **bm_base_addr_phys,
                               unsigned int *bm_size,
                               uint8_t **fm_base_addr,
                               uint8_t **fm_base_addr_phys,
                               unsigned int *fm_size)
{
    int rc;

    rc = BcmMemReserveGetByName(BUFFER_MEMORY_BASE_ADDR_STR,
                                (void **)bm_base_addr, bm_size);
    if (unlikely(rc)) {
        printk("%s %s Failed to get buffer memory, rc(%d)\n",
               __FILE__, __func__, rc);
        return rc;
    }

    rc = BcmMemReserveGetByName(FLOW_MEMORY_BASE_ADDR_STR,
                                (void **)fm_base_addr, fm_size);
    if (unlikely(rc)) {
        printk("Failed to get valid flow memory, rc = %d\n", rc);
        return rc;
    }

    memset(*bm_base_addr, 0x00, *bm_size);
    memset(*fm_base_addr, 0x00, *fm_size);

    *bm_base_addr_phys = (uint8_t *)virt_to_phys(*bm_base_addr);

    printk("bm_base_addr 0x%p, size %u, bm_base_addr_phys 0x%p\n",
           *bm_base_addr, *bm_size, *bm_base_addr_phys);

    *fm_base_addr_phys = (uint8_t *)virt_to_phys(*fm_base_addr);

    printk("fm_base_addr 0x%p, size %u, fm_base_addr_phys 0x%p\n",
           *fm_base_addr, *fm_size, *fm_base_addr_phys);

    *bm_size = *bm_size >> 20;	/* convert from Byte to MB */
    *fm_size = *fm_size >> 20;	/* convert from Byte to MB */

    return rc;
}
EXPORT_SYMBOL(runner_reserved_memory_get);
#endif

int rdp_shut_down(void)
{
    /*put all RDP modules in reset state*/
    // TBD. pmcPutAllRdpModulesInReset();
    return 0;
}
#ifndef _CFE_
EXPORT_SYMBOL(rdp_shut_down);
#endif

#if defined(__KERNEL__) && defined(CONFIG_BCM_PON_XRDP)
static void alloc_rdp_dummy_device(void)
{
    if (rdp_dummy_dev == NULL) {
        rdp_dummy_dev = kzalloc(sizeof(struct device), GFP_ATOMIC);

        /* need to confirm how many bits we support in 6858 runner */
        dma_set_coherent_mask(rdp_dummy_dev, DMA_BIT_MASK(40));
    }
}
#endif
#if defined(CONFIG_BCM96858)
extern void bcm_gpio_set_data(unsigned int, unsigned int);
extern void bcm_gpio_set_dir(unsigned int gpio_num, unsigned int dir);

static void configure_xfi_optic_phy(void)
{
    bcm_gpio_set_dir(52, 1);
    bcm_gpio_set_data(52, 0);
}
#endif


#if defined (CONFIG_BCM96858) || defined(_BCM96858_) || defined(CONFIG_BCM96836) || defined(_BCM96836_)
int log2_32 (unsigned int value)
{
    unsigned int result = 0;
    if( value < 1)
        return 0;

    while (value > 1) {
        ++result;
        value >>= 1;
    }

    return result;
}
#ifndef _CFE_
EXPORT_SYMBOL(log2_32);
#endif

int ubus_master_decode_wnd_cfg(MST_PORT_NODE node, int win, unsigned int phys_addr, unsigned int size_power_of_2, int port_id, unsigned int cache_bit_en)
{
    MstPortNode *master_addr = NULL; 
    int ret = 0;
#if defined(CONFIG_BCM96836) || defined(_BCM96836_)
    unsigned int wa_coherent_flag = 0;
#endif

#if defined(CONFIG_BCM96836) || defined(_BCM96836_)
    wa_coherent_flag = wa_coherent_flag;
#endif

    UBUS_REMAP_DEBUG_LOG("\x1b[35m node[%d] win[%d] phys_addr[0x%x] power_of_2[%d] port_id[%d] cache_bit[%d]\x1b[0m\n", 
                         node, win, phys_addr, size_power_of_2, port_id,cache_bit_en);


    if((win > 3) || (size_power_of_2 > 31) || (phys_addr & ((1 << size_power_of_2)-1)))
    {
        printk("\x1b[35m Paramets Error:  win[%d] phys_addr[0x%x] power_of_2[%d] port_id[%d] cache_bit[%d]\x1b[0m\n", 
               win, phys_addr, size_power_of_2, port_id, cache_bit_en);
        return -1;
    }

     switch(node)
    {
        case MST_PORT_NODE_PCIE0:
            master_addr = (MstPortNode *)MST_PORT_NODE_PCIE0_BASE;
            break;
        case MST_PORT_NODE_SATA:
            master_addr = (MstPortNode *)MST_PORT_NODE_SATA_BASE;
            break;
        case MST_PORT_NODE_USB:
            master_addr = (MstPortNode *)MST_PORT_NODE_USB_BASE;
            break;
        case MST_PORT_NODE_PER:
            master_addr = (MstPortNode *)MST_PORT_NODE_PER_BASE;
            break;
        case MST_PORT_NODE_DMA0:
            master_addr = (MstPortNode *)MST_PORT_NODE_DMA0_BASE;
            break;
        case MST_PORT_NODE_RQ0:
            master_addr = (MstPortNode *)MST_PORT_NODE_RQ0_BASE;
#if defined(CONFIG_BCM96836) || defined(_BCM96836_)
            if (cache_bit_en) // function calls from alloc_coherent_rings()
                wa_coherent_flag = 1;//On the 2nd bit window register set bit 24 to 1 - WA 
#endif
            break;
        case MST_PORT_NODE_NATC:
            master_addr = (MstPortNode *)MST_PORT_NODE_NATC_BASE;
            break;
        case MST_PORT_NODE_DQM:
            master_addr = (MstPortNode *)MST_PORT_NODE_DQM_BASE;
            break;
        case MST_PORT_NODE_QM:
            master_addr = (MstPortNode *)MST_PORT_NODE_QM_BASE;
            break;
#if defined (CONFIG_BCM96858) || defined(_BCM96858_)
        case MST_PORT_NODE_PCIE1:
            master_addr = (MstPortNode *)MST_PORT_NODE_PCIE1_BASE;
            break;
        case MST_PORT_NODE_B53:
            master_addr = (MstPortNode *)MST_PORT_NODE_B53_BASE;
            break;
        case MST_PORT_NODE_PCIE2:
            master_addr = (MstPortNode *)MST_PORT_NODE_PCIE2_BASE;
            break;
        case MST_PORT_NODE_PMC:
            master_addr = (MstPortNode *)MST_PORT_NODE_PMC_BASE;
            break;
        case MST_PORT_NODE_APM:
            master_addr = (MstPortNode *)MST_PORT_NODE_APM_BASE;
            break;

        case MST_PORT_NODE_DMA1:
            master_addr = (MstPortNode *)MST_PORT_NODE_DMA1_BASE;
            break;
        case MST_PORT_NODE_RQ1:
            master_addr = (MstPortNode *)MST_PORT_NODE_RQ1_BASE;
            break;
        case MST_PORT_NODE_RQ2:
            master_addr = (MstPortNode *)MST_PORT_NODE_RQ2_BASE;
            break;
        case MST_PORT_NODE_RQ3:
            master_addr = (MstPortNode *)MST_PORT_NODE_RQ3_BASE;
            break;
#endif
#if defined(CONFIG_BCM96836) || defined(_BCM96836_)
        case MST_PORT_NODE_PERDMA:
          master_addr = (MstPortNode *)MST_PORT_NODE_PER_DMA_BASE;
          break;
#endif
     default:
         printk("\x1b[35m ERROR line[[%d]]: node[%d] \x1b[0m\n",__LINE__, node);
         ret = -1;
     }

    if(!ret)
    {
        if(size_power_of_2)
        {
#if (CONFIG_BCM_CHIP_REV == 0x6858A0)
            // there is a bug in A0 UBUS that requires a shift by one into the decode cfg
            master_addr->decode_cfg.window[win].base_addr = (phys_addr>>8) << (win + 1);
            master_addr->decode_cfg.window[win].remap_addr = (phys_addr>>8) << (win + 1);
#else
            master_addr->decode_cfg.window[win].base_addr =  (phys_addr>>8);
            master_addr->decode_cfg.window[win].remap_addr = (phys_addr>>8);
#endif
#if (CONFIG_BCM_CHIP_REV == 0x6836A0)
            if (wa_coherent_flag) 
                master_addr->decode_cfg.window[win].remap_addr |= 1 << 24;
#endif

            if( (port_id == DECODE_CFG_PID_B53) && (cache_bit_en))
            {
                    master_addr->decode_cfg.window[win].attributes = 
                                (DECODE_CFG_CACHE_BITS | DECODE_CFG_ENABLE_ADDR_ONLY | (size_power_of_2 << DECODE_CFG_SIZE_SHIFT) | port_id) ;
                    UBUS_REMAP_DEBUG_LOG("\x1b[35m base_addr[0x%x] remap_addr[0x%x] attributes[0x%x]\x1b[0m\n", 
                                         master_addr->decode_cfg.window[win].base_addr, 
                                         master_addr->decode_cfg.window[win].remap_addr,
                                         master_addr->decode_cfg.window[win].attributes);
             }
            else
            {
                master_addr->decode_cfg.window[win].attributes = 
                                (DECODE_CFG_ENABLE_ADDR_ONLY | (size_power_of_2 << DECODE_CFG_SIZE_SHIFT) | port_id) ;

                UBUS_REMAP_DEBUG_LOG("\x1b[35m base_addr[0x%x] remap_addr[0x%x] attributes[0x%x]\x1b[0m\n",
                                     master_addr->decode_cfg.window[win].base_addr, 
                                     master_addr->decode_cfg.window[win].remap_addr,
                                     master_addr->decode_cfg.window[win].attributes); 
            }
        }
        else
        {
            master_addr->decode_cfg.window[win].base_addr = 0;
            master_addr->decode_cfg.window[win].remap_addr = 0;
            master_addr->decode_cfg.window[win].attributes = 0;
        }
    }

    return ret;
}
#ifndef _CFE_
EXPORT_SYMBOL(ubus_master_decode_wnd_cfg);
#endif
#endif



#if defined(CONFIG_BCM96836) || defined(_BCM96836_)
#define SIZE_OF_REG_BYTES     (4)
int ubus_remap_to_biu_cfg_queue_srcpid(unsigned long lut_idx, unsigned int *p_srcpid_queus_value)
{
    CoherencyPortCfgReg_t *reg_addr = 
        (CoherencyPortCfgReg_t*)(UBUS_COHERENCY_PORT_CFG_LUT_BASE + lut_idx * SIZE_OF_REG_BYTES); 

    if((lut_idx > 31) || (NULL == p_srcpid_queus_value))
        return -1;

    reg_addr->queue_cfg = (((p_srcpid_queus_value[0] & 0xf) << SRCPID_TO_QUEUE_0_BITS_SHIFT) |
                           ((p_srcpid_queus_value[1] & 0xf) << SRCPID_TO_QUEUE_1_BITS_SHIFT) |
                           ((p_srcpid_queus_value[2] & 0xf) << SRCPID_TO_QUEUE_2_BITS_SHIFT) |
                           ((p_srcpid_queus_value[3] & 0xf) << SRCPID_TO_QUEUE_3_BITS_SHIFT) |
                           ((p_srcpid_queus_value[4] & 0xf) << SRCPID_TO_QUEUE_4_BITS_SHIFT) |
                           ((p_srcpid_queus_value[5] & 0xf) << SRCPID_TO_QUEUE_5_BITS_SHIFT) |
                           ((p_srcpid_queus_value[6] & 0xf) << SRCPID_TO_QUEUE_6_BITS_SHIFT) |
                           ((p_srcpid_queus_value[7] & 0xf) << SRCPID_TO_QUEUE_7_BITS_SHIFT));

    UBUS_REMAP_DEBUG_LOG("\x1b[35m reg_addr[0x%p] reg_value[0x%x]\x1b[0m\n",
                         (unsigned int*)(reg_addr), reg_addr->queue_cfg); 
    
    return 0;                        
}

int ubus_remap_to_biu_cfg_queue_depth(unsigned long q_depth_idx, unsigned int *p_depth_queus_value)
{
    CoherencyPortCfgReg_t *reg_addr = 
        (CoherencyPortCfgReg_t*)(UBUS_COHERENCY_PORT_CFG_DEPTH_BASE + q_depth_idx * SIZE_OF_REG_BYTES); 

    if((q_depth_idx > 3) || (NULL == p_depth_queus_value))
        return -1;

    reg_addr->queue_cfg = (((p_depth_queus_value[0] & 0xff) << DEPTH_TO_QUEUE_0_BITS_SHIFT) |
                           ((p_depth_queus_value[1] & 0xff) << DEPTH_TO_QUEUE_1_BITS_SHIFT) |
                           ((p_depth_queus_value[2] & 0xff) << DEPTH_TO_QUEUE_2_BITS_SHIFT) |
                           ((p_depth_queus_value[3] & 0xff) << DEPTH_TO_QUEUE_3_BITS_SHIFT));

    UBUS_REMAP_DEBUG_LOG("\x1b[35m reg_addr[0x%p] reg_value[0x%x]\x1b[0m\n",
                         (unsigned int*)(reg_addr), reg_addr->queue_cfg); 

    return 0;                        
}

int ubus_remap_to_biu_cfg_queue_thresh(unsigned long q_thresh_idx, unsigned int *p_thresh_queus_value)
{
    CoherencyPortCfgReg_t *reg_addr = 
        (CoherencyPortCfgReg_t*)(UBUS_COHERENCY_PORT_CFG_CBS_BASE + q_thresh_idx * SIZE_OF_REG_BYTES); 

    if((q_thresh_idx > 8) || (NULL == p_thresh_queus_value))
        return -1;

    reg_addr->queue_cfg = (((p_thresh_queus_value[0] & 0xffff) << THRESH_TO_QUEUE_0_BITS_SHIFT) |
                          ((p_thresh_queus_value [1] & 0xffff) << THRESH_TO_QUEUE_1_BITS_SHIFT));
                    
    UBUS_REMAP_DEBUG_LOG("\x1b[35m reg_addr[0x%p] reg_value[0x%x]\x1b[0m\n",
                         (unsigned int*)(reg_addr), reg_addr->queue_cfg); 

    return 0;                        
}

int ubus_remap_to_biu_cfg_cir_incr(unsigned long q_cirinc_idx, unsigned int *p_cirinc_queus_value)
{
    CoherencyPortCfgReg_t *reg_addr =
         (CoherencyPortCfgReg_t*)(UBUS_COHERENCY_PORT_CFG_CIR_INCR_BASE + q_cirinc_idx * SIZE_OF_REG_BYTES); 

    if((q_cirinc_idx > 3) || (NULL == p_cirinc_queus_value))
        return -1;

    reg_addr->queue_cfg = (((p_cirinc_queus_value[0] & 0xff) << CIR_INCR_TO_QUEUE_0_BITS_SHIFT) |
                          ((p_cirinc_queus_value [1] & 0xff) << CIR_INCR_TO_QUEUE_1_BITS_SHIFT) |
                          ((p_cirinc_queus_value [2] & 0xff) << CIR_INCR_TO_QUEUE_2_BITS_SHIFT) |
                          ((p_cirinc_queus_value [3] & 0xff) << CIR_INCR_TO_QUEUE_3_BITS_SHIFT));

    UBUS_REMAP_DEBUG_LOG("\x1b[35m reg_addr[0x%p] reg_value[0x%x]\x1b[0m\n",
                         (unsigned int*)(reg_addr), reg_addr->queue_cfg); 

    return 0;                        
}

int ubus_remap_to_biu_cfg_ref_cnt(unsigned long q_ref_cnt_idx, unsigned int *p_ref_cnt_value)
{
    CoherencyPortCfgReg_t *reg_addr = 
       (CoherencyPortCfgReg_t*)(UBUS_COHERENCY_PORT_CFG_REF_COUNT_BASE + q_ref_cnt_idx * SIZE_OF_REG_BYTES); 

    if((q_ref_cnt_idx > 1) || (NULL == p_ref_cnt_value))
        return -1;

    reg_addr->queue_cfg = (((p_ref_cnt_value[0] & 0xf) << REF_CNT_0_BITS_SHIFT) |
                           ((p_ref_cnt_value[1] & 0xf) << REF_CNT_1_BITS_SHIFT) |
                           ((p_ref_cnt_value[2] & 0xf) << REF_CNT_2_BITS_SHIFT) |
                           ((p_ref_cnt_value[3] & 0xf) << REF_CNT_3_BITS_SHIFT) |
                           ((p_ref_cnt_value[4] & 0xf) << REF_CNT_4_BITS_SHIFT) |
                           ((p_ref_cnt_value[5] & 0xf) << REF_CNT_5_BITS_SHIFT) |
                           ((p_ref_cnt_value[6] & 0xf) << REF_CNT_6_BITS_SHIFT) |
                           ((p_ref_cnt_value[7] & 0xf) << REF_CNT_7_BITS_SHIFT));
                    
    UBUS_REMAP_DEBUG_LOG("\x1b[35m  reg_addr[0x%p] reg_value[0x%x]\x1b[0m\n",
                         (unsigned int*)(reg_addr), reg_addr->queue_cfg); 
    
    return 0;                        
}

#ifndef _CFE_
static int ubus_proc_cmd_remap_master_x(int argc, char *argv[])
{
    char *usage = "Usage: remap_master_x <masters id (0-5)> [<remap 0|1>]";
    unsigned int remap_master = 0xffffffff;
    unsigned int if_cache = 0xffffffff;
    int rc = 0;

    if (argc < 3)
        goto wrong_params;

    if (kstrtos32(argv[1], 10, &remap_master))
        goto wrong_params;

    if (remap_master < MST_PORT_NODE_PCIE0 || remap_master > MST_PORT_NODE_LAST - MST_PORT_NODE_DMA0)
        goto wrong_params;


    if (kstrtou32(argv[2], 10, &if_cache))
        goto wrong_params;

    if (if_cache > 1)
        goto wrong_params; 
    
    
    rc = ubus_master_decode_wnd_cfg(remap_master, 
                                    0/* Always use window 0 to remap all and wind 1 to coherent rings */, 
                                    MST_START_DDR_ADDR, 
                                    g_board_size_power_of_2, 
                                    DECODE_CFG_PID_B53, 
                                    if_cache);/* For now not support cache mode*/
    if (rc < 0)
        printk("Error %s line[%d] node[%d] address[0x%x] size[%d]:\n",
               __FILE__, __LINE__, remap_master, MST_START_DDR_ADDR, g_board_size_power_of_2); 
    return rc;


wrong_params:
    pr_info("%s\n", usage);
    return rc;

}

static int ubus_proc_cmd_remap_master_all(int argc, char *argv[])
{
    char *usage = "Usage: remap_master_all <[<remap 0|1>]";
    unsigned int if_remap = 0xffffffff;
    int rc = 0;
    unsigned int i = 0;

    if (argc < 2)
        goto wrong_params;

    if (kstrtou32(argv[1], 10, &if_remap))
        goto wrong_params;

    if (if_remap > 1)
        goto wrong_params;
    
     
    for (;i < MST_PORT_NODE_LAST - MST_PORT_NODE_DMA0; i++ ) 
    {
        rc = ubus_master_decode_wnd_cfg(i, 
                                        0, /* Always use window 0 to remap all and wind 0 to coherent rings */
                                        MST_START_DDR_ADDR, 
                                        g_board_size_power_of_2, 
                                        DECODE_CFG_PID_B53, 
                                        if_remap);
        if (rc < 0)
        {
            printk("Error %s line[%d] node[%d] address[0x%x] size[%d]: \n",
                    __FILE__, __LINE__, i,  MST_START_DDR_ADDR, g_board_size_power_of_2);
            return rc;
        }

    } 
    
    return rc;                      


wrong_params:
    pr_info("%s\n", usage);
    return rc;
}

static int ubus_proc_cmd_remap_master_reset_all(int argc, char *argv[])
{
    char *usage = "Usage: remap_master_reset_all";
    int rc = 0;
    unsigned int i = 0;

    if (argc < 1)
        goto wrong_params;
    
     
    for (;i < MST_PORT_NODE_LAST; i++ ) 
    {
        rc = ubus_master_decode_wnd_cfg(i, 
                                        0 /* Always use window 1 to remap all and wind 0 to coherent rings */,  
                                        MST_START_DDR_ADDR, 
                                        0,/* to reset parameters */
                                        DECODE_CFG_PID_B53, 
                                        0);
        if (rc < 0)
        {
            printk("Error %s line[%d] node[%d] address[0x%x] size[%d]: \n",
                   __FILE__, __LINE__, i, MST_START_DDR_ADDR,0);
            return rc;
        }

    } 
    
    return rc;                      


wrong_params:
    pr_info("%s\n", usage);
    return rc;
}



static int create_ubus_proc(void)
{
    int rc = 0;

    proc_dir = proc_mkdir(PROC_DIR, NULL);
    if (!proc_dir) 
    {
        pr_err("Failed to create PROC directory %s.\n",
            PROC_DIR);
        goto error;
    }


    cmd_proc_file = proc_create_cmd(UBUS_PROC_FILE, proc_dir, &ubus_remap_command_table);
    if (!cmd_proc_file) 
    {
        pr_err("Failed to create %s\n", UBUS_PROC_FILE);
        goto error;
    }

    return rc;

error:
    if (cmd_proc_file) 
    {
        remove_proc_entry(UBUS_PROC_FILE, proc_dir);
        cmd_proc_file = NULL;
    }	
    if (proc_dir)
    {
        remove_proc_entry(PROC_DIR, NULL);
        proc_dir = NULL;
    }
    
    return -1;	
}
#endif
   
int remap_ubus_masters_biu(void)
{
    int rc = 0;
    unsigned int i = 0;
    int win = 0; /* Use window 0 to remap all relevant masters to BIU and wind 1 uses to rings - make them coherent */

#ifndef _CFE_
    /* Need to add proc and update start_mst_port and last_mst_port port_id */
    rc = create_ubus_proc();
    if (rc < 0)
        goto exit_;
#endif
    /* Calculate board size of power 2 */
    g_board_size_power_of_2 = log2_32(getMemorySize());

    UBUS_REMAP_DEBUG_LOG("\x1b[35m board_sdram_size[0x%lx] board_size_power_of_2[%d]\x1b[0m\n",
                         getMemorySize(), g_board_size_power_of_2);

    for (; i <= MST_PORT_NODE_LAST - MST_PORT_NODE_DMA0; i++ ) 
    {
        rc = ubus_master_decode_wnd_cfg(i, 
                                        win, 
                                        MST_START_DDR_ADDR, 
                                        g_board_size_power_of_2, 
                                        DECODE_CFG_PID_B53, 
                                        0);/* For now not support cache mode*/
        if (rc < 0)
        {
            printk("Error %s line[%d] node[%d] address[0x%x] size[%d]: \n",
                   __FILE__, __LINE__, i, MST_START_DDR_ADDR,g_board_size_power_of_2);
            goto exit_;
        }
    }

exit_:
    if (rc < 0)
        printk("Error: line[%d]\n",__LINE__);

    return rc;                       
}

#define  SRC_PID_Q_NUM      (8)
#define  DEPTH_Q_NUM        (4)
#define  THRESH_Q_NUM       (2)
#define  CIR_INCR_Q_NUM     (4)
#define  REF_CNT_NUM        (8)
int configure_biu_pid_to_queue(void)
{
    int rc = 0;
    unsigned int srcpid_queus_value[SRC_PID_Q_NUM] = {0};
    unsigned int depth_queus_value[DEPTH_Q_NUM] = {0};
    unsigned int thresh_queus_value[THRESH_Q_NUM] = {0};
    unsigned int cir_incr_queus_value[CIR_INCR_Q_NUM] = {0};
    unsigned int ref_cnt_value[REF_CNT_NUM] = {0};
    unsigned long lut_idx;
    unsigned long depth_idx;
    unsigned long thresh_idx;
    unsigned long cir_incr_idx;
    unsigned long ref_cnt_idx;

    lut_idx = 0;
    srcpid_queus_value[0] = 0;
    srcpid_queus_value[1] = 0;
    srcpid_queus_value[2] = 0;
    srcpid_queus_value[3] = 0;
    srcpid_queus_value[4] = 1;
    srcpid_queus_value[5] = 1;
    srcpid_queus_value[6] = 1;
    srcpid_queus_value[7] = 1;
    rc = ubus_remap_to_biu_cfg_queue_srcpid(lut_idx, srcpid_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    lut_idx = 1;
    srcpid_queus_value[0] = 0;
    srcpid_queus_value[1] = 0;
    srcpid_queus_value[2] = 0;
    srcpid_queus_value[3] = 2;
    srcpid_queus_value[4] = 3;
    srcpid_queus_value[5] = 4;
    srcpid_queus_value[6] = 3;
    srcpid_queus_value[7] = 5;
    rc = ubus_remap_to_biu_cfg_queue_srcpid(lut_idx, srcpid_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    depth_idx = 0;
    depth_queus_value[0] = 0x10;
    depth_queus_value[1] = 0x10;
    depth_queus_value[2] = 8;
    depth_queus_value[3] = 8;
    rc = ubus_remap_to_biu_cfg_queue_depth(depth_idx, depth_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    depth_idx = 1;
    depth_queus_value[0] = 8;
    depth_queus_value[1] = 8;
    depth_queus_value[2] = 0;
    depth_queus_value[3] = 0;
    rc = ubus_remap_to_biu_cfg_queue_depth(depth_idx, depth_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    thresh_idx = 0;
    thresh_queus_value[0] = 0x100;
    thresh_queus_value[1] = 0x100;
    rc = ubus_remap_to_biu_cfg_queue_thresh(thresh_idx, thresh_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    thresh_idx = 1;
    thresh_queus_value[0] = 0x1000;
    thresh_queus_value[1] = 0x400;
    rc = ubus_remap_to_biu_cfg_queue_thresh(thresh_idx, thresh_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    thresh_idx = 2;
    thresh_queus_value[0] = 0x400;
    thresh_queus_value[1] = 0x1000;
    rc = ubus_remap_to_biu_cfg_queue_thresh(thresh_idx, thresh_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    cir_incr_idx = 0;
    cir_incr_queus_value[0] = 1;
    cir_incr_queus_value[1] = 1;
    cir_incr_queus_value[2] = 4;
    cir_incr_queus_value[3] = 4;
    rc = ubus_remap_to_biu_cfg_cir_incr(cir_incr_idx, cir_incr_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    cir_incr_idx = 1;
    cir_incr_queus_value[0] = 2;
    cir_incr_queus_value[1] = 3;
    cir_incr_queus_value[2] = 0;
    cir_incr_queus_value[3] = 0;
    rc = ubus_remap_to_biu_cfg_cir_incr(cir_incr_idx, cir_incr_queus_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

    ref_cnt_idx = 0;
    ref_cnt_value[0] = 7;
    ref_cnt_value[1] = 4;
    ref_cnt_value[2] = 2;
    ref_cnt_value[3] = 2;
    ref_cnt_value[4] = 3;
    ref_cnt_value[5] = 2;
    ref_cnt_value[6] = 0;
    ref_cnt_value[7] = 0;
    rc = ubus_remap_to_biu_cfg_ref_cnt(ref_cnt_idx, ref_cnt_value);
    if (rc < 0)
    {
        printk("Error %s line[%d]\n",__FILE__, __LINE__);
        goto exit_;
    }

exit_:
    if (rc < 0)
        printk("Error: line[%d]\n",__LINE__);

    return rc;                       
}
#endif
 


int bcm_misc_hw_init(void)
{
    bcm_misc_hw_intr_mux_init();
#if defined(_BCM94908_) || defined(CONFIG_BCM94908)
    bcm_misc_hw_xmii_pads_init();
    bcm_misc_hw_rcal();
#endif
#if defined(_BCM96836_) || defined(CONFIG_BCM96836)
#ifndef _CFE_
    alloc_rdp_dummy_device();
#endif
#endif
#if defined(_BCM96858_) || defined(CONFIG_BCM96858)
#ifndef _CFE_
    alloc_rdp_dummy_device();
    ubus_master_set_token_credits(MST_PORT_NODE_PER, 1, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_USB, 1, 4);
    ubus_master_set_token_credits(MST_PORT_NODE_PMC, 1, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_DMA0, 1, 9);
    ubus_master_set_token_credits(MST_PORT_NODE_DMA1, 1, 9);
    ubus_master_set_token_credits(MST_PORT_NODE_NATC, 1, 4);
    ubus_master_set_token_credits(MST_PORT_NODE_QM, 1, 10);
    ubus_master_set_token_credits(MST_PORT_NODE_DQM, 1, 7);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ0, 1, 8);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ1, 1, 4);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ2, 1, 4);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ3, 1, 4);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ0, 20, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ1, 20, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ2, 20, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ3, 20, 1);

    /*These credits of PCIe to Runner quads are requiered to Wakeup runner
     * in case of DHD Offload RxComplete*/
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE0, 32, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE0, 33, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE0, 34, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE0, 35, 1);

#if (CONFIG_BCM_CHIP_REV == 0x6858B0)
    /* PCIe1 shares the same MASTER with PCIe0,PCIe2 Master is actually PCIe1
     * DHD offload is supported only on B0 */
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE1, 32, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE1, 33, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE1, 34, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PCIE1, 35, 1);
#endif

#else //_CFE_
    /*Set UBUS credits for runner quads */
    ubus_master_set_token_credits(MST_PORT_NODE_RQ0, 20, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ1, 20, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ2, 20, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ3, 20, 1);

#if (CONFIG_BCM_CHIP_REV == 0x6858B0)
    ubus_master_set_token_credits(MST_PORT_NODE_RQ0, 32, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ1, 33, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ2, 34, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_RQ3, 35, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PMC, 32, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PMC, 33, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PMC, 34, 1);
    ubus_master_set_token_credits(MST_PORT_NODE_PMC, 35, 1);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ0, 32, 0x9);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ0, 33, 0x209);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ0, 34, 0x109);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ0, 35, 0x309);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ1, 32, 0x9);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ1, 33, 0x209);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ1, 34, 0x109);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ1, 35, 0x309);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ2, 32, 0x8);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ2, 33, 0x208);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ2, 34, 0x108);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ2, 35, 0x308);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ3, 32, 0x8);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ3, 33, 0x208);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ3, 34, 0x108);
    ubus_master_set_rte_addr(MST_PORT_NODE_RQ3, 35, 0x308);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA0, 32, 0x0);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA0, 33, 0x8);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA0, 34, 0x4);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA0, 35, 0xc);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA1, 32, 0x1);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA1, 33, 0x9);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA1, 34, 0x5);
    ubus_master_set_rte_addr(MST_PORT_NODE_DMA1, 35, 0xd);
    ubus_master_set_rte_addr(MST_PORT_NODE_DQM, 32, 0x2);
    ubus_master_set_rte_addr(MST_PORT_NODE_DQM, 33, 0x6);
    ubus_master_set_rte_addr(MST_PORT_NODE_DQM, 34, 0x24);
    ubus_master_set_rte_addr(MST_PORT_NODE_DQM, 35, 0x64);
    ubus_master_set_rte_addr(MST_PORT_NODE_NATC, 32, 0x0);
    ubus_master_set_rte_addr(MST_PORT_NODE_NATC, 33, 0x8);
    ubus_master_set_rte_addr(MST_PORT_NODE_NATC, 34, 0x4);
    ubus_master_set_rte_addr(MST_PORT_NODE_NATC, 35, 0xc);
#endif
#endif
    configure_xfi_optic_phy();
#endif

#if defined(CONFIG_BCM96836) || defined(_BCM96836_)
#ifndef _CFE_
    remap_ubus_masters_biu();
    configure_biu_pid_to_queue();
#endif
#endif
    return 0;
}

#if defined(CONFIG_BCM96858) || defined(_BCM96858_) || defined(CONFIG_BCM96836) || defined(_BCM96836_)
// ucb commands
#define UCB_CMD_RD               0
#define UCB_CMD_RD_RPLY          1
#define UCB_CMD_WR               2
#define UCB_CMD_WR_ACK           3
#define UCB_CMD_BCAST            4

static void write_reg_thr_sm(uint32_t ucbid, uint32_t addr, uint32_t data)
{
    // check if response fifo is full
    while( UBUSSYSTOP->ReadUcbStatus & 0x40000000);

    UBUSSYSTOP->UcbData = data;
    
    UBUSSYSTOP->UcbHdr = (addr/4) | (UCB_CMD_WR<<12) | (ucbid<<16) | (0x1<<24);
    
    // check if resp fifo has data
    while( !(UBUSSYSTOP->ReadUcbStatus & 0x80000000 ) );
  
    UBUSSYSTOP->ReadUcbHdr;
}

static uint32_t read_reg_thr_sm(uint32_t ucbid, uint32_t addr)
{
    // check if response fifo is full
    while( UBUSSYSTOP->ReadUcbStatus & 0x40000000);    

    UBUSSYSTOP->UcbHdr = (addr/4) | (UCB_CMD_RD<<12) | (ucbid<<16) | (0x1<<24);

    // check if resp fifo has data
    while( !(UBUSSYSTOP->ReadUcbStatus & 0x80000000 ) );

    UBUSSYSTOP->ReadUcbHdr;

    return UBUSSYSTOP->ReadUcbData;
}


void ubus_deregister_port(int ucbid)
{
    write_reg_thr_sm(ucbid, 0x1c, 0x1);

    // poll status bit for port unregistered
    while ( read_reg_thr_sm(ucbid, 0x1c) != 0x1 );
}

void ubus_register_port(int ucbid)
{
#if defined (CONFIG_BCM96836) || defined(_BCM96836_) || (CONFIG_BCM_CHIP_REV==0x6858B0)
#if (CONFIG_BCM_CHIP_REV==0x6858B0)
    if ((ucbid==UCB_NODE_ID_MST_USB) || (ucbid==UCB_NODE_ID_SLV_USB) || (ucbid==UCB_NODE_ID_MST_SATA) || (ucbid==UCB_NODE_ID_SLV_SATA))
#endif
    {
    write_reg_thr_sm(ucbid, 0x1c, 0x0);
    // poll status bit for port registered
    while ( read_reg_thr_sm(ucbid, 0x1c) != 0x2 );
    }
#endif
}
#endif

#if defined(CONFIG_BCM96858) || defined(_BCM96858_)
int ubus_master_set_rte_addr(MST_PORT_NODE node, int port, int val)
{
    volatile MstPortNode *master_addr = NULL;
    int ret = 0;

    switch(node)
    {
        case MST_PORT_NODE_PCIE0:
        master_addr = (MstPortNode *)MST_PORT_NODE_PCIE0_BASE;
        break;
        case MST_PORT_NODE_PCIE1:
        master_addr = (MstPortNode *)MST_PORT_NODE_PCIE1_BASE;
        break;
        case MST_PORT_NODE_B53:
        master_addr = (MstPortNode *)MST_PORT_NODE_B53_BASE;
        break;
        case MST_PORT_NODE_PCIE2:
        master_addr = (MstPortNode *)MST_PORT_NODE_PCIE2_BASE;
        break;
        case MST_PORT_NODE_SATA:
        master_addr = (MstPortNode *)MST_PORT_NODE_SATA_BASE;
        break;
        case MST_PORT_NODE_USB:
        master_addr = (MstPortNode *)MST_PORT_NODE_USB_BASE;
        break;
        case MST_PORT_NODE_PMC:
        master_addr = (MstPortNode *)MST_PORT_NODE_PMC_BASE;
        break;
        case MST_PORT_NODE_APM:
        master_addr = (MstPortNode *)MST_PORT_NODE_APM_BASE;
        break;
        case MST_PORT_NODE_PER:
        master_addr = (MstPortNode *)MST_PORT_NODE_PER_BASE;
        break;
        case MST_PORT_NODE_DMA0:
        master_addr = (MstPortNode *)MST_PORT_NODE_DMA0_BASE;
        break;
        case MST_PORT_NODE_DMA1:
        master_addr = (MstPortNode *)MST_PORT_NODE_DMA1_BASE;
        break;
        case MST_PORT_NODE_RQ0:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ0_BASE;
        break;
        case MST_PORT_NODE_RQ1:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ1_BASE;
        break;
        case MST_PORT_NODE_RQ2:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ2_BASE;
        break;
        case MST_PORT_NODE_RQ3:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ3_BASE;
        break;
        case MST_PORT_NODE_NATC:
        master_addr = (MstPortNode *)MST_PORT_NODE_NATC_BASE;
        break;
        case MST_PORT_NODE_DQM:
        master_addr = (MstPortNode *)MST_PORT_NODE_DQM_BASE;
        break;
        case MST_PORT_NODE_QM:
        master_addr = (MstPortNode *)MST_PORT_NODE_QM_BASE;
        break;
        default:
        ret = -1;
    }

    if(!master_addr)
    {
        printk("Node %d master address is zero\n", node);
        return -1;
    }
    if(!ret)
        master_addr->routing_addr[port] = val;

    return ret;
}
#endif

#if defined(CONFIG_BCM96858) || defined(_BCM96858_) || defined(CONFIG_BCM96836) || defined(_BCM96836_)
/*this function is used to set UBUS route credits per usub master, should be equivalent configuration at masters*/
int ubus_master_set_token_credits(MST_PORT_NODE node, int token, int credits)
{
    volatile MstPortNode *master_addr = NULL;
    int ret = 0;

    switch(node)
    {
        case MST_PORT_NODE_RQ0:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ0_BASE;
        break;
#if defined(CONFIG_BCM96858) || defined(_BCM96858_)
        case MST_PORT_NODE_PCIE0:
        master_addr = (MstPortNode *)MST_PORT_NODE_PCIE0_BASE;
        break;
        case MST_PORT_NODE_PCIE1:
        master_addr = (MstPortNode *)MST_PORT_NODE_PCIE1_BASE;
        break;
        case MST_PORT_NODE_B53:
        master_addr = (MstPortNode *)MST_PORT_NODE_B53_BASE;
        break;
        case MST_PORT_NODE_PCIE2:
        master_addr = (MstPortNode *)MST_PORT_NODE_PCIE2_BASE;
        break;
        case MST_PORT_NODE_SATA:
        master_addr = (MstPortNode *)MST_PORT_NODE_SATA_BASE;
        break;
        case MST_PORT_NODE_USB:
        master_addr = (MstPortNode *)MST_PORT_NODE_USB_BASE;
        break;
        case MST_PORT_NODE_PMC:
        master_addr = (MstPortNode *)MST_PORT_NODE_PMC_BASE;
        break;
        case MST_PORT_NODE_APM:
        master_addr = (MstPortNode *)MST_PORT_NODE_APM_BASE;
        break;
        case MST_PORT_NODE_PER:
        master_addr = (MstPortNode *)MST_PORT_NODE_PER_BASE;
        break;
        case MST_PORT_NODE_DMA0:
        master_addr = (MstPortNode *)MST_PORT_NODE_DMA0_BASE;
        break;
        case MST_PORT_NODE_DMA1:
        master_addr = (MstPortNode *)MST_PORT_NODE_DMA1_BASE;
        break;
        case MST_PORT_NODE_RQ1:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ1_BASE;
        break;
        case MST_PORT_NODE_RQ2:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ2_BASE;
        break;
        case MST_PORT_NODE_RQ3:
        master_addr = (MstPortNode *)MST_PORT_NODE_RQ3_BASE;
        break;
        case MST_PORT_NODE_NATC:
        master_addr = (MstPortNode *)MST_PORT_NODE_NATC_BASE;
        break;
        case MST_PORT_NODE_DQM:
        master_addr = (MstPortNode *)MST_PORT_NODE_DQM_BASE;
        break;
        case MST_PORT_NODE_QM:
        master_addr = (MstPortNode *)MST_PORT_NODE_QM_BASE;
        break;
#endif
        default:
        ret = -1;
    }

    if(!master_addr)
    {
        printk("Node %d master address is zero\n", node);
        return -1;
    }
    if(!ret)
        master_addr->token[token] = credits;

    return ret;
}

#ifndef _CFE_
EXPORT_SYMBOL(ubus_master_set_token_credits);
#endif
#endif


#ifndef _CFE_
arch_initcall(bcm_misc_hw_init);
#endif

