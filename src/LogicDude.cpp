#include <string>
#include "../headers/LogicDude.hpp"

bool LogicDude::isLogic(std::string statement) {
    std::regex re("[a-zA-z0-9\"]+ *\\(([a-zA-Z],)*\\) *;");
    return regex_match(statement, re);
}