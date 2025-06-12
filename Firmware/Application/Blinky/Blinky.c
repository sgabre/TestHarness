#include <stdio.h>

//#include <Version.h>

//#include <Module.h>

#ifdef STM32F401xE
static_assert(defined(STM32F401xE), "STM32F401xE must be defined!");
static_assert(defined(USE_HAL_DRIVER), "USE_HAL_DRIVER must be defined!");
#endif

extern void board_Setup(void);

int main(void)
{
    #ifdef STM32F401xE
    board_Setup();
    printf("Board Setup......Completed\n");
    #endif
    
    #ifdef _FIRMWARE_INFORMATION_H_
    printf("%s - %s - V%s\n", APPLICATION_NAME, APPLICATION_CONFIG, FIRMWARE_VERSION);
    printf("Revision ID: %s\n", REVISION_ID);
    printf("Build Date & Time: %s\n", BUILD_DATE);
    printf("Compiler: %s - V%s\n", COMPILER_ID, COMPILER_VERSION);
    printf("--Boards--\n");
    printf("Hardware: %s - %s - Rev: %s\n", "NUCLEO", "STM32F403RE", HARDWARE_VERSION);
    #else
    printf("Blinky - Debug - V 0.0.0\n");
    #endif

    #ifdef STM32F401xE
    while (1)
    {
        printf("Tick #%lu\r\n", i++);
        HAL_GPIO_TogglePin(LD2_GPIO_PORT, LD2_PIN); // Toggle the LED
        HAL_Delay(500); // Delay for 500 ms
    }
    #endif

    return 0;
}
