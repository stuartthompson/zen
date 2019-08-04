#include <iostream>
#include <regex>
#include <sstream>

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

    // TODO: Check status of command
    return true;
}

std::vector<std::string> splitter(std::string in_pattern, std::string& content){
    std::vector<std::string> split_content;

    std::regex pattern(in_pattern);
    std::copy( std::sregex_token_iterator(content.begin(), content.end(), pattern, -1),
    std::sregex_token_iterator(),back_inserter(split_content));  
    return split_content;
}

void RegexCommand::handleMatchCommand() const
{
    if (this->arguments_.size() < 3)
    {
        std::cerr << "zen regex match requires two arguments." << std::endl;
        std::cout << "Usage: zen regex match [input] [regex]" << std::endl;
        return;
    }

    // TODO: Figure out what to do here. Hacked this. Got tired. Leaving it for now.

    // std::string input = this->arguments_[1];
    // std::string regex = this->arguments_[2];

    std::stringstream ss;
    ss << "Pruning origin" << std::endl;
    ss << "URL: git@github.com:stuartthompson/zen.git" << std::endl;
    ss << " * [pruned] origin/build" << std::endl;
    ss << " * [pruned] origin/git" << std::endl;
    std::string input = ss.str();

    std::string regex = R"([\]] (.*)$)";

    // Split the input into separate lines
    std::vector<std::string> lines = splitter(R"(\n)", input);

    for (std::vector<std::string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    {
        std::string line = *i;
        std::cout << "Testing line: " << line << std::endl;

        // Get matches for this line
        this->getMatches(line, regex);
    }
}

void RegexCommand::getMatches(const std::string& input, const std::string& regex) const
{
    // TEST: ./zen regex match " * [pruned]: t" "^ \* \[pruned\]: {1}(t|d){1}\n?$"

    std::regex r(regex);
    std::smatch matches;

    std::regex_search(input, matches, r);

    std::cout << "Found " << matches.size() << " matches." << std::endl;
    for (std::size_t n = 0; n < matches.size(); ++n)
    {
        std::cout << " m" << n << ": " << matches[n] << std::endl;
    }
}