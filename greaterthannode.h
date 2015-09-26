#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class GreaterThanNode: public BinaryOperationNode
{
public:
    GreaterThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~GreaterThanNode();

    string GetName();
};

#endif // GREATERTHANNODE_H
