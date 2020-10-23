#ifndef FUNCTION_EXECUTOR_HPP_
#define FUNCTION_EXECUTOR_HPP_

#include <string>
#include <vector>

#include "VariableKeeper.hpp"
#include "./structs/functions/main.hpp"

class FunctionExecutor
{
public:
    FunctionExecutor(VariableKeeper fatherVariables);
    void set(std::string function);
    bool exists(std::string name);
    void execute(std::string name, std::vector<std::pair<std::string, std::string>> parameters);
    private:
    void parseFunction(std::string function);
    std::vector<FunctionT> functions; 
};

#endif