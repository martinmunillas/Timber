#ifndef HEADER_HPP_
#define HEADER_HPP_

#include <iostream>
#include <vector>

using namespace std;

class Interpreter
{
public:
    Interpreter(string file);
    void runProgram();

private:
    vector<string> statements; 
    string fileName;
    string file;
    void getFile();
    void tokenize();
};

#endif