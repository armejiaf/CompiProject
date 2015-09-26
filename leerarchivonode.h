#ifndef LEERARCHIVONODE_H
#define LEERARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "typearchivonode.h"
#include <stdexcept>

class LeerArchivoNode:public StatementNode
{
public:
    VariableNode * archive;
    VariableNode * data;
    LeerArchivoNode(VariableNode * archive,VariableNode * data);
    ~LeerArchivoNode();

    string GetName();
    void ValidateSemantic();
};

#endif // LEERARCHIVONODE_H
