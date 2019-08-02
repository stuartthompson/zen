#pragma once

#include <string>
#include <vector>

class BuildHandler
{
public:
    BuildHandler(const std::vector<std::string>& arguments);

private:
    std::vector<std::string> arguments_;
};
