#ifndef HEADER_HPP_
#define HEADER_HPP_

#include <iostream>
#include <vector>
#include "./varStruct.hpp"

using namespace std;

class Interpreter
{
public:
    Interpreter(string file);
    void runProgram();

private:
    vector<VarStruct> vars;
    string fileName;
    string file;
    void getFile();
    void parseFile();
    void parseVars(string statement);
    bool isVarDeclaration(string statement);
};

#endif