#pragma once

#include <string>
#include <vector>

#include "../config/cppBuildConfig.h" 
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
};
