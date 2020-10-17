DESCRIPTION = "Stinger96 base image for SD"
require stinger96-image-base.bb

IMAGE_FSTYPES = "wic"

do_image_wic[depends] += "stinger96-image-base:do_image_complete"
WKS_FILE = "sd.wks"
export IMAGE_BASENAME = "stinger96-image-base-sd"
