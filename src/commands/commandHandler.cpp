#include "../../inc/commands/commandHandler.h"

#include <iostream>

CommandHandler::CommandHandler(const std::vector<std::string>& arguments) :
    arguments_(arguments)
{
    // Emit arguments (TODO: Remove when no longer useful)
    std::cout << "Args: " << arguments.size() << std::endl;
    for (std::vector<std::string>::const_iterator i = this->arguments_.begin(); i != this->arguments_.end(); ++i) 
    {
        std::cout << *i << std::endl;
    }

}

std::string CommandHandler::findSwitchValue(const std::string& s) const
{
    // Search for the switch
    for (std::vector<std::string>::const_iterator i = this->arguments_.begin(); i != this->arguments_.end(); ++i) 
    {
        if (*i == s) {
            if (i+1 != this->arguments_.end()) {
                return *(i+1);
            }
            else {
                return "";
            }
        }
    }

    // Return empty string if the requested switch was not found
    return "";
}

bool CommandHandler::isUnarySwitchPresent(const std::string& s) const
{
    for (std::vector<std::string>::const_iterator i = this->arguments_.begin(); i != this->arguments_.end(); ++i) 
    {
        if (*i == s)
        {
            // Switch found
            return true;
        }
    }

    // Switch not found
    return false;
}