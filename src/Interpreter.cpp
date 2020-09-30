#include "../headers/Interpreter.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Interpreter::Interpreter(string iFileName)
{
    fileName = iFileName;
    file = "";
}

void Interpreter::getFile()
{
    ifstream src(fileName);
    if (src.is_open())
    {
        string line;
        while (getline(src, line))
        {
            file += line;
        }
    }
    tokenize();
};

void Interpreter::tokenize()
{
    int i = 0;
    while (file.size())
    {
        i++;
        if (file[i] == ';')
        {
            statements.push_back(file.substr(0, i + 1));
            file = file.substr(i + 1, file.size());
            i = 0;
        };

        if (file.size() + 1 == i)
        {
            cout << "Missing ';' at " << i << endl;
            exit(0);
        }
    }
};

void Interpreter::runProgram()
{
    getFile();
    for (int i = 0; i < statements.size(); i++)
    {
        cout << statements[i] << endl;
    }
}