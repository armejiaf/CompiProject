#ifndef CONSTANBOOLEANNODE_H
#define CONSTANBOOLEANNODE_H
#include "literalnode.h"

class ConstanBooleanNode:public LiteralNode
{
public:
    bool value;
    ConstanBooleanNode();
    ~ConstanBooleanNode();
};

#endif // CONSTANBOOLEANNODE_H
