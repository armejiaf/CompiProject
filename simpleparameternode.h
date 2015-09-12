#ifndef SIMPLEPARAMETERNODE_H
#define SIMPLEPARAMETERNODE_H
#include "parameternode.h"
#include "expressionnode.h"


class SimpleParameterNode:public ParameterNode
{
public:
    ExpressionNode* id;
    ExpressionNode* type;
    SimpleParameterNode();
    ~SimpleParameterNode();

    // ParameterNode interface
    string ToXml();
};

#endif // SIMPLEPARAMETERNODE_H
