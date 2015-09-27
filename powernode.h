#ifndef POWERNODE_H
#define POWERNODE_H
#include "binaryoperationnode.h"
#include "typerealnode.h"
#include "typeenteronode.h"
#include <math.h>
#include <stdio.h>

class PowerNode:public BinaryOperationNode
{
public:
    PowerNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~PowerNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // POWERNODE_H
