#ifndef NX_CAM_DATA_EXTRACTOR_H
#define NX_CAM_DATA_EXTRACTOR_H

#include <string>
#include <vector>

/**
 * @brief Represents a machining operation extracted from NX CAM
 */
class NXOperation {
private:
    std::string operationType;
    double cuttingTime;     // minutes
    double feedRate;        // mm/min
    double spindleSpeed;    // RPM
    double toolDiameter;    // mm

public:
    NXOperation(const std::string& type, double time, double feed, double spindle, double diameter);
    
    std::string getOperationType() const;
    double getCuttingTime() const;
    double getFeedRate() const;
    double getSpindleSpeed() const;
    double getToolDiameter() const;
};

/**
 * @brief Class to extract data from NX CAM using NX Open API
 * 
 * This class simulates the extraction of machining data from NX CAM,
 * including cutting time, operation list, tool information, and process parameters.
 */
class NXCamDataExtractor {
public:
    NXCamDataExtractor();
    ~NXCamDataExtractor();
    
    /**
     * @brief Extract operation list from NX CAM
     * @return Vector of NXOperation objects
     */
    std::vector<NXOperation> extractOperations();
    
    /**
     * @brief Extract tool information from NX CAM
     * @return Tool information as string
     */
    std::string extractToolInfo();
    
    /**
     * @brief Extract process parameters from NX CAM
     * @return Process parameters as string
     */
    std::string extractProcessParameters();
    
    /**
     * @brief Get total cutting time from all operations
     * @return Total cutting time in minutes
     */
    double getTotalCuttingTime();
};

#endif // NX_CAM_DATA_EXTRACTOR_H