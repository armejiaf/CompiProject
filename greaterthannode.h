#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "binaryoperationnode.h"

class GreaterThanNode: BinaryOperationNode
{
public:
    GreaterThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~GreaterThanNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // GREATERTHANNODE_H
