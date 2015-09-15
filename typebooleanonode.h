#ifndef BOOLEANONODE_H
#define BOOLEANONODE_H
#include "expressionnode.h"
#include "typenode.h"
class BooleanoNode:public TypeNode
{
public:
    BooleanoNode();
    ~BooleanoNode();

    string ToXml();
    string GetName();
};

#endif // BOOLEANONODE_H
