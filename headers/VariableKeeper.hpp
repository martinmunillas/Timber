#ifndef VARIABLE_KEEPER_HPP_
#define VARIABLE_KEEPER_HPP_

#include <iostream>
#include <vector>
#include "./structs/variables/number.hpp"
#include "./structs/variables/string.hpp"

class VariableKeeper
{
public:

    void set(std::string statement);
    void assign(std::string statement);
    bool exists(std::string varName);
    bool isConstant(std::string name);
    void updateNumber(std::string varName, long long newValue);

private:
    void parseDeclaration(std::string statement);
    void parseAssignment(std::string statement);

    long long setNumber(NumberT newNumber);
    std::string setString(StringT newString);

    std::vector<NumberT> numbers;
    std::vector<StringT> strings;
};

#endif