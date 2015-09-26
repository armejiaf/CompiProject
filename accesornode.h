#ifndef ACCESORNODE_H
#define ACCESORNODE_H
#include <string.h>
#include <iostream>
#include "typenode.h"
#include "symboltable.h"

using namespace std;

class AccesorNode
{
public:
    virtual string GetName()=0;
    virtual TypeNode* ValidateSemantic()=0;
    int row;
    int column;
    AccesorNode();
    ~AccesorNode();
};

#endif // ACCESORNODE_H
