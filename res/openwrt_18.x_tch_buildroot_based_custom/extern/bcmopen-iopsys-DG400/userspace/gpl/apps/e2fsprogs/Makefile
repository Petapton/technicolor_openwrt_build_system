
dynamic install: conditional_build

#
# Set our CommEngine directory (by splitting the pwd into two words
# at /userspace and taking the first word only).
# Then include the common defines under CommEngine.
# You do not need to modify this part.
#
CURR_DIR := $(shell pwd)
BUILD_DIR:=$(subst /userspace, /userspace,$(CURR_DIR))
BUILD_DIR:=$(word 1, $(BUILD_DIR))

include $(BUILD_DIR)/make.common

APP = e2fsprogs


.PHONY: check_untar check_configure conditional_build check_versions e2fsprogs

ifneq ($(strip $(BUILD_EMMC_IMG)),)
conditional_build: all

else
conditional_build: sanity_check
	@echo "skipping $(APP) (not configured)"

endif

check_configure: $(PROFILE_ARCH)/Makefile 

$(PROFILE_ARCH)/Makefile: check_untar
	mkdir -p $(PROFILE_ARCH)
	cd $(PROFILE_ARCH) && ../e2fsprogs/configure --host=$(TOOLCHAIN_PREFIX) --prefix=$(BCM_FSBUILD_DIR)/gpl/ 

check_untar: e2fsprogs/README

e2fsprogs/README: e2fsprogs-1.43.4.tar.gz
	mkdir -p e2fsprogs
	(cd e2fsprogs && tar --strip-components=1 -xkzf ../e2fsprogs-1.43.4.tar.gz  || true)

all: check_configure
	make -C $(PROFILE_ARCH)
	make -C $(PROFILE_ARCH) install
	mkdir -p $(INSTALL_DIR)/bin
	-cp $(BCM_FSBUILD_DIR)/gpl/sbin/e2fsck $(INSTALL_DIR)/bin/
	-cp $(BCM_FSBUILD_DIR)/gpl/sbin/mke2fs $(INSTALL_DIR)/bin/

clean:
	if [ -e $(PROFILE_ARCH) ]; then \
		make -C $(PROFILE_ARCH) uninstall; \
		make -C $(PROFILE_ARCH) clean; \
		rm -rf $(PROFILE_ARCH); \
	fi
	rm -f $(INSTALL_DIR)/bin/mke2fs
	rm -f $(INSTALL_DIR)/bin/e2fsck
	rm -rf $(APP)

bcm_dorel_distclean:
	rm -rf $(PROFILE_ARCH) e2fsprogs

shell:
	bash -i

