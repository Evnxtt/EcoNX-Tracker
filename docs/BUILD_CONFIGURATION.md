# NX Siemens Add-On Build Configuration

## Overview
This document describes how to build the NX Carbon Emission Add-On for Siemens NX CAM software.

## Prerequisites

### Required Software
- Siemens NX (version 12 or higher recommended)
- NX Open API development libraries
- Microsoft Visual Studio 2019 or later (for Windows)
- C++17 compatible compiler
- CMake 3.15 or higher
- OpenAI API key (optional, for AI features)

### NX Development Environment Setup
1. Install Siemens NX with CAM module
2. Install NX Open API development libraries
3. Set environment variables:
   - `UGII_BASE_DIR`: Path to NX installation
   - `UGII_USER_DIR`: Path to user NX directory

## Build Process

### Windows (Visual Studio)

1. Open Developer Command Prompt for VS
2. Navigate to the project directory
3. Create build directory:
   ```
   mkdir build
   cd build
   ```

4. Configure with CMake:
   ```
   cmake .. -G "Visual Studio 16 2019" -A x64 -DUGII_BASE_DIR="C:\Program Files\Siemens\NX" -DCMAKE_BUILD_TYPE=Release
   ```

5. Build the project:
   ```
   cmake --build . --config Release
   ```

### Alternative CMake Configuration
```
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A x64 \
    -DUGII_BASE_DIR="C:\Program Files\Siemens\NX" \
    -DCMAKE_BUILD_TYPE=Release \
    -DNX_VERSION=1946 \
    ..
cmake --build . --config Release
```

## NX Add-On Installation

### Method 1: Direct Copy
1. Build the project successfully
2. Copy the resulting DLL file to NX's startup folder:
   - Default location: `C:\Program Files\Siemens\NX\UGII\startup\`
   - Or to user's startup: `%UGII_USER_DIR%\startup\`

### Method 2: Using NX Customization
1. Open NX
2. Go to Tools → Customize → Add-ons
3. Add the built DLL file

### Method 3: Registry Method
Add registry entry under:
```
HKEY_CURRENT_USER\SOFTWARE\Siemens\NX\UGII\Startup\NXCarbonAddon
```
Value: Full path to the DLL

## Project Structure for NX Integration

```
NXCarbonAddon_NX_Siemens/
├── src/                    # Source code
│   ├── NXCarbonAddon.cpp   # Main NX entry point
│   ├── NXCamDataExtractor.cpp
│   ├── TimeModel.cpp
│   ├── EnergyModel.cpp
│   ├── CarbonModel.cpp
│   └── AIInterface.cpp
├── include/                # Header files
│   ├── NXCarbonAddon.h
│   ├── NXCamDataExtractor.h
│   ├── TimeModel.h
│   ├── EnergyModel.h
│   ├── CarbonModel.h
│   └── AIInterface.h
├── libs/                   # External libraries
│   ├── nxopen_cpp_core.lib
│   ├── nxopen_cam.lib
│   └── (OpenAI client library if needed)
├── res/                    # Resources
│   ├── icons/
│   └── dialogs/
├── ui/                     # User interface files
├── config/                 # Configuration templates
├── build/                  # Build artifacts
├── docs/                   # Documentation
├── CMakeLists.txt          # Build configuration
└── nx_addon_manifest.xml   # NX add-on manifest
```

## CMakeLists.txt for NX Integration

```cmake
cmake_minimum_required(VERSION 3.15)
project(NXCarbonAddon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find NX libraries
find_path(UGII_BASE_DIR
    NAMES include/uf_defs.h
    PATHS $ENV{UGII_BASE_DIR}
    PATH_SUFFIXES UGII
)

if(NOT UGII_BASE_DIR)
    message(FATAL_ERROR "UGII_BASE_DIR not found. Please set the environment variable.")
endif()

# Include directories
include_directories(
    ${UGII_BASE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Library directories
link_directories(
    ${UGII_BASE_DIR}/ugii
)

# Source files
set(SOURCES
    src/NXCarbonAddon.cpp
    src/NXCamDataExtractor.cpp
    src/TimeModel.cpp
    src/EnergyModel.cpp
    src/CarbonModel.cpp
    src/AIInterface.cpp
)

# Create shared library (NX add-on is a DLL)
add_library(NXCarbonAddon SHARED ${SOURCES})

# Link NX libraries
target_link_libraries(NXCarbonAddon 
    uforide
    ugxprt
    ugeomp
    # Add other required NX libraries
)

# Compiler definitions
target_compile_definitions(NXCarbonAddon PRIVATE 
    UFUN_EXPORTS
    WIN32_LEAN_AND_MEAN
)

# Set output name to match NX expectations
set_target_properties(NXCarbonAddon PROPERTIES
    PREFIX ""
    OUTPUT_NAME "NXCarbonAddon"
)

# Copy to NX startup directory (optional)
if(DEFINED NX_STARTUP_DIR)
    add_custom_command(TARGET NXCarbonAddon POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:NXCarbonAddon>
        ${NX_STARTUP_DIR}/
    )
endif()
```

## NX Add-On Manifest

Create `nx_addon_manifest.xml`:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<addonManifest>
    <addon id="com.siemens.nx.carbonaddon" version="1.0.0">
        <name>NX Carbon Emission Calculator</name>
        <description>Calculate carbon emissions for NX CAM operations</description>
        <vendor>EcoNX Team</vendor>
        <entryPoint>ufusr</entryPoint>
        <dllName>NXCarbonAddon.dll</dllName>
        <minimumNXVersion>12.0.0</minimumNXVersion>
        <startupType>AtStartup</startupType>
    </addon>
</addonManifest>
```

## Deployment

### Creating Installation Package
1. Build the add-on in Release mode
2. Create installation directory structure
3. Include all necessary files:
   - NXCarbonAddon.dll
   - Dependencies (if any)
   - Configuration files
   - Documentation
4. Create installer or zip package

### Enterprise Deployment
For enterprise environments:
1. Create MSI installer
2. Deploy via company software distribution system
3. Configure group policies for automatic installation
4. Set up centralized configuration management

## Troubleshooting

### Common Build Issues
- Missing NX development libraries: Ensure UGII_BASE_DIR is set correctly
- Linker errors: Verify all required NX libraries are linked
- Missing headers: Check include paths are correct

### Common Runtime Issues
- Add-on not loading: Check file permissions and NX startup directory
- NX version compatibility: Verify NX version requirements
- API access errors: Ensure proper NX CAM licenses are available