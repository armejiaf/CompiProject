#ifndef NOTEQUAL_H
#define NOTEQUAL_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class NotEqualNode:public BinaryOperationNode
{
public:
    NotEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~NotEqualNode();

    string GetName();
};

#endif // NOTEQUAL_H
