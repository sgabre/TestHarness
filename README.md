# Test Harness

A Test Harness automates the execution, monitoring, and validation of tests in embedded systems, ensuring correctness, performance, and compliance. It is used for unit testing, hardware-software integration, regression testing, performance benchmarking, protocol validation, fault injection, security analysis, compliance verification, HIL testing, and CI/CD automation.



## Test Type

### Scope

### Testbench

#### Hardware

- Power Supply
- J-Link
- Virtual COM/Debug Port (UART/ITM)
- Microcontroller Board/Dev Board/Product Board/Device Board

#### Software

- Compilator
- CMake
- Unity
- CMock
- Ceedling
- Terminal ()

### Test Type

-
- 

### Inputs

- "Software Module" Code Sources
- Software Low Level Design/Software Detailled Design (doxygen)

### Delivery

- Unit Test Sources
- FunctionUnitTestRunner.bin
- Unit Test Report
- Quality Report 

### Criterial

- Number of Total Unit Test is greater or equal to Cyclomatic complexity
-  For each Function, the Statement Coverage greater than 70%
-  For each Function, the Branch Coverage greater than 70%

### Dashboard

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



# Workflow

1. Checkout Code

2. Compilation

4. Static Code Analysis

5. Documentation

6. Unit Testing

   Goal

   Testbench
 
   Actions
    - Compile Unit Tests
    - Flash Firmware
    - Run Tests on Target
    - Check Test Results
  
    Delivery
   - FunctionUnitTestRunner
   - 

8. Component Testing
    - Compile Component Tests
    - Flash Firmware
    - Run Tests on Target
    - Check Test Results

9. Integration testing
    - Compile Integration Tests
    - Flash Firmware
    - Run Tests on Target
    - Check Test Results

I 6.2. Component integration testing
    - Compile Component Integration Tests
    - Flash Firmware
    - Run Tests on Target
    - Check Test Results

6.3. System integration testing
    - Compile System Integration Tests
    - Flash Firmware
    - Run Tests on Target
    - Check Test Results

7. System testing
    - Compile System Tests
    - Flash Firmware
    - Run Tests on Target
    - Check Test Results
   
8. Acceptance testing
    - Compile System Tests
    - Flash Firmware
    - Run Tests on Target
    - Check Test Results

 9.  Package

 10.  Release



