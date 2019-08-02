/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_CommandHandlerTests_init = false;
#include "/Users/s.thompson/dev/src/github.com/stuartthompson/zen/tests/commands/commandHandler_tests.h"

static CommandHandlerTests suite_CommandHandlerTests;

static CxxTest::List Tests_CommandHandlerTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CommandHandlerTests( "./tests/commands/commandHandler_tests.h", 12, "CommandHandlerTests", suite_CommandHandlerTests, Tests_CommandHandlerTests );

static class TestDescription_suite_CommandHandlerTests_testFindSwitchValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CommandHandlerTests_testFindSwitchValid() : CxxTest::RealTestDescription( Tests_CommandHandlerTests, suiteDescription_CommandHandlerTests, 18, "testFindSwitchValid" ) {}
 void runTest() { suite_CommandHandlerTests.testFindSwitchValid(); }
} testDescription_suite_CommandHandlerTests_testFindSwitchValid;

static class TestDescription_suite_CommandHandlerTests_testFindSwitchNoValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CommandHandlerTests_testFindSwitchNoValue() : CxxTest::RealTestDescription( Tests_CommandHandlerTests, suiteDescription_CommandHandlerTests, 32, "testFindSwitchNoValue" ) {}
 void runTest() { suite_CommandHandlerTests.testFindSwitchNoValue(); }
} testDescription_suite_CommandHandlerTests_testFindSwitchNoValue;

#include "/Users/s.thompson/dev/src/github.com/stuartthompson/zen/tests/build/cppBuildDefinition_tests.h"

static CppBuildDefinitionTests suite_CppBuildDefinitionTests;

static CxxTest::List Tests_CppBuildDefinitionTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CppBuildDefinitionTests( "./tests/build/cppBuildDefinition_tests.h", 14, "CppBuildDefinitionTests", suite_CppBuildDefinitionTests, Tests_CppBuildDefinitionTests );

static class TestDescription_suite_CppBuildDefinitionTests_testValidBuildDefinition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CppBuildDefinitionTests_testValidBuildDefinition() : CxxTest::RealTestDescription( Tests_CppBuildDefinitionTests, suiteDescription_CppBuildDefinitionTests, 20, "testValidBuildDefinition" ) {}
 void runTest() { suite_CppBuildDefinitionTests.testValidBuildDefinition(); }
} testDescription_suite_CppBuildDefinitionTests_testValidBuildDefinition;

static class TestDescription_suite_CppBuildDefinitionTests_testGetIncludeDirectives_Success : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CppBuildDefinitionTests_testGetIncludeDirectives_Success() : CxxTest::RealTestDescription( Tests_CppBuildDefinitionTests, suiteDescription_CppBuildDefinitionTests, 45, "testGetIncludeDirectives_Success" ) {}
 void runTest() { suite_CppBuildDefinitionTests.testGetIncludeDirectives_Success(); }
} testDescription_suite_CppBuildDefinitionTests_testGetIncludeDirectives_Success;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
