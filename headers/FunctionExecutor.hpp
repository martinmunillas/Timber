#ifndef FUNCTION_EXECUTOR_HPP_
#define FUNCTION_EXECUTOR_HPP_

#include <string>
#include <vector>

#include "VariableKeeper.hpp"
#include "./structs/functions/main.hpp"

class FunctionExecutor
{
public:
    FunctionExecutor(VariableKeeper &fatherVariables);
    void set(std::string function);
    void execute(std::string call);

private:
    bool exists(std::string name);
    void parseFunction(std::string function);
    void parseParams(std::string params);
    std::vector<FunctionT> functions;
};

#endif