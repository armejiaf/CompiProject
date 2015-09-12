#ifndef CONSTANTINTEGERNODE_H
#define CONSTANTINTEGERNODE_H
#include "literalnode.h"

class ConstantIntegerNode:public LiteralNode
{
public:
    int value;
    ConstantIntegerNode();
    ~ConstantIntegerNode();

    // LiteralNode interface
    string ToXml();
};

#endif // CONSTANTINTEGERNODE_H
