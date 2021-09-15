/***********************************************************************
 *
 *  Copyright (c) 2007  Broadcom Corporation
 *  All Rights Reserved
 *
 * <:label-BRCM:2011:DUAL/GPL:standard
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
 ************************************************************************/


#ifndef _BCM_FLASHUTIL_H__
#define _BCM_FLASHUTIL_H_

#include "bcm_flashutil_nand.h"

#define FLASH_INFO_FLAG_NOR    0x0001
#define FLASH_INFO_FLAG_NAND   0x0002
#define FLASH_INFO_FLAG_EMMC   0x0003

#define PSI_FILE_NAME           "/data/psi"
#define PSI_BACKUP_FILE_NAME    "/data/psibackup"
#define SCRATCH_PAD_FILE_NAME   "/data/scratchpad"


#define IDENT_TAG               "@(#) $imageversion: "

#define MAX_MTD_NAME_SIZE         64

/** Get info about the flash.  Currently, just returns the type of flash,
 *  but in the future, could return more useful info.
 *
 *  @flags (OUT)  Bit field containing info about the flash type.
 *
 *  @return CmsRet enum.
 */

int getFlashInfo(unsigned int *flags);
int getSequenceNumber(int imageNumber);
int getNextSequenceNumber(int seqNumImg1, int seqNumImg2);
int setBootImageState(int newState);
int getBootImageState(void);
int getBootedValue(void);
int readNvramData(void *pNvramData);
unsigned int otp_is_btrm_boot(void);
unsigned int otp_is_boot_secure(void);
unsigned int otp_is_boot_mfg_secure(void);
unsigned int get_chip_id(void);
unsigned int get_flash_type(void);
int getImageVersion(uint8_t *imagePtr, int imageSize, char *image_name,
  int image_name_len);
int getBootPartition( void );
int commit( int partition, char *string );
#endif /* _BCM_FLASHUTIL_H_ */
