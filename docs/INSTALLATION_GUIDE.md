# NX Carbon Emission Add-On - Installation Guide

## Overview
This document provides instructions for installing the NX Carbon Emission Add-On for Siemens NX CAM software.

## System Requirements

### Hardware Requirements
- 64-bit Windows 10 or Windows 11
- Minimum 8 GB RAM (16 GB recommended)
- 500 MB available disk space
- Network connection (for OpenAI API features)

### Software Requirements
- Siemens NX 12.0 or higher (CAM module required)
- Microsoft Visual C++ Redistributable 2019 or later
- OpenAI API key (optional, for AI-enhanced features)

## Installation Methods

### Method 1: Manual Installation (Recommended)

#### Step 1: Download Files
1. Download the installation package
2. Extract to a temporary directory

#### Step 2: Install the Add-On
1. Close all NX sessions
2. Copy `NXCarbonAddon.dll` to your NX startup directory:
   - For all users: `C:\Program Files\Siemens\NX\UGII\startup\`
   - For current user: `%UGII_USER_DIR%\startup\` (usually `C:\Users\[username]\AppData\Roaming\Siemens\NXxx.x\startup\`)

#### Step 3: Configure API Key (Optional)
1. If you want to use OpenAI features, you need to configure your API key
2. Follow the instructions in `docs\API_KEY_CONFIGURATION.md`
3. Recommended: Store in Windows Registry or secure config file

#### Step 4: Restart NX
1. Launch NX
2. The add-on should load automatically
3. Look for "NX Carbon Emission Calculator" in the menu or ribbon

### Method 2: Using NX Customize Dialog
1. Open NX
2. Go to Tools → Customize
3. Select "Add-ons" tab
4. Click "Browse" and select `NXCarbonAddon.dll`
5. The add-on will be loaded on next NX restart

### Method 3: Registry Installation
Add the following registry entry:
```
[HKEY_CURRENT_USER\SOFTWARE\Siemens\NX\UGII\Startup\NXCarbonAddon]
@="C:\\path\\to\\NXCarbonAddon.dll"
```

## Post-Installation Configuration

### Initial Setup
1. Launch NX after installation
2. The add-on will initialize and may prompt for API key configuration
3. If using OpenAI features, enter your API key when prompted
4. The add-on will validate the API key and save securely

### Menu Integration
The add-on integrates into NX with:
- New menu items under "Tools" or "Manufacturing" menu
- Toolbar buttons for quick access
- Ribbon panel in CAM environment

## Configuration Files

### User Configuration
- Location: `%APPDATA%\Siemens\NX_Carbon_Addon\user_config.json`
- Contains user preferences and settings
- Does not contain API keys (for security)

### Secure Configuration
- Location: `%APPDATA%\Siemens\NX_Carbon_Addon\secure_config.json` (encrypted)
- Contains API keys and sensitive information
- Protected with appropriate file permissions

## First Run

### Initial Setup Dialog
On first run, you may see:
1. Welcome screen explaining the add-on
2. API key configuration prompt (if OpenAI features are desired)
3. Settings configuration options

### Main Interface
After initialization, access the main functionality through:
- Menu: Tools → NX Carbon Emission Calculator
- Toolbar: Carbon Emission Calculator icon
- Command: `carbon_calc` in NX command line

## Troubleshooting

### Add-On Not Loading
- Verify NX is closed before copying DLL
- Check file permissions on the DLL
- Verify NX version compatibility
- Check Windows Event Log for errors

### API Key Issues
- Verify API key format (should start with "sk-")
- Check API key permissions in OpenAI dashboard
- Ensure network connectivity to OpenAI API
- Verify firewall settings allow HTTPS to api.openai.com

### NX Compatibility Issues
- Verify minimum NX version (12.0+ required)
- Ensure CAM module is licensed and installed
- Check for conflicting add-ons

### Performance Issues
- Large CAM operations may take longer to process
- AI features require network connectivity
- Consider using local models for offline operation

## Enterprise Deployment

### Group Policy Installation
For enterprise environments:
1. Use MSI installer (if provided)
2. Deploy via Active Directory Group Policy
3. Configure centralized settings management
4. Implement security policies for API key management

### Network Considerations
- OpenAI API requires HTTPS access to api.openai.com
- Consider proxy configuration if required
- Plan for API usage costs in enterprise environment

## Uninstallation

### Manual Removal
1. Close NX
2. Delete `NXCarbonAddon.dll` from startup directory
3. Remove registry entries if created
4. Delete configuration files if desired:
   - `%APPDATA%\Siemens\NX_Carbon_Addon\`
   - `%PROGRAMDATA%\Siemens\NX\CarbonAddon\` (if exists)

### Verify Removal
- Restart NX
- Confirm menu items and toolbar buttons are gone
- Check that no errors appear in NX startup

## Support

For technical support:
- Check the FAQ in the documentation
- Contact your NX administrator
- Visit the project repository for updates
- Open an issue for bugs or feature requests