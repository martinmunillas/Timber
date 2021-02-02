#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include <iostream>
#include <vector>
#include "./VariableKeeper.hpp"
#include "./FunctionExecutor.hpp"

using namespace std;

class Interpreter
{
public:
    Interpreter(string file);
    void runProgram();

private:
    VariableKeeper variableKeeper;
    // FunctionExecutor functionExecutor;
    string fileName;
    string file;
    void getFile();
    void parseFile();
    bool isVarDeclaration(string statement);
    bool isVarAssignment(string statement);
    bool isFunctionDeclaration(string statement);
    bool isFunctionExecution(string statement);
};

#endif