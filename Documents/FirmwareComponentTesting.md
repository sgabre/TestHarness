## Firmware Component Testing

### Scope

The purpose of Component Testing is to verify the correctness, reliability, and performance of individual firmware components in isolation before integration into the complete system. This ensures that each component meets functional, structural, and quality requirements.

### Testbench

#### Hardware

- Power Supply
- J-Link
- Virtual COM/Debug Port (UART/ITM)
- Microcontroller Board/Dev Board/Product Board/Device Board

#### Software

1. Test Case Development
- doxygen
- IDE (VS Code, STM32CubeIDE),
  
2. Test Execution
- Compilator, 
- CMake
- Unity
- CMock
- Ceedling
- Terminal ()

### Test Type

- Boundary Tests
- Functional Tests
- Structural Tests
- Error Handling Tests*
- Performance Tests*
- Regression Tests (Testbenc + CI)

### Inputs

- Firmware Component Code Sources
- Firmware Low Level Design/Firmware Detailed Design (doxygen for the Component & Module(s) )

### Delivery

- Component Test Code Sources
- Module.lib
- ModuleTestRunner.bin
- ComponentTestRunner.bin
- Unit Test Report
- Quality Report 

### Criterial



### Dashboard*
 
