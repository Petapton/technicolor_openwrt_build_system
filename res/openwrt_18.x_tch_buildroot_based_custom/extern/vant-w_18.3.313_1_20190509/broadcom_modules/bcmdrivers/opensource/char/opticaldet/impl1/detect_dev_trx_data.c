/*
<:copyright-BRCM:2015:DUAL/GPL:standard

   Copyright (c) 2015 Broadcom 
   All Rights Reserved

Unless you and Broadcom execute a separate written software license
agreement governing use of this software, this software is licensed
to you under the terms of the GNU General Public License version 2
(the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
with the following added to such license:

   As a special exception, the copyright holders of this software give
   you permission to link this software with independent modules, and
   to copy and distribute the resulting executable under terms of your
   choice, provided that you also meet, for each linked independent
   module, the terms and conditions of the license of that module.
   An independent module is a module which is not derived from this
   software.  The special exception does not apply to any modifications
   of the software.

Not withstanding the above, under no circumstances may you combine
this software in any way with any other Broadcom software provided
under a license other than the GPL, without Broadcom's express prior
written consent.

:>
*/
#include <linux/i2c.h>
#include <linux/slab.h>  /* kzalloc() */
#include <linux/types.h>
#include <boardparms.h>
#include <board.h>
#include <pon_i2c.h>
#include "detect.h"
#include "trx_descr_usr.h"

#define TRX_EEPROM_OFFSET_TYPE  0
#define TRX_EEPROM_OFFSET_NAME 20
#define TRX_EEPROM_OFFSET_OUI  37
#define TRX_EEPROM_OFFSET_REV  56
#define TRX_EEPROM_OFFSET_PN   40
#define TRX_EEPROM_LEN_NAME    16
#define TRX_EEPROM_LEN_OUI      3
#define TRX_EEPROM_LEN_REV      4
#define TRX_EEPROM_LEN_PN      16
#define SOURCEPHOTONICS_FIXUP_PN "SPPS2748FN2CDFA"


#define TRX_XFP_EEPROM_PAGE_SELECT   127
#define TRX_XFP_EEPROM_PAGE_1        128
#define TRX_XFP_EEPROM_OFFSET_NAME   148
#define TRX_XFP_EEPROM_OFFSET_PN     168


static TRX_DESCRIPTOR* trx_curr_p = NULL;

void print_part(uint8_t *data, char *ptype, char *prefix, int from, int len){
    int i;

    printk("%s: ", prefix);
    for (i = from; i < from + len; i++)
        printk(ptype, data[i]);

    printk("\n");
}

void trx_fixup(void)
{
    unsigned short gpio;

    if (trx_curr_p != NULL)
    {

       /* Pull pin 9 on module for SOURCEPHOTONICS XGPON */
      if ((!BpGetOpticalModuleFixupGpio(&gpio)) && trx_curr_p->tx_pwr_down_cfg_req)
       {
        printk(KERN_ALERT "Opticaldet: doing the power down pin fixup\n");
         
         kerSysSetGpioState(gpio, (trx_curr_p->tx_pwr_down_polarity==TRX_ACTIVE_LOW) ? kGpioInactive : kGpioActive);
       }

    }
}

static char *trx_module_type_table[11] = {
   "UNKNOWN",   /* 0x0 */
   "GBIC",      /* 0x1 */
   "SFF",       /* 0x2 - SFF */
   "SFP/SFP+",  /* 0x3 - SFP or SFP+ */
   "XBI",       /* 0x4 */
   "XENPAK",    /* 0x5 */
   "XFP",       /* 0x6 */
   "XFF",       /* 0x7 */
   "XFP-E",     /* 0x8 */
   "XPAK",      /* 0x9 */
   "X2"         /* 0xA */
} ;

static TRX_DESCRIPTOR default_pluggable_trx = {
    .form_factor           = TRX_SFP,              
    .vendor_name           = "Default",
    .vendor_pn             = "Default",
    .lbe_polarity          = TRX_ACTIVE_LOW,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
} ;


static TRX_DESCRIPTOR default_on_board_trx = {
    .form_factor           = TRX_SFF,              
    .vendor_name           = "Default",
    .vendor_pn             = "Default",
    .lbe_polarity          = TRX_ACTIVE_HIGH,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
} ;

static TRX_DESCRIPTOR default_pmd_trx = {
    .form_factor           = TRX_PMD,
    .vendor_name           = "BRoadcom",
    .vendor_pn             = "689xx",
    .lbe_polarity          = TRX_ACTIVE_HIGH,
    .tx_sd_polarity        = TRX_ACTIVE_HIGH,
    .tx_pwr_down_polarity  = TRX_ACTIVE_LOW,
    .tx_pwr_down_cfg_req   = BDMF_FALSE
} ;


static void trx_find_descriptor(uint8_t trx_type, char *vendor, char *part_number)
{
   int trx_gen_size ;
   int trx_usr_size ;
   int i ;

   trx_gen_size = sizeof (trx_lst) / sizeof (TRX_DESCRIPTOR) ;

   trx_usr_size = sizeof (trx_usr) / sizeof (TRX_DESCRIPTOR) ;

   for (i=0; i<trx_usr_size; i++) {
     if ((!strncmp(vendor, trx_usr[i].vendor_name, strlen(trx_usr[i].vendor_name))) &&
         (!strncmp(part_number, trx_usr[i].vendor_pn, strlen(trx_usr[i].vendor_pn)))) 
     {
          trx_curr_p = &trx_usr[i];
          return ;
     }
   }

   for (i=0; i<trx_gen_size; i++) {
      if (!strncmp(vendor, trx_lst[i].vendor_name, strlen(trx_lst[i].vendor_name)) &&
          !strncmp(part_number, trx_lst[i].vendor_pn, strlen(trx_lst[i].vendor_pn))) 
      {
         trx_curr_p = &trx_lst[i];
         printk(KERN_ALERT  "Opticaldet: Known TRX - Vendor: %s PN %s\n", trx_lst[i].vendor_name, trx_lst[i].vendor_pn);
         return ;
      }
   }
   /*
    *    TRX not found
    */
   trx_curr_p = (trx_type == TRX_SFF)? &default_on_board_trx : &default_pluggable_trx ;
   printk(KERN_ALERT "************************************************************************\n");
   printk(KERN_ALERT "* Opticaldet: Unknown WAN optical module - using default configuration *\n");
   printk(KERN_ALERT "************************************************************************\n");
}


static void i2c_read_sff_sfp_data(uint8_t trx_type)
{
   uint8_t i, data[70] ;
   uint8_t i2c_byte ;


   for (i = 0; i < 70; i++)
    {
        i2c_byte = ponPhy_read_byte(0, i);
        if (i2c_byte < 0)
        {
            printk(KERN_ALERT "Opticaldet:>>>> Error reading from i2c at offset %d\n", i) ;
            return;
        }

        data[i] = i2c_byte;
    }

   print_part(&data[0], "%c", "NAME", TRX_EEPROM_OFFSET_NAME, TRX_EEPROM_LEN_NAME);
   print_part(&data[0], "%c", "Rev",  TRX_EEPROM_OFFSET_REV, TRX_EEPROM_LEN_REV);
   print_part(&data[0], "%c", "PN",   TRX_EEPROM_OFFSET_PN, TRX_EEPROM_LEN_PN);


   trx_find_descriptor(trx_type, &data[TRX_EEPROM_OFFSET_NAME], &data[TRX_EEPROM_OFFSET_PN]) ;
}


static void i2c_read_xfp_data(uint8_t trx_type)
{

   uint8_t i, data[70] ;
   uint8_t i2c_byte ;
   int rc ;
   
   rc = ponPhy_write_byte (0, TRX_XFP_EEPROM_PAGE_SELECT, 1);
   if (rc < 0)
   {
       printk(">>>> Error writing to i2c at offset %d\n", TRX_XFP_EEPROM_PAGE_SELECT) ;
       return;
   }


   for (i = 0; i < 60; i++)
    {
        i2c_byte = ponPhy_read_byte(0, i + TRX_XFP_EEPROM_PAGE_1);
        if (i2c_byte < 0)
        {
            printk(KERN_ALERT "Opticaldet:>>>> Error reading from i2c at offset %d\n", i + TRX_XFP_EEPROM_PAGE_1) ;
            return;
        }

        data[i] = i2c_byte;
    }

   print_part(&data[0], "%c", "NAME", TRX_XFP_EEPROM_OFFSET_NAME - TRX_XFP_EEPROM_PAGE_1, TRX_EEPROM_LEN_NAME);
   print_part(&data[0], "%c", "PN",   TRX_XFP_EEPROM_OFFSET_PN - TRX_XFP_EEPROM_PAGE_1, TRX_EEPROM_LEN_PN);

   trx_find_descriptor(trx_type, &data[TRX_XFP_EEPROM_OFFSET_NAME - TRX_XFP_EEPROM_PAGE_1], &data[TRX_XFP_EEPROM_OFFSET_PN - TRX_XFP_EEPROM_PAGE_1]) ;
}


void i2c_read_trx_data(void)
{
    int trx_type;
    uint16_t OpticsTypeFlag = 0;

    printk("WAN module detected:\n");

    BpGetGponOpticsType(&OpticsTypeFlag);
    if (OpticsTypeFlag == BP_GPON_OPTICS_TYPE_PMD)
    {
        printk("Opticaldet: PMD found\n");
        trx_curr_p = &default_pmd_trx;
    }
    else
    {
        trx_type = ponPhy_read_byte(0, 0);
        if (trx_type < 0)
        {
            printk(KERN_ALERT "Opticaldet: No TRX found\n");
            trx_curr_p = NULL; /* To indicate that actually no TRX was found */
        }
        else
        {
            printk("Module Type : %s\n", trx_module_type_table[trx_type]) ;
            switch (trx_type)
            {
                case TRX_SFF:
                   i2c_read_sff_sfp_data(trx_type);
                break;

                case TRX_SFP:
                   i2c_read_sff_sfp_data(trx_type);
                break;

                case TRX_XFP:
                   i2c_read_xfp_data(trx_type);
                break;

                default:
                   printk(KERN_ALERT "Opticaldet: Illegal TRX type %d\n", trx_type);
                   trx_curr_p = (trx_type == TRX_SFF)? &default_on_board_trx : &default_pluggable_trx ;
            }
        }
    }
}

int trx_get_lbe_polarity(TRX_SIG_ACTIVE_POLARITY *lbe_polarity_p)
{
  if (trx_curr_p) {
    *lbe_polarity_p = trx_curr_p->lbe_polarity ;
    return 0;
  } 
  else {
    return -1;
  }
}
EXPORT_SYMBOL(trx_get_lbe_polarity);

int trx_get_tx_sd_polarity(TRX_SIG_ACTIVE_POLARITY *tx_sd_polarity_p)
{
  if (trx_curr_p) {
    *tx_sd_polarity_p = trx_curr_p->tx_sd_polarity ;
    return 0;
  } 
  else {
    return -1;
  }
}
EXPORT_SYMBOL(trx_get_tx_sd_polarity);

int trx_get_vendor_name_part_num(char *vendor_name_p, int vendor_name_len,
                                 char *part_num_p, int part_num_len)
{
   if (trx_curr_p) {
      strncpy(vendor_name_p, trx_curr_p->vendor_name, vendor_name_len);
      strncpy(part_num_p, trx_curr_p->vendor_pn, part_num_len);
      return 0;
  } 
  else {
    return -1;
  }
}
EXPORT_SYMBOL(trx_get_vendor_name_part_num);


