#ifndef PROCEDIMIENTONODE_H
#define PROCEDIMIENTONODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "parameternode.h"
#include <vector>

class ProcedimientoNode:public StatementNode
{
public:
    ExpressionNode * id;
    vector<ParameterNode*> parameters;
    vector<StatementNode*> code;
    ProcedimientoNode();
    ~ProcedimientoNode();

    // StatementNode interface
    string ToXml();
};

#endif // PROCEDIMIENTONODE_H
