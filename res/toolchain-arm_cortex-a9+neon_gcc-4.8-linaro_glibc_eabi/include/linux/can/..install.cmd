cmd_/home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/can/.install := bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/can ./include/uapi/linux/can bcm.h error.h gw.h netlink.h raw.h; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/can ./include/linux/can ; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/can ./include/generated/uapi/linux/can ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/can/$$F; done; touch /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/can/.install