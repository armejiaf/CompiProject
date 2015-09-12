#ifndef GREATEREQUALNODE_H
#define GREATEREQUALNODE_H
#include "binaryoperationnode.h"

class GreaterEqualNode:public BinaryOperationNode
{
public:
    GreaterEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~GreaterEqualNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // GREATEREQUALNODE_H
