SUBTARGET:=VBNTS
BOARDNAME:=VBNT-S

BRCM_CHIP:=63138
ARCH:=arm
CPU_TYPE:=cortex-a9
CPU_SUBTYPE:=neon

define Target/Description
	Broadcom 63x38 (VBNT-S)
endef

BCM_SDK=$(TOPDIR)/extern/bcmopen-iopsys-DG400
BRCMDRIVERS_DIR:=$(BCM_SDK)/bcmdrivers
BCM_USERSPACE_DIR:=$(BCM_SDK)/userspace
SHARED_DIR:=$(BCM_SDK)/shared

PROFILE:=963138GWV
RDPA_PLATFORM=dsl
VOXXXLOAD=1

INC_BROADCOM_APPS_SHARED:=$(SHARED_DIR)
INC_BRCMDRIVER_PUB_PATH:=$(BRCMDRIVERS_DIR)/opensource/include
INC_BRCMDRIVER_PRIV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/include
INC_ADSLDRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/adsl/impl1
INC_ATMAPI_DRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/atmapi/impl1
INC_MOCACFGDRV_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/moca/impl2
INC_BRCMSHARED_PUB_PATH:=$(SHARED_DIR)/opensource/include
INC_BRCMSHARED_PRIV_PATH:=$(SHARED_DIR)/broadcom/include
INC_BRCMBOARDPARMS_PATH:=$(SHARED_DIR)/opensource/boardparms
INC_FLASH_PATH:=$(SHARED_DIR)/opensource/flash
INC_SPI_PATH:=$(SHARED_DIR)/opensource/spi
INC_SPUDRV_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/spudd/impl3
INC_PWRMNGTDRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/pwrmngt/impl1
INC_ENETDRV_PATH:=$(BRCMDRIVERS_DIR)/opensource/net/enet/impl5
INC_EPONDRV_PATH:=$(BRCMDRIVERS_DIR)/broadcom/char/epon/impl1
INC_RDPA_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl/impl1/include
INC_RDPA_EXT_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl_ext/impl1/include
INC_RDPA_MW_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/rdpa_mw/impl1
INC_RDPA_DRV_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/rdpa_drv/impl1
INC_RDPA_PATH_PLATFORM:=$(INC_RDPA_PATH)/$(RDPA_PLATFORM)
INC_RDPA_EXT_PATH_PLATFORM:=$(INC_RDPA_EXT_PATH)/$(RDPA_PLATFORM)
INC_BDMF_PATH:=$(BRCMDRIVERS_DIR)/opensource/char/bdmf/impl1
INC_UTILS_PATH:=$(SHARED_DIR)/opensource/utils
RDP_PATH:=$(BCM_SDK)/rdp

ifneq ($(strip $(RDPA_PLATFORM)),)
EXTRA_CFLAGS_RDPA += -DRDPA_PLATFORM
endif

RDPSDK_DIR:=$(BCM_SDK)/rdp
ifeq ($(strip $(BRCM_CHIP)),63138)
    RDP_PROJECT=DSL_63138
endif

ifeq ($(strip $(BRCM_CHIP)),63148)
    RDP_PROJECT=DSL_63148
endif

ifeq ($(strip $(BRCM_CHIP)),6838)
ifeq ($(strip $(BUILD_BRCM_FTTDP)),)
    RDP_PROJECT=PON_6838
else
    RDP_PROJECT=PON_6838_G9991
endif
endif

ifeq ($(strip $(BRCM_CHIP)),6848)
    RDP_PROJECT=PON_6838
endif

ifneq ($(findstring _$(strip $(BRCM_CHIP))_,_6858_6836_),)
export BRCM_FULL_CHIP_NAME=$(strip $(BRCM_CHIP)$(subst $\",,$(BRCM_CHIP_REV)))
endif

ifeq ($(strip $(BRCM_CHIP)),6858)
    BCM_EPON_STACK_IMPL=2
ifeq ($(strip $(BUILD_BRCM_FTTDP)),)
ifeq ($(BRCM_CHIP_REV),"B0")
    RDP_PROJECT=PON_6858B0
else
    RDP_PROJECT=PON_6858
endif
else
    RDP_PROJECT=PON_6858_G9991
endif
else
    BCM_EPON_STACK_IMPL=1
endif

ifeq ($(strip $(BRCM_CHIP)),4908)
    RDP_PROJECT=WL4908
endif

ifeq ($(strip $(BRCM_CHIP)),6836)
    RDP_PROJECT=PON_6836
endif

ifneq ($(strip $(RDP_PROJECT)),)
PROJECT_DIR = $(RDPSDK_DIR)/projects/$(RDP_PROJECT)
include $(PROJECT_DIR)/make.proj_flags
endif
export RDPSDK_DIR BCM_EPON_STACK_IMPL

INC_RDP_FLAGS = -I$(PROJECT_DIR)/target/bdmf/system \
                -I$(PROJECT_DIR)/target/bdmf/system/linux \
                -I$(PROJECT_DIR)/target/bdmf/system/linux/ce \
                -I$(PROJECT_DIR)/target/bdmf/framework \
                -I$(PROJECT_DIR)/target/bdmf/shell \
                -I$(PROJECT_DIR)/target/rdp_subsystem \
                -I$(PROJECT_DIR)/target/rdp_subsystem/RU \
                -I$(PROJECT_DIR)/target/rdpa \
                -I$(PROJECT_DIR)/target/rdpa_gpl \
                -I$(PROJECT_DIR)/target/rdd \
                -I$(INC_BRCMSHARED_PUB_PATH)/rdp \
                -I$(INC_BRCMSHARED_PUB_PATH)/pmc \
                -I$(INC_BRCMSHARED_PUB_PATH)/drv/mdio \
                -I$(INC_BRCMSHARED_PUB_PATH)/drv/phys \
                -I$(INC_BRCMSHARED_PRIV_PATH)/$(BRCM_BOARD) \
                -I$(INC_BRCMSHARED_PUB_PATH)/$(BRCM_BOARD) \
                -I$(INC_BRCMDRIVER_PUB_PATH)/$(BRCM_BOARD) \
                -I$(INC_BRCMDRIVER_PRIV_PATH)/$(BRCM_BOARD) \
                -I$(SHARED_DIR)/opensource/drv/lport \
                -I$(KERNEL_DIR)/net/core \
                -I$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl/impl1/include \
                -I$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl/impl1/include/autogen \
                -I$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl_ext/impl1/include \
                -I$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl_ext/impl1/include/gpon_stack \
                -I$(BRCMDRIVERS_DIR)/opensource/char/rdpa_gpl_ext/impl1/include/autogen \
                -I$(BRCMDRIVERS_DIR)/broadcom/char/pon_drv/impl1 \
                -I$(BRCMDRIVERS_DIR)/opensource/char/fpm/impl1 \
                 $(PROJ_DEFS)

EXTRA_CFLAGS_BDMF=-I$(INC_BDMF_PATH)/framework \
                  -I$(INC_BDMF_PATH)/platform/$(RDPA_PLATFORM) \
                  -I$(INC_BDMF_PATH)/system \
                  -I$(INC_BDMF_PATH)/system/linux \
                  -I$(INC_BDMF_PATH)/system/linux/ce \
                  -I$(INC_BDMF_PATH)/shell

EXTRA_CFLAGS_RDPA=$(EXTRA_CFLAGS_BDMF) \
                  -I$(INC_RDPA_PATH) \
                  -I$(INC_RDPA_EXT_PATH) \
                  -I$(INC_RDPA_PATH)/$(RDPA_PLATFORM) \
                  -I$(INC_RDPA_EXT_PATH)/$(RDPA_PLATFORM) \
                  -I$(INC_RDPA_MW_PATH) \
                  -I$(INC_RDPA_DRV_PATH)
#                  -I$(RDPSDK_DIR)/drivers/rdpa_gpl/include \
#                  $(INC_RDP_FLAGS)

ADD_LINUX_INCLUDE:=-I$(BRCMDRIVERS_DIR)/broadcom/net/wl/impl22/main/src/include

INC_ENET_DMA_FLAGS = -I$(INC_BRCMSHARED_PUB_PATH)/drv/phys \
                     -I$(INC_BRCMSHARED_PUB_PATH)/bcm963xx \
                     -I$(BRCMDRIVERS_DIR)/opensource/include/bcm963xx \
                     -I$(BRCMDRIVERS_DIR)/opensource/net/enet/shared \
                     -I$(BRCMDRIVERS_DIR)/broadcom/include/bcm963xx

export BCM_SDK BRCMDRIVERS_DIR BCM_USERSPACE_DIR SHARED_DIR PROJECT_DIR \
       BRCM_CHIP PROFILE RDPA_PLATFORM VOXXXLOAD ADD_LINUX_INCLUDE \
       INC_BROADCOM_APPS_SHARED INC_BRCMDRIVER_PUB_PATH INC_BRCMDRIVER_PRIV_PATH \
       INC_ADSLDRV_PATH INC_ATMAPI_DRV_PATH INC_MOCACFGDRV_PATH INC_BRCMSHARED_PUB_PATH \
       INC_BRCMSHARED_PRIV_PATH INC_BRCMBOARDPARMS_PATH INC_FLASH_PATH INC_UTILS_PATH \
       INC_SPI_PATH INC_SPUDRV_PATH INC_PWRMNGTDRV_PATH INC_ENETDRV_PATH INC_EPONDRV_PATH \
       INC_RDPA_PATH INC_RDPA_EXT_PATH \
       INC_RDPA_MW_PATH INC_RDPA_DRV_PATH \
       INC_RDPA_PATH_PLATFORM INC_RDPA_EXT_PATH_PLATFORM \
       INC_BDMF_PATH RDP_PATH INC_ENET_DMA_FLAGS \
       EXTRA_CFLAGS_RDPA EXTRA_CFLAGS_BDMF INC_RDP_FLAGS

