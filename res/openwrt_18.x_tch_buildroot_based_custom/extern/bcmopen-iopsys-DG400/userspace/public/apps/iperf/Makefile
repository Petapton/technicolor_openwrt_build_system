
all:	conditional_build

CURR_DIR := $(shell pwd)
BUILD_DIR:=$(subst /userspace, /userspace,$(CURR_DIR))
BUILD_DIR:=$(word 1, $(BUILD_DIR))
include $(BUILD_DIR)/make.common

APP = iperf-2.0.9
CXX := $(CC)
CFLAGS := -lstlport
CXXFLAGS := -lstlport
LDFLAGS := -lstlport -lm -L$(USERSPACE_PUBLIC_LIBS_DIR)/stlport/lib

export CXX CFLAGS CXXFLAGS LDFLAGS CC USERSPACE_PUBLIC_LIBS_DIR


ifneq ($(strip $(BUILD_IPERF)),)
conditional_build: build
else
conditional_build: 
	@echo "skipping iperf (not configured)"
endif

build:
	(tar xkfz $(APP).tar.gz 2> /dev/null || true)
	if [ ! -e ./$(APP)/Makefile ];then \
	cd ./$(APP); ./configure --host=$(TOOLCHAIN_PREFIX) --target=$(TOOLCHAIN_PREFIX) ac_cv_func_malloc_0_nonnull=yes; \
	fi
	echo "configure is done"
	$(MAKE) -j 1 -C ./$(APP) srcdir=./ builddir=./
	install -m 755 ./$(APP)/src/iperf $(INSTALL_DIR)/bin/iperf

clean:
	if [ -f ./$(APP)/Makefile ];then $(MAKE) -C ./$(APP) distclean srcdir=./ builddir=./;fi;

shell:
	bash

