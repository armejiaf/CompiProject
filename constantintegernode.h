#ifndef CONSTANTINTEGERNODE_H
#define CONSTANTINTEGERNODE_H
#include "expressionnode.h"

class ConstantIntegerNode:public ExpressionNode
{
public:
    int value;
    ConstantIntegerNode(int value);
    ~ConstantIntegerNode();

    string ToXml();
    string GetName();
};

#endif // CONSTANTINTEGERNODE_H
