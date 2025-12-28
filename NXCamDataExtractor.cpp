#include "NXCamDataExtractor.h"
#include <iostream>

// NXOperation implementation
NXOperation::NXOperation(const std::string& type, double time, double feed, double spindle, double diameter)
    : operationType(type), cuttingTime(time), feedRate(feed), spindleSpeed(spindle), toolDiameter(diameter) {
}

std::string NXOperation::getOperationType() const {
    return operationType;
}

double NXOperation::getCuttingTime() const {
    return cuttingTime;
}

double NXOperation::getFeedRate() const {
    return feedRate;
}

double NXOperation::getSpindleSpeed() const {
    return spindleSpeed;
}

double NXOperation::getToolDiameter() const {
    return toolDiameter;
}

// NXCamDataExtractor implementation
NXCamDataExtractor::NXCamDataExtractor() {
    std::cout << "NXCamDataExtractor initialized" << std::endl;
}

NXCamDataExtractor::~NXCamDataExtractor() {
    std::cout << "NXCamDataExtractor destroyed" << std::endl;
}

std::vector<NXOperation> NXCamDataExtractor::extractOperations() {
    // In a real implementation, this would connect to NX CAM via NX Open API
    // For this example, we'll return a sample set of operations
    std::vector<NXOperation> operations;
    
    // Simulate extraction of operations from NX CAM
    operations.emplace_back("Rough Milling", 15.2, 1000, 7500, 12.0);
    operations.emplace_back("Finish Milling", 8.7, 800, 8000, 8.0);
    operations.emplace_back("Drilling", 3.4, 500, 4500, 6.0);
    
    std::cout << "Extracted " << operations.size() << " operations from NX CAM" << std::endl;
    return operations;
}

std::string NXCamDataExtractor::extractToolInfo() {
    // In a real implementation, this would extract tool information from NX CAM
    return "Tool information extracted from NX CAM";
}

std::string NXCamDataExtractor::extractProcessParameters() {
    // In a real implementation, this would extract process parameters from NX CAM
    return "Process parameters extracted from NX CAM";
}

double NXCamDataExtractor::getTotalCuttingTime() {
    // In a real implementation, this would calculate total cutting time from all operations
    // For this example, returning a sample value
    return 27.3; // minutes
}