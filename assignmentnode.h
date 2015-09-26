#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "expressionnode.h"
#include <stdexcept>

class AssignmentNode:public StatementNode
{
public:
    AssignmentNode(VariableNode *id,ExpressionNode *value);
    ~AssignmentNode();
    VariableNode* id;
    ExpressionNode* value;


    string GetName();
    void ValidateSemantic();
};

#endif // ASSIGNMENTNODE_H
