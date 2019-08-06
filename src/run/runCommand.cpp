#include <fstream>
#include <iostream>
#include <sstream>

#include "../../inc/run/runCommand.h"

RunCommand::RunCommand(const std::string& command, const std::vector<std::string>& arguments) :
    Command(command, arguments)
{
}

bool RunCommand::execute() const
{
    // Parse project config
    // TODO: Check for -f flag (this should probably move to base)
    std::ifstream fs(".zbuild");

    if (!fs.good()) {
        std::cerr << "Unable to open project config file." << std::endl;
        return false;
    }

    // TODO: Verify that this project builds a program

    // TODO: Check if a build is needed

    // Output name
    std::string outputName = "zen";

    // Construct run command
    std::stringstream ss;
    ss << "./build/" << outputName;

    std::string command = ss.str();

    std::cout << command << std::endl;

    // Run the build output
    std::cout << this->exec(command.c_str());
}