#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H
#include "binaryoperationnode.h"
#include "typeenteronode.h"
#include "typerealnode.h"
class DivisionNode:public BinaryOperationNode
{
public:
    DivisionNode(ExpressionNode * leftNode, ExpressionNode*rightNode);
    ~DivisionNode();

    string GetName();
};

#endif // DIVISIONNODE_H
