#ifndef SINODE_H
#define SINODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class SiNode:public StatementNode
{
public:
    ExpressionNode *condicion;
    vector <StatementNode*> trueCode;
    vector<StatementNode*> falseCode;

    SiNode();
    ~SiNode();

    // StatementNode interface
    string ToXml();
};

#endif // SINODE_H
