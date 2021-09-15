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


#ifndef _BCM_FLASHUTIL_NAND_H__
#define _BCM_FLASHUTIL_NAND_H_

#include <stdint.h>
#include <mtd/mtd-user.h>

#define IMAGE_VERSION_FILE_NAME "image_version"

/** Get info about the flash.  Currently, just returns the type of flash,
 *  but in the future, could return more useful info.
 *
 *  @flags (OUT)  Bit field containing info about the flash type.
 *
 *  @return CmsRet enum.
 */

/* Used by bcm_imgif, bcm_imgutil, image.c*/
int writeImageToNand(unsigned char *string, int size);
unsigned char *nandUpdateSeqNum(unsigned char *imagePtr, int imageSize, int blkLen, int seq, int *found);
int nand_image_type(unsigned char * buf);
int partitionBooted(int partition);
mtd_info_t *get_mtd_device_handle(const char *check, int *mtd_fd);
void put_mtd_device(mtd_info_t *mtd, int mtd_fd);
int nandEraseBlk(mtd_info_t *mtd, int blk_addr, int mtd_fd);
int nandWriteBlk(mtd_info_t *mtd, int blk_addr, int data_len, unsigned char *data_ptr,
  int mtd_fd, int write_JFFS2_clean_marker);
int flashCferam(mtd_info_t *mtd, int mtd_fd, int rsrvd_for_cferam,
  unsigned char *cferam_ptr, unsigned char *cferam_ptr2);
int handleCferom(mtd_info_t *mtd0, char *image_ptr, unsigned int wfiFlags,
  void *inMemNvramData_buf);
int flashCferom(unsigned char *image_ptr, unsigned int size);
int validateWfiTag(void *wt, int blksize, uint32_t btrmEnabled);

/* Used by bcm_flashutil.c */
int nandReadNvramData(void *nvramData);
int nandGetSequenceNumber(int imageNumber);
int nandGetImageVersion(uint8_t *imagePtr, int imageSize, char *image_name, int image_name_len);
int nandWriteBootImageState( int newState );
int nandReadBootImageState( void );
int nandUpdateSequenceNumber(int incSeqNumPart, int seqPart1, int seqPart2);
int nandIsBootDevice(void);
int nandGetBootedValue(void);
int nandGetBootPartition(void);
int nandCommit( int partition, char *string );


#endif /* _BCM_FLASHUTIL_NAND_H_ */
