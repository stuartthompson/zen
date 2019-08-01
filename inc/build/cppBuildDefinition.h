#pragma once

#include <string>
#include <vector>

class CppBuildDefinition 
{
public:
    /**
     * Initializes a new c++ build definition.
     * 
     * @param definition The build definition to initialize from.
     */
    CppBuildDefinition(const std::string& definition);

    /**
     * Copy constructor.
     */
    CppBuildDefinition(const CppBuildDefinition& definition);

    const std::string getCompiler() const;

private:
    std::string compiler_;
    std::string cflags_;
    std::vector<std::string> includes_;
    std::vector<std::string> sources_;
};
