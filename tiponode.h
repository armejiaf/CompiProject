#ifndef TIPONODE_H
#define TIPONODE_H
#include "variablenode.h"
#include "typenode.h"
#include "typearchivonode.h"
#include "statementnode.h"
#include "symboltable.h"

class TipoNode:public StatementNode
{
public:
    string  id;
    TypeNode * type;
    TipoNode(string id,TypeNode * type);
    ~TipoNode();

    string GetName();
    void ValidateSemantic();
    void Interpret();
};

#endif // TIPONODE_H
