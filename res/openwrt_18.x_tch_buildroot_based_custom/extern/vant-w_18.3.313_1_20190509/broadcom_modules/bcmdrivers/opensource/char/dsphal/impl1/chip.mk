#
# Chip custom files & defines, etc. as setup by make
#

PCM_SUPPORT := $(strip $(CONFIG_BCM963138) $(CONFIG_BCM963148) $(CONFIG_BCM963268) $(CONFIG_BCM963381) $(CONFIG_BCM96362) $(CONFIG_BCM96368) $(CONFIG_BCM96838) $(CONFIG_BCM96848) $(CONFIG_BCM94908) $(CONFIG_BCM96858) $(CONFIG_BCM96836))
APM_SUPPORT := $(strip $(CONFIG_BCM963138) $(CONFIG_BCM963148) $(CONFIG_BCM96838))
APM_DMA_SUPPORT := $(strip $(CONFIG_BCM96838))


# PCM
dsphal-chip-$(PCM_SUPPORT)      += pcm/dsphal_pcm.o
subdir-ccflags-$(PCM_SUPPORT)   += -DPCM_SUPPORT
dsphal-chip-$(CONFIG_BCM963268) += pcm/impl1.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM96362)  += pcm/impl1.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM96368)  += pcm/impl1.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM963138) += pcm/impl2.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM963148) += pcm/impl2.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM963381) += pcm/impl2.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM96838)  += pcm/impl2.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM96848)  += pcm/impl2.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM94908)  += pcm/impl2.o pcm/timeslot1.o
dsphal-chip-$(CONFIG_BCM96858)  += pcm/impl3.o pcm/timeslot2.o
dsphal-chip-$(CONFIG_BCM96836)  += pcm/impl3.o pcm/timeslot2.o

# APM
dsphal-chip-$(APM_SUPPORT)        += apm/dsphal_apm.o
subdir-ccflags-$(APM_SUPPORT)     += -DAPM_SUPPORT
subdir-ccflags-$(APM_DMA_SUPPORT) += -DAPM_DMA_SUPPORT
dsphal-chip-$(CONFIG_BCM963138)   += apm/impl1.o
dsphal-chip-$(CONFIG_BCM963148)   += apm/impl1.o
dsphal-chip-$(CONFIG_BCM96838)    += apm/impl1.o

# DECT
dsphal-chip-$(CONFIG_BCM_DECT_SUPPORT) += dect/dsphal_dect.o
dsphal-chip-$(CONFIG_BCM963268)   += dect/impl1.o
dsphal-chip-$(CONFIG_BCM96362)    += dect/impl1.o
dsphal-chip-$(CONFIG_BCM963138)   += dect/impl2.o
dsphal-chip-$(CONFIG_BCM963148)   += dect/impl2.o

# Extra
dsphal-chip-$(CONFIG_BCM96838) += chip/6838.o
dsphal-chip-$(CONFIG_BCM96848) += chip/6848.o
dsphal-chip-$(CONFIG_BCM94908) += chip/4908.o
dsphal-chip-$(CONFIG_BCM96858) += chip/6858.o
dsphal-chip-$(CONFIG_BCM96836) += chip/6836.o

# Add all the chip-specific objects
dsphal-objs += $(dsphal-chip-y)
