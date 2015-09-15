#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "expressionnode.h"
#include "typenode.h"

class EnteroNode:public TypeNode
{
public:

    EnteroNode();
    ~EnteroNode();

    string ToXml();
    string GetName();
};

#endif // ENTERONODE_H
