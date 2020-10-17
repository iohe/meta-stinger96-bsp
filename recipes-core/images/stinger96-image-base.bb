SUMMARY = "Base image for Stinger96 Distribution"
LICENSE = "MIT"
inherit core-image

IMAGE_LINGUAS = "en-us"

IMAGE_INSTALL = "\
	packagegroup-core-boot \
	kernel-modules \
	u-boot \
"
export IMAGE_BASENAME = "stinger96-image-base"
