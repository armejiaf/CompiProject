#ifndef ORNODE_H
#define ORNODE_H
#include "binaryoperationnode.h"

class OrNode:public BinaryOperationNode
{
public:
    OrNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~OrNode();

    string ToXml();
    string GetName();
};

#endif // ORNODE_H
