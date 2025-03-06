## Firmware Integration Testing 

### Scope

The purpose of Firmware Integration Testing is to verify that individual firmware components/modules interact correctly when integrated. It ensures proper data flow, communication, and functionality across modules while detecting issues like interface mismatches, incorrect dependencies, and integration errors.

### Testbench

#### Hardware

- Power Supply
- J-Link
- Virtual COM/Debug Port (UART/ITM)
- Product Board/Device Board
- Raspberry

#### Software

1. Test Analysis & Planning

3. Test Case Development
- doxygen
- IDE (VS Code, STM32CubeIDE),
  
3. Test Execution
- Compilator, 
- CMake
- Shelly
- Python
 
### Test Type

* Interface Testing – Validate interactions between firmware modules
* Data Flow Testing – Verify data consistency and correctness across interfaces
* Communication Testing – Test UART, SPI, I2C, CAN, or other communication protocols
* Error Handling Tests – Ensure proper error detection and recovery at integration level
* Performance Tests – Measure execution time, memory usage, and CPU load in integrated execution
* Regression Tests – Ensure new changes do not break existing functionality (Testbench + CI)

### Inputs

- Firmware Integration Strategies
- Firmware Component Code Sources
- Firmware Architecture Design [Software Architecture, Functional Decoposition]
- Firmware Detailled Design 

### Delivery

- Component Test Code Sources
- Module.lib
- ModuleTestRunner.bin
- ComponentTestRunner.bin
- Integration Test Report
- Quality Report 

### Criterial

### Dashboard*
 
