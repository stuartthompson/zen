#include <iostream>
#include <regex>
#include <sstream>

#include "../../inc/git/gitCommand.h"

GitCommand::GitCommand(const std::string& command, const std::vector<std::string>& arguments) :
    Command(command, arguments)
{   
}

bool GitCommand::execute()
{
    // Git command only works with sub-commands
    if (this->arguments_.size() == 0)
    {
        std::cerr << "zen git requires a sub-command." << std::endl;
        std::cout << "Usage: zen git [sub-command]" << std::endl;
    }

    // Determine the sub-command
    std::string subCommand = this->arguments_[0];
    if (subCommand == "prune")
    {
        std::vector<std::string> branches = this->pruneRemotes();
        this->deleteLocalBranches(branches);
    }
}

std::vector<std::string> GitCommand::pruneRemotes() const
{
    // std::string result = this->exec("git remote prune origin");
    // std::cout << result << std::endl;
    
    std::stringstream ss;
    ss << "Pruning origin" << std::endl;
    ss << "URL: git@github.com:stuartthompson/zen.git" << std::endl;
    ss << " * [pruned] origin/build" << std::endl;
    ss << " * [pruned] origin/git" << std::endl;
    std::string result = ss.str();

    // TODO: Clean this up. There is a lot that can be optimized/refactored here.

    // Split result into separate lines
    std::vector<std::string> lines;
    std::regex pattern(R"(\n)");
    std::copy(std::sregex_token_iterator(result.begin(), result.end(), pattern, -1),
        std::sregex_token_iterator(),back_inserter(lines));

    // This regex attempts to match anything following a closing ] and a space
    std::string regex = R"([\]] (.*)$)";

    // List of pruned branches
    std::vector<std::string> prunedBranches;

    // Search each line for matches
    for (std::vector<std::string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    {
        std::string line = *i;
        std::cout << "Testing line: " << line << std::endl;
    
        std::regex r(regex);
        std::smatch matches;
        std::regex_search(line, matches, r);

        if (matches.size() == 2)
        {
            prunedBranches.push_back(matches[1]);
        }
    }

    return prunedBranches; 
}

void GitCommand::deleteLocalBranches(const std::vector<std::string>& branches) const
{
    std::cout << "Branches to delete:" << std::endl;
    for (std::vector<std::string>::const_iterator i = branches.begin(); i != branches.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
}