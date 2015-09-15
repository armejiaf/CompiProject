#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H
#include "binaryoperationnode.h"

class MultiplicationNode:public BinaryOperationNode
{
public:
    MultiplicationNode(ExpressionNode *leftNode,ExpressionNode * rightNode);
    ~MultiplicationNode();

    string ToXml();
    string GetName();
};

#endif // MULTIPLICATIONNODE_H
