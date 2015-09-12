#ifndef NOTEQUAL_H
#define NOTEQUAL_H
#include "binaryoperationnode.h"

class NotEqual:public BinaryOperationNode
{
public:
    NotEqual(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~NotEqual();

    // ExpressionNode interface

    string ToXml();
};

#endif // NOTEQUAL_H
