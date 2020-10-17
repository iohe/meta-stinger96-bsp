DFAULTTUNE ?= "cortexa7thf-neon-vfpv4"
SOC_FAMILY ?= "stm32mp1"

ARM_INSTRUCTION_SET = "thumb"

require conf/machine/include/tune-cortexa7.inc
require conf/machine/include/soc-family.inc

MACHINE_FEATURES ?= "apm ext2 keyboard screen serial usbgadget usbhost"

SERIAL_CONSOLE = "115200 ttySTM1"

# U-Boot bootloader
UBOOT_MAKE_TARGET := "all"
UBOOT_BINARY := "u-boot.img"
SPL_BINARY := "u-boot-spl.stm32"
UBOOT_ENV = "boot"
UBOOT_ENV_SUFFIX = "scr"

PREFERRED_PROVIDER_virtual/bootloader = "u-boot-2018"
PREFERRED_PROVIDER_u-boot = "u-boot-2018"
PREFERRED_PROVIDER_u-boot-native = "u-boot-2018"
PREFERRED_PROVIDER_u-boot-fw-utils = "u-boot-2018-fw-utils"
PREFERRED_PROVIDER_u-boot-fw-utils-native = "u-boot-2018-fw-utils-native"
PREFERRED_VERSION_u-boot = "2018.11%"
PREFERRED_VERSION_u-boot-native = "2018.11%"
PREFERRED_VERSION_u-boot-fw-utils = "2018.11%"
PREFERRED_VERSION_u-boot-fw-utils-native = "2018.11%"

# Linux kernel
KERNEL_IMAGETYPE     =  "uImage"
KERNEL_ALT_IMAGETYPE =  " Image "
KERNEL_ALT_IMAGETYPE =+ " vmlinux "
KERNEL_ALT_IMAGETYPE =+ " zImage "

PREFERRED_PROVIDER_virtual/kernel = "linux-mainline"
PREFERRED_VERSION_linux-yocto = "5.9%"

# Ship kernel modules
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += " kernel-modules kernel-devicetree u-boot-default-env "

# List of images to be built
IMAGE_FSTYPES ?= "tar.xz wic.xz"
INITRAMFS_FSTYPES ?= "cpio.xz"

EXTRA_IMAGEDEPENDS += "virtual/bootloader"
WKS_FILE = "sdimage-stm32mp1.wks"
IMAGE_BOOT_FILES ?= "${KERNEL_IMAGETYPE}"
IMAGE_INSTALL_append = " kernel-devicetree u-boot-2018 "
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot virtual/bootloader:do_deploy"
