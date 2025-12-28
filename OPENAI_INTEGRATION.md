# Using OpenAI API with NX CNC Carbon Emission Add-on

This document explains how to integrate and use OpenAI API with the NX CNC Carbon Emission Add-on for improved cutting power predictions.

## Overview

The add-on includes an AIInterface class that can utilize OpenAI's API to make more accurate predictions of cutting power based on machining parameters. This provides a more sophisticated alternative to the local heuristic model.

## Setup

### 1. Get an OpenAI API Key

1. Visit [OpenAI Platform](https://platform.openai.com/)
2. Create an account or log in
3. Navigate to the API keys section
4. Create a new secret key
5. Save the key securely

### 2. Configure the Application

The application can be configured to use OpenAI API in several ways:

#### Method 1: Direct Configuration in Code
```cpp
AIInterface aiInterface;
aiInterface.setEnabled(true);
aiInterface.setUseOpenAI(true);
aiInterface.setOpenAIApiKey("your-api-key-here");
aiInterface.setOpenAIModel("gpt-3.5-turbo"); // or "gpt-4" for more accuracy
```

#### Method 2: Environment Variable (Recommended)
Set the API key as an environment variable:
```bash
export OPENAI_API_KEY="your-api-key-here"
```

#### Method 3: Configuration File
Update the `config.json` file:
```json
{
  "ai_interface": {
    "enabled": true,
    "use_openai": true,
    "openai_model": "gpt-3.5-turbo",
    "model_path": "",
    "training_data_path": "datasets/machining_power.csv"
  }
}
```

## Usage

### Basic Usage
```cpp
AIInterface aiInterface;

// Enable AI and OpenAI API
aiInterface.setEnabled(true);
aiInterface.setUseOpenAI(true);
aiInterface.setOpenAIApiKey("your-api-key-here");

// Make a prediction
double predictedPower = aiInterface.predictCuttingPower(
    "Steel_S45C",    // material
    12.0,            // tool diameter (mm)
    6000,            // spindle speed (RPM)
    800,             // feed rate (mm/min)
    2.5,             // depth of cut (mm)
    "Milling",       // operation type
    "5axis_VMC"      // machine type
);
```

### API Implementation Details

In a real implementation, the OpenAI API call would work as follows:

1. **Request Preparation**: The machining parameters are formatted into a prompt for the OpenAI API
2. **API Call**: An HTTP request is made to `https://api.openai.com/v1/chat/completions`
3. **Response Processing**: The API response is parsed to extract the predicted cutting power value
4. **Integration**: The predicted power is used in the energy and carbon calculations

The actual implementation would require:
- An HTTP client library (like libcurl)
- A JSON library (like nlohmann/json) for request/response handling
- Proper error handling for API failures

## Configuration Options

### OpenAI Models
- `gpt-3.5-turbo`: Good balance of speed and accuracy (recommended)
- `gpt-4`: Higher accuracy but slower and more expensive
- `gpt-4-turbo`: Latest model with improved performance

### Parameters
- `temperature`: Controls randomness (0.0-1.0, lower = more deterministic)
- `max_tokens`: Maximum tokens in response (affects response length)

## Security Considerations

1. **Never commit API keys** to version control
2. Use environment variables or secure configuration management
3. Implement proper error handling to avoid exposing API keys in logs
4. Consider using OpenAI's organization and project features for access control

## Cost Management

OpenAI API usage incurs costs based on token usage. Consider:
- Monitoring API usage through the OpenAI dashboard
- Implementing caching for repeated predictions
- Using appropriate model based on accuracy needs vs. cost

## Fallback Mechanism

If OpenAI API is unavailable or disabled, the system falls back to:
1. Local machine learning model (if available)
2. Heuristic-based prediction algorithm

## Example Prompt Engineering

The system constructs prompts like:
```
"Based on machining parameters, predict cutting power in kW. 
Material: Steel_S45C, Tool Diameter: 12.0mm, Spindle Speed: 6000RPM, 
Feed Rate: 800mm/min, Depth of Cut: 2.5mm, Operation Type: Milling, 
Machine Type: 5axis_VMC. Provide only the numerical value in kW."
```

This specific prompt structure helps ensure consistent, numerical responses that can be easily parsed.