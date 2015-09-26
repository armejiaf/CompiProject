#ifndef DECLARARNODE_H
#define DECLARARNODE_H
#include "statementnode.h"
#include "typenode.h"
#include "symboltable.h"
#include <vector>

class DeclararNode:public StatementNode
{
public:
    TypeNode * type;
    vector <string> idList;
    DeclararNode(TypeNode * type,vector <string> idList);
    ~DeclararNode();

    string GetName();
    void ValidateSemantic();
};

#endif // DECLARARNODE_H
