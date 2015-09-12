#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H
#include "binaryoperationnode.h"

class DivisionNode:public BinaryOperationNode
{
public:
    DivisionNode(ExpressionNode * leftNode, ExpressionNode*rightNode);
    ~DivisionNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // DIVISIONNODE_H
