#ifndef AI_INTERFACE_H
#define AI_INTERFACE_H

#include <string>

/**
 * @brief Class to interface with AI/ML models for predicting cutting power
 *
 * This class provides an interface to AI models that can predict cutting power
 * based on machining parameters, potentially improving prediction accuracy.
 * Supports both local ML models and cloud-based models like OpenAI.
 */
class AIInterface {
private:
    bool aiEnabled;              // Whether AI integration is enabled
    bool useOpenAI;              // Whether to use OpenAI API instead of local model
    std::string modelPath;       // Path to the local ML model file
    std::string openAIApiKey;    // OpenAI API key
    std::string openAIOrganization; // OpenAI organization ID (optional)
    std::string openAIModel;     // OpenAI model to use (e.g., "gpt-3.5-turbo", "gpt-4")

public:
    AIInterface();
    ~AIInterface();

    /**
     * @brief Enable or disable AI integration
     * @param enabled Whether to enable AI integration
     */
    void setEnabled(bool enabled);

    /**
     * @brief Check if AI integration is enabled
     * @return True if AI integration is enabled, false otherwise
     */
    bool isEnabled() const;

    /**
     * @brief Enable or disable OpenAI API usage
     * @param enabled Whether to use OpenAI API
     */
    void setUseOpenAI(bool enabled);

    /**
     * @brief Check if OpenAI API usage is enabled
     * @return True if OpenAI API is enabled, false otherwise
     */
    bool isUsingOpenAI() const;

    /**
     * @brief Set the OpenAI API key
     * @param apiKey The OpenAI API key
     */
    void setOpenAIApiKey(const std::string& apiKey);

    /**
     * @brief Set the OpenAI organization ID (optional)
     * @param orgId The OpenAI organization ID
     */
    void setOpenAIOrganization(const std::string& orgId);

    /**
     * @brief Set the OpenAI model to use
     * @param model The OpenAI model name (e.g., "gpt-3.5-turbo")
     */
    void setOpenAIModel(const std::string& model);

    /**
     * @brief Predict cutting power using AI based on machining parameters
     * @param material Type of material being machined
     * @param toolDiameter Tool diameter in mm
     * @param spindleSpeed Spindle speed in RPM
     * @param feedRate Feed rate in mm/min
     * @param depthOfCut Depth of cut in mm
     * @param operationType Type of operation (milling, drilling, etc.)
     * @param machineType Type of machine
     * @return Predicted cutting power in kW
     */
    double predictCuttingPower(const std::string& material,
                              double toolDiameter,
                              double spindleSpeed,
                              double feedRate,
                              double depthOfCut,
                              const std::string& operationType,
                              const std::string& machineType);

    /**
     * @brief Predict cutting power using OpenAI API
     * @param material Type of material being machined
     * @param toolDiameter Tool diameter in mm
     * @param spindleSpeed Spindle speed in RPM
     * @param feedRate Feed rate in mm/min
     * @param depthOfCut Depth of cut in mm
     * @param operationType Type of operation (milling, drilling, etc.)
     * @param machineType Type of machine
     * @return Predicted cutting power in kW
     */
    double predictCuttingPowerWithOpenAI(const std::string& material,
                                        double toolDiameter,
                                        double spindleSpeed,
                                        double feedRate,
                                        double depthOfCut,
                                        const std::string& operationType,
                                        const std::string& machineType);

    /**
     * @brief Load an ML model from file
     * @param path Path to the model file
     */
    void loadModel(const std::string& path);

    /**
     * @brief Train the AI model with new data
     * @param dataPath Path to training data file
     */
    void trainModel(const std::string& dataPath);

    /**
     * @brief Calibrate the model with actual measured data
     * @param actualPower Actual measured cutting power in kW
     * @param predictedPower Previously predicted cutting power in kW
     */
    void calibrateModel(double actualPower, double predictedPower);

    /**
     * @brief Get the path to the current ML model
     * @return Path to the ML model file
     */
    const std::string& getModelPath() const;

    /**
     * @brief Get the OpenAI model name
     * @return OpenAI model name
     */
    const std::string& getOpenAIModel() const;
};

#endif // AI_INTERFACE_H