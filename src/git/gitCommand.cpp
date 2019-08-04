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
        std::vector<std::string> prunedBranches;
        bool result = this->pruneRemotes(prunedBranches);
        if (result)
        {
            this->deleteLocalBranches(prunedBranches);
        }
    }

    // TODO: Check status of command
    return true;
}

bool GitCommand::pruneRemotes(std::vector<std::string>& prunedBranches) const
{
    // Execute git remote prune origin
    std::string pruneResult = this->exec("git remote prune origin");
    
    // Split result into separate lines (we're going to skip the first two)
    std::vector<std::string> lines;
    std::regex pattern(R"(\n)");
    std::copy(std::sregex_token_iterator(pruneResult.begin(), pruneResult.end(), pattern, -1),
        std::sregex_token_iterator(),back_inserter(lines));

    // Check to see that any branches were pruned
    if (lines.size() <= 2)
    {
        std::cout << "No remote branches were pruned." << std::endl;
        return false;
    }

    // This regex matches characters following / (which should be the branch name)
    // The git remote prune origin command returns lines such as * [pruned] origin/branchName
    std::string regex = R"(.*/(.*)$)";
    std::regex r(regex);

    // Build list of pruned branches
    for (int i = 2; i <= lines.size(); i++)
    {
        std::smatch matches;
        std::string line = lines[i];
        std::regex_search(line, matches, r);
        if (matches.size() == 2)
        {
            // Push branch name onto list
            prunedBranches.push_back(matches[1]);
        }
    }
    
    return true; 
}

void GitCommand::deleteLocalBranches(const std::vector<std::string>& branches) const
{
    std::cout << "The following local branches will be deleted:" << std::endl;
    for (std::vector<std::string>::const_iterator i = branches.begin(); i != branches.end(); ++i)
    {
        std::cout << " * " << *i << std::endl;
    }

    std::cout << "Press [Y]es to continue or [N]o to cancel." << std::endl;

    char response;
    std::cin.get(response);

    if (response == 'Y' || response == 'y')
    {
        for (std::vector<std::string>::const_iterator i = branches.begin(); i != branches.end(); ++i)
        {
            // Build the command
            std::stringstream ss;
            ss << "git branch -d " << *i;
            std::string delCmd = ss.str();
            std::cout << delCmd << std::endl; 
            this->exec(delCmd.c_str());
        }    
    }
}