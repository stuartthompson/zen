#include <iostream>
#include <string>

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
    std::string buildFilePath = findSwitchValue(SWITCH_FILE_PATH);
    // Set a default if no build file path was specified
    if (buildFilePath == "")
    {
        buildFilePath = ".zbuild";
    }
    
    std::cout << "Verbose mode: " << verboseMode << std::endl;
    std::cout << "Build file path: " << buildFilePath << std::endl;

    CppBuildDefinition buildDef = CppBuildDefinition(buildFilePath);

    // Parse the build file
    std::string inc = buildDef.getIncludeDirectives();
    std::string src = buildDef.getSourceFileList();
    std::string src = buildDef.getLibraryDirectives();
}

