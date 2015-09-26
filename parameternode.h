#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H
#include <string.h>
#include <iostream>
#include "typenode.h"
using namespace std;

class ParameterNode
{
public:
    int row;
    int column;
    virtual string GetName()=0;
    virtual TypeNode* ValidateSemantic()=0;
    ParameterNode();
    ~ParameterNode();
};

#endif // PARAMETERNODE_H
