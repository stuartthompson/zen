#pragma once

#include <string>
#include <vector>

#include "../command/command.h"

class GitCommand : public Command
{
public:
    GitCommand(const std::string& command, const std::vector<std::string>& arguments);

    bool execute();
  
private:
    /**
     * Prunes remote branches ('git remote prune origin') and returns the names of pruned branches.
     * 
     * @param prunedBranches A vector that will be populated with the list of pruned branches.
     * @return True if branches were pruned, false otherwise.
     */
    bool pruneRemotes(std::vector<std::string>& prunedBranches) const;

    /**
     * Deletes local branches.
     * 
     * @param branches The list of branches to delete.
     */
    void deleteLocalBranches(const std::vector<std::string>& branches) const;
};
