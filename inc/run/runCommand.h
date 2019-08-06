#pragma once

#include <string>
#include <vector>

#include "../command/command.h"

class RunCommand : public Command
{
public:
    RunCommand(const std::string& commandName, const std::vector<std::string>& arguments);

    bool execute() const;
};