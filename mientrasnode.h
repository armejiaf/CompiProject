#ifndef MIENTRASNODE_H
#define MIENTRASNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class MientrasNode:public StatementNode
{
public:
    ExpressionNode *condition;
    vector <StatementNode*> code;


    MientrasNode();
    ~MientrasNode();

    // StatementNode interface
   string ToXml();
};

#endif // MIENTRASNODE_H
