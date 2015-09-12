#ifndef REALNODE_H
#define REALNODE_H
#include "expressionnode.h"

class RealNode:public ExpressionNode
{
public:
    RealNode();
    ~RealNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // REALNODE_H
