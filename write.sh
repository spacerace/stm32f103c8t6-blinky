# since stm32loader.py is a 'bit' outdated, i moved to st-util's st-flash.

#stm32loader.py -e -w -p /dev/ttyUSB0 -b 115200 -g 0x08000000 output/main.bin
st-flash write output/main.bin 0x8000000

