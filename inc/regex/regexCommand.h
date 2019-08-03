#pragma once

#include <string>
#include <vector>

#include "../command/command.h"

class RegexCommand : public Command
{
public:
    RegexCommand(const std::string& command, const std::vector<std::string>& arguments);

    bool execute();
  
private:
    void handleMatchCommand() const;
    bool isMatch(const std::string& input, const std::string& regex) const;
};
