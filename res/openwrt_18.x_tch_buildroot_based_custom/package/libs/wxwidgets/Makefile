include $(TOPDIR)/rules.mk

PKG_NAME:=wxbase
PKG_VERSION:=2.8.1
PKG_RELEASE:=1

PKG_SOURCE:=wxWidgets-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/wxwindows
PKG_HASH:=skip

PKG_BUILD_DIR:=$(BUILD_DIR)/wxWidgets-$(PKG_VERSION)
PKG_INSTALL_DIR:=$(PKG_BUILD_DIR)/ipkg-install

include $(INCLUDE_DIR)/package.mk

define Package/wxbase
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libexpat +zlib +libstdcpp
  TITLE:=wxBase library (runtime) - non-GUI support classes of wxWindows toolkit
  URL:=http://sourceforge.net/projects/wxwindows/
endef

define Package/wxbase/description
	wxBase is a collection of C++ classes providing basic data structures \\\
	(strings, lists, arrays), powerful wxDateTime class for date manipulations, \\\
	portable wrappers around many OS-specific functions allowing to build the \\\
	same program under all supported folders, wxThread class for writing \\\
	multithreaded programs using either Win32 or POSIX threads and much more. \\\
	wxBase currently supports the following platforms: Generic Unix (Linux, \\\
	FreeBSD, Solaris, HP-UX, ...), win32, and BeOS. \\\
	\\\
	This package is only useful for non-GUI apps.  It offers a subset of the \\\
	classes in libwx_gtk2.8 for use in console apps and daemons.  You do not need \\\
	this package to build or use wxWindows GUI apps.
endef

define Build/Configure
	$(call Build/Configure/Default, \
		--disable-precomp-headers \
		--disable-gui \
		--without-subdirs \
		--with-regex=builtin \
		--with-zlib=sys \
		--with-expat=sys \
		--enable-largefile \
		--without-sdl \
		--disable-sdltest \
		--enable-unicode \
		, \
		ac_cv_path_SDL_CONFIG=no \
	)
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

define Build/InstallDev
	mkdir -p $(STAGING_DIR)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libwx_baseu* $(STAGING_DIR)/usr/lib
	mkdir -p $(STAGING_DIR)/usr/include/wx-2.8/wx
	$(CP) $(PKG_INSTALL_DIR)/usr/include/wx-2.8/wx/* $(STAGING_DIR)/usr/include/wx-2.8/wx
endef

define Build/UninstallDev
	rm -rf \
		$(STAGING_DIR)/usr/lib/libwx_baseu* \
		$(STAGING_DIR)/usr/include/wx-2.8 \
		$(STAGING_DIR)/usr/bin/wx-config
endef

define Package/wxbase/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libwx_baseu* $(1)/usr/lib
endef

$(eval $(call BuildPackage,wxbase))