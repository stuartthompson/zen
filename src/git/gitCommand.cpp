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

    // TODO: Check status of command
    return true;
}

std::vector<std::string> GitCommand::pruneRemotes() const
{
    std::string pruneResult = this->exec("git remote prune origin");
    std::cout << pruneResult << std::endl;
    
    // TODO: Clean this up. There is a lot that can be optimized/refactored here.

    // Split result into separate lines
    std::vector<std::string> lines;
    std::regex pattern(R"(\n)");
    std::copy(std::sregex_token_iterator(pruneResult.begin(), pruneResult.end(), pattern, -1),
        std::sregex_token_iterator(),back_inserter(lines));

    // This regex attempts to match anything following a closing ] and a space
    // The git remote prune origin command returns lines such as * [pruned] origin/branchName
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
    // TODO: Abstract regex facilities into a separate method or class
    // This regex should put the branch name without the preceeding origin/ into the second match
    std::string regex = R"(^.*[/](.*)$))";
    std::regex r(regex);

    std::cout << "Branches to delete:" << std::endl;
    for (std::vector<std::string>::const_iterator i = branches.begin(); i != branches.end(); ++i)
    {
        std::smatch matches;
        std::regex_search(*i, matches, r);

        if (matches.size() == 2)
        {
            // Delete the local branch
            std::cout << "Deleting branch: " << matches[1] << std::endl;
            // Build command
            std::stringstream ss;
            ss << "git branch -d " << matches[1];
            this->exec(ss.str().c_str());
        }
    }
}