#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H
#include "binaryoperationnode.h"

class MultiplicationNode:public BinaryOperationNode
{
public:
    MultiplicationNode(ExpressionNode *leftNode,ExpressionNode * rightNode);
    ~MultiplicationNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // MULTIPLICATIONNODE_H
