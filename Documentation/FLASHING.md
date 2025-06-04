# ESP32 Flashing Documentation
Make sure you have the `esptool` python package installed.
`pip install esptool`

## How do I erase the flash?
`esptool --port COM5 erase_flash`

## How do I write to flash?
`esptool --port COM5 --baud 460800 write_flash 0x1000 firmware.bin`
- Replace `firmware.bin` with the firmware file.

## HELP, esptool is not found!
Try use `esptool.py` instead of `esptool`.