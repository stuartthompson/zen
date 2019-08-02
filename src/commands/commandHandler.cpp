#include "../../inc/commands/commandHandler.h"

#include <iostream>

CommandHandler::CommandHandler(const std::string& command, const std::vector<std::string>& arguments) :
    command_(command), arguments_(arguments)
{
    // Check for verbose mode
    if (isUnarySwitchPresent(CommandHandler::VerboseSwitch))
    {
        std::cout << *this;
    }
}

std::ostream& operator<< (std::ostream& os, const CommandHandler& h)
{
    // Emit command and list of arguments
    os << "Command: " << h.command_ << std::endl;
    os << "Arguments (Count: " << h.arguments_.size() << ")" << std::endl;
    for (int i = 0; i < h.arguments_.size(); i++)
    {
        os << "  [" << i+1 << "]: " << h.arguments_[i] << std::endl;
    }

    return os;
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

const std::string CommandHandler::VerboseSwitch = "-v";