# STM32 Project skeleton
Project skeleton for the STM32 line of microcontrollers.
This is a work in progress, support for many hardware registers and many microcontrollers is still missing.

## Requirements
 - arm-none-eabi toolchain (should be in your linux distibutions reposiory)
 - [stlink](https://github.com/texane/stlink)
 - (optional) stm32loader (should be in your linux distibutions reposiory)

## Getting started
 - Edit the file `config.mk` to reflect your device configuration
 - Set up the interrupt handlers in `src/interrupt.c`
 - Type `make` to compile
 - Type `make install` to program the microcontroller

## Debugging
 - Program the microcontroller with `make install`
 - Run `st-util` to open debug link to device
 - Run `arm-none-eabi-gdb project.elf` and type the command `target remote localhost:4242` in gdb
