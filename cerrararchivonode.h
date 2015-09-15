#ifndef CERRARARCHIVONODE_H
#define CERRARARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"

class CerrarArchivoNode:public StatementNode
{
public:
    VariableNode * archiveToClose;
    CerrarArchivoNode(VariableNode * archiveToClose);
    ~CerrarArchivoNode();

    string ToXml();
    string GetName();
};

#endif // CERRARARCHIVONODE_H
