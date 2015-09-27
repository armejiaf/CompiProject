#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H
#include "binaryoperationnode.h"
#include "typeenteronode.h"
#include "typerealnode.h"
class MultiplicationNode:public BinaryOperationNode
{
public:
    MultiplicationNode(ExpressionNode *leftNode,ExpressionNode * rightNode);
    ~MultiplicationNode();

    string GetName();
    InterpretValue *Evaluate();

};

#endif // MULTIPLICATIONNODE_H
