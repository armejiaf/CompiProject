#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "expressionnode.h"

class AssignmentNode:public StatementNode
{
public:
    AssignmentNode(VariableNode *id,ExpressionNode *value);
    ~AssignmentNode();
    VariableNode* id;
    ExpressionNode* value;

    string ToXml();
    string GetName();
};

#endif // ASSIGNMENTNODE_H
