# Troubleshooting Guide: NX Carbon Emission Add-On

## Overview
This guide provides solutions to common issues encountered when installing and using the NX Carbon Emission Add-On in Siemens NX. Use this guide to diagnose and resolve problems with your add-on installation.

## Common Installation Issues

### Issue 1: Add-On Does Not Load
**Symptoms**: 
- No new menu items appear in NX
- No loading messages in Information Window
- Add-on not listed in Customize → Add-ons

**Solutions**:
1. **Verify DLL Location**:
   - Ensure `NXCarbonAddon.dll` is in the correct startup directory
   - For all users: `C:\Program Files\Siemens\NX\UGII\startup\`
   - For current user: `%UGII_USER_DIR%\startup\`

2. **Check File Permissions**:
   - Right-click DLL → Properties → Security
   - Ensure NX user has Read & Execute permissions
   - If not, add permissions as Administrator

3. **Verify NX Version Compatibility**:
   - Check that your NX version is 12.0 or higher
   - Verify CAM module is installed and licensed
   - Ensure NX Open API libraries are available

4. **Check NX Log Files**:
   - Look for error messages in NX log files
   - Log files are typically in `%UGII_USER_DIR%\simplivity\`
   - Look for "ufusr" or "add-on" related errors

### Issue 2: DLL Load Error
**Symptoms**:
- Error message about unable to load DLL
- Missing dependencies error
- Crash on NX startup

**Solutions**:
1. **Check Dependencies**:
   - Use Dependency Walker or similar tool
   - Verify all required DLLs are available
   - Ensure Visual C++ Redistributables are installed

2. **Architecture Mismatch**:
   - Ensure DLL is built for 64-bit (NX is 64-bit)
   - Verify build configuration matches NX architecture

3. **Missing NX Libraries**:
   - Ensure NX installation directory is properly set
   - Verify UGII environment variables are set

### Issue 3: API Key Not Working
**Symptoms**:
- AI features not functioning
- Error messages about invalid API key
- Fallback to local models only

**Solutions**:
1. **Verify API Key Format**:
   - OpenAI API keys start with "sk-"
   - Ensure no extra spaces or characters
   - Verify the key is not expired

2. **Check Storage Location**:
   - Verify registry entry: `HKEY_CURRENT_USER\SOFTWARE\Siemens\NX\CarbonAddon\APIKey`
   - Check secure config file: `%APPDATA%\Siemens\NX_Carbon_Addon\secure_config.json`

3. **Network Connectivity**:
   - Verify internet connectivity
   - Check firewall settings for access to api.openai.com
   - Verify proxy settings if applicable

## Functionality Issues

### Issue 4: Calculations Not Working
**Symptoms**:
- No results when running carbon calculations
- Error messages during calculation
- Unexpected calculation results

**Solutions**:
1. **Verify CAM Data Access**:
   - Ensure CAM operations exist in the current part
   - Verify NX session has active CAM data
   - Check that required NX CAM licenses are available

2. **Check Input Parameters**:
   - Verify operation data is properly extracted
   - Check that all required parameters are available
   - Ensure NX session is in CAM environment

3. **Model Configuration**:
   - Verify default power values are set correctly
   - Check regional emission factors are configured
   - Ensure time modeling parameters are appropriate

### Issue 5: Performance Issues
**Symptoms**:
- NX runs slowly after add-on installation
- Long delays when accessing add-on features
- High CPU or memory usage

**Solutions**:
1. **Disable Add-On Temporarily**:
   - Remove DLL from startup directory
   - Restart NX to confirm performance returns to normal
   - Reinstall if performance is acceptable without add-on

2. **Check for Conflicts**:
   - Disable other add-ons to identify conflicts
   - Check for multiple instances of similar functionality
   - Verify no infinite loops in code

3. **Optimize Configuration**:
   - Reduce frequency of API calls if using OpenAI features
   - Implement caching for repeated calculations
   - Optimize data extraction for large operations

## Advanced Troubleshooting

### Issue 6: Registry Problems
**Symptoms**:
- Cannot save API key to registry
- Registry settings not persisting
- Access denied errors when writing to registry

**Solutions**:
1. **Run as Administrator**:
   - Ensure registry modifications are done with admin privileges
   - Run Registry Editor as Administrator

2. **Check Group Policy**:
   - Verify no group policies restrict registry access
   - Check with IT administrator for enterprise restrictions

3. **Alternative Storage**:
   - Use secure config file instead of registry
   - Implement environment variable approach

### Issue 7: Network and Security Issues
**Symptoms**:
- OpenAI API calls fail
- Security warnings about network access
- Corporate firewall blocking access

**Solutions**:
1. **Firewall Configuration**:
   - Allow NX process access to internet
   - Configure firewall for HTTPS access to api.openai.com
   - Check for corporate proxy requirements

2. **Security Software**:
   - Add NX and add-on to antivirus exceptions
   - Configure security software to allow API calls
   - Verify no security policies block external access

3. **Corporate Network**:
   - Configure proxy settings if required
   - Verify corporate policies allow external API access
   - Work with IT to establish approved access methods

## Debugging Steps

### Enable Debug Logging
1. **Add Debug Output**:
   - Add `UF_print_message` calls in your code
   - Log key events and parameters
   - Output to NX Information Window

2. **Check NX Log Files**:
   - Monitor log files in `%UGII_USER_DIR%\simplivity\`
   - Look for error messages and warnings
   - Check timestamps around when issues occur

### Use NX Development Tools
1. **NX Open API Error Checking**:
   - Always check return values from NX API calls
   - Use `UF_get_fail_message` for detailed error information
   - Implement proper error handling

2. **Debug Build**:
   - Build with debug symbols
   - Use debugging tools to trace execution
   - Check for memory leaks or invalid operations

## Enterprise Deployment Issues

### Issue 8: Multi-User Problems
**Symptoms**:
- Works for admin user but not regular users
- Permissions issues in corporate environment
- Configuration not applying to all users

**Solutions**:
1. **User Permissions**:
   - Verify all users have appropriate file permissions
   - Use Group Policy to deploy settings consistently
   - Check UAC settings that might affect access

2. **Centralized Configuration**:
   - Deploy via Group Policy or similar system
   - Use network shares for configuration files
   - Implement roaming profile support

### Issue 9: License and Compatibility Issues
**Symptoms**:
- Works on some machines but not others
- NX license restrictions affecting add-on
- Different behavior across NX versions

**Solutions**:
1. **License Verification**:
   - Ensure CAM license is available on all machines
   - Check for add-on specific license requirements
   - Verify license server connectivity

2. **Version Compatibility**:
   - Test on all target NX versions
   - Implement version-specific code paths if needed
   - Maintain backward compatibility where possible

## Quick Fixes

### Immediate Solutions to Try
1. **Restart NX completely** - Close all sessions and reopen
2. **Verify file locations** - Double-check DLL placement
3. **Check permissions** - Ensure proper access rights
4. **Validate API key** - Confirm format and validity
5. **Review log files** - Look for specific error messages
6. **Test in safe mode** - Disable other add-ons temporarily
7. **Rebuild the solution** - Ensure no compilation errors
8. **Verify prerequisites** - Check all dependencies are installed

## Support Information

### When to Seek Help
Contact support or development team when:
- Issues persist after trying all troubleshooting steps
- Error messages indicate internal add-on problems
- Security restrictions prevent normal operation
- Enterprise policies conflict with add-on requirements

### Information to Provide
When reporting issues, include:
- NX version and build number
- Operating system version
- Error messages (exact text)
- Steps to reproduce the issue
- Log file contents
- Network and security environment details
- Any recent system changes

## Prevention Tips

### Best Practices to Avoid Issues
1. **Always backup** NX configuration before installing add-ons
2. **Test in non-production** environment first
3. **Verify all prerequisites** before installation
4. **Document installation** process for your environment
5. **Monitor API usage** to avoid unexpected costs
6. **Keep add-on updated** with latest releases
7. **Maintain security** by following best practices for API keys
8. **Plan for compatibility** when upgrading NX versions

## Conclusion

This troubleshooting guide covers the most common issues with the NX Carbon Emission Add-On. If problems persist after following these steps, consult the detailed documentation or contact technical support with specific error information and system details.