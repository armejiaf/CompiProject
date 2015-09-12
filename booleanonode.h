#ifndef BOOLEANONODE_H
#define BOOLEANONODE_H
#include "expressionnode.h"

class BooleanoNode:public ExpressionNode
{
public:
    BooleanoNode();
    ~BooleanoNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // BOOLEANONODE_H
