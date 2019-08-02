#include <fstream>
#include <iostream>
#include <string>

#include <cxxtest/TestSuite.h>
#include <nlohmann/json.hpp>

#include "../../inc/build/cppBuildDefinition.h"

using json = nlohmann::json;

const std::string FIXTURE_VALID_CPP_BUILD = "validCppBuild.json";

class CppBuildDefinitionTests : public CxxTest::TestSuite
{
public:
    /**
     * Tests using the default constructor to parse a valid build definition file.
     */
    void testValidBuildDefinition(void)
    {
        // Create build definition object from JSON
        CppBuildDefinition buildDef = CppBuildDefinition(FIXTURE_VALID_CPP_BUILD);

        TS_TRACE("Parsing simple definition.");
        TS_ASSERT_EQUALS(buildDef.getOutputType(), "library");
        TS_ASSERT_EQUALS(buildDef.getCompiler(), "g++");
        TS_ASSERT_EQUALS(buildDef.getCflags(), "-std=c++17 -D_REENTRANT");

        TS_TRACE("Testing includes.");
        std::vector<std::string> includePaths = buildDef.getIncludePaths();
        TS_ASSERT_EQUALS(includePaths.size(), 3);
        if (includePaths.size() == 3)
        {
            TS_ASSERT_EQUALS(includePaths[0], "/usr/local/include/nlohmann");
            TS_ASSERT_EQUALS(includePaths[1], "/usr/local/include/cxxtest");
            TS_ASSERT_EQUALS(includePaths[2], "/usr/local/include/boost");
        }

        TS_TRACE("Testing sources.");
        std::vector<std::string> sources = buildDef.getSources();
        if (sources.size() == 2)
        {
            TS_ASSERT_EQUALS(sources[0], "src/build");
            TS_ASSERT_EQUALS(sources[1], "src/commands");
        }

        TS_TRACE("Testing library paths");
        std::vector<std::string> libraryPaths = buildDef.getLibraryPaths();
        if (libraryPaths.size() == 1)
        {
            TS_ASSERT_EQUALS(libraryPaths[0], "/usr/local/lib");
        }

        TS_TRACE("Testing libraries.");
        std::vector<std::string> libraries = buildDef.getLibraries();
        if (libraries.size() == 1)
        {
            TS_ASSERT_EQUALS(libraries[0], "boost_filesystem");
        }
        else
        {
            TS_ASSERT(false);
        }
    }

    /**
     * Tests that include directives can be read from a valid build definition.
     */
    void testGetIncludeDirectives_Success(void)
    {
        // Create build definition object from JSON
        CppBuildDefinition buildDef = CppBuildDefinition(FIXTURE_VALID_CPP_BUILD);

        std::string expected = "-I/usr/local/include/nlohmann -I/usr/local/include/cxxtest -I/usr/local/include/boost ";
        std::string includeDirectives = buildDef.getIncludeDirectives();
        TS_ASSERT_EQUALS(expected, includeDirectives);
    }

    /**
     * Tests that source files can be read from a valid build definition.
     */
    void testGetSourceFiles_Success(void)
    {
        // Create build definition object from JSON
        CppBuildDefinition buildDef = CppBuildDefinition(FIXTURE_VALID_CPP_BUILD);

        std::string expected = "src/build/cppBuildDefinition.cpp src/build/buildHandler.cpp src/commands/commandHandler.cpp ";
        std::string sourceFiles = buildDef.getSourceFileList();
        TS_ASSERT_EQUALS(expected, sourceFiles);
    }

    /**
     * Tests that library directives can be read from a valid build definition.
     */
    void testGetLibraryDirectives_Success(void)
    {
        // Create build definition object from JSON
        CppBuildDefinition buildDef = CppBuildDefinition(FIXTURE_VALID_CPP_BUILD);

        std::string expected = "-L/usr/local/lib -lboost_filesystem ";
        std::string libraryDirectives = buildDef.getLibraryDirectives();
        TS_ASSERT_EQUALS(expected, libraryDirectives);
    }
};
