#***********************************************************************
#
#  Copyright (c) 2015  Broadcom Corporation
#  All Rights Reserved
#
#***********************************************************************/

LIB = dbus-1.10.8

all dynamic install: conditional_build

#
# Set our CommEngine directory (by splitting the pwd into two words
# at /userspace and taking the first word only).
# Then include the common defines under CommEngine.
# You do not need to modify this part.
#
CURR_DIR := $(shell pwd)
BUILD_DIR:=$(subst /userspace, /userspace,$(CURR_DIR))
BUILD_DIR:=$(word 1, $(BUILD_DIR))

PREFIX = $(BCM_FSBUILD_DIR)/public
BINDIR=$(INSTALL_DIR)/usr/bin
SBINDIR=$(INSTALL_DIR)/usr/sbin
DBUSLIBDIR=$(INSTALL_DIR)/lib$(BCM_INSTALL_SUFFIX_DIR)
LOCALSTATEDIR=$(INSTALL_DIR)/var

clean:
	-[ ! -e $(LIB) ] || $(MAKE) -C $(LIB) clean;
	rm -rf $(LIB)
	rm -rf $(BINDIR)/dbus*
	rm -rf $(SBINDIR)/dbus*
	rm -rf $(INSTALL_DIR)/etc/dbus-1
	rm -rf $(DBUSLIBDIR)/libdbus*
	rm -rf $(DBUSLIBDIR)/dbus-1.0/*
	rm -rf $(INSTALL_DIR)/share/dbus-1
	rm -rf $(LOCALSTATEDIR)/lib/dbus
	rm -f $(INSTALL_DIR)/etc/init.d/dbus.sh
	rm -f $(INSTALL_DIR)/etc/rc3.d/S61dbus


# The next line is a hint to to our release scripts
# GLOBAL_RELEASE_SCRIPT_CALL_DISTCLEAN
distclean: clean

include $(BUILD_DIR)/make.common

ifeq ($(strip $(DESKTOP_LINUX)),y)
# Force 32 bit compiles even if the build machine is a 64 bit system
BCM_BLT32_FLAGS := -m32
endif

ifneq ($(strip $(BUILD_DBUS)),)
conditional_build: build
else
conditional_build: 
	@echo "skipping $(LIB) (not configured)"
endif

check_untar_configure: sanity_check
	@if [ ! -e $(LIB)/Makefile ]; then \
	echo "Untarring original $(LIB) source and configure"; \
	(tar xzf $(LIB).tar.gz 2> /dev/null || true); \
	echo "Applying patches to $(LIB)" ; \
	patch -p1 -b -N -s -d$(LIB) < $(LIB).patch ; \
	( cd $(LIB); export LDFLAGS='-L$(INSTALL_DIR)/lib/public -lexpat $(BCM_BLT32_FLAGS)';  \
	export CPPFLAGS=-I$(BCM_FSBUILD_DIR)/public/include/expat $(BCM_BLT32_FLAGS); \
	./configure --host=$(TOOLCHAIN_PREFIX) \
	--enable-shared=yes --enable-static=no --enable-abstract-sockets=no --disable-ansi --disable-console-owner-file \
	--disable-selinux \
	--enable-doxygen-docs=no --enable-compiler-coverage=no --enable-tests=no --enable-verbose-mode \
	--enable-xml-docs=no --without-x \
	--with-sysroot=/ --prefix=$(PREFIX) \
	--libdir=$(PREFIX)/lib \
	--includedir=$(PREFIX)/usr/include \
	--libexecdir=$(PREFIX)/lib \
	--bindir=$(PREFIX)/usr/bin \
	--localstatedir=/var \
	--datarootdir=$(BCM_FSBUILD_DIR)/share \
	--with-dbus-daemondir=$(INSTALL_DIR)/usr/sbin \
	--with-dbus-user=admin \
	--with-system-socket=/var/run/dbus/system_bus_socket \
	--with-system-pid-file=/var/run/dbus/pid \
	"CFLAGS=$(BCM_BLT32_FLAGS) -g"\ -O2\ -Wno-strict-aliasing\ -Wno-error=unused-parameter ); \
    fi


build: check_untar_configure
	@echo "Building $(LIB)"
	$(MAKE) -C $(LIB) 
	$(MAKE) -C $(LIB) install
	mkdir -p $(INSTALL_DIR)/etc/init.d
	mkdir -p $(INSTALL_DIR)/etc/rc3.d
	mkdir -p $(DBUSLIBDIR)
	cp -d $(PREFIX)/lib/libd*.so* $(DBUSLIBDIR)
	mkdir -p $(BINDIR)	
	cp -d $(PREFIX)/usr/bin/dbus-monitor $(BINDIR)
	cp -d $(PREFIX)/usr/bin/dbus-send $(BINDIR)
	cp -d $(PREFIX)/usr/bin/dbus-uuidgen $(BINDIR)
	
	echo "install brcm dbus system.conf"
	mkdir -p $(INSTALL_DIR)/share/dbus-1
	install -m 0644 system.conf $(INSTALL_DIR)/share/dbus-1/system.conf
	mkdir -p $(INSTALL_DIR)/etc/dbus-1
	install -m 0755 dbus.sh $(INSTALL_DIR)/etc/init.d
	(cd $(INSTALL_DIR)/etc/rc3.d; rm -f S61dbus; ln -s ../init.d/dbus.sh S61dbus)


.PHONY: build check_untar_configure sanity_check conditional_build

