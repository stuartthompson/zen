#include "../../inc/config/config.h"
#include "../../inc/config/cppBuildConfig.h"

bool Config::loadConfig(const std::string& configFilePath)
{
    // TODO: Support different language types
    CppBuildConfig buildConfig = CppBuildConfig();
    buildConfig.loadBuildConfig(configFilePath);

    this->buildConfig_ = buildConfig;
}

CppBuildConfig Config::getBuildConfig() const
{
    return this->buildConfig_;
}