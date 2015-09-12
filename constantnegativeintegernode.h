#ifndef CONSTANTNEGATIVEINTEGERNODE_H
#define CONSTANTNEGATIVEINTEGERNODE_H
#include "literalnode.h"
#include "expressionnode.h"

class ConstantNegativeIntegerNode:public LiteralNode
{
public:
    int value;
    ExpressionNode *sign;

    ConstantNegativeIntegerNode();
    ~ConstantNegativeIntegerNode();

    // LiteralNode interface
    string ToXml();
};

#endif // CONSTANTNEGATIVEINTEGERNODE_H
