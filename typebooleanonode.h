#ifndef BOOLEANONODE_H
#define BOOLEANONODE_H
#include "expressionnode.h"
#include "typenode.h"
#include "valuebooleano.h"

class BooleanoNode:public TypeNode
{
public:
    BooleanoNode();
    ~BooleanoNode();

    string GetName();

    InterpretValue *GetDefaultValue();
};

#endif // BOOLEANONODE_H
