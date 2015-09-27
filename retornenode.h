#ifndef RETORNENODE_H
#define RETORNENODE_H
#include "statementnode.h"
#include "variablenode.h"

class RetorneNode:public StatementNode
{
public:
    ExpressionNode * returnVariable;
    RetorneNode(ExpressionNode *returnVariable);
    ~RetorneNode();

    string GetName();
    void ValidateSemantic();
    void Interpret();
};

#endif // RETORNENODE_H
