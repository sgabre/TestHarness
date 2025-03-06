# Test Harness

A Test Harness automates the execution, monitoring, and validation of tests in embedded systems, ensuring correctness, performance, and compliance. It is used for unit testing, hardware-software integration, regression testing, performance benchmarking, protocol validation, fault injection, security analysis, compliance verification, HIL testing, and CI/CD automation.

# Workflow

1. Checkout Code
2. Compilation
4. Static & Dynamic Code Analysis
5. Documentation
6. [Unit Testing]()
8. Component Testing
9. Integration testing
7. System testing
8. Acceptance testing
9.  Package
10. Release

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

- "Software Module" Code Sources
- Software Low Level Design/Software Detailled Design (doxygen for each function(s))

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


## Firmware Component Testing

### Scope

The purpose of Component testing is to TBD

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

- Software Component Code Sources
- Software Low Level Design/Software Detailed Design (doxygen for the Component & Module(s) )

### Delivery

- Component Test Code Sources
- Module.lib
- ModuleTestRunner.bin
- ComponentTestRunner.bin
- Unit Test Report
- Quality Report 

### Criterial



### Dashboard*



## Firmware Integration Testing 

### Scope

The purpose of Component testing is to TBD

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

- Boundary Tests
- Functional Tests
- Structural Tests
- Error Handling Tests*
- Performance Tests*
- Regression Tests (Testbenc + CI)

### Inputs

- Integration Strategies
- Software Component Code Sources
- Software Architecture Design [Software Architecture, Functional Decoposition]
- Software Detailled Design 

### Delivery

- Component Test Code Sources
- Module.lib
- ModuleTestRunner.bin
- ComponentTestRunner.bin
- Integration Test Report
- Quality Report 

### Criterial

### Dashboard*



## Firmware System testing

### Scope

The purpose of Component testing is to TBD

### Testbench

#### Hardware

- Power Supply
- J-Link
- Virtual COM/Debug Port (UART/ITM)
- Product Board/Device Board
- Raspberry

#### Software

1. Test Case Development
- doxygen
- IDE (VS Code, STM32CubeIDE),
  
2. Test Execution
- Compilator, 
- CMake
- Shelly
- Python
 
### Test Type

- Boundary Tests
- Functional Tests
- Structural Tests
- Error Handling Tests*
- Performance Tests*
- Regression Tests (Testbenc + CI)

### Inputs

- Integration Strategies
- Software Component Code Sources
- Software Architecture Design [Software Architecture, Functional Decoposition]
- Software Detailled Design 

### Delivery

- Code Sources
- SystemSoftware.bin
- System Test Report
- Quality Report 

### Criterial

### Dashboard*
