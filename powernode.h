#ifndef POWERNODE_H
#define POWERNODE_H
#include "binaryoperationnode.h"

class PowerNode:public BinaryOperationNode
{
public:
    PowerNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~PowerNode();

    // ExpressionNode interface

    string ToXml();
};

#endif // POWERNODE_H
