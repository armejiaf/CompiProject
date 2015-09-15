#ifndef PARANODE_H
#define PARANODE_H
#include "statementnode.h"
#include "assignmentnode.h"
#include <vector>


class ParaNode:public StatementNode
{
public:

    ParaNode(AssignmentNode *counter,ExpressionNode *condition,vector<StatementNode*> code);
    ~ParaNode();


    AssignmentNode *counter;
    ExpressionNode *condition;
    vector<StatementNode*> code;

    string ToXml();
    string GetName();
};

#endif // PARANODE_H
