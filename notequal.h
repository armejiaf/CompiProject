#ifndef NOTEQUAL_H
#define NOTEQUAL_H
#include "binaryoperationnode.h"

class NotEqual:public BinaryOperationNode
{
public:
    NotEqual(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~NotEqual();

    string ToXml();
    string GetName();
};

#endif // NOTEQUAL_H
