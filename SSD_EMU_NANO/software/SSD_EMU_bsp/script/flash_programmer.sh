#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting Binary File: C:\Users\Robert\file.mbcconfig to: "..\flash/file_cfi_flash_0.flash"
#
nios2eds/bin/bin2flash --input="C:/Users/Robert/file.mbcconfig" --output="../flash/file_cfi_flash_0.flash" --location=0x0 

#
# Programming File: "..\flash/file_cfi_flash_0.flash" To Device: cfi_flash_0
#
nios2eds/bin/nios2-flash-programmer "../flash/file_cfi_flash_0.flash" --base=0x0 --sidp=0x4021068 --id=0x0 --timestamp=1351042533 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program 

