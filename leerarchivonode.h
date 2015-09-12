#ifndef LEERARCHIVONODE_H
#define LEERARCHIVONODE_H
#include "statementnode.h"
#include "expressionnode.h"

class LeerArchivoNode:public StatementNode
{
public:
    ExpressionNode * firstVariable;
    ExpressionNode * secondVariable;
    LeerArchivoNode();
    ~LeerArchivoNode();

    // StatementNode interface
    string ToXml();
};

#endif // LEERARCHIVONODE_H
