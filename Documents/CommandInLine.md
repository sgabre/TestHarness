
## Command In Line

When you are at the root directroy (/TestHarness)

Compile in Debug Configuration 

rm -rf build && mkdir build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=Debug && cmake --build ./build 

 
Compile in Debug Configuration 

rm -rf build && mkdir build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=Release && cmake --build ./build 

Compile in Unit Test Configuration 

rm -rf build && mkdir build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=UnitTesting && cmake --build ./buil

Run Unit Test
ctest -C Debug -VV --test-dir ./build

Compile in Unit Test Configuration And Run Unit Test

rm -rf build && mkdir build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=UnitTesting && cmake --build ./build && ctest -C Debug -VV --test-dir ./build



cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./Resources/gcc-arm64-apple-darwin.cmake && cmake --build build


## Build a module as static/shared Libraries

I want to build Module Software Component as a library and the deliverable artefact should be place in the Libraries 

Project Structure

```
/TestHarness
├── CMakeLists.txt
├── Firmware
│   ├── CMakeLists.txt
│   └── Module
│       ├── CMakeLists.txt
│       ├── Module.c
│       └── Module.h
├── LICENSE
└── Libraries
    ├── inc
    │   └── Module.h
    └── lib
        └── Module.lib
```

1. Specify Installation Directories in CMakeLists.txt

```
#/TestHarness/Firmware/Module/CMakeList.txt
# Optionally, specify installation rules
install(TARGETS mylibrary DESTINATION lib)
install(FILES include/library.h DESTINATION include)

```

2. Configure and Build a static library (default)

```
rm -rf build && mkdir build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./Libraries && cmake --build ./build --target Module
```

3. Configure and Build a Shared library

```
rm -rf build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./Libraries -DBUILD_SHARED=ON && cmake --build ./build --target Module
```

4. Install to the Specified Path

```
cmake --build ./build --target install 
```

## Note

CMake's CMAKE_BUILD_TYPE is typically set to Debug, Release, RelWithDebInfo, or MinSizeRel

Default → Builds a static library (.a on Linux/macOS, .lib on Windows).
With -DBUILD_SHARED=ON → Builds a shared library (.so on Linux/macOS, .dll on Windows).
Both versions install headers into Libraries/inc/.



## Build a module as static/shared Libraries for a specific platform/boards

1. MCU GCC Compiler

   1.1 Options

```
   -mcpu=cortex-m4 -c -x assembler-with-cpp --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
```

2. MCU GCC Compiler

   2.1 Options

```
-DSTM32F401xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
```

 2.1 Define Symbol (-D)

```
USE_HAL_DRIVER
STM32F401xE
```

3. MCU GCC Linker

   3.1 Options

```
   -mcpu=cortex-m4 -T"/Users/sgabre/git/Board/STM32F401RE-Board/Core/Startup/STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="${BuildArtifactFileBaseName}.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
```

3. Build & Compilation Command-In-Line
   
```
rm -rf build && cmake -B ./build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=./Resources/gcc-arm-none-eabi.cmake -DCMAKE_INSTALL_PREFIX=./Libraries && cmake --build ./build --target Module
```

## Build a Board as static Libraries for a specific platform/boards

```
rm -rf build && cmake -B ./build -S ./Firmware/Boards/STM32F401RE/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=./Resources/gcc-arm-none-eabi.cmake -DCMAKE_INSTALL_PREFIX=./Libraries && cmake --build ./build --target Module
```







## Coverage Option (gcc)

add -fprofile-arcs and -ftest-coverage flags

Compile in Unit Test Configuration, Run Unit Test 

cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./Resources/gcc-arm64-apple-darwin-coverage.cmake && cmake --build build && ctest -C Debug -VV --test-dir ./build

Search for *.gcda and *.gcno files

gcov ./Firmware/Module/Module.c


# CDash Server

docker pull kitware/cdash


/TestHarness
└── Libraries
    ├── inc
    │   └── Module.h         # Installed header
    ├── lib
    │   ├── ModuleLib.a      # Release static library (Linux/macOS)
    │   ├── ModuleLib.lib    # Release static library (Windows)
    │   ├── DModuleLib.a     # Debug static library (Linux/macOS)
    │   ├── DModuleLib.lib   # Debug static library (Windows)
    │   ├── ModuleLib.so     # Release shared library (Linux/macOS, if `BUILD_SHARED=ON`)
    │   ├── DModuleLib.so    # Debug shared library (Linux/macOS, if `BUILD_SHARED=ON`)
    │   ├── ModuleLib.dll    # Release shared library (Windows, if `BUILD_SHARED=ON`)
    │   ├── DModuleLib.dll   # Debug shared library (Windows, if `BUILD_SHARED=ON`)
    └── bin
        ├── ModuleLib.dll     # Windows runtime shared library
        └── DModuleLib.dll    # Windows runtime shared library (Debug)



# Comparaison between STM32CubeIDE and gcc-arm-none-eabi.cmake 

## CMAKE

### CMAKE_C_FLAGS 

```
-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
-Wall -Wextra -Wpedantic -fdata-sections -ffunction-sections 
(O0 -g3/-Os -g0)
```

### CMAKE_ASM_FLAGS

```
-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard 
-Wall -Wextra -Wpedantic -fdata-sections -ffunction-sections 
(O0 -g3/-Os -g0)
-x assembler-with-cpp -MMD -MP

```


### CMAKE_CXX_FLAGS

```
-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard 
-Wall -Wextra -Wpedantic -fdata-sections -ffunction-sections 
(O0 -g3/-Os -g0)
-fno-rtti -fno-exceptions -fno-threadsafe-statics
```

### CMAKE_C_LINK_FLAGS

```
-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
-T \"${CMAKE_SOURCE_DIR}/Core/Startup/STM32F401RETx_FLASH.ld\
--specs=nano.specs
-Wl,-Map=${CMAKE_PROJECT_NAME}.map -Wl,--gc-sections
-Wl,--start-group -lc -lm -Wl,--end-group
-Wl,--print-memory-usage

```

### CMAKE_CXX_LINK_FLAGS

```
-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
-T \"${CMAKE_SOURCE_DIR}/Core/Startup/STM32F401RETx_FLASH.ld\
--specs=nano.specs
-Wl,-Map=${CMAKE_PROJECT_NAME}.map -Wl,--gc-sections
-Wl,--start-group -lc -lm -Wl,--end-group
-Wl,--print-memory-usage
 -Wl,--start-group -lstdc++ -lsupc++ -Wl,--end-group
```

## STM32CubeIDE

### MCU GCC Compiler

```
   -mcpu=cortex-m4 -c -x assembler-with-cpp --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
```

### MCU GCC Compiler

```
-DSTM32F401xE -c -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
```

** Define Symbol (-D) **

```
USE_HAL_DRIVER
STM32F401xE
```

### MCU GCC Linker

```
   -mcpu=cortex-m4 -T"/Users/sgabre/git/Board/STM32F401RE-Board/Core/Startup/STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="${BuildArtifactFileBaseName}.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
```


# Remember

## Build a Board as static Libraries for a specific platform/boards

```
rm -rf build && cmake -B ./build -S ./Firmware/Boards/STM32F401RE/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=./Resources/gcc-arm-none-eabi.cmake -DCMAKE_INSTALL_PREFIX=./Libraries && cmake --build ./build --target Module
```

## Build Application for a specific platform/boards , i don't know if it working ...

```
 cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./Resources/gcc-arm-none-eabi.cmake -DLINK=./Resources/STM32F401RETx_FLASH.ld && cmake --build build && ctest -C Debug -VV --test-dir ./build
 ```


 