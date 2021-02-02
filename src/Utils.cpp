#include <regex>
#include <iostream>

bool isNumber(std::string str)
{
    return std::regex_search(str, std::regex("[0-9]+"));
};

bool isString(std::string str)
{
    return std::regex_search(str, std::regex("\".*\""));
};

void throwError(std::string message) {
    std::cout << message << std::endl;
    exit(0);
};