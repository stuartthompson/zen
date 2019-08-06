#include "../../inc/command/command.h"

#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

Command::Command(const std::string& command, const std::vector<std::string>& arguments) :
    command_(command), arguments_(arguments)
{
    // Check for verbose mode
    if (isUnarySwitchPresent(Command::VerboseSwitch))
    {
        std::cout << *this;
    }

    // Load configuration
    this->loadConfiguration();
}

std::ostream& operator<< (std::ostream& os, const Command& h)
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

bool Command::loadConfiguration()
{
    // TODO: Move to static const on command
    const std::string SWITCH_CONFIG_FILE_PATH = "-f";

    // Look for a -f argument (specifies custom project configuration file path)
    this->configFilePath_ = findSwitchValue(SWITCH_CONFIG_FILE_PATH);

    // Set a default if no build file path was specified
    if (this->configFilePath_ == "")
    {
        this->configFilePath_ = ".zenconfig";
    }

    this->config_.loadConfig(this->configFilePath_);
}

std::string Command::findSwitchValue(const std::string& s) const
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

bool Command::isUnarySwitchPresent(const std::string& s) const
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

std::string Command::exec(const char* cmd) const {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

const std::string Command::VerboseSwitch = "-v";