#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "../inc/build/buildCommand.h"
#include "../inc/git/gitCommand.h"
#include "../inc/regex/regexCommand.h"

using json = nlohmann::json;

int main(int argc, char *argv[])
{
    // Verify that a root command group was specified
    if (argc == 1)
    {
        // TODO: Abstract into usage provider
        std::cout << "Usage: zen [command]" << std::endl;
        return -1;
    }

    // Get command name
    std::string commandName = argv[1];

    // Convert remaining arguments to vector
    std::vector<std::string> args;
    for (int i = 2; i <= argc - 1; i++) {
        args.push_back(argv[i]);
    }
     
    // Find command handler
    if (commandName == "build")
    {
        bool result = BuildCommand(commandName, args).execute();;
    }

    if (commandName == "git")
    {
        bool result = GitCommand(commandName, args).execute();;
    }

    if (commandName == "regex")
    {
        RegexCommand(commandName, args).execute();
    }

    return 0;
}