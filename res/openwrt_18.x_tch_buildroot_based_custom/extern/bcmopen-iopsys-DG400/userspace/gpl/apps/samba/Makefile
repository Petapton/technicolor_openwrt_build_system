

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

include $(BUILD_DIR)/make.common

APP = samba


.PHONY: check_untar_patch_configure conditional_build check_versions

ifneq ($(strip $(BUILD_SAMBA)),)
conditional_build: $(APP)

else
conditional_build: sanity_check
	@echo "skipping $(APP) (not configured)"

endif

samba: sanity_check
	(tar xkfz samba.tar.gz 2> /dev/null || true)
	$(MAKE) -C ./samba -j 1


clean:
	-make -C samba clean

