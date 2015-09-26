#ifndef LLAMARNODE_H
#define LLAMARNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "variablenode.h"
#include "symboltable.h"
#include "procedimientonode.h"
#include <vector>

class LlamarNode:public StatementNode
{
public:
    string idProcedure;
    vector<ExpressionNode*> parameters;

    LlamarNode( string idProcedure,vector<ExpressionNode*> parameters);
    ~LlamarNode();

    string GetName();
    void ValidateSemantic();
};

#endif // LLAMARNODE_H
