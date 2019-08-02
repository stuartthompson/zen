#pragma once

#include <string>
#include <vector>

class CommandHandler
{
public:
    CommandHandler(const std::vector<std::string>& arguments);

    /**
     * Finds the value of a switch argument provided to the command.
     * 
     * Switch arguments come in pairs, one for the switch and the other for the value, i.e. -f .zbuild
     * 
     * @param s The switch name.
     * @return The switch value. Null if switch value was not provided.
     */
    std::string findSwitchValue(const std::string& s) const;

private:
    std::vector<std::string> arguments_;
};