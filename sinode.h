#ifndef SINODE_H
#define SINODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "typebooleanonode.h"
#include <stdexcept>
#include <vector>

class SiNode:public StatementNode
{
public:
    ExpressionNode *condicion;
    vector <StatementNode*> trueCode;
    vector<StatementNode*> falseCode;

    SiNode( ExpressionNode *condicion,vector <StatementNode*> trueCode, vector<StatementNode*> falseCode);
    ~SiNode();


    string GetName();
    void ValidateSemantic();
};

#endif // SINODE_H
