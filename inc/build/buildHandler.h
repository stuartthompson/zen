#pragma once

#include <string>
#include <vector>

#include "../build/cppBuildDefinition.h" 
#include "../commands/commandHandler.h"

class BuildHandler : public CommandHandler
{
public:
    BuildHandler(const std::string& commandName, const std::vector<std::string>& arguments);

    bool executeCommand();
    bool loadBuildDefinition();
    bool executeBuild() const;

private:
    std::string buildFilePath_;
    CppBuildDefinition buildDef_;
};
