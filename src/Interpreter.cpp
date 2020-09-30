#include "../headers/Interpreter.hpp"
#include <iostream>
#include <fstream>

using namespace std;


Interpreter::Interpreter(string iFileName) {
    fileName = iFileName;
    file = "";
}

void Interpreter::getFile() {
    ifstream src(fileName);
    if (src.is_open()) {
        string line;
        while(getline(src, line)) {
            file += line;
        }

    }
};

void Interpreter::tokenize() {

};

void Interpreter::runProgram() {
    getFile();
    cout << file;
}