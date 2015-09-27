#ifndef MODNODE_H
#define MODNODE_H
#include "binaryoperationnode.h"
#include "typeenteronode.h"

class ModNode:public BinaryOperationNode
{
public:
    ModNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~ModNode();

    string ToXml();
    string GetName();
    InterpretValue *Evaluate();
};

#endif // MODNODE_H
