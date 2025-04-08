# Firmware Architecture Design

[TOC]

## Hardware Architecture

This section describes the physical components of the system.  
It includes the microcontroller (e.g., STM32), power supply design, sensors, actuators, communication interfaces (USB, UART, CAN, etc.), and any peripherals connected to the MCU.

You should explain:

- What hardware is used (e.g., development board or custom PCB)
- How components are connected (bus types, GPIO usage, etc.)
- Key MCU peripherals (e.g., timers, ADCs, DMA) that your firmware relies on

Purpose: Help the reader understand the embedded platform the software will run on, and any physical or electrical constraints.

## Software System Environment


This section provides an overview of the software tools, dependencies, and build environment required to develop, test, and run the system.

Include details such as:

- Programming language and coding standards (C, MISRA-C, C++)
- Development tools (IDE, compiler, debugger)
- Build system (e.g., CMake, Make, Docker containers)
- Operating systems (embedded RTOS or bare-metal, desktop platforms for simulation)
- External libraries or frameworks (HAL, unit testing frameworks, etc.)
- Documentation and version control tools (e.g., Doxygen, Git)

Purpose: Describe everything needed to build and maintain the software, and support traceability and reproducibility.

## System Software Architecture

This is a high-level structural view of your software.  
It explains how the system is layered or modularized, how responsibilities are divided, and how different components interact.

You should:

- Describe architectural layers (application, middleware, hardware abstraction)
- Highlight any design patterns or architectural principles used
- Explain how modules communicate (e.g., function calls, message queues)
- Mention cross-platform support (if modules are reused on PC or Python)

Purpose: Provide a conceptual blueprint of how the software is organized, and justify architectural decisions.


## Functional Decomposition

<< Identify the software items that fulfill the requirements defined in the SRS.  
One or more context diagrams as shown in the examples below or other graphical presentation could be used for this purpose in addition to a short description of each main component or subsystem.  
In the decomposition, identify any component that is classified as SOUP (Software of Unknown Provenance/Off the shelf software) >>


## Hazard Mitigation

<< Define any necessary component segregation required to reduce the risks and how segregation is achieved.  
Describe also any other measure taken at architectural level to reduce or control the risks>>

In this section, you describe what architectural-level decisions were made to minimize or control safety risks.

Topics might include:

- Logical or physical segregation of critical components
- Use of watchdogs, assertions, or fault handlers
- Handling of invalid input or unexpected states
- Safe startup or shutdown sequences
- Restrictions on dynamic memory or threading (to reduce unpredictability)
- How SOUP is isolated or validated to prevent unexpected behavior

Purpose: Show how the design ensures safety, reliability, and robustness from the top down.

## Key Algorithms 

This section identifies the core algorithms that the firmware implements — anything with significant logic or processing beyond basic I/O.

For each algorithm, you might provide:

- Its purpose and where it fits in the system
- A short description of how it works (detailed logic can go in detailed design docs)
- Information on input/output data or timing constraints
- Optionally, include a table or list format. The detailed code-level explanation would be referenced in another section or document.

Purpose: Highlight the most important logic your system runs and serve as a roadmap for deeper understanding or testing.


# Interfaces

In this section, we detail the main hardware and software interfaces that are implemented for the architectural components defined in the previous section. Low-level interfaces used within a single component are not defined here, as they should be described in the detailed design of that component.

## Interface Mechanisms

This section describes the **interface mechanisms** used for communication between different components in the system. These mechanisms define how data and control are exchanged.

- **Message Queues**: Used for inter-process communication (IPC) where components send messages asynchronously.
- **Example**: A message queue could be used by the sensor module to send sensor data to the application layer for processing.

- **Shared Memory**: A memory segment that multiple components access for data exchange, useful for high-performance applications.
- **Example**: A shared memory block could store sensor readings from the MCU's ADC, which are then processed by the software.

- **Function Calls (Direct)**: Direct calls between software modules (or between the module and its hardware abstraction layer).
- **Example**: The application layer might call the `Sensor_Read()` function to gather data from the sensor driver.

- **Interrupts**: Hardware interrupts trigger asynchronous events, typically used for time-sensitive tasks.
- **Example**: An interrupt could signal that a sensor's ADC conversion has completed, prompting the software to read the new data.

- **Events**: Used in real-time systems to indicate state changes or completion of tasks.
- **Example**: An event may signal that new sensor data is available for processing.

Each of these mechanisms is used for different purposes within the system, providing efficient and reliable communication between components.

## Data Structures

This section defines the **data structures** used for interfacing between components, specifying data formats and any related structures.

- **Data Formats**: The format of data exchanged between components, such as JSON, binary, or raw sensor data.
- **Example**:
```c
typedef struct {
float temperature;
float humidity;
} SensorData_t;
```

- **Buffers and Queues**: Data structures like circular buffers or FIFO queues used to store and manage data flow.
- **Example**: A `SensorQueue_t` structure that holds a circular buffer for storing sensor data.

- **Control Structures**: Flags, semaphores, or other synchronization mechanisms used to coordinate the system's operation.
- **Example**: A structure used to track the status of sensor data acquisition.

- **Data Dictionary**: A detailed dictionary describing the data fields, valid ranges, and units of the data structures.
- **Example**: Refer to the "Data Dictionary" for an explanation of the `SensorData_t` structure and acceptable value ranges.

This section ensures that the data exchanged between components is well-defined and standardized for correct usage.

## Error Handling

In this section, we describe the **error handling mechanisms** employed in the system for handling errors in interface mechanisms and data exchanges.

- **Timeouts**: Used for interfaces like UART or SPI, where a failure to receive a response within a specified time is considered an error.
- **Example**: If UART communication times out, the system retries the transmission or flags an error.

- **Buffer Overflow or Underflow**: In message queues or circular buffers, the system must handle cases where buffers overflow (too many messages) or underflow (no data to read).
- **Example**: If a buffer overflows, the system could drop the oldest message or signal an error condition.

- **Checksum Errors**: Communication protocols like SPI or I2C may use checksums to ensure data integrity. If a checksum error occurs, the data is discarded or retried.
- **Example**: If a received message has a bad checksum, the system retries the communication.

- **Error Codes and Handling Structures**: A set of error codes or structures to track errors and respond appropriately.
- **Example**:
```c
typedef enum {
ERROR_UART_TIMEOUT,
ERROR_SENSOR_FAILURE,
ERROR_INVALID_DATA
} ErrorCode_t;
```

- **Fallback Strategies**: Mechanisms that ensure the system can recover or fail safely in the case of critical errors, like a sensor failure.
- **Example**: If a sensor fails, the system can revert to a default value or trigger an alert.

If error handling is described in another section (e.g., in the detailed design or testing documentation), you can reference that section here and avoid repetition.

This section ensures that the system can gracefully handle any errors that occur during communication or data exchange, maintaining reliability and robustness.
