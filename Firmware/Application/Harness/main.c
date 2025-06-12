#include <stdio.h>

//#include <Version.h>

//#include <Module.h>

#ifdef STM32F401xE
static_assert(defined(STM32F401xE), "STM32F401xE must be defined!");
static_assert(defined(USE_HAL_DRIVER), "USE_HAL_DRIVER must be defined!");
#endif
extern void board_Setup(void);
//#ifdef STM32F401xE
int main(void)
//#else
//int main(int argc, char *argv[])
//#endif
{
    //#ifdef STM32F401xE
    //board_Setup();
/*
    //Board()->Init();

    uint32_t HAL_GetHalVersion(void);
    uint32_t HAL_GetREVID(void);
    uint32_t HAL_GetDEVID(void);

    // Get HAL version
    uint32_t hal_version = HAL_GetHalVersion();

    // Get the revision ID of the STM32 chip
    uint32_t revision_id = HAL_GetREVID();

    // Get the device ID of the STM32 chip
    uint32_t device_id = HAL_GetDEVID();

    // Retrieve each word of the Unique Identifier (UID)
    uint32_t uid_word0 = HAL_GetUIDw0(); // First 32 bits (word 0)
    uint32_t uid_word1 = HAL_GetUIDw1(); // Second 32 bits (word 1)
    uint32_t uid_word2 = HAL_GetUIDw2(); // Third 32 bits (word 2)

    // Extract version information
    uint8_t major_version = (hal_version >> 24) & 0xFF;
    uint8_t minor_version = (hal_version >> 16) & 0xFF;
    uint8_t sub_version = (hal_version >> 8) & 0xFF;

    printf("--Microcontroler--\n");
    // Print version information
    printf("HAL Version: %d.%d.%d\n", major_version, minor_version, sub_version);

    // Print the device ID (this will print the raw 32-bit device ID)
    printf("STM32 Device ID: 0x%08X\n", device_id);

    // Print the revision ID (this will print the raw 32-bit revision ID)
    printf("STM32 Revision ID: 0x%08X\n", revision_id);

    // Print the full Unique Identifier (96-bit UID)
    printf("STM32 UID: 0x%08X%08X%08X\n", uid_word2, uid_word1, uid_word0);

    #endif
    */
    #ifdef _FIRMWARE_INFORMATION_H_
    printf("%s - %s - V%s\n", APPLICATION_NAME, APPLICATION_CONFIG, FIRMWARE_VERSION);
    printf("Revision ID: %s\n", REVISION_ID);
    printf("Build Date & Time: %s\n", BUILD_DATE);
    printf("Compiler: %s - V%s\n", COMPILER_ID, COMPILER_VERSION);
    //printf("--Boards--\n");
    //printf("Board Version: %s\n", HARDWARE_VERSION);
    #else
    printf("Hello Words\n");
    #endif

    #ifdef STM32F401xE
    while (1)
    {
  
    }
    #endif

    return 0;
}
