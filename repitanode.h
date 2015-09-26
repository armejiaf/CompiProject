#ifndef REPITANODE_H
#define REPITANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "typebooleanonode.h"
#include <stdexcept>
#include <vector>

class RepitaNode:public StatementNode
{
public:
    vector <StatementNode*> code;
    ExpressionNode *condition;
    RepitaNode(vector <StatementNode*> code, ExpressionNode *condition);
    ~RepitaNode();

    string GetName();
    void ValidateSemantic();
};

#endif // REPITANODE_H
