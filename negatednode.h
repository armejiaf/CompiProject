#ifndef NEGATEDNODE_H
#define NEGATEDNODE_H
#include "binaryoperationnode.h"

class NegatedNode:public BinaryOperationNode
{
public:
    NegatedNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~NegatedNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // NEGATEDNODE_H
