#ifndef HEADER_HPP_
#define HEADER_HPP_

#include <iostream>

using namespace std;

class Interpreter
{
public:
    Interpreter(string file);
    void runProgram();

private:
    string fileName;
    string file;
    void getFile();
    void tokenize();
};

#endif