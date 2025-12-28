#ifndef CARBON_MODEL_H
#define CARBON_MODEL_H

#include <string>

/**
 * @brief Class to calculate carbon emissions based on energy consumption
 *
 * This class converts energy consumption to carbon emissions using regional electricity factors.
 */
class CarbonModel {
public:
    CarbonModel();
    ~CarbonModel();

    /**
     * @brief Calculate carbon emissions from energy consumption
     * @param energy Total energy consumption in kWh
     * @param emissionFactor Emission factor in kg CO2/kWh
     * @return Carbon emissions in kg CO2
     */
    double calculateCarbonEmission(double energy, double emissionFactor);

    /**
     * @brief Get emission factor for a specific country/region
     * @param country Country code or name
     * @return Emission factor in kg CO2/kWh
     */
    double getEmissionFactorForCountry(const std::string& country);

    /**
     * @brief Get emission factor for a specific grid type
     * @param gridType Grid type (e.g., "coal", "gas", "renewable", "mixed")
     * @return Emission factor in kg CO2/kWh
     */
    double getEmissionFactorForGridType(const std::string& gridType);

    /**
     * @brief Calculate carbon emissions per operation
     * @param operationEnergy Energy consumption of a single operation in kWh
     * @param emissionFactor Emission factor in kg CO2/kWh
     * @return Carbon emissions for the operation in kg CO2
     */
    double calculateCarbonPerOperation(double operationEnergy, double emissionFactor);

    /**
     * @brief Calculate carbon emissions per part
     * @param totalEnergy Total energy consumption for the part in kWh
     * @param emissionFactor Emission factor in kg CO2/kWh
     * @return Carbon emissions for the part in kg CO2
     */
    double calculateCarbonPerPart(double totalEnergy, double emissionFactor);
};

#endif // CARBON_MODEL_H