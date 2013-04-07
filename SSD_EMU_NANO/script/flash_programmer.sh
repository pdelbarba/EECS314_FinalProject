#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting Binary File: C:\Users\Robert\fir_kernel.mbcconf to: "..\flash/fir_kernel_cfi_flash_0.flash"
#
nios2eds/bin/bin2flash --input="C:/Users/Robert/fir_kernel.mbcconf" --output="../flash/fir_kernel_cfi_flash_0.flash" --location=0x0 --verbose 

#
# Programming File: "..\flash/fir_kernel_cfi_flash_0.flash" To Device: cfi_flash_0
#
nios2eds/bin/nios2-flash-programmer "../flash/fir_kernel_cfi_flash_0.flash" --base=0x0 --sidp=0x40410E8 --id=0x0 --timestamp=1353270030 --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

