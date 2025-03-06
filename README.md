# Test Harness

A Test Harness automates the execution, monitoring, and validation of tests in embedded systems, ensuring correctness, performance, and compliance. It is used for unit testing, hardware-software integration, regression testing, performance benchmarking, protocol validation, fault injection, security analysis, compliance verification, HIL testing, and CI/CD automation.

# Workflow

1. Checkout Code
2. Compilation
4. Static & Dynamic Code Analysis
5. Documentation
6. [Unit Testing](./Documents/FirmwareUnitTesting.md)
8. [Component Testing](./Documents/FirmwareComponentTesting.md)
9. [Integration testing](./Documents/FirmwareIntegrationTesting.md)
7. [System testing](./Documents/FirmwareSystemTesting.md)
8. [Acceptance testing](./Documents/FirmwareAcceptanceTesting.md)
9.  Package
10. Release






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
