#ifndef LEERARCHIVONODE_H
#define LEERARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"

class LeerArchivoNode:public StatementNode
{
public:
    VariableNode * archive;
    VariableNode * data;
    LeerArchivoNode(VariableNode * archive,VariableNode * data);
    ~LeerArchivoNode();

    string ToXml();
    string GetName();
};

#endif // LEERARCHIVONODE_H
