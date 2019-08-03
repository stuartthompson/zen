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
    std::string result = this->exec("git remote prune origin");
    std::cout << result << std::endl;
    
    // std::stringstream ss;
    // ss << "Pruning origin" << std::endl;
    // ss << "URL: git@github.com:stuartthompson/zen.git" << std::endl;
    // ss << " * [pruned] origin/build" << std::endl;
    // ss << " * [pruned] origin/git" << std::endl;
    // std::string res = ss.str();

    // Pruned matches
    //std::string matchStr = ".\\[pruned\\]\\s*([^\\n\\r]*)";

    //res = " * [pruned] origin/build";
    // std::string matchStr = R"#(
    //     (.*)\r\n
    // )#";

    // std::cout << "Testing matches for match string " << matchStr << " against " << std::endl << res << std::endl;

    // std::regex m(matchStr);
    // if (regex_match(res, m))
    // {
    //     std::cout << "Yeah, it matches.";        
    // }
    // else
    // {
    //     std::cout << "No match";
    // }
    

    // TODO: Actually return the pruned branches
    std::vector<std::string> prunedBranches;

    return prunedBranches; 
}

void GitCommand::deleteLocalBranches(const std::vector<std::string>& branches) const
{
    for (std::vector<std::string>::const_iterator i = branches.begin(); i != branches.end(); ++i)
    {

    }
}