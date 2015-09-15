#ifndef CARACTERNODE_H
#define CARACTERNODE_H
#include "typenode.h"

class CaracterNode:public TypeNode
{
public:
    CaracterNode();
    ~CaracterNode();

    string ToXml();
    string GetName();
};

#endif // CARACTERNODE_H
