# Installing NX Carbon Emission Add-On in Siemens NX

## Overview
This document provides comprehensive instructions for installing the NX Carbon Emission Add-On in Siemens NX CAM software. The add-on integrates directly into the NX environment to provide carbon emission calculations for machining operations.

## Prerequisites

### System Requirements
- **Siemens NX Version**: 12.0 or higher (CAM module required)
- **Operating System**: Windows 10 or Windows 11 (64-bit)
- **RAM**: Minimum 8 GB (16 GB recommended)
- **Disk Space**: 500 MB available
- **Visual C++ Redistributables**: Microsoft Visual C++ 2019 or later

### Development Environment (For Building)
If you need to build from source:
- Microsoft Visual Studio 2019 or later
- NX Open API development libraries
- CMake 3.15 or higher
- Your OpenAI API key (optional, for AI features)

## Installation Methods

### Method 1: Manual Installation (Recommended)

#### Step 1: Prepare Your Environment
1. **Close all NX sessions** completely before installation
2. **Ensure you have administrator privileges** on the target machine
3. **Backup your current NX configuration** if desired

#### Step 2: Build the Add-On (If Building from Source)
1. Open Visual Studio Developer Command Prompt
2. Navigate to the project directory:
   ```
   cd NXCarbonAddon_NX_Siemens
   ```
3. Create build directory and build:
   ```
   mkdir build
   cd build
   cmake .. -G "Visual Studio 16 2019" -A x64 -DUGII_BASE_DIR="C:\Program Files\Siemens\NX" -DCMAKE_BUILD_TYPE=Release
   cmake --build . --config Release
   ```

#### Step 3: Copy the Add-On File
1. Locate the built DLL file: `NXCarbonAddon.dll`
2. Copy it to one of these NX startup directories:
   
   **For all users** (requires administrator privileges):
   ```
   C:\Program Files\Siemens\NX\UGII\startup\
   ```
   
   **For current user only**:
   ```
   %UGII_USER_DIR%\startup\
   ```
   (Typically: `C:\Users\[username]\AppData\Roaming\Siemens\NX[version]\startup\`)

#### Step 4: Verify Installation
1. Launch Siemens NX
2. The add-on should load automatically
3. Look for new menu items or toolbar buttons related to carbon calculation

### Method 2: Using NX Customize Dialog

1. Open Siemens NX
2. Go to **Tools** → **Customize**
3. Select the **"Add-ons"** tab
4. Click **"Browse"** button
5. Navigate to and select your `NXCarbonAddon.dll` file
6. The add-on will be registered and will load on next NX restart

### Method 3: Registry Installation (Advanced)

1. Open Registry Editor (regedit) as Administrator
2. Navigate to:
   ```
   HKEY_CURRENT_USER\SOFTWARE\Siemens\NX\UGII\Startup\
   ```
3. Create a new **Key** named `NXCarbonAddon`
4. In the new key, create a **String Value** named `(Default)`
5. Set the value to the full path of your DLL:
   ```
   C:\path\to\your\NXCarbonAddon.dll
   ```

## NX-Specific Configuration

### NX Environment Variables
Ensure these environment variables are set (usually done automatically by NX installation):
- `UGII_BASE_DIR`: Path to NX installation
- `UGII_USER_DIR`: Path to user NX directory

### NX CAM Module Requirement
The add-on requires the CAM module to be licensed and available in your NX installation.

## API Key Configuration

### Automatic Configuration (Recommended)
1. Launch NX after installing the add-on
2. The add-on may display an initial configuration dialog
3. Enter your OpenAI API key when prompted
4. The key will be stored securely in Windows Registry

### Manual Configuration
If the automatic configuration doesn't appear:

1. Create the registry entry manually:
   ```
   HKEY_CURRENT_USER\SOFTWARE\Siemens\NX\CarbonAddon\APIKey
   ```
2. Set the value to your OpenAI API key

Or create a secure config file:
```
%APPDATA%\Siemens\NX_Carbon_Addon\secure_config.json
```

## Integration Points in NX

### Menu Integration
After installation, you should see:
- New menu item under **Tools** → **NX Carbon Emission Calculator**
- Or under **Manufacturing** → **Analysis** menu

### Toolbar Integration
- New toolbar buttons for quick access to carbon calculations
- Ribbon panel in CAM environment

### Command Integration
- New commands available in NX command line:
  - `carbon_calc` - Main carbon calculation command
  - `carbon_settings` - Configuration command

## Post-Installation Verification

### 1. Check Add-On Loading
1. Launch NX
2. Look at the **Information Window** or **Log File** for loading messages
3. You should see: "NX Carbon Emission Add-On initialized"

### 2. Test Functionality
1. Open a CAM file with operations
2. Access the carbon calculation through the menu or toolbar
3. Verify that calculations work correctly

### 3. Verify API Integration
1. If you configured OpenAI API key, verify AI features work
2. If not, verify that local models work as fallback

## Enterprise Deployment

### Network Installation
For enterprise environments:

1. **Prepare installation package** with built DLL and configuration
2. **Deploy via Active Directory Group Policy** or similar system
3. **Configure centralized settings** if needed
4. **Set up security policies** for API key management

### Multi-User Configuration
- Use company-wide configuration servers
- Implement role-based access controls
- Set up usage monitoring and budget controls

## Security Considerations

### File Permissions
- Ensure DLL file has appropriate permissions
- Verify NX can access the startup directory
- Protect configuration files containing API keys

### API Key Security
- Never store API keys in plain text
- Use encrypted storage (registry or config files)
- Implement proper access controls

## Updating the Add-On

### To Update to New Version
1. Close all NX sessions
2. Replace the old `NXCarbonAddon.dll` file with the new version
3. Restart NX
4. Check for any new configuration requirements

### Backup and Rollback
- Keep backup of previous version DLL
- Maintain configuration backups
- Have rollback plan if update causes issues

## Integration Testing

### Test Scenarios
1. **Basic Loading**: Verify add-on loads without errors
2. **Functionality Test**: Test carbon calculations with sample operations
3. **API Integration**: If configured, test OpenAI features
4. **Performance**: Ensure add-on doesn't impact NX performance significantly
5. **Compatibility**: Test with different NX versions if applicable

This completes the installation process for the NX Carbon Emission Add-On. The add-on should now be fully integrated into your NX environment and ready for use.