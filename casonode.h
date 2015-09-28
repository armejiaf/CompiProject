#ifndef CASONODE_H
#define CASONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "casolinenode.h"
#include "valueentero.h"
#include "valuecaracter.h"
#include "valuereal.h"
#include <vector>
class CasoNode:public StatementNode
{
public:
    VariableNode * idCase;
    vector<CasoLineNode*> cases;
    vector<StatementNode*> defaultNode;
    CasoNode( VariableNode * idCase,vector<CasoLineNode*> cases,vector<StatementNode*> defaultNode);
    ~CasoNode();

   string GetName();
   void ValidateSemantic();
   void Interpret();
};

#endif // CASONODE_H
