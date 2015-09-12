#ifndef BINARYOPERATIONNODE_H
#define BINARYOPERATIONNODE_H
#include "expressionnode.h"


class BinaryOperationNode: public ExpressionNode
{
public:
    BinaryOperationNode(ExpressionNode *leftNode,ExpressionNode *rightNode);
    ~BinaryOperationNode();
    ExpressionNode *RightNode;
    ExpressionNode *LeftNode;

    // ExpressionNode interface

};

#endif // BINARYOPERATIONNODE_H
