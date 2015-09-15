#ifndef ESCRIBIRARCHIVONODE_H
#define ESCRIBIRARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"

class EscribirArchivoNode:public StatementNode
{
public:
    VariableNode * archive;
    VariableNode * data;
    EscribirArchivoNode(VariableNode * archive,VariableNode * data);
    ~EscribirArchivoNode();

    string ToXml();
    string GetName();
};

#endif // ESCRIBIRARCHIVONODE_H
