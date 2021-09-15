#
# Makefile for the DSPHAL driver
#

obj-$(CONFIG_BCM_DSPHAL) += dsphal.o
dsphal-objs := dsphal_core.o dsphal_helpers.o dsphal_ioctl.o dsphal_debug.o
dsphal-objs += dma/iudma.o
dsphal-objs += g711/g711.o

# Per-chip files
include $(src)/chip.mk

subdir-ccflags-y += -I$(src)/dma -I$(src)/pcm -I$(src)/apm -I$(src)/dect -I$(src)/chip -I $(src)/g711 -I$(src)
subdir-ccflags-y += -I$(INC_BRCMDRIVER_PUB_PATH)/$(BRCM_BOARD) -I$(INC_BRCMSHARED_PUB_PATH)/$(BRCM_BOARD) -I$(INC_BRCMSHARED_PUB_PATH)
subdir-ccflags-y += -I$(INC_BRCMDRIVER_PRIV_PATH)/$(BRCM_BOARD) -I$(INC_BRCMSHARED_PRIV_PATH)/$(BRCM_BOARD)

# Voice defs
include $(BUILD_DIR)/make.voice
subdir-ccflags-y += $(VOICE_CFLAGS)

-include $(TOPDIR)/Rules.make
