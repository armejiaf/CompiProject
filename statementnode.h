#ifndef STATEMENTNODE_H
#define STATEMENTNODE_H
#include "parentnode.h"

class StatementNode:public ParentNode
{
public:

    StatementNode();
    ~StatementNode();
    virtual void ValidateSemantic()=0;

};


#endif // STATEMENTNODE_H
