# EcoNX-Tracker CNC Carbon Emission Add-on

This is a C++ implementation of an NX Siemens Add-on designed to estimate energy consumption and carbon emissions from CNC machining processes. The add-on extracts machining data directly from NX CAM, applies engineering-based physical models, and optionally integrates AI (machine learning) to improve prediction accuracy.

## Overview

This project implements the system architecture described in the original `project.md` file:
- NX CAM data extraction using simulated NX Open API
- Time modeling (cutting, rapid, idle)
- Energy modeling based on machine-specific power profiles
- Carbon emission calculation using regional electricity factors
- Optional AI integration for improved predictions

## Project Structure

```
NXCarbonAddon/
├── main.cpp                    # Main entry point
├── NXCamDataExtractor.h/cpp    # NX CAM data extraction
├── TimeModel.h/cpp             # Time modeling
├── EnergyModel.h/cpp           # Energy consumption modeling
├── CarbonModel.h/cpp           # Carbon emission calculation
├── AIInterface.h/cpp           # AI integration interface
├── CMakeLists.txt              # Build configuration
└── README.md                   # This file
```

## Building the Project

### Prerequisites
- C++17 compatible compiler (GCC, Clang, or MSVC)
- CMake 3.10 or higher
- (For real NX integration) NX Open API libraries

### Build Instructions

```bash
# Clone or copy the project
cd NXCarbonAddon

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .
```

On Windows with Visual Studio:
```cmd
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
```

## Usage

Run the executable:
```bash
# Linux/Mac
./NXCarbonAddon

# Windows
NXCarbonAddon.exe
```

## Key Features

1. **NX Data Extraction**: Simulated extraction of cutting time, operation list, tool information, and process parameters
2. **Time Modeling**: Estimation of rapid and idle times based on cutting time and operations count
3. **Energy Modeling**: Calculation of energy consumption for cutting, rapid, and idle phases
4. **Carbon Modeling**: Conversion of energy consumption to carbon emissions using regional factors
5. **AI Integration**: Optional machine learning interface for improved power prediction

## Configuration

The models have default parameters that can be adjusted:

- **TimeModel**: Rapid time factor, idle time per operation, setup time
- **EnergyModel**: Cutting, rapid, and idle power values
- **CarbonModel**: Emission factors by country/grid type
- **AIInterface**: Enable/disable AI, load models

## Data Flow

1. NX CAM provides cutting time and operation parameters
2. TimeModel estimates rapid and idle times
3. EnergyModel calculates energy consumption based on time and power values
4. CarbonModel converts energy to carbon emissions using regional factors
5. (Optional) AIInterface refines power predictions using ML

## Extending the Project

To integrate with real NX CAM:
1. Link against NX Open API libraries
2. Implement actual data extraction functions in NXCamDataExtractor
3. Adjust model parameters based on real machine specifications

## Academic & Industrial Use

This project is suitable for:
- Academic research on sustainable manufacturing
- Engineering competitions
- Sustainability assessment in manufacturing
- Research papers on carbon footprint of machining

## License

This project is intended for academic research, educational purposes, and sustainability assessment. It is not intended to replace certified energy measurement systems.
