#include <string>
#include <vector>
#include <regex>

#include "../headers/FunctionExecutor.hpp"
#include "../headers/Utils.hpp"
#include "../headers/structs/functions/main.hpp"

void FunctionExecutor::set(std::string function) {
    parseFunction(function);
};
void FunctionExecutor::execute(std::string name, std::vector<std::pair<std::string, std::string>> parameters) {

};

bool FunctionExecutor::exists(std::string name) {
    for(int i = 0; i < functions.size(); i++) {
        if(functions[i].name == name) {
            return true;
        }
    }
    return false;
};


void FunctionExecutor::parseFunction(std::string function) {
    std::regex re("function +([a-z]{1,30})\((.*)\) += + ({^;.}*);");
    std::smatch tokens;
    if (std::regex_search(function, tokens, re))
    {
        // 0 function
        // 1 name
        // 2 params
        // 3 body
        if (!exists(tokens[1]))
        {
            FunctionT newFunc;
            newFunc.name = tokens[1];
            newFunc.body = tokens[3];
            newFunc.params.push_back(tokens[2]);
        }
        else
        {
            std::cout << tokens[1];
            throwError(" is already declared");
        }
    }
};
