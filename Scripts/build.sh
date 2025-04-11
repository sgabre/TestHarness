#!/bin/bash
echo "--Clean-up--"
if [ -d ../build ]; then
	rm -r ../build
fi

if [ -d ../Install ]; then
	rm -r ../Install
fi

if [ -d ../Pack ]; then
rm -r ../Pack
fi

echo "--Configuration--"
#cmake -B ../build -S .. -DTEST_LEVEL=UNIT
#cmake -B ../build -S .. -DCMAKE_BUILD_TYPE=Debug -DTEST_LEVEL=UNIT

cmake -B ../build -S .. -DCMAKE_BUILD_TYPE=Debug -DTEST_LEVEL=NONE -DCMAKE_TOOLCHAIN_FILE=../.cmake/toolchains/gcc-arm-none-eabi.cmake -DLINK=./Firmware/Application/STM32F401RETx_FLASH.ld

echo "--Building--"
cmake --build ../build --config Debug 

#echo "--Testing--"
#ctest --show-only
#ctest -C Debug -VV --test-dir ../build

echo "--Deployement--"
cmake --install ../build --prefix "/Users/sgabre/git/TestHarness/Libraries/"

#echo "--Packing--"
#cpack -G ZIP -C Debug --build-config Debug --config ../build/CPackConfig.cmake

#echo "--Publishing--"

#echo "--Run Application--"
#../build/Tutorial
#../build/Tutorial 25.0

# Open a screen in new terminal and also log the output 
#screen /dev/tty.usbmodem103 115200 | tee -a output.log

#arm-none-eabi-gdb ../build/TestHarness.elf \
#-ex "target extended-remote localhost:61234" \
#-ex "monitor reset halt" \
#-ex "load" \
#-ex "monitor reset init" \
#-ex "monitor reset run" \
#-ex "detach" \
#-ex "quit"

echo "--Clean-up--"





