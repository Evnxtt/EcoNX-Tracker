#include "NXCamDataExtractor.h"
#include "TimeModel.h"
#include "EnergyModel.h"
#include "CarbonModel.h"
#include "AIInterface.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

/**
 * @brief NX CNC Carbon Emission Add-on
 *
 * This program estimates energy consumption and carbon emissions
 * from CNC machining processes based on data extracted from NX CAM.
 *
 * Based on the project specification in project.md
 */
int main() {
    std::cout << "NX CNC Carbon Emission Add-on" << std::endl;
    std::cout << "===============================" << std::endl;

    // Read the project.md file to extract configuration or initial data
    std::ifstream projectFile("project.md");
    if (!projectFile.is_open()) {
        std::cout << "Warning: project.md not found in current directory." << std::endl;
    } else {
        std::cout << "Successfully read project.md file" << std::endl;
        projectFile.close();
    }

    // Initialize the core components
    NXCamDataExtractor extractor;
    TimeModel timeModel;
    EnergyModel energyModel;
    CarbonModel carbonModel;
    AIInterface aiInterface;

    std::cout << "\nInitializing NX CNC Carbon Emission Add-on..." << std::endl;

    // Example usage: Extract NX CAM data
    std::cout << "\nExtracting NX CAM data..." << std::endl;
    NXOperation operation1("Milling", 10.5, 1200, 8000, 10.0); // time, feed, spindle, diameter
    NXOperation operation2("Drilling", 5.2, 600, 5000, 8.0);

    std::vector<NXOperation> operations;
    operations.push_back(operation1);
    operations.push_back(operation2);

    std::cout << "Operations extracted: " << operations.size() << std::endl;

    // Example usage: Model time components
    std::cout << "\nModeling time components..." << std::endl;
    double totalCutTime = 0;
    for (const auto& op : operations) {
        totalCutTime += op.getCuttingTime();
    }

    double rapidTime = timeModel.estimateRapidTime(totalCutTime);
    double idleTime = timeModel.estimateIdleTime(operations.size());
    double totalTime = timeModel.calculateTotalTime(totalCutTime, rapidTime, idleTime);

    std::cout << "Total Cutting Time: " << totalCutTime << " min" << std::endl;
    std::cout << "Estimated Rapid Time: " << rapidTime << " min" << std::endl;
    std::cout << "Estimated Idle Time: " << idleTime << " min" << std::endl;
    std::cout << "Total Time: " << totalTime << " min" << std::endl;

    // Example usage: Calculate energy consumption
    std::cout << "\nCalculating energy consumption..." << std::endl;
    double cuttingPower = 5.0; // kW - could be predicted by AI model
    double rapidPower = 3.0;   // kW
    double idlePower = 1.0;    // kW

    double cuttingEnergy = energyModel.calculateCuttingEnergy(totalCutTime, cuttingPower);
    double rapidEnergy = energyModel.calculateRapidEnergy(rapidTime, rapidPower);
    double idleEnergy = energyModel.calculateIdleEnergy(idleTime, idlePower);
    double totalEnergy = energyModel.calculateTotalEnergy(cuttingEnergy, rapidEnergy, idleEnergy);

    std::cout << "Cutting Energy: " << cuttingEnergy << " kWh" << std::endl;
    std::cout << "Rapid Energy: " << rapidEnergy << " kWh" << std::endl;
    std::cout << "Idle Energy: " << idleEnergy << " kWh" << std::endl;
    std::cout << "Total Energy: " << totalEnergy << " kWh" << std::endl;

    // Example usage: Calculate carbon emissions
    std::cout << "\nCalculating carbon emissions..." << std::endl;
    double emissionFactor = 0.475; // kg CO2/kWh (US average)
    double carbonEmission = carbonModel.calculateCarbonEmission(totalEnergy, emissionFactor);

    std::cout << "Carbon Emission: " << carbonEmission << " kg CO2" << std::endl;

    // Example usage: AI integration (optional) - Local model
    std::cout << "\nTesting local AI interface..." << std::endl;
    aiInterface.setEnabled(true);
    double predictedPower = aiInterface.predictCuttingPower("Al6061", 10.0, 8000, 1200, 2.0, "Milling", "3axis_VMC");
    std::cout << "Local AI Predicted Cutting Power: " << predictedPower << " kW" << std::endl;

    // Example usage: OpenAI API integration
    std::cout << "\nTesting OpenAI API integration..." << std::endl;
    aiInterface.setUseOpenAI(true);
    aiInterface.setOpenAIApiKey("YOUR_OPENAI_API_KEY_HERE"); // In a real app, this would come from environment/config
    aiInterface.setOpenAIModel("gpt-3.5-turbo");

    // Note: In a real implementation, you would set the API key from an environment variable or config file
    // For this example, we'll show how it would work conceptually
    if (aiInterface.isEnabled() && aiInterface.isUsingOpenAI()) {
        std::cout << "OpenAI API integration enabled" << std::endl;
        std::cout << "Using model: " << aiInterface.getOpenAIModel() << std::endl;

        // This would make an actual API call in a real implementation
        double openAIPredictedPower = aiInterface.predictCuttingPower("Steel_S45C", 12.0, 6000, 800, 2.5, "Milling", "5axis_VMC");
        std::cout << "OpenAI Predicted Cutting Power: " << openAIPredictedPower << " kW" << std::endl;
    } else {
        std::cout << "OpenAI API key not set, using local model instead" << std::endl;
        double localPredictedPower = aiInterface.predictCuttingPower("Steel_S45C", 12.0, 6000, 800, 2.5, "Milling", "5axis_VMC");
        std::cout << "Local AI Predicted Cutting Power: " << localPredictedPower << " kW" << std::endl;
    }

    std::cout << "\nNX CNC Carbon Emission Add-on completed successfully!" << std::endl;

    return 0;
}