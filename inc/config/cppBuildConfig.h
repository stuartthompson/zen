#pragma once

#include <ostream>
#include <string>
#include <vector>

class CppBuildConfig
{
public:
    /**
     * Initializes a new c++ build configuration.
     */
    CppBuildConfig();

    /**
     * Loads the build configuration file.
     * 
     * @param filePath The file path of the build definition file.
     */
    const bool loadBuildConfig(const std::string& configFilePath);

    /**
     * Builds the list of include directives to send to the compiler.
     * 
     * @return A string representing the include directives that will be provided to the compiler.
     */
    const std::string getIncludeDirectives() const;

    /**
     * Builds the list of source files.
     * 
     * @return A string representing the source files that will be provided to the compiler.
     */
    const std::string getSourceFileList() const;

    /**
     * Builds the list of library directives to send to the compiler.
     * 
     * @return A string representing the library directives that will be provided to the compiler.
     */
    const std::string getLibraryDirectives() const;

    /**
     * Gets the output directive to send to the compiler.
     * 
     * @return A string representing the output directive that will be provided to the compiler.
     */
    const std::string getOutputDirective() const;

    /**
     * Writes a build configuration to an output stream.
     * 
     * @param os The output stream to write to.
     * @param def The build definition to write.
     */
    friend std::ostream& operator<<(std::ostream& os, const CppBuildConfig& def);

    const std::string getBuildType() const;
    const std::string getCompiler() const;
    const std::string getCflags() const;
    const std::string getOutput() const;
    const std::vector<std::string> getIncludePaths() const;
    const std::vector<std::string> getSources() const;
    const std::vector<std::string> getLibraryPaths() const;
    const std::vector<std::string> getLibraries() const;
    const bool isValid() const;

private:
    std::string buildType_;
    std::string compiler_;
    std::string cflags_;
    std::string output_;
    std::vector<std::string> includePaths_;
    std::vector<std::string> sources_;
    std::vector<std::string> libraryPaths_;
    std::vector<std::string> libraries_;
    bool isValid_;
};
