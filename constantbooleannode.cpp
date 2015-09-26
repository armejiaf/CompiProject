#include "constantbooleannode.h"

ConstantBooleanNode::ConstantBooleanNode(bool value)
{
    this->value=value;
}

ConstantBooleanNode::~ConstantBooleanNode()
{

}



string ConstantBooleanNode::GetName()
{
    return "ConstantBooleanNode";
}

TypeNode *ConstantBooleanNode::ValidateSemantic()
{
    return new BooleanoNode();
}


