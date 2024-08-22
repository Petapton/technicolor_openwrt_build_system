# technicolor_openwrt_build_system
The Docker-way for building packages for technicolor gateways.

This is just a put-together of sparse information found digging into https://github.com/Ansuel/GUI_ipk and its issues, all packaged into a docker container, so that you can focus on actually building packages.

## Contents
This repo contains toolchain and buildenv for some techicolor gateways. They're the ones linked in [this repo](https://github.com/Ansuel/GUI_ipk)'s readme. I just unpacked them, cleaned the environment, set some configuration parameters, and wrote a dockerfile to spare you the hassle of configuring everything from scratch every time.

I also included a docker-compose, which features an http server to host your own local package repo.

## Requirements
- docker

## Set up
### Just the container
If you just need the bare container (note you will have to manually export and install your ipk files or executables)

First of all clone the repository if you haven't done it yet, and cd into it.

    git clone https://github.com/Petapton/technicolor_openwrt_build_system
    cd technicolor_openwrt_build_system
Then build the container. It will take a while, since it has to download all the dependencies and compile some stuff, so get yourself comfortable...

    docker build -t tch_buildenv .
Now you can run the container and get a shell session.

    docker run -it tch_buildenv bash

### docker-compose
Alternatively you can also set up an http server so that you are ready to serve ipk files to your device.

Again, clone and cd. Then 

    docker compose up

Again, it will take some time. After that you will be able to get a shell into the buildenv container by running

    docker compose exec -it buildenv bash

Also add these lines to your /etc/opkg.conf

    arch all 100
    arch brcm63xx 200
    arch brcm63xx-tch 300
    arch arm_cortex-a9 400

    # Local repositories
    src/gz local_base http://your-ip-address:8080/base
    src/gz local_packages http://your-ip-address:8080/packages
    src/gz local_luci http://your-ip-address:8080/luci
    src/gz local_routing http://your-ip-address:8080/routing
    src/gz local_telephony http://your-ip-address:8080/telephony
    src/gz local_core http://your-ip-address:8080/packages

so you can install packages with `opkg install`.

## Usage
Once you have shell access you can start compiling.
Run

    scripts/feeds update && scripts/feeds install mypackage

Replace _mypackage_ with the package you want to build (e.g. python3).
Run

    make menuconfig
and select your subtarget. Then find your package and select it to be built (you can find all _installed_ packages at the end, grouped in categories). Save and exit.

Now let's get to the point:

    make package/mypackage/compile
where again *mypackage* is the package you want to build.

Lastly, you can go `make package/index` to build Package.gz files, useful if you set up a local repo.
