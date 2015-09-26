#ifndef CASOLINENODE_H
#define CASOLINENODE_H
#include "parentnode.h"
#include "expressionnode.h"
#include "statementnode.h"
#include <vector>


class CasoLineNode:public ParentNode
{
public:
    vector<ExpressionNode*> conditions;
    vector<StatementNode*> code;
    CasoLineNode( vector<ExpressionNode*> conditions,vector<StatementNode*> code);
    ~CasoLineNode();

    string GetName();
};

#endif // CASOLINENODE_H
