#ifndef POWERNODE_H
#define POWERNODE_H
#include "binaryoperationnode.h"

class PowerNode:public BinaryOperationNode
{
public:
    PowerNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~PowerNode();

    string ToXml();
    string GetName();
};

#endif // POWERNODE_H
