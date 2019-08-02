#pragma once

#include <string>
#include <vector>

class CommandHandler
{
public:
    /**
     * Initializes a new command handler.
     * 
     * @param command The name of the command being run.
     * @param arguments The list of arguments supplied to the command.
     */
    CommandHandler(const std::string& command, const std::vector<std::string>& arguments);

    /**
     * Writes the command to an output stream.
     * 
     * @param os The output stream to write to.
     * @param h The command handler.
     */
    friend std::ostream& operator<<(std::ostream& os, const CommandHandler& h);

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
    static const std::string VerboseSwitch;

    std::string command_;
    std::vector<std::string> arguments_;
};