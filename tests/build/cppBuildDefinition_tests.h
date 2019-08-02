#include <fstream>
#include <iostream>
#include <string>

#include <cxxtest/TestSuite.h>
#include <nlohmann/json.hpp>

#include "../../inc/build/cppBuildDefinition.h"

using json = nlohmann::json;

class CppBuildDefinitionTests : public CxxTest::TestSuite
{
public:
    /**
     * Tests using the default constructor to parse a build definition.
     */
    void testDefaultCtor(void)
    {
        // Read test build definition
        std::string testFileName = "testDef.json";
        
        // Create build definition object from JSON
        CppBuildDefinition buildDef = CppBuildDefinition(testFileName);

        TS_TRACE("Parsing simple definition.");
        TS_ASSERT_EQUALS(buildDef.getCompiler(), "g++");
        TS_ASSERT_EQUALS(buildDef.getCflags(), "-std=c++17 -D_REENTRANT");
        TS_ASSERT_EQUALS(buildDef.getIncludes().size(), 2);
        TS_ASSERT_EQUALS(buildDef.getSources().size(), 2);
        // TS_TRACE("Testing includes.");
        // TS_ASSERT_EQUALS(buildDef.getIncludes()[0], "file1.h");
        // TS_ASSERT_EQUALS(buildDef.getIncludes()[1], "file2.h");
        // TS_TRACE("Testing sources.");
        // TS_ASSERT_EQUALS(buildDef.getSources()[0], "file1.cpp");
        // TS_ASSERT_EQUALS(buildDef.getSources()[1], "file2.cpp");
    }
};
