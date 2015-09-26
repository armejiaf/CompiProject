#ifndef TYPENODE_H
#define TYPENODE_H
#include "parentnode.h"
#include "interpretvalue.h"


class TypeNode:public ParentNode
{
public:
    TypeNode();
    ~TypeNode();
    virtual InterpretValue * GetDefaultValue()=0;

};

#endif // TYPENODE_H
