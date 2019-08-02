#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/stat.h>

#include <boost/filesystem.hpp>
#include <nlohmann/json.hpp>

#include "../../inc/build/cppBuildDefinition.h"

using json = nlohmann::json;

const std::string DEFAULT_OUTPUT_TYPE = "program";
const std::string DEFAULT_COMPILER = "g++";
const std::string DEFAULT_CFLAGS = "-std=c++17";

CppBuildDefinition::CppBuildDefinition(const std::string& filePath)
{   
    const std::string OutputTypeProperty = "outputType";
    const std::string CompilerProperty = "compiler";
    const std::string CflagsProperty = "cflags";
    const std::string IncludePathsProperty = "includePaths";
    const std::string SourcesProperty = "sources";
    const std::string LibraryPathsProperty = "libraryPaths";
    const std::string LibrariesProperty = "libraries";

    // Get file stream to build definition file
    std::ifstream fs(filePath.c_str());
    if (!fs.good())
    {
        std::cerr << "Unable to open build definition file: " << filePath << std::endl;
    }                 

    // Read build definition json from file stream
    json buildDefJson;
    fs >> buildDefJson;

    // Parse build definition build and provide default values as needed
    try 
    {
        // Output Type
        if (buildDefJson.count(OutputTypeProperty) != 0)
        {
            this->outputType_ = buildDefJson.at(OutputTypeProperty).get<std::string>();
        }
        else
        {
            this->outputType_ = DEFAULT_OUTPUT_TYPE;
            std::cout << "Output type specified. Using default value: " << DEFAULT_OUTPUT_TYPE << std::endl;
        }
        // Compiler
        if (buildDefJson.count(CompilerProperty) != 0)
        {
            this->compiler_ = buildDefJson.at(CompilerProperty).get<std::string>();
        }
        else
        {
            this->compiler_ = DEFAULT_COMPILER;
            std::cout << "Compiler not specified. Using default value: " << DEFAULT_COMPILER << std::endl;
        }
        // Cflags
        if (buildDefJson.count(CflagsProperty) != 0)
        {
            this->cflags_ = buildDefJson.at(CflagsProperty).get<std::string>();
        }
        else
        {
            this->cflags_ = DEFAULT_CFLAGS;
            std::cout << "Compiler not specified. Using default value: " << DEFAULT_CFLAGS << std::endl;
        }
        // Include paths
        if (buildDefJson.count(IncludePathsProperty) != 0)
        {
            this->includePaths_ = buildDefJson.at(IncludePathsProperty).get<std::vector<std::string>>();
        }
        // Sources
        if (buildDefJson.count(SourcesProperty) != 0)
        {
            this->sources_ = buildDefJson.at(SourcesProperty).get<std::vector<std::string>>();
        }
        // Library paths
        if (buildDefJson.count(LibraryPathsProperty) != 0)
        {
            this->libraryPaths_ = buildDefJson.at(LibraryPathsProperty).get<std::vector<std::string>>();
        }
        // Libraries
        if (buildDefJson.count(LibrariesProperty) != 0)
        {
            this->libraries_ = buildDefJson.at(LibrariesProperty).get<std::vector<std::string>>();
        }
    }
    catch (const json::exception& e)
    {
        std::cerr << "An error occurred parsing the build definition file: " << filePath << std::endl;
        std::cerr << "Error message: " << e.what() << std::endl;        
    }
}

std::ostream& operator<< (std::ostream& os, const CppBuildDefinition& def)
{
    os << "Output type: " << def.outputType_ << std::endl;
    os << "Compiler: " << def.compiler_ << std::endl;
    os << "Cflags: " << def.cflags_ << std::endl;
    os << "Includes: ";
    for (std::vector<std::string>::const_iterator i = def.includePaths_.begin(); i != def.includePaths_.end(); ++i) os << *i;
    os << std::endl;
    os << "Sources: ";
    for (std::vector<std::string>::const_iterator i = def.sources_.begin(); i != def.sources_.end(); ++i) os << *i;
    os << std::endl;
    os << "Libraries: ";
    for (std::vector<std::string>::const_iterator i = def.libraries_.begin(); i != def.libraries_.end(); ++i) os << *i;
    os << std::endl;
    return os;
}

const std::string CppBuildDefinition::getIncludeDirectives() const
{
    // Iterate the list of include paths
    std::stringstream ss;
    for (std::vector<std::string>::const_iterator i = this->includePaths_.begin(); i != this->includePaths_.end(); ++i)
    {
        ss << "-I" << *i << " ";
    }
    return ss.str();
}

const std::string CppBuildDefinition::getSourceFileList() const
{
    std::stringstream ss;
    for (std::vector<std::string>::const_iterator i = this->sources_.begin(); i != this->sources_.end(); ++i)
    {
        // Is this source a directory?
        std::string dir = *i;
        struct stat buf;
        stat(dir.c_str(), &buf);
        if (S_ISDIR(buf.st_mode)) {
            boost::filesystem::path p(dir);
            boost::filesystem::directory_iterator end_itr;

            // cycle through the directory
            for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr)
            {
                // If it's not a directory, list it. If you want to list directories too, just remove this check.
                if (is_regular_file(itr->path())) {
                    // assign current file name to current_file and echo it out to the console.
                    std::string file = itr->path().string();
                    ss << file << " ";
                }
            }
        }
    }
    return ss.str();
}

const std::string CppBuildDefinition::getLibraryDirectives() const
{
    std::stringstream ss;
    for (std::vector<std::string>::const_iterator i = this->libraryPaths_.begin(); i != this->libraryPaths_.end(); ++i)
    {
        ss << "-L" << *i << " ";
    }
    for (std::vector<std::string>::const_iterator i = this->libraries_.begin(); i != this->libraries_.end(); ++i)
    {
        ss << "-l" << *i << " ";
    }
    return ss.str();
}

const std::string CppBuildDefinition::getCompiler() const
{
    return this->compiler_;
}

const std::string CppBuildDefinition::getCflags() const
{
    return this->cflags_;
}

const std::string CppBuildDefinition::getOutputType() const
{
    return this->outputType_;
}

const std::vector<std::string> CppBuildDefinition::getIncludePaths() const
{
    return this->includePaths_;
}

const std::vector<std::string> CppBuildDefinition::getSources() const
{
    return this->sources_;
}

const std::vector<std::string> CppBuildDefinition::getLibraryPaths() const
{
    return this->libraryPaths_;
}

const std::vector<std::string> CppBuildDefinition::getLibraries() const
{
    return this->libraries_;
}