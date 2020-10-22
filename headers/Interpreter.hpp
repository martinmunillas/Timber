#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include <iostream>
#include <vector>
#include "./VariableKeeper.hpp"

using namespace std;

class Interpreter
{
public:
    Interpreter(string file);
    void runProgram();

private:
    VariableKeeper variableKeeper;
    string fileName;
    string file;
    void getFile();
    void parseFile();
    bool isVarDeclaration(string statement);
    bool isVarAssignment(string statement);
};

#endif