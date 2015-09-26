#ifndef MIENTRASNODE_H
#define MIENTRASNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "typebooleanonode.h"
#include <stdexcept>
#include <vector>

class MientrasNode:public StatementNode
{
public:
    ExpressionNode *condition;
    vector <StatementNode*> code;


    MientrasNode(ExpressionNode *condition,vector <StatementNode*> code);
    ~MientrasNode();

   string GetName();
   void ValidateSemantic();
};

#endif // MIENTRASNODE_H
