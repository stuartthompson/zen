#pragma once

#include <string>
#include "cppBuildConfig.h"

class Config
{
public:
    /**
     * Loads project configuration from config file.
     * 
     * @return True if the configuration loaded successfully, false otherwise.
     */
    bool loadConfig(const std::string& configFilePath);

    CppBuildConfig getBuildConfig() const;

private:
    std::string configFilePath_;
    CppBuildConfig buildConfig_;
};