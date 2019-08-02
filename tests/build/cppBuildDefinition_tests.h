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
        TS_ASSERT_EQUALS(buildDef.getIncludes()[0], "file1.h");
        TS_ASSERT_EQUALS(buildDef.getIncludes()[1], "file2.h");
        
        TS_TRACE("Testing sources.");
        TS_ASSERT_EQUALS(buildDef.getSources()[0], "file1.cpp");
        TS_ASSERT_EQUALS(buildDef.getSources()[1], "file2.cpp");

        TS_TRACE("Testing libraries.");
        TS_ASSERT_EQUALS(buildDef.getLibraries()[0], "lib1");
    }
};
