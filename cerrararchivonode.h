#ifndef CERRARARCHIVONODE_H
#define CERRARARCHIVONODE_H
#include "statementnode.h"
#include "expressionnode.h"

class CerrarArchivoNode:public StatementNode
{
public:
    ExpressionNode * variable;
    CerrarArchivoNode();
    ~CerrarArchivoNode();

    // StatementNode interface
    string ToXml();
};

#endif // CERRARARCHIVONODE_H
