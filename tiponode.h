#ifndef TIPONODE_H
#define TIPONODE_H
#include "variablenode.h"
#include "typenode.h"
#include "statementnode.h"

class TipoNode:public StatementNode
{
public:
    VariableNode * id;
    TypeNode * type;
    TipoNode(VariableNode * id,TypeNode * type);
    ~TipoNode();

    string ToXml();
    string GetName();
};

#endif // TIPONODE_H
