#ifndef ABRIRARCHIVONODE_H
#define ABRIRARCHIVONODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include "modenode.h"
#include <vector>
class AbrirArchivoNode:public StatementNode
{
public:
    ExpressionNode * variable;
    ExpressionNode * archiveToOpen;
    vector<ModeNode*> modes;
    AbrirArchivoNode();
    ~AbrirArchivoNode();

    // StatementNode interface
    string ToXml();
};

#endif // ABRIRARCHIVONODE_H
