#ifndef ANDNODE_H
#define ANDNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class AndNode:public BinaryOperationNode
{
public:
    AndNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~AndNode();


    string GetName();
};

#endif // ANDNODE_H
