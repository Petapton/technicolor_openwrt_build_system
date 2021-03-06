
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

BOARD:=brcm63xx-tch
BOARDNAME:=Broadcom BCM63xx based Technicolor platform

SUBTARGETS:=VANTF VANTW VBNTK VBNTO VBNTS

LINUX_VERSION-3.4 = .11
LINUX_VERSION-4.1 = .38

KERNEL_PATCHVER:=4.1
#LINUX_RELEASE:=rt19

FEATURES:=squashfs jffs2 usb atm pci pcmcia
DEFAULT_PACKAGES += kmod-switch gpioctl

BCM_KF:=y
INSTALL_MOD_DIR:=extra
BRCM_BOARD:=bcm963xx
HOSTTOOLS_DIR:=$(TOPDIR)/scripts
SCRIPT_DIR:=$(TOPDIR)/scripts
SHELL:=/bin/bash

export BCM_KF INSTALL_MOD_DIR BRCM_BOARD HOSTTOOLS_DIR SCRIPT_DIR

define Target/Description
	Build firmware images for Technicolor Broadcom based xDSL/routers
endef

include $(INCLUDE_DIR)/target.mk

KERNEL_DIR:=$(BUILD_DIR)/linux-$(BOARD)_$(SUBTARGET)/linux-$(LINUX_VERSION)
export KERNEL_DIR

ifeq ($(BRCM_CHIP),63138)
  CFLAGS:=-Os -pipe -march=armv7-a -mtune=cortex-a9 -fno-caller-saves -mfpu=neon
endif

ifeq ($(BRCM_CHIP),63148)
  CFLAGS:=-Os -pipe -march=armv7-a -mtune=cortex-a15 -fno-caller-saves
endif

$(eval $(call BuildTarget))
