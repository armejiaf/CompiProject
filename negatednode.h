#ifndef NEGATEDNODE_H
#define NEGATEDNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class NegatedNode:public BinaryOperationNode
{
public:
    NegatedNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~NegatedNode();

    string GetName();
};

#endif // NEGATEDNODE_H
