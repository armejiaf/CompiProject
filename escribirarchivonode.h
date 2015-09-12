#ifndef ESCRIBIRARCHIVONODE_H
#define ESCRIBIRARCHIVONODE_H
#include "statementnode.h"
#include "expressionnode.h"

class EscribirArchivoNode:public StatementNode
{
public:
    ExpressionNode * firstVariable;
    ExpressionNode * secondVariable;
    EscribirArchivoNode();
    ~EscribirArchivoNode();

    // StatementNode interface
    string ToXml();
};

#endif // ESCRIBIRARCHIVONODE_H
