#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

#include "../headers/Interpreter.hpp"
#include "../headers/VariableKeeper.hpp"
#include "../headers/FunctionExecutor.hpp"

Interpreter::Interpreter(std::string iFileName)
{
    fileName = iFileName;
    file = "";
    variableKeeper = VariableKeeper();
    // functionExecutor = FunctionExecutor(variableKeeper);
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

    for (int i = 0; i < statements.size(); i++)
    {
        if (isVarDeclaration(statements[i]))
        {
            variableKeeper.set(statements[i]);
        }
        else if (isVarAssignment(statements[i]))
        {
            variableKeeper.assign(statements[i]);
        }
        // else if (isFunctionDeclaration(statements[i]))
        // {
        //     functionExecutor.set(statements[i]);
        // }
        // else if (isFunctionExecution(statements[i]))
        // {
        //     functionExecutor.execute(statements[i]);
        // }
    };
};

void Interpreter::runProgram()
{
    getFile();
};

bool Interpreter::isVarDeclaration(std::string statement)
{
    std::regex re("(const|var) +[a-zA-z]+ *(= *.+)?;");
    return regex_match(statement, re);
}

bool Interpreter::isVarAssignment(std::string statement)
{
    std::regex re("[a-zA-z]+ = .+;");
    return regex_match(statement, re);
}

bool Interpreter::isFunctionDeclaration(string statement){
    std::regex re("func *[a-zA-z]+ *\\(([a-zA-Z],?)*\\) *{.*};");
    return regex_match(statement, re);

};
bool Interpreter::isFunctionExecution(string statement){

    std::regex re("[a-zA-z]+ *\\(([a-zA-Z],)*\\) *;");
    return regex_match(statement, re);
};