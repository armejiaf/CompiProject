#ifndef CONSTANTFLOATNODE_H
#define CONSTANTFLOATNODE_H
#include "literalnode.h"

class ConstantFloatNode:public LiteralNode
{
public:
    float value;
    ConstantFloatNode();
    ~ConstantFloatNode();

    // LiteralNode interface
    string ToXml();
};

#endif // CONSTANTFLOATNODE_H
