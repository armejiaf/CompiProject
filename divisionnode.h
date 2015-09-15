#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H
#include "binaryoperationnode.h"

class DivisionNode:public BinaryOperationNode
{
public:
    DivisionNode(ExpressionNode * leftNode, ExpressionNode*rightNode);
    ~DivisionNode();

    string ToXml();
    string GetName();
};

#endif // DIVISIONNODE_H
