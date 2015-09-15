#ifndef SINODE_H
#define SINODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class SiNode:public StatementNode
{
public:
    ExpressionNode *condicion;
    vector <StatementNode*> trueCode;
    vector<StatementNode*> falseCode;

    SiNode( ExpressionNode *condicion,vector <StatementNode*> trueCode, vector<StatementNode*> falseCode);
    ~SiNode();

    string ToXml();
    string GetName();
};

#endif // SINODE_H
