#ifndef SIMPLEPARAMETERNODE_H
#define SIMPLEPARAMETERNODE_H
#include "parameternode.h"
#include "variablenode.h"
#include "typenode.h"


class SimpleParameterNode:public ParameterNode
{
public:
    VariableNode * id;
    TypeNode * type;
    SimpleParameterNode( VariableNode * id,TypeNode * type);
    ~SimpleParameterNode();

    string ToXml();
    string GetName();
};

#endif // SIMPLEPARAMETERNODE_H
