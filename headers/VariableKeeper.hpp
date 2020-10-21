#ifndef VARIABLE_KEEPER_HPP_
#define VARIABLE_KEEPER_HPP_

#include <iostream>
#include <vector>
#include "./structs/variables/number.hpp"
#include "./structs/variables/string.hpp"

class VariableKeeper
{
public:

    void setVariable(std::string statement);

    std::vector<long long> getNumbers();

    std::vector<std::string> getStrings();

private:
    void parseStatement(std::string statement);
    long long setNumber();
    std::string setString();
    std::vector<NumberT> numbers;
    std::vector<StringT> strings;
};

#endif