cmd_/home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/spi/.install := bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/spi ./include/uapi/linux/spi spidev.h; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/spi ./include/linux/spi ; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/spi ./include/generated/uapi/linux/spi ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/spi/$$F; done; touch /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/spi/.install
