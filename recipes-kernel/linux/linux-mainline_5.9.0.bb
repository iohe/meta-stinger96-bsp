FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
require linux.inc

KBRANCH = "master"
LINUX_KERNEL_TYPE = "mainline"
LINUX_VERSION_EXTENSION = "-${LINUX_KERNEL_TYPE}"
SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git;branch=${KBRANCH} \
	   file://defconfig \
	"
SRCREV = "bbf5c979011a099af5dc76498918ed7df445635b"
PV = "5.9"

# We need to pass it as param since kernel might support more then one
# machine, with different entry points
KERNEL_EXTRA_ARGS += "LOADADDR=0xC2000040"
