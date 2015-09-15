#ifndef NEGATEDNODE_H
#define NEGATEDNODE_H
#include "binaryoperationnode.h"

class NegatedNode:public BinaryOperationNode
{
public:
    NegatedNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~NegatedNode();

    string ToXml();
    string GetName();
};

#endif // NEGATEDNODE_H
