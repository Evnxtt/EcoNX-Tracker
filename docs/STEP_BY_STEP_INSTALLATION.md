# Step-by-Step Installation Guide: NX Carbon Emission Add-On

## Overview
This guide provides detailed, step-by-step instructions for installing the NX Carbon Emission Add-On in Siemens NX. Follow these steps carefully to ensure successful installation.

## Prerequisites Check

### Before You Begin
- ✅ Ensure Siemens NX (version 12.0 or higher) is installed
- ✅ Ensure the CAM module is licensed and available
- ✅ Ensure you have administrator privileges on the machine
- ✅ Ensure Microsoft Visual C++ Redistributables are installed
- ✅ Have your built `NXCarbonAddon.dll` file ready
- ✅ Have your OpenAI API key ready (if using AI features)

## Step 1: Prepare Your System

### Close All NX Sessions
1. Close all instances of Siemens NX
2. Verify no NX processes are running in Task Manager
3. If necessary, restart your computer to ensure clean state

### Locate NX Installation Directory
1. Open Windows Explorer
2. Navigate to your NX installation directory (typically `C:\Program Files\Siemens\NX`)
3. Verify the `UGII\startup\` directory exists

## Step 2: Build the Add-On (If Building from Source)

### Using Visual Studio Command Prompt
1. Open **"Developer Command Prompt for VS"** as Administrator
2. Navigate to the project directory:
   ```
   cd C:\path\to\your\NXCarbonAddon_NX_Siemens
   ```
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

### Locate the Built DLL
1. After successful build, locate `NXCarbonAddon.dll` in:
   ```
   C:\path\to\your\NXCarbonAddon_NX_Siemens\build\Release\NXCarbonAddon.dll
   ```

## Step 3: Copy the DLL to NX Startup Directory

### Option A: For All Users (Recommended)
1. Open Windows Explorer as Administrator
2. Navigate to: `C:\Program Files\Siemens\NX\UGII\startup\`
3. Copy `NXCarbonAddon.dll` to this directory
4. If prompted for permissions, confirm to copy the file

### Option B: For Current User Only
1. Open Windows Explorer
2. Navigate to: `%APPDATA%\Siemens\NX[version]\startup\`
   (Replace [version] with your NX version, e.g., NX1946)
3. Copy `NXCarbonAddon.dll` to this directory

## Step 4: Verify File Permissions

### Check DLL Permissions
1. Right-click on `NXCarbonAddon.dll` in the startup directory
2. Select **Properties**
3. Go to **Security** tab
4. Ensure the user account running NX has **Read & Execute** permissions
5. If not, click **Edit** and add the necessary permissions

## Step 5: Launch NX and Verify Installation

### First Launch
1. Launch Siemens NX as the user who will use the add-on
2. Look for any loading messages in the Information Window
3. You should see a message like: "NX Carbon Emission Add-On initialized"

### Check Menu Integration
1. Look for new menu items under **Tools** or **Manufacturing**
2. Look for new toolbar buttons or ribbon panels
3. The add-on should appear in the **Customize** → **Add-ons** dialog

## Step 6: Configure API Key (If Using OpenAI Features)

### Automatic Configuration
1. If the add-on displays a configuration dialog, enter your OpenAI API key
2. The key should start with "sk-"
3. The add-on will validate and store the key securely

### Manual Configuration (If Automatic Doesn't Appear)
1. Press **Windows + R** to open Run dialog
2. Type `regedit` and press Enter
3. Navigate to: `HKEY_CURRENT_USER\SOFTWARE\Siemens\NX\CarbonAddon\`
4. If the key doesn't exist, create it:
   - Right-click on `NX` folder → **New** → **Key**
   - Name it `CarbonAddon`
5. Right-click on the `CarbonAddon` key → **New** → **String Value**
6. Name it `APIKey`
7. Double-click the `APIKey` value and enter your OpenAI API key
8. Click **OK**

## Step 7: Test the Installation

### Basic Functionality Test
1. Open a NX CAM file with operations
2. Access the carbon calculation feature through:
   - Menu: **Tools** → **NX Carbon Emission Calculator**
   - Or toolbar button if available
3. Verify calculations work with sample operations

### API Integration Test (If Configured)
1. If you configured OpenAI API key, test the AI prediction features
2. Compare AI predictions with local model predictions
3. Verify network connectivity to OpenAI API

## Step 8: Troubleshooting Common Issues

### Add-On Not Loading
- **Symptom**: No menu items appear, no loading messages
- **Solution**: 
  1. Verify DLL is in correct startup directory
  2. Check file permissions
  3. Verify NX version compatibility
  4. Check Windows Event Log for errors

### API Key Issues
- **Symptom**: AI features not working
- **Solution**:
  1. Verify API key format (starts with "sk-")
  2. Check API key permissions in OpenAI dashboard
  3. Verify network connectivity
  4. Check firewall settings

### Performance Issues
- **Symptom**: NX runs slowly after installation
- **Solution**:
  1. Disable add-on temporarily to verify
  2. Check for conflicts with other add-ons
  3. Verify system meets requirements

## Step 9: Enterprise Deployment (For IT Administrators)

### Group Policy Deployment
1. Create a Group Policy Object (GPO)
2. Configure file deployment to copy DLL to NX startup directory
3. Configure registry settings for API keys if needed
4. Link GPO to appropriate Organizational Units

### Network Share Installation
1. Place DLL on network share accessible to all users
2. Create login script to copy DLL to local NX startup directory
3. Configure centralized configuration management

## Step 10: Verification Checklist

Complete this checklist to ensure successful installation:

- [ ] NXCarbonAddon.dll is in the correct startup directory
- [ ] NX loads without errors
- [ ] Add-on menu items appear in NX
- [ ] Basic functionality tests pass
- [ ] API key (if configured) is stored securely
- [ ] AI features (if configured) work properly
- [ ] No performance degradation in NX
- [ ] Add-on appears in NX Customize → Add-ons dialog

## Next Steps

### After Successful Installation
1. Configure your API key if using OpenAI features
2. Test with your actual CAM projects
3. Configure user permissions if needed
4. Set up monitoring for API usage costs
5. Document the installation for your organization

### Optional Configurations
1. Customize default calculation parameters
2. Configure regional emission factors
3. Set up automated reporting
4. Configure integration with your PLM system

## Support Information

If you encounter issues not covered in this guide:
- Check the project documentation
- Verify system requirements are met
- Contact your NX administrator
- Review NX log files for error details
- Check Windows Event Log for system errors

Congratulations! You have successfully installed the NX Carbon Emission Add-On in Siemens NX.