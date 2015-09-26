#ifndef SUMNODE_H
#define SUMNODE_H
#include "binaryoperationnode.h"
#include "typeenteronode.h"
#include "typerealnode.h"
#include "typebooleanonode.h"
#include "typecadenanode.h"

class SumNode:public BinaryOperationNode
{
public:
    SumNode(ExpressionNode* leftNode, ExpressionNode *rightNode);
    ~SumNode();

    string GetName();
};

#endif // SUMNODE_H
