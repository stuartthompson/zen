#include <nlohmann/json.hpp>
#include "../inc/build/cppBuildDefinition.h"

using json = nlohmann::json;

CppBuildDefinition::CppBuildDefinition(const std::string& definition)
{   
    // Deserialize the definition
    auto cppBuildDef = json::parse(definition);

    // TODO: Validate the deserialized values

    // Extract the properties
    this->compiler_ = cppBuildDef["compiler"];
}

const std::string CppBuildDefinition::getCompiler() const
{
    return this->compiler_;
}