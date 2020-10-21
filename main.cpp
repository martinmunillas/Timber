#include <iostream>

#include "./headers/Interpreter.hpp"

int main()
{
    std::string file;
    std::cout << "Insert the file name :" << std::endl;
    std::cin >> file;

    Interpreter timber(file);
    timber.runProgram();
    
    return 0;
}