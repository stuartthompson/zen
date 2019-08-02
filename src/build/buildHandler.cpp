#include <iostream>

#include "../../inc/build/buildHandler.h"

BuildHandler::BuildHandler(const std::vector<std::string>& arguments) :
    arguments_(arguments) 
{
    // Emit arguments (TODO: Remove when no longer useful)
    std::cout << "Args: " << std::endl;
    for (std::vector<std::string>::const_iterator i = this->arguments_.begin(); i != this->arguments_.end(); ++i) 
    {
        std::cout << *i << std::endl;
    }

    // Look for a -f argument with associated build file path


    // Look for a .zbuild file

}

