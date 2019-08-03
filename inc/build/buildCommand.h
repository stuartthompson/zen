#pragma once

#include <string>
#include <vector>

#include "../build/cppBuildDefinition.h" 
#include "../command/command.h"

class BuildCommand : public Command
{
public:
    BuildCommand(const std::string& commandName, const std::vector<std::string>& arguments);

    /**
     * Executes the build command.
     * 
     * @return True if the command executed successfully, false otherwise.
     */
    bool execute();

    /**
     * Loads the build definition.
     * 
     * @return True if the build definition loaded successfully, false otherwise.
     */
    bool loadBuildDefinition();

    /**
     * Executes the build.
     * 
     * @return True if the build executed successfully, false otherwise.
     */
    bool runBuild() const;

private:
    std::string buildFilePath_;
    CppBuildDefinition buildDef_;
};
