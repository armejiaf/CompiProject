#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H
#include "parentnode.h"
#include "typenode.h"
class  ExpressionNode:public ParentNode
{
public:
    ExpressionNode();
    ~ExpressionNode();
    virtual TypeNode* ValidateSemantic()=0;
};

#endif // EXPRESSIONNODE_H
