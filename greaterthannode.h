#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "binaryoperationnode.h"

class GreaterThanNode: BinaryOperationNode
{
public:
    GreaterThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~GreaterThanNode();

    string ToXml();
    string GetName();
};

#endif // GREATERTHANNODE_H
