#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "binaryoperationnode.h"

class LessThanNode:public BinaryOperationNode
{
public:
    LessThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~LessThanNode();

    string ToXml();
    string GetName();
};

#endif // LESSTHANNODE_H
