#ifndef ESCRIBANODE_H
#define ESCRIBANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class EscribaNode:public StatementNode
{
public:
    vector<ExpressionNode*> printVariables;

    EscribaNode(vector<ExpressionNode*> printVariables);
    ~EscribaNode();

    string ToXml();
    string GetName();
};

#endif // ESCRIBANODE_H
