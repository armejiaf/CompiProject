#ifndef REGISTRONODE_H
#define REGISTRONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "declararnode.h"
#include "symboltable.h"
#include <vector>

class RegistroNode:public StatementNode
{
public:
    string id;
    vector<StatementNode*> variables;

    RegistroNode(string id,vector<StatementNode*> variables);
    ~RegistroNode();

    string GetName();
    void ValidateSemantic();
};

#endif // REGISTRONODE_H
