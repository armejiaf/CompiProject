#ifndef SUBSTRACTIONNODE_H
#define SUBSTRACTIONNODE_H
#include "binaryoperationnode.h"

class SubstractionNode:public BinaryOperationNode
{
public:
    SubstractionNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~SubstractionNode();

    string ToXml();
    string GetName();
};

#endif // SUBSTRACTIONNODE_H
