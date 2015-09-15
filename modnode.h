#ifndef MODNODE_H
#define MODNODE_H
#include "binaryoperationnode.h"


class ModNode:public BinaryOperationNode
{
public:
    ModNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~ModNode();

    string ToXml();
    string GetName();
};

#endif // MODNODE_H
