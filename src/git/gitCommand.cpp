#include "../../inc/git/gitCommand.h"

GitCommand::GitCommand(const std::string& command, const std::vector<std::string>& arguments) :
    Command(command, arguments)
{
    
}

bool GitCommand::execute()
{
    
}