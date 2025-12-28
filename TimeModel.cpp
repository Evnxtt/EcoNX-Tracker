#include "TimeModel.h"
#include <iostream>

TimeModel::TimeModel() 
    : rapidTimeFactor(0.3), idleTimePerOp(2.0), setupTime(10.0) {
    std::cout << "TimeModel initialized with default parameters" << std::endl;
    std::cout << "Rapid time factor: " << rapidTimeFactor << std::endl;
    std::cout << "Idle time per operation: " << idleTimePerOp << " min" << std::endl;
    std::cout << "Setup time: " << setupTime << " min" << std::endl;
}

TimeModel::~TimeModel() {
    std::cout << "TimeModel destroyed" << std::endl;
}

double TimeModel::estimateRapidTime(double cuttingTime) {
    // Rapid time estimation based on cutting time
    // This is a simplified model - in reality, this would be more complex
    double estimatedRapidTime = cuttingTime * rapidTimeFactor;
    std::cout << "Estimated rapid time: " << estimatedRapidTime << " min (factor: " << rapidTimeFactor << ")" << std::endl;
    return estimatedRapidTime;
}

double TimeModel::estimateIdleTime(int numOperations) {
    // Idle time estimation based on number of operations
    // Includes setup time and tool change time
    double estimatedIdleTime = setupTime + (numOperations * idleTimePerOp);
    std::cout << "Estimated idle time: " << estimatedIdleTime << " min (setup: " << setupTime 
              << ", per op: " << idleTimePerOp << ", num ops: " << numOperations << ")" << std::endl;
    return estimatedIdleTime;
}

double TimeModel::calculateTotalTime(double cuttingTime, double rapidTime, double idleTime) {
    double totalTime = cuttingTime + rapidTime + idleTime;
    std::cout << "Total time calculated: " << totalTime << " min" << std::endl;
    return totalTime;
}

void TimeModel::setRapidTimeFactor(double factor) {
    rapidTimeFactor = factor;
    std::cout << "Rapid time factor updated to: " << factor << std::endl;
}

void TimeModel::setIdleTimePerOp(double time) {
    idleTimePerOp = time;
    std::cout << "Idle time per operation updated to: " << time << " min" << std::endl;
}

void TimeModel::setSetupTime(double time) {
    setupTime = time;
    std::cout << "Setup time updated to: " << time << " min" << std::endl;
}