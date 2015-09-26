#ifndef POWERNODE_H
#define POWERNODE_H
#include "binaryoperationnode.h"
#include "typerealnode.h"
#include "typeenteronode.h"
class PowerNode:public BinaryOperationNode
{
public:
    PowerNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~PowerNode();

    string GetName();
};

#endif // POWERNODE_H
