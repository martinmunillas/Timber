#ifndef VARSSTRUCT_HPP_
#define VARSSTRUCT_HPP_
#include <string>

struct VarStruct {
    VarStruct(bool iIsConstant, std::string iName) {
        bool isConstant = iIsConstant;
        std::string name = iName;
    }
    
};

#endif