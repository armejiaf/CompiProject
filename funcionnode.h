#ifndef FUNCIONNODE_H
#define FUNCIONNODE_H
#include "statementnode.h"
#include "typenode.h"
#include "parameternode.h"
#include "variablenode.h"
#include <vector>

class FuncionNode:public StatementNode
{
public:
    VariableNode * id;
    TypeNode * type;
    vector<ParameterNode*> parameters;
    vector<StatementNode*> code;
    FuncionNode( VariableNode * id,TypeNode * type,vector<ParameterNode*> parameters,vector<StatementNode*> code);
    ~FuncionNode();

    string ToXml();
    string GetName();
};

#endif // FUNCIONNODE_H
