#ifndef ABRIRARCHIVONODE_H
#define ABRIRARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "modenode.h"
#include "symboltable.h"
#include "typearchivonode.h"
#include <vector>
class AbrirArchivoNode:public StatementNode
{
public:
    string archiveName;
    VariableNode* archiveType;
    vector<ModeNode*> modes;

    AbrirArchivoNode(string archiveName, VariableNode* archiveType, vector<ModeNode*> modes);
    ~AbrirArchivoNode();


    string GetName();
    void ValidateSemantic();
};

#endif // ABRIRARCHIVONODE_H
