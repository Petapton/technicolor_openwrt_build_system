cmd_/home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/hdlc/.install := bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/hdlc ./include/uapi/linux/hdlc ioctl.h; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/hdlc ./include/linux/hdlc ; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/hdlc ./include/generated/uapi/linux/hdlc ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/hdlc/$$F; done; touch /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/hdlc/.install
