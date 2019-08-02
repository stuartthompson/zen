#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "../../inc/build/cppBuildDefinition.h"

using json = nlohmann::json;

const std::string DEFAULT_OUTPUT_TYPE = "program";
const std::string DEFAULT_COMPILER = "g++";
const std::string DEFAULT_CFLAGS = "-std=c++17";

CppBuildDefinition::CppBuildDefinition(const std::string& filePath)
{   
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
        if (buildDefJson.count("outputType") != 0)
        {
            this->outputType_ = buildDefJson.at("outputType").get<std::string>();
        }
        else
        {
            this->outputType_ = DEFAULT_OUTPUT_TYPE;
            std::cout << "Output type specified. Using default value: " << DEFAULT_OUTPUT_TYPE << std::endl;
        }
        if (buildDefJson.count("compiler") != 0)
        {
            this->compiler_ = buildDefJson.at("compiler").get<std::string>();
        }
        else
        {
            buildDefJson["compiler"] = DEFAULT_COMPILER;
            std::cout << "Compiler not specified. Using default value: " << DEFAULT_COMPILER << std::endl;
        }
        if (buildDefJson.count("cflags") != 0)
        {
            this->cflags_ = buildDefJson.at("cflags").get<std::string>();
        }
        else
        {
            buildDefJson["cflags"] = "-std=c++17";
            std::cout << "Compiler not specified. Using default value: " << DEFAULT_CFLAGS << std::endl;
        }
        if (buildDefJson.count("includes") != 0)
        {
            this->includes_ = buildDefJson.at("includes").get<std::vector<std::string>>();
        }
        if (buildDefJson.count("sources") != 0)
        {
            this->sources_ = buildDefJson.at("sources").get<std::vector<std::string>>();
        }
        if (buildDefJson.count("libraries") != 0)
        {
            this->libraries_ = buildDefJson.at("libraries").get<std::vector<std::string>>();
        }
    }
    catch (const json::exception& e)
    {
        std::cerr << "An error occurred parsing the build definition file: " << filePath << std::endl;
        std::cerr << "Error message: " << e.what() << std::endl;        
    }

    std::cout << "Parsed build definition file: " << std::endl << *this << std::endl;
}

std::ostream& operator<< (std::ostream& os, const CppBuildDefinition& def)
{
    os << "Output type: " << def.outputType_ << std::endl;
    os << "Compiler: " << def.compiler_ << std::endl;
    os << "Cflags: " << def.cflags_ << std::endl;
    os << "Includes: ";
    for (std::vector<std::string>::const_iterator i = def.includes_.begin(); i != def.includes_.end(); ++i) os << *i;
    os << std::endl;
    os << "Sources: ";
    for (std::vector<std::string>::const_iterator i = def.sources_.begin(); i != def.sources_.end(); ++i) os << *i;
    os << std::endl;
    os << "Libraries: ";
    for (std::vector<std::string>::const_iterator i = def.libraries_.begin(); i != def.libraries_.end(); ++i) os << *i;
    os << std::endl;
    return os;
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

const std::vector<std::string> CppBuildDefinition::getIncludes() const
{
    return this->includes_;
}

const std::vector<std::string> CppBuildDefinition::getSources() const
{
    return this->sources_;
}

const std::vector<std::string> CppBuildDefinition::getLibraries() const
{
    return this->libraries_;
}