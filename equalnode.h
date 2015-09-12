#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "binaryoperationnode.h"

class EqualNode: public BinaryOperationNode
{
public:
    EqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~EqualNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // EQUALNODE_H
