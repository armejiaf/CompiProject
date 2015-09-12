#ifndef TIPONODE_H
#define TIPONODE_H
#include "expressionnode.h"
#include "statementnode.h"

class TipoNode:public StatementNode
{
public:
    ExpressionNode * id;
    ExpressionNode * type;
    TipoNode();
    ~TipoNode();

    // StatementNode interface
    string ToXml();
};

#endif // TIPONODE_H
