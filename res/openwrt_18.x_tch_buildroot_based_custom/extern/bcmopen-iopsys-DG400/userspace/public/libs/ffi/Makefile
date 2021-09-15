#***********************************************************************
#
#  Copyright (c) 2015  Broadcom Corporation
#  All Rights Reserved
#
#***********************************************************************/

LIB = libffi-3.2.1

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
FFIINCLUDEDIR=$(PREFIX)/include
FFILIBDIR=$(INSTALL_DIR)/lib$(BCM_INSTALL_SUFFIX_DIR)

all dynamic install: conditional_build

clean:
	-[ ! -e $(LIB) ] || $(MAKE) -C $(LIB) uninstall
	rm -rf $(LIB)
	rm -f $(FFILIBDIR)/libffi*

# The next line is a hint to to our release scripts
# GLOBAL_RELEASE_SCRIPT_CALL_DISTCLEAN
distclean: clean

include $(BUILD_DIR)/make.common

ifeq ($(strip $(DESKTOP_LINUX)),y)
# Force 32 bit compiles even if the build machine is a 64 bit system
BCM_BLT32_FLAGS := "CFLAGS=-m32" "CXXFLAGS=-m32" "LDFLAGS=-m32"
BCM_BLT32_LIB=$(shell $(CC) -m32 -print-multi-os-directory)
BCM_LIBS_BIN=$(PREFIX)/lib/$(BCM_BLT32_LIB)
else
BCM_BLT32_FLAGS := 
BCM_LIBS_BIN=$(PREFIX)/lib
endif

ifneq ($(strip $(BUILD_FFI)),)
conditional_build: build
else
conditional_build: 
	@echo "skipping $(LIB) (not configured)"
endif

check_untar_configure: sanity_check
	@if [ ! -e $(LIB)/Makefile ]; then \
	echo "Untarring original $(LIB) source and configure"; \
	(tar zxf $(LIB).tar.gz 2> /dev/null || true); \
	(cd $(LIB); patch -p1 < ../mips.softfloat.patch; ./configure --host=$(TOOLCHAIN_PREFIX) \
        --prefix=$(PREFIX) $(BCM_BLT32_FLAGS)); \
	fi

build: check_untar_configure
	$(MAKE) -C $(LIB) 
	$(MAKE) -C $(LIB) install
	mkdir -p  $(FFILIBDIR)
	cp -d $(BCM_LIBS_BIN)/libffi.so* $(FFILIBDIR)

.PHONY: build check_untar_configure sanity_check conditional_build

