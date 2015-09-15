#ifndef LLAMARNODE_H
#define LLAMARNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "variablenode.h"
#include <vector>

class LlamarNode:public StatementNode
{
public:
    VariableNode * idProcedure;
    vector<ExpressionNode*> parameters;

    LlamarNode( VariableNode * idProcedure,vector<ExpressionNode*> parameters);
    ~LlamarNode();

    string ToXml();
    string GetName();
};

#endif // LLAMARNODE_H
