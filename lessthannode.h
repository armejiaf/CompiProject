#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "binaryoperationnode.h"

class LessThanNode:public BinaryOperationNode
{
public:
    LessThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~LessThanNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // LESSTHANNODE_H
