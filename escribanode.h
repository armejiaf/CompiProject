#ifndef ESCRIBANODE_H
#define ESCRIBANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "typearchivonode.h"
#include "typearreglonode.h"
#include <vector>
#include <stdexcept>
class EscribaNode:public StatementNode
{
public:
    vector<ExpressionNode*> printVariables;

    EscribaNode(vector<ExpressionNode*> printVariables);
    ~EscribaNode();

    string GetName();
    void ValidateSemantic();
    void Interpret();
};

#endif // ESCRIBANODE_H
