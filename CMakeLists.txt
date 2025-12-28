cmake_minimum_required(VERSION 3.10)
project(NXCarbonAddon)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
# For OpenAI API integration, we need JSON library and HTTP client
# Note: For a real NX add-on, you would need to find NX Open API libraries
# find_package(UFSDK REQUIRED)  # Example for NX SDK
# find_package(nlohmann_json 3.2.0 REQUIRED)  # JSON library
# find_package(CURL REQUIRED)   # HTTP client library

# Define source files - Changed from main.cpp to NXCarbonAddon.cpp for NX compatibility
set(SOURCES
    NXCarbonAddon.cpp
    NXCamDataExtractor.cpp
    TimeModel.cpp
    EnergyModel.cpp
    CarbonModel.cpp
    AIInterface.cpp
)

# Define header files
set(HEADERS
    NXCamDataExtractor.h
    TimeModel.h
    EnergyModel.h
    CarbonModel.h
    AIInterface.h
    NXCarbonAddon.h
)

# Create SHARED library (DLL) instead of executable for NX add-on
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Compiler-specific options
if(MSVC)
    # Microsoft Visual C++ specific options
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
    # Define UFUN_EXPORTS for NX add-on
    target_compile_definitions(${PROJECT_NAME} PRIVATE UFUN_EXPORTS)
else()
    # GCC/Clang specific options
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

# For OpenAI integration, link required libraries
# target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json ${CURL_LIBRARIES})

# For a real NX add-on, you would link against NX libraries like this:
# target_link_libraries(${PROJECT_NAME} PRIVATE ${UFSDK_LIBRARIES})

# Set output name and properties for NX compatibility
set_target_properties(${PROJECT_NAME} PROPERTIES
    PREFIX ""
    OUTPUT_NAME "NXCarbonAddon"
)

# Install target (optional)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)