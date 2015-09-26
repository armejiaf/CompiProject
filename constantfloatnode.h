#ifndef CONSTANTFLOATNODE_H
#define CONSTANTFLOATNODE_H
#include "expressionnode.h"
#include "typerealnode.h"

class ConstantFloatNode:public ExpressionNode
{
public:
    float value;
    ConstantFloatNode(double value);
    ~ConstantFloatNode();

    string GetName();
    TypeNode *ValidateSemantic();
};

#endif // CONSTANTFLOATNODE_H
