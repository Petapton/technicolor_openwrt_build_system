/*
    pon_i2c.c - I2C client driver for PON transceiver
    Copyright (C) 2008 Broadcom Corp.
 
* <:copyright-BRCM:2012:DUAL/GPL:standard
* 
*    Copyright (c) 2012 Broadcom 
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

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/slab.h>  /* kzalloc() */
#include <linux/types.h>
#include <linux/bcm_log.h>
#include "pmd.h"
#include <boardparms.h>
#include <pon_i2c.h>
#include "opif.h"

#ifdef PROCFS_HOOKS
#include <asm/uaccess.h> /*copy_from_user*/
#include <linux/proc_fs.h>
#define PROC_DIR_NAME "i2c_pon"
#define PROC_ENTRY_NAME1 "ponPhy_eeprom0"
#define PROC_ENTRY_NAME2 "ponPhy_eeprom1"
#define PROC_ENTRY_NAME4 "ponPhy_eeprom2"
#ifdef GPON_I2C_TEST
#define PROC_ENTRY_NAME3 "ponPhyTest"
#endif
#endif


/* I2C client chip addresses */
/* Note that these addresses are 7-bit addresses without the LSB bit
   which indicates R/W operation */
#ifdef CONFIG_BCM_GPON_BOSA
#define PON_PHY_I2C_ADDR1 0x4E
#define PON_PHY_I2C_ADDR2 0x4F
#else
#define PON_PHY_I2C_ADDR1 0x50
#define PON_PHY_I2C_ADDR2 0x51
#endif
#define PON_PHY_I2C_ADDR3 0x52

/* Addresses to scan */
static unsigned short normal_i2c[] = {PON_PHY_I2C_ADDR1,
                                      PON_PHY_I2C_ADDR2,
                                      PON_PHY_I2C_ADDR3, I2C_CLIENT_END};

/* file system */
enum fs_enum {PROC_FS, SYS_FS};

/* Size of client in bytes */
#define DATA_SIZE             256
#define DWORD_ALIGN           4
#define WORD_ALIGN            2

/* Client0 for Address 0x50 and Client1 for Address 0x51, Client2 for Address 0x52 */
#define client0               0
#define client1               1
#define client2               2

#ifndef PON_I2C_IOCTL
#define PON_I2C_IOCTL 1
#endif

/* Each client has this additional data */
struct ponPhy_data {
    struct i2c_client client;
};

/* Assumption: The i2c modules will be built-in to the kernel and will not be 
   unloaded; otherwise, it is possible for caller modules to call the exported
   functions even when the i2c modules are not loaded unless some registration
   mechanism is built-in to this module.  */
static struct ponPhy_data *pclient1_data;
static struct ponPhy_data *pclient2_data;
static struct ponPhy_data *pclient3_data;

static int ponPhy_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int ponPhy_remove(struct i2c_client *client);
static int ponPhy_detect(struct i2c_client *, struct i2c_board_info *);

/* Check if given offset is valid or not */
static inline int check_offset(u8 offset, u8 alignment)
{
    if (offset % alignment) {
        BCM_LOG_ERROR(BCM_LOG_ID_I2C, "Invalid offset %d. The offset should be"
                      " %d byte alligned \n", offset, alignment);
        return -1;
    }
    return 0;
}


static int get_client(u8 client_num, struct i2c_client **client)
{
    switch (client_num)
    {
    case 0:
        *client = &pclient1_data->client;
        break;
    case 1:
        *client = &pclient2_data->client;
        break;
    case 2:
        *client = &pclient3_data->client;
        break;
    default:
        BCM_LOG_ERROR(BCM_LOG_ID_I2C, "Invalid client number \n");
        return -1;
    }

    if(*client == NULL)
    {
        BCM_LOG_ERROR(BCM_LOG_ID_I2C, "Invalid client %d \n", client_num);
        return -1;
    }
    
    return 0;
}

/****************************************************************************/
/* generic_i2c_access: Provides a way to use BCM6816 algorithm driver to    */
/*  access any I2C device on the bus                                        */
/* Inputs: i2c_addr = 7-bit I2C address; offset = 8-bit offset; length =    */
/*  length (limited to 4); val = value to be written; set = indicates write */
/* Returns: None                                                            */
/****************************************************************************/
static void generic_i2c_access(u8 i2c_addr, u8 offset, u8 length, 
                               int val, u8 set)
{
    struct i2c_msg msg[2];
    char buf[5];
    int i;

    if (length > 4)
    {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Read limited to 4 bytes\n");
        return;
    }

    /* First write the offset  */
    msg[0].addr = msg[1].addr = i2c_addr;
    msg[0].flags = msg[1].flags = 0;

    /* if set = 1, do i2c write; otheriwse do i2c read */
    if (set) {
        msg[0].len = length + 1;
        buf[0] = offset;
        /* On the I2C bus, LS Byte should go first */
#ifndef __LITTLE_ENDIAN 
        val = swab32(val);
#endif
        memcpy(&buf[1], (char*)&val, length);
        msg[0].buf = buf;
        if(i2c_transfer(pclient1_data->client.adapter, msg, 1) != 1) {
            BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "I2C Write Failed \n");
        }
    } else {
        /* write message */
        msg[0].len = 1;
        buf[0] = offset;
        msg[0].buf = buf;
        /* read message */
        msg[1].flags |= I2C_M_RD;
        msg[1].len = length;
        msg[1].buf = buf;

        /* On I2C bus, we receive LS byte first. So swap bytes as necessary */
        if(i2c_transfer(pclient1_data->client.adapter, msg, 2) == 2)
        {
            for (i=0; i < length; i++) {
                printk("0x%2x = 0x%2x \n", offset + i, buf[i] & 0xFF);
            }
            printk("\n");
        } else {
            BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "I2C Read Failed \n");
        }
    }
}

/****************************************************************************/
/* Write ponPhy: Writes count number of bytes from buf on to the I2C bus   */
/* Returns:                                                                 */
/*   number of bytes written on success, negative value on failure.         */
/* Notes: 1. The LS byte should follow the offset                           */
/* Design Notes: The ponPhy takes the first byte after the chip address    */
/*  as offset. The BCM6816 can only send/receive upto 8 or 32 bytes         */
/*  depending on I2C_CTLHI_REG.DATA_REG_SIZE configuration in one           */
/*  transaction without using the I2C_IIC_ENABLE NO_STOP functionality.     */
/*  The 6816 algorithm driver currently splits a given transaction larger   */
/*  than DATA_REG_SIZE into multiple transactions. This function is         */   
/*  expected to be used very rarely and hence a simple approach is          */
/*  taken whereby this function limits the count to 32 (Note that the 6816  */
/*  I2C_CTLHI_REG.DATA_REG_SIZE is hard coded in 6816 algorithm driver for  */
/*  32B. This means, we can only write upto 31 bytes using this function.   */
/****************************************************************************/
ssize_t ponPhy_write(u8 client_num, char *buf, size_t count)
{
    struct i2c_client *client = NULL;
    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(count > MAX_TRANSACTION_SIZE)
    {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "count > %d is not yet supported \n", MAX_TRANSACTION_SIZE);
        return -1;
    }
  
    if(get_client(client_num, &client))
    {
        return -1;
    }
    
    return i2c_master_send(client, buf, count);
}
EXPORT_SYMBOL(ponPhy_write);

/****************************************************************************/
/* Read: Reads count number of bytes from BCM3450                   */
/* Returns:                                                                 */
/*   number of bytes read on success, negative value on failure.            */
/* Notes: 1. The offset should be provided in buf[0]                        */
/*        2. The count is limited to 32.                                    */
/*        3. The ponPhy with the serial EEPROM protocol requires the offset*/
/*        be written before reading the data on every I2C transaction       */
/****************************************************************************/
ssize_t ponPhy_read(u8 client_num, char *buf, size_t count)
{
    struct i2c_msg msg[2];
    struct i2c_client *client = NULL;
    uint16_t OpticsType;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(count > MAX_TRANSACTION_SIZE)
    {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "count > %d is not yet supported \n", MAX_TRANSACTION_SIZE);
        return -1;
    }

    if(get_client(client_num, &client))
    {
        return -1;
    }

    /* First write the offset  */
    msg[0].addr = msg[1].addr = client->addr;
    msg[0].flags = msg[1].flags = client->flags & I2C_M_TEN;

    BpGetGponOpticsType( &OpticsType );

    if ( OpticsType == BP_GPON_OPTICS_TYPE_PMD )
        msg[0].len = PMD_I2C_HEADER;
    else
        msg[0].len = 1;

    msg[0].buf = buf;

    /* Now read the data */
    msg[1].flags |= I2C_M_RD;
    msg[1].len = count;
    msg[1].buf = buf;

    /* On I2C bus, we receive LS byte first. So swap bytes as necessary */
    if(i2c_transfer(client->adapter, msg, 2) == 2)
    {
        return count;
    }

    return -1;
}
EXPORT_SYMBOL(ponPhy_read);

/****************************************************************************/
/* Write Register: Writes the val into ponPhy register                     */
/* Returns:                                                                 */
/*   0 on success, negative value on failure.                               */
/* Notes: 1. The offset should be DWORD aligned                             */
/****************************************************************************/
int ponPhy_write_reg(u8 client_num, u8 offset, int val)
{
    char buf[5];
    struct i2c_client *client = NULL;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(check_offset(offset, DWORD_ALIGN))
    {
        return -1;
    }

    if(get_client(client_num, &client))
    {
        return -1;
    }

    /* Set the buf[0] to be the offset for write operation */
    buf[0] = offset;

    /* On the I2C bus, LS Byte should go first */
#ifndef __LITTLE_ENDIAN  
    val = swab32(val);
#endif
    memcpy(&buf[1], (char*)&val, 4);
    if (i2c_master_send(client, buf, 5) == 5)
    {
        return 0;
    }
    return -1;
}
EXPORT_SYMBOL(ponPhy_write_reg);

/****************************************************************************/
/* Read Register: Read the ponPhy register                                 */
/* Returns:                                                                 */
/*   value on success, negative value on failure.                           */
/* Notes: 1. The offset should be DWORD aligned                             */
/****************************************************************************/
int ponPhy_read_reg(u8 client_num, u8 offset)
{
    struct i2c_msg msg[2];
    int val;
    struct i2c_client *client = NULL;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(check_offset(offset, DWORD_ALIGN))
    {
        return -1;
    }

    if(get_client(client_num, &client))
    {
            return -1;
    }

    msg[0].addr = msg[1].addr = client->addr;
    msg[0].flags = msg[1].flags = client->flags & I2C_M_TEN;

    msg[0].len = 1;
    msg[0].buf = (char *)&offset;

    msg[1].flags |= I2C_M_RD;
    msg[1].len = 4;
    msg[1].buf = (char *)&val;

    /* On I2C bus, we receive LS byte first. So swap bytes as necessary */
    if(i2c_transfer(client->adapter, msg, 2) == 2)
    {
#ifdef __LITTLE_ENDIAN
        return val;
#else 
        return swab32(val);
#endif
    }

    return -1;
}
EXPORT_SYMBOL(ponPhy_read_reg);

/****************************************************************************/
/* Write Word: Writes the val into the word offset                          */ 
/* Returns:                                                                 */
/*   0 on success, negative value on failure.                               */
/* Notes: 1. The offset should be WORD aligned                              */
/****************************************************************************/
int ponPhy_write_word(u8 client_num, u8 offset, u16 val)
{
    char buf[3];
    struct i2c_client *client = NULL;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(check_offset(offset, WORD_ALIGN))
    {
        return -1;
    }

    if(get_client(client_num, &client))
    {
        return -1;
    }

    /* The offset to be written should be the first byte in the I2C write */
    buf[0] = offset;
    buf[1] = (char)(val&0xFF);
    buf[2] = (char)(val>>8);
    if (i2c_master_send(client, buf, 3) == 3)
    {
        return 0;
    }
    return -1;
}
EXPORT_SYMBOL(ponPhy_write_word);

/****************************************************************************/
/* Read Word: Reads the LSB 2 bytes of Register                             */ 
/* Returns:                                                                 */
/*   value on success, negative value on failure.                           */
/* Notes: 1. The offset should be WORD aligned                              */
/****************************************************************************/
int ponPhy_read_word(u8 client_num, u8 offset)
{
    struct i2c_msg msg[2];
    u16 val;
    struct i2c_client *client = NULL;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(check_offset(offset, WORD_ALIGN))
    {
        return -1;
    }

    if(get_client(client_num, &client))
    {
        return -1;
    }

    msg[0].addr = msg[1].addr = client->addr;
    msg[0].flags = msg[1].flags = client->flags & I2C_M_TEN;

    msg[0].len = 1;
    msg[0].buf = (char *)&offset;

    msg[1].flags |= I2C_M_RD;
    msg[1].len = 2;
    msg[1].buf = (char *)&val;

    if(i2c_transfer(client->adapter, msg, 2) == 2)
    {        
#ifdef __LITTLE_ENDIAN
        return val;
#else 
        return swab16(val);
#endif
    }

    return -1;
}
EXPORT_SYMBOL(ponPhy_read_word);

/****************************************************************************/
/* Write Byte: Writes the val into LS Byte of Register                      */ 
/* Returns:                                                                 */
/*   0 on success, negative value on failure.                               */
/****************************************************************************/
int ponPhy_write_byte(u8 client_num, u8 offset, u8 val)
{
    char buf[2];
    struct i2c_client *client = NULL;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(get_client(client_num, &client))
    {
        return -1;
    }

    /* BCM3450 requires the offset to be the register number */
    buf[0] = offset;
    buf[1] = val;
    if (i2c_master_send(client, buf, 2) == 2)
    {
        return 0;
    }
    return -1;
}
EXPORT_SYMBOL(ponPhy_write_byte);

/****************************************************************************/
/* Read Byte: Reads the LS Byte of Register                                 */ 
/* Returns:                                                                 */
/*   value on success, negative value on failure.                           */
/****************************************************************************/
int ponPhy_read_byte(u8 client_num, u8 offset)
{
    struct i2c_msg msg[2];
    char val;
    struct i2c_client *client = NULL;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if(get_client(client_num, &client))
    {
        return -1;
    }

    msg[0].addr = msg[1].addr = client->addr;
    msg[0].flags = msg[1].flags = client->flags & I2C_M_TEN;

    msg[0].len = 1;
    msg[0].buf = (char *)&offset;

    msg[1].flags |= I2C_M_RD;
    msg[1].len = 1;
    msg[1].buf = (char *)&val;

    if(i2c_transfer(client->adapter, msg, 2) == 2)
    {
        return val;
    }

    return -1;
}
EXPORT_SYMBOL(ponPhy_read_byte);

#if defined(SYSFS_HOOKS) || defined(PROCFS_HOOKS)
#ifdef GPON_I2C_TEST
static int client_num = 0;
/* Calls the appropriate function based on user command */
static int exec_command(const char *buf, size_t count, int fs_type)
{
#define MAX_ARGS 4
#define MAX_ARG_SIZE 32
    int i, argc = 0, val = 0;
    char cmd;
    u8 offset, i2c_addr, length, set = 0;
    char arg[MAX_ARGS][MAX_ARG_SIZE];
#ifdef PROCFS_HOOKS
#define LOG_WR_KBUF_SIZE 128
    char kbuf[LOG_WR_KBUF_SIZE];

    if(fs_type == PROC_FS)
    {
        if ((count > LOG_WR_KBUF_SIZE-1) || 
            (copy_from_user(kbuf, buf, count) != 0))
            return -EFAULT;
        kbuf[count]=0;
        argc = sscanf(kbuf, "%c %s %s %s %s", &cmd, arg[0], arg[1], 
                      arg[2], arg[3]);
    }
#endif

#ifdef SYSFS_HOOKS
    if(fs_type == SYS_FS)
        argc = sscanf(buf, "%c %s %s %s %s", &cmd, arg[0], arg[1], 
                      arg[2], arg[3]);
#endif

    if (argc < 1) {
        return -EFAULT;
    }

    for (i=0; i<MAX_ARGS; ++i) {
        arg[i][MAX_ARG_SIZE-1] = '\0';
    }

    offset = (u8) 0;
    if (argc >= 2)
    {
        offset = (u8) simple_strtoul(arg[0], NULL, 0);
    }

    if (argc == 3)
    {
        val = (int) simple_strtoul(arg[1], NULL, 0);
    }

    switch (cmd) {
 
       case 'a':
        if (argc >= 4) {
            i2c_addr = (u8) simple_strtoul(arg[0], NULL, 0);
            offset = (u8) simple_strtoul(arg[1], NULL, 0);
            length = (u8) simple_strtoul(arg[2], NULL, 0);
            BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "I2C Access: i2c_addr = 0x%x, offset"
                          " = 0x%x, len = %d \n", i2c_addr, offset, length);
            if (i2c_addr > 127 || length > 4) {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Invalid I2C addr or len \n");
                return -EFAULT;
            }
            val = 0;
            if (argc > 4) {
                val = (int) simple_strtoul(arg[3], NULL, 0);
                set = 1;
            }
            generic_i2c_access(i2c_addr, offset, length, val, set);
        } else {
            BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Need at-least 3 arguments \n");
            return -EFAULT;
        }
        break;

    case 'b':
        if (argc == 3) {
            BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Write Byte: offset = 0x%x, " 
                          "val = 0x%x \n", offset, val);
            if (ponPhy_write_byte(client_num, offset, (u8)val) < 0) {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Write Failed \n"); 
            } else {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Write Successful \n"); 
            }
        }
        else {
            if((val = ponPhy_read_byte(client_num, offset)) < 0) {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Read Failed \n"); 
            } else {
                 BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Read Byte: offset = 0x%x, " 
                                "val = 0x%x \n", offset, val);
            }
        }
        break;

    case 'w':
        if (argc == 3) {
            BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Write Word: offset = 0x%x, " 
                              "val = 0x%x \n", offset, val);
            if (ponPhy_write_word(client_num, offset, (u16)val) < 0) {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Write Failed \n"); 
            } else {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Write Successful \n"); 
            }
        }
        else {
            if((val = ponPhy_read_word(client_num, offset)) < 0) {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Read Failed \n"); 
            } else {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Read Word: offset = 0x%x, " 
                               "val = 0x%x \n", offset, val);
            }
        }
        break;

    case 'd':    
        if (argc == 3) {
            BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Write Register: offset = 0x%x, " 
                          "val = 0x%x \n", offset, val);
            if (ponPhy_write_reg(client_num, offset, val) < 0) {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Write Failed \n"); 
            } else {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Write Successful \n"); 
            }
        }
        else {
            if((val = ponPhy_read_reg(client_num, offset)) < 0) {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Read Failed \n"); 
            } else {
                BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Read Register: offset = 0x%x,"
                               " val = 0x%x \n", offset, val);
            }
        }
        break;

    case 'c':    
        if (offset == PON_PHY_I2C_ADDR1)
            client_num = 0;
        else if (offset == PON_PHY_I2C_ADDR2)
            client_num = 1;
        else 
            client_num = 2;
        break;

    default:
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Invalid command. \n Valid commands: \n" 
                       "  Change I2C Addr b/w 0x50 and 0x51: c addr \n" 
                       "  Write Reg:       d offset val \n" 
                       "  Read Reg:        d offset \n" 
                       "  Write Word:      w offset val \n" 
                       "  Read Word:       w offset \n" 
                       "  Write Byte:      b offset val \n" 
                       "  Read Byte:       b offset \n" 
                       "  Generic I2C access: a <i2c_addr(7-bit)>" 
                       " <offset> <length(1-4)> [value] \n" 
                       );
        break;
    }
    return count;
}
#endif
#endif

#ifdef PROCFS_HOOKS
#ifdef GPON_I2C_TEST
/* Read Function of PROCFS attribute "ponPhyTest" */
static ssize_t ponPhy_proc_test_read(struct file *f, char *buf, size_t count,
                               loff_t *pos) 
{
    BCM_LOG_NOTICE(BCM_LOG_ID_I2C, " Usage: echo command > "
                   " /proc/i2c-pon/ponPhyTest \n");
    BCM_LOG_NOTICE(BCM_LOG_ID_I2C, " supported commands: \n" 
                   "  Change I2C Addr b/w 0x50 and 0x51: c addr \n" 
                   "  Write Reg:       d offset val \n" 
                   "  Read Reg:        d offset \n" 
                   "  Write Word:      w offset val \n" 
                   "  Read Word:       w offset \n" 
                   "  Write Byte:      b offset val \n" 
                   "  Read Byte:       b offset \n" 
                   "  Generic I2C access: a <i2c_addr(7-bit)>" 
                   " <offset> <length(1-4)> [value] \n" 
                   );
    return 0;
}

/* Write Function of PROCFS attribute "ponPhyTest" */
static ssize_t ponPhy_proc_test_write(struct file *f, const char *buf,
                                       size_t count, loff_t *pos)
{
    return exec_command(buf, count, PROC_FS);
}
#endif

#define PON_PHY_EEPROM_SIZE  256
/* Read Function of PROCFS attribute "ponPhy_eepromX" */
static ssize_t ponPhy_proc_read(struct file *filep, char __user *page, size_t count, loff_t *offset)
{
    int client_num = 0, max_offset, ret_val;
    struct ponPhy_data *pclient_data;
    int off = (int)(*offset);

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "The offset is %d; the count is %d \n", 
                  (int)off, (int)count);

    /* Verify that max_offset is below the max_eeprom_size (256 Bytes)*/
    max_offset = (int) (off + count);
    if (max_offset > PON_PHY_EEPROM_SIZE) {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "offset + count must be less than "
                       "Max EEPROM Size of 256\n");
        return -1;
    }
 
    /* Set the page[0] to eeprom offset */
    page[0] = (u8)off;

    /* Select the eeprom of the 2 eeproms inside ponPhy */
    pclient_data = (struct ponPhy_data *)(PDE_DATA(file_inode(filep)));
    if (pclient_data->client.addr == PON_PHY_I2C_ADDR2) {
        client_num = 1;
    }

    ret_val = ponPhy_read(client_num, page, count);
    if( ret_val > 0 )
        *offset += ret_val;

   /* return zero here to indicate EOF */
    return ((ret_val < 0) ? ret_val : 0);
}

/* Write Function of PROCFS attribute "ponPhy_eepromX" */
static ssize_t ponPhy_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *off)
{
    int client_num = 0, max_offset;
    struct ponPhy_data *pclient_data;
    char *kbuf;
    int rc;
    int offset = (int)(*off);

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "The offset is %d; the count is %ld \n", 
                  offset, (long)count);

    /* Verify that count is less than 31 bytes */
    if ((count+1) > MAX_TRANSACTION_SIZE)
    {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Writing more than 31 Bytes is not"
                       "yet supported \n");
        return -1;
    }

    kbuf = kzalloc(count, GFP_KERNEL);
    if (!kbuf)
    {
        BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Couldn't allocated kbuf \n");
        return -1;
    }
 
    /* Verify that max_offset is below the max_eeprom_size (256 Bytes)*/
    max_offset = (int) (offset + count);
    if (max_offset > PON_PHY_EEPROM_SIZE)
    {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "offset + count must be less than "
                       "Max EEPROM Size of 256\n");
        rc = -1;
        goto exit;
    }  
   
    /* Select the eeprom of the 2 eeproms inside ponPhy */
    pclient_data = (struct ponPhy_data *)(PDE_DATA(file_inode(file)));

    if (pclient_data->client.addr == PON_PHY_I2C_ADDR2)
        client_num = 1;

    if (pclient_data->client.addr == PON_PHY_I2C_ADDR3)
    {
        client_num = 2;
    }

    kbuf[0] = (u8)offset;
    copy_from_user(&kbuf[1], buffer, count);
    /* Return the number of bytes written (exclude the address byte added
       at kbuf[0] */
    rc = ponPhy_write(client_num, kbuf, count+1) - 1;
exit:
    kfree(kbuf);
    return rc;
}
#endif

#ifdef SYSFS_HOOKS
/* Read Function of SYSFS attribute */
static ssize_t ponPhy_sys_read(struct device *dev, struct device_attribute *attr,
                          char *buf)
{
    return snprintf(buf, PAGE_SIZE, "The ponPhy access read attribute \n");
}

/* Write Function of SYSFS attribute */
static ssize_t ponPhy_sys_write(struct device *dev, struct device_attribute *attr,
                           const char *buf, size_t count)
{
    return exec_command(buf, count, SYS_FS);
}

static DEVICE_ATTR(ponPhy_access, S_IRWXUGO, ponPhy_sys_read, ponPhy_sys_write);

static struct attribute *ponPhy_attributes[] = {
    &dev_attr_ponPhy_access.attr,
    NULL
};

static const struct attribute_group ponPhy_attr_group = {
    .attrs = ponPhy_attributes,
};
#endif

#ifdef PROCFS_HOOKS
static struct file_operations ponPhyProc_fops = {
    .owner  = THIS_MODULE,
    .read = ponPhy_proc_read,
    .write = ponPhy_proc_write
};
#ifdef GPON_I2C_TEST
static struct file_operations ponPhyTest_fops = {
    .owner  = THIS_MODULE,
    .read = ponPhy_proc_test_read,
    .write = ponPhy_proc_test_write
};
#endif
#endif

#ifdef PON_I2C_IOCTL
static int ponPhy_write_check_boundary(u8 offset, u8 count)
{
    int max_offset;

    if(IS_BITFIELD_SIZE(count))
        return 0;

    /* Verify that count is less than 31 bytes */
    if ((count+1) > MAX_TRANSACTION_SIZE) {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Writing more than 31 Bytes is not yet supported \n");
        return -1;
    }

    /* Verify that max_offset is below the max_eeprom_size (256 Bytes)*/
    max_offset = (int) (offset + count);
    if (max_offset > PON_PHY_EEPROM_SIZE) {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "offset + count must be less than Max EEPROM Size of 256\n");
        return -1;
    }

    return 0;
}

static int ponPhy_write_n_bytes(u8 client_num, u8 offset, u8 count, u8 *buf)
{
    int ret = 0;

    if(IS_BITFIELD_SIZE(count))  /* write a bit */
    {
        u8 c;

        c = ponPhy_read_byte(client_num, offset);

        if(0 == buf[0])
            c &= ~(1<<(count&0x7f));
        else
            c |= 1<<(count&0x7f);

        ret = ponPhy_write_byte(client_num, offset, c);
    }
    else   /* write n bytes, 1<=n<=31 */
    {
        char kbuf[MAX_TRANSACTION_SIZE];

        kbuf[0] = offset;
        memcpy(&kbuf[1], buf, count);
        ret =  ponPhy_write(client_num, kbuf, count+1) - 1;
    }

    return ret;
}

static long pon_i2c_ioctl(int client_num, unsigned int cmd, unsigned long argument)
{
    int ret = 0;
    u8  len = 0, offset = 0, real_len = 0;
    transceiver_ioctl_st  arg;

    if (cmd >= GPON_I2C_IOC_A2_NUM) {
        BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Now we only support SET and GET, don't support [%d], return!\n", cmd);
        return -EINVAL;
    }

    if (copy_from_user(&arg, (const void*)argument, sizeof(transceiver_ioctl_st)))
        return -EINVAL;

    real_len = (IS_BITFIELD_SIZE(arg.len)) ? 1 : arg.len;
    if (arg.offset + real_len >= PON_PHY_EEPROM_SIZE)
        return -EINVAL;

    if (cmd == GPON_I2C_IOC_SET || cmd == GPON_I2C_IOC_GET) {
        len = arg.len;
        offset = arg.offset;
    }

    switch(cmd)
    {
        case GPON_I2C_IOC_SET:
        {
            if (ponPhy_write_check_boundary(offset, len) < 0)
                return -EFAULT;

            ret = ponPhy_write_n_bytes(client_num, offset, len, arg.buf);
            break;
        }

        case GPON_I2C_IOC_GET:
        {
            if(IS_BITFIELD_SIZE(len))  /* read a bit */
            {
                u8 c;
                c = ponPhy_read_byte(client_num, offset);
                arg.buf[0] = (c & ( 1<<(len&0x7f) )) ? 1 : 0;
                ret = 1;  //read 1 byte
            }
            else   /* read n bytes, 1<=n<=31 */
            {
                arg.buf[0] = offset;
                if ( (ret =  ponPhy_read(client_num, arg.buf, len)) < 0)
                    return ret;

            }

            if (copy_to_user((void*)argument, &arg, sizeof(transceiver_ioctl_st)))
                return -EFAULT;
            break;
        }

        case GPON_I2C_IOC_SET_12V_VIDEO_POWER:
        {
            if (arg.buf[0])
            {
                //uncomment below 2 lines after PEM3 ready
                //GPIO->GPIODir_low |= GPIO_12V_DISABLE;
                //GPIO->GPIOData_low |= GPIO_12V_DISABLE; // set the voltage of pin17 to 12V, to enable the power supply of RF-O
                printk("[pon_i2c] Enable 12V video power supply.\n");
            }
            else
            {
                //uncomment below 2 lines after PEM3 ready
                //GPIO->GPIODir_low |= GPIO_12V_DISABLE;
                //GPIO->GPIOData_low&= ~GPIO_12V_DISABLE; // set the voltage of pin17 to 0V, to disable the power supply of RF-O
                printk("[pon_i2c] Disable 12V video power supply.\n");
            }
            break;
        }

        default:
            printk("KERN_EMERG invalid command, %d\n", cmd);
    };

    return ret;
}


/*   How to use this IOCTL in user space?
 *   1.Set a field
 *      CMD: GPON_I2C_IOC_SET
 *      example:
 *              transceiver_ioctl_st  arg;
 *              memset(&arg, 0, sizeof(arg));
 *              //set field_id and fill out buf
 *              arg.field_id = index;
 *              memcpy(arg.buf, pMsg->value, pCmd->nDataLen);
 *              ioctl(i2c_socket, GPON_I2C_IOC_SET, (u32)&arg);
 *      Return value:
 *             number of bytes written on success, negative value on failure.
 *             -EINVAL: Invalid argument address
 *             -EACCES: Permission denied
 *             -EFAULT: boundary check failure
 *             -1     : I2C write failure
 *
 *
 *   2.Get a field
 *      CMD: GPON_I2C_IOC_GET
 *      example:
 *              transceiver_ioctl_st  arg;
 *              memset(&arg, 0, sizeof(arg));
 *              //set field_id
 *              arg.field_id = index;
 *              ioctl(i2c_socket, GPON_I2C_IOC_GET, (u32)&arg);
 *      Return value:
 *             number of bytes read on success, negative value on failure.
 *             on success, the bytes read are stored in arg.buf[]
 *             -EINVAL: Invalid argument address
 *             -EFAULT: copy_to_user() failed
 *             -1     : I2C read failure
 */
static long pon_i2c_ioctl_0(struct file *filp, unsigned int cmd, unsigned long argument)
{
    return pon_i2c_ioctl(OP_BANK_A0, cmd, argument);
}

static long pon_i2c_ioctl_1(struct file *filp, unsigned int cmd, unsigned long argument)
{
    return pon_i2c_ioctl(OP_BANK_A2, cmd, argument);
}

static ssize_t pon_fops_read(int client_id, struct file *file, char *buf,
        size_t count, loff_t *pos)
{
    int max_offset, ret_val;
    int off = *pos;
    char kbuf[MAX_TRANSACTION_SIZE]={0};

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "The offset is 0x%x; the count is %d \n", (int)off, count);

    if(count > MAX_TRANSACTION_SIZE)
        count = MAX_TRANSACTION_SIZE;

    /* Verify that max_offset is below the max_eeprom_size (256 Bytes)*/
    max_offset = (int) (off + count);
    if (max_offset > PON_PHY_EEPROM_SIZE) {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "offset + count must be less than Max EEPROM Size of 256\n");
        return -1;
    }

    /* Set the kbuf[0] to eeprom offset */
    kbuf[0] = (u8)off;

    ret_val = ponPhy_read(client_id, kbuf, count);
    if (ret_val > 0)
        copy_to_user(buf, kbuf, ret_val);

    *pos += ret_val;

    return ret_val;
}

static ssize_t pon_fops0_read(struct file *file, char *buf,
        size_t count, loff_t *pos)
{
    return pon_fops_read(client0, file, buf, count, pos);
}

static ssize_t pon_fops1_read(struct file *file, char *buf,
        size_t count, loff_t *pos)
{
    return pon_fops_read(client1, file, buf, count, pos);
}

static ssize_t pon_fops_write(int client_id, struct file * file, const char * buf,
        size_t count, loff_t *pos)
{
    int max_offset, offset = *pos;
    char kbuf[MAX_TRANSACTION_SIZE]={0};

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "The offset is %d; the count is %d \n", offset, count);

    /* Verify that count is less than 31 bytes */
    if ((count+1) > MAX_TRANSACTION_SIZE) {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "Writing more than 31 Bytes is not yet supported \n");
        return -1;
    }

    /* Verify that max_offset is below the max_eeprom_size (256 Bytes)*/
    max_offset = (int) (offset + count);
    if (max_offset > PON_PHY_EEPROM_SIZE) {
        BCM_LOG_NOTICE(BCM_LOG_ID_I2C, "offset + count must be less than Max EEPROM Size of 256\n");
        return -1;
    }

    kbuf[0] = (u8)offset;
    copy_from_user(&kbuf[1], buf, count);
    /* Return the number of bytes written (exclude the address byte added at kbuf[0] */
    return (ponPhy_write(client_id, kbuf, count+1) - 1);
}

static ssize_t pon_fops0_write(struct file *file, const char *buf,
        size_t count, loff_t *pos)
{
    return pon_fops_write(client0, file, buf, count, pos);
}

static ssize_t pon_fops1_write(struct file *file, const char *buf,
        size_t count, loff_t *pos)
{
    return pon_fops_write(client1, file, buf, count, pos);
}

static struct file_operations pon_fops0 = {
read : pon_fops0_read,
write: pon_fops0_write,
unlocked_ioctl: pon_i2c_ioctl_0,
};

static struct file_operations pon_fops1 = {
read : pon_fops1_read,
write: pon_fops1_write,
unlocked_ioctl: pon_i2c_ioctl_1,
};
#endif

#ifdef PROCFS_HOOKS
static struct proc_dir_entry *q=NULL;
#endif

static const struct i2c_device_id pon_i2c_id_table[] = {
    { "pon_i2c", 0 },
    { },
};

MODULE_DEVICE_TABLE(i2c, pon_i2c_id_table);

static struct i2c_driver ponPhy_driver = {
    .class = ~0,
    .driver = {
        .name = "pon_i2c",
    },
    .probe  = ponPhy_probe,
    .remove = ponPhy_remove,
    .id_table = pon_i2c_id_table,
    .detect = ponPhy_detect,
    .address_list = normal_i2c
};

static int ponPhy_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    int err = 0;
    struct ponPhy_data *pclient_data;
#ifdef PROCFS_HOOKS
    struct proc_dir_entry *p;
#endif

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

    if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
        goto exit;

    if (!(pclient_data = kzalloc(sizeof(struct ponPhy_data), GFP_KERNEL)))
    {
        err = -ENOMEM;
        goto exit;
    }

    pclient_data->client.addr = client->addr;
    pclient_data->client.adapter = client->adapter;
    pclient_data->client.flags = client->flags;

    i2c_set_clientdata(client, pclient_data);

    switch(client->addr)
    {
        case PON_PHY_I2C_ADDR1:
            pclient1_data = pclient_data;
            break;
        case PON_PHY_I2C_ADDR2:
            pclient2_data = pclient_data;
            break;
        case PON_PHY_I2C_ADDR3:
            pclient3_data = pclient_data;
            break;
        default:
            BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "%s client addr out of range \n", __FUNCTION__);
            goto exit_kfree;
    }

#ifdef SYSFS_HOOKS
    /* Register sysfs hooks */
    err = sysfs_create_group(&client->dev.kobj, &ponPhy_attr_group);
    if (err)
        goto exit_kfree;
#endif

#ifdef PROCFS_HOOKS
    if (client->addr == PON_PHY_I2C_ADDR1)
    {
        if (!q && (q = proc_mkdir(PROC_DIR_NAME, NULL) ) == NULL) {
            BCM_LOG_ERROR(BCM_LOG_ID_I2C, "pon_i2c: unable to create proc entry\n");
            err = -ENOMEM;
#ifdef SYSFS_HOOKS
            sysfs_remove_group(&client->dev.kobj, &ponPhy_attr_group);
#endif
            goto exit_kfree;
        }
    }

    if (client->addr == PON_PHY_I2C_ADDR1)
        p = proc_create_data(PROC_ENTRY_NAME1, 0644, q, &pon_fops0, pclient_data);
    else if (client->addr == PON_PHY_I2C_ADDR2)
        p = proc_create_data(PROC_ENTRY_NAME2, 0644, q, &pon_fops1, pclient_data);
    else
        p = proc_create_data(PROC_ENTRY_NAME4, 0644, q, &ponPhyProc_fops, pclient_data);
    if (!p) {
        BCM_LOG_ERROR(BCM_LOG_ID_I2C, "pon_i2c: unable to create proc entry\n");
        err = -EIO;
#ifdef SYSFS_HOOKS
        sysfs_remove_group(&client->dev.kobj, &ponPhy_attr_group);
#endif
        goto exit_kfree;
    }

#ifdef GPON_I2C_TEST
    /* Create only once */
    if (client->addr == PON_PHY_I2C_ADDR1)
        p = proc_create(PROC_ENTRY_NAME3, 0644, q, &ponPhyTest_fops);
#endif
#endif

    return 0;

exit_kfree:
    kfree(pclient_data);
exit:
    return err;
   
}

static int ponPhy_detect(struct i2c_client *client, struct i2c_board_info *info)
{
    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);
    strcpy(info->type, "pon_i2c");
    info->flags = 0;
    return 0;
}

static int ponPhy_remove(struct i2c_client *client)
{
    int err = 0;

    BCM_LOG_DEBUG(BCM_LOG_ID_I2C, "Entering the function %s \n", __FUNCTION__);

#ifdef SYSFS_HOOKS
    sysfs_remove_group(&client->dev.kobj, &ponPhy_attr_group);
#endif

#ifdef PROCFS_HOOKS
        remove_proc_entry(PROC_ENTRY_NAME1, q);
        remove_proc_entry(PROC_ENTRY_NAME2, q);
#ifdef GPON_I2C_TEST
        remove_proc_entry(PROC_ENTRY_NAME3, q);
#endif
        remove_proc_entry(PROC_DIR_NAME, NULL);
#endif

    kfree(i2c_get_clientdata(client));

    return err;
}

module_i2c_driver(ponPhy_driver);


MODULE_AUTHOR("Pratapa Reddy, Vaka <pvaka@broadcom.com>");
MODULE_DESCRIPTION("PON OLT Transceiver I2C driver");
MODULE_LICENSE("GPL");

