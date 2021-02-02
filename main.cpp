#include <iostream>

#include "./headers/Interpreter.hpp"
#include "./headers/Utils.hpp"

int main(int argc, char **argv)
{
    if(argc > 2) {
        throwError("Too many arguments");
    } else if(argc < 2) {
        throwError("No file specified");
    }

    Interpreter timber(argv[1]);
    timber.runProgram();
    
    return 0;
}