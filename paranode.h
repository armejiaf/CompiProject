#ifndef PARANODE_H
#define PARANODE_H
#include "statementnode.h"
#include "assignmentnode.h"
#include <vector>


class ParaNode:public StatementNode
{
public:

    ParaNode();
    ~ParaNode();


    AssignmentNode *counter;
    ExpressionNode *condition;
    vector<StatementNode*> code;

    // StatementNode interface
    string ToXml();
};

#endif // PARANODE_H
