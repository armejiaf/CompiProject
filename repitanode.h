#ifndef REPITANODE_H
#define REPITANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class RepitaNode:public StatementNode
{
public:
    vector <StatementNode*> code;
    ExpressionNode *condition;
    RepitaNode(vector <StatementNode*> code, ExpressionNode *condition);
    ~RepitaNode();

    string ToXml();
    string GetName();
};

#endif // REPITANODE_H
