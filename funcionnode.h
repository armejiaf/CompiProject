#ifndef FUNCIONNODE_H
#define FUNCIONNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "parameternode.h"
#include <vector>

class FuncionNode:public StatementNode
{
public:
    ExpressionNode * id;
    ExpressionNode * type;
    vector<ParameterNode*> parameters;
    vector<StatementNode*> code;
    FuncionNode();
    ~FuncionNode();

    // StatementNode interface
    string ToXml();
};

#endif // FUNCIONNODE_H
