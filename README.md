# Building Yocto images for Stinger96 and IoTBox

## Required packages on Ubuntu

This section provides required packages on an Ubuntu Linux distribution:

### Essentials

Packages needed to build an image for a headless system:

```shell
$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \
    build-essential chrpath socat cpio python python3 python3-pip python3-pexpect \
    xz-utils debianutils iputils-ping python-git repo bmap-tools
```

## Download meta-stinger96 project manifest

To easily manage different git repositories layers, meta-stinger96 project is using [Android repo tool](https://source.android.com/source/using-repo),

First initialize repo specifying the project manifest and the corresponding branch:

```shell
$ repo init -u https://github.com/linuxdev-linumiz/meta-stinger96-bsp.git -m conf/samples/default.xml -b master 
```

then checkout the project source tree:

```shell
$ repo sync -j10
```

## Stinger96

Instructions for building and flashing the Stinger96 board.

### Configuring the project

meta-stinger96-bsp offers pre-configured machine templates, tested and ready to use.

```shell
$ cd stinger96/
$ TEMPLATECONF=meta-stinger96-bsp/conf/samples/ source oe-init-build-env
```

### Build the project
#### SD image
```shell
$ bitbake stinger96-image-base-sd
```

### Flashing the Image
#### SD image
After successfull compilation, the image can be flashed onto the uSD card using below command:

**NOTE:** The below instruction assumes the uSD card is available at `/dev/sdX`, you need to change it to corresponding mount point in the host machine.

```shell
$ sudo dd if=tmp/deploy/images/stinger96/stinger96-image-base-sd-stinger96.wic of=/dev/sdX iflag=fullblock conv=fsync status=progress bs=8M;sync
```
