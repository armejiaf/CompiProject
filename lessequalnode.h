#ifndef LESSEQUALNODE_H
#define LESSEQUALNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class LessEqualNode:public BinaryOperationNode
{
public:
    LessEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~LessEqualNode();

    string GetName();
};

#endif // LESSEQUALNODE_H
