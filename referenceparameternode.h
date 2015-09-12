#ifndef REFERENCEPARAMETERNODE_H
#define REFERENCEPARAMETERNODE_H
#include "parameternode.h"
#include "expressionnode.h"

class ReferenceParameterNode:public ParameterNode
{
public:
    ExpressionNode * id;
    ExpressionNode * type;
    ReferenceParameterNode();
    ~ReferenceParameterNode();

    // ParameterNode interface
    string ToXml();
};

#endif // REFERENCEPARAMETERNODE_H
