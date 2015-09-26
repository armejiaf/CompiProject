#ifndef ESCRIBIRARCHIVONODE_H
#define ESCRIBIRARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "typearchivonode.h"
#include <stdexcept>

class EscribirArchivoNode:public StatementNode
{
public:
    VariableNode * archive;
    VariableNode * data;
    EscribirArchivoNode(VariableNode * archive,VariableNode * data);
    ~EscribirArchivoNode();

    string GetName();
    void ValidateSemantic();
};

#endif // ESCRIBIRARCHIVONODE_H
