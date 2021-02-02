#ifndef MAIN_FUNCTION_STRUCT_HPP_
#define MAIN_FUNCTION_STRUCT_HPP_

#include "../../VariableKeeper.hpp"

struct FunctionT
{
    std::string name;
    std::vector<std::string> params;
    VariableKeeper scopedVariables;
    std::string body;
};


#endif 