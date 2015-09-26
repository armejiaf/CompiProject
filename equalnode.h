#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class EqualNode: public BinaryOperationNode
{
public:
    EqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~EqualNode();

    string GetName();
};

#endif // EQUALNODE_H
