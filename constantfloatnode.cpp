#include "constantfloatnode.h"

ConstantFloatNode::ConstantFloatNode(double value)
{
    this->value=value;
}

ConstantFloatNode::~ConstantFloatNode()
{

}

string ConstantFloatNode::GetName()
{
    return "ConstantFloatNode";
}

TypeNode *ConstantFloatNode::ValidateSemantic()
{
    return new RealNode();
}

