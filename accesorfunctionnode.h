#ifndef FUNCTIONACCESORNODE_H
#define FUNCTIONACCESORNODE_H
#include "accesornode.h"
#include "expressionnode.h"
#include <vector>
class FunctionAccesorNode:public AccesorNode
{
public:
    vector<ExpressionNode*> parameters;
    FunctionAccesorNode(vector<ExpressionNode*> parameters);
    ~FunctionAccesorNode();

    string GetName();
    TypeNode *ValidateSemantic();
};

#endif // FUNCTIONACCESORNODE_H
