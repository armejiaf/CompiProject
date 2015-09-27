#ifndef SUBSTRACTIONNODE_H
#define SUBSTRACTIONNODE_H
#include "binaryoperationnode.h"
#include "typeenteronode.h"
#include "typerealnode.h"
class SubstractionNode:public BinaryOperationNode
{
public:
    SubstractionNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~SubstractionNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // SUBSTRACTIONNODE_H
