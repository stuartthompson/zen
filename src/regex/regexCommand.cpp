#include <iostream>
#include <regex>

#include "../../inc/regex/regexCommand.h"

RegexCommand::RegexCommand(const std::string& command, const std::vector<std::string>& arguments) :
    Command(command, arguments)
{   
}

bool RegexCommand::execute()
{
    // Git command only works with sub-commands
    if (this->arguments_.size() == 0)
    {
        std::cerr << "zen regex requires a sub-command." << std::endl;
        std::cout << "Usage: zen regex [sub-command]" << std::endl;
        return false;
    }

    // Determine the sub-command
    std::string subCommand = this->arguments_[0];
    if (subCommand == "match")
    {
        this->handleMatchCommand();
    }
}

void RegexCommand::handleMatchCommand() const
{
    if (this->arguments_.size() < 3)
    {
        std::cerr << "zen regex match requires two arguments." << std::endl;
        std::cout << "Usage: zen regex match [input] [regex]" << std::endl;
        return;
    }

    std::string input = this->arguments_[1];
    std::string regex = this->arguments_[2];
    bool isMatch = this->isMatch(input, regex);

    // std::cout <<  (isMatch ? "Match" : "No Match") << std::endl;
}

bool RegexCommand::isMatch(const std::string& input, const std::string& regex) const
{
    std::string re = R"#(
        (\[pruned\]:) (.*)[^\n]$
    )#";

    std::smatch m;
    std::regex_search(input, m, std::regex(re));
    if(m.empty()) {
        std::cout << "input=[" << input << "], regex=[" << regex << "]: NO MATCH\n";
    } else {
        std::cout << "input=[" << input << "], regex=[" << regex << "]: ";
        std::cout << "prefix=[" << m.prefix() << "] ";
        for(std::size_t n = 0; n < m.size(); ++n)
            std::cout << " m[" << n << "]=[" << m[n] << "] ";
        std::cout << "suffix=[" << m.suffix() << "]\n";
    }

    return false;
    // std::regex r(regex);
    // return (regex_match(input, r));
}