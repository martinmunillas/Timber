#include "../headers/VariableKeeper.hpp"
#include <regex>


void VariableKeeper::setVariable(std::string statement) {
    parseStatement(statement);
};

std::vector<long long> VariableKeeper::getNumbers() {

};

std::vector<std::string> VariableKeeper::getStrings() {

};

void VariableKeeper::parseStatement(std::string statement) {
    std::regex re("(const|var) ([a-z]{1,30}) = (.*)");
    std::smatch tokens;
    if(std::regex_search(statement, tokens, re)) {
        for(int i = 1; i < tokens.size(); i++) {
            std::cout << tokens[i] << std::endl;
        }
    }
};

long long VariableKeeper::setNumber() {

};

std::string VariableKeeper::setString() {

};