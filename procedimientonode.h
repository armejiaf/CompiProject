#ifndef PROCEDIMIENTONODE_H
#define PROCEDIMIENTONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "parameternode.h"
#include "symboltable.h"
#include <vector>

class ProcedimientoNode:public StatementNode
{
public:
    string id;
    vector<ParameterNode*> parameters;
    vector<StatementNode*>variables;
    vector<StatementNode*> code;
    ProcedimientoNode( string id,vector<ParameterNode*> parameters,vector<StatementNode*>variables,vector<StatementNode*> code);
    ~ProcedimientoNode();

    string GetName();
    void ValidateSemantic();
};

#endif // PROCEDIMIENTONODE_H
