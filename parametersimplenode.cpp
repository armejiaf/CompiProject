#include "parametersimplenode.h"

SimpleParameterNode::SimpleParameterNode(string id, TypeNode *type)
{
    this->id=id;
    this->type=type;
}

SimpleParameterNode::~SimpleParameterNode()
{

}



string SimpleParameterNode::GetName()
{
    return "SimpleParameterNode";
}

TypeNode *SimpleParameterNode::ValidateSemantic()
{
    return type;
}

