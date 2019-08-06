#include <iostream>
#include <string>
#include <sstream>

#include "../../inc/build/buildCommand.h"
#include "../../inc/config/cppBuildConfig.h"
#include "../../inc/command/command.h"

BuildCommand::BuildCommand(const std::string& command, const std::vector<std::string>& arguments) :
    Command(command, arguments) 
{
    const std::string SWITCH_VERBOSE = "-v";

    // Check for -v (verbose) unary switch
    bool verboseMode = isUnarySwitchPresent(SWITCH_VERBOSE);
}

bool BuildCommand::execute()
{
    CppBuildConfig buildConfig = this->config_.getBuildConfig();

    // Get the build parameters
    std::string inc = buildConfig.getIncludeDirectives();
    std::string src = buildConfig.getSourceFileList();
    std::string lib = buildConfig.getLibraryDirectives();

    // Construct build command
    std::stringstream ss;
    ss << buildConfig.getCompiler() << " ";
    ss << buildConfig.getSourceFileList();
    ss << buildConfig.getIncludeDirectives();
    ss << buildConfig.getLibraryDirectives();
    ss << buildConfig.getOutputDirective() << " ";
    ss << buildConfig.getCflags();

    std::string command = ss.str();

    // Create build dir
    this->exec("mkdir build");

    // Execute the build
    std::cout << command << std::endl;

    std::string output = this->exec(command.c_str());

    std::cout << "Result: " << output << std::endl;

    // TODO: Check build status
    return true;
}
