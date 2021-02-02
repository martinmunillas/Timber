#ifndef LOOPER_HPP_
#define LOOPER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "./VariableKeeper.hpp"
#include "./FunctionExecutor.hpp"

using namespace std;

class Looper
{
public:
    Looper();
    void generateLoop(std::string statement);
    void loop(int times, std::string body);
    void cycle(int i, std::string body);
private:
};

#endif