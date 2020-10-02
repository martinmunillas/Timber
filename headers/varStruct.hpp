#ifndef VARSSTRUCT_HPP_
#define VARSSTRUCT_HPP_
#include <string>

using namespace std;

struct VarStruct
{
    VarStruct(bool iIsConstant, string iName)
    {
        isConstant = iIsConstant;
        string name = iName;
    }

    bool isConstant;
    string name;
};

#endif