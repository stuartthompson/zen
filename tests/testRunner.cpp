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
bool suite_CppBuildDefinitionTests_init = false;
#include "/Users/s.thompson/dev/src/github.com/stuartthompson/zen/tests/build/cppBuildDefinition_tests.h"

static CppBuildDefinitionTests suite_CppBuildDefinitionTests;

static CxxTest::List Tests_CppBuildDefinitionTests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CppBuildDefinitionTests( "./tests/build/cppBuildDefinition_tests.h", 12, "CppBuildDefinitionTests", suite_CppBuildDefinitionTests, Tests_CppBuildDefinitionTests );

static class TestDescription_suite_CppBuildDefinitionTests_testDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CppBuildDefinitionTests_testDefaultCtor() : CxxTest::RealTestDescription( Tests_CppBuildDefinitionTests, suiteDescription_CppBuildDefinitionTests, 18, "testDefaultCtor" ) {}
 void runTest() { suite_CppBuildDefinitionTests.testDefaultCtor(); }
} testDescription_suite_CppBuildDefinitionTests_testDefaultCtor;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
