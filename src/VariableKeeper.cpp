#include <regex>

#include "../headers/Utils.hpp"

#include "../headers/VariableKeeper.hpp"
#include "../headers/structs/variables/number.hpp"
#include "../headers/structs/variables/string.hpp"

void VariableKeeper::set(std::string statement)
{
    parseDeclaration(statement);
};

void VariableKeeper::assign(std::string statement)
{
    parseAssignment(statement);
};

bool VariableKeeper::exists(std::string varName)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i].name == varName)
        {
            return true;
        }
    }
    for (int i = 0; i < strings.size(); i++)
    {
        if (strings[i].name == varName)
        {
            return true;
        }
    }
    return false;
};

void VariableKeeper::updateNumber(std::string varName, long long newValue)
{
    if (exists(varName))
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            if (varName == numbers[i].name)
            {
                if(!numbers[i].isConstant) {
                    numbers[i].value = newValue;
                } else {
                    throwError(varName + " value can't be change because is a constant");
                }
            }
        }

        for (int i = 0; i < strings.size(); i++)
        {
            if (varName == strings[i].name)
            {
                if(!strings[i].isConstant) {
                    NumberT morph;
                    morph.name = strings[i].name;
                    morph.isConstant = false;
                    morph.value = newValue;
                    numbers.push_back(morph);
                    strings.erase(strings.begin() + i);
                } else {
                    throwError(varName + " value can't be change because is a constant");
                }
            }
        }
    }
    else
    {
        throwError(varName + " is not declared");
    }
};

void VariableKeeper::updateString(std::string varName, std::string newValue)
{
    if (exists(varName))
    {
        for (int i = 0; i < strings.size(); i++)
        {
            if (varName == strings[i].name)
            {
                if(!strings[i].isConstant) {
                    strings[i].value = newValue;
                } else {
                    throwError(varName + " value can't be change because is a constant");
                }
            }
        }

        for (int i = 0; i < numbers.size(); i++)
        {
            if (varName == numbers[i].name)
            {
                if(!numbers[i].isConstant) {
                    StringT morph;
                    morph.name = numbers[i].name;
                    morph.isConstant = false;
                    morph.value = newValue;
                    strings.push_back(morph);
                    numbers.erase(numbers.begin() + i);
                } else {
                    throwError(varName + " value can't be change because is a constant");
                }
            }
        }
    }
    else
    {
        throwError(varName + " is not declared");
    }
};


void VariableKeeper::parseDeclaration(std::string statement)
{

    std::regex re("(const|var) ([a-z]{1,30})( = ([^;.]+))?;");
    std::smatch tokens;
    if (std::regex_search(statement, tokens, re))
    {
        // 0 statement
        // 1 isConstant
        // 2 name
        // 3 equals value
        // 4 value
        if (!exists(tokens[2]))
        {
            if (isNumber(tokens[4]))
            {
                NumberT newNumber;
                newNumber.isConstant = (tokens[1] == "const");
                newNumber.name = tokens[2];
                newNumber.value = std::stoi(tokens[4]);
                setNumber(newNumber);
            }
            else if (isString(tokens[4]))
            {
                StringT newString;
                newString.isConstant = (tokens[1] == "const");
                newString.name = tokens[2];
                newString.value = tokens[4];
                setString(newString);
            }
        }
        else
        {
            std::cout << tokens[2];
            throwError(" is already declared");
        }
    }
};

void VariableKeeper::parseAssignment(std::string statement)
{
    std::regex re("([a-z]+) = ([^;.]+);");
    std::smatch tokens;
    if (std::regex_search(statement, tokens, re))
    {
        // 0 statement
        // 1 name
        // 2 newValue

        std::cout << std::endl;
        if (exists(tokens[1]))
        {
            if (isNumber(tokens[2]))
            {
                long long value = std::stoi(tokens[2]);
                updateNumber(tokens[1], value);
            }
            else if (isString(tokens[2]))
            {
            }
        }
        else
        {
            std::cout << tokens[2];
            throwError(" is already declared");
        }
    }
};

long long VariableKeeper::setNumber(NumberT newNumber)
{
    numbers.push_back(newNumber);
};

std::string VariableKeeper::setString(StringT newString)
{
    strings.push_back(newString);
};