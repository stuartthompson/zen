#pragma once

#include <string>

class BuildSource
{
public:
    /**
     * Resolves the file paths to the source files that this source represents.
     * 
     * @return A vector of files paths that this source resolves to.
     */
    std::vector<const std::string> const resolveSourcePaths() const;

private:
    std::string sourceFilePattern;
};