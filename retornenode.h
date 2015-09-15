#ifndef RETORNENODE_H
#define RETORNENODE_H
#include "statementnode.h"
#include "variablenode.h"

class RetorneNode:public StatementNode
{
public:
    VariableNode * returnVariable;
    RetorneNode(VariableNode * returnVariable);
    ~RetorneNode();

    string ToXml();
    string GetName();
};

#endif // RETORNENODE_H
