#ifndef CONSTANTFLOATNODE_H
#define CONSTANTFLOATNODE_H
#include "expressionnode.h"

class ConstantFloatNode:public ExpressionNode
{
public:
    float value;
    ConstantFloatNode(float value);
    ~ConstantFloatNode();

    string ToXml();
    string GetName();
};

#endif // CONSTANTFLOATNODE_H
