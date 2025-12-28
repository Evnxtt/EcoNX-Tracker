#include "AIInterface.h"
#include <iostream>

AIInterface::AIInterface() : aiEnabled(false), useOpenAI(false), modelPath(""), openAIModel("gpt-3.5-turbo") {
    std::cout << "AIInterface initialized (AI integration disabled by default)" << std::endl;
}

AIInterface::~AIInterface() {
    std::cout << "AIInterface destroyed" << std::endl;
}

void AIInterface::setEnabled(bool enabled) {
    aiEnabled = enabled;
    std::cout << "AI integration " << (enabled ? "enabled" : "disabled") << std::endl;
}

bool AIInterface::isEnabled() const {
    return aiEnabled;
}

void AIInterface::setUseOpenAI(bool enabled) {
    useOpenAI = enabled;
    std::cout << "OpenAI API usage " << (enabled ? "enabled" : "disabled") << std::endl;
}

bool AIInterface::isUsingOpenAI() const {
    return useOpenAI;
}

void AIInterface::setOpenAIApiKey(const std::string& apiKey) {
    openAIApiKey = apiKey;
    std::cout << "OpenAI API key set" << std::endl;
}

void AIInterface::setOpenAIOrganization(const std::string& orgId) {
    openAIOrganization = orgId;
    std::cout << "OpenAI organization ID set" << std::endl;
}

void AIInterface::setOpenAIModel(const std::string& model) {
    openAIModel = model;
    std::cout << "OpenAI model set to: " << model << std::endl;
}

double AIInterface::predictCuttingPower(const std::string& material,
                                      double toolDiameter,
                                      double spindleSpeed,
                                      double feedRate,
                                      double depthOfCut,
                                      const std::string& operationType,
                                      const std::string& machineType) {
    if (!aiEnabled) {
        // If AI is disabled, return a default value or use a simple heuristic
        std::cout << "AI disabled - using heuristic to estimate cutting power" << std::endl;
        // Simple heuristic based on material and operation type
        double basePower = 3.0; // Base power in kW

        // Adjust based on material hardness (simplified)
        if (material.find("Steel") != std::string::npos || material.find("steel") != std::string::npos) {
            basePower *= 1.5;
        } else if (material.find("Ti") != std::string::npos || material.find("titanium") != std::string::npos) {
            basePower *= 1.8;
        } else if (material.find("Al") != std::string::npos || material.find("aluminum") != std::string::npos) {
            basePower *= 0.8;
        }

        // Adjust based on operation type
        if (operationType.find("Milling") != std::string::npos || operationType.find("milling") != std::string::npos) {
            basePower *= 1.1;
        } else if (operationType.find("Drilling") != std::string::npos || operationType.find("drilling") != std::string::npos) {
            basePower *= 0.9;
        }

        std::cout << "Heuristic estimated cutting power: " << basePower << " kW" << std::endl;
        return basePower;
    }

    if (useOpenAI && !openAIApiKey.empty()) {
        // Use OpenAI API for prediction
        return predictCuttingPowerWithOpenAI(material, toolDiameter, spindleSpeed,
                                           feedRate, depthOfCut, operationType, machineType);
    } else {
        // In a real implementation, this would call an actual local ML model
        // For this example, we'll simulate a prediction based on the input parameters
        std::cout << "Local AI prediction for material: " << material
                  << ", tool diameter: " << toolDiameter
                  << "mm, spindle: " << spindleSpeed
                  << "RPM, feed: " << feedRate
                  << "mm/min" << std::endl;

        // Simulate AI prediction (in a real implementation, this would use actual ML)
        double predictedPower = 2.0; // Base power

        // Factors based on input parameters
        if (material.find("Steel") != std::string::npos) predictedPower += 2.0;
        else if (material.find("Al") != std::string::npos) predictedPower += 0.5;
        else predictedPower += 1.0; // default for other materials

        // Tool diameter effect (larger tools generally need more power)
        predictedPower += (toolDiameter / 10.0) * 0.2;

        // Spindle speed effect (higher speeds may require more power)
        predictedPower += (spindleSpeed / 10000.0) * 0.5;

        // Feed rate effect
        predictedPower += (feedRate / 1000.0) * 0.3;

        // Depth of cut effect
        predictedPower += depthOfCut * 0.4;

        // Operation type effect
        if (operationType.find("Milling") != std::string::npos) predictedPower += 0.5;
        else if (operationType.find("Drilling") != std::string::npos) predictedPower -= 0.2;

        std::cout << "Local AI predicted cutting power: " << predictedPower << " kW" << std::endl;
        return predictedPower;
    }
}

double AIInterface::predictCuttingPowerWithOpenAI(const std::string& material,
                                                 double toolDiameter,
                                                 double spindleSpeed,
                                                 double feedRate,
                                                 double depthOfCut,
                                                 const std::string& operationType,
                                                 const std::string& machineType) {
    std::cout << "Calling OpenAI API for cutting power prediction..." << std::endl;

    // In a real implementation, this would make an HTTP request to the OpenAI API
    // For this example, we'll simulate the API call and response
    std::cout << "OpenAI request: material=" << material
              << ", tool_diameter=" << toolDiameter
              << "mm, spindle=" << spindleSpeed
              << "RPM, feed=" << feedRate
              << "mm/min, depth_of_cut=" << depthOfCut
              << "mm, operation=" << operationType
              << ", machine=" << machineType << std::endl;

    // This is where the actual API call would happen in a real implementation:
    /*
    // Example of what would happen in a real implementation:
    std::string apiUrl = "https://api.openai.com/v1/chat/completions";
    std::string apiKey = openAIApiKey;

    // Prepare the prompt for the API
    std::string prompt = "Based on machining parameters, predict cutting power in kW. ";
    prompt += "Material: " + material + ", ";
    prompt += "Tool Diameter: " + std::to_string(toolDiameter) + "mm, ";
    prompt += "Spindle Speed: " + std::to_string(spindleSpeed) + "RPM, ";
    prompt += "Feed Rate: " + std::to_string(feedRate) + "mm/min, ";
    prompt += "Depth of Cut: " + std::to_string(depthOfCut) + "mm, ";
    prompt += "Operation Type: " + operationType + ", ";
    prompt += "Machine Type: " + machineType + ". ";
    prompt += "Provide only the numerical value in kW.";

    // Create JSON payload
    json request = {
        {"model", openAIModel},
        {"messages", json::array({
            {{"role", "system"}, {"content", "You are an expert in CNC machining and energy consumption. Predict cutting power based on machining parameters."}},
            {{"role", "user"}, {"content", prompt}}
        })},
        {"temperature", 0.2}
    };

    // Make HTTP request to OpenAI API
    // ... (HTTP request code would go here)
    */

    // For this example, simulate a prediction based on the input parameters
    // In reality, this would come from the OpenAI API response
    double predictedPower = 2.0; // Base power

    // Factors based on input parameters (similar to local model but potentially more refined)
    if (material.find("Steel") != std::string::npos) predictedPower += 2.2;
    else if (material.find("Ti") != std::string::npos) predictedPower += 2.5;
    else if (material.find("Al") != std::string::npos) predictedPower += 0.6;
    else predictedPower += 1.1; // default for other materials

    // Tool diameter effect (larger tools generally need more power)
    predictedPower += (toolDiameter / 10.0) * 0.22;

    // Spindle speed effect (higher speeds may require more power)
    predictedPower += (spindleSpeed / 10000.0) * 0.55;

    // Feed rate effect
    predictedPower += (feedRate / 1000.0) * 0.33;

    // Depth of cut effect
    predictedPower += depthOfCut * 0.44;

    // Operation type effect
    if (operationType.find("Milling") != std::string::npos) predictedPower += 0.55;
    else if (operationType.find("Drilling") != std::string::npos) predictedPower -= 0.15;

    std::cout << "OpenAI predicted cutting power: " << predictedPower << " kW" << std::endl;
    return predictedPower;
}

void AIInterface::loadModel(const std::string& path) {
    modelPath = path;
    std::cout << "ML model loaded from: " << path << std::endl;
}

void AIInterface::trainModel(const std::string& dataPath) {
    std::cout << "Training ML model with data from: " << dataPath << std::endl;
    // In a real implementation, this would train the model with the provided data
}

void AIInterface::calibrateModel(double actualPower, double predictedPower) {
    std::cout << "Calibrating model: actual=" << actualPower << "kW, predicted=" << predictedPower << "kW" << std::endl;
    // In a real implementation, this would adjust the model based on the difference
}

const std::string& AIInterface::getModelPath() const {
    return modelPath;
}

const std::string& AIInterface::getOpenAIModel() const {
    return openAIModel;
}