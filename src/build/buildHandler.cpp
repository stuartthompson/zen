#include <iostream>
#include <string>
#include <sstream>

#include "../../inc/build/buildHandler.h"
#include "../../inc/build/cppBuildDefinition.h"
#include "../../inc/commands/commandHandler.h"

BuildHandler::BuildHandler(const std::string& command, const std::vector<std::string>& arguments) :
    CommandHandler(command, arguments) 
{
    const std::string SWITCH_VERBOSE = "-v";
    const std::string SWITCH_FILE_PATH = "-f";

    // Check for -v (verbose) unary switch
    bool verboseMode = isUnarySwitchPresent(SWITCH_VERBOSE);

    // Look for a -f argument with associated build file path
    this->buildFilePath_ = findSwitchValue(SWITCH_FILE_PATH);
    // Set a default if no build file path was specified
    if (this->buildFilePath_ == "")
    {
        this->buildFilePath_ = ".zbuild";
    }
    
    std::cout << "Verbose mode: " << verboseMode << std::endl;
    std::cout << "Build file path: " << this->buildFilePath_ << std::endl;
}

bool BuildHandler::executeCommand()
{
    bool ok = this->loadBuildDefinition();
    if (!ok)
    {
        return false;
    }

    // Return execution result
    return this->executeBuild();;
}

bool BuildHandler::loadBuildDefinition()
{
    bool ok = this->buildDef_.loadBuildDef(this->buildFilePath_);
    if (!ok)
    {
        std::cerr << "Problem loading build definition file." << std::endl;
    }

    if (!this->buildDef_.isValid())
    {
        std::cerr << "Build definition file is invalid." << std::endl;
        return false;
    }

    return true;
}

bool BuildHandler::executeBuild() const
{
    // Get the build parameters
    std::string inc = this->buildDef_.getIncludeDirectives();
    std::string src = this->buildDef_.getSourceFileList();
    std::string lib = this->buildDef_.getLibraryDirectives();

    // Construct build command
    std::stringstream ss;
    ss << this->buildDef_.getCompiler() << " ";
    ss << this->buildDef_.getSourceFileList();
    ss << this->buildDef_.getIncludeDirectives();
    ss << this->buildDef_.getLibraryDirectives();
    ss << this->buildDef_.getOutputDirective() << " ";
    ss << this->buildDef_.getCflags();

    std::string command = ss.str();

    // Execute the build
    std::cout << command << std::endl;

    std::string output = this->exec(command.c_str());

    std::cout << "Result: " << output << std::endl;
}