#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

#include "inc/build/cppBuildDefinition.h"

using json = nlohmann::json;

int main(int argc, char *argv[])
{
   std::ifstream i("testDef.json");
    json j;
    i >> j;

    std::cout << j << std::endl;
    std::cout << "Compiler: " << j["compiler"] << std::endl;
    std::cout << "Cflags: " << j["cflags"] << std::endl;
    std::cout << "Includes: " << j["includes"] << std::endl;
    std::cout << "Sources: " << j["sources"] << std::endl;

    std::vector<std::string> vec = j["includes"];
    std::cout << "VSize: " << vec.size() << std::endl; 
    std::cout << "I1" << vec[0] << std::endl;
    std::cout << "I2" << vec[1] << std::endl;

    CppBuildDefinition def = CppBuildDefinition("testDef.json");
}