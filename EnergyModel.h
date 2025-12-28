#ifndef ENERGY_MODEL_H
#define ENERGY_MODEL_H

/**
 * @brief Class to model energy consumption in CNC machining
 * 
 * This class calculates energy consumption based on time components and machine-specific power profiles.
 */
class EnergyModel {
private:
    double cuttingPower;    // kW
    double rapidPower;      // kW
    double idlePower;       // kW

public:
    EnergyModel();
    ~EnergyModel();
    
    /**
     * @brief Calculate cutting energy consumption
     * @param cuttingTime Cutting time in minutes
     * @param power Cutting power in kW (default uses internal value)
     * @return Cutting energy in kWh
     */
    double calculateCuttingEnergy(double cuttingTime, double power = -1.0);
    
    /**
     * @brief Calculate rapid energy consumption
     * @param rapidTime Rapid time in minutes
     * @param power Rapid power in kW (default uses internal value)
     * @return Rapid energy in kWh
     */
    double calculateRapidEnergy(double rapidTime, double power = -1.0);
    
    /**
     * @brief Calculate idle energy consumption
     * @param idleTime Idle time in minutes
     * @param power Idle power in kW (default uses internal value)
     * @return Idle energy in kWh
     */
    double calculateIdleEnergy(double idleTime, double power = -1.0);
    
    /**
     * @brief Calculate total energy consumption
     * @param cuttingEnergy Cutting energy in kWh
     * @param rapidEnergy Rapid energy in kWh
     * @param idleEnergy Idle energy in kWh
     * @return Total energy in kWh
     */
    double calculateTotalEnergy(double cuttingEnergy, double rapidEnergy, double idleEnergy);
    
    /**
     * @brief Set the cutting power
     * @param power Cutting power in kW
     */
    void setCuttingPower(double power);
    
    /**
     * @brief Set the rapid power
     * @param power Rapid power in kW
     */
    void setRapidPower(double power);
    
    /**
     * @brief Set the idle power
     * @param power Idle power in kW
     */
    void setIdlePower(double power);
    
    /**
     * @brief Get the cutting power
     * @return Cutting power in kW
     */
    double getCuttingPower() const;
    
    /**
     * @brief Get the rapid power
     * @return Rapid power in kW
     */
    double getRapidPower() const;
    
    /**
     * @brief Get the idle power
     * @return Idle power in kW
     */
    double getIdlePower() const;
};

#endif // ENERGY_MODEL_H