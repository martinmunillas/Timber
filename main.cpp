#include <iostream>

#include "./headers/Interpreter.hpp"

using namespace std;

int main()
{
    string file;
    cout << "Insert the file name :" << endl;
    cin >> file;

    Interpreter timber(file);
    timber.runProgram();
    
    return 0;
}