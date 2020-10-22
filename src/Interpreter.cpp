#include "../headers/Interpreter.hpp"
#include "../headers/VariableKeeper.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

Interpreter::Interpreter(std::string iFileName)
{
    fileName = iFileName;
    file = "";
    variableKeeper = VariableKeeper();
}

void Interpreter::getFile()
{
    std::ifstream src(fileName);
    if (src.is_open())
    {
        std::string line;
        while (getline(src, line))
        {
            file += line;
        }
    }
    parseFile();
};

void Interpreter::parseFile()
{
    std::vector<std::string> statements;

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
    };

    for(int i = 0; i < statements.size(); i++){
        if(isVarDeclaration(statements[i])) {
            variableKeeper.set(statements[i]);
        } else if(isVarAssignment(statements[i])) {
            variableKeeper.assign(statements[i]);
        }
    };

};

void Interpreter::runProgram()
{
    getFile();
};

bool Interpreter::isVarDeclaration(std::string statement)
{
    std::regex re("(const|var) +[A-z]{1,} *(= *.+)?;");
    return regex_match(statement, re);
}

bool Interpreter::isVarAssignment(std::string statement)
{
    std::regex re("[a-z]+ = .+;");
    return regex_match(statement, re);
}
