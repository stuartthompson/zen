#include <cxxtest/TestSuite.h>

#include <string>
#include "../inc/build/cppBuildDefinition.h"

class CppBuildDefinitionTests : public CxxTest::TestSuite
{
public:
    /**
     * Tests using the default constructor to parse a build definition.
     */
    void ctor_test(void)
    {
        std::string jsonDef = "{\"compiler\": \"g++\"}";
        CppBuildDefinition buildDef = CppBuildDefinition(jsonDef);

        TS_TRACE("Parsing simple definition.");
        TS_ASSERT_EQUALS(buildDef.getCompiler(), "g++");
    }
};
