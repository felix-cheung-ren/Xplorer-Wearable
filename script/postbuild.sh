#!/bin/bash

# create bin image with arm-none-eabi-objcopy -O binary ${ProjName}.elf ${ProjName}.bin

${cross_prefix}${cross_objcopy}${cross_suffix} -O binary ${ProjName}.elf ${ProjName}.bin


# check for python version installed
if command -v python >/dev/null; then
    PYTHON=python
else
    PYTHON=python3
fi

# Set device argument based on device name

DEVICE_ARG="RA6W1-RRQ61001"

echo "Device Selected: ${DEVICE_ARG}"

# run python script to generate img.bin from .bin

$PYTHON ../scripts/gen_rrq61_flash_image.py ${ProjName}.bin ${ProjName}.img.bin ${DEVICE_ARG}
