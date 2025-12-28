// NXCarbonAddon.h
// Main header file for the NX Carbon Emission Add-On

#ifndef NX_CARBON_ADDON_H
#define NX_CARBON_ADDON_H

// Define NX-specific types and macros for compilation without NX headers
#ifndef NX_TYPES_DEFINED
#define NX_TYPES_DEFINED

typedef int  tag_t;
typedef int  logical;
typedef int  int_t;
typedef int  UF_MB_box_type_t;
typedef char UFIXAPI;
#define UFUN_EXPORT __declspec(dllexport)
#define UFIXAPI __stdcall
#define UF_UNLOAD_IMMEDIATELY 1

// Mock NX functions for compilation
int UF_initialize(int* error_code);
void UF_terminate();
#endif

// Function declarations for NX integration
extern "C" {
    // Main entry point for the add-on
    UFUN_EXPORT int ufusr(char *param, int param_len);

    // Function to determine when to unload the add-on
    UFUN_EXPORT int ufusr_ask_unload();
}

// Version information
#define NX_CARBON_ADDON_VERSION "1.0.0"
#define NX_CARBON_ADDON_NAME "NX Carbon Emission Calculator"

// Configuration paths and constants
#define SECURE_CONFIG_PATH "C:\\ProgramData\\Siemens\\NX\\CarbonAddon\\config.secure"
#define USER_CONFIG_PATH "%APPDATA%\\Siemens\\NX_Carbon_Addon\\user_config.json"
#define COMPANY_CONFIG_PATH "\\\\server\\shared\\NX_Config\\carbon_addon_config.json"

#endif // NX_CARBON_ADDON_H