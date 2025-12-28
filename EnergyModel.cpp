#include "EnergyModel.h"
#include <iostream>

EnergyModel::EnergyModel() 
    : cuttingPower(5.0), rapidPower(3.0), idlePower(1.0) {
    std::cout << "EnergyModel initialized with default power values" << std::endl;
    std::cout << "Cutting power: " << cuttingPower << " kW" << std::endl;
    std::cout << "Rapid power: " << rapidPower << " kW" << std::endl;
    std::cout << "Idle power: " << idlePower << " kW" << std::endl;
}

EnergyModel::~EnergyModel() {
    std::cout << "EnergyModel destroyed" << std::endl;
}

double EnergyModel::calculateCuttingEnergy(double cuttingTime, double power) {
    double p = (power >= 0) ? power : cuttingPower;
    double energy = (cuttingTime / 60.0) * p;  // Convert minutes to hours
    std::cout << "Calculated cutting energy: " << energy << " kWh (time: " << cuttingTime 
              << " min, power: " << p << " kW)" << std::endl;
    return energy;
}

double EnergyModel::calculateRapidEnergy(double rapidTime, double power) {
    double p = (power >= 0) ? power : rapidPower;
    double energy = (rapidTime / 60.0) * p;  // Convert minutes to hours
    std::cout << "Calculated rapid energy: " << energy << " kWh (time: " << rapidTime 
              << " min, power: " << p << " kW)" << std::endl;
    return energy;
}

double EnergyModel::calculateIdleEnergy(double idleTime, double power) {
    double p = (power >= 0) ? power : idlePower;
    double energy = (idleTime / 60.0) * p;  // Convert minutes to hours
    std::cout << "Calculated idle energy: " << energy << " kWh (time: " << idleTime 
              << " min, power: " << p << " kW)" << std::endl;
    return energy;
}

double EnergyModel::calculateTotalEnergy(double cuttingEnergy, double rapidEnergy, double idleEnergy) {
    double totalEnergy = cuttingEnergy + rapidEnergy + idleEnergy;
    std::cout << "Total energy calculated: " << totalEnergy << " kWh" << std::endl;
    return totalEnergy;
}

void EnergyModel::setCuttingPower(double power) {
    cuttingPower = power;
    std::cout << "Cutting power updated to: " << power << " kW" << std::endl;
}

void EnergyModel::setRapidPower(double power) {
    rapidPower = power;
    std::cout << "Rapid power updated to: " << power << " kW" << std::endl;
}

void EnergyModel::setIdlePower(double power) {
    idlePower = power;
    std::cout << "Idle power updated to: " << power << " kW" << std::endl;
}

double EnergyModel::getCuttingPower() const {
    return cuttingPower;
}

double EnergyModel::getRapidPower() const {
    return rapidPower;
}

double EnergyModel::getIdlePower() const {
    return idlePower;
}