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


    MientrasNode(ExpressionNode *condition,vector <StatementNode*> code);
    ~MientrasNode();

   string ToXml();
   string GetName();
};

#endif // MIENTRASNODE_H
