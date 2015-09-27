#ifndef FUNCIONNODE_H
#define FUNCIONNODE_H
#include "statementnode.h"
#include "typenode.h"
#include "parameternode.h"
#include "symboltable.h"
#include "variablenode.h"
#include "retornenode.h"
#include <vector>

class FuncionNode:public StatementNode
{
public:
    string id;
    TypeNode * type;
    vector<ParameterNode*> parameters;
    vector<StatementNode*> variables;
    vector<StatementNode*> code;
    FuncionNode(string id, TypeNode * returnType, vector<ParameterNode*> parameters, vector<StatementNode*> variables, vector<StatementNode*> code);
    ~FuncionNode();

    string GetName();
    void ValidateSemantic();
    void Interpret();
};

#endif // FUNCIONNODE_H
