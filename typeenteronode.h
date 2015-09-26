#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "expressionnode.h"
#include "typenode.h"
#include "valueentero.h"

class EnteroNode:public TypeNode
{
public:

    EnteroNode();
    ~EnteroNode();

    string GetName();

    InterpretValue *GetDefaultValue();
};

#endif // ENTERONODE_H
