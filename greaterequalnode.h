#ifndef GREATEREQUALNODE_H
#define GREATEREQUALNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class GreaterEqualNode:public BinaryOperationNode
{
public:
    GreaterEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~GreaterEqualNode();

    string GetName();
};

#endif // GREATEREQUALNODE_H
