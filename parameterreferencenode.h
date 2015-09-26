#ifndef REFERENCEPARAMETERNODE_H
#define REFERENCEPARAMETERNODE_H
#include "parameternode.h"
#include "variablenode.h"
#include "typenode.h"

class ReferenceParameterNode:public ParameterNode
{
public:
    string id;
    TypeNode * type;
    ReferenceParameterNode( string id,TypeNode * type);
    ~ReferenceParameterNode();

    string GetName();
    TypeNode *ValidateSemantic();
};

#endif // REFERENCEPARAMETERNODE_H
