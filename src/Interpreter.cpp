#include "../headers/Interpreter.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "../headers/varStruct.hpp"

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
    parseFile();
};

void Interpreter::parseFile()
{
    vector<string> statements;

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

    while (statements.size())
    {
        if (isVarDeclaration(statements[0]))
        {
            parseVars(statements[0]);
            statements.erase(statements.begin());
        }
        else
        {
            cout << "Not var" << endl;
            statements.erase(statements.begin());
        }
    }
};

void Interpreter::runProgram()
{
    getFile();
};

bool Interpreter::isVarDeclaration(string statement)
{
    regex re("(const|var) +[A-z]{1,} *(= *.+)?;");
    return regex_match(statement, re);
}

void Interpreter::parseVars(string statement)
{
    regex reConst("const *.*");
    regex reVar("var *.*");
    regex reName(" *[A-z]{1,} *");
    if (regex_match(statement, reConst))
    {
        smatch m;
        regex_search(statement, m, reName);
        VarStruct fresh(true, m[0]);
        vars.push_back(fresh);
    }
    else if (regex_match(statement, reVar))
    {
        smatch m;
        regex_search(statement, m, reName);
        VarStruct fresh(false, m[0]);
        vars.push_back(fresh);
    }
    else
    {
        cout << "Wrong syntax '" << statement << "' <--" << endl;
        exit(0);
    }
}