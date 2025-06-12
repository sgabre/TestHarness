#include <stdint.h>
#include <stdio.h>

//#include <Version.h>

//#include <Module.h>

#ifdef STM32F401xE
static_assert(defined(STM32F401xE), "STM32F401xE must be defined!");
static_assert(defined(USE_HAL_DRIVER), "USE_HAL_DRIVER must be defined!");
#endif
extern void board_Setup(void);

/*== Defines ================================================================*/
/*


__attribute__((at(BOOTLOADER_START_ADDRESS + TARGET_PROJECT_VERSION_ADDRESS_OFFSET)))
#define HASH_SIZE  5
const uin8_t Hash[HASH_SIZE] = "1.0.0";




__attribute__((at(BOOTLOADER_START_ADDRESS + TARGET_PROJECT_VERSION_ADDRESS_OFFSET)))
typedef struct Header_t
{
    char Signature[SIGNATURE_SIZE];
}Header_ts;
*/

// OSI model
// 7.  Application layer    APL
// 6.  Presentation layer   PPL_
// 5.  Session layer        SPL
// 4.  Transport layer      TPL
// 3.  Network layer        NTL
// 2.  Data link layer      DTL
// 1.  Physical layer       PHL

typdedef struct SetupCommand_t
{
     uint32_t Address;
     uint16_t N;        //Number of fragments (N):
     uint8_t  S;        //Fragments Size (S):
     uint8_t  P;        //Padding (P):
}SetupCommand_ts;

typdedef struct RebootCommand_t
{
    uint32_t RebootTime;
}RebootCommand_ts;

typdedef struct ImageCommand_t
{
    uint32_t SoftwareVersion;
}ImageCommand_ts;

typdedef struct ImageAnswer_t
{
    uint8_t Status
    uint32_t SoftwareVersion;
}ImageAnswer_ts;

typdedef struct DeviceVersionAnswer_t
{
    uint32_t SoftwareVersion;
    uint32_t HardwareVersion;
}DeviceVersionAnswer_ts;


// Get the SoftwareVersion & HardwareVersion of the device
void Upgrader_DeviceVersionCommand(uint8_t* aData, uint8_t size)
{
    DeviceVersionAnswer_ts Answer;
    uint8_t TxFrame[] = (DeviceVersionAnswer_ts*)&Answer;
    //Answer.SoftwareVersion = Device_GetSoftwareVersion();
    //Answer.HardwareVersion = Device_GetHardwareVersion();
    // TPL_TxAck(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxError(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxData(TxFrame, sizeof(DeviceVersionAnswer_ts) );

}

// Reboot the device
void Upgrader_DeviceRebootCommand(uint8_t* aData, uint8_t size)
{
    RebootCommand_ts* Command =(RebootCommand_ts*)aData;
    //Device_Reboot(Command->RebootTime);
    // TPL_TxData(TxFrame, sizeof(DeviceVersionAnswer_ts) );
}

// Get the Status & SoftwareVersion of the Image currently present.
void Upgrader_DeviceUpgradeImageCommand(uint8_t* aData, uint8_t size)
{
    // uint8_t Status;
    // 0: No firmware upgrade image currently present.
    // 1: A firmware upgrade image is present but is eithercorrupted or its cryptographic signature is wrong.
    // 2: An authenticated firmware upgrade image is present but does not correspond to the end-device’s hardware platform.
    // 3: A valid firmware upgrade image is present and can be installed.

    //uint32_t SoftwareVersion 
    ImageAnswer_ts Answer;
    uint8_t TxFrame[] = (uint8_t*)&Answer;

    //Answer.Status = Device_GetSoftwareVersion();
    //Answer.SoftwareVersion = Device_GetHardwareVersion();
    // TPL_TxAck(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxError(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxData(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    
}

//Delete the Image currently present. 
void Upgrader_DeviceDeleteImageCommand(uint8_t* aData, uint8_t size)
{
    ImageAnswer_ts Answer;
    uint8_t TxFrame[] = (uint8_t*)&Answer;
    ImageCommand_t* Command =(ImageCommand_t*)aData;

    // uint32_t SoftwareVersion 
    // uint32_t Status
    // ErrorInvalidVersion
    // ErrorNoValidImage
    // TPL_TxAck(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxError(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxData(TxFrame, sizeof(DeviceVersionAnswer_ts) );
}
//

void Upgrader_SetupCommand(uint8_t* aData, uint8_t size)
{
    SetupCommand_t* Command =(SetupCommand_t*)aData;
    // uint32_t Address
    // uint16_t Number of fragments (N):
    // uint8_t Fragments Size (S):
    // uint8_t Padding (P):
    // The data block size is N × S – P.
    // TPL_TxAck(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxError(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxData(TxFrame, sizeof(DeviceVersionAnswer_ts) );
}

// Transfer a Block 
void Upgrader_ChuckCommand(uint8_t* aData, uint8_t size)
{
    // uint32_t  Index;
    // uint8_t   Data[]; 
    // TPL_TxAck(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxError(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxData(TxFrame, sizeof(DeviceVersionAnswer_ts) );
}

void Upgrader_StatusCommand(uint8_t* aData, uint8_t size)
{
    // TPL_TxAck(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxError(TxFrame, sizeof(DeviceVersionAnswer_ts) );
    // TPL_TxData(TxFrame, sizeof(DeviceVersionAnswer_ts) );
}

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
    //printf("--Boards--\n");
    //printf("Board Version: %s\n", HARDWARE_VERSION);
    #else
    printf("Hello Words\n");
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


