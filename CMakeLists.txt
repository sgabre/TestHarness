#/TestHarness/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(TestHareness VERSION 0.0.0)

if(NOT CMAKE_BUILD_TYPE)
    # Set a default build type if not defined
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type (Release, Debug, UnitTesting)" FORCE)
    message(STATUS "CMAKE_BUILD_TYPE not defined, defaulting to Debug.")
endif()

# Define valid build types
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Release Debug UnitTesting)

# Display the current build type
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
#message(STATUS "CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
#message(STATUS "MAJOR_VERSION: ${PROJECT_VERSION_MAJOR}")
#message(STATUS "MINOR_VERSION: ${PROJECT_VERSION_MINOR}")
#message(STATUS "PATCH_VERSION: ${PROJECT_VERSION_PATCH}")

# Display the toolchain details in the output
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "ASM Compiler: ${CMAKE_ASM_COMPILER}")
message(STATUS "Linker: ${CMAKE_LINKER}")
message(STATUS "C Flags: ${CMAKE_C_FLAGS}")
message(STATUS "CXX Flags: ${CMAKE_CXX_FLAGS}")






# Add Firmware subdirectory for all build types
add_subdirectory(Firmware)

# Conditionally add Unity and UnitTesting when the build type is UnitTesting
if(CMAKE_BUILD_TYPE STREQUAL UnitTesting)
    message(STATUS "Unit Testing build type detected!")
    enable_testing()
    include(./Resources/Unity.cmake)
    add_subdirectory(UnitTesting)
endif()

# Ensure the Libraries directory exists before installation
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/Libraries)
install(TARGETS Module)
