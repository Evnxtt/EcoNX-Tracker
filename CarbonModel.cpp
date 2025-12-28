#include "CarbonModel.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

CarbonModel::CarbonModel() {
    std::cout << "CarbonModel initialized" << std::endl;
}

CarbonModel::~CarbonModel() {
    std::cout << "CarbonModel destroyed" << std::endl;
}

double CarbonModel::calculateCarbonEmission(double energy, double emissionFactor) {
    double carbonEmission = energy * emissionFactor;
    std::cout << "Calculated carbon emission: " << carbonEmission << " kg CO2 (energy: " 
              << energy << " kWh, factor: " << emissionFactor << " kg CO2/kWh)" << std::endl;
    return carbonEmission;
}

double CarbonModel::getEmissionFactorForCountry(const std::string& country) {
    // Map of country codes/names to emission factors (kg CO2/kWh)
    // These are approximate values based on real-world data
    std::map<std::string, double> countryFactors = {
        {"US", 0.475}, {"USA", 0.475}, {"United States", 0.475},
        {"CN", 0.704}, {"China", 0.704},
        {"IN", 0.707}, {"India", 0.707},
        {"DE", 0.318}, {"Germany", 0.318},
        {"FR", 0.059}, {"France", 0.059},
        {"JP", 0.503}, {"Japan", 0.503},
        {"GB", 0.285}, {"UK", 0.285}, {"United Kingdom", 0.285},
        {"BR", 0.116}, {"Brazil", 0.116},
        {"CA", 0.129}, {"Canada", 0.129},
        {"AU", 0.798}, {"Australia", 0.798},
        {"EU", 0.299}, {"European Union", 0.299}
    };
    
    // Convert country string to uppercase for case-insensitive comparison
    std::string upperCountry = country;
    std::transform(upperCountry.begin(), upperCountry.end(), upperCountry.begin(), ::toupper);
    
    auto it = countryFactors.find(upperCountry);
    if (it != countryFactors.end()) {
        std::cout << "Emission factor for " << country << ": " << it->second << " kg CO2/kWh" << std::endl;
        return it->second;
    }
    
    // If country not found, return a default value (world average)
    std::cout << "Country " << country << " not found, using default emission factor: 0.475 kg CO2/kWh" << std::endl;
    return 0.475; // World average
}

double CarbonModel::getEmissionFactorForGridType(const std::string& gridType) {
    // Map of grid types to emission factors (kg CO2/kWh)
    std::map<std::string, double> gridFactors = {
        {"coal", 0.95},
        {"gas", 0.47},
        {"oil", 0.82},
        {"renewable", 0.05}, // Average for solar, wind, hydro
        {"solar", 0.045},
        {"wind", 0.015},
        {"hydro", 0.02},
        {"nuclear", 0.012},
        {"mixed", 0.475} // Mixed grid average
    };
    
    // Convert grid type string to lowercase for case-insensitive comparison
    std::string lowerGridType = gridType;
    std::transform(lowerGridType.begin(), lowerGridType.end(), lowerGridType.begin(), ::tolower);
    
    auto it = gridFactors.find(lowerGridType);
    if (it != gridFactors.end()) {
        std::cout << "Emission factor for " << gridType << " grid: " << it->second << " kg CO2/kWh" << std::endl;
        return it->second;
    }
    
    // If grid type not found, return a default value
    std::cout << "Grid type " << gridType << " not found, using default emission factor: 0.475 kg CO2/kWh" << std::endl;
    return 0.475; // Default
}

double CarbonModel::calculateCarbonPerOperation(double operationEnergy, double emissionFactor) {
    double carbon = operationEnergy * emissionFactor;
    std::cout << "Calculated carbon per operation: " << carbon << " kg CO2" << std::endl;
    return carbon;
}

double CarbonModel::calculateCarbonPerPart(double totalEnergy, double emissionFactor) {
    double carbon = totalEnergy * emissionFactor;
    std::cout << "Calculated carbon per part: " << carbon << " kg CO2" << std::endl;
    return carbon;
}