cmd_/home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/rdma/.install := bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/rdma ./include/uapi/rdma ib_user_cm.h ib_user_mad.h ib_user_sa.h ib_user_verbs.h rdma_netlink.h rdma_user_cm.h; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/rdma ./include/rdma ; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/rdma ./include/generated/uapi/rdma ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/rdma/$$F; done; touch /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/rdma/.install
