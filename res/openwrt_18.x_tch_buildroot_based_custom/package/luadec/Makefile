#
# Copyright (C) 2006-2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=luadec
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/viruscamp/luadec
PKG_SOURCE_DATE:=2017-01-06
PKG_SOURCE_VERSION:=895d92313fabaee260121c758c8320d1b21dd741
PKG_MIRROR_HASH:=SKIP

PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=COPYING

# PKG_FIXUP:=autoreconf
PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/luadec
  SECTION:=base
  CATEGORY:=Base
  DEPENDS:=+liblua
  TITLE:=luadec is a web frontend making aria2 easier to use.
  URL:=https://github.com/mayswind/luadec
endef

define Package/luadec/description
	luadec is a web frontend making aria2 easier to use. luadec is written in pure html & javascript, thus it does not need any compilers or runtime environment.
endef

MAKE_FLAGS += LUAVER=5.1

TARGET_CFLAGS += $(FPIC) $(TARGET_CPPFLAGS)

TARGET_LDFLAGS += -llua

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/luadec \
		$(TARGET_CONFIGURE_OPTS) \
		CFLAGS="$(TARGET_CFLAGS) -std=gnu99" \
		LDFLAGS="$(TARGET_LDFLAGS)"
endef

define Package/luadec/install
	$(INSTALL_DIR) \
		$(1)/www/luadec

	$(CP) \
		$(PKG_BUILD_DIR)/{langs,css,js,fonts} \
		$(PKG_BUILD_DIR)/index.html \
		$(PKG_BUILD_DIR)/index.manifest \
		$(PKG_BUILD_DIR)/LICENSE \
		$(PKG_BUILD_DIR)/favicon.ico \
		$(1)/www/luadec
endef

$(eval $(call BuildPackage,luadec))