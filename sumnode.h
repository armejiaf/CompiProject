#ifndef SUMNODE_H
#define SUMNODE_H
#include "binaryoperationnode.h"

class SumNode:public BinaryOperationNode
{
public:
    SumNode(ExpressionNode* leftNode, ExpressionNode *rightNode);
    ~SumNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // SUMNODE_H
