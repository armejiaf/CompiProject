#ifndef BINARYOPERATIONNODE_H
#define BINARYOPERATIONNODE_H
#include "expressionnode.h"
#include <stdexcept>
#include <map>

class BinaryOperationNode: public ExpressionNode
{
public:
    BinaryOperationNode(ExpressionNode *leftNode,ExpressionNode *rightNode);
    ~BinaryOperationNode();

    map<string, TypeNode*> Rules;
    ExpressionNode *RightNode;
    ExpressionNode *LeftNode;

    TypeNode* ValidateSemantic();
};

#endif // BINARYOPERATIONNODE_H
