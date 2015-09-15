#ifndef REGISTRONODE_H
#define REGISTRONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "declararnode.h"
#include <vector>

class RegistroNode:public StatementNode
{
public:
    VariableNode * id;
    vector<DeclararNode*> variables;

    RegistroNode(VariableNode * id,vector<DeclararNode*> variables);
    ~RegistroNode();

    string ToXml();
    string GetName();
};

#endif // REGISTRONODE_H
