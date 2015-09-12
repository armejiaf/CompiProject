#ifndef ESCRIBANODE_H
#define ESCRIBANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class EscribaNode:public StatementNode
{
public:
    vector<ExpressionNode*> printVariables;

    EscribaNode();
    ~EscribaNode();

    // StatementNode interface
    string ToXml();
};

#endif // ESCRIBANODE_H
