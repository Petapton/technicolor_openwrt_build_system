cmd_/home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/netfilter_ipv4/.install := bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/netfilter_ipv4 ./include/uapi/linux/netfilter_ipv4 ip_tables.h ipt_CLUSTERIP.h ipt_ECN.h ipt_LOG.h ipt_REJECT.h ipt_TTL.h ipt_ah.h ipt_ecn.h ipt_ttl.h; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/netfilter_ipv4 ./include/linux/netfilter_ipv4 ; bash scripts/headers_install.sh /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/netfilter_ipv4 ./include/generated/uapi/linux/netfilter_ipv4 ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/netfilter_ipv4/$$F; done; touch /home/ansuel/openwrt/build_dir/toolchain-arm_cortex-a9+neon_gcc-4.8-linaro_glibc_eabi/linux-dev//include/linux/netfilter_ipv4/.install
