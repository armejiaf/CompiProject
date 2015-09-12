#ifndef REGISTRONODE_H
#define REGISTRONODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "declararnode.h"
#include <vector>

class RegistroNode:public StatementNode
{
public:
    ExpressionNode * id;
    vector<DeclararNode*> variables;

    RegistroNode();
    ~RegistroNode();

    // StatementNode interface
    string ToXml();
};

#endif // REGISTRONODE_H
