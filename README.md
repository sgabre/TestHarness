# Test Harness

A Test Harness automates the execution, monitoring, and validation of tests in embedded systems, ensuring correctness, performance, and compliance. It is used for unit testing, hardware-software integration, regression testing, performance benchmarking, protocol validation, fault injection, security analysis, compliance verification, HIL testing, and CI/CD automation.

# Workflow

1. Checkout Code
2. Compilation
4. [Static Code Analysis](./Documents/CodeAnalysis.md)
5. [Documentation](./Documents/Documentation.md)
6. [Unit Testing](./Documents/FirmwareUnitTesting.md)
8. [Component Testing](./Documents/FirmwareComponentTesting.md)
9. [Integration testing](./Documents/FirmwareIntegrationTesting.md)
7. [System testing](./Documents/FirmwareSystemTesting.md)
8. [Acceptance testing](./Documents/FirmwareAcceptanceTesting.md)
9. [Package](./Documents/FirmwarePackage.md)
10. Release

# Software Environment Tools

## Configuration Manager

* [git](https://git-scm.com/)
* [Git Credential Manager](https://github.com/git-ecosystem/git-credential-manager)
  
## Compilator

* [CMake](https://cmake.org/)
* [Compilators]()

## Unit Test Framework

* [Unity](https://www.throwtheswitch.org/unity/)
* [CMock](https://www.throwtheswitch.org/cmock)
* [Ceedling](https://www.throwtheswitch.org/ceedling)
* [Exception](https://www.throwtheswitch.org/cexception)
* [Code Coverage](https://mcuoneclipse.com/2014/12/26/code-coverage-for-embedded-target-with-eclipse-gcc-and-gcov/)

# Documentation

* [Doxygen](https://www.doxygen.nl)
* [GraphViz](https://graphviz.org/download/)
* [Message Sequence Chart](https://www.mcternan.me.uk/mscgen/)

# File Structure

```
.
├── CMakeLists.txt
├── CMakePresets.json
├── Documents
├── Firmware
│   ├── Application
│   │   ├── CMakeLists.txt
│   │   ├── Benchy
│   │   ├── Blinky
│   │   ├── Booty
│   │   ├── Faulty
│   │   ├── Shelly
│   │   ├── Startup
│   │   └── Tracy
│   ├── Module
│   ├── shell
│   └── STM32F403RE
├── LICENSE
├── Libraries
│   ├── inc
│   └── lib
├── Packs
│   └── Boards
│       └── STM32F403RE
│           ├── Lib
│           └── inc
├── README.md
├── Scripts
│   ├── build.sh
│   └── pack.sh
├── Tests
│   ├── 0 - Unit Testing
│   ├── 1 - Component Testing
│   ├── 2 - Component Integration Testing
│   ├── 3 - System Integration Testing
│   ├── 4 - System Testing
│   └── 5 - Acceptance Testing
├── Unity
└── doxygen
```

# Command-In-Line

## 

```
```


# Tasks

## Host (Windows, Linux, Mac OS X, Raspberry)
- [ ] Hello Word
- [ ] Software Information
- [ ] Shelly
- [ ] Unit Testing
- [ ] Component Testing
- [ ] Integration Testing
- [ ] System Integration Testing

## Bare-Metal-System
- [ ] Blinky
- [ ] Tracy
- [ ] Shelly
- [ ] Fault
- [ ] Benchy
- [ ] Unit Testing
- [ ] Static Code Analysis
- [ ] Code Coverage
- [ ] Component Testing
- [ ] Integration Testing
- [ ] System Integration Testing
- [ ] Board Library 

## RTOS
- [ ] Blinky
- [ ] Tracy
- [ ] Shelly
- [ ] Fault
- [ ] Benchy
- [ ] Unit Testing
- [ ] Static Code Analysis
- [ ] Code Coverage
- [ ] Component Testing
- [ ] Integration Testing
- [ ] System Integration Testing
- [ ] Board Library 


