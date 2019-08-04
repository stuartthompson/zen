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
CxxTest::StaticSuiteDescription suiteDescription_CppBuildDefinitionTests( "./tests/build/cppBuildDefinition_tests.h", 14, "CppBuildDefinitionTests", suite_CppBuildDefinitionTests, Tests_CppBuildDefinitionTests );

static class TestDescription_suite_CppBuildDefinitionTests_testValidBuildDefinition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CppBuildDefinitionTests_testValidBuildDefinition() : CxxTest::RealTestDescription( Tests_CppBuildDefinitionTests, suiteDescription_CppBuildDefinitionTests, 20, "testValidBuildDefinition" ) {}
 void runTest() { suite_CppBuildDefinitionTests.testValidBuildDefinition(); }
} testDescription_suite_CppBuildDefinitionTests_testValidBuildDefinition;

static class TestDescription_suite_CppBuildDefinitionTests_testGetIncludeDirectives_Success : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CppBuildDefinitionTests_testGetIncludeDirectives_Success() : CxxTest::RealTestDescription( Tests_CppBuildDefinitionTests, suiteDescription_CppBuildDefinitionTests, 70, "testGetIncludeDirectives_Success" ) {}
 void runTest() { suite_CppBuildDefinitionTests.testGetIncludeDirectives_Success(); }
} testDescription_suite_CppBuildDefinitionTests_testGetIncludeDirectives_Success;

static class TestDescription_suite_CppBuildDefinitionTests_testGetSourceFiles_Success : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CppBuildDefinitionTests_testGetSourceFiles_Success() : CxxTest::RealTestDescription( Tests_CppBuildDefinitionTests, suiteDescription_CppBuildDefinitionTests, 83, "testGetSourceFiles_Success" ) {}
 void runTest() { suite_CppBuildDefinitionTests.testGetSourceFiles_Success(); }
} testDescription_suite_CppBuildDefinitionTests_testGetSourceFiles_Success;

static class TestDescription_suite_CppBuildDefinitionTests_testGetLibraryDirectives_Success : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_CppBuildDefinitionTests_testGetLibraryDirectives_Success() : CxxTest::RealTestDescription( Tests_CppBuildDefinitionTests, suiteDescription_CppBuildDefinitionTests, 96, "testGetLibraryDirectives_Success" ) {}
 void runTest() { suite_CppBuildDefinitionTests.testGetLibraryDirectives_Success(); }
} testDescription_suite_CppBuildDefinitionTests_testGetLibraryDirectives_Success;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
