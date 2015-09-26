#ifndef REALNODE_H
#define REALNODE_H
#include "expressionnode.h"
#include "typenode.h"
#include "valuereal.h"
class RealNode:public TypeNode
{
public:
    RealNode();
    ~RealNode();

    string GetName();

    InterpretValue *GetDefaultValue();
};

#endif // REALNODE_H
