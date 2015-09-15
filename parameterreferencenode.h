#ifndef REFERENCEPARAMETERNODE_H
#define REFERENCEPARAMETERNODE_H
#include "parameternode.h"
#include "variablenode.h"
#include "typenode.h"

class ReferenceParameterNode:public ParameterNode
{
public:
    VariableNode * id;
    TypeNode * type;
    ReferenceParameterNode( VariableNode * id,TypeNode * type);
    ~ReferenceParameterNode();


    string ToXml();
    string GetName();
};

#endif // REFERENCEPARAMETERNODE_H
