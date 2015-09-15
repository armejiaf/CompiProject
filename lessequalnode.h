#ifndef LESSEQUALNODE_H
#define LESSEQUALNODE_H
#include "binaryoperationnode.h"

class LessEqualNode:BinaryOperationNode
{
public:
    LessEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~LessEqualNode();

    string ToXml();
    string GetName();
};

#endif // LESSEQUALNODE_H
