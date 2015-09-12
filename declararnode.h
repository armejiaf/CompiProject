#ifndef DECLARARNODE_H
#define DECLARARNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <vector>

class DeclararNode:public StatementNode
{
public:
    ExpressionNode * type;
    vector <string> idList;
    DeclararNode();
    ~DeclararNode();

    // StatementNode interface
    string ToXml();
};

#endif // DECLARARNODE_H
