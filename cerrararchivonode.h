#ifndef CERRARARCHIVONODE_H
#define CERRARARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "typearchivonode.h"
#include <stdexcept>

class CerrarArchivoNode:public StatementNode
{
public:
    VariableNode* archiveToClose;
    CerrarArchivoNode(VariableNode* archiveToClose);
    ~CerrarArchivoNode();

    string GetName();
    void ValidateSemantic();
    void Interpret();
};

#endif // CERRARARCHIVONODE_H
