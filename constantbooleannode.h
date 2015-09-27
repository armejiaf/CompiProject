#ifndef CONSTANBOOLEANNODE_H
#define CONSTANBOOLEANNODE_H
#include "expressionnode.h"
#include "typebooleanonode.h"

class ConstantBooleanNode:public ExpressionNode
{
public:
    bool value;
    ConstantBooleanNode(bool value);
    ~ConstantBooleanNode();

    string GetName();
    TypeNode *ValidateSemantic();
    InterpretValue *Evaluate();
};

#endif // CONSTANBOOLEANNODE_H
