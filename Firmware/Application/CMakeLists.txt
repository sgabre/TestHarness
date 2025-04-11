#/TestHarness/Firmware/Application/CMakeLists.txt




# TODO: Add Condition 
# TODO: When the CMAKE_TOOLCHAIN_FILE is ../.cmake/toolchains/gcc-arm-none-eabi.cmake 
#       Then Add Path to the external library files
#       Specify the include directory for the external library
#       Enable Message
#       Add Link with the library

message(STATUS "Application Type: ${APPLICATION_TYPE}")
if(APPLICATION_TYPE STREQUAL "EMBEDDED_APPLICATION")
    # Path to the external library files
    set(EXTERNAL_LIB_PATH "${CMAKE_SOURCE_DIR}/Packs/Boards/STM32F403RE")

    # Specify the include directory for the external library
    include_directories("${EXTERNAL_LIB_PATH}/inc")

    message(STATUS "PACK_LIB_PATH: ${EXTERNAL_LIB_PATH}")
    message(STATUS "PACK_LIB_PATH: ${EXTERNAL_LIB_PATH}/inc")
    message(STATUS "PACK_LIB_PATH: ${EXTERNAL_LIB_PATH}/Lib")

    # Enable CMake support for ASM and C languages
    enable_language(C ASM)



endif()


# Set source files for the application
set(SOURCES
	main.c
   # startup_stm32f401xe.s
)

if(APPLICATION_TYPE STREQUAL "EMBEDDED_APPLICATION")
    # Set source files for the application
    list(APPEND SOURCES startup_stm32f401xe.s)
endif()

# Create the executable for the application
ADD_EXECUTABLE(TestHarness ${SOURCES})

# Link with the Module library if required
set(ITEMS Module)

if(APPLICATION_TYPE STREQUAL "EMBEDDED_APPLICATION")
    list(APPEND ITEMS "${EXTERNAL_LIB_PATH}/Lib/STM32F403RELib.a")
endif()

target_link_libraries(TestHarness PRIVATE ${ITEMS})

# Include directories
TARGET_INCLUDE_DIRECTORIES(TestHarness PRIVATE ${CMAKE_CURRENT_LIST_DIR})

install(TARGETS TestHarness
    RUNTIME DESTINATION bin
)



## Check and configure for embedded
#if(APPLICATION_TYPE STREQUAL "EMBEDDED_APPLICATION")

# Vérifie que le fichier toolchain a bien été utilisé
#if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#    message(WARNING "Embedded application selected but no toolchain file was specified!")
#endif()

# Activer STM32 Packs
#set(USE_STM32_PACKS ON)

#set(PACK_LIB_PATH "${CMAKE_SOURCE_DIR}/Packs/Boards/STM32F401RE")
#set(STARTUP_ASM ${PACK_LIB_PATH}/Startup/startup_stm32f401xe.s)
#set(LINKER_SCRIPT ${PACK_LIB_PATH}/Linker/STM32F401RE.ld)
#set(PACK_LIB ${PACK_LIB_PATH}/Lib/STM32F401RELib.lib)
#
# Ajout des sources
#target_sources(TestHarness PRIVATE ${STARTUP_ASM})
#set_source_files_properties(${STARTUP_ASM} PROPERTIES LANGUAGE ASM)
#
## Ajout des options de lien
#target_link_options(TestHarness PRIVATE -T${LINKER_SCRIPT})
#
## Include dir
#target_include_directories(TestHarness PRIVATE ${STM32_PACKS_DIR}/Include)

# Lien vers la bibliothèque
#if(EXISTS ${PACK_LIB})
#    target_link_libraries(TestHarness PRIVATE ${PACK_LIB})
#else()
#    message(WARNING "Pack library not found: ${PACK_LIB}")
#endif()
#
#endif()