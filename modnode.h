#ifndef MODNODE_H
#define MODNODE_H
#include "binaryoperationnode.h"


class ModNode:public BinaryOperationNode
{
public:
    ModNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~ModNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // MODNODE_H
