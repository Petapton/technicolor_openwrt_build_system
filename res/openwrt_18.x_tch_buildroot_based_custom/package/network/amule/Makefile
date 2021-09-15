#
# Copyright (C) 2007-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=amule
PKG_VERSION:=2.3.2
PKG_RELEASE:=1

PKG_SOURCE_URL:=https://github.com/amule-project/amule.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=52bdccb16628030a08b8ce5b00cff2eb8d9f3505

PKG_BUILD_DEPENDS:=libgd
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/amule
  SUBMENU:=P2P
  SECTION:=net
  CATEGORY:=Network
  TITLE:=A multi-platform eMule-like ed2k client
  URL:=http://www.amule.org/
  DEPENDS:=+libpng +libpthread +libncurses +libreadline +wxbase
endef

CONFIGURE_ARGS+= \
	--enable-shared \
	--disable-static \
	--disable-rpath \
	--with-gnu-ld \
	--disable-ccache \
	--disable-debug \
	--disable-optimize \
	--disable-profile \
	--disable-monolithic \
	--enable-amule-daemon \
	--enable-amulecmd \
	--enable-webserver \
	--disable-amule-gui \
	--disable-cas \
	--disable-wxcas \
	--disable-alc \
	--disable-alcc \
	--disable-systray \
	--disable-utf8-systray \
	--enable-gsocket \
	--disable-gtktest \
	\
	--with-zlib="$(STAGING_DIR)/usr" \
	--with-gdlib-prefix="$(STAGING_DIR)/usr" \
	--with-libpng-prefix="$(STAGING_DIR)/usr" \
	--with-wx-prefix="$(STAGING_DIR)/usr" \
	--with-crypto-prefix="$(STAGING_DIR)/usr" \
	--with-libiconv-prefix="$(ICONV_PREFIX)" \
	--with-libintl-prefix="$(INTL_PREFIX)" \

TARGET_LDFLAGS += \
	-liconv

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		HOSTCC="$(HOSTCC)" \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		amule install
endef

define Package/amule/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/amule{cmd,d,web} $(1)/usr/bin/
	$(INSTALL_DIR) $(1)/usr/share
	$(CP) $(PKG_INSTALL_DIR)/usr/share/amule $(1)/usr/share/
endef

$(eval $(call BuildPackage,amule))