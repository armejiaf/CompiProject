#ifndef CASONODE_H
#define CASONODE_H
#include "statementnode.h"
#include "expressionnode.h"

class CasoNode:public StatementNode
{
public:
    ExpressionNode * type;

    CasoNode();
    ~CasoNode();

    // StatementNode interface
   string ToXml();
};

#endif // CASONODE_H
