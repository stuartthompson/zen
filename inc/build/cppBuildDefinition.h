#pragma once

#include <ostream>
#include <string>
#include <vector>

class CppBuildDefinition 
{
public:
    /**
     * Initializes a new c++ build definition.
     * 
     * @param filePath The file path of the build definition file.
     */
    CppBuildDefinition(const std::string& buildDefFileName);

    /**
     * Copy constructor.
     */
    CppBuildDefinition(const CppBuildDefinition& definition);

    friend std::ostream& operator<<(std::ostream& os, const CppBuildDefinition& def);

    const std::string getCompiler() const;
    const std::string getCflags() const;
    const std::string getOutputType() const;
    const std::vector<std::string> getIncludes() const;
    const std::vector<std::string> getSources() const;
    const std::vector<std::string> getLibraries() const;

private:
    std::string compiler_;
    std::string cflags_;
    std::string outputType_;
    std::vector<std::string> includes_;
    std::vector<std::string> sources_;
    std::vector<std::string> libraries_;
};
