#ifndef LOOPER_HPP_
#define LOOPER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "./VariableKeeper.hpp"
#include "./FunctionExecutor.hpp"

using namespace std;

class LogicDude
{
public:
    Looper();
    static bool isLogic(std::string statement);
    void sum(std::string statement);
    void minus(std::string statement);
    void times(std::string statement);

private:
};

#endif