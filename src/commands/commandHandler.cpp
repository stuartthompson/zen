#include "../../inc/commands/commandHandler.h"

CommandHandler::CommandHandler(const std::vector<std::string>& arguments) :
    arguments_(arguments)
{
}

std::string CommandHandler::findSwitchValue(const std::string& s) const
{
    for (std::vector<std::string>::const_iterator i = this->arguments_.begin(); i != this->arguments_.end(); ++i) 
    {
    }
}