#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class LessThanNode:public BinaryOperationNode
{
public:
    LessThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~LessThanNode();

    string GetName();
};

#endif // LESSTHANNODE_H
