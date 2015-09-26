#include "parameterreferencenode.h"

ReferenceParameterNode::ReferenceParameterNode(string id, TypeNode *type)
{
    this->id=id;
    this->type=type;
}

ReferenceParameterNode::~ReferenceParameterNode()
{

}



string ReferenceParameterNode::GetName()
{
    return "ReferenceParameterNode";
}

TypeNode *ReferenceParameterNode::ValidateSemantic()
{
    return type;
}

