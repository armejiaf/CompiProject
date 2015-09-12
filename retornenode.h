#ifndef RETORNENODE_H
#define RETORNENODE_H
#include "statementnode.h"
#include "expressionnode.h"

class RetorneNode:public StatementNode
{
public:
    ExpressionNode * variable;
    RetorneNode();
    ~RetorneNode();

    // StatementNode interface
    string ToXml();
};

#endif // RETORNENODE_H
