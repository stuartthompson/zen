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
     * @param s The switch to find.
     * @return The switch value or an empty string if the switch value was not provided.
     */
    std::string findSwitchValue(const std::string& s) const;

    /**
     * Checks if a unary switch was provided.
     * 
     * Unary switches have no associated value. For example the -v switch is often provided to indicate verbose mode.
     * 
     * @param s The switch to check for.
     * @return True if the switch is present, false otherwise.
     */
    bool isUnarySwitchPresent(const std::string& s) const;

protected:
    std::vector<std::string> arguments_;
};