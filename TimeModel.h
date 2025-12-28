#ifndef TIME_MODEL_H
#define TIME_MODEL_H

/**
 * @brief Class to model time components in CNC machining
 * 
 * This class estimates rapid time and idle time based on cutting time and number of operations,
 * since NX CAM only provides cutting time directly.
 */
class TimeModel {
private:
    double rapidTimeFactor;    // Factor to estimate rapid time relative to cutting time
    double idleTimePerOp;      // Idle time per operation (setup + tool change)
    double setupTime;          // Fixed setup time per job

public:
    TimeModel();
    ~TimeModel();
    
    /**
     * @brief Estimate rapid time based on cutting time
     * @param cuttingTime Total cutting time in minutes
     * @return Estimated rapid time in minutes
     */
    double estimateRapidTime(double cuttingTime);
    
    /**
     * @brief Estimate idle time based on number of operations
     * @param numOperations Number of machining operations
     * @return Estimated idle time in minutes
     */
    double estimateIdleTime(int numOperations);
    
    /**
     * @brief Calculate total time as sum of all components
     * @param cuttingTime Cutting time in minutes
     * @param rapidTime Rapid time in minutes
     * @param idleTime Idle time in minutes
     * @return Total time in minutes
     */
    double calculateTotalTime(double cuttingTime, double rapidTime, double idleTime);
    
    /**
     * @brief Set the rapid time factor
     * @param factor Factor to estimate rapid time relative to cutting time
     */
    void setRapidTimeFactor(double factor);
    
    /**
     * @brief Set the idle time per operation
     * @param time Idle time per operation in minutes
     */
    void setIdleTimePerOp(double time);
    
    /**
     * @brief Set the setup time
     * @param time Setup time in minutes
     */
    void setSetupTime(double time);
};

#endif // TIME_MODEL_H