#include <stdio.h>
#include <stdint.h>

//#include <Version.h>

//#include <Module.h>


#include "stm32f4xx_hal.h"
//Cortex-M0/0+ - ARMv6-M
#ifdef CORTEX_M0
typedef struct 
{
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t psr;
} ExceptionStackFrame;

void dumpExceptionStack (ExceptionStackFrame* frame, uint32_t lr) 
{
    printf ("Stack frame:\r\n");
    printf (" R0 = %08X\r\n", frame->r0);
    printf (" R1 = %08X\r\n", frame->r1);
    printf (" R2 = %08X\r\n", frame->r2);
    printf (" R3 = %08X\r\n", frame->r3);
    printf (" R12 = %08X\r\n", frame->r12);
    printf (" LR = %08X\r\n", frame->lr);
    printf (" PC = %08X\r\n", frame->pc);
    printf (" PSR = %08X\r\n", frame->psr);
    printf ("Misc\r\n");
    printf (" LR/EXC_RETURN= %08X\r\n", lr);
}

void HardFault_Handler (void) 
{
    asm volatile(
    " movs r0,#4 \r\n"
    " mov r1,lr \r\n"
    " tst r0,r1 \r\n"
    " beq 1f \r\n"
    " mrs r0,psp \r\n"
    " b 2f \r\n"
    "1: \r\n"
    " mrs r0,msp \r\n"
    "2:"
    " mov r1,lr \r\n"
    " ldr r2,=HardFault_Handler_C \r\n"
    " bx r2"
    : /* Outputs */
    : /* Inputs */
    : /* Clobbers */
    );
}

void HardFault_Handler_C (ExceptionStackFrame* frame __attribute__((unused)), uint32_t lr __attribute__((unused))) 
{
    printf ("[HardFault]\r\n");
    dumpExceptionStack (frame, lr);
    
    #if defined(DEBUG)
    __DEBUG_BKPT();
    #endif
    while (1);
}

//Cortex-M3/4/7 - ARMv7-M/ARMv7E-M
#else
typedef struct 
{
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t psr;
    #if defined(__ARM_ARCH_7EM__)
    uint32_t s[16];
    #endif
 } ExceptionStackFrame;


 void dumpExceptionStack (ExceptionStackFrame* frame, uint32_t cfsr, uint32_t mmfar, uint32_t bfar, uint32_t lr) 
 {
    printf ("Stack frame:\r\n");
    printf (" R0 = %08X\r\n", frame->r0);
    printf (" R1 = %08X\r\n", frame->r1);
    printf (" R2 = %08X\r\n", frame->r2);
    printf (" R3 = %08X\r\n", frame->r3);
    printf (" R12 = %08X\r\n", frame->r12);
    printf (" LR = %08X\r\n", frame->lr);
    printf (" PC = %08X\r\n", frame->pc);
    printf (" PSR = %08X\r\n", frame->psr);
    printf ("FSR/FAR:\r\n");
    printf (" CFSR = %08X\r\n", cfsr);
    printf (" HFSR = %08X\r\n", SCB->HFSR);
    printf (" DFSR = %08X\r\n", SCB->DFSR);
    printf (" AFSR = %08X\r\n", SCB->AFSR);

    if (cfsr & (1UL << 7)) 
    {
        printf (" MMFAR = %08X\r\n", mmfar);
    }
    if (cfsr & (1UL << 15)) 
    {
        printf (" BFAR = %08X\r\n", bfar);
    }

    printf ("Misc\r\n");
    printf (" LR/EXC_RETURN= %08X\r\n", lr);
}


void HardFault_Handler (void) 
{
    asm volatile(
    " tst lr,#4 \r\n"
    " ite eq \r\n"
    " mrseq r0,msp \r\n"
    " mrsne r0,psp \r\n"
    " mov r1,lr \r\n"
    " ldr r2,=HardFault_CallBack \r\n"
    " bx r2"
    : /* Outputs */
    : /* Inputs */
    : /* Clobbers */
    );
}

void HardFault_CallBack (ExceptionStackFrame* frame __attribute__((unused)), uint32_t lr __attribute__((unused))) 
{
    uint32_t mmfar = SCB->MMFAR;    // MemManage Fault Address
    uint32_t bfar = SCB->BFAR;      // Bus Fault Address
    uint32_t cfsr = SCB->CFSR;      // Configurable Fault Status Registers
    
    printf ("[HardFault]\r\n");
    dumpExceptionStack (frame, cfsr, mmfar, bfar, lr);
    
    #if defined(DEBUG)
    __DEBUG_BKPT();
    #endif
    while (1);
}
#endif


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
