#ifndef ABRIRARCHIVONODE_H
#define ABRIRARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "modenode.h"
#include <vector>
class AbrirArchivoNode:public StatementNode
{
public:
    VariableNode * archiveToOpen;
    VariableNode * id;
    vector<ModeNode*> modes;

    AbrirArchivoNode(VariableNode * archiveToOpen,VariableNode * id,vector<ModeNode*> modes);
    ~AbrirArchivoNode();

    string ToXml();
    string GetName();
};

#endif // ABRIRARCHIVONODE_H
