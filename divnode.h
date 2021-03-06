#ifndef DIVNODE_H
#define DIVNODE_H
#include "binaryoperationnode.h"
#include "typeenteronode.h"
class DivNode:public BinaryOperationNode
{
public:
    DivNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~DivNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // DIVNODE_H
