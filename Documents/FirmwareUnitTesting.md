## Firmware Unit Testing

### Scope

The purpose of unit testing is to validate individual functions (Public & Private) to ensure they work as expected in isolation. It helps detect and fix defects early in the development cycle, improving code quality, reliability, and maintainability.

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

- "Firmware Module" Code Sources
- Firmware Low Level Design/Firmware Detailled Design (doxygen for each function(s))

### Delivery

- Unit Test Sources
- FunctionUnitTestRunner.bin
- Unit Test Report
- Quality Report 

### Criterial

-  Number of Total Unit Test is greater or equal to Cyclomatic complexity
-  For each Function, the Statement Coverage greater than 70%
-  For each Function, the Branch Coverage greater than 70%

### Dashboard*

| Function                | Cyclomatic complexity | # Total | # Pass | # Fail | # Not Executed |
|-------------------------|-----------------------|---------|--------|--------|----------------|
| Module_PublicFunction   |   12                  |     14  |   12   |  1     |   1            |
| Module_PrivateFunction  |   10                  |     5   |   3     |  1    |   3            | <= Issue

| Function                | Statement Coverage    | Branch Coverage |
|-------------------------|-----------------------|-----------------|
| Module_PublicFunction   |   100 %               |         100 %   |
| Module_PrivateFunction  |   100 %               |         100 %   |

| Function                              | Code Size (Byte)      | RAM (Byte)            |
|---------------------------------------|-----------------------|-----------------------|
| Module_PublicFunctionUnitTestRunner   |   1024                |   35                  |
| Module_PrivateFunctionUnitTestRunner  |   54                  |   64                  |


| Function	                            | Execution Time (ms)	 | Memory Usage (Bytes)	 | Code Size (Bytes) | CPU Cycles    |
|---------------------------------------|-----------------------|-----------------------|-------------------|---------------|
| Module_PublicFunctionUnitTestRunner   |	1.2 ms	             | 512 B	                | 1024 B	         | 24000         |
| Module_PrivateFunctionUnitTestRunner  | 0.8 ms	             | 256 B	                | 768 B             | 18000         |
 
