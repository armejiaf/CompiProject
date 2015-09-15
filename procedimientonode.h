#ifndef PROCEDIMIENTONODE_H
#define PROCEDIMIENTONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "parameternode.h"
#include <vector>

class ProcedimientoNode:public StatementNode
{
public:
    VariableNode * id;
    vector<ParameterNode*> parameters;
    vector<StatementNode*> code;
    ProcedimientoNode( VariableNode * id,vector<ParameterNode*> parameters,vector<StatementNode*> code);
    ~ProcedimientoNode();

    string ToXml();
    string GetName();
};

#endif // PROCEDIMIENTONODE_H
