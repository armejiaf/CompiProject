#ifndef SIMPLEPARAMETERNODE_H
#define SIMPLEPARAMETERNODE_H
#include "parameternode.h"
#include "variablenode.h"
#include "typenode.h"


class SimpleParameterNode:public ParameterNode
{
public:
    string id;
    TypeNode * type;
    SimpleParameterNode( string id,TypeNode * type);
    ~SimpleParameterNode();

    string GetName();
    TypeNode *ValidateSemantic();
};

#endif // SIMPLEPARAMETERNODE_H
