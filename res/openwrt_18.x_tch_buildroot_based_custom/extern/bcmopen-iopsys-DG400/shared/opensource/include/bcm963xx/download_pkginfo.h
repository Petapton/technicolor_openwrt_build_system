/*
    Copyright 2000-2016 Broadcom Limited

<:label-BRCM:2016:DUAL/GPL:standard

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

#ifndef _DOWNLOAD_PKGINFO_H_
#define _DOWNLOAD_PKGINFO_H_

#define KEY_LEN                            128                /* good for up to sha512 */
#define PACKAGE_DIR_PREFIX                 "/pkg_"            /* pkg AKA  DU in tr157 */
#define APP_DIR_PREFIX                     "/app_"            /* app AKA  EU in tr157 */
#define LIB_DIR_PREFIX                     "/lib"
#define PACKAGE_BEEP_FILE_FREFIX           "pkg_beep_"
#define PACKAGE_BEEP_FILE_SUFFIX           ".tar.gz"
#define PACKAGE_BEEP_MANI_SUFFIX           ".manifest"

#endif // _DOWNLOAD_PKGINFO_H_
