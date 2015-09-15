#ifndef DECLARARNODE_H
#define DECLARARNODE_H
#include "statementnode.h"
#include "typenode.h"
#include <vector>

class DeclararNode:public StatementNode
{
public:
    TypeNode * type;
    vector <string> idList;
    DeclararNode(TypeNode * type,vector <string> idList);
    ~DeclararNode();

    string ToXml();
    string GetName();
};

#endif // DECLARARNODE_H
