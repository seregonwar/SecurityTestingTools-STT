# 900

## Purpose

This project aims to decrypt and decompile code compiled in the `.bin` format, translating it from pseudocode to high-level source code. Although C++ has been chosen for this implementation, the pseudocode can be easily adapted to any high-level language superior to assembly.

## Project Structure

The project is organized into several directories and files to ensure a clear separation between headers, source code, documentation, and configurations. Below is the structure of the project:

```plaintext
.
├── include/                     # Header files (.h) for classes and functions
│   ├── bit_extractor.h          # Class for extracting bits from binary data
│   ├── checksum_calculator.h    # Class for calculating checksums
│   ├── cr0_handler.h            # Handler for the CPU's CR0 register
│   ├── data_cleaner.h           # Class for data cleaning
│   ├── data_decoder.h           # Class for decoding input data
│   ├── data_handler.h           # Data handler for various operations
│   ├── data_processing.h        # Class for data processing logic
│   ├── data_processor.h         # Main module for data processing
│   ├── data_validator.h         # Validator for input data
│   ├── interrupt_handler.h      # System interrupt handler
│   ├── memory_accessor.h        # Accessor for memory
│   ├── memory_caller.h          # Class for invoking functions in memory
│   ├── memory_checker.h         # Memory consistency checks
│   ├── memory_function.h        # Functions for memory management
│   ├── memory_initializer.h     # Memory initializer
│   ├── msr_reader.h             # Reading MSR registers
│   ├── syscall_caller.h         # Syscall invocation
│   ├── syscall_handler.h        # Syscall handler
│   └── ...                      # Other header files
├── src/                         # Implemented source files (.cpp)
│   ├── bit_extractor.cpp        # Implementation of bit extraction
│   ├── checksum_calculator.cpp  # Implementation of checksum calculation
│   ├── cr0_handler.cpp          # Implementation of CR0 handler
│   ├── data_cleaner.cpp         # Implementation of data cleaning
│   ├── data_decoder.cpp         # Implementation of data decoding
│   ├── data_handler.cpp         # Implementation of data handler
│   ├── data_processing.cpp      # Logic for data processing
│   ├── data_processor.cpp       # Implementation of data processor
│   ├── function1.cpp            # Another generic function implemented
│   ├── main.cpp                 # Main file for program execution
│   ├── memory_accessor.cpp      # Implementation for memory access
│   ├── memory_caller.cpp        # Implementation for invoking functions in memory
│   ├── memory_checker.cpp       # Implemented memory checks
│   ├── memory_function.cpp      # Implementation of memory functions
│   ├── memory_initializer.cpp    # Implementation of memory initialization
│   ├── msr_reader.cpp           # Reading MSR registers
│   ├── syscall_caller.cpp       # Implemented syscall invocation
│   ├── syscall_handler.cpp       # Implemented syscall handler
│   └── ...                      # Other source files
├── docs/                        # Project documentation
│   └── ...                      # Documentation files
├── .vscode/                     # Configurations for Visual Studio Code IDE
│   └── launch.json              # Debug configuration
├── .gitignore                   # File to exclude files and folders from Git
└── README.md                    # Main project documentation
```

## Directory Descriptions

### `include/`
Contains all the header files used in the project. These files declare classes, functions, and data structures, which are then implemented in the source files.

### `src/`
Includes the implementations of the classes and functions declared in the header files. This is where the main logic of the program resides.

### `docs/`
This folder hosts the project documentation, which can include user guides, technical manuals, or specifications.

### `.vscode/`
Contains configurations for Visual Studio Code, such as debugging settings, useful for developers using this editor for project development and testing.

### `.gitignore`
Specifies which files or directories should be ignored by Git version control. Typically includes temporary files, personal configuration files, or build artifacts.

### `README.md`
The file you are currently reading, providing an overview of the project, its purposes, and how to use it.
