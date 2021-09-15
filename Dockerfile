FROM ubuntu:14.04
RUN apt-get update -y && apt-get install -y build-essential ccache ecj fastjar file g++ gawk gettext git java-propose-classpath libelf-dev libncurses5-dev libncursesw5-dev libssl-dev python python2.7-dev python3 unzip wget python3-distutils-extra python3-setuptools python3-dev rsync subversion swig time xsltproc zlib1g-dev
WORKDIR /workdir
COPY res .
WORKDIR /workdir/openwrt_18.x_tch_buildroot_based_custom
RUN make defconfig
RUN wget -P tools/missing-macros/src/bin https://raw.githubusercontent.com/openwrt/openwrt/openwrt-18.06/tools/missing-macros/src/bin/help2man https://raw.githubusercontent.com/openwrt/openwrt/openwrt-18.06/tools/missing-macros/src/bin/makeinfo # These two files are somehow missing, so let's download them. https://github.com/Ansuel/GUI_ipk/issues/7#issuecomment-594193964
ENV FORCE_UNSAFE_CONFIGURE=1
RUN make tools/compile -j $(($(nproc) + 1))
