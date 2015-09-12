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
    RepitaNode();
    ~RepitaNode();

    // StatementNode interface
    string ToXml();
};

#endif // REPITANODE_H
