#ifndef CONSTANBOOLEANNODE_H
#define CONSTANBOOLEANNODE_H
#include "expressionnode.h"

class ConstanBooleanNode:public ExpressionNode
{
public:
    bool value;
    ConstanBooleanNode(bool value);
    ~ConstanBooleanNode();

    string ToXml();
    string GetName();
};

#endif // CONSTANBOOLEANNODE_H
