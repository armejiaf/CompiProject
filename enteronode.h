#ifndef ENTERONODE_H
#define ENTERONODE_H
#include "expressionnode.h"

class EnteroNode:public ExpressionNode
{
public:

    EnteroNode();
    ~EnteroNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // ENTERONODE_H
