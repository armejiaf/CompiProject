#ifndef ORNODE_H
#define ORNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
class OrNode:public BinaryOperationNode
{
public:
    OrNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~OrNode();

   string GetName();
   InterpretValue *Evaluate();
};

#endif // ORNODE_H
