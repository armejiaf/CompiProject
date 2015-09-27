#ifndef CONSTANTINTEGERNODE_H
#define CONSTANTINTEGERNODE_H
#include "expressionnode.h"
#include "typeenteronode.h"

class ConstantIntegerNode:public ExpressionNode
{
public:
    int value;
    ConstantIntegerNode(int value);
    ~ConstantIntegerNode();

    string GetName();
    TypeNode *ValidateSemantic();
    InterpretValue *Evaluate();
};

#endif // CONSTANTINTEGERNODE_H
