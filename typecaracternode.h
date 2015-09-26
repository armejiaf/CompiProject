#ifndef CARACTERNODE_H
#define CARACTERNODE_H
#include "typenode.h"
#include "valuecaracter.h"

class CaracterNode:public TypeNode
{
public:
    CaracterNode();
    ~CaracterNode();

    string GetName();

    InterpretValue *GetDefaultValue();
};

#endif // CARACTERNODE_H
