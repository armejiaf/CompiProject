#ifndef REALNODE_H
#define REALNODE_H
#include "expressionnode.h"
#include "typenode.h"
class RealNode:public TypeNode
{
public:
    RealNode();
    ~RealNode();

    string ToXml();
    string GetName();
};

#endif // REALNODE_H
