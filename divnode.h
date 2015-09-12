#ifndef DIVNODE_H
#define DIVNODE_H
#include "binaryoperationnode.h"

class DivNode:public BinaryOperationNode
{
public:
    DivNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~DivNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // DIVNODE_H
