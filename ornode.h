#ifndef ORNODE_H
#define ORNODE_H
#include "binaryoperationnode.h"

class OrNode:public BinaryOperationNode
{
public:
    OrNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~OrNode();

    // ExpressionNode interface
public:
    string ToXml();
};

#endif // ORNODE_H
