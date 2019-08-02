#include <fstream>
#include <iostream>
#include <string>

#include <cxxtest/TestSuite.h>
#include <nlohmann/json.hpp>

#include "../../inc/commands/commandHandler.h"

using json = nlohmann::json;

class CommandHandlerTests : public CxxTest::TestSuite
{
public:
    /**
     * Tests finding a switch where it is specified in a valid manner.
     */
    void testFindSwitchValid(void)
    {
        std::vector<std::string> args;
        args.push_back("-f");
        args.push_back("file1");
        CommandHandler ch = CommandHandler("build", args);

        std::string fVal = ch.findSwitchValue("-f");
        TS_ASSERT_EQUALS(fVal, "file1");
    }

    /**
     * Tests finding a switch where the switch is specified but a value is not.
     */
    void testFindSwitchNoValue(void)
    {
        std::vector<std::string> args;
        args.push_back("-f");
        CommandHandler ch = CommandHandler("build", args);

        std::string fVal = ch.findSwitchValue("-f");
        TS_ASSERT_EQUALS(fVal, "");
    }
};
