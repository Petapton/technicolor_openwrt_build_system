/***********************************************************************
 *
 *  Copyright (c) 2006-2007  Broadcom Corporation
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
:>
 *
 ************************************************************************/

#ifndef __CMS_PARAMS_MODSW_H__
#define __CMS_PARAMS_MODSW_H__

/*!\file cms_params_modsw.h
 * \brief Header file containing customizable parameters related to
 *               Modular Software.
 */



/** Path to CMS data storage dir.
 */
#define CMS_DATA_STORAGE_DIR   "/local"


/** Path to Modular Software dir.
 */
#define CMS_MODSW_DIR   CMS_DATA_STORAGE_DIR"/modsw"


/** Path to tmp modsw dir.  Files are initially downloaded to tmp before
 *  they are put in their correct location.
 */
#define CMS_MODSW_TMP_DIR   CMS_DATA_STORAGE_DIR"/modsw/tmp"


/** Common path to both OSGI DU, BEEP DU and Linux DU.
 *
 */
#define CMS_MODSW_DU_DIR    CMS_DATA_STORAGE_DIR"/modsw/tr157du"


/** Path to TR157 Deployment Unit Directory for OSGI bundles.
 *  OSGI bundle deployment units are put in this directory based on their
 *  name, e.g. /local/modsw/tr157du/osgibundle/bundle_name...
 * So each DU has its own directory.
 */
#define CMS_MODSW_OSGIEE_DU_DIR    CMS_DATA_STORAGE_DIR"/modsw/tr157du/osgibundles"


/** Path to TR157 Deployment Unit Dir for Linux packages.
 * Linux deployment units are put in this directory based on their name,
 * e.g. /local/modsw/tr157du/linux/du_name...
 * So each DU has its own directory.
 */
#define CMS_MODSW_LINUXEE_DU_DIR    CMS_DATA_STORAGE_DIR"/modsw/tr157du/linuxpkgs"

/** Path to TR157 Deployment Unit Dir for OpenWRT opkg packages.
 * Linux deployment units are put in this directory based on their name,
 * e.g. /local/modsw/tr157du/openwrt/du_name...
 * So each DU has its own directory.
 */
#define CMS_MODSW_OPENWRTEE_DU_DIR    CMS_DATA_STORAGE_DIR"/modsw/tr157du/openwrt-opkgs"



/** Path to TR157 Primary Firmware Patch dir.  Patches to the primary firmware
 *  are put in this directory based on their name,
 *  e.g. /local/modsw/tr157pfp/pfpname/...
 *  So each Primary Firmware Patch has its own directory.
 */
#define CMS_MODSW_LINUXPFP_DIR   CMS_DATA_STORAGE_DIR"/modsw/tr157pfp"

#define CMS_MODSW_TMP_BEEP_DIR   CMS_DATA_STORAGE_DIR"/modsw/tmp/beep"

/** Path to TR157 Deployment Unit Directory for BEEP DU.
 *  BEEP bundle deployment units are put in this directory based on their
 *  name, e.g. /local/modsw/tr157du/beep/bundle_name...
 * So each DU has its own directory.
 */
#define CMS_MODSW_BEEP_DU_DIR    CMS_DATA_STORAGE_DIR"/modsw/tr157du/beep"

/** First 32 bytes of a Primary Firmware Patch consists of this string.
 *  This string must be 32 bytes, as specified by CMS_MODSW_LINUX_HEADER1_LEN
 *  below.
 */
#define CMS_MODSW_LINUXPFP_HEADER "BCMTR157:Linux:PrimFirmwrePatch;"


/** First 32 bytes of a Linux Deployment Unit (DU) consists of this string.
 *  This string must be 32 bytes, as specified by CMS_MODSW_LINUX_HEADER1_LEN
 *  below.
 */
#define CMS_MODSW_LINUXEE_DU_HEADER "BCMTR157:LinuxEE:DeploymentUnit;"


/** Length of first Header section.
 */
#define CMS_MODSW_LINUX_HEADER1_LEN    32


/** Length of second Header section, which is the name of the patch or DU.
 *  If the name is shorter than the length, the remaining bytes must
 *  contain 0.
 */
#define CMS_MODSW_LINUX_HEADER2_LEN    128


/** Text header in the outer tarball */
#define CMS_MODSW_OUTER_HEADER_NAME    "outer-header.txt"


/** Below are the keywords allowed in version 1 of the outer-header */
#define BCMPKG_VERSION                1

#define BCMPKG_KW_VERSION             "version"
#define BCMPKG_TK_VERSION             1001

#define BCMPKG_KW_INNERFILENAME       "innerFilename"
#define BCMPKG_TK_INNERFILENAME       1002
/* matches max length defined for TR181 Execution Unit name */
#define BCMPKG_INNERFILENAME_MAX_LEN  32

#define BCMPKG_KW_CHECKSUMALGO        "checksumAlgo"
#define BCMPKG_TK_CHECKSUMALGO        1003

#define BCMPKG_KW_CHECKSUM            "checksum"
#define BCMPKG_TK_CHECKSUM            1004

#define BCMPKG_SHA1_CHECKSUM_LEN      40


/** Text header in the inner tarball */
#define CMS_MODSW_INNER_HEADER_NAME    "inner-header.txt"

/** Below are the keywords allowed in version 1 of the inner-header */
#define BCMPKG_KW_PKGVERSION          "pkgVersion"
#define BCMPKG_TK_PKGVERSION          2001
#define TR157_VERSION_STR_LEN         32

#define BCMPKG_KW_PKGDESCRIPTION      "pkgDescription"
#define BCMPKG_TK_PKGDESCRIPTION      2002
#define TR157_DESCRIPTION_STR_LEN     256

#define BCMPKG_KW_INNERVERSION        "innerVersion"
#define BCMPKG_TK_INNERVERSION        2003

#define BCMPKG_KW_INNERDESCRIPTION    "innerDescription"
#define BCMPKG_TK_INNERDESCRIPTION    2004

#define TR157_NAME_STR_LEN            64

/** Debug log for storing various ModSw operations.  Use of this file is
 *  deprecated.  Was OSGID_LOG_FILE.
 */
#define CMS_MODSW_DEBUG_LOG           CMS_DATA_STORAGE_DIR"/modsw/tmp/DuLog"
#define CMS_MODSW_DEBUG_EU_LOG        CMS_DATA_STORAGE_DIR"/modsw/tmp/EuLog"

/*
 * Defines specific to the Linux Execution Environment.
 */

#define LINUXEE_NAME     "Linux"
#define LINUXEE_TYPE     "Linux"
#define LINUXEE_VENDOR   "Linux"
#define LINUXEE_VERSION  "3.4"

/*
 * Defines specific to the Openwrt Execution Environment.
 */

#define OPENWRTEE_NAME     "Openwrt"
#define OPENWRTEE_TYPE     "Chaos Calmer"
#define OPENWRTEE_VENDOR   "OpenWRT Project"
#define OPENWRTEE_VERSION  "15.05"

/*
 * Defines specific to the BEEP Execution Environment.
 */
#define BEEP_NAME    "BEEP"
#define BEEP_TYPE    "Broadcom Execution Environment Platform"
#define BEEP_VENDOR  "Broadcom Ltd."
#define BEEP_VERSION "1.0"

#endif  /* __CMS_PARAMS_MODSW_H__ */
