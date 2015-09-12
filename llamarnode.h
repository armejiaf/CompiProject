#ifndef LLAMARNODE_H
#define LLAMARNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class LlamarNode:public StatementNode
{
public:
    ExpressionNode * idName;
    vector<ExpressionNode*> parameters;

    LlamarNode();
    ~LlamarNode();

    // StatementNode interface
    string ToXml();
};

#endif // LLAMARNODE_H
