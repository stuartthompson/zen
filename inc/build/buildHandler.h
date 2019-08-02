#pragma once

#include <string>
#include <vector>

#include "../commands/commandHandler.h"

class BuildHandler : public CommandHandler
{
public:
    BuildHandler(const std::vector<std::string>& arguments);

private:
    
};
