#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H
#include <string.h>
#include <iostream>
using namespace std;

class ParameterNode
{
public:
    int row;
    int column;
    virtual string ToXml()=0;
    ParameterNode();
    ~ParameterNode();
};

#endif // PARAMETERNODE_H
