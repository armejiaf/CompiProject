#ifndef ANDNODE_H
#define ANDNODE_H
#include "binaryoperationnode.h"

class AndNode:public BinaryOperationNode
{
public:
    AndNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~AndNode();

    // ExpressionNode interface
    string ToXml();

};

#endif // ANDNODE_H
